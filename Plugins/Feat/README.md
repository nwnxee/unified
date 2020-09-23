@page feat Readme
@ingroup feat 

This plugin allows for the builder to define many traits for feats.

## Environmental Variables

`NWNX_FEAT_SHOW_EFFECT_ICON` - Helpful when debugging, this shows the effect's icon (the red and green squares). Some builders may even wish this permanently.

## Setup
Adding new feats is beyond the scope of this documentation. The builder should know how to add new feats by adding a new entry in the `feat.2da` as well as adding the appropriate TLK reference identifiers for that new feat then adjusting the appropriate columns for that feat.

Once your feat has been added (or it's also fine to modify existing feats) builders run the NWNX_Feat_SetFeatModifier() as illustrated below.

The **NWNX_Feat plugin does not provide modifications to skill ranks**, use the NWNX_SkillRanks plugin for changing those.

## Feat Modifiers

These commands should be ran `on_module_load`.

* [AB](#ab)
* [ABILITY](#ability)
* [ABVSRACE](#abvsrace)
* [AC](#ac)
* [ACVSRACE](#acvsrace)
* [ARCANESPELLFAILURE](#arcanespellfailure)
* [CONCEALMENT](#concealment)
* [DMGREDUCTION](#dmgreduction)
* [DMGRESIST](#dmgresist)
* [DMGIMMUNITY](#dmgimmunity)
* [IMMUNITY](#immunity)
* [MOVEMENTSPEED](#movementspeed)
* [REGENERATION](#regeneration)
* [SAVE](#save)
* [SAVEVSRACE](#savevsrace)
* [SAVEVSTYPE](#savevstype)
* [SAVEVSTYPERACE](#savevstyperace)
* [SPELLIMMUNITY](#spellimmunity)
* [SRCHARGEN](#srchargen)
* [SRINCLEVEL](#srinclevel)

***

### AB
The `AB` entry is used to modify an attack bonus. Note: this is not a change to the base attack bonus, it's added on top of that.

* Param1 = Modifier value (+/-)

##### Example script on_module_load
```c
NWNX_Feat_SetFeatModifier(2150, NWNX_FEAT_MODIFIER_AB, 1);
```
***
### ABILITY
The `ABILITY` entry is used to modify an ability bonus.

* Param1 = ABILITY_ constant
* Param2 = Modifier value (+/-)

##### Example script on_module_load
```c
NWNX_Feat_SetFeatModifier(2150, NWNX_FEAT_MODIFIER_ABILITY, ABILITY_STRENGTH, 1);
```
***
### ABVSRACE
The `ABVSRACE` entry is used to modify the attack bonus versus another race.

* Param1 = Racial ID from racialtypes.2da
* Param2 = Modifier value (+/-)

##### Example script on_module_load
```c
NWNX_Feat_SetFeatModifier(2150, NWNX_FEAT_MODIFIER_ABVSRACE, RACIAL_TYPE_DRAGON, 3);
```
***
### AC
The `AC` entry is used to modify the base AC.

* Param1 = Modifier value (+/-)

##### Example script on_module_load
```c
NWNX_Feat_SetFeatModifier(2150, NWNX_FEAT_MODIFIER_AC, 1);
```
***
### ACVSRACE
The `ACVSRACE` entry is used to modify the base AC versus another race.

* Param1 = Racial ID from racialtypes.2da
* Param2 = Modifier value (+/-)

##### Example script on_module_load
```c
NWNX_Feat_SetFeatModifier(2150, NWNX_FEAT_MODIFIER_ACVSRACE, RACIAL_TYPE_DRAGON, 4);
```
***
### ARCANESPELLFAILURE
The `ARCANESPELLFAILURE` can modify the arcane spell failure for the creature.

* Param1 = The percentage change to their failure (-100/+100)

##### Example script on_module_load
```c
NWNX_Feat_SetFeatModifier(2150, NWNX_FEAT_MODIFIER_ARCANESPELLFAILURE, -30);
```
***
### CONCEALMENT
The `CONCEALMENT` entry is used to grant an inate concealment.

* Param1 = Modifier value (1-100)

##### Example script on_module_load
```c
NWNX_Feat_SetFeatModifier(2150, NWNX_FEAT_MODIFIER_CONCEALMENT, 30);
```
***
### DMGREDUCTION
The `DMGREDUCTION` entry gives an inate damage reduction

* Param1 = Points to soak (+)
* Param2 = Level of soak (+)

##### Example script on_module_load
```c
NWNX_Feat_SetFeatModifier(2150, NWNX_FEAT_MODIFIER_DMGREDUCTION, 5, 5);
NWNX_Feat_SetFeatModifier(2150, NWNX_FEAT_MODIFIER_DMGREDUCTION, 10, 4);
```
***
### DMGRESIST
The `DMGRESIST` entry gives an inate resistance to damage types

* Param1 = The damage type, can be a single Damage Type integer or multiple Damage Type integers summed. You can also just do each on its own line if you'd prefer. Hex can be used for the scripting method if preferred.
* Param2 = Points to resist (+)

##### Example script on_module_load
```c
NWNX_Feat_SetFeatModifier(2150, NWNX_FEAT_MODIFIER_DMGRESIST, DAMAGE_TYPE_FIRE, 10);
NWNX_Feat_SetFeatModifier(2150, NWNX_FEAT_MODIFIER_DMGRESIST, DAMAGE_TYPE_FIRE & DAMAGE_TYPE_COLD, 5);
```
***
### DMGIMMUNITY
The `DMGIMMUNITY` entry gives an inate immunity to damage types

* Param1 = The damage type, can be a single Damage Type integer or multiple Damage Type integers summed. You can also just do each on its own line if you'd prefer. Hex can be used for the scripting method if preferred.
* Param2 = Percentage to resist (+/-)

##### Example script on_module_load
```c
NWNX_Feat_SetFeatModifier(2150, NWNX_FEAT_MODIFIER_DMGIMMUNITY, DAMAGE_TYPE_FIRE, 100);
NWNX_Feat_SetFeatModifier(2150, NWNX_FEAT_MODIFIER_DMGIMMUNITY, DAMAGE_TYPE_ACID, -50);
```
### IMMUNITY
The `IMMUNITY` entry is used to grant a total immunity to a variety of effects.

* Param1 = The IMMUNITY_TYPE_ constant value

##### Example script on_module_load
```c
NWNX_Feat_SetFeatModifier(2150, NWNX_FEAT_MODIFIER_IMMUNITY, IMMUNITY_TYPE_FEAR);
```
***
### MOVEMENTSPEED
The `MOVEMENTSPEED` can modify the speed by default.

* Param1 = The percentage change to their speed (-99/+99)

##### Example script on_module_load
```c
NWNX_Feat_SetFeatModifier(2150, NWNX_FEAT_MODIFIER_MOVEMENTSPEED, 33);
```
***
### REGENERATION
The `REGENERATION` entry is used to grant inate regeneration.

* Param1 = How many hitpoints to increase (+)
* Param2 = How often in seconds to increase the hitpoints (+)

##### Example script on_module_load
```c
NWNX_Feat_SetFeatModifier(2150, NWNX_FEAT_MODIFIER_REGENERATION, 2, 6);
```
***
### SAVE
The `SAVE` entry is used to modify base save values.

* Param1 = 0-3 meaning SAVING_THROW_ALL, SAVING_THROW_FORT, SAVING_THROW_REFLEX or SAVING_THROW_WILL
* Param2 = Modifier value (+/-)

##### Example script on_module_load
```c
NWNX_Feat_SetFeatModifier(2150, NWNX_FEAT_MODIFIER_SAVE, SAVING_THROW_FORT, -2);
```
***
### SAVEVSRACE
The `SAVEVSRACE` entry is used to modify base save values vs a specific race. Param1 is the Save constant ID and param2 is the target race constant ID and param3 is the modifier.

* Param1 = 0-3 meaning SAVING_THROW_ALL, SAVING_THROW_FORT, SAVING_THROW_REFLEX or SAVING_THROW_WILL
* Param2 = Racial ID from racialtypes.2da
* Param3 = Modifier value (+/-)

##### Example script on_module_load
```c
NWNX_Feat_SetFeatModifier(2150, NWNX_FEAT_MODIFIER_SAVEVSRACE, SAVING_THROW_ALL, RACIAL_TYPE_UNDEAD, 5);
```
***
### SAVEVSTYPE
The `SAVEVSTYPE` entry is used to modify base save values vs a specific type. Param1 is the Save constant ID and param2 is the Saving Throw Type constant ID and param3 is the modifier.

* Param1 = 0-3 meaning SAVING_THROW_ALL, SAVING_THROW_FORT, SAVING_THROW_REFLEX or SAVING_THROW_WILL
* Param2 = A SAVING_THROW_TYPE_ constant
* Param3 = Modifier value (+/-)

##### Example script on_module_load
```c
NWNX_Feat_SetFeatModifier(2150, NWNX_FEAT_MODIFIER_SAVEVSTYPE, SAVING_THROW_REFLEX, SAVING_THROW_TYPE_TRAP, 3);
```
***
### SAVEVSTYPERACE
The `SAVEVSTYPERACE` entry is used to modify base save values vs a specific type versus a specific race. Param1 is the Save constant ID and param2 is the Saving Throw Type constant ID and param3 is the Racial Type constant ID and param4 is the modifier.

* Param1 = 0-3 meaning SAVING_THROW_ALL, SAVING_THROW_FORT, SAVING_THROW_REFLEX or SAVING_THROW_WILL
* Param2 = A SAVING_THROW_TYPE_ constant
* Param3 = A RACIAL_TYPE_ constant
* Param4 = Modifier value (+/-)

##### Example script on_module_load
```c
NWNX_Feat_SetFeatModifier(2150, NWNX_FEAT_MODIFIER_SAVEVSTYPE, SAVING_THROW_ALL, SAVING_THROW_TYPE_SPELLS, RACIAL_TYPE_DRAGON, 3);
```
***
### SPELLIMMUNITY
The `SPELLIMMUNITY` entry is used to grant a total immunity to specific spells. Note: Only spells that can be resisted can have immunities.

##### Example script on_module_load
```c
NWNX_Feat_SetFeatModifier(2150, NWNX_FEAT_MODIFIER_SPELLIMMUNITY, SPELL_HORRID_WILTING);
```
***
### SRCHARGEN
The `SRCHARGEN` entry is used to award a default spell resistance on character creation.

* Param1 = Modifier value (+)
* Param2 (Optional) = Maximum value all Spell Resistance racial values can reach

##### Example script on_module_load
```c
NWNX_Feat_SetFeatModifier(2150, NWNX_FEAT_MODIFIER_SRCHARGEN, 10, 36);
```
***
### SRINCLEVEL
The `SRINCLEVEL` entry is used to award a spell resistance racial bonus as the creature's level increases.

* Param1 = Amount of points to increment (+)
* Param2 = Level per increment (+)
* Param3 = Level at which the incremental gains begin (+)

##### Example script on_module_load
```c
NWNX_Feat_SetFeatModifier(2150, NWNX_FEAT_MODIFIER_SRINCLEVEL, 1, 1, 6);
```
