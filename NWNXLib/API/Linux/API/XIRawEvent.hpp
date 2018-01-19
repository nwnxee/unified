#pragma once

#include <cstdint>

#include "XIValuatorState.hpp"
#include "unknown__XDisplay.hpp"

namespace NWNXLib {

namespace API {

struct XIRawEvent
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
    int32_t flags;
    XIValuatorState valuators;
    double* raw_values;
};

}

}
