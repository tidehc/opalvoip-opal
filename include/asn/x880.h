//
// x880.h
//
// Code automatically generated by asnparse.
//

#if ! H323_DISABLE_X880

#ifndef __X880_H
#define __X880_H

#ifdef P_USE_PRAGMA
#pragma interface
#endif

#include <ptclib/asner.h>

//
// ROS
//

class X880_Invoke;
class X880_ReturnResult;
class X880_ReturnError;
class X880_Reject;

class X880_ROS : public PASN_Choice
{
#ifndef PASN_LEANANDMEAN
    PCLASSINFO(X880_ROS, PASN_Choice);
#endif
  public:
    X880_ROS(unsigned tag = 0, TagClass tagClass = UniversalTagClass);

    enum Choices {
      e_invoke,
      e_returnResult,
      e_returnError,
      e_reject
    };

#if defined(__GNUC__) && __GNUC__ <= 2 && __GNUC_MINOR__ < 9
    operator X880_Invoke &() const;
#else
    operator X880_Invoke &();
    operator const X880_Invoke &() const;
#endif
#if defined(__GNUC__) && __GNUC__ <= 2 && __GNUC_MINOR__ < 9
    operator X880_ReturnResult &() const;
#else
    operator X880_ReturnResult &();
    operator const X880_ReturnResult &() const;
#endif
#if defined(__GNUC__) && __GNUC__ <= 2 && __GNUC_MINOR__ < 9
    operator X880_ReturnError &() const;
#else
    operator X880_ReturnError &();
    operator const X880_ReturnError &() const;
#endif
#if defined(__GNUC__) && __GNUC__ <= 2 && __GNUC_MINOR__ < 9
    operator X880_Reject &() const;
#else
    operator X880_Reject &();
    operator const X880_Reject &() const;
#endif

    BOOL CreateObject();
    PObject * Clone() const;
};


//
// GeneralProblem
//

class X880_GeneralProblem : public PASN_Integer
{
#ifndef PASN_LEANANDMEAN
    PCLASSINFO(X880_GeneralProblem, PASN_Integer);
#endif
  public:
    X880_GeneralProblem(unsigned tag = UniversalInteger, TagClass tagClass = UniversalTagClass);

    X880_GeneralProblem & operator=(int v);
    X880_GeneralProblem & operator=(unsigned v);
    PObject * Clone() const;
};


//
// InvokeProblem
//

class X880_InvokeProblem : public PASN_Integer
{
#ifndef PASN_LEANANDMEAN
    PCLASSINFO(X880_InvokeProblem, PASN_Integer);
#endif
  public:
    X880_InvokeProblem(unsigned tag = UniversalInteger, TagClass tagClass = UniversalTagClass);

    X880_InvokeProblem & operator=(int v);
    X880_InvokeProblem & operator=(unsigned v);
    PObject * Clone() const;
};


//
// ReturnResultProblem
//

class X880_ReturnResultProblem : public PASN_Integer
{
#ifndef PASN_LEANANDMEAN
    PCLASSINFO(X880_ReturnResultProblem, PASN_Integer);
#endif
  public:
    X880_ReturnResultProblem(unsigned tag = UniversalInteger, TagClass tagClass = UniversalTagClass);

    X880_ReturnResultProblem & operator=(int v);
    X880_ReturnResultProblem & operator=(unsigned v);
    PObject * Clone() const;
};


//
// ReturnErrorProblem
//

class X880_ReturnErrorProblem : public PASN_Integer
{
#ifndef PASN_LEANANDMEAN
    PCLASSINFO(X880_ReturnErrorProblem, PASN_Integer);
#endif
  public:
    X880_ReturnErrorProblem(unsigned tag = UniversalInteger, TagClass tagClass = UniversalTagClass);

    X880_ReturnErrorProblem & operator=(int v);
    X880_ReturnErrorProblem & operator=(unsigned v);
    PObject * Clone() const;
};


//
// RejectProblem
//

class X880_RejectProblem : public PASN_Integer
{
#ifndef PASN_LEANANDMEAN
    PCLASSINFO(X880_RejectProblem, PASN_Integer);
#endif
  public:
    X880_RejectProblem(unsigned tag = UniversalInteger, TagClass tagClass = UniversalTagClass);

    X880_RejectProblem & operator=(int v);
    X880_RejectProblem & operator=(unsigned v);
    PObject * Clone() const;
};


//
// InvokeId
//

class X880_InvokeId : public PASN_Integer
{
#ifndef PASN_LEANANDMEAN
    PCLASSINFO(X880_InvokeId, PASN_Integer);
#endif
  public:
    X880_InvokeId(unsigned tag = UniversalInteger, TagClass tagClass = UniversalTagClass);

    X880_InvokeId & operator=(int v);
    X880_InvokeId & operator=(unsigned v);
    PObject * Clone() const;
};


//
// Code
//

class X880_Code : public PASN_Choice
{
#ifndef PASN_LEANANDMEAN
    PCLASSINFO(X880_Code, PASN_Choice);
#endif
  public:
    X880_Code(unsigned tag = 0, TagClass tagClass = UniversalTagClass);

    enum Choices {
      e_local,
      e_global
    };

    BOOL CreateObject();
    PObject * Clone() const;
};


//
// ReturnResult_result
//

class X880_ReturnResult_result : public PASN_Sequence
{
#ifndef PASN_LEANANDMEAN
    PCLASSINFO(X880_ReturnResult_result, PASN_Sequence);
#endif
  public:
    X880_ReturnResult_result(unsigned tag = UniversalSequence, TagClass tagClass = UniversalTagClass);

