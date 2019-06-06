#include "nwnx_race"

void report(string func, int bSuccess)
{
    if (bSuccess)
        WriteTimestampedLogEntry("NWNX_Race: " + func + "() success");
    else
        WriteTimestampedLogEntry("NWNX_Race: " + func + "() failed");
}

void main()
{
    WriteTimestampedLogEntry("NWNX_Race unit test begin..");

    object oCreature = CreateObject(OBJECT_TYPE_CREATURE, "nw_chicken", GetStartingLocation());
    int iSR = GetSpellResistance(oCreature);
    int iSkillRank = GetSkillRank(SKILL_HEAL, oCreature);
    int iAC = GetAC(oCreature);
    int iImmune = GetIsImmune(oCreature, IMMUNITY_TYPE_CURSED);
    DestroyObject(oCreature);

    NWNX_Race_SetRacialModifier(RACIAL_TYPE_ANIMAL, NWNX_RACE_MODIFIER_SRCHARGEN, 10);
    NWNX_Race_SetRacialModifier(RACIAL_TYPE_ANIMAL, NWNX_RACE_MODIFIER_SKILL, SKILL_HEAL, 5);
    NWNX_Race_SetRacialModifier(RACIAL_TYPE_ANIMAL, NWNX_RACE_MODIFIER_AC, 1);
    NWNX_Race_SetRacialModifier(RACIAL_TYPE_ANIMAL, NWNX_RACE_MODIFIER_IMMUNITY, IMMUNITY_TYPE_CURSED);

    oCreature = CreateObject(OBJECT_TYPE_CREATURE, "nw_chicken", GetStartingLocation());
    int iNewSR = GetSpellResistance(oCreature);
    int iNewSkillRank = GetSkillRank(SKILL_HEAL, oCreature);
    int iNewAC = GetAC(oCreature);
    int iNewImmune = GetIsImmune(oCreature, IMMUNITY_TYPE_CURSED);
    DestroyObject(oCreature);

    report("SetRacialModifier SR", iSR == iNewSR - 10);
    report("SetRacialModifier SkillRank", iSkillRank == iNewSkillRank - 5);
    report("SetRacialModifier AC", iAC == iNewAC - 1);
    report("SetRacialModifier Immunity", iImmune != iNewImmune);

    WriteTimestampedLogEntry("NWNX_Race unit test end.");
}
