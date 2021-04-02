/// @addtogroup weapon Weapon
/// @brief Functions exposing additional weapon properties.
/// @{
/// @file nwnx_weapon.nss
#include "nwnx"

const string NWNX_Weapon = "NWNX_Weapon"; ///< @private

/// @name Weapons Options
/// @anchor wpn_opts
///
/// Options constants to be used with NWNX_Weapon_SetOption function.
/// @{
const int NWNX_WEAPON_OPT_GRTFOCUS_AB_BONUS = 0; ///< Greater Focus Attack Bonus
const int NWNX_WEAPON_OPT_GRTSPEC_DAM_BONUS = 1; ///< Greater Specialization Damage Bonus
///@}

// Get Event Data Constants
const int NWNX_WEAPON_GETDATA_DC = 0; ///< Get Devastating Critical Data

// Set Event Data Constants
const int NWNX_WEAPON_SETDATA_DC_BYPASS = 0; ///< Set Devastating Critical Bypass

/// Devastating critical event data
struct NWNX_Weapon_DevastatingCriticalEvent_Data
{
    object oWeapon; ///< The weapon used to cause the event.
    object oTarget; ///< The target hit with a devastating critical.
    int nDamage; ///< The damage points delivered.
};

/// @brief Set nFeat as weapon focus feat for a base item.
/// @param nBaseItem The base item id.
/// @param nFeat The feat to set.
void NWNX_Weapon_SetWeaponFocusFeat(int nBaseItem, int nFeat);

/// @brief Set required creature size for a weapon base item to be finessable.
/// @param nBaseItem The base item id.
/// @param nSize The creature size minimum to consider this weapon finessable.
void NWNX_Weapon_SetWeaponFinesseSize(int nBaseItem, int nSize);

/// @brief Get required creature size for a weapon base item to be finessable.
/// @param nBaseItem The base item id.
int NWNX_Weapon_GetWeaponFinesseSize(int nBaseItem);

/// @brief Set weapon base item to be considered as unarmed for weapon finesse feat.
/// @param nBaseItem The base item id.
void NWNX_Weapon_SetWeaponUnarmed(int nBaseItem);

/// @brief Set a feat as weapon improved critical for a base item.
/// @param nBaseItem The base item id.
/// @param nFeat The feat to set.
void NWNX_Weapon_SetWeaponImprovedCriticalFeat(int nBaseItem, int nFeat);

/// @brief Set a feat as weapon specialization for a base item.
/// @param nBaseItem The base item id.
/// @param nFeat The feat to set.
void NWNX_Weapon_SetWeaponSpecializationFeat(int nBaseItem, int nFeat);

/// @brief Set a feat as epic weapon focus for a base item.
/// @param nBaseItem The base item id.
/// @param nFeat The feat to set.
void NWNX_Weapon_SetEpicWeaponFocusFeat(int nBaseItem, int nFeat);

/// @brief Set a feat as epic weapon specialization for a base item.
/// @param nBaseItem The base item id.
/// @param nFeat The feat to set.
void NWNX_Weapon_SetEpicWeaponSpecializationFeat(int nBaseItem, int nFeat);

/// @brief Set a feat as epic weapon overwhelming critical for a base item.
/// @param nBaseItem The base item id.
/// @param nFeat The feat to set.
void NWNX_Weapon_SetEpicWeaponOverwhelmingCriticalFeat(int nBaseItem, int nFeat);

/// @brief Set a feat as epic weapon devastating critical for a base item.
/// @param nBaseItem The base item id.
/// @param nFeat The feat to set.
void NWNX_Weapon_SetEpicWeaponDevastatingCriticalFeat(int nBaseItem, int nFeat);

/// @brief Set a feat as weapon of choice for a base item.
/// @param nBaseItem The base item id.
/// @param nFeat The feat to set.
void NWNX_Weapon_SetWeaponOfChoiceFeat(int nBaseItem, int nFeat);

/// @brief Set a feat as greater weapon specialization for a base item.
/// @param nBaseItem The base item id.
/// @param nFeat The feat to set.
void NWNX_Weapon_SetGreaterWeaponSpecializationFeat(int nBaseItem, int nFeat);

/// @brief Set a feat as greater weapon focus for a base item.
/// @param nBaseItem The base item id.
/// @param nFeat The feat to set.
void NWNX_Weapon_SetGreaterWeaponFocusFeat(int nBaseItem, int nFeat);

/// @brief Set base item as monk weapon.
/// @note Requires activation of CombatModes plugin for Flurry of Blows.
/// @param nBaseItem The base item id.
void NWNX_Weapon_SetWeaponIsMonkWeapon(int nBaseItem);

/// @brief Set plugin options.
/// @param nOption The option to change from @ref wpn_opts "Weapon Options".
/// @param nVal The new value of the option.
void NWNX_Weapon_SetOption(int nOption, int nVal);

