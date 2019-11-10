#include "nwnx_creature"
#include "nwnx_skillranks"
#include "nwnx_tests"

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
    NWNX_Tests_Report("NWNX_SkillRanks", "GetSkillFeatCountForSkill", iCount > 0);

    // Required to give the skill focus feat
    NWNX_Creature_SetSkillRank(o, SKILL_LORE, 1);
    NWNX_Creature_AddFeat(o, FEAT_SKILL_FOCUS_LORE);
    int iRank = GetSkillRank(SKILL_LORE, o);

    struct NWNX_SkillRanks_SkillFeat sf = NWNX_SkillRanks_GetSkillFeatForSkillByIndex(SKILL_LORE, iCount - 1);
    int iModifier = sf.iModifier;
    NWNX_Tests_Report("NWNX_SkillRanks", "GetSkillFeatForSkillByIndex", iModifier > 0);

    sf = NWNX_SkillRanks_GetSkillFeat(SKILL_LORE, FEAT_SKILL_FOCUS_LORE);
    iModifier = sf.iModifier;
    NWNX_Tests_Report("NWNX_SkillRanks", "GetSkillFeat", iModifier == 3);

    sf.iModifier = 10;
    NWNX_SkillRanks_SetSkillFeat(sf);
    NWNX_Tests_Report("NWNX_SkillRanks", "SetSkillFeat", GetSkillRank(SKILL_LORE, o) == (iRank + 10 - iModifier));

    NWNX_SkillRanks_SetSkillFeatFocusModifier(4);
    NWNX_Tests_Report("NWNX_SkillRanks", "SetSkillFeatFocusModifier", GetSkillRank(SKILL_LORE, o) == (iRank + 4 - iModifier));

    int iBlindnessPenalty = NWNX_SkillRanks_GetBlindnessPenalty();
    NWNX_Tests_Report("NWNX_SkillRanks", "GetBlindnessPenalty", iBlindnessPenalty == 4);
    effect eBlind = EffectBlindness();
    ApplyEffectToObject(DURATION_TYPE_TEMPORARY, eBlind, o, 2.0f);
    iRank = GetSkillRank(SKILL_HIDE, o);
    NWNX_SkillRanks_SetBlindnessPenalty(12);
    NWNX_Tests_Report("NWNX_SkillRanks", "SetBlindnessPenalty", GetSkillRank(SKILL_HIDE, o) == (iRank - 12 + iBlindnessPenalty));
    NWNX_Tests_Report("NWNX_SkillRanks", "GetBlindnessPenalty", NWNX_SkillRanks_GetBlindnessPenalty() == 12);

    iRank = GetSkillRank(SKILL_LORE, o);
    NWNX_SkillRanks_SetAreaModifier(GetArea(o), SKILL_LORE, 20);
    NWNX_Tests_Report("NWNX_SkillRanks", "SetAreaModifier", GetSkillRank(SKILL_LORE, o) == (iRank + 20));
    NWNX_Tests_Report("NWNX_SkillRanks", "GetAreaModifier", NWNX_SkillRanks_GetAreaModifier(GetArea(o), SKILL_LORE) == 20);

    DestroyObject(o);
    WriteTimestampedLogEntry("NWNX_SkillRanks unit test end.");
}
