#pragma once

#include <cstdint>

#include "unknown_z_Byte.hpp"

namespace NWNXLib {

namespace API {

struct z_gz_header_s
{
    int32_t text;
    uint32_t time;
    int32_t xflags;
    int32_t os;
    z_Byte* extra;
    uint32_t extra_len;
    uint32_t extra_max;
    z_Byte* name;
    uint32_t name_max;
    z_Byte* comment;
    uint32_t comm_max;
    int32_t hcrc;
    int32_t done;
};

}

}
