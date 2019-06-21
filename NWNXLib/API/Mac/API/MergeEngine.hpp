#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct PmaReader;
struct SortSubtask;

struct MergeEngine
{
    int32_t nTree;
    SortSubtask* pTask;
    int32_t* aTree;
    PmaReader* aReadr;
};

}

}
