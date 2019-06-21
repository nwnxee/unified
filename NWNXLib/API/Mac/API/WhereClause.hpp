#pragma once

#include <cstdint>

#include "WhereTerm.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct WhereInfo;

struct WhereClause
{
    WhereInfo* pWInfo;
    WhereClause* pOuter;
    uint8_t op;
    uint8_t hasOr;
    int32_t nTerm;
    int32_t nSlot;
    WhereTerm* a;
    WhereTerm aStatic[8];
};

}

}
