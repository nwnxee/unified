#pragma once

#include <cstdint>

#include "unknown_TLS_8138CC866C42D44EC6A524EE8CBAED38.hpp"
#include "unknown_u64.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct WhereTerm;

struct WhereLoop
{
    u64 prereq;
    u64 maskSelf;
    uint8_t iTab;
    uint8_t iSortIdx;
    int16_t rSetup;
    int16_t rRun;
    int16_t nOut;
    TLS_8138CC866C42D44EC6A524EE8CBAED38 u;
    uint32_t wsFlags;
    uint16_t nLTerm;
    uint16_t nSkip;
    uint16_t nLSlot;
    WhereTerm** aLTerm;
    WhereLoop* pNextLoop;
    WhereTerm* aLTermSpace[3];
};

}

}
