#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct WaveFMT
{
    uint16_t encoding;
    uint16_t channels;
    uint32_t frequency;
    uint32_t byterate;
    uint16_t blockalign;
    uint16_t bitspersample;
};

}

}
