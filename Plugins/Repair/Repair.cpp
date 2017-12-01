#include "Repair.hpp"
#include "API/Version.hpp"
#include "Services/Config/Config.hpp"
#include "Targets/DDoS.hpp"
#include "Targets/ResolveSpecialAttackDamageBonus.hpp"
#include "Targets/SpawnInHeartbeatPerception.hpp"
#include "ViewPtr.hpp"

using namespace NWNXLib;

static ViewPtr<Repair::Repair> g_plugin;

NWNX_PLUGIN_ENTRY Plugin::Info* PluginInfo()
{
    return new Plugin::Info
    {
        "Repair",
        "Patches various exploits and crashes in the game.",
        "Liareth",
        "liarethnwn@gmail.com",
        1,
        true
    };
}

NWNX_PLUGIN_ENTRY Plugin* PluginLoad(Plugin::CreateParams params)
{
    g_plugin = new Repair::Repair(params);
    return g_plugin;
}

namespace Repair {

Repair::Repair(const Plugin::CreateParams& params)
    : Plugin(params)
{
    using namespace NWNXLib::Services;

    if (GetServices()->m_config->Get<bool>("ENABLE_DDOS_TARGET", true))
    {
        m_ddosTarget = std::make_unique<DDoS>(
            GetServices()->m_config->Get<bool>("ENABLE_DDOS_TARGET_NET_METRICS", true),
            GetServices()->m_config->Get<bool>("ENABLE_DDOS_TARGET_DDOS_METRICS", true),
            GetServices()->m_metrics,
            GetServices()->m_patching,
            GetServices()->m_tasks,
            GetServices()->m_log);
    }

    if (GetServices()->m_config->Get<bool>("ENABLE_RESOLVE_SPECIAL_ATTACK_DAMAGE_BONUS_TARGET", true))
    {
        m_resolveSpecialAttackDamageBonusTarget = std::make_unique<ResolveSpecialAttackDamageBonus>(
            GetServices()->m_metrics,
            GetServices()->m_patching,
            GetServices()->m_log);
    }



    if (GetServices()->m_config->Get<bool>("ENABLE_SPAWN_IN_HEARTBEAT_PERCEPTION_TARGET", true))
    {
        m_spawnInHeartbeatPerceptionTarget = std::make_unique<SpawnInHeartbeatPerception>(
            GetServices()->m_metrics,
            GetServices()->m_patching,
            GetServices()->m_log);
    }
}

Repair::~Repair()
{
}

}
