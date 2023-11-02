#include "nwnx.hpp"

#include "API/CNWSCreature.hpp"
#include "API/CNWSCreatureStats.hpp"
#include "API/CNWSItem.hpp"
#include "API/CNWRules.hpp"
#include "API/CNWClass.hpp"
#include "API/CNWItemProperty.hpp"
#include "API/CTwoDimArrays.hpp"
#include "API/C2DA.hpp"
#include "API/CNWSpellArray.hpp"
#include "API/CNWSpell.hpp"
#include "API/CAppManager.hpp"
#include "API/CServerExoApp.hpp"
#include "API/CServerInfo.hpp"
#include "API/CPlayOptions.hpp"
#include "API/CNWBaseItemArray.hpp"
#include "API/CNWBaseItem.hpp"

namespace Tweaks {

using namespace NWNXLib;
using namespace NWNXLib::API;


void CanUseItemCheckILRForHenchmen() __attribute__((constructor));
void CanUseItemCheckILRForHenchmen()
{
    if (!Config::Get<bool>("CANUSEITEM_CHECK_ILR_FOR_HENCHMEN", false))
        return;

    LOG_INFO("CNWSCreature::CanUseItem() will also check ILR for Henchmen.");

    static Hooks::Hook s_CanUseItemHook = Hooks::HookFunction(&CNWSCreature::CanUseItem,
    +[](CNWSCreature *pCreature, CNWSItem *pItem, BOOL bIgnoreIdentifiedFlag) -> BOOL
    {
        bool bUsable = true;

        if (!pItem)
            return false;

        if (pCreature->m_pStats->GetIsDM() || pCreature->m_nAssociateType == Constants::AssociateType::DMImpersonate)
            return true;

        if (bUsable && !pCreature->CheckItemAlignmentRestrictions(pItem))
            bUsable = false;
        if (bUsable && !pCreature->CheckItemClassRestrictions(pItem))
            bUsable = false;
        if (bUsable && !pCreature->CheckItemRaceRestrictions(pItem))
            bUsable = false;

        if (bUsable && pItem->m_nBaseItem == Constants::BaseItem::SpellScroll)
        {
            for (int32_t i = 0; i < pCreature->m_pStats->m_nNumMultiClasses; i++)
            {
                if (!Globals::Rules()->m_lstClasses[pCreature->m_pStats->GetClass(i)].m_bHasSpecialization)
                    continue;

                uint8_t nSpellSchool = pCreature->m_pStats->GetSchool(i);

                if (nSpellSchool != 0 /*General*/)
                {
                    if (auto *pProperty = pItem->GetActiveProperty(0))
                    {
                        int32_t nSpellID;
                        Globals::Rules()->m_p2DArrays->GetIPRPSpells()->GetINTEntry(pProperty->m_nSubType, "SpellIndex", &nSpellID);

                        if (auto *pSpell = Globals::Rules()->m_pSpellArray->GetSpell(nSpellID))
                        {
                            int32_t nOppositionSchool;
                            Globals::Rules()->m_p2DArrays->GetSpellSchoolTable()->GetINTEntry(nSpellSchool, "Opposition", &nOppositionSchool);

                            if (pSpell->m_nSchool == nOppositionSchool)
                            {
                                bUsable = false;
                            }
                        }
                    }
                }
            }
        }

        if (bUsable && (pCreature->m_bIsPolymorphed &&
            (pItem->m_nBaseItem != Constants::BaseItem::Potions &&
             pItem->m_nBaseItem != Constants::BaseItem::EnchantedPotion)))
        {
            bUsable = false;
        }

        if (bUsable && (pCreature->m_bPlayerCharacter || pCreature->m_nAssociateType == Constants::AssociateType::Henchman))
        {
            if ((Globals::AppManager()->m_pServerExoApp->GetServerInfo()->m_PlayOptions.bItemLevelRestrictions && pCreature->m_pStats->GetLevel() < pItem->GetMinEquipLevel()) ||
                (!bIgnoreIdentifiedFlag && !pItem->m_bIdentified))
            {
                bUsable = false;
            }
        }

        if (bUsable)
        {
            if (auto *pBaseItem = Globals::Rules()->m_pBaseItemArray->GetBaseItem(pItem->m_nBaseItem))
            {
                if (pBaseItem->m_nWeaponWield != 0x01/*NonWeapon*/ &&
                    pBaseItem->m_nWeaponType != 0/*None*/ &&
                    pItem->m_nBaseItem != Constants::BaseItem::Gloves &&
                    pItem->m_nBaseItem != Constants::BaseItem::Bracer)
                {
                    int32_t nWeaponToEquipSize = pBaseItem->m_nWeaponSize - pCreature->m_nCreatureSize;

                    if (nWeaponToEquipSize > 1/*RelSizeLarge*/ || nWeaponToEquipSize < -2/*RelSizeTiny*/)
                    {
                        bUsable = false;
                    }
                }

                if (bUsable)
                {
                    bool bSlotFound = false;
                    uint32_t nEquipToSlot;

                    for (int32_t nCount = 0; nCount <= Constants::InventorySlot::MAX; nCount++)
                    {
                        nEquipToSlot = 1 << nCount;
                        if ((pBaseItem->m_nEquipableSlots & nEquipToSlot) != 0)
                        {
                            bSlotFound = true;
                            break;
                        }
                    }

                    if (bSlotFound && !pCreature->CheckProficiencies(pItem, nEquipToSlot))
                    {
                        bUsable = false;
                    }
                }
            }
        }

        if (bUsable && pItem->m_nBaseItem == Constants::BaseItem::TowerShield &&
            (pCreature->m_nCreatureSize == Constants::CreatureSize::Tiny || pCreature->m_nCreatureSize == Constants::CreatureSize::Small))
        {
            bUsable = false;
        }

        return bUsable;
    }, Hooks::Order::Final);
}

}
