#include "Targets/SpawnInHeartbeatPerception.hpp"
#include "API/CNWSArea.hpp"
#include "API/CNWSCreature.hpp"
#include "API/CNWSTile.hpp"
#include "API/Version.hpp"
#include "Services/Log/Log.hpp"
#include "Services/Metrics/Metrics.hpp"
#include "Services/Patching/Patching.hpp"

using namespace NWNXLib;
using namespace NWNXLib::API;

namespace Repair {

static ViewPtr<Services::MetricsProxy> g_metrics;
static ViewPtr<Services::LogProxy> g_log;

SpawnInHeartbeatPerception::SpawnInHeartbeatPerception(ViewPtr<Services::MetricsProxy> metrics,
    ViewPtr<Services::PatchingProxy> patcher,
    ViewPtr<Services::LogProxy> log)
{
    g_metrics = metrics;
    g_log = log;

    patcher->PatchWithCall(0x08119C55, 0x08119C5A - 0x08119C55, &SpawnInHeartbeatPerceptionInlineHook); NWNX_EXPECT_VERSION(8109);
}

bool SpawnInHeartbeatPerception::SpawnInHeartbeatPerceptionInlineHook(NWNXLib::API::CNWSCreature* thisPtr)
{
    CNWSArea* area = thisPtr->GetArea();

    if (area)
    {
        CNWSTile* tile = area->GetTile(thisPtr->m_vPosition);

        if (tile)
        {
            int tileX = 0;
            int tileY = 0;

            tile->GetLocation(&tileX, &tileY);

            if (thisPtr->m_nLastExploredTileX != tileX ||
                thisPtr->m_nLastExploredTileY != tileY ||
                thisPtr->oidLastExploredArea != area->m_idSelf)
            {
                thisPtr->UpdateAutoMap(thisPtr->m_idSelf);
                thisPtr->m_nLastExploredTileX = tileX;
                thisPtr->m_nLastExploredTileY = tileY;
                thisPtr->oidLastExploredArea = area->m_idSelf;
            }
        }
        else
        {
            g_log->Info("Prevented the SpawnInHeartbeatPerception crash.");
            g_metrics->Push("Crashes", { { "Count", "1" }, { "Type", "SpawnInHeartbeatPerception" } });
        }
    }

    return false;
}

}
