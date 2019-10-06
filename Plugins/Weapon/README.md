# Weapon Plugin Reference

## Environment Variables

None.

## Description

Functions exposing additional weapon properties.

Allows modifying which feats count as which for the weapon feats. Can be used to add feats like WEAPON_FOCUS_* to custom weapons. All you have to do is:

1. Create a custom feat and add it to your hak.
2. Create the new base item ID for your new weapon or use one that already exists.
3. On the OnModuleLoad event script of your module define the association between the weapon and the feat using the functions defined in the _nwnx_weapon_ script

For example, if you added the FEAT_WEAPON_FOCUS_KATAR on line 3000 of your _feat.2da_ and you added the new BASE_ITEM_KATAR on line 310 of your _baseitems.2da_, in the OnModuleLoad script just add (don't forget to include the _nwnx_weapon_ script) :

```C
int FEAT_WEAPON_FOCUS_KATAR = 3000; 
int BASE_ITEM_KATAR = 310;
NWNX_Weapon_SetWeaponFocusFeat(BASE_ITEM_KATAR, FEAT_WEAPON_FOCUS_KATAR);
```
## Available functions

Script function | Description  
----------------|-------------
NWNX_Weapon_SetWeaponFocusFeat() | Associate a weapon focus feat to a weapon 
NWNX_Weapon_SetWeaponFinesseSize() | Define the required creature size for a weapon in order to be finessable
NWNX_Weapon_SetWeaponUnarmed() | Set the weapon to be considered unarmed regarding the finesse feat
NWNX_Weapon_SetWeaponImprovedCriticalFeat() | Associate a weapon improved critical feat to a weapon 
NWNX_Weapon_SetWeaponSpecializationFeat() | Associate a weapon specialization feat to a weapon 
NWNX_Weapon_SetEpicWeaponFocusFeat() | Associate an epic weapon focus feat to a weapon 
NWNX_Weapon_SetEpicWeaponSpecializationFeat() | Associate an epic weapon specialization feat to a weapon 
NWNX_Weapon_SetEpicWeaponOverwhelmingCriticalFeat() | Associate an epic weapon overwhelming critical feat to a weapon 
NWNX_Weapon_SetEpicWeaponDevastatingCriticalFeat() | Associate an epic weapon devastating critical feat to a weapon 
NWNX_Weapon_SetWeaponOfChoiceFeat() | Associate a weapon of choice feat to a weapon 
NWNX_Weapon_SetGreaterWeaponFocusFeat() | Associate a greater weapon focus feat (default: +1 attack bonus) to a weapon
NWNX_Weapon_SetGreaterWeaponSpecializationFeat() | Associate a greater weapon specialization feat (default: +2 damage bonus) to a weapon
NWNX_Weapon_SetWeaponIsMonkWeapon() | Set the weapon to be considered a monk weapon
NWNX_Weapon_SetOption() | Set different options of the plugin
NWNX_Weapon_SetDevastatingCriticalEventScript() | Set a script to be called when a devastating critical event occurs
NWNX_Weapon_GetDevastatingCriticalEventData() | Must be called inside the devastating critical event script. Returns a structure with the data of the devastating critical event (weapon, target and damage)
NWNX_Weapon_BypassDevastatingCritical() | Must be called inside the devastating critical event script. If called, no devastating critical will occur.

The NWNX_Weapon_SetOption() function can be used to define the attack and damage bonusses of the Greater Weapon Focus Feats and Greater Weapon Specialization Feats respectively. 

## Example for Critical Event Script

This script just prints some info to the log and then bypasses the devastating critical 50% of the time. You have to set your script with NWNX_Weapon_SetDevastatingCriticalEventScript() (in the OnModuleLoad script for example)

```cpp
#include "nwnx_weapon"

void main()
{
   struct NWNX_Weapon_DevastatingCriticalEvent_Data data = NWNX_Weapon_GetDevastatingCriticalEventData();
   object oAttacker = OBJECT_SELF;
   object oWeapon = data.oWeapon;
   object oTarget = data.oTarget;
   int nDamage = data.nDamage;

   WriteTimestampedLogEntry("Devastating Critical Event: Attaker: " + GetName(oAttacker) +
      ", Weapon: "+ GetName(oWeapon) +
      ", Target: "+ GetName(oTarget) +
      ", Damage: " + IntToString(nDamage));

   if(d100()>50)
   {
      NWNX_Weapon_BypassDevastatingCritical();
      WriteTimestampedLogEntry("Devastating Critical Bypassed");
   }
}```
