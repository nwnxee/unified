#pragma once

#include "Common.hpp"

namespace Profiler {

class NetLayer
{
public:
    NetLayer(NWNXLib::Services::HooksProxy* hooker,
        NWNXLib::Services::MetricsProxy* metrics);
};

}
