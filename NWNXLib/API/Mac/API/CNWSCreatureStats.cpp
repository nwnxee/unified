#include "CNWSCreatureStats.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CCombatInformation.hpp"
#include "CExoArrayListTemplatedCNWSStats_SpellLikeAbility.hpp"
#include "CNWClass.hpp"
#include "CNWCreatureStatsUpdate.hpp"
#include "CNWLevelStats.hpp"
#include "CNWSCreature.hpp"
#include "CNWSCreatureAppearanceInfo.hpp"
#include "CNWSItem.hpp"
#include "CNWSObject.hpp"
#include "CNWSpell.hpp"
#include "CResGFF.hpp"
#include "CResStruct.hpp"

namespace NWNXLib {

namespace API {

CNWSCreatureStats::CNWSCreatureStats(CNWSCreature* a0)
{
    CNWSCreatureStats__CNWSCreatureStatsCtor__0(this, a0);
}

CNWSCreatureStats::~CNWSCreatureStats()
{
    CNWSCreatureStats__CNWSCreatureStatsDtor__0(this);
}

void CNWSCreatureStats::AddExperience(uint32_t a0)
{
    return CNWSCreatureStats__AddExperience(this, a0);
}

void CNWSCreatureStats::AddFeat(uint16_t a0)
{
    return CNWSCreatureStats__AddFeat(this, a0);
}

void CNWSCreatureStats::AddKnownSpell(unsigned char a0, uint32_t a1)
{
    return CNWSCreatureStats__AddKnownSpell(this, a0, a1);
}

void CNWSCreatureStats::AddSpellLikeAbilityToList(uint32_t a0, int32_t a1, unsigned char a2)
{
    return CNWSCreatureStats__AddSpellLikeAbilityToList(this, a0, a1, a2);
}

void CNWSCreatureStats::AdjustAlignment(unsigned char a0, int16_t a1, uint32_t a2)
{
    return CNWSCreatureStats__AdjustAlignment(this, a0, a1, a2);
}

void CNWSCreatureStats::AdjustSpellUsesPerDay()
{
    return CNWSCreatureStats__AdjustSpellUsesPerDay(this);
}

int32_t CNWSCreatureStats::AutoMemorizeSpells(int32_t a0)
{
    return CNWSCreatureStats__AutoMemorizeSpells(this, a0);
}

void CNWSCreatureStats::CalcLevelUpNumberFeats(unsigned char a0, unsigned char a1, unsigned char& a2, unsigned char& a3)
{
    return CNWSCreatureStats__CalcLevelUpNumberFeats(this, a0, a1, a2, a3);
}

char CNWSCreatureStats::CalcStatModifier(unsigned char a0)
{
    return CNWSCreatureStats__CalcStatModifier(this, a0);
}

int32_t CNWSCreatureStats::CanChooseFeat(uint16_t a0, unsigned char a1, unsigned char a2, CExoArrayListTemplatedunsignedshort* a3)
{
    return CNWSCreatureStats__CanChooseFeat(this, a0, a1, a2, a3);
}

int32_t CNWSCreatureStats::CanLevelUp()
{
    return CNWSCreatureStats__CanLevelUp(this);
}

int32_t CNWSCreatureStats::CheckSpellSuitability(int32_t a0, CNWSpell* a1, int32_t a2, int32_t a3, int32_t a4, int32_t a5, int32_t a6, int32_t a7, unsigned char& a8, int32_t a9)
{
    return CNWSCreatureStats__CheckSpellSuitability(this, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9);
}

void CNWSCreatureStats::ClearFeats()
{
    return CNWSCreatureStats__ClearFeats(this);
}

void CNWSCreatureStats::ClearMemorizedSpellSlot(unsigned char a0, unsigned char a1, unsigned char a2)
{
    return CNWSCreatureStats__ClearMemorizedSpellSlot(this, a0, a1, a2);
}

void CNWSCreatureStats::ComputeFeatBonuses(CExoArrayListTemplatedunsignedshort* a0, int32_t a1, int32_t a2)
{
    return CNWSCreatureStats__ComputeFeatBonuses(this, a0, a1, a2);
}

unsigned char CNWSCreatureStats::ComputeNumberKnownSpellsLeft(unsigned char a0, unsigned char a1)
{
    return CNWSCreatureStats__ComputeNumberKnownSpellsLeft(this, a0, a1);
}

int32_t CNWSCreatureStats::ConfirmDomainSpell(unsigned char a0, unsigned char a1, uint32_t a2)
{
    return CNWSCreatureStats__ConfirmDomainSpell(this, a0, a1, a2);
}

void CNWSCreatureStats::DecrementFeatRemainingUses(uint16_t a0)
{
    return CNWSCreatureStats__DecrementFeatRemainingUses(this, a0);
}

void CNWSCreatureStats::DecrementSpellsPerDayLeft(unsigned char a0, unsigned char a1)
{
    return CNWSCreatureStats__DecrementSpellsPerDayLeft(this, a0, a1);
}

int32_t CNWSCreatureStats::FeatAcquired(uint16_t a0, CExoArrayListTemplatedunsignedshort* a1, int32_t a2)
{
    return CNWSCreatureStats__FeatAcquired(this, a0, a1, a2);
}

int32_t CNWSCreatureStats::FeatRequirementsMet(uint16_t a0, CExoArrayListTemplatedunsignedshort* a1)
{
    return CNWSCreatureStats__FeatRequirementsMet(this, a0, a1);
}

int32_t CNWSCreatureStats::FeatRequirementsMetAfterLevelUp(uint16_t a0, CNWLevelStats* a1, unsigned char a2)
{
    return CNWSCreatureStats__FeatRequirementsMetAfterLevelUp(this, a0, a1, a2);
}

void CNWSCreatureStats::GetAbilityModsFromFeats(CExoArrayListTemplatedunsignedshort* a0, int32_t* a1, int32_t a2, int32_t a3)
{
    return CNWSCreatureStats__GetAbilityModsFromFeats(this, a0, a1, a2, a3);
}

char CNWSCreatureStats::GetACNaturalBase(int32_t a0)
{
    return CNWSCreatureStats__GetACNaturalBase(this, a0);
}

CExoString CNWSCreatureStats::GetAlignmentString()
{
    return CNWSCreatureStats__GetAlignmentString(this);
}

int16_t CNWSCreatureStats::GetArmorClassVersus(CNWSCreature* a0, int32_t a1)
{
    return CNWSCreatureStats__GetArmorClassVersus(this, a0, a1);
}

int32_t CNWSCreatureStats::GetAttackModifierVersus(CNWSCreature* a0)
{
    return CNWSCreatureStats__GetAttackModifierVersus(this, a0);
}

unsigned char CNWSCreatureStats::GetAttacksPerRound()
{
    return CNWSCreatureStats__GetAttacksPerRound(this);
}

int32_t CNWSCreatureStats::GetBaseAttackBonus(int32_t a0)
{
    return CNWSCreatureStats__GetBaseAttackBonus(this, a0);
}

char CNWSCreatureStats::GetBaseFortSavingThrow()
{
    return CNWSCreatureStats__GetBaseFortSavingThrow(this);
}

char CNWSCreatureStats::GetBaseReflexSavingThrow()
{
    return CNWSCreatureStats__GetBaseReflexSavingThrow(this);
}

char CNWSCreatureStats::GetBaseWillSavingThrow()
{
    return CNWSCreatureStats__GetBaseWillSavingThrow(this);
}

uint16_t CNWSCreatureStats::GetBonusFeat(uint16_t a0)
{
    return CNWSCreatureStats__GetBonusFeat(this, a0);
}

int32_t CNWSCreatureStats::GetCanUseRelatedCategory(int32_t a0, int32_t a1)
{
    return CNWSCreatureStats__GetCanUseRelatedCategory(this, a0, a1);
}

int32_t CNWSCreatureStats::GetCanUseSkill(unsigned char a0)
{
    return CNWSCreatureStats__GetCanUseSkill(this, a0);
}

int32_t CNWSCreatureStats::GetCanUseSkillAfterLevelUp(uint16_t a0, CNWLevelStats* a1)
{
    return CNWSCreatureStats__GetCanUseSkillAfterLevelUp(this, a0, a1);
}

uint16_t CNWSCreatureStats::GetCasterLevel(unsigned char a0)
{
    return CNWSCreatureStats__GetCasterLevel(this, a0);
}

unsigned char CNWSCreatureStats::GetCHAStat()
{
    return CNWSCreatureStats__GetCHAStat(this);
}

unsigned char CNWSCreatureStats::GetClass(unsigned char a0)
{
    return CNWSCreatureStats__GetClass(this, a0);
}

CNWSCreatureStats_ClassInfo* CNWSCreatureStats::GetClassInfo(unsigned char a0)
{
    return CNWSCreatureStats__GetClassInfo(this, a0);
}

unsigned char CNWSCreatureStats::GetClassLevel(unsigned char a0, int32_t a1)
{
    return CNWSCreatureStats__GetClassLevel(this, a0, a1);
}

unsigned char CNWSCreatureStats::GetClassNegativeLevels(unsigned char a0)
{
    return CNWSCreatureStats__GetClassNegativeLevels(this, a0);
}

CExoString CNWSCreatureStats::GetClassString(unsigned char a0)
{
    return CNWSCreatureStats__GetClassString(this, a0);
}

unsigned char CNWSCreatureStats::GetCONStat()
{
    return CNWSCreatureStats__GetCONStat(this);
}

unsigned char CNWSCreatureStats::GetCreatureDamageDice(unsigned char a0)
{
    return CNWSCreatureStats__GetCreatureDamageDice(this, a0);
}

unsigned char CNWSCreatureStats::GetCreatureDamageDie(unsigned char a0)
{
    return CNWSCreatureStats__GetCreatureDamageDie(this, a0);
}

int32_t CNWSCreatureStats::GetCreatureHasTalent(int32_t a0, int32_t a1, unsigned char a2)
{
    return CNWSCreatureStats__GetCreatureHasTalent(this, a0, a1, a2);
}

int32_t CNWSCreatureStats::GetCreatureTalentRandom(int32_t a0, int32_t a1, int32_t& a2, int32_t& a3, unsigned char& a4, uint32_t& a5, int32_t& a6, unsigned char& a7, unsigned char& a8)
{
    return CNWSCreatureStats__GetCreatureTalentRandom(this, a0, a1, a2, a3, a4, a5, a6, a7, a8);
}

int32_t CNWSCreatureStats::GetCreatureTalentRandomFeat(int32_t a0, int32_t a1, int32_t& a2, int32_t& a3, unsigned char& a4)
{
    return CNWSCreatureStats__GetCreatureTalentRandomFeat(this, a0, a1, a2, a3, a4);
}

int32_t CNWSCreatureStats::GetCreatureTalentRandomKnownSpell(int32_t a0, int32_t a1, int32_t& a2, int32_t& a3, unsigned char& a4, int32_t a5)
{
    return CNWSCreatureStats__GetCreatureTalentRandomKnownSpell(this, a0, a1, a2, a3, a4, a5);
}

int32_t CNWSCreatureStats::GetCreatureTalentRandomMemorisedSpell(int32_t a0, int32_t a1, int32_t& a2, int32_t& a3, unsigned char& a4, int32_t a5, unsigned char& a6)
{
    return CNWSCreatureStats__GetCreatureTalentRandomMemorisedSpell(this, a0, a1, a2, a3, a4, a5, a6);
}

int32_t CNWSCreatureStats::GetCreatureTalentRandomSkill(int32_t a0, int32_t a1, int32_t& a2, int32_t& a3, unsigned char& a4)
{
    return CNWSCreatureStats__GetCreatureTalentRandomSkill(this, a0, a1, a2, a3, a4);
}

int32_t CNWSCreatureStats::GetCreatureTalentRandomSpell(int32_t a0, int32_t a1, int32_t& a2, int32_t& a3, unsigned char& a4, unsigned char& a5)
{
    return CNWSCreatureStats__GetCreatureTalentRandomSpell(this, a0, a1, a2, a3, a4, a5);
}

int32_t CNWSCreatureStats::GetCreatureTalentRandomSpellFromItem(int32_t a0, int32_t a1, int32_t& a2, int32_t& a3, unsigned char& a4, uint32_t& a5, int32_t& a6)
{
    return CNWSCreatureStats__GetCreatureTalentRandomSpellFromItem(this, a0, a1, a2, a3, a4, a5, a6);
}

int32_t CNWSCreatureStats::GetCreatureTalentRandomSpellLikeAbility(int32_t a0, int32_t a1, int32_t& a2, int32_t& a3, unsigned char& a4, unsigned char& a5)
{
    return CNWSCreatureStats__GetCreatureTalentRandomSpellLikeAbility(this, a0, a1, a2, a3, a4, a5);
}

int32_t CNWSCreatureStats::GetCriticalHitMultiplier(int32_t a0)
{
    return CNWSCreatureStats__GetCriticalHitMultiplier(this, a0);
}

int32_t CNWSCreatureStats::GetCriticalHitRoll(int32_t a0)
{
    return CNWSCreatureStats__GetCriticalHitRoll(this, a0);
}

int32_t CNWSCreatureStats::GetDamageBonus(CNWSCreature* a0, int32_t a1)
{
    return CNWSCreatureStats__GetDamageBonus(this, a0, a1);
}

int32_t CNWSCreatureStats::GetDamageRoll(CNWSObject* a0, int32_t a1, int32_t a2, int32_t a3, int32_t a4, int32_t a5)
{
    return CNWSCreatureStats__GetDamageRoll(this, a0, a1, a2, a3, a4, a5);
}

char CNWSCreatureStats::GetDEXMod(int32_t a0)
{
    return CNWSCreatureStats__GetDEXMod(this, a0);
}

unsigned char CNWSCreatureStats::GetDEXStat()
{
    return CNWSCreatureStats__GetDEXStat(this);
}

unsigned char CNWSCreatureStats::GetDomain1(unsigned char a0)
{
    return CNWSCreatureStats__GetDomain1(this, a0);
}

unsigned char CNWSCreatureStats::GetDomain2(unsigned char a0)
{
    return CNWSCreatureStats__GetDomain2(this, a0);
}

int32_t CNWSCreatureStats::GetEffectImmunity(unsigned char a0, CNWSCreature* a1, int32_t a2)
{
    return CNWSCreatureStats__GetEffectImmunity(this, a0, a1, a2);
}

unsigned char CNWSCreatureStats::GetEffectiveCRForPotentialLevel()
{
    return CNWSCreatureStats__GetEffectiveCRForPotentialLevel(this);
}

int32_t CNWSCreatureStats::GetEpicWeaponDevastatingCritical(CNWSItem* a0)
{
    return CNWSCreatureStats__GetEpicWeaponDevastatingCritical(this, a0);
}

int32_t CNWSCreatureStats::GetEpicWeaponFocus(CNWSItem* a0)
{
    return CNWSCreatureStats__GetEpicWeaponFocus(this, a0);
}

int32_t CNWSCreatureStats::GetEpicWeaponOverwhelmingCritical(CNWSItem* a0)
{
    return CNWSCreatureStats__GetEpicWeaponOverwhelmingCritical(this, a0);
}

int32_t CNWSCreatureStats::GetEpicWeaponSpecialization(CNWSItem* a0)
{
    return CNWSCreatureStats__GetEpicWeaponSpecialization(this, a0);
}

uint32_t CNWSCreatureStats::GetExpNeededForLevelUp()
{
    return CNWSCreatureStats__GetExpNeededForLevelUp(this);
}

int32_t CNWSCreatureStats::GetFavoredEnemyBonus(CNWSCreature* a0)
{
    return CNWSCreatureStats__GetFavoredEnemyBonus(this, a0);
}

uint16_t CNWSCreatureStats::GetFeat(uint16_t a0)
{
    return CNWSCreatureStats__GetFeat(this, a0);
}

unsigned char CNWSCreatureStats::GetFeatRemainingUses(uint16_t a0)
{
    return CNWSCreatureStats__GetFeatRemainingUses(this, a0);
}

unsigned char CNWSCreatureStats::GetFeatSourceClass(uint16_t a0)
{
    return CNWSCreatureStats__GetFeatSourceClass(this, a0);
}

unsigned char CNWSCreatureStats::GetFeatTotalUses(uint16_t a0)
{
    return CNWSCreatureStats__GetFeatTotalUses(this, a0);
}

char CNWSCreatureStats::GetFortSavingThrow(int32_t a0)
{
    return CNWSCreatureStats__GetFortSavingThrow(this, a0);
}

CExoString CNWSCreatureStats::GetFullName()
{
    return CNWSCreatureStats__GetFullName(this);
}

int32_t CNWSCreatureStats::GetHasLostClassAbilities(unsigned char a0)
{
    return CNWSCreatureStats__GetHasLostClassAbilities(this, a0);
}

int32_t CNWSCreatureStats::GetHasSilencedSpell(uint32_t a0)
{
    return CNWSCreatureStats__GetHasSilencedSpell(this, a0);
}

int32_t CNWSCreatureStats::GetHasStilledSpell(uint32_t a0)
{
    return CNWSCreatureStats__GetHasStilledSpell(this, a0);
}

uint32_t CNWSCreatureStats::GetHighestLevelKnown()
{
    return CNWSCreatureStats__GetHighestLevelKnown(this);
}

uint16_t CNWSCreatureStats::GetHighestLevelOfFeat(uint16_t a0)
{
    return CNWSCreatureStats__GetHighestLevelOfFeat(this, a0);
}

unsigned char CNWSCreatureStats::GetHitDie(unsigned char a0, unsigned char a1)
{
    return CNWSCreatureStats__GetHitDie(this, a0, a1);
}

unsigned char CNWSCreatureStats::GetINTStat()
{
    return CNWSCreatureStats__GetINTStat(this);
}

unsigned char CNWSCreatureStats::GetIsClass(unsigned char a0)
{
    return CNWSCreatureStats__GetIsClass(this, a0);
}

int32_t CNWSCreatureStats::GetIsClassAvailable(unsigned char a0)
{
    return CNWSCreatureStats__GetIsClassAvailable(this, a0);
}

int32_t CNWSCreatureStats::GetIsDomainSpell(unsigned char a0, unsigned char a1, unsigned char a2)
{
    return CNWSCreatureStats__GetIsDomainSpell(this, a0, a1, a2);
}

int32_t CNWSCreatureStats::GetIsEpitomeOfAlignment()
{
    return CNWSCreatureStats__GetIsEpitomeOfAlignment(this);
}

int32_t CNWSCreatureStats::GetIsInKnownSpellList(unsigned char a0, uint32_t a1)
{
    return CNWSCreatureStats__GetIsInKnownSpellList(this, a0, a1);
}

int32_t CNWSCreatureStats::GetIsInSpellLikeAbilityList(uint32_t a0)
{
    return CNWSCreatureStats__GetIsInSpellLikeAbilityList(this, a0);
}

int32_t CNWSCreatureStats::GetIsWeaponOfChoice(uint32_t a0)
{
    return CNWSCreatureStats__GetIsWeaponOfChoice(this, a0);
}

uint32_t CNWSCreatureStats::GetKnownSpell(unsigned char a0, unsigned char a1, unsigned char a2)
{
    return CNWSCreatureStats__GetKnownSpell(this, a0, a1, a2);
}

CResRef CNWSCreatureStats::GetLargePortrait()
{
    return CNWSCreatureStats__GetLargePortrait(this);
}

unsigned char CNWSCreatureStats::GetLevel(int32_t a0)
{
    return CNWSCreatureStats__GetLevel(this, a0);
}

CNWLevelStats* CNWSCreatureStats::GetLevelStats(unsigned char a0)
{
    return CNWSCreatureStats__GetLevelStats(this, a0);
}

int32_t CNWSCreatureStats::GetMeetsPrestigeClassRequirements(CNWClass* a0)
{
    return CNWSCreatureStats__GetMeetsPrestigeClassRequirements(this, a0);
}

int32_t CNWSCreatureStats::GetMeleeAttackBonus(int32_t a0, int32_t a1, int32_t a2)
{
    return CNWSCreatureStats__GetMeleeAttackBonus(this, a0, a1, a2);
}

int32_t CNWSCreatureStats::GetMeleeDamageBonus(int32_t a0, unsigned char a1)
{
    return CNWSCreatureStats__GetMeleeDamageBonus(this, a0, a1);
}

uint32_t CNWSCreatureStats::GetMemorizedSpellInSlot(unsigned char a0, unsigned char a1, unsigned char a2)
{
    return CNWSCreatureStats__GetMemorizedSpellInSlot(this, a0, a1, a2);
}

unsigned char CNWSCreatureStats::GetMemorizedSpellInSlotMetaType(unsigned char a0, unsigned char a1, unsigned char a2)
{
    return CNWSCreatureStats__GetMemorizedSpellInSlotMetaType(this, a0, a1, a2);
}

unsigned char CNWSCreatureStats::GetMemorizedSpellInSlotReady(unsigned char a0, unsigned char a1, unsigned char a2)
{
    return CNWSCreatureStats__GetMemorizedSpellInSlotReady(this, a0, a1, a2);
}

unsigned char CNWSCreatureStats::GetMemorizedSpellReadyCount(uint32_t a0)
{
    return CNWSCreatureStats__GetMemorizedSpellReadyCount__0(this, a0);
}

unsigned char CNWSCreatureStats::GetMemorizedSpellReadyCount(unsigned char a0, uint32_t a1, unsigned char a2)
{
    return CNWSCreatureStats__GetMemorizedSpellReadyCount__1(this, a0, a1, a2);
}

unsigned char CNWSCreatureStats::GetMemorizedSpellReadyCount(unsigned char a0, uint32_t a1, unsigned char* a2, unsigned char* a3)
{
    return CNWSCreatureStats__GetMemorizedSpellReadyCount__2(this, a0, a1, a2, a3);
}

int32_t CNWSCreatureStats::GetMetamagicPrerequisitesMet(unsigned char a0)
{
    return CNWSCreatureStats__GetMetamagicPrerequisitesMet(this, a0);
}

uint16_t CNWSCreatureStats::GetNumberKnownSpells(unsigned char a0, unsigned char a1)
{
    return CNWSCreatureStats__GetNumberKnownSpells(this, a0, a1);
}

unsigned char CNWSCreatureStats::GetNumberMemorizedSpellSlots(unsigned char a0, unsigned char a1)
{
    return CNWSCreatureStats__GetNumberMemorizedSpellSlots(this, a0, a1);
}

uint32_t CNWSCreatureStats::GetNumberOfBonusSpells(unsigned char a0, unsigned char a1)
{
    return CNWSCreatureStats__GetNumberOfBonusSpells(this, a0, a1);
}

int32_t CNWSCreatureStats::GetNumLevelsOfClass(unsigned char a0)
{
    return CNWSCreatureStats__GetNumLevelsOfClass__0(this, a0);
}

int32_t CNWSCreatureStats::GetNumLevelsOfClass(unsigned char a0, int32_t a1)
{
    return CNWSCreatureStats__GetNumLevelsOfClass__1(this, a0, a1);
}

unsigned char CNWSCreatureStats::GetPotentialLevel()
{
    return CNWSCreatureStats__GetPotentialLevel(this);
}

char CNWSCreatureStats::GetPrimaryMod(unsigned char a0)
{
    return CNWSCreatureStats__GetPrimaryMod(this, a0);
}

CExoString CNWSCreatureStats::GetRaceString()
{
    return CNWSCreatureStats__GetRaceString(this);
}

int32_t CNWSCreatureStats::GetRangedAttackBonus(int32_t a0, int32_t a1)
{
    return CNWSCreatureStats__GetRangedAttackBonus(this, a0, a1);
}

int32_t CNWSCreatureStats::GetRangedDamageBonus()
{
    return CNWSCreatureStats__GetRangedDamageBonus(this);
}

char CNWSCreatureStats::GetReflexSavingThrow(int32_t a0)
{
    return CNWSCreatureStats__GetReflexSavingThrow(this, a0);
}

unsigned char CNWSCreatureStats::GetSchool(unsigned char a0)
{
    return CNWSCreatureStats__GetSchool(this, a0);
}

unsigned char CNWSCreatureStats::GetSimpleAlignmentGoodEvil()
{
    return CNWSCreatureStats__GetSimpleAlignmentGoodEvil(this);
}

unsigned char CNWSCreatureStats::GetSimpleAlignmentLawChaos()
{
    return CNWSCreatureStats__GetSimpleAlignmentLawChaos(this);
}

char CNWSCreatureStats::GetSkillRank(unsigned char a0, CNWSObject* a1, int32_t a2)
{
    return CNWSCreatureStats__GetSkillRank(this, a0, a1, a2);
}

CResRef CNWSCreatureStats::GetSmallPortrait()
{
    return CNWSCreatureStats__GetSmallPortrait(this);
}

unsigned char CNWSCreatureStats::GetSpellFailure(unsigned char a0)
{
    return CNWSCreatureStats__GetSpellFailure(this, a0);
}

unsigned char CNWSCreatureStats::GetSpellGainWithBonus(unsigned char a0, unsigned char a1)
{
    return CNWSCreatureStats__GetSpellGainWithBonus(this, a0, a1);
}

unsigned char CNWSCreatureStats::GetSpellGainWithBonusAfterLevelUp(unsigned char a0, unsigned char a1, CNWLevelStats* a2, unsigned char a3, int32_t a4)
{
    return CNWSCreatureStats__GetSpellGainWithBonusAfterLevelUp(this, a0, a1, a2, a3, a4);
}

unsigned char CNWSCreatureStats::GetSpellLikeAbilityCasterLevel(uint32_t a0)
{
    return CNWSCreatureStats__GetSpellLikeAbilityCasterLevel(this, a0);
}

int32_t CNWSCreatureStats::GetSpellMinAbilityMet(unsigned char a0, unsigned char a1)
{
    return CNWSCreatureStats__GetSpellMinAbilityMet(this, a0, a1);
}

char CNWSCreatureStats::GetSpellResistance()
{
    return CNWSCreatureStats__GetSpellResistance(this);
}

unsigned char CNWSCreatureStats::GetSpellsOfLevelReady(unsigned char a0, unsigned char a1)
{
    return CNWSCreatureStats__GetSpellsOfLevelReady(this, a0, a1);
}

unsigned char CNWSCreatureStats::GetSpellsPerDayLeft(unsigned char a0, unsigned char a1)
{
    return CNWSCreatureStats__GetSpellsPerDayLeft(this, a0, a1);
}

unsigned char CNWSCreatureStats::GetSpellUsesLeft(uint32_t a0, unsigned char a1, unsigned char a2, unsigned char a3)
{
    return CNWSCreatureStats__GetSpellUsesLeft(this, a0, a1, a2, a3);
}

void CNWSCreatureStats::GetStatBonusesFromFeats(CExoArrayListTemplatedunsignedshort* a0, int32_t* a1, unsigned char a2)
{
    return CNWSCreatureStats__GetStatBonusesFromFeats(this, a0, a1, a2);
}

float CNWSCreatureStats::GetStatById(int32_t a0)
{
    return CNWSCreatureStats__GetStatById(this, a0);
}

unsigned char CNWSCreatureStats::GetSTRStat()
{
    return CNWSCreatureStats__GetSTRStat(this);
}

CExoString* CNWSCreatureStats::GetTag()
{
    return CNWSCreatureStats__GetTag(this);
}

char CNWSCreatureStats::GetTotalACSkillMod()
{
    return CNWSCreatureStats__GetTotalACSkillMod(this);
}

char CNWSCreatureStats::GetTotalCHABonus()
{
    return CNWSCreatureStats__GetTotalCHABonus(this);
}

char CNWSCreatureStats::GetTotalCONBonus()
{
    return CNWSCreatureStats__GetTotalCONBonus(this);
}

char CNWSCreatureStats::GetTotalDEXBonus()
{
    return CNWSCreatureStats__GetTotalDEXBonus(this);
}

char CNWSCreatureStats::GetTotalINTBonus()
{
    return CNWSCreatureStats__GetTotalINTBonus(this);
}

int32_t CNWSCreatureStats::GetTotalNegativeLevels()
{
    return CNWSCreatureStats__GetTotalNegativeLevels(this);
}

char CNWSCreatureStats::GetTotalSTRBonus()
{
    return CNWSCreatureStats__GetTotalSTRBonus(this);
}

char CNWSCreatureStats::GetTotalWISBonus()
{
    return CNWSCreatureStats__GetTotalWISBonus(this);
}

unsigned char CNWSCreatureStats::GetUnarmedDamageDice()
{
    return CNWSCreatureStats__GetUnarmedDamageDice(this);
}

unsigned char CNWSCreatureStats::GetUnarmedDamageDie()
{
    return CNWSCreatureStats__GetUnarmedDamageDie(this);
}

int32_t CNWSCreatureStats::GetUnarmedDamageRoll(CNWSObject* a0)
{
    return CNWSCreatureStats__GetUnarmedDamageRoll(this, a0);
}

int32_t CNWSCreatureStats::GetUseMonkAttackTables(int32_t a0)
{
    return CNWSCreatureStats__GetUseMonkAttackTables(this, a0);
}

int32_t CNWSCreatureStats::GetWeaponFinesse(CNWSItem* a0)
{
    return CNWSCreatureStats__GetWeaponFinesse(this, a0);
}

int32_t CNWSCreatureStats::GetWeaponFocus(CNWSItem* a0)
{
    return CNWSCreatureStats__GetWeaponFocus(this, a0);
}

int32_t CNWSCreatureStats::GetWeaponImprovedCritical(CNWSItem* a0)
{
    return CNWSCreatureStats__GetWeaponImprovedCritical(this, a0);
}

int32_t CNWSCreatureStats::GetWeaponSpecialization(CNWSItem* a0)
{
    return CNWSCreatureStats__GetWeaponSpecialization(this, a0);
}

char CNWSCreatureStats::GetWillSavingThrow(int32_t a0)
{
    return CNWSCreatureStats__GetWillSavingThrow(this, a0);
}

unsigned char CNWSCreatureStats::GetWISStat()
{
    return CNWSCreatureStats__GetWISStat(this);
}

int32_t CNWSCreatureStats::HasFeat(uint16_t a0)
{
    return CNWSCreatureStats__HasFeat(this, a0);
}

void CNWSCreatureStats::IncrementFeatRemainingUses(uint16_t a0)
{
    return CNWSCreatureStats__IncrementFeatRemainingUses(this, a0);
}

void CNWSCreatureStats::IncrementSpellsPerDayLeft(unsigned char a0, unsigned char a1)
{
    return CNWSCreatureStats__IncrementSpellsPerDayLeft(this, a0, a1);
}

void CNWSCreatureStats::LevelDown(CNWLevelStats* a0)
{
    return CNWSCreatureStats__LevelDown(this, a0);
}

void CNWSCreatureStats::LevelUp(CNWLevelStats* a0, unsigned char a1, unsigned char a2, unsigned char a3, int32_t a4)
{
    return CNWSCreatureStats__LevelUp(this, a0, a1, a2, a3, a4);
}

int32_t CNWSCreatureStats::LevelUpAutomatic(unsigned char a0, int32_t a1, unsigned char a2)
{
    return CNWSCreatureStats__LevelUpAutomatic(this, a0, a1, a2);
}

int32_t CNWSCreatureStats::ModifyAlignment(int16_t a0, int16_t a1)
{
    return CNWSCreatureStats__ModifyAlignment(this, a0, a1);
}

void CNWSCreatureStats::ModifyNumberBonusSpells(unsigned char a0, unsigned char a1, int32_t a2)
{
    return CNWSCreatureStats__ModifyNumberBonusSpells(this, a0, a1, a2);
}

void CNWSCreatureStats::ReadSpellsFromGff(CResGFF* a0, CResStruct* a1, int32_t a2)
{
    return CNWSCreatureStats__ReadSpellsFromGff(this, a0, a1, a2);
}

uint32_t CNWSCreatureStats::ReadStatsFromGff(CResGFF* a0, CResStruct* a1, CNWSCreatureAppearanceInfo* a2, int32_t a3, int32_t a4, int32_t a5)
{
    return CNWSCreatureStats__ReadStatsFromGff(this, a0, a1, a2, a3, a4, a5);
}

void CNWSCreatureStats::ReadySpellLevel(unsigned char a0)
{
    return CNWSCreatureStats__ReadySpellLevel(this, a0);
}

void CNWSCreatureStats::RemoveFeat(uint16_t a0)
{
    return CNWSCreatureStats__RemoveFeat(this, a0);
}

void CNWSCreatureStats::RemoveKnownSpell(unsigned char a0, uint32_t a1)
{
    return CNWSCreatureStats__RemoveKnownSpell(this, a0, a1);
}

void CNWSCreatureStats::ResetFeatRemainingUses()
{
    return CNWSCreatureStats__ResetFeatRemainingUses(this);
}

void CNWSCreatureStats::ResetSpellLikeAbilities()
{
    return CNWSCreatureStats__ResetSpellLikeAbilities(this);
}

void CNWSCreatureStats::ResetSpellsPerDayLeft(unsigned char a0, unsigned char a1)
{
    return CNWSCreatureStats__ResetSpellsPerDayLeft(this, a0, a1);
}

int32_t CNWSCreatureStats::ResolveSpecialAttackAttackBonus(CNWSCreature* a0)
{
    return CNWSCreatureStats__ResolveSpecialAttackAttackBonus(this, a0);
}

int32_t CNWSCreatureStats::ResolveSpecialAttackDamageBonus(CNWSCreature* a0)
{
    return CNWSCreatureStats__ResolveSpecialAttackDamageBonus(this, a0);
}

void CNWSCreatureStats::SaveClassInfo(CResGFF* a0, CResStruct* a1)
{
    return CNWSCreatureStats__SaveClassInfo(this, a0, a1);
}

void CNWSCreatureStats::SaveStats(CResGFF* a0, CResStruct* a1)
{
    return CNWSCreatureStats__SaveStats(this, a0, a1);
}

void CNWSCreatureStats::SetArcaneSpellFailure(char a0)
{
    return CNWSCreatureStats__SetArcaneSpellFailure(this, a0);
}

void CNWSCreatureStats::SetCHABase(unsigned char a0)
{
    return CNWSCreatureStats__SetCHABase(this, a0);
}

void CNWSCreatureStats::SetClass(unsigned char a0, unsigned char a1)
{
    return CNWSCreatureStats__SetClass(this, a0, a1);
}

void CNWSCreatureStats::SetClassLevel(unsigned char a0, unsigned char a1)
{
    return CNWSCreatureStats__SetClassLevel(this, a0, a1);
}

void CNWSCreatureStats::SetClassNegativeLevels(unsigned char a0, unsigned char a1)
{
    return CNWSCreatureStats__SetClassNegativeLevels(this, a0, a1);
}

void CNWSCreatureStats::SetCONBase(unsigned char a0, int32_t a1)
{
    return CNWSCreatureStats__SetCONBase(this, a0, a1);
}

void CNWSCreatureStats::SetDEXBase(unsigned char a0)
{
    return CNWSCreatureStats__SetDEXBase(this, a0);
}

void CNWSCreatureStats::SetDomain1(unsigned char a0, unsigned char a1)
{
    return CNWSCreatureStats__SetDomain1(this, a0, a1);
}

void CNWSCreatureStats::SetDomain2(unsigned char a0, unsigned char a1)
{
    return CNWSCreatureStats__SetDomain2(this, a0, a1);
}

void CNWSCreatureStats::SetExperience(uint32_t a0, int32_t a1)
{
    return CNWSCreatureStats__SetExperience(this, a0, a1);
}

void CNWSCreatureStats::SetFeatRemainingUses(uint16_t a0, unsigned char a1)
{
    return CNWSCreatureStats__SetFeatRemainingUses(this, a0, a1);
}

void CNWSCreatureStats::SetHasLostClassAbilities(unsigned char a0, int32_t a1)
{
    return CNWSCreatureStats__SetHasLostClassAbilities(this, a0, a1);
}

void CNWSCreatureStats::SetINTBase(unsigned char a0)
{
    return CNWSCreatureStats__SetINTBase(this, a0);
}

void CNWSCreatureStats::SetMemorizedSpellInSlotReady(unsigned char a0, unsigned char a1, unsigned char a2, int32_t a3)
{
    return CNWSCreatureStats__SetMemorizedSpellInSlotReady(this, a0, a1, a2, a3);
}

int32_t CNWSCreatureStats::SetMemorizedSpellSlot(unsigned char a0, unsigned char a1, uint32_t a2, unsigned char a3, unsigned char a4, int32_t a5)
{
    return CNWSCreatureStats__SetMemorizedSpellSlot(this, a0, a1, a2, a3, a4, a5);
}

void CNWSCreatureStats::SetMovementRate(int32_t a0)
{
    return CNWSCreatureStats__SetMovementRate(this, a0);
}

void CNWSCreatureStats::SetNormalBonusFlags(uint16_t a0, int32_t& a1, int32_t& a2)
{
    return CNWSCreatureStats__SetNormalBonusFlags(this, a0, a1, a2);
}

void CNWSCreatureStats::SetNumberMemorizedSpellSlots(unsigned char a0, unsigned char a1, unsigned char a2)
{
    return CNWSCreatureStats__SetNumberMemorizedSpellSlots(this, a0, a1, a2);
}

void CNWSCreatureStats::SetSchool(unsigned char a0, unsigned char a1)
{
    return CNWSCreatureStats__SetSchool(this, a0, a1);
}

void CNWSCreatureStats::SetSkillRank(unsigned char a0, char a1)
{
    return CNWSCreatureStats__SetSkillRank(this, a0, a1);
}

void CNWSCreatureStats::SetSpellFailure(unsigned char a0, unsigned char a1)
{
    return CNWSCreatureStats__SetSpellFailure(this, a0, a1);
}

int32_t CNWSCreatureStats::SetSpellLikeAbilityReady(uint32_t a0, int32_t a1, unsigned char a2)
{
    return CNWSCreatureStats__SetSpellLikeAbilityReady(this, a0, a1, a2);
}

void CNWSCreatureStats::SetSpellResistance(char a0)
{
    return CNWSCreatureStats__SetSpellResistance(this, a0);
}

void CNWSCreatureStats::SetSpellResistancePenalty(char a0)
{
    return CNWSCreatureStats__SetSpellResistancePenalty(this, a0);
}

void CNWSCreatureStats::SetStatById(int32_t a0, float a1)
{
    return CNWSCreatureStats__SetStatById(this, a0, a1);
}

void CNWSCreatureStats::SetSTRBase(unsigned char a0)
{
    return CNWSCreatureStats__SetSTRBase(this, a0);
}

void CNWSCreatureStats::SetTag(const CExoString& a0)
{
    return CNWSCreatureStats__SetTag(this, a0);
}

void CNWSCreatureStats::SetWISBase(unsigned char a0)
{
    return CNWSCreatureStats__SetWISBase(this, a0);
}

int32_t CNWSCreatureStats::UnReadySpell(uint32_t a0, unsigned char a1, unsigned char a2, unsigned char a3)
{
    return CNWSCreatureStats__UnReadySpell(this, a0, a1, a2, a3);
}

void CNWSCreatureStats::UpdateCombatInformation()
{
    return CNWSCreatureStats__UpdateCombatInformation(this);
}

void CNWSCreatureStats::UpdateLastStatsObject(uint64_t a0, CNWCreatureStatsUpdate* a1)
{
    return CNWSCreatureStats__UpdateLastStatsObject(this, a0, a1);
}

void CNWSCreatureStats::UpdateNumberMemorizedSpellSlots()
{
    return CNWSCreatureStats__UpdateNumberMemorizedSpellSlots(this);
}

uint32_t CNWSCreatureStats::ValidateLevelUp(CNWLevelStats* a0, unsigned char a1, unsigned char a2, unsigned char a3)
{
    return CNWSCreatureStats__ValidateLevelUp(this, a0, a1, a2, a3);
}

void CNWSCreatureStats__CNWSCreatureStatsCtor__0(CNWSCreatureStats* thisPtr, CNWSCreature* a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreatureStats*, CNWSCreature*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__CNWSCreatureStatsCtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, a0);
}

void CNWSCreatureStats__CNWSCreatureStatsDtor__0(CNWSCreatureStats* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreatureStats*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__CNWSCreatureStatsDtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

void CNWSCreatureStats__AddExperience(CNWSCreatureStats* thisPtr, uint32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreatureStats*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__AddExperience);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSCreatureStats__AddFeat(CNWSCreatureStats* thisPtr, uint16_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreatureStats*, uint16_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__AddFeat);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSCreatureStats__AddKnownSpell(CNWSCreatureStats* thisPtr, unsigned char a0, uint32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreatureStats*, unsigned char, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__AddKnownSpell);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSCreatureStats__AddSpellLikeAbilityToList(CNWSCreatureStats* thisPtr, uint32_t a0, int32_t a1, unsigned char a2)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreatureStats*, uint32_t, int32_t, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__AddSpellLikeAbilityToList);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

void CNWSCreatureStats__AdjustAlignment(CNWSCreatureStats* thisPtr, unsigned char a0, int16_t a1, uint32_t a2)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreatureStats*, unsigned char, int16_t, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__AdjustAlignment);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

