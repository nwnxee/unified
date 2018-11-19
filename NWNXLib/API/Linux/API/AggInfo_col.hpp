#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct Expr;
struct Table;

struct AggInfo_col
{
    Table* pTab;
    int32_t iTable;
    int32_t iColumn;
    int32_t iSorterColumn;
    int32_t iMem;
    Expr* pExpr;
};

}

}
