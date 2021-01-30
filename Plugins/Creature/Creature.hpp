#pragma once

#include "nwnx.hpp"
#include "API/CNWSCreature.hpp"

using ArgumentStack = NWNXLib::Events::ArgumentStack;

namespace Creature {

class Creature : public NWNXLib::Plugin
{
public:
    Creature(NWNXLib::Services::ProxyServiceList* services);
    virtual ~Creature();

private:
    ArgumentStack AddFeat                       (ArgumentStack&& args);
    ArgumentStack AddFeatByLevel                (ArgumentStack&& args);
    ArgumentStack RemoveFeat                    (ArgumentStack&& args);
    ArgumentStack GetKnowsFeat                  (ArgumentStack&& args);
    ArgumentStack GetFeatCountByLevel           (ArgumentStack&& args);
    ArgumentStack GetFeatByLevel                (ArgumentStack&& args);
    ArgumentStack GetFeatGrantLevel             (ArgumentStack&& args);
    ArgumentStack GetFeatCount                  (ArgumentStack&& args);
    ArgumentStack GetFeatByIndex                (ArgumentStack&& args);
    ArgumentStack GetMeetsFeatRequirements      (ArgumentStack&& args);
    ArgumentStack GetSpecialAbility             (ArgumentStack&& args);
    ArgumentStack GetSpecialAbilityCount        (ArgumentStack&& args);
    ArgumentStack AddSpecialAbility             (ArgumentStack&& args);
    ArgumentStack RemoveSpecialAbility          (ArgumentStack&& args);
    ArgumentStack SetSpecialAbility             (ArgumentStack&& args);
    ArgumentStack GetClassByLevel               (ArgumentStack&& args);
    ArgumentStack SetBaseAC                     (ArgumentStack&& args);
    ArgumentStack GetBaseAC                     (ArgumentStack&& args);
    ArgumentStack SetRawAbilityScore            (ArgumentStack&& args);
    ArgumentStack GetRawAbilityScore            (ArgumentStack&& args);
    ArgumentStack ModifyRawAbilityScore         (ArgumentStack&& args);
    ArgumentStack GetPrePolymorphAbilityScore   (ArgumentStack&& args);
    ArgumentStack GetMemorisedSpell             (ArgumentStack&& args);
    ArgumentStack GetMemorisedSpellCountByLevel (ArgumentStack&& args);
    ArgumentStack SetMemorisedSpell             (ArgumentStack&& args);
    ArgumentStack GetRemainingSpellSlots        (ArgumentStack&& args);
    ArgumentStack SetRemainingSpellSlots        (ArgumentStack&& args);
    ArgumentStack GetMaxSpellSlots              (ArgumentStack&& args);
    ArgumentStack GetKnownSpell                 (ArgumentStack&& args);
    ArgumentStack GetKnownSpellCount            (ArgumentStack&& args);
    ArgumentStack RemoveKnownSpell              (ArgumentStack&& args);
    ArgumentStack AddKnownSpell                 (ArgumentStack&& args);
    ArgumentStack ClearMemorisedKnownSpells     (ArgumentStack&& args);
    ArgumentStack ClearMemorisedSpell           (ArgumentStack&& args);
    ArgumentStack GetMaxHitPointsByLevel        (ArgumentStack&& args);
    ArgumentStack SetMaxHitPointsByLevel        (ArgumentStack&& args);
    ArgumentStack SetMovementRate               (ArgumentStack&& args);
    ArgumentStack GetMovementRateFactor         (ArgumentStack&& args);
    ArgumentStack SetMovementRateFactor         (ArgumentStack&& args);
    ArgumentStack SetMovementRateFactorCap      (ArgumentStack&& args);
    ArgumentStack SetAlignmentGoodEvil          (ArgumentStack&& args);
    ArgumentStack SetAlignmentLawChaos          (ArgumentStack&& args);
    ArgumentStack SetDomain                     (ArgumentStack&& args);
    ArgumentStack SetSpecialization             (ArgumentStack&& args);
    ArgumentStack GetSoundset                   (ArgumentStack&& args);
    ArgumentStack SetSoundset                   (ArgumentStack&& args);
    ArgumentStack SetSkillRank                  (ArgumentStack&& args);
    ArgumentStack SetClassByPosition            (ArgumentStack&& args);
    ArgumentStack SetLevelByPosition            (ArgumentStack&& args);
    ArgumentStack SetBaseAttackBonus            (ArgumentStack&& args);
    ArgumentStack GetAttacksPerRound            (ArgumentStack&& args);
    ArgumentStack SetGender                     (ArgumentStack&& args);
    ArgumentStack RestoreFeats                  (ArgumentStack&& args);
    ArgumentStack RestoreSpecialAbilities       (ArgumentStack&& args);
    ArgumentStack RestoreSpells                 (ArgumentStack&& args);
    ArgumentStack RestoreItems                  (ArgumentStack&& args);
    ArgumentStack SetSize                       (ArgumentStack&& args);
    ArgumentStack GetSkillPointsRemaining       (ArgumentStack&& args);
    ArgumentStack SetSkillPointsRemaining       (ArgumentStack&& args);
    ArgumentStack SetRacialType                 (ArgumentStack&& args);
    ArgumentStack GetMovementType               (ArgumentStack&& args);
    ArgumentStack SetWalkRateCap                (ArgumentStack&& args);
    ArgumentStack SetGold                       (ArgumentStack&& args);
    ArgumentStack SetCorpseDecayTime            (ArgumentStack&& args);
    ArgumentStack GetBaseSavingThrow            (ArgumentStack&& args);
    ArgumentStack SetBaseSavingThrow            (ArgumentStack&& args);
    ArgumentStack LevelUp                       (ArgumentStack&& args);
    ArgumentStack LevelDown                     (ArgumentStack&& args);
    ArgumentStack SetChallengeRating            (ArgumentStack&& args);
    ArgumentStack GetAttackBonus                (ArgumentStack&& args);
    ArgumentStack GetHighestLevelOfFeat         (ArgumentStack&& args);
    ArgumentStack GetFeatRemainingUses          (ArgumentStack&& args);
    ArgumentStack GetFeatTotalUses              (ArgumentStack&& args);
    ArgumentStack SetFeatRemainingUses          (ArgumentStack&& args);
    ArgumentStack GetTotalEffectBonus           (ArgumentStack&& args);
    ArgumentStack SetOriginalName               (ArgumentStack&& args);
    ArgumentStack GetOriginalName               (ArgumentStack&& args);
    ArgumentStack SetSpellResistance            (ArgumentStack&& args);
    ArgumentStack SetAnimalCompanionCreatureType(ArgumentStack&& args);
    ArgumentStack SetFamiliarCreatureType       (ArgumentStack&& args);
    ArgumentStack SetAnimalCompanionName        (ArgumentStack&& args);
    ArgumentStack SetFamiliarName               (ArgumentStack&& args);
    ArgumentStack GetDisarmable                 (ArgumentStack&& args);
    ArgumentStack SetDisarmable                 (ArgumentStack&& args);
    ArgumentStack SetFaction                    (ArgumentStack&& args);
    ArgumentStack GetFaction                    (ArgumentStack&& args);
    ArgumentStack GetFlatFooted                 (ArgumentStack&& args);
    ArgumentStack SerializeQuickbar             (ArgumentStack&& args);
    ArgumentStack DeserializeQuickbar           (ArgumentStack&& args);
    ArgumentStack SetCasterLevelModifier        (ArgumentStack&& args);
    ArgumentStack GetCasterLevelModifier        (ArgumentStack&& args);
    ArgumentStack SetCasterLevelOverride        (ArgumentStack&& args);
    ArgumentStack GetCasterLevelOverride        (ArgumentStack&& args);
    ArgumentStack JumpToLimbo                   (ArgumentStack&& args);
    ArgumentStack SetCriticalMultiplierModifier (ArgumentStack&& args);
    ArgumentStack GetCriticalMultiplierModifier (ArgumentStack&& args);
    ArgumentStack SetCriticalMultiplierOverride (ArgumentStack&& args);
    ArgumentStack GetCriticalMultiplierOverride (ArgumentStack&& args);
    ArgumentStack SetCriticalRangeModifier      (ArgumentStack&& args);
    ArgumentStack GetCriticalRangeModifier      (ArgumentStack&& args);
    ArgumentStack SetCriticalRangeOverride      (ArgumentStack&& args);
    ArgumentStack GetCriticalRangeOverride      (ArgumentStack&& args);
    ArgumentStack AddAssociate                  (ArgumentStack&& args);
    ArgumentStack SetLastItemCasterLevel        (ArgumentStack&& args);
    ArgumentStack GetLastItemCasterLevel        (ArgumentStack&& args);
    ArgumentStack GetArmorClassVersus           (ArgumentStack&& args);
    ArgumentStack SetEffectIconFlashing         (ArgumentStack&& args);
    ArgumentStack OverrideDamageLevel           (ArgumentStack&& args);
    ArgumentStack SetEncounter                  (ArgumentStack&& args);
    ArgumentStack GetEncounter                  (ArgumentStack&& args);
    ArgumentStack GetIsBartering                (ArgumentStack&& args);
    ArgumentStack GetWalkAnimation              (ArgumentStack&& args);
    ArgumentStack SetWalkAnimation              (ArgumentStack&& args);
    ArgumentStack SetAttackRollOverride         (ArgumentStack&& args);
    ArgumentStack SetParryAllAttacks            (ArgumentStack&& args);
    ArgumentStack GetNoPermanentDeath           (ArgumentStack&& args);
    ArgumentStack SetNoPermanentDeath           (ArgumentStack&& args);
    ArgumentStack ComputeSafeLocation           (ArgumentStack&& args);
    ArgumentStack DoPerceptionUpdateOnCreature  (ArgumentStack&& args);
    ArgumentStack GetPersonalSpace              (ArgumentStack&& args);
    ArgumentStack SetPersonalSpace              (ArgumentStack&& args);
    ArgumentStack GetCreaturePersonalSpace      (ArgumentStack&& args);
    ArgumentStack SetCreaturePersonalSpace      (ArgumentStack&& args);
    ArgumentStack GetHeight                     (ArgumentStack&& args);
    ArgumentStack SetHeight                     (ArgumentStack&& args);
    ArgumentStack GetHitDistance                (ArgumentStack&& args);
    ArgumentStack SetHitDistance                (ArgumentStack&& args);
    ArgumentStack GetPreferredAttackDistance    (ArgumentStack&& args);
    ArgumentStack SetPreferredAttackDistance    (ArgumentStack&& args);

    CNWSCreature *creature(ArgumentStack& args);
    std::unordered_map<uint8_t, std::unordered_map<ObjectID, int16_t>> m_RollModifier;
    std::unordered_map<ObjectID, bool> m_ParryAllAttacks;

private:
    static bool s_bAdjustCasterLevel;
    static bool s_bCasterLevelHooksInitialized;
    static bool s_bCriticalMultiplierHooksInitialized;
    static bool s_bCriticalRangeHooksInitialized;
    static bool s_bResolveAttackRollHookInitialized;

    static void InitCasterLevelHooks();
    static uint8_t CNWSCreatureStats__GetClassLevel(CNWSCreatureStats*, uint8_t, BOOL);
    static void InitCriticalMultiplierHook();
    static void InitCriticalRangeHook();
    static void DoResolveAttackHook(CNWSCreature* thisPtr, CNWSObject* pTarget);
    static void InitResolveAttackRollHook();

};

}
