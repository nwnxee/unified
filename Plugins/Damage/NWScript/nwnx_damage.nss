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
    int iAttackResult; ///< 1=hit, 2=parried, 3=critical hit, 4=miss, 5=resisted, 7=automatic hit, 8=concealed, 9=miss chance, 10=devastating crit
    int iWeaponAttackType; ///< 1=main hand, 2=offhand, 3-5=creature, 6=extra(haste), 7=unarmed, 8=unarmed extra
    int iSneakAttack; ///< 0=neither, 1=sneak attack, 2=death attack, 3=both
    int iAttackType; ///< 65002=Attack of Opportunity, 65003=Riposte or a FeatID like KnockDown or some other special attack.
    int bKillingBlow; ///< TRUE if the hit is a killing blow
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

    NWNX_PushArgumentObject(oOwner);
    NWNX_PushArgumentString(sScript);
    NWNX_PushArgumentString("DAMAGE");

    NWNX_CallFunction(NWNX_Damage, sFunc);
}

struct NWNX_Damage_DamageEventData NWNX_Damage_GetDamageEventData()
{
    string sFunc = "GetDamageEventData";
    struct NWNX_Damage_DamageEventData data;

    NWNX_CallFunction(NWNX_Damage, sFunc);

    data.oDamager     = NWNX_GetReturnValueObject();
    data.iBludgeoning = NWNX_GetReturnValueInt();
    data.iPierce      = NWNX_GetReturnValueInt();
    data.iSlash       = NWNX_GetReturnValueInt();
    data.iMagical     = NWNX_GetReturnValueInt();
    data.iAcid        = NWNX_GetReturnValueInt();
    data.iCold        = NWNX_GetReturnValueInt();
    data.iDivine      = NWNX_GetReturnValueInt();
    data.iElectrical  = NWNX_GetReturnValueInt();
    data.iFire        = NWNX_GetReturnValueInt();
    data.iNegative    = NWNX_GetReturnValueInt();
    data.iPositive    = NWNX_GetReturnValueInt();
    data.iSonic       = NWNX_GetReturnValueInt();
    data.iBase        = NWNX_GetReturnValueInt();

    return data;
}

void NWNX_Damage_SetDamageEventData(struct NWNX_Damage_DamageEventData data)
{
    string sFunc = "SetDamageEventData";

    NWNX_PushArgumentInt(data.iBase);
    NWNX_PushArgumentInt(data.iSonic);
    NWNX_PushArgumentInt(data.iPositive);
    NWNX_PushArgumentInt(data.iNegative);
    NWNX_PushArgumentInt(data.iFire);
    NWNX_PushArgumentInt(data.iElectrical);
    NWNX_PushArgumentInt(data.iDivine);
    NWNX_PushArgumentInt(data.iCold);
    NWNX_PushArgumentInt(data.iAcid);
    NWNX_PushArgumentInt(data.iMagical);
    NWNX_PushArgumentInt(data.iSlash);
    NWNX_PushArgumentInt(data.iPierce);
    NWNX_PushArgumentInt(data.iBludgeoning);

    NWNX_CallFunction(NWNX_Damage, sFunc);
}

void NWNX_Damage_SetAttackEventScript(string sScript, object oOwner=OBJECT_INVALID)
{
    string sFunc = "SetEventScript";

    NWNX_PushArgumentObject(oOwner);
    NWNX_PushArgumentString(sScript);
    NWNX_PushArgumentString("ATTACK");

    NWNX_CallFunction(NWNX_Damage, sFunc);
}

struct NWNX_Damage_AttackEventData NWNX_Damage_GetAttackEventData()
{
    string sFunc = "GetAttackEventData";
    struct NWNX_Damage_AttackEventData data;

    NWNX_CallFunction(NWNX_Damage, sFunc);

    data.oTarget           = NWNX_GetReturnValueObject();
    data.iBludgeoning      = NWNX_GetReturnValueInt();
    data.iPierce           = NWNX_GetReturnValueInt();
    data.iSlash            = NWNX_GetReturnValueInt();
    data.iMagical          = NWNX_GetReturnValueInt();
    data.iAcid             = NWNX_GetReturnValueInt();
    data.iCold             = NWNX_GetReturnValueInt();
    data.iDivine           = NWNX_GetReturnValueInt();
    data.iElectrical       = NWNX_GetReturnValueInt();
    data.iFire             = NWNX_GetReturnValueInt();
    data.iNegative         = NWNX_GetReturnValueInt();
    data.iPositive         = NWNX_GetReturnValueInt();
    data.iSonic            = NWNX_GetReturnValueInt();
    data.iBase             = NWNX_GetReturnValueInt();
    data.iAttackNumber     = NWNX_GetReturnValueInt();
    data.iAttackResult     = NWNX_GetReturnValueInt();
    data.iWeaponAttackType = NWNX_GetReturnValueInt();
    data.iSneakAttack      = NWNX_GetReturnValueInt();
    data.bKillingBlow      = NWNX_GetReturnValueInt();
    data.iAttackType       = NWNX_GetReturnValueInt();

    return data;
}

void NWNX_Damage_SetAttackEventData(struct NWNX_Damage_AttackEventData data)
{
    string sFunc = "SetAttackEventData";

    NWNX_PushArgumentInt(data.iAttackResult);
    NWNX_PushArgumentInt(data.iBase);
    NWNX_PushArgumentInt(data.iSonic);
    NWNX_PushArgumentInt(data.iPositive);
    NWNX_PushArgumentInt(data.iNegative);
    NWNX_PushArgumentInt(data.iFire);
    NWNX_PushArgumentInt(data.iElectrical);
    NWNX_PushArgumentInt(data.iDivine);
    NWNX_PushArgumentInt(data.iCold);
    NWNX_PushArgumentInt(data.iAcid);
    NWNX_PushArgumentInt(data.iMagical);
    NWNX_PushArgumentInt(data.iSlash);
    NWNX_PushArgumentInt(data.iPierce);
    NWNX_PushArgumentInt(data.iBludgeoning);

    NWNX_CallFunction(NWNX_Damage, sFunc);
}

void NWNX_Damage_DealDamage(struct NWNX_Damage_DamageData data, object oTarget, object oSource, int iRanged = FALSE)
{
    string sFunc = "DealDamage";

    NWNX_PushArgumentInt(iRanged);
    NWNX_PushArgumentInt(data.iPower);
    NWNX_PushArgumentInt(data.iSonic);
    NWNX_PushArgumentInt(data.iPositive);
    NWNX_PushArgumentInt(data.iNegative);
    NWNX_PushArgumentInt(data.iFire);
    NWNX_PushArgumentInt(data.iElectrical);
    NWNX_PushArgumentInt(data.iDivine);
    NWNX_PushArgumentInt(data.iCold);
    NWNX_PushArgumentInt(data.iAcid);
    NWNX_PushArgumentInt(data.iMagical);
    NWNX_PushArgumentInt(data.iSlash);
    NWNX_PushArgumentInt(data.iPierce);
    NWNX_PushArgumentInt(data.iBludgeoning);
    NWNX_PushArgumentObject(oTarget);
    NWNX_PushArgumentObject(oSource);

    NWNX_CallFunction(NWNX_Damage, sFunc);
}
