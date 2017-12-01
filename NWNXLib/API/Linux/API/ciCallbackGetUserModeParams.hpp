#pragma once

#include <cstdint>

#include "unknown_CHATBool.hpp"

namespace NWNXLib {

namespace API {

struct ciCallbackGetUserModeParams
{
    CHATBool success;
    char* channel;
    char* user;
    int32_t mode;
};

}

}
