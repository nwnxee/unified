#pragma once

#include <cstdint>

#include "unknown_CHATBool.hpp"

namespace NWNXLib {

namespace API {

struct ciCallbackEnumChannelsAllParams
{
    CHATBool success;
    int32_t numChannels;
    char** channels;
    char** topics;
    int32_t* numUsers;
};

}

}
