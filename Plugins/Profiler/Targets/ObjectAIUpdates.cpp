#include "Targets/ObjectAIUpdates.hpp"

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

DECLARE_PROFILE_TARGET_FAST_SIMPLE(*g_metrics, AIUpdateArea, int32_t, CNWSArea*)
DECLARE_PROFILE_TARGET_FAST_SIMPLE(*g_metrics, AIUpdateAreaOfEffect, void, CNWSAreaOfEffectObject*)
DECLARE_PROFILE_TARGET_FAST_SIMPLE(*g_metrics, AIUpdateCreature, void, CNWSCreature*)
DECLARE_PROFILE_TARGET_FAST_SIMPLE(*g_metrics, AIUpdateDoor, void, CNWSDoor*)
DECLARE_PROFILE_TARGET_FAST_SIMPLE(*g_metrics, AIUpdateEncounter, void, CNWSEncounter*)
DECLARE_PROFILE_TARGET_FAST_SIMPLE(*g_metrics, AIUpdateItem, void, CNWSItem*)
DECLARE_PROFILE_TARGET_FAST_SIMPLE(*g_metrics, AIUpdateModule, int32_t, CNWSModule*)
DECLARE_PROFILE_TARGET_FAST_SIMPLE(*g_metrics, AIUpdatePlaceable, void, CNWSPlaceable*)
DECLARE_PROFILE_TARGET_FAST_SIMPLE(*g_metrics, AIUpdateStore, void, CNWSStore*)
DECLARE_PROFILE_TARGET_FAST_SIMPLE(*g_metrics, AIUpdateTrigger, void, CNWSTrigger*)
DECLARE_PROFILE_TARGET_FAST_SIMPLE(*g_metrics, AIUpdateWaypoint, void, CNWSWaypoint*)

ObjectAIUpdates::ObjectAIUpdates(NWNXLib::Services::MetricsProxy* metrics)
{
    g_metrics = metrics;

    DEFINE_PROFILER_TARGET_FAST(
        AIUpdateArea, &CNWSArea::AIUpdate,
        int32_t, CNWSArea*);

    DEFINE_PROFILER_TARGET_FAST(
        AIUpdateAreaOfEffect, &CNWSAreaOfEffectObject::AIUpdate,
        void, CNWSAreaOfEffectObject*);

    DEFINE_PROFILER_TARGET_FAST(
        AIUpdateCreature, &CNWSCreature::AIUpdate,
        void, CNWSCreature*);

    DEFINE_PROFILER_TARGET_FAST(
        AIUpdateDoor, &CNWSDoor::AIUpdate,
        void, CNWSDoor*);

    DEFINE_PROFILER_TARGET_FAST(
        AIUpdateEncounter, &CNWSEncounter::AIUpdate,
        void, CNWSEncounter*);

    DEFINE_PROFILER_TARGET_FAST(
        AIUpdateItem, &CNWSItem::AIUpdate,
        void, CNWSItem*);

    DEFINE_PROFILER_TARGET_FAST(
        AIUpdateModule, &CNWSModule::AIUpdate,
        int32_t, CNWSModule*);

    DEFINE_PROFILER_TARGET_FAST(
        AIUpdatePlaceable, &CNWSPlaceable::AIUpdate,
        void, CNWSPlaceable*);

    DEFINE_PROFILER_TARGET_FAST(
        AIUpdateStore, &CNWSStore::AIUpdate,
        void, CNWSStore*);

    DEFINE_PROFILER_TARGET_FAST(
        AIUpdateTrigger, &CNWSTrigger::AIUpdate,
        void, CNWSTrigger*);

    DEFINE_PROFILER_TARGET_FAST(
        AIUpdateWaypoint, &CNWSWaypoint::AIUpdate,
        void, CNWSWaypoint*);
}

}
