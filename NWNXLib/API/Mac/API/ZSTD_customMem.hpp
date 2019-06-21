#pragma once

#include <cstdint>

#include "unknown_ZSTD_allocFunction.hpp"
#include "unknown_ZSTD_freeFunction.hpp"

namespace NWNXLib {

namespace API {

struct ZSTD_customMem
{
    ZSTD_allocFunction customAlloc;
    ZSTD_freeFunction customFree;
    void* opaque;
};

}

}
