#include "nwnx"

struct NWNX_IPUnpacked
{
    int nProperty;
    int nSubType;
    int nCostTable;
    int nCostTableValue;
    int nParam1;
    int nParam1Value;
    int nUsesPerDay;
    int nChanceToAppear;
    int bUsable;
    int nSpellId;
    object oCreator;
    string sTag;
};

// Convert native itemproperty type to unpacked structure
struct NWNX_IPUnpacked NWNX_ItemProperty_UnpackIP(itemproperty ip);

// Convert unpacked itemproperty structure to native type
itemproperty NWNX_ItemProperty_PackIP(struct NWNX_IPUnpacked ip);


const string NWNX_ItemProperty = "NWNX_ItemProperty";

struct NWNX_IPUnpacked NWNX_ItemProperty_UnpackIP(itemproperty ip)
{
    string sFunc = "UnpackIP";

    NWNX_PushArgumentItemProperty(NWNX_ItemProperty, sFunc, ip);
    NWNX_CallFunction(NWNX_ItemProperty, sFunc);

    struct NWNX_IPUnpacked n;
    n.nProperty       = NWNX_GetReturnValueInt(NWNX_ItemProperty, sFunc);
    n.nSubType        = NWNX_GetReturnValueInt(NWNX_ItemProperty, sFunc);
    n.nCostTable      = NWNX_GetReturnValueInt(NWNX_ItemProperty, sFunc);
    n.nCostTableValue = NWNX_GetReturnValueInt(NWNX_ItemProperty, sFunc);
    n.nParam1         = NWNX_GetReturnValueInt(NWNX_ItemProperty, sFunc);
    n.nParam1Value    = NWNX_GetReturnValueInt(NWNX_ItemProperty, sFunc);
    n.nUsesPerDay     = NWNX_GetReturnValueInt(NWNX_ItemProperty, sFunc);
    n.nChanceToAppear = NWNX_GetReturnValueInt(NWNX_ItemProperty, sFunc);
    n.bUsable         = NWNX_GetReturnValueInt(NWNX_ItemProperty, sFunc);
    n.nSpellId        = NWNX_GetReturnValueInt(NWNX_ItemProperty, sFunc);
    n.oCreator        = NWNX_GetReturnValueObject(NWNX_ItemProperty, sFunc);
    n.sTag            = NWNX_GetReturnValueString(NWNX_ItemProperty, sFunc);

    return n;
}
itemproperty NWNX_ItemProperty_PackIP(struct NWNX_IPUnpacked n)
{
    string sFunc = "PackIP";

    NWNX_PushArgumentString(NWNX_ItemProperty, sFunc, n.sTag);
    NWNX_PushArgumentObject(NWNX_ItemProperty, sFunc, n.oCreator);
    NWNX_PushArgumentInt(NWNX_ItemProperty, sFunc, n.nSpellId);
    NWNX_PushArgumentInt(NWNX_ItemProperty, sFunc, n.bUsable);
    NWNX_PushArgumentInt(NWNX_ItemProperty, sFunc, n.nChanceToAppear);
    NWNX_PushArgumentInt(NWNX_ItemProperty, sFunc, n.nUsesPerDay);
    NWNX_PushArgumentInt(NWNX_ItemProperty, sFunc, n.nParam1Value);
    NWNX_PushArgumentInt(NWNX_ItemProperty, sFunc, n.nParam1);
    NWNX_PushArgumentInt(NWNX_ItemProperty, sFunc, n.nCostTableValue);
    NWNX_PushArgumentInt(NWNX_ItemProperty, sFunc, n.nCostTable);
    NWNX_PushArgumentInt(NWNX_ItemProperty, sFunc, n.nSubType);
    NWNX_PushArgumentInt(NWNX_ItemProperty, sFunc, n.nProperty);

    NWNX_CallFunction(NWNX_ItemProperty, sFunc);
    return NWNX_GetReturnValueItemProperty(NWNX_ItemProperty, sFunc);
}
