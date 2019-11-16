#include "Tweaks/PlayerDyingHitPointLimit.hpp"

#include "Services/Hooks/Hooks.hpp"
#include "Utils.hpp"

#include "API/CAppManager.hpp"
#include "API/CNWSCreature.hpp"
#include "API/CNWSMessage.hpp"
#include "API/CServerExoApp.hpp"
#include "API/Functions.hpp"
#include "API/Globals.hpp"

namespace Tweaks {

using namespace NWNXLib;
using namespace NWNXLib::API;

int16_t PlayerDyingHitPointLimit::m_hplimit;
PlayerDyingHitPointLimit::PlayerDyingHitPointLimit(ViewPtr<Services::HooksProxy> hooker, int16_t hplimit)
{
    m_hplimit = hplimit;

    hooker->RequestExclusiveHook<API::Functions::_ZN10CNWSObject12GetIsPCDyingEv>(&CNWSObject__GetIsPCDying_Hook);
    hooker->RequestExclusiveHook<API::Functions::_ZN10CNWSObject7GetDeadEv>(&CNWSObject__GetDead_Hook);
}

int32_t PlayerDyingHitPointLimit::CNWSObject__GetIsPCDying_Hook(CNWSObject* thisPtr)
{
    if (auto *pCreature = Utils::AsNWSCreature(thisPtr))
    {
        if (pCreature->m_bPlayerCharacter || pCreature->GetIsPossessedFamiliar())
        {
            int16_t hp = pCreature->GetCurrentHitPoints(false);
            return (hp <= 0) && (hp > m_hplimit);
        }
    }

    return false;
}
int32_t PlayerDyingHitPointLimit::CNWSObject__GetDead_Hook(CNWSObject* thisPtr)
{
    int16_t hp = thisPtr->GetCurrentHitPoints(false);
    if (auto *pCreature = Utils::AsNWSCreature(thisPtr))
    {
        if (pCreature->m_bPlayerCharacter || pCreature->GetIsPossessedFamiliar())
        {
            return hp <= m_hplimit;
        }
    }

    return hp <= 0;
}

}
