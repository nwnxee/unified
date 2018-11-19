#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct Expr;
struct ExprList;
struct IdList;
struct Select;
struct Trigger;
struct Upsert;

struct TriggerStep
{
    uint8_t op;
    uint8_t orconf;
    Trigger* pTrig;
    Select* pSelect;
    char* zTarget;
    Expr* pWhere;
    ExprList* pExprList;
    IdList* pIdList;
    Upsert* pUpsert;
    char* zSpan;
    TriggerStep* pNext;
    TriggerStep* pLast;
};

}

}