/// @brief Set Devastating Critical Event Script.
/// @param sScript The script to call when a Devastating Critical occurs.
void NWNX_Weapon_SetDevastatingCriticalEventScript(string sScript);

/// @brief Get Devastating Critical Event Data.
/// @note This is only for use with the Devastating Critical Event Script.
/// @return An NWNX_Weapon_DevastatingCriticalEvent_Data struct.
struct NWNX_Weapon_DevastatingCriticalEvent_Data NWNX_Weapon_GetDevastatingCriticalEventData();

/// @brief Bypass Devastating Critical.
/// @note This is only for use with the Devastating Critical Event Script.
void NWNX_Weapon_BypassDevastatingCritical();

/// @brief Sets weapon to gain .5 strength bonus.
/// @param oWeapon Should be a melee weapon.
/// @param nEnable TRUE for bonus. FALSE to turn off bonus.
/// @param bPersist whether the two hand state should persist to the gff file.
void NWNX_Weapon_SetOneHalfStrength(object oWeapon, int nEnable, int bPersist = FALSE);

/// @brief Gets if the weapon is set to gain addition .5 strength bonus
/// @param oWeapon the weapon
/// @return FALSE/0 if weapon is not receiving the bonus. TRUE/1 if it does.
int NWNX_Weapon_GetOneHalfStrength(object oWeapon);

/// @brief Override the max attack distance of ranged weapons.
/// @param nBaseItem The baseitem id.
/// @param fMax The maximum attack distance. Default is 40.0f.
/// @param fMaxPassive The maximum passive attack distance. Default is 20.0f. Seems to be used by the engine to determine a new nearby target when needed.
/// @param fPreferred The preferred attack distance. See the PrefAttackDist column in baseitems.2da, default seems to be 30.0f for ranged weapons.
/// @note fMaxPassive should probably be lower than fMax, half of fMax seems to be a good start. fPreferred should be at least ~0.5f lower than fMax.
void NWNX_Weapon_SetMaxRangedAttackDistanceOverride(int nBaseItem, float fMax, float fMaxPassive, float fPreferred);

/// @}

void NWNX_Weapon_SetWeaponFocusFeat(int nBaseItem, int nFeat)
{
    string sFunc = "SetWeaponFocusFeat";

    NWNX_PushArgumentInt(nFeat);
    NWNX_PushArgumentInt(nBaseItem);

    NWNX_CallFunction(NWNX_Weapon, sFunc);
}

void NWNX_Weapon_SetEpicWeaponFocusFeat(int nBaseItem, int nFeat)
{
    string sFunc = "SetEpicWeaponFocusFeat";

    NWNX_PushArgumentInt(nFeat);
    NWNX_PushArgumentInt(nBaseItem);

    NWNX_CallFunction(NWNX_Weapon, sFunc);
}

void NWNX_Weapon_SetGreaterWeaponFocusFeat(int nBaseItem, int nFeat)
{
    string sFunc = "SetGreaterWeaponFocusFeat";

    NWNX_PushArgumentInt(nFeat);
    NWNX_PushArgumentInt(nBaseItem);

    NWNX_CallFunction(NWNX_Weapon, sFunc);
}

void NWNX_Weapon_SetWeaponFinesseSize(int nBaseItem, int nSize)
{
    string sFunc = "SetWeaponFinesseSize";

    NWNX_PushArgumentInt(nSize);
    NWNX_PushArgumentInt(nBaseItem);

    NWNX_CallFunction(NWNX_Weapon, sFunc);
}

int NWNX_Weapon_GetWeaponFinesseSize(int nBaseItem)
{
    string sFunc = "GetWeaponFinesseSize";

    NWNX_PushArgumentInt(nBaseItem);

    NWNX_CallFunction(NWNX_Weapon, sFunc);

    return NWNX_GetReturnValueInt();
}

void NWNX_Weapon_SetWeaponUnarmed(int nBaseItem)
{
    string sFunc = "SetWeaponUnarmed";

    NWNX_PushArgumentInt(nBaseItem);

    NWNX_CallFunction(NWNX_Weapon, sFunc);
}

void NWNX_Weapon_SetWeaponIsMonkWeapon(int nBaseItem)
{
    string sFunc = "SetWeaponIsMonkWeapon";

    NWNX_PushArgumentInt(nBaseItem);

    NWNX_CallFunction(NWNX_Weapon, sFunc);
}

void NWNX_Weapon_SetWeaponImprovedCriticalFeat(int nBaseItem, int nFeat)
{
    string sFunc = "SetWeaponImprovedCriticalFeat";

    NWNX_PushArgumentInt(nFeat);
    NWNX_PushArgumentInt(nBaseItem);

    NWNX_CallFunction(NWNX_Weapon, sFunc);
}

