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
