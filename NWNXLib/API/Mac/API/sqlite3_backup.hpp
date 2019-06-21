#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct Btree;
struct sqlite3;

struct sqlite3_backup
{
    sqlite3* pDestDb;
    Btree* pDest;
    uint32_t iDestSchema;
    int32_t bDestLocked;
    uint32_t iNext;
    sqlite3* pSrcDb;
    Btree* pSrc;
    int32_t rc;
    uint32_t nRemaining;
    uint32_t nPagecount;
    int32_t isAttached;
    sqlite3_backup* pNext;
};

}

}
