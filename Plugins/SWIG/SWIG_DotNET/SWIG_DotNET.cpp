#include "SWIG_DotNET.hpp"

using namespace NWNXLib;
using namespace NWNXLib::API;

static SWIG_DotNET::SWIG_DotNET* g_plugin;

NWNX_PLUGIN_ENTRY Plugin* PluginLoad(Services::ProxyServiceList* services)
{
    g_plugin = new SWIG_DotNET::SWIG_DotNET(services);
    return g_plugin;
}


namespace SWIG_DotNET
{

SWIG_DotNET::SWIG_DotNET(Services::ProxyServiceList* services)
  : Plugin(services) {}

}
