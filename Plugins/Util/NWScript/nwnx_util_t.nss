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

    effect e = EffectCurse(1,2,3,4,5,6);
    e = TagEffect(e, "NWNX_UTIL_TEST");
    itemproperty ip = NWNX_Util_EffectToItemProperty(e);
    e = NWNX_Util_ItemPropertyToEffect(ip);
    report("EffectToItemProperty_ItemPropertyToEffect", GetEffectTag(e) == "NWNX_UTIL_TEST");

    string uuid = NWNX_Util_GenerateUUID();
    report("GenerateUUID", GetStringLength(uuid) == 36);

    WriteTimestampedLogEntry("NWNX_Util unit test end.");
}
