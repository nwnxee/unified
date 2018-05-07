#include "nwnx_creature"



void report(string func, int bSuccess)
{
    if (bSuccess)
        WriteTimestampedLogEntry("NWNX_Creature: " + func + "() success");
    else
        WriteTimestampedLogEntry("NWNX_Creature: " + func + "() failed");
}
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
    // FEAT related functions
    //

    int nFeatCountLvl1 = NWNX_Creature_GetFeatCountByLevel(oCreature, 1);
    int nFeatCountTotal = NWNX_Creature_GetFeatCount(oCreature);

    report("GetKnowsFeat", NWNX_Creature_GetKnowsFeat(oCreature, FEAT_PLAYER_TOOL_01) == 0);

    NWNX_Creature_AddFeat(oCreature, FEAT_PLAYER_TOOL_01);
    report("AddFeat", NWNX_Creature_GetKnowsFeat(oCreature, FEAT_PLAYER_TOOL_01) == 1);

    report("GetFeatCountByLevel", NWNX_Creature_GetFeatCountByLevel(oCreature, 1) == nFeatCountLvl1);
    report("GetFeatCount", NWNX_Creature_GetFeatCount(oCreature) == (nFeatCountTotal+1));

    report("GetFeatByIndex", NWNX_Creature_GetFeatByIndex(oCreature, nFeatCountTotal) == FEAT_PLAYER_TOOL_01);

    NWNX_Creature_RemoveFeat(oCreature, FEAT_PLAYER_TOOL_01);
    report("RemoveFeat", NWNX_Creature_GetKnowsFeat(oCreature, FEAT_PLAYER_TOOL_01) == 0);
    report("GetFeatCount", NWNX_Creature_GetFeatCount(oCreature) == nFeatCountTotal);
    report("GetFeatByIndex", NWNX_Creature_GetFeatByIndex(oCreature, nFeatCountTotal) == -1);

    NWNX_Creature_AddFeatByLevel(oCreature, FEAT_PLAYER_TOOL_01, 1);
    report("AddFeatByLevel", NWNX_Creature_GetKnowsFeat(oCreature, FEAT_PLAYER_TOOL_01) == 1);
    report("GetFeatCountByLevel", NWNX_Creature_GetFeatCountByLevel(oCreature, 1) > nFeatCountLvl1);
    report("GetFeatCount", NWNX_Creature_GetFeatCount(oCreature) == (nFeatCountTotal+1));
    report("GetFeatByIndex", NWNX_Creature_GetFeatByIndex(oCreature, nFeatCountTotal) == FEAT_PLAYER_TOOL_01);

    report("GetFeatByLevel", NWNX_Creature_GetFeatByLevel(oCreature, 1, nFeatCountLvl1) == FEAT_PLAYER_TOOL_01);


    //
    // SPECIAL ABILITY functions
    //
    struct NWNX_Creature_SpecialAbility ability;
    ability.id = 1; ability.ready = 1; ability.level = 1;

    int nAbilityCount = NWNX_Creature_GetSpecialAbilityCount(oCreature);
    NWNX_Creature_AddSpecialAbility(oCreature, ability);
    report("AddSpecialAbility", NWNX_Creature_GetSpecialAbilityCount(oCreature) > nAbilityCount);

    ability = NWNX_Creature_GetSpecialAbility(oCreature, nAbilityCount);
    report("GetSpecialAbility", ability.id == 1);

    NWNX_Creature_RemoveSpecialAbility(oCreature, nAbilityCount);
    report("RemoveSpecialAbility", NWNX_Creature_GetSpecialAbilityCount(oCreature) == nAbilityCount);

    //
    // SPELL functions
    //
    // TODO: Need a wizard.

    //
    // MISC
    //

    int nBaseAC = NWNX_Creature_GetBaseAC(oCreature);
    report("GetBaseAC", nBaseAC >= 0);

    NWNX_Creature_SetBaseAC(oCreature, nBaseAC + 5);
    report("SetBaseAC", NWNX_Creature_GetBaseAC(oCreature) > nBaseAC);


    int nOldStr = GetAbilityScore(oCreature, ABILITY_STRENGTH, TRUE);
    NWNX_Creature_SetAbilityScore(oCreature, ABILITY_STRENGTH, 25);
    report("SetAbilityScore", nOldStr != GetAbilityScore(oCreature, ABILITY_STRENGTH, TRUE));
    report("SetAbilityScore", 25      == GetAbilityScore(oCreature, ABILITY_STRENGTH, TRUE));


    int nLvl1HP = NWNX_Creature_GetMaxHitPointsByLevel(oCreature, 1);
    report("GetMaxHitPointsByLevel", nLvl1HP >= 0);

    NWNX_Creature_SetMaxHitPointsByLevel(oCreature, 1, nLvl1HP + 5);
    report("SetMaxHitPointsByLevel", NWNX_Creature_GetMaxHitPointsByLevel(oCreature, 1) > nLvl1HP);


    int nSkillRanks = GetSkillRank(SKILL_LISTEN, oCreature, TRUE);
    NWNX_Creature_SetSkillRank(oCreature, SKILL_LISTEN, nSkillRanks + 5);
    report("SetSkillRank", GetSkillRank(SKILL_LISTEN, oCreature, TRUE) > nSkillRanks);

    int nBAB = GetBaseAttackBonus(oCreature);
    NWNX_Creature_SetBaseAttackBonus(oCreature, 6);
    report("SetBaseAttackBonus", GetBaseAttackBonus(oCreature) == 6);
    SetBaseAttackBonus(4, oCreature);
    report("GetAttacksPerRound - base", NWNX_Creature_GetAttacksPerRound(oCreature, TRUE) == 2);
    report("GetAttacksPerRound - override", NWNX_Creature_GetAttacksPerRound(oCreature, FALSE) == 4);
    RestoreBaseAttackBonus(oCreature);
    report("GetAttacksPerRound - base", NWNX_Creature_GetAttacksPerRound(oCreature, TRUE) == 2);
    report("GetAttacksPerRound - override", NWNX_Creature_GetAttacksPerRound(oCreature, FALSE) == 2);

    int nGender = GetGender(oCreature);
    NWNX_Creature_SetGender(oCreature, !nGender);
    report("SetGender", GetGender(oCreature) != nGender);

    int nSize = GetCreatureSize(oCreature);
    NWNX_Creature_SetSize(oCreature, nSize + 1);
    report("SetSize", GetCreatureSize(oCreature) != nSize);

    int nSkillPointsRemaining = NWNX_Creature_GetSkillPointsRemaining(oCreature);
    report("GetSkillPointsRemaining", nSkillPointsRemaining >= 0);
    NWNX_Creature_SetSkillPointsRemaining(oCreature, nSkillPointsRemaining+1);
    report("SetSkillPointsRemaining", NWNX_Creature_GetSkillPointsRemaining(oCreature) == nSkillPointsRemaining+1);

    int nGold = GetGold(oCreature);
    NWNX_Creature_SetGold(oCreature, nGold + 100);
    report("SetGold", GetGold(oCreature) == (nGold+100));

    int nSave = NWNX_Creature_GetBaseSavingThrow(oCreature, SAVING_THROW_WILL);
    NWNX_Creature_SetBaseSavingThrow(oCreature, SAVING_THROW_WILL, nSave + 10);
    report("{S,G}etBaseSavingThrow", NWNX_Creature_GetBaseSavingThrow(oCreature, SAVING_THROW_WILL) == nSave+10);

    WriteTimestampedLogEntry("NWNX_Creature unit test end.");
}
