#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct PGroup;
struct PgHdr1;

struct PCache1
{
    PGroup* pGroup;
    uint32_t* pnPurgeable;
    int32_t szPage;
    int32_t szExtra;
    int32_t szAlloc;
    int32_t bPurgeable;
    uint32_t nMin;
    uint32_t nMax;
    uint32_t n90pct;
    uint32_t iMaxKey;
    uint32_t nRecyclable;
    uint32_t nPage;
    uint32_t nHash;
    PgHdr1** apHash;
    PgHdr1* pFree;
    void* pBulk;
};

}

}
