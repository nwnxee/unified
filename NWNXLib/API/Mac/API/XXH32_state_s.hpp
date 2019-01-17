#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct XXH32_state_s
{
    uint32_t total_len_32;
    uint32_t large_len;
    uint32_t v1;
    uint32_t v2;
    uint32_t v3;
    uint32_t v4;
    uint32_t mem32[4];
    uint32_t memsize;
    uint32_t reserved;
};

}

}
