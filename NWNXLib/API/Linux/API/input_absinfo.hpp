#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct input_absinfo
{
    int32_t value;
    int32_t minimum;
    int32_t maximum;
    int32_t fuzz;
    int32_t flat;
    int32_t resolution;
};

}

}
