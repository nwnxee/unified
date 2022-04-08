#include "nwnx.hpp"

#include "API/CNWSCreature.hpp"


namespace Tweaks {

using namespace NWNXLib;
using namespace NWNXLib::API;


static int16_t s_HPLimit;

void PlayerDyingHitPointLimit() __attribute__((constructor));
void PlayerDyingHitPointLimit()
{
    s_HPLimit = Config::Get<int32_t>("PLAYER_DYING_HP_LIMIT", -10);

    if (s_HPLimit == -10)
        return;

    LOG_INFO("Setting the player dying HP limit to %d", s_HPLimit);

    static Hooks::Hook s_GetIsPCDyingHook = Hooks::HookFunction(API::Functions::_ZN10CNWSObject12GetIsPCDyingEv,
        (void*)+[](CNWSObject* thisPtr) -> int32_t
        {
            if (auto *pCreature = Utils::AsNWSCreature(thisPtr))
            {
                if (pCreature->m_bPlayerCharacter || pCreature->GetIsPossessedFamiliar())
                {
                    int16_t hp = pCreature->GetCurrentHitPoints(false);
                    return (hp <= 0) && (hp > s_HPLimit);
                }
            }

            return false;
        }, Hooks::Order::Final);

    static Hooks::Hook s_GetDeadHook = Hooks::HookFunction(API::Functions::_ZN10CNWSObject7GetDeadEv,
        (void*)+[](CNWSObject* thisPtr) -> int32_t
        {
            int16_t hp = thisPtr->GetCurrentHitPoints(false);
            if (auto *pCreature = Utils::AsNWSCreature(thisPtr))
            {
                if (pCreature->m_bPlayerCharacter || pCreature->GetIsPossessedFamiliar())
                {
                    return hp <= s_HPLimit;
                }
            }

            return hp <= 0;
        }, Hooks::Order::Final);
}

}
