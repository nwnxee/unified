#include "nwnx_creature"
#include "nwnx_tests"

const int FEAT_BARBARIAN_RAGE_2 = 326;

void main()
{
    WriteTimestampedLogEntry("NWNX_Creature unit test begin..");

    object oCreature = CreateObject(OBJECT_TYPE_CREATURE, "nw_chicken", GetStartingLocation());
    if (!GetIsObjectValid(oCreature))
    {
        WriteTimestampedLogEntry("NWNX_Creature test: Failed to create creature");
        return;
    }

    //
    // Personal space related functions
    //

    NWNX_Creature_SetPersonalSpace(oCreature, 0.5);
    NWNX_Tests_Report("NWNX_Creature", "{Set/Get}PersonalSpace", NWNX_Creature_GetPersonalSpace(oCreature) == 0.5);

    NWNX_Creature_SetCreaturePersonalSpace(oCreature, 0.25);
    NWNX_Tests_Report("NWNX_Creature", "{Set/Get}CreaturePersonalSpace", NWNX_Creature_GetCreaturePersonalSpace(oCreature) == 0.25);

    NWNX_Creature_SetHeight(oCreature, 0.4);
    NWNX_Tests_Report("NWNX_Creature", "{Set/Get}Height", NWNX_Creature_GetHeight(oCreature) == 0.4);

    NWNX_Creature_SetHitDistance(oCreature, 0.3);
    NWNX_Tests_Report("NWNX_Creature", "{Set/Get}HitDistance", NWNX_Creature_GetHitDistance(oCreature) == 0.3);

    NWNX_Creature_SetPreferredAttackDistance(oCreature, 1.1);
    NWNX_Tests_Report("NWNX_Creature", "{Set/Get}PreferredAttackDistance", NWNX_Creature_GetPreferredAttackDistance(oCreature) == 1.1);

    //
    // FEAT related functions
    //

    int nFeatCountLvl1 = NWNX_Creature_GetFeatCountByLevel(oCreature, 1);
    int nFeatCountTotal = NWNX_Creature_GetFeatCount(oCreature);

    NWNX_Tests_Report("NWNX_Creature", "GetKnowsFeat", NWNX_Creature_GetKnowsFeat(oCreature, FEAT_PLAYER_TOOL_01) == 0);

    NWNX_Creature_AddFeat(oCreature, FEAT_PLAYER_TOOL_01);
    NWNX_Tests_Report("NWNX_Creature", "AddFeat", NWNX_Creature_GetKnowsFeat(oCreature, FEAT_PLAYER_TOOL_01) == 1);

    NWNX_Tests_Report("NWNX_Creature", "GetFeatCountByLevel", NWNX_Creature_GetFeatCountByLevel(oCreature, 1) == nFeatCountLvl1);
    NWNX_Tests_Report("NWNX_Creature", "GetFeatCount", NWNX_Creature_GetFeatCount(oCreature) == (nFeatCountTotal+1));

    NWNX_Tests_Report("NWNX_Creature", "GetFeatByIndex", NWNX_Creature_GetFeatByIndex(oCreature, nFeatCountTotal) == FEAT_PLAYER_TOOL_01);

    NWNX_Creature_RemoveFeat(oCreature, FEAT_PLAYER_TOOL_01);
    NWNX_Tests_Report("NWNX_Creature", "RemoveFeat", NWNX_Creature_GetKnowsFeat(oCreature, FEAT_PLAYER_TOOL_01) == 0);
    NWNX_Tests_Report("NWNX_Creature", "GetFeatCount", NWNX_Creature_GetFeatCount(oCreature) == nFeatCountTotal);
    NWNX_Tests_Report("NWNX_Creature", "GetFeatByIndex", NWNX_Creature_GetFeatByIndex(oCreature, nFeatCountTotal) == -1);

    NWNX_Creature_AddFeatByLevel(oCreature, FEAT_PLAYER_TOOL_01, 1);
    NWNX_Tests_Report("NWNX_Creature", "AddFeatByLevel", NWNX_Creature_GetKnowsFeat(oCreature, FEAT_PLAYER_TOOL_01) == 1);
    NWNX_Tests_Report("NWNX_Creature", "GetFeatCountByLevel", NWNX_Creature_GetFeatCountByLevel(oCreature, 1) > nFeatCountLvl1);
    NWNX_Tests_Report("NWNX_Creature", "GetFeatCount", NWNX_Creature_GetFeatCount(oCreature) == (nFeatCountTotal+1));
    NWNX_Tests_Report("NWNX_Creature", "GetFeatByIndex", NWNX_Creature_GetFeatByIndex(oCreature, nFeatCountTotal) == FEAT_PLAYER_TOOL_01);

    NWNX_Tests_Report("NWNX_Creature", "GetFeatByLevel", NWNX_Creature_GetFeatByLevel(oCreature, 1, nFeatCountLvl1) == FEAT_PLAYER_TOOL_01);
    NWNX_Tests_Report("NWNX_Creature", "GetFeatGrantLevel", NWNX_Creature_GetFeatGrantLevel(oCreature, FEAT_PLAYER_TOOL_01) == 1);

    NWNX_Creature_AddFeat(oCreature, FEAT_BARBARIAN_RAGE);
    NWNX_Tests_Report("NWNX_Creature", "GetHighestLevelOfFeat", NWNX_Creature_GetHighestLevelOfFeat(oCreature, FEAT_BARBARIAN_RAGE) == FEAT_BARBARIAN_RAGE);
    NWNX_Creature_AddFeat(oCreature, FEAT_BARBARIAN_RAGE_2);
    NWNX_Tests_Report("NWNX_Creature", "GetHighestLevelOfFeat", NWNX_Creature_GetHighestLevelOfFeat(oCreature, FEAT_BARBARIAN_RAGE) == FEAT_BARBARIAN_RAGE_2);

    NWNX_Creature_AddFeat(oCreature, FEAT_STUNNING_FIST);
    NWNX_Tests_Report("NWNX_Creature", "GetFeatRemainingUses", NWNX_Creature_GetFeatRemainingUses(oCreature, FEAT_STUNNING_FIST) == 1);
    NWNX_Creature_SetFeatRemainingUses(oCreature, FEAT_STUNNING_FIST, 0);
    NWNX_Tests_Report("NWNX_Creature", "GetFeatRemainingUses", NWNX_Creature_GetFeatRemainingUses(oCreature, FEAT_STUNNING_FIST) == 0);

    int uses = NWNX_Creature_GetFeatTotalUses(oCreature, FEAT_STUNNING_FIST);
    WriteTimestampedLogEntry("Creature has " + IntToString(uses) + " total uses of STUNNING FIST left");

    //
    // SPECIAL ABILITY functions
    //
    struct NWNX_Creature_SpecialAbility ability;
    ability.id = 1; ability.ready = 1; ability.level = 1;

    int nAbilityCount = NWNX_Creature_GetSpecialAbilityCount(oCreature);
    NWNX_Creature_AddSpecialAbility(oCreature, ability);
    NWNX_Tests_Report("NWNX_Creature", "AddSpecialAbility", NWNX_Creature_GetSpecialAbilityCount(oCreature) > nAbilityCount);

    ability = NWNX_Creature_GetSpecialAbility(oCreature, nAbilityCount);
    NWNX_Tests_Report("NWNX_Creature", "GetSpecialAbility", ability.id == 1);

    NWNX_Creature_RemoveSpecialAbility(oCreature, nAbilityCount);
    NWNX_Tests_Report("NWNX_Creature", "RemoveSpecialAbility", NWNX_Creature_GetSpecialAbilityCount(oCreature) == nAbilityCount);

    //
    // SPELL functions
    //
    // TODO: Need a wizard.

    //
    // MISC
    //

    int nBaseAC = NWNX_Creature_GetBaseAC(oCreature);
    NWNX_Tests_Report("NWNX_Creature", "GetBaseAC", nBaseAC >= 0);

    NWNX_Creature_SetBaseAC(oCreature, nBaseAC + 5);
    NWNX_Tests_Report("NWNX_Creature", "SetBaseAC", NWNX_Creature_GetBaseAC(oCreature) > nBaseAC);


    int nOldStr = GetAbilityScore(oCreature, ABILITY_STRENGTH, TRUE);
    NWNX_Creature_SetRawAbilityScore(oCreature, ABILITY_STRENGTH, 25);
    NWNX_Tests_Report("NWNX_Creature", "SetRawAbilityScore", nOldStr != GetAbilityScore(oCreature, ABILITY_STRENGTH, TRUE));
    NWNX_Tests_Report("NWNX_Creature", "SetRawAbilityScore", 25      == GetAbilityScore(oCreature, ABILITY_STRENGTH, TRUE));

    ApplyEffectToObject(DURATION_TYPE_PERMANENT, EffectPolymorph(POLYMORPH_TYPE_BADGER), oCreature);
    NWNX_Tests_Report("NWNX_Creature", "GetPrePolymorphAbilityScore", 25 == NWNX_Creature_GetPrePolymorphAbilityScore(oCreature, ABILITY_STRENGTH));
    RemoveEffect(oCreature, GetFirstEffect(oCreature));

    NWNX_Tests_Report("NWNX_Creature", "GetMovementRateFactor", 1.0 == NWNX_Creature_GetMovementRateFactor(oCreature));
    ApplyEffectToObject(DURATION_TYPE_PERMANENT, EffectMovementSpeedIncrease(25), oCreature);
    NWNX_Tests_Report("NWNX_Creature", "GetMovementRateFactor", 1.25 == NWNX_Creature_GetMovementRateFactor(oCreature));
    NWNX_Creature_SetMovementRateFactor(oCreature, 1.5);
    NWNX_Tests_Report("NWNX_Creature", "SetMovementRateFactor", 1.5 == NWNX_Creature_GetMovementRateFactor(oCreature));

    int nLvl1HP = NWNX_Creature_GetMaxHitPointsByLevel(oCreature, 1);
    NWNX_Tests_Report("NWNX_Creature", "GetMaxHitPointsByLevel", nLvl1HP >= 0);

    NWNX_Creature_SetMaxHitPointsByLevel(oCreature, 1, nLvl1HP + 5);
    NWNX_Tests_Report("NWNX_Creature", "SetMaxHitPointsByLevel", NWNX_Creature_GetMaxHitPointsByLevel(oCreature, 1) > nLvl1HP);


    int nSkillRanks = GetSkillRank(SKILL_LISTEN, oCreature, TRUE);
    NWNX_Creature_SetSkillRank(oCreature, SKILL_LISTEN, nSkillRanks + 5);
    NWNX_Tests_Report("NWNX_Creature", "SetSkillRank", GetSkillRank(SKILL_LISTEN, oCreature, TRUE) > nSkillRanks);

    int nBAB = GetBaseAttackBonus(oCreature);
    NWNX_Creature_SetBaseAttackBonus(oCreature, 6);
    NWNX_Tests_Report("NWNX_Creature", "SetBaseAttackBonus", GetBaseAttackBonus(oCreature) == 6);
    SetBaseAttackBonus(4, oCreature);
    NWNX_Tests_Report("NWNX_Creature", "GetAttacksPerRound - base", NWNX_Creature_GetAttacksPerRound(oCreature, TRUE) == 2);
    NWNX_Tests_Report("NWNX_Creature", "GetAttacksPerRound - override", NWNX_Creature_GetAttacksPerRound(oCreature, FALSE) == 4);
    RestoreBaseAttackBonus(oCreature);
    NWNX_Tests_Report("NWNX_Creature", "GetAttacksPerRound - base", NWNX_Creature_GetAttacksPerRound(oCreature, TRUE) == 2);
    NWNX_Tests_Report("NWNX_Creature", "GetAttacksPerRound - override", NWNX_Creature_GetAttacksPerRound(oCreature, FALSE) == 2);

    int nGender = GetGender(oCreature);
    NWNX_Creature_SetGender(oCreature, !nGender);
    NWNX_Tests_Report("NWNX_Creature", "SetGender", GetGender(oCreature) != nGender);

    int nSize = GetCreatureSize(oCreature);
    NWNX_Creature_SetSize(oCreature, nSize + 1);
    NWNX_Tests_Report("NWNX_Creature", "SetSize", GetCreatureSize(oCreature) != nSize);

    int nSkillPointsRemaining = NWNX_Creature_GetSkillPointsRemaining(oCreature);
    NWNX_Tests_Report("NWNX_Creature", "GetSkillPointsRemaining", nSkillPointsRemaining >= 0);
    NWNX_Creature_SetSkillPointsRemaining(oCreature, nSkillPointsRemaining+1);
    NWNX_Tests_Report("NWNX_Creature", "SetSkillPointsRemaining", NWNX_Creature_GetSkillPointsRemaining(oCreature) == nSkillPointsRemaining+1);

    int nGold = GetGold(oCreature);
    NWNX_Creature_SetGold(oCreature, nGold + 100);
    NWNX_Tests_Report("NWNX_Creature", "SetGold", GetGold(oCreature) == (nGold+100));

    int nSave = NWNX_Creature_GetBaseSavingThrow(oCreature, SAVING_THROW_WILL);
    NWNX_Creature_SetBaseSavingThrow(oCreature, SAVING_THROW_WILL, nSave + 10);
    NWNX_Tests_Report("NWNX_Creature", "{S,G}etBaseSavingThrow", NWNX_Creature_GetBaseSavingThrow(oCreature, SAVING_THROW_WILL) == nSave+10);


    int cls = NWNX_Creature_GetClassByLevel(oCreature, 1);
    NWNX_Creature_LevelUp(oCreature, cls, 10);
    NWNX_Tests_Report("NWNX_Creature", "LevelUp", GetLevelByPosition(1, oCreature) == 11);
    NWNX_Creature_LevelDown(oCreature, 10);
    NWNX_Tests_Report("NWNX_Creature", "LevelDown", GetLevelByPosition(1, oCreature) == 1);
    NWNX_Creature_SetClassByPosition(oCreature, 0, CLASS_TYPE_ROGUE);
    NWNX_Creature_LevelUp(oCreature, CLASS_TYPE_ROGUE, 20);
    NWNX_Creature_LevelUp(oCreature, CLASS_TYPE_ROGUE, 20);
    NWNX_Creature_LevelUp(oCreature, CLASS_TYPE_ROGUE, 20);
    NWNX_Creature_LevelUp(oCreature, CLASS_TYPE_ROGUE, 20);
    NWNX_Tests_Report("NWNX_Creature", "LevelUp+SetLevelByPosition", GetLevelByPosition(1, oCreature) == 60);

    NWNX_Creature_SetLevelByPosition(oCreature, 0, 1); // Ugh, game uses 1-based indexing here..
    NWNX_Tests_Report("NWNX_Creature", "SetLevelByPosition", GetLevelByPosition(1, oCreature) == 1);

    float fCR = GetChallengeRating(oCreature);
    NWNX_Creature_SetChallengeRating(oCreature, fCR + 1.0);
    NWNX_Tests_Report("NWNX_Creature", "SetChallengeRating", GetChallengeRating(oCreature) == (fCR + 1.0));

    int iOldBonus = NWNX_Creature_GetTotalEffectBonus(oCreature, NWNX_CREATURE_BONUS_TYPE_ABILITY, OBJECT_INVALID, 0, 0, -1, -1, -1, ABILITY_STRENGTH);
    effect eStr = EffectAbilityIncrease(ABILITY_STRENGTH,1);
    ApplyEffectToObject(DURATION_TYPE_TEMPORARY, eStr, oCreature, 2.0f);
    int iNewBonus = NWNX_Creature_GetTotalEffectBonus(oCreature, NWNX_CREATURE_BONUS_TYPE_ABILITY, OBJECT_INVALID, 0, 0, -1, -1, -1, ABILITY_STRENGTH);
    NWNX_Tests_Report("NWNX_Creature", "GetTotalEffectBonus", iOldBonus+1 == iNewBonus);

    int iSR = GetSpellResistance(oCreature);
    NWNX_Creature_SetSpellResistance(oCreature, iSR + 10);
    NWNX_Tests_Report("NWNX_Creature", "SetSpellResistance", GetSpellResistance(oCreature) == (iSR + 10));

    NWNX_Creature_SetAnimalCompanionCreatureType(oCreature, ANIMAL_COMPANION_CREATURE_TYPE_PANTHER);
    NWNX_Tests_Report("NWNX_Creature", "SetAnimalCompanionCreatureType", GetAnimalCompanionCreatureType(oCreature) == ANIMAL_COMPANION_CREATURE_TYPE_PANTHER);

    NWNX_Creature_SetFamiliarCreatureType(oCreature, FAMILIAR_CREATURE_TYPE_PSEUDO_DRAGON);
    NWNX_Tests_Report("NWNX_Creature", "SetFamiliarCreatureType", GetFamiliarCreatureType(oCreature) == FAMILIAR_CREATURE_TYPE_PSEUDO_DRAGON);

    NWNX_Creature_SetAnimalCompanionName(oCreature, "Fuzzles");
    NWNX_Tests_Report("NWNX_Creature", "SetAnimalCompanionName", GetAnimalCompanionName(oCreature) == "Fuzzles");

    NWNX_Creature_SetFamiliarName(oCreature, "Fuzzles");
    NWNX_Tests_Report("NWNX_Creature", "SetFamiliarName", GetFamiliarName(oCreature) == "Fuzzles");

    int bDisarmable = NWNX_Creature_GetDisarmable(oCreature);
    NWNX_Creature_SetDisarmable(oCreature, !bDisarmable);
    NWNX_Tests_Report("NWNX_Creature", "{S,G}etDisarmable", NWNX_Creature_GetDisarmable(oCreature) != bDisarmable);

    //Spawn a Wizard
    oCreature = CreateObject(OBJECT_TYPE_CREATURE, "NW_ELFMAGE001", GetStartingLocation());
    if (!GetIsObjectValid(oCreature))
    {
        WriteTimestampedLogEntry("NWNX_Creature test: Failed to create creature");
        return;
    }

    //Test specialization functions on a class that has specialization
    int nSchool = NWNX_Creature_GetSpecialization(oCreature, CLASS_TYPE_WIZARD);
    NWNX_Creature_SetSpecialization(oCreature, CLASS_TYPE_WIZARD, (nSchool+1)%5);
    NWNX_Tests_Report("NWNX_Creature", "{S,G}etSpecialization", NWNX_Creature_GetSpecialization(oCreature, CLASS_TYPE_WIZARD) == (nSchool+1)%5);

    //Test domain functions on a class that doesn't have domains
    int nDomain = NWNX_Creature_GetDomain(oCreature, CLASS_TYPE_WIZARD, 1);
    NWNX_Tests_Report("NWNX_Creature", "GetDomain", NWNX_Creature_GetDomain(oCreature, CLASS_TYPE_WIZARD, 1) == 0);
    NWNX_Creature_SetDomain(oCreature, CLASS_TYPE_WIZARD, 1, (nDomain+1)%5);
    NWNX_Tests_Report("NWNX_Creature", "{S,G}etDomain", NWNX_Creature_GetDomain(oCreature, CLASS_TYPE_WIZARD, 1) == (nDomain+1)%5);
    int nDomain2 = NWNX_Creature_GetDomain(oCreature, CLASS_TYPE_WIZARD, 2);
    NWNX_Tests_Report("NWNX_Creature", "GetDomain", NWNX_Creature_GetDomain(oCreature, CLASS_TYPE_WIZARD, 2) == 0);
    NWNX_Creature_SetDomain(oCreature, CLASS_TYPE_WIZARD, 2, (nDomain2+1)%5);
    NWNX_Tests_Report("NWNX_Creature", "{S,G}etDomain", NWNX_Creature_GetDomain(oCreature, CLASS_TYPE_WIZARD, 2) == (nDomain2+1)%5);

    //Get/Set Last Item Caster level
    NWNX_Creature_SetLastItemCasterLevel(oCreature, 5);
    NWNX_Tests_Report("NWNX_Creature", "{S,G}etLastItemCasterLevel", NWNX_Creature_GetLastItemCasterLevel(oCreature) == 5);

    //Spawn a cleric
    object oCreature2 = CreateObject(OBJECT_TYPE_CREATURE, "NW_BANDIT004", GetStartingLocation());
    if (!GetIsObjectValid(oCreature2))
    {
        WriteTimestampedLogEntry("NWNX_Creature test: Failed to create creature");
        return;
    }

    //Test specialization functions on a class that doesn't have specialization
    nSchool = NWNX_Creature_GetSpecialization(oCreature2, CLASS_TYPE_CLERIC);
    NWNX_Tests_Report("NWNX_Creature", "GetSpecialization", NWNX_Creature_GetSpecialization(oCreature2, CLASS_TYPE_CLERIC) == 0);
    NWNX_Creature_SetSpecialization(oCreature2, CLASS_TYPE_CLERIC, (nSchool+1)%5);
    NWNX_Tests_Report("NWNX_Creature", "{S,G}etSpecialization", NWNX_Creature_GetSpecialization(oCreature2, CLASS_TYPE_CLERIC) == (nSchool+1)%5);

    //Test domain functions on a class that has domains
    nDomain = NWNX_Creature_GetDomain(oCreature2, CLASS_TYPE_CLERIC, 1);
    NWNX_Creature_SetDomain(oCreature2, CLASS_TYPE_CLERIC, 1, (nDomain+1)%5);
    NWNX_Tests_Report("NWNX_Creature", "{S,G}etDomain", NWNX_Creature_GetDomain(oCreature2, CLASS_TYPE_CLERIC, 1) == (nDomain+1)%5);
    nDomain2 = NWNX_Creature_GetDomain(oCreature2, CLASS_TYPE_CLERIC, 2);
    NWNX_Creature_SetDomain(oCreature2, CLASS_TYPE_CLERIC, 2, (nDomain2+1)%5);
    NWNX_Tests_Report("NWNX_Creature", "{S,G}etDomain", NWNX_Creature_GetDomain(oCreature2, CLASS_TYPE_CLERIC, 2) == (nDomain2+1)%5);

	//Test Armor class versus function, elf mage vs bandit
    NWNX_Tests_Report("NWNX_Creature", "Without a Versus GetArmorClassVersus", NWNX_Creature_GetArmorClassVersus(oCreature, OBJECT_INVALID) > 0);
    int nOldAC = NWNX_Creature_GetArmorClassVersus(oCreature, oCreature2);
    int nOldTouchAC = NWNX_Creature_GetArmorClassVersus(oCreature, oCreature2, TRUE);
    NWNX_Tests_Report("NWNX_Creature", "Hard AC GetArmorClassVersus", nOldAC >=  0);
    NWNX_Tests_Report("NWNX_Creature", "Touch AC GetArmorClassVersus", nOldTouchAC >=  0);
    //Increase non-touch ac
    ApplyEffectToObject(DURATION_TYPE_TEMPORARY, EffectACIncrease(5, AC_NATURAL_BONUS), oCreature, 10.0);
    NWNX_Tests_Report("NWNX_Creature", "Hard AC increased after hard buff GetArmorClassVersus", nOldAC <  NWNX_Creature_GetArmorClassVersus(oCreature, oCreature2));
    NWNX_Tests_Report("NWNX_Creature", "Touch AC did not increase after hard buff GetArmorClassVersus", nOldTouchAC ==  NWNX_Creature_GetArmorClassVersus(oCreature, oCreature2, TRUE));
    //Increase touch AC against oVersus
    ApplyEffectToObject(DURATION_TYPE_TEMPORARY, VersusRacialTypeEffect(EffectACIncrease(5, AC_DEFLECTION_BONUS), RACIAL_TYPE_HUMAN), oCreature, 10.0);
    NWNX_Tests_Report("NWNX_Creature", "Touch AC increased after deflection buff GetArmorClassVersus", nOldTouchAC <  NWNX_Creature_GetArmorClassVersus(oCreature, oCreature2, TRUE));

    WriteTimestampedLogEntry("NWNX_Creature unit test end.");
}
