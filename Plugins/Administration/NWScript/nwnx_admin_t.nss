#include "nwnx_admin"
#include "nwnx_test"

void main()
{
    while(TEST("Administration"))
    {
        ASSERT(IS_TRUE(NWNX_Test_PluginExists("NWNX_Administration")));

        string sString = "FuzzyKittens";

        NWNX_Administration_SetPlayerPassword(sString);
        EXPECT(IS_EQUAL_STRING(NWNX_Administration_GetPlayerPassword(), sString), "{Set/Get}PlayerPassword");

        NWNX_Administration_ClearPlayerPassword();
        EXPECT(IS_EQUAL_STRING(NWNX_Administration_GetPlayerPassword(), ""), "ClearPlayerPassword");

        NWNX_Administration_SetDMPassword(sString);
        EXPECT(IS_EQUAL_STRING(NWNX_Administration_GetDMPassword(), sString), "{Set/Get}DMPassword");

        NWNX_Administration_SetPlayOption(NWNX_ADMINISTRATION_OPTION_EXAMINE_EFFECTS, TRUE);
        EXPECT(IS_TRUE(NWNX_Administration_GetPlayOption(NWNX_ADMINISTRATION_OPTION_EXAMINE_EFFECTS)), "{Set/Get}PlayOption");

        NWNX_Administration_SetDebugValue(NWNX_ADMINISTRATION_DEBUG_MOVEMENT_SPEED, TRUE);
        EXPECT(IS_TRUE(NWNX_Administration_GetDebugValue(NWNX_ADMINISTRATION_DEBUG_MOVEMENT_SPEED)), "{Set/Get}DebugValue");
    }
}
