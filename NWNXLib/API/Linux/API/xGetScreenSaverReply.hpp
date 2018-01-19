#pragma once

#include <cstdint>

#include "unknown_CARD8.hpp"

namespace NWNXLib {

namespace API {

struct xGetScreenSaverReply
{
    CARD8 type;
    CARD8 pad1;
    uint16_t sequenceNumber;
    uint32_t length;
    uint16_t timeout;
    uint16_t interval;
    CARD8 preferBlanking;
    CARD8 allowExposures;
    uint16_t pad2;
    uint32_t pad3;
    uint32_t pad4;
    uint32_t pad5;
    uint32_t pad6;
};

}

}
