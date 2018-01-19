#pragma once

#include <cstdint>

#include "unknown_XID.hpp"
#include "unknown__XDisplay.hpp"

namespace NWNXLib {

namespace API {

struct XButtonEvent
{
    int32_t type;
    uint32_t serial;
    int32_t send_event;
    _XDisplay* display;
    XID window;
    XID root;
    XID subwindow;
    uint32_t time;
    int32_t x;
    int32_t y;
    int32_t x_root;
    int32_t y_root;
    uint32_t state;
    uint32_t button;
    int32_t same_screen;
};

}

}
