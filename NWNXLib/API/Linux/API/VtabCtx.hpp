#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct Table;
struct VTable;

struct VtabCtx
{
    VTable* pVTable;
    Table* pTab;
    VtabCtx* pPrior;
    int32_t bDeclared;
};

}

}
