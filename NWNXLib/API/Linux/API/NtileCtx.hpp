#pragma once

#include <cstdint>

#include "unknown_sqlite_int64.hpp"

namespace NWNXLib {

namespace API {

struct NtileCtx
{
    sqlite_int64 nTotal;
    sqlite_int64 nParam;
    sqlite_int64 iRow;
};

}

}
