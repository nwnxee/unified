/// @addtogroup damage Damage
/// @brief Run a script before damage and attack events allowing for modification. Includes function to arbitrarily apply damage.
/// @{
/// @file nwnx_damage.nss

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
    int iCustom1; ///< Custom1 damage
    int iCustom2; ///< Custom2 damage
    int iCustom3; ///< Custom3 damage
    int iCustom4; ///< Custom4 damage
    int iCustom5; ///< Custom5 damage
    int iCustom6; ///< Custom6 damage
    int iCustom7; ///< Custom7 damage
    int iCustom8; ///< Custom8 damage
    int iCustom9; ///< Custom9 damage
    int iCustom10; ///< Custom10 damage
    int iCustom11; ///< Custom11 damage
    int iCustom12; ///< Custom12 damage
    int iCustom13; ///< Custom13 damage
    int iCustom14; ///< Custom14 damage
    int iCustom15; ///< Custom15 damage
    int iCustom16; ///< Custom16 damage
    int iCustom17; ///< Custom17 damage
    int iCustom18; ///< Custom18 damage
    int iCustom19; ///< Custom19 damage
    int iSpellId; ///< The spell id associated with the damage or -1 if not known.
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
    int iCustom1; ///< Custom1 damage
    int iCustom2; ///< Custom2 damage
    int iCustom3; ///< Custom3 damage
    int iCustom4; ///< Custom4 damage
    int iCustom5; ///< Custom5 damage
    int iCustom6; ///< Custom6 damage
    int iCustom7; ///< Custom7 damage
    int iCustom8; ///< Custom8 damage
    int iCustom9; ///< Custom9 damage
    int iCustom10; ///< Custom10 damage
    int iCustom11; ///< Custom11 damage
    int iCustom12; ///< Custom12 damage
    int iCustom13; ///< Custom13 damage
    int iCustom14; ///< Custom14 damage
    int iCustom15; ///< Custom15 damage
    int iCustom16; ///< Custom16 damage
    int iCustom17; ///< Custom17 damage
    int iCustom18; ///< Custom18 damage
    int iCustom19; ///< Custom19 damage
    int iAttackNumber; ///< 1-based index of the attack in current combat round
    int iAttackResult; ///< 1=hit, 2=parried, 3=critical hit, 4=miss, 5=resisted, 7=automatic hit, 8=concealed, 9=miss chance, 10=devastating crit
    int iWeaponAttackType; ///< 1=main hand, 2=offhand, 3-5=creature, 6=extra(haste), 7=unarmed, 8=unarmed extra
    int iSneakAttack; ///< 0=neither, 1=sneak attack, 2=death attack, 3=both
    int iAttackType; ///< 65002=Attack of Opportunity, 65003=Riposte or a FeatID like KnockDown or some other special attack.
    int bKillingBlow; ///< TRUE if the hit is a killing blow
    int iToHitRoll; ///< The to hit roll of the attack
    int iToHitModifier; ///< The to hit modifier of the attack
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
    int iCustom1; ///< Custom1 damage
    int iCustom2; ///< Custom2 damage
    int iCustom3; ///< Custom3 damage
    int iCustom4; ///< Custom4 damage
    int iCustom5; ///< Custom5 damage
    int iCustom6; ///< Custom6 damage
    int iCustom7; ///< Custom7 damage
    int iCustom8; ///< Custom8 damage
    int iCustom9; ///< Custom9 damage
    int iCustom10; ///< Custom10 damage
    int iCustom11; ///< Custom11 damage
    int iCustom12; ///< Custom12 damage
    int iCustom13; ///< Custom13 damage
    int iCustom14; ///< Custom14 damage
    int iCustom15; ///< Custom15 damage
    int iCustom16; ///< Custom16 damage
    int iCustom17; ///< Custom17 damage
    int iCustom18; ///< Custom18 damage
    int iCustom19; ///< Custom19 damage
    int iPower; ///< For overcoming DR
};

