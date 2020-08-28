#include "Tracking.hpp"
#include "Services/Config/Config.hpp"
#include "Targets/Activity.hpp"

using namespace NWNXLib;

static Tracking::Tracking* g_plugin;

NWNX_PLUGIN_ENTRY Plugin* PluginLoad(Services::ProxyServiceList* services)
{
    g_plugin = new Tracking::Tracking(services);
    return g_plugin;
}

namespace Tracking {

Tracking::Tracking(Services::ProxyServiceList* services)
    : Plugin(services)
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
