#pragma once

#include <cstdint>

#include "unknown__XExtData.hpp"

namespace NWNXLib {

namespace API {

struct Visual
{
    _XExtData* ext_data;
    uint32_t visualid;
    int32_t _class;
    uint32_t red_mask;
    uint32_t green_mask;
    uint32_t blue_mask;
    int32_t bits_per_rgb;
    int32_t map_entries;
};

}

}
