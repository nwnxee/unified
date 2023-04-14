#include "nwnx.hpp"

#include "API/CNWSCreature.hpp"
#include "API/CNWSCombatRound.hpp"
#include "API/CNWSItem.hpp"
#include "API/CNWBaseItemArray.hpp"
#include "API/CNWBaseItem.hpp"
#include "API/CNWRules.hpp"

namespace Tweaks {

using namespace NWNXLib;
using namespace NWNXLib::API;

void RangedWeaponsUseOnHitEffectItemProperties() __attribute__((constructor));
void RangedWeaponsUseOnHitEffectItemProperties()
{
    if (!Config::Get<bool>("RANGED_WEAPONS_USE_ON_HIT_EFFECT_ITEM_PROPERTIES", false))
        return;

    LOG_INFO("Ranged weapons will use On Hit: Effect item properties.");

    static Hooks::Hook s_ResolveOnHitEffectHook = Hooks::HookFunction(&CNWSCreature::ResolveOnHitEffect,
        (void*)+[](CNWSCreature *pCreature, CNWSObject *pTarget, BOOL bOffHandAttack, BOOL bCritical) -> void
        {
            if (auto *pCombatRound = pCreature->m_pcCombatRound)
            {
                if (auto *pWeapon = pCombatRound->GetCurrentAttackWeapon(pCombatRound->GetWeaponAttackType()))
                {
                    auto nBaseItem = pWeapon->m_nBaseItem;

                    if (nBaseItem == Constants::BaseItem::HeavyCrossbow ||
                        nBaseItem == Constants::BaseItem::LightCrossbow ||
                        nBaseItem == Constants::BaseItem::Longbow ||
                        nBaseItem == Constants::BaseItem::Shortbow ||
                        nBaseItem == Constants::BaseItem::Sling)
                    {
                        pWeapon->m_nBaseItem = Constants::BaseItem::Shortsword;
                        s_ResolveOnHitEffectHook->CallOriginal<void>(pCreature, pTarget, bOffHandAttack, bCritical);
                        pWeapon->m_nBaseItem = nBaseItem;
                    }
                }
            }

            s_ResolveOnHitEffectHook->CallOriginal<void>(pCreature, pTarget, bOffHandAttack, bCritical);
            
        }, Hooks::Order::Earliest);
}

}

