#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct et_info
{
    char fmttype;
    uint8_t base;
    uint8_t flags;
    uint8_t type;
    uint8_t charset;
    uint8_t prefix;
};

}

}
