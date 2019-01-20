#include "nwnx_visibility"

void report(string func, int bSuccess)
{
    if (bSuccess)
        WriteTimestampedLogEntry("NWNX_Visibility: " + func + "() success");
    else
        WriteTimestampedLogEntry("NWNX_Visibility: " + func + "() failed");
}

void main()
{
    WriteTimestampedLogEntry("NWNX_Visibility unit test begin..");

    object oCreature = CreateObject(OBJECT_TYPE_CREATURE, "nw_chicken", GetStartingLocation());
    if (!GetIsObjectValid(oCreature))
    {
        WriteTimestampedLogEntry("NWNX_Visibility test: Failed to create creature");
        return;
    }

    NWNX_Visibility_SetVisibilityOverride(OBJECT_INVALID, oCreature, NWNX_VISIBILITY_DM_ONLY);
    report("{Set/Get}VisibilityOverride (Global)", NWNX_Visibility_GetVisibilityOverride(OBJECT_INVALID, oCreature) == NWNX_VISIBILITY_DM_ONLY);

    object oPC = GetFirstPC();

    if( GetIsObjectValid(oPC) )
    {
        NWNX_Visibility_SetVisibilityOverride(oPC, oCreature, NWNX_VISIBILITY_HIDDEN);
        report("{Set/Get}VisibilityOverride (Personal)", NWNX_Visibility_GetVisibilityOverride(oPC, oCreature) == NWNX_VISIBILITY_HIDDEN);
    }
    else
    {
        WriteTimestampedLogEntry("No valid PC found, skipping personal visibility state tests");
    }

    DestroyObject(oCreature);

    WriteTimestampedLogEntry("NWNX_Visibility unit test end.");
}
