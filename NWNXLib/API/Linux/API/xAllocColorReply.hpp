#pragma once

#include <cstdint>

#include "unknown_CARD8.hpp"

namespace NWNXLib {

namespace API {

struct xAllocColorReply
{
    CARD8 type;
    CARD8 pad1;
    uint16_t sequenceNumber;
    uint32_t length;
    uint16_t red;
    uint16_t green;
    uint16_t blue;
    uint16_t pad2;
    uint32_t pixel;
    uint32_t pad3;
    uint32_t pad4;
    uint32_t pad5;
};

}

}
