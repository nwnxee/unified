#include "nwnx"

const string NWNX_Weapon = "NWNX_Weapon";

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


