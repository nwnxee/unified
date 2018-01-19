#pragma once

#include <cstdint>

#include "unknown_CARD8.hpp"

namespace NWNXLib {

namespace API {

struct xGrabPointerReply
{
    CARD8 type;
    CARD8 status;
    uint16_t sequenceNumber;
    uint32_t length;
    uint32_t pad1;
    uint32_t pad2;
    uint32_t pad3;
    uint32_t pad4;
    uint32_t pad5;
    uint32_t pad6;
};

}

}
