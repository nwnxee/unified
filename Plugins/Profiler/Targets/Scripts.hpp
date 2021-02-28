#pragma once

#include "nwnx.hpp"

namespace Profiler {

class Scripts
{
public:
    Scripts(const bool areaTimings, const bool typeTimings,
        NWNXLib::Services::MetricsProxy* metrics);
};

}
