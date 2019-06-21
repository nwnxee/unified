#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct ZSTD_outBuffer_s
{
    void* dst;
    uint32_t size;
    uint32_t pos;
};

}

}
