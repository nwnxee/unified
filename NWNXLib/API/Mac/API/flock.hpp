#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct flock
{
    int16_t l_type;
    int16_t l_whence;
    int32_t l_start;
    int32_t l_len;
    int32_t l_pid;
};

}

}
