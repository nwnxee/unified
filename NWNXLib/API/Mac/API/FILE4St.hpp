#pragma once

#include <cstdint>

#include "FILE4LONG_EXTENDSt.hpp"
#include "LIST4.hpp"
#include "l4linkSt.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CODE4St;

struct FILE4St
{
    l4linkSt link;
    char doAllocFree;
    char isTemp;
    int32_t hand;
    int32_t isReadOnly;
    char* nameBuf;
    const char* name;
    CODE4St* codeBase;
    int32_t lowAccessMode;
    char space26;
    char fileCreated;
    char writeBuffer;
    int32_t hashInit;
    uint32_t len;
    FILE4LONG_EXTENDSt space0;
    char type;
    char bufferWrites;
    int32_t doBuffer;
    int32_t expectedReadSize;
    double hitCountAdd;
    const void* ownerPtr;
    LIST4 space28;
    int32_t space30a;
    LIST4 space30b;
    char* space30c;
    int32_t space30d;
    uint32_t space30e;
    uint32_t space30f;
};

}

}
