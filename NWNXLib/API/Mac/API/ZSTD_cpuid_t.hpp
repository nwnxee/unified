#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct ZSTD_cpuid_t
{
    uint32_t f1c;
    uint32_t f1d;
    uint32_t f7b;
    uint32_t f7c;
};

}

}
