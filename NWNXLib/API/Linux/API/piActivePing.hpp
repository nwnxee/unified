#pragma once

#include <cstdint>

#include "unknown_PINGERBool.hpp"
#include "unknown_pingerGotPing.hpp"

namespace NWNXLib {

namespace API {

struct piActivePing
{
    PINGERBool originator;
    uint16_t ID;
    uint16_t expectedTrip;
    uint32_t timestamp;
    uint32_t timeout;
    uint32_t remoteIP;
    uint16_t remotePort;
    pingerGotPing reply;
    void* replyParam;
};

}

}
