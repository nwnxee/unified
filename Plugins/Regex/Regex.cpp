#include "Regex.hpp"


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
    Events::RegisterEvent(PLUGIN_NAME, #func, \
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
    const auto str = Events::ExtractArgument<std::string>(args);
    const auto regex = Events::ExtractArgument<std::string>(args);

    std::regex rgx(regex);
    const auto retVal = std::regex_search(str, rgx);

    return Events::Arguments(retVal);
}

ArgumentStack Regex::Replace(ArgumentStack&& args)
{
    const auto str = Events::ExtractArgument<std::string>(args);
    const auto regex = Events::ExtractArgument<std::string>(args);
    const auto rpl = Events::ExtractArgument<std::string>(args);
    const auto firstOnly = Events::ExtractArgument<int32_t>(args);

    std::regex rgx(regex);
    std::string retVal;
    if (firstOnly)
        retVal = std::regex_replace(str, rgx, rpl, std::regex_constants::format_first_only);
    else
        retVal = std::regex_replace(str, rgx, rpl);

    return Events::Arguments(retVal);
}

}
