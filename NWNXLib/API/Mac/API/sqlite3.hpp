#pragma once

#include <cstdint>

#include "BusyHandler.hpp"
#include "Db.hpp"
#include "Hash.hpp"
#include "Lookaside.hpp"
#include "sqlite3InitInfo.hpp"
#include "unknown_TLS_70119770D337527CBEBD5BDC76406021.hpp"
#include "unknown_sqlite3_xauth.hpp"
#include "unknown_sqlite_int64.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CollSeq;
struct Savepoint;
struct VTable;
struct Vdbe;
struct VtabCtx;
struct sqlite3_mutex;
struct sqlite3_value;
struct sqlite3_vfs;

struct sqlite3
{
    sqlite3_vfs* pVfs;
    Vdbe* pVdbe;
    CollSeq* pDfltColl;
    sqlite3_mutex* mutex;
    Db* aDb;
    int32_t nDb;
    uint32_t mDbFlags;
    uint32_t flags;
    sqlite_int64 lastRowid;
    sqlite_int64 szMmap;
    uint32_t nSchemaLock;
    uint32_t openFlags;
    int32_t errCode;
    int32_t errMask;
    int32_t iSysErrno;
    uint16_t dbOptFlags;
    uint8_t enc;
    uint8_t autoCommit;
    uint8_t temp_store;
    uint8_t mallocFailed;
    uint8_t bBenignMalloc;
    uint8_t dfltLockMode;
    char nextAutovac;
    uint8_t suppressErr;
    uint8_t vtabOnConflict;
    uint8_t isTransactionSavepoint;
    uint8_t mTrace;
    uint8_t noSharedCache;
    uint8_t nSqlExec;
    int32_t nextPagesize;
    uint32_t magic;
    int32_t nChange;
    int32_t nTotalChange;
    int32_t aLimit[12];
    int32_t nMaxSorterMmap;
    sqlite3InitInfo init;
    int32_t nVdbeActive;
    int32_t nVdbeRead;
    int32_t nVdbeWrite;
    int32_t nVdbeExec;
    int32_t nVDestroy;
    int32_t nExtension;
    void** aExtension;
    void** m_funcPtrPlaceholder__0;
    void* pTraceArg;
    void** m_funcPtrPlaceholder__1;
    void* pProfileArg;
    void* pCommitArg;
    void** m_funcPtrPlaceholder__2;
    void* pRollbackArg;
    void** m_funcPtrPlaceholder__3;
    void* pUpdateArg;
    void** m_funcPtrPlaceholder__4;
    void** m_funcPtrPlaceholder__5;
    void* pWalArg;
    void** m_funcPtrPlaceholder__6;
    void** m_funcPtrPlaceholder__7;
    void* pCollNeededArg;
    sqlite3_value* pErr;
    TLS_70119770D337527CBEBD5BDC76406021 u1;
    Lookaside lookaside;
    sqlite3_xauth xAuth;
    void* pAuthArg;
    void** m_funcPtrPlaceholder__8;
    void* pProgressArg;
    uint32_t nProgressOps;
    int32_t nVTrans;
    Hash aModule;
    VtabCtx* pVtabCtx;
    VTable** aVTrans;
    VTable* pDisconnect;
    Hash aFunc;
    Hash aCollSeq;
    BusyHandler busyHandler;
    Db aDbStatic[2];
    Savepoint* pSavepoint;
    int32_t busyTimeout;
    int32_t nSavepoint;
    int32_t nStatement;
    sqlite_int64 nDeferredCons;
    sqlite_int64 nDeferredImmCons;
    int32_t* pnBytesFreed;
};

}

}
