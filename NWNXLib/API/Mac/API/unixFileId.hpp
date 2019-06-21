#pragma once

#include <cstdint>

#include "unknown___dev_t.hpp"
#include "unknown_sqlite_uint64.hpp"

namespace NWNXLib {

namespace API {

struct unixFileId
{
    __dev_t dev;
    sqlite_uint64 ino;
};

}

}
