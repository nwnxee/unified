#include "Targets/MainLoop.hpp"

#include "API/Functions.hpp"
#include "API/CServerExoAppInternal.hpp"
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
        ExoAppMainLoop, &CServerExoAppInternal::MainLoop,
        int32_t, CServerExoAppInternal*);

    DEFINE_PROFILER_TARGET(
        ExoAppConnectionLibMainLoop, &CServerExoAppInternal::ConnectionLibMainLoop,
        void, CServerExoAppInternal*);

    DEFINE_PROFILER_TARGET(
        ExoAppUpdateClientGameObjects, &CServerExoAppInternal::UpdateClientGameObjects,
        void, CServerExoAppInternal*, int32_t);
}

}
