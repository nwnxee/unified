#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct sqlite3_io_methods;

struct sqlite3_file
{
    const sqlite3_io_methods* pMethods;
};

}

}
