#pragma once

#include <cstdint>

#include "unknown_sqlite_int64.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct sqlite3_mutex;

struct Mem0Global
{
    sqlite3_mutex* mutex;
    sqlite_int64 alarmThreshold;
    int32_t nearlyFull;
};

}

}
