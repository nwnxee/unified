#pragma once

#include <cstdint>

#include "unknown_SDL_BlitFunc.hpp"

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
    SDL_BlitFunc blitfunc;
    uint32_t alpha;
};

}

}
