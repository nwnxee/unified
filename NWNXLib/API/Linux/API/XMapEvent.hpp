#pragma once

#include <cstdint>

#include "unknown_XID.hpp"
#include "unknown__XDisplay.hpp"

namespace NWNXLib {

namespace API {

struct XMapEvent
{
    int32_t type;
    uint32_t serial;
    int32_t send_event;
    _XDisplay* display;
    XID event;
    XID window;
    int32_t override_redirect;
};

}

}
