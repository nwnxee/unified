#pragma once

#include <cstdint>

#include "unknown_CHATBool.hpp"

namespace NWNXLib {

namespace API {

struct ciCallbackEnumChannelsEachParams
{
    CHATBool success;
    int32_t index;
    char* channel;
    char* topic;
    int32_t numUsers;
    void* param;
};

}

}
