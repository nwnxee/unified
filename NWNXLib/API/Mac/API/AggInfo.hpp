#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct AggInfo_col;
struct AggInfo_func;
struct ExprList;

struct AggInfo
{
    uint8_t directMode;
    uint8_t useSortingIdx;
    int32_t sortingIdx;
    int32_t sortingIdxPTab;
    int32_t nSortingColumn;
    int32_t mnReg;
    int32_t mxReg;
    ExprList* pGroupBy;
    AggInfo_col* aCol;
    int32_t nColumn;
    int32_t nAccumulator;
    AggInfo_func* aFunc;
    int32_t nFunc;
};

}

}
