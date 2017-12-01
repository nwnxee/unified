#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct MD5_CTX
{
    uint32_t state[4];
    uint32_t count[2];
    uint8_t buffer[64];
};

}

}
