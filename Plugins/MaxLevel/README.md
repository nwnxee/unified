# MaxLevel Plugin Reference

## Description

This plugin extends the maximum level possibility from 40 to 60. The plugin provides normal level up alerting and procedure with a few minor issues. Feats and Ability Points follow their normal progression. Spell counts known and gained can be configured for the additional levels.

## Environment Variables
| Variable Name | Value | Default | Notes |
| ------------- | :---: | :-----: | ----- |
| `NWNX_MAXLEVEL_MAX` | 41-60 | null | Maximum level you wish to support.

## Required Plugins
* The `NWNX_ELC` plugin is also needed to bypass the level restriction. No configuration is necessary though, merely loading this plugin is sufficient.

## Issues

* Spellcasters may not change spells when levelling up
* Next Level XP on Character Sheet shows an incorrect value

## Setup
* Define your max levels variable in your server environment. 
```
export NWNX_MAXLEVEL_MAX=45
```
* If you provide a `-maxlevel` argument in your server start up or have `MaxCharLevel` defined in your **nwnplayer.ini** make sure those values are changed as well.

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
* (Optional) Edit the class spell gain and spell known 2da files to provide more spells as levels progress. These are **cls_spgn_???.2da** and **cls_spkn_???.2da**.
