#pragma once

#include <cstdint>

#include "sqlite3_vtab_cursor.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct sqlite3_stmt;

struct PragmaVtabCursor
{
    sqlite3_vtab_cursor base;
    sqlite3_stmt* pPragma;
    int64_t iRowid;
    char* azArg[2];
};

}

}
