#include "nwnx_creature"
#include "nwnx_test"

const int FEAT_BARBARIAN_RAGE_2 = 326;

void main()
{
    while(TEST("Creature"))
    {
        ASSERT(IS_TRUE(NWNX_Test_PluginExists("NWNX_Creature")));

        object oCreature = CreateObject(OBJECT_TYPE_CREATURE, "nw_chicken", GetStartingLocation());
        ASSERT(IS_VALID(oCreature));

        while(TEST("Feat"))
        {
            int nFeatCountLvl1 = NWNX_Creature_GetFeatCountByLevel(oCreature, 1);
            int nFeatCountTotal = NWNX_Creature_GetFeatCount(oCreature);

            EXPECT(IS_FALSE(NWNX_Creature_GetKnowsFeat(oCreature, FEAT_PLAYER_TOOL_01)), "GetKnowsFeat");

            NWNX_Creature_AddFeat(oCreature, FEAT_PLAYER_TOOL_01);
            EXPECT(IS_EQUAL_INT(NWNX_Creature_GetKnowsFeat(oCreature, FEAT_PLAYER_TOOL_01), 1), "AddFeat");

            EXPECT(IS_EQUAL_INT(NWNX_Creature_GetFeatCountByLevel(oCreature, 1), nFeatCountLvl1), "GetFeatCountByLevel");
            EXPECT(IS_EQUAL_INT(NWNX_Creature_GetFeatCount(oCreature), (nFeatCountTotal+1)), "GetFeatCount");

            EXPECT(IS_EQUAL_INT(NWNX_Creature_GetFeatByIndex(oCreature, nFeatCountTotal), FEAT_PLAYER_TOOL_01), "GetFeatByIndex");

            NWNX_Creature_RemoveFeat(oCreature, FEAT_PLAYER_TOOL_01);
            EXPECT(IS_FALSE(NWNX_Creature_GetKnowsFeat(oCreature, FEAT_PLAYER_TOOL_01)), "RemoveFeat");
            EXPECT(IS_EQUAL_INT(NWNX_Creature_GetFeatCount(oCreature), nFeatCountTotal), "GetFeatCount");
            EXPECT(IS_EQUAL_INT(NWNX_Creature_GetFeatByIndex(oCreature, nFeatCountTotal), -1), "GetFeatByIndex");

            NWNX_Creature_AddFeatByLevel(oCreature, FEAT_PLAYER_TOOL_01, 1);
            EXPECT(IS_TRUE(NWNX_Creature_GetKnowsFeat(oCreature, FEAT_PLAYER_TOOL_01)), "AddFeatByLevel");
            EXPECT(IS_EQUAL_INT(NWNX_Creature_GetFeatCountByLevel(oCreature, 1), nFeatCountLvl1 + 1), "GetFeatCountByLevel");
            EXPECT(IS_EQUAL_INT(NWNX_Creature_GetFeatCount(oCreature), (nFeatCountTotal+1)), "GetFeatCount");
            EXPECT(IS_EQUAL_INT(NWNX_Creature_GetFeatByIndex(oCreature, nFeatCountTotal), FEAT_PLAYER_TOOL_01), "GetFeatByIndex");

            EXPECT(IS_EQUAL_INT(NWNX_Creature_GetFeatByLevel(oCreature, 1, nFeatCountLvl1), FEAT_PLAYER_TOOL_01), "GetFeatByLevel");
            EXPECT(IS_EQUAL_INT(NWNX_Creature_GetFeatGrantLevel(oCreature, FEAT_PLAYER_TOOL_01), 1), "GetFeatGrantLevel");

            NWNX_Creature_AddFeat(oCreature, FEAT_BARBARIAN_RAGE);
            EXPECT(IS_EQUAL_INT(NWNX_Creature_GetHighestLevelOfFeat(oCreature, FEAT_BARBARIAN_RAGE), FEAT_BARBARIAN_RAGE), "GetHighestLevelOfFeat");
            NWNX_Creature_AddFeat(oCreature, FEAT_BARBARIAN_RAGE_2);
            EXPECT(IS_EQUAL_INT(NWNX_Creature_GetHighestLevelOfFeat(oCreature, FEAT_BARBARIAN_RAGE), FEAT_BARBARIAN_RAGE_2), "GetHighestLevelOfFeat");

            NWNX_Creature_AddFeat(oCreature, FEAT_STUNNING_FIST);
            EXPECT(IS_EQUAL_INT(NWNX_Creature_GetFeatRemainingUses(oCreature, FEAT_STUNNING_FIST), 1), "GetFeatRemainingUses");
            NWNX_Creature_SetFeatRemainingUses(oCreature, FEAT_STUNNING_FIST, 0);
            EXPECT(IS_EQUAL_INT(NWNX_Creature_GetFeatRemainingUses(oCreature, FEAT_STUNNING_FIST), 0), "GetFeatRemainingUses");

            int uses = NWNX_Creature_GetFeatTotalUses(oCreature, FEAT_STUNNING_FIST);
            WriteTimestampedLogEntry("Creature has " + IntToString(uses) + " total uses of STUNNING FIST left");
        }

        while (TEST("Special Ability"))
        {
            struct NWNX_Creature_SpecialAbility ability;
            ability.id = 1; ability.ready = 1; ability.level = 1;

            int nAbilityCount = NWNX_Creature_GetSpecialAbilityCount(oCreature);
            NWNX_Creature_AddSpecialAbility(oCreature, ability);
            EXPECT(IS_GT_INT(NWNX_Creature_GetSpecialAbilityCount(oCreature),nAbilityCount), "AddSpecialAbility");

            ability = NWNX_Creature_GetSpecialAbility(oCreature, nAbilityCount);
            EXPECT(IS_EQUAL_INT(ability.id, 1), "GetSpecialAbility");

            NWNX_Creature_RemoveSpecialAbility(oCreature, nAbilityCount);
            EXPECT(IS_EQUAL_INT(NWNX_Creature_GetSpecialAbilityCount(oCreature), nAbilityCount), "RemoveSpecialAbility");

        }

        while (TEST("Misc"))
        {
            int nBaseAC = NWNX_Creature_GetBaseAC(oCreature);
            EXPECT(IS_GTE_INT(nBaseAC, 0), "GetBaseAC");

            NWNX_Creature_SetBaseAC(oCreature, nBaseAC + 5);
            EXPECT(IS_GT_INT(NWNX_Creature_GetBaseAC(oCreature), nBaseAC), "SetBaseAC");

            int nOldStr = GetAbilityScore(oCreature, ABILITY_STRENGTH, TRUE);
            NWNX_Creature_SetRawAbilityScore(oCreature, ABILITY_STRENGTH, 25);
            EXPECT(NOT_EQUAL_INT(GetAbilityScore(oCreature, ABILITY_STRENGTH, TRUE), nOldStr), "SetAbilityScore");
            EXPECT(IS_EQUAL_INT(GetAbilityScore(oCreature, ABILITY_STRENGTH, TRUE), 25), "SetAbilityScore");

            ApplyEffectToObject(DURATION_TYPE_PERMANENT, EffectPolymorph(POLYMORPH_TYPE_BADGER), oCreature);
            EXPECT(IS_EQUAL_INT(NWNX_Creature_GetPrePolymorphAbilityScore(oCreature, ABILITY_STRENGTH), 25), "GetPrePolymorphAbilityScore");
            RemoveEffect(oCreature, GetFirstEffect(oCreature));

            EXPECT(IS_EQUAL_FLOAT(1.0, NWNX_Creature_GetMovementRateFactor(oCreature)), "GetMovementRateFactor");
            ApplyEffectToObject(DURATION_TYPE_PERMANENT, EffectMovementSpeedIncrease(25), oCreature);
            EXPECT(IS_EQUAL_FLOAT(1.25, NWNX_Creature_GetMovementRateFactor(oCreature)), "GetMovementRateFactor");
            NWNX_Creature_SetMovementRateFactor(oCreature, 1.5);
            EXPECT(IS_EQUAL_FLOAT(1.5, NWNX_Creature_GetMovementRateFactor(oCreature)), "SetMovementRateFactor");

            int nLvl1HP = NWNX_Creature_GetMaxHitPointsByLevel(oCreature, 1);
            EXPECT(IS_GTE_INT(nLvl1HP, 0), "GetMaxHitPointsByLevel");

            NWNX_Creature_SetMaxHitPointsByLevel(oCreature, 1, nLvl1HP + 5);
            EXPECT(IS_GT_INT(NWNX_Creature_GetMaxHitPointsByLevel(oCreature, 1), nLvl1HP), "SetMaxHitPointsByLevel");


            int nSkillRanks = GetSkillRank(SKILL_LISTEN, oCreature, TRUE);
            NWNX_Creature_SetSkillRank(oCreature, SKILL_LISTEN, nSkillRanks + 5);
            EXPECT(IS_GT_INT(GetSkillRank(SKILL_LISTEN, oCreature, TRUE), nSkillRanks), "SetSkillRank");

            int nBAB = GetBaseAttackBonus(oCreature);
            NWNX_Creature_SetBaseAttackBonus(oCreature, 6);
            EXPECT(IS_EQUAL_INT(GetBaseAttackBonus(oCreature), 6), "SetBaseAttackBonus");
            SetBaseAttackBonus(4, oCreature);
            EXPECT(IS_EQUAL_INT(NWNX_Creature_GetAttacksPerRound(oCreature, TRUE), 2), "GetAttacksPerRound - base");
            EXPECT(IS_EQUAL_INT(NWNX_Creature_GetAttacksPerRound(oCreature, FALSE), 4), "GetAttacksPerRound - override");
            RestoreBaseAttackBonus(oCreature);
            EXPECT(IS_EQUAL_INT(NWNX_Creature_GetAttacksPerRound(oCreature, TRUE), 2), "GetAttacksPerRound - base");
            EXPECT(IS_EQUAL_INT(NWNX_Creature_GetAttacksPerRound(oCreature, FALSE), 2), "GetAttacksPerRound - override");

            int nGender = GetGender(oCreature);
            NWNX_Creature_SetGender(oCreature, !nGender);
            EXPECT(NOT_EQUAL_INT(GetGender(oCreature), nGender), "SetGender");

            int nSize = GetCreatureSize(oCreature);
            NWNX_Creature_SetSize(oCreature, nSize + 1);
            EXPECT(NOT_EQUAL_INT(GetCreatureSize(oCreature), nSize), "SetSize");

            int nSkillPointsRemaining = NWNX_Creature_GetSkillPointsRemaining(oCreature);
            EXPECT(IS_GTE_INT(nSkillPointsRemaining, 0), "GetSkillPointsRemaining");
            NWNX_Creature_SetSkillPointsRemaining(oCreature, nSkillPointsRemaining+1);
            EXPECT(IS_EQUAL_INT(NWNX_Creature_GetSkillPointsRemaining(oCreature), nSkillPointsRemaining+1), "SetSkillPointsRemaining");

            int nGold = GetGold(oCreature);
            NWNX_Creature_SetGold(oCreature, nGold + 100);
            EXPECT(IS_EQUAL_INT(GetGold(oCreature), (nGold+100)), "SetGold");

            int nSave = NWNX_Creature_GetBaseSavingThrow(oCreature, SAVING_THROW_WILL);
            NWNX_Creature_SetBaseSavingThrow(oCreature, SAVING_THROW_WILL, nSave + 10);
            EXPECT(IS_EQUAL_INT(NWNX_Creature_GetBaseSavingThrow(oCreature, SAVING_THROW_WILL), nSave+10), "{S,G}etBaseSavingThrow");

            int cls = NWNX_Creature_GetClassByLevel(oCreature, 1);
            NWNX_Creature_LevelUp(oCreature, cls, 10);
            EXPECT(IS_EQUAL_INT(GetLevelByPosition(1, oCreature), 11), "LevelUp");
            NWNX_Creature_LevelDown(oCreature, 10);
            EXPECT(IS_EQUAL_INT(GetLevelByPosition(1, oCreature), 1), "LevelDown");
            NWNX_Creature_SetClassByPosition(oCreature, 0, CLASS_TYPE_ROGUE);
            NWNX_Creature_LevelUp(oCreature, CLASS_TYPE_ROGUE, 20);
            NWNX_Creature_LevelUp(oCreature, CLASS_TYPE_ROGUE, 20);
            NWNX_Creature_LevelUp(oCreature, CLASS_TYPE_ROGUE, 20);
            NWNX_Creature_LevelUp(oCreature, CLASS_TYPE_ROGUE, 20);
            EXPECT(IS_EQUAL_INT(GetLevelByPosition(1, oCreature), 60), "LevelUp+SetLevelByPosition");

            NWNX_Creature_SetLevelByPosition(oCreature, 0, 1); // Ugh, game uses 1-based indexing here..
            EXPECT(IS_EQUAL_INT(GetLevelByPosition(1, oCreature), 1), "SetLevelByPosition");

            float fCR = GetChallengeRating(oCreature);
            NWNX_Creature_SetChallengeRating(oCreature, fCR + 1.0);
            EXPECT(IS_EQUAL_FLOAT(GetChallengeRating(oCreature), (fCR + 1.0)), "SetChallengeRating");

            int iOldBonus = NWNX_Creature_GetTotalEffectBonus(oCreature, NWNX_CREATURE_BONUS_TYPE_ABILITY, OBJECT_INVALID, 0, 0, -1, -1, -1, ABILITY_STRENGTH);
            effect eStr = EffectAbilityIncrease(ABILITY_STRENGTH,1);
            ApplyEffectToObject(DURATION_TYPE_TEMPORARY, eStr, oCreature, 2.0f);
            int iNewBonus = NWNX_Creature_GetTotalEffectBonus(oCreature, NWNX_CREATURE_BONUS_TYPE_ABILITY, OBJECT_INVALID, 0, 0, -1, -1, -1, ABILITY_STRENGTH);
            EXPECT(IS_EQUAL_INT(iOldBonus+1, iNewBonus), "GetTotalEffectBonus");

            int iSR = GetSpellResistance(oCreature);
            NWNX_Creature_SetSpellResistance(oCreature, iSR + 10);
            EXPECT(IS_EQUAL_INT(GetSpellResistance(oCreature), (iSR + 10)), "SetSpellResistance");

            NWNX_Creature_SetAnimalCompanionCreatureType(oCreature, ANIMAL_COMPANION_CREATURE_TYPE_PANTHER);
            EXPECT(IS_EQUAL_INT(GetAnimalCompanionCreatureType(oCreature), ANIMAL_COMPANION_CREATURE_TYPE_PANTHER), "SetAnimalCompanionCreatureType");

            NWNX_Creature_SetFamiliarCreatureType(oCreature, FAMILIAR_CREATURE_TYPE_PSEUDO_DRAGON);
            EXPECT(IS_EQUAL_INT(GetFamiliarCreatureType(oCreature), FAMILIAR_CREATURE_TYPE_PSEUDO_DRAGON), "SetFamiliarCreatureType");

            NWNX_Creature_SetAnimalCompanionName(oCreature, "Fuzzles");
            EXPECT(IS_EQUAL_STRING(GetAnimalCompanionName(oCreature), "Fuzzles"), "SetAnimalCompanionName");

            NWNX_Creature_SetFamiliarName(oCreature, "Fuzzles");
            EXPECT(IS_EQUAL_STRING(GetFamiliarName(oCreature), "Fuzzles"), "SetFamiliarName");

            int bDisarmable = NWNX_Creature_GetDisarmable(oCreature);
            NWNX_Creature_SetDisarmable(oCreature, !bDisarmable);
            EXPECT(NOT_EQUAL_INT(NWNX_Creature_GetDisarmable(oCreature),  bDisarmable), "{S,G}etDisarmable");

        }

        while (TEST("Wizard"))
        {
            //Spawn a Wizard
            object oCreature = CreateObject(OBJECT_TYPE_CREATURE, "NW_ELFMAGE001", GetStartingLocation());
            ASSERT(IS_VALID(oCreature));

            //Test specialization functions on a class that has specialization
            int nSchool = NWNX_Creature_GetSpecialization(oCreature, CLASS_TYPE_WIZARD);
            NWNX_Creature_SetSpecialization(oCreature, CLASS_TYPE_WIZARD, (nSchool+1)%5);
            EXPECT(IS_EQUAL_INT(NWNX_Creature_GetSpecialization(oCreature, CLASS_TYPE_WIZARD), (nSchool+1)%5), "{S,G}etSpecialization");

            //Test old functions for compatibility (deprecated)
            nSchool = NWNX_Creature_GetWizardSpecialization(oCreature);
            NWNX_Creature_SetWizardSpecialization(oCreature, (nSchool+1)%5);
            EXPECT(IS_EQUAL_INT(NWNX_Creature_GetWizardSpecialization(oCreature), (nSchool+1)%5), "{S,G}etWizardSpecialization");

            //Test domain functions on a class that doesn't have domains
            int nDomain = NWNX_Creature_GetDomain(oCreature, CLASS_TYPE_WIZARD, 1);
            EXPECT(IS_EQUAL_INT(NWNX_Creature_GetDomain(oCreature, CLASS_TYPE_WIZARD, 1), 0), "GetDomain");
            NWNX_Creature_SetDomain(oCreature, CLASS_TYPE_WIZARD, 1, (nDomain+1)%5);
            EXPECT(IS_EQUAL_INT(NWNX_Creature_GetDomain(oCreature, CLASS_TYPE_WIZARD, 1), (nDomain+1)%5), "{S,G}etDomain");
            int nDomain2 = NWNX_Creature_GetDomain(oCreature, CLASS_TYPE_WIZARD, 2);
            EXPECT(IS_EQUAL_INT(NWNX_Creature_GetDomain(oCreature, CLASS_TYPE_WIZARD, 2), 0), "GetDomain");
            NWNX_Creature_SetDomain(oCreature, CLASS_TYPE_WIZARD, 2, (nDomain2+1)%5);
            EXPECT(IS_EQUAL_INT(NWNX_Creature_GetDomain(oCreature, CLASS_TYPE_WIZARD, 2), (nDomain2+1)%5), "{S,G}etDomain");
        }

        while(TEST("Cleric"))
        {
            //Spawn a cleric
            object oCreature = CreateObject(OBJECT_TYPE_CREATURE, "NW_BANDIT004", GetStartingLocation());
            ASSERT(IS_VALID(oCreature));

            //Test specialization functions on a class that doesn't have specialization
            int nSchool = NWNX_Creature_GetSpecialization(oCreature, CLASS_TYPE_CLERIC);
            EXPECT(IS_EQUAL_INT(NWNX_Creature_GetSpecialization(oCreature, CLASS_TYPE_CLERIC), 0), "GetSpecialization");
            NWNX_Creature_SetSpecialization(oCreature, CLASS_TYPE_CLERIC, (nSchool+1)%5);
            EXPECT(IS_EQUAL_INT(NWNX_Creature_GetSpecialization(oCreature, CLASS_TYPE_CLERIC), (nSchool+1)%5), "{S,G}etSpecialization");

            //Test domain functions on a class that has domains
            int nDomain = NWNX_Creature_GetDomain(oCreature, CLASS_TYPE_CLERIC, 1);
            NWNX_Creature_SetDomain(oCreature, CLASS_TYPE_CLERIC, 1, (nDomain+1)%5);
            EXPECT(IS_EQUAL_INT(NWNX_Creature_GetDomain(oCreature, CLASS_TYPE_CLERIC, 1), (nDomain+1)%5), "{S,G}etDomain");
            int nDomain2 = NWNX_Creature_GetDomain(oCreature, CLASS_TYPE_CLERIC, 2);
            NWNX_Creature_SetDomain(oCreature, CLASS_TYPE_CLERIC, 2, (nDomain2+1)%5);
            EXPECT(IS_EQUAL_INT(NWNX_Creature_GetDomain(oCreature, CLASS_TYPE_CLERIC, 2), (nDomain2+1)%5), "{S,G}etDomain");

            //Test old functions for compatibility (deprecated)
            nDomain = NWNX_Creature_GetClericDomain(oCreature, 1);
            NWNX_Creature_SetClericDomain(oCreature, 1, (nDomain+1)%5);
            EXPECT(IS_EQUAL_INT(NWNX_Creature_GetClericDomain(oCreature, 1), (nDomain+1)%5), "{S,G}etClericDomain");
            nDomain2 = NWNX_Creature_GetClericDomain(oCreature, 2);
            NWNX_Creature_SetClericDomain(oCreature, 2, (nDomain2+1)%5);
            EXPECT(IS_EQUAL_INT(NWNX_Creature_GetClericDomain(oCreature, 2), (nDomain2+1)%5), "{S,G}etClericDomain");
        }
    }
}
