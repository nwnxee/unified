#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct Expr;
struct WhereClause;

struct WhereScan
{
    WhereClause* pOrigWC;
    WhereClause* pWC;
    const char* zCollName;
    Expr* pIdxExpr;
    char idxaff;
    uint8_t nEquiv;
    uint8_t iEquiv;
    uint32_t opMask;
    int32_t k;
    int32_t aiCur[11];
    int16_t aiColumn[11];
};

}

}
