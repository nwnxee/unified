# Extra2DA Plugin Reference

This plugin allows configuration of various game aspects via 2DA files.

## Dragon Abilities

Allows configuration of dragon disciple ability score progression via a new dragon.2da file (a sample dragon.2da file is provided).
Level-up ability score adjustments work pretty much out of the box, but there are some trickier things to consider:

* To enable reliable level-down functionality, the plugin stores ability score adjustments made in NWNX's internal PerObjectStorage.
At present this storage does not persist across server resets, so persistence must be ensure by the module.
The functions `NWNX_Extra2DA_GetDragonAbilityHistory` and `NWNX_Extra2DA_SetDragonAbilityHistory` should be used for this.

* When ability score progression changes, existing characters will not be updated automatically.
However, the plugin provides a function `NWNX_Extra2DA_RelevelToFixDragonAbilities` for this purpose.
This works by de-leveling the character as much as needed, then restoring XP (players will need to re-level manually).

### Example

`OnClientEnter` event:

```C
#include "nwnx_extra2da"

void main()
{
    object oPC=GetEnteringObject();
    string sHistory = GetCampaignString("MyDatabase", "DragonAbilityHistory", oPC);
    NWNX_Extra2DA_SetDragonAbilityHistory(oPC, sHistory);
    NWNX_Extra2DA_RelevelToFixDragonAbilities(oPC);
}
```

`OnClientLeave` event:

```C
#include "nwnx_extra2da"

void main()
{
    object oPC=GetExitingObject();
    string sHistory = NWNX_Extra2DA_GetDragonAbilityHistory(oPC);
    SetCampaignString("MyDatabase", "DragonAbilityHistory", sHistory, oPC);
}
```

*Note:* The `OnClientLeave` event may not always fire should the server go down hard. This may cause history data to become outdated.
To be on the safe side, you may want to update persistent ability history after each level change.

### Known Issues

* Things will break if adjustment history data is lost.
* Does not work with ELC enabled.
* Does not work on NPCs (they use standard progression).
