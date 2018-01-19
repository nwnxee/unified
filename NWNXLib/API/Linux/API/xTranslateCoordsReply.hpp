#pragma once

#include <cstdint>

#include "unknown_CARD8.hpp"

namespace NWNXLib {

namespace API {

struct xTranslateCoordsReply
{
    CARD8 type;
    CARD8 sameScreen;
    uint16_t sequenceNumber;
    uint32_t length;
    uint32_t child;
    int16_t dstX;
    int16_t dstY;
    uint32_t pad2;
    uint32_t pad3;
    uint32_t pad4;
    uint32_t pad5;
};

}

}
