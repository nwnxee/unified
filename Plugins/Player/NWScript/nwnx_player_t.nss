#include "nwnx_player"
#include "nwnx_test"

void main()
{
    while(TEST("Player"))
    {
        ASSERT(IS_TRUE(NWNX_Test_PluginExists("NWNX_Player")));

        object oPC = GetFirstPC();
        ASSERT(IS_VALID(oPC), "GetFirstPC()");
    }
}
