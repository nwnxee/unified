#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct sqlite3_value;

struct PrintfArguments
{
    int32_t nArg;
    int32_t nUsed;
    sqlite3_value** apArg;
};

}

}
