#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct LookasideSlot;

struct Lookaside
{
    uint32_t bDisable;
    uint16_t sz;
    uint8_t bMalloced;
    uint32_t nSlot;
    uint32_t anStat[3];
    LookasideSlot* pInit;
    LookasideSlot* pFree;
    void* pStart;
    void* pEnd;
};

}

}
