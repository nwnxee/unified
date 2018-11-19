#pragma once

#include <cstdint>

#include "unknown_MemValue.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct sqlite3;

struct sqlite3_value
{
    MemValue u;
    uint16_t flags;
    uint8_t enc;
    uint8_t eSubtype;
    int32_t n;
    char* z;
    char* zMalloc;
    int32_t szMalloc;
    uint32_t uTemp;
    sqlite3* db;
    void** m_funcPtrPlaceholder__0;
};

}

}
