#pragma once

#include <cstdint>

#include "SortSubtask.hpp"
#include "SorterList.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct KeyInfo;
struct MergeEngine;
struct PmaReader;
struct UnpackedRecord;
struct sqlite3;

struct VdbeSorter
{
    int32_t mnPmaSize;
    int32_t mxPmaSize;
    int32_t mxKeysize;
    int32_t pgsz;
    PmaReader* pReader;
    MergeEngine* pMerger;
    sqlite3* db;
    KeyInfo* pKeyInfo;
    UnpackedRecord* pUnpacked;
    SorterList list;
    int32_t iMemory;
    int32_t nMemory;
    uint8_t bUsePMA;
    uint8_t bUseThreads;
    uint8_t iPrev;
    uint8_t nTask;
    uint8_t typeMask;
    SortSubtask aTask[1];
};

}

}
