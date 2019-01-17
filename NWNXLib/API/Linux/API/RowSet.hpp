#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct RowSetChunk;
struct RowSetEntry;
struct sqlite3;

struct RowSet
{
    RowSetChunk* pChunk;
    sqlite3* db;
    RowSetEntry* pEntry;
    RowSetEntry* pLast;
    RowSetEntry* pFresh;
    RowSetEntry* pForest;
    uint16_t nFresh;
    uint16_t rsFlags;
    int32_t iBatch;
};

}

}
