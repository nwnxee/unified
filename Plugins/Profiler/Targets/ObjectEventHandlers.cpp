#include "Targets/ObjectEventHandlers.hpp"

#include "API/Functions.hpp"
#include "ProfilerMacros.hpp"
#include "Services/Metrics/Metrics.hpp"
#include "Services/Hooks/Hooks.hpp"

namespace Profiler {

using namespace NWNXLib;

static ViewPtr<Services::MetricsProxy> g_metrics;

DECLARE_PROFILE_TARGET_FAST_SIMPLE(*g_metrics, EventHandlerArea, void, API::CNWSArea*, uint32_t, uint32_t, void*, uint32_t, uint32_t);
DECLARE_PROFILE_TARGET_FAST_SIMPLE(*g_metrics, EventHandlerAreaOfEffect, void, API::CNWSAreaOfEffectObject*, uint32_t, uint32_t, void*, uint32_t, uint32_t);
DECLARE_PROFILE_TARGET_FAST_SIMPLE(*g_metrics, EventHandlerCreature, void, API::CNWSCreature*, uint32_t, uint32_t, void*, uint32_t, uint32_t);
DECLARE_PROFILE_TARGET_FAST_SIMPLE(*g_metrics, EventHandlerDoor, void, API::CNWSDoor*, uint32_t, uint32_t, void*, uint32_t, uint32_t);
DECLARE_PROFILE_TARGET_FAST_SIMPLE(*g_metrics, EventHandlerEncounter, void, API::CNWSEncounter*, uint32_t, uint32_t, void*, uint32_t, uint32_t);
DECLARE_PROFILE_TARGET_FAST_SIMPLE(*g_metrics, EventHandlerItem,void, API::CNWSItem*, uint32_t, uint32_t, void*, uint32_t, uint32_t);
DECLARE_PROFILE_TARGET_FAST_SIMPLE(*g_metrics, EventHandlerModule, void, API::CNWSModule*, uint32_t, uint32_t, void*, uint32_t, uint32_t);
DECLARE_PROFILE_TARGET_FAST_SIMPLE(*g_metrics, EventHandlerPlaceable, void, API::CNWSPlaceable*, uint32_t, uint32_t, void*, uint32_t, uint32_t);
DECLARE_PROFILE_TARGET_FAST_SIMPLE(*g_metrics, EventHandlerStore, void, API::CNWSStore*, uint32_t, uint32_t, void*, uint32_t, uint32_t);
DECLARE_PROFILE_TARGET_FAST_SIMPLE(*g_metrics, EventHandlerTrigger, void, API::CNWSTrigger*, uint32_t, uint32_t, void*, uint32_t, uint32_t);
DECLARE_PROFILE_TARGET_FAST_SIMPLE(*g_metrics, EventHandlerWaypoint, void, API::CNWSWaypoint*, uint32_t, uint32_t, void*, uint32_t, uint32_t);

ObjectEventHandlers::ObjectEventHandlers(ViewPtr<NWNXLib::Services::HooksProxy> hooker,
    ViewPtr<NWNXLib::Services::MetricsProxy> metrics)
{
    g_metrics = metrics;

    DEFINE_PROFILER_TARGET_FAST(hooker,
        EventHandlerArea, API::Functions::_ZN8CNWSArea12EventHandlerEjjPvjj,
        void, API::CNWSArea*, uint32_t, uint32_t, void*, uint32_t, uint32_t);

    DEFINE_PROFILER_TARGET_FAST(hooker,
        EventHandlerAreaOfEffect, API::Functions::_ZN22CNWSAreaOfEffectObject12EventHandlerEjjPvjj,
        void, API::CNWSAreaOfEffectObject*, uint32_t, uint32_t, void*, uint32_t, uint32_t);

    DEFINE_PROFILER_TARGET_FAST(hooker,
        EventHandlerCreature, API::Functions::_ZN12CNWSCreature12EventHandlerEjjPvjj,
        void, API::CNWSCreature*, uint32_t, uint32_t, void*, uint32_t, uint32_t);

    DEFINE_PROFILER_TARGET_FAST(hooker,
        EventHandlerDoor, API::Functions::_ZN8CNWSDoor12EventHandlerEjjPvjj,
        void, API::CNWSDoor*, uint32_t, uint32_t, void*, uint32_t, uint32_t);

    DEFINE_PROFILER_TARGET_FAST(hooker,
        EventHandlerEncounter, API::Functions::_ZN13CNWSEncounter12EventHandlerEjjPvjj,
        void, API::CNWSEncounter*, uint32_t, uint32_t, void*, uint32_t, uint32_t);

    DEFINE_PROFILER_TARGET_FAST(hooker,
        EventHandlerItem, API::Functions::_ZN8CNWSItem12EventHandlerEjjPvjj,
        void, API::CNWSItem*, uint32_t, uint32_t, void*, uint32_t, uint32_t);

    DEFINE_PROFILER_TARGET_FAST(hooker,
        EventHandlerModule, API::Functions::_ZN10CNWSModule12EventHandlerEjjPvjj,
        void, API::CNWSModule*, uint32_t, uint32_t, void*, uint32_t, uint32_t);

    DEFINE_PROFILER_TARGET_FAST(hooker,
        EventHandlerPlaceable, API::Functions::_ZN13CNWSPlaceable12EventHandlerEjjPvjj,
        void, API::CNWSPlaceable*, uint32_t, uint32_t, void*, uint32_t, uint32_t);

    DEFINE_PROFILER_TARGET_FAST(hooker,
        EventHandlerStore, API::Functions::_ZN9CNWSStore12EventHandlerEjjPvjj,
        void, API::CNWSStore*, uint32_t, uint32_t, void*, uint32_t, uint32_t);

    DEFINE_PROFILER_TARGET_FAST(hooker,
        EventHandlerTrigger, API::Functions::_ZN11CNWSTrigger12EventHandlerEjjPvjj,
        void, API::CNWSTrigger*, uint32_t, uint32_t, void*, uint32_t, uint32_t);

    DEFINE_PROFILER_TARGET_FAST(hooker,
        EventHandlerWaypoint, API::Functions::_ZN12CNWSWaypoint12EventHandlerEjjPvjj,
        void, API::CNWSWaypoint*, uint32_t, uint32_t, void*, uint32_t, uint32_t);
}

}
