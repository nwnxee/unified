#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct tempbuf
{
    char* buf;
    uint32_t len;
    int32_t type;
};

}

}
