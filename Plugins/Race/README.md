@page race Readme
@ingroup race 

This plugin allows for the builder to add new races or subraces and define many traits for the races via 2da entry or scripting. This plugin also applies effects, and weapon properties, versus a parent race to effect a child race, as well as effects vs that specific child race.

## Environmental Variables

`NWNX_RACE_SHOW_EFFECT_ICON` - Helpful when debugging, this shows the effect's icon (the red and green squares). Some builders may even wish this permanently.

## Required NWNX Plugins

* @ref skillranks "NWNX_SkillRanks" - Needed if you're modifying skill ranks.
* @ref util "NWNX_Util" - Needed if you're using the 2da method which requires new `NWNX_Util_Get2DARowCount()`.

## Setup
Adding new races is beyond the scope of this documentation. The builder should know how to add new races by adding a new entry in the `racialtypes.2da` as well as adding the appropriate TLK reference identifiers for that new race then adjusting the appropriate columns for their race, including the Ability Score modifications. 

The **NWNX Race plugin does not provide modifications to ability scores**, use the `racialtypes.2da` columns for changing those.


### The 2da Method
To use the 2da method, the builder must create a new column at the end of the `racialtypes.2da` named **RacialModsTable**. This column should then be populated with a string value that references another 2da file in which we will define our racial modifiers. Once that is done the builder needs to **include nwnx_race_2da and make sure to run `NWNX_Race_LoadRacialModifiers()` in their OnModuleLoad script**.

For example, we've inserted a new race called **Aasimar** into `racialtypes.2da` at line 150. In the `RacialModsTable` column we enter **RACEMOD_AASIMAR** (Remember maximum 16 characters, case insensitive)

We will now create and define our `racemod_aasimar.2da` file and enter appropriate lines for each modifier they will receive. The end result will look something like this:

```text
2DA V2.0

    LABEL                       Type            Param1  Param2  Param3
0   Race                        RACE            6       ****    ****
1   ColdElectricalAcidResist    DMGRESIST       272     5       ****
2   CharmPersonImmunity         SPELLIMMUNITY   16      ****    ****
3   DominatePersonImmune        SPELLIMMUNITY   45      ****    ****
4   HoldPersonImmunity          SPELLIMMUNITY   83      ****    ****
5   Spot                        SKILL           17      2       ****
6   Listen                      SKILL           6       2       ****
7   LightFeatUsage              FEATUSAGE       1107    1       10
8   UniversalSaves              SAVE            0       2       ****
```

### The Scripting Method

The scripting method involves running a command for each race and each modifier OnModuleLoad.

The end result for the Aasimar using the script method would be something like:
```c
NWNX_Race_SetRacialModifier(150, NWNX_RACE_MODIFIER_RACE, RACIAL_TYPE_HUMAN);
NWNX_Race_SetRacialModifier(150, NWNX_RACE_MODIFIER_DMGRESIST, 272, 5);
NWNX_Race_SetRacialModifier(150, NWNX_RACE_MODIFIER_SPELLIMMUNITY, 16);
NWNX_Race_SetRacialModifier(150, NWNX_RACE_MODIFIER_SPELLIMMUNITY, 45);
NWNX_Race_SetRacialModifier(150, NWNX_RACE_MODIFIER_SPELLIMMUNITY, 83);
NWNX_Race_SetRacialModifier(150, NWNX_RACE_MODIFIER_SKILL, SKILL_SPOT, 2);
NWNX_Race_SetRacialModifier(150, NWNX_RACE_MODIFIER_SKILL, SKILL_LISTEN, 2);
NWNX_Race_SetRacialModifier(150, NWNX_RACE_MODIFIER_FEATUSAGE, 1107, 1, 10);
NWNX_Race_SetRacialModifier(150, NWNX_RACE_MODIFIER_SAVE, 0, 2);
```

## Racial Modifiers

