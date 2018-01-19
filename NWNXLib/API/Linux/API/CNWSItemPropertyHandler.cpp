#include "CNWSItemPropertyHandler.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CNWItemProperty.hpp"
#include "CNWSCreature.hpp"
#include "CNWSItem.hpp"
#include "pfAIPCommands.hpp"
#include "pfRIPCommands.hpp"

namespace NWNXLib {

namespace API {

CNWSItemPropertyHandler::~CNWSItemPropertyHandler()
{
    CNWSItemPropertyHandler__CNWSItemPropertyHandlerDtor__0(this);
}

int32_t CNWSItemPropertyHandler::ApplyAbilityBonus(CNWSItem* a0, CNWItemProperty* a1, CNWSCreature* a2, uint32_t a3, int32_t a4)
{
    return CNWSItemPropertyHandler__ApplyAbilityBonus(this, a0, a1, a2, a3, a4);
}

int32_t CNWSItemPropertyHandler::ApplyACBonus(CNWSItem* a0, CNWItemProperty* a1, CNWSCreature* a2, uint32_t a3, int32_t a4)
{
    return CNWSItemPropertyHandler__ApplyACBonus(this, a0, a1, a2, a3, a4);
}

int32_t CNWSItemPropertyHandler::ApplyArcaneSpellFailure(CNWSItem* a0, CNWItemProperty* a1, CNWSCreature* a2, uint32_t a3, int32_t a4)
{
    return CNWSItemPropertyHandler__ApplyArcaneSpellFailure(this, a0, a1, a2, a3, a4);
}

int32_t CNWSItemPropertyHandler::ApplyAttackBonus(CNWSItem* a0, CNWItemProperty* a1, CNWSCreature* a2, uint32_t a3, int32_t a4)
{
    return CNWSItemPropertyHandler__ApplyAttackBonus(this, a0, a1, a2, a3, a4);
}

int32_t CNWSItemPropertyHandler::ApplyAttackPenalty(CNWSItem* a0, CNWItemProperty* a1, CNWSCreature* a2, uint32_t a3, int32_t a4)
{
    return CNWSItemPropertyHandler__ApplyAttackPenalty(this, a0, a1, a2, a3, a4);
}

int32_t CNWSItemPropertyHandler::ApplyBonusFeat(CNWSItem* a0, CNWItemProperty* a1, CNWSCreature* a2, uint32_t a3, int32_t a4)
{
    return CNWSItemPropertyHandler__ApplyBonusFeat(this, a0, a1, a2, a3, a4);
}

int32_t CNWSItemPropertyHandler::ApplyBonusSpellOfLevel(CNWSItem* a0, CNWItemProperty* a1, CNWSCreature* a2, uint32_t a3, int32_t a4)
{
    return CNWSItemPropertyHandler__ApplyBonusSpellOfLevel(this, a0, a1, a2, a3, a4);
}

int32_t CNWSItemPropertyHandler::ApplyChangedSavingThrow(CNWSItem* a0, int32_t a1, CNWItemProperty* a2, CNWSCreature* a3, int32_t a4)
{
    return CNWSItemPropertyHandler__ApplyChangedSavingThrow(this, a0, a1, a2, a3, a4);
}

int32_t CNWSItemPropertyHandler::ApplyChangedSavingThrowVsX(CNWSItem* a0, int32_t a1, CNWItemProperty* a2, CNWSCreature* a3, int32_t a4)
{
    return CNWSItemPropertyHandler__ApplyChangedSavingThrowVsX(this, a0, a1, a2, a3, a4);
}

int32_t CNWSItemPropertyHandler::ApplyDamageBonus(CNWSItem* a0, CNWItemProperty* a1, CNWSCreature* a2, uint32_t a3, int32_t a4)
{
    return CNWSItemPropertyHandler__ApplyDamageBonus(this, a0, a1, a2, a3, a4);
}

int32_t CNWSItemPropertyHandler::ApplyDamageImmunity(CNWSItem* a0, CNWItemProperty* a1, CNWSCreature* a2, uint32_t a3, int32_t a4)
{
    return CNWSItemPropertyHandler__ApplyDamageImmunity(this, a0, a1, a2, a3, a4);
}

int32_t CNWSItemPropertyHandler::ApplyDamagePenalty(CNWSItem* a0, CNWItemProperty* a1, CNWSCreature* a2, uint32_t a3, int32_t a4)
{
    return CNWSItemPropertyHandler__ApplyDamagePenalty(this, a0, a1, a2, a3, a4);
}

int32_t CNWSItemPropertyHandler::ApplyDamageReduction(CNWSItem* a0, CNWItemProperty* a1, CNWSCreature* a2, uint32_t a3, int32_t a4)
{
    return CNWSItemPropertyHandler__ApplyDamageReduction(this, a0, a1, a2, a3, a4);
}

int32_t CNWSItemPropertyHandler::ApplyDamageResistance(CNWSItem* a0, CNWItemProperty* a1, CNWSCreature* a2, uint32_t a3, int32_t a4)
{
    return CNWSItemPropertyHandler__ApplyDamageResistance(this, a0, a1, a2, a3, a4);
}

int32_t CNWSItemPropertyHandler::ApplyDamageVulnerability(CNWSItem* a0, CNWItemProperty* a1, CNWSCreature* a2, uint32_t a3, int32_t a4)
{
    return CNWSItemPropertyHandler__ApplyDamageVulnerability(this, a0, a1, a2, a3, a4);
}

int32_t CNWSItemPropertyHandler::ApplyDarkVision(CNWSItem* a0, CNWItemProperty* a1, CNWSCreature* a2, uint32_t a3, int32_t a4)
{
    return CNWSItemPropertyHandler__ApplyDarkVision(this, a0, a1, a2, a3, a4);
}

int32_t CNWSItemPropertyHandler::ApplyDecreaseAbility(CNWSItem* a0, CNWItemProperty* a1, CNWSCreature* a2, uint32_t a3, int32_t a4)
{
    return CNWSItemPropertyHandler__ApplyDecreaseAbility(this, a0, a1, a2, a3, a4);
}

int32_t CNWSItemPropertyHandler::ApplyDecreaseAC(CNWSItem* a0, CNWItemProperty* a1, CNWSCreature* a2, uint32_t a3, int32_t a4)
{
    return CNWSItemPropertyHandler__ApplyDecreaseAC(this, a0, a1, a2, a3, a4);
}

int32_t CNWSItemPropertyHandler::ApplyDecreaseSkill(CNWSItem* a0, CNWItemProperty* a1, CNWSCreature* a2, uint32_t a3, int32_t a4)
{
    return CNWSItemPropertyHandler__ApplyDecreaseSkill(this, a0, a1, a2, a3, a4);
}

int32_t CNWSItemPropertyHandler::ApplyEnhancementBonus(CNWSItem* a0, CNWItemProperty* a1, CNWSCreature* a2, uint32_t a3, int32_t a4)
{
    return CNWSItemPropertyHandler__ApplyEnhancementBonus(this, a0, a1, a2, a3, a4);
}

int32_t CNWSItemPropertyHandler::ApplyEnhancementPenalty(CNWSItem* a0, CNWItemProperty* a1, CNWSCreature* a2, uint32_t a3, int32_t a4)
{
    return CNWSItemPropertyHandler__ApplyEnhancementPenalty(this, a0, a1, a2, a3, a4);
}

int32_t CNWSItemPropertyHandler::ApplyFreeAction(CNWSItem* a0, CNWItemProperty* a1, CNWSCreature* a2, uint32_t a3, int32_t a4)
{
    return CNWSItemPropertyHandler__ApplyFreeAction(this, a0, a1, a2, a3, a4);
}

int32_t CNWSItemPropertyHandler::ApplyHaste(CNWSItem* a0, CNWItemProperty* a1, CNWSCreature* a2, uint32_t a3, int32_t a4)
{
    return CNWSItemPropertyHandler__ApplyHaste(this, a0, a1, a2, a3, a4);
}

int32_t CNWSItemPropertyHandler::ApplyHolyAvenger(CNWSItem* a0, CNWItemProperty* a1, CNWSCreature* a2, uint32_t a3, int32_t a4)
{
    return CNWSItemPropertyHandler__ApplyHolyAvenger(this, a0, a1, a2, a3, a4);
}

int32_t CNWSItemPropertyHandler::ApplyImmunity(CNWSItem* a0, CNWItemProperty* a1, CNWSCreature* a2, uint32_t a3, int32_t a4)
{
    return CNWSItemPropertyHandler__ApplyImmunity(this, a0, a1, a2, a3, a4);
}

int32_t CNWSItemPropertyHandler::ApplyImprovedEvasion(CNWSItem* a0, CNWItemProperty* a1, CNWSCreature* a2, uint32_t a3, int32_t a4)
{
    return CNWSItemPropertyHandler__ApplyImprovedEvasion(this, a0, a1, a2, a3, a4);
}

int32_t CNWSItemPropertyHandler::ApplyImprovedSavingThrow(CNWSItem* a0, CNWItemProperty* a1, CNWSCreature* a2, uint32_t a3, int32_t a4)
{
    return CNWSItemPropertyHandler__ApplyImprovedSavingThrow(this, a0, a1, a2, a3, a4);
}

int32_t CNWSItemPropertyHandler::ApplyImprovedSavingThrowVsX(CNWSItem* a0, CNWItemProperty* a1, CNWSCreature* a2, uint32_t a3, int32_t a4)
{
    return CNWSItemPropertyHandler__ApplyImprovedSavingThrowVsX(this, a0, a1, a2, a3, a4);
}

int32_t CNWSItemPropertyHandler::ApplyImprovedSpellResistance(CNWSItem* a0, CNWItemProperty* a1, CNWSCreature* a2, uint32_t a3, int32_t a4)
{
    return CNWSItemPropertyHandler__ApplyImprovedSpellResistance(this, a0, a1, a2, a3, a4);
}

int32_t CNWSItemPropertyHandler::ApplyLight(CNWSItem* a0, CNWItemProperty* a1, CNWSCreature* a2, uint32_t a3, int32_t a4)
{
    return CNWSItemPropertyHandler__ApplyLight(this, a0, a1, a2, a3, a4);
}

int32_t CNWSItemPropertyHandler::ApplyReducedSavingThrow(CNWSItem* a0, CNWItemProperty* a1, CNWSCreature* a2, uint32_t a3, int32_t a4)
{
    return CNWSItemPropertyHandler__ApplyReducedSavingThrow(this, a0, a1, a2, a3, a4);
}

int32_t CNWSItemPropertyHandler::ApplyReducedSavingThrowVsX(CNWSItem* a0, CNWItemProperty* a1, CNWSCreature* a2, uint32_t a3, int32_t a4)
{
    return CNWSItemPropertyHandler__ApplyReducedSavingThrowVsX(this, a0, a1, a2, a3, a4);
}

int32_t CNWSItemPropertyHandler::ApplyRegeneration(CNWSItem* a0, CNWItemProperty* a1, CNWSCreature* a2, uint32_t a3, int32_t a4)
{
    return CNWSItemPropertyHandler__ApplyRegeneration(this, a0, a1, a2, a3, a4);
}

int32_t CNWSItemPropertyHandler::ApplySkillBonus(CNWSItem* a0, CNWItemProperty* a1, CNWSCreature* a2, uint32_t a3, int32_t a4)
{
    return CNWSItemPropertyHandler__ApplySkillBonus(this, a0, a1, a2, a3, a4);
}

int32_t CNWSItemPropertyHandler::ApplySpecialWalk(CNWSItem* a0, CNWItemProperty* a1, CNWSCreature* a2, uint32_t a3, int32_t a4)
{
    return CNWSItemPropertyHandler__ApplySpecialWalk(this, a0, a1, a2, a3, a4);
}

int32_t CNWSItemPropertyHandler::ApplySpellImmunityLevel(CNWSItem* a0, CNWItemProperty* a1, CNWSCreature* a2, uint32_t a3, int32_t a4)
{
    return CNWSItemPropertyHandler__ApplySpellImmunityLevel(this, a0, a1, a2, a3, a4);
}

int32_t CNWSItemPropertyHandler::ApplySpellImmunitySchool(CNWSItem* a0, CNWItemProperty* a1, CNWSCreature* a2, uint32_t a3, int32_t a4)
{
    return CNWSItemPropertyHandler__ApplySpellImmunitySchool(this, a0, a1, a2, a3, a4);
}

int32_t CNWSItemPropertyHandler::ApplySpellImmunitySpecific(CNWSItem* a0, CNWItemProperty* a1, CNWSCreature* a2, uint32_t a3, int32_t a4)
{
    return CNWSItemPropertyHandler__ApplySpellImmunitySpecific(this, a0, a1, a2, a3, a4);
}

int32_t CNWSItemPropertyHandler::ApplyTrueSeeing(CNWSItem* a0, CNWItemProperty* a1, CNWSCreature* a2, uint32_t a3, int32_t a4)
{
    return CNWSItemPropertyHandler__ApplyTrueSeeing(this, a0, a1, a2, a3, a4);
}

int32_t CNWSItemPropertyHandler::ApplyTurnResistance(CNWSItem* a0, CNWItemProperty* a1, CNWSCreature* a2, uint32_t a3, int32_t a4)
{
    return CNWSItemPropertyHandler__ApplyTurnResistance(this, a0, a1, a2, a3, a4);
}

int32_t CNWSItemPropertyHandler::ApplyUnlimitedAmmo(CNWSItem* a0, CNWItemProperty* a1, CNWSCreature* a2, uint32_t a3, int32_t a4)
{
    return CNWSItemPropertyHandler__ApplyUnlimitedAmmo(this, a0, a1, a2, a3, a4);
}

void CNWSItemPropertyHandler::InitializeItemProperties()
{
    return CNWSItemPropertyHandler__InitializeItemProperties(this);
}

int32_t CNWSItemPropertyHandler::OnItemPropertyApplied(CNWSItem* a0, CNWItemProperty* a1, CNWSCreature* a2, uint32_t a3, int32_t a4)
{
    return CNWSItemPropertyHandler__OnItemPropertyApplied(this, a0, a1, a2, a3, a4);
}

int32_t CNWSItemPropertyHandler::OnItemPropertyRemoved(CNWSItem* a0, CNWItemProperty* a1, CNWSCreature* a2, uint32_t a3)
{
    return CNWSItemPropertyHandler__OnItemPropertyRemoved(this, a0, a1, a2, a3);
}

int32_t CNWSItemPropertyHandler::RemoveBonusSpellOfLevel(CNWSItem* a0, CNWItemProperty* a1, CNWSCreature* a2, uint32_t a3)
{
    return CNWSItemPropertyHandler__RemoveBonusSpellOfLevel(this, a0, a1, a2, a3);
}

int32_t CNWSItemPropertyHandler::RemoveUnlimitedAmmo(CNWSItem* a0, CNWItemProperty* a1, CNWSCreature* a2, uint32_t a3)
{
    return CNWSItemPropertyHandler__RemoveUnlimitedAmmo(this, a0, a1, a2, a3);
}

void CNWSItemPropertyHandler__CNWSItemPropertyHandlerDtor__0(CNWSItemPropertyHandler* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSItemPropertyHandler*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSItemPropertyHandler__CNWSItemPropertyHandlerDtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

int32_t CNWSItemPropertyHandler__ApplyAbilityBonus(CNWSItemPropertyHandler* thisPtr, CNWSItem* a0, CNWItemProperty* a1, CNWSCreature* a2, uint32_t a3, int32_t a4)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSItemPropertyHandler*, CNWSItem*, CNWItemProperty*, CNWSCreature*, uint32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSItemPropertyHandler__ApplyAbilityBonus);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4);
}

