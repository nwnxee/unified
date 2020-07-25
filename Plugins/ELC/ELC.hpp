#pragma once

#include "Plugin.hpp"
#include "Services/Events/Events.hpp"
#include "Services/Hooks/Hooks.hpp"

using ArgumentStack = NWNXLib::Services::Events::ArgumentStack;

namespace ELC {

namespace ValidationFailureType
{
    enum TYPE
    {
        None = 0,
        Character,
        Item,
        Skill,
        Feat,
        Spell,
        Custom
    };
}

namespace ValidationFailureSubType
{
    enum TYPE
    {
        None = 0,
        ServerLevelRestriction,
        LevelHack,
        ColoredName,
        UnidentifiedEquippedItem,
        MinEquipLevel,
        NonPCCharacter,
        DMCharacter,
        NonPlayerRace,
        NonPlayerClass,
        ClassLevelRestriction,
        PrestigeClassRequirements,
        ClassAlignmentRestriction,
        StartingAbilityValueMax,
        AbilityPointBuySystemCalculation,
        ClassSpellcasterInvalidPrimaryStat,
        EpicLevelFlag,
        TooManyHitPoints,
        UnusableSkill,
        NotEnoughSkillPoints,
        InvalidNumRanksInClassSkill,
        InvalidNumRanksInNonClassSkill,
        InvalidNumRemainingSkillPoints,
        InvalidFeat,
        FeatRequiredSpellLevelNotMet,
        FeatRequiredBaseAttackBonusNotMet,
        FeatRequiredAbilityValueNotMet,
        FeatRequiredSkillNotMet,
        FeatRequiredFeatNotMet,
        TooManyFeatsThisLevel,
        FeatNotAvailableToClass,
        FeatIsNormalFeatOnly,
        FeatIsBonusFeatOnly,
        SpellInvalidSpellGainWizard,
        SpellInvalidSpellGainBardSorcerer,
        SpellInvalidSpellGainOtherClasses,
        InvalidSpell,
        SpellInvalidSpellLevel,
        SpellMinimumAbilityBardSorcerer_Unused,
        SpellMinimumAbilityWizard_Unused,
        SpellMinimumAbility,
        SpellRestrictedSpellSchool,
        SpellAlreadyKnown,
        SpellWizardExceedsNumSpellsToAdd,
        IllegalRemovedSpell,
        RemovedNotKnownSpell,
        InvalidNumSpells,
        SpellListComparison,
        SkillListComparison,
        FeatListComparison,
        MiscSavingThrow,
        NumFeatComparison
    };
}

class ELC : public NWNXLib::Plugin
{
public:
    ELC(NWNXLib::Services::ProxyServiceList* services);
    virtual ~ELC();

private:
    std::string m_elcScript;
    bool m_enableCustomELCCheck;
    bool m_enforceDefaultEventScripts;
    bool m_enforceEmptyDialogResRef;
    uint32_t m_elcDepth;
    bool m_skipValidationFailure;
    int32_t m_validationFailureType;
    int32_t m_validationFailureSubType;
    int32_t m_validationFailureMessageStrRef;

    ObjectID m_ILRItemOID;
    int32_t m_ELCLevel;
    int32_t m_ELCSkillID;
    int32_t m_ELCFeatID;
    int32_t m_ELCSpellID;

    static int32_t ValidateCharacterHook(CNWSPlayer*, int32_t*);

    ArgumentStack SetELCScript                      (ArgumentStack&& args);
    ArgumentStack EnableCustomELCCheck              (ArgumentStack&& args);
    ArgumentStack SkipValidationFailure             (ArgumentStack&& args);
    ArgumentStack GetValidationFailureType          (ArgumentStack&& args);
    ArgumentStack GetValidationFailureSubType       (ArgumentStack&& args);
    ArgumentStack GetValidationFailureMessageStrRef (ArgumentStack&& args);
    ArgumentStack SetValidationFailureMessageStrRef (ArgumentStack&& args);
    ArgumentStack GetValidationFailureItem          (ArgumentStack&& args);
    ArgumentStack GetValidationFailureLevel         (ArgumentStack&& args);
    ArgumentStack GetValidationFailureSkillID       (ArgumentStack&& args);
    ArgumentStack GetValidationFailureFeatID        (ArgumentStack&& args);
    ArgumentStack GetValidationFailureSpellID       (ArgumentStack&& args);
};

}
