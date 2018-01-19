#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CNWSPersonalReputation;

struct CExoArrayListTemplatedCNWSPersonalReputation
{
    CNWSPersonalReputation* element;
    int32_t num;
    int32_t array_size;

    void Allocate(int32_t);
};

void CExoArrayListTemplatedCNWSPersonalReputation__Allocate(CExoArrayListTemplatedCNWSPersonalReputation* thisPtr, int32_t);

}

}
