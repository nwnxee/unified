#pragma once

#include <cstdint>

#include "unknown_sqlite_int64.hpp"

namespace NWNXLib {

namespace API {

struct CallCount
{
    sqlite_int64 nValue;
    sqlite_int64 nStep;
    sqlite_int64 nTotal;
};

}

}
