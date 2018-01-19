#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct Visual;

struct Depth
{
    int32_t depth;
    int32_t nvisuals;
    Visual* visuals;
};

}

}
