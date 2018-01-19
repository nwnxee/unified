#pragma once

#include <cstdint>

#include "unknown__XDisplay.hpp"

namespace NWNXLib {

namespace API {

struct XErrorEvent
{
    int32_t type;
    _XDisplay* display;
    uint32_t resourceid;
    uint32_t serial;
    uint8_t error_code;
    uint8_t request_code;
    uint8_t minor_code;
};

}

}
