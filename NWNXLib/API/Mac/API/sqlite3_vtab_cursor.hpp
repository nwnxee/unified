#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct sqlite3_vtab;

struct sqlite3_vtab_cursor
{
    sqlite3_vtab* pVtab;
};

}

}
