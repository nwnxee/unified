#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct Expr;
struct IdList;
struct Schema;
struct TriggerStep;

struct Trigger
{
    char* zName;
    char* table;
    uint8_t op;
    uint8_t tr_tm;
    Expr* pWhen;
    IdList* pColumns;
    Schema* pSchema;
    Schema* pTabSchema;
    TriggerStep* step_list;
    Trigger* pNext;
};

}

}
