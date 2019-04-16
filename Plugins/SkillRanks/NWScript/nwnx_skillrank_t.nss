#include "nwnx_creature"
#include "nwnx_skillranks"

void report(string func, int bSuccess)
{
    if (bSuccess)
        WriteTimestampedLogEntry("NWNX_SkillRanks: " + func + "() success");
    else
        WriteTimestampedLogEntry("NWNX_SkillRanks: " + func + "() failed");
}
void main()
{
    WriteTimestampedLogEntry("NWNX_SkillRanks unit test begin..");

    object o = CreateObject(OBJECT_TYPE_CREATURE, "nw_chicken", GetStartingLocation());
    if (!GetIsObjectValid(o))
    {
        WriteTimestampedLogEntry("NWNX_SkillRanks test: Failed to create creature");
        return;
    }

    int iCount = NWNX_SkillRanks_GetSkillFeatCountForSkill(SKILL_LORE);
    report("GetSkillFeatCountForSkill", iCount > 0);

    // Required to give the skill focus feat
    NWNX_Creature_SetSkillRank(o, SKILL_LORE, 1);
    NWNX_Creature_AddFeat(o, FEAT_SKILL_FOCUS_LORE);
    int iRank = GetSkillRank(SKILL_LORE, o);

    struct NWNX_SkillRanks_SkillFeat sf = NWNX_SkillRanks_GetSkillFeatForSkillByIndex(SKILL_LORE, iCount - 1);
    int iModifier = sf.iModifier;
    report("GetSkillFeatForSkillByIndex", iModifier > 0);

    sf = NWNX_SkillRanks_GetSkillFeat(SKILL_LORE, FEAT_SKILL_FOCUS_LORE);
    iModifier = sf.iModifier;
    report("GetSkillFeat", iModifier == 3);

    sf.iModifier = 10;
    NWNX_SkillRanks_SetSkillFeat(sf);
    report("SetSkillFeat", GetSkillRank(SKILL_LORE, o) == (iRank + 10 - iModifier));

    NWNX_SkillRanks_SetSkillFeatFocusModifier(4);
    report("SetSkillFeatFocusModifier", GetSkillRank(SKILL_LORE, o) == (iRank + 4 - iModifier));

    int iBlindnessPenalty = NWNX_SkillRanks_GetBlindnessPenalty();
    report("GetBlindnessPenalty", iBlindnessPenalty == 4);
    effect eBlind = EffectBlindness();
    ApplyEffectToObject(DURATION_TYPE_TEMPORARY, eBlind, o, 2.0f);
    iRank = GetSkillRank(SKILL_HIDE, o);
    NWNX_SkillRanks_SetBlindnessPenalty(12);
    report("SetBlindnessPenalty", GetSkillRank(SKILL_HIDE, o) == (iRank - 12 + iBlindnessPenalty));
    report("GetBlindnessPenalty", NWNX_SkillRanks_GetBlindnessPenalty() == 12);

    iRank = GetSkillRank(SKILL_LORE, o);
    NWNX_SkillRanks_SetAreaModifier(GetArea(o), SKILL_LORE, 20);
    report("SetAreaModifier", GetSkillRank(SKILL_LORE, o) == (iRank + 20));
    report("GetAreaModifier", NWNX_SkillRanks_GetAreaModifier(GetArea(o), SKILL_LORE) == 20);

    DestroyObject(o);
    WriteTimestampedLogEntry("NWNX_SkillRanks unit test end.");
}
