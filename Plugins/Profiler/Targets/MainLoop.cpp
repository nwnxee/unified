#include "Targets/MainLoop.hpp"

#include "API/Functions.hpp"
#include "ProfilerMacros.hpp"

namespace Profiler {

using namespace NWNXLib;

static Services::MetricsProxy* g_metrics;

DECLARE_PROFILE_TARGET_SIMPLE(*g_metrics, ExoAppMainLoop, int32_t, CServerExoAppInternal*)
DECLARE_PROFILE_TARGET_SIMPLE(*g_metrics, ExoAppConnectionLibMainLoop, void, CServerExoAppInternal*)
DECLARE_PROFILE_TARGET_SIMPLE(*g_metrics, ExoAppUpdateClientGameObjects, void, CServerExoAppInternal*, int32_t)

MainLoop::MainLoop(NWNXLib::Services::MetricsProxy* metrics)
{
    g_metrics = metrics;

    DEFINE_PROFILER_TARGET(
        ExoAppMainLoop, API::Functions::_ZN21CServerExoAppInternal8MainLoopEv,
        int32_t, CServerExoAppInternal*);

    DEFINE_PROFILER_TARGET(
        ExoAppConnectionLibMainLoop, API::Functions::_ZN21CServerExoAppInternal21ConnectionLibMainLoopEv,
        void, CServerExoAppInternal*);

    DEFINE_PROFILER_TARGET(
        ExoAppUpdateClientGameObjects, API::Functions::_ZN21CServerExoAppInternal23UpdateClientGameObjectsEi,
        void, CServerExoAppInternal*, int32_t);
}

}
