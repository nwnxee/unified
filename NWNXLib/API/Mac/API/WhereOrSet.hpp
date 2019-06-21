#pragma once

#include <cstdint>

#include "WhereOrCost.hpp"

namespace NWNXLib {

namespace API {

struct WhereOrSet
{
    uint16_t n;
    WhereOrCost a[3];
};

}

}
