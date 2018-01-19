#pragma once

#include <cstdint>

#include "unknown_CARD8.hpp"

namespace NWNXLib {

namespace API {

struct xAllocColorPlanesReply
{
    CARD8 type;
    CARD8 pad1;
    uint16_t sequenceNumber;
    uint32_t length;
    uint16_t nPixels;
    uint16_t pad2;
    uint32_t redMask;
    uint32_t greenMask;
    uint32_t blueMask;
    uint32_t pad3;
    uint32_t pad4;
};

}

}
