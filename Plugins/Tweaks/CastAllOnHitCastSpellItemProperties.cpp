#include "nwnx.hpp"

#include "API/CAppManager.hpp"
#include "API/CServerExoApp.hpp"
#include "API/CServerAIMaster.hpp"
#include "API/Constants.hpp"
#include "API/CExoArrayList.hpp"
#include "API/CNWSCreature.hpp"
#include "API/CNWSItem.hpp"
#include "API/CNWItemProperty.hpp"
#include "API/CNWRules.hpp"
#include "API/CNWSpellArray.hpp"
#include "API/CNWSSpellScriptData.hpp"
#include "API/CNWSCombatRound.hpp"
#include "API/CNWSCombatAttackData.hpp"
#include "API/CTwoDimArrays.hpp"

namespace Tweaks {

using namespace NWNXLib;
using namespace NWNXLib::API;

void CastAllOnHitCastSpellItemProperties() __attribute__((constructor));
void CastAllOnHitCastSpellItemProperties()
{
    if (!Config::Get<bool>("CAST_ALL_ON_HIT_CAST_SPELL_ITEM_PROPERTIES", false))
        return;

    LOG_INFO("All On Hit: Cast Spell item properties will be cast on hit");

    static Hooks::Hook s_ApplyOnHitCastSpellHook = Hooks::HookFunction(&CNWSCreature::ApplyOnHitCastSpell,
        (void*)+[](CNWSCreature *pCreature, CNWSObject *pTarget, CNWItemProperty*, CNWSItem *pItem) -> void
        {
            bool bArmorHit = pItem->m_nBaseItem == Constants::BaseItem::CreatureItem ||
                             pItem->m_nBaseItem == Constants::BaseItem::TowerShield ||
                             pItem->m_nBaseItem == Constants::BaseItem::LargeShield ||
                             pItem->m_nBaseItem == Constants::BaseItem::SmallShield ||
                             pItem->m_nBaseItem == Constants::BaseItem::Armor;

            auto *pAttackData = pCreature->m_pcCombatRound->GetAttack(pCreature->m_pcCombatRound->m_nCurrentAttack);

            for (int32_t i = 0; i < pItem->m_lstPassiveProperties.num; i++)
            {
                if (auto *pItemProperty = pItem->GetPassiveProperty(i))
                {
                    if (pItemProperty->m_nPropertyName == Constants::ItemProperty::OnHitCastSpell)
                    {
                        int32_t nSpellID;
                        if (Globals::Rules()->m_p2DArrays->m_pOnHitSpellTable->GetINTEntry(pItemProperty->m_nSubType, CExoString("SpellIndex"), &nSpellID))
                        {
                            if (auto *pSpell = Globals::Rules()->m_pSpellArray->GetSpell(nSpellID))
                            {
                                auto *pSpellScriptData = new CNWSSpellScriptData;
                                pSpellScriptData->m_nSpellId = pSpell->m_nSpellId;
                                pSpellScriptData->m_nFeatId = 0xFFFF;
                                pSpellScriptData->m_oidCaster = bArmorHit ? pTarget->m_idSelf : pCreature->m_idSelf;
                                pSpellScriptData->m_oidTarget = bArmorHit ? pCreature->m_idSelf : pTarget->m_idSelf;
                                pSpellScriptData->m_oidItem = pItem->m_idSelf;
                                pSpellScriptData->m_vTargetPosition = bArmorHit ? pCreature->m_vPosition : pTarget->m_vPosition;
                                pSpellScriptData->m_sScript = pSpell->m_sImpactScript;
                                pSpellScriptData->m_oidArea = pTarget->m_oidArea;
                                pSpellScriptData->m_nItemCastLevel = pItemProperty->m_nCostTableValue + 1;

                                if (bArmorHit)
                                    pAttackData->m_alstOnHitEnemySpellScripts.Add(pSpellScriptData);
                                else
                                    pAttackData->m_alstOnHitSpellScripts.Add(pSpellScriptData);
                            }
                        }
                    }
                }
            }
        }, Hooks::Order::Final);
}

}
