#pragma once

#include <cstdint>

#include "WaveFMT.hpp"

namespace NWNXLib {

namespace API {

struct WaveExtensibleFMT
{
    WaveFMT format;
    uint16_t size;
    uint16_t validbits;
    uint32_t channelmask;
    uint8_t subformat[16];
};

}

}
