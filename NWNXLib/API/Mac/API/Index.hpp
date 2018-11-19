#pragma once

#include <cstdint>

#include "unknown_u64.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct Expr;
struct ExprList;
struct Schema;
struct Table;

struct Index
{
    char* zName;
    int16_t* aiColumn;
    int16_t* aiRowLogEst;
    Table* pTable;
    char* zColAff;
    Index* pNext;
    Schema* pSchema;
    uint8_t* aSortOrder;
    const char** azColl;
    Expr* pPartIdxWhere;
    ExprList* aColExpr;
    int32_t tnum;
    int16_t szIdxRow;
    uint16_t nKeyCol;
    uint16_t nColumn;
    uint8_t onError;
    uint32_t idxType : 2;
    uint32_t bUnordered : 1;
    uint32_t uniqNotNull : 1;
    uint32_t isResized : 1;
    uint32_t isCovering : 1;
    uint32_t noSkipScan : 1;
    uint32_t hasStat1 : 1;
    uint32_t bNoQuery : 1;
    u64 colNotIdxed;
};

}

}
