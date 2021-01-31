#pragma once

#include "nwnx.hpp"

namespace Tweaks {

class AlwaysReturnFullDEXStat
{
public:
    AlwaysReturnFullDEXStat();

private:
    static uint8_t GetDEXStatHook(CNWSCreatureStats*);
};

}

