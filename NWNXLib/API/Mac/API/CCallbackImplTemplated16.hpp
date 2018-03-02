#pragma once

#include <cstdint>

#include "CCallbackBase.hpp"

namespace NWNXLib {

namespace API {

struct CCallbackImplTemplated16
    : CCallbackBase
{

    int32_t GetCallbackSizeBytes();
    void Run(void*, int32_t, uint64_t);
};

int32_t CCallbackImplTemplated16__GetCallbackSizeBytes(CCallbackImplTemplated16* thisPtr);
void CCallbackImplTemplated16__Run(CCallbackImplTemplated16* thisPtr, void*, int32_t, uint64_t);

}

}
