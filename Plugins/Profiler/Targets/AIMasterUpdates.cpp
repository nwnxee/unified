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

static MetricsProxy* g_metrics;

DECLARE_PROFILE_TARGET_SIMPLE(*g_metrics, AIMasterUpdateState, void, CServerAIMaster*);
DECLARE_PROFILE_TARGET_FAST_SIMPLE(*g_metrics, EventPending, int32_t, CServerAIMaster*, uint32_t, uint32_t);
DECLARE_PROFILE_TARGET_FAST_SIMPLE(*g_metrics, GetNextObject, CNWSObject*, CServerAIList*);
DECLARE_PROFILE_TARGET_FAST_SIMPLE(*g_metrics, GetPendingEvent, int32_t, CServerAIMaster*, uint32_t*, uint32_t*, uint32_t*, uint32_t*, uint32_t*, void**);
DECLARE_PROFILE_TARGET_FAST_SIMPLE(*g_metrics, UpdateDialog, int32_t, CNWSObject*);

AIMasterUpdates::AIMasterUpdates(const bool overkill,
    HooksProxy* hooker,
    MetricsProxy* metrics)
{
    g_metrics = metrics;

    hooker->RequestSharedHook<API::Functions::_ZN15CServerAIMaster11UpdateStateEv, void>(&AIMasterUpdate);

    Resamplers::ResamplerFuncPtr resampler = &Resamplers::template Mean<uint32_t>;
    metrics->SetResampler("AIQueuedEvents", resampler, std::chrono::seconds(1));
    metrics->SetResampler("AIUpdateListObjects", resampler, std::chrono::seconds(1));

    DEFINE_PROFILER_TARGET(hooker,
        AIMasterUpdateState, API::Functions::_ZN15CServerAIMaster11UpdateStateEv,
        void, CServerAIMaster*);

    if (overkill)
    {
        DEFINE_PROFILER_TARGET_FAST(hooker,
            EventPending, API::Functions::_ZN15CServerAIMaster12EventPendingEjj,
            int32_t, CServerAIMaster*, uint32_t, uint32_t);

        DEFINE_PROFILER_TARGET_FAST(hooker,
            GetNextObject, API::Functions::_ZN13CServerAIList13GetNextObjectEv,
            CNWSObject*, CServerAIList*);

        DEFINE_PROFILER_TARGET_FAST(hooker,
            GetPendingEvent, API::Functions::_ZN15CServerAIMaster15GetPendingEventEPjS0_S0_S0_S0_PPv,
            int32_t, CServerAIMaster*, uint32_t*, uint32_t*, uint32_t*, uint32_t*, uint32_t*, void**);

        DEFINE_PROFILER_TARGET_FAST(hooker,
            UpdateDialog, API::Functions::_ZN10CNWSObject12UpdateDialogEv,
            int32_t, CNWSObject*);
    }
}

void AIMasterUpdates::AIMasterUpdate(bool before, CServerAIMaster* thisPtr)
{
    if (!before)
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
