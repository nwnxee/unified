#pragma once

#include "Common.hpp"

namespace Experimental {

class UnhardcodeRangerDualWield
{
public:
    UnhardcodeRangerDualWield(NWNXLib::Services::HooksProxy* hooker);

private:
    static int32_t HasFeatHook(CNWSCreatureStats*, uint16_t);
};

}
