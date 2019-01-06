# Tweaks Plugin Reference

## Description

Tweaks stuff. See below.

## Environment Variables

* `NWNX_TWEAKS_HIDE_CLASSES_ON_CHAR_LIST`: true or false
* `NWNX_TWEAKS_PLAYER_DYING_HP_LIMIT`: Between 0 and -127
* `NWNX_TWEAKS_DISABLE_PAUSE`: true or false
* `NWNX_TWEAKS_DISABLE_QUICKSAVE`: true or false
* `NWNX_TWEAKS_COMPARE_VARIABLES_WHEN_MERGING`: true or false
* `NWNX_TWEAKS_PARRY_ALL_ATTACKS`: true or false
* `NWNX_TWEAKS_SNEAK_ATTACK_IGNORE_CRIT_IMMUNITY`: true or false
* `NWNX_TWEAKS_PRESERVE_DEPLETED_ITEMS`: true or false
* `NWNX_TWEAKS_HIDE_ITEM_FEEDBACK_MESSAGES`: 0, 1 or 2

## Hide Item Feedback Messages Notes

This tweak will hide the following messages from the combat log:

* Acquired Item: 
* Lost Item:
* Armor/Shield Penalty
* Weapon equipped as one handed weapon
* Weapon equipped as two handed weapon
* Equipped item swapped out

`NWNX_TWEAKS_HIDE_ITEM_FEEDBACK_MESSAGES` has two modes:

* `1` will always suppress the item feedback messages.
* `2` will only suppress the item feedback messages if the player has `SetLocalInt(oPlayer, "NWNX_HIDE_ITEM_FEEDBACK_MESSAGES", TRUE)` set on them.

If you only want to hide the lost/acquired messages you can set the following optional environment variable to true:

* `NWNX_TWEAKS_ONLY_HIDE_LOST_ACQUIRED_MESSAGES`: true or false
