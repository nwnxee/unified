#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct sqlite3;

struct InitData
{
    sqlite3* db;
    char** pzErrMsg;
    int32_t iDb;
    int32_t rc;
    uint32_t mInitFlags;
};

}

}
