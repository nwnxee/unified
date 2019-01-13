#include "nwnx_util"

void report(string func, int bSuccess)
{
    if (bSuccess)
        WriteTimestampedLogEntry("NWNX_Util: " + func + "() success");
    else
        WriteTimestampedLogEntry("NWNX_Util: " + func + "() failed");
}

void main()
{
    WriteTimestampedLogEntry("NWNX_Util unit test begin..");

    string sScript = NWNX_Util_GetCurrentScriptName(0);
    report("GetCurrentScriptName", sScript == "nwnx_util_t");

    string str = "string to be hashed";
    int hash = NWNX_Util_Hash(str);
    report("Hash", hash != 0);

    string ascii = NWNX_Util_GetAsciiTableString();
    report("GetAsciiTableString", GetSubString(ascii, 65, 1) == "A");

    SetCustomToken(1000, "Test Token 1000");
    string sToken = NWNX_Util_GetCustomToken(1000);
    report("GetCustomToken", sToken == "Test Token 1000");

    WriteTimestampedLogEntry("NWNX_Util unit test end.");
}
