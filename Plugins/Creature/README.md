@page creature Readme
@ingroup creature

Functions exposing additional creature properties.

## Environment Variables

* `NWNX_CREATURE_NOSTACK_*`: See below.
* `NWNX_CREATURE_NOSTACK_DEFAULT_TYPE`: Between 0 and 10. See below.
* `NWNX_CREATURE_NOSTACK_ALWAYS_STACK_PENALTIES`: true or false. Defaults to false.

### NWNX_CREATURE_NOSTACK_*

The following environment variables are available.

| ENV VAR | Description |
|---|----|
| NWNX_CREATURE_NOSTACK_ABILITY | Controls whether ability scores should stack or not |
| NWNX_CREATURE_NOSTACK_SKILL | Controls whether skill bonuses should stack or not |
| NWNX_CREATURE_NOSTACK_SAVINGTHROW | Controls whether saving throw bonuses should stack or not |
| NWNX_CREATURE_NOSTACK_ATTACKBONUS | Controls whether attack bonuses should stack or not |

Each of the variables can take one of the following values.

| Value | Description |
|---:|----|
| 0 | Default value, vanilla behavior. |
| 1 | It will prevent any kind of stacking of properties. Only the highest effect will be used. |
| 2 | It will allow both the highest item effect and the highest spell effect. |
| 3 | It will only prevent stacking of effects from items. Spell effects will stack as usual. |
| 4 | Stacking will be determined by effect type that can be set using NWscript functions. |

### NWNX_CREATURE_NOSTACK_DEFAULT_TYPE
This variable takes one of the following values, assigning all effects this modifier type by default.
This is used only when mode is set to 4. Per-spell overrides can be defined using the
`NWNX_Creature_SetSpellBonusType(int spellId, int type)` function. Effects of different types
stack with each other but only circumstance bonuses stack with effects of the same type.

Feats and other spell-like effects use spellIds from spells.2da. Item effects will always use the default type.

| Value | Type |
|---:|----|
| 0 | Enhancement bonus, default value. |
| 1 | Circumstance bonus (stacks). |
| 2 | Competence bonus. |
| 3 | Insight bonus. |
| 4 | Luck bonus. |
| 5 | Morale bonus. |
| 6 | Profane bonus. |
| 7 | Resistance bonus. |
| 8 | Sacred bonus. |
| 9 | Custom bonus. |
| 10 | Custom bonus 2. |