#include "Experimental.hpp"
#include "Experimentals/SuppressPlayerLoginInfo.hpp"
#include "Experimentals/AdjustReputationFix.hpp"
#include "Experimentals/DisableLevelUpValidation.hpp"
#include "Experimentals/UnhardcodeRangerDualWield.hpp"



using namespace NWNXLib;

static Experimental::Experimental* g_plugin;

NWNX_PLUGIN_ENTRY Plugin* PluginLoad(Services::ProxyServiceList* services)
{
    g_plugin = new Experimental::Experimental(services);
    return g_plugin;
}

namespace Experimental {

Experimental::Experimental(Services::ProxyServiceList* services)
        : Plugin(services)
{
    if (Config::Get<bool>("SUPPRESS_PLAYER_LOGIN_INFO", false))
    {
        LOG_INFO("EXPERIMENTAL: Suppressing playerlist and player login/logout messages for non DMs.");
        m_SuppressPlayerLoginInfo = std::make_unique<SuppressPlayerLoginInfo>();
    }

    if (Config::Get<bool>("ADJUST_REPUTATION_FIX", false))
    {
        LOG_INFO("EXPERIMENTAL: Attempting to resolve faction/reputation crash.");
        m_AdjustReputationFix = std::make_unique<AdjustReputationFix>();
    }

    if (Config::Get<bool>("DISABLE_LEVELUP_VALIDATION", false))
    {
        LOG_INFO("EXPERIMENTAL: Disabling LevelUp Validation.");
        m_DisableLevelUpValidation = std::make_unique<DisableLevelUpValidation>();
    }

    if (Config::Get<bool>("UNHARDCODE_RANGER_DUALWIELD", false))
    {
        LOG_INFO("EXPERIMENTAL: Unhardcoding Ranger DualWield Feat.");
        m_UnhardcodeRangerDualWield = std::make_unique<UnhardcodeRangerDualWield>();
    }
}

Experimental::~Experimental()
{
}

}
