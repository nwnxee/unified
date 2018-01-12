#pragma once

#include <cstdint>

#include "CExoString.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CExoIniInternal;

struct CExoIni
{
    CExoIniInternal* m_pcExoIniInternal;

    // The below are auto generated stubs.
    CExoIni() = default;
    CExoIni(const CExoIni&) = default;
    CExoIni& operator=(const CExoIni&) = default;

    CExoIni(CExoString);
    ~CExoIni();
    int32_t ReadIniEntry(CExoString&, const int32_t&, const CExoString&, const CExoString&);
    int32_t WriteIniEntry(const CExoString&, const int32_t&, const CExoString&, const CExoString&);
};

void CExoIni__CExoIniCtor__0(CExoIni* thisPtr, CExoString);
void CExoIni__CExoIniDtor__0(CExoIni* thisPtr);
int32_t CExoIni__ReadIniEntry(CExoIni* thisPtr, CExoString&, const int32_t&, const CExoString&, const CExoString&);
int32_t CExoIni__WriteIniEntry(CExoIni* thisPtr, const CExoString&, const int32_t&, const CExoString&, const CExoString&);

}

}
