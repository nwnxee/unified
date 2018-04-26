# Spell Plugin Reference

## Description

Spell checking through Hunspell 1.4.1

## How to install?

Note: 1.4.1 was chosen due to it's current ease of install. The include files from 1.6 have proven compatible with limited testing.

Mandatory:
sudo apt-get install libhunspell-1.4-0:i386

If you wish to build (which you likely do if you're here)

sudo apt-get install libhunspell-dev

Alternatively, you can find hunspells source here: https://github.com/hunspell/hunspell/releases

For easily installed dictionary list:

apt-cache search hunspell

sudo apt-get install hunspell-en-us for English (United States)



## Environment Variables

```
NWNX_SPELL_PATH_AFF [optional]: The path to the aff file. By default /usr/share/hunspell/en_US.aff is used.
NWNX_SPELL_PATH_DIC [optional]: The path to the dic file. By default /usr/share/hunspell/en_US.dic is used.
```
