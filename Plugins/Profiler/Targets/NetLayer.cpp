#include "Targets/NetLayer.hpp"

#include "API/Functions.hpp"
#include "API/CNetLayer.hpp"
#include "ProfilerMacros.hpp"

namespace Profiler {

using namespace NWNXLib;

static Services::MetricsProxy* g_metrics;

DECLARE_PROFILE_TARGET_SIMPLE(*g_metrics, NetLayerProcessReceivedFrames, void, CNetLayer*, int32_t)
DECLARE_PROFILE_TARGET_SIMPLE(*g_metrics, NetLayerUpdateStatusLoop, int32_t, CNetLayer*, uint32_t)

NetLayer::NetLayer(NWNXLib::Services::MetricsProxy* metrics)
{
    g_metrics = metrics;

    DEFINE_PROFILER_TARGET(
        NetLayerProcessReceivedFrames, &CNetLayer::ProcessReceivedFrames,
        void, CNetLayer*, int32_t);

    DEFINE_PROFILER_TARGET(
        NetLayerUpdateStatusLoop, &CNetLayer::UpdateStatusLoop,
        int32_t, CNetLayer*, uint32_t);
}

}
