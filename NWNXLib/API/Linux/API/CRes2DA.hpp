#pragma once

#include <cstdint>

#include "CRes.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct Exo2DAHeader_st;

struct CRes2DA
    : CRes
{
    int32_t m_bLoaded;
    uint32_t m_n2DANormalSize;
    uint8_t* m_p2DAData;
    Exo2DAHeader_st* m_p2DAHeader;

    // The below are auto generated stubs.
    CRes2DA(const CRes2DA&) = default;
    CRes2DA& operator=(const CRes2DA&) = default;

    CRes2DA();
    ~CRes2DA();
    unsigned char* Get2DADataPtr();
    Exo2DAHeader_st* Get2DAHeaderPtr();
    uint32_t Get2DASize();
    int32_t IsLoaded();
    int32_t OnResourceFreed();
    int32_t OnResourceServiced();
};

void CRes2DA__CRes2DACtor(CRes2DA* thisPtr);
void CRes2DA__CRes2DADtor__0(CRes2DA* thisPtr);
unsigned char* CRes2DA__Get2DADataPtr(CRes2DA* thisPtr);
Exo2DAHeader_st* CRes2DA__Get2DAHeaderPtr(CRes2DA* thisPtr);
uint32_t CRes2DA__Get2DASize(CRes2DA* thisPtr);
int32_t CRes2DA__IsLoaded(CRes2DA* thisPtr);
int32_t CRes2DA__OnResourceFreed(CRes2DA* thisPtr);
int32_t CRes2DA__OnResourceServiced(CRes2DA* thisPtr);

}

}
