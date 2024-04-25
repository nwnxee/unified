#include "nwnx.hpp"

#include "API/CExoDebugInternal.hpp"
#include "API/CNWSVirtualMachineCommands.hpp"

using namespace NWNXLib;
using namespace NWNXLib::API;

static bool s_printString;

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
        LOG_INFO("(Server) %s", TrimMessage(message));
        s_WriteToLogFileHook->CallOriginal<void>(pExoDebugInternal, message);
    }, Hooks::Order::VeryEarly);

static Hooks::Hook s_ExecuteCommandPrintStringHook = Hooks::HookFunction((void*)&CNWSVirtualMachineCommands::ExecuteCommandPrintString,
    +[](CNWSVirtualMachineCommands *pVirtualMachineCommands, int32_t nCommandId, int32_t nParameters) -> int32_t
    {
        s_printString = true;
        auto retVal = s_ExecuteCommandPrintStringHook->CallOriginal<int32_t>(pVirtualMachineCommands, nCommandId, nParameters);
        s_printString = false;
        return retVal;
    }, Hooks::Order::VeryEarly);
