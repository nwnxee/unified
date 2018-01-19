#pragma once

#include <cstdint>

#include "FILE4SEQ_WRITE.hpp"
#include "FILE4St.hpp"
#include "LIST4.hpp"
#include "unknown_S4CMP_FUNCTION.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CODE4St;
struct MEM4st;
struct S4SPOOL;

struct SORT4
{
    CODE4St* codeBase;
    FILE4St file;
    FILE4SEQ_WRITE seqwrite;
    char* seqwriteBuffer;
    S4SPOOL* spoolPointer;
    uint32_t spoolsN;
    uint32_t spoolsMax;
    char** pointers;
    uint32_t pointersI;
    uint32_t pointersUsed;
    uint32_t pointersInit;
    uint32_t pointersMax;
    LIST4 pool;
    MEM4st* poolMemory;
    uint32_t poolN;
    uint32_t poolEntries;
    uint32_t sortLen;
    int32_t spoolDiskLen;
    uint32_t spoolMemLen;
    uint32_t infoOffset;
    uint32_t infoLen;
    uint32_t totLen;
    int32_t isMemAvail;
    S4CMP_FUNCTION* cmp;
};

}

}
