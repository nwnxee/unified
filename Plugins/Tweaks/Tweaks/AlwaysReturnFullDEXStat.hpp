#pragma once

#include "nwnx.hpp"

namespace Tweaks {

class AlwaysReturnFullDEXStat
{
public:
    AlwaysReturnFullDEXStat(NWNXLib::Services::HooksProxy* hooker);

private:
    static uint8_t GetDEXStatHook(CNWSCreatureStats*);
};

}

