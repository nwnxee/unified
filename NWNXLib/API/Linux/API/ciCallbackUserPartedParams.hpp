#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct ciCallbackUserPartedParams
{
    char* channel;
    char* user;
    int32_t why;
    char* reason;
    char* kicker;
};

}

}
