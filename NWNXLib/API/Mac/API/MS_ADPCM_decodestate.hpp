#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct MS_ADPCM_decodestate
{
    uint8_t hPredictor;
    uint16_t iDelta;
    int16_t iSamp1;
    int16_t iSamp2;
};

}

}
