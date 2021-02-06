#include "nwnx.hpp"

#include "API/CNWVirtualMachineCommands.hpp"
#include "API/CVirtualMachine.hpp"


namespace Tweaks {

using namespace NWNXLib;
using namespace NWNXLib::API;
using namespace NWNXLib::API::Constants;


void StringToIntBaseToAuto() __attribute__((constructor));
void StringToIntBaseToAuto()
{
    if (!Config::Get<bool>("STRINGTOINT_BASE_TO_AUTO", false))
        return;

    LOG_INFO("Setting StringToInt() base to auto to allow for conversion of hex strings to proper values.");

    static Hooks::Hook s_ExecuteCommandStringConversionsHook =
            Hooks::HookFunction(Functions::_ZN25CNWVirtualMachineCommands31ExecuteCommandStringConversionsEii,
            (void*)+[](CNWVirtualMachineCommands* thisPtr, int32_t nCommandId, int32_t nParameters) -> int32_t
            {
                ASSERT(thisPtr); ASSERT(nParameters == 1);
                auto *vm = Globals::VirtualMachine();

                bool success = false;
                CExoString str;
                if (!vm->StackPopString(&str))
                    return VMError::StackUnderflow;

                switch (nCommandId)
                {
                    case VMCommand::StringToInt:
                        try {
                            success = vm->StackPushInteger(std::stoi(str.CStr(), nullptr, 0));
                        } catch(...) {
                            success = vm->StackPushInteger(0);
                        }
                        break;
                    case VMCommand::StringToFloat:
                        try {
                            success = vm->StackPushFloat(std::stof(str.CStr()));
                        } catch(...) {
                            success = vm->StackPushFloat(0.0);
                        }
                        break;
                    default:
                        ASSERT_FAIL_MSG("Bad command ID %d.", nCommandId);
                }

                return success ? VMError::Success : VMError::StackOverflow;
            }, Hooks::Order::Final);
}

}