int32_t CNWSItemPropertyHandler__ApplyACBonus(CNWSItemPropertyHandler* thisPtr, CNWSItem* a0, CNWItemProperty* a1, CNWSCreature* a2, uint32_t a3, int32_t a4)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSItemPropertyHandler*, CNWSItem*, CNWItemProperty*, CNWSCreature*, uint32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSItemPropertyHandler__ApplyACBonus);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4);
}

int32_t CNWSItemPropertyHandler__ApplyArcaneSpellFailure(CNWSItemPropertyHandler* thisPtr, CNWSItem* a0, CNWItemProperty* a1, CNWSCreature* a2, uint32_t a3, int32_t a4)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSItemPropertyHandler*, CNWSItem*, CNWItemProperty*, CNWSCreature*, uint32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSItemPropertyHandler__ApplyArcaneSpellFailure);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4);
}

int32_t CNWSItemPropertyHandler__ApplyAttackBonus(CNWSItemPropertyHandler* thisPtr, CNWSItem* a0, CNWItemProperty* a1, CNWSCreature* a2, uint32_t a3, int32_t a4)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSItemPropertyHandler*, CNWSItem*, CNWItemProperty*, CNWSCreature*, uint32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSItemPropertyHandler__ApplyAttackBonus);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4);
}

int32_t CNWSItemPropertyHandler__ApplyAttackPenalty(CNWSItemPropertyHandler* thisPtr, CNWSItem* a0, CNWItemProperty* a1, CNWSCreature* a2, uint32_t a3, int32_t a4)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSItemPropertyHandler*, CNWSItem*, CNWItemProperty*, CNWSCreature*, uint32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSItemPropertyHandler__ApplyAttackPenalty);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4);
}

