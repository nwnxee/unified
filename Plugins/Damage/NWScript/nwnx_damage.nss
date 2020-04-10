/// @addtogroup damage Damage
/// @brief Run a script before damage and attack events allowing for modification. Includes function to arbitrarily apply damage.
/// @{
/// @file nwnx_damage.nss
#include "nwnx"

const string NWNX_Damage = "NWNX_Damage"; ///< @private

/// @struct NWNX_Damage_DamageEventData
/// @brief Damage Event Data
struct NWNX_Damage_DamageEventData
{
    object oDamager; ///< The object that inflicted the damage.
    int iBludgeoning; ///< Bludgeoning damage
    int iPierce; ///< Piercing damage
    int iSlash; ///< Slashing damage
    int iMagical; ///< Magical damage
    int iAcid; ///< Acid damage
    int iCold; ///< Cold damage
    int iDivine; ///< Divine damage
    int iElectrical; ///< Electrical damage
    int iFire; ///< Fire damage
    int iNegative; ///< Negative damage
    int iPositive; ///< Positive damage
    int iSonic; ///< Sonic damage
    int iBase; ///< Base damage
};

/// @struct NWNX_Damage_AttackEventData
/// @brief Attack Event Data
struct NWNX_Damage_AttackEventData
{
    object oTarget; ///< The target who took the damage
    int iBludgeoning; ///< Bludgeoning damage
    int iPierce; ///< Piercing damage
    int iSlash; ///< Slashing damage
    int iMagical; ///< Magical damage
    int iAcid; ///< Acid damage
    int iCold; ///< Cold damage
    int iDivine; ///< Divine damage
    int iElectrical; ///< Electrical damage
    int iFire; ///< Fire damage
    int iNegative; ///< Negative damage
    int iPositive; ///< Positive damage
    int iSonic; ///< Sonic damage
    int iBase; ///< Base damage
    int iAttackNumber; ///< 1-based index of the attack in current combat round
    int iAttackResult; ///< 1=hit, 3=critical hit, 4=miss, 8=concealed
    int iAttackType;   ///< 1=main hand, 2=offhand, 3-5=creature, 6=haste
    int iSneakAttack;  ///< 0=neither, 1=sneak attack, 2=death attack, 3=both
};

/// @struct NWNX_Damage_DamageData
/// @brief Used for DealDamage
struct NWNX_Damage_DamageData
{
    int iBludgeoning; ///< Bludgeoning damage
    int iPierce; ///< Piercing damage
    int iSlash; ///< Slashing damage
    int iMagical; ///< Magical damage
    int iAcid; ///< Acid damage
    int iCold; ///< Cold damage
    int iDivine; ///< Divine damage
    int iElectrical; ///< Electrical damage
    int iFire; ///< Fire damage
    int iNegative; ///< Negative damage
    int iPositive; ///< Positive damage
    int iSonic; ///< Sonic damage
    int iPower; ///< For overcoming DR
};

/// @brief Sets the script to run with a damage event.
/// @param sScript The script that will handle the damage event.
/// @param oOwner An object if only executing for a specific object or OBJECT_INVALID for global.
void NWNX_Damage_SetDamageEventScript(string sScript, object oOwner=OBJECT_INVALID);

/// @brief Get Damage Event Data
/// @return A NWNX_Damage_DamageEventData struct.
/// @note To use only in the Damage Event Script.
struct NWNX_Damage_DamageEventData NWNX_Damage_GetDamageEventData();

/// @brief Set Damage Event Data
/// @param data A NWNX_Damage_DamageEventData struct.
/// @note To use only in the Damage Event Script.
void NWNX_Damage_SetDamageEventData(struct NWNX_Damage_DamageEventData data);

/// @brief Sets the script to run with an attack event.
/// @param sScript The script that will handle the attack event.
/// @param oOwner An object if only executing for a specific object or OBJECT_INVALID for global.
void NWNX_Damage_SetAttackEventScript(string sScript, object oOwner=OBJECT_INVALID);

/// @brief Get Attack Event Data
/// @return A NWNX_Damage_AttackEventData struct.
/// @note To use only in the Attack Event Script.
struct NWNX_Damage_AttackEventData NWNX_Damage_GetAttackEventData();

/// @brief Set Attack Event Data
/// @param data A NWNX_Damage_AttackEventData struct.
/// @note To use only in the Attack Event Script.
void NWNX_Damage_SetAttackEventData(struct NWNX_Damage_AttackEventData data);

/// @brief Deal damage to a target.
/// @remark Permits multiple damage types and checks enhancement bonus for overcoming DR.
/// @param data A NWNX_Damage_DamageData struct.
/// @param oTarget The target object on whom the damage is dealt.
/// @param oSource The source of the damage.
/// @param iRanged Whether the attack should be treated as ranged by the engine (for example when considering damage inflicted by Acid Sheath and other such effects)
void NWNX_Damage_DealDamage(struct NWNX_Damage_DamageData data, object oTarget, object oSource=OBJECT_SELF, int iRanged = FALSE);

/// @}

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

    NWNX_PushArgumentInt(NWNX_Damage, sFunc, data.iAttackResult);
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

void NWNX_Damage_DealDamage(struct NWNX_Damage_DamageData data, object oTarget, object oSource, int iRanged = FALSE)
{
    string sFunc = "DealDamage";

    NWNX_PushArgumentInt(NWNX_Damage, sFunc, iRanged);
    NWNX_PushArgumentInt(NWNX_Damage, sFunc, data.iPower);
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
    NWNX_PushArgumentObject(NWNX_Damage, sFunc, oTarget);
    NWNX_PushArgumentObject(NWNX_Damage, sFunc, oSource);

    NWNX_CallFunction(NWNX_Damage, sFunc);
}
