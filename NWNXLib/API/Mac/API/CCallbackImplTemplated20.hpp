#pragma once

#include <cstdint>

#include "CCallbackBase.hpp"

namespace NWNXLib {

namespace API {

struct CCallbackImplTemplated20
    : CCallbackBase
{

    void GetCallbackSizeBytes();
    void Run(void*, int32_t, uint64_t);
};

void CCallbackImplTemplated20__GetCallbackSizeBytes(CCallbackImplTemplated20* thisPtr);
void CCallbackImplTemplated20__Run(CCallbackImplTemplated20* thisPtr, void*, int32_t, uint64_t);

}

}
