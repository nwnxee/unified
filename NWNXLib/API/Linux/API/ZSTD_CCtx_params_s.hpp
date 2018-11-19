#pragma once

#include <cstdint>

#include "ZSTD_compressionParameters.hpp"
#include "ZSTD_customMem.hpp"
#include "ZSTD_frameParameters.hpp"
#include "ldmParams_t.hpp"
#include "unknown_ZSTD_dictAttachPref_e.hpp"
#include "unknown_ZSTD_format_e.hpp"

namespace NWNXLib {

namespace API {

struct ZSTD_CCtx_params_s
{
    ZSTD_format_e format;
    ZSTD_compressionParameters cParams;
    ZSTD_frameParameters fParams;
    int32_t compressionLevel;
    int32_t forceWindow;
    ZSTD_dictAttachPref_e attachDictPref;
    uint32_t nbWorkers;
    uint32_t jobSize;
    uint32_t overlapSizeLog;
    ldmParams_t ldmParams;
    ZSTD_customMem customMem;
};

}

}
