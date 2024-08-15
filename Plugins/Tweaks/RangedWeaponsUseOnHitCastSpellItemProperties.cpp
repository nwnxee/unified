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

void RangedWeaponsUseOnHitCastSpellItemProperties() __attribute__((constructor));
void RangedWeaponsUseOnHitCastSpellItemProperties()
{
    if (!Config::Get<bool>("RANGED_WEAPONS_USE_ON_HIT_CAST_SPELL_ITEM_PROPERTIES", false))
        return;

    LOG_INFO("Ranged weapons will use On Hit: Cast Spell item properties");

    static Hooks::Hook s_ResolveItemCastSpellHook = Hooks::HookFunction(&CNWSCreature::ResolveItemCastSpell,
        (void*)+[](CNWSCreature *pCreature, CNWSObject *pTarget) -> void
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
                        s_ResolveItemCastSpellHook->CallOriginal<void>(pCreature, pTarget);
                        pWeapon->m_nBaseItem = nBaseItem;
                    }
                }
            }

            s_ResolveItemCastSpellHook->CallOriginal<void>(pCreature, pTarget);
            
        }, Hooks::Order::Earliest);
}

}

