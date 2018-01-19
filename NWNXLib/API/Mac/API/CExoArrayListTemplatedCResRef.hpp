#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CResRef;

struct CExoArrayListTemplatedCResRef
{
    CResRef* element;
    int32_t num;
    int32_t array_size;

    void Allocate(int32_t);
};

void CExoArrayListTemplatedCResRef__Allocate(CExoArrayListTemplatedCResRef* thisPtr, int32_t);

}

}
