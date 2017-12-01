#pragma once

#include "Common.hpp"
#include "ViewPtr.hpp"
#include "Services/Hooks/Hooks.hpp"

#include <cstdint>

namespace Optimizations {

class GetHRTOptimization
{
public:
    GetHRTOptimization(const uint32_t flushCount, NWNXLib::ViewPtr<NWNXLib::Services::HooksProxy> hooker,
        NWNXLib::ViewPtr<NWNXLib::Services::PatchingProxy> patcher);

    static void MainLoopUpdate(NWNXLib::Services::Hooks::CallType type, NWNXLib::API::CServerExoAppInternal*);
    static uint64_t GetHighResolutionTimer(NWNXLib::API::CExoTimersInternal* thisPtr);
    static uint64_t GetHighResolutionTimerWithCacheReset(NWNXLib::API::CExoTimers* thisPtr);
};

}
