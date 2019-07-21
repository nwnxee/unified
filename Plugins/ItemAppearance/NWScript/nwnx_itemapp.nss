#include "nwnx"

const string NWNX_ItemAppearance = "NWNX_ItemAppearance";

// Cache item appearances
void NWNX_ItemAppearance_CacheAppearances();

// Blacklist item appearance
void NWNX_ItemAppearance_BlacklistAppearance(int nBaseItem, string sBot = "*", string sMid = "*", string sTop = "*", string sBotC = "*", string sMidC = "*", string sTopC = "*");

// Sync appearance number (all parts use same value whenever one of them randomly is selected
void NWNX_ItemAppearance_SyncAppearance(int nBaseItem, string sPart);

// Get random appearance
int NWNX_ItemAppearance_GetRandomAppearance(object oItem, int nPart = 0);

// Get next valid appearance
int NWNX_ItemAppearance_GetNextAppearance(object oItem, int nPart = 0);

// Get previous valid appearance
int NWNX_ItemAppearance_GetPreviousAppearance(object oItem, int nPart = 0);

// Get next valid color
int NWNX_ItemAppearance_GetNextColor(object oItem, int nPart = 0);

// Get previous valid color
int NWNX_ItemAppearance_GetPreviousColor(object oItem, int nPart = 0);

void NWNX_ItemAppearance_SetWeight(object oItem, int w)
{
    string sFunc = "SetWeight";

    NWNX_PushArgumentInt(NWNX_ItemAppearance, sFunc, w);
    NWNX_PushArgumentObject(NWNX_ItemAppearance, sFunc, oItem);

    NWNX_CallFunction(NWNX_ItemAppearance, sFunc);
}

void NWNX_ItemAppearance_SetBaseGoldPieceValue(object oItem, int g)
{
    string sFunc = "SetBaseGoldPieceValue";

    NWNX_PushArgumentInt(NWNX_ItemAppearance, sFunc, g);
    NWNX_PushArgumentObject(NWNX_ItemAppearance, sFunc, oItem);

    NWNX_CallFunction(NWNX_ItemAppearance, sFunc);
}

void NWNX_ItemAppearance_SetAddGoldPieceValue(object oItem, int g)
{
    string sFunc = "SetAddGoldPieceValue";

    NWNX_PushArgumentInt(NWNX_ItemAppearance, sFunc, g);
    NWNX_PushArgumentObject(NWNX_ItemAppearance, sFunc, oItem);

    NWNX_CallFunction(NWNX_ItemAppearance, sFunc);
}

int NWNX_ItemAppearance_GetBaseGoldPieceValue(object oItem)
{
    string sFunc = "GetBaseGoldPieceValue";

    NWNX_PushArgumentObject(NWNX_ItemAppearance, sFunc, oItem);

    NWNX_CallFunction(NWNX_ItemAppearance, sFunc);
    return NWNX_GetReturnValueInt(NWNX_ItemAppearance, sFunc);
}

int NWNX_ItemAppearance_GetAddGoldPieceValue(object oItem)
{
    string sFunc = "GetAddGoldPieceValue";

    NWNX_PushArgumentObject(NWNX_ItemAppearance, sFunc, oItem);

    NWNX_CallFunction(NWNX_ItemAppearance, sFunc);
    return NWNX_GetReturnValueInt(NWNX_ItemAppearance, sFunc);
}

void NWNX_ItemAppearance_SetBaseItemType(object oItem, int nBaseItem)
{
    string sFunc = "SetBaseItemType";

    NWNX_PushArgumentInt(NWNX_ItemAppearance, sFunc, nBaseItem);
    NWNX_PushArgumentObject(NWNX_ItemAppearance, sFunc, oItem);

    NWNX_CallFunction(NWNX_ItemAppearance, sFunc);
}

void NWNX_ItemAppearance_SetItemAppearance(object oItem, int nType, int nIndex, int nValue)
{
    string sFunc = "SetItemAppearance";

    NWNX_PushArgumentInt(NWNX_ItemAppearance, sFunc, nValue);
    NWNX_PushArgumentInt(NWNX_ItemAppearance, sFunc, nIndex);
    NWNX_PushArgumentInt(NWNX_ItemAppearance, sFunc, nType);
    NWNX_PushArgumentObject(NWNX_ItemAppearance, sFunc, oItem);

    NWNX_CallFunction(NWNX_ItemAppearance, sFunc);

}

string NWNX_ItemAppearance_GetEntireItemAppearance(object oItem)
{
    string sFunc = "GetEntireItemAppearance";

    NWNX_PushArgumentObject(NWNX_ItemAppearance, sFunc, oItem);

    NWNX_CallFunction(NWNX_ItemAppearance, sFunc);
    return NWNX_GetReturnValueString(NWNX_ItemAppearance, sFunc);
}

void NWNX_ItemAppearance_RestoreItemAppearance(object oItem, string sApp)
{
    string sFunc = "RestoreItemAppearance";

    NWNX_PushArgumentString(NWNX_ItemAppearance, sFunc, sApp);
    NWNX_PushArgumentObject(NWNX_ItemAppearance, sFunc, oItem);

    NWNX_CallFunction(NWNX_ItemAppearance, sFunc);
}

