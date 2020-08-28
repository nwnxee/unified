#pragma once

#include "Common.hpp"
#include "Services/Hooks/Hooks.hpp"

namespace Tweaks {

class StringToIntBaseToAuto
{
public:
    StringToIntBaseToAuto(NWNXLib::Services::HooksProxy* hooker);

private:
    static int32_t CNWVirtualMachineCommands__ExecuteCommandStringConversions_hook(CNWVirtualMachineCommands*, int32_t, int32_t);
};

}
