#include "Tracking.hpp"
#include "API/Version.hpp"
#include "Services/Config/Config.hpp"
#include "Targets/Activity.hpp"

using namespace NWNXLib;

static Tracking::Tracking* g_plugin;

NWNX_PLUGIN_ENTRY Plugin::Info* PluginInfo()
{
    return new Plugin::Info
    {
        "Tracking",
        "Exposes a number of metrics regarding tracking events in the game.",
        "Liareth",
        "liarethnwn@gmail.com",
        1,
        true
    };
}

NWNX_PLUGIN_ENTRY Plugin* PluginLoad(Plugin::CreateParams params)
{
    g_plugin = new Tracking::Tracking(params);
    return g_plugin;
}

namespace Tracking {

Tracking::Tracking(const Plugin::CreateParams& params)
    : Plugin(params)
{
    if (GetServices()->m_config->Get<bool>("ENABLE_ACTIVITY_TARGET", true))
    {
        m_activityTarget = std::make_unique<Activity>(GetServices()->m_metrics.get(), GetServices()->m_hooks.get());
    }
}

Tracking::~Tracking()
{
}

}
