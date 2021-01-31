#pragma once

#include "nwnx.hpp"

namespace Tweaks {

class StringToIntBaseToAuto
{
public:
    StringToIntBaseToAuto();

private:
    static int32_t CNWVirtualMachineCommands__ExecuteCommandStringConversions_hook(CNWVirtualMachineCommands*, int32_t, int32_t);
};

}
