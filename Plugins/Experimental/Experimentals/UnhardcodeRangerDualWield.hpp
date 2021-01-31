#pragma once

#include "nwnx.hpp"

namespace Experimental {

class UnhardcodeRangerDualWield
{
public:
    UnhardcodeRangerDualWield();

private:
    static int32_t HasFeatHook(CNWSCreatureStats*, uint16_t);
};

}
