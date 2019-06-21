#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct VdbeOp;

struct SubProgram
{
    VdbeOp* aOp;
    int32_t nOp;
    int32_t nMem;
    int32_t nCsr;
    uint8_t* aOnce;
    void* token;
    SubProgram* pNext;
};

}

}
