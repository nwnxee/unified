#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct XIValuatorState
{
    int32_t mask_len;
    uint8_t* mask;
    double* values;
};

}

}
