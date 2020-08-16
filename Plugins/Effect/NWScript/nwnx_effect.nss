/// @addtogroup effect Effect
/// @brief Utility functions to manipulate the builtin effect type.
/// @{
/// @file nwnx_effect.nss
#include "nwnx"

const string NWNX_Effect = "NWNX_Effect"; ///< @private

/// An unpacked effect
struct NWNX_EffectUnpacked
{
    int nType; ///< @todo Describe
    int nSubType; ///< @todo Describe

    float fDuration; ///< @todo Describe
    int nExpiryCalendarDay; ///< @todo Describe
    int nExpiryTimeOfDay; ///< @todo Describe

    object oCreator; ///< @todo Describe
    int nSpellId; ///< @todo Describe
    int bExpose; ///< @todo Describe
    int bShowIcon; ///< @todo Describe
    int nCasterLevel; ///< @todo Describe

    effect eLinkLeft; ///< @todo Describe
    int bLinkLeftValid; ///< @todo Describe
    effect eLinkRight; ///< @todo Describe
    int bLinkRightValid; ///< @todo Describe

    int nNumIntegers; ///< @todo Describe
    int nParam0; ///< @todo Describe
    int nParam1; ///< @todo Describe
    int nParam2; ///< @todo Describe
    int nParam3; ///< @todo Describe
    int nParam4; ///< @todo Describe
    int nParam5; ///< @todo Describe
    int nParam6; ///< @todo Describe
    int nParam7; ///< @todo Describe
    float fParam0; ///< @todo Describe
    float fParam1; ///< @todo Describe
    float fParam2; ///< @todo Describe
    float fParam3; ///< @todo Describe
    string sParam0; ///< @todo Describe
    string sParam1; ///< @todo Describe
    string sParam2; ///< @todo Describe
    string sParam3; ///< @todo Describe
    string sParam4; ///< @todo Describe
    string sParam5; ///< @todo Describe
    object oParam0; ///< @todo Describe
    object oParam1; ///< @todo Describe
    object oParam2; ///< @todo Describe
    object oParam3; ///< @todo Describe
    vector vParam0; ///< @todo Describe
    vector vParam1; ///< @todo Describe

    string sTag; ///< @todo Describe
};

/// @brief Convert native effect type to unpacked structure.
/// @param e The effect to convert.
/// @return A constructed NWNX_EffectUnpacked.
struct NWNX_EffectUnpacked NWNX_Effect_UnpackEffect(effect e);

/// @brief Convert unpacked effect structure to native type.
/// @param e The NWNX_EffectUnpacked structure to convert.
/// @return The effect.
effect NWNX_Effect_PackEffect(struct NWNX_EffectUnpacked e);

/// @brief Set a script with optional data that runs when an effect expires
/// @param e The effect.
/// @param script The script to run when the effect expires.
/// @param data Any other data you wish to send back to the script.
/// @remark OBJECT_SELF in the script is the object the effect is applied to.
/// @note Only works for TEMPORARY and PERMANENT effects applied to an object.
effect NWNX_Effect_SetEffectExpiredScript(effect e, string script, string data = "");

/// @brief Get the data set with NWNX_Effect_SetEffectExpiredScript()
/// @note Should only be called from a script set with NWNX_Effect_SetEffectExpiredScript().
/// @return The data attached to the effect.
string NWNX_Effect_GetEffectExpiredData();

/// @brief Get the effect creator.
/// @note Should only be called from a script set with NWNX_Effect_SetEffectExpiredScript().
/// @return The object from which the effect originated.
object NWNX_Effect_GetEffectExpiredCreator();

/// @brief replace an already applied effect on an object
/// Only duration, subtype, tag and spell related fields can be overwritten.
/// @note eNew and eOld need to have the same type.
/// @return Number of internal effects updated.
int NWNX_Effect_ReplaceEffect(object obj, effect eOld, effect eNew);

/// @}

struct NWNX_EffectUnpacked NWNX_Effect_UnpackEffect(effect e)
{
    string sFunc = "UnpackEffect";

    NWNX_PushArgumentEffect(NWNX_Effect, sFunc, e);
    NWNX_CallFunction(NWNX_Effect, sFunc);

    struct NWNX_EffectUnpacked n;
    n.sTag = NWNX_GetReturnValueString(NWNX_Effect, sFunc);

    float fZ = NWNX_GetReturnValueFloat(NWNX_Effect, sFunc);
    float fY = NWNX_GetReturnValueFloat(NWNX_Effect, sFunc);
    float fX = NWNX_GetReturnValueFloat(NWNX_Effect, sFunc);
    n.vParam1 = Vector(fX, fY, fZ);
    fZ = NWNX_GetReturnValueFloat(NWNX_Effect, sFunc);
    fY = NWNX_GetReturnValueFloat(NWNX_Effect, sFunc);
    fX = NWNX_GetReturnValueFloat(NWNX_Effect, sFunc);
    n.vParam0 = Vector(fX, fY, fZ);
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

    NWNX_PushArgumentFloat(NWNX_Effect, sFunc, e.vParam0.x);
    NWNX_PushArgumentFloat(NWNX_Effect, sFunc, e.vParam0.y);
    NWNX_PushArgumentFloat(NWNX_Effect, sFunc, e.vParam0.z);

    NWNX_PushArgumentFloat(NWNX_Effect, sFunc, e.vParam1.x);
    NWNX_PushArgumentFloat(NWNX_Effect, sFunc, e.vParam1.y);
    NWNX_PushArgumentFloat(NWNX_Effect, sFunc, e.vParam1.z);

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

int NWNX_Effect_ReplaceEffect(object obj, effect eOld, effect eNew)
{
    string sFunc = "ReplaceEffect";

    NWNX_PushArgumentEffect(NWNX_Effect, sFunc, eNew);
    NWNX_PushArgumentEffect(NWNX_Effect, sFunc, eOld);
    NWNX_PushArgumentObject(NWNX_Effect, sFunc, obj);

    NWNX_CallFunction(NWNX_Effect, sFunc);

    return NWNX_GetReturnValueInt(NWNX_Effect, sFunc);
}
