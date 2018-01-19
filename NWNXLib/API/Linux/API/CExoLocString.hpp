#pragma once

#include <cstdint>

#include "CExoString.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CExoLocStringInternal;

struct CExoLocString
{
    CExoLocStringInternal* m_pExoLocStringInternal;
    uint32_t m_dwStringRef;

    CExoLocString();
    CExoLocString(const CExoLocString&);
    ~CExoLocString();
    int32_t AddString(int32_t, CExoString, unsigned char);
    void ClearLocString();
    int32_t GetString(uint32_t, int32_t*, CExoString*, unsigned char*);
    int32_t GetString(int32_t, CExoString*, unsigned char, int32_t);
    uint32_t GetStringCount();
    int32_t GetStringInternal(int32_t, CExoString*);
    int32_t GetStringLength(uint32_t);
    int32_t GetStringLoc(int32_t, CExoString*, unsigned char);
    int32_t operator!=(CExoLocString&);
    CExoLocString& operator=(const CExoLocString&);
    int32_t operator==(CExoLocString&);
    void RemoveString(int32_t);
    void RemoveString(int32_t, unsigned char);
};

void CExoLocString__CExoLocStringCtor__0(CExoLocString* thisPtr);
void CExoLocString__CExoLocStringCtor__1(CExoLocString* thisPtr, const CExoLocString&);
void CExoLocString__CExoLocStringDtor(CExoLocString* thisPtr);
int32_t CExoLocString__AddString(CExoLocString* thisPtr, int32_t, CExoString, unsigned char);
void CExoLocString__ClearLocString(CExoLocString* thisPtr);
int32_t CExoLocString__GetString__0(CExoLocString* thisPtr, uint32_t, int32_t*, CExoString*, unsigned char*);
int32_t CExoLocString__GetString__1(CExoLocString* thisPtr, int32_t, CExoString*, unsigned char, int32_t);
uint32_t CExoLocString__GetStringCount(CExoLocString* thisPtr);
int32_t CExoLocString__GetStringInternal(CExoLocString* thisPtr, int32_t, CExoString*);
int32_t CExoLocString__GetStringLength(CExoLocString* thisPtr, uint32_t);
int32_t CExoLocString__GetStringLoc(CExoLocString* thisPtr, int32_t, CExoString*, unsigned char);
int32_t CExoLocString__OperatorNotEqualTo(CExoLocString* thisPtr, CExoLocString&);
CExoLocString& CExoLocString__OperatorAssignment(CExoLocString* thisPtr, const CExoLocString&);
int32_t CExoLocString__OperatorEqualTo(CExoLocString* thisPtr, CExoLocString&);
void CExoLocString__RemoveString__0(CExoLocString* thisPtr, int32_t);
void CExoLocString__RemoveString__1(CExoLocString* thisPtr, int32_t, unsigned char);

}

}
