#pragma once

#include <cstdint>

#include "unknown_CHATBool.hpp"

namespace NWNXLib {

namespace API {

struct ciCallbackEnumChannelBansParams
{
    CHATBool success;
    char* channel;
    int32_t numBans;
    char** bans;
};

}

}
