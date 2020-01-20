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

    WriteTimestampedLogEntry("NWNX_Player unit test end.");
}
