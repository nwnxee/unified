#pragma once

#include <cstdint>

#include "CNWSPersonalReputation.hpp"

namespace NWNXLib {

namespace API {

struct CExoArrayListTemplatedCNWSPersonalReputation
{
    CNWSPersonalReputation* element;
    int32_t num;
    int32_t array_size;

    void Add(CNWSPersonalReputation);
    void Allocate(int32_t);
};

void CExoArrayListTemplatedCNWSPersonalReputation__Add(CExoArrayListTemplatedCNWSPersonalReputation* thisPtr, CNWSPersonalReputation);
void CExoArrayListTemplatedCNWSPersonalReputation__Allocate(CExoArrayListTemplatedCNWSPersonalReputation* thisPtr, int32_t);

}

}
