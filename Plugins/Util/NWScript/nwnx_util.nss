#include "nwnx"

// Returns the name of the currently executing script.
// If depth is >0, it will return the name of the script that called this one via ExecuteScript()
string NWNX_Util_GetCurrentScriptName(int depth=0);
// Returns a string that contains all characters at their position (e.g. 'A' at 65).
// The character at index 0 is a space.
string NWNX_Util_GetAsciiTableString();
// Returns an integer hash of a string
int NWNX_Util_Hash(string str);


struct NWNX_Effect
{
    int nType;
    int nSubType;

    float fDuration;
    int nExpiryCalendarDay;
    int nExpiryTimeOfDay;

    object oCreator;
    int nSpellId;
    int bExpose;
    int bShowIcon;
    int nCasterLevel;

    effect eLinkLeft;
    int bLinkLeftValid;
    effect eLinkRight;
    int eLinkRightValid;

    int nNumIntegers;
    int nParam0;
    int nParam1;
    int nParam2;
    int nParam3;
    int nParam4;
    int nParam5;
    int nParam6;
    int nParam7;
    float fParam0;
    float fParam1;
    float fParam2;
    float fParam3;
    string sParam0;
    string sParam1;
    string sParam2;
    string sParam3;
    string sParam4;
    string sParam5;
    object oParam0;
    object oParam1;
    object oParam2;
    object oParam3;

    string sTag;
};



const string NWNX_Util = "NWNX_Util";


string NWNX_Util_GetCurrentScriptName(int depth=0)
{
    string sFunc = "GetCurrentScriptName";
    NWNX_PushArgumentInt(NWNX_Util, sFunc, depth);
    NWNX_CallFunction(NWNX_Util, sFunc);
    return NWNX_GetReturnValueString(NWNX_Util, sFunc);
}
string NWNX_Util_GetAsciiTableString()
{
    string sFunc = "GetAsciiTableString";
    NWNX_CallFunction(NWNX_Util, sFunc);
    return NWNX_GetReturnValueString(NWNX_Util, sFunc);
}
int NWNX_Util_Hash(string str)
{
    string sFunc = "Hash";
    NWNX_PushArgumentString(NWNX_Util, sFunc, str);
    NWNX_CallFunction(NWNX_Util, sFunc);
    return NWNX_GetReturnValueInt(NWNX_Util, sFunc);
}


struct NWNX_Effect NWNX_Util_UnpackEffect(effect e)
{
    string sFunc = "UnpackEffect";

    NWNX_PushArgumentEffect(NWNX_Util, sFunc, e);
    NWNX_CallFunction(NWNX_Util, sFunc);

    struct NWNX_Effect n;
    n.sTag = NWNX_GetReturnValueString(NWNX_Util, sFunc);

    n.oParam3 = NWNX_GetReturnValueObject(NWNX_Util, sFunc);
    n.oParam2 = NWNX_GetReturnValueObject(NWNX_Util, sFunc);
    n.oParam1 = NWNX_GetReturnValueObject(NWNX_Util, sFunc);
    n.oParam0 = NWNX_GetReturnValueObject(NWNX_Util, sFunc);
    n.sParam5 = NWNX_GetReturnValueString(NWNX_Util, sFunc);
    n.sParam4 = NWNX_GetReturnValueString(NWNX_Util, sFunc);
    n.sParam3 = NWNX_GetReturnValueString(NWNX_Util, sFunc);
    n.sParam2 = NWNX_GetReturnValueString(NWNX_Util, sFunc);
    n.sParam1 = NWNX_GetReturnValueString(NWNX_Util, sFunc);
    n.sParam0 = NWNX_GetReturnValueString(NWNX_Util, sFunc);
    n.fParam3 = NWNX_GetReturnValueFloat(NWNX_Util, sFunc);
    n.fParam2 = NWNX_GetReturnValueFloat(NWNX_Util, sFunc);
    n.fParam1 = NWNX_GetReturnValueFloat(NWNX_Util, sFunc);
    n.fParam0 = NWNX_GetReturnValueFloat(NWNX_Util, sFunc);
    n.nParam7 = NWNX_GetReturnValueInt(NWNX_Util, sFunc);
    n.nParam6 = NWNX_GetReturnValueInt(NWNX_Util, sFunc);
    n.nParam5 = NWNX_GetReturnValueInt(NWNX_Util, sFunc);
    n.nParam4 = NWNX_GetReturnValueInt(NWNX_Util, sFunc);
    n.nParam3 = NWNX_GetReturnValueInt(NWNX_Util, sFunc);
    n.nParam2 = NWNX_GetReturnValueInt(NWNX_Util, sFunc);
    n.nParam1 = NWNX_GetReturnValueInt(NWNX_Util, sFunc);
    n.nParam0 = NWNX_GetReturnValueInt(NWNX_Util, sFunc);
    n.nNumIntegers = NWNX_GetReturnValueInt(NWNX_Util, sFunc);

