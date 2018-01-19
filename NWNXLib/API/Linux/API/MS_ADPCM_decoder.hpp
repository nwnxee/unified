#pragma once

#include <cstdint>

#include "MS_ADPCM_decodestate.hpp"
#include "WaveFMT.hpp"

namespace NWNXLib {

namespace API {

struct MS_ADPCM_decoder
{
    WaveFMT wavefmt;
    uint16_t wSamplesPerBlock;
    uint16_t wNumCoef;
    int16_t aCoeff[7][2];
    MS_ADPCM_decodestate state[2];
};

}

}
