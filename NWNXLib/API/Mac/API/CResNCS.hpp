#pragma once

#include <cstdint>

#include "CRes.hpp"

namespace NWNXLib {

namespace API {

struct CResNCS
    : CRes
{
    int32_t m_bLoaded;
    uint32_t m_nNCSNormalSize;
    uint8_t* m_pNCSData;

    // The below are auto generated stubs.
    CResNCS(const CResNCS&) = default;
    CResNCS& operator=(const CResNCS&) = default;

    CResNCS();
    ~CResNCS();
    unsigned char* GetNCSDataPtr();
    uint32_t GetNCSSize();
    int32_t IsLoaded();
    int32_t OnResourceFreed();
    int32_t OnResourceServiced();
};

void CResNCS__CResNCSCtor__0(CResNCS* thisPtr);
void CResNCS__CResNCSDtor__0(CResNCS* thisPtr);
unsigned char* CResNCS__GetNCSDataPtr(CResNCS* thisPtr);
uint32_t CResNCS__GetNCSSize(CResNCS* thisPtr);
int32_t CResNCS__IsLoaded(CResNCS* thisPtr);
int32_t CResNCS__OnResourceFreed(CResNCS* thisPtr);
int32_t CResNCS__OnResourceServiced(CResNCS* thisPtr);

}

}
