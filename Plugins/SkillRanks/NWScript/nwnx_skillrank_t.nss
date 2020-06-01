#include "nwnx_creature"
#include "nwnx_skillranks"
#include "nwnx_test"

void main()
{
    while(TEST("SkillRanks"))
    {
        ASSERT(IS_TRUE(NWNX_Test_PluginExists("NWNX_SkillRanks")));
        ASSERT(IS_TRUE(NWNX_Test_PluginExists("NWNX_Creature")));

        object o = CreateObject(OBJECT_TYPE_CREATURE, "nw_chicken", GetStartingLocation());
        ASSERT(IS_VALID(o));

        int iCount = NWNX_SkillRanks_GetSkillFeatCountForSkill(SKILL_LORE);
        EXPECT(IS_GT_INT(iCount, 0), "GetSkillFeatCountForSkill");

        // Required to give the skill focus feat
        NWNX_Creature_SetSkillRank(o, SKILL_LORE, 50);
        NWNX_Creature_AddFeat(o, FEAT_SKILL_FOCUS_LORE);
        int iRank = GetSkillRank(SKILL_LORE, o);

        // NOTE: If this happens to pick the feat Bardic Knowledge, for example, this test will fail because that's
        // dealt with in class bonuses.
        struct NWNX_SkillRanks_SkillFeat sf = NWNX_SkillRanks_GetSkillFeatForSkillByIndex(SKILL_LORE, iCount - 1);
        int iModifier = sf.iModifier;
        EXPECT(IS_GT_INT(iModifier, 0), "GetSkillFeatForSkillByIndex");

        iRank = GetSkillRank(SKILL_LORE, o);
        NWNX_SkillRanks_SetAreaModifier(GetArea(o), SKILL_LORE, 20);
        EXPECT(IS_EQUAL_INT(NWNX_SkillRanks_GetAreaModifier(GetArea(o), SKILL_LORE), 20), "GetAreaModifier");
        int iNewRank = GetSkillRank(SKILL_LORE, o);

        EXPECT(IS_EQUAL_INT(iNewRank, (iRank + 20)), "SetAreaModifier");

        sf = NWNX_SkillRanks_GetSkillFeat(SKILL_LORE, FEAT_SKILL_FOCUS_LORE);
        iModifier = sf.iModifier;
        EXPECT(IS_EQUAL_INT(iModifier, 3), "GetSkillFeat");

        iRank = GetSkillRank(SKILL_LORE, o);
        sf.iModifier = 10;
        NWNX_SkillRanks_SetSkillFeat(sf);
        sf = NWNX_SkillRanks_GetSkillFeat(SKILL_LORE, FEAT_SKILL_FOCUS_LORE);
        EXPECT(IS_EQUAL_INT(sf.iModifier, 10), "GetSkillFeat");

        iNewRank = GetSkillRank(SKILL_LORE, o);
        EXPECT(IS_EQUAL_INT(iRank, (iRank + 10 - sf.iModifier)), "SetSkillFeat");

        NWNX_SkillRanks_SetSkillFeatFocusModifier(4);
        EXPECT(IS_EQUAL_INT(GetSkillRank(SKILL_LORE, o), (iRank + 4 - iModifier)), "SetSkillFeatFocusModifier");

        int iBlindnessPenalty = NWNX_SkillRanks_GetBlindnessPenalty();
        EXPECT(IS_EQUAL_INT(iBlindnessPenalty, 4), "GetBlindnessPenalty");
        effect eBlind = EffectBlindness();
        ApplyEffectToObject(DURATION_TYPE_TEMPORARY, eBlind, o, 2.0f);
        iRank = GetSkillRank(SKILL_HIDE, o);
        NWNX_SkillRanks_SetBlindnessPenalty(12);
        EXPECT(IS_EQUAL_INT(GetSkillRank(SKILL_HIDE, o), (iRank - 12 + iBlindnessPenalty)), "SetBlindnessPenalty");
        EXPECT(IS_EQUAL_INT(NWNX_SkillRanks_GetBlindnessPenalty(), 12), "GetBlindnessPenalty");

        DestroyObject(o);

    }
}
