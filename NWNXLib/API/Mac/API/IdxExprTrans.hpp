#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct Expr;

struct IdxExprTrans
{
    Expr* pIdxExpr;
    int32_t iTabCur;
    int32_t iIdxCur;
    int32_t iIdxCol;
};

}

}
