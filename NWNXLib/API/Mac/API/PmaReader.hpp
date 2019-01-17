#pragma once

#include <cstdint>

#include "unknown_sqlite_int64.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct IncrMerger;
struct sqlite3_file;

struct PmaReader
{
    sqlite_int64 iReadOff;
    sqlite_int64 iEof;
    int32_t nAlloc;
    int32_t nKey;
    sqlite3_file* pFd;
    uint8_t* aAlloc;
    uint8_t* aKey;
    uint8_t* aBuffer;
    int32_t nBuffer;
    uint8_t* aMap;
    IncrMerger* pIncr;
};

}

}
