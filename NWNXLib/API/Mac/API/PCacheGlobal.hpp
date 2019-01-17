#pragma once

#include <cstdint>

#include "PGroup.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct PgFreeslot;
struct sqlite3_mutex;

struct PCacheGlobal
{
    PGroup grp;
    int32_t isInit;
    int32_t separateCache;
    int32_t nInitPage;
    int32_t szSlot;
    int32_t nSlot;
    int32_t nReserve;
    void* pStart;
    void* pEnd;
    sqlite3_mutex* mutex;
    PgFreeslot* pFree;
    int32_t nFreeSlot;
    int32_t bUnderPressure;
};

}

}
