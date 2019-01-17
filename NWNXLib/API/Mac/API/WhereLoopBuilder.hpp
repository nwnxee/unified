#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct ExprList;
struct WhereClause;
struct WhereInfo;
struct WhereLoop;
struct WhereOrSet;

struct WhereLoopBuilder
{
    WhereInfo* pWInfo;
    WhereClause* pWC;
    ExprList* pOrderBy;
    WhereLoop* pNew;
    WhereOrSet* pOrSet;
    uint32_t bldFlags;
};

}

}
