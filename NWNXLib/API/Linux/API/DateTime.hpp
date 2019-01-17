#pragma once

#include <cstdint>

#include "unknown_sqlite_int64.hpp"

namespace NWNXLib {

namespace API {

struct DateTime
{
    sqlite_int64 iJD;
    int32_t Y;
    int32_t M;
    int32_t D;
    int32_t h;
    int32_t m;
    int32_t tz;
    double s;
    char validJD;
    char rawS;
    char validYMD;
    char validHMS;
    char validTZ;
    char tzSet;
    char isError;
};

}

}
