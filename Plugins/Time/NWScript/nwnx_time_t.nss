#include "nwnx_time"
#include "nwnx_test"

void main()
{
    while(TEST("Time"))
    {
        EXPECT(IS_TRUE(NWNX_Test_PluginExists("NWNX_Time")));
        struct NWNX_Time_HighResTimestamp t1 = NWNX_Time_GetHighResTimeStamp();

        // waste some time..
        DestroyObject(CreateObject(OBJECT_TYPE_CREATURE, "nw_chicken", GetStartingLocation()));
        DestroyObject(CreateObject(OBJECT_TYPE_CREATURE, "nw_chicken", GetStartingLocation()));
        DestroyObject(CreateObject(OBJECT_TYPE_CREATURE, "nw_chicken", GetStartingLocation()));
        DestroyObject(CreateObject(OBJECT_TYPE_CREATURE, "nw_chicken", GetStartingLocation()));

        struct NWNX_Time_HighResTimestamp t2 = NWNX_Time_GetHighResTimeStamp();
        EXPECT(NOT_EQUAL_INT(t1.microseconds, t2.microseconds));

        NWNX_Test_Context("t1.seconds: " + IntToString(t1.seconds) + "\n" +
                          "t1.microseconds: " + IntToString(t1.microseconds) + "\n" +
                          "t2.seconds: " + IntToString(t2.seconds) + "\n" +
                          "t2.microseconds: " + IntToString(t2.microseconds));

    }
}
