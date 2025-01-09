/// @addtogroup itemproperty ItemProperty
/// @brief Utility functions to manipulate the builtin itemproperty type.
/// @{
/// @file nwnx_itemprop.nss

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
    NWNXPushItemProperty(ip);
    NWNXCall(NWNX_ItemProperty, "UnpackIP");
    struct NWNX_IPUnpacked n;
    n.sID             = NWNXPopString();
    n.nProperty       = NWNXPopInt();
    n.nSubType        = NWNXPopInt();
    n.nCostTable      = NWNXPopInt();
    n.nCostTableValue = NWNXPopInt();
    n.nParam1         = NWNXPopInt();
    n.nParam1Value    = NWNXPopInt();
    n.nUsesPerDay     = NWNXPopInt();
    n.nChanceToAppear = NWNXPopInt();
    n.bUsable         = NWNXPopInt();
    n.nSpellId        = NWNXPopInt();
    n.oCreator        = NWNXPopObject();
    n.sTag            = NWNXPopString();
    return n;
}

itemproperty NWNX_ItemProperty_PackIP(struct NWNX_IPUnpacked n)
{
    NWNXPushString(n.sTag);
    NWNXPushObject(n.oCreator);
    NWNXPushInt(n.nSpellId);
    NWNXPushInt(n.bUsable);
    NWNXPushInt(n.nChanceToAppear);
    NWNXPushInt(n.nUsesPerDay);
    NWNXPushInt(n.nParam1Value);
    NWNXPushInt(n.nParam1);
    NWNXPushInt(n.nCostTableValue);
    NWNXPushInt(n.nCostTable);
    NWNXPushInt(n.nSubType);
    NWNXPushInt(n.nProperty);
    NWNXCall(NWNX_ItemProperty, "PackIP");
    return NWNXPopItemProperty();
}

struct NWNX_IPUnpacked NWNX_ItemProperty_GetActiveProperty(object oItem, int nIndex)
{
    NWNXPushInt(nIndex);
    NWNXPushObject(oItem);
    NWNXCall(NWNX_ItemProperty, "GetActiveProperty");
    struct NWNX_IPUnpacked n;
    n.nProperty       = NWNXPopInt();
    n.nSubType        = NWNXPopInt();
    n.nCostTable      = NWNXPopInt();
    n.nCostTableValue = NWNXPopInt();
    n.nParam1         = NWNXPopInt();
    n.nParam1Value    = NWNXPopInt();
    n.nUsesPerDay     = NWNXPopInt();
    n.nChanceToAppear = NWNXPopInt();
    n.bUsable         = NWNXPopInt();
    n.sTag            = NWNXPopString();
    return n;
}
