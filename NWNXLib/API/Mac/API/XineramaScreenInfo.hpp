#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct XineramaScreenInfo
{
    int32_t screen_number;
    int16_t x_org;
    int16_t y_org;
    int16_t width;
    int16_t height;
};

}

}
