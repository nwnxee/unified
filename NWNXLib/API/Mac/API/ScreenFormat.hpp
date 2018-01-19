#pragma once

#include <cstdint>

#include "unknown__XExtData.hpp"

namespace NWNXLib {

namespace API {

struct ScreenFormat
{
    _XExtData* ext_data;
    int32_t depth;
    int32_t bits_per_pixel;
    int32_t scanline_pad;
};

}

}
