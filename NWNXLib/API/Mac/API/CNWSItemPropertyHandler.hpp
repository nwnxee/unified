#pragma once

#include <cstdint>

#include "CItemPropertyApplierRemover.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CNWItemProperty;
struct CNWSCreature;
struct CNWSItem;
struct pfAIPCommands;
struct pfRIPCommands;

struct CNWSItemPropertyHandler
    : CItemPropertyApplierRemover
{
    pfAIPCommands* m_pApplyItemPropertyCommands;
    pfRIPCommands* m_pRemoveItemPropertyCommands;

    // The below are auto generated stubs.
    CNWSItemPropertyHandler() = default;
    CNWSItemPropertyHandler(const CNWSItemPropertyHandler&) = default;
    CNWSItemPropertyHandler& operator=(const CNWSItemPropertyHandler&) = default;

    ~CNWSItemPropertyHandler();
    int32_t ApplyAbilityBonus(CNWSItem*, CNWItemProperty*, CNWSCreature*, uint32_t, int32_t);
    int32_t ApplyACBonus(CNWSItem*, CNWItemProperty*, CNWSCreature*, uint32_t, int32_t);
    int32_t ApplyArcaneSpellFailure(CNWSItem*, CNWItemProperty*, CNWSCreature*, uint32_t, int32_t);
    int32_t ApplyAttackBonus(CNWSItem*, CNWItemProperty*, CNWSCreature*, uint32_t, int32_t);
    int32_t ApplyAttackPenalty(CNWSItem*, CNWItemProperty*, CNWSCreature*, uint32_t, int32_t);
    int32_t ApplyBonusFeat(CNWSItem*, CNWItemProperty*, CNWSCreature*, uint32_t, int32_t);
    int32_t ApplyBonusSpellOfLevel(CNWSItem*, CNWItemProperty*, CNWSCreature*, uint32_t, int32_t);
    int32_t ApplyChangedSavingThrow(CNWSItem*, int32_t, CNWItemProperty*, CNWSCreature*, int32_t);
    int32_t ApplyChangedSavingThrowVsX(CNWSItem*, int32_t, CNWItemProperty*, CNWSCreature*, int32_t);
    int32_t ApplyDamageBonus(CNWSItem*, CNWItemProperty*, CNWSCreature*, uint32_t, int32_t);
    int32_t ApplyDamageImmunity(CNWSItem*, CNWItemProperty*, CNWSCreature*, uint32_t, int32_t);
    int32_t ApplyDamagePenalty(CNWSItem*, CNWItemProperty*, CNWSCreature*, uint32_t, int32_t);
    int32_t ApplyDamageReduction(CNWSItem*, CNWItemProperty*, CNWSCreature*, uint32_t, int32_t);
    int32_t ApplyDamageResistance(CNWSItem*, CNWItemProperty*, CNWSCreature*, uint32_t, int32_t);
    int32_t ApplyDamageVulnerability(CNWSItem*, CNWItemProperty*, CNWSCreature*, uint32_t, int32_t);
    int32_t ApplyDarkVision(CNWSItem*, CNWItemProperty*, CNWSCreature*, uint32_t, int32_t);
    int32_t ApplyDecreaseAbility(CNWSItem*, CNWItemProperty*, CNWSCreature*, uint32_t, int32_t);
    int32_t ApplyDecreaseAC(CNWSItem*, CNWItemProperty*, CNWSCreature*, uint32_t, int32_t);
    int32_t ApplyDecreaseSkill(CNWSItem*, CNWItemProperty*, CNWSCreature*, uint32_t, int32_t);
    int32_t ApplyEnhancementBonus(CNWSItem*, CNWItemProperty*, CNWSCreature*, uint32_t, int32_t);
    int32_t ApplyEnhancementPenalty(CNWSItem*, CNWItemProperty*, CNWSCreature*, uint32_t, int32_t);
    int32_t ApplyFreeAction(CNWSItem*, CNWItemProperty*, CNWSCreature*, uint32_t, int32_t);
    int32_t ApplyHaste(CNWSItem*, CNWItemProperty*, CNWSCreature*, uint32_t, int32_t);
    int32_t ApplyHolyAvenger(CNWSItem*, CNWItemProperty*, CNWSCreature*, uint32_t, int32_t);
    int32_t ApplyImmunity(CNWSItem*, CNWItemProperty*, CNWSCreature*, uint32_t, int32_t);
    int32_t ApplyImprovedEvasion(CNWSItem*, CNWItemProperty*, CNWSCreature*, uint32_t, int32_t);
    int32_t ApplyImprovedSavingThrow(CNWSItem*, CNWItemProperty*, CNWSCreature*, uint32_t, int32_t);
    int32_t ApplyImprovedSavingThrowVsX(CNWSItem*, CNWItemProperty*, CNWSCreature*, uint32_t, int32_t);
    int32_t ApplyImprovedSpellResistance(CNWSItem*, CNWItemProperty*, CNWSCreature*, uint32_t, int32_t);
    int32_t ApplyLight(CNWSItem*, CNWItemProperty*, CNWSCreature*, uint32_t, int32_t);
    int32_t ApplyReducedSavingThrow(CNWSItem*, CNWItemProperty*, CNWSCreature*, uint32_t, int32_t);
    int32_t ApplyReducedSavingThrowVsX(CNWSItem*, CNWItemProperty*, CNWSCreature*, uint32_t, int32_t);
    int32_t ApplyRegeneration(CNWSItem*, CNWItemProperty*, CNWSCreature*, uint32_t, int32_t);
    int32_t ApplySkillBonus(CNWSItem*, CNWItemProperty*, CNWSCreature*, uint32_t, int32_t);
    int32_t ApplySpecialWalk(CNWSItem*, CNWItemProperty*, CNWSCreature*, uint32_t, int32_t);
    int32_t ApplySpellImmunityLevel(CNWSItem*, CNWItemProperty*, CNWSCreature*, uint32_t, int32_t);
    int32_t ApplySpellImmunitySchool(CNWSItem*, CNWItemProperty*, CNWSCreature*, uint32_t, int32_t);
    int32_t ApplySpellImmunitySpecific(CNWSItem*, CNWItemProperty*, CNWSCreature*, uint32_t, int32_t);
    int32_t ApplyTrueSeeing(CNWSItem*, CNWItemProperty*, CNWSCreature*, uint32_t, int32_t);
    int32_t ApplyTurnResistance(CNWSItem*, CNWItemProperty*, CNWSCreature*, uint32_t, int32_t);
    int32_t ApplyUnlimitedAmmo(CNWSItem*, CNWItemProperty*, CNWSCreature*, uint32_t, int32_t);
    void InitializeItemProperties();
    int32_t OnItemPropertyApplied(CNWSItem*, CNWItemProperty*, CNWSCreature*, uint32_t, int32_t);
    int32_t OnItemPropertyRemoved(CNWSItem*, CNWItemProperty*, CNWSCreature*, uint32_t);
    int32_t RemoveBonusSpellOfLevel(CNWSItem*, CNWItemProperty*, CNWSCreature*, uint32_t);
    int32_t RemoveUnlimitedAmmo(CNWSItem*, CNWItemProperty*, CNWSCreature*, uint32_t);
};

