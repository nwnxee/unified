#pragma once

#include <cstdint>

#include "XXH64_state_s.hpp"
#include "ZSTD_CCtx_params_s.hpp"
#include "ZSTD_blockState_t.hpp"
#include "ZSTD_customMem.hpp"
#include "ZSTD_prefixDict_s.hpp"
#include "ldmState_t.hpp"
#include "rawSeqStore_t.hpp"
#include "seqStore_t.hpp"
#include "unknown_ZSTD_cStreamStage.hpp"
#include "unknown_ZSTD_compressionStage_e.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct ZSTDMT_CCtx_s;
struct ZSTD_CDict_s;
struct rawSeq;

struct ZSTD_CCtx_s
{
    ZSTD_compressionStage_e stage;
    int32_t cParamsChanged;
    int32_t bmi2;
    ZSTD_CCtx_params_s requestedParams;
    ZSTD_CCtx_params_s appliedParams;
    uint32_t dictID;
    int32_t workSpaceOversizedDuration;
    void* workSpace;
    uint32_t workSpaceSize;
    uint32_t blockSize;
    uint64_t pledgedSrcSizePlusOne;
    uint64_t consumedSrcSize;
    uint64_t producedCSize;
    XXH64_state_s xxhState;
    ZSTD_customMem customMem;
    uint32_t staticSize;
    seqStore_t seqStore;
    ldmState_t ldmState;
    rawSeq* ldmSequences;
    uint32_t maxNbLdmSequences;
    rawSeqStore_t externSeqStore;
    ZSTD_blockState_t blockState;
    uint32_t* entropyWorkspace;
    char* inBuff;
    uint32_t inBuffSize;
    uint32_t inToCompress;
    uint32_t inBuffPos;
    uint32_t inBuffTarget;
    char* outBuff;
    uint32_t outBuffSize;
    uint32_t outBuffContentSize;
    uint32_t outBuffFlushedSize;
    ZSTD_cStreamStage streamStage;
    uint32_t frameEnded;
    ZSTD_CDict_s* cdictLocal;
    const ZSTD_CDict_s* cdict;
    ZSTD_prefixDict_s prefixDict;
    ZSTDMT_CCtx_s* mtctx;
};

}

}
