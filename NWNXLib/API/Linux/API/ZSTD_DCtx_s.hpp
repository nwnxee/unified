#pragma once

#include <cstdint>

#include "XXH64_state_s.hpp"
#include "ZSTD_customMem.hpp"
#include "ZSTD_entropyDTables_t.hpp"
#include "ZSTD_frameHeader.hpp"
#include "unknown_ZSTD_dStage.hpp"
#include "unknown_ZSTD_dStreamStage.hpp"
#include "unknown_ZSTD_format_e.hpp"
#include "unknown_blockType_e.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct ZSTD_DDict_s;
struct ZSTD_seqSymbol;

struct ZSTD_DCtx_s
{
    const ZSTD_seqSymbol* LLTptr;
    const ZSTD_seqSymbol* MLTptr;
    const ZSTD_seqSymbol* OFTptr;
    const uint32_t* HUFptr;
    ZSTD_entropyDTables_t entropy;
    const void* previousDstEnd;
    const void* prefixStart;
    const void* virtualStart;
    const void* dictEnd;
    uint32_t expected;
    ZSTD_frameHeader fParams;
    uint64_t decodedSize;
    blockType_e bType;
    ZSTD_dStage stage;
    uint32_t litEntropy;
    uint32_t fseEntropy;
    XXH64_state_s xxhState;
    uint32_t headerSize;
    uint32_t dictID;
    ZSTD_format_e format;
    const uint8_t* litPtr;
    ZSTD_customMem customMem;
    uint32_t litSize;
    uint32_t rleSize;
    uint32_t staticSize;
    int32_t bmi2;
    ZSTD_DDict_s* ddictLocal;
    const ZSTD_DDict_s* ddict;
    ZSTD_dStreamStage streamStage;
    char* inBuff;
    uint32_t inBuffSize;
    uint32_t inPos;
    uint32_t maxWindowSize;
    char* outBuff;
    uint32_t outBuffSize;
    uint32_t outStart;
    uint32_t outEnd;
    uint32_t lhSize;
    void* legacyContext;
    uint32_t previousLegacyVersion;
    uint32_t legacyVersion;
    uint32_t hostageByte;
    int32_t noForwardProgress;
    uint8_t litBuffer[131080];
    uint8_t headerBuffer[18];
};

}

}
