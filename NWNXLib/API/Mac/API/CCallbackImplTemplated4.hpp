#pragma once

#include <cstdint>

#include "CCallbackBase.hpp"

namespace NWNXLib {

namespace API {

struct CCallbackImplTemplated4
    : CCallbackBase
{

    int32_t GetCallbackSizeBytes();
    void Run(void*, int32_t, uint64_t);
};

int32_t CCallbackImplTemplated4__GetCallbackSizeBytes(CCallbackImplTemplated4* thisPtr);
void CCallbackImplTemplated4__Run(CCallbackImplTemplated4* thisPtr, void*, int32_t, uint64_t);

}

}
