#pragma once

#include <cstdint>

#include "unknown_u64.hpp"

namespace NWNXLib {

namespace API {

struct WhereOrCost
{
    u64 prereq;
    int16_t rRun;
    int16_t nOut;
};

}

}
