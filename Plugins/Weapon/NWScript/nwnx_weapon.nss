#include "nwnx"

const string NWNX_Weapon = "NWNX_Weapon";

// Set nFeat as weapon focus feat for nBaseItem
void NWNX_Weapon_SetWeaponFocusFeat(int nBaseItem, int nFeat);

void NWNX_Weapon_SetWeaponFocusFeat(int nBaseItem, int nFeat)
{
    string sFunc = "SetWeaponFocusFeat";
    
    NWNX_PushArgumentInt(NWNX_Weapon, sFunc, nFeat);
    NWNX_PushArgumentInt(NWNX_Weapon, sFunc, nBaseItem);
    
    NWNX_CallFunction(NWNX_Weapon, sFunc);
}

