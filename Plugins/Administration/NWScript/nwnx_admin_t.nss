#include "nwnx_admin"
#include "nwnx_tests"

void main()
{
    WriteTimestampedLogEntry("NWNX_Administration unit test begin..");

    string sString = "FuzzyKittens";

    NWNX_Administration_SetPlayerPassword(sString);
    NWNX_Tests_Report("NWNX_Administration", "{Set/Get}PlayerPassword", NWNX_Administration_GetPlayerPassword() == sString);

    NWNX_Administration_ClearPlayerPassword();
    NWNX_Tests_Report("NWNX_Administration", "ClearPlayerPassword", NWNX_Administration_GetPlayerPassword() == "");

    NWNX_Administration_SetDMPassword(sString);
    NWNX_Tests_Report("NWNX_Administration", "{Set/Get}DMPassword", NWNX_Administration_GetDMPassword() == sString);

    NWNX_Administration_SetPlayOption(NWNX_ADMINISTRATION_OPTION_EXAMINE_EFFECTS, TRUE);
    NWNX_Tests_Report("NWNX_Administration", "{Set/Get}PlayOption", NWNX_Administration_GetPlayOption(NWNX_ADMINISTRATION_OPTION_EXAMINE_EFFECTS));

    WriteTimestampedLogEntry("NWNX_Administration unit test end.");
}