int32_t CNWSItemPropertyHandler__ApplyBonusFeat(CNWSItemPropertyHandler* thisPtr, CNWSItem* a0, CNWItemProperty* a1, CNWSCreature* a2, uint32_t a3, int32_t a4)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSItemPropertyHandler*, CNWSItem*, CNWItemProperty*, CNWSCreature*, uint32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSItemPropertyHandler__ApplyBonusFeat);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4);
}

int32_t CNWSItemPropertyHandler__ApplyBonusSpellOfLevel(CNWSItemPropertyHandler* thisPtr, CNWSItem* a0, CNWItemProperty* a1, CNWSCreature* a2, uint32_t a3, int32_t a4)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSItemPropertyHandler*, CNWSItem*, CNWItemProperty*, CNWSCreature*, uint32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSItemPropertyHandler__ApplyBonusSpellOfLevel);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4);
}

int32_t CNWSItemPropertyHandler__ApplyChangedSavingThrow(CNWSItemPropertyHandler* thisPtr, CNWSItem* a0, int32_t a1, CNWItemProperty* a2, CNWSCreature* a3, int32_t a4)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSItemPropertyHandler*, CNWSItem*, int32_t, CNWItemProperty*, CNWSCreature*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSItemPropertyHandler__ApplyChangedSavingThrow);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4);
}

