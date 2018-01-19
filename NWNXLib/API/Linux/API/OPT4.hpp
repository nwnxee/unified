#pragma once

#include <cstdint>

#include "LIST4.hpp"
#include "OPT4LIST.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct FILE4St;
struct OPT4BLOCK;

struct OPT4
{
    char blockPower;
    char forceCurrent;
    char numShift;
    uint8_t oldMode;
    uint8_t doUpdate;
    uint8_t checkCount;
    uint8_t dummyChar;
    uint32_t minLink;
    int32_t numBuffers;
    uint32_t maxBlocks;
    uint32_t writeBlockCount;
    uint32_t blockSize;
    uint32_t bufferSize;
    uint32_t hashTrail;
    uint32_t mask;
    uint32_t numBlocks;
    uint32_t numLists;
    uint32_t readStartPos;
    uint32_t writeStartPos;
    uint32_t writeCurPos;
    uint32_t readTimeCount;
    uint32_t accessTimeCount;
    uint32_t minAccessTimeVariation;
    char* readBuffer;
    char* writeBuffer;
    char* writeBufferActual;
    void** buffers;
    OPT4BLOCK* blocks;
    LIST4* lists;
    OPT4LIST* prio[5];
    LIST4 avail;
    OPT4LIST dbfLo;
    OPT4LIST dbfHi;
    OPT4LIST indexLo;
    OPT4LIST indexHi;
    OPT4LIST other;
    LIST4 optFiles;
    FILE4St* writeFile;
    FILE4St* readFile;
};

}

}
