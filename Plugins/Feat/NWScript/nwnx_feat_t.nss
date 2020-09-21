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
    NWNX_Feat_SetFeatModifier(FEAT_ALERTNESS, NWNX_FEAT_MODIFIER_AC, 1);
    NWNX_Feat_SetFeatModifier(FEAT_ALERTNESS, NWNX_FEAT_MODIFIER_SRCHARGEN, 10);
    NWNX_Feat_SetFeatModifier(FEAT_ALERTNESS, NWNX_FEAT_MODIFIER_IMMUNITY, IMMUNITY_TYPE_CURSED);
    NWNX_Creature_AddFeat(oCreature, FEAT_ALERTNESS);

    int iNewSR = GetSpellResistance(oCreature);
    int iNewAC = GetAC(oCreature);
    int iNewImmune = GetIsImmune(oCreature, IMMUNITY_TYPE_CURSED);

    NWNX_Tests_Report("NWNX_Feat", "AddFeat SetFeatModifier SR", iSR == iNewSR - 10);
    NWNX_Tests_Report("NWNX_Feat", "AddFeat SetFeatModifier AC", iAC == iNewAC - 1);
    NWNX_Tests_Report("NWNX_Feat", "AddFeat SetFeatModifier Immunity", iImmune != iNewImmune);

    NWNX_Creature_RemoveFeat(oCreature, FEAT_ALERTNESS);

    iNewSR = GetSpellResistance(oCreature);
    iNewAC = GetAC(oCreature);
    iNewImmune = GetIsImmune(oCreature, IMMUNITY_TYPE_CURSED);

    NWNX_Tests_Report("NWNX_Feat", "RemoveFeat SetFeatModifier SR", iSR == iNewSR);
    NWNX_Tests_Report("NWNX_Feat", "RemoveFeat SetFeatModifier AC", iAC == iNewAC);
    NWNX_Tests_Report("NWNX_Feat", "RemoveFeat SetFeatModifier Immunity", iImmune == iNewImmune);

    WriteTimestampedLogEntry("NWNX_Feat unit test end.");
}
