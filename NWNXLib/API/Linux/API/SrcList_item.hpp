#pragma once

#include <cstdint>

#include "unknown_TLS_A352990341AB9D36C2C82DEBE0BBC3A4.hpp"
#include "unknown_TLS_B5CDA8079296640A520FAF1B7DA6F914.hpp"
#include "unknown_u64.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct Expr;
struct IdList;
struct Index;
struct Schema;
struct Select;
struct Table;

struct SrcList_item
{
    Schema* pSchema;
    char* zDatabase;
    char* zName;
    char* zAlias;
    Table* pTab;
    Select* pSelect;
    int32_t addrFillSub;
    int32_t regReturn;
    int32_t regResult;
    TLS_A352990341AB9D36C2C82DEBE0BBC3A4 fg;
    int32_t iCursor;
    Expr* pOn;
    IdList* pUsing;
    u64 colUsed;
    TLS_B5CDA8079296640A520FAF1B7DA6F914 u1;
    Index* pIBIndex;
};

}

}
