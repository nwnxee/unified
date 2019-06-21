#pragma once

#include <cstdint>

#include "SorterFile.hpp"
#include "unknown_sqlite_int64.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct MergeEngine;
struct SortSubtask;

struct IncrMerger
{
    SortSubtask* pTask;
    MergeEngine* pMerger;
    sqlite_int64 iStartOff;
    int32_t mxSz;
    int32_t bEof;
    int32_t bUseThread;
    SorterFile aFile[2];
};

}

}
