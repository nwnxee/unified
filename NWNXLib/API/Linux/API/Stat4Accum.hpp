#pragma once

#include <cstdint>

#include "Stat4Sample.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct sqlite3;

struct Stat4Accum
{
    uint32_t nRow;
    uint32_t nPSample;
    int32_t nCol;
    int32_t nKeyCol;
    int32_t mxSample;
    Stat4Sample current;
    uint32_t iPrn;
    Stat4Sample* aBest;
    int32_t iMin;
    int32_t nSample;
    int32_t nMaxEqZero;
    int32_t iGet;
    Stat4Sample* a;
    sqlite3* db;
};

}

}
