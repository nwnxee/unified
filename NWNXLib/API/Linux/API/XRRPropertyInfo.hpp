#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct XRRPropertyInfo
{
    int32_t pending;
    int32_t range;
    int32_t immutable;
    int32_t num_values;
    int32_t* values;
};

}

}
