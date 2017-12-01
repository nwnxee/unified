#pragma once

#include <cstdint>

#include "unknown_CHATBool.hpp"

namespace NWNXLib {

namespace API {

struct GETCKEYData
{
    int32_t num;
    char** keys;
    CHATBool channel;
    CHATBool allBroadcastKeys;
};

}

}
