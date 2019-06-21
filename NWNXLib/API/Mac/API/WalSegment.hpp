#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct WalSegment
{
    int32_t iNext;
    uint16_t* aIndex;
    uint32_t* aPgno;
    int32_t nEntry;
    int32_t iZero;
};

}

}
