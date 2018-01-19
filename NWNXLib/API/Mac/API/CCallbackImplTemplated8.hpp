#pragma once

#include <cstdint>

#include "CCallbackBase.hpp"

namespace NWNXLib {

namespace API {

struct CCallbackImplTemplated8
    : CCallbackBase
{

    int32_t GetCallbackSizeBytes();
    void Run(void*, int32_t, uint64_t);
};

int32_t CCallbackImplTemplated8__GetCallbackSizeBytes(CCallbackImplTemplated8* thisPtr);
void CCallbackImplTemplated8__Run(CCallbackImplTemplated8* thisPtr, void*, int32_t, uint64_t);

}

}