int NWNX_ItemAppearance_GetBaseArmorClass(object oItem)
{
    string sFunc = "GetBaseArmorClass";

    NWNX_PushArgumentObject(NWNX_ItemAppearance, sFunc, oItem);

    NWNX_CallFunction(NWNX_ItemAppearance, sFunc);
    return NWNX_GetReturnValueInt(NWNX_ItemAppearance, sFunc);
}

int NWNX_ItemAppearance_GetMinEquipLevel(object oItem)
{
    string sFunc = "GetMinEquipLevel";

    NWNX_PushArgumentObject(NWNX_ItemAppearance, sFunc, oItem);

    NWNX_CallFunction(NWNX_ItemAppearance, sFunc);
    return NWNX_GetReturnValueInt(NWNX_ItemAppearance, sFunc);
}

void NWNX_ItemAppearance_CacheAppearances()
{
    string sFunc = "CacheAppearances";

    NWNX_CallFunction(NWNX_ItemAppearance, sFunc);
}

void NWNX_ItemAppearance_BlacklistAppearance(int nBaseItem, string sBot = "*", string sMid = "*", string sTop = "*", string sBotC = "*", string sMidC = "*", string sTopC = "*")
{
    string sFunc = "BlacklistAppearance";
    NWNX_PushArgumentString(NWNX_ItemAppearance, sFunc, sTopC);
    NWNX_PushArgumentString(NWNX_ItemAppearance, sFunc, sMidC);
    NWNX_PushArgumentString(NWNX_ItemAppearance, sFunc, sBotC);
    NWNX_PushArgumentString(NWNX_ItemAppearance, sFunc, sTop);
    NWNX_PushArgumentString(NWNX_ItemAppearance, sFunc, sMid);
    NWNX_PushArgumentString(NWNX_ItemAppearance, sFunc, sBot);
    NWNX_PushArgumentInt(NWNX_ItemAppearance, sFunc, nBaseItem);

    NWNX_CallFunction(NWNX_ItemAppearance, sFunc);
}

void NWNX_ItemAppearance_SyncAppearance(int nBaseItem, string sPart)
{
    string sFunc = "SyncAppearance";
    NWNX_PushArgumentString(NWNX_ItemAppearance, sFunc, sPart);
    NWNX_PushArgumentInt(NWNX_ItemAppearance, sFunc, nBaseItem);

    NWNX_CallFunction(NWNX_ItemAppearance, sFunc);
}

int NWNX_ItemAppearance_GetRandomAppearance(object oItem, int nPart = 0)
{
    string sFunc = "GetRandomAppearance";
    NWNX_PushArgumentInt(NWNX_ItemAppearance, sFunc, nPart);
    NWNX_PushArgumentObject(NWNX_ItemAppearance, sFunc, oItem);

    NWNX_CallFunction(NWNX_ItemAppearance, sFunc);
    return  NWNX_GetReturnValueInt(NWNX_ItemAppearance, sFunc);
}

int NWNX_ItemAppearance_GetNextAppearance(object oItem, int nPart = 0)
{
    string sFunc = "GetNextAppearance";
    NWNX_PushArgumentInt(NWNX_ItemAppearance, sFunc, nPart);
    NWNX_PushArgumentObject(NWNX_ItemAppearance, sFunc, oItem);

    NWNX_CallFunction(NWNX_ItemAppearance, sFunc);
    return  NWNX_GetReturnValueInt(NWNX_ItemAppearance, sFunc);
}

int NWNX_ItemAppearance_GetPreviousAppearance(object oItem, int nPart = 0)
{
    string sFunc = "GetPreviousAppearance";
    NWNX_PushArgumentInt(NWNX_ItemAppearance, sFunc, nPart);
    NWNX_PushArgumentObject(NWNX_ItemAppearance, sFunc, oItem);

    NWNX_CallFunction(NWNX_ItemAppearance, sFunc);
    return  NWNX_GetReturnValueInt(NWNX_ItemAppearance, sFunc);
}

int NWNX_ItemAppearance_GetNextColor(object oItem, int nPart = 0)
{
    string sFunc = "GetNextColor";
    NWNX_PushArgumentInt(NWNX_ItemAppearance, sFunc, nPart);
    NWNX_PushArgumentObject(NWNX_ItemAppearance, sFunc, oItem);

    NWNX_CallFunction(NWNX_ItemAppearance, sFunc);
    return  NWNX_GetReturnValueInt(NWNX_ItemAppearance, sFunc);
}

int NWNX_ItemAppearance_GetPreviousColor(object oItem, int nPart = 0)
{
    string sFunc = "GetPreviousColor";
    NWNX_PushArgumentInt(NWNX_ItemAppearance, sFunc, nPart);
    NWNX_PushArgumentObject(NWNX_ItemAppearance, sFunc, oItem);

    NWNX_CallFunction(NWNX_ItemAppearance, sFunc);
    return  NWNX_GetReturnValueInt(NWNX_ItemAppearance, sFunc);
}
