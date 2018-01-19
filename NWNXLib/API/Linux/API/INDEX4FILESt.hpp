#pragma once

#include <cstdint>

#include "FILE4St.hpp"
#include "LIST4.hpp"
#include "STRUCT_B4NODE.hpp"
#include "l4linkSt.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CODE4St;
struct DATA4FILESt;
struct MEM4st;
struct TAG4FILESt;

struct INDEX4FILESt
{
    l4linkSt link;
    LIST4 tags;
    int32_t userCount;
    CODE4St* codeBase;
    DATA4FILESt* dataFile;
    FILE4St file;
    MEM4st* blockMemory;
    int32_t fileLocked;
    TAG4FILESt* tagIndex;
    STRUCT_B4NODE eof;
    uint32_t versionOld;
    uint32_t versionReadUnlocked;
    uint32_t blockSize;
    uint32_t multiplier;
    TAG4FILESt* readBlockTag;
    int32_t isValid;
};

}

}