int32_t CNWSItemPropertyHandler__ApplyChangedSavingThrowVsX(CNWSItemPropertyHandler* thisPtr, CNWSItem* a0, int32_t a1, CNWItemProperty* a2, CNWSCreature* a3, int32_t a4)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSItemPropertyHandler*, CNWSItem*, int32_t, CNWItemProperty*, CNWSCreature*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSItemPropertyHandler__ApplyChangedSavingThrowVsX);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4);
}

int32_t CNWSItemPropertyHandler__ApplyDamageBonus(CNWSItemPropertyHandler* thisPtr, CNWSItem* a0, CNWItemProperty* a1, CNWSCreature* a2, uint32_t a3, int32_t a4)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSItemPropertyHandler*, CNWSItem*, CNWItemProperty*, CNWSCreature*, uint32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSItemPropertyHandler__ApplyDamageBonus);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4);
}

int32_t CNWSItemPropertyHandler__ApplyDamageImmunity(CNWSItemPropertyHandler* thisPtr, CNWSItem* a0, CNWItemProperty* a1, CNWSCreature* a2, uint32_t a3, int32_t a4)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSItemPropertyHandler*, CNWSItem*, CNWItemProperty*, CNWSCreature*, uint32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSItemPropertyHandler__ApplyDamageImmunity);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4);
}

