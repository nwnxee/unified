@page skillranks Readme
@ingroup skillranks

Enhances and allows for manipulation of skill rank calculations including the ability to build custom skill related feats as well as modifying stock feats.

## Plugin Sample Usage

To create a new skill feat, builders create a `SkillFeat` structure and run functions on the `OnModuleLoad`.

#### Example 1
The builder wants to create a new skill called **Travel** and wants to add Skill Focus and Epic Skill Focus feats.

* Add the **Travel** skill definition to skills.2da
* Add the **Skill Focus Travel** and **Epic Skill Focus Travel** to feat.2da
* In the `OnModuleLoad` script enter the following:
```c
struct NWNX_SkillRanks_SkillFeat skillFeat;
skillFeat.iSkill = 27; // The row number for the new Travel skill
skillFeat.iFeat = 1801; // The row number for the Skill Focus Travel feat
skillFeat.iModifier = 3;
// Defining feats with the iFocusFeat setting helps with mass changing modifiers
skillFeat.iFocusFeat = 1;
NWNX_SkillRanks_SetSkillFeat(skillFeat, TRUE);

skillFeat.iFeat = 1802; // The row number for the Epic Skill Focus Travel feat
skillFeat.iModifier = 10;
skillFeat.iFocusFeat = 2; // 2 for Epic Focus
NWNX_SkillRanks_SetSkillFeat(skillFeat, TRUE);
``` 

#### Example 2
The builder doesn't like the restriction on the **Trackless Step** feat which inhibits the skill bonus while Underground even if the Natural flag is set.

* In the `OnModuleLoad` script enter the following:
```c
struct NWNX_SkillRanks_SkillFeat skillFeat = NWNX_SkillRanks_GetSkillFeat(SKILL_HIDE, FEAT_TRACKLESS_STEP);
skillFeat.iAreaFlagsForbidden &= ~(0x2);
NWNX_SkillRanks_SetSkillFeat(skillFeat);
skillFeat.iSkill = SKILL_MOVE_SILENTLY;
NWNX_SkillRanks_SetSkillFeat(skillFeat);
``` 

#### Example 3
The builder has created a new feat called **Doctor** which counts the creature's **Intelligence** instead of **Wisdom** if higher when calculating their **Heal** skill.
* Add the Doctor feat to feat.2da. 
* In the `OnModuleLoad` script enter the following:
```c
struct NWNX_SkillRanks_SkillFeat skillFeat;
skillFeat.iSkill = SKILL_HEAL;
skillFeat.iFeat = 1803; // New feat row id
skillFeat.iKeyAbilityMask = NWNX_SKILLRANKS_KEY_ABILITY_INTELLIGENCE | NWNX_SKILLRANKS_KEY_ABILITY_WISDOM | NWNX_SKILLRANKS_KEY_ABILITY_CALC_MAX;
NWNX_SkillRanks_SetSkillFeat(skillFeat, TRUE);
```

#### Example 4
The builder has created a new feat called **Moonlight Spy** which gives a **Listen**, **Search** and **Spot** bonus of 3 plus 1 for every 2 levels of **Assassin** or **Rogue** when the player is outdoors at night time.
* Add the **Moonlight Spy** feat to feat.2da 
* In the `OnModuleLoad` script enter the following:
```c
struct NWNX_SkillRanks_SkillFeat skillFeat;
skillFeat.iSkill = SKILL_LISTEN;
skillFeat.iFeat = 1804;
skillFeat.iModifier = 3;
skillFeat.fClassLevelMod = 0.5f;
skillFeat.iAreaFlagsRequired = 0x4; // Natural
skillFeat.iAreaFlagsForbidden = 0x1 | 0x2; // Not indoors or underground
skillFeat.iDayOrNight = 2;
skillFeat = NWNX_SkillRanks_AddSkillFeatClass(skillFeat, CLASS_TYPE_ASSASSIN);
skillFeat = NWNX_SkillRanks_AddSkillFeatClass(skillFeat, CLASS_TYPE_ROGUE);
NWNX_SkillRanks_SetSkillFeat(skillFeat, TRUE);

skillFeat.iSkill = SKILL_SEARCH;
NWNX_SkillRanks_SetSkillFeat(skillFeat, TRUE);

skillFeat.iSkill = SKILL_SPOT;
NWNX_SkillRanks_SetSkillFeat(skillFeat, TRUE);
```

#### Example 5
The builder wants all Skill Focus feats to increase the modifier by 5 and all Epic Skill Focus feats to increase the modifier by 12.
* Change the TLK reference in the feat.2da for all Skill Focus feats from 424 to a new custom TLK entry that states:
```text
Type of Feat: General
Prerequisite: Able to use the skill.
Specifics: A character with this feat is adept at a certain skill, gaining a +5 bonus on all checks with it.
Use: Automatic. This feat may be selected multiple times, but the effects do not stack. It applies to a different skill in each case.
```
* Change the TLK reference in the feat.2da for all Skill Focus feats from 4063 to a new custom TLK entry that states:
```text
Type of Feat: General
Prerequisite: 21st level, 20 ranks in the chosen skill.
Specifics: The character gains a +12 bonus on all skill checks with the chosen skill.
Use: Automatic.
```
* In the `OnModuleLoad` script enter the following:
```c
NWNX_SkillRanks_SetSkillFeatFocusMod(5);
NWNX_SkillRanks_SetSkillFeatFocusMod(12, TRUE);
```

#### Example 6
The builder has an area in her module called *The Great Library* where she wants all creatures to receive a bonus of 10 **Lore** whenever inside.
* In the `OnModuleLoad` script enter the following:
```c
object oArea = GetObjectByTag("greatlibrary");
NWNX_SkillRanks_SetAreaModifier(oArea, SKILL_LORE, 10);
```
