@page nostack Readme
@ingroup nostack

Functions and variables to control stacking of multiple bonuses of the same type.

## Environment Variables

* `NWNX_NOSTACK_*`: See below.
* `NWNX_NOSTACK_SPELL_DEFAULT_TYPE`: Between 0 and 20. See below.
* `NWNX_NOSTACK_ITEM_DEFAULT_TYPE`: Between 0 and 20. See below.
* `NWNX_NOSTACK_ALWAYS_STACK_PENALTIES`: true or false. Defaults to false.
* `NWNX_NOSTACK_SEPARATE_INVALID_OID_EFFECTS`: true or false. Defaults to false.
* `NWNX_NOSTACK_IGNORE_SUPERNATURAL_INNATE`: true or false. Defaults to false.

### NWNX_NOSTACK_*

The following environment variables are available.

| ENV VAR | Description |
|---|----|
| NWNX_NOSTACK_ABILITY | Controls whether ability scores should stack or not |
| NWNX_NOSTACK_SKILL | Controls whether skill bonuses should stack or not |
| NWNX_NOSTACK_SAVINGTHROW | Controls whether saving throw bonuses should stack or not |
| NWNX_NOSTACK_ATTACKBONUS | Controls whether attack bonuses should stack or not |

Each of the variables can take one of the following values.

| Value | Description |
|---:|----|
| 0 | Default value, vanilla behavior. |
| 1 | It will prevent any kind of stacking of properties. Only the highest effect will be used. |
| 2 | It will allow both the highest item effect and the highest spell effect. |
| 3 | It will only prevent stacking of effects from items. Spell effects will stack as usual. |
| 4 | Stacking will be determined by effect type that can be set using NWscript functions. |

### NWNX_NOSTACK_*_DEFAULT_TYPE
This variable takes one of the following values, assigning all effects this modifier type by default.
This is used only when mode is set to 4. Per-spell overrides can be defined using the
`NWNX_NoStack_SetSpellBonusType(int spellId, int type)` function. Effects of different types
stack with each other but only circumstance bonuses stack with effects of the same type.

Feats and other spell-like effects use spellIds from spells.2da to determine the bonus type. Item effects will always use the default type set for all items.

| Value | Type |
|---:|----|
| 0 | Enhancement bonus. Default value for items. |
| 1 | Circumstance bonus (stacks). Default value for spells. |
| 2 | Competence bonus. |
| 3 | Insight bonus. |
| 4 | Luck bonus. |
| 5 | Morale bonus. |
| 6 | Profane bonus. |
| 7 | Resistance bonus. |
| 8 | Sacred bonus. |
| 9-20 | Custom bonus types. |

### NWNX_NOSTACK_SEPARATE_INVALID_OID_EFFECTS
Set this value to true if you are adding effects through scripts that you want to stack with each other.
This is needed because scripted effects, unless created from a spellscript, always have an INVALID_OBJECT creator and a spellId of -1.

This is a quick fix, if you want to control each of the scripted effect types you will need to unpack the effect, set a valid spellId and use the
`SetSpellBonusType()` function to set the bonus for that spellId. The spellId has to be a valid spell, so either reuse one of the existing spells
that don't give a bonus effect (i.e. healing or damaging spells) or add a dummy spell to your spells.2da.

### NWNX_NOSTACK_IGNORE_SUPERNATURAL_INNATE
Set this value to true if you want to ignore your stacking rules for Supernatural Innate effects. This is the type of effect used in the
Race, SkillRanks and Feat plugins.