void NWNX_Weapon_SetWeaponSpecializationFeat(int nBaseItem, int nFeat)
{
    string sFunc = "SetWeaponSpecializationFeat";

    NWNX_PushArgumentInt(nFeat);
    NWNX_PushArgumentInt(nBaseItem);

    NWNX_CallFunction(NWNX_Weapon, sFunc);
}

void NWNX_Weapon_SetGreaterWeaponSpecializationFeat(int nBaseItem, int nFeat)
{
    string sFunc = "SetGreaterWeaponSpecializationFeat";

    NWNX_PushArgumentInt(nFeat);
    NWNX_PushArgumentInt(nBaseItem);

    NWNX_CallFunction(NWNX_Weapon, sFunc);
}

void NWNX_Weapon_SetEpicWeaponSpecializationFeat(int nBaseItem, int nFeat)
{
    string sFunc = "SetEpicWeaponSpecializationFeat";

    NWNX_PushArgumentInt(nFeat);
    NWNX_PushArgumentInt(nBaseItem);

    NWNX_CallFunction(NWNX_Weapon, sFunc);
}

void NWNX_Weapon_SetEpicWeaponOverwhelmingCriticalFeat(int nBaseItem, int nFeat)
{
    string sFunc = "SetEpicWeaponOverwhelmingCriticalFeat";

    NWNX_PushArgumentInt(nFeat);
    NWNX_PushArgumentInt(nBaseItem);

    NWNX_CallFunction(NWNX_Weapon, sFunc);
}

void NWNX_Weapon_SetEpicWeaponDevastatingCriticalFeat(int nBaseItem, int nFeat)
{
    string sFunc = "SetEpicWeaponDevastatingCriticalFeat";

    NWNX_PushArgumentInt(nFeat);
    NWNX_PushArgumentInt(nBaseItem);

    NWNX_CallFunction(NWNX_Weapon, sFunc);
}

void NWNX_Weapon_SetWeaponOfChoiceFeat(int nBaseItem, int nFeat)
{
    string sFunc = "SetWeaponOfChoiceFeat";

    NWNX_PushArgumentInt(nFeat);
    NWNX_PushArgumentInt(nBaseItem);

    NWNX_CallFunction(NWNX_Weapon, sFunc);
}

void NWNX_Weapon_SetOption(int nOption, int nVal)
{
    string sFunc = "SetOption";

    NWNX_PushArgumentInt(nVal);
    NWNX_PushArgumentInt(nOption);

    NWNX_CallFunction(NWNX_Weapon, sFunc);
}

void NWNX_Weapon_SetDevastatingCriticalEventScript(string sScript)
{
    string sFunc = "SetDevastatingCriticalEventScript";

    NWNX_PushArgumentString(sScript);

    NWNX_CallFunction(NWNX_Weapon, sFunc);
}

void NWNX_Weapon_BypassDevastatingCritical()
{
    string sFunc = "SetEventData";

    NWNX_PushArgumentInt(1);
    NWNX_PushArgumentInt(NWNX_WEAPON_SETDATA_DC_BYPASS);

    NWNX_CallFunction(NWNX_Weapon, sFunc);
}

struct NWNX_Weapon_DevastatingCriticalEvent_Data NWNX_Weapon_GetDevastatingCriticalEventData()
{
    string sFunc = "GetEventData";
    struct NWNX_Weapon_DevastatingCriticalEvent_Data data;

    NWNX_PushArgumentInt(NWNX_WEAPON_GETDATA_DC);
    NWNX_CallFunction(NWNX_Weapon, sFunc);

    data.oWeapon = NWNX_GetReturnValueObject();
    data.oTarget = NWNX_GetReturnValueObject();
    data.nDamage = NWNX_GetReturnValueInt();

    return data;
}

void NWNX_Weapon_SetOneHalfStrength(object oWeapon, int nEnable, int bPersist = FALSE)
{
    string sFunc = "SetOneHalfStrength";
    NWNX_PushArgumentInt(bPersist);
    NWNX_PushArgumentInt(nEnable);
    NWNX_PushArgumentObject(oWeapon);
    NWNX_CallFunction(NWNX_Weapon, sFunc);
}

int NWNX_Weapon_GetOneHalfStrength(object oWeapon)
{
    string sFunc = "GetOneHalfStrength";
    NWNX_PushArgumentObject(oWeapon);
    NWNX_CallFunction(NWNX_Weapon, sFunc);

    return NWNX_GetReturnValueInt();
}

void NWNX_Weapon_SetMaxRangedAttackDistanceOverride(int nBaseItem, float fMax, float fMaxPassive, float fPreferred)
{
    string sFunc = "SetMaxRangedAttackDistanceOverride";

    NWNX_PushArgumentFloat(fPreferred);
    NWNX_PushArgumentFloat(fMaxPassive);
    NWNX_PushArgumentFloat(fMax);
    NWNX_PushArgumentInt(nBaseItem);
    NWNX_CallFunction(NWNX_Weapon, sFunc);
}
