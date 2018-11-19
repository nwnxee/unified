#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct Expr;
struct ExprList;
struct Index;
struct SrcList;

struct Upsert
{
    ExprList* pUpsertTarget;
    Expr* pUpsertTargetWhere;
    ExprList* pUpsertSet;
    Expr* pUpsertWhere;
    Index* pUpsertIdx;
    SrcList* pUpsertSrc;
    int32_t regData;
    int32_t iDataCur;
    int32_t iIdxCur;
};

}

}
