#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct sqlite3_value;

struct LastValueCtx
{
    sqlite3_value* pVal;
    int32_t nVal;
};

}

}
