#include "nwnx_player"



void report(string func, int bSuccess)
{
    if (bSuccess)
        WriteTimestampedLogEntry("NWNX_Player: " + func + "() success");
    else
        WriteTimestampedLogEntry("NWNX_Player: " + func + "() failed");
}
void main()
{
    WriteTimestampedLogEntry("NWNX_Player unit test begin..");

    object oPC = GetFirstPC();
    if (!GetIsObjectValid(oPC))
    {
        WriteTimestampedLogEntry("NWNX_Player test: No PC found");
        return;
    }

    WriteTimestampedLogEntry("NWNX_Player unit test end.");
}
