#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct Parse;
struct WhereClause;

struct HiddenIndexInfo
{
    WhereClause* pWC;
    Parse* pParse;
};

}

}
