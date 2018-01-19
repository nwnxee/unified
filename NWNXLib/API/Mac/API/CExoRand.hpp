#pragma once

#include <cstdint>

#include "CExoString.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CExoRandInternal;

struct CExoRand
{
    CExoRandInternal* m_pcExoRandInternal;

    // The below are auto generated stubs.
    CExoRand(const CExoRand&) = default;
    CExoRand& operator=(const CExoRand&) = default;

    CExoRand();
    ~CExoRand();
    CExoString GetString(uint16_t);
    uint32_t Rand();
    void SignalEvent();
    void SignalEvent(uint32_t);
};

void CExoRand__CExoRandCtor__0(CExoRand* thisPtr);
void CExoRand__CExoRandDtor__0(CExoRand* thisPtr);
CExoString CExoRand__GetString(CExoRand* thisPtr, uint16_t);
uint32_t CExoRand__Rand(CExoRand* thisPtr);
void CExoRand__SignalEvent__0(CExoRand* thisPtr);
void CExoRand__SignalEvent__1(CExoRand* thisPtr, uint32_t);

}

}
