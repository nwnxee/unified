#pragma once

#include <cstdint>

#include "unknown___quad_t.hpp"

namespace NWNXLib {

namespace API {

struct flock
{
    int16_t l_type;
    int16_t l_whence;
    __quad_t l_start;
    __quad_t l_len;
    int32_t l_pid;
};

}

}
