#include "Tweaks/SneakAttackCritImmunity.hpp"
#include "API/CNWSCreature.hpp"
#include "API/CNWSCombatRound.hpp"
#include "API/Functions.hpp"
#include "API/Globals.hpp"
#include "API/Version.hpp"

#include "Services/Hooks/Hooks.hpp"
#include "Utils.hpp"


namespace Tweaks {

using namespace NWNXLib;
using namespace NWNXLib::API;

NWNXLib::Hooking::FunctionHook* SneakAttackCritImmunity::pResolveSneakAttack_hook;
SneakAttackCritImmunity::SneakAttackCritImmunity(ViewPtr<Services::HooksProxy> hooker)
{
    hooker->RequestExclusiveHook<Functions::CNWSCreature__ResolveSneakAttack>
                                    (&CNWSCreature__ResolveSneakAttack_hook);

    pResolveSneakAttack_hook = hooker->FindHookByAddress(Functions::CNWSCreature__ResolveSneakAttack);
}


void SneakAttackCritImmunity::CNWSCreature__ResolveSneakAttack_hook(CNWSCreature *pThis, CNWSCreature *pTarget)
{

}


}
