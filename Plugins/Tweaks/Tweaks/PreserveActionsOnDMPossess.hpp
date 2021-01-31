#pragma once

#include "nwnx.hpp"

namespace Tweaks {

class PreserveActionsOnDMPossess
{
public:
    PreserveActionsOnDMPossess();

private:
    static void CNWSCreature__PossessCreatureDM_hook(CNWSCreature*, ObjectID, uint8_t);
};

}
