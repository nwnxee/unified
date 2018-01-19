#pragma once

#include <cstdint>

#include "CCallbackBase.hpp"

namespace NWNXLib {

namespace API {

struct CCallbackImplTemplated12
    : CCallbackBase
{

    void GetCallbackSizeBytes();
    void Run(void*, int32_t, uint64_t);
};

void CCallbackImplTemplated12__GetCallbackSizeBytes(CCallbackImplTemplated12* thisPtr);
void CCallbackImplTemplated12__Run(CCallbackImplTemplated12* thisPtr, void*, int32_t, uint64_t);

}

}
