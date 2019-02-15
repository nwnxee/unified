#include "nwnx"

struct NWNX_Player_QuickBarSlot
{
    object oItem;
    object oSecondaryItem;
    int    nObjectType;
    int    nMultiClass;
    string sResRef;
    string sCommandLabel;
    string sCommandLine;
    string sToolTip;
    int    nINTParam1;
    int    nMetaType;
    int    nDomainLevel;
    int    nAssociateType;
    object oAssociate;
};

const int NWNX_PLAYER_VISIBILITY_DEFAULT = 0;
const int NWNX_PLAYER_VISIBILITY_HIDDEN  = 1;
const int NWNX_PLAYER_VISIBILITY_VISIBLE = 2;

// Force display placeable examine window for player
// If used on a placeable in a different area than the player, the portait will not be shown.
void NWNX_Player_ForcePlaceableExamineWindow(object player, object placeable);

// Force opens the target object's inventory for the player.
// A few notes about this function:
// - If the placeable is in a different area than the player, the portrait will not be shown
// - The placeable's open/close animations will be played
// - Clicking the 'close' button will cause the player to walk to the placeable;
//     If the placeable is in a different area, the player will just walk to the edge
//     of the current area and stop. This action can be cancelled manually.
// - Walking will close the placeable automatically.
void NWNX_Player_ForcePlaceableInventoryWindow(object player, object placeable);

// Starts displaying a timing bar.
// Will run a script at the end of the timing bar, if specified.
void NWNX_Player_StartGuiTimingBar(object player, float seconds, string script = "");

// Stops displaying a timing bar.
// Runs a script if specified.
void NWNX_Player_StopGuiTimingBar(object player, string script = "");

// Sets whether the player should always walk when given movement commands.
// If true, clicking on the ground or using WASD will trigger walking instead of running.
void NWNX_Player_SetAlwaysWalk(object player, int bWalk=TRUE);

// Gets the player's quickbar slot info
struct NWNX_Player_QuickBarSlot NWNX_Player_GetQuickBarSlot(object player, int slot);

// Sets a player's quickbar slot
void NWNX_Player_SetQuickBarSlot(object player, int slot, struct NWNX_Player_QuickBarSlot qbs);

// Get the name of the .bic file associated with the player's character.
string NWNX_Player_GetBicFileName(object player);

// Overrides the default visibility rules about how player perceives the target object.
// NWNX_PLAYER_VISIBILITY_DEFAULT - Restore normal behavior
// NWNX_PLAYER_VISIBILITY_HIDDEN - Object is always hidden from the player
// NWNX_PLAYER_VISIBILITY_VISIBLE - Object is always shown to the player
//
// DEPRECATED - Use NWNX_Visibility_SetVisibilityOverride instead
void NWNX_Player_SetVisibilityOverride(object player, object target, int override);

// Queries the existing visibility override for given (player, object) pair
// Returns NWNX_PLAYER_VISIBILITY_DEFAULT if no override exists
//
// DEPRECATED - Use NWNX_Visibility_GetVisibilityOverride instead
int NWNX_Player_GetVisibilityOverride(object player, object target);

// Plays the VFX at the target position in current area for the given player only
void NWNX_Player_ShowVisualEffect(object player, int effectId, vector position);

// Changes the daytime music track for the given player only
void NWNX_Player_MusicBackgroundChangeDay(object player, int track);

// Changes the nighttime music track for the given player only
void NWNX_Player_MusicBackgroundChangeNight(object player, int track);

// Starts the background music for the given player only
void NWNX_Player_MusicBackgroundStart(object player);

// Stops the background music for the given player only
void NWNX_Player_MusicBackgroundStop(object player);

// Changes the battle music track for the given player only
void NWNX_Player_MusicBattleChange(object player, int track);

// Starts the battle music for the given player only
void NWNX_Player_MusicBattleStart(object player);

// Stops the background music for the given player only
void NWNX_Player_MusicBattleStop(object player);

// Play a sound at the location of target for the given player only
// If target is OBJECT_INVALID the sound will play at the location of the player
void NWNX_Player_PlaySound(object player, string sound, object target = OBJECT_INVALID);

// Toggle a placeable's usable flag for the given player only
void NWNX_Player_SetPlaceableUsable(object player, object placeable, int usable);

// Override player's rest duration
// Duration is in milliseconds, 1000 = 1 second
// Minimum duration of 10ms
// -1 clears the override
void NWNX_Player_SetRestDuration(object player, int duration);

// Apply visualeffect to target that only player can see
//
// Note: Only works with instant effects: VFX_COM_*, VFX_FNF_*, VFX_IMP_*
void NWNX_Player_ApplyInstantVisualEffectToObject(object player, object target, int visualeffect);


