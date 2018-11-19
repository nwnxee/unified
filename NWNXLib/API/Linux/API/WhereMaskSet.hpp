#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct WhereMaskSet
{
    int32_t bVarSelect;
    int32_t n;
    int32_t ix[64];
};

}

}