int32_t CNWSItemPropertyHandler__ApplyDamagePenalty(CNWSItemPropertyHandler* thisPtr, CNWSItem* a0, CNWItemProperty* a1, CNWSCreature* a2, uint32_t a3, int32_t a4)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSItemPropertyHandler*, CNWSItem*, CNWItemProperty*, CNWSCreature*, uint32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSItemPropertyHandler__ApplyDamagePenalty);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4);
}

int32_t CNWSItemPropertyHandler__ApplyDamageReduction(CNWSItemPropertyHandler* thisPtr, CNWSItem* a0, CNWItemProperty* a1, CNWSCreature* a2, uint32_t a3, int32_t a4)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSItemPropertyHandler*, CNWSItem*, CNWItemProperty*, CNWSCreature*, uint32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSItemPropertyHandler__ApplyDamageReduction);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4);
}

int32_t CNWSItemPropertyHandler__ApplyDamageResistance(CNWSItemPropertyHandler* thisPtr, CNWSItem* a0, CNWItemProperty* a1, CNWSCreature* a2, uint32_t a3, int32_t a4)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSItemPropertyHandler*, CNWSItem*, CNWItemProperty*, CNWSCreature*, uint32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSItemPropertyHandler__ApplyDamageResistance);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4);
}

int32_t CNWSItemPropertyHandler__ApplyDamageVulnerability(CNWSItemPropertyHandler* thisPtr, CNWSItem* a0, CNWItemProperty* a1, CNWSCreature* a2, uint32_t a3, int32_t a4)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSItemPropertyHandler*, CNWSItem*, CNWItemProperty*, CNWSCreature*, uint32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSItemPropertyHandler__ApplyDamageVulnerability);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4);
}

