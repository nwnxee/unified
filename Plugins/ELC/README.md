@page elc Readme
@ingroup elc 

An NWNX replacement for ValidateCharacter: ELC & ILR

## Notes
If enabled and used without setting an ELC script it will function just like ELC/ILR in the base game.

This is a pretty advanced plugin and may at times require you to dive into the source code to figure out what's going on.

## Environment Variables
| Variable Name | Value | Default | Notes |
| ------------- | :---: | :-----: | ----- |
| `NWNX_ELC_ELC_SCRIPT` | string | "" | Set the NWScript that receives all the ELC validation failure events.
| `NWNX_ELC_CUSTOM_ELC_CHECK` | true/false | false | Enables the custom ELC check, an ELC script must be set for it to run.
| `NWNX_ELC_ENFORCE_DEFAULT_EVENT_SCRIPTS` | true/false | false | If enabled, resets a character's event scripts to `default`. Requires ELC to be enabled.
| `NWNX_ELC_ENFORCE_EMPTY_DIALOG_RESREF` | true/false | false | If enabled, resets a character's dialog resref to empty. Requires ELC to be enabled.

## Events
This plugin adds the following events which can be subscribed to with NWNX_Events.

`NWNX_ON_ELC_VALIDATE_CHARACTER_BEFORE`

`NWNX_ON_ELC_VALIDATE_CHARACTER_AFTER`

`OBJECT_SELF` is the player object, the `_AFTER` event only runs if the character successfully validates.

## Example Script
```c
#include "nwnx_elc"

void main()
{
    object oPC = OBJECT_SELF;
    int nType = NWNX_ELC_GetValidationFailureType();
    int nSubType = NWNX_ELC_GetValidationFailureSubType();
    int nStrRef = NWNX_ELC_GetValidationFailureMessageStrRef();

    WriteTimestampedLogEntry("ELC: FAIL: " + GetName(oPC) +
                        " -> Type = " +IntToString(nType) +
                        ", SubType = " +IntToString(nSubType) +
                        ", StrRef = " + IntToString(nStrRef));

    // MrMunchkin is friends with the server owner and gets to skip any ILR MinEquipLevel failures
    if (nSubType == NWNX_ELC_SUBTYPE_MIN_EQUIP_LEVEL)
    {
        if (GetPCPublicCDKey(oPC) == "OMG1337")
            NWNX_ELC_SkipValidationFailure();
    }

    // The validation failure happened on our current level so we could
    // just roll back their last level
    if (GetHitDice(oPC) == NWNX_ELC_GetValidationFailureLevel())
    {
        // Do XP Stuff here
        // Send message to player
        // Etc
        // NWNX_ELC_SkipValidationFailure();
        // return;
    }

    switch (nType)
    {
        case NWNX_ELC_VALIDATION_FAILURE_TYPE_CHARACTER:
        {
            // We allow colored names on our server
            if (nSubType == NWNX_ELC_SUBTYPE_COLORED_NAME)
            {
                NWNX_ELC_SkipValidationFailure();
            }

            break;
        }

        case NWNX_ELC_VALIDATION_FAILURE_TYPE_ITEM:
        {
            object oItem = NWNX_ELC_GetValidationFailureItem();

            // Unequip the item instead of having the player unable to login
            if (GetIsObjectValid(oItem))
                ActionUnequipItem(oItem);

            NWNX_ELC_SkipValidationFailure();
            break;
        }

        case NWNX_ELC_VALIDATION_FAILURE_TYPE_SKILL:
        {
            // We don't handle skill validation failures
            break;
        }

        case NWNX_ELC_VALIDATION_FAILURE_TYPE_FEAT:
        {
            // We ignore the ability requirement for the dodge feat
            if (nSubType == NWNX_ELC_SUBTYPE_FEAT_REQUIRED_ABILITY_VALUE_NOT_MET)
            {
                int nFeatID = NWNX_ELC_GetValidationFailureFeatID();

                if (nFeatID == FEAT_DODGE)
                {
                    NWNX_ELC_SkipValidationFailure();
                }
            }
            break;
        }

        case NWNX_ELC_VALIDATION_FAILURE_TYPE_SPELL:
        {
            // We skip all spell ELC checks
            NWNX_ELC_SkipValidationFailure();
            break;
        }

        // Enable with NWNX_ELC_EnableCustomELCCheck()
        case NWNX_ELC_VALIDATION_FAILURE_TYPE_CUSTOM:
        {
            // Only blue haired characters allowed on our server
            if (GetColor(oPC, COLOR_CHANNEL_HAIR) == 25)
            {
                NWNX_ELC_SkipValidationFailure();
            }
            else
            {
                // Set Custom Failure Message: Hair Color
                NWNX_ELC_SetValidationFailureMessageStrRef(125);
            }
            break;
        }
    }
}
 ```
