@addtogroup tweaks Tweaks
@page tweaks Readme
@ingroup tweaks 

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
* `NWNX_TWEAKS_DISABLE_SHADOWS`: true or false
* `NWNX_TWEAKS_HIDE_DMS_ON_CHAR_LIST`: true or false 
@deprecated Use `NWNX_TWEAKS_HIDE_PLAYERS_ON_CHAR_LIST`

* `NWNX_TWEAKS_HIDE_PLAYERS_ON_CHAR_LIST`: between 1 and 3
* `NWNX_TWEAKS_DISABLE_MONK_ABILITIES_WHEN_POLYMORPHED`: true or false
* `NWNX_TWEAKS_STRINGTOINT_BASE_TO_AUTO`: true or false
* `NWNX_TWEAKS_DEAD_CREATURES_TRIGGER_ON_AREA_EXIT`: true or false
* `NWNX_TWEAKS_PRESERVE_ACTIONS_ON_DM_POSSESS`: true or false
* `NWNX_TWEAKS_FIX_GREATER_SANCTUARY_BUG`: true or false
* `NWNX_TWEAKS_ITEM_CHARGES_COST_MODE`: Between 1 and 3
* `NWNX_TWEAKS_FIX_DISPEL_EFFECT_LEVELS`: true or false
* `NWNX_TWEAKS_ADD_PRESTIGECLASS_CASTER_LEVELS`: true or false
* `NWNX_TWEAKS_FIX_UNLIMITED_POTIONS_BUG`: true or false
* `NWNX_TWEAKS_UNHARDCODE_SHIELDS`: true or false
* `NWNX_TWEAKS_BLOCK_DM_SPAWNITEM`: true or false
* `NWNX_TWEAKS_FIX_ARMOR_DEX_BONUS_UNDER_ONE`: true or false
* `NWNX_TWEAKS_FIX_ITEM_NULLPTR_IN_CITEMREPOSITORY`: true or false
* `NWNX_TWEAKS_CLEAR_SPELL_EFFECTS_ON_TURDS`: true or false
* `NWNX_TWEAKS_ALWAYS_RETURN_FULL_DEX_STAT`: true or false
* `NWNX_TWEAKS_DISPLAY_NUM_ATTACKS_OVERRIDE_IN_CHARACTER_SHEET`: true or false
* `NWNX_TWEAKS_TURD_BY_CDKEY`: true or false
  - Note: pass the CDKey instead of PlayerName when calling NWNX_Administration_DeleteTURD().
  
## Environment variable values

### NWNX_TWEAKS_HIDE_PLAYERS_ON_CHAR_LIST
Values between 1 and 3 are valid. Any of those values will adjust who is shown on the Module Character Listing. Note: DMs always see all PCs and DMs logged in.

| Value | Description |
|---:|----|
| 1 | DMs are hidden on the module character list. |
| 2 | PCs are hidden on the module character list. |
| 3 | Both PCs and DMs are hidden on the module character list. |

### NWNX_TWEAKS_ITEM_CHARGES_COST_MODE
Values between 1 and 3 are valid. Any of those values will adjust the item cost to the old values used in 1.69 for items with 50 charges or less.

| Value | Description |
|---:|----|
| 1 | Cost will be capped at 50 charges. Any charges over 50 won't affect the item cost. |
| 2 | Up to 50 charges the cost will be the same as it was in 1.69. Any charges over 50 will add less value, capping at twice the cost at 250 charges. |
| 3 | Cost will be calculated linearly based on the number of charges the same it was in 1.69, making items with 250 charges 5 times as expensive as 50 charges ones. |
