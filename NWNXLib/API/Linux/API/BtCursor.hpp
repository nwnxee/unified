#pragma once

#include <cstdint>

#include "CellInfo.hpp"
#include "unknown_sqlite_int64.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct BtShared;
struct Btree;
struct KeyInfo;
struct MemPage;

struct BtCursor
{
    uint8_t eState;
    uint8_t curFlags;
    uint8_t curPagerFlags;
    uint8_t hints;
    int32_t skipNext;
    Btree* pBtree;
    uint32_t* aOverflow;
    void* pKey;
    BtShared* pBt;
    BtCursor* pNext;
    CellInfo info;
    sqlite_int64 nKey;
    uint32_t pgnoRoot;
    char iPage;
    uint8_t curIntKey;
    uint16_t ix;
    uint16_t aiIdx[19];
    KeyInfo* pKeyInfo;
    MemPage* pPage;
    MemPage* apPage[19];
};

}

}
