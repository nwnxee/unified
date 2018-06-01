#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct YUV2RGBParam
{
    uint8_t y_shift;
    int16_t y_factor;
    int16_t v_r_factor;
    int16_t u_g_factor;
    int16_t v_g_factor;
    int16_t u_b_factor;
};

}

}
