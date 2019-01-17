#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct ZSTD_seqSymbol
{
    uint16_t nextState;
    uint8_t nbAdditionalBits;
    uint8_t nbBits;
    uint32_t baseValue;
};

}

}
