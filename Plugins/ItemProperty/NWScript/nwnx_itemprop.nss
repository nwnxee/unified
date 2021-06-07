/// @addtogroup itemproperty ItemProperty
/// @brief Utility functions to manipulate the builtin itemproperty type.
/// @{
/// @file nwnx_itemprop.nss
#include "nwnx"

const string NWNX_ItemProperty = "NWNX_ItemProperty"; ///< @private

/// @brief An unpacked itemproperty.
struct NWNX_IPUnpacked
{
    string sID; ///< @todo Describe
    int nProperty; ///< @todo Describe
    int nSubType; ///< @todo Describe
    int nCostTable; ///< @todo Describe
    int nCostTableValue; ///< @todo Describe
    int nParam1; ///< @todo Describe
    int nParam1Value; ///< @todo Describe
    int nUsesPerDay; ///< @todo Describe
    int nChanceToAppear; ///< @todo Describe
    int bUsable; ///< @todo Describe
    int nSpellId; ///< @todo Describe
    object oCreator; ///< @todo Describe
    string sTag; ///< @todo Describe
};

/// @brief Convert native itemproperty type to unpacked structure.
/// @param ip The itemproperty to convert.
/// @return A constructed NWNX_IPUnpacked.
struct NWNX_IPUnpacked NWNX_ItemProperty_UnpackIP(itemproperty ip);

/// @brief Convert unpacked itemproperty structure to native type.
/// @param ip The NWNX_IPUnpacked structure to convert.
/// @return The itemproperty.
itemproperty NWNX_ItemProperty_PackIP(struct NWNX_IPUnpacked ip);

/// @brief Gets the active item property at the index
/// @param oItem - the item with the property
/// @param nIndex - the index such as returned by some Item Events
/// @return A constructed NWNX_IPUnpacked, except for creator, and spell id.
struct NWNX_IPUnpacked NWNX_ItemProperty_GetActiveProperty(object oItem, int nIndex);

/// @}

struct NWNX_IPUnpacked NWNX_ItemProperty_UnpackIP(itemproperty ip)
{
    string sFunc = "UnpackIP";

    NWNX_PushArgumentItemProperty(ip);
    NWNX_CallFunction(NWNX_ItemProperty, sFunc);

    struct NWNX_IPUnpacked n;

    n.sID             = NWNX_GetReturnValueString();
    n.nProperty       = NWNX_GetReturnValueInt();
    n.nSubType        = NWNX_GetReturnValueInt();
    n.nCostTable      = NWNX_GetReturnValueInt();
    n.nCostTableValue = NWNX_GetReturnValueInt();
    n.nParam1         = NWNX_GetReturnValueInt();
    n.nParam1Value    = NWNX_GetReturnValueInt();
    n.nUsesPerDay     = NWNX_GetReturnValueInt();
    n.nChanceToAppear = NWNX_GetReturnValueInt();
    n.bUsable         = NWNX_GetReturnValueInt();
    n.nSpellId        = NWNX_GetReturnValueInt();
    n.oCreator        = NWNX_GetReturnValueObject();
    n.sTag            = NWNX_GetReturnValueString();

    return n;
}

itemproperty NWNX_ItemProperty_PackIP(struct NWNX_IPUnpacked n)
{
    string sFunc = "PackIP";

    NWNX_PushArgumentString(n.sTag);
    NWNX_PushArgumentObject(n.oCreator);
    NWNX_PushArgumentInt(n.nSpellId);
    NWNX_PushArgumentInt(n.bUsable);
    NWNX_PushArgumentInt(n.nChanceToAppear);
    NWNX_PushArgumentInt(n.nUsesPerDay);
    NWNX_PushArgumentInt(n.nParam1Value);
    NWNX_PushArgumentInt(n.nParam1);
    NWNX_PushArgumentInt(n.nCostTableValue);
    NWNX_PushArgumentInt(n.nCostTable);
    NWNX_PushArgumentInt(n.nSubType);
    NWNX_PushArgumentInt(n.nProperty);

    NWNX_CallFunction(NWNX_ItemProperty, sFunc);
    return NWNX_GetReturnValueItemProperty();
}

struct NWNX_IPUnpacked NWNX_ItemProperty_GetActiveProperty(object oItem, int nIndex)
{
    string sFunc = "GetActiveProperty";
    NWNX_PushArgumentInt(nIndex);
    NWNX_PushArgumentObject(oItem);
    NWNX_CallFunction(NWNX_ItemProperty, sFunc);

    struct NWNX_IPUnpacked n;

    n.nProperty       = NWNX_GetReturnValueInt();
    n.nSubType        = NWNX_GetReturnValueInt();
    n.nCostTable      = NWNX_GetReturnValueInt();
    n.nCostTableValue = NWNX_GetReturnValueInt();
    n.nParam1         = NWNX_GetReturnValueInt();
    n.nParam1Value    = NWNX_GetReturnValueInt();
    n.nUsesPerDay     = NWNX_GetReturnValueInt();
    n.nChanceToAppear = NWNX_GetReturnValueInt();
    n.bUsable         = NWNX_GetReturnValueInt();
    n.sTag            = NWNX_GetReturnValueString();

    return n;
}
