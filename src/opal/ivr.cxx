/*
 * ivr.cxx
 *
 * Interactive Voice Response support.
 *
 * Open Phone Abstraction Library (OPAL)
 *
 * Copyright (c) 2000 Equivalence Pty. Ltd.
 *
 * The contents of this file are subject to the Mozilla Public License
 * Version 1.0 (the "License"); you may not use this file except in
 * compliance with the License. You may obtain a copy of the License at
 * http://www.mozilla.org/MPL/
 *
 * Software distributed under the License is distributed on an "AS IS"
 * basis, WITHOUT WARRANTY OF ANY KIND, either express or implied. See
 * the License for the specific language governing rights and limitations
 * under the License.
 *
 * The Original Code is Open Phone Abstraction Library.
 *
 * The Initial Developer of the Original Code is Equivalence Pty. Ltd.
 *
 * Contributor(s): ______________________________________.
 *
 * $Revision$
 * $Author$
 * $Date$
 */

#include <ptlib.h>

#ifdef P_USE_PRAGMA
#pragma implementation "ivr.h"
#endif

#include <opal/ivr.h>

#include <opal/call.h>


#define new PNEW


#if P_EXPAT

/////////////////////////////////////////////////////////////////////////////

OpalIVREndPoint::OpalIVREndPoint(OpalManager & mgr, const char * prefix)
  : OpalEndPoint(mgr, prefix, CanTerminateCall),
    defaultVXML("<?xml version=\"1.0\"?>"
                "<vxml version=\"1.0\">"
                  "<form id=\"root\">"
                    "<audio src=\"welcome.wav\">"
                      "This is the OPAL, V X M L test program, please speak after the tone."
                    "</audio>"
                    "<record name=\"msg\" beep=\"true\" dtmfterm=\"true\" dest=\"recording.wav\" maxtime=\"10s\"/>"
                  "</form>"
                "</vxml>")
{
  nextTokenNumber = 1;

  defaultMediaFormats += OpalPCM16;

  PTRACE(4, "IVR\tCreated endpoint.");
}


OpalIVREndPoint::~OpalIVREndPoint()
{
  PTRACE(4, "IVR\tDeleted endpoint.");
}


BOOL OpalIVREndPoint::MakeConnection(OpalCall & call,
                                     const PString & remoteParty,
                                     void * userData,
                               unsigned int /*options*/,
                               OpalConnection::StringOptions * stringOptions)
{
  // First strip of the prefix if present
  PINDEX prefixLength = 0;
  if (remoteParty.Find(GetPrefixName()+":") == 0)
    prefixLength = GetPrefixName().GetLength()+1;

  PString vxml = remoteParty.Mid(prefixLength);
  if (vxml.Left(2) == "//")
    vxml = vxml.Mid(2);
  if (vxml.IsEmpty() || vxml == "*")
    vxml = defaultVXML;

  return AddConnection(CreateConnection(call, CreateConnectionToken(), userData, vxml, stringOptions));
}


OpalMediaFormatList OpalIVREndPoint::GetMediaFormats() const
{
  PWaitAndSignal mutex(inUseFlag);
  return defaultMediaFormats;
}


OpalIVRConnection * OpalIVREndPoint::CreateConnection(OpalCall & call,
                                                      const PString & token,
                                                      void * userData,
                                                      const PString & vxml,
                                                      OpalConnection::StringOptions * stringOptions)
{
  return new OpalIVRConnection(call, *this, token, userData, vxml, stringOptions);
}


PString OpalIVREndPoint::CreateConnectionToken()
{
  inUseFlag.Wait();
  unsigned tokenNumber = nextTokenNumber++;
  inUseFlag.Signal();
  return psprintf("IVR/%u", tokenNumber);
}


void OpalIVREndPoint::SetDefaultVXML(const PString & vxml)
{
  inUseFlag.Wait();
  defaultVXML = vxml;
  inUseFlag.Signal();
}


void OpalIVREndPoint::SetDefaultMediaFormats(const OpalMediaFormatList & formats)
{
  inUseFlag.Wait();
  defaultMediaFormats = formats;
  inUseFlag.Signal();
}

BOOL OpalIVREndPoint::StartVXML()
{
  return FALSE;
}


/////////////////////////////////////////////////////////////////////////////

