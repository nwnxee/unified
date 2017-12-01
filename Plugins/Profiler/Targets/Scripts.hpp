#pragma once

#include "Common.hpp"
#include "ViewPtr.hpp"

namespace Profiler {

class Scripts
{
public:
    Scripts(const bool areaTimings, const bool typeTimings,
        NWNXLib::ViewPtr<NWNXLib::Services::HooksProxy> hooker,
        NWNXLib::ViewPtr<NWNXLib::Services::MetricsProxy> metrics);
};

}
