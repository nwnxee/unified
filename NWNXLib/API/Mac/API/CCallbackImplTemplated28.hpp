#pragma once

#include <cstdint>

#include "CCallbackBase.hpp"

namespace NWNXLib {

namespace API {

struct CCallbackImplTemplated28
    : CCallbackBase
{

    void GetCallbackSizeBytes();
    void Run(void*, int32_t, uint64_t);
};

void CCallbackImplTemplated28__GetCallbackSizeBytes(CCallbackImplTemplated28* thisPtr);
void CCallbackImplTemplated28__Run(CCallbackImplTemplated28* thisPtr, void*, int32_t, uint64_t);

}

}
