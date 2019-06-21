#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct PgHdr;
struct sqlite3_pcache;

struct PCache
{
    PgHdr* pDirty;
    PgHdr* pDirtyTail;
    PgHdr* pSynced;
    int32_t nRefSum;
    int32_t szCache;
    int32_t szSpill;
    int32_t szPage;
    int32_t szExtra;
    uint8_t bPurgeable;
    uint8_t eCreate;
    void** m_funcPtrPlaceholder__0;
    void* pStress;
    sqlite3_pcache* pCache;
};

}

}
