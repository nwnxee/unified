#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct Expr;
struct ExprList;
struct FuncDef;

struct Window_0
{
    char* zName;
    ExprList* pPartition;
    ExprList* pOrderBy;
    uint8_t eType;
    uint8_t eStart;
    uint8_t eEnd;
    Expr* pStart;
    Expr* pEnd;
    Window_0* pNextWin;
    Expr* pFilter;
    FuncDef* pFunc;
    int32_t iEphCsr;
    int32_t regAccum;
    int32_t regResult;
    int32_t csrApp;
    int32_t regApp;
    int32_t regPart;
    Expr* pOwner;
    int32_t nBufferCol;
    int32_t iArgCol;
};

}

}
