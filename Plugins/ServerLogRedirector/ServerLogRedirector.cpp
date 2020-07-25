#include "ServerLogRedirector.hpp"
#include "API/CExoString.hpp"
#include "Services/Config/Config.hpp"
#include "Services/Hooks/Hooks.hpp"

using namespace NWNXLib;

static ServerLogRedirector::ServerLogRedirector* g_plugin;

NWNX_PLUGIN_ENTRY Plugin* PluginLoad(Services::ProxyServiceList* services)
{
    g_plugin = new ServerLogRedirector::ServerLogRedirector(services);
    return g_plugin;
}

namespace ServerLogRedirector {

using namespace NWNXLib;
using namespace NWNXLib::API;
using namespace NWNXLib::Services;

static bool s_printString;
static bool s_hideValidateGFFResourceMessage;

ServerLogRedirector::ServerLogRedirector(Services::ProxyServiceList* services)
    : Plugin(services)
{
    // Hook logging so it always emits to stdout/stderr.
    GetServices()->m_hooks->RequestSharedHook<Functions::_ZN17CExoDebugInternal14WriteToLogFileERK10CExoString,
        void, CExoDebugInternal*, CExoString*>(&WriteToLogFileHook);

    GetServices()->m_hooks->RequestSharedHook<Functions::_ZN17CExoDebugInternal16WriteToErrorFileERK10CExoString,
        void, CExoDebugInternal*, CExoString*>(&WriteToErrorFileHook);

    GetServices()->m_hooks->RequestSharedHook<Functions::_ZN25CNWVirtualMachineCommands25ExecuteCommandPrintStringEii,
        int32_t>(+[](bool before, CNWVirtualMachineCommands*, int32_t, int32_t){ s_printString = before; });

    s_hideValidateGFFResourceMessage = GetServices()->m_config->Get<bool>("HIDE_VALIDATEGFFRESOURCE_MESSAGES", false);
}

ServerLogRedirector::~ServerLogRedirector()
{
}

inline std::string TrimMessage(CExoString* message)
{
    std::string s = std::string(message->CStr());

    if (!s_printString)
    {
        // Eat the auto-added timestamp.
        auto idxOfBracket = s.find_first_of(']');
        if (idxOfBracket != std::string::npos)
            s.erase(0, idxOfBracket + 1);
    }

    return Utils::trim(s);
}

void ServerLogRedirector::WriteToLogFileHook(bool before, CExoDebugInternal*, CExoString* message)
{
    if (before)
    {
        std::string str = TrimMessage(message);

        if (s_hideValidateGFFResourceMessage)
        {
            if(str.find("*** ValidateGFFResource sent by user.") == std::string::npos)
            {
                LOG_INFO("(Server) %s", str);
            }
        }
        else
        {
            LOG_INFO("(Server) %s", str);
        }
    }
}

void ServerLogRedirector::WriteToErrorFileHook(bool before, CExoDebugInternal*, CExoString* message)
{
    if (before)
    {
        std::string str = TrimMessage(message);
        LOG_INFO("(Error) %s", str);
    }
}

}
