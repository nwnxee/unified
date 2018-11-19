#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct sqlite3;

struct analysisInfo
{
    sqlite3* db;
    const char* zDatabase;
};

}

}
