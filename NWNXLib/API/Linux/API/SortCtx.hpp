#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct ExprList;
struct RowLoadInfo;

struct SortCtx
{
    ExprList* pOrderBy;
    int32_t nOBSat;
    int32_t iECursor;
    int32_t regReturn;
    int32_t labelBkOut;
    int32_t addrSortIndex;
    int32_t labelDone;
    int32_t labelOBLopt;
    uint8_t sortFlags;
    RowLoadInfo* pDeferredRowLoad;
};

}

}
