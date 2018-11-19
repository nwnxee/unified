#pragma once

#include <cstdint>

#include "ZSTD_customMem.hpp"
#include "unknown_pthread_cond_t_0.hpp"
#include "unknown_pthread_mutex_t_0.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct POOL_job_s;

struct POOL_ctx_s
{
    ZSTD_customMem customMem;
    uint32_t* threads;
    uint32_t threadCapacity;
    uint32_t threadLimit;
    POOL_job_s* queue;
    uint32_t queueHead;
    uint32_t queueTail;
    uint32_t queueSize;
    uint32_t numThreadsBusy;
    int32_t queueEmpty;
    pthread_mutex_t_0 queueMutex;
    pthread_cond_t_0 queuePushCond;
    pthread_cond_t_0 queuePopCond;
    int32_t shutdown;
};

}

}
