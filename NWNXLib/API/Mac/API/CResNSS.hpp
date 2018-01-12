#pragma once

#include <cstdint>

#include "CRes.hpp"

namespace NWNXLib {

namespace API {

struct CResNSS
    : CRes
{
    int32_t m_bLoaded;
    uint32_t m_nNSSNormalSize;
    uint8_t* m_pNSSData;

    // The below are auto generated stubs.
    CResNSS(const CResNSS&) = default;
    CResNSS& operator=(const CResNSS&) = default;

    CResNSS();
    ~CResNSS();
    unsigned char* GetNSSDataPtr();
    uint32_t GetNSSSize();
    int32_t IsLoaded();
    int32_t OnResourceFreed();
    int32_t OnResourceServiced();
};

void CResNSS__CResNSSCtor__0(CResNSS* thisPtr);
void CResNSS__CResNSSDtor__0(CResNSS* thisPtr);
unsigned char* CResNSS__GetNSSDataPtr(CResNSS* thisPtr);
uint32_t CResNSS__GetNSSSize(CResNSS* thisPtr);
int32_t CResNSS__IsLoaded(CResNSS* thisPtr);
int32_t CResNSS__OnResourceFreed(CResNSS* thisPtr);
int32_t CResNSS__OnResourceServiced(CResNSS* thisPtr);

}

}
