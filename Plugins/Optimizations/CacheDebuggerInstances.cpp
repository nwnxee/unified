#include "nwnx.hpp"

#include "API/CVirtualMachine.hpp"
#include "API/CScriptCompiler.hpp"

namespace Optimizations {

using namespace NWNXLib;
using namespace NWNXLib::API;

static std::unordered_map<std::string, std::shared_ptr<CVirtualMachineDebuggerInstance>> s_DebuggerInstances;

void CacheDebuggerInstances() __attribute__((constructor));
void CacheDebuggerInstances()
{
    if (Config::Get<bool>("CACHE_DEBUGGER_INSTANCES", false))
    {
        LOG_INFO("Caching debugger instances");

        static Hooks::Hook s_GetDebuggerInstanceHook = Hooks::HookFunction(&CVirtualMachine::GetDebuggerInstance,
        +[](CVirtualMachine *pVirtualMachine) -> std::shared_ptr<CVirtualMachineDebuggerInstance>
        {
            auto pScript = pVirtualMachine->m_pVirtualMachineScript[pVirtualMachine->m_nRecursionLevel];
            std::string key = pScript.m_sScriptChunk.IsEmpty() ? pScript.m_sScriptName.CStr() : pScript.m_sScriptChunk.CStr();

            if (key.empty())
                return s_GetDebuggerInstanceHook->CallOriginal<std::shared_ptr<CVirtualMachineDebuggerInstance>>(pVirtualMachine);

            auto debuggerInstance = s_DebuggerInstances.find(key);
            if (debuggerInstance != s_DebuggerInstances.end())
                return debuggerInstance->second;
            else
            {
                auto dbg = s_GetDebuggerInstanceHook->CallOriginal<std::shared_ptr<CVirtualMachineDebuggerInstance>>(pVirtualMachine);

                if (dbg)
                    s_DebuggerInstances[key] = dbg;

                return dbg;
            }
        }, Hooks::Order::Late);
    }
}

}
