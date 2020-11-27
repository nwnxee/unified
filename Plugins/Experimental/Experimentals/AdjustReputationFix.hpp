#pragma once

#include "Common.hpp"

namespace Experimental {

class AdjustReputationFix
{
public:
    AdjustReputationFix(NWNXLib::Services::HooksProxy* hooker);

private:
    static void CNWSCreature__AdjustReputation_Hook(CNWSCreature*, int32_t, int32_t);
};

}
