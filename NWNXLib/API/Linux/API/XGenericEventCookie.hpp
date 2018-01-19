#pragma once

#include <cstdint>

#include "unknown__XDisplay.hpp"

namespace NWNXLib {

namespace API {

struct XGenericEventCookie
{
    int32_t type;
    uint32_t serial;
    int32_t send_event;
    _XDisplay* display;
    int32_t extension;
    int32_t evtype;
    uint32_t cookie;
    void* data;
};

}

}
