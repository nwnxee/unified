#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct Expr;
struct ExprList;
struct SrcList;
struct Window_0;
struct With;

struct Select
{
    ExprList* pEList;
    uint8_t op;
    int16_t nSelectRow;
    uint32_t selFlags;
    int32_t iLimit;
    int32_t iOffset;
    uint32_t selId;
    int32_t addrOpenEphm[2];
    SrcList* pSrc;
    Expr* pWhere;
    ExprList* pGroupBy;
    Expr* pHaving;
    ExprList* pOrderBy;
    Select* pPrior;
    Select* pNext;
    Expr* pLimit;
    With* pWith;
    Window_0* pWin;
    Window_0* pWinDefn;
};

}

}
