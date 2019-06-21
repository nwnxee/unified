#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct ExprList;
struct Select;

struct Cte
{
    char* zName;
    ExprList* pCols;
    Select* pSelect;
    const char* zCteErr;
};

}

}
