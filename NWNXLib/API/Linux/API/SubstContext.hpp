#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct ExprList;
struct Parse;

struct SubstContext
{
    Parse* pParse;
    int32_t iTable;
    int32_t iNewTable;
    int32_t isLeftJoin;
    ExprList* pEList;
};

}

}
