#include "nwnx.hpp"

#include "API/CAppManager.hpp"
#include "API/CNWBaseItem.hpp"
#include "API/CNWBaseItemArray.hpp"
#include "API/CNWRules.hpp"
#include "API/CNWSAreaOfEffectObject.hpp"
#include "API/CNWSCombatRound.hpp"
#include "API/CNWSCreature.hpp"
#include "API/CNWSCreatureStats.hpp"
#include "API/CNWSInventory.hpp"
#include "API/CNWSItem.hpp"
#include "API/CServerExoApp.hpp"

namespace Tweaks
{

using namespace NWNXLib;
using namespace NWNXLib::API;

int32_t CNWSCreature__GetWeaponPower(CNWSCreature* thisPtr, CNWSObject* pTarget, int32_t bOffhand);

static Hooks::Hook s_getWeaponPowerHook = nullptr;

void PreventAttackBonusBypassingReductions() __attribute__((constructor));
void PreventAttackBonusBypassingReductions()
{
    if (!Config::Get<bool>("PREVENT_ATTACK_BONUS_BYPASSING_REDUCTION", false))
        return;

    LOG_INFO("Preventing attack bonus effects from bypassing damage reductions");

    s_getWeaponPowerHook = Hooks::HookFunction(Functions::_ZN12CNWSCreature14GetWeaponPowerEP10CNWSObjecti, (void*)&CNWSCreature__GetWeaponPower, Hooks::Order::Final);
}

int32_t CNWSCreature__GetWeaponPower(CNWSCreature* thisPtr, CNWSObject* pTarget, int32_t bOffhand)
{
    auto pCombatRound = thisPtr->m_pcCombatRound;
    auto pCurrentAttack = pCombatRound->GetAttack(pCombatRound->m_nCurrentAttack);
    uint8_t nAlignmentLaw = static_cast<uint8_t>(~0u), nAlignmentGood = static_cast<uint8_t>(~0u);
    uint16_t nRace = static_cast<uint16_t>(~0u);
    int32_t nWeaponPower = 0;

    auto nWeaponAttackType = pCurrentAttack->m_nWeaponAttackType;
    if (nWeaponAttackType == 0)
        nWeaponAttackType = !!bOffhand + 1;

    CNWSItem* pAttackWeapon = nullptr;
    if (bOffhand)
    {
        if (auto* pItem = pCombatRound->GetCurrentAttackWeapon(2))
        {
            // Make sure it isn't a ranged weapon or a shield (shouldn't happen)
            if (auto* pBaseItem = Globals::Rules()->m_pBaseItemArray->GetBaseItem(pItem->m_nBaseItem))
            {
                if (!pBaseItem->m_nWeaponRanged && pBaseItem->m_nWeaponType && pBaseItem->m_nWeaponWield != 7)
                {
                    pAttackWeapon = pItem;
                }
            }
        }
    }
    else
    {
        pAttackWeapon = pCombatRound->GetCurrentAttackWeapon(0);
    }

    if (thisPtr->m_appliedEffects.num < 1 && pAttackWeapon->m_lstPassiveProperties.num < 1)
        return 0;

    if (pTarget)
    {
        CNWSCreature* pTargetCreature = Utils::AsNWSCreature(pTarget);
        if (!pTargetCreature)
        {
            auto pTargetAoe = Utils::AsNWSAreaOfEffectObject(pTarget);
            if (!pTargetAoe ||
                !(pTargetCreature = Globals::AppManager()->m_pServerExoApp->GetCreatureByGameObjectID(pTargetAoe->m_oidCreator)) ||
                !pTargetCreature->m_pStats)
            {

                pTargetCreature = nullptr;
            }
        }

        if (pTargetCreature)
        {
            nRace = pTargetCreature->m_pStats->m_nRace;
            nAlignmentLaw = pTargetCreature->m_pStats->GetSimpleAlignmentLawChaos();
            nAlignmentGood = pTargetCreature->m_pStats->GetSimpleAlignmentGoodEvil();
        }
    }

    if (pAttackWeapon)
    {
        // Get enhancement bonuses on weapon instead of attack bonuses on creature
        for (auto& pItemProperty : pAttackWeapon->m_lstPassiveProperties)
        {
            if (nWeaponPower >= pItemProperty.m_nCostTableValue)
                continue;

            switch (pItemProperty.m_nPropertyName)
            {
                case Constants::ItemProperty::EnhancementBonus:
                    nWeaponPower = pItemProperty.m_nCostTableValue;
                    break;

                case Constants::ItemProperty::EnhancementBonusVSAlignmentGroup:
                    if (pItemProperty.m_nSubType == nAlignmentGood || pItemProperty.m_nSubType == nAlignmentLaw)
                        nWeaponPower = pItemProperty.m_nCostTableValue;
                    break;

                case Constants::ItemProperty::EnhancementBonusVSRacialGroup:
                    if (nRace == pItemProperty.m_nSubType)
                        nWeaponPower = pItemProperty.m_nCostTableValue;
                    break;

                case Constants::ItemProperty::EnhancementBonusVSSpecificAlignment:
                    if (nWeaponPower < pItemProperty.m_nCostTableValue)
                    {
                        if (pItemProperty.m_nSubType < 9)
                        {
                            uint8_t nRequiredAlignLaw = 2;
                            if (pItemProperty.m_nSubType > 5)
                                nRequiredAlignLaw = 3;
                            else if (pItemProperty.m_nSubType > 2)
                                nRequiredAlignLaw = 1;

                            uint8_t nRequiredAlignGood = 4;
                            if (pItemProperty.m_nSubType % 3 == 1)
                                nRequiredAlignGood = 1;
                            else if (pItemProperty.m_nSubType % 3 == 2)
                                nRequiredAlignGood = 5;

                            if (nAlignmentLaw == nRequiredAlignLaw && nAlignmentGood == nRequiredAlignGood)
                                nWeaponPower = pItemProperty.m_nCostTableValue;
                        }
                    }
                    break;
            }
        }
    }

    // Get damage reduction to apply enhancement equal to reduction on creature weapons
    if (nWeaponAttackType == Constants::WeaponAttackType::CreatureLeftWeapon
        || nWeaponAttackType == Constants::WeaponAttackType::CreatureRightWeapon
        || nWeaponAttackType == Constants::WeaponAttackType::CreatureBiteWeapon)
    {
        for (int i = thisPtr->m_pStats->m_nDamageReductionPtr;
            i < thisPtr->m_appliedEffects.num
            && thisPtr->m_appliedEffects.element[i]->m_nType == Constants::EffectTrueType::DamageReduction;
            i++)
        {
            auto nEffectPower = thisPtr->m_appliedEffects.element[i]->GetInteger(1);
            if (nWeaponPower < nEffectPower)
                nWeaponPower = nEffectPower;
        }
    }

    int nMaxAttackBonus = Globals::AppManager()->m_pServerExoApp->GetAttackBonusLimit();
    return std::min(nWeaponPower, nMaxAttackBonus);
}

}
