#pragma once

#include <cstdint>

#include "unknown_sqlite_int64.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct Bitvec;

struct PagerSavepoint
{
    sqlite_int64 iOffset;
    sqlite_int64 iHdrOffset;
    Bitvec* pInSavepoint;
    uint32_t nOrig;
    uint32_t iSubRec;
    uint32_t aWalData[4];
};

}

}
