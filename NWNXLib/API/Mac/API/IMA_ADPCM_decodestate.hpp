#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct IMA_ADPCM_decodestate
{
    int32_t sample;
    int8_t index;
};

}

}
