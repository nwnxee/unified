#pragma once

#include <cstdint>

#include "sqlite3_mem_methods.hpp"
#include "sqlite3_mutex_methods.hpp"
#include "sqlite3_pcache_methods2.hpp"
#include "unknown_sqlite_int64.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct sqlite3_mutex;

struct Sqlite3Config
{
    int32_t bMemstat;
    int32_t bCoreMutex;
    int32_t bFullMutex;
    int32_t bOpenUri;
    int32_t bUseCis;
    int32_t bSmallMalloc;
    int32_t mxStrlen;
    int32_t neverCorrupt;
    int32_t szLookaside;
    int32_t nLookaside;
    int32_t nStmtSpill;
    sqlite3_mem_methods m;
    sqlite3_mutex_methods mutex;
    sqlite3_pcache_methods2 pcache2;
    void* pHeap;
    int32_t nHeap;
    int32_t mnReq;
    int32_t mxReq;
    sqlite_int64 szMmap;
    sqlite_int64 mxMmap;
    void* pPage;
    int32_t szPage;
    int32_t nPage;
    int32_t mxParserStack;
    int32_t sharedCacheEnabled;
    uint32_t szPma;
    int32_t isInit;
    int32_t inProgress;
    int32_t isMutexInit;
    int32_t isMallocInit;
    int32_t isPCacheInit;
    int32_t nRefInitMutex;
    sqlite3_mutex* pInitMutex;
    void** m_funcPtrPlaceholder__0;
    void* pLogArg;
    void** m_funcPtrPlaceholder__1;
    int32_t bLocaltimeFault;
    int32_t iOnceResetThreshold;
    uint32_t szSorterRef;
};

}

}
