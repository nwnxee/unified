#include "Diagnostics.hpp"
#include "Diagnostics/MemorySanitizer.hpp"
#include "Services/Config/Config.hpp"


using namespace NWNXLib;

static Diagnostics::Diagnostics* g_plugin;

NWNX_PLUGIN_ENTRY Plugin* PluginLoad(Services::ProxyServiceList* services)
{
    g_plugin = new Diagnostics::Diagnostics(services);
    return g_plugin;
}

namespace Diagnostics {

static bool preloaded = false;
void auto_constructor() __attribute__((constructor));
void auto_constructor() { preloaded = true; }

Diagnostics::Diagnostics(Services::ProxyServiceList* services)
        : Plugin(services)
{
    if (preloaded)
    {
        LOG_INFO("Memory sanitizer enabled");
        m_MemorySanitizer = std::make_unique<MemorySanitizer>(GetServices()->m_hooks.get());
    }
    else
    {
        LOG_WARNING("Diagnostics will not do anything unless preloaded. See the readme file");
    }
}

Diagnostics::~Diagnostics() { }

}
