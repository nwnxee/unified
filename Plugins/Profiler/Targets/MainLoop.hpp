#pragma once

#include "nwnx.hpp"

namespace Profiler {

class MainLoop
{
public:
    MainLoop(NWNXLib::Services::HooksProxy* hooker,
        NWNXLib::Services::MetricsProxy* metrics);
};

}
