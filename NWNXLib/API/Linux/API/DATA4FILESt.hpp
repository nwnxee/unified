#pragma once

#include <cstdint>

#include "FILE4St.hpp"
#include "LIST4.hpp"
#include "MEMO4FILE.hpp"
#include "Single4.hpp"
#include "l4linkSt.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CODE4St;

struct DATA4FILESt
{
    l4linkSt link;
    uint32_t recWidth;
    uint16_t infoLen;
    int16_t nFields;
    int16_t nFieldsMemo;
    int32_t minCount;
    int32_t userCount;
    CODE4St* c4;
    char* info;
    char version;
    char yy;
    char mm;
    char dd;
    int32_t numRecs;
    uint16_t headerLen;
    int32_t doDate;
    char* record;
    FILE4St file;
    char hasMdxMemo;
    int32_t fileChanged;
    int16_t blockSize;
    MEMO4FILE memoFile;
    int32_t tranStatus;
    char valid;
    int32_t fileServerWriteLock;
    int32_t fileClientWriteLock;
    int32_t appendClientLock;
    int32_t appendServerLock;
    int32_t tempServerLock;
    int32_t tempClientLock;
    uint32_t recordLockWriteCount;
    uint32_t recordLockReadCount;
    LIST4 data4list;
    int32_t compatibility;
    int32_t codePage;
    int32_t hiPrio;
    char openMdx;
    LIST4 indexes;
    Single4 fileReadLocks;
};

}

}
