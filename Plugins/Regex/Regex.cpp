#include "Regex.hpp"

#include "Services/Config/Config.hpp"

#include <string>
#include <stdio.h>
#include <regex>

using namespace NWNXLib;
using namespace NWNXLib::Services;

static Regex::Regex* g_plugin;

NWNX_PLUGIN_ENTRY Plugin* PluginLoad(Services::ProxyServiceList* services)
{
    g_plugin = new Regex::Regex(services);
    return g_plugin;
}

namespace Regex {

Regex::Regex(Services::ProxyServiceList* services)
    : Plugin(services)
{

#define REGISTER(func) \
    GetServices()->m_events->RegisterEvent(#func, \
        [this](ArgumentStack&& args){ return func(std::move(args)); })

    REGISTER(Search);
    REGISTER(Replace);

#undef REGISTER

}

Regex::~Regex()
{
}

ArgumentStack Regex::Search(ArgumentStack&& args)
{
    const auto str = Services::Events::ExtractArgument<std::string>(args);
    const auto regex = Services::Events::ExtractArgument<std::string>(args);

    std::regex rgx(regex);
    const auto retVal = std::regex_search(str, rgx);

    return Services::Events::Arguments(retVal);
}

ArgumentStack Regex::Replace(ArgumentStack&& args)
{
    const auto str = Services::Events::ExtractArgument<std::string>(args);
    const auto regex = Services::Events::ExtractArgument<std::string>(args);
    const auto rpl = Services::Events::ExtractArgument<std::string>(args);
    const auto firstOnly = Services::Events::ExtractArgument<int32_t>(args);

    std::regex rgx(regex);
    std::string retVal;
    if (firstOnly)
        retVal = std::regex_replace(str, rgx, rpl, std::regex_constants::format_first_only);
    else
        retVal = std::regex_replace(str, rgx, rpl);

    return Services::Events::Arguments(retVal);
}

}
