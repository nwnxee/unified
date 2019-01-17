#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct sqlite3_mutex;
struct unixInodeInfo;
struct unixShm;

struct unixShmNode
{
    unixInodeInfo* pInode;
    sqlite3_mutex* mutex;
    char* zFilename;
    int32_t h;
    int32_t szRegion;
    uint16_t nRegion;
    uint8_t isReadonly;
    uint8_t isUnlocked;
    char** apRegion;
    int32_t nRef;
    unixShm* pFirst;
};

}

}
