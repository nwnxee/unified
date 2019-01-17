#pragma once

#include <cstdint>

#include "BIT_DStream_t.hpp"
#include "ZSTD_fseState.hpp"

namespace NWNXLib {

namespace API {

struct seqState_t
{
    BIT_DStream_t DStream;
    ZSTD_fseState stateLL;
    ZSTD_fseState stateOffb;
    ZSTD_fseState stateML;
    uint32_t prevOffset[3];
    const uint8_t* prefixStart;
    const uint8_t* dictEnd;
    uint32_t pos;
};

}

}
