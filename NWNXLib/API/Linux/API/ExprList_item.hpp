#pragma once

#include <cstdint>

#include "unknown_TLS_0EC62EA21888E82ADD75FBCFAC55248C.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct Expr;

struct ExprList_item
{
    Expr* pExpr;
    char* zName;
    char* zSpan;
    uint8_t sortOrder;
    uint32_t done : 1;
    uint32_t bSpanIsTab : 1;
    uint32_t reusable : 1;
    uint32_t bSorterRef : 1;
    TLS_0EC62EA21888E82ADD75FBCFAC55248C u;
};

}

}
