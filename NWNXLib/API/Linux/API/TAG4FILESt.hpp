#pragma once

#include <cstdint>

#include "FILE4St.hpp"
#include "LIST4.hpp"
#include "STRUCT_B4NODE.hpp"
#include "T4HEADER.hpp"
#include "l4linkSt.hpp"
#include "unknown_C4DTOK.hpp"
#include "unknown_C4STOK.hpp"
#include "unknown_Collate4name.hpp"
#include "unknown_S4CMP_FUNCTION.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CODE4St;
struct INDEX4FILESt;
struct MEM4st;
struct e4exprSt;

struct TAG4FILESt
{
    l4linkSt link;
    INDEX4FILESt* indexFile;
    char alias[11];
    CODE4St* codeBase;
    int32_t debugInt;
    int32_t space2;
    e4exprSt* expr;
    e4exprSt* filter;
    S4CMP_FUNCTION* cmp;
    C4STOK* stok;
    C4DTOK* dtok;
    char space3;
    char hasKeys;
    LIST4 blocks;
    LIST4 saved;
    uint32_t space6;
    FILE4St space7;
    int32_t space8;
    void* space9;
    T4HEADER header;
    STRUCT_B4NODE headerOffset;
    int32_t rootWrite;
    int32_t keyDec;
    Collate4name collateName;
    uint8_t isUnicode;
    char pChar;
    MEM4st* builtKeyMemory;
    int32_t keyType;
};

}

}
