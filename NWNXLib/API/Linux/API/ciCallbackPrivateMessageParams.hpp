#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct ciCallbackPrivateMessageParams
{
    char* user;
    char* message;
    int32_t type;
};

}

}
