#pragma once

#include <cstdint>

#include "CRes.hpp"

namespace NWNXLib {

namespace API {

struct CResPWK
    : CRes
{
    int32_t m_bLoaded;
    uint32_t m_nPWKNormalSize;
    uint8_t* m_pPWKData;

    // The below are auto generated stubs.
    CResPWK(const CResPWK&) = default;
    CResPWK& operator=(const CResPWK&) = default;

    CResPWK();
    ~CResPWK();
    unsigned char* GetPWKDataPtr();
    uint32_t GetPWKSize();
    int32_t IsLoaded();
    int32_t OnResourceFreed();
    int32_t OnResourceServiced();
};

void CResPWK__CResPWKCtor__0(CResPWK* thisPtr);
void CResPWK__CResPWKDtor__0(CResPWK* thisPtr);
unsigned char* CResPWK__GetPWKDataPtr(CResPWK* thisPtr);
uint32_t CResPWK__GetPWKSize(CResPWK* thisPtr);
int32_t CResPWK__IsLoaded(CResPWK* thisPtr);
int32_t CResPWK__OnResourceFreed(CResPWK* thisPtr);
int32_t CResPWK__OnResourceServiced(CResPWK* thisPtr);

}

}
