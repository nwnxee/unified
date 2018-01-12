#pragma once

#include <cstdint>

#include "CExoFile.hpp"
#include "CExoString.hpp"

namespace NWNXLib {

namespace API {

struct CERFString
{
    uint32_t m_nLanguageID;
    uint32_t m_nSize;
    char* m_pText;

    // The below are auto generated stubs.
    CERFString(const CERFString&) = default;
    CERFString& operator=(const CERFString&) = default;

    CERFString();
    ~CERFString();
    CExoString GetText();
    int32_t Read();
    int32_t Reset();
    void SetText(CExoString&);
    int32_t Write(CExoFile&);
};

void CERFString__CERFStringCtor__0(CERFString* thisPtr);
void CERFString__CERFStringDtor__0(CERFString* thisPtr);
CExoString CERFString__GetText(CERFString* thisPtr);
int32_t CERFString__Read(CERFString* thisPtr);
int32_t CERFString__Reset(CERFString* thisPtr);
void CERFString__SetText(CERFString* thisPtr, CExoString&);
int32_t CERFString__Write(CERFString* thisPtr, CExoFile&);

}

}
