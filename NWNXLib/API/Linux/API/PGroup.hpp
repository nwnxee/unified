#pragma once

#include <cstdint>

#include "PgHdr1.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct sqlite3_mutex;

struct PGroup
{
    sqlite3_mutex* mutex;
    uint32_t nMaxPage;
    uint32_t nMinPage;
    uint32_t mxPinned;
    uint32_t nPurgeable;
    PgHdr1 lru;
};

}

}
