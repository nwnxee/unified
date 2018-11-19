#pragma once

#include <cstdint>

#include "unknown_sqlite_int64.hpp"

namespace NWNXLib {

namespace API {

struct Savepoint
{
    char* zName;
    sqlite_int64 nDeferredCons;
    sqlite_int64 nDeferredImmCons;
    Savepoint* pNext;
};

}

}
