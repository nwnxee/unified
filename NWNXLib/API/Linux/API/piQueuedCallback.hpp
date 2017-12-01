#pragma once

#include <cstdint>

#include "unknown_pingerGotPing.hpp"

namespace NWNXLib {

namespace API {

struct piQueuedCallback
{
    uint32_t IP;
    uint16_t port;
    int32_t ping;
    char* data;
    int32_t len;
    void* param;
    pingerGotPing callback;
};

}

}
