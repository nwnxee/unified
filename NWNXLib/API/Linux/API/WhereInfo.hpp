#pragma once

#include <cstdint>

#include "WhereClause.hpp"
#include "WhereLevel.hpp"
#include "WhereMaskSet.hpp"
#include "unknown_u64.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct Expr;
struct ExprList;
struct Parse;
struct SrcList;
struct WhereLoop;

struct WhereInfo
{
    Parse* pParse;
    SrcList* pTabList;
    ExprList* pOrderBy;
    ExprList* pResultSet;
    Expr* pWhere;
    int16_t iLimit;
    int32_t aiCurOnePass[2];
    int32_t iContinue;
    int32_t iBreak;
    int32_t savedNQueryLoop;
    uint16_t wctrlFlags;
    uint8_t nLevel;
    char nOBSat;
    uint8_t sorted;
    uint8_t eOnePass;
    uint8_t untestedTerms;
    uint8_t eDistinct;
    uint8_t bOrderedInnerLoop;
    int32_t iTop;
    WhereLoop* pLoops;
    u64 revMask;
    int16_t nRowOut;
    WhereClause sWC;
    WhereMaskSet sMaskSet;
    WhereLevel a[1];
};

}

}