* [AB](#ab)
* [ABVSRACE](#abvsrace)
* [AC](#ac)
* [ACVSRACE](#acvsrace)
* [CONCEALMENT](#concealment)
* [DMGREDUCTION](#dmgreduction)
* [DMGRESIST](#dmgresist)
* [DMGIMMUNITY](#dmgimmunity)
* [FEAT](#feat)
* [FEATUSAGE](#featusage)
* [IMMUNITY](#immunity)
* [INITIATIVE](#initiative)
* [MOVEMENTSPEED](#movementspeed)
* [RACE](#race)
* [REGENERATION](#regeneration)
* [SAVE](#save)
* [SAVEVSRACE](#savevsrace)
* [SAVEVSTYPE](#savevstype)
* [SKILL](#skill)
* [SPELLIMMUNITY](#spellimmunity)
* [SRCHARGEN](#srchargen)
* [SRINCLEVEL](#srinclevel)

***

### AB
The `AB` entry is used to modify an attack bonus for a race. Note: this is not a change to the base attack bonus, it's added on top of that.

* Param1 = Modifier value (+/-)

##### Example 2da entry
```text
2DA V2.0

     LABEL                    Type            Param1 Param2 Param3
0    InateAB                  AB              1      ****   ****
``` 

##### Example script on_module_load
```c
NWNX_Race_SetRacialModifier(150, NWNX_RACE_MODIFIER_AB, 1);
```
***
### ABVSRACE
The `ABVSRACE` entry is used to modify the attack bonus for a race versus another specific race.

* Param1 = Racial ID from racialtypes.2da
* Param2 = Modifier value (+/-)

##### Example 2da entry
```text
2DA V2.0

     LABEL                    Type            Param1 Param2 Param3
0    DragonAB                 ABVSRACE        11     3      ****
``` 

##### Example script on_module_load
```c
NWNX_Race_SetRacialModifier(150, NWNX_RACE_MODIFIER_ABVSRACE, RACIAL_TYPE_DRAGON, 3);
```
***
### AC
The `AC` entry is used to modify the base AC for a race.

* Param1 = Modifier value (+/-)
* Param2 = Armor Class type. Keep in mind that non-dodge AC types won't stack with other non-dodge AC from spell effects nor item properties.

##### Example 2da entry
```text
2DA V2.0

     LABEL                    Type            Param1 Param2 Param3
0    InateAC                  AC              1      0      ****
``` 

##### Example script on_module_load
```c
NWNX_Race_SetRacialModifier(150, NWNX_RACE_MODIFIER_AC, 1, AC_DODGE_BONUS);
```
***
### ACVSRACE
The `ACVSRACE` entry is used to modify the base AC for a race versus another specific race.

* Param1 = Racial ID from racialtypes.2da
* Param2 = Modifier value (+/-)

##### Example 2da entry
```text
2DA V2.0

     LABEL                    Type            Param1 Param2 Param3
0    DragonAC                 ACVSRACE        11     4      ****
``` 

##### Example script on_module_load
```c
NWNX_Race_SetRacialModifier(150, NWNX_RACE_MODIFIER_ACVSRACE, RACIAL_TYPE_DRAGON, 4);
```
***
### CONCEALMENT
The `CONCEALMENT` entry is used to grant an inate concealment to a race.

* Param1 = Modifier value (1-100)

##### Example 2da entry
```text
2DA V2.0

     LABEL                    Type            Param1 Param2 Param3
0    Concealment              CONCEALMENT     30     ****   ****
```

##### Example script on_module_load
```c
NWNX_Race_SetRacialModifier(150, NWNX_RACE_MODIFIER_CONCEALMENT, 30);
```
***
### DMGREDUCTION
The `DMGREDUCTION` entry gives an inate damage reduction

* Param1 = Points to soak (+)
* Param2 = Level of soak (+)

##### Example 2da entry
```text
2DA V2.0

     LABEL                    Type            Param1 Param2 Param3
0    DR_SOAK5_PLUS5           DMGREDUCTION    5      5      ****
1    DR_SOAK10_PLUS4          DMGREDUCTION    10     4      ****
``` 

##### Example script on_module_load
```c
NWNX_Race_SetRacialModifier(150, NWNX_RACE_MODIFIER_DMGREDUCTION, 5, 5);
NWNX_Race_SetRacialModifier(150, NWNX_RACE_MODIFIER_DMGREDUCTION, 10, 4);
```
***
### DMGRESIST
The `DMGRESIST` entry gives an inate resistance to damage types

* Param1 = The damage type, can be a single Damage Type integer or multiple Damage Type integers summed. You can also just do each on its own line if you'd prefer. Hex can be used for the scripting method if preferred.
* Param2 = Points to resist (+)

##### Example 2da entry
```text
2DA V2.0

     LABEL                    Type            Param1 Param2 Param3
0    FireDamageResist         DMGRESIST       256    10     ****
1    FireColdDamageResist     DMGRESIST       288    5      ****
``` 

##### Example script on_module_load
```c
NWNX_Race_SetRacialModifier(150, NWNX_RACE_MODIFIER_DMGRESIST, DAMAGE_TYPE_FIRE, 10);
NWNX_Race_SetRacialModifier(150, NWNX_RACE_MODIFIER_DMGRESIST, DAMAGE_TYPE_FIRE & DAMAGE_TYPE_COLD, 5);
```
***
### DMGIMMUNITY
The `DMGIMMUNITY` entry gives an inate immunity to damage types

* Param1 = The damage type, can be a single Damage Type integer or multiple Damage Type integers summed. You can also just do each on its own line if you'd prefer. Hex can be used for the scripting method if preferred.
* Param2 = Percentage to resist (+/-)

##### Example 2da entry
```text
2DA V2.0

     LABEL                    Type            Param1 Param2 Param3
0    FireDamageImmunity       DMGIMMUNITY     256    100    ****
1    AcidDamageVulnerability  DMGIMMUNITY     16     -50    ****
``` 

##### Example script on_module_load
```c
NWNX_Race_SetRacialModifier(150, NWNX_RACE_MODIFIER_DMGIMMUNITY, DAMAGE_TYPE_FIRE, 100);
NWNX_Race_SetRacialModifier(150, NWNX_RACE_MODIFIER_DMGIMMUNITY, DAMAGE_TYPE_ACID, -50);
```
***
### FEAT
The `FEAT` entry awards a feat at a specified level. This feat is awarded after the creature levels up. Level 1 feats can still be added using the **FeatsTable** column of the `racialtypes.2da`.

* Param1 = The row in feat.2da
* Param2 = The level to grant the feat

##### Example 2da entry
```text
2DA V2.0

     LABEL                    Type            Param1 Param2 Param3
0    IronWill                 FEAT            22     3      ****
``` 

##### Example script on_module_load
```c
NWNX_Race_SetRacialModifier(150, NWNX_RACE_MODIFIER_FEAT, 22, 3);
```
***
### FEATUSAGE
The `FEATUSAGE` controls the amount of usages a race will have based upon their character level for a custom feat they are granted. 

* Param1 = The row in feat.2da
* Param2 = Usages a day granted at character creation
* Param3 = Additional usages a day granted for this many levels

##### Example 2da entry
```text
2DA V2.0

     LABEL                    Type            Param1 Param2 Param3
0    LightFeatUsage           FEATUSAGE       1101   1      5
``` 

##### Example script on_module_load
```c
NWNX_Race_SetRacialModifier(150, NWNX_RACE_MODIFIER_FEATUSAGE, 1101, 1, 5);
```
***
### IMMUNITY
The `IMMUNITY` entry is used to grant the race a total immunity to a variety of effects.

* Param1 = The IMMUNITY_TYPE_ constant value

##### Example 2da entry
```text
2DA V2.0

     LABEL                    Type            Param1 Param2 Param3
0    FearImmunity             IMMUNITY        4      ****   ****
``` 

##### Example script on_module_load
```c
NWNX_Race_SetRacialModifier(150, NWNX_RACE_MODIFIER_IMMUNITY, IMMUNITY_TYPE_FEAR);
```
***
### INITIATIVE
The `INITIATIVE` entry is used to modify the initiative check.

* Param1 = Modifier value (+/-)

##### Example 2da entry
```text
2DA V2.0

     LABEL                    Type            Param1 Param2 Param3
0    PoorInitiative           INITIATIVE      -3     ****   ****
```

##### Example script on_module_load
```c
NWNX_Race_SetRacialModifier(150, NWNX_RACE_MODIFIER_INITIATIVE, -3);
```
***
### MOVEMENTSPEED
The `MOVEMENTSPEED` can modify the speed at which the race moves by default.

* Param1 = The percentage change to their speed (-99/+99)

##### Example 2da entry
```text
2DA V2.0

     LABEL                    Type            Param1 Param2 Param3
0    Faster                   MOVEMENTSPEED   33     ****   ****
```

##### Example script on_module_load
```c
NWNX_Race_SetRacialModifier(150, NWNX_RACE_MODIFIER_MOVEMENTSPEED, 33);
```
***
### RACE
The `RACE` entry is used when the race the builder is adding has a parent race with which to inherit some hard coded checks. For example, a Ghostwise Halfling would have its `RACE` set as `3` representing the Halfling race and in turn a player with that race would have an additional +1 to ranged attacks as is set for the Halfling race.

* Param1 = Race ID from racialtypes.2da

##### Example 2da entry
```text
2DA V2.0

     LABEL                    Type            Param1 Param2 Param3
0    Race                     RACE            3      ****   ****
``` 
##### Example script on_module_load
```c
NWNX_Race_SetRacialModifier(150, NWNX_RACE_MODIFIER_RACE, RACIAL_TYPE_HALFLING);
```
***
### REGENERATION
The `REGENERATION` entry is used to grant the race an inate regeneration.

* Param1 = How many hitpoints to increase (+)
* Param2 = How often in seconds to increase the hitpoints (+)

##### Example 2da entry
```text
2DA V2.0

     LABEL                    Type            Param1 Param2 Param3
0    Regeneration             REGENERATION    2      6      ****
``` 

##### Example script on_module_load
```c
NWNX_Race_SetRacialModifier(150, NWNX_RACE_MODIFIER_REGENERATION, 2, 6);
```
***
### SAVE
The `SAVE` entry is used to modify base save values.

* Param1 = 0-3 meaning SAVING_THROW_ALL, SAVING_THROW_FORT, SAVING_THROW_REFLEX or SAVING_THROW_WILL
* Param2 = Modifier value (+/-)

##### Example 2da entry
```text
2DA V2.0

     LABEL                    Type            Param1 Param2 Param3
0    FortitudeVulnerable      SAVE            1      -2     ****
``` 

##### Example script on_module_load
```c
NWNX_Race_SetRacialModifier(150, NWNX_RACE_MODIFIER_SAVE, SAVING_THROW_FORT, -2);
```
***
### SAVEVSRACE
The `SAVEVSRACE` entry is used to modify base save values vs a specific race. Param1 is the Save constant ID and param2 is the target race constant ID and param3 is the modifier.

* Param1 = 0-3 meaning SAVING_THROW_ALL, SAVING_THROW_FORT, SAVING_THROW_REFLEX or SAVING_THROW_WILL
* Param2 = Racial ID from racialtypes.2da
* Param3 = Modifier value (+/-)

##### Example 2da entry
```text
2DA V2.0

     LABEL                    Type            Param1 Param2 Param3
0    UniversalSaveVsUndead    SAVEVSRACE      0      24     5
``` 

##### Example script on_module_load
```c
NWNX_Race_SetRacialModifier(150, NWNX_RACE_MODIFIER_SAVEVSRACE, SAVING_THROW_ALL, RACIAL_TYPE_UNDEAD, 5);
```
***
### SAVEVSTYPE
The `SAVEVSTYPE` entry is used to modify base save values vs a specific type. Param1 is the Save constant ID and param2 is the Saving Throw Type constant ID and param3 is the modifier.

* Param1 = 0-3 meaning SAVING_THROW_ALL, SAVING_THROW_FORT, SAVING_THROW_REFLEX or SAVING_THROW_WILL
* Param2 = A SAVING_THROW_TYPE_ constant
* Param3 = Modifier value (+/-)

##### Example 2da entry
```text
2DA V2.0

     LABEL                    Type            Param1 Param2 Param3
0    ReflexSaveVsTraps        SAVEVSTYPE      2      14     3
``` 

##### Example script on_module_load
```c
NWNX_Race_SetRacialModifier(150, NWNX_RACE_MODIFIER_SAVEVSTYPE, SAVING_THROW_REFLEX, SAVING_THROW_TYPE_TRAP, 3);
```
***
### SKILL
The `SKILL` entry is used to modify base skill ranks. Note: This requires the `NWNX_SkillRanks` plugin.

* Param1 = Skill ID from skills.2da
* Param2 = Modifier value (+/-)

##### Example 2da entry
```text
2DA V2.0

     LABEL                    Type            Param1 Param2 Param3
0    IntimidateBonus+2        SKILL           24     2      ****
1    HealLimited-2            SKILL           5      -2     ****

``` 
##### Example script on_module_load
```c
NWNX_Race_SetRacialModifier(150, NWNX_RACE_MODIFIER_SKILL, SKILL_INTIMIDATE, 2);
NWNX_Race_SetRacialModifier(150, NWNX_RACE_MODIFIER_SKILL, SKILL_HEAL, -2);
```
***
### SPELLIMMUNITY
The `SPELLIMMUNITY` entry is used to grant the race a total immunity to specific spells. Note: Only spells that can be resisted can have immunities.

* Param1 = The spell row from spells.2da

##### Example 2da entry
```text
2DA V2.0

     LABEL                    Type            Param1 Param2 Param3
0    HorridWiltingImmune      SPELLIMMUNITY   367    ****   ****
``` 

##### Example script on_module_load
```c
NWNX_Race_SetRacialModifier(150, NWNX_RACE_MODIFIER_SPELLIMMUNITY, SPELL_HORRID_WILTING);
```
***
### SRCHARGEN
The `SRCHARGEN` entry is used to award the race a default spell resistance on character creation.

* Param1 = Modifier value (+)
* Param2 (Optional) = Maximum value all Spell Resistance racial values can reach

##### Example 2da entry
```text
2DA V2.0

     LABEL                    Type            Param1 Param2 Param3
0    SRAtCharCreation         SRCHARGEN       10     36     ****
``` 
##### Example script on_module_load
```c
NWNX_Race_SetRacialModifier(150, NWNX_RACE_MODIFIER_SRCHARGEN, 10, 36);
```
***
### SRINCLEVEL
The `SRINCLEVEL` entry is used to award a spell resistance racial bonus as the creature's level increases.

* Param1 = Amount of points to increment (+)
* Param2 = Level per increment (+)
* Param3 = Level at which the incremental gains begin (+)

##### Example 2da entry
```text
2DA V2.0

     LABEL                    Type            Param1 Param2 Param3
0    SRIncrementLevels        SRINCLEVEL      1      1      6
``` 

##### Example script on_module_load
```c
NWNX_Race_SetRacialModifier(150, NWNX_RACE_MODIFIER_SRINCLEVEL, 1, 1, 6);
```
