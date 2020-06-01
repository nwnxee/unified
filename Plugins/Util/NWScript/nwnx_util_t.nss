#include "nwnx_util"
#include "nwnx_test"
#include "x3_inc_string"

void main()
{
    while(TEST("Util"))
    {
        ASSERT(IS_TRUE(NWNX_Test_PluginExists("NWNX_Util")));

        string sScript = NWNX_Util_GetCurrentScriptName(0);
        EXPECT(IS_EQUAL_STRING(sScript, "nwnx_util_t"), "GetCurrentScriptName");

        string str = "string to be hashed";
        int hash = NWNX_Util_Hash(str);
        EXPECT(NOT_EQUAL_INT(hash, 0), "Hash");

        string ascii = NWNX_Util_GetAsciiTableString();
        EXPECT(IS_EQUAL_STRING(GetSubString(ascii, 65, 1), "A"), "GetAsciiTableString");

        SetCustomToken(1000, "Test Token 1000");
        string sToken = NWNX_Util_GetCustomToken(1000);
        EXPECT(IS_EQUAL_STRING(sToken, "Test Token 1000"), "GetCustomToken");

        effect e = EffectCurse(1,2,3,4,5,6);
        e = TagEffect(e, "NWNX_UTIL_TEST");
        itemproperty ip = NWNX_Util_EffectToItemProperty(e);
        e = NWNX_Util_ItemPropertyToEffect(ip);
        EXPECT(IS_EQUAL_STRING(GetEffectTag(e), "NWNX_UTIL_TEST"), "EffectToItemProperty_ItemPropertyToEffect");

        string sRedString = StringToRGBString("stripped colors.", STRING_COLOR_RED);
        str = "This is a <cfff>test</c> of "+sRedString;
        string strip_colors = NWNX_Util_StripColors(str);
        EXPECT(IS_EQUAL_STRING(strip_colors, "This is a test of stripped colors."), "Strip Colors");

        string sValidResRef = "nw_undeadhigh";
        EXPECT(IS_TRUE(NWNX_Util_IsValidResRef(sValidResRef, NWNX_UTIL_RESREF_TYPE_ENCOUNTER)), "IsValidResRef");
        string sInValidResRef = "aaaaaaaaaaaaaaaa";
        EXPECT(IS_FALSE(NWNX_Util_IsValidResRef(sInValidResRef, NWNX_UTIL_RESREF_TYPE_ITEM)), "IsValidResRef");

        string sEnvVar = "NWNX_CORE_LOG_LEVEL";
        EXPECT(IS_GT_INT(StringToInt(NWNX_Util_GetEnvironmentVariable(sEnvVar)), 0), "GetEnvironmentVariable");

        int nMinsPerHour = NWNX_Util_GetMinutesPerHour();
        EXPECT(IS_GT_INT(nMinsPerHour, 0), "GetMinutesPerHour");
        NWNX_Util_SetMinutesPerHour(30);
        EXPECT(IS_EQUAL_INT(NWNX_Util_GetMinutesPerHour(), 30), "SetMinutesPerHour");

        string sStringForURL = "This is a test, yes.";
        EXPECT(IS_EQUAL_STRING(NWNX_Util_EncodeStringForURL(sStringForURL), "This+is+a+test%2C+yes."), "EncodeStringForURL");

        string sTwoDA = "bodybag";
        EXPECT(IS_EQUAL_INT(NWNX_Util_Get2DARowCount(sTwoDA), 7), "Get2DARowCount");

        EXPECT(NOT_EQUAL_STRING(NWNX_Util_GetFirstResRef(NWNX_UTIL_RESREF_TYPE_NSS, "nwnx_util.*", FALSE), ""), "GetFirstResRef");
        EXPECT(NOT_EQUAL_STRING(NWNX_Util_GetNextResRef(), ""), "GetNextResRef");

        EXPECT(IS_GT_INT(NWNX_Util_GetServerTicksPerSecond(), 0), "GetServerTicksPerSecond");

        EXPECT(IS_VALID(NWNX_Util_GetLastCreatedObject(4/*OBJECT_TYPE_AREA*/, 1)), "GetLastCreatedObject");
    }
}
