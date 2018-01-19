#pragma once

#include <cstdint>

#include "unknown_CARD8.hpp"

namespace NWNXLib {

namespace API {

struct xError
{
    CARD8 type;
    CARD8 errorCode;
    uint16_t sequenceNumber;
    uint32_t resourceID;
    uint16_t minorCode;
    uint8_t majorCode;
    CARD8 pad1;
    uint32_t pad3;
    uint32_t pad4;
    uint32_t pad5;
    uint32_t pad6;
    uint32_t pad7;
};

}

}