/// @brief Sets the script to run with a damage event.
/// @param sScript The script that will handle the damage event.
/// @param oOwner An object if only executing for a specific object or OBJECT_INVALID for global.
void NWNX_Damage_SetDamageEventScript(string sScript, object oOwner = OBJECT_INVALID);

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
void NWNX_Damage_SetAttackEventScript(string sScript, object oOwner = OBJECT_INVALID);

/// @brief Get Attack Event Data
/// @return A NWNX_Damage_AttackEventData struct.
/// @note To use only in the Attack Event Script.
struct NWNX_Damage_AttackEventData NWNX_Damage_GetAttackEventData();

/// @brief Set Attack Event Data
/// @param data A NWNX_Damage_AttackEventData struct.
/// @note To use only in the Attack Event Script.
/// @note Setting iSneakAttack will only change the attack roll message and floating text feedback. Immunities and damage will have already been resolved by the time the attack event script is ran.
void NWNX_Damage_SetAttackEventData(struct NWNX_Damage_AttackEventData data);

/// @brief Deal damage to a target.
/// @remark Permits multiple damage types and checks enhancement bonus for overcoming DR.
/// @param data A NWNX_Damage_DamageData struct.
/// @param oTarget The target object on whom the damage is dealt.
/// @param oSource The source of the damage.
/// @param iRanged Whether the attack should be treated as ranged by the engine (for example when considering damage inflicted by Acid Sheath and other such effects)
void NWNX_Damage_DealDamage(struct NWNX_Damage_DamageData data, object oTarget, object oSource = OBJECT_SELF, int iRanged = FALSE);

/// @}

void NWNX_Damage_SetDamageEventScript(string sScript, object oOwner=OBJECT_INVALID)
{
    NWNXPushObject(oOwner);
    NWNXPushString(sScript);
    NWNXPushString("DAMAGE");
    NWNXCall(NWNX_Damage, "SetEventScript");
}

struct NWNX_Damage_DamageEventData NWNX_Damage_GetDamageEventData()
{
    struct NWNX_Damage_DamageEventData data;
    NWNXCall(NWNX_Damage, "GetDamageEventData");
    data.oDamager     = NWNXPopObject();
    data.iBludgeoning = NWNXPopInt();
    data.iPierce      = NWNXPopInt();
    data.iSlash       = NWNXPopInt();
    data.iMagical     = NWNXPopInt();
    data.iAcid        = NWNXPopInt();
    data.iCold        = NWNXPopInt();
    data.iDivine      = NWNXPopInt();
    data.iElectrical  = NWNXPopInt();
    data.iFire        = NWNXPopInt();
    data.iNegative    = NWNXPopInt();
    data.iPositive    = NWNXPopInt();
    data.iSonic       = NWNXPopInt();
    data.iBase        = NWNXPopInt();
    data.iCustom1     = NWNXPopInt();
    data.iCustom2     = NWNXPopInt();
    data.iCustom3     = NWNXPopInt();
    data.iCustom4     = NWNXPopInt();
    data.iCustom5     = NWNXPopInt();
    data.iCustom6     = NWNXPopInt();
    data.iCustom7     = NWNXPopInt();
    data.iCustom8     = NWNXPopInt();
    data.iCustom9     = NWNXPopInt();
    data.iCustom10    = NWNXPopInt();
    data.iCustom11    = NWNXPopInt();
    data.iCustom12    = NWNXPopInt();
    data.iCustom13    = NWNXPopInt();
    data.iCustom14    = NWNXPopInt();
    data.iCustom15    = NWNXPopInt();
    data.iCustom16    = NWNXPopInt();
    data.iCustom17    = NWNXPopInt();
    data.iCustom18    = NWNXPopInt();
    data.iCustom19    = NWNXPopInt();
    data.iSpellId     = NWNXPopInt();
    return data;
}

