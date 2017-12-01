#pragma once

#include <cstdint>

#include "unknown_CHATBool.hpp"

namespace NWNXLib {

namespace API {

struct ciCallbackGetChannelKeysParams
{
    CHATBool success;
    char* channel;
    char* user;
    int32_t num;
    char** keys;
    char** values;
};

}

}
