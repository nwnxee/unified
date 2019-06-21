#pragma once

#include <cstdint>

#include "unknown_sqlite_int64.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct sqlite3_file;

struct PmaWriter
{
    int32_t eFWErr;
    uint8_t* aBuffer;
    int32_t nBuffer;
    int32_t iBufStart;
    int32_t iBufEnd;
    sqlite_int64 iWriteOff;
    sqlite3_file* pFd;
};

}

}
