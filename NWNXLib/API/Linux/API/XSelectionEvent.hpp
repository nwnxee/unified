#pragma once

#include <cstdint>

#include "unknown_XID.hpp"
#include "unknown__XDisplay.hpp"

namespace NWNXLib {

namespace API {

struct XSelectionEvent
{
    int32_t type;
    uint32_t serial;
    int32_t send_event;
    _XDisplay* display;
    XID requestor;
    uint32_t selection;
    uint32_t target;
    uint32_t property;
    uint32_t time;
};

}

}
