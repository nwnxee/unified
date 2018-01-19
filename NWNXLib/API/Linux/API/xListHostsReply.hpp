#pragma once

#include <cstdint>

#include "unknown_CARD8.hpp"

namespace NWNXLib {

namespace API {

struct xListHostsReply
{
    CARD8 type;
    CARD8 enabled;
    uint16_t sequenceNumber;
    uint32_t length;
    uint16_t nHosts;
    uint16_t pad1;
    uint32_t pad3;
    uint32_t pad4;
    uint32_t pad5;
    uint32_t pad6;
    uint32_t pad7;
};

}

}
