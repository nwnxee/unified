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
static Hooking::FunctionHook *s_WriteToLogFileHook;
static Hooking::FunctionHook *s_WriteToErrorFileHook;
static Hooking::FunctionHook *s_ExecuteCommandPrintStringHook;

ServerLogRedirector::ServerLogRedirector(Services::ProxyServiceList* services)
    : Plugin(services)
{
    // Hook logging so it always emits to stdout/stderr.
    s_WriteToLogFileHook = GetServices()->m_hooks->Hook(Functions::_ZN17CExoDebugInternal14WriteToLogFileERK10CExoString,
                                                        (void*)&WriteToLogFileHook, Hooking::Order::VeryEarly);

    s_WriteToErrorFileHook = GetServices()->m_hooks->Hook(Functions::_ZN17CExoDebugInternal16WriteToErrorFileERK10CExoString,
                                                          (void*)&WriteToErrorFileHook, Hooking::Order::VeryEarly);

    s_ExecuteCommandPrintStringHook = GetServices()->m_hooks->Hook(Functions::_ZN25CNWVirtualMachineCommands25ExecuteCommandPrintStringEii,
        (void*)+[](CNWVirtualMachineCommands *pVirtualMachineCommands, int32_t nCommandId, int32_t nParameters) -> int32_t
        {
            s_printString = true;
            auto retVal = s_ExecuteCommandPrintStringHook->CallOriginal<int32_t>(pVirtualMachineCommands, nCommandId, nParameters);
            s_printString = false;
            return retVal;
        }, Hooking::Order::VeryEarly);

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

void ServerLogRedirector::WriteToLogFileHook(CExoDebugInternal *pExoDebugInternal, CExoString* message)
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

    s_WriteToLogFileHook->CallOriginal<void>(pExoDebugInternal, message);
}

void ServerLogRedirector::WriteToErrorFileHook(CExoDebugInternal *pExoDebugInternal, CExoString* message)
{
    std::string str = TrimMessage(message);
    LOG_INFO("(Error) %s", str);

    s_WriteToErrorFileHook->CallOriginal<void>(pExoDebugInternal, message);
}

}
