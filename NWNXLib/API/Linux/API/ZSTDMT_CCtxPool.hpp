#pragma once

#include <cstdint>

#include "ZSTD_customMem.hpp"
#include "unknown_pthread_mutex_t_0.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct ZSTD_CCtx_s;

struct ZSTDMT_CCtxPool
{
    pthread_mutex_t_0 poolMutex;
    uint32_t totalCCtx;
    uint32_t availCCtx;
    ZSTD_customMem cMem;
    ZSTD_CCtx_s* cctx[1];
};

}

}
