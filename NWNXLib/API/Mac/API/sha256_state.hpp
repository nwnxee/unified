#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct sha256_state
{
    uint64_t length;
    uint32_t state[8];
    uint32_t curlen;
    uint8_t buf[64];
};

}

}
