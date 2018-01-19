#pragma once

#include <cstdint>

#include "timeval.hpp"

namespace NWNXLib {

namespace API {

struct input_event
{
    timeval time;
    uint16_t type;
    uint16_t code;
    int32_t value;
};

}

}
