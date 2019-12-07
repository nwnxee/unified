#pragma once

#include "Common.hpp"

namespace Profiler {

class MainLoop
{
public:
    MainLoop(NWNXLib::Services::HooksProxy* hooker,
        NWNXLib::Services::MetricsProxy* metrics);
};

}
