#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct Expr;

struct FrameBound
{
    int32_t eType;
    Expr* pExpr;
};

}

}
