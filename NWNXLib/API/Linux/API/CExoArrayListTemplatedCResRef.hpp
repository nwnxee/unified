#pragma once

#include <cstdint>

#include "CResRef.hpp"

namespace NWNXLib {

namespace API {

struct CExoArrayListTemplatedCResRef
{
    CResRef* element;
    int32_t num;
    int32_t array_size;

    void Add(CResRef);
    void Allocate(int32_t);
};

void CExoArrayListTemplatedCResRef__Add(CExoArrayListTemplatedCResRef* thisPtr, CResRef);
void CExoArrayListTemplatedCResRef__Allocate(CExoArrayListTemplatedCResRef* thisPtr, int32_t);

}

}
