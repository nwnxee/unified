#pragma once

#include "Common.hpp"

namespace Profiler {

class Scripts
{
public:
    Scripts(const bool areaTimings, const bool typeTimings,
        NWNXLib::Services::HooksProxy* hooker,
        NWNXLib::Services::MetricsProxy* metrics);
};

}
