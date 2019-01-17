#pragma once

#include <cstdint>

#include "unknown_sqlite_int64.hpp"

namespace NWNXLib {

namespace API {

struct CellInfo
{
    sqlite_int64 nKey;
    uint8_t* pPayload;
    uint32_t nPayload;
    uint16_t nLocal;
    uint16_t nSize;
};

}

}
