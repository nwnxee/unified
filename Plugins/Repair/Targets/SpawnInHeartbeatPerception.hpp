#pragma once

#include "Common.hpp"
#include "ViewPtr.hpp"

#include <sys/socket.h>

namespace Repair {

class SpawnInHeartbeatPerception
{
public:
    SpawnInHeartbeatPerception(
        NWNXLib::ViewPtr<NWNXLib::Services::MetricsProxy> metrics,
        NWNXLib::ViewPtr<NWNXLib::Services::PatchingProxy> patcher,
        NWNXLib::ViewPtr<NWNXLib::Services::LogProxy> log);

private:
    static bool SpawnInHeartbeatPerceptionInlineHook(NWNXLib::API::CNWSCreature* thisPtr);
};

}