void NWNX_Damage_SetDamageEventData(struct NWNX_Damage_DamageEventData data)
{
    NWNXPushInt(data.iCustom19);
    NWNXPushInt(data.iCustom18);
    NWNXPushInt(data.iCustom17);
    NWNXPushInt(data.iCustom16);
    NWNXPushInt(data.iCustom15);
    NWNXPushInt(data.iCustom14);
    NWNXPushInt(data.iCustom13);
    NWNXPushInt(data.iCustom12);
    NWNXPushInt(data.iCustom11);
    NWNXPushInt(data.iCustom10);
    NWNXPushInt(data.iCustom9);
    NWNXPushInt(data.iCustom8);
    NWNXPushInt(data.iCustom7);
    NWNXPushInt(data.iCustom6);
    NWNXPushInt(data.iCustom5);
    NWNXPushInt(data.iCustom4);
    NWNXPushInt(data.iCustom3);
    NWNXPushInt(data.iCustom2);
    NWNXPushInt(data.iCustom1);
    NWNXPushInt(data.iBase);
    NWNXPushInt(data.iSonic);
    NWNXPushInt(data.iPositive);
    NWNXPushInt(data.iNegative);
    NWNXPushInt(data.iFire);
    NWNXPushInt(data.iElectrical);
    NWNXPushInt(data.iDivine);
    NWNXPushInt(data.iCold);
    NWNXPushInt(data.iAcid);
    NWNXPushInt(data.iMagical);
    NWNXPushInt(data.iSlash);
    NWNXPushInt(data.iPierce);
    NWNXPushInt(data.iBludgeoning);

    NWNXCall(NWNX_Damage, "SetDamageEventData");
}

void NWNX_Damage_SetAttackEventScript(string sScript, object oOwner=OBJECT_INVALID)
{
    NWNXPushObject(oOwner);
    NWNXPushString(sScript);
    NWNXPushString("ATTACK");
    NWNXCall(NWNX_Damage, "SetEventScript");
}

struct NWNX_Damage_AttackEventData NWNX_Damage_GetAttackEventData()
{
    struct NWNX_Damage_AttackEventData data;
    NWNXCall(NWNX_Damage, "GetAttackEventData");
    data.oTarget           = NWNXPopObject();
    data.iBludgeoning      = NWNXPopInt();
    data.iPierce           = NWNXPopInt();
    data.iSlash            = NWNXPopInt();
    data.iMagical          = NWNXPopInt();
    data.iAcid             = NWNXPopInt();
    data.iCold             = NWNXPopInt();
    data.iDivine           = NWNXPopInt();
    data.iElectrical       = NWNXPopInt();
    data.iFire             = NWNXPopInt();
    data.iNegative         = NWNXPopInt();
    data.iPositive         = NWNXPopInt();
    data.iSonic            = NWNXPopInt();
    data.iBase             = NWNXPopInt();
    data.iCustom1          = NWNXPopInt();
    data.iCustom2          = NWNXPopInt();
    data.iCustom3          = NWNXPopInt();
    data.iCustom4          = NWNXPopInt();
    data.iCustom5          = NWNXPopInt();
    data.iCustom6          = NWNXPopInt();
    data.iCustom7          = NWNXPopInt();
    data.iCustom8          = NWNXPopInt();
    data.iCustom9          = NWNXPopInt();
    data.iCustom10         = NWNXPopInt();
    data.iCustom11         = NWNXPopInt();
    data.iCustom12         = NWNXPopInt();
    data.iCustom13         = NWNXPopInt();
    data.iCustom14         = NWNXPopInt();
    data.iCustom15         = NWNXPopInt();
    data.iCustom16         = NWNXPopInt();
    data.iCustom17         = NWNXPopInt();
    data.iCustom18         = NWNXPopInt();
    data.iCustom19         = NWNXPopInt();
    data.iAttackNumber     = NWNXPopInt();
    data.iAttackResult     = NWNXPopInt();
    data.iWeaponAttackType = NWNXPopInt();
    data.iSneakAttack      = NWNXPopInt();
    data.bKillingBlow      = NWNXPopInt();
    data.iAttackType       = NWNXPopInt();
    data.iToHitRoll        = NWNXPopInt();
    data.iToHitModifier    = NWNXPopInt();
    return data;
}

