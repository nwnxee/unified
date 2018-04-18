#include "nwnx"

const string NWNX_Weapon = "NWNX_Weapon";

// Otpions constants to be used with NWNX_Weapon_SetOption function
const int NWNX_WEAPON_OPT_GRTFOCUS_AB_BONUS = 0; // Greater Focus AB bonus
const int NWNX_WEAPON_OPT_GRTSPEC_DAM_BONUS = 1; // Greater Spec. DAM bonus

// Get Event Data Constants
const int NWNX_WEAPON_GETDATA_DC_WEAPON = 0; // Get Devastating Critical Weapon
const int NWNX_WEAPON_GETDATA_DC_TARGET = 1; // Get Devastating Critical Target
const int NWNX_WEAPON_GETDATA_DC_DAMAGE = 2; // Get Devastating Critical Damage

// Set Event Data Constants
const int NWNX_WEAPON_SETDATA_DC_BYPASS = 0; // Set Devastating Critical Bypass


struct

// Set nFeat as weapon focus feat for nBaseItem
void NWNX_Weapon_SetWeaponFocusFeat(int nBaseItem, int nFeat);

// Set required creature size for weapon nBaseItem to be finessable
void NWNX_Weapon_SetWeaponFinesseSize(int nBaseItem, int nSize);

// Set weapon nBaseItem to be considered as unarmed for weapon finesse feat
void NWNX_Weapon_SetWeaponUnarmed(int nBaseItem);

// Set nFeat as weapon improved critical feat for nBaseItem
void NWNX_Weapon_SetWeaponImprovedCriticalFeat(int nBaseItem, int nFeat);

// Set nFeat as weapon specialization feat for nBaseItem
void NWNX_Weapon_SetWeaponSpecializationFeat(int nBaseItem, int nFeat);

// Set nFeat as epic weapon focus feat for nBaseItem
void NWNX_Weapon_SetEpicWeaponFocusFeat(int nBaseItem, int nFeat);

// Set nFeat as epic weapon specialization feat for nBaseItem
void NWNX_Weapon_SetEpicWeaponSpecializationFeat(int nBaseItem, int nFeat);

// Set nFeat as epic weapon overwhelming critical feat for nBaseItem
void NWNX_Weapon_SetEpicWeaponOverwhelmingCriticalFeat(int nBaseItem, int nFeat);

// Set nFeat as epic weapon devastating critical feat for nBaseItem
void NWNX_Weapon_SetEpicWeaponDevastatingCriticalFeat(int nBaseItem, int nFeat);

// Set nFeat as weapon of choice feat for nBaseItem
void NWNX_Weapon_SetWeaponOfChoiceFeat(int nBaseItem, int nFeat);

// Set nFeat as greater weapon specialization feat for nBaseItem
void NWNX_Weapon_SetGreaterWeaponSpecializationFeat(int nBaseItem, int nFeat);

// Set nFeat as greater weapon focus feat for nBaseItem
void NWNX_Weapon_SetGreaterWeaponFocusFeat(int nBaseItem, int nFeat);

// Set nBaseItem as monk weapon
void NWNX_Weapon_SetWeaponIsMonkWeapon(int nBaseItem);

// Set plugin options
void NWNX_Weapon_SetOption(int nOption, int nVal);

// Set Devastating Critical Event Script
void NWNX_Weapon_SetDevastatingCritalEventScript(string sScript);

// Get Devastating Critical Event Weapon (to use only on Devastating Crital Event Script)
object NWNX_Weapon_GetDevastatingCritalEventWeapon();

// Get Devastating Critical Event Target (to use only on Devastating Crital Event Script)
object NWNX_Weapon_GetDevastatingCritalEventTarget();

// Get Devastating Critical Event Damage (to use only on Devastating Crital Event Script)
int NWNX_Weapon_GetDevastatingCritalEventDamage();

// Bypass Devastating Crtical (to use only on Devastating Crital Event Script)
void NWNX_Weapon_BypassDevastatingCritical();


