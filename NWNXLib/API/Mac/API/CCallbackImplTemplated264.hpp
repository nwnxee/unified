#pragma once

#include <cstdint>

#include "CCallbackBase.hpp"

namespace NWNXLib {

namespace API {

struct CCallbackImplTemplated264
    : CCallbackBase
{

    int32_t GetCallbackSizeBytes();
    void Run(void*, int32_t, uint64_t);
};

int32_t CCallbackImplTemplated264__GetCallbackSizeBytes(CCallbackImplTemplated264* thisPtr);
void CCallbackImplTemplated264__Run(CCallbackImplTemplated264* thisPtr, void*, int32_t, uint64_t);

}

}
