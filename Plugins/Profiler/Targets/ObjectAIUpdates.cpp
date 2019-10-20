#include "Targets/ObjectAIUpdates.hpp"

#include "API/Functions.hpp"
#include "ProfilerMacros.hpp"
#include "Services/Metrics/Metrics.hpp"
#include "Services/Hooks/Hooks.hpp"

namespace Profiler {

using namespace NWNXLib;

static ViewPtr<Services::MetricsProxy> g_metrics;

DECLARE_PROFILE_TARGET_FAST_SIMPLE(*g_metrics, AIUpdateArea, bool, CNWSArea*);
DECLARE_PROFILE_TARGET_FAST_SIMPLE(*g_metrics, AIUpdateAreaOfEffect, bool, CNWSAreaOfEffectObject*);
DECLARE_PROFILE_TARGET_FAST_SIMPLE(*g_metrics, AIUpdateCreature, bool, CNWSCreature*);
DECLARE_PROFILE_TARGET_FAST_SIMPLE(*g_metrics, AIUpdateDoor, bool, CNWSDoor*);
DECLARE_PROFILE_TARGET_FAST_SIMPLE(*g_metrics, AIUpdateEncounter, bool, CNWSEncounter*);
DECLARE_PROFILE_TARGET_FAST_SIMPLE(*g_metrics, AIUpdateItem, bool, CNWSItem*);
DECLARE_PROFILE_TARGET_FAST_SIMPLE(*g_metrics, AIUpdateModule, bool, CNWSModule*);
DECLARE_PROFILE_TARGET_FAST_SIMPLE(*g_metrics, AIUpdatePlaceable, bool, CNWSPlaceable*);
DECLARE_PROFILE_TARGET_FAST_SIMPLE(*g_metrics, AIUpdateStore, bool, CNWSStore*);
DECLARE_PROFILE_TARGET_FAST_SIMPLE(*g_metrics, AIUpdateTrigger, bool, CNWSTrigger*);
DECLARE_PROFILE_TARGET_FAST_SIMPLE(*g_metrics, AIUpdateWaypoint, bool, CNWSWaypoint*);

ObjectAIUpdates::ObjectAIUpdates(ViewPtr<NWNXLib::Services::HooksProxy> hooker,
    ViewPtr<NWNXLib::Services::MetricsProxy> metrics)
{
    g_metrics = metrics;

    DEFINE_PROFILER_TARGET_FAST(hooker,
        AIUpdateArea, API::Functions::_ZN8CNWSArea8AIUpdateEv,
        bool, CNWSArea*);

    DEFINE_PROFILER_TARGET_FAST(hooker,
        AIUpdateAreaOfEffect, API::Functions::_ZN22CNWSAreaOfEffectObject8AIUpdateEv,
        bool, CNWSAreaOfEffectObject*);

    DEFINE_PROFILER_TARGET_FAST(hooker,
        AIUpdateCreature, API::Functions::_ZN12CNWSCreature8AIUpdateEv,
        bool, CNWSCreature*);

    DEFINE_PROFILER_TARGET_FAST(hooker,
        AIUpdateDoor, API::Functions::_ZN8CNWSDoor8AIUpdateEv,
        bool, CNWSDoor*);

    DEFINE_PROFILER_TARGET_FAST(hooker,
        AIUpdateEncounter, API::Functions::_ZN13CNWSEncounter8AIUpdateEv,
        bool, CNWSEncounter*);

    DEFINE_PROFILER_TARGET_FAST(hooker,
        AIUpdateItem, API::Functions::_ZN8CNWSItem8AIUpdateEv,
        bool, CNWSItem*);

    DEFINE_PROFILER_TARGET_FAST(hooker,
        AIUpdateModule, API::Functions::_ZN10CNWSModule8AIUpdateEv,
        bool, CNWSModule*);

    DEFINE_PROFILER_TARGET_FAST(hooker,
        AIUpdatePlaceable, API::Functions::_ZN13CNWSPlaceable8AIUpdateEv,
        bool, CNWSPlaceable*);

    DEFINE_PROFILER_TARGET_FAST(hooker,
        AIUpdateStore, API::Functions::_ZN9CNWSStore8AIUpdateEv,
        bool, CNWSStore*);

    DEFINE_PROFILER_TARGET_FAST(hooker,
        AIUpdateTrigger, API::Functions::_ZN11CNWSTrigger8AIUpdateEv,
        bool, CNWSTrigger*);

    DEFINE_PROFILER_TARGET_FAST(hooker,
        AIUpdateWaypoint, API::Functions::_ZN12CNWSWaypoint8AIUpdateEv,
        bool, CNWSWaypoint*);
}

}