OpalIVRConnection::OpalIVRConnection(OpalCall & call,
                                     OpalIVREndPoint & ep,
                                     const PString & token,
                                     void * /*userData*/,
                                     const PString & vxml,
                                     OpalConnection::StringOptions * stringOptions)
  : OpalConnection(call, ep, token, 0, stringOptions),
    endpoint(ep),
    vxmlToLoad(vxml),
    vxmlMediaFormats(ep.GetMediaFormats()),
#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable:4355)
#endif
    vxmlSession(this, PFactory<PTextToSpeech>::CreateInstance(ep.GetDefaultTextToSpeech()))
#ifdef _MSC_VER
#pragma warning(pop)
#endif
{
  phase = SetUpPhase;

  PTRACE(4, "IVR\tConstructed");
}


OpalIVRConnection::~OpalIVRConnection()
{
  PTRACE(4, "IVR\tDestroyed.");
}


BOOL OpalIVRConnection::SetUpConnection()
{
  // Check if we are A-Party in thsi call, so need to do things differently
  if (ownerCall.GetConnection(0) == this) {
    phase = SetUpPhase;
    if (!OnIncomingConnection(0, NULL)) {
      Release(EndedByCallerAbort);
      return FALSE;
    }

    PTRACE(3, "IVR\tOutgoing call routed to " << ownerCall.GetPartyB() << " for " << *this);
    if (!ownerCall.OnSetUp(*this)) {
      Release(EndedByNoAccept);
      return FALSE;
    }

    return TRUE;
  }

  remotePartyName = ownerCall.GetOtherPartyConnection(*this)->GetRemotePartyName();

  PTRACE(3, "IVR\tSetUpConnection(" << remotePartyName << ')');

  // load the vxml file before calling OnAlerting() in case of h323 is used with faststart,
  // in this case, the media will be opened ealier and the vxml file needs to be already loaded 
  //if (!StartVXML()) {
  //  PTRACE(1, "IVR\tVXML session not loaded, aborting.");
  //  Release(EndedByLocalUser);
  //  return FALSE;
  //}

  phase = AlertingPhase;
  OnAlerting();

  phase = ConnectedPhase;
  OnConnected();

  return TRUE;
}

void OpalIVRConnection::OnEstablished()
{
  OpalConnection::OnEstablished();
  StartVXML();
}


BOOL OpalIVRConnection::StartVXML()
{
  PStringToString & vars = vxmlSession.GetSessionVars();

  if (stringOptions != NULL) {
    PString originator = (*stringOptions)("Originator-Address");
    if (originator.IsEmpty())
      originator = (*stringOptions)("Remote-Address");
    if (!originator.IsEmpty()) {
      PIPSocketAddressAndPort ap(originator);
      vars.SetAt("Source-IP-Address", ap.address.AsString());
    }
  }

  vars.SetAt("Time", PTime().AsString());

  if (vxmlToLoad.IsEmpty()) 
    vxmlToLoad = endpoint.GetDefaultVXML();

  if (vxmlToLoad.IsEmpty())
    return endpoint.StartVXML();

  if (vxmlToLoad.Find("<?xml") == 0)
    return vxmlSession.LoadVXML(vxmlToLoad);

  ////////////////////////////////

  PINDEX repeat = 1;
  PINDEX delay = 0;
  PString voice;

  PINDEX i;
  PStringArray tokens = vxmlToLoad.Tokenise(';', FALSE);
  for (i = 0; i < tokens.GetSize(); ++i) {
    PString str(tokens[i]);

    if (str.Find("file://") == 0) {
      PString fn = str.Mid(7).Trim();
      if (fn.Right(5) *= ".vxml") {
        if (!voice.IsEmpty())
          fn = voice + PDIR_SEPARATOR + fn;
        vxmlSession.LoadFile(fn);
        continue;
      }
      else if (fn.Right(4) *= ".wav") {
        if (!voice.IsEmpty())
          fn = voice + PDIR_SEPARATOR + fn;
        vxmlSession.PlayFile(fn, repeat, delay);
        continue;
      }
    }

    PINDEX pos = str.Find("=");
    PString key(str);
    PString val;
    if (pos != P_MAX_INDEX) {
      key = str.Left(pos);
      val = str.Mid(pos+1);
    }

    if (key *= "repeat") {
      if (!val.IsEmpty())
        repeat = val.AsInteger();
    }
    else if (key *= "delay") {
      if (!val.IsEmpty())
        delay = val.AsInteger();
    }
    else if (key *= "voice") {
      if (!val.IsEmpty()) {
        voice = val;
        PTextToSpeech * tts = vxmlSession.GetTextToSpeech();
        if (tts != NULL)
          tts->SetVoice(voice);
      }
    }

    else if (key *= "tone") 
      vxmlSession.PlayTone(val, repeat, delay);

    else if (key *= "speak") {
      if (!val.IsEmpty() && (val[0] == '$'))
        val = vars(val.Mid(1));
      vxmlSession.PlayText(val, PTextToSpeech::Default, repeat, delay);
    }
  }

  vxmlSession.SetFinishWhenEmpty(TRUE);

  return TRUE;
}

