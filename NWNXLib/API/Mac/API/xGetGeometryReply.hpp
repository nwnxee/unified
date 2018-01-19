#pragma once

#include <cstdint>

#include "unknown_CARD8.hpp"

namespace NWNXLib {

namespace API {

struct xGetGeometryReply
{
    CARD8 type;
    uint8_t depth;
    uint16_t sequenceNumber;
    uint32_t length;
    uint32_t root;
    int16_t x;
    int16_t y;
    uint16_t width;
    uint16_t height;
    uint16_t borderWidth;
    uint16_t pad1;
    uint32_t pad2;
    uint32_t pad3;
};

}

}