const string NWNX_Player = "NWNX_Player";


void NWNX_Player_ForcePlaceableExamineWindow(object player, object placeable)
{
    string sFunc = "ForcePlaceableExamineWindow";
    NWNX_PushArgumentObject(NWNX_Player, sFunc, placeable);
    NWNX_PushArgumentObject(NWNX_Player, sFunc, player);

    NWNX_CallFunction(NWNX_Player, sFunc);
}

void NWNX_Player_ForcePlaceableInventoryWindow(object player, object placeable)
{
    string sFunc = "ForcePlaceableInventoryWindow";
    NWNX_PushArgumentObject(NWNX_Player, sFunc, placeable);
    NWNX_PushArgumentObject(NWNX_Player, sFunc, player);

    NWNX_CallFunction(NWNX_Player, sFunc);
}

void NWNX_Player_INTERNAL_StopGuiTimingBar(object player, string script = "", int id = -1)
{
    int activeId = GetLocalInt(player, "NWNX_PLAYER_GUI_TIMING_ACTIVE");
    // Either the timing event was never started, or it already finished.
    if (activeId == 0)
        return;

    // If id != -1, we ended up here through DelayCommand. Make sure it's for the right ID
    if (id != -1 && id != activeId)
        return;

    DeleteLocalInt(player, "NWNX_PLAYER_GUI_TIMING_ACTIVE");

    string sFunc = "StopGuiTimingBar";
    NWNX_PushArgumentObject(NWNX_Player, sFunc, player);
    NWNX_CallFunction(NWNX_Player, sFunc);

    if(script != "")
    {
        ExecuteScript(script, player);
    }
}

void NWNX_Player_StartGuiTimingBar(object player, float seconds, string script = "")
{
    // only one timing bar at a time!
    if (GetLocalInt(player, "NWNX_PLAYER_GUI_TIMING_ACTIVE"))
        return;

    string sFunc = "StartGuiTimingBar";
    NWNX_PushArgumentFloat(NWNX_Player, sFunc, seconds);
    NWNX_PushArgumentObject(NWNX_Player, sFunc, player);

    NWNX_CallFunction(NWNX_Player, sFunc);

    int id = GetLocalInt(player, "NWNX_PLAYER_GUI_TIMING_ID") + 1;
    SetLocalInt(player, "NWNX_PLAYER_GUI_TIMING_ACTIVE", id);
    SetLocalInt(player, "NWNX_PLAYER_GUI_TIMING_ID", id);

    DelayCommand(seconds, NWNX_Player_INTERNAL_StopGuiTimingBar(player, script, id));
}

void NWNX_Player_StopGuiTimingBar(object player, string script = "")
{
    NWNX_Player_INTERNAL_StopGuiTimingBar(player, script, -1);
}

void NWNX_Player_SetAlwaysWalk(object player, int bWalk=TRUE)
{
    string sFunc = "SetAlwaysWalk";
    NWNX_PushArgumentInt(NWNX_Player, sFunc, bWalk);
    NWNX_PushArgumentObject(NWNX_Player, sFunc, player);

    NWNX_CallFunction(NWNX_Player, sFunc);
}

struct NWNX_Player_QuickBarSlot NWNX_Player_GetQuickBarSlot(object player, int slot)
{
    string sFunc = "GetQuickBarSlot";
    struct NWNX_Player_QuickBarSlot qbs;

    NWNX_PushArgumentInt(NWNX_Player, sFunc, slot);
    NWNX_PushArgumentObject(NWNX_Player, sFunc, player);
    NWNX_CallFunction(NWNX_Player, sFunc);

    qbs.oAssociate     = NWNX_GetReturnValueObject(NWNX_Player, sFunc);
    qbs.nAssociateType = NWNX_GetReturnValueInt(NWNX_Player,    sFunc);
    qbs.nDomainLevel   = NWNX_GetReturnValueInt(NWNX_Player,    sFunc);
    qbs.nMetaType      = NWNX_GetReturnValueInt(NWNX_Player,    sFunc);
    qbs.nINTParam1     = NWNX_GetReturnValueInt(NWNX_Player,    sFunc);
    qbs.sToolTip       = NWNX_GetReturnValueString(NWNX_Player, sFunc);
    qbs.sCommandLine   = NWNX_GetReturnValueString(NWNX_Player, sFunc);
    qbs.sCommandLabel  = NWNX_GetReturnValueString(NWNX_Player, sFunc);
    qbs.sResRef        = NWNX_GetReturnValueString(NWNX_Player, sFunc);
    qbs.nMultiClass    = NWNX_GetReturnValueInt(NWNX_Player,    sFunc);
    qbs.nObjectType    = NWNX_GetReturnValueInt(NWNX_Player,    sFunc);
    qbs.oSecondaryItem = NWNX_GetReturnValueObject(NWNX_Player, sFunc);
    qbs.oItem          = NWNX_GetReturnValueObject(NWNX_Player, sFunc);

