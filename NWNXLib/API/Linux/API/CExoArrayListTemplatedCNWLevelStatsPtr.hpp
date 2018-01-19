#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CNWLevelStats;

struct CExoArrayListTemplatedCNWLevelStatsPtr
{
    CNWLevelStats** element;
    int32_t num;
    int32_t array_size;

    void Add(CNWLevelStats*);
};

void CExoArrayListTemplatedCNWLevelStatsPtr__Add(CExoArrayListTemplatedCNWLevelStatsPtr* thisPtr, CNWLevelStats*);

}

}
