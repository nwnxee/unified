#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct asprintf
{
    char* buffer;
    uint32_t len;
    uint32_t alloc;
    int32_t fail;
};

}

}