    return qbs;
}

void NWNX_Player_SetQuickBarSlot(object player, int slot, struct NWNX_Player_QuickBarSlot qbs)
{
    string sFunc = "SetQuickBarSlot";

    NWNX_PushArgumentObject(NWNX_Player, sFunc, qbs.oItem);
    NWNX_PushArgumentObject(NWNX_Player, sFunc, qbs.oSecondaryItem);
    NWNX_PushArgumentInt(NWNX_Player,    sFunc, qbs.nObjectType);
    NWNX_PushArgumentInt(NWNX_Player,    sFunc, qbs.nMultiClass);
    NWNX_PushArgumentString(NWNX_Player, sFunc, qbs.sResRef);
    NWNX_PushArgumentString(NWNX_Player, sFunc, qbs.sCommandLabel);
    NWNX_PushArgumentString(NWNX_Player, sFunc, qbs.sCommandLine);
    NWNX_PushArgumentString(NWNX_Player, sFunc, qbs.sToolTip);
    NWNX_PushArgumentInt(NWNX_Player,    sFunc, qbs.nINTParam1);
    NWNX_PushArgumentInt(NWNX_Player,    sFunc, qbs.nMetaType);
    NWNX_PushArgumentInt(NWNX_Player,    sFunc, qbs.nDomainLevel);
    NWNX_PushArgumentInt(NWNX_Player,    sFunc, qbs.nAssociateType);
    NWNX_PushArgumentObject(NWNX_Player, sFunc, qbs.oAssociate);

    NWNX_PushArgumentInt(NWNX_Player, sFunc, slot);
    NWNX_PushArgumentObject(NWNX_Player, sFunc, player);
    NWNX_CallFunction(NWNX_Player, sFunc);
}

string NWNX_Player_GetBicFileName(object player)
{
    string sFunc = "GetBicFileName";
    NWNX_PushArgumentObject(NWNX_Player, sFunc, player);
    NWNX_CallFunction(NWNX_Player, sFunc);
    return NWNX_GetReturnValueString(NWNX_Player, sFunc);
}

void NWNX_Player_SetVisibilityOverride(object player, object target, int override)
{
    WriteTimestampedLogEntry("NWNX_Player: SetVisibilityOverride() is deprecated. Use NWNX_Visibility: SetVisibilityOverride() instead");

    string sFunc = "SetVisibilityOverride";
    string NWNX_Visibility = "NWNX_Visibility";

    switch(override)
    {
        case NWNX_PLAYER_VISIBILITY_DEFAULT:
            override = -1;
            break;

        case NWNX_PLAYER_VISIBILITY_HIDDEN:
            override = 1;
            break;

        case NWNX_PLAYER_VISIBILITY_VISIBLE:
            override = 0;
            break;
    }

    NWNX_PushArgumentInt(NWNX_Visibility, sFunc, override);
    NWNX_PushArgumentObject(NWNX_Visibility, sFunc, target);
    NWNX_PushArgumentObject(NWNX_Visibility, sFunc, player);

    NWNX_CallFunction(NWNX_Visibility, sFunc);
}

int NWNX_Player_GetVisibilityOverride(object player, object target)
{
    WriteTimestampedLogEntry("NWNX_Player: GetVisibilityOverride() is deprecated. Use NWNX_Visibility: GetVisibilityOverride() instead");

    string sFunc = "GetVisibilityOverride";
    string NWNX_Visibility = "NWNX_Visibility";

    NWNX_PushArgumentObject(NWNX_Visibility, sFunc, target);
    NWNX_PushArgumentObject(NWNX_Visibility, sFunc, player);

    NWNX_CallFunction(NWNX_Visibility, sFunc);

    int retVal = NWNX_GetReturnValueInt(NWNX_Visibility, sFunc);

    switch(retVal)
    {
        case -1:
            retVal = NWNX_PLAYER_VISIBILITY_DEFAULT;
            break;

        case 0:
            retVal = NWNX_PLAYER_VISIBILITY_VISIBLE;
            break;

        case 1:
            retVal = NWNX_PLAYER_VISIBILITY_HIDDEN;
            break;
    }

    return retVal;
}

void NWNX_Player_ShowVisualEffect(object player, int effectId, vector position)
{
    string sFunc = "ShowVisualEffect";
    NWNX_PushArgumentFloat(NWNX_Player, sFunc, position.x);
    NWNX_PushArgumentFloat(NWNX_Player, sFunc, position.y);
    NWNX_PushArgumentFloat(NWNX_Player, sFunc, position.z);
    NWNX_PushArgumentInt(NWNX_Player, sFunc, effectId);
    NWNX_PushArgumentObject(NWNX_Player, sFunc, player);

    NWNX_CallFunction(NWNX_Player, sFunc);
}

