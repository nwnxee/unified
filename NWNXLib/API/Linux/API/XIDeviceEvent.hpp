#pragma once

#include <cstdint>

#include "XIButtonState.hpp"
#include "XIModifierState.hpp"
#include "XIValuatorState.hpp"
#include "unknown_XID.hpp"
#include "unknown__XDisplay.hpp"

namespace NWNXLib {

namespace API {

struct XIDeviceEvent
{
    int32_t type;
    uint32_t serial;
    int32_t send_event;
    _XDisplay* display;
    int32_t extension;
    int32_t evtype;
    uint32_t time;
    int32_t deviceid;
    int32_t sourceid;
    int32_t detail;
    XID root;
    XID event;
    XID child;
    double root_x;
    double root_y;
    double event_x;
    double event_y;
    int32_t flags;
    XIButtonState buttons;
    XIValuatorState valuators;
    XIModifierState mods;
    XIModifierState group;
};

}

}
