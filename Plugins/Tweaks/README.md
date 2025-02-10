@addtogroup tweaks Tweaks
@page tweaks Readme
@ingroup tweaks

Tweaks stuff. See below.

## Environment Variables

| Variable Name | Value | Notes |
| ------------- | ----- | ----- |
| `NWNX_TWEAKS_HIDE_CLASSES_ON_CHAR_LIST` | true or false | Hides the classes of players on the loginscreen playerlist. |
| `NWNX_TWEAKS_PLAYER_DYING_HP_LIMIT` | Between 0 and -127 | Changes the hp limit where a creature is considered to be dying. |
| `NWNX_TWEAKS_DISABLE_PAUSE` | true or false | Disables DM pause. |
| `NWNX_TWEAKS_DISABLE_QUICKSAVE` | true or false | Disables DM quicksave. |
| `NWNX_TWEAKS_COMPARE_VARIABLES_WHEN_MERGING` | true or false | When trying to merge items, local variables are also considered. |
| `NWNX_TWEAKS_PARRY_ALL_ATTACKS` | true or false | Removes the number of parried attacks per round limit. |
| `NWNX_TWEAKS_SNEAK_ATTACK_IGNORE_CRIT_IMMUNITY` | true or false | Allow sneakattacks on creatures that are immune to critical hits. |
| `NWNX_TWEAKS_PRESERVE_DEPLETED_ITEMS` | true or false | Items that run out of charges are not destroyed. |
| `NWNX_TWEAKS_HIDE_PLAYERS_ON_CHAR_LIST` | between 1 and 3 | See [here](https://github.com/nwnxee/unified/tree/master/Plugins/Tweaks#nwnx_tweaks_hide_players_on_char_list). |
| `NWNX_TWEAKS_DISABLE_MONK_ABILITIES_WHEN_POLYMORPHED` | true or false | Disables monk abilities (ac, speed, etc) when polymorphed. |
| `NWNX_TWEAKS_STRINGTOINT_BASE_TO_AUTO` | true or false | Changes the base of the StringToInt() nwscript function from base10 to automatic. |
| `NWNX_TWEAKS_DEAD_CREATURES_TRIGGER_ON_AREA_EXIT` | true or false | Dead creatures will fire the on area exit event. |
| `NWNX_TWEAKS_PRESERVE_ACTIONS_ON_DM_POSSESS` | true or false | DMs possessing a creature will not clear their actions. |
| `NWNX_TWEAKS_FIX_GREATER_SANCTUARY_BUG` | true or false | Fixes a bug with greater sanctuary. |
| `NWNX_TWEAKS_ITEM_CHARGES_COST_MODE` | Between 1 and 3 | See [here](https://github.com/nwnxee/unified/tree/master/Plugins/Tweaks#nwnx_tweaks_item_charges_cost_mode). |
| `NWNX_TWEAKS_FIX_DISPEL_EFFECT_LEVELS` | true or false | Fixes dispel checks vs. effects created by deleted objects. |
| `NWNX_TWEAKS_ADD_PRESTIGECLASS_CASTER_LEVELS` | true or false | Adds prestige class levels to caster level. |
| `NWNX_TWEAKS_FIX_UNLIMITED_POTIONS_BUG` | true or false | Fixes a bug where scrolls/potions could have unlimited uses. |
| `NWNX_TWEAKS_UNHARDCODE_SHIELDS` | true or false | baseitems.2da will be used to define shield AC for shields and shield-like items. |
| `NWNX_TWEAKS_BLOCK_DM_SPAWNITEM` | true or false | Disables the dm_spawnitem console command. |
| `NWNX_TWEAKS_FIX_ARMOR_DEX_BONUS_UNDER_ONE` | true or false | Allows armor with a max DEX bonus of under 1. |
| `NWNX_TWEAKS_CLEAR_SPELL_EFFECTS_ON_TURDS` | true or false | Effects on logged out player characters will be removed when a caster rests. |
| `NWNX_TWEAKS_ALWAYS_RETURN_FULL_DEX_STAT` | true or false | Creatures will always have their full dex states, even when immobilized/entangled. |
| `NWNX_TWEAKS_DISPLAY_NUM_ATTACKS_OVERRIDE_IN_CHARACTER_SHEET` | true or false | The number of attacks per round overridden by SetBaseAttackBonus() will show on the character sheet. |
| `NWNX_TWEAKS_TURD_BY_CDKEY` | true or false | TURDs are associated by CDKey/CharacterName instead of PlayerName/CharacterName. Pass the CDKey instead of PlayerName when calling NWNX_Administration_DeleteTURD() |
| `NWNX_TWEAKS_LANGUAGE_OVERRIDE` | between 1 and 5, or between 128 and 131 | See [here](https://github.com/nwnxee/unified/tree/master/Plugins/Tweaks#nwnx_tweaks_language_override). |
| `NWNX_TWEAKS_SEND_TLK_OVERRIDE_BEFORE_CHARGEN` | true or false | TlkTable entries overridden by SetTlkOverride() will be sent before Character Generation. |
| `NWNX_TWEAKS_RETAIN_LOCAL_VARIABLES_ON_ITEM_SPLIT` | true or false | When splitting an item, local variables will be copied. |
| `NWNX_TWEAKS_PREVENT_ATTACK_BONUS_BYPASSING_REDUCTION` | true or false | Prevents attack bonus effects from bypassing damage reductions. |
| `NWNX_TWEAKS_MATERIAL_NAME_NULL_IS_ALL` | true or false | Makes SetMaterialShaderParamXxx() functions take `sMaterial=""` to mean all materials. |
| `NWNX_TWEAKS_HIDE_HARDCODED_ITEM_VFX` | int | See [here](https://github.com/nwnxee/unified/tree/master/Plugins/Tweaks#nwnx_tweaks_hide_hardcoded_item_vfx). |
| `NWNX_TWEAKS_CANUSEITEM_CHECK_ILR_FOR_HENCHMEN` | true or false | The CNWSCreature::CanUseItem() function will also check ILR for Henchmen. |
| `NWNX_TWEAKS_FIX_TRIGGER_ENTER_DETECTION` | true or false | Adds an additional bounds check for triggers to fix a trigger detection bug. |
| `NWNX_TWEAKS_UNCAP_DAMAGE_RESISTANCE_DAMAGE_FLAGS` | true or false | Uncaps the compounded damage flags of EffectDamageResistance. |
| `NWNX_TWEAKS_RANGED_WEAPONS_USE_ON_HIT_EFFECT_ITEM_PROPERTIES` | true or false | Makes all bows, crossbows, and slings use On Hit: Effect item properties (in addition to their ammunition). |
| `NWNX_TWEAKS_RANGED_WEAPONS_USE_ON_HIT_CAST_SPELL_ITEM_PROPERTIES` | true or false | Makes all bows, crossbows, and slings use On Hit: Cast Spell item properties (in addition to their ammunition). |
| `NWNX_TWEAKS_CAST_ALL_ON_HIT_CAST_SPELL_ITEM_PROPERTIES` | true or false | Casts all On Hit: Cast Spell item properties on hit, instead of only the first property. |
| `NWNX_TWEAKS_SETAREA_CALLS_SETPOSITION` | true or false | If enabled, a creature getting added to an area will fire the `NWNX_ON_MATERIALCHANGE_*` and `NWNX_ON_CREATURE_TILE_CHANGE_*` events. |
| `NWNX_TWEAKS_FIRE_EQUIP_EVENTS_FOR_ALL_CREATURES` | true or false | The module OnPlayerEquipItem and OnPlayerUnEquipItem events are fired for all creatures |
| `NWNX_TWEAKS_DONT_DELAY_EQUIP_EVENT` | true or false | Fixes Unequip/Equip events being out of sync if an item is equipped/unequipped multiple times per server tick |
| `NWNX_TWEAKS_CUTSCENE_MODE_NO_TURD` | true or false | SetCutsceneMode() will not cause a TURD to be dropped. |
| `NWNX_TWEAKS_CAN_USE_ITEMS_WHILE_POLYMORPHED` | true or false | Allow all items to be used while polymorphed. |
| `NWNX_TWEAKS_RESIST_ENERGY_STACKS_WITH_EPIC_ENERGY_RESISTANCE` | true or false | Resist Energy feats stack with Epic Energy Resistance. |
| `NWNX_TWEAKS_UNHARDCODE_SPECIAL_ABILITY_TARGET_TYPE` | true or false | Allows special abilities to be used on target types other than creatures. |

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

### NWNX_TWEAKS_LANGUAGE_OVERRIDE

| Value | Description |
|---:|----|
| 1 | French |
| 2 | German |
| 3 | Italian |
| 4 | Spanish |
| 5 | Polish |
| 6 | Italian |
| 128 | Korean |
| 129 | Chinese traditional |
| 130 | Chinese simplified |
| 131 | Japanese |

### NWNX_TWEAKS_HIDE_HARDCODED_ITEM_VFX

Add the numbers of the VFX you want to hide. For example to hide all Elemental Damage Bonus, Holy Avenger and OnHitVorpal visual effects you'd set the environment variable to 318 (2 + 4 + 8 + 16 + 32 + 256)

Specific VFX values in order of priority:

| Value | Description |
|---:|----|
| 1 | Manual VFX (ItemPropertyVisualEffect) |
| 2 | (Elemental) DamageBonus |
| 4 | (Elemental) DamageBonusVSAlignmentGroup |
| 8 | (Elemental) DamageBonusVSRacialGroup |
| 16 | (Elemental) DamageBonusVSSpecificAlignment |
| 32 | HolyAvenger |
| 64 | VampiricRegeneration |
| 128 | OnHitLevelDrain |
| 256 | OnHitVorpal |
| 512 | OnHitWounding |
| 1024 | (Good/Evil) DamageBonusVSAlignmentGroup |
| 2048 | (Good/Evil) AttackBonusVSAlignmentGroup |
| 4096 | (Good/Evil) EnhancementBonusVSAlignmentGroup |
| 8192 | (Good/Evil) DamageBonusVSSpecificAlignment |
| 16384 | (Good/Evil) AttackBonusVSSpecificAlignment |
| 32768 | (Good/Evil) EnhancementBonusVSSpecificAlignment |

Some values for convenience:

| Value | Description |
|---:|----|
| 30 | All Elemental Damage Bonus |
| 896 | All OnHit Properties |
| 7168 | All Good/Evil vs AlignmentGroup |
| 57344 | All Good/Evil vs SpecificAlignment |
| 65535 | Hide All VFX |
