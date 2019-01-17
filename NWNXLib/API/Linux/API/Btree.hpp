#pragma once

#include <cstdint>

#include "BtLock.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct BtShared;
struct sqlite3;

struct Btree
{
    sqlite3* db;
    BtShared* pBt;
    uint8_t inTrans;
    uint8_t sharable;
    uint8_t locked;
    uint8_t hasIncrblobCur;
    int32_t wantToLock;
    int32_t nBackup;
    uint32_t iDataVersion;
    Btree* pNext;
    Btree* pPrev;
    BtLock lock;
};

}

}
