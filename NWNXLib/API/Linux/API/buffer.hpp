#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct buffer
{
    const uint32_t size;
    uint32_t used;
    char* data;
};

}

}
