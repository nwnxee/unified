#pragma once

#include <cstdint>

#include "flex_unit.hpp"

namespace NWNXLib {

namespace API {

struct MS_RSAVLong_value
    : flex_unit
{
    uint32_t share;
};

}

}
