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
        EventHandlerArea, API::Functions::CNWSArea__EventHandler,
        void, API::CNWSArea*, uint32_t, uint32_t, void*, uint32_t, uint32_t);

    DEFINE_PROFILER_TARGET_FAST(hooker,
        EventHandlerAreaOfEffect, API::Functions::CNWSAreaOfEffectObject__EventHandler,
        void, API::CNWSAreaOfEffectObject*, uint32_t, uint32_t, void*, uint32_t, uint32_t);

    DEFINE_PROFILER_TARGET_FAST(hooker,
        EventHandlerCreature, API::Functions::CNWSCreature__EventHandler,
        void, API::CNWSCreature*, uint32_t, uint32_t, void*, uint32_t, uint32_t);

    DEFINE_PROFILER_TARGET_FAST(hooker,
        EventHandlerDoor, API::Functions::CNWSDoor__EventHandler,
        void, API::CNWSDoor*, uint32_t, uint32_t, void*, uint32_t, uint32_t);

    DEFINE_PROFILER_TARGET_FAST(hooker,
        EventHandlerEncounter, API::Functions::CNWSEncounter__EventHandler,
        void, API::CNWSEncounter*, uint32_t, uint32_t, void*, uint32_t, uint32_t);

    DEFINE_PROFILER_TARGET_FAST(hooker,
        EventHandlerItem, API::Functions::CNWSItem__EventHandler,
        void, API::CNWSItem*, uint32_t, uint32_t, void*, uint32_t, uint32_t);

    DEFINE_PROFILER_TARGET_FAST(hooker,
        EventHandlerModule, API::Functions::CNWSModule__EventHandler,
        void, API::CNWSModule*, uint32_t, uint32_t, void*, uint32_t, uint32_t);

    DEFINE_PROFILER_TARGET_FAST(hooker,
        EventHandlerPlaceable, API::Functions::CNWSPlaceable__EventHandler,
        void, API::CNWSPlaceable*, uint32_t, uint32_t, void*, uint32_t, uint32_t);

    DEFINE_PROFILER_TARGET_FAST(hooker,
        EventHandlerStore, API::Functions::CNWSStore__EventHandler,
        void, API::CNWSStore*, uint32_t, uint32_t, void*, uint32_t, uint32_t);

    DEFINE_PROFILER_TARGET_FAST(hooker,
        EventHandlerTrigger, API::Functions::CNWSTrigger__EventHandler,
        void, API::CNWSTrigger*, uint32_t, uint32_t, void*, uint32_t, uint32_t);

    DEFINE_PROFILER_TARGET_FAST(hooker,
        EventHandlerWaypoint, API::Functions::CNWSWaypoint__EventHandler,
        void, API::CNWSWaypoint*, uint32_t, uint32_t, void*, uint32_t, uint32_t);
}

}
