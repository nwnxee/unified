#pragma once

#include "API/Types.hpp"
#include "Common.hpp"
#include "ViewPtr.hpp"
#include "Services/Hooks/Hooks.hpp"

namespace Tweaks {

class PreserveActionsOnDMPossess
{
public:
    PreserveActionsOnDMPossess(NWNXLib::ViewPtr<NWNXLib::Services::HooksProxy> hooker);

private:
    static void CNWSCreature__PossessCreatureDM_hook(CNWSCreature*, NWNXLib::API::Types::ObjectID, uint8_t);
};

}
