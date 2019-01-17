#pragma once

#include <cstdint>

#include "unknown_sqlite_int64.hpp"

namespace NWNXLib {

namespace API {

struct RowSetEntry
{
    sqlite_int64 v;
    RowSetEntry* pRight;
    RowSetEntry* pLeft;
};

}

}
