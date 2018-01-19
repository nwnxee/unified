#pragma once

#include <cstdint>

#include "ff_envelope.hpp"

namespace NWNXLib {

namespace API {

struct ff_ramp_effect
{
    int16_t start_level;
    int16_t end_level;
    ff_envelope envelope;
};

}

}
