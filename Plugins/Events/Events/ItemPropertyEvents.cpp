#include "Events.hpp"
#include "API/CNWSItemPropertyHandler.hpp"
#include "API/CNWSCreature.hpp"
#include "API/CNWSInventory.hpp"
#include "API/CNWSItem.hpp"
#include "API/CNWItemProperty.hpp"
#include "API/CGameEffect.hpp"

namespace Events {

using namespace NWNXLib;
using namespace NWNXLib::API;

static NWNXLib::Hooks::Hook s_OnItemPropertyAppliedHook;
static NWNXLib::Hooks::Hook s_OnItemPropertyRemovedHook;

static int32_t OnItemPropertyAppliedHook(CNWSItemPropertyHandler*, CNWSItem*, CNWItemProperty*, CNWSCreature*, uint32_t, BOOL);
static int32_t OnItemPropertyRemovedHook(CNWSItemPropertyHandler*, CNWSItem*, CNWItemProperty*, CNWSCreature*, uint32_t);

void ItemPropertyEvents() __attribute__((constructor));
void ItemPropertyEvents()
{
    ForceEnableWhitelist("NWNX_ON_ITEMPROPERTY_EFFECT");
    InitOnFirstSubscribe("NWNX_ON_ITEMPROPERTY_EFFECT_(APPLIED|REMOVED)_.*", []() {
        s_OnItemPropertyAppliedHook = NWNXLib::Hooks::HookFunction(
            Functions::_ZN23CNWSItemPropertyHandler21OnItemPropertyAppliedEP8CNWSItemP15CNWItemPropertyP12CNWSCreatureji,
            &OnItemPropertyAppliedHook, NWNXLib::Hooks::Order::Latest);
        s_OnItemPropertyRemovedHook = NWNXLib::Hooks::HookFunction(
                Functions::_ZN23CNWSItemPropertyHandler21OnItemPropertyRemovedEP8CNWSItemP15CNWItemPropertyP12CNWSCreaturej,
                &OnItemPropertyRemovedHook, NWNXLib::Hooks::Order::Latest);
    });
}

static int32_t ApplyOriginalItemPropertyEffects(CNWSItemPropertyHandler* pThis, uint16_t nType, CNWSItem *pItem, CNWItemProperty *pItemProperty, CNWSCreature *pCreature, uint32_t nInventorySlot, BOOL bLoadingGame)
{
    switch (nType)
    {
        case Constants::ItemProperty::AbilityBonus:
            return pThis->ApplyAbilityBonus(pItem, pItemProperty, pCreature, nInventorySlot, bLoadingGame);
        case Constants::ItemProperty::ACBonus:
        case Constants::ItemProperty::ACBonusVSAlignmentGroup:
        case Constants::ItemProperty::ACBonusVSDamageType:
        case Constants::ItemProperty::ACBonusVSRacialGroup:
        case Constants::ItemProperty::ACBonusVSSpecificAlignment:
            return pThis->ApplyACBonus(pItem, pItemProperty, pCreature, nInventorySlot, bLoadingGame);
        case Constants::ItemProperty::EnhancementBonus:
        case Constants::ItemProperty::EnhancementBonusVSAlignmentGroup:
        case Constants::ItemProperty::EnhancementBonusVSRacialGroup:
        case Constants::ItemProperty::EnhancementBonusVSSpecificAlignment:
            return pThis->ApplyEnhancementBonus(pItem, pItemProperty, pCreature, nInventorySlot, bLoadingGame);
        case Constants::ItemProperty::DecreasedEnhancementModifier:
            return pThis->ApplyEnhancementPenalty(pItem, pItemProperty, pCreature, nInventorySlot, bLoadingGame);
        case Constants::ItemProperty::BonusFeat:
            return pThis->ApplyBonusFeat(pItem, pItemProperty, pCreature, nInventorySlot, bLoadingGame);
        case Constants::ItemProperty::BonusSpellSlot:
            return pThis->ApplyBonusSpellOfLevel(pItem, pItemProperty, pCreature, nInventorySlot, bLoadingGame);
        case Constants::ItemProperty::DamageBonus:
        case Constants::ItemProperty::DamageBonusVSAlignmentGroup:
        case Constants::ItemProperty::DamageBonusVSRacialGroup:
        case Constants::ItemProperty::DamageBonusVSSpecificAlignment:
            return pThis->ApplyDamageBonus(pItem, pItemProperty, pCreature, nInventorySlot, bLoadingGame);
        case Constants::ItemProperty::ImmunityDamageType:
            return pThis->ApplyDamageImmunity(pItem, pItemProperty, pCreature, nInventorySlot, bLoadingGame);
        case Constants::ItemProperty::DecreasedDamage:
            return pThis->ApplyDamagePenalty(pItem, pItemProperty, pCreature, nInventorySlot, bLoadingGame);
        case Constants::ItemProperty::DamageReduction:
            return pThis->ApplyDamageReduction(pItem, pItemProperty, pCreature, nInventorySlot, bLoadingGame);
        case Constants::ItemProperty::DamageResistance:
            return pThis->ApplyDamageResistance(pItem, pItemProperty, pCreature, nInventorySlot, bLoadingGame);
        case Constants::ItemProperty::DamageVulnerability:
            return pThis->ApplyDamageVulnerability(pItem, pItemProperty, pCreature, nInventorySlot, bLoadingGame);
        case Constants::ItemProperty::Darkvision:
            return pThis->ApplyDarkVision(pItem, pItemProperty, pCreature, nInventorySlot, bLoadingGame);
        case Constants::ItemProperty::DecreasedAbilityScore:
            return pThis->ApplyDecreaseAbility(pItem, pItemProperty, pCreature, nInventorySlot, bLoadingGame);
        case Constants::ItemProperty::DecreasedAC:
            return pThis->ApplyDecreaseAC(pItem, pItemProperty, pCreature, nInventorySlot, bLoadingGame);
        case Constants::ItemProperty::DecreasedSkillModifier:
            return pThis->ApplyDecreaseSkill(pItem, pItemProperty, pCreature, nInventorySlot, bLoadingGame);
        case Constants::ItemProperty::Haste:
            return pThis->ApplyHaste(pItem, pItemProperty, pCreature, nInventorySlot, bLoadingGame);
        case Constants::ItemProperty::HolyAvenger:
            return pThis->ApplyHolyAvenger(pItem, pItemProperty, pCreature, nInventorySlot, bLoadingGame);
        case Constants::ItemProperty::ImmunityMiscellaneous:
            return pThis->ApplyImmunity(pItem, pItemProperty, pCreature, nInventorySlot, bLoadingGame);
        case Constants::ItemProperty::ImprovedEvasion:
            return pThis->ApplyImprovedEvasion(pItem, pItemProperty, pCreature, nInventorySlot, bLoadingGame);
        case Constants::ItemProperty::SpellResistance:
            return pThis->ApplyImprovedSpellResistance(pItem, pItemProperty, pCreature, nInventorySlot, bLoadingGame);
        case Constants::ItemProperty::SavingThrowBonusSpecific:
            return pThis->ApplyImprovedSavingThrow(pItem, pItemProperty, pCreature, nInventorySlot, bLoadingGame);
        case Constants::ItemProperty::SavingThrowBonus:
            return pThis->ApplyImprovedSavingThrowVsX(pItem, pItemProperty, pCreature, nInventorySlot, bLoadingGame);
        case Constants::ItemProperty::Light:
            return pThis->ApplyLight(pItem, pItemProperty, pCreature, nInventorySlot, bLoadingGame);
        case Constants::ItemProperty::DecreasedSavingThrowsSpecific:
            return pThis->ApplyReducedSavingThrow(pItem, pItemProperty, pCreature, nInventorySlot, bLoadingGame);
        case Constants::ItemProperty::DecreasedSavingThrows:
            return pThis->ApplyReducedSavingThrowVsX(pItem, pItemProperty, pCreature, nInventorySlot, bLoadingGame);
        case Constants::ItemProperty::Regeneration:
            return pThis->ApplyRegeneration(pItem, pItemProperty, pCreature, nInventorySlot, bLoadingGame);
        case Constants::ItemProperty::SkillBonus:
            return pThis->ApplySkillBonus(pItem, pItemProperty, pCreature, nInventorySlot, bLoadingGame);
        case Constants::ItemProperty::ImmunitySpecificSpell:
            return pThis->ApplySpellImmunitySpecific(pItem, pItemProperty, pCreature, nInventorySlot, bLoadingGame);
        case Constants::ItemProperty::ImmunitySpellSchool:
            return pThis->ApplySpellImmunitySchool(pItem, pItemProperty, pCreature, nInventorySlot, bLoadingGame);
        case Constants::ItemProperty::AttackBonus:
        case Constants::ItemProperty::AttackBonusVSAlignmentGroup:
        case Constants::ItemProperty::AttackBonusVSRacialGroup:
        case Constants::ItemProperty::AttackBonusVSSpecificAlignment:
            return pThis->ApplyAttackBonus(pItem, pItemProperty, pCreature, nInventorySlot, bLoadingGame);
        case Constants::ItemProperty::DecreasedAttackModifier:
            return pThis->ApplyAttackPenalty(pItem, pItemProperty, pCreature, nInventorySlot, bLoadingGame);
        case Constants::ItemProperty::UnlimitedAmmunition:
            return pThis->ApplyUnlimitedAmmo(pItem, pItemProperty, pCreature, nInventorySlot, bLoadingGame);
        case Constants::ItemProperty::TrueSeeing:
            return pThis->ApplyTrueSeeing(pItem, pItemProperty, pCreature, nInventorySlot, bLoadingGame);
        case Constants::ItemProperty::TurnResistance:
            return pThis->ApplyTurnResistance(pItem, pItemProperty, pCreature, nInventorySlot, bLoadingGame);
        case Constants::ItemProperty::FreedomOfMovement:
            return pThis->ApplyFreeAction(pItem, pItemProperty, pCreature, nInventorySlot, bLoadingGame);
        case Constants::ItemProperty::ImmunitySpellsByLevel:
            return pThis->ApplySpellImmunityLevel(pItem, pItemProperty, pCreature, nInventorySlot, bLoadingGame);
        case Constants::ItemProperty::SpecialWalk:
            return pThis->ApplySpecialWalk(pItem, pItemProperty, pCreature, nInventorySlot, bLoadingGame);
        case Constants::ItemProperty::ArcaneSpellFailure:
            return pThis->ApplyArcaneSpellFailure(pItem, pItemProperty, pCreature, nInventorySlot, bLoadingGame);

        default:
            return 0;
    }
}

static int32_t RemoveOriginalItemPropertyEffects(CNWSItemPropertyHandler* pThis, uint16_t nType, CNWSItem *pItem, CNWItemProperty *pItemProperty, CNWSCreature *pCreature, uint32_t nInventorySlot)
{
    switch (nType)
    {
        case Constants::ItemProperty::BonusSpellSlot:
            return pThis->RemoveBonusSpellOfLevel(pItem, pItemProperty, pCreature, nInventorySlot);
        case Constants::ItemProperty::UnlimitedAmmunition:
            return pThis->RemoveUnlimitedAmmo(pItem, pItemProperty, pCreature, nInventorySlot);

        default:
            return 0;
    }
}

static int32_t OnItemPropertyAppliedHook(CNWSItemPropertyHandler* pThis, CNWSItem *pItem, CNWItemProperty *pItemProperty, CNWSCreature *pCreature, uint32_t nInventorySlot, BOOL bLoadingGame)
{
    if (!pItemProperty)
        return 0;

    const uint16_t ipType = pItemProperty->m_nPropertyName;
    if (!IsIDInWhitelist("NWNX_ON_ITEMPROPERTY_EFFECT", ipType))
        return s_OnItemPropertyAppliedHook->CallOriginal<int32_t>(pThis, pItem, pItemProperty, pCreature, nInventorySlot, bLoadingGame);

    int32_t retVal = 0;
    std::vector<CGameEffect*> oldAppliedEffects(pCreature->m_appliedEffects.num);
    for (int32_t i = 0; i < pCreature->m_appliedEffects.num; i++)
        oldAppliedEffects.push_back(pCreature->m_appliedEffects[i]);

    auto PushAndSignal = [&](const std::string& ev) -> bool
    {
        PushEventData("CREATURE", Utils::ObjectIDToString(pCreature->m_idSelf));
        PushEventData("LOADING_GAME", std::to_string(bLoadingGame));
        PushEventData("INVENTORY_SLOT", std::to_string(pCreature->m_pInventory->GetArraySlotFromSlotFlag(nInventorySlot)));
        PushEventData("PROPERTY", std::to_string(ipType));
        PushEventData("SUBTYPE", std::to_string(pItemProperty->m_nSubType));
        PushEventData("TAG", pItemProperty->m_sCustomTag.CStr());
        PushEventData("COST_TABLE", std::to_string(pItemProperty->m_nCostTable));
        PushEventData("COST_TABLE_VALUE", std::to_string(pItemProperty->m_nCostTableValue));
        PushEventData("PARAM1", std::to_string(pItemProperty->m_nParam1));
        PushEventData("PARAM1_VALUE", std::to_string(pItemProperty->m_nParam1Value));
        return SignalEvent(ev, pItem->m_idSelf);
    };

    if (PushAndSignal("NWNX_ON_ITEMPROPERTY_EFFECT_APPLIED_BEFORE"))
    {
        retVal = ApplyOriginalItemPropertyEffects(pThis, ipType, pItem, pItemProperty, pCreature, nInventorySlot, bLoadingGame);
    }
    PushAndSignal("NWNX_ON_ITEMPROPERTY_EFFECT_APPLIED_AFTER");

    for (int32_t i = 0; i < pCreature->m_appliedEffects.num; i++)
    {
        CGameEffect *pEffect = pCreature->m_appliedEffects[i];
        if (std::find(oldAppliedEffects.begin(), oldAppliedEffects.end(), pEffect) == oldAppliedEffects.end())
        {
            if (pEffect->GetDurationType() != Constants::EffectDurationType::Innate)
            {
                if (pEffect->GetDurationType() != Constants::EffectDurationType::Equipped)
                    LOG_WARNING("NWNX_ON_ITEMPROPERTY_EFFECT_APPLIED_BEFORE applied an effect without DURATION_TYPE_EQUIPPED!");
                if (pEffect->m_oidCreator != pItem->m_idSelf)
                    LOG_WARNING("NWNX_ON_ITEMPROPERTY_EFFECT_APPLIED_BEFORE applied an effect without the item as creator!");

                pEffect->m_nItemPropertySourceId = pItemProperty->m_nID;
            }
        }
    }

    return retVal;
}

static int32_t OnItemPropertyRemovedHook(CNWSItemPropertyHandler* pThis, CNWSItem *pItem, CNWItemProperty *pItemProperty, CNWSCreature *pCreature, uint32_t nInventorySlot)
{
    if (!pItemProperty)
        return 0;

    const uint16_t ipType = pItemProperty->m_nPropertyName;
    if (!IsIDInWhitelist("NWNX_ON_ITEMPROPERTY_EFFECT", ipType))
        return s_OnItemPropertyRemovedHook->CallOriginal<int32_t>(pThis, pItem, pItemProperty, pCreature, nInventorySlot);

    int32_t retVal = 0;
    std::vector<uint64_t> effectsToRemove(64);
    for (int32_t i = 0; i < pCreature->m_appliedEffects.num; i++)
    {
        CGameEffect *pEffect = pCreature->m_appliedEffects[i];
        if (pEffect->m_nItemPropertySourceId == pItemProperty->m_nID)
            effectsToRemove.emplace_back(pEffect->m_nID);
    }
    for (auto id: effectsToRemove)
        pCreature->RemoveEffectById(id);

    auto PushAndSignal = [&](const std::string& ev) -> bool
    {
        PushEventData("CREATURE", Utils::ObjectIDToString(pCreature->m_idSelf));
        PushEventData("LOADING_GAME", "0");
        PushEventData("INVENTORY_SLOT", std::to_string(pCreature->m_pInventory->GetArraySlotFromSlotFlag(nInventorySlot)));
        PushEventData("PROPERTY", std::to_string(ipType));
        PushEventData("SUBTYPE", std::to_string(pItemProperty->m_nSubType));
        PushEventData("TAG", pItemProperty->m_sCustomTag.CStr());
        PushEventData("COST_TABLE", std::to_string(pItemProperty->m_nCostTable));
        PushEventData("COST_TABLE_VALUE", std::to_string(pItemProperty->m_nCostTableValue));
        PushEventData("PARAM1", std::to_string(pItemProperty->m_nParam1));
        PushEventData("PARAM1_VALUE", std::to_string(pItemProperty->m_nParam1Value));
        return SignalEvent(ev, pItem->m_idSelf);
    };

    if (PushAndSignal("NWNX_ON_ITEMPROPERTY_EFFECT_REMOVED_BEFORE"))
    {
        retVal = RemoveOriginalItemPropertyEffects(pThis, ipType, pItem, pItemProperty, pCreature, nInventorySlot);
    }
    PushAndSignal("NWNX_ON_ITEMPROPERTY_EFFECT_REMOVED_AFTER");

    return retVal;
}

}