void CNWSCreatureStats__AdjustSpellUsesPerDay(CNWSCreatureStats* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreatureStats*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__AdjustSpellUsesPerDay);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CNWSCreatureStats__AutoMemorizeSpells(CNWSCreatureStats* thisPtr, int32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreatureStats*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__AutoMemorizeSpells);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSCreatureStats__CalcLevelUpNumberFeats(CNWSCreatureStats* thisPtr, unsigned char a0, unsigned char a1, unsigned char& a2, unsigned char& a3)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreatureStats*, unsigned char, unsigned char, unsigned char&, unsigned char&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__CalcLevelUpNumberFeats);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

char CNWSCreatureStats__CalcStatModifier(CNWSCreatureStats* thisPtr, unsigned char a0)
{
    using FuncPtrType = char(__attribute__((cdecl)) *)(CNWSCreatureStats*, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__CalcStatModifier);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSCreatureStats__CanChooseFeat(CNWSCreatureStats* thisPtr, uint16_t a0, unsigned char a1, unsigned char a2, CExoArrayListTemplatedunsignedshort* a3)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreatureStats*, uint16_t, unsigned char, unsigned char, CExoArrayListTemplatedunsignedshort*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__CanChooseFeat);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

int32_t CNWSCreatureStats__CanLevelUp(CNWSCreatureStats* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreatureStats*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__CanLevelUp);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CNWSCreatureStats__CheckSpellSuitability(CNWSCreatureStats* thisPtr, int32_t a0, CNWSpell* a1, int32_t a2, int32_t a3, int32_t a4, int32_t a5, int32_t a6, int32_t a7, unsigned char& a8, int32_t a9)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreatureStats*, int32_t, CNWSpell*, int32_t, int32_t, int32_t, int32_t, int32_t, int32_t, unsigned char&, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__CheckSpellSuitability);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9);
}

