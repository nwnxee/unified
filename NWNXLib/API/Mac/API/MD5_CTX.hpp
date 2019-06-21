#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct MD5_CTX
{
    uint32_t lo;
    uint32_t hi;
    uint32_t a;
    uint32_t b;
    uint32_t c;
    uint32_t d;
    uint8_t buffer[64];
    uint32_t block[16];
};

}

}