int32_t CNWSItemPropertyHandler__ApplyDarkVision(CNWSItemPropertyHandler* thisPtr, CNWSItem* a0, CNWItemProperty* a1, CNWSCreature* a2, uint32_t a3, int32_t a4)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSItemPropertyHandler*, CNWSItem*, CNWItemProperty*, CNWSCreature*, uint32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSItemPropertyHandler__ApplyDarkVision);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4);
}

int32_t CNWSItemPropertyHandler__ApplyDecreaseAbility(CNWSItemPropertyHandler* thisPtr, CNWSItem* a0, CNWItemProperty* a1, CNWSCreature* a2, uint32_t a3, int32_t a4)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSItemPropertyHandler*, CNWSItem*, CNWItemProperty*, CNWSCreature*, uint32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSItemPropertyHandler__ApplyDecreaseAbility);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4);
}

int32_t CNWSItemPropertyHandler__ApplyDecreaseAC(CNWSItemPropertyHandler* thisPtr, CNWSItem* a0, CNWItemProperty* a1, CNWSCreature* a2, uint32_t a3, int32_t a4)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSItemPropertyHandler*, CNWSItem*, CNWItemProperty*, CNWSCreature*, uint32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSItemPropertyHandler__ApplyDecreaseAC);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4);
}

int32_t CNWSItemPropertyHandler__ApplyDecreaseSkill(CNWSItemPropertyHandler* thisPtr, CNWSItem* a0, CNWItemProperty* a1, CNWSCreature* a2, uint32_t a3, int32_t a4)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSItemPropertyHandler*, CNWSItem*, CNWItemProperty*, CNWSCreature*, uint32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSItemPropertyHandler__ApplyDecreaseSkill);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4);
}

int32_t CNWSItemPropertyHandler__ApplyEnhancementBonus(CNWSItemPropertyHandler* thisPtr, CNWSItem* a0, CNWItemProperty* a1, CNWSCreature* a2, uint32_t a3, int32_t a4)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSItemPropertyHandler*, CNWSItem*, CNWItemProperty*, CNWSCreature*, uint32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSItemPropertyHandler__ApplyEnhancementBonus);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4);
}

int32_t CNWSItemPropertyHandler__ApplyEnhancementPenalty(CNWSItemPropertyHandler* thisPtr, CNWSItem* a0, CNWItemProperty* a1, CNWSCreature* a2, uint32_t a3, int32_t a4)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSItemPropertyHandler*, CNWSItem*, CNWItemProperty*, CNWSCreature*, uint32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSItemPropertyHandler__ApplyEnhancementPenalty);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4);
}

int32_t CNWSItemPropertyHandler__ApplyFreeAction(CNWSItemPropertyHandler* thisPtr, CNWSItem* a0, CNWItemProperty* a1, CNWSCreature* a2, uint32_t a3, int32_t a4)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSItemPropertyHandler*, CNWSItem*, CNWItemProperty*, CNWSCreature*, uint32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSItemPropertyHandler__ApplyFreeAction);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4);
}

int32_t CNWSItemPropertyHandler__ApplyHaste(CNWSItemPropertyHandler* thisPtr, CNWSItem* a0, CNWItemProperty* a1, CNWSCreature* a2, uint32_t a3, int32_t a4)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSItemPropertyHandler*, CNWSItem*, CNWItemProperty*, CNWSCreature*, uint32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSItemPropertyHandler__ApplyHaste);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4);
}

int32_t CNWSItemPropertyHandler__ApplyHolyAvenger(CNWSItemPropertyHandler* thisPtr, CNWSItem* a0, CNWItemProperty* a1, CNWSCreature* a2, uint32_t a3, int32_t a4)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSItemPropertyHandler*, CNWSItem*, CNWItemProperty*, CNWSCreature*, uint32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSItemPropertyHandler__ApplyHolyAvenger);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4);
}

int32_t CNWSItemPropertyHandler__ApplyImmunity(CNWSItemPropertyHandler* thisPtr, CNWSItem* a0, CNWItemProperty* a1, CNWSCreature* a2, uint32_t a3, int32_t a4)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSItemPropertyHandler*, CNWSItem*, CNWItemProperty*, CNWSCreature*, uint32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSItemPropertyHandler__ApplyImmunity);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4);
}

