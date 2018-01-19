#pragma once

#include <cstdint>

#include "ff_replay.hpp"
#include "ff_trigger.hpp"
#include "unknown_TLS_10E9238F90CDC863A5F6C06770EDDDCB.hpp"

namespace NWNXLib {

namespace API {

struct ff_effect
{
    uint16_t type;
    int16_t id;
    uint16_t direction;
    ff_trigger trigger;
    ff_replay replay;
    TLS_10E9238F90CDC863A5F6C06770EDDDCB u;
};

}

}
