#include "Tweaks/StringToIntBaseToAuto.hpp"


#include "API/CNWVirtualMachineCommands.hpp"
#include "API/CVirtualMachine.hpp"
#include "API/Functions.hpp"
#include "API/Globals.hpp"
#include "API/Constants.hpp"

namespace Tweaks {

using namespace NWNXLib;
using namespace NWNXLib::API;
using namespace NWNXLib::API::Constants;

StringToIntBaseToAuto::StringToIntBaseToAuto()
{
    static auto s_ReplacedFunc = Hooks::HookFunction(Functions::_ZN25CNWVirtualMachineCommands31ExecuteCommandStringConversionsEii,
                 (void*)&CNWVirtualMachineCommands__ExecuteCommandStringConversions_hook, Hooks::Order::Final);
}

int32_t StringToIntBaseToAuto::CNWVirtualMachineCommands__ExecuteCommandStringConversions_hook(CNWVirtualMachineCommands* thisPtr,
                                                                                               int32_t nCommandId, int32_t nParameters)
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
}

}
