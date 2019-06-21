#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct XXH64_state_s
{
    uint64_t total_len;
    uint64_t v1;
    uint64_t v2;
    uint64_t v3;
    uint64_t v4;
    uint64_t mem64[4];
    uint32_t memsize;
    uint32_t reserved[2];
};

}

}
