#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct Bitvec;
struct BtCursor;
struct BtLock;
struct Btree;
struct MemPage;
struct Pager;
struct sqlite3;
struct sqlite3_mutex;

struct BtShared
{
    Pager* pPager;
    sqlite3* db;
    BtCursor* pCursor;
    MemPage* pPage1;
    uint8_t openFlags;
    uint8_t autoVacuum;
    uint8_t incrVacuum;
    uint8_t bDoTruncate;
    uint8_t inTransaction;
    uint8_t max1bytePayload;
    uint16_t btsFlags;
    uint16_t maxLocal;
    uint16_t minLocal;
    uint16_t maxLeaf;
    uint16_t minLeaf;
    uint32_t pageSize;
    uint32_t usableSize;
    int32_t nTransaction;
    uint32_t nPage;
    void* pSchema;
    void** m_funcPtrPlaceholder__0;
    sqlite3_mutex* mutex;
    Bitvec* pHasContent;
    int32_t nRef;
    BtShared* pNext;
    BtLock* pLock;
    Btree* pWriter;
    uint8_t* pTmpSpace;
};

}

}
