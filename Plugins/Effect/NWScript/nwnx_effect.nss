/// @addtogroup effect Effect
/// @brief Utility functions to manipulate the builtin effect type.
/// @{
/// @file nwnx_effect.nss

const string NWNX_Effect = "NWNX_Effect"; ///< @private

/// EQUIPPED effects are always associated with a slotted item:
/// Setting this duration type requires the effect creator
/// to be set to the (already equipped) item that should remove
/// this effect when unequipped.
/// Removal behaviour for effects where the creator is NOT a equipped
/// item is undefined.
/// They are not removed by resting, cannot be dispelled, etc.
const int DURATION_TYPE_EQUIPPED = 3;

/// These are feat/racial effects used internally by the game to
/// implement things like movement speed changes and darkvision.
/// They cannot be removed by resting, dispelling, etc.
const int DURATION_TYPE_INNATE   = 4;

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

/// @brief Sets an effect creator.
/// @param eEffect The effect to be modified.
/// @param oObject The effect creator.
/// @return The effect with creator field set.
effect NWNX_Effect_SetEffectCreator(effect eEffect, object oObject);

/// @brief Checks if the given effect is valid. Unlike the game builtin, this call considers internal types too.
/// @param eEffect The effect to check
/// @return TRUE if the effect is valid (including internal types).
int NWNX_Effect_GetIsEffectValid(effect eEffect);

/// @brief Returns the number of applied effects on the given object.
/// @param oObject The object to get the applied effect count for.
/// @return The number of applied effects, including internal.
int NWNX_Effect_GetAppliedEffectCount(object oObject);

/// @brief Returns the nNth applied effect on a object.
/// @param oObject The object to get the applied effect copy for.
/// @param nNth The effect index to get.
/// @note Make sure to check with NWNX_Effect_GetIsEffectValid, as this iterator also includes internal effects.
/// @return A copy of the applied game effect, or a invalid effect.
effect NWNX_Effect_GetAppliedEffect(object oObject, int nNth);

/// @}

struct NWNX_EffectUnpacked __NWNX_Effect_ResolveUnpack(int bLink=TRUE)
{
    struct NWNX_EffectUnpacked n;

    n.sItemProp = NWNXPopString();

    n.sTag = NWNXPopString();

    n.vParam1 = NWNXPopVector();
    n.vParam0 = NWNXPopVector();
    n.oParam3 = NWNXPopObject();
    n.oParam2 = NWNXPopObject();
    n.oParam1 = NWNXPopObject();
    n.oParam0 = NWNXPopObject();
    n.sParam5 = NWNXPopString();
    n.sParam4 = NWNXPopString();
    n.sParam3 = NWNXPopString();
    n.sParam2 = NWNXPopString();
    n.sParam1 = NWNXPopString();
    n.sParam0 = NWNXPopString();
    n.fParam3 = NWNXPopFloat();
    n.fParam2 = NWNXPopFloat();
    n.fParam1 = NWNXPopFloat();
    n.fParam0 = NWNXPopFloat();
    n.nParam7 = NWNXPopInt();
    n.nParam6 = NWNXPopInt();
    n.nParam5 = NWNXPopInt();
    n.nParam4 = NWNXPopInt();
    n.nParam3 = NWNXPopInt();
    n.nParam2 = NWNXPopInt();
    n.nParam1 = NWNXPopInt();
    n.nParam0 = NWNXPopInt();
    n.nNumIntegers = NWNXPopInt();

    if(bLink)
    {
        n.bLinkRightValid = NWNXPopInt();
        n.eLinkRight = NWNXPopEffect();
        n.bLinkLeftValid = NWNXPopInt();
        n.eLinkLeft = NWNXPopEffect();
    }
    else
    {
        n.bLinkRightValid = FALSE;
        n.bLinkLeftValid = FALSE;
    }

    n.nCasterLevel = NWNXPopInt();
    n.bShowIcon = NWNXPopInt();
    n.bExpose = NWNXPopInt();
    n.nSpellId = NWNXPopInt();
    n.oCreator = NWNXPopObject();

    n.nExpiryTimeOfDay = NWNXPopInt();
    n.nExpiryCalendarDay = NWNXPopInt();
    n.fDuration = NWNXPopFloat();

    n.nSubType = NWNXPopInt();
    n.nType = NWNXPopInt();
    n.sID = NWNXPopString();

    return n;
}

