#pragma once

#include <cstdint>

#include "unknown_TLS_18C5643EE2D4CB873001FB92DAAED575.hpp"
#include "unknown_XID.hpp"
#include "unknown__XDisplay.hpp"

namespace NWNXLib {

namespace API {

struct XClientMessageEvent
{
    int32_t type;
    uint32_t serial;
    int32_t send_event;
    _XDisplay* display;
    XID window;
    uint32_t message_type;
    int32_t format;
    TLS_18C5643EE2D4CB873001FB92DAAED575 data;
};

}

}
