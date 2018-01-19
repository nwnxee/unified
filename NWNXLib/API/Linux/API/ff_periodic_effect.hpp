#pragma once

#include <cstdint>

#include "ff_envelope.hpp"

namespace NWNXLib {

namespace API {

struct ff_periodic_effect
{
    uint16_t waveform;
    uint16_t period;
    int16_t magnitude;
    int16_t offset;
    uint16_t phase;
    ff_envelope envelope;
    uint32_t custom_len;
    int16_t* custom_data;
};

}

}
