@page vault Readme
@ingroup vault

Provides various character/servervault functions.

## NWNX_Vault_SwitchCharacter Notes

### Before even attempting to do anything with this function, make sure to (regularly) backup your servervault. You have been warned.

Things of note:

* **Backup your servervault.**
* Will disconnect the player if something goes catastrophically wrong.
* OnClientEnter/Leave and OnAreaEnter/Exit will fire for the appropriate creature objects.
* Players will switch characters on the spot, it's up to you to move them if needed.
* Probably has weird quirks and/or bugs.