    n.eLinkRightValid = NWNX_GetReturnValueInt(NWNX_Util, sFunc);
    n.eLinkRight = NWNX_GetReturnValueEffect(NWNX_Util, sFunc);
    n.bLinkLeftValid = NWNX_GetReturnValueInt(NWNX_Util, sFunc);
    n.eLinkLeft = NWNX_GetReturnValueEffect(NWNX_Util, sFunc);

    n.nCasterLevel = NWNX_GetReturnValueInt(NWNX_Util, sFunc);
    n.bShowIcon = NWNX_GetReturnValueInt(NWNX_Util, sFunc);
    n.bExpose = NWNX_GetReturnValueInt(NWNX_Util, sFunc);
    n.nSpellId = NWNX_GetReturnValueInt(NWNX_Util, sFunc);
    n.oCreator = NWNX_GetReturnValueObject(NWNX_Util, sFunc);

    n.nExpiryTimeOfDay = NWNX_GetReturnValueInt(NWNX_Util, sFunc);
    n.nExpiryCalendarDay = NWNX_GetReturnValueInt(NWNX_Util, sFunc);
    n.fDuration = NWNX_GetReturnValueFloat(NWNX_Util, sFunc);

    n.nSubType = NWNX_GetReturnValueInt(NWNX_Util, sFunc);
    n.nType = NWNX_GetReturnValueInt(NWNX_Util, sFunc);

    return n;
}
effect NWNX_Util_PackEffect(struct NWNX_Effect e)
{
    string sFunc = "PackEffect";

    NWNX_PushArgumentInt(NWNX_Util, sFunc, e.nType);
    NWNX_PushArgumentInt(NWNX_Util, sFunc, e.nSubType);

    NWNX_PushArgumentFloat(NWNX_Util, sFunc, e.fDuration);
    NWNX_PushArgumentInt(NWNX_Util, sFunc, e.nExpiryCalendarDay);
    NWNX_PushArgumentInt(NWNX_Util, sFunc, e.nExpiryTimeOfDay);

    NWNX_PushArgumentObject(NWNX_Util, sFunc, e.oCreator);
    NWNX_PushArgumentInt(NWNX_Util, sFunc, e.nSpellId);
    NWNX_PushArgumentInt(NWNX_Util, sFunc, e.bExpose);
    NWNX_PushArgumentInt(NWNX_Util, sFunc, e.bShowIcon);
    NWNX_PushArgumentInt(NWNX_Util, sFunc, e.nCasterLevel);

    NWNX_PushArgumentEffect(NWNX_Util, sFunc, e.eLinkLeft);
    NWNX_PushArgumentInt(NWNX_Util, sFunc, e.bLinkLeftValid);
    NWNX_PushArgumentEffect(NWNX_Util, sFunc, e.eLinkRight);
    NWNX_PushArgumentInt(NWNX_Util, sFunc, e.eLinkRightValid);

    NWNX_PushArgumentInt(NWNX_Util, sFunc, e.nNumIntegers);
    NWNX_PushArgumentInt(NWNX_Util, sFunc, e.nParam0);
    NWNX_PushArgumentInt(NWNX_Util, sFunc, e.nParam1);
    NWNX_PushArgumentInt(NWNX_Util, sFunc, e.nParam2);
    NWNX_PushArgumentInt(NWNX_Util, sFunc, e.nParam3);
    NWNX_PushArgumentInt(NWNX_Util, sFunc, e.nParam4);
    NWNX_PushArgumentInt(NWNX_Util, sFunc, e.nParam5);
    NWNX_PushArgumentInt(NWNX_Util, sFunc, e.nParam6);
    NWNX_PushArgumentInt(NWNX_Util, sFunc, e.nParam7);
    NWNX_PushArgumentFloat(NWNX_Util, sFunc, e.fParam0);
    NWNX_PushArgumentFloat(NWNX_Util, sFunc, e.fParam1);
    NWNX_PushArgumentFloat(NWNX_Util, sFunc, e.fParam2);
    NWNX_PushArgumentFloat(NWNX_Util, sFunc, e.fParam3);
    NWNX_PushArgumentString(NWNX_Util, sFunc, e.sParam0);
    NWNX_PushArgumentString(NWNX_Util, sFunc, e.sParam1);
    NWNX_PushArgumentString(NWNX_Util, sFunc, e.sParam2);
    NWNX_PushArgumentString(NWNX_Util, sFunc, e.sParam3);
    NWNX_PushArgumentString(NWNX_Util, sFunc, e.sParam4);
    NWNX_PushArgumentString(NWNX_Util, sFunc, e.sParam5);
    NWNX_PushArgumentObject(NWNX_Util, sFunc, e.oParam0);
    NWNX_PushArgumentObject(NWNX_Util, sFunc, e.oParam1);
    NWNX_PushArgumentObject(NWNX_Util, sFunc, e.oParam2);
    NWNX_PushArgumentObject(NWNX_Util, sFunc, e.oParam3);

    NWNX_PushArgumentString(NWNX_Util, sFunc, e.sTag);

    NWNX_CallFunction(NWNX_Util, sFunc);
    return NWNX_GetReturnValueEffect(NWNX_Util, sFunc);
}
