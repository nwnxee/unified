#pragma once

#include <cstdint>

#include "unknown_sqlite_int64.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct sqlite3_value;

struct BtreePayload
{
    const void* pKey;
    sqlite_int64 nKey;
    const void* pData;
    sqlite3_value* aMem;
    uint16_t nMem;
    int32_t nData;
    int32_t nZero;
};

}

}
