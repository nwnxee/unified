#pragma once

#include <cstdint>

#include "unknown___quad_t.hpp"
#include "unknown___u_quad_t.hpp"

namespace NWNXLib {

namespace API {

struct dirent
{
    __u_quad_t d_ino;
    __quad_t d_off;
    uint16_t d_reclen;
    uint8_t d_type;
    char d_name[256];
};

}

}