void CNWSCreatureStats__ClearFeats(CNWSCreatureStats* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreatureStats*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__ClearFeats);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWSCreatureStats__ClearMemorizedSpellSlot(CNWSCreatureStats* thisPtr, unsigned char a0, unsigned char a1, unsigned char a2)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreatureStats*, unsigned char, unsigned char, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__ClearMemorizedSpellSlot);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

void CNWSCreatureStats__ComputeFeatBonuses(CNWSCreatureStats* thisPtr, CExoArrayListTemplatedunsignedshort* a0, int32_t a1, int32_t a2)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreatureStats*, CExoArrayListTemplatedunsignedshort*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__ComputeFeatBonuses);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

unsigned char CNWSCreatureStats__ComputeNumberKnownSpellsLeft(CNWSCreatureStats* thisPtr, unsigned char a0, unsigned char a1)
{
    using FuncPtrType = unsigned char(__attribute__((cdecl)) *)(CNWSCreatureStats*, unsigned char, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__ComputeNumberKnownSpellsLeft);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSCreatureStats__ConfirmDomainSpell(CNWSCreatureStats* thisPtr, unsigned char a0, unsigned char a1, uint32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreatureStats*, unsigned char, unsigned char, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__ConfirmDomainSpell);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

void CNWSCreatureStats__DecrementFeatRemainingUses(CNWSCreatureStats* thisPtr, uint16_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreatureStats*, uint16_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__DecrementFeatRemainingUses);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSCreatureStats__DecrementSpellsPerDayLeft(CNWSCreatureStats* thisPtr, unsigned char a0, unsigned char a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreatureStats*, unsigned char, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__DecrementSpellsPerDayLeft);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSCreatureStats__FeatAcquired(CNWSCreatureStats* thisPtr, uint16_t a0, CExoArrayListTemplatedunsignedshort* a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreatureStats*, uint16_t, CExoArrayListTemplatedunsignedshort*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__FeatAcquired);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSCreatureStats__FeatRequirementsMet(CNWSCreatureStats* thisPtr, uint16_t a0, CExoArrayListTemplatedunsignedshort* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreatureStats*, uint16_t, CExoArrayListTemplatedunsignedshort*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__FeatRequirementsMet);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSCreatureStats__FeatRequirementsMetAfterLevelUp(CNWSCreatureStats* thisPtr, uint16_t a0, CNWLevelStats* a1, unsigned char a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreatureStats*, uint16_t, CNWLevelStats*, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__FeatRequirementsMetAfterLevelUp);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

void CNWSCreatureStats__GetAbilityModsFromFeats(CNWSCreatureStats* thisPtr, CExoArrayListTemplatedunsignedshort* a0, int32_t* a1, int32_t a2, int32_t a3)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreatureStats*, CExoArrayListTemplatedunsignedshort*, int32_t*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__GetAbilityModsFromFeats);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