void NWNX_Weapon_SetWeaponFocusFeat(int nBaseItem, int nFeat)
{
    string sFunc = "SetWeaponFocusFeat";

    NWNX_PushArgumentInt(NWNX_Weapon, sFunc, nFeat);
    NWNX_PushArgumentInt(NWNX_Weapon, sFunc, nBaseItem);

    NWNX_CallFunction(NWNX_Weapon, sFunc);
}

void NWNX_Weapon_SetEpicWeaponFocusFeat(int nBaseItem, int nFeat)
{
    string sFunc = "SetEpicWeaponFocusFeat";

    NWNX_PushArgumentInt(NWNX_Weapon, sFunc, nFeat);
    NWNX_PushArgumentInt(NWNX_Weapon, sFunc, nBaseItem);

    NWNX_CallFunction(NWNX_Weapon, sFunc);
}

void NWNX_Weapon_SetGreaterWeaponFocusFeat(int nBaseItem, int nFeat)
{
    string sFunc = "SetGreaterWeaponFocusFeat";

    NWNX_PushArgumentInt(NWNX_Weapon, sFunc, nFeat);
    NWNX_PushArgumentInt(NWNX_Weapon, sFunc, nBaseItem);

    NWNX_CallFunction(NWNX_Weapon, sFunc);
}

void NWNX_Weapon_SetWeaponFinesseSize(int nBaseItem, int nSize)
{
    string sFunc = "SetWeaponFinesseSize";

    NWNX_PushArgumentInt(NWNX_Weapon, sFunc, nSize);
    NWNX_PushArgumentInt(NWNX_Weapon, sFunc, nBaseItem);

    NWNX_CallFunction(NWNX_Weapon, sFunc);
}

void NWNX_Weapon_SetWeaponUnarmed(int nBaseItem)
{
    string sFunc = "SetWeaponUnarmed";

    NWNX_PushArgumentInt(NWNX_Weapon, sFunc, nBaseItem);

    NWNX_CallFunction(NWNX_Weapon, sFunc);
}

void NWNX_Weapon_SetWeaponIsMonkWeapon(int nBaseItem)
{
    string sFunc = "SetWeaponIsMonkWeapon";

    NWNX_PushArgumentInt(NWNX_Weapon, sFunc, nBaseItem);

    NWNX_CallFunction(NWNX_Weapon, sFunc);
}

void NWNX_Weapon_SetWeaponImprovedCriticalFeat(int nBaseItem, int nFeat)
{
    string sFunc = "SetWeaponImprovedCriticalFeat";

    NWNX_PushArgumentInt(NWNX_Weapon, sFunc, nFeat);
    NWNX_PushArgumentInt(NWNX_Weapon, sFunc, nBaseItem);

    NWNX_CallFunction(NWNX_Weapon, sFunc);
}

void NWNX_Weapon_SetWeaponSpecializationFeat(int nBaseItem, int nFeat)
{
    string sFunc = "SetWeaponSpecializationFeat";

    NWNX_PushArgumentInt(NWNX_Weapon, sFunc, nFeat);
    NWNX_PushArgumentInt(NWNX_Weapon, sFunc, nBaseItem);

    NWNX_CallFunction(NWNX_Weapon, sFunc);
}

void NWNX_Weapon_SetGreaterWeaponSpecializationFeat(int nBaseItem, int nFeat)
{
    string sFunc = "SetGreaterWeaponSpecializationFeat";

    NWNX_PushArgumentInt(NWNX_Weapon, sFunc, nFeat);
    NWNX_PushArgumentInt(NWNX_Weapon, sFunc, nBaseItem);

    NWNX_CallFunction(NWNX_Weapon, sFunc);
}

