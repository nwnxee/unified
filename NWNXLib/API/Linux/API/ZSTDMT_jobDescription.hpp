#pragma once

#include <cstdint>

#include "ZSTD_CCtx_params_s.hpp"
#include "buffer_s.hpp"
#include "pthread_cond_t.hpp"
#include "range_t.hpp"
#include "unknown_ZSTDMT_bufferPool.hpp"
#include "unknown_pthread_mutex_t_0.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct ZSTDMT_CCtxPool;
struct ZSTDMT_bufferPool_s;
struct ZSTD_CDict_s;
struct serialState_t;

struct ZSTDMT_jobDescription
{
    uint32_t consumed;
    uint32_t cSize;
    pthread_mutex_t_0 job_mutex;
    pthread_cond_t job_cond;
    ZSTDMT_CCtxPool* cctxPool;
    ZSTDMT_bufferPool_s* bufPool;
    ZSTDMT_bufferPool* seqPool;
    serialState_t* serial;
    buffer_s dstBuff;
    range_t prefix;
    range_t src;
    uint32_t jobID;
    uint32_t firstJob;
    uint32_t lastJob;
    ZSTD_CCtx_params_s params;
    const ZSTD_CDict_s* cdict;
    uint64_t fullFrameSize;
    uint32_t dstFlushed;
    uint32_t frameChecksumNeeded;
};

}

}
