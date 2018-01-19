#pragma once

#include <cstdint>

#include "IMA_ADPCM_decodestate.hpp"
#include "WaveFMT.hpp"

namespace NWNXLib {

namespace API {

struct IMA_ADPCM_decoder
{
    WaveFMT wavefmt;
    uint16_t wSamplesPerBlock;
    IMA_ADPCM_decodestate state[2];
};

}

}
