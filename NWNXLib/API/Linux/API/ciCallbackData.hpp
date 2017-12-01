#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct ciCallbackData
{
    int32_t type;
    void* callback;
    void* callbackParams;
    void* param;
    int32_t ID;
    char* channel;
};

}

}
