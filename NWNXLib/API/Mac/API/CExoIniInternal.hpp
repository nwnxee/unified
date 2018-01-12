#pragma once

#include <cstdint>

#include "CExoString.hpp"

namespace NWNXLib {

namespace API {

struct CExoIniInternal
{
    CExoString* m_pFileNames;

    // The below are auto generated stubs.
    CExoIniInternal() = default;
    CExoIniInternal(const CExoIniInternal&) = default;
    CExoIniInternal& operator=(const CExoIniInternal&) = default;

    CExoIniInternal(CExoString);
    ~CExoIniInternal();
    int32_t ReadIniEntry(CExoString&, const int32_t&, const CExoString&, const CExoString&);
    int32_t WriteIniEntry(const CExoString&, const int32_t&, const CExoString&, const CExoString&);
};

void CExoIniInternal__CExoIniInternalCtor__0(CExoIniInternal* thisPtr, CExoString);
void CExoIniInternal__CExoIniInternalDtor__0(CExoIniInternal* thisPtr);
int32_t CExoIniInternal__ReadIniEntry(CExoIniInternal* thisPtr, CExoString&, const int32_t&, const CExoString&, const CExoString&);
int32_t CExoIniInternal__WriteIniEntry(CExoIniInternal* thisPtr, const CExoString&, const int32_t&, const CExoString&, const CExoString&);

}

}
