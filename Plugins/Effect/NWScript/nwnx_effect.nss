/// @addtogroup effect Effect
/// @brief Utility functions to manipulate the builtin effect type.
/// @{
/// @file nwnx_effect.nss
#include "nwnx"

const string NWNX_Effect = "NWNX_Effect"; ///< @private

/// An unpacked effect
struct NWNX_EffectUnpacked
{
    string sID; ///< @todo Describe
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

    string sItemProp; ///< @todo Describe
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

/// @brief Gets the true effect count
/// @param oObject The object to get the count of.
/// @return the number of effects (item properties and other non-exposed effects included)
int NWNX_Effect_GetTrueEffectCount(object oObject);

/// @brief Gets a specific effect on an object. This can grab effects normally hidden from developers, such as item properties.
/// @param oObject The object with the effect
/// @param nIndex The point in the array to retrieve (0 to GetTrueEffectCount())
/// @return A constructed NWNX_EffectUnpacked.
struct NWNX_EffectUnpacked NWNX_Effect_GetTrueEffect(object oObject, int nIndex);

/// @brief Replaces an already applied effect with another.
/// @param oObject The object with the effect to replace
/// @param nIndex The array element to be replaced
/// @param e The unpacked effect to replace it with.
/// @note Cannot replace an effect with a different type or ID.
void NWNX_Effect_ReplaceEffectByIndex(object oObject, int nIndex, struct  NWNX_EffectUnpacked e);

/// @brief Removes effect by ID
/// @param oObject The object to remove the effect from
/// @param sID The id of the effect, can be retrieved by unpacking effects.
/// @return FALSE/0 on failure TRUE/1 on success.
int NWNX_Effect_RemoveEffectById(object oObject,  string sID);

/// @brief Applys an effect, bypassing any processing done by ApplyEffectToObject
/// @param eEffect The effect to be applied.
/// @param oObject The object to apply it to.
void NWNX_Effect_Apply(effect eEffect, object oObject);

/// @}

struct NWNX_EffectUnpacked __NWNX_Effect_ResolveUnpack(string sFunc, int bLink=TRUE)
{
    struct NWNX_EffectUnpacked n;

    n.sItemProp = NWNX_GetReturnValueString();

    n.sTag = NWNX_GetReturnValueString();

    float fZ = NWNX_GetReturnValueFloat();
    float fY = NWNX_GetReturnValueFloat();
    float fX = NWNX_GetReturnValueFloat();
    n.vParam1 = Vector(fX, fY, fZ);
    fZ = NWNX_GetReturnValueFloat();
    fY = NWNX_GetReturnValueFloat();
    fX = NWNX_GetReturnValueFloat();
    n.vParam0 = Vector(fX, fY, fZ);
    n.oParam3 = NWNX_GetReturnValueObject();
    n.oParam2 = NWNX_GetReturnValueObject();
    n.oParam1 = NWNX_GetReturnValueObject();
    n.oParam0 = NWNX_GetReturnValueObject();
    n.sParam5 = NWNX_GetReturnValueString();
    n.sParam4 = NWNX_GetReturnValueString();
    n.sParam3 = NWNX_GetReturnValueString();
    n.sParam2 = NWNX_GetReturnValueString();
    n.sParam1 = NWNX_GetReturnValueString();
    n.sParam0 = NWNX_GetReturnValueString();
    n.fParam3 = NWNX_GetReturnValueFloat();
    n.fParam2 = NWNX_GetReturnValueFloat();
    n.fParam1 = NWNX_GetReturnValueFloat();
    n.fParam0 = NWNX_GetReturnValueFloat();
    n.nParam7 = NWNX_GetReturnValueInt();
    n.nParam6 = NWNX_GetReturnValueInt();
    n.nParam5 = NWNX_GetReturnValueInt();
    n.nParam4 = NWNX_GetReturnValueInt();
    n.nParam3 = NWNX_GetReturnValueInt();
    n.nParam2 = NWNX_GetReturnValueInt();
    n.nParam1 = NWNX_GetReturnValueInt();
    n.nParam0 = NWNX_GetReturnValueInt();
    n.nNumIntegers = NWNX_GetReturnValueInt();

