#pragma once

#include "Common.hpp"
#include "ViewPtr.hpp"

namespace Profiler {

class MainLoop
{
public:
    MainLoop(NWNXLib::ViewPtr<NWNXLib::Services::HooksProxy> hooker,
        NWNXLib::ViewPtr<NWNXLib::Services::MetricsProxy> metrics);
};

}
