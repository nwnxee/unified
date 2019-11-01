#include "ServerLogRedirector.hpp"
#include "API/Version.hpp"
#include "API/Functions.hpp"
#include "API/CExoString.hpp"
#include "Services/Config/Config.hpp"
#include "Services/Hooks/Hooks.hpp"
#include "ViewPtr.hpp"

using namespace NWNXLib;

static ViewPtr<ServerLogRedirector::ServerLogRedirector> g_plugin;

NWNX_PLUGIN_ENTRY Plugin::Info* PluginInfo()
{
    return new Plugin::Info
    {
        "ServerLogRedirector",
        "Redirects server log output to the NWNX logger.",
        "niv",
        "niv@nwnx.io",
        1,
        true
    };
}

NWNX_PLUGIN_ENTRY Plugin* PluginLoad(Plugin::CreateParams params)
{
    g_plugin = new ServerLogRedirector::ServerLogRedirector(params);
    return g_plugin;
}

namespace ServerLogRedirector {

using namespace NWNXLib;
using namespace NWNXLib::API;
using namespace NWNXLib::Services;

ServerLogRedirector::ServerLogRedirector(const Plugin::CreateParams& params)
    : Plugin(params)
{
    // Hook logging so it always emits to stdout/stderr.
    GetServices()->m_hooks->RequestSharedHook<Functions::CExoDebugInternal__WriteToLogFile,
        void, CExoDebugInternal*, CExoString*>(&WriteToLogFileHook);

    GetServices()->m_hooks->RequestSharedHook<Functions::CExoDebugInternal__WriteToErrorFile,
        void, CExoDebugInternal*, CExoString*>(&WriteToErrorFileHook);
}

ServerLogRedirector::~ServerLogRedirector()
{
}

inline std::string TrimMessage(CExoString* message)
{
    std::string s = std::string(message->CStr());

    // Eat the auto-added timestamp.
    auto idxOfBracket = s.find_first_of(']');
    if (idxOfBracket != std::string::npos)
        s.erase(0, idxOfBracket + 1);

    return Utils::trim(s);
}

void ServerLogRedirector::WriteToLogFileHook(Hooks::CallType type,
    CExoDebugInternal*, CExoString* message)
{
    if (type == Services::Hooks::CallType::BEFORE_ORIGINAL)
    {
        std::string str = TrimMessage(message);
        LOG_INFO("(Server) %s", str);
    }
}

void ServerLogRedirector::WriteToErrorFileHook(Hooks::CallType type,
    CExoDebugInternal*, CExoString* message)
{
    if (type == Services::Hooks::CallType::BEFORE_ORIGINAL)
    {
        std::string str = TrimMessage(message);
        LOG_INFO("(Error) %s", str);
    }
}

}
