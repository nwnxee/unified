#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct Expr;
struct Parse;

struct WhereConst
{
    Parse* pParse;
    int32_t nConst;
    int32_t nChng;
    Expr** apExpr;
};

}

}
