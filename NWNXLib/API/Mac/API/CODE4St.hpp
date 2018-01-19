#pragma once

#include <cstdint>

#include "CODE4TRANSSt.hpp"
#include "LIST4.hpp"
#include "OPT4.hpp"
#include "TRAN4FILESt.hpp"
#include "unknown_Collate4name.hpp"
#include "unknown___time_t.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct FILE4St;
struct MEM4st;
struct RELATION4St;

struct CODE4St
{
    int32_t autoOpen;
    int32_t createTemp;
    int16_t errDefaultUnique;
    int32_t errExpr;
    int32_t errFieldName;
    int32_t errOff;
    int32_t errOpen;
    int16_t log;
    int32_t memExpandData;
    uint32_t memSizeBuffer;
    uint32_t memSizeSortBuffer;
    uint32_t memSizeSortPool;
    uint32_t memStartData;
    char safety;
    int32_t timeout;
    int16_t compatibility;
    int32_t s4cr2;
    int32_t initialized;
    int32_t numericStrLen;
    int32_t decimals;
    int32_t memExpandDataFile;
    uint32_t memStartDataFile;
    uint32_t storedKeyLen;
    uint32_t bufLen;
    char* storedKey;
    char* fieldBuffer;
    char indexExtension[4];
    char memoExtension[4];
    MEM4st* bitmapMemory;
    MEM4st* dataMemory;
    MEM4st* calcMemory;
    MEM4st* data4fileMemory;
    MEM4st* relateDataListMemory;
    MEM4st* relateListMemory;
    MEM4st* relateMemory;
    MEM4st* relationMemory;
    MEM4st* dataListMemory;
    LIST4 dataFileList;
    FILE4St* errorLog;
    int16_t collatingSequence;
    int16_t codePage;
    int32_t didAlloc;
    char oledbSchemaCreate;
    char accessMode;
    int32_t memExpandLock;
    uint32_t memStartLock;
    int32_t lockAttemptsSingle;
    uint32_t lockDelay;
    int32_t fileFlush;
    char readLock;
    int32_t lockAttempts;
    MEM4st* lockMemory;
    MEM4st* lockGroupMemory;
    MEM4st* lockLinkMemory;
    int32_t optimizeWrite;
    int32_t optimize;
    int32_t memMaxPercent;
    int32_t memStartMax;
    uint32_t memSizeBlock;
    int32_t errTagName;
    int32_t memExpandBlock;
    int32_t memExpandIndex;
    int32_t memExpandTag;
    uint32_t memStartBlock;
    uint32_t memStartIndex;
    uint32_t memStartTag;
    int32_t memExpandTagFile;
    uint32_t memStartTagFile;
    MEM4st* indexMemory;
    MEM4st* index4fileMemory;
    MEM4st* tagMemory;
    MEM4st* tagFileMemory;
    uint32_t memSizeMemo;
    uint32_t memSizeMemoExpr;
    int32_t doTrans;
    uint32_t foxCreateIndexBlockSize;
    uint32_t foxCreateIndexMultiplier;
    int32_t errCreate;
    int32_t errorCode;
    int32_t readOnly;
    int32_t errorCode2;
    uint32_t memStartIndexFile;
    int32_t memExpandIndexFile;
    uint32_t hInst;
    uint32_t hInstLocal;
    char* transFileName;
    char* tranData;
    uint32_t tranDataLen;
    __time_t transactionTime;
    OPT4 opt;
    int32_t hasOpt;
    int32_t doOpt;
    int32_t hadOpt;
    TRAN4FILESt transFile;
    int32_t logOpen;
    int32_t largeFileOffset;
    int32_t doRemove;
    int16_t singleOpen;
    int32_t errGo;
    int32_t errRelate;
    int32_t errSkip;
    int32_t lockEnforce;
    char* lockedNetName;
    char* lockedNetNameBuf;
    char* lockedUserName;
    char* lockedUserNameBuf;
    const char* lockedFileName;
    char* lockedFileNameBuf;
    uint32_t lockedFileNameLen;
    uint32_t lockedUserNameLen;
    uint32_t lockedNetNameLen;
    int32_t lockedLockItem;
    CODE4TRANSSt c4trans;
    MEM4st* totalMemory;
    LIST4 calcList;
    LIST4 totalList;
    int32_t numReports;
    int16_t pageno;
    int32_t clientDataCount;
    int32_t doIndexVerify;
    RELATION4St* currentRelation;
    char savedKey[248];
    char skipCom;
    char* applicationVerify;
    Collate4name collateName;
    Collate4name collateNameUnicode;
    int32_t codeCollateSetValue;
    int32_t codeCollateSetValueUnicode;
};

}

}
