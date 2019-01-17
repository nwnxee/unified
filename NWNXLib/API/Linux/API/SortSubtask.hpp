#pragma once

#include <cstdint>

#include "SorterFile.hpp"
#include "SorterList.hpp"
#include "unknown_SorterCompare.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct SQLiteThread;
struct UnpackedRecord;
struct VdbeSorter;

struct SortSubtask
{
    SQLiteThread* pThread;
    int32_t bDone;
    VdbeSorter* pSorter;
    UnpackedRecord* pUnpacked;
    SorterList list;
    int32_t nPMA;
    SorterCompare xCompare;
    SorterFile file;
    SorterFile file2;
};

}

}