BOOL OpalIVRConnection::SetAlerting(const PString & calleeName, BOOL)
{
  PTRACE(3, "IVR\tSetAlerting(" << calleeName << ')');

  if (!LockReadWrite())
    return FALSE;

  phase = AlertingPhase;
  remotePartyName = calleeName;
  UnlockReadWrite();

  return TRUE;
}


BOOL OpalIVRConnection::SetConnected()
{
  PTRACE(3, "IVR\tSetConnected()");

  {
    PSafeLockReadWrite safeLock(*this);
    if (!safeLock.IsLocked())
      return FALSE;

    phase = ConnectedPhase;

    if (!StartVXML()) {
      PTRACE(1, "IVR\tVXML session not loaded, aborting.");
      Release(EndedByLocalUser);
      return FALSE;
    }

    if (mediaStreams.IsEmpty())
      return TRUE;

    phase = EstablishedPhase;
  }

  OnEstablished();

  return TRUE;
}


OpalMediaFormatList OpalIVRConnection::GetMediaFormats() const
{
  return vxmlMediaFormats;
}


OpalMediaStream * OpalIVRConnection::CreateMediaStream(const OpalMediaFormat & mediaFormat,
                                                       unsigned sessionID,
                                                       BOOL isSource)
{
  return new OpalIVRMediaStream(*this, mediaFormat, sessionID, isSource, vxmlSession);
}


BOOL OpalIVRConnection::SendUserInputString(const PString & value)
{
  PTRACE(3, "IVR\tSendUserInputString(" << value << ')');

  for (PINDEX i = 0; i < value.GetLength(); i++)
    vxmlSession.OnUserInput(value[i]);

  return TRUE;
}


/////////////////////////////////////////////////////////////////////////////

OpalIVRMediaStream::OpalIVRMediaStream(OpalIVRConnection & conn,
                                       const OpalMediaFormat & mediaFormat,
                                       unsigned sessionID,
                                       BOOL isSourceStream,
                                       PVXMLSession & vxml)
  : OpalRawMediaStream(conn, mediaFormat, sessionID, isSourceStream, &vxml, FALSE),
    vxmlSession(vxml)
{
  PTRACE(3, "IVR\tOpalIVRMediaStream sessionID = " << sessionID << ", isSourceStream = " << isSourceStream);
}


BOOL OpalIVRMediaStream::Open()
{
  PTRACE(3, "IVR\tOpen");
  if (isOpen)
    return TRUE;

  if (vxmlSession.IsOpen()) {
    PVXMLChannel * vxmlChannel = vxmlSession.GetAndLockVXMLChannel();
    PString vxmlChannelMediaFormat;
    
    if (vxmlChannel == NULL) {
      PTRACE(1, "IVR\tVXML engine not really open");
      return FALSE;
    }

    vxmlChannelMediaFormat = vxmlChannel->GetMediaFormat();
    vxmlSession.UnLockVXMLChannel();
    
    if (mediaFormat != vxmlChannelMediaFormat) {
      PTRACE(1, "IVR\tCannot use VXML engine: asymmetrical media format");
      return FALSE;
    }

    return OpalMediaStream::Open();
  }

  if (vxmlSession.Open(mediaFormat))
    return OpalMediaStream::Open();

  PTRACE(1, "IVR\tCannot open VXML engine: incompatible media format");
  return FALSE;
}


BOOL OpalIVRMediaStream::IsSynchronous() const
{
  return FALSE;
}


#endif // P_EXPAT


/////////////////////////////////////////////////////////////////////////////
