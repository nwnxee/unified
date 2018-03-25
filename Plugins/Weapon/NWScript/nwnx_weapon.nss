#include "nwnx"

const string NWNX_Weapon = "NWNX_Weapon";

// Set nFeat as weapon focus feat for nBaseItem
void NWNX_Weapon_SetWeaponFocusFeat(int nBaseItem, int nFeat);

// Set required creature size for weapon nBaseItem to be finessable
void NWNX_Weapon_SetWeaponFinesseSize(int nBaseItem, int nSize);

// Set weapon nBaseItem to be considered as unarmed for weapon finesse feat
void NWNX_Weapon_SetWeaponUnarmed(int nBaseItem);

void NWNX_Weapon_SetWeaponFocusFeat(int nBaseItem, int nFeat)
{
    string sFunc = "SetWeaponFocusFeat";
    
    NWNX_PushArgumentInt(NWNX_Weapon, sFunc, nFeat);
    NWNX_PushArgumentInt(NWNX_Weapon, sFunc, nBaseItem);
    
    NWNX_CallFunction(NWNX_Weapon, sFunc);
}

void NWNX_Weapon_SetWeaponFinesseSize(int nBaseItem, int nSize)
{
    string sFunc = "SetWeaponFinessSize";
    
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