void CNWSItemPropertyHandler__CNWSItemPropertyHandlerDtor__0(CNWSItemPropertyHandler* thisPtr);
int32_t CNWSItemPropertyHandler__ApplyAbilityBonus(CNWSItemPropertyHandler* thisPtr, CNWSItem*, CNWItemProperty*, CNWSCreature*, uint32_t, int32_t);
int32_t CNWSItemPropertyHandler__ApplyACBonus(CNWSItemPropertyHandler* thisPtr, CNWSItem*, CNWItemProperty*, CNWSCreature*, uint32_t, int32_t);
int32_t CNWSItemPropertyHandler__ApplyArcaneSpellFailure(CNWSItemPropertyHandler* thisPtr, CNWSItem*, CNWItemProperty*, CNWSCreature*, uint32_t, int32_t);
int32_t CNWSItemPropertyHandler__ApplyAttackBonus(CNWSItemPropertyHandler* thisPtr, CNWSItem*, CNWItemProperty*, CNWSCreature*, uint32_t, int32_t);
int32_t CNWSItemPropertyHandler__ApplyAttackPenalty(CNWSItemPropertyHandler* thisPtr, CNWSItem*, CNWItemProperty*, CNWSCreature*, uint32_t, int32_t);
int32_t CNWSItemPropertyHandler__ApplyBonusFeat(CNWSItemPropertyHandler* thisPtr, CNWSItem*, CNWItemProperty*, CNWSCreature*, uint32_t, int32_t);
int32_t CNWSItemPropertyHandler__ApplyBonusSpellOfLevel(CNWSItemPropertyHandler* thisPtr, CNWSItem*, CNWItemProperty*, CNWSCreature*, uint32_t, int32_t);
int32_t CNWSItemPropertyHandler__ApplyChangedSavingThrow(CNWSItemPropertyHandler* thisPtr, CNWSItem*, int32_t, CNWItemProperty*, CNWSCreature*, int32_t);
int32_t CNWSItemPropertyHandler__ApplyChangedSavingThrowVsX(CNWSItemPropertyHandler* thisPtr, CNWSItem*, int32_t, CNWItemProperty*, CNWSCreature*, int32_t);
int32_t CNWSItemPropertyHandler__ApplyDamageBonus(CNWSItemPropertyHandler* thisPtr, CNWSItem*, CNWItemProperty*, CNWSCreature*, uint32_t, int32_t);
int32_t CNWSItemPropertyHandler__ApplyDamageImmunity(CNWSItemPropertyHandler* thisPtr, CNWSItem*, CNWItemProperty*, CNWSCreature*, uint32_t, int32_t);
int32_t CNWSItemPropertyHandler__ApplyDamagePenalty(CNWSItemPropertyHandler* thisPtr, CNWSItem*, CNWItemProperty*, CNWSCreature*, uint32_t, int32_t);
int32_t CNWSItemPropertyHandler__ApplyDamageReduction(CNWSItemPropertyHandler* thisPtr, CNWSItem*, CNWItemProperty*, CNWSCreature*, uint32_t, int32_t);
int32_t CNWSItemPropertyHandler__ApplyDamageResistance(CNWSItemPropertyHandler* thisPtr, CNWSItem*, CNWItemProperty*, CNWSCreature*, uint32_t, int32_t);
int32_t CNWSItemPropertyHandler__ApplyDamageVulnerability(CNWSItemPropertyHandler* thisPtr, CNWSItem*, CNWItemProperty*, CNWSCreature*, uint32_t, int32_t);
int32_t CNWSItemPropertyHandler__ApplyDarkVision(CNWSItemPropertyHandler* thisPtr, CNWSItem*, CNWItemProperty*, CNWSCreature*, uint32_t, int32_t);
int32_t CNWSItemPropertyHandler__ApplyDecreaseAbility(CNWSItemPropertyHandler* thisPtr, CNWSItem*, CNWItemProperty*, CNWSCreature*, uint32_t, int32_t);
int32_t CNWSItemPropertyHandler__ApplyDecreaseAC(CNWSItemPropertyHandler* thisPtr, CNWSItem*, CNWItemProperty*, CNWSCreature*, uint32_t, int32_t);
int32_t CNWSItemPropertyHandler__ApplyDecreaseSkill(CNWSItemPropertyHandler* thisPtr, CNWSItem*, CNWItemProperty*, CNWSCreature*, uint32_t, int32_t);
int32_t CNWSItemPropertyHandler__ApplyEnhancementBonus(CNWSItemPropertyHandler* thisPtr, CNWSItem*, CNWItemProperty*, CNWSCreature*, uint32_t, int32_t);
int32_t CNWSItemPropertyHandler__ApplyEnhancementPenalty(CNWSItemPropertyHandler* thisPtr, CNWSItem*, CNWItemProperty*, CNWSCreature*, uint32_t, int32_t);
int32_t CNWSItemPropertyHandler__ApplyFreeAction(CNWSItemPropertyHandler* thisPtr, CNWSItem*, CNWItemProperty*, CNWSCreature*, uint32_t, int32_t);
int32_t CNWSItemPropertyHandler__ApplyHaste(CNWSItemPropertyHandler* thisPtr, CNWSItem*, CNWItemProperty*, CNWSCreature*, uint32_t, int32_t);
int32_t CNWSItemPropertyHandler__ApplyHolyAvenger(CNWSItemPropertyHandler* thisPtr, CNWSItem*, CNWItemProperty*, CNWSCreature*, uint32_t, int32_t);
int32_t CNWSItemPropertyHandler__ApplyImmunity(CNWSItemPropertyHandler* thisPtr, CNWSItem*, CNWItemProperty*, CNWSCreature*, uint32_t, int32_t);
int32_t CNWSItemPropertyHandler__ApplyImprovedEvasion(CNWSItemPropertyHandler* thisPtr, CNWSItem*, CNWItemProperty*, CNWSCreature*, uint32_t, int32_t);
int32_t CNWSItemPropertyHandler__ApplyImprovedSavingThrow(CNWSItemPropertyHandler* thisPtr, CNWSItem*, CNWItemProperty*, CNWSCreature*, uint32_t, int32_t);
int32_t CNWSItemPropertyHandler__ApplyImprovedSavingThrowVsX(CNWSItemPropertyHandler* thisPtr, CNWSItem*, CNWItemProperty*, CNWSCreature*, uint32_t, int32_t);
int32_t CNWSItemPropertyHandler__ApplyImprovedSpellResistance(CNWSItemPropertyHandler* thisPtr, CNWSItem*, CNWItemProperty*, CNWSCreature*, uint32_t, int32_t);
int32_t CNWSItemPropertyHandler__ApplyLight(CNWSItemPropertyHandler* thisPtr, CNWSItem*, CNWItemProperty*, CNWSCreature*, uint32_t, int32_t);
int32_t CNWSItemPropertyHandler__ApplyReducedSavingThrow(CNWSItemPropertyHandler* thisPtr, CNWSItem*, CNWItemProperty*, CNWSCreature*, uint32_t, int32_t);
int32_t CNWSItemPropertyHandler__ApplyReducedSavingThrowVsX(CNWSItemPropertyHandler* thisPtr, CNWSItem*, CNWItemProperty*, CNWSCreature*, uint32_t, int32_t);
int32_t CNWSItemPropertyHandler__ApplyRegeneration(CNWSItemPropertyHandler* thisPtr, CNWSItem*, CNWItemProperty*, CNWSCreature*, uint32_t, int32_t);
int32_t CNWSItemPropertyHandler__ApplySkillBonus(CNWSItemPropertyHandler* thisPtr, CNWSItem*, CNWItemProperty*, CNWSCreature*, uint32_t, int32_t);
int32_t CNWSItemPropertyHandler__ApplySpecialWalk(CNWSItemPropertyHandler* thisPtr, CNWSItem*, CNWItemProperty*, CNWSCreature*, uint32_t, int32_t);
int32_t CNWSItemPropertyHandler__ApplySpellImmunityLevel(CNWSItemPropertyHandler* thisPtr, CNWSItem*, CNWItemProperty*, CNWSCreature*, uint32_t, int32_t);
int32_t CNWSItemPropertyHandler__ApplySpellImmunitySchool(CNWSItemPropertyHandler* thisPtr, CNWSItem*, CNWItemProperty*, CNWSCreature*, uint32_t, int32_t);
int32_t CNWSItemPropertyHandler__ApplySpellImmunitySpecific(CNWSItemPropertyHandler* thisPtr, CNWSItem*, CNWItemProperty*, CNWSCreature*, uint32_t, int32_t);
int32_t CNWSItemPropertyHandler__ApplyTrueSeeing(CNWSItemPropertyHandler* thisPtr, CNWSItem*, CNWItemProperty*, CNWSCreature*, uint32_t, int32_t);
int32_t CNWSItemPropertyHandler__ApplyTurnResistance(CNWSItemPropertyHandler* thisPtr, CNWSItem*, CNWItemProperty*, CNWSCreature*, uint32_t, int32_t);
int32_t CNWSItemPropertyHandler__ApplyUnlimitedAmmo(CNWSItemPropertyHandler* thisPtr, CNWSItem*, CNWItemProperty*, CNWSCreature*, uint32_t, int32_t);
void CNWSItemPropertyHandler__InitializeItemProperties(CNWSItemPropertyHandler* thisPtr);
int32_t CNWSItemPropertyHandler__OnItemPropertyApplied(CNWSItemPropertyHandler* thisPtr, CNWSItem*, CNWItemProperty*, CNWSCreature*, uint32_t, int32_t);
int32_t CNWSItemPropertyHandler__OnItemPropertyRemoved(CNWSItemPropertyHandler* thisPtr, CNWSItem*, CNWItemProperty*, CNWSCreature*, uint32_t);
int32_t CNWSItemPropertyHandler__RemoveBonusSpellOfLevel(CNWSItemPropertyHandler* thisPtr, CNWSItem*, CNWItemProperty*, CNWSCreature*, uint32_t);
int32_t CNWSItemPropertyHandler__RemoveUnlimitedAmmo(CNWSItemPropertyHandler* thisPtr, CNWSItem*, CNWItemProperty*, CNWSCreature*, uint32_t);

}

}
