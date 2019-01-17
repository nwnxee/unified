#pragma once

#include <cstdint>

#include "unknown_sqlite_int64.hpp"

namespace NWNXLib {

namespace API {

struct SumCtx
{
    double rSum;
    sqlite_int64 iSum;
    sqlite_int64 cnt;
    uint8_t overflow;
    uint8_t approx;
};

}

}
