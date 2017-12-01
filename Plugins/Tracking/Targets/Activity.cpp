#include "Targets/Activity.hpp"
#include "API/CExoLinkedListNode.hpp"
#include "API/CExoLinkedListInternal.hpp"
#include "API/CExoLinkedListTemplatedCNWSClient.hpp"
#include "API/CNWSArea.hpp"
#include "API/CNWSObject.hpp"
#include "API/CNWSPlayer.hpp"
#include "API/Constants.hpp"
#include "API/CServerExoAppInternal.hpp"
#include "API/Functions.hpp"
#include "API/Version.hpp"
#include "Services/Metrics/Metrics.hpp"
#include "Services/Metrics/Resamplers.hpp"

using namespace NWNXLib;
using namespace NWNXLib::API;

namespace Tracking {

static ViewPtr<Services::MetricsProxy> g_metrics;

Activity::Activity(ViewPtr<Services::MetricsProxy> metrics, ViewPtr<Services::HooksProxy> hooks)
{
    g_metrics = metrics;
    hooks->RequestSharedHook<Functions::CServerExoAppInternal__MainLoop, int32_t>(&MainLoopUpdate);
    Services::Resamplers::ResamplerFuncPtr resampler = &Services::Resamplers::template Sum<uint32_t>;
    metrics->SetResampler("Activity", resampler, std::chrono::seconds(1));
}

void Activity::MainLoopUpdate(Services::Hooks::CallType type, CServerExoAppInternal* thisPtr)
{
    if (type != Services::Hooks::CallType::BEFORE_ORIGINAL)
    {
        return;
    }

    using namespace std::chrono;
    static time_point<high_resolution_clock> s_lastUpdate;
    auto now = high_resolution_clock::now();

    if (duration_cast<seconds>(now - s_lastUpdate) >= seconds(1))
    {
        s_lastUpdate = std::move(now);

        CExoLinkedListNode* head = thisPtr->m_pNWSPlayerList->m_pcExoLinkedListInternal->pHead;

        while (head)
        {
            CNWSPlayer* player = static_cast<CNWSPlayer*>(head->pObject);

            std::string areaName;
            CGameObject* obj = thisPtr->GetGameObject(player->m_oidNWSObject);

            if (obj)
            {
                CNWSArea* area = thisPtr->GetAreaByGameObjectID(static_cast<CNWSObject*>(obj)->m_oidArea);

                if (area)
                {
                    areaName = std::string(area->m_cResRef.m_resRef, area->m_cResRef.GetLength());
                }
            }

            const bool isDm = false; //TODO: reinterpret_cast<uintptr_t>(player->m_vtable[3]) == Functions::CNWSDungeonMaster__AsNWSDungeonMaster; NWNX_EXPECT_VERSION(8109);

            g_metrics->Push(
                "Activity",
                {
                    { "Count", "1" }
                },
                {
                    { "Area", areaName.empty() ? "(unknown)" : std::move(areaName) },
                    { "Type", isDm ? "DM" : "Player" }
                });

            head = head->pNext;
        }
    }
}

}
