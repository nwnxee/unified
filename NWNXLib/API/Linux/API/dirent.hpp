#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct dirent
{
    uint32_t d_ino;
    int32_t d_off;
    uint16_t d_reclen;
    uint8_t d_type;
    char d_name[256];
};

}

}
