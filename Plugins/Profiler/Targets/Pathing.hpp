#pragma once

#include "Common.hpp"

namespace Profiler {

class Pathing
{
public:
    Pathing(NWNXLib::Services::HooksProxy* hooker,
        NWNXLib::Services::MetricsProxy* metrics);
};

}
