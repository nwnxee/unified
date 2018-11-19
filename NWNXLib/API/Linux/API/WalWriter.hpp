#pragma once

#include <cstdint>

#include "unknown_sqlite_int64.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct Wal;
struct sqlite3_file;

struct WalWriter
{
    Wal* pWal;
    sqlite3_file* pFd;
    sqlite_int64 iSyncPoint;
    int32_t syncFlags;
    int32_t szPage;
};

}

}
