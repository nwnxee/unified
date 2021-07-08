#include "nwnx.hpp"

#include "API/CAppManager.hpp"
#include "API/CNWBaseItem.hpp"
#include "API/CNWBaseItemArray.hpp"
#include "API/CNWCCMessageData.hpp"
#include "API/CNWCCMessageData.hpp"
#include "API/CNWItemProperty.hpp"
#include "API/CNWRules.hpp"
#include "API/CNWSCombatRound.hpp"
#include "API/CNWSCreature.hpp"
#include "API/CNWSCreatureStats.hpp"
#include "API/CNWSDoor.hpp"
#include "API/CNWSItem.hpp"
#include "API/CNWSObject.hpp"
#include "API/CNWSPlaceable.hpp"
#include "API/CServerExoApp.hpp"
#include "API/CTwoDimArrays.hpp"

#include <cmath>

using namespace NWNXLib;
using namespace NWNXLib::API;

int32_t CNWSCreatureStats__GetDamageRoll(CNWSCreatureStats*, CNWSObject*, int32_t, int32_t, int32_t, int32_t, int32_t);
int32_t CNWSObject__DoDamageResistance(CNWSObject*, CNWSCreature*, int32_t, uint16_t, int32_t, int32_t, int32_t);
int32_t CNWSObject__DoDamageReduction(CNWSObject*, CNWSCreature*, int32_t, unsigned char, int32_t, int32_t);
int32_t CNWSItemPropertyHandler__ApplyDamageResistance(void*, CNWSItem*, CNWItemProperty*, CNWSCreature*, BOOL, BOOL);
int32_t CNWSItemPropertyHandler__ApplyDamageReduction(void*, CNWSItem*, CNWItemProperty*, CNWSCreature*, BOOL, BOOL);
void LoadRulesetInfo(CNWRules*);

static constexpr bool FIX_HIGHEST_REDUCTION_EFFECT = true;

static Hooks::Hook s_getDamageRollHook = nullptr;
static Hooks::Hook s_doDamageResistanceHook = nullptr;
static Hooks::Hook s_doDamageReductionHook = nullptr;
static Hooks::Hook s_applyDamageResistanceHook = nullptr;
static Hooks::Hook s_applyDamageReductionHook = nullptr;
static Hooks::Hook s_loadRulesetInfoHook = nullptr;
static std::vector<uint32_t> s_currentWeaponMaterials;
static std::vector<uint32_t> s_damageToMaterialMap;
static std::vector<uint32_t> s_reductionToMaterialMap;

void WeaponMaterials() __attribute__((constructor));
void WeaponMaterials()
{
    s_getDamageRollHook = Hooks::HookFunction(Functions::_ZN17CNWSCreatureStats13GetDamageRollEP10CNWSObjectiiiii, (void*)&CNWSCreatureStats__GetDamageRoll, Hooks::Order::VeryEarly);
    s_doDamageResistanceHook = Hooks::HookFunction(Functions::_ZN10CNWSObject18DoDamageResistanceEP12CNWSCreatureitiii, (void*)&CNWSObject__DoDamageResistance, Hooks::Order::Final);
    s_doDamageReductionHook = Hooks::HookFunction(Functions::_ZN10CNWSObject17DoDamageReductionEP12CNWSCreatureihii, (void*)&CNWSObject__DoDamageReduction, Hooks::Order::Final);
    s_applyDamageResistanceHook = Hooks::HookFunction(Functions::_ZN23CNWSItemPropertyHandler21ApplyDamageResistanceEP8CNWSItemP15CNWItemPropertyP12CNWSCreatureji, (void*)&CNWSItemPropertyHandler__ApplyDamageResistance, Hooks::Order::Final);
    s_applyDamageReductionHook = Hooks::HookFunction(Functions::_ZN23CNWSItemPropertyHandler20ApplyDamageReductionEP8CNWSItemP15CNWItemPropertyP12CNWSCreatureji, (void*)&CNWSItemPropertyHandler__ApplyDamageReduction, Hooks::Order::Final);
    s_loadRulesetInfoHook = Hooks::HookFunction(Functions::_ZN8CNWRules15LoadRulesetInfoEv, (void*)&LoadRulesetInfo, Hooks::Order::VeryEarly);
}

