#pragma once

#include <cstdint>

#include "unknown_CHATBool.hpp"
#include "unknown_CHATEnterResult.hpp"

namespace NWNXLib {

namespace API {

struct ciCallbackEnterChannelParams
{
    CHATBool success;
    CHATEnterResult result;
    char* channel;
};

}

}
