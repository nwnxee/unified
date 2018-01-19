#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct RLEDestFormat
{
    uint8_t BytesPerPixel;
    uint8_t padding[3];
    uint32_t Rmask;
    uint32_t Gmask;
    uint32_t Bmask;
    uint32_t Amask;
    uint8_t Rloss;
    uint8_t Gloss;
    uint8_t Bloss;
    uint8_t Aloss;
    uint8_t Rshift;
    uint8_t Gshift;
    uint8_t Bshift;
    uint8_t Ashift;
};

}

}
