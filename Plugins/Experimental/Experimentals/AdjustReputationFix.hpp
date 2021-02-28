#pragma once

#include "nwnx.hpp"

namespace Experimental {

class AdjustReputationFix
{
public:
    AdjustReputationFix();

private:
    static void CNWSCreature__AdjustReputation_Hook(CNWSCreature*, int32_t, int32_t);
};

}
