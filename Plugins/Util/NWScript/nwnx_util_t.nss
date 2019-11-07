#include "nwnx_util"
#include "x3_inc_string"

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

    string sRedString = StringToRGBString("stripped colors.", STRING_COLOR_RED);
    str = "This is a <cfff>test</c> of "+sRedString;
    string strip_colors = NWNX_Util_StripColors(str);
    report("RegexReplace", strip_colors == "This is a test of stripped colors.");

    string sValidResRef = "nw_undeadhigh";
    report("IsValidResRef", NWNX_Util_IsValidResRef(sValidResRef, NWNX_UTIL_RESREF_TYPE_ENCOUNTER));
    string sInValidResRef = "aaaaaaaaaaaaaaaa";
    report("IsValidResRef", NWNX_Util_IsValidResRef(sInValidResRef, NWNX_UTIL_RESREF_TYPE_ITEM) == 0);

    string sEnvVar = "NWNX_CORE_LOG_LEVEL";
    report("GetEnvironmentVariable", StringToInt(NWNX_Util_GetEnvironmentVariable(sEnvVar)) > 0);

    int nMinsPerHour = NWNX_Util_GetMinutesPerHour();
    report("GetMinutesPerHour", nMinsPerHour > 0);
    NWNX_Util_SetMinutesPerHour(30);
    report("SetMinutesPerHour", NWNX_Util_GetMinutesPerHour() == 30);

    string sStringForURL = "This is a test, yes.";
    report("EncodeStringForURL", NWNX_Util_EncodeStringForURL(sStringForURL) == "This+is+a+test%2C+yes.");

    string sTwoDA = "bodybag";
    report("Get2DARowCount", NWNX_Util_Get2DARowCount(sTwoDA) == 7);

    report("GetFirstResRef", NWNX_Util_GetFirstResRef(NWNX_UTIL_RESREF_TYPE_NSS, "nwnx_util.*") != "");
    report("GetNextResRef", NWNX_Util_GetNextResRef() != "");

    report("GetServerTicksPerSecond", NWNX_Util_GetServerTicksPerSecond() > 0);

    report("GetLastCreatedObject", GetIsObjectValid(NWNX_Util_GetLastCreatedObject(4/*OBJECT_TYPE_AREA*/, 1)));

    WriteTimestampedLogEntry("NWNX_Util unit test end.");
}
