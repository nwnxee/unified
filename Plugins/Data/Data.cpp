#include "Data.hpp"
#include "Providers/Array.hpp"

using namespace NWNXLib;

static Data::Data* g_plugin;

NWNX_PLUGIN_ENTRY Plugin* PluginLoad(Services::ProxyServiceList* services)
{
    g_plugin = new Data::Data(services);
    return g_plugin;
}

namespace Data {

Data::Data(Services::ProxyServiceList* services)
    : Plugin(services)
{
    LOG_WARNING("Data plugin is deprecated.  Please migrate to inc_array");
    m_arrayProvider = std::make_unique<Array>();
}

Data::~Data()
{
}

}