void NWNX_Weapon_SetEpicWeaponSpecializationFeat(int nBaseItem, int nFeat)
{
    string sFunc = "SetEpicWeaponSpecializationFeat";

    NWNX_PushArgumentInt(NWNX_Weapon, sFunc, nFeat);
    NWNX_PushArgumentInt(NWNX_Weapon, sFunc, nBaseItem);

    NWNX_CallFunction(NWNX_Weapon, sFunc);
}

void NWNX_Weapon_SetEpicWeaponOverwhelmingCriticalFeat(int nBaseItem, int nFeat)
{
    string sFunc = "SetEpicWeaponOverwhelmingCriticalFeat";

    NWNX_PushArgumentInt(NWNX_Weapon, sFunc, nFeat);
    NWNX_PushArgumentInt(NWNX_Weapon, sFunc, nBaseItem);

    NWNX_CallFunction(NWNX_Weapon, sFunc);
}

void NWNX_Weapon_SetEpicWeaponDevastatingCriticalFeat(int nBaseItem, int nFeat)
{
    string sFunc = "SetEpicWeaponDevastatingCriticalFeat";

    NWNX_PushArgumentInt(NWNX_Weapon, sFunc, nFeat);
    NWNX_PushArgumentInt(NWNX_Weapon, sFunc, nBaseItem);

    NWNX_CallFunction(NWNX_Weapon, sFunc);
}

void NWNX_Weapon_SetWeaponOfChoiceFeat(int nBaseItem, int nFeat)
{
    string sFunc = "SetWeaponOfChoiceFeat";

    NWNX_PushArgumentInt(NWNX_Weapon, sFunc, nFeat);
    NWNX_PushArgumentInt(NWNX_Weapon, sFunc, nBaseItem);

    NWNX_CallFunction(NWNX_Weapon, sFunc);
}

void NWNX_Weapon_SetOption(int nOption, int nVal)
{
    string sFunc = "SetOption";

    NWNX_PushArgumentInt(NWNX_Weapon, sFunc, nVal);
    NWNX_PushArgumentInt(NWNX_Weapon, sFunc, nOption);

    NWNX_CallFunction(NWNX_Weapon, sFunc);
}

void NWNX_Weapon_SetDevastatingCritalEventScript(string sScript)
{
    string sFunc = "SetDevastatingCritalEventScript";

    NWNX_PushArgumentString(NWNX_Weapon, sFunc, sScript);

    NWNX_CallFunction(NWNX_Weapon, sFunc);
}

void NWNX_Weapon_BypassDevastatingCritical()
{
    string sFunc = "SetEventData";

    NWNX_PushArgumentInt(NWNX_Weapon, sFunc, 1);
    NWNX_PushArgumentInt(NWNX_Weapon, sFunc, NWNX_WEAPON_SETDATA_DC_BYPASS);

    NWNX_CallFunction(NWNX_Weapon, sFunc);
}

object NWNX_Weapon_GetDevastatingCritalEventWeapon()
{
    string sFunc = "GetEventData";

    NWNX_PushArgumentInt(NWNX_Weapon, sFunc, NWNX_WEAPON_GETDATA_DC_WEAPON);

    NWNX_CallFunction(NWNX_Weapon, sFunc);
    return NWNX_GetReturnValueObject(NWNX_Weapon, sFunc);
}

object NWNX_Weapon_GetDevastatingCritalEventTarget()
{
    string sFunc = "GetEventData";

    NWNX_PushArgumentInt(NWNX_Weapon, sFunc, NWNX_WEAPON_GETDATA_DC_TARGET);

    NWNX_CallFunction(NWNX_Weapon, sFunc);

    return NWNX_GetReturnValueObject(NWNX_Weapon, sFunc);
}

int NWNX_Weapon_GetDevastatingCritalEventDamage()
{
    string sFunc = "GetEventData";

    NWNX_PushArgumentInt(NWNX_Weapon, sFunc, NWNX_WEAPON_GETDATA_DC_DAMAGE);

    NWNX_CallFunction(NWNX_Weapon, sFunc);

    return NWNX_GetReturnValueInt(NWNX_Weapon, sFunc);
}
