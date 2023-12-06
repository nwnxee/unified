#include "nwnx.hpp"

#include "API/CNWSItem.hpp"
#include "API/CNWItemProperty.hpp"
#include "API/CNWRules.hpp"
#include "API/CNWBaseItemArray.hpp"
#include "API/CNWBaseItem.hpp"
#include "API/CTwoDimArrays.hpp"
#include "API/C2DA.hpp"


namespace Tweaks {

using namespace NWNXLib;
using namespace NWNXLib::API;

static int32_t s_HiddenVFX;

void HideHardcodedItemVFX() __attribute__((constructor));
void HideHardcodedItemVFX()
{
    s_HiddenVFX = Config::Get<int32_t>("HIDE_HARDCODED_ITEM_VFX", 0);

    if (!s_HiddenVFX)
        return;

    LOG_INFO("One or more hardcoded Item VFX will be hidden: %i", s_HiddenVFX);

    static Hooks::Hook s_UpdateVisualEffectHook = Hooks::HookFunction(&CNWSItem::UpdateVisualEffect,
        +[](CNWSItem *pThis) -> void
        {
            if (Globals::Rules()->m_pBaseItemArray->GetBaseItem(pThis->m_nBaseItem)->m_nModelType != 2/*Composite*/)
            {
                pThis->m_nVisualEffect = Constants::ItemVFX::None;
                return;
            }

            // 1:       Manual VFX (ItemPropertyVisualEffect)

            // 2:       (Elemental) DamageBonus
            // 4:       (Elemental) DamageBonusVSAlignmentGroup
            // 8:       (Elemental) DamageBonusVSRacialGroup
            // 16:      (Elemental) DamageBonusVSSpecificAlignment

            // 32:      HolyAvenger
            // 64:      VampiricRegeneration
            // 128:     OnHitLevelDrain
            // 256:     OnHitVorpal
            // 512:     OnHitWounding
            // 1024:    (Good/Evil) DamageBonusVSAlignmentGroup
            // 2048:    (Good/Evil) AttackBonusVSAlignmentGroup
            // 4096:    (Good/Evil) EnhancementBonusVSAlignmentGroup
            // 8192:    (Good/Evil) DamageBonusVSSpecificAlignment
            // 16384:   (Good/Evil) AttackBonusVSSpecificAlignment
            // 32768:   (Good/Evil) EnhancementBonusVSSpecificAlignment

            // 30: All Elemental Damage Bonus
            // 896: All OnHit Properties
            // 7168: All Good/Evil vs AlignmentGroup
            // 57344: All Good/Evil vs SpecificAlignment
            // 65535: All VFX

            if (!(s_HiddenVFX & 1))
            {
                for (int32_t i = 0; i < pThis->m_lstPassiveProperties.num; i++)
                {
                    if (auto *pItemProperty = pThis->GetPassiveProperty(i))
                    {
                        if (pItemProperty->m_nPropertyName == Constants::ItemProperty::VisualEffect)
                        {
                            pThis->m_nVisualEffect = (uint8_t)pItemProperty->m_nSubType + 1;
                            return;
                        }
                    }
                }
            }

            for (int32_t i = 0; i < pThis->m_lstPassiveProperties.num; i++)
            {
                if (auto *pItemProperty = pThis->GetPassiveProperty(i))
                {
                    int32_t nDamageType = -1;
                    if (pItemProperty->m_nPropertyName == Constants::ItemProperty::DamageBonus && !(s_HiddenVFX & 2))
                        nDamageType = pItemProperty->m_nSubType > 2 ? pItemProperty->m_nSubType - 2 : pItemProperty->m_nSubType;
                    else if ((pItemProperty->m_nPropertyName == Constants::ItemProperty::DamageBonusVSAlignmentGroup && !(s_HiddenVFX & 4)) ||
                             (pItemProperty->m_nPropertyName == Constants::ItemProperty::DamageBonusVSRacialGroup && !(s_HiddenVFX & 8)) ||
                             (pItemProperty->m_nPropertyName == Constants::ItemProperty::DamageBonusVSSpecificAlignment && !(s_HiddenVFX & 16)))
                        nDamageType = pItemProperty->m_nParam1Value > 2 ? pItemProperty->m_nParam1Value - 2 : pItemProperty->m_nParam1Value;

                    if (nDamageType != -1)
                    {
                        int32_t nDisplayVFX = 0;
                        Globals::Rules()->m_p2DArrays->GetDamageTable()->GetINTEntry(pItemProperty->m_nCostTableValue, "VFX", &nDisplayVFX);

                        if (nDisplayVFX)
                        {
                            uint8_t nItemVFX;
                            switch (nDamageType)
                            {
                                case 4: nItemVFX = Constants::ItemVFX::Acid; break;
                                case 5: nItemVFX = Constants::ItemVFX::Cold; break;
                                case 7: nItemVFX = Constants::ItemVFX::Electrical; break;
                                case 8: nItemVFX = Constants::ItemVFX::Fire; break;
                                case 11: nItemVFX = Constants::ItemVFX::Sonic; break;
                                default: nItemVFX = Constants::ItemVFX::None; break;
                            }

                            if (nItemVFX != Constants::ItemVFX::None)
                            {
                                pThis->m_nVisualEffect = nItemVFX;
                                return;
                            }
                        }
                    }
                }
            }

            for (int32_t i = 0; i < pThis->m_lstPassiveProperties.num; i++)
            {
                if (auto *pItemProperty = pThis->GetPassiveProperty(i))
                {
                    uint8_t nItemVFX = Constants::ItemVFX::None;

                    if (pItemProperty->m_nPropertyName == Constants::ItemProperty::HolyAvenger && !(s_HiddenVFX & 32))
                        nItemVFX = Constants::ItemVFX::Holy;
                    else if (pItemProperty->m_nPropertyName == Constants::ItemProperty::VampiricRegeneration && !(s_HiddenVFX & 64))
                    {
                        int32_t nDisplayVFX = 0;
                        Globals::Rules()->m_p2DArrays->GetIPRPMelee()->GetINTEntry(pItemProperty->m_nCostTableValue, "VFX", &nDisplayVFX);
                        if (nDisplayVFX)
                            nItemVFX = Constants::ItemVFX::Evil;
                    }
                    else if (pItemProperty->m_nPropertyName == Constants::ItemProperty::OnHitProperties && (
                            (pItemProperty->m_nSubType == 17/*Level Drain*/ && !(s_HiddenVFX & 128)) ||
                            (pItemProperty->m_nSubType == 24/*Vorpal*/ && !(s_HiddenVFX & 256)) ||
                            (pItemProperty->m_nSubType == 25/*Wounding*/ && !(s_HiddenVFX & 512))))
                        nItemVFX = Constants::ItemVFX::Evil;
                    else if ((pItemProperty->m_nPropertyName == Constants::ItemProperty::DamageBonusVSAlignmentGroup && !(s_HiddenVFX & 1024)) ||
                             (pItemProperty->m_nPropertyName == Constants::ItemProperty::AttackBonusVSAlignmentGroup && !(s_HiddenVFX & 2048)) ||
                             (pItemProperty->m_nPropertyName == Constants::ItemProperty::EnhancementBonusVSAlignmentGroup && !(s_HiddenVFX & 4096)))
                    {
                        if (pItemProperty->m_nSubType == 4/*Good*/)
                            nItemVFX = Constants::ItemVFX::Evil;
                        else if (pItemProperty->m_nSubType == 5/*Evil*/)
                            nItemVFX = Constants::ItemVFX::Holy;
                    }
                    else if ((pItemProperty->m_nPropertyName == Constants::ItemProperty::DamageBonusVSSpecificAlignment && !(s_HiddenVFX & 8192)) ||
                             (pItemProperty->m_nPropertyName == Constants::ItemProperty::AttackBonusVSSpecificAlignment && !(s_HiddenVFX & 16384)) ||
                             (pItemProperty->m_nPropertyName == Constants::ItemProperty::EnhancementBonusVSSpecificAlignment && !(s_HiddenVFX & 32768)))
                    {
                        if (pItemProperty->m_nSubType == 0/*LawfulGood*/ || pItemProperty->m_nSubType == 3/*NeutralGood*/ || pItemProperty->m_nSubType == 6/*ChaoticGood*/)
                            nItemVFX = Constants::ItemVFX::Evil;
                        else if (pItemProperty->m_nSubType == 2/*LawfulEvil*/ || pItemProperty->m_nSubType == 5/*NeutralEvil*/ || pItemProperty->m_nSubType == 8/*ChaoticEvil*/)
                            nItemVFX = Constants::ItemVFX::Holy;
                    }

                    if (nItemVFX != Constants::ItemVFX::None)
                    {
                        pThis->m_nVisualEffect = nItemVFX;
                        return;
                    }
                }
            }

            pThis->m_nVisualEffect = Constants::ItemVFX::None;
        }, Hooks::Order::Final);
}

}
