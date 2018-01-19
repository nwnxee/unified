#pragma once

#include <cstdint>

#include "unknown_CARD8.hpp"

namespace NWNXLib {

namespace API {

struct xGetPropertyReply
{
    CARD8 type;
    uint8_t format;
    uint16_t sequenceNumber;
    uint32_t length;
    uint32_t propertyType;
    uint32_t bytesAfter;
    uint32_t nItems;
    uint32_t pad1;
    uint32_t pad2;
    uint32_t pad3;
};

}

}