void __NWNX_Effect_ResolvePack(struct NWNX_EffectUnpacked e, int bReplace=FALSE)
{
    if(!bReplace)
        NWNXPushInt(e.nType);

    NWNXPushInt(e.nSubType);

    NWNXPushFloat(e.fDuration);
    NWNXPushInt(e.nExpiryCalendarDay);
    NWNXPushInt(e.nExpiryTimeOfDay);

    NWNXPushObject(e.oCreator);
    NWNXPushInt(e.nSpellId);
    NWNXPushInt(e.bExpose);
    NWNXPushInt(e.bShowIcon);
    NWNXPushInt(e.nCasterLevel);

    if(!bReplace)
    {
        NWNXPushEffect(e.eLinkLeft);
        NWNXPushInt(e.bLinkLeftValid);
        NWNXPushEffect(e.eLinkRight);
        NWNXPushInt(e.bLinkRightValid);
    }

    NWNXPushInt(e.nNumIntegers);
    NWNXPushInt(e.nParam0);
    NWNXPushInt(e.nParam1);
    NWNXPushInt(e.nParam2);
    NWNXPushInt(e.nParam3);
    NWNXPushInt(e.nParam4);
    NWNXPushInt(e.nParam5);
    NWNXPushInt(e.nParam6);
    NWNXPushInt(e.nParam7);
    NWNXPushFloat(e.fParam0);
    NWNXPushFloat(e.fParam1);
    NWNXPushFloat(e.fParam2);
    NWNXPushFloat(e.fParam3);
    NWNXPushString(e.sParam0);
    NWNXPushString(e.sParam1);
    NWNXPushString(e.sParam2);
    NWNXPushString(e.sParam3);
    NWNXPushString(e.sParam4);
    NWNXPushString(e.sParam5);
    NWNXPushObject(e.oParam0);
    NWNXPushObject(e.oParam1);
    NWNXPushObject(e.oParam2);
    NWNXPushObject(e.oParam3);

    NWNXPushVector(e.vParam0);
    NWNXPushVector(e.vParam1);

    NWNXPushString(e.sTag);

    NWNXPushString(e.sItemProp);
}

struct NWNX_EffectUnpacked NWNX_Effect_UnpackEffect(effect e)
{
    NWNXPushEffect(e);
    NWNXCall(NWNX_Effect, "UnpackEffect");
    return __NWNX_Effect_ResolveUnpack();
}
effect NWNX_Effect_PackEffect(struct NWNX_EffectUnpacked e)
{
    __NWNX_Effect_ResolvePack(e);
    NWNXCall(NWNX_Effect, "PackEffect");
    return NWNXPopEffect();
}

int NWNX_Effect_ReplaceEffect(object obj, effect eOld, effect eNew)
{
    NWNXPushEffect(eNew);
    NWNXPushEffect(eOld);
    NWNXPushObject(obj);
    NWNXCall(NWNX_Effect, "ReplaceEffect");
    return NWNXPopInt();
}

int NWNX_Effect_GetTrueEffectCount(object oObject)
{
    NWNXPushObject(oObject);
    NWNXCall(NWNX_Effect, "GetTrueEffectCount");
    return NWNXPopInt();
}

struct NWNX_EffectUnpacked NWNX_Effect_GetTrueEffect(object oObject, int nIndex)
{
    NWNXPushInt(nIndex);
    NWNXPushObject(oObject);
    NWNXCall(NWNX_Effect, "GetTrueEffect");
    return __NWNX_Effect_ResolveUnpack(FALSE);
}

void NWNX_Effect_ReplaceEffectByIndex(object oObject, int nIndex, struct  NWNX_EffectUnpacked e)
{
    __NWNX_Effect_ResolvePack(e, TRUE);
    NWNXPushInt(nIndex);
    NWNXPushObject(oObject);
    NWNXCall(NWNX_Effect, "ReplaceEffectByIndex");
}

int NWNX_Effect_RemoveEffectById(object oObject,  string sID)
{
    NWNXPushString(sID);
    NWNXPushObject(oObject);
    NWNXCall(NWNX_Effect, "RemoveEffectById");
    return NWNXPopInt();
}

void NWNX_Effect_Apply(effect eEffect, object oObject)
{
    NWNXPushObject(oObject);
    NWNXPushEffect(eEffect);
    NWNXCall(NWNX_Effect, "Apply");
}

effect NWNX_Effect_SetEffectCreator(effect eEffect, object oObject)
{
    NWNXPushObject(oObject);
    NWNXPushEffect(eEffect);
    NWNXCall(NWNX_Effect, "SetEffectCreator");
    return NWNXPopEffect();
}

int NWNX_Effect_GetIsEffectValid(effect eEffect)
{
    NWNXPushEffect(eEffect);
    NWNXCall(NWNX_Effect, "GetIsEffectValid");
    return NWNXPopInt();
}

int NWNX_Effect_GetAppliedEffectCount(object oObject)
{
    NWNXPushObject(oObject);
    NWNXCall(NWNX_Effect, "GetAppliedEffectCount");
    return NWNXPopInt();
}

effect NWNX_Effect_GetAppliedEffect(object oObject, int nNth)
{
    NWNXPushInt(nNth);
    NWNXPushObject(oObject);
    NWNXCall(NWNX_Effect, "GetAppliedEffect");
    return NWNXPopEffect();
}
