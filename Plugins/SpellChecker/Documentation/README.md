# SpellChecker Plugin Reference

## Description

Spell checking through Hunspell 1.4.1 and up

## How to install?

Note: More heavily tested on 1.4.1 but works on 1.6.

Hunspell is installed by default on some systems, if it's not:
sudo apt-get install libhunspell-1.4-0:i386

If you wish to build (which you likely do if you're here) This also includes the necessary files above
sudo apt-get install libhunspell-dev:i386


Alternatively, you can find hunspells source here: https://github.com/hunspell/hunspell/releases

For easily installed dictionary list:

apt-cache search hunspell

sudo apt-get install hunspell-en-us for English (United States)


The package requires a 32-bit version of libhunspell.so

If this doesn't exist with your OS's i386 libaries and you have libhunspell 1.4 or above installed try running:

Example for Debian:
sudo ln -s /usr/lib/i386-linux-gnu/libhunspell-1.4.so.0 /usr/lib/i386-linux-gnu/libhunspell.so

You can also use the above method to update hunspell to a newer version (may not be supported)


## Environment Variables

```
NWNX_SPELL_PATH_AFF [optional]: The path to the aff file. By default /usr/share/hunspell/en_US.aff is used.
NWNX_SPELL_PATH_DIC [optional]: The path to the dic file. By default /usr/share/hunspell/en_US.dic is used.
```
