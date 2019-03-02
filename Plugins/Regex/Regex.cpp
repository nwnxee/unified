#include "Regex.hpp"

#include "Services/Config/Config.hpp"
#include "ViewPtr.hpp"

#include <string>
#include <stdio.h>
#include <regex>

using namespace NWNXLib;
using namespace NWNXLib::Services;

static ViewPtr<Regex::Regex> g_plugin;

NWNX_PLUGIN_ENTRY Plugin::Info* PluginInfo()
{
    return new Plugin::Info
    {
        "Regex",
        "Regular expression functions",
        "orth",
        "plenarius@gmail.com",
        1,
        true
    };
}

NWNX_PLUGIN_ENTRY Plugin* PluginLoad(Plugin::CreateParams params)
{
    g_plugin = new Regex::Regex(params);
    return g_plugin;
}

namespace Regex {

Regex::Regex(const Plugin::CreateParams& params)
    : Plugin(params)
{
    m_backslashSubstring = GetServices()->m_config->Get<std::string>("BACKSLASH_SUBSTRING", "!!");

#define REGISTER(func) \
    GetServices()->m_events->RegisterEvent(#func, std::bind(&Regex::func, this, std::placeholders::_1))

    REGISTER(Search);
    REGISTER(Replace);

#undef REGISTER

}

Regex::~Regex()
{
}

std::regex Regex::ConvertToBackslash(std::string beforeRegex)
{
    // First replace all double exclamation marks in the string to backslashes
    std::regex backslashes(m_backslashSubstring);
    std::string clean_regex = std::regex_replace(beforeRegex, backslashes, "\\");

    std::regex afterRegex(clean_regex);

    return afterRegex;
}

ArgumentStack Regex::Search(ArgumentStack&& args)
{
    ArgumentStack stack;
    const auto str = Services::Events::ExtractArgument<std::string>(args);
    const auto regex = Services::Events::ExtractArgument<std::string>(args);

    const auto rgx = ConvertToBackslash(regex);
    const auto retVal = std::regex_search(str, rgx);

    Services::Events::InsertArgument(stack, retVal);
    return stack;
}

ArgumentStack Regex::Replace(ArgumentStack&& args)
{
    ArgumentStack stack;
    const auto str = Services::Events::ExtractArgument<std::string>(args);
    const auto regex = Services::Events::ExtractArgument<std::string>(args);
    const auto rpl = Services::Events::ExtractArgument<std::string>(args);
    const auto firstOnly = Services::Events::ExtractArgument<int32_t>(args);

    const auto rgx = ConvertToBackslash(regex);
    std::string retVal;
    if (firstOnly)
        retVal = std::regex_replace(str, rgx, rpl, std::regex_constants::format_first_only);
    else
        retVal = std::regex_replace(str, rgx, rpl);

    Services::Events::InsertArgument(stack, retVal);
    return stack;
}

}
