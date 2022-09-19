#include "Targets/Scripts.hpp"

#include "API/CAppManager.hpp"
#include "API/CExoString.hpp"
#include "API/CGameObject.hpp"
#include "API/CNWSArea.hpp"
#include "API/CNWSObject.hpp"
#include "API/CServerExoApp.hpp"
#include "API/CVirtualMachine.hpp"
#include "API/Constants.hpp"
#include "API/Functions.hpp"
#include "API/Globals.hpp"
#include "ProfilerMacros.hpp"

namespace Profiler {

using namespace NWNXLib;

static Services::MetricsProxy* g_metrics;
static bool g_areaTimings;
static bool g_typeTimings;

DECLARE_PROFILE_TARGET_FAST(*g_metrics, RunScript,
    (
        [](CVirtualMachine*, CExoString* script, uint32_t oid, bool, int32_t) -> Services::MetricData::Tags
        {
            using namespace NWNXLib::API;
            using namespace NWNXLib::API::Constants;
            using namespace NWNXLib::API::Globals;
            using namespace NWNXLib::Services;

            if (!script->m_sString || oid == OBJECT_INVALID)
            {
                return
                {
                    { "Script", "(unknown)" },
                    { "Area", "(unknown)" },
                    { "ObjectType", "(unknown)" }
                };
            }

            MetricData::Tags tags;
            tags.emplace_back("Script", script->m_sString);

            if (g_areaTimings || g_typeTimings)
            {
                CServerExoApp* server = AppManager()->m_pServerExoApp;
                CGameObject* obj = server->GetGameObject(oid);

                if (obj)
                {
                    const uint8_t objectType = obj->m_nObjectType;

                    if (g_areaTimings)
                    {
                        std::string areaName;

                        if (objectType >= ObjectType::Area)
                        {
                            CNWSArea* area = objectType == ObjectType::Area
                                ? static_cast<CNWSArea*>(obj)
                                : server->GetAreaByGameObjectID(static_cast<CNWSObject*>(obj)->m_oidArea);

                            if (area)
                            {
                                areaName = std::string(area->m_cResRef.GetResRef(), area->m_cResRef.GetLength());
                            }
                        }

                        tags.emplace_back("Area", areaName.empty() ? "(unknown)" : std::move(areaName));
                    }

                    if (g_typeTimings)
                    {
                        tags.emplace_back("ObjectType", ObjectType::ToString(objectType));
                    }
                }
            }

            return tags;
        }
    ),
    int32_t, CVirtualMachine*, CExoString*, uint32_t, int32_t, int32_t)

Scripts::Scripts(const bool areaTimings, const bool typeTimings,
    NWNXLib::Services::MetricsProxy* metrics)
{
    g_metrics = metrics;
    g_areaTimings = areaTimings;
    g_typeTimings = typeTimings;

    DEFINE_PROFILER_TARGET_FAST(
        RunScript, &CVirtualMachine::RunScript,
        int32_t, CVirtualMachine*, CExoString*, uint32_t, int32_t, int32_t);
}

}
