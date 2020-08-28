#include "Targets/Activity.hpp"
#include "API/CExoLinkedListNode.hpp"
#include "API/CExoLinkedListInternal.hpp"
#include "API/CExoLinkedList.hpp"
#include "API/CNWSArea.hpp"
#include "API/CNWSObject.hpp"
#include "API/CNWSPlayer.hpp"
#include "API/CNWSCreature.hpp"
#include "API/CNWSCreatureStats.hpp"
#include "API/Constants.hpp"
#include "API/CServerExoAppInternal.hpp"
#include "API/Functions.hpp"
#include "Services/Metrics/Metrics.hpp"
#include "Services/Metrics/Resamplers.hpp"

using namespace NWNXLib;
using namespace NWNXLib::API;

namespace Tracking {

static Services::MetricsProxy* g_metrics;

Activity::Activity(Services::MetricsProxy* metrics, Services::HooksProxy* hooks)
{
    g_metrics = metrics;
    hooks->RequestSharedHook<Functions::_ZN21CServerExoAppInternal8MainLoopEv, int32_t>(&MainLoopUpdate);
    Services::Resamplers::ResamplerFuncPtr resampler = &Services::Resamplers::template Sum<uint32_t>;
    metrics->SetResampler("Activity", resampler, std::chrono::seconds(1));
}

void Activity::MainLoopUpdate(bool before, CServerExoAppInternal* thisPtr)
{
    if (!before)
    {
        return;
    }

    using namespace std::chrono;
    static time_point<high_resolution_clock> s_lastUpdate;
    auto now = high_resolution_clock::now();

    if (duration_cast<seconds>(now - s_lastUpdate) >= seconds(1))
    {
        s_lastUpdate = std::move(now);

        for (auto oidPC = thisPtr->GetFirstPCObject();
             oidPC != Constants::OBJECT_INVALID;
             oidPC = thisPtr->GetNextPCObject())
        {
            CNWSPlayer *player = thisPtr->GetClientObjectByObjectId(oidPC);
            CNWSCreature *creature = thisPtr->GetCreatureByGameObjectID(player ? player->m_oidNWSObject : oidPC);

            std::string areaName;
            std::string clientType;
            if (creature)
            {
                CNWSArea* area = thisPtr->GetAreaByGameObjectID(creature->m_oidArea);

                if (area)
                {
                    areaName = std::string(area->m_cResRef.GetResRef(), area->m_cResRef.GetLength());
                }

                if (creature->m_pStats->m_bIsDMCharacterFile || creature->m_nAssociateType == 7 || creature->m_nAssociateType == 8)
                {
                    clientType = "DM";
                }
                else
                {
                    clientType = "Player";
                }
            }

            g_metrics->Push(
                "Activity",
                {
                    { "Count", "1" }
                },
                {
                    { "Area", areaName.empty() ? "(unknown)" : std::move(areaName) },
                    { "Type", clientType.empty() ? "(unknown)" : std::move(clientType) }
                });
        }
    }
}

}
