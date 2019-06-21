#pragma once

#include <cstdint>

#include "unknown_sqlite_int64.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct Bitvec;
struct PCache;
struct PagerSavepoint;
struct PgHdr;
struct Wal;
struct sqlite3_backup;
struct sqlite3_file;
struct sqlite3_vfs;

struct Pager
{
    sqlite3_vfs* pVfs;
    uint8_t exclusiveMode;
    uint8_t journalMode;
    uint8_t useJournal;
    uint8_t noSync;
    uint8_t fullSync;
    uint8_t extraSync;
    uint8_t syncFlags;
    uint8_t walSyncFlags;
    uint8_t tempFile;
    uint8_t noLock;
    uint8_t readOnly;
    uint8_t memDb;
    uint8_t eState;
    uint8_t eLock;
    uint8_t changeCountDone;
    uint8_t setMaster;
    uint8_t doNotSpill;
    uint8_t subjInMemory;
    uint8_t bUseFetch;
    uint8_t hasHeldSharedLock;
    uint32_t dbSize;
    uint32_t dbOrigSize;
    uint32_t dbFileSize;
    uint32_t dbHintSize;
    int32_t errCode;
    int32_t nRec;
    uint32_t cksumInit;
    uint32_t nSubRec;
    Bitvec* pInJournal;
    sqlite3_file* fd;
    sqlite3_file* jfd;
    sqlite3_file* sjfd;
    sqlite_int64 journalOff;
    sqlite_int64 journalHdr;
    sqlite3_backup* pBackup;
    PagerSavepoint* aSavepoint;
    int32_t nSavepoint;
    uint32_t iDataVersion;
    char dbFileVers[16];
    int32_t nMmapOut;
    sqlite_int64 szMmap;
    PgHdr* pMmapFreelist;
    uint16_t nExtra;
    int16_t nReserve;
    uint32_t vfsFlags;
    uint32_t sectorSize;
    int32_t pageSize;
    uint32_t mxPgno;
    sqlite_int64 journalSizeLimit;
    char* zFilename;
    char* zJournal;
    void** m_funcPtrPlaceholder__0;
    void* pBusyHandlerArg;
    int32_t aStat[4];
    void** m_funcPtrPlaceholder__1;
    void** m_funcPtrPlaceholder__2;
    char* pTmpSpace;
    PCache* pPCache;
    Wal* pWal;
    char* zWal;
};

}

}
