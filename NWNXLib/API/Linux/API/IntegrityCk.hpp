#pragma once

#include <cstdint>

#include "sqlite3_str.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct BtShared;
struct Pager;

struct IntegrityCk
{
    BtShared* pBt;
    Pager* pPager;
    uint8_t* aPgRef;
    uint32_t nPage;
    int32_t mxErr;
    int32_t nErr;
    int32_t mallocFailed;
    const char* zPfx;
    int32_t v1;
    int32_t v2;
    sqlite3_str errMsg;
    uint32_t* heap;
};

}

}
