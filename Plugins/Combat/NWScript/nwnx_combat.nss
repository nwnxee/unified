/// @addtogroup combat Combat
/// @brief Functions that expose extra functionality related to the combat engine
/// @{
/// @file nwnx_combat.nss
#include "nwnx"

const string NWNX_Combat = "NWNX_Combat"; ///< @private

const int NWNX_COMBAT_SCRIPT_TYPE_REQUIREMENTS = 0;
const int NWNX_COMBAT_SCRIPT_TYPE_ATTACK_MODIFIER = 1;
const int NWNX_COMBAT_SCRIPT_TYPE_DAMAGE_MODIFIER = 2;
const int NWNX_COMBAT_SCRIPT_TYPE_POST_DAMAGE = 3;

const int NWNX_COMBAT_FEAT_TYPE_ANY = 0;
const int NWNX_COMBAT_FEAT_TYPE_MELEE = 1;
const int NWNX_COMBAT_FEAT_TYPE_RANGED = 2;

/// @brief Set custom modifiers and scripts for a special attack feat.
/// @param nFeat Feat ID of the special attack.
void NWNX_Combat_SetSpecialAttackInfo(int nFeat, int nAttackRangeType, int nDamageModifier = 0, int nAttackModifier = 0, string sTestRequirementsScript = "", string sAttackModScript = "", string sDamageModScript = "", string sPostDamageScript = "");

/// @brief Sets a new return value for the current function.
/// @param nRet returned value
void NWNX_Combat_SetReturnValue(int nRet);

/// @brief Gets the feat ID for this feat event
/// @return feat ID
int NWNX_Combat_GetCurrentFeat();

/// @brief Gets the script type of the current script.
/// @return script type
int NWNX_Combat_GetScriptType();

/// @brief Gets the target of the current special attack.
/// @return feat target
object NWNX_Combat_GetFeatTarget();

/// @}

void NWNX_Combat_SetSpecialAttackInfo(int nFeat, int nAttackRangeType, int nDamageModifier = 0, int nAttackModifier = 0, string sTestRequirementsScript = "", string sAttackModScript = "", string sDamageModScript = "", string sPostDamageScript = "")
{
    string sFunc = "SetSpecialAttackInfo";

    NWNX_PushArgumentString(NWNX_Combat, sFunc, sPostDamageScript);
    NWNX_PushArgumentString(NWNX_Combat, sFunc, sDamageModScript);
    NWNX_PushArgumentString(NWNX_Combat, sFunc, sAttackModScript);
    NWNX_PushArgumentString(NWNX_Combat, sFunc, sTestRequirementsScript);
    NWNX_PushArgumentInt(NWNX_Combat, sFunc, nAttackModifier);
    NWNX_PushArgumentInt(NWNX_Combat, sFunc, nDamageModifier);
    NWNX_PushArgumentInt(NWNX_Combat, sFunc, nAttackRangeType);
    NWNX_PushArgumentInt(NWNX_Combat, sFunc, nFeat);

    NWNX_CallFunction(NWNX_Combat, sFunc);
}

void NWNX_Combat_SetReturnValue(int nRet)
{
    string sFunc = "SetReturnValue";

    NWNX_PushArgumentInt(NWNX_Combat, sFunc, nRet);

    NWNX_CallFunction(NWNX_Combat, sFunc);
}

int NWNX_Combat_GetCurrentFeat()
{
    string sFunc = "GetCurrentFeat";

    NWNX_CallFunction(NWNX_Combat, sFunc);

    return NWNX_GetReturnValueInt(NWNX_Combat, sFunc);
}

int NWNX_Combat_GetScriptType()
{
    string sFunc = "GetScriptType";

    NWNX_CallFunction(NWNX_Combat, sFunc);

    return NWNX_GetReturnValueInt(NWNX_Combat, sFunc);
}

object NWNX_Combat_GetFeatTarget()
{
    string sFunc = "GetFeatTarget";

    NWNX_CallFunction(NWNX_Combat, sFunc);

    return NWNX_GetReturnValueObject(NWNX_Combat, sFunc);
}
