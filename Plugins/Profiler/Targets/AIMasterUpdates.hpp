#pragma once

#include "Common.hpp"
#include "Services/Hooks/Hooks.hpp"
#include "ViewPtr.hpp"

namespace Profiler {

class AIMasterUpdates
{
public:
    AIMasterUpdates(const bool overkill,
        NWNXLib::ViewPtr<NWNXLib::Services::HooksProxy> hooker,
        NWNXLib::ViewPtr<NWNXLib::Services::MetricsProxy> metrics);

private:
    static void AIMasterUpdate(bool, CServerAIMaster* thisPtr);
};

}
