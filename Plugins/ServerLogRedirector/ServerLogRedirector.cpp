#include "nwnx.hpp"

#include "API/CExoDebugInternal.hpp"
#include "API/CNWVirtualMachineCommands.hpp"

using namespace NWNXLib;
using namespace NWNXLib::API;

static bool s_printString;
static bool s_hideValidateGFFResourceMessage = Config::Get<bool>("HIDE_VALIDATEGFFRESOURCE_MESSAGES", false);

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

    return String::Trim(s);
}

static Hooks::Hook s_WriteToLogFileHook = Hooks::HookFunction((void*)&CExoDebugInternal::WriteToLogFile,
    +[](CExoDebugInternal *pExoDebugInternal, CExoString* message) -> void
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
    }, Hooks::Order::VeryEarly);

static Hooks::Hook s_WriteToErrorFileHook = Hooks::HookFunction((void*)&CExoDebugInternal::WriteToErrorFile,
    +[](CExoDebugInternal *pExoDebugInternal, CExoString* message) -> void
    {
        std::string str = TrimMessage(message);
        LOG_INFO("(Error) %s", str);

        s_WriteToErrorFileHook->CallOriginal<void>(pExoDebugInternal, message);
    }, Hooks::Order::VeryEarly);

static Hooks::Hook s_ExecuteCommandPrintStringHook = Hooks::HookFunction((void*)&CNWVirtualMachineCommands::ExecuteCommandPrintString,
    +[](CNWVirtualMachineCommands *pVirtualMachineCommands, int32_t nCommandId, int32_t nParameters) -> int32_t
    {
        s_printString = true;
        auto retVal = s_ExecuteCommandPrintStringHook->CallOriginal<int32_t>(pVirtualMachineCommands, nCommandId, nParameters);
        s_printString = false;
        return retVal;
    }, Hooks::Order::VeryEarly);
