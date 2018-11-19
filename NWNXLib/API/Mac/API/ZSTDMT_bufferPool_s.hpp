#pragma once

#include <cstdint>

#include "ZSTD_customMem.hpp"
#include "buffer_s.hpp"
#include "unknown_pthread_mutex_t_0.hpp"

namespace NWNXLib {

namespace API {

struct ZSTDMT_bufferPool_s
{
    pthread_mutex_t_0 poolMutex;
    uint32_t bufferSize;
    uint32_t totalBuffers;
    uint32_t nbBuffers;
    ZSTD_customMem cMem;
    buffer_s bTable[1];
};

}

}
