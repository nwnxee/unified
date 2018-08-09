#include "nwnx_time"

void main()
{
    WriteTimestampedLogEntry("NWNX_Time unit test begin..");
    struct NWNX_Time_HighResTimestamp t1 = NWNX_Time_GetHighResTimeStamp();

    // waste some time..
    DestroyObject(CreateObject(OBJECT_TYPE_CREATURE, "nw_chicken", GetStartingLocation()));
    DestroyObject(CreateObject(OBJECT_TYPE_CREATURE, "nw_chicken", GetStartingLocation()));
    DestroyObject(CreateObject(OBJECT_TYPE_CREATURE, "nw_chicken", GetStartingLocation()));
    DestroyObject(CreateObject(OBJECT_TYPE_CREATURE, "nw_chicken", GetStartingLocation()));

    struct NWNX_Time_HighResTimestamp t2 = NWNX_Time_GetHighResTimeStamp();

    if (t1.microseconds == t2.microseconds) // yeah, chance of again triggering
        WriteTimestampedLogEntry("GetHighResTimeStamp failed");
    else
        WriteTimestampedLogEntry("GetHighResTimeStamp succeed");

    WriteTimestampedLogEntry("t1.seconds: " + IntToString(t1.seconds) + "; " +
                             "t1.microseconds: " + IntToString(t1.microseconds) + "; " +
                             "t2.seconds: " + IntToString(t2.seconds) + "; " +
                             "t2.microseconds: " + IntToString(t2.microseconds) + "; ");
}
