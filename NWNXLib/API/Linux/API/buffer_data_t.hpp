#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct buffer_data_t
{
    const char* data;
    uint32_t len;
    uint32_t pos;
};

}

}
