#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct ciCallbackBroadcastKeyChangedParams
{
    char* channel;
    char* user;
    char* key;
    char* value;
};

}

}
