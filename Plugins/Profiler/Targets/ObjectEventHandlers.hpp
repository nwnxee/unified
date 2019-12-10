#pragma once

#include "Common.hpp"

namespace Profiler {

class ObjectEventHandlers
{
public:
    ObjectEventHandlers(NWNXLib::Services::HooksProxy* hooker,
        NWNXLib::Services::MetricsProxy* metrics);
};

}
