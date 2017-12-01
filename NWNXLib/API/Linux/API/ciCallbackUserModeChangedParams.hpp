#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct ciCallbackUserModeChangedParams
{
    char* channel;
    char* user;
    int32_t mode;
};

}

}
