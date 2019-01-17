#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct ZSTD_optimal_t
{
    int32_t price;
    uint32_t off;
    uint32_t mlen;
    uint32_t litlen;
    uint32_t rep[3];
};

}

}
