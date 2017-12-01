#include "Optimizations.hpp"
#include "API/Constants.hpp"
#include "API/Functions.hpp"
#include "Optimizations/AIMasterOptimizations.hpp"
#include "Optimizations/BroadcastCombatStateToPartyOptimization.hpp"
#include "Optimizations/CGameObjectArrayOptimization.hpp"
#include "Optimizations/GetClientObjectByObjectIdOptimization.hpp"
#include "Optimizations/GetHRTOptimization.hpp"
#include "Optimizations/MainLoopSleepOptimization.hpp"
#include "Optimizations/SortObjectsForGameObjectUpdateOptimization.hpp"
#include "Services/Config/Config.hpp"
#include "Services/Metrics/Metrics.hpp"
#include "Services/Patching/Patching.hpp"
#include "ViewPtr.hpp"
#include <cassert>

using namespace NWNXLib;

static ViewPtr<Optimizations::Optimizations> g_plugin;

NWNX_PLUGIN_ENTRY Plugin::Info* PluginInfo()
{
    return new Plugin::Info
    {
        "Optimizations",
        "Offers a series of useful performance optimizations.",
        "Liareth",
        "liarethnwn@gmail.com",
        1,
        false
    };
}

NWNX_PLUGIN_ENTRY Plugin* PluginLoad(Plugin::CreateParams params)
{
    g_plugin = new Optimizations::Optimizations(params);
    return g_plugin;
}

namespace Optimizations {

using namespace NWNXLib::Services;

Optimizations::Optimizations(const Plugin::CreateParams& params)
    : Plugin(params)
{
    if (GetServices()->m_config->Get<bool>("ENABLE_AI_MASTER_OPTIMIZATIONS", true))
    {
        m_aiMasterOptimizations = std::make_unique<AIMasterOptimizations>(GetServices()->m_hooks, GetServices()->m_patching);
    }

    if (GetServices()->m_config->Get<bool>("ENABLE_BROADCAST_COMBAT_STATE_OPTIMIZATION", true))
    {
        m_broadcastCombatStateToPartyOptimization = std::make_unique<BroadcastCombatStateToPartyOptimization>(GetServices()->m_patching);
    }

    if (GetServices()->m_config->Get<bool>("ENABLE_OBJCACHE_OPTIMIZATION", true))
    {
        const uint32_t objcacheSize = GetServices()->m_config->Get<uint32_t>("OBJCACHE_SIZE", 64000);
        m_cgameObjectArrayOptimization = std::make_unique<CGameObjectArrayOptimization>(objcacheSize, GetServices()->m_hooks);

        if (GetServices()->m_config->Get<bool>("OBJCACHE_METRICS", false))
        {
            GetServices()->m_hooks->RequestSharedHook<API::Functions::CServerExoAppInternal__MainLoop, int32_t>(&MainLoopUpdate);
        }
    }

    if (GetServices()->m_config->Get<bool>("ENABLE_GET_CLIENT_OBJECT_OPTIMIZATION", true))
    {
        m_getClientObjectByObjectIdOptimization = std::make_unique<GetClientObjectByObjectIdOptimization>(GetServices()->m_hooks);
    }

    if (GetServices()->m_config->Get<bool>("ENABLE_HAS_FEAT_OPTIMIZATION", true))
    {
        // We remove the object lookup for expansion pack check here by replacing the call with a jump to the failure case.
        // This is a signficant performance win (25%->35% server perf under heavy load with all other optimizations applies).
        using namespace NWNXLib::Platform::Assembly;
        GetServices()->m_patching->PatchWithInstructions(0x08153BE9,
            AddRegImmByteInstruction(Register::ESP, 16),
            JmpRelInstruction(0x8153C2C)
        ); NWNX_EXPECT_VERSION(8109);
    }

    if (GetServices()->m_config->Get<bool>("ENABLE_HRT_OPTIMIZATION", true))
    {
        const uint32_t flushCount = GetServices()->m_config->Get<uint32_t>("HRT_FLUSH_COUNT", 8);
        m_getHRTOptimization = std::make_unique<GetHRTOptimization>(flushCount, GetServices()->m_hooks, GetServices()->m_patching);
    }

    if (GetServices()->m_config->Get<bool>("ENABLE_SLEEP_OPTIMIZATION", true))
    {
        MainLoopSleepOptimization::Configuration config =
        {
            static_cast<uint8_t>(GetServices()->m_config->Get<uint32_t>("SLEEP_THRESHOLD", 1)),
            static_cast<uint8_t>(GetServices()->m_config->Get<uint32_t>("SLEEP_LOW_RATE", 5)),
            static_cast<uint8_t>(GetServices()->m_config->Get<uint32_t>("SLEEP_HIGH_RATE", 0)),
            static_cast<MainLoopSleepOptimization::OptimizationType>(GetServices()->m_config->Get<uint32_t>("SLEEP_TYPE", 0))
        };

        m_mainLoopSleepOptimization = std::make_unique<MainLoopSleepOptimization>(std::move(config), GetServices()->m_patching);
    }

    if (GetServices()->m_config->Get<bool>("ENABLE_SORT_LAST_UPDATE_OBJECT_OPTIMIZATION", true))
    {
        const uint32_t flushCount = GetServices()->m_config->Get<uint32_t>("SORT_LAST_UPDATE_FLUSH_COUNT", 8);
        m_sortObjectsForGameObjectUpdateOptimization = std::make_unique<SortObjectsForGameObjectUpdateOptimization>(flushCount, GetServices()->m_patching);
    }
}

Optimizations::~Optimizations()
{
}

void Optimizations::MainLoopUpdate(Hooks::CallType type, API::CServerExoAppInternal*)
{
    if (type != Hooks::CallType::BEFORE_ORIGINAL)
    {
        return;
    }

    using namespace std::chrono;
    static time_point<high_resolution_clock> s_lastUpdate;
    auto now = high_resolution_clock::now();

    if (duration_cast<seconds>(now - s_lastUpdate) >= seconds(15))
    {
        s_lastUpdate = std::move(now);

        const CGameObjectReport report = g_plugin->m_cgameObjectArrayOptimization->GetObjectReport();

        for (uint32_t i = 1; i <= 16; ++i)
        {
            g_plugin->GetServices()->m_metrics->Push("ObjCache",
                { { "Count", std::to_string(report.m_objCounts[i]) } },
                { { "Type", API::Constants::ObjectTypeToString(i) } });
        }
    }
}

}
