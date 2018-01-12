#pragma once

#include <cstdint>

#include "CExoString.hpp"

namespace NWNXLib {

namespace API {

struct CResRef
{
    char m_resRefLowerCase[16];
    char m_resRef[16];

    // The below are auto generated stubs.
    CResRef(const CResRef&) = default;

    CResRef();
    CResRef(const CExoString&);
    CResRef(const char*);
    CResRef(const unsigned char*);
    CResRef(const unsigned char*, unsigned char);
    void CopyToString(CExoString&);
    void CopyToString(char*);
    unsigned char GetLength();
    char* GetResRef();
    void GetResRef(unsigned char*);
    char* GetResRefStr();
    int32_t IsValid();
    int32_t operator!();
    int32_t operator!=(const CExoString&);
    int32_t operator!=(const char*);
    int32_t operator!=(const CResRef&);
    CResRef operator+=(const CExoString&);
    CResRef operator=(const CExoString&);
    CResRef operator=(const char*);
    CResRef operator=(const unsigned char*);
    CResRef operator=(const CResRef&);
    int32_t operator==(const CExoString&);
    int32_t operator==(const char*);
    int32_t operator==(const CResRef&);
};

void CResRef__CResRefCtor__0(CResRef* thisPtr);
void CResRef__CResRefCtor__2(CResRef* thisPtr, const CExoString&);
void CResRef__CResRefCtor__4(CResRef* thisPtr, const char*);
void CResRef__CResRefCtor__6(CResRef* thisPtr, const unsigned char*);
void CResRef__CResRefCtor__8(CResRef* thisPtr, const unsigned char*, unsigned char);
void CResRef__CopyToString__0(CResRef* thisPtr, CExoString&);
void CResRef__CopyToString__1(CResRef* thisPtr, char*);
unsigned char CResRef__GetLength(CResRef* thisPtr);
char* CResRef__GetResRef__0(CResRef* thisPtr);
void CResRef__GetResRef__1(CResRef* thisPtr, unsigned char*);
char* CResRef__GetResRefStr(CResRef* thisPtr);
int32_t CResRef__IsValid(CResRef* thisPtr);
int32_t CResRef__OperatorUndefined(CResRef* thisPtr);
int32_t CResRef__OperatorNotEqualTo__0(CResRef* thisPtr, const CExoString&);
int32_t CResRef__OperatorNotEqualTo__1(CResRef* thisPtr, const char*);
int32_t CResRef__OperatorNotEqualTo__2(CResRef* thisPtr, const CResRef&);
CResRef CResRef__OperatorAdditionAssignment(CResRef* thisPtr, const CExoString&);
CResRef CResRef__OperatorAssignment__0(CResRef* thisPtr, const CExoString&);
CResRef CResRef__OperatorAssignment__1(CResRef* thisPtr, const char*);
CResRef CResRef__OperatorAssignment__2(CResRef* thisPtr, const unsigned char*);
CResRef CResRef__OperatorAssignment__3(CResRef* thisPtr, const CResRef&);
int32_t CResRef__OperatorEqualTo__0(CResRef* thisPtr, const CExoString&);
int32_t CResRef__OperatorEqualTo__1(CResRef* thisPtr, const char*);
int32_t CResRef__OperatorEqualTo__2(CResRef* thisPtr, const CResRef&);

}

}
