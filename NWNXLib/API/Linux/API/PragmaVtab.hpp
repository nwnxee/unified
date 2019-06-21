#pragma once

#include <cstdint>

#include "sqlite3_vtab.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct PragmaName;
struct sqlite3;

struct PragmaVtab
{
    sqlite3_vtab base;
    sqlite3* db;
    const PragmaName* pName;
    uint8_t nHidden;
    uint8_t iHidden;
};

}

}
