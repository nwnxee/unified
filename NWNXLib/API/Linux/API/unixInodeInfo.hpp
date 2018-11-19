#pragma once

#include <cstdint>

#include "unixFileId.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct UnixUnusedFd;
struct sqlite3_mutex;
struct unixShmNode;

struct unixInodeInfo
{
    unixFileId fileId;
    sqlite3_mutex* pLockMutex;
    int32_t nShared;
    int32_t nLock;
    uint8_t eFileLock;
    uint8_t bProcessLock;
    UnixUnusedFd* pUnused;
    int32_t nRef;
    unixShmNode* pShmNode;
    unixInodeInfo* pNext;
    unixInodeInfo* pPrev;
};

}

}