void LoadRulesetInfo(CNWRules* rules)
{
    s_loadRulesetInfoHook->CallOriginal<void>(rules);

    auto materialTDA = rules->m_p2DArrays->GetCached2DA("iprp_material", true);
    materialTDA->Load2DArray();
    auto numMaterials = materialTDA->m_nNumRows;

    auto damageTDA = rules->m_p2DArrays->GetCached2DA("iprp_damagetype", true);
    damageTDA->Load2DArray();
    auto numDamagetypes = damageTDA->m_nNumRows;
    s_damageToMaterialMap.resize(numDamagetypes, 0);

    int32_t val;
    for (int i = 0; i < numDamagetypes; i++)
    {
        if (!damageTDA->GetINTEntry(i, "Material", &val) || val > numMaterials || val < 0)
            val = 0;
        s_damageToMaterialMap[i] = val;
    }

    auto protectionTDA = rules->m_p2DArrays->GetCached2DA("iprp_protection", true);
    protectionTDA->Load2DArray();
    auto numReductionTypes = protectionTDA->m_nNumRows;
    s_reductionToMaterialMap.resize(numReductionTypes, 0);

    for (int i = 0; i < numReductionTypes; i++)
    {
        if (!protectionTDA->GetINTEntry(i, "Material", &val) || val > numMaterials || val < 0)
            val = 0;
        s_reductionToMaterialMap[i] = val;
    }
}

int32_t CNWSCreatureStats__GetDamageRoll(CNWSCreatureStats* thisPtr, CNWSObject* pTarget, int32_t bOffhand,
    int32_t bCritical, int32_t bSneak, int32_t bDeath, int32_t bForceMax)
{
    CNWSItem* pAttackWeapon = nullptr;
    auto pCombatRound = thisPtr->m_pBaseCreature->m_pcCombatRound;

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

    s_currentWeaponMaterials.resize(0);
    if (pTarget && pAttackWeapon)
    {
        for (auto& property : pAttackWeapon->m_lstPassiveProperties)
            if (property.m_nPropertyName == Constants::ItemProperty::Material)
                s_currentWeaponMaterials.push_back(property.m_nCostTableValue);
    }

    auto ret = s_getDamageRollHook->CallOriginal<int32_t>(thisPtr, pTarget, bOffhand, bCritical, bSneak, bDeath, bForceMax);

    s_currentWeaponMaterials.resize(0);
    return ret;
}

