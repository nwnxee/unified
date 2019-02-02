#include "nwnx"

struct NWNX_EffectUnpacked
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
    int bLinkRightValid;

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

// Convert native effect type to unpacked structure
struct NWNX_EffectUnpacked NWNX_Effect_UnpackEffect(effect e);
// Convert unpacked effect structure to native type
effect NWNX_Effect_PackEffect(struct NWNX_EffectUnpacked e);
// Set a script with optional data that runs when an effect expires
// Only works for TEMPORARY and PERMANENT effects applied to an object
//
// Note: OBJECT_SELF in the script is the object the effect is applied to
effect NWNX_Effect_SetEffectExpiredScript(effect e, string script, string data = "");
// Get the data set with NWNX_Effect_SetEffectExpiredScript()
//
// THIS SHOULD ONLY BE CALLED FROM WITHIN A SCRIPT THAT WAS EXECUTED BY NWNX_Effect_SetEffectExpiredScript()
string NWNX_Effect_GetEffectExpiredData();
// Get the effect creator of NWNX_Effect_SetEffectExpiredScript()
//
// THIS SHOULD ONLY BE CALLED FROM WITHIN A SCRIPT THAT WAS EXECUTED BY NWNX_Effect_SetEffectExpiredScript()
object NWNX_Effect_GetEffectExpiredCreator();


const string NWNX_Effect = "NWNX_Effect";

struct NWNX_EffectUnpacked NWNX_Effect_UnpackEffect(effect e)
{
    string sFunc = "UnpackEffect";

    NWNX_PushArgumentEffect(NWNX_Effect, sFunc, e);
    NWNX_CallFunction(NWNX_Effect, sFunc);

    struct NWNX_EffectUnpacked n;
    n.sTag = NWNX_GetReturnValueString(NWNX_Effect, sFunc);

    n.oParam3 = NWNX_GetReturnValueObject(NWNX_Effect, sFunc);
    n.oParam2 = NWNX_GetReturnValueObject(NWNX_Effect, sFunc);
    n.oParam1 = NWNX_GetReturnValueObject(NWNX_Effect, sFunc);
    n.oParam0 = NWNX_GetReturnValueObject(NWNX_Effect, sFunc);
    n.sParam5 = NWNX_GetReturnValueString(NWNX_Effect, sFunc);
    n.sParam4 = NWNX_GetReturnValueString(NWNX_Effect, sFunc);
    n.sParam3 = NWNX_GetReturnValueString(NWNX_Effect, sFunc);
    n.sParam2 = NWNX_GetReturnValueString(NWNX_Effect, sFunc);
    n.sParam1 = NWNX_GetReturnValueString(NWNX_Effect, sFunc);
    n.sParam0 = NWNX_GetReturnValueString(NWNX_Effect, sFunc);
    n.fParam3 = NWNX_GetReturnValueFloat(NWNX_Effect, sFunc);
    n.fParam2 = NWNX_GetReturnValueFloat(NWNX_Effect, sFunc);
    n.fParam1 = NWNX_GetReturnValueFloat(NWNX_Effect, sFunc);
    n.fParam0 = NWNX_GetReturnValueFloat(NWNX_Effect, sFunc);
    n.nParam7 = NWNX_GetReturnValueInt(NWNX_Effect, sFunc);
    n.nParam6 = NWNX_GetReturnValueInt(NWNX_Effect, sFunc);
    n.nParam5 = NWNX_GetReturnValueInt(NWNX_Effect, sFunc);
    n.nParam4 = NWNX_GetReturnValueInt(NWNX_Effect, sFunc);
    n.nParam3 = NWNX_GetReturnValueInt(NWNX_Effect, sFunc);
    n.nParam2 = NWNX_GetReturnValueInt(NWNX_Effect, sFunc);
    n.nParam1 = NWNX_GetReturnValueInt(NWNX_Effect, sFunc);
    n.nParam0 = NWNX_GetReturnValueInt(NWNX_Effect, sFunc);
    n.nNumIntegers = NWNX_GetReturnValueInt(NWNX_Effect, sFunc);

    n.bLinkRightValid = NWNX_GetReturnValueInt(NWNX_Effect, sFunc);
    n.eLinkRight = NWNX_GetReturnValueEffect(NWNX_Effect, sFunc);
    n.bLinkLeftValid = NWNX_GetReturnValueInt(NWNX_Effect, sFunc);
    n.eLinkLeft = NWNX_GetReturnValueEffect(NWNX_Effect, sFunc);

    n.nCasterLevel = NWNX_GetReturnValueInt(NWNX_Effect, sFunc);
    n.bShowIcon = NWNX_GetReturnValueInt(NWNX_Effect, sFunc);
    n.bExpose = NWNX_GetReturnValueInt(NWNX_Effect, sFunc);
    n.nSpellId = NWNX_GetReturnValueInt(NWNX_Effect, sFunc);
    n.oCreator = NWNX_GetReturnValueObject(NWNX_Effect, sFunc);

    n.nExpiryTimeOfDay = NWNX_GetReturnValueInt(NWNX_Effect, sFunc);
    n.nExpiryCalendarDay = NWNX_GetReturnValueInt(NWNX_Effect, sFunc);
    n.fDuration = NWNX_GetReturnValueFloat(NWNX_Effect, sFunc);

