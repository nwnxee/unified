#pragma once

#include <cstdint>

#include "unknown_XID.hpp"
#include "unknown__XDisplay.hpp"

namespace NWNXLib {

namespace API {

struct XMapRequestEvent
{
    int32_t type;
    uint32_t serial;
    int32_t send_event;
    _XDisplay* display;
    XID parent;
    XID window;
};

}

}
