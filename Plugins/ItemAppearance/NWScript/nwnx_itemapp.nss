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

void NWNX_ItemAppearance_CacheAppearances()
{
    string sFunc = "CacheAppearances";

    NWNX_CallFunction(NWNX_ItemAppearance, sFunc);
}

void NWNX_ItemAppearance_BlacklistAppearance(int nBaseItem, string sBot = "*", string sMid = "*", string sTop = "*", string sBotC = "*", string sMidC = "*", string sTopC = "*")
{
    string sFunc = "BlacklistAppearance";
    NWNX_PushArgumentString(sTopC);
    NWNX_PushArgumentString(sMidC);
    NWNX_PushArgumentString(sBotC);
    NWNX_PushArgumentString(sTop);
    NWNX_PushArgumentString(sMid);
    NWNX_PushArgumentString(sBot);
    NWNX_PushArgumentInt(nBaseItem);

    NWNX_CallFunction(NWNX_ItemAppearance, sFunc);
}

void NWNX_ItemAppearance_SyncAppearance(int nBaseItem, string sPart)
{
    string sFunc = "SyncAppearance";
    NWNX_PushArgumentString(sPart);
    NWNX_PushArgumentInt(nBaseItem);

    NWNX_CallFunction(NWNX_ItemAppearance, sFunc);
}

int NWNX_ItemAppearance_GetRandomAppearance(object oItem, int nPart = 0)
{
    string sFunc = "GetRandomAppearance";
    NWNX_PushArgumentInt(nPart);
    NWNX_PushArgumentObject(oItem);

    NWNX_CallFunction(NWNX_ItemAppearance, sFunc);
    return  NWNX_GetReturnValueInt();
}

int NWNX_ItemAppearance_GetNextAppearance(object oItem, int nPart = 0)
{
    string sFunc = "GetNextAppearance";
    NWNX_PushArgumentInt(nPart);
    NWNX_PushArgumentObject(oItem);

    NWNX_CallFunction(NWNX_ItemAppearance, sFunc);
    return  NWNX_GetReturnValueInt();
}

int NWNX_ItemAppearance_GetPreviousAppearance(object oItem, int nPart = 0)
{
    string sFunc = "GetPreviousAppearance";
    NWNX_PushArgumentInt(nPart);
    NWNX_PushArgumentObject(oItem);

    NWNX_CallFunction(NWNX_ItemAppearance, sFunc);
    return  NWNX_GetReturnValueInt();
}

int NWNX_ItemAppearance_GetNextColor(object oItem, int nPart = 0)
{
    string sFunc = "GetNextColor";
    NWNX_PushArgumentInt(nPart);
    NWNX_PushArgumentObject(oItem);

    NWNX_CallFunction(NWNX_ItemAppearance, sFunc);
    return  NWNX_GetReturnValueInt();
}

int NWNX_ItemAppearance_GetPreviousColor(object oItem, int nPart = 0)
{
    string sFunc = "GetPreviousColor";
    NWNX_PushArgumentInt(nPart);
    NWNX_PushArgumentObject(oItem);

    NWNX_CallFunction(NWNX_ItemAppearance, sFunc);
    return  NWNX_GetReturnValueInt();
}
