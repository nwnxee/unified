#pragma once

#include "Common.hpp"
#include "ViewPtr.hpp"
#include "Services/Hooks/Hooks.hpp"

#include <cstdint>

namespace Optimizations {

class AIMasterOptimizations
{
public:
    AIMasterOptimizations(NWNXLib::ViewPtr<NWNXLib::Services::HooksProxy> hooker,
        NWNXLib::ViewPtr<NWNXLib::Services::PatchingProxy> patcher);

private:
    static void AIMasterUpdate(NWNXLib::Services::Hooks::CallType type, NWNXLib::API::CServerAIMaster*);
};

}
