#include "Targets/ObjectAIUpdates.hpp"

#include "API/Functions.hpp"
#include "ProfilerMacros.hpp"
#include "Services/Metrics/Metrics.hpp"
#include "Services/Hooks/Hooks.hpp"

namespace Profiler {

using namespace NWNXLib;

static ViewPtr<Services::MetricsProxy> g_metrics;

DECLARE_PROFILE_TARGET_FAST_SIMPLE(*g_metrics, AIUpdateArea, bool, API::CNWSArea*);
DECLARE_PROFILE_TARGET_FAST_SIMPLE(*g_metrics, AIUpdateAreaOfEffect, bool, API::CNWSAreaOfEffectObject*);
DECLARE_PROFILE_TARGET_FAST_SIMPLE(*g_metrics, AIUpdateCreature, bool, API::CNWSCreature*);
DECLARE_PROFILE_TARGET_FAST_SIMPLE(*g_metrics, AIUpdateDoor, bool, API::CNWSDoor*);
DECLARE_PROFILE_TARGET_FAST_SIMPLE(*g_metrics, AIUpdateEncounter, bool, API::CNWSEncounter*);
//DECLARE_PROFILE_TARGET_FAST_SIMPLE(*g_metrics, AIUpdateItem, bool, API::CNWSItem*);
DECLARE_PROFILE_TARGET_FAST_SIMPLE(*g_metrics, AIUpdateModule, bool, API::CNWSModule*);
DECLARE_PROFILE_TARGET_FAST_SIMPLE(*g_metrics, AIUpdatePlaceable, bool, API::CNWSPlaceable*);
DECLARE_PROFILE_TARGET_FAST_SIMPLE(*g_metrics, AIUpdateStore, bool, API::CNWSStore*);
DECLARE_PROFILE_TARGET_FAST_SIMPLE(*g_metrics, AIUpdateTrigger, bool, API::CNWSTrigger*);
DECLARE_PROFILE_TARGET_FAST_SIMPLE(*g_metrics, AIUpdateWaypoint, bool, API::CNWSWaypoint*);

ObjectAIUpdates::ObjectAIUpdates(ViewPtr<NWNXLib::Services::HooksProxy> hooker,
    ViewPtr<NWNXLib::Services::MetricsProxy> metrics)
{
    g_metrics = metrics;

    DEFINE_PROFILER_TARGET_FAST(hooker,
        AIUpdateArea, API::Functions::CNWSArea__AIUpdate,
        bool, API::CNWSArea*);

    DEFINE_PROFILER_TARGET_FAST(hooker,
        AIUpdateAreaOfEffect, API::Functions::CNWSAreaOfEffectObject__AIUpdate,
        bool, API::CNWSAreaOfEffectObject*);

    DEFINE_PROFILER_TARGET_FAST(hooker,
        AIUpdateCreature, API::Functions::CNWSCreature__AIUpdate,
        bool, API::CNWSCreature*);

    DEFINE_PROFILER_TARGET_FAST(hooker,
        AIUpdateDoor, API::Functions::CNWSDoor__AIUpdate,
        bool, API::CNWSDoor*);

    DEFINE_PROFILER_TARGET_FAST(hooker,
        AIUpdateEncounter, API::Functions::CNWSEncounter__AIUpdate,
        bool, API::CNWSEncounter*);

/*
    DEFINE_PROFILER_TARGET_FAST(hooker,
        AIUpdateItem, API::Functions::CNWSItem__AIUpdate,
        bool, API::CNWSItem*);
*/

    DEFINE_PROFILER_TARGET_FAST(hooker,
        AIUpdateModule, API::Functions::CNWSModule__AIUpdate,
        bool, API::CNWSModule*);

    DEFINE_PROFILER_TARGET_FAST(hooker,
        AIUpdatePlaceable, API::Functions::CNWSPlaceable__AIUpdate,
        bool, API::CNWSPlaceable*);

    DEFINE_PROFILER_TARGET_FAST(hooker,
        AIUpdateStore, API::Functions::CNWSStore__AIUpdate,
        bool, API::CNWSStore*);

    DEFINE_PROFILER_TARGET_FAST(hooker,
        AIUpdateTrigger, API::Functions::CNWSTrigger__AIUpdate,
        bool, API::CNWSTrigger*);

    DEFINE_PROFILER_TARGET_FAST(hooker,
        AIUpdateWaypoint, API::Functions::CNWSWaypoint__AIUpdate,
        bool, API::CNWSWaypoint*);
}

}
