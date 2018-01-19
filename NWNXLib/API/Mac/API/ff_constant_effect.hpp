#pragma once

#include <cstdint>

#include "ff_envelope.hpp"

namespace NWNXLib {

namespace API {

struct ff_constant_effect
{
    int16_t level;
    ff_envelope envelope;
};

}

}
