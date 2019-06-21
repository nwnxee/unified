#pragma once

#include <cstdint>

#include "unknown_sqlite_int64.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct sqlite3_file;

struct SorterFile
{
    sqlite3_file* pFd;
    sqlite_int64 iEof;
};

}

}