void NWNX_Damage_SetAttackEventData(struct NWNX_Damage_AttackEventData data)
{
    NWNXPushInt(data.iSneakAttack);
    NWNXPushInt(data.iAttackResult);
    NWNXPushInt(data.iCustom19);
    NWNXPushInt(data.iCustom18);
    NWNXPushInt(data.iCustom17);
    NWNXPushInt(data.iCustom16);
    NWNXPushInt(data.iCustom15);
    NWNXPushInt(data.iCustom14);
    NWNXPushInt(data.iCustom13);
    NWNXPushInt(data.iCustom12);
    NWNXPushInt(data.iCustom11);
    NWNXPushInt(data.iCustom10);
    NWNXPushInt(data.iCustom9);
    NWNXPushInt(data.iCustom8);
    NWNXPushInt(data.iCustom7);
    NWNXPushInt(data.iCustom6);
    NWNXPushInt(data.iCustom5);
    NWNXPushInt(data.iCustom4);
    NWNXPushInt(data.iCustom3);
    NWNXPushInt(data.iCustom2);
    NWNXPushInt(data.iCustom1);
    NWNXPushInt(data.iBase);
    NWNXPushInt(data.iSonic);
    NWNXPushInt(data.iPositive);
    NWNXPushInt(data.iNegative);
    NWNXPushInt(data.iFire);
    NWNXPushInt(data.iElectrical);
    NWNXPushInt(data.iDivine);
    NWNXPushInt(data.iCold);
    NWNXPushInt(data.iAcid);
    NWNXPushInt(data.iMagical);
    NWNXPushInt(data.iSlash);
    NWNXPushInt(data.iPierce);
    NWNXPushInt(data.iBludgeoning);
    NWNXCall(NWNX_Damage, "SetAttackEventData");
}

void NWNX_Damage_DealDamage(struct NWNX_Damage_DamageData data, object oTarget, object oSource, int iRanged = FALSE)
{
    NWNXPushInt(iRanged);
    NWNXPushInt(data.iPower);
    NWNXPushInt(data.iCustom19);
    NWNXPushInt(data.iCustom18);
    NWNXPushInt(data.iCustom17);
    NWNXPushInt(data.iCustom16);
    NWNXPushInt(data.iCustom15);
    NWNXPushInt(data.iCustom14);
    NWNXPushInt(data.iCustom13);
    NWNXPushInt(data.iCustom12);
    NWNXPushInt(data.iCustom11);
    NWNXPushInt(data.iCustom10);
    NWNXPushInt(data.iCustom9);
    NWNXPushInt(data.iCustom8);
    NWNXPushInt(data.iCustom7);
    NWNXPushInt(data.iCustom6);
    NWNXPushInt(data.iCustom5);
    NWNXPushInt(data.iCustom4);
    NWNXPushInt(data.iCustom3);
    NWNXPushInt(data.iCustom2);
    NWNXPushInt(data.iCustom1);
    NWNXPushInt(0);// Padding for Base Damage
    NWNXPushInt(data.iSonic);
    NWNXPushInt(data.iPositive);
    NWNXPushInt(data.iNegative);
    NWNXPushInt(data.iFire);
    NWNXPushInt(data.iElectrical);
    NWNXPushInt(data.iDivine);
    NWNXPushInt(data.iCold);
    NWNXPushInt(data.iAcid);
    NWNXPushInt(data.iMagical);
    NWNXPushInt(data.iSlash);
    NWNXPushInt(data.iPierce);
    NWNXPushInt(data.iBludgeoning);
    NWNXPushObject(oTarget);
    NWNXPushObject(oSource);
    NWNXCall(NWNX_Damage, "DealDamage");
}
