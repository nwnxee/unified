#pragma once

#include "Plugin.hpp"
#include "Services/Events/Events.hpp"
#include "API/Types.hpp"
#include "API/CNWSCreature.hpp"

using ArgumentStack = NWNXLib::Services::Events::ArgumentStack;

namespace Creature {

class Creature : public NWNXLib::Plugin
{
public:
    Creature(const Plugin::CreateParams& params);
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

    CNWSCreature *creature(ArgumentStack& args);

};

}
