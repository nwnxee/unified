#pragma once

#include <cstdint>

#include "unknown_CHATBool.hpp"

namespace NWNXLib {

namespace API {

struct ciCallbackGetChannelBasicUserInfoParams
{
    CHATBool success;
    char* channel;
    char* nick;
    char* user;
    char* address;
};

}

}
