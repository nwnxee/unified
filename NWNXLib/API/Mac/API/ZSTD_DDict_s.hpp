#pragma once

#include <cstdint>

#include "ZSTD_customMem.hpp"
#include "ZSTD_entropyDTables_t.hpp"

namespace NWNXLib {

namespace API {

struct ZSTD_DDict_s
{
    void* dictBuffer;
    const void* dictContent;
    uint32_t dictSize;
    ZSTD_entropyDTables_t entropy;
    uint32_t dictID;
    uint32_t entropyPresent;
    ZSTD_customMem cMem;
};

}

}
