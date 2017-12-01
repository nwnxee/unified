#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct ciCallbackChannelMessageParams
{
    char* channel;
    char* user;
    char* message;
    int32_t type;
};

}

}
