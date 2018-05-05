#include "nwnx"

const string NWNX_Damage = "NWNX_Damage";

struct NWNX_Damage_DamageEventData // Damage event data
{
    object oDamager;
    int iBludgeoning;
    int iPierce;
    int iSlash;
    int iMagical;
    int iAcid;
    int iCold;
    int iDivine;
    int iElectrical;
    int iFire;
    int iNegative;
    int iPositive;
    int iSonic;
    int iBase;
};

// Set Damage Event Script
void NWNX_Damage_SetDamageEventScript(string sScript);

// Get Damage Event Data (to use only on Damage Event Script)
struct NWNX_Damage_DamageEventData NWNX_Weapon_GetDamageEventData();

// Set Damage Event Data (to use only on Damage Event Script)
void NWNX_Damage_SetDamageEventData(struct NWNX_Damage_DamageEventData data);


void NWNX_Weapon_SetDamageEventScript(string sScript)
{
    string sFunc = "SetDamageEventScript";

    NWNX_PushArgumentString(NWNX_Damage, sFunc, sScript);

    NWNX_CallFunction(NWNX_Damage, sFunc);
}


struct NWNX_Damage_DamageEventData NWNX_Damage_GetDamageEventData()
{
    string sFunc = "GetEventData";
    struct NWNX_Damage_DamageEventData data;

    NWNX_CallFunction(NWNX_Damage, sFunc);

    data.oDamager     = NWNX_GetReturnValueObject(NWNX_Damage, sFunc);
    data.iBludgeoning = NWNX_GetReturnValueInt(NWNX_Damage, sFunc);
    data.iPierce      = NWNX_GetReturnValueInt(NWNX_Damage, sFunc);
    data.iSlash       = NWNX_GetReturnValueInt(NWNX_Damage, sFunc);
    data.iMagical     = NWNX_GetReturnValueInt(NWNX_Damage, sFunc);
    data.iAcid        = NWNX_GetReturnValueInt(NWNX_Damage, sFunc);
    data.iCold        = NWNX_GetReturnValueInt(NWNX_Damage, sFunc);
    data.iDivine      = NWNX_GetReturnValueInt(NWNX_Damage, sFunc);
    data.iElectrical  = NWNX_GetReturnValueInt(NWNX_Damage, sFunc);
    data.iFire        = NWNX_GetReturnValueInt(NWNX_Damage, sFunc);
    data.iNegative    = NWNX_GetReturnValueInt(NWNX_Damage, sFunc);
    data.iPositive    = NWNX_GetReturnValueInt(NWNX_Damage, sFunc);
    data.iSonic       = NWNX_GetReturnValueInt(NWNX_Damage, sFunc);
    data.iBase        = NWNX_GetReturnValueInt(NWNX_Damage, sFunc);

    return data;
}

void NWNX_Damage_SetDamageEventData(struct NWNX_Damage_DamageEventData data)
{
    string sFunc = "SetEventData";

    NWNX_PushArgumentInt(NWNX_Damage, sFunc, data.iBase);
    NWNX_PushArgumentInt(NWNX_Damage, sFunc, data.iSonic);
    NWNX_PushArgumentInt(NWNX_Damage, sFunc, data.iPositive);
    NWNX_PushArgumentInt(NWNX_Damage, sFunc, data.iNegative);
    NWNX_PushArgumentInt(NWNX_Damage, sFunc, data.iFire);
    NWNX_PushArgumentInt(NWNX_Damage, sFunc, data.iElectrical);
    NWNX_PushArgumentInt(NWNX_Damage, sFunc, data.iDivine);
    NWNX_PushArgumentInt(NWNX_Damage, sFunc, data.iCold);
    NWNX_PushArgumentInt(NWNX_Damage, sFunc, data.iAcid);
    NWNX_PushArgumentInt(NWNX_Damage, sFunc, data.iMagical);
    NWNX_PushArgumentInt(NWNX_Damage, sFunc, data.iSlash);
    NWNX_PushArgumentInt(NWNX_Damage, sFunc, data.iPierce);
    NWNX_PushArgumentInt(NWNX_Damage, sFunc, data.iBludgeoning);

    NWNX_CallFunction(NWNX_Damage, sFunc);
}
