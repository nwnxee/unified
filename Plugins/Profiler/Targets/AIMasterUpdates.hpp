#pragma once

#include "nwnx.hpp"

namespace Profiler {

class AIMasterUpdates
{
public:
    AIMasterUpdates(const bool overkill,
        NWNXLib::Services::HooksProxy* hooker,
        NWNXLib::Services::MetricsProxy* metrics);

private:
    static void AIMasterUpdate(bool, CServerAIMaster* thisPtr);
};

}
