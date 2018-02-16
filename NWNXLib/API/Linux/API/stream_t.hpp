#pragma once

#include <cstdint>

#include "unknown_get_func.hpp"

namespace NWNXLib {

namespace API {

struct stream_t
{
    get_func get;
    void* data;
    char buffer[5];
    uint32_t buffer_pos;
    int32_t state;
    int32_t line;
    int32_t column;
    int32_t last_column;
    uint32_t position;
};

}

}
