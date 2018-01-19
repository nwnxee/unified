#pragma once

#include <cstdint>

#include "B4NODE_HEADER.hpp"
#include "FILE4SEQ_WRITE.hpp"
#include "SORT4.hpp"
#include "STRUCT_B4NODE.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CODE4St;
struct DATA4FILESt;
struct DATA4St;
struct INDEX4FILESt;
struct R4BLOCK_DATA;
struct TAG4FILESt;

struct R4REINDEX
{
    int16_t nTags;
    INDEX4FILESt* indexFile;
    TAG4FILESt* tag;
    char* curPos;
    B4NODE_HEADER nodeHdr;
    int32_t nBlocksUsed;
    uint32_t grouplen;
    int32_t valuelen;
    int32_t keysmax;
    STRUCT_B4NODE lastblock;
    int32_t keyCount;
    SORT4 sort;
    FILE4SEQ_WRITE seqwrite;
    char* buffer;
    uint32_t bufferLen;
    R4BLOCK_DATA* startBlock;
    int32_t nBlocks;
    int32_t minKeysmax;
    DATA4St* data;
    DATA4FILESt* dataFile;
    CODE4St* codeBase;
};

}

}