int32_t CNWSObject__DoDamageResistance(CNWSObject* thisPtr, CNWSCreature* pAttacker, int32_t nDamage, uint16_t nFlags, int32_t bSimulate, int32_t bCombatDamage, int32_t bBaseDamage)
{
    auto pCreature = Utils::AsNWSCreature(thisPtr);
    uint32_t nReduction = 0;
    if (pCreature)
    {
        int32_t nReductionFeat = Constants::Feat::MAX + 1;
        int32_t nEpicReductionFeat = Constants::Feat::MAX + 1;
        if (nFlags & Constants::DamageType::Cold)
        {
            nReductionFeat = Constants::Feat::ResistEnergy_Cold;
            nEpicReductionFeat = Constants::Feat::EpicEnergyResistance_Cold10;
        }
        else if (nFlags & Constants::DamageType::Acid)
        {
            nReductionFeat = Constants::Feat::ResistEnergy_Acid;
            nEpicReductionFeat = Constants::Feat::EpicEnergyResistance_Acid10;
        }
        else if (nFlags & Constants::DamageType::Fire)
        {
            nReductionFeat = Constants::Feat::ResistEnergy_Fire;
            nEpicReductionFeat = Constants::Feat::EpicEnergyResistance_Fire10;
        }
        else if (nFlags & Constants::DamageType::Electrical)
        {
            nReductionFeat = Constants::Feat::ResistEnergy_Electrical;
            nEpicReductionFeat = Constants::Feat::EpicEnergyResistance_Electrical10;
        }
        else if (nFlags & Constants::DamageType::Sonic)
        {
            nReductionFeat = Constants::Feat::ResistEnergy_Sonic;
            nEpicReductionFeat = Constants::Feat::EpicEnergyResistance_Sonic10;
        }
        if (nReductionFeat != Constants::Feat::MAX + 1)
        {
            if (pCreature->m_pStats->HasFeat(nReductionFeat))
                nReduction = Globals::Rules()->GetRulesetIntEntry("RESISTANCE_TO_ENERGY", 5);
            for (int i = 10, baseFeat = nEpicReductionFeat - 10; i > 0; i--)
            {
                if (pCreature->m_pStats->HasFeat(baseFeat + i))
                {
                    auto nFeatReduction = Globals::Rules()->GetRulesetIntEntry("EPIC_ENERGY_RESISTANCE_AMOUNT_10", i * 10);
                    if (nReduction < nFeatReduction)
                        nReduction = nFeatReduction;
                    break;
                }
            }
        }
        if (nReduction > 0)
        {
            if (nReduction > nDamage)
                nReduction = nDamage;
            nDamage -= nReduction;

            if (!bSimulate)
            {
                auto pMessage = std::make_unique<CNWCCMessageData>();
                pMessage->SetObjectID(0, thisPtr->m_idSelf);
                if (bCombatDamage && pAttacker)
                {
                    pMessage->SetInteger(0, 0x3f);
                    pMessage->SetInteger(1, nReduction);
                    auto pAttack = pAttacker->m_pcCombatRound->GetAttack(pAttacker->m_pcCombatRound->m_nCurrentAttack);
                    pAttack->m_alstPendingFeedback.Add(pMessage.release());
                }
                else
                {
                    auto pMessage2 = std::make_unique<CNWCCMessageData>();
                    pMessage->SetInteger(1, nReduction);
                    pMessage->CopyTo(pMessage2.get());
                    if (pCreature)
                        pCreature->SendFeedbackMessage(0x3f, pMessage.release(), 0);
                    if (pAttacker)
                        pAttacker->SendFeedbackMessage(0x3f, pMessage2.release(), 0);
                }
            }
        }
    }

    if (nDamage < 1)
        return 0;

    int32_t nFoundEffectPtr = -1;
    if (thisPtr->m_appliedEffects.num)
    {
        int32_t nReductionEffectPtr = 0;
        auto nNumDamageTypes = !!(nFlags & Constants::DamageType::Bludgeoning) + !!(nFlags & Constants::DamageType::Piercing) + !!(nFlags & Constants::DamageType::Slashing);
        nReduction = 0;
        if (!bBaseDamage || nNumDamageTypes < 2)
        {
            nReductionEffectPtr = 0;
            if (pCreature)
                nReductionEffectPtr = pCreature->m_pStats->m_nDamageResistancePtr;
            if (nReductionEffectPtr < thisPtr->m_appliedEffects.num)
            {
                CGameEffect* pEffect = nullptr;
                for (;
                    nReductionEffectPtr < thisPtr->m_appliedEffects.num
                    && (pEffect = thisPtr->m_appliedEffects.element[nReductionEffectPtr],
                        pEffect->m_nType <= Constants::EffectTrueType::DamageResistance);
                    nReductionEffectPtr++)
                {
                    if (pEffect->m_nType == Constants::EffectTrueType::DamageResistance)
                    {
                        auto nEffectFlags = pEffect->GetInteger(0);
                        auto nEffectReduction = pEffect->GetInteger(1);

                        auto nRemaining = pEffect->GetInteger(2);
                        if (nRemaining > 0)
                            nEffectReduction = std::min(nEffectReduction, nRemaining);

                        if ((nEffectFlags & nFlags) && nReduction < nEffectReduction)
                        {
                            nFoundEffectPtr = nReductionEffectPtr;
                            nReduction = nEffectReduction;
                        }
                    }
                }
            }
        }
        else
        {
            nReduction = ~0u;
            int32_t nBestIndex = -1;
            uint32_t nFoundReduction = 0;
            if (nFlags & Constants::DamageType::Bludgeoning)
                nReduction = thisPtr->GetMaximumDamageResistanceVsDamageFlag(Constants::DamageType::Bludgeoning, &nFoundEffectPtr);
            if (nFlags & Constants::DamageType::Piercing)
            {
                nFoundReduction = thisPtr->GetMaximumDamageResistanceVsDamageFlag(Constants::DamageType::Piercing, &nBestIndex);
                if (nReduction > nFoundReduction)
                {
                    nReduction = nFoundReduction;
                    nFoundEffectPtr = nBestIndex;
                }
            }
            if (nFlags & Constants::DamageType::Slashing)
            {
                nFoundReduction = thisPtr->GetMaximumDamageResistanceVsDamageFlag(Constants::DamageType::Slashing, &nBestIndex);
                if (nReduction > nFoundReduction)
                {
                    nReduction = nFoundReduction;
                    nFoundEffectPtr = nBestIndex;
                }
            }
            if (nReduction == ~0u)
                nReduction = 0;
        }

        if (bBaseDamage && nFlags & Constants::DamageType::Physical)
        {
            // Find custom material resistances
            CGameEffect* pEffect = nullptr;
            nReductionEffectPtr = 0;
            if (pCreature)
                nReductionEffectPtr = pCreature->m_pStats->m_nDamageResistancePtr;
            for (; nReductionEffectPtr < thisPtr->m_appliedEffects.num
                && (pEffect = thisPtr->m_appliedEffects.element[nReductionEffectPtr],
                    pEffect->m_nType <= Constants::EffectTrueType::DamageResistance);
                nReductionEffectPtr++)
            {
                if (pEffect->m_nType == Constants::EffectTrueType::DamageResistance
                    && pEffect->m_nNumIntegers > 3)
                {
                    auto nEffectFlags = pEffect->GetInteger(0);
                    if (!nEffectFlags)
                    {
                        auto nEffectReduction = pEffect->GetInteger(1);
                        auto nRemaining = pEffect->GetInteger(2);
                        if (nRemaining > 0)
                            nEffectReduction = std::min(nEffectReduction, nRemaining);

                        if (nReduction < nEffectReduction)
                        {
                            auto nMaterial = s_damageToMaterialMap[pEffect->GetInteger(3)];
                            bool bMaterialFound = !nMaterial || std::find(s_currentWeaponMaterials.begin(),
                                s_currentWeaponMaterials.end(), nMaterial) != s_currentWeaponMaterials.end();
                            if (!bMaterialFound)
                            {
                                nFoundEffectPtr = nReductionEffectPtr;
                                nReduction = nEffectReduction;
                            }
                        }
                    }
                }
            }
        }
    }

    if (nFlags & Constants::DamageType::Physical)
    {
        uint32_t nHardness = 0;
        if (auto* pDoor = Utils::AsNWSDoor(thisPtr))
        {
            nHardness = pDoor->m_nHardness;
        }
        else if (auto* pPlaceable = Utils::AsNWSPlaceable(thisPtr))
        {
            nHardness = pPlaceable->m_nHardness;
        }

        if (nHardness >= nReduction)
        {
            nReduction = nHardness;
            nFoundEffectPtr = -1;
        }
    }

    if (nReduction < 1)
        return nDamage;

    nReduction = std::min(nReduction, static_cast<uint32_t>(nDamage));

    if (bSimulate)
        return nDamage - nReduction;

    uint32_t nRemainingEffect = 0;
    if (nFoundEffectPtr >= 0)
    {
        auto* pEffect = thisPtr->m_appliedEffects.element[nFoundEffectPtr];
        nRemainingEffect = pEffect->GetInteger(2);
        if (nRemainingEffect > 0)
        {
            if (nReduction < nRemainingEffect)
                pEffect->SetInteger(2, nRemainingEffect - nReduction);
            else
                thisPtr->RemoveEffectById(pEffect->m_nID);
        }
    }

    auto pMessage = std::make_unique<CNWCCMessageData>();
    pMessage->SetObjectID(0, thisPtr->m_idSelf);

    if (!nRemainingEffect)
    {
        pMessage->SetInteger(1, nReduction);
    }
    else
    {
        pMessage->SetInteger(1, nReduction);
        pMessage->SetInteger(2, nRemainingEffect - nReduction);
    }
    if (bCombatDamage && pAttacker)
    {
        if (!nRemainingEffect)
            pMessage->SetInteger(0, 0x3f);
        else
            pMessage->SetInteger(0, 0x42);
        auto pAttack = pAttacker->m_pcCombatRound->GetAttack(pAttacker->m_pcCombatRound->m_nCurrentAttack);
        pAttack->m_alstPendingFeedback.Add(pMessage.release());
    }
    else
    {
        auto pMessage2 = std::make_unique<CNWCCMessageData>();
        pMessage->CopyTo(pMessage2.get());
        if (pCreature)
            pCreature->SendFeedbackMessage(0x3f, pMessage.release(), 0);
        if (pAttacker)
            pAttacker->SendFeedbackMessage(0x3f, pMessage2.release(), 0);
    }
    return nDamage - nReduction;
}

