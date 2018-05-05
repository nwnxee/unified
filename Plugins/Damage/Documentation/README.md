# Damage Plugin Reference

Ported form nwnx2 plugin from Baaleos.

## Environment Variables

None.

## Description

This plugin allows to run a script just before a damage is applied to a creature, and allows to modify the amount and type of the damage. 

For this plugin to work you have to create a script and associate it to the "OnApplyDamage" event (see the example below) this should be done on the OnModuleLoad event of your module. 

Note that the immunities and damage reduction of the creature have been already taken into account when your script is called.

## Example

On Module Load event example:

```C
#include "nwnx_damage"

void main()
{
   NWNX_Weapon_SetDamageEventScript("_on_damage"); // This is the script that will be called
}
```

"_on_damage" script example:

```C
#include "nwnx_damage"

void main()
{
    struct NWNX_Damage_DamageEventData data;
     
    // Get all the data of the damage event
    data = NWNX_Damage_GetDamageEventData(); 
    
    object oDamager = data.oDamager; // The damager
    object oTarget = OBJECT_SELF;    // The creature receiving the damage

    // Let send the damage amounts and types to the Damager
    SendMessageToPC(oDamager, "iBludgeoning: " + IntToString(data.iBludgeoning));
    SendMessageToPC(oDamager, "iPierce: " + IntToString(data.iPierce));
    SendMessageToPC(oDamager, "iSlash: " + IntToString(data.iSlash));
    SendMessageToPC(oDamager, "iMagical: " + IntToString(data.iMagical));
    SendMessageToPC(oDamager, "iAcid: " + IntToString(data.iAcid));
    SendMessageToPC(oDamager, "iCold: " + IntToString(data.iCold));
    SendMessageToPC(oDamager, "iDivine: " + IntToString(data.iDivine));
    SendMessageToPC(oDamager, "iElectrical: " + IntToString(data.iElectrical));
    SendMessageToPC(oDamager, "iFire: " + IntToString(data.iFire));
    SendMessageToPC(oDamager, "iNegative: " + IntToString(data.iNegative));
    SendMessageToPC(oDamager, "iPositive: " + IntToString(data.iPositive));
    SendMessageToPC(oDamager, "iSonic: " + IntToString(data.iSonic));
    SendMessageToPC(oDamager, "iBase: " + IntToString(data.iBase));

    // Let say I want all creatures that have certain local int to be inmune to fire
    // and I want to see on the log that the creature received 0 damage form fire
    if(GetLocalInt(oTarget,"I_M_FIRE_ELEMENTAL"))
        data.iFire = 0; // 

    // Let say I want all creatures that have certain local int to be inmune to cold
    // this time I don't want to see anything on the log about ICE damage
    if(GetLocalInt(oTarget,"I_M_ICE_ELEMENTAL"))
        data.iCold = -1;
    
    // So:
    //  - Set the numbers to -1 to hide them from the combat log
    //  - Set them to 0 to have them reported as 0
    //  - Set them to other positive numbers to change the damage values as you see fit.
	
        
    // Send the modfied damages to nwnx
    NWNX_Damage_SetDamageEventData(data);
}
