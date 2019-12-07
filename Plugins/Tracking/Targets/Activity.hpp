#pragma once

#include "Common.hpp"
#include "Services/Hooks/Hooks.hpp"
#include "ViewPtr.hpp"

namespace Tracking {

class Activity
{
public:
    Activity(NWNXLib::ViewPtr<NWNXLib::Services::MetricsProxy> metrics,
        NWNXLib::ViewPtr<NWNXLib::Services::HooksProxy> hooks);

private:
    static void MainLoopUpdate(bool, CServerExoAppInternal* thisPtr);
};

}
