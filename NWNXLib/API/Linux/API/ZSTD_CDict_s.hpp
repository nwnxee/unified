#pragma once

#include <cstdint>

#include "ZSTD_compressedBlockState_t.hpp"
#include "ZSTD_compressionParameters.hpp"
#include "ZSTD_customMem.hpp"
#include "ZSTD_matchState_t.hpp"

namespace NWNXLib {

namespace API {

struct ZSTD_CDict_s
{
    void* dictBuffer;
    const void* dictContent;
    uint32_t dictContentSize;
    void* workspace;
    uint32_t workspaceSize;
    ZSTD_matchState_t matchState;
    ZSTD_compressedBlockState_t cBlockState;
    ZSTD_compressionParameters cParams;
    ZSTD_customMem customMem;
    uint32_t dictID;
};

}

}
