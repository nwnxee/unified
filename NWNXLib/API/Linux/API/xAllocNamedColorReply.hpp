#pragma once

#include <cstdint>

#include "unknown_CARD8.hpp"

namespace NWNXLib {

namespace API {

struct xAllocNamedColorReply
{
    CARD8 type;
    CARD8 pad1;
    uint16_t sequenceNumber;
    uint32_t length;
    uint32_t pixel;
    uint16_t exactRed;
    uint16_t exactGreen;
    uint16_t exactBlue;
    uint16_t screenRed;
    uint16_t screenGreen;
    uint16_t screenBlue;
    uint32_t pad2;
    uint32_t pad3;
};

}

}