int32_t CNWSItemPropertyHandler__ApplyImprovedEvasion(CNWSItemPropertyHandler* thisPtr, CNWSItem* a0, CNWItemProperty* a1, CNWSCreature* a2, uint32_t a3, int32_t a4)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSItemPropertyHandler*, CNWSItem*, CNWItemProperty*, CNWSCreature*, uint32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSItemPropertyHandler__ApplyImprovedEvasion);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4);
}

int32_t CNWSItemPropertyHandler__ApplyImprovedSavingThrow(CNWSItemPropertyHandler* thisPtr, CNWSItem* a0, CNWItemProperty* a1, CNWSCreature* a2, uint32_t a3, int32_t a4)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSItemPropertyHandler*, CNWSItem*, CNWItemProperty*, CNWSCreature*, uint32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSItemPropertyHandler__ApplyImprovedSavingThrow);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4);
}

int32_t CNWSItemPropertyHandler__ApplyImprovedSavingThrowVsX(CNWSItemPropertyHandler* thisPtr, CNWSItem* a0, CNWItemProperty* a1, CNWSCreature* a2, uint32_t a3, int32_t a4)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSItemPropertyHandler*, CNWSItem*, CNWItemProperty*, CNWSCreature*, uint32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSItemPropertyHandler__ApplyImprovedSavingThrowVsX);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4);
}

int32_t CNWSItemPropertyHandler__ApplyImprovedSpellResistance(CNWSItemPropertyHandler* thisPtr, CNWSItem* a0, CNWItemProperty* a1, CNWSCreature* a2, uint32_t a3, int32_t a4)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSItemPropertyHandler*, CNWSItem*, CNWItemProperty*, CNWSCreature*, uint32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSItemPropertyHandler__ApplyImprovedSpellResistance);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4);
}

int32_t CNWSItemPropertyHandler__ApplyLight(CNWSItemPropertyHandler* thisPtr, CNWSItem* a0, CNWItemProperty* a1, CNWSCreature* a2, uint32_t a3, int32_t a4)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSItemPropertyHandler*, CNWSItem*, CNWItemProperty*, CNWSCreature*, uint32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSItemPropertyHandler__ApplyLight);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4);
}

int32_t CNWSItemPropertyHandler__ApplyReducedSavingThrow(CNWSItemPropertyHandler* thisPtr, CNWSItem* a0, CNWItemProperty* a1, CNWSCreature* a2, uint32_t a3, int32_t a4)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSItemPropertyHandler*, CNWSItem*, CNWItemProperty*, CNWSCreature*, uint32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSItemPropertyHandler__ApplyReducedSavingThrow);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4);
}

int32_t CNWSItemPropertyHandler__ApplyReducedSavingThrowVsX(CNWSItemPropertyHandler* thisPtr, CNWSItem* a0, CNWItemProperty* a1, CNWSCreature* a2, uint32_t a3, int32_t a4)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSItemPropertyHandler*, CNWSItem*, CNWItemProperty*, CNWSCreature*, uint32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSItemPropertyHandler__ApplyReducedSavingThrowVsX);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4);
}

int32_t CNWSItemPropertyHandler__ApplyRegeneration(CNWSItemPropertyHandler* thisPtr, CNWSItem* a0, CNWItemProperty* a1, CNWSCreature* a2, uint32_t a3, int32_t a4)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSItemPropertyHandler*, CNWSItem*, CNWItemProperty*, CNWSCreature*, uint32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSItemPropertyHandler__ApplyRegeneration);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4);
}

int32_t CNWSItemPropertyHandler__ApplySkillBonus(CNWSItemPropertyHandler* thisPtr, CNWSItem* a0, CNWItemProperty* a1, CNWSCreature* a2, uint32_t a3, int32_t a4)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSItemPropertyHandler*, CNWSItem*, CNWItemProperty*, CNWSCreature*, uint32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSItemPropertyHandler__ApplySkillBonus);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4);
}

int32_t CNWSItemPropertyHandler__ApplySpecialWalk(CNWSItemPropertyHandler* thisPtr, CNWSItem* a0, CNWItemProperty* a1, CNWSCreature* a2, uint32_t a3, int32_t a4)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSItemPropertyHandler*, CNWSItem*, CNWItemProperty*, CNWSCreature*, uint32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSItemPropertyHandler__ApplySpecialWalk);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4);
}

