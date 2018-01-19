#pragma once

#include <cstdint>

#include "CRes.hpp"

namespace NWNXLib {

namespace API {

struct CResDWK
    : CRes
{
    int32_t m_bLoaded;
    uint32_t m_nDWKNormalSize;
    uint8_t* m_pDWKData;

    // The below are auto generated stubs.
    CResDWK(const CResDWK&) = default;
    CResDWK& operator=(const CResDWK&) = default;

    CResDWK();
    ~CResDWK();
    unsigned char* GetDWKDataPtr();
    uint32_t GetDWKSize();
    int32_t IsLoaded();
    int32_t OnResourceFreed();
    int32_t OnResourceServiced();
};

void CResDWK__CResDWKCtor__0(CResDWK* thisPtr);
void CResDWK__CResDWKDtor__0(CResDWK* thisPtr);
unsigned char* CResDWK__GetDWKDataPtr(CResDWK* thisPtr);
uint32_t CResDWK__GetDWKSize(CResDWK* thisPtr);
int32_t CResDWK__IsLoaded(CResDWK* thisPtr);
int32_t CResDWK__OnResourceFreed(CResDWK* thisPtr);
int32_t CResDWK__OnResourceServiced(CResDWK* thisPtr);

}

}
