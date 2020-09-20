#include "nwnx_creature"
#include "nwnx_feat"
#include "nwnx_tests"

void main()
{
    WriteTimestampedLogEntry("NWNX_Feat unit test begin..");

    object oCreature = CreateObject(OBJECT_TYPE_CREATURE, "nw_chicken", GetStartingLocation());
    int iSR = GetSpellResistance(oCreature);
    int iAC = GetAC(oCreature);
    int iImmune = GetIsImmune(oCreature, IMMUNITY_TYPE_CURSED);

    // Temporarily change the Alertness feat and grant it to our chicken
    NWNX_Feat_SetFeatModifier(FEAT_ALERTNESS, NWNX_FEAT_MODIFIER_SRCHARGEN, 10);
    NWNX_Feat_SetFeatModifier(FEAT_ALERTNESS, NWNX_FEAT_MODIFIER_AC, 1);
    NWNX_Feat_SetFeatModifier(FEAT_ALERTNESS, NWNX_FEAT_MODIFIER_IMMUNITY, IMMUNITY_TYPE_CURSED);
    NWNX_Creature_AddFeat(oCreature, FEAT_ALERTNESS);
    NWNX_Feat_CreatureRefreshFeats(oCreature);

    int iNewSR = GetSpellResistance(oCreature);
    int iNewAC = GetAC(oCreature);
    int iNewImmune = GetIsImmune(oCreature, IMMUNITY_TYPE_CURSED);
    DestroyObject(oCreature);

    NWNX_Tests_Report("NWNX_Feat", "SetFeatModifier SR", iSR == iNewSR - 10);
    NWNX_Tests_Report("NWNX_Feat", "SetFeatModifier AC", iAC == iNewAC - 1);
    NWNX_Tests_Report("NWNX_Feat", "SetFeatModifier Immunity", iImmune != iNewImmune);

    WriteTimestampedLogEntry("NWNX_Feat unit test end.");
}
