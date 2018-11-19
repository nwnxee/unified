#pragma once

#include <cstdint>

#include "unknown_sqlite_int64.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct UnixUnusedFd;
struct sqlite3_io_methods;
struct sqlite3_vfs;
struct unixInodeInfo;
struct unixShm;

struct unixFile
{
    const sqlite3_io_methods* pMethod;
    sqlite3_vfs* pVfs;
    unixInodeInfo* pInode;
    int32_t h;
    uint8_t eFileLock;
    uint16_t ctrlFlags;
    int32_t lastErrno;
    void* lockingContext;
    UnixUnusedFd* pPreallocatedUnused;
    const char* zPath;
    unixShm* pShm;
    int32_t szChunk;
    int32_t nFetchOut;
    sqlite_int64 mmapSize;
    sqlite_int64 mmapSizeActual;
    sqlite_int64 mmapSizeMax;
    void* pMapRegion;
    int32_t sectorSize;
    int32_t deviceCharacteristics;
};

}

}
