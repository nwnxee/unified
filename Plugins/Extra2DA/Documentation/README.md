# Extra2DA Plugin Reference

This plugin allows configuration of various game aspects via 2DA files.

## Dragon Abilities

Allows configuration of dragon disciple ability score progression via a new dragon.2da file (a sample dragon.2da file is provided).
Level-up ability score adjustments work pretty much out of the box, but there are some trickier things to consider:

* To enable reliable level-down functionality, the plugin stores ability score adjustments made in NWNX's internal PerObjectStorage.
At present this storage is not persistent, but that will hopefully be addressed soon&trade;, at which point this plugin will be updated.
Until then DO NOT USE this plugin if you ever want to de-level characters (unless you are prepared to manually fix ability scores).

* When ability score progression changes, existing characters will not be updated automatically.
However, the plugin provides a function `NWNX_Extra2DA_RelevelToFixDragonAbilities` for this purpose.
This works by de-leveling the character as much as needed, then restoring XP (players will need to re-level manually).
DO NOT USE this function until PerObjectStorage is persistent (it will de-level valid characters and break them)!

Note: PerObjectStorage currently persists while the server is running, which should allow some basic testing.

### Example

On Client Enter event example:

```C
#include "nwnx_extra2da"

void main()
{
    object oPC=GetEnteringObject();
    NWNX_Extra2DA_RelevelToFixDragonAbilities(oPC);
}
```

### Known Issues

* Things will break if adjustment data is lost (see above).
* Does not work with ELC enabled.
* Does not work on NPCs (they use standard progression).
