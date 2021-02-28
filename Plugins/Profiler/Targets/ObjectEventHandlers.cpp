#include "Targets/ObjectEventHandlers.hpp"

#include "API/Functions.hpp"
#include "ProfilerMacros.hpp"

namespace Profiler {

using namespace NWNXLib;

static Services::MetricsProxy* g_metrics;

DECLARE_PROFILE_TARGET_FAST_SIMPLE(*g_metrics, EventHandlerArea, void, CNWSArea*, uint32_t, uint32_t, void*, uint32_t, uint32_t)
DECLARE_PROFILE_TARGET_FAST_SIMPLE(*g_metrics, EventHandlerAreaOfEffect, void, CNWSAreaOfEffectObject*, uint32_t, uint32_t, void*, uint32_t, uint32_t)
DECLARE_PROFILE_TARGET_FAST_SIMPLE(*g_metrics, EventHandlerCreature, void, CNWSCreature*, uint32_t, uint32_t, void*, uint32_t, uint32_t)
DECLARE_PROFILE_TARGET_FAST_SIMPLE(*g_metrics, EventHandlerDoor, void, CNWSDoor*, uint32_t, uint32_t, void*, uint32_t, uint32_t)
DECLARE_PROFILE_TARGET_FAST_SIMPLE(*g_metrics, EventHandlerEncounter, void, CNWSEncounter*, uint32_t, uint32_t, void*, uint32_t, uint32_t)
DECLARE_PROFILE_TARGET_FAST_SIMPLE(*g_metrics, EventHandlerItem,void, CNWSItem*, uint32_t, uint32_t, void*, uint32_t, uint32_t)
DECLARE_PROFILE_TARGET_FAST_SIMPLE(*g_metrics, EventHandlerModule, void, CNWSModule*, uint32_t, uint32_t, void*, uint32_t, uint32_t)
DECLARE_PROFILE_TARGET_FAST_SIMPLE(*g_metrics, EventHandlerPlaceable, void, CNWSPlaceable*, uint32_t, uint32_t, void*, uint32_t, uint32_t)
DECLARE_PROFILE_TARGET_FAST_SIMPLE(*g_metrics, EventHandlerStore, void, CNWSStore*, uint32_t, uint32_t, void*, uint32_t, uint32_t)
DECLARE_PROFILE_TARGET_FAST_SIMPLE(*g_metrics, EventHandlerTrigger, void, CNWSTrigger*, uint32_t, uint32_t, void*, uint32_t, uint32_t)
DECLARE_PROFILE_TARGET_FAST_SIMPLE(*g_metrics, EventHandlerWaypoint, void, CNWSWaypoint*, uint32_t, uint32_t, void*, uint32_t, uint32_t)

ObjectEventHandlers::ObjectEventHandlers(NWNXLib::Services::MetricsProxy* metrics)
{
    g_metrics = metrics;

    DEFINE_PROFILER_TARGET_FAST(
        EventHandlerArea, API::Functions::_ZN8CNWSArea12EventHandlerEjjPvjj,
        void, CNWSArea*, uint32_t, uint32_t, void*, uint32_t, uint32_t);

    DEFINE_PROFILER_TARGET_FAST(
        EventHandlerAreaOfEffect, API::Functions::_ZN22CNWSAreaOfEffectObject12EventHandlerEjjPvjj,
        void, CNWSAreaOfEffectObject*, uint32_t, uint32_t, void*, uint32_t, uint32_t);

    DEFINE_PROFILER_TARGET_FAST(
        EventHandlerCreature, API::Functions::_ZN12CNWSCreature12EventHandlerEjjPvjj,
        void, CNWSCreature*, uint32_t, uint32_t, void*, uint32_t, uint32_t);

    DEFINE_PROFILER_TARGET_FAST(
        EventHandlerDoor, API::Functions::_ZN8CNWSDoor12EventHandlerEjjPvjj,
        void, CNWSDoor*, uint32_t, uint32_t, void*, uint32_t, uint32_t);

    DEFINE_PROFILER_TARGET_FAST(
        EventHandlerEncounter, API::Functions::_ZN13CNWSEncounter12EventHandlerEjjPvjj,
        void, CNWSEncounter*, uint32_t, uint32_t, void*, uint32_t, uint32_t);

    DEFINE_PROFILER_TARGET_FAST(
        EventHandlerItem, API::Functions::_ZN8CNWSItem12EventHandlerEjjPvjj,
        void, CNWSItem*, uint32_t, uint32_t, void*, uint32_t, uint32_t);

    DEFINE_PROFILER_TARGET_FAST(
        EventHandlerModule, API::Functions::_ZN10CNWSModule12EventHandlerEjjPvjj,
        void, CNWSModule*, uint32_t, uint32_t, void*, uint32_t, uint32_t);

    DEFINE_PROFILER_TARGET_FAST(
        EventHandlerPlaceable, API::Functions::_ZN13CNWSPlaceable12EventHandlerEjjPvjj,
        void, CNWSPlaceable*, uint32_t, uint32_t, void*, uint32_t, uint32_t);

    DEFINE_PROFILER_TARGET_FAST(
        EventHandlerStore, API::Functions::_ZN9CNWSStore12EventHandlerEjjPvjj,
        void, CNWSStore*, uint32_t, uint32_t, void*, uint32_t, uint32_t);

    DEFINE_PROFILER_TARGET_FAST(
        EventHandlerTrigger, API::Functions::_ZN11CNWSTrigger12EventHandlerEjjPvjj,
        void, CNWSTrigger*, uint32_t, uint32_t, void*, uint32_t, uint32_t);

    DEFINE_PROFILER_TARGET_FAST(
        EventHandlerWaypoint, API::Functions::_ZN12CNWSWaypoint12EventHandlerEjjPvjj,
        void, CNWSWaypoint*, uint32_t, uint32_t, void*, uint32_t, uint32_t);
}

}