    X880_Code m_opcode;
    PASN_OctetString m_result;

    PINDEX GetDataLength() const;
    BOOL Decode(PASN_Stream & strm);
    void Encode(PASN_Stream & strm) const;
#ifndef PASN_NOPRINTON
    void PrintOn(ostream & strm) const;
#endif
    Comparison Compare(const PObject & obj) const;
    PObject * Clone() const;
};


//
// Reject_problem
//

class X880_GeneralProblem;
class X880_InvokeProblem;
class X880_ReturnResultProblem;
class X880_ReturnErrorProblem;

class X880_Reject_problem : public PASN_Choice
{
#ifndef PASN_LEANANDMEAN
    PCLASSINFO(X880_Reject_problem, PASN_Choice);
#endif
  public:
    X880_Reject_problem(unsigned tag = 0, TagClass tagClass = UniversalTagClass);

    enum Choices {
      e_general,
      e_invoke,
      e_returnResult,
      e_returnError
    };

#if defined(__GNUC__) && __GNUC__ <= 2 && __GNUC_MINOR__ < 9
    operator X880_GeneralProblem &() const;
#else
    operator X880_GeneralProblem &();
    operator const X880_GeneralProblem &() const;
#endif
#if defined(__GNUC__) && __GNUC__ <= 2 && __GNUC_MINOR__ < 9
    operator X880_InvokeProblem &() const;
#else
    operator X880_InvokeProblem &();
    operator const X880_InvokeProblem &() const;
#endif
#if defined(__GNUC__) && __GNUC__ <= 2 && __GNUC_MINOR__ < 9
    operator X880_ReturnResultProblem &() const;
#else
    operator X880_ReturnResultProblem &();
    operator const X880_ReturnResultProblem &() const;
#endif
#if defined(__GNUC__) && __GNUC__ <= 2 && __GNUC_MINOR__ < 9
    operator X880_ReturnErrorProblem &() const;
#else
    operator X880_ReturnErrorProblem &();
    operator const X880_ReturnErrorProblem &() const;
#endif

    BOOL CreateObject();
    PObject * Clone() const;
};


//
// Invoke
//

class X880_Invoke : public PASN_Sequence
{
#ifndef PASN_LEANANDMEAN
    PCLASSINFO(X880_Invoke, PASN_Sequence);
#endif
  public:
    X880_Invoke(unsigned tag = UniversalSequence, TagClass tagClass = UniversalTagClass);

    enum OptionalFields {
      e_linkedId,
      e_argument
    };

    PASN_Integer m_invokeId;
    X880_InvokeId m_linkedId;
    X880_Code m_opcode;
    PASN_OctetString m_argument;

    PINDEX GetDataLength() const;
    BOOL Decode(PASN_Stream & strm);
    void Encode(PASN_Stream & strm) const;
#ifndef PASN_NOPRINTON
    void PrintOn(ostream & strm) const;
#endif
    Comparison Compare(const PObject & obj) const;
    PObject * Clone() const;
};


//
// ReturnResult
//

class X880_ReturnResult : public PASN_Sequence
{
#ifndef PASN_LEANANDMEAN
    PCLASSINFO(X880_ReturnResult, PASN_Sequence);
#endif
  public:
    X880_ReturnResult(unsigned tag = UniversalSequence, TagClass tagClass = UniversalTagClass);

    enum OptionalFields {
      e_result
    };

    X880_InvokeId m_invokeId;
    X880_ReturnResult_result m_result;

    PINDEX GetDataLength() const;
    BOOL Decode(PASN_Stream & strm);
    void Encode(PASN_Stream & strm) const;
#ifndef PASN_NOPRINTON
    void PrintOn(ostream & strm) const;
#endif
    Comparison Compare(const PObject & obj) const;
    PObject * Clone() const;
};


//
// ReturnError
//

class X880_ReturnError : public PASN_Sequence
{
#ifndef PASN_LEANANDMEAN
    PCLASSINFO(X880_ReturnError, PASN_Sequence);
#endif
  public:
    X880_ReturnError(unsigned tag = UniversalSequence, TagClass tagClass = UniversalTagClass);

    enum OptionalFields {
      e_parameter
    };

    X880_InvokeId m_invokeId;
    X880_Code m_errorCode;
    PASN_OctetString m_parameter;

    PINDEX GetDataLength() const;
    BOOL Decode(PASN_Stream & strm);
    void Encode(PASN_Stream & strm) const;
#ifndef PASN_NOPRINTON
    void PrintOn(ostream & strm) const;
#endif
    Comparison Compare(const PObject & obj) const;
    PObject * Clone() const;
};


//
// Reject
//

class X880_Reject : public PASN_Sequence
{
#ifndef PASN_LEANANDMEAN
    PCLASSINFO(X880_Reject, PASN_Sequence);
#endif
  public:
    X880_Reject(unsigned tag = UniversalSequence, TagClass tagClass = UniversalTagClass);

    X880_InvokeId m_invokeId;
    X880_Reject_problem m_problem;

    PINDEX GetDataLength() const;
    BOOL Decode(PASN_Stream & strm);
    void Encode(PASN_Stream & strm) const;
#ifndef PASN_NOPRINTON
    void PrintOn(ostream & strm) const;
#endif
    Comparison Compare(const PObject & obj) const;
    PObject * Clone() const;
};


#endif // __X880_H

#endif // if ! H323_DISABLE_X880


// End of x880.h
