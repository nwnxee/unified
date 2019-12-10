#include "Targets/ObjectAIUpdates.hpp"

#include "API/Functions.hpp"
#include "ProfilerMacros.hpp"
#include "Services/Metrics/Metrics.hpp"
#include "Services/Hooks/Hooks.hpp"

namespace Profiler {

using namespace NWNXLib;

static Services::MetricsProxy* g_metrics;

DECLARE_PROFILE_TARGET_FAST_SIMPLE(*g_metrics, AIUpdateArea, int32_t, CNWSArea*);
DECLARE_PROFILE_TARGET_FAST_SIMPLE(*g_metrics, AIUpdateAreaOfEffect, void, CNWSAreaOfEffectObject*);
DECLARE_PROFILE_TARGET_FAST_SIMPLE(*g_metrics, AIUpdateCreature, void, CNWSCreature*);
DECLARE_PROFILE_TARGET_FAST_SIMPLE(*g_metrics, AIUpdateDoor, void, CNWSDoor*);
DECLARE_PROFILE_TARGET_FAST_SIMPLE(*g_metrics, AIUpdateEncounter, void, CNWSEncounter*);
DECLARE_PROFILE_TARGET_FAST_SIMPLE(*g_metrics, AIUpdateItem, void, CNWSItem*);
DECLARE_PROFILE_TARGET_FAST_SIMPLE(*g_metrics, AIUpdateModule, int32_t, CNWSModule*);
DECLARE_PROFILE_TARGET_FAST_SIMPLE(*g_metrics, AIUpdatePlaceable, void, CNWSPlaceable*);
DECLARE_PROFILE_TARGET_FAST_SIMPLE(*g_metrics, AIUpdateStore, void, CNWSStore*);
DECLARE_PROFILE_TARGET_FAST_SIMPLE(*g_metrics, AIUpdateTrigger, void, CNWSTrigger*);
DECLARE_PROFILE_TARGET_FAST_SIMPLE(*g_metrics, AIUpdateWaypoint, void, CNWSWaypoint*);

ObjectAIUpdates::ObjectAIUpdates(NWNXLib::Services::HooksProxy* hooker,
    NWNXLib::Services::MetricsProxy* metrics)
{
    g_metrics = metrics;

    DEFINE_PROFILER_TARGET_FAST(hooker,
        AIUpdateArea, API::Functions::_ZN8CNWSArea8AIUpdateEv,
        int32_t, CNWSArea*);

    DEFINE_PROFILER_TARGET_FAST(hooker,
        AIUpdateAreaOfEffect, API::Functions::_ZN22CNWSAreaOfEffectObject8AIUpdateEv,
        void, CNWSAreaOfEffectObject*);

    DEFINE_PROFILER_TARGET_FAST(hooker,
        AIUpdateCreature, API::Functions::_ZN12CNWSCreature8AIUpdateEv,
        void, CNWSCreature*);

    DEFINE_PROFILER_TARGET_FAST(hooker,
        AIUpdateDoor, API::Functions::_ZN8CNWSDoor8AIUpdateEv,
        void, CNWSDoor*);

    DEFINE_PROFILER_TARGET_FAST(hooker,
        AIUpdateEncounter, API::Functions::_ZN13CNWSEncounter8AIUpdateEv,
        void, CNWSEncounter*);

    DEFINE_PROFILER_TARGET_FAST(hooker,
        AIUpdateItem, API::Functions::_ZN8CNWSItem8AIUpdateEv,
        void, CNWSItem*);

    DEFINE_PROFILER_TARGET_FAST(hooker,
        AIUpdateModule, API::Functions::_ZN10CNWSModule8AIUpdateEv,
        int32_t, CNWSModule*);

    DEFINE_PROFILER_TARGET_FAST(hooker,
        AIUpdatePlaceable, API::Functions::_ZN13CNWSPlaceable8AIUpdateEv,
        void, CNWSPlaceable*);

    DEFINE_PROFILER_TARGET_FAST(hooker,
        AIUpdateStore, API::Functions::_ZN9CNWSStore8AIUpdateEv,
        void, CNWSStore*);

    DEFINE_PROFILER_TARGET_FAST(hooker,
        AIUpdateTrigger, API::Functions::_ZN11CNWSTrigger8AIUpdateEv,
        void, CNWSTrigger*);

    DEFINE_PROFILER_TARGET_FAST(hooker,
        AIUpdateWaypoint, API::Functions::_ZN12CNWSWaypoint8AIUpdateEv,
        void, CNWSWaypoint*);
}

}
