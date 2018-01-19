#pragma once

#include <cstdint>

#include "unknown_XID.hpp"
#include "unknown__XDisplay.hpp"

namespace NWNXLib {

namespace API {

struct XCreateWindowEvent
{
    int32_t type;
    uint32_t serial;
    int32_t send_event;
    _XDisplay* display;
    XID parent;
    XID window;
    int32_t x;
    int32_t y;
    int32_t width;
    int32_t height;
    int32_t border_width;
    int32_t override_redirect;
};

}

}
