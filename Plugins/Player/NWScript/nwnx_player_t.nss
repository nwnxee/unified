#include "nwnx_player"
#include "nwnx_tests"

void main()
{
    WriteTimestampedLogEntry("NWNX_Player unit test begin..");

    object oPC = GetFirstPC();
    if (!GetIsObjectValid(oPC))
    {
        WriteTimestampedLogEntry("NWNX_Player test: No PC found");
        return;
    }

    object oGameObject = NWNX_Player_GetGameObject(oPC);
    NWNX_Tests_Report("NWNX_Player", "GetControllingPlayer", NWNX_Player_GetControllingPlayer(oGameObject) == oPC);

    object oCreature = CreateObject(OBJECT_TYPE_CREATURE, "nw_chicken", GetStartingLocation());
    NWNX_Tests_Report("NWNX_Player", "GetControllingPlayer (not controlled)", NWNX_Player_GetControllingPlayer(oCreature) == OBJECT_INVALID);
    DestroyObject(oCreature);

    WriteTimestampedLogEntry("NWNX_Player unit test end.");
}
