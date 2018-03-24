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
    ArgumentStack GetMaxHitPointsByLevel        (ArgumentStack&& args);
    ArgumentStack SetMaxHitPointsByLevel        (ArgumentStack&& args);
    ArgumentStack SetMovementRate               (ArgumentStack&& args);
    ArgumentStack SetAlignmentGoodEvil          (ArgumentStack&& args);
    ArgumentStack SetAlignmentLawChaos          (ArgumentStack&& args);
    ArgumentStack GetClericDomain               (ArgumentStack&& args);
    ArgumentStack SetClericDomain               (ArgumentStack&& args);
    ArgumentStack GetWizardSpecialization       (ArgumentStack&& args);
    ArgumentStack SetWizardSpecialization       (ArgumentStack&& args);
    ArgumentStack GetSoundset                   (ArgumentStack&& args);
    ArgumentStack SetSoundset                   (ArgumentStack&& args);
    ArgumentStack SetSkillRank                  (ArgumentStack&& args);
    ArgumentStack SetClassByPosition            (ArgumentStack&& args);
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

    NWNXLib::API::CNWSCreature *creature(ArgumentStack& args);

};

}
