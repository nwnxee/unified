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

PlayerDyingHitPointLimit::PlayerDyingHitPointLimit(ViewPtr<Services::HooksProxy> hooker, int16_t hplimit)
{
    m_hplimit = hplimit;

    hooker->RequestExclusiveHook<API::Functions::CNWSObject__GetIsPCDying>
        (&CNWSObject__GetIsPCDying_Hook);
}

int32_t PlayerDyingHitPointLimit::CNWSObject__GetIsPCDying_Hook(CNWSObject* thisPtr)
{
    if (auto *pCreature = Utils::AsNWSCreature(thisPtr))
    {
        if (pCreature->m_bPlayerCharacter || pCreature->GetIsPossessedFamiliar())
        {
            int16_t hp = pCreature->GetCurrentHitPoints(false);
            return (hp < 0) && (hp > m_hplimit);
        }
    }

    return false;
}

}
