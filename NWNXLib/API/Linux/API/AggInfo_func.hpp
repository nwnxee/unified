#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct Expr;
struct FuncDef;

struct AggInfo_func
{
    Expr* pExpr;
    FuncDef* pFunc;
    int32_t iMem;
    int32_t iDistinct;
};

}

}
