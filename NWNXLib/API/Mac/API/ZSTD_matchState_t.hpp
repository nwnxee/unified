#pragma once

#include <cstdint>

#include "ZSTD_window_t.hpp"
#include "optState_t.hpp"

namespace NWNXLib {

namespace API {

struct ZSTD_matchState_t
{
    ZSTD_window_t window;
    uint32_t loadedDictEnd;
    uint32_t nextToUpdate;
    uint32_t nextToUpdate3;
    uint32_t hashLog3;
    uint32_t* hashTable;
    uint32_t* hashTable3;
    uint32_t* chainTable;
    optState_t opt;
    const ZSTD_matchState_t* dictMatchState;
};

}

}