void NWNX_Player_MusicBackgroundChangeDay(object player, int track)
{
    string sFunc = "ChangeBackgroundMusic";
    NWNX_PushArgumentInt(NWNX_Player, sFunc, track);
    NWNX_PushArgumentInt(NWNX_Player, sFunc, TRUE); // bool day = TRUE
    NWNX_PushArgumentObject(NWNX_Player, sFunc, player);

    NWNX_CallFunction(NWNX_Player, sFunc);
}

void NWNX_Player_MusicBackgroundChangeNight(object player, int track)
{
    string sFunc = "ChangeBackgroundMusic";
    NWNX_PushArgumentInt(NWNX_Player, sFunc, track);
    NWNX_PushArgumentInt(NWNX_Player, sFunc, FALSE); // bool day = FALSE
    NWNX_PushArgumentObject(NWNX_Player, sFunc, player);

    NWNX_CallFunction(NWNX_Player, sFunc);
}

void NWNX_Player_MusicBackgroundStart(object player)
{
    string sFunc = "PlayBackgroundMusic";
    NWNX_PushArgumentInt(NWNX_Player, sFunc, TRUE); // bool play = TRUE
    NWNX_PushArgumentObject(NWNX_Player, sFunc, player);

    NWNX_CallFunction(NWNX_Player, sFunc);
}

void NWNX_Player_MusicBackgroundStop(object player)
{
    string sFunc = "PlayBackgroundMusic";
    NWNX_PushArgumentInt(NWNX_Player, sFunc, FALSE); // bool play = FALSE
    NWNX_PushArgumentObject(NWNX_Player, sFunc, player);

    NWNX_CallFunction(NWNX_Player, sFunc);
}

void NWNX_Player_MusicBattleChange(object player, int track)
{
    string sFunc = "ChangeBattleMusic";
    NWNX_PushArgumentInt(NWNX_Player, sFunc, track);
    NWNX_PushArgumentObject(NWNX_Player, sFunc, player);

    NWNX_CallFunction(NWNX_Player, sFunc);
}

void NWNX_Player_MusicBattleStart(object player)
{
    string sFunc = "PlayBattleMusic";
    NWNX_PushArgumentInt(NWNX_Player, sFunc, TRUE); // bool play = TRUE
    NWNX_PushArgumentObject(NWNX_Player, sFunc, player);

    NWNX_CallFunction(NWNX_Player, sFunc);
}

void NWNX_Player_MusicBattleStop(object player)
{
    string sFunc = "PlayBattleMusic";
    NWNX_PushArgumentInt(NWNX_Player, sFunc, FALSE); // bool play = FALSE
    NWNX_PushArgumentObject(NWNX_Player, sFunc, player);

    NWNX_CallFunction(NWNX_Player, sFunc);
}

void NWNX_Player_PlaySound(object player, string sound, object target = OBJECT_INVALID)
{
    string sFunc = "PlaySound";
    NWNX_PushArgumentObject(NWNX_Player, sFunc, target);
    NWNX_PushArgumentString(NWNX_Player, sFunc, sound);
    NWNX_PushArgumentObject(NWNX_Player, sFunc, player);

    NWNX_CallFunction(NWNX_Player, sFunc);
}

void NWNX_Player_SetPlaceableUsable(object player, object placeable, int usable)
{
    string sFunc = "SetPlaceableUsable";
    NWNX_PushArgumentInt(NWNX_Player, sFunc, usable);
    NWNX_PushArgumentObject(NWNX_Player, sFunc, placeable);
    NWNX_PushArgumentObject(NWNX_Player, sFunc, player);

    NWNX_CallFunction(NWNX_Player, sFunc);
}

void NWNX_Player_SetRestDuration(object player, int duration)
{
    string sFunc = "SetRestDuration";
    NWNX_PushArgumentInt(NWNX_Player, sFunc, duration);
    NWNX_PushArgumentObject(NWNX_Player, sFunc, player);

    NWNX_CallFunction(NWNX_Player, sFunc);
}

void NWNX_Player_ApplyInstantVisualEffectToObject(object player, object target, int visualeffect)
{
    string sFunc = "ApplyInstantVisualEffectToObject";
    NWNX_PushArgumentInt(NWNX_Player, sFunc, visualeffect);
    NWNX_PushArgumentObject(NWNX_Player, sFunc, target);
    NWNX_PushArgumentObject(NWNX_Player, sFunc, player);

    NWNX_CallFunction(NWNX_Player, sFunc);
}