int32_t CNWSItemPropertyHandler__ApplySpellImmunityLevel(CNWSItemPropertyHandler* thisPtr, CNWSItem* a0, CNWItemProperty* a1, CNWSCreature* a2, uint32_t a3, int32_t a4)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSItemPropertyHandler*, CNWSItem*, CNWItemProperty*, CNWSCreature*, uint32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSItemPropertyHandler__ApplySpellImmunityLevel);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4);
}

int32_t CNWSItemPropertyHandler__ApplySpellImmunitySchool(CNWSItemPropertyHandler* thisPtr, CNWSItem* a0, CNWItemProperty* a1, CNWSCreature* a2, uint32_t a3, int32_t a4)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSItemPropertyHandler*, CNWSItem*, CNWItemProperty*, CNWSCreature*, uint32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSItemPropertyHandler__ApplySpellImmunitySchool);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4);
}

int32_t CNWSItemPropertyHandler__ApplySpellImmunitySpecific(CNWSItemPropertyHandler* thisPtr, CNWSItem* a0, CNWItemProperty* a1, CNWSCreature* a2, uint32_t a3, int32_t a4)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSItemPropertyHandler*, CNWSItem*, CNWItemProperty*, CNWSCreature*, uint32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSItemPropertyHandler__ApplySpellImmunitySpecific);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4);
}

int32_t CNWSItemPropertyHandler__ApplyTrueSeeing(CNWSItemPropertyHandler* thisPtr, CNWSItem* a0, CNWItemProperty* a1, CNWSCreature* a2, uint32_t a3, int32_t a4)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSItemPropertyHandler*, CNWSItem*, CNWItemProperty*, CNWSCreature*, uint32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSItemPropertyHandler__ApplyTrueSeeing);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4);
}

int32_t CNWSItemPropertyHandler__ApplyTurnResistance(CNWSItemPropertyHandler* thisPtr, CNWSItem* a0, CNWItemProperty* a1, CNWSCreature* a2, uint32_t a3, int32_t a4)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSItemPropertyHandler*, CNWSItem*, CNWItemProperty*, CNWSCreature*, uint32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSItemPropertyHandler__ApplyTurnResistance);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4);
}

int32_t CNWSItemPropertyHandler__ApplyUnlimitedAmmo(CNWSItemPropertyHandler* thisPtr, CNWSItem* a0, CNWItemProperty* a1, CNWSCreature* a2, uint32_t a3, int32_t a4)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSItemPropertyHandler*, CNWSItem*, CNWItemProperty*, CNWSCreature*, uint32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSItemPropertyHandler__ApplyUnlimitedAmmo);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4);
}

void CNWSItemPropertyHandler__InitializeItemProperties(CNWSItemPropertyHandler* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSItemPropertyHandler*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSItemPropertyHandler__InitializeItemProperties);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CNWSItemPropertyHandler__OnItemPropertyApplied(CNWSItemPropertyHandler* thisPtr, CNWSItem* a0, CNWItemProperty* a1, CNWSCreature* a2, uint32_t a3, int32_t a4)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSItemPropertyHandler*, CNWSItem*, CNWItemProperty*, CNWSCreature*, uint32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSItemPropertyHandler__OnItemPropertyApplied);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4);
}

int32_t CNWSItemPropertyHandler__OnItemPropertyRemoved(CNWSItemPropertyHandler* thisPtr, CNWSItem* a0, CNWItemProperty* a1, CNWSCreature* a2, uint32_t a3)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSItemPropertyHandler*, CNWSItem*, CNWItemProperty*, CNWSCreature*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSItemPropertyHandler__OnItemPropertyRemoved);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

int32_t CNWSItemPropertyHandler__RemoveBonusSpellOfLevel(CNWSItemPropertyHandler* thisPtr, CNWSItem* a0, CNWItemProperty* a1, CNWSCreature* a2, uint32_t a3)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSItemPropertyHandler*, CNWSItem*, CNWItemProperty*, CNWSCreature*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSItemPropertyHandler__RemoveBonusSpellOfLevel);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

int32_t CNWSItemPropertyHandler__RemoveUnlimitedAmmo(CNWSItemPropertyHandler* thisPtr, CNWSItem* a0, CNWItemProperty* a1, CNWSCreature* a2, uint32_t a3)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSItemPropertyHandler*, CNWSItem*, CNWItemProperty*, CNWSCreature*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSItemPropertyHandler__RemoveUnlimitedAmmo);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

}

}