char CNWSCreatureStats__GetACNaturalBase(CNWSCreatureStats* thisPtr, int32_t a0)
{
    using FuncPtrType = char(__attribute__((cdecl)) *)(CNWSCreatureStats*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__GetACNaturalBase);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

CExoString CNWSCreatureStats__GetAlignmentString(CNWSCreatureStats* thisPtr)
{
    using FuncPtrType = CExoString(__attribute__((cdecl)) *)(CNWSCreatureStats*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__GetAlignmentString);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int16_t CNWSCreatureStats__GetArmorClassVersus(CNWSCreatureStats* thisPtr, CNWSCreature* a0, int32_t a1)
{
    using FuncPtrType = int16_t(__attribute__((cdecl)) *)(CNWSCreatureStats*, CNWSCreature*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__GetArmorClassVersus);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSCreatureStats__GetAttackModifierVersus(CNWSCreatureStats* thisPtr, CNWSCreature* a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreatureStats*, CNWSCreature*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__GetAttackModifierVersus);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

unsigned char CNWSCreatureStats__GetAttacksPerRound(CNWSCreatureStats* thisPtr)
{
    using FuncPtrType = unsigned char(__attribute__((cdecl)) *)(CNWSCreatureStats*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__GetAttacksPerRound);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CNWSCreatureStats__GetBaseAttackBonus(CNWSCreatureStats* thisPtr, int32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreatureStats*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__GetBaseAttackBonus);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

char CNWSCreatureStats__GetBaseFortSavingThrow(CNWSCreatureStats* thisPtr)
{
    using FuncPtrType = char(__attribute__((cdecl)) *)(CNWSCreatureStats*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__GetBaseFortSavingThrow);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

char CNWSCreatureStats__GetBaseReflexSavingThrow(CNWSCreatureStats* thisPtr)
{
    using FuncPtrType = char(__attribute__((cdecl)) *)(CNWSCreatureStats*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__GetBaseReflexSavingThrow);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

char CNWSCreatureStats__GetBaseWillSavingThrow(CNWSCreatureStats* thisPtr)
{
    using FuncPtrType = char(__attribute__((cdecl)) *)(CNWSCreatureStats*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__GetBaseWillSavingThrow);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

uint16_t CNWSCreatureStats__GetBonusFeat(CNWSCreatureStats* thisPtr, uint16_t a0)
{
    using FuncPtrType = uint16_t(__attribute__((cdecl)) *)(CNWSCreatureStats*, uint16_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__GetBonusFeat);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSCreatureStats__GetCanUseRelatedCategory(CNWSCreatureStats* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreatureStats*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__GetCanUseRelatedCategory);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSCreatureStats__GetCanUseSkill(CNWSCreatureStats* thisPtr, unsigned char a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreatureStats*, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__GetCanUseSkill);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSCreatureStats__GetCanUseSkillAfterLevelUp(CNWSCreatureStats* thisPtr, uint16_t a0, CNWLevelStats* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreatureStats*, uint16_t, CNWLevelStats*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__GetCanUseSkillAfterLevelUp);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

uint16_t CNWSCreatureStats__GetCasterLevel(CNWSCreatureStats* thisPtr, unsigned char a0)
{
    using FuncPtrType = uint16_t(__attribute__((cdecl)) *)(CNWSCreatureStats*, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__GetCasterLevel);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

unsigned char CNWSCreatureStats__GetCHAStat(CNWSCreatureStats* thisPtr)
{
    using FuncPtrType = unsigned char(__attribute__((cdecl)) *)(CNWSCreatureStats*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__GetCHAStat);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

unsigned char CNWSCreatureStats__GetClass(CNWSCreatureStats* thisPtr, unsigned char a0)
{
    using FuncPtrType = unsigned char(__attribute__((cdecl)) *)(CNWSCreatureStats*, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__GetClass);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

CNWSCreatureStats_ClassInfo* CNWSCreatureStats__GetClassInfo(CNWSCreatureStats* thisPtr, unsigned char a0)
{
    using FuncPtrType = CNWSCreatureStats_ClassInfo*(__attribute__((cdecl)) *)(CNWSCreatureStats*, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__GetClassInfo);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

unsigned char CNWSCreatureStats__GetClassLevel(CNWSCreatureStats* thisPtr, unsigned char a0, int32_t a1)
{
    using FuncPtrType = unsigned char(__attribute__((cdecl)) *)(CNWSCreatureStats*, unsigned char, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__GetClassLevel);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

unsigned char CNWSCreatureStats__GetClassNegativeLevels(CNWSCreatureStats* thisPtr, unsigned char a0)
{
    using FuncPtrType = unsigned char(__attribute__((cdecl)) *)(CNWSCreatureStats*, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__GetClassNegativeLevels);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

CExoString CNWSCreatureStats__GetClassString(CNWSCreatureStats* thisPtr, unsigned char a0)
{
    using FuncPtrType = CExoString(__attribute__((cdecl)) *)(CNWSCreatureStats*, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__GetClassString);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

unsigned char CNWSCreatureStats__GetCONStat(CNWSCreatureStats* thisPtr)
{
    using FuncPtrType = unsigned char(__attribute__((cdecl)) *)(CNWSCreatureStats*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__GetCONStat);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

unsigned char CNWSCreatureStats__GetCreatureDamageDice(CNWSCreatureStats* thisPtr, unsigned char a0)
{
    using FuncPtrType = unsigned char(__attribute__((cdecl)) *)(CNWSCreatureStats*, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__GetCreatureDamageDice);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

unsigned char CNWSCreatureStats__GetCreatureDamageDie(CNWSCreatureStats* thisPtr, unsigned char a0)
{
    using FuncPtrType = unsigned char(__attribute__((cdecl)) *)(CNWSCreatureStats*, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__GetCreatureDamageDie);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSCreatureStats__GetCreatureHasTalent(CNWSCreatureStats* thisPtr, int32_t a0, int32_t a1, unsigned char a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreatureStats*, int32_t, int32_t, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__GetCreatureHasTalent);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSCreatureStats__GetCreatureTalentRandom(CNWSCreatureStats* thisPtr, int32_t a0, int32_t a1, int32_t& a2, int32_t& a3, unsigned char& a4, uint32_t& a5, int32_t& a6, unsigned char& a7, unsigned char& a8)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreatureStats*, int32_t, int32_t, int32_t&, int32_t&, unsigned char&, uint32_t&, int32_t&, unsigned char&, unsigned char&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__GetCreatureTalentRandom);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4, a5, a6, a7, a8);
}

int32_t CNWSCreatureStats__GetCreatureTalentRandomFeat(CNWSCreatureStats* thisPtr, int32_t a0, int32_t a1, int32_t& a2, int32_t& a3, unsigned char& a4)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreatureStats*, int32_t, int32_t, int32_t&, int32_t&, unsigned char&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__GetCreatureTalentRandomFeat);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4);
}

int32_t CNWSCreatureStats__GetCreatureTalentRandomKnownSpell(CNWSCreatureStats* thisPtr, int32_t a0, int32_t a1, int32_t& a2, int32_t& a3, unsigned char& a4, int32_t a5)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreatureStats*, int32_t, int32_t, int32_t&, int32_t&, unsigned char&, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__GetCreatureTalentRandomKnownSpell);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4, a5);
}

int32_t CNWSCreatureStats__GetCreatureTalentRandomMemorisedSpell(CNWSCreatureStats* thisPtr, int32_t a0, int32_t a1, int32_t& a2, int32_t& a3, unsigned char& a4, int32_t a5, unsigned char& a6)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreatureStats*, int32_t, int32_t, int32_t&, int32_t&, unsigned char&, int32_t, unsigned char&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__GetCreatureTalentRandomMemorisedSpell);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4, a5, a6);
}

int32_t CNWSCreatureStats__GetCreatureTalentRandomSkill(CNWSCreatureStats* thisPtr, int32_t a0, int32_t a1, int32_t& a2, int32_t& a3, unsigned char& a4)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreatureStats*, int32_t, int32_t, int32_t&, int32_t&, unsigned char&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__GetCreatureTalentRandomSkill);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4);
}

int32_t CNWSCreatureStats__GetCreatureTalentRandomSpell(CNWSCreatureStats* thisPtr, int32_t a0, int32_t a1, int32_t& a2, int32_t& a3, unsigned char& a4, unsigned char& a5)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreatureStats*, int32_t, int32_t, int32_t&, int32_t&, unsigned char&, unsigned char&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__GetCreatureTalentRandomSpell);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4, a5);
}