    n.nSubType = NWNX_GetReturnValueInt(NWNX_Effect, sFunc);
    n.nType = NWNX_GetReturnValueInt(NWNX_Effect, sFunc);

    return n;
}
effect NWNX_Effect_PackEffect(struct NWNX_EffectUnpacked e)
{
    string sFunc = "PackEffect";

    NWNX_PushArgumentInt(NWNX_Effect, sFunc, e.nType);
    NWNX_PushArgumentInt(NWNX_Effect, sFunc, e.nSubType);

    NWNX_PushArgumentFloat(NWNX_Effect, sFunc, e.fDuration);
    NWNX_PushArgumentInt(NWNX_Effect, sFunc, e.nExpiryCalendarDay);
    NWNX_PushArgumentInt(NWNX_Effect, sFunc, e.nExpiryTimeOfDay);

    NWNX_PushArgumentObject(NWNX_Effect, sFunc, e.oCreator);
    NWNX_PushArgumentInt(NWNX_Effect, sFunc, e.nSpellId);
    NWNX_PushArgumentInt(NWNX_Effect, sFunc, e.bExpose);
    NWNX_PushArgumentInt(NWNX_Effect, sFunc, e.bShowIcon);
    NWNX_PushArgumentInt(NWNX_Effect, sFunc, e.nCasterLevel);

    NWNX_PushArgumentEffect(NWNX_Effect, sFunc, e.eLinkLeft);
    NWNX_PushArgumentInt(NWNX_Effect, sFunc, e.bLinkLeftValid);
    NWNX_PushArgumentEffect(NWNX_Effect, sFunc, e.eLinkRight);
    NWNX_PushArgumentInt(NWNX_Effect, sFunc, e.bLinkRightValid);

    NWNX_PushArgumentInt(NWNX_Effect, sFunc, e.nNumIntegers);
    NWNX_PushArgumentInt(NWNX_Effect, sFunc, e.nParam0);
    NWNX_PushArgumentInt(NWNX_Effect, sFunc, e.nParam1);
    NWNX_PushArgumentInt(NWNX_Effect, sFunc, e.nParam2);
    NWNX_PushArgumentInt(NWNX_Effect, sFunc, e.nParam3);
    NWNX_PushArgumentInt(NWNX_Effect, sFunc, e.nParam4);
    NWNX_PushArgumentInt(NWNX_Effect, sFunc, e.nParam5);
    NWNX_PushArgumentInt(NWNX_Effect, sFunc, e.nParam6);
    NWNX_PushArgumentInt(NWNX_Effect, sFunc, e.nParam7);
    NWNX_PushArgumentFloat(NWNX_Effect, sFunc, e.fParam0);
    NWNX_PushArgumentFloat(NWNX_Effect, sFunc, e.fParam1);
    NWNX_PushArgumentFloat(NWNX_Effect, sFunc, e.fParam2);
    NWNX_PushArgumentFloat(NWNX_Effect, sFunc, e.fParam3);
    NWNX_PushArgumentString(NWNX_Effect, sFunc, e.sParam0);
    NWNX_PushArgumentString(NWNX_Effect, sFunc, e.sParam1);
    NWNX_PushArgumentString(NWNX_Effect, sFunc, e.sParam2);
    NWNX_PushArgumentString(NWNX_Effect, sFunc, e.sParam3);
    NWNX_PushArgumentString(NWNX_Effect, sFunc, e.sParam4);
    NWNX_PushArgumentString(NWNX_Effect, sFunc, e.sParam5);
    NWNX_PushArgumentObject(NWNX_Effect, sFunc, e.oParam0);
    NWNX_PushArgumentObject(NWNX_Effect, sFunc, e.oParam1);
    NWNX_PushArgumentObject(NWNX_Effect, sFunc, e.oParam2);
    NWNX_PushArgumentObject(NWNX_Effect, sFunc, e.oParam3);

    NWNX_PushArgumentString(NWNX_Effect, sFunc, e.sTag);

    NWNX_CallFunction(NWNX_Effect, sFunc);
    return NWNX_GetReturnValueEffect(NWNX_Effect, sFunc);
}

effect NWNX_Effect_SetEffectExpiredScript(effect e, string script, string data = "")
{
    string sFunc = "SetEffectExpiredScript";

    NWNX_PushArgumentString(NWNX_Effect, sFunc, data);
    NWNX_PushArgumentString(NWNX_Effect, sFunc, script);
    NWNX_PushArgumentEffect(NWNX_Effect, sFunc, e);

    NWNX_CallFunction(NWNX_Effect, sFunc);

    return NWNX_GetReturnValueEffect(NWNX_Effect, sFunc);
}

string NWNX_Effect_GetEffectExpiredData()
{
    string sFunc = "GetEffectExpiredData";

    NWNX_CallFunction(NWNX_Effect, sFunc);

    return NWNX_GetReturnValueString(NWNX_Effect, sFunc);
}

object NWNX_Effect_GetEffectExpiredCreator()
{
    string sFunc = "GetEffectExpiredCreator";

    NWNX_CallFunction(NWNX_Effect, sFunc);

    return NWNX_GetReturnValueObject(NWNX_Effect, sFunc);
}
