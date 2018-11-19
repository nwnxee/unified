#pragma once

#include <cstdint>

#include "WalIndexHdr.hpp"
#include "unknown_sqlite_int64.hpp"
#include "unknown_volatileu32.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct sqlite3_file;
struct sqlite3_vfs;

struct Wal
{
    sqlite3_vfs* pVfs;
    sqlite3_file* pDbFd;
    sqlite3_file* pWalFd;
    uint32_t iCallback;
    sqlite_int64 mxWalSize;
    int32_t nWiData;
    int32_t szFirstBlock;
    volatileu32** apWiData;
    uint32_t szPage;
    int16_t readLock;
    uint8_t syncFlags;
    uint8_t exclusiveMode;
    uint8_t writeLock;
    uint8_t ckptLock;
    uint8_t readOnly;
    uint8_t truncateOnCommit;
    uint8_t syncHeader;
    uint8_t padToSectorBoundary;
    uint8_t bShmUnreliable;
    WalIndexHdr hdr;
    uint32_t minFrame;
    uint32_t iReCksum;
    const char* zWalName;
    uint32_t nCkpt;
};

}

}