    if(bLink)
    {
        n.bLinkRightValid = NWNX_GetReturnValueInt();
        n.eLinkRight = NWNX_GetReturnValueEffect();
        n.bLinkLeftValid = NWNX_GetReturnValueInt();
        n.eLinkLeft = NWNX_GetReturnValueEffect();
    }
    else
    {
        n.bLinkRightValid = FALSE;
        n.bLinkLeftValid = FALSE;
    }

    n.nCasterLevel = NWNX_GetReturnValueInt();
    n.bShowIcon = NWNX_GetReturnValueInt();
    n.bExpose = NWNX_GetReturnValueInt();
    n.nSpellId = NWNX_GetReturnValueInt();
    n.oCreator = NWNX_GetReturnValueObject();

    n.nExpiryTimeOfDay = NWNX_GetReturnValueInt();
    n.nExpiryCalendarDay = NWNX_GetReturnValueInt();
    n.fDuration = NWNX_GetReturnValueFloat();

    n.nSubType = NWNX_GetReturnValueInt();
    n.nType = NWNX_GetReturnValueInt();
    n.sID = NWNX_GetReturnValueString();

    return n;
}

void __NWNX_Effect_ResolvePack(string sFunc, struct NWNX_EffectUnpacked e, int bReplace=FALSE)
{
    if(!bReplace)
        NWNX_PushArgumentInt(e.nType);

    NWNX_PushArgumentInt(e.nSubType);

    NWNX_PushArgumentFloat(e.fDuration);
    NWNX_PushArgumentInt(e.nExpiryCalendarDay);
    NWNX_PushArgumentInt(e.nExpiryTimeOfDay);

    NWNX_PushArgumentObject(e.oCreator);
    NWNX_PushArgumentInt(e.nSpellId);
    NWNX_PushArgumentInt(e.bExpose);
    NWNX_PushArgumentInt(e.bShowIcon);
    NWNX_PushArgumentInt(e.nCasterLevel);

    if(!bReplace)
    {
        NWNX_PushArgumentEffect(e.eLinkLeft);
        NWNX_PushArgumentInt(e.bLinkLeftValid);
        NWNX_PushArgumentEffect(e.eLinkRight);
        NWNX_PushArgumentInt(e.bLinkRightValid);
    }

    NWNX_PushArgumentInt(e.nNumIntegers);
    NWNX_PushArgumentInt(e.nParam0);
    NWNX_PushArgumentInt(e.nParam1);
    NWNX_PushArgumentInt(e.nParam2);
    NWNX_PushArgumentInt(e.nParam3);
    NWNX_PushArgumentInt(e.nParam4);
    NWNX_PushArgumentInt(e.nParam5);
    NWNX_PushArgumentInt(e.nParam6);
    NWNX_PushArgumentInt(e.nParam7);
    NWNX_PushArgumentFloat(e.fParam0);
    NWNX_PushArgumentFloat(e.fParam1);
    NWNX_PushArgumentFloat(e.fParam2);
    NWNX_PushArgumentFloat(e.fParam3);
    NWNX_PushArgumentString(e.sParam0);
    NWNX_PushArgumentString(e.sParam1);
    NWNX_PushArgumentString(e.sParam2);
    NWNX_PushArgumentString(e.sParam3);
    NWNX_PushArgumentString(e.sParam4);
    NWNX_PushArgumentString(e.sParam5);
    NWNX_PushArgumentObject(e.oParam0);
    NWNX_PushArgumentObject(e.oParam1);
    NWNX_PushArgumentObject(e.oParam2);
    NWNX_PushArgumentObject(e.oParam3);

    NWNX_PushArgumentFloat(e.vParam0.x);
    NWNX_PushArgumentFloat(e.vParam0.y);
    NWNX_PushArgumentFloat(e.vParam0.z);

    NWNX_PushArgumentFloat(e.vParam1.x);
    NWNX_PushArgumentFloat(e.vParam1.y);
    NWNX_PushArgumentFloat(e.vParam1.z);

    NWNX_PushArgumentString(e.sTag);

    NWNX_PushArgumentString(e.sItemProp);
}

struct NWNX_EffectUnpacked NWNX_Effect_UnpackEffect(effect e)
{
    string sFunc = "UnpackEffect";

