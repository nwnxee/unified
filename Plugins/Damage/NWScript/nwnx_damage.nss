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

struct NWNX_Damage_AttackEventData
{
    object oTarget;
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
    int iAttackNumber; // 1-based index of the attack in current combat round
    int iAttackResult; // 1=hit, 3=critical hit, 4=miss, 8=concealed
    int iAttackType;   // 1=main hand, 2=offhand, 3-5=creature, 6=haste
    int iSneakAttack;  // 0=neither, 1=sneak attack, 2=death attack, 3=both
};

// Set Damage Event Script
// If oOwner is OBJECT_INVALID, this sets the script globally for all creatures
// If oOwner is valid, it will set it only for that creature.
void NWNX_Damage_SetDamageEventScript(string sScript, object oOwner=OBJECT_INVALID);

// Get Damage Event Data (to use only on Damage Event Script)
struct NWNX_Damage_DamageEventData NWNX_Damage_GetDamageEventData();

// Set Damage Event Data (to use only on Damage Event Script)
void NWNX_Damage_SetDamageEventData(struct NWNX_Damage_DamageEventData data);

// Set Attack Event Script
// If oOwner is OBJECT_INVALID, this sets the script globally for all creatures
// If oOwner is valid, it will set it only for that creature.
void NWNX_Damage_SetAttackEventScript(string sScript, object oOwner=OBJECT_INVALID);

// Get Attack Event Data (to use only on Attack Event Script)
struct NWNX_Damage_AttackEventData NWNX_Damage_GetAttackEventData();

// Set Attack Event Data (to use only on Attack Event Script)
void NWNX_Damage_SetAttackEventData(struct NWNX_Damage_AttackEventData data);


void NWNX_Damage_SetDamageEventScript(string sScript, object oOwner=OBJECT_INVALID)
{
    string sFunc = "SetEventScript";

    NWNX_PushArgumentObject(NWNX_Damage, sFunc, oOwner);
    NWNX_PushArgumentString(NWNX_Damage, sFunc, sScript);
    NWNX_PushArgumentString(NWNX_Damage, sFunc, "DAMAGE");

    NWNX_CallFunction(NWNX_Damage, sFunc);
}

struct NWNX_Damage_DamageEventData NWNX_Damage_GetDamageEventData()
{
    string sFunc = "GetDamageEventData";
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
    string sFunc = "SetDamageEventData";

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

void NWNX_Damage_SetAttackEventScript(string sScript, object oOwner=OBJECT_INVALID)
{
    string sFunc = "SetEventScript";

    NWNX_PushArgumentObject(NWNX_Damage, sFunc, oOwner);
    NWNX_PushArgumentString(NWNX_Damage, sFunc, sScript);
    NWNX_PushArgumentString(NWNX_Damage, sFunc, "ATTACK");

    NWNX_CallFunction(NWNX_Damage, sFunc);
}

struct NWNX_Damage_AttackEventData NWNX_Damage_GetAttackEventData()
{
    string sFunc = "GetAttackEventData";
    struct NWNX_Damage_AttackEventData data;

    NWNX_CallFunction(NWNX_Damage, sFunc);

    data.oTarget       = NWNX_GetReturnValueObject(NWNX_Damage, sFunc);
    data.iBludgeoning  = NWNX_GetReturnValueInt(NWNX_Damage, sFunc);
    data.iPierce       = NWNX_GetReturnValueInt(NWNX_Damage, sFunc);
    data.iSlash        = NWNX_GetReturnValueInt(NWNX_Damage, sFunc);
    data.iMagical      = NWNX_GetReturnValueInt(NWNX_Damage, sFunc);
    data.iAcid         = NWNX_GetReturnValueInt(NWNX_Damage, sFunc);
    data.iCold         = NWNX_GetReturnValueInt(NWNX_Damage, sFunc);
    data.iDivine       = NWNX_GetReturnValueInt(NWNX_Damage, sFunc);
    data.iElectrical   = NWNX_GetReturnValueInt(NWNX_Damage, sFunc);
    data.iFire         = NWNX_GetReturnValueInt(NWNX_Damage, sFunc);
    data.iNegative     = NWNX_GetReturnValueInt(NWNX_Damage, sFunc);
    data.iPositive     = NWNX_GetReturnValueInt(NWNX_Damage, sFunc);
    data.iSonic        = NWNX_GetReturnValueInt(NWNX_Damage, sFunc);
    data.iBase         = NWNX_GetReturnValueInt(NWNX_Damage, sFunc);
    data.iAttackNumber = NWNX_GetReturnValueInt(NWNX_Damage, sFunc);
    data.iAttackResult = NWNX_GetReturnValueInt(NWNX_Damage, sFunc);
    data.iAttackType   = NWNX_GetReturnValueInt(NWNX_Damage, sFunc);
    data.iSneakAttack  = NWNX_GetReturnValueInt(NWNX_Damage, sFunc);

    return data;
}

void NWNX_Damage_SetAttackEventData(struct NWNX_Damage_AttackEventData data)
{
    string sFunc = "SetAttackEventData";

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
