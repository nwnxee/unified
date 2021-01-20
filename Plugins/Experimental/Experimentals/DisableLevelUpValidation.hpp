#pragma once

#include "Common.hpp"

namespace Experimental {

class DisableLevelUpValidation
{
public:
    DisableLevelUpValidation(NWNXLib::Services::HooksProxy* hooker);

private:
    static uint32_t ValidateLevelUpHook(CNWSCreatureStats*, CNWLevelStats*, uint8_t, uint8_t, uint8_t);
};

}
