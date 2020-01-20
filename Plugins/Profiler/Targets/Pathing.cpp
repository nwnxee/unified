#include "Targets/Pathing.hpp"

#include "API/CAppManager.hpp"
#include "API/CNWSArea.hpp"
#include "API/CNWSCreature.hpp"
#include "API/CPathfindInformation.hpp"
#include "API/CServerExoApp.hpp"
#include "API/Constants.hpp"
#include "API/Functions.hpp"
#include "API/Globals.hpp"
#include "ProfilerMacros.hpp"
#include "Services/Metrics/Metrics.hpp"
#include "Services/Hooks/Hooks.hpp"

namespace Profiler {

using namespace NWNXLib;

static Services::MetricsProxy* g_metrics;

DECLARE_PROFILE_TARGET_FAST(*g_metrics, PlotPath,
    (
        [](CNWSModule*, CPathfindInformation* pfi, uint32_t) -> Services::MetricData::Tags
        {
            using namespace NWNXLib::API;
            using namespace NWNXLib::API::Constants;
            using namespace NWNXLib::API::Globals;
            using namespace NWNXLib::Services;

            MetricData::Tags tags;
            CServerExoApp* server = AppManager()->m_pServerExoApp;
            CNWSCreature* creature = server->GetCreatureByGameObjectID(pfi->m_oidSelf);

            if (creature)
            {
                CExoString& resRef = creature->m_sTemplate;
                tags.emplace_back("ResRef", resRef.m_sString ? resRef.m_sString : "(unknown)");
                CNWSArea* area = server->GetAreaByGameObjectID(creature->m_oidArea);

                if (area)
                {
                    std::string areaName = std::string(area->m_cResRef.GetResRef(), 16);
                    tags.emplace_back("Area", areaName.empty() ? "(unknown)" : std::move(areaName));
                }
            }

            return tags;
        }
    ),
    int32_t, CNWSModule*, CPathfindInformation*, uint32_t);

Pathing::Pathing(NWNXLib::Services::HooksProxy* hooker,
    NWNXLib::Services::MetricsProxy* metrics)
{
    g_metrics = metrics;

    DEFINE_PROFILER_TARGET_FAST(hooker,
        PlotPath, API::Functions::_ZN10CNWSModule8PlotPathEP20CPathfindInformationj,
        int32_t, CNWSModule*, CPathfindInformation*, uint32_t);
}

}
