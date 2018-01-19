#pragma once

#include <cstdint>

#include "unknown_StereoType.hpp"
#include "unknown_TLS_83F1A5C51A5EAE819F547DC1FDDED4CC.hpp"

namespace NWNXLib {

namespace API {

struct DetailedTiming
{
    int32_t pixel_clock;
    int32_t h_addr;
    int32_t h_blank;
    int32_t h_sync;
    int32_t h_front_porch;
    int32_t v_addr;
    int32_t v_blank;
    int32_t v_sync;
    int32_t v_front_porch;
    int32_t width_mm;
    int32_t height_mm;
    int32_t right_border;
    int32_t top_border;
    int32_t interlaced;
    StereoType stereo;
    int32_t digital_sync;
    TLS_83F1A5C51A5EAE819F547DC1FDDED4CC _anon_0;
};

}

}
