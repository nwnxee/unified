#pragma once

#include <cstdint>

#include "unknown_CARD8.hpp"

namespace NWNXLib {

namespace API {

struct xQueryTreeReply
{
    CARD8 type;
    CARD8 pad1;
    uint16_t sequenceNumber;
    uint32_t length;
    uint32_t root;
    uint32_t parent;
    uint16_t nChildren;
    uint16_t pad2;
    uint32_t pad3;
    uint32_t pad4;
    uint32_t pad5;
};

}

}
