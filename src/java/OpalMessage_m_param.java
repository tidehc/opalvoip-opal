/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 1.3.40
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package org.opalvoip;

public class OpalMessage_m_param {
  private long swigCPtr;
  protected boolean swigCMemOwn;

  protected OpalMessage_m_param(long cPtr, boolean cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = cPtr;
  }

  protected static long getCPtr(OpalMessage_m_param obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public synchronized void delete() {
    if (swigCPtr != 0) {
      if (swigCMemOwn) {
        swigCMemOwn = false;
        OPALJNI.delete_OpalMessage_m_param(swigCPtr);
      }
      swigCPtr = 0;
    }
  }

  public void setM_commandError(String value) {
    OPALJNI.OpalMessage_m_param_m_commandError_set(swigCPtr, this, value);
  }

  public String getM_commandError() {
    return OPALJNI.OpalMessage_m_param_m_commandError_get(swigCPtr, this);
  }

  public void setM_general(OpalParamGeneral value) {
    OPALJNI.OpalMessage_m_param_m_general_set(swigCPtr, this, OpalParamGeneral.getCPtr(value), value);
  }

  public OpalParamGeneral getM_general() {
    long cPtr = OPALJNI.OpalMessage_m_param_m_general_get(swigCPtr, this);
    return (cPtr == 0) ? null : new OpalParamGeneral(cPtr, false);
  }

  public void setM_protocol(OpalParamProtocol value) {
    OPALJNI.OpalMessage_m_param_m_protocol_set(swigCPtr, this, OpalParamProtocol.getCPtr(value), value);
  }

  public OpalParamProtocol getM_protocol() {
    long cPtr = OPALJNI.OpalMessage_m_param_m_protocol_get(swigCPtr, this);
    return (cPtr == 0) ? null : new OpalParamProtocol(cPtr, false);
  }

  public void setM_registrationInfo(OpalParamRegistration value) {
    OPALJNI.OpalMessage_m_param_m_registrationInfo_set(swigCPtr, this, OpalParamRegistration.getCPtr(value), value);
  }

  public OpalParamRegistration getM_registrationInfo() {
    long cPtr = OPALJNI.OpalMessage_m_param_m_registrationInfo_get(swigCPtr, this);
    return (cPtr == 0) ? null : new OpalParamRegistration(cPtr, false);
  }

  public void setM_registrationStatus(OpalStatusRegistration value) {
    OPALJNI.OpalMessage_m_param_m_registrationStatus_set(swigCPtr, this, OpalStatusRegistration.getCPtr(value), value);
  }

  public OpalStatusRegistration getM_registrationStatus() {
    long cPtr = OPALJNI.OpalMessage_m_param_m_registrationStatus_get(swigCPtr, this);
    return (cPtr == 0) ? null : new OpalStatusRegistration(cPtr, false);
  }

  public void setM_callSetUp(OpalParamSetUpCall value) {
    OPALJNI.OpalMessage_m_param_m_callSetUp_set(swigCPtr, this, OpalParamSetUpCall.getCPtr(value), value);
  }

  public OpalParamSetUpCall getM_callSetUp() {
    long cPtr = OPALJNI.OpalMessage_m_param_m_callSetUp_get(swigCPtr, this);
    return (cPtr == 0) ? null : new OpalParamSetUpCall(cPtr, false);
  }

  public void setM_callToken(String value) {
    OPALJNI.OpalMessage_m_param_m_callToken_set(swigCPtr, this, value);
  }

  public String getM_callToken() {
    return OPALJNI.OpalMessage_m_param_m_callToken_get(swigCPtr, this);
  }

  public void setM_incomingCall(OpalStatusIncomingCall value) {
    OPALJNI.OpalMessage_m_param_m_incomingCall_set(swigCPtr, this, OpalStatusIncomingCall.getCPtr(value), value);
  }

  public OpalStatusIncomingCall getM_incomingCall() {
    long cPtr = OPALJNI.OpalMessage_m_param_m_incomingCall_get(swigCPtr, this);
    return (cPtr == 0) ? null : new OpalStatusIncomingCall(cPtr, false);
  }

  public void setM_answerCall(OpalParamAnswerCall value) {
    OPALJNI.OpalMessage_m_param_m_answerCall_set(swigCPtr, this, OpalParamAnswerCall.getCPtr(value), value);
  }

  public OpalParamAnswerCall getM_answerCall() {
    long cPtr = OPALJNI.OpalMessage_m_param_m_answerCall_get(swigCPtr, this);
    return (cPtr == 0) ? null : new OpalParamAnswerCall(cPtr, false);
  }

  public void setM_userInput(OpalStatusUserInput value) {
    OPALJNI.OpalMessage_m_param_m_userInput_set(swigCPtr, this, OpalStatusUserInput.getCPtr(value), value);
  }

  public OpalStatusUserInput getM_userInput() {
    long cPtr = OPALJNI.OpalMessage_m_param_m_userInput_get(swigCPtr, this);
    return (cPtr == 0) ? null : new OpalStatusUserInput(cPtr, false);
  }

  public void setM_messageWaiting(OpalStatusMessageWaiting value) {
    OPALJNI.OpalMessage_m_param_m_messageWaiting_set(swigCPtr, this, OpalStatusMessageWaiting.getCPtr(value), value);
  }

  public OpalStatusMessageWaiting getM_messageWaiting() {
    long cPtr = OPALJNI.OpalMessage_m_param_m_messageWaiting_get(swigCPtr, this);
    return (cPtr == 0) ? null : new OpalStatusMessageWaiting(cPtr, false);
  }

  public void setM_lineAppearance(OpalStatusLineAppearance value) {
    OPALJNI.OpalMessage_m_param_m_lineAppearance_set(swigCPtr, this, OpalStatusLineAppearance.getCPtr(value), value);
  }

  public OpalStatusLineAppearance getM_lineAppearance() {
    long cPtr = OPALJNI.OpalMessage_m_param_m_lineAppearance_get(swigCPtr, this);
    return (cPtr == 0) ? null : new OpalStatusLineAppearance(cPtr, false);
  }

  public void setM_callCleared(OpalStatusCallCleared value) {
    OPALJNI.OpalMessage_m_param_m_callCleared_set(swigCPtr, this, OpalStatusCallCleared.getCPtr(value), value);
  }

  public OpalStatusCallCleared getM_callCleared() {
    long cPtr = OPALJNI.OpalMessage_m_param_m_callCleared_get(swigCPtr, this);
    return (cPtr == 0) ? null : new OpalStatusCallCleared(cPtr, false);
  }

  public void setM_clearCall(OpalParamCallCleared value) {
    OPALJNI.OpalMessage_m_param_m_clearCall_set(swigCPtr, this, OpalParamCallCleared.getCPtr(value), value);
  }

  public OpalParamCallCleared getM_clearCall() {
    long cPtr = OPALJNI.OpalMessage_m_param_m_clearCall_get(swigCPtr, this);
    return (cPtr == 0) ? null : new OpalParamCallCleared(cPtr, false);
  }

  public void setM_mediaStream(OpalStatusMediaStream value) {
    OPALJNI.OpalMessage_m_param_m_mediaStream_set(swigCPtr, this, OpalStatusMediaStream.getCPtr(value), value);
  }

  public OpalStatusMediaStream getM_mediaStream() {
    long cPtr = OPALJNI.OpalMessage_m_param_m_mediaStream_get(swigCPtr, this);
    return (cPtr == 0) ? null : new OpalStatusMediaStream(cPtr, false);
  }

  public void setM_setUserData(OpalParamSetUserData value) {
    OPALJNI.OpalMessage_m_param_m_setUserData_set(swigCPtr, this, OpalParamSetUserData.getCPtr(value), value);
  }

  public OpalParamSetUserData getM_setUserData() {
    long cPtr = OPALJNI.OpalMessage_m_param_m_setUserData_get(swigCPtr, this);
    return (cPtr == 0) ? null : new OpalParamSetUserData(cPtr, false);
  }

  public void setM_recording(OpalParamRecording value) {
    OPALJNI.OpalMessage_m_param_m_recording_set(swigCPtr, this, OpalParamRecording.getCPtr(value), value);
  }

  public OpalParamRecording getM_recording() {
    long cPtr = OPALJNI.OpalMessage_m_param_m_recording_get(swigCPtr, this);
    return (cPtr == 0) ? null : new OpalParamRecording(cPtr, false);
  }

  public void setM_transferStatus(OpalStatusTransferCall value) {
    OPALJNI.OpalMessage_m_param_m_transferStatus_set(swigCPtr, this, OpalStatusTransferCall.getCPtr(value), value);
  }

  public OpalStatusTransferCall getM_transferStatus() {
    long cPtr = OPALJNI.OpalMessage_m_param_m_transferStatus_get(swigCPtr, this);
    return (cPtr == 0) ? null : new OpalStatusTransferCall(cPtr, false);
  }

  public void setM_ivrStatus(OpalStatusIVR value) {
    OPALJNI.OpalMessage_m_param_m_ivrStatus_set(swigCPtr, this, OpalStatusIVR.getCPtr(value), value);
  }

  public OpalStatusIVR getM_ivrStatus() {
    long cPtr = OPALJNI.OpalMessage_m_param_m_ivrStatus_get(swigCPtr, this);
    return (cPtr == 0) ? null : new OpalStatusIVR(cPtr, false);
  }

  public OpalMessage_m_param() {
    this(OPALJNI.new_OpalMessage_m_param(), true);
  }

}
