#include "Targets/AIMasterUpdates.hpp"

#include "API/Constants.hpp"
#include "API/CExoLinkedListInternal.hpp"
#include "API/CExoLinkedList.hpp"
#include "API/CServerAIMaster.hpp"
#include "API/Functions.hpp"
#include "ProfilerMacros.hpp"
#include "Services/Metrics/Metrics.hpp"
#include "Services/Metrics/Resamplers.hpp"

#include <chrono>

namespace Profiler {

using namespace NWNXLib;
using namespace NWNXLib::Services;

static ViewPtr<MetricsProxy> g_metrics;

DECLARE_PROFILE_TARGET_SIMPLE(*g_metrics, AIMasterUpdateState, void, API::CServerAIMaster*);
DECLARE_PROFILE_TARGET_FAST_SIMPLE(*g_metrics, EventPending, bool, API::CServerAIMaster*, uint32_t, uint32_t);
DECLARE_PROFILE_TARGET_FAST_SIMPLE(*g_metrics, GetNextObject, API::CNWSObject*, API::CServerAIList*);
DECLARE_PROFILE_TARGET_FAST_SIMPLE(*g_metrics, GetPendingEvent, bool, API::CServerAIMaster*, uint32_t*, uint32_t*, uint32_t*, uint32_t*, uint32_t*, void**);
DECLARE_PROFILE_TARGET_FAST_SIMPLE(*g_metrics, UpdateDialog, bool, API::CNWSObject*);

AIMasterUpdates::AIMasterUpdates(const bool overkill,
    ViewPtr<HooksProxy> hooker,
    ViewPtr<MetricsProxy> metrics)
{
    g_metrics = metrics;

    hooker->RequestSharedHook<API::Functions::CServerAIMaster__UpdateState, void>(&AIMasterUpdate);

    Resamplers::ResamplerFuncPtr resampler = &Resamplers::template Mean<uint32_t>;
    metrics->SetResampler("AIQueuedEvents", resampler, std::chrono::seconds(1));
    metrics->SetResampler("AIUpdateListObjects", resampler, std::chrono::seconds(1));

    DEFINE_PROFILER_TARGET(hooker,
        AIMasterUpdateState, API::Functions::CServerAIMaster__UpdateState,
        void, API::CServerAIMaster*);

    if (overkill)
    {
        DEFINE_PROFILER_TARGET_FAST(hooker,
            EventPending, API::Functions::CServerAIMaster__EventPending,
            bool, API::CServerAIMaster*, uint32_t, uint32_t);

        DEFINE_PROFILER_TARGET_FAST(hooker,
            GetNextObject, API::Functions::CServerAIList__GetNextObject,
            API::CNWSObject*, API::CServerAIList*);

        DEFINE_PROFILER_TARGET_FAST(hooker,
            GetPendingEvent, API::Functions::CServerAIMaster__GetPendingEvent,
            bool, API::CServerAIMaster*, uint32_t*, uint32_t*, uint32_t*, uint32_t*, uint32_t*, void**);

        DEFINE_PROFILER_TARGET_FAST(hooker,
            UpdateDialog, API::Functions::CNWSObject__UpdateDialog,
            bool, API::CNWSObject*);
    }
}

void AIMasterUpdates::AIMasterUpdate(Hooks::CallType type, API::CServerAIMaster* thisPtr)
{
    if (type != Hooks::CallType::BEFORE_ORIGINAL)
    {
        return;
    }

    g_metrics->Push("AIQueuedEvents", { { "Count", std::to_string(thisPtr->m_lEventQueue.m_pcExoLinkedListInternal->m_nCount) } });

    using namespace API::Constants;
    for (uint8_t i = AIPriority::MIN; i <= AIPriority::MAX; ++i)
    {
        g_metrics->Push("AIUpdateListObjects",
            { { "Count", std::to_string(thisPtr->m_apGameAIList[i].m_aoGameObjects.num) } },
            { { "Level", AIPriority::ToString(i) } });
    }
}

}
