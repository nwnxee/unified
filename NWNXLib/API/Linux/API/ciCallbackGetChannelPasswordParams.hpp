#pragma once

#include <cstdint>

#include "unknown_CHATBool.hpp"

namespace NWNXLib {

namespace API {

struct ciCallbackGetChannelPasswordParams
{
    CHATBool success;
    char* channel;
    CHATBool enabled;
    char* password;
};

}

}
