#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct RGB2YUVParam
{
    uint8_t y_shift;
    int16_t matrix[3][3];
};

}

}
