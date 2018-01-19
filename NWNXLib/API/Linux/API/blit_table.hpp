#pragma once

#include <cstdint>

#include "unknown_SDL2_BlitFunc.hpp"
#include "unknown_TLS_320BA70ECA43DCC2AFAF891964572EC6.hpp"

namespace NWNXLib {

namespace API {

struct blit_table
{
    uint32_t srcR;
    uint32_t srcG;
    uint32_t srcB;
    int32_t dstbpp;
    uint32_t dstR;
    uint32_t dstG;
    uint32_t dstB;
    uint32_t blit_features;
    SDL2_BlitFunc blitfunc;
    TLS_320BA70ECA43DCC2AFAF891964572EC6 alpha;
};

}

}
