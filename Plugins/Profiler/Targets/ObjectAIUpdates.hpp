#pragma once

#include "Common.hpp"

namespace Profiler {

class ObjectAIUpdates
{
public:
    ObjectAIUpdates(NWNXLib::Services::HooksProxy* hooker,
        NWNXLib::Services::MetricsProxy* metrics);
};

}
