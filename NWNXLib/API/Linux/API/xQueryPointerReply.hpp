#pragma once

#include <cstdint>

#include "unknown_CARD8.hpp"

namespace NWNXLib {

namespace API {

struct xQueryPointerReply
{
    CARD8 type;
    CARD8 sameScreen;
    uint16_t sequenceNumber;
    uint32_t length;
    uint32_t root;
    uint32_t child;
    int16_t rootX;
    int16_t rootY;
    int16_t winX;
    int16_t winY;
    uint16_t mask;
    uint16_t pad1;
    uint32_t pad;
};

}

}