int32_t CNWSCreatureStats__GetCreatureTalentRandomSpellFromItem(CNWSCreatureStats* thisPtr, int32_t a0, int32_t a1, int32_t& a2, int32_t& a3, unsigned char& a4, uint32_t& a5, int32_t& a6)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreatureStats*, int32_t, int32_t, int32_t&, int32_t&, unsigned char&, uint32_t&, int32_t&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__GetCreatureTalentRandomSpellFromItem);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4, a5, a6);
}

int32_t CNWSCreatureStats__GetCreatureTalentRandomSpellLikeAbility(CNWSCreatureStats* thisPtr, int32_t a0, int32_t a1, int32_t& a2, int32_t& a3, unsigned char& a4, unsigned char& a5)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreatureStats*, int32_t, int32_t, int32_t&, int32_t&, unsigned char&, unsigned char&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__GetCreatureTalentRandomSpellLikeAbility);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4, a5);
}

int32_t CNWSCreatureStats__GetCriticalHitMultiplier(CNWSCreatureStats* thisPtr, int32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreatureStats*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__GetCriticalHitMultiplier);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSCreatureStats__GetCriticalHitRoll(CNWSCreatureStats* thisPtr, int32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreatureStats*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__GetCriticalHitRoll);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSCreatureStats__GetDamageBonus(CNWSCreatureStats* thisPtr, CNWSCreature* a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreatureStats*, CNWSCreature*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__GetDamageBonus);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSCreatureStats__GetDamageRoll(CNWSCreatureStats* thisPtr, CNWSObject* a0, int32_t a1, int32_t a2, int32_t a3, int32_t a4, int32_t a5)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreatureStats*, CNWSObject*, int32_t, int32_t, int32_t, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__GetDamageRoll);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4, a5);
}

