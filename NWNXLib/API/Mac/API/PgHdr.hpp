#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct PCache;
struct Pager;
struct sqlite3_pcache_page;

struct PgHdr
{
    sqlite3_pcache_page* pPage;
    void* pData;
    void* pExtra;
    PCache* pCache;
    PgHdr* pDirty;
    Pager* pPager;
    uint32_t pgno;
    uint16_t flags;
    int16_t nRef;
    PgHdr* pDirtyNext;
    PgHdr* pDirtyPrev;
};

}

}
