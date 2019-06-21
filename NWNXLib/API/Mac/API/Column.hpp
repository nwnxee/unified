#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct Expr;

struct Column
{
    char* zName;
    Expr* pDflt;
    char* zColl;
    uint8_t notNull;
    char affinity;
    uint8_t szEst;
    uint8_t colFlags;
};

}

}
