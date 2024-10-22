@addtogroup maxlevel MaxLevel
@page maxlevel Readme
@ingroup maxlevel

This plugin extends the maximum level possibility from 40 to 60. The plugin provides normal level up alerting and procedure with a few minor issues. Feats and Ability Points follow their normal progression. Spell counts gained can be configured for the additional levels.

## Environment Variables
| Variable Name | Value | Default | Notes |
| ------------- | :---: | :-----: | ----- |
| `NWNX_MAXLEVEL_MAX` | 41-60 | null | Maximum level you wish to support.

## Required Plugins
* The `NWNX_ELC` plugin is also needed to bypass the level restriction. No configuration is necessary though, merely loading this plugin is sufficient.

## Issues
* Spellcasters may not change spells when levelling up.
* Next Level XP on Character Sheet shows an incorrect value. For a possible workaround see below.

## Setup
* Define your max levels variable in your server environment.
```
export NWNX_MAXLEVEL_MAX=45
```
* If you provide a `-maxlevel` argument in your server start up or have `MaxCharLevel` defined in your **nwnplayer.ini** make sure those values are changed as well. It is safe to ignore the message at startup stating `Server: Invalid argument to -maxlevel`.

* Add your XP thresholds to your **exptable.2da**
```csv
...
40	41	35935000
41	42	39935000
42	43	45935000
43	44	53935000
44	45	63935000
45	46	0xFFFFFFF
```
* (Optional) Edit the class spell gain 2da files to provide more spells as levels progress. These are **cls_spgn_???.2da**. The spell known 2da is not worth changing as there's currently no client interface for PCs to change their known spells past level 40.

## Next Level XP workaround
Beginning at level 40 the xp value shown on the character sheet after "Next Level:" is incorrect.
This can be worked around with, with a tlk override for the strref 315 "Next Level" that also pushes the xp value out of view by use of a new line `\n`.
With NWNX this can be done per player and can show the actual value of xp needed for the next level so that it looks as usual.
```c
// Todo: Do something to get the PC object as oPC.
int nLevel = GetHitDice(oPC);
if (nLevel < 40)
{
  // In case of a level down the override might not be needed anymore.
  NWNX_Player_SetTlkOverride(oPC, 315, "");
}
else
{
  string sNextLevel = IntToString((nLevel + 1) * nLevel * 500);
  // The line above assumes you followed the same pattern of xp progression as the first 40 levels.
  // If not, read from exptable.2da or do what you have to do to get the correct xp value for the next level.
  NWNX_Player_SetTlkOverride(oPC, 315, "Next Level: " + sNextLevel + "\n");
}
```
Code like the above could for example be run in the base game events `EVENT_SCRIPT_MODULE_ON_CLIENT_ENTER`, `EVENT_SCRIPT_MODULE_ON_PLAYER_LEVEL_UP` and the NWNX event `NWNX_ON_LEVEL_DOWN_AFTER`.
An alternative would be the nwnx event before opening the character sheet `NWNX_ON_CHARACTER_SHEET_OPEN_BEFORE`.
