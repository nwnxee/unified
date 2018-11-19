#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct ZSTD_inBuffer_s
{
    const void* src;
    uint32_t size;
    uint32_t pos;
};

}

}
