#include "Targets/ObjectEventHandlers.hpp"

#include "API/Functions.hpp"
#include "API/CNWSArea.hpp"
#include "API/CNWSAreaOfEffectObject.hpp"
#include "API/CNWSCreature.hpp"
#include "API/CNWSDoor.hpp"
#include "API/CNWSEncounter.hpp"
#include "API/CNWSItem.hpp"
#include "API/CNWSModule.hpp"
#include "API/CNWSPlaceable.hpp"
#include "API/CNWSStore.hpp"
#include "API/CNWSTrigger.hpp"
#include "API/CNWSWaypoint.hpp"
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
        EventHandlerArea, &CNWSArea::EventHandler,
        void, CNWSArea*, uint32_t, uint32_t, void*, uint32_t, uint32_t);

    DEFINE_PROFILER_TARGET_FAST(
        EventHandlerAreaOfEffect, &CNWSAreaOfEffectObject::EventHandler,
        void, CNWSAreaOfEffectObject*, uint32_t, uint32_t, void*, uint32_t, uint32_t);

    DEFINE_PROFILER_TARGET_FAST(
        EventHandlerCreature, &CNWSCreature::EventHandler,
        void, CNWSCreature*, uint32_t, uint32_t, void*, uint32_t, uint32_t);

    DEFINE_PROFILER_TARGET_FAST(
        EventHandlerDoor, &CNWSDoor::EventHandler,
        void, CNWSDoor*, uint32_t, uint32_t, void*, uint32_t, uint32_t);

    DEFINE_PROFILER_TARGET_FAST(
        EventHandlerEncounter, &CNWSEncounter::EventHandler,
        void, CNWSEncounter*, uint32_t, uint32_t, void*, uint32_t, uint32_t);

    DEFINE_PROFILER_TARGET_FAST(
        EventHandlerItem, &CNWSItem::EventHandler,
        void, CNWSItem*, uint32_t, uint32_t, void*, uint32_t, uint32_t);

    DEFINE_PROFILER_TARGET_FAST(
        EventHandlerModule, &CNWSModule::EventHandler,
        void, CNWSModule*, uint32_t, uint32_t, void*, uint32_t, uint32_t);

    DEFINE_PROFILER_TARGET_FAST(
        EventHandlerPlaceable, &CNWSPlaceable::EventHandler,
        void, CNWSPlaceable*, uint32_t, uint32_t, void*, uint32_t, uint32_t);

    DEFINE_PROFILER_TARGET_FAST(
        EventHandlerStore, &CNWSStore::EventHandler,
        void, CNWSStore*, uint32_t, uint32_t, void*, uint32_t, uint32_t);

    DEFINE_PROFILER_TARGET_FAST(
        EventHandlerTrigger, API::Functions::_ZN11CNWSTrigger12EventHandlerEjjPvjj,
        void, CNWSTrigger*, uint32_t, uint32_t, void*, uint32_t, uint32_t);

    DEFINE_PROFILER_TARGET_FAST(
        EventHandlerWaypoint, &CNWSWaypoint::EventHandler,
        void, CNWSWaypoint*, uint32_t, uint32_t, void*, uint32_t, uint32_t);
}

}
