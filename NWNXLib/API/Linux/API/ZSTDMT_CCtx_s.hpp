#pragma once

#include <cstdint>

#include "ZSTD_CCtx_params_s.hpp"
#include "ZSTD_customMem.hpp"
#include "inBuff_t.hpp"
#include "roundBuff_t.hpp"
#include "serialState_t.hpp"
#include "unknown_ZSTDMT_bufferPool.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct POOL_ctx_s;
struct ZSTDMT_CCtxPool;
struct ZSTDMT_bufferPool_s;
struct ZSTDMT_jobDescription;
struct ZSTD_CDict_s;

struct ZSTDMT_CCtx_s
{
    POOL_ctx_s* factory;
    ZSTDMT_jobDescription* jobs;
    ZSTDMT_bufferPool_s* bufPool;
    ZSTDMT_CCtxPool* cctxPool;
    ZSTDMT_bufferPool* seqPool;
    ZSTD_CCtx_params_s params;
    uint32_t targetSectionSize;
    uint32_t targetPrefixSize;
    int32_t jobReady;
    inBuff_t inBuff;
    roundBuff_t roundBuff;
    serialState_t serial;
    uint32_t singleBlockingThread;
    uint32_t jobIDMask;
    uint32_t doneJobID;
    uint32_t nextJobID;
    uint32_t frameEnded;
    uint32_t allJobsCompleted;
    uint64_t frameContentSize;
    uint64_t consumed;
    uint64_t produced;
    ZSTD_customMem cMem;
    ZSTD_CDict_s* cdictLocal;
    const ZSTD_CDict_s* cdict;
};

}

}
