#include "nwnx_race"
#include "nwnx_test"

void main()
{
    while(TEST("Race"))
    {
        ASSERT(IS_TRUE(NWNX_Test_PluginExists("NWNX_Race")));
        object oCreature = CreateObject(OBJECT_TYPE_CREATURE, "nw_chicken", GetStartingLocation());
        ASSERT(IS_VALID(oCreature));
        int iSR = GetSpellResistance(oCreature);
        int iSkillRank = GetSkillRank(SKILL_HEAL, oCreature);
        int iAC = GetAC(oCreature);
        int iImmune = GetIsImmune(oCreature, IMMUNITY_TYPE_CURSED);
        DestroyObject(oCreature);

        NWNX_Race_SetRacialModifier(RACIAL_TYPE_ANIMAL, NWNX_RACE_MODIFIER_SRCHARGEN, 10);
        NWNX_Race_SetRacialModifier(RACIAL_TYPE_ANIMAL, NWNX_RACE_MODIFIER_AC, 1);
        NWNX_Race_SetRacialModifier(RACIAL_TYPE_ANIMAL, NWNX_RACE_MODIFIER_IMMUNITY, IMMUNITY_TYPE_CURSED);

        oCreature = CreateObject(OBJECT_TYPE_CREATURE, "nw_chicken", GetStartingLocation());
        ASSERT(IS_VALID(oCreature));
        int iNewSR = GetSpellResistance(oCreature);
        int iNewAC = GetAC(oCreature);
        int iNewImmune = GetIsImmune(oCreature, IMMUNITY_TYPE_CURSED);

        // NOTE: Judging by the code this is for PCs only, but SkillRanks works on NPCs too.
        EXPECT(IS_EQUAL_INT(iSR, iNewSR - 10), "SetRacialModifier SR");
        EXPECT(IS_EQUAL_INT(iAC, iNewAC - 1), "SetRacialModifier AC");
        EXPECT(NOT_EQUAL_INT(iImmune, iNewImmune), "SetRacialModifier Immunity");

        while(TEST("SkillRanks"))
        {
            ASSERT(IS_TRUE(NWNX_Test_PluginExists("NWNX_SkillRanks")));
            NWNX_Race_SetRacialModifier(RACIAL_TYPE_ANIMAL, NWNX_RACE_MODIFIER_SKILL, SKILL_HEAL, 5);
            int iNewSkillRank = GetSkillRank(SKILL_HEAL, oCreature);
            EXPECT(IS_EQUAL_INT(iSkillRank, iNewSkillRank - 5), "SetRacialModifier SkillRank");
        }
        DestroyObject(oCreature);
    }
}
