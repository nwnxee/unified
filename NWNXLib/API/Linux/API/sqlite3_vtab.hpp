#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct sqlite3_module;

struct sqlite3_vtab
{
    const sqlite3_module* pModule;
    int32_t nRef;
    char* zErrMsg;
};

}

}
