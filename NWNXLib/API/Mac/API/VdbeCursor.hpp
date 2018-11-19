#pragma once

#include <cstdint>

#include "unknown_TLS_163D2B3F583E63717835E72178F548D9.hpp"
#include "unknown_sqlite_int64.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct Btree;
struct KeyInfo;

struct VdbeCursor
{
    uint8_t eCurType;
    char iDb;
    uint8_t nullRow;
    uint8_t deferredMoveto;
    uint8_t isTable;
    uint32_t isEphemeral : 1;
    uint32_t useRandomRowid : 1;
    uint32_t isOrdered : 1;
    uint32_t seekHit : 1;
    Btree* pBtx;
    sqlite_int64 seqCount;
    int32_t* aAltMap;
    uint32_t cacheStatus;
    int32_t seekResult;
    VdbeCursor* pAltCursor;
    TLS_163D2B3F583E63717835E72178F548D9 uc;
    KeyInfo* pKeyInfo;
    uint32_t iHdrOffset;
    uint32_t pgnoRoot;
    int16_t nField;
    uint16_t nHdrParsed;
    sqlite_int64 movetoTarget;
    uint32_t* aOffset;
    const uint8_t* aRow;
    uint32_t payloadSize;
    uint32_t szRow;
    uint32_t aType[1];
};

}

}
