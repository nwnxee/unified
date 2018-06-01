#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct RGB2YUVFactors
{
    int32_t y_offset;
    float y[3];
    float u[3];
    float v[3];
};

}

}