int32_t CNWSObject__DoDamageReduction(CNWSObject* thisPtr, CNWSCreature* pAttacker, int32_t nDamage,
    unsigned char nDamagePower, int32_t bSimulate, int32_t bCombatDamage)
{

    auto pCreature = Utils::AsNWSCreature(thisPtr);

    int nHighestReductionPower = 0;
    uint16_t nReductionEffectPos = static_cast<uint16_t>(-1u);
    int nFeatReduction = 0;
    int nReduction = 0;

    for (uint16_t i = pCreature ? pCreature->m_pStats->m_nDamageReductionPtr : 0;
        i < thisPtr->m_appliedEffects.num
        && thisPtr->m_appliedEffects.element[i]->m_nType <= Constants::EffectTrueType::DamageReduction;
        i++)
    {
        if (thisPtr->m_appliedEffects.element[i]->m_nType == Constants::EffectTrueType::DamageReduction)
        {
            auto pEffect = thisPtr->m_appliedEffects.element[i];
            auto nReductionAmount = pEffect->GetInteger(0);

            auto nRemaining = pEffect->GetInteger(2);
            if (nRemaining > 0)
                nReductionAmount = std::min(nReductionAmount, nRemaining);

            auto nReductionPower = pEffect->GetInteger(1);
            if (nReductionPower > nDamagePower && nReduction < nReductionAmount)
            {
                nReduction = nReductionAmount;
                nHighestReductionPower = nReductionPower;
                nReductionEffectPos = i;
            }
        }
    }

    int32_t nHighestReductionMaterial = -1;
    for (uint16_t i = pCreature ? pCreature->m_pStats->m_nDamageReductionPtr : 0;
        i < thisPtr->m_appliedEffects.num
        && thisPtr->m_appliedEffects.element[i]->m_nType <= Constants::EffectTrueType::DamageReduction;
        i++)
    {
        CGameEffect* pEffect = thisPtr->m_appliedEffects.element[i];
        if (pEffect->m_nType == Constants::EffectTrueType::DamageReduction
            && pEffect->m_nNumIntegers > 3 && !pEffect->GetInteger(1))
        {
            auto nReductionAmount = pEffect->GetInteger(0);

            auto nRemaining = pEffect->GetInteger(2);
            if (nRemaining > 0)
                nReductionAmount = std::min(nReductionAmount, nRemaining);

            if (nReduction < nReductionAmount)
            {
                auto nMaterial = s_reductionToMaterialMap[pEffect->GetInteger(3)];
                bool bMaterialFound = !nMaterial || std::find(s_currentWeaponMaterials.begin(),
                    s_currentWeaponMaterials.end(), nMaterial) != s_currentWeaponMaterials.end();
                if (!bMaterialFound)
                {
                    //bSendCustomMessage = nFlags > Constants::DamageType::Physical && nFlags <= Constants::DamageType::Positive;
                    nReductionEffectPos = i;
                    nReduction = nReductionAmount;
                    nHighestReductionMaterial = nMaterial;
                }
            }
        }
    }

    if (pCreature)
    {
        if (pCreature->m_pStats->HasFeat(Constants::Feat::EpicBarbarianDamageReduction))
        {
            int nBarbarianLevel = pCreature->m_pStats->GetNumLevelsOfClass(Constants::ClassType::Barbarian);
            nFeatReduction = Globals::Rules()->GetRulesetIntEntry("EPIC_BARBARIAN_DAMAGE_REDUCTION", 5);
            if (nBarbarianLevel > 25)
            {
                nFeatReduction = std::floor((nBarbarianLevel - 23) / 3.0f) + nFeatReduction;
                if (nFeatReduction < 1)
                    nFeatReduction = 0;
            }
        }
        else if (pCreature->m_pStats->HasFeat(Constants::Feat::DamageReduction4))
        {
            nFeatReduction = Globals::Rules()->GetRulesetIntEntry("BARBARIAN_DAMAGE_REDUCTION_LEVEL_4", 4);
        }
        else if (pCreature->m_pStats->HasFeat(Constants::Feat::DamageReduction3))
        {
            nFeatReduction = Globals::Rules()->GetRulesetIntEntry("BARBARIAN_DAMAGE_REDUCTION_LEVEL_3", 3);
        }
        else if (pCreature->m_pStats->HasFeat(Constants::Feat::DamageReduction2))
        {
            nFeatReduction = Globals::Rules()->GetRulesetIntEntry("BARBARIAN_DAMAGE_REDUCTION_LEVEL_2", 2);
        }
        else if (pCreature->m_pStats->HasFeat(Constants::Feat::DamageReduction))
        {
            nFeatReduction = Globals::Rules()->GetRulesetIntEntry("BARBARIAN_DAMAGE_REDUCTION_LEVEL_1", 1);
        }

        if (pCreature->m_pStats->HasFeat(Constants::Feat::DamageReduction6))
        {
            auto nDefenderLevels = pCreature->m_pStats->GetNumLevelsOfClass(Constants::ClassType::DwarvenDefender);
            auto nDefenderReduction = Globals::Rules()->GetRulesetIntEntry("DWARVEN_DEFENDER_DAMAGE_REDUCTION", 3);
            nFeatReduction += nDefenderReduction;
            if (nDefenderLevels > 9)
                nFeatReduction += ((nDefenderLevels - 6) >> 2) * 3; //((Level - 6) / 4) * 3
        }

        if (pCreature->m_pStats->HasFeat(Constants::Feat::PerfectSelf))
        {
            auto nPerfectSelfReduction = Globals::Rules()->GetRulesetIntEntry("PERFECT_SELF_DAMAGE_REDUCTION", 20);
            auto nPerfectSelfReductionPower = Globals::Rules()->GetRulesetIntEntry("PERFECT_SELF_DAMAGE_REDUCTION_POWER", 1);
            if (nDamagePower < nPerfectSelfReductionPower && nFeatReduction < nPerfectSelfReduction)
            {
                nFeatReduction = nPerfectSelfReduction;
            }
        }

        if (pCreature->m_pStats->HasFeat(Constants::Feat::EpicDamageReduction9))
        {
            nFeatReduction += Globals::Rules()->GetRulesetIntEntry("EPIC_DAMAGE_REDUCTION_9", 9);
        }
        else if (pCreature->m_pStats->HasFeat(Constants::Feat::EpicDamageReduction6))
        {
            nFeatReduction += Globals::Rules()->GetRulesetIntEntry("EPIC_DAMAGE_REDUCTION_6", 6);
        }
        else if (pCreature->m_pStats->HasFeat(Constants::Feat::EpicDamageReduction3))
        {
            nFeatReduction += Globals::Rules()->GetRulesetIntEntry("EPIC_DAMAGE_REDUCTION_3", 3);
        }

        if (nFeatReduction > 0 && nFeatReduction >= nReduction)
        {
            int nReducedAmount = nFeatReduction < nDamage ? nFeatReduction : nDamage;
            nDamage -= nFeatReduction;

            if (!bSimulate)
            {
                auto pMessage = new CNWCCMessageData();
                pMessage->SetObjectID(0, thisPtr->m_idSelf);
                pMessage->SetInteger(1, nReducedAmount);

                if (bCombatDamage && pAttacker)
                {
                    pMessage->SetInteger(0, 0x40);
                    auto pAttack = pAttacker->m_pcCombatRound->GetAttack(pAttacker->m_pcCombatRound->m_nCurrentAttack);
                    pAttack->m_alstPendingFeedback.Add(pMessage);

                    return nDamage;
                }

                auto pMessage2 = new CNWCCMessageData();
                pMessage->CopyTo(pMessage2);

                if (pCreature)
                    pCreature->SendFeedbackMessage(0x40, pMessage, 0);
                else
                    delete pMessage;
                if (pAttacker)
                    pAttacker->SendFeedbackMessage(0x40, pMessage2, 0);
                else
                    delete pMessage2;

                return nDamage;
            }

            return nDamage;
        }
    }

    if (!nReduction)
        return nDamage;

    nReduction = std::min(nReduction, nDamage);

    int nRemainingEffectReduction = pCreature->m_appliedEffects.element[nReductionEffectPos]->GetInteger(2);
    if (!nRemainingEffectReduction && bSimulate)
        return nDamage - nReduction;

    // Update remaining reduction amount on spell effects
    if (nRemainingEffectReduction)
    {
        if (nReduction >= nRemainingEffectReduction)
        {
            nReduction = nRemainingEffectReduction;
            if (!bSimulate)
                thisPtr->RemoveEffectById(pCreature->m_appliedEffects.element[nReductionEffectPos]->m_nID);
        }
        else if (!bSimulate)
        {
            auto* pEffect = pCreature->m_appliedEffects.element[nReductionEffectPos];
            pEffect->SetInteger(2, nRemainingEffectReduction - nReduction);
        }
    }
    nDamage = nDamage - nReduction;

    if (bSimulate)
        return nDamage;

    // Feedback
    if (bCombatDamage && pAttacker)
    {
        auto pMessage = std::make_unique<CNWCCMessageData>();
        pMessage->SetObjectID(0, thisPtr->m_idSelf);
        if (!nRemainingEffectReduction)
        {
            pMessage->SetInteger(0, 0x40);
            pMessage->SetInteger(1, nReduction);
        }
        else
        {
            pMessage->SetInteger(0, 0x43);

            if (nRemainingEffectReduction <= nReduction)
            {
                pMessage->SetInteger(1, nRemainingEffectReduction);
                pMessage->SetInteger(2, 0);
            }
            else
            {
                pMessage->SetInteger(1, nReduction);
                pMessage->SetInteger(2, nRemainingEffectReduction - nReduction);
            }
        }
        auto pAttack = pAttacker->m_pcCombatRound->GetAttack(pAttacker->m_pcCombatRound->m_nCurrentAttack);
        pAttack->m_alstPendingFeedback.Add(pMessage.release());
    }
    else
    {
        auto pMessage = std::make_unique<CNWCCMessageData>();
        auto pMessage2 = std::make_unique<CNWCCMessageData>();
        pMessage->SetObjectID(0, thisPtr->m_idSelf);

        if (nRemainingEffectReduction == 0)
        {
            pMessage->SetInteger(1, nReduction);
            pMessage->CopyTo(pMessage2.get());

            if (pCreature)
                pCreature->SendFeedbackMessage(0x40, pMessage.release(), 0);

            if (pAttacker)
                pAttacker->SendFeedbackMessage(0x40, pMessage2.release(), 0);
        }
        else
        {
            if (nRemainingEffectReduction <= nReduction)
            {
                pMessage->SetInteger(1, nRemainingEffectReduction);
                pMessage->SetInteger(2, 0);
            }
            else
            {
                pMessage->SetInteger(1, nReduction);
                pMessage->SetInteger(2, nRemainingEffectReduction - nReduction);
            }
            pMessage->CopyTo(pMessage2.get());

            if (pCreature)
                pCreature->SendFeedbackMessage(0x43, pMessage.release(), 0);

            if (pAttacker)
                pAttacker->SendFeedbackMessage(0x43, pMessage2.release(), 0);
        }
    }

    return nDamage;
}

