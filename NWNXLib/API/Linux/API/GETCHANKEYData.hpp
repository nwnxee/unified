#pragma once

#include <cstdint>

#include "unknown_CHATBool.hpp"

namespace NWNXLib {

namespace API {

struct GETCHANKEYData
{
    int32_t num;
    char** keys;
    CHATBool allBroadcastKeys;
};

}

}
