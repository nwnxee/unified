@page itemappearance Readme
@ingroup itemappearance

Lists the appearances an item can take and picks, steps through or randomizes them, with rules to leave some out.

The lists are built from the TGA and PLT icons in the module and haks (the client cannot show an icon that is only a DDS), so only appearances that have an icon (and, for weapons, a model) are offered.

## Usage

Call `NWNX_ItemAppearance_CacheAppearances()` once on module load, after the haks are available. It builds the lists and clears every rule, so add rules (`NWNX_ItemAppearance_BlacklistAppearance()`, `NWNX_ItemAppearance_SyncAppearance()`) afterwards.

Rules apply to an item class (the `ItemClass` column of baseitems.2da), so a rule for one base item applies to every base item sharing its class.

Ranges are written as `*` (any value) or a comma separated list of `n`, `n-m`, `-m` (up to m) and `n-` (n and up). A range that doesn't parse ignores the whole rule and logs a warning.

## Notes

- Simple and layered items (rings, shields, cloaks, helmets...) have a single model number and use only the first range of a blacklist rule. Weapons have three parts, each with a model and a color (0-9), written as `model * 10 + color`.
- A synced weapon model can only be used on all three parts together. Stepping or randomizing a single part never lands on a synced model, since the other parts would no longer match. To reach one, use `NWNX_ItemAppearance_GetNextWeaponAppearance()` / `GetPreviousWeaponAppearance()` (step all three parts by bottom model) or `GetRandomWeaponAppearance()`.
- A blacklist rule for a simple or layered item may only use the first range; a rule with any other range is ignored with a warning.
- For weapons the next and previous functions return `model * 10 + color`, like the random ones, not just the model.
- The functions only return values. Apply them with `NWNX_Item_SetItemAppearance()` or `CopyItemAndModify()`.

## Environment Variables

There are no environment variables for this plugin.