int32_t CNWSItemPropertyHandler__ApplyDamageResistance(void*, CNWSItem* pItem, CNWItemProperty* pProperty, CNWSCreature* pCreature,
    BOOL, BOOL bLoadingGame)
{
    CGameEffect* pEffect = new CGameEffect(1);
    pEffect->m_nType = 2;
    pEffect->m_nSubType = 3;
    pEffect->SetCreator(pItem->m_idSelf);
    auto* p2DA = Globals::Rules()->m_p2DArrays->GetIPRPCostTable(7);
    int32_t nReductionAmount = 0;
    p2DA->GetINTEntry(pProperty->m_nCostTableValue, "Amount", &nReductionAmount);
    auto nSubType = pProperty->m_nSubType;

    if (nSubType > 12)
    {
        // Custom damage types
        pEffect->SetInteger(0, 0);
        pEffect->SetInteger(3, nSubType);
    }
    else
    {
        // Regular damage types
        if (nSubType > 2)
            nSubType -= 2;
        pEffect->SetInteger(0, 1 << nSubType);
    }

    pEffect->SetInteger(1, nReductionAmount);
    pCreature->ApplyEffect(pEffect, bLoadingGame);

    return 0;
}

int32_t CNWSItemPropertyHandler__ApplyDamageReduction(void*, CNWSItem* pItem, CNWItemProperty* pProperty, CNWSCreature* pCreature,
    BOOL, BOOL bLoadingGame)
{
    CGameEffect* pEffect = new CGameEffect(1);
    pEffect->m_nType = 12;
    pEffect->m_nSubType = 3;
    pEffect->SetCreator(pItem->m_idSelf);
    auto* p2DA = Globals::Rules()->m_p2DArrays->GetIPRPCostTable(6);
    int32_t nReductionAmount = 0;
    p2DA->GetINTEntry(pProperty->m_nCostTableValue, "Amount", &nReductionAmount);
    auto nSubType = pProperty->m_nSubType;

    if (nSubType > 19)
    {
        // Custom reductions
        pEffect->SetInteger(0, nReductionAmount);
        pEffect->SetInteger(1, 0);
        pEffect->SetInteger(3, nSubType);
    }
    else
    {
        // +X reductions
        pEffect->SetInteger(0, nReductionAmount);
        pEffect->SetInteger(1, nSubType + 1);
    }

    pCreature->ApplyEffect(pEffect, bLoadingGame);

    return 0;
}
