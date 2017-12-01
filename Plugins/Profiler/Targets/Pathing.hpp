#pragma once

#include "Common.hpp"
#include "ViewPtr.hpp"

namespace Profiler {

class Pathing
{
public:
    Pathing(NWNXLib::ViewPtr<NWNXLib::Services::HooksProxy> hooker,
        NWNXLib::ViewPtr<NWNXLib::Services::MetricsProxy> metrics);
};

}
