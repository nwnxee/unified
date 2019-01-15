#include "nwnx_util"


void printeff(struct NWNX_Effect n)
{
    string s = "Unpacked effect: \n";
    s += "nType = " + IntToString(n.nType) + "\n";
    s += "nSubType = " + IntToString(n.nSubType) + "\n";

    s += "fDuration = " + FloatToString(n.fDuration) + "\n";
    s += "nExpiryCalendarDay = " + IntToString(n.nExpiryCalendarDay) + "\n";
    s += "nExpiryTimeOfDay = " + IntToString(n.nExpiryTimeOfDay) + "\n";

    s += "oCreator = " + ObjectToString(n.oCreator) + "\n";
    s += "nSpellId = " + IntToString(n.nSpellId) + "\n";
    s += "bExpose = " + IntToString(n.bExpose) + "\n";
    s += "bShowIcon = " + IntToString(n.bShowIcon) + "\n";
    s += "nCasterLevel = " + IntToString(n.nCasterLevel) + "\n";

    s += "bLinkLeftValid = " + IntToString(n.bLinkLeftValid) + "\n";
    s += "eLinkRightValid = " + IntToString(n.eLinkRightValid) + "\n";

    s += "nNumIntegers = " + IntToString(n.nNumIntegers) + "\n";
    s += "nParam0 = " + IntToString(n.nParam0) + "\n";
    s += "nParam1 = " + IntToString(n.nParam1) + "\n";
    s += "nParam2 = " + IntToString(n.nParam2) + "\n";
    s += "nParam3 = " + IntToString(n.nParam3) + "\n";
    s += "nParam4 = " + IntToString(n.nParam4) + "\n";
    s += "nParam5 = " + IntToString(n.nParam5) + "\n";
    s += "nParam6 = " + IntToString(n.nParam6) + "\n";
    s += "nParam7 = " + IntToString(n.nParam7) + "\n";
    s += "fParam0 = " + FloatToString(n.fParam0) + "\n";
    s += "fParam1 = " + FloatToString(n.fParam1) + "\n";
    s += "fParam2 = " + FloatToString(n.fParam2) + "\n";
    s += "fParam3 = " + FloatToString(n.fParam3) + "\n";
    s += "sParam0 = " + "'" + n.sParam0 + "'" + "\n";
    s += "sParam1 = " + "'" + n.sParam1 + "'" + "\n";
    s += "sParam2 = " + "'" + n.sParam2 + "'" + "\n";
    s += "sParam3 = " + "'" + n.sParam3 + "'" + "\n";
    s += "sParam4 = " + "'" + n.sParam4 + "'" + "\n";
    s += "sParam5 = " + "'" + n.sParam5 + "'" + "\n";
    s += "oParam0 = " + ObjectToString(n.oParam0) + "\n";
    s += "oParam1 = " + ObjectToString(n.oParam1) + "\n";
    s += "oParam2 = " + ObjectToString(n.oParam2) + "\n";
    s += "oParam3 = " + ObjectToString(n.oParam3) + "\n";

    s += "sTag = " + "'" + n.sTag + "'" + "\n";

    WriteTimestampedLogEntry(s);
}


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

    WriteTimestampedLogEntry("NWNX_Util unit test end.");


    struct NWNX_Effect unpacked = NWNX_Util_UnpackEffect(EffectCurse(1,2,3,4,5,6));
    printeff(unpacked);
    effect packed = NWNX_Util_PackEffect(unpacked);

    object oCreature = CreateObject(OBJECT_TYPE_CREATURE, "nw_chicken", GetStartingLocation());
    ApplyEffectToObject(DURATION_TYPE_PERMANENT, packed, oCreature);
}
