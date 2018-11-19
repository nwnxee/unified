#pragma once

#include <cstdint>

#include "unknown_sqlite3_index_raint.hpp"
#include "unknown_sqlite3_index_raint_usage.hpp"
#include "unknown_sqlite_int64.hpp"
#include "unknown_sqlite_uint64.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct sqlite3_index_orderby;

struct sqlite3_index_info
{
    int32_t nConstraint;
    const sqlite3_index_raint* aConstraint;
    int32_t nOrderBy;
    sqlite3_index_orderby* aOrderBy;
    const sqlite3_index_raint_usage* aConstraintUsage;
    int32_t idxNum;
    char* idxStr;
    int32_t needToFreeIdxStr;
    int32_t orderByConsumed;
    double estimatedCost;
    sqlite_int64 estimatedRows;
    int32_t idxFlags;
    sqlite_uint64 colUsed;
};

}

}
