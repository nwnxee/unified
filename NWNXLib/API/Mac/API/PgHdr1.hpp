#pragma once

#include <cstdint>

#include "sqlite3_pcache_page.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct PCache1;

struct PgHdr1
{
    sqlite3_pcache_page page;
    uint32_t iKey;
    uint8_t isBulkLocal;
    uint8_t isAnchor;
    PgHdr1* pNext;
    PCache1* pCache;
    PgHdr1* pLruNext;
    PgHdr1* pLruPrev;
};

}

}
