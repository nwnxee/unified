#pragma once

#include <cstdint>

#include "unknown_u64.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct WhereLoop;

struct WherePath
{
    u64 maskLoop;
    u64 revLoop;
    int16_t nRow;
    int16_t rCost;
    int16_t rUnsorted;
    char isOrdered;
    WhereLoop** aLoop;
};

}

}
