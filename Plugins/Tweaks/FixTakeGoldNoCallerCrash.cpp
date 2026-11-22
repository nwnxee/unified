#include "nwnx.hpp"

#include "API/CNWSVirtualMachineCommands.hpp"
#include "API/CVirtualMachine.hpp"


namespace Tweaks {

using namespace NWNXLib;
using namespace NWNXLib::API;
using namespace NWNXLib::API::Constants;


void FixTakeGoldNoCallerCrash() __attribute__((constructor));
void FixTakeGoldNoCallerCrash()
{
    if (!Config::Get<bool>("FIX_TAKE_GOLD_NO_CALLER_CRASH", false))
        return;

    LOG_INFO("TakeGoldFromCreature() will do nothing instead of crashing when OBJECT_SELF no longer exists.");

    static Hooks::Hook s_ExecuteCommandTakeGoldFromCreatureHook =
            Hooks::HookFunction(&CNWSVirtualMachineCommands::ExecuteCommandTakeGoldFromCreature,
            +[](CNWSVirtualMachineCommands *thisPtr, int32_t nCommandId, int32_t nParameters) -> int32_t
            {
                if (Utils::GetGameObject(thisPtr->m_oidObjectRunScript))
                    return s_ExecuteCommandTakeGoldFromCreatureHook->CallOriginal<int32_t>(thisPtr, nCommandId, nParameters);

                // The engine dereferences OBJECT_SELF's game object unchecked, so pop the arguments and skip the call.
                auto *pVM = Globals::VirtualMachine();
                int32_t nAmount, bDestroy;
                ObjectID oidCreature;
                if (!pVM->StackPopInteger(&nAmount) || !pVM->StackPopObject(&oidCreature) || !pVM->StackPopInteger(&bDestroy))
                    return VMError::StackUnderflow;

                LOG_WARNING("TakeGoldFromCreature(%d, %x) skipped: OBJECT_SELF %x no longer exists.",
                            nAmount, oidCreature, thisPtr->m_oidObjectRunScript);
                return VMError::Success;
            }, Hooks::Order::Early);
}

}