char CNWSCreatureStats__GetDEXMod(CNWSCreatureStats* thisPtr, int32_t a0)
{
    using FuncPtrType = char(__attribute__((cdecl)) *)(CNWSCreatureStats*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__GetDEXMod);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

unsigned char CNWSCreatureStats__GetDEXStat(CNWSCreatureStats* thisPtr)
{
    using FuncPtrType = unsigned char(__attribute__((cdecl)) *)(CNWSCreatureStats*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__GetDEXStat);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

unsigned char CNWSCreatureStats__GetDomain1(CNWSCreatureStats* thisPtr, unsigned char a0)
{
    using FuncPtrType = unsigned char(__attribute__((cdecl)) *)(CNWSCreatureStats*, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__GetDomain1);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

unsigned char CNWSCreatureStats__GetDomain2(CNWSCreatureStats* thisPtr, unsigned char a0)
{
    using FuncPtrType = unsigned char(__attribute__((cdecl)) *)(CNWSCreatureStats*, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__GetDomain2);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSCreatureStats__GetEffectImmunity(CNWSCreatureStats* thisPtr, unsigned char a0, CNWSCreature* a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreatureStats*, unsigned char, CNWSCreature*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__GetEffectImmunity);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

unsigned char CNWSCreatureStats__GetEffectiveCRForPotentialLevel(CNWSCreatureStats* thisPtr)
{
    using FuncPtrType = unsigned char(__attribute__((cdecl)) *)(CNWSCreatureStats*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__GetEffectiveCRForPotentialLevel);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CNWSCreatureStats__GetEpicWeaponDevastatingCritical(CNWSCreatureStats* thisPtr, CNWSItem* a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreatureStats*, CNWSItem*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__GetEpicWeaponDevastatingCritical);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSCreatureStats__GetEpicWeaponFocus(CNWSCreatureStats* thisPtr, CNWSItem* a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreatureStats*, CNWSItem*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__GetEpicWeaponFocus);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSCreatureStats__GetEpicWeaponOverwhelmingCritical(CNWSCreatureStats* thisPtr, CNWSItem* a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreatureStats*, CNWSItem*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__GetEpicWeaponOverwhelmingCritical);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSCreatureStats__GetEpicWeaponSpecialization(CNWSCreatureStats* thisPtr, CNWSItem* a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreatureStats*, CNWSItem*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__GetEpicWeaponSpecialization);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

uint32_t CNWSCreatureStats__GetExpNeededForLevelUp(CNWSCreatureStats* thisPtr)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNWSCreatureStats*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__GetExpNeededForLevelUp);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CNWSCreatureStats__GetFavoredEnemyBonus(CNWSCreatureStats* thisPtr, CNWSCreature* a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreatureStats*, CNWSCreature*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__GetFavoredEnemyBonus);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

uint16_t CNWSCreatureStats__GetFeat(CNWSCreatureStats* thisPtr, uint16_t a0)
{
    using FuncPtrType = uint16_t(__attribute__((cdecl)) *)(CNWSCreatureStats*, uint16_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__GetFeat);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

unsigned char CNWSCreatureStats__GetFeatRemainingUses(CNWSCreatureStats* thisPtr, uint16_t a0)
{
    using FuncPtrType = unsigned char(__attribute__((cdecl)) *)(CNWSCreatureStats*, uint16_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__GetFeatRemainingUses);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

unsigned char CNWSCreatureStats__GetFeatSourceClass(CNWSCreatureStats* thisPtr, uint16_t a0)
{
    using FuncPtrType = unsigned char(__attribute__((cdecl)) *)(CNWSCreatureStats*, uint16_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__GetFeatSourceClass);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

unsigned char CNWSCreatureStats__GetFeatTotalUses(CNWSCreatureStats* thisPtr, uint16_t a0)
{
    using FuncPtrType = unsigned char(__attribute__((cdecl)) *)(CNWSCreatureStats*, uint16_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__GetFeatTotalUses);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

char CNWSCreatureStats__GetFortSavingThrow(CNWSCreatureStats* thisPtr, int32_t a0)
{
    using FuncPtrType = char(__attribute__((cdecl)) *)(CNWSCreatureStats*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__GetFortSavingThrow);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

CExoString CNWSCreatureStats__GetFullName(CNWSCreatureStats* thisPtr)
{
    using FuncPtrType = CExoString(__attribute__((cdecl)) *)(CNWSCreatureStats*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__GetFullName);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CNWSCreatureStats__GetHasLostClassAbilities(CNWSCreatureStats* thisPtr, unsigned char a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreatureStats*, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__GetHasLostClassAbilities);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSCreatureStats__GetHasSilencedSpell(CNWSCreatureStats* thisPtr, uint32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreatureStats*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__GetHasSilencedSpell);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSCreatureStats__GetHasStilledSpell(CNWSCreatureStats* thisPtr, uint32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreatureStats*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__GetHasStilledSpell);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

uint32_t CNWSCreatureStats__GetHighestLevelKnown(CNWSCreatureStats* thisPtr)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNWSCreatureStats*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__GetHighestLevelKnown);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

uint16_t CNWSCreatureStats__GetHighestLevelOfFeat(CNWSCreatureStats* thisPtr, uint16_t a0)
{
    using FuncPtrType = uint16_t(__attribute__((cdecl)) *)(CNWSCreatureStats*, uint16_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__GetHighestLevelOfFeat);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

unsigned char CNWSCreatureStats__GetHitDie(CNWSCreatureStats* thisPtr, unsigned char a0, unsigned char a1)
{
    using FuncPtrType = unsigned char(__attribute__((cdecl)) *)(CNWSCreatureStats*, unsigned char, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__GetHitDie);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

unsigned char CNWSCreatureStats__GetINTStat(CNWSCreatureStats* thisPtr)
{
    using FuncPtrType = unsigned char(__attribute__((cdecl)) *)(CNWSCreatureStats*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__GetINTStat);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

unsigned char CNWSCreatureStats__GetIsClass(CNWSCreatureStats* thisPtr, unsigned char a0)
{
    using FuncPtrType = unsigned char(__attribute__((cdecl)) *)(CNWSCreatureStats*, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__GetIsClass);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSCreatureStats__GetIsClassAvailable(CNWSCreatureStats* thisPtr, unsigned char a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreatureStats*, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__GetIsClassAvailable);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSCreatureStats__GetIsDomainSpell(CNWSCreatureStats* thisPtr, unsigned char a0, unsigned char a1, unsigned char a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreatureStats*, unsigned char, unsigned char, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__GetIsDomainSpell);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSCreatureStats__GetIsEpitomeOfAlignment(CNWSCreatureStats* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreatureStats*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__GetIsEpitomeOfAlignment);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CNWSCreatureStats__GetIsInKnownSpellList(CNWSCreatureStats* thisPtr, unsigned char a0, uint32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreatureStats*, unsigned char, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__GetIsInKnownSpellList);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSCreatureStats__GetIsInSpellLikeAbilityList(CNWSCreatureStats* thisPtr, uint32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreatureStats*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__GetIsInSpellLikeAbilityList);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSCreatureStats__GetIsWeaponOfChoice(CNWSCreatureStats* thisPtr, uint32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreatureStats*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__GetIsWeaponOfChoice);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

uint32_t CNWSCreatureStats__GetKnownSpell(CNWSCreatureStats* thisPtr, unsigned char a0, unsigned char a1, unsigned char a2)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNWSCreatureStats*, unsigned char, unsigned char, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__GetKnownSpell);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

CResRef CNWSCreatureStats__GetLargePortrait(CNWSCreatureStats* thisPtr)
{
    using FuncPtrType = CResRef(__attribute__((cdecl)) *)(CNWSCreatureStats*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__GetLargePortrait);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

unsigned char CNWSCreatureStats__GetLevel(CNWSCreatureStats* thisPtr, int32_t a0)
{
    using FuncPtrType = unsigned char(__attribute__((cdecl)) *)(CNWSCreatureStats*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__GetLevel);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

CNWLevelStats* CNWSCreatureStats__GetLevelStats(CNWSCreatureStats* thisPtr, unsigned char a0)
{
    using FuncPtrType = CNWLevelStats*(__attribute__((cdecl)) *)(CNWSCreatureStats*, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__GetLevelStats);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSCreatureStats__GetMeetsPrestigeClassRequirements(CNWSCreatureStats* thisPtr, CNWClass* a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreatureStats*, CNWClass*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__GetMeetsPrestigeClassRequirements);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSCreatureStats__GetMeleeAttackBonus(CNWSCreatureStats* thisPtr, int32_t a0, int32_t a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreatureStats*, int32_t, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__GetMeleeAttackBonus);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSCreatureStats__GetMeleeDamageBonus(CNWSCreatureStats* thisPtr, int32_t a0, unsigned char a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreatureStats*, int32_t, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__GetMeleeDamageBonus);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

uint32_t CNWSCreatureStats__GetMemorizedSpellInSlot(CNWSCreatureStats* thisPtr, unsigned char a0, unsigned char a1, unsigned char a2)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNWSCreatureStats*, unsigned char, unsigned char, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__GetMemorizedSpellInSlot);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

unsigned char CNWSCreatureStats__GetMemorizedSpellInSlotMetaType(CNWSCreatureStats* thisPtr, unsigned char a0, unsigned char a1, unsigned char a2)
{
    using FuncPtrType = unsigned char(__attribute__((cdecl)) *)(CNWSCreatureStats*, unsigned char, unsigned char, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__GetMemorizedSpellInSlotMetaType);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

unsigned char CNWSCreatureStats__GetMemorizedSpellInSlotReady(CNWSCreatureStats* thisPtr, unsigned char a0, unsigned char a1, unsigned char a2)
{
    using FuncPtrType = unsigned char(__attribute__((cdecl)) *)(CNWSCreatureStats*, unsigned char, unsigned char, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__GetMemorizedSpellInSlotReady);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

unsigned char CNWSCreatureStats__GetMemorizedSpellReadyCount__0(CNWSCreatureStats* thisPtr, uint32_t a0)
{
    using FuncPtrType = unsigned char(__attribute__((cdecl)) *)(CNWSCreatureStats*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__GetMemorizedSpellReadyCount__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

unsigned char CNWSCreatureStats__GetMemorizedSpellReadyCount__1(CNWSCreatureStats* thisPtr, unsigned char a0, uint32_t a1, unsigned char a2)
{
    using FuncPtrType = unsigned char(__attribute__((cdecl)) *)(CNWSCreatureStats*, unsigned char, uint32_t, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__GetMemorizedSpellReadyCount__1);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

unsigned char CNWSCreatureStats__GetMemorizedSpellReadyCount__2(CNWSCreatureStats* thisPtr, unsigned char a0, uint32_t a1, unsigned char* a2, unsigned char* a3)
{
    using FuncPtrType = unsigned char(__attribute__((cdecl)) *)(CNWSCreatureStats*, unsigned char, uint32_t, unsigned char*, unsigned char*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__GetMemorizedSpellReadyCount__2);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

int32_t CNWSCreatureStats__GetMetamagicPrerequisitesMet(CNWSCreatureStats* thisPtr, unsigned char a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreatureStats*, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__GetMetamagicPrerequisitesMet);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

uint16_t CNWSCreatureStats__GetNumberKnownSpells(CNWSCreatureStats* thisPtr, unsigned char a0, unsigned char a1)
{
    using FuncPtrType = uint16_t(__attribute__((cdecl)) *)(CNWSCreatureStats*, unsigned char, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__GetNumberKnownSpells);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

unsigned char CNWSCreatureStats__GetNumberMemorizedSpellSlots(CNWSCreatureStats* thisPtr, unsigned char a0, unsigned char a1)
{
    using FuncPtrType = unsigned char(__attribute__((cdecl)) *)(CNWSCreatureStats*, unsigned char, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__GetNumberMemorizedSpellSlots);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

uint32_t CNWSCreatureStats__GetNumberOfBonusSpells(CNWSCreatureStats* thisPtr, unsigned char a0, unsigned char a1)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNWSCreatureStats*, unsigned char, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__GetNumberOfBonusSpells);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSCreatureStats__GetNumLevelsOfClass__0(CNWSCreatureStats* thisPtr, unsigned char a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreatureStats*, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__GetNumLevelsOfClass__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSCreatureStats__GetNumLevelsOfClass__1(CNWSCreatureStats* thisPtr, unsigned char a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreatureStats*, unsigned char, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__GetNumLevelsOfClass__1);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

unsigned char CNWSCreatureStats__GetPotentialLevel(CNWSCreatureStats* thisPtr)
{
    using FuncPtrType = unsigned char(__attribute__((cdecl)) *)(CNWSCreatureStats*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__GetPotentialLevel);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

char CNWSCreatureStats__GetPrimaryMod(CNWSCreatureStats* thisPtr, unsigned char a0)
{
    using FuncPtrType = char(__attribute__((cdecl)) *)(CNWSCreatureStats*, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__GetPrimaryMod);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

CExoString CNWSCreatureStats__GetRaceString(CNWSCreatureStats* thisPtr)
{
    using FuncPtrType = CExoString(__attribute__((cdecl)) *)(CNWSCreatureStats*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__GetRaceString);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CNWSCreatureStats__GetRangedAttackBonus(CNWSCreatureStats* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreatureStats*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__GetRangedAttackBonus);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSCreatureStats__GetRangedDamageBonus(CNWSCreatureStats* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreatureStats*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__GetRangedDamageBonus);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

char CNWSCreatureStats__GetReflexSavingThrow(CNWSCreatureStats* thisPtr, int32_t a0)
{
    using FuncPtrType = char(__attribute__((cdecl)) *)(CNWSCreatureStats*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__GetReflexSavingThrow);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

unsigned char CNWSCreatureStats__GetSchool(CNWSCreatureStats* thisPtr, unsigned char a0)
{
    using FuncPtrType = unsigned char(__attribute__((cdecl)) *)(CNWSCreatureStats*, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__GetSchool);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

unsigned char CNWSCreatureStats__GetSimpleAlignmentGoodEvil(CNWSCreatureStats* thisPtr)
{
    using FuncPtrType = unsigned char(__attribute__((cdecl)) *)(CNWSCreatureStats*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__GetSimpleAlignmentGoodEvil);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

unsigned char CNWSCreatureStats__GetSimpleAlignmentLawChaos(CNWSCreatureStats* thisPtr)
{
    using FuncPtrType = unsigned char(__attribute__((cdecl)) *)(CNWSCreatureStats*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__GetSimpleAlignmentLawChaos);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

char CNWSCreatureStats__GetSkillRank(CNWSCreatureStats* thisPtr, unsigned char a0, CNWSObject* a1, int32_t a2)
{
    using FuncPtrType = char(__attribute__((cdecl)) *)(CNWSCreatureStats*, unsigned char, CNWSObject*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__GetSkillRank);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

CResRef CNWSCreatureStats__GetSmallPortrait(CNWSCreatureStats* thisPtr)
{
    using FuncPtrType = CResRef(__attribute__((cdecl)) *)(CNWSCreatureStats*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__GetSmallPortrait);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

unsigned char CNWSCreatureStats__GetSpellFailure(CNWSCreatureStats* thisPtr, unsigned char a0)
{
    using FuncPtrType = unsigned char(__attribute__((cdecl)) *)(CNWSCreatureStats*, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__GetSpellFailure);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

unsigned char CNWSCreatureStats__GetSpellGainWithBonus(CNWSCreatureStats* thisPtr, unsigned char a0, unsigned char a1)
{
    using FuncPtrType = unsigned char(__attribute__((cdecl)) *)(CNWSCreatureStats*, unsigned char, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__GetSpellGainWithBonus);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

unsigned char CNWSCreatureStats__GetSpellGainWithBonusAfterLevelUp(CNWSCreatureStats* thisPtr, unsigned char a0, unsigned char a1, CNWLevelStats* a2, unsigned char a3, int32_t a4)
{
    using FuncPtrType = unsigned char(__attribute__((cdecl)) *)(CNWSCreatureStats*, unsigned char, unsigned char, CNWLevelStats*, unsigned char, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__GetSpellGainWithBonusAfterLevelUp);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4);
}

unsigned char CNWSCreatureStats__GetSpellLikeAbilityCasterLevel(CNWSCreatureStats* thisPtr, uint32_t a0)
{
    using FuncPtrType = unsigned char(__attribute__((cdecl)) *)(CNWSCreatureStats*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__GetSpellLikeAbilityCasterLevel);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSCreatureStats__GetSpellMinAbilityMet(CNWSCreatureStats* thisPtr, unsigned char a0, unsigned char a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreatureStats*, unsigned char, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__GetSpellMinAbilityMet);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

char CNWSCreatureStats__GetSpellResistance(CNWSCreatureStats* thisPtr)
{
    using FuncPtrType = char(__attribute__((cdecl)) *)(CNWSCreatureStats*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__GetSpellResistance);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

unsigned char CNWSCreatureStats__GetSpellsOfLevelReady(CNWSCreatureStats* thisPtr, unsigned char a0, unsigned char a1)
{
    using FuncPtrType = unsigned char(__attribute__((cdecl)) *)(CNWSCreatureStats*, unsigned char, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__GetSpellsOfLevelReady);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

unsigned char CNWSCreatureStats__GetSpellsPerDayLeft(CNWSCreatureStats* thisPtr, unsigned char a0, unsigned char a1)
{
    using FuncPtrType = unsigned char(__attribute__((cdecl)) *)(CNWSCreatureStats*, unsigned char, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__GetSpellsPerDayLeft);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

unsigned char CNWSCreatureStats__GetSpellUsesLeft(CNWSCreatureStats* thisPtr, uint32_t a0, unsigned char a1, unsigned char a2, unsigned char a3)
{
    using FuncPtrType = unsigned char(__attribute__((cdecl)) *)(CNWSCreatureStats*, uint32_t, unsigned char, unsigned char, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__GetSpellUsesLeft);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

void CNWSCreatureStats__GetStatBonusesFromFeats(CNWSCreatureStats* thisPtr, CExoArrayListTemplatedunsignedshort* a0, int32_t* a1, unsigned char a2)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreatureStats*, CExoArrayListTemplatedunsignedshort*, int32_t*, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__GetStatBonusesFromFeats);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

float CNWSCreatureStats__GetStatById(CNWSCreatureStats* thisPtr, int32_t a0)
{
    using FuncPtrType = float(__attribute__((cdecl)) *)(CNWSCreatureStats*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__GetStatById);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

unsigned char CNWSCreatureStats__GetSTRStat(CNWSCreatureStats* thisPtr)
{
    using FuncPtrType = unsigned char(__attribute__((cdecl)) *)(CNWSCreatureStats*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__GetSTRStat);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

CExoString* CNWSCreatureStats__GetTag(CNWSCreatureStats* thisPtr)
{
    using FuncPtrType = CExoString*(__attribute__((cdecl)) *)(CNWSCreatureStats*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__GetTag);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

char CNWSCreatureStats__GetTotalACSkillMod(CNWSCreatureStats* thisPtr)
{
    using FuncPtrType = char(__attribute__((cdecl)) *)(CNWSCreatureStats*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__GetTotalACSkillMod);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

char CNWSCreatureStats__GetTotalCHABonus(CNWSCreatureStats* thisPtr)
{
    using FuncPtrType = char(__attribute__((cdecl)) *)(CNWSCreatureStats*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__GetTotalCHABonus);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

char CNWSCreatureStats__GetTotalCONBonus(CNWSCreatureStats* thisPtr)
{
    using FuncPtrType = char(__attribute__((cdecl)) *)(CNWSCreatureStats*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__GetTotalCONBonus);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

char CNWSCreatureStats__GetTotalDEXBonus(CNWSCreatureStats* thisPtr)
{
    using FuncPtrType = char(__attribute__((cdecl)) *)(CNWSCreatureStats*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__GetTotalDEXBonus);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

char CNWSCreatureStats__GetTotalINTBonus(CNWSCreatureStats* thisPtr)
{
    using FuncPtrType = char(__attribute__((cdecl)) *)(CNWSCreatureStats*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__GetTotalINTBonus);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CNWSCreatureStats__GetTotalNegativeLevels(CNWSCreatureStats* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreatureStats*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__GetTotalNegativeLevels);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

char CNWSCreatureStats__GetTotalSTRBonus(CNWSCreatureStats* thisPtr)
{
    using FuncPtrType = char(__attribute__((cdecl)) *)(CNWSCreatureStats*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__GetTotalSTRBonus);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

char CNWSCreatureStats__GetTotalWISBonus(CNWSCreatureStats* thisPtr)
{
    using FuncPtrType = char(__attribute__((cdecl)) *)(CNWSCreatureStats*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__GetTotalWISBonus);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

unsigned char CNWSCreatureStats__GetUnarmedDamageDice(CNWSCreatureStats* thisPtr)
{
    using FuncPtrType = unsigned char(__attribute__((cdecl)) *)(CNWSCreatureStats*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__GetUnarmedDamageDice);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

unsigned char CNWSCreatureStats__GetUnarmedDamageDie(CNWSCreatureStats* thisPtr)
{
    using FuncPtrType = unsigned char(__attribute__((cdecl)) *)(CNWSCreatureStats*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__GetUnarmedDamageDie);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CNWSCreatureStats__GetUnarmedDamageRoll(CNWSCreatureStats* thisPtr, CNWSObject* a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreatureStats*, CNWSObject*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__GetUnarmedDamageRoll);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSCreatureStats__GetUseMonkAttackTables(CNWSCreatureStats* thisPtr, int32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreatureStats*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__GetUseMonkAttackTables);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSCreatureStats__GetWeaponFinesse(CNWSCreatureStats* thisPtr, CNWSItem* a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreatureStats*, CNWSItem*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__GetWeaponFinesse);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSCreatureStats__GetWeaponFocus(CNWSCreatureStats* thisPtr, CNWSItem* a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreatureStats*, CNWSItem*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__GetWeaponFocus);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSCreatureStats__GetWeaponImprovedCritical(CNWSCreatureStats* thisPtr, CNWSItem* a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreatureStats*, CNWSItem*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__GetWeaponImprovedCritical);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSCreatureStats__GetWeaponSpecialization(CNWSCreatureStats* thisPtr, CNWSItem* a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreatureStats*, CNWSItem*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__GetWeaponSpecialization);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

char CNWSCreatureStats__GetWillSavingThrow(CNWSCreatureStats* thisPtr, int32_t a0)
{
    using FuncPtrType = char(__attribute__((cdecl)) *)(CNWSCreatureStats*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__GetWillSavingThrow);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

unsigned char CNWSCreatureStats__GetWISStat(CNWSCreatureStats* thisPtr)
{
    using FuncPtrType = unsigned char(__attribute__((cdecl)) *)(CNWSCreatureStats*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__GetWISStat);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CNWSCreatureStats__HasFeat(CNWSCreatureStats* thisPtr, uint16_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreatureStats*, uint16_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__HasFeat);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSCreatureStats__IncrementFeatRemainingUses(CNWSCreatureStats* thisPtr, uint16_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreatureStats*, uint16_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__IncrementFeatRemainingUses);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSCreatureStats__IncrementSpellsPerDayLeft(CNWSCreatureStats* thisPtr, unsigned char a0, unsigned char a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreatureStats*, unsigned char, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__IncrementSpellsPerDayLeft);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSCreatureStats__LevelDown(CNWSCreatureStats* thisPtr, CNWLevelStats* a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreatureStats*, CNWLevelStats*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__LevelDown);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSCreatureStats__LevelUp(CNWSCreatureStats* thisPtr, CNWLevelStats* a0, unsigned char a1, unsigned char a2, unsigned char a3, int32_t a4)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreatureStats*, CNWLevelStats*, unsigned char, unsigned char, unsigned char, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__LevelUp);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4);
}

int32_t CNWSCreatureStats__LevelUpAutomatic(CNWSCreatureStats* thisPtr, unsigned char a0, int32_t a1, unsigned char a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreatureStats*, unsigned char, int32_t, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__LevelUpAutomatic);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSCreatureStats__ModifyAlignment(CNWSCreatureStats* thisPtr, int16_t a0, int16_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreatureStats*, int16_t, int16_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__ModifyAlignment);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSCreatureStats__ModifyNumberBonusSpells(CNWSCreatureStats* thisPtr, unsigned char a0, unsigned char a1, int32_t a2)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreatureStats*, unsigned char, unsigned char, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__ModifyNumberBonusSpells);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

void CNWSCreatureStats__ReadSpellsFromGff(CNWSCreatureStats* thisPtr, CResGFF* a0, CResStruct* a1, int32_t a2)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreatureStats*, CResGFF*, CResStruct*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__ReadSpellsFromGff);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

uint32_t CNWSCreatureStats__ReadStatsFromGff(CNWSCreatureStats* thisPtr, CResGFF* a0, CResStruct* a1, CNWSCreatureAppearanceInfo* a2, int32_t a3, int32_t a4, int32_t a5)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNWSCreatureStats*, CResGFF*, CResStruct*, CNWSCreatureAppearanceInfo*, int32_t, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__ReadStatsFromGff);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4, a5);
}

void CNWSCreatureStats__ReadySpellLevel(CNWSCreatureStats* thisPtr, unsigned char a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreatureStats*, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__ReadySpellLevel);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSCreatureStats__RemoveFeat(CNWSCreatureStats* thisPtr, uint16_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreatureStats*, uint16_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__RemoveFeat);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSCreatureStats__RemoveKnownSpell(CNWSCreatureStats* thisPtr, unsigned char a0, uint32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreatureStats*, unsigned char, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__RemoveKnownSpell);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSCreatureStats__ResetFeatRemainingUses(CNWSCreatureStats* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreatureStats*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__ResetFeatRemainingUses);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWSCreatureStats__ResetSpellLikeAbilities(CNWSCreatureStats* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreatureStats*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__ResetSpellLikeAbilities);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWSCreatureStats__ResetSpellsPerDayLeft(CNWSCreatureStats* thisPtr, unsigned char a0, unsigned char a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreatureStats*, unsigned char, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__ResetSpellsPerDayLeft);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSCreatureStats__ResolveSpecialAttackAttackBonus(CNWSCreatureStats* thisPtr, CNWSCreature* a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreatureStats*, CNWSCreature*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__ResolveSpecialAttackAttackBonus);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSCreatureStats__ResolveSpecialAttackDamageBonus(CNWSCreatureStats* thisPtr, CNWSCreature* a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreatureStats*, CNWSCreature*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__ResolveSpecialAttackDamageBonus);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSCreatureStats__SaveClassInfo(CNWSCreatureStats* thisPtr, CResGFF* a0, CResStruct* a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreatureStats*, CResGFF*, CResStruct*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__SaveClassInfo);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSCreatureStats__SaveStats(CNWSCreatureStats* thisPtr, CResGFF* a0, CResStruct* a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreatureStats*, CResGFF*, CResStruct*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__SaveStats);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSCreatureStats__SetArcaneSpellFailure(CNWSCreatureStats* thisPtr, char a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreatureStats*, char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__SetArcaneSpellFailure);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSCreatureStats__SetCHABase(CNWSCreatureStats* thisPtr, unsigned char a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreatureStats*, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__SetCHABase);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSCreatureStats__SetClass(CNWSCreatureStats* thisPtr, unsigned char a0, unsigned char a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreatureStats*, unsigned char, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__SetClass);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSCreatureStats__SetClassLevel(CNWSCreatureStats* thisPtr, unsigned char a0, unsigned char a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreatureStats*, unsigned char, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__SetClassLevel);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSCreatureStats__SetClassNegativeLevels(CNWSCreatureStats* thisPtr, unsigned char a0, unsigned char a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreatureStats*, unsigned char, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__SetClassNegativeLevels);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSCreatureStats__SetCONBase(CNWSCreatureStats* thisPtr, unsigned char a0, int32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreatureStats*, unsigned char, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__SetCONBase);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSCreatureStats__SetDEXBase(CNWSCreatureStats* thisPtr, unsigned char a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreatureStats*, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__SetDEXBase);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSCreatureStats__SetDomain1(CNWSCreatureStats* thisPtr, unsigned char a0, unsigned char a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreatureStats*, unsigned char, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__SetDomain1);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSCreatureStats__SetDomain2(CNWSCreatureStats* thisPtr, unsigned char a0, unsigned char a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreatureStats*, unsigned char, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__SetDomain2);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSCreatureStats__SetExperience(CNWSCreatureStats* thisPtr, uint32_t a0, int32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreatureStats*, uint32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__SetExperience);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSCreatureStats__SetFeatRemainingUses(CNWSCreatureStats* thisPtr, uint16_t a0, unsigned char a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreatureStats*, uint16_t, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__SetFeatRemainingUses);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSCreatureStats__SetHasLostClassAbilities(CNWSCreatureStats* thisPtr, unsigned char a0, int32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreatureStats*, unsigned char, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__SetHasLostClassAbilities);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSCreatureStats__SetINTBase(CNWSCreatureStats* thisPtr, unsigned char a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreatureStats*, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__SetINTBase);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSCreatureStats__SetMemorizedSpellInSlotReady(CNWSCreatureStats* thisPtr, unsigned char a0, unsigned char a1, unsigned char a2, int32_t a3)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreatureStats*, unsigned char, unsigned char, unsigned char, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__SetMemorizedSpellInSlotReady);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

int32_t CNWSCreatureStats__SetMemorizedSpellSlot(CNWSCreatureStats* thisPtr, unsigned char a0, unsigned char a1, uint32_t a2, unsigned char a3, unsigned char a4, int32_t a5)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreatureStats*, unsigned char, unsigned char, uint32_t, unsigned char, unsigned char, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__SetMemorizedSpellSlot);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4, a5);
}

void CNWSCreatureStats__SetMovementRate(CNWSCreatureStats* thisPtr, int32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreatureStats*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__SetMovementRate);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSCreatureStats__SetNormalBonusFlags(CNWSCreatureStats* thisPtr, uint16_t a0, int32_t& a1, int32_t& a2)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreatureStats*, uint16_t, int32_t&, int32_t&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__SetNormalBonusFlags);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

void CNWSCreatureStats__SetNumberMemorizedSpellSlots(CNWSCreatureStats* thisPtr, unsigned char a0, unsigned char a1, unsigned char a2)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreatureStats*, unsigned char, unsigned char, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__SetNumberMemorizedSpellSlots);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

void CNWSCreatureStats__SetSchool(CNWSCreatureStats* thisPtr, unsigned char a0, unsigned char a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreatureStats*, unsigned char, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__SetSchool);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSCreatureStats__SetSkillRank(CNWSCreatureStats* thisPtr, unsigned char a0, char a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreatureStats*, unsigned char, char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__SetSkillRank);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSCreatureStats__SetSpellFailure(CNWSCreatureStats* thisPtr, unsigned char a0, unsigned char a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreatureStats*, unsigned char, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__SetSpellFailure);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSCreatureStats__SetSpellLikeAbilityReady(CNWSCreatureStats* thisPtr, uint32_t a0, int32_t a1, unsigned char a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreatureStats*, uint32_t, int32_t, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__SetSpellLikeAbilityReady);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

void CNWSCreatureStats__SetSpellResistance(CNWSCreatureStats* thisPtr, char a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreatureStats*, char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__SetSpellResistance);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSCreatureStats__SetSpellResistancePenalty(CNWSCreatureStats* thisPtr, char a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreatureStats*, char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__SetSpellResistancePenalty);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSCreatureStats__SetStatById(CNWSCreatureStats* thisPtr, int32_t a0, float a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreatureStats*, int32_t, float);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__SetStatById);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSCreatureStats__SetSTRBase(CNWSCreatureStats* thisPtr, unsigned char a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreatureStats*, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__SetSTRBase);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSCreatureStats__SetTag(CNWSCreatureStats* thisPtr, const CExoString& a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreatureStats*, const CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__SetTag);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSCreatureStats__SetWISBase(CNWSCreatureStats* thisPtr, unsigned char a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreatureStats*, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__SetWISBase);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSCreatureStats__UnReadySpell(CNWSCreatureStats* thisPtr, uint32_t a0, unsigned char a1, unsigned char a2, unsigned char a3)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreatureStats*, uint32_t, unsigned char, unsigned char, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__UnReadySpell);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

void CNWSCreatureStats__UpdateCombatInformation(CNWSCreatureStats* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreatureStats*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__UpdateCombatInformation);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWSCreatureStats__UpdateLastStatsObject(CNWSCreatureStats* thisPtr, uint64_t a0, CNWCreatureStatsUpdate* a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreatureStats*, uint64_t, CNWCreatureStatsUpdate*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__UpdateLastStatsObject);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSCreatureStats__UpdateNumberMemorizedSpellSlots(CNWSCreatureStats* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreatureStats*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__UpdateNumberMemorizedSpellSlots);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

uint32_t CNWSCreatureStats__ValidateLevelUp(CNWSCreatureStats* thisPtr, CNWLevelStats* a0, unsigned char a1, unsigned char a2, unsigned char a3)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNWSCreatureStats*, CNWLevelStats*, unsigned char, unsigned char, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats__ValidateLevelUp);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

}

}
