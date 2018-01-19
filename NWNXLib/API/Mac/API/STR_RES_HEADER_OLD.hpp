#pragma once

#include <cstdint>

#include "unknown__BYTE.hpp"

namespace NWNXLib {

namespace API {

struct STR_RES_HEADER_OLD
{
    uint32_t wFlags;
    char sndResRef[1];
    _BYTE gap5[15];
    uint32_t volumeVariance;
    uint32_t pitchVariance;
    uint32_t offsetToStr;
    uint32_t strSize;
};

}

}