    NWNX_PushArgumentEffect(e);
    NWNX_CallFunction(NWNX_Effect, sFunc);

    return __NWNX_Effect_ResolveUnpack(sFunc);
}
effect NWNX_Effect_PackEffect(struct NWNX_EffectUnpacked e)
{
    string sFunc = "PackEffect";

    __NWNX_Effect_ResolvePack(sFunc, e);

    NWNX_CallFunction(NWNX_Effect, sFunc);
    return NWNX_GetReturnValueEffect();
}

effect NWNX_Effect_SetEffectExpiredScript(effect e, string script, string data = "")
{
    string sFunc = "SetEffectExpiredScript";

    NWNX_PushArgumentString(data);
    NWNX_PushArgumentString(script);
    NWNX_PushArgumentEffect(e);

    NWNX_CallFunction(NWNX_Effect, sFunc);

    return NWNX_GetReturnValueEffect();
}

string NWNX_Effect_GetEffectExpiredData()
{
    string sFunc = "GetEffectExpiredData";

    NWNX_CallFunction(NWNX_Effect, sFunc);

    return NWNX_GetReturnValueString();
}

object NWNX_Effect_GetEffectExpiredCreator()
{
    string sFunc = "GetEffectExpiredCreator";

    NWNX_CallFunction(NWNX_Effect, sFunc);

    return NWNX_GetReturnValueObject();
}

int NWNX_Effect_ReplaceEffect(object obj, effect eOld, effect eNew)
{
    string sFunc = "ReplaceEffect";

    NWNX_PushArgumentEffect(eNew);
    NWNX_PushArgumentEffect(eOld);
    NWNX_PushArgumentObject(obj);

    NWNX_CallFunction(NWNX_Effect, sFunc);

    return NWNX_GetReturnValueInt();
}

int NWNX_Effect_GetTrueEffectCount(object oObject)
{
    string sFunc = "GetTrueEffectCount";
    NWNX_PushArgumentObject(oObject);
    NWNX_CallFunction(NWNX_Effect, sFunc);

    return  NWNX_GetReturnValueInt();
}

struct NWNX_EffectUnpacked NWNX_Effect_GetTrueEffect(object oObject, int nIndex)
{
    string sFunc = "GetTrueEffect";
    NWNX_PushArgumentInt(nIndex);
    NWNX_PushArgumentObject(oObject);
    NWNX_CallFunction(NWNX_Effect, sFunc);

    return __NWNX_Effect_ResolveUnpack(sFunc, FALSE);
}

void NWNX_Effect_ReplaceEffectByIndex(object oObject, int nIndex, struct  NWNX_EffectUnpacked e)
{
    string sFunc = "ReplaceEffectByIndex";

    __NWNX_Effect_ResolvePack(sFunc, e, TRUE);

    NWNX_PushArgumentInt(nIndex);
    NWNX_PushArgumentObject(oObject);
    NWNX_CallFunction(NWNX_Effect, sFunc);

}

int NWNX_Effect_RemoveEffectById(object oObject,  string sID)
{
    string sFunc = "RemoveEffectById";
    NWNX_PushArgumentString(sID);
    NWNX_PushArgumentObject(oObject);
    NWNX_CallFunction(NWNX_Effect, sFunc);

    return  NWNX_GetReturnValueInt();
}

void NWNX_Effect_Apply(effect eEffect, object oObject)
{
    string sFunc = "Apply";
    NWNX_PushArgumentObject(oObject);
    NWNX_PushArgumentEffect(eEffect);
    NWNX_CallFunction(NWNX_Effect, sFunc);
}
