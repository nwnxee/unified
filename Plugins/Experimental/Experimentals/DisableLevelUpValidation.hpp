#pragma once

#include "nwnx.hpp"

namespace Experimental {

class DisableLevelUpValidation
{
public:
    DisableLevelUpValidation();

private:
    static uint32_t ValidateLevelUpHook(CNWSCreatureStats*, CNWLevelStats*, uint8_t, uint8_t, uint8_t);
};

}
