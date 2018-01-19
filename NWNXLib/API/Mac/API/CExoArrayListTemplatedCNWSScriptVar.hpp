#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CNWSScriptVar;

struct CExoArrayListTemplatedCNWSScriptVar
{
    CNWSScriptVar* element;
    int32_t num;
    int32_t array_size;

    void Allocate(int32_t);
};

void CExoArrayListTemplatedCNWSScriptVar__Allocate(CExoArrayListTemplatedCNWSScriptVar* thisPtr, int32_t);

}

}
