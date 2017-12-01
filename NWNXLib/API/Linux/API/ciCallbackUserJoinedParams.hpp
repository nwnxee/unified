#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct ciCallbackUserJoinedParams
{
    char* channel;
    char* user;
    int32_t mode;
};

}

}
