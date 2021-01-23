#include "nwnx_util"
#include "nwnx_tests"
#include "x3_inc_string"

void main()
{
    WriteTimestampedLogEntry("NWNX_Util unit test begin..");

    string sScript = NWNX_Util_GetCurrentScriptName(0);
    NWNX_Tests_Report("NWNX_Util", "GetCurrentScriptName", sScript == "nwnx_util_t");

    string str = "string to be hashed";
    int hash = NWNX_Util_Hash(str);
    NWNX_Tests_Report("NWNX_Util", "Hash", hash != 0);

    string ascii = NWNX_Util_GetAsciiTableString();
    NWNX_Tests_Report("NWNX_Util", "GetAsciiTableString", GetSubString(ascii, 65, 1) == "A");

    SetCustomToken(1000, "Test Token 1000");
    string sToken = NWNX_Util_GetCustomToken(1000);
    NWNX_Tests_Report("NWNX_Util", "GetCustomToken", sToken == "Test Token 1000");

    effect e = EffectCurse(1,2,3,4,5,6);
    e = TagEffect(e, "NWNX_UTIL_TEST");
    itemproperty ip = NWNX_Util_EffectToItemProperty(e);
    e = NWNX_Util_ItemPropertyToEffect(ip);
    NWNX_Tests_Report("NWNX_Util", "EffectToItemProperty_ItemPropertyToEffect", GetEffectTag(e) == "NWNX_UTIL_TEST");

    string sRedString = StringToRGBString("stripped colors.", STRING_COLOR_RED);
    str = "This is a <cfff>test</c> of "+sRedString;
    string strip_colors = NWNX_Util_StripColors(str);
    NWNX_Tests_Report("NWNX_Util", "RegexReplace", strip_colors == "This is a test of stripped colors.");

    string sValidResRef = "nw_undeadhigh";
    NWNX_Tests_Report("NWNX_Util", "IsValidResRef", NWNX_Util_IsValidResRef(sValidResRef, NWNX_UTIL_RESREF_TYPE_ENCOUNTER));
    string sInValidResRef = "aaaaaaaaaaaaaaaa";
    NWNX_Tests_Report("NWNX_Util", "IsValidResRef", NWNX_Util_IsValidResRef(sInValidResRef, NWNX_UTIL_RESREF_TYPE_ITEM) == 0);

    string sEnvVar = "NWNX_CORE_LOG_LEVEL";
    NWNX_Tests_Report("NWNX_Util", "GetEnvironmentVariable", StringToInt(NWNX_Util_GetEnvironmentVariable(sEnvVar)) > 0);

    int nMinsPerHour = NWNX_Util_GetMinutesPerHour();
    NWNX_Tests_Report("NWNX_Util", "GetMinutesPerHour", nMinsPerHour > 0);
    NWNX_Util_SetMinutesPerHour(30);
    NWNX_Tests_Report("NWNX_Util", "SetMinutesPerHour", NWNX_Util_GetMinutesPerHour() == 30);

    string sStringForURL = "This is a test, yes.";
    NWNX_Tests_Report("NWNX_Util", "EncodeStringForURL", NWNX_Util_EncodeStringForURL(sStringForURL) == "This+is+a+test%2C+yes.");

    string sTwoDA = "bodybag";
    NWNX_Tests_Report("NWNX_Util", "Get2DARowCount", NWNX_Util_Get2DARowCount(sTwoDA) == 7);

    NWNX_Tests_Report("NWNX_Util", "GetFirstResRef", NWNX_Util_GetFirstResRef(NWNX_UTIL_RESREF_TYPE_NSS, "nwnx_util.*") != "");
    NWNX_Tests_Report("NWNX_Util", "GetNextResRef", NWNX_Util_GetNextResRef() != "");

    NWNX_Tests_Report("NWNX_Util", "GetServerTicksPerSecond", NWNX_Util_GetServerTicksPerSecond() > 0);

    NWNX_Tests_Report("NWNX_Util", "GetLastCreatedObject", GetIsObjectValid(NWNX_Util_GetLastCreatedObject(4/*OBJECT_TYPE_AREA*/, 1)));

    struct NWNX_Util_HighResTimestamp t1 = NWNX_Util_GetHighResTimeStamp();
    // waste some time..
    DestroyObject(CreateObject(OBJECT_TYPE_CREATURE, "nw_chicken", GetStartingLocation()));
    DestroyObject(CreateObject(OBJECT_TYPE_CREATURE, "nw_chicken", GetStartingLocation()));
    DestroyObject(CreateObject(OBJECT_TYPE_CREATURE, "nw_chicken", GetStartingLocation()));
    DestroyObject(CreateObject(OBJECT_TYPE_CREATURE, "nw_chicken", GetStartingLocation()));
    struct NWNX_Util_HighResTimestamp t2 = NWNX_Util_GetHighResTimeStamp();
    WriteTimestampedLogEntry("t1.seconds: " + IntToString(t1.seconds) + "; " +
                             "t1.microseconds: " + IntToString(t1.microseconds) + "; " +
                             "t2.seconds: " + IntToString(t2.seconds) + "; " +
                             "t2.microseconds: " + IntToString(t2.microseconds) + "; ");
    NWNX_Tests_Report("NWNX_Util", "GetHighResTimeStamp", t1.microseconds != t2.microseconds);

    WriteTimestampedLogEntry("NWNX_Util unit test end.");
}
