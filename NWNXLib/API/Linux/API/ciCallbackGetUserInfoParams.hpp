#pragma once

#include <cstdint>

#include "unknown_CHATBool.hpp"

namespace NWNXLib {

namespace API {

struct ciCallbackGetUserInfoParams
{
    CHATBool success;
    char* nick;
    char* user;
    char* name;
    char* address;
    int32_t numChannels;
    char** channels;
};

}

}
