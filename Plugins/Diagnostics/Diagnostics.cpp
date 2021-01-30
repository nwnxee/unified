#include "Diagnostics.hpp"
#include "Diagnostics/MemorySanitizer.hpp"


using namespace NWNXLib;

static Diagnostics::Diagnostics* g_plugin;

NWNX_PLUGIN_ENTRY Plugin* PluginLoad(Services::ProxyServiceList* services)
{
    g_plugin = new Diagnostics::Diagnostics(services);
    return g_plugin;
}

namespace Diagnostics {

Diagnostics::Diagnostics(Services::ProxyServiceList* services)
        : Plugin(services)
{
    if (Config::Get<bool>("MEMORY_SANITIZER", false))
    {
        LOG_INFO("Memory sanitizer enabled");
        m_MemorySanitizer = std::make_unique<MemorySanitizer>();
    }
}

Diagnostics::~Diagnostics() { }

}
