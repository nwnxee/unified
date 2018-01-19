#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct ff_condition_effect
{
    uint16_t right_saturation;
    uint16_t left_saturation;
    int16_t right_coeff;
    int16_t left_coeff;
    uint16_t deadband;
    int16_t center;
};

}

}
