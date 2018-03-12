#include "Data.hpp"
#include "API/Version.hpp"
#include "Providers/Array.hpp"
#include "ViewPtr.hpp"

using namespace NWNXLib;

static ViewPtr<Data::Data> g_plugin;

NWNX_PLUGIN_ENTRY Plugin::Info* PluginInfo()
{
    return new Plugin::Info
    {
        "Data",
        "Provides a number of data structures for nwn code to use.",
        "Liareth",
        "liarethnwn@gmail.com",
        1,
        true
    };
}

NWNX_PLUGIN_ENTRY Plugin* PluginLoad(Plugin::CreateParams params)
{
    g_plugin = new Data::Data(params);
    return g_plugin;
}

namespace Data {

Data::Data(const Plugin::CreateParams& params)
    : Plugin(params)
{
    m_arrayProvider = std::make_unique<Array>(*GetServices()->m_events);
}

Data::~Data()
{
}

}
