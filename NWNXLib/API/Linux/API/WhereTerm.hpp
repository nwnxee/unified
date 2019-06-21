#pragma once

#include <cstdint>

#include "unknown_TLS_23896D441AC72EC8F44BC5F09F53DC54.hpp"
#include "unknown_u64.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct Expr;
struct WhereClause;

struct WhereTerm
{
    Expr* pExpr;
    WhereClause* pWC;
    int16_t truthProb;
    uint16_t wtFlags;
    uint16_t eOperator;
    uint8_t nChild;
    uint8_t eMatchOp;
    int32_t iParent;
    int32_t leftCursor;
    int32_t iField;
    TLS_23896D441AC72EC8F44BC5F09F53DC54 u;
    u64 prereqRight;
    u64 prereqAll;
};

}

}
