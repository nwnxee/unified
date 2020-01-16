/// @addtogroup player
/// @brief Functions exposing additional player properties.
/// @{
/// @file nwnx_player.nss
#include "nwnx"

const string NWNX_Player = "NWNX_Player"; ///< @private

/// @brief A quickbar slot.
struct NWNX_Player_QuickBarSlot
{
    object oItem; ///< @todo Describe
    object oSecondaryItem; ///< @todo Describe
    int    nObjectType; ///< @todo Describe
    int    nMultiClass; ///< @todo Describe
    string sResRef; ///< @todo Describe
    string sCommandLabel; ///< @todo Describe
    string sCommandLine; ///< @todo Describe
    string sToolTip; ///< @todo Describe
    int    nINTParam1; ///< @todo Describe
    int    nMetaType; ///< @todo Describe
    int    nDomainLevel; ///< @todo Describe
    int    nAssociateType; ///< @todo Describe
    object oAssociate; ///< @todo Describe
};

/// @name Timing Bar Types
/// @anchor timing_bar_types
///
/// The various types of timing bars.
/// @{
const int NWNX_PLAYER_TIMING_BAR_TRAP_FLAG     = 1;
const int NWNX_PLAYER_TIMING_BAR_TRAP_RECOVER  = 2;
const int NWNX_PLAYER_TIMING_BAR_TRAP_DISARM   = 3;
const int NWNX_PLAYER_TIMING_BAR_TRAP_EXAMINE  = 4;
const int NWNX_PLAYER_TIMING_BAR_TRAP_SET      = 5;
const int NWNX_PLAYER_TIMING_BAR_REST          = 6;
const int NWNX_PLAYER_TIMING_BAR_UNLOCK        = 7;
const int NWNX_PLAYER_TIMING_BAR_LOCK          = 8;
const int NWNX_PLAYER_TIMING_BAR_CUSTOM        = 10;
/// @}

/// @name Platform IDs
/// @anchor platform_ids
/// @{
const int NWNX_PLAYER_PLATFORM_INVALID           = 0;
const int NWNX_PLAYER_PLATFORM_WINDOWS_X86       = 1;
const int NWNX_PLAYER_PLATFORM_WINDOWS_X64       = 2;
const int NWNX_PLAYER_PLATFORM_LINUX_X86         = 10;
const int NWNX_PLAYER_PLATFORM_LINUX_X64         = 11;
const int NWNX_PLAYER_PLATFORM_LINUX_ARM32       = 12;
const int NWNX_PLAYER_PLATFORM_LINUX_ARM64       = 13;
const int NWNX_PLAYER_PLATFORM_MAC_X86           = 20;
const int NWNX_PLAYER_PLATFORM_MAC_X64           = 21;
const int NWNX_PLAYER_PLATFORM_IOS               = 30;
const int NWNX_PLAYER_PLATFORM_ANDROID_ARM32     = 40;
const int NWNX_PLAYER_PLATFORM_ANDROID_ARM64     = 41;
const int NWNX_PLAYER_PLATFORM_ANDROID_X64       = 42;
const int NWNX_PLAYER_PLATFORM_NINTENDO_SWITCH   = 50;
const int NWNX_PLAYER_PLATFORM_MICROSOFT_XBOXONE = 60;
const int NWNX_PLAYER_PLATFORM_SONY_PS4          = 70;
/// @}

/// @brief Force display placeable examine window for player
/// @note If used on a placeable in a different area than the player, the portait will not be shown.
/// @param player The player object.
/// @param placeable The placeable object.
void NWNX_Player_ForcePlaceableExamineWindow(object player, object placeable);

/// @brief Force opens the target object's inventory for the player.
/// @note
/// * If the placeable is in a different area than the player, the portrait will not be shown
/// * The placeable's open/close animations will be played
/// * Clicking the 'close' button will cause the player to walk to the placeable If the placeable is in a
/// different area, the player will just walk to the edge of the current area and stop.
/// This action can be cancelled manually.
/// * Walking will close the placeable automatically.
/// @param player The player object.
/// @param placeable The placeable object.
void NWNX_Player_ForcePlaceableInventoryWindow(object player, object placeable);

/// @brief Starts displaying a timing bar.
/// @param player The player object.
/// @param seconds The length of time the timing bar will complete.
/// @param script The script to run at the bar's completion.
/// @param type The @ref timing_bar_types "Timing Bar Type"
/// @remark Only one timing bar can be ran at the same time.
void NWNX_Player_StartGuiTimingBar(object player, float seconds, string script = "", int type = NWNX_PLAYER_TIMING_BAR_CUSTOM);

/// @brief Stop displaying a timing bar.
/// @param player The player object.
/// @param script The script to run when stopped.
void NWNX_Player_StopGuiTimingBar(object player, string script = "");

/// @brief Sets whether the player should always walk when given movement commands.
/// @param player The player object.
/// @param bWalk TRUE to set the player to always walk.
/// @remark Clicking on the ground or using WASD will trigger walking instead of running.
void NWNX_Player_SetAlwaysWalk(object player, int bWalk=TRUE);

/// @brief Gets the player's quickbar slot info
/// @param player The player object.
/// @param slot Slot ID 0-35
/// @return An NWNX_Player_QuickBarSlot struct.
struct NWNX_Player_QuickBarSlot NWNX_Player_GetQuickBarSlot(object player, int slot);

/// @brief Sets the player's quickbar slot info
/// @param player The player object.
/// @param slot Slot ID 0-35
/// @param qbs An NWNX_Player_QuickBarSlot struct.
void NWNX_Player_SetQuickBarSlot(object player, int slot, struct NWNX_Player_QuickBarSlot qbs);

/// @brief Get the name of the .bic file associated with the player's character.
/// @param player The player object.
/// @return The filename for this player's bic. (Not including the ".bic")
string NWNX_Player_GetBicFileName(object player);

/// @brief Plays the VFX at the target position in current area for the given player only
/// @param player The player object.
/// @param effectId The effect id.
/// @param position The position to play the visual effect.
void NWNX_Player_ShowVisualEffect(object player, int effectId, vector position);

/// @brief Changes the daytime music track for the given player only
/// @param player The player object.
/// @param track The track id to play.
void NWNX_Player_MusicBackgroundChangeDay(object player, int track);

/// @brief Changes the nighttime music track for the given player only
/// @param player The player object.
/// @param track The track id to play.
void NWNX_Player_MusicBackgroundChangeNight(object player, int track);

/// @brief Starts the background music for the given player only
/// @param player The player object.
void NWNX_Player_MusicBackgroundStart(object player);

/// @brief Stops the background music for the given player only
/// @param player The player object.
void NWNX_Player_MusicBackgroundStop(object player);

/// @brief Changes the battle music track for the given player only
/// @param player The player object.
/// @param track The track id to play.
void NWNX_Player_MusicBattleChange(object player, int track);

/// @brief Starts the battle music for the given player only
/// @param player The player object.
void NWNX_Player_MusicBattleStart(object player);

/// @brief Stops the battle music for the given player only
/// @param player The player object.
void NWNX_Player_MusicBattleStop(object player);

/// @brief Play a sound at the location of target for the given player only
/// @param player The player object.
/// @param sound The sound resref.
/// @param target The target object for the sound to originate. If target OBJECT_INVALID the sound
/// will play at the location of the player.
void NWNX_Player_PlaySound(object player, string sound, object target = OBJECT_INVALID);

/// @brief Toggle a placeable's usable flag for the given player only
/// @param player The player object.
/// @param placeable The placeable object.
/// @param usable TRUE for usable.
void NWNX_Player_SetPlaceableUsable(object player, object placeable, int usable);

/// @brief Override player's rest duration
/// @param player The player object.
/// @param duration The duration of rest in milliseconds, 1000 = 1 second. Minimum duration of 10ms. -1 clears the override.
void NWNX_Player_SetRestDuration(object player, int duration);

/// @brief Apply visualeffect to target that only player can see
/// @param player The player object.
/// @param target The target object to play the effect upon.
/// @param visualeffect The visual effect id.
/// @note Only works with instant effects: VFX_COM_*, VFX_FNF_*, VFX_IMP_*
void NWNX_Player_ApplyInstantVisualEffectToObject(object player, object target, int visualeffect);

/// @brief Refreshes the players character sheet
/// @param player The player object.
/// @note You may need to use DelayCommand if you're manipulating values
/// through nwnx and forcing a UI refresh, 0.5s seemed to be fine
void NWNX_Player_UpdateCharacterSheet(object player);

/// @brief Allows player to open target's inventory
/// @param player The player object.
/// @param target The target object, must be a creature or another player.
/// @param open TRUE to open.
/// @remark Only works if player and target are in the same area.
void NWNX_Player_OpenInventory(object player, object target, int open = TRUE);

/// @brief Get player's area exploration state
/// @param player The player object.
/// @param area The area object.
/// @return A string representation of the tiles explored for that area.
string NWNX_Player_GetAreaExplorationState(object player, object area);

/// @brief Set player's area exploration state.
/// @param player The player object.
/// @param area The area object.
/// @param str An encoded string obtained with NWNX_Player_GetAreaExplorationState()
void NWNX_Player_SetAreaExplorationState(object player, object area, string str);

/// @brief Override player's rest animation.
/// @param oPlayer The player object.
/// @param nAnimation The NWNX animation id. This does not take ANIMATION_LOOPING_* or
/// ANIMATION_FIREFORGET_* constants. Instead use NWNX_Consts_TranslateNWScriptAnimation() to get
/// the NWNX equivalent. -1 to clear the override.
void NWNX_Player_SetRestAnimation(object oPlayer, int nAnimation);

/// @brief Override a visual transform on the given object that only player will see.
/// @param oPlayer The player object.
/// @param oObject The target object. Can be any valid Creature, Placeable, Item or Door.
/// @param nTransform One of OBJECT_VISUAL_TRANSFORM_* or -1 to remove the override.
/// @param fValue Depends on the transformation to apply.
void NWNX_Player_SetObjectVisualTransformOverride(object oPlayer, object oObject, int nTransform, float fValue);

/// @brief Apply a looping visualeffect to a target that only player can see
/// @param player The player object.
/// @param target The target object.
/// @param visualeffect A VFX_DUR_*. Calling again will remove an applied effect. -1 to remove all effects
/// @note Only really works with looping effects: VFX_DUR_*. Other types *kind* of work, they'll play when
/// reentering the area and the object is in view or when they come back in view range.
void NWNX_Player_ApplyLoopingVisualEffectToObject(object player, object target, int visualeffect);

/// @brief Override the name of placeable for player only
/// @param player The player object.
/// @param placeable The placeable object.
/// @param name The name for the placeable for this player, "" to clear the override.
void NWNX_Player_SetPlaceableNameOverride(object player, object placeable, string name);

/// @brief Gets whether a quest has been completed by a player
/// @param player The player object.
/// @param sQuestName The name identifier of the quest from the Journal Editor.
/// @return TRUE if the quest has been completed. -1 if the player does not have the journal entry.
int NWNX_Player_GetQuestCompleted(object player, string sQuestName);

/// @brief Place waypoints on module load representing where a PC should start
///
/// This will require storing the PC's cd key or community name (depending on how you store in your vault)
/// and bic_filename along with routinely updating their location in some persistent method like OnRest,
/// OnAreaEnter and OnClentExit.
///
/// @param sCDKeyOrCommunityName The Public CD Key or Community Name of the player, this will depend on your vault type.
/// @param sBicFileName The filename for the character. Retrieved with NWNX_Player_GetBicFileName().
/// @param oWP The waypoint object to place where the PC should start.
/// @param bFirstConnectOnly Set to FALSE if you would like the PC to go to this location every time they login instead
/// of just every server restart.
void NWNX_Player_SetPersistentLocation(string sCDKeyOrCommunityName, string sBicFileName, object oWP, int bFirstConnectOnly = TRUE);

/// @brief Force an item name to be updated.
/// @note This is a workaround for bug that occurs when updating item names in open containers.
/// @param oPlayer The player object.
/// @param oItem The item object.
void NWNX_Player_UpdateItemName(object oPlayer, object oItem);

/// @brief Possesses a creature by temporarily making them a familiar
/// @details This command allows a PC to possess an NPC by temporarily adding them as a familiar. It will work
/// if the player already has an existing familiar. The creatures must be in the same area. Unpossession can be
/// done with the regular @nwn{UnpossessFamiliar} commands.
/// @note The possessed creature will send automap data back to the possessor.
/// If you wish to prevent this you may wish to use NWNX_Player_GetAreaExplorationState() and
/// NWNX_Player_SetAreaExplorationState() before and after the possession.
/// @note The possessing creature will be left wherever they were when beginning the possession. You may wish
/// to use @nwn{EffectCutsceneImmobilize} and @nwn{EffectCutsceneGhost} to hide them.
/// @param oPossessor The possessor player object.
/// @param oPossessed The possessed creature object. Only works on NPCs.
/// @param bMindImmune If FALSE will remove the mind immunity effect on the possessor.
/// @param bCreateDefaultQB If TRUE will populate the quick bar with default buttons.
/// @return TRUE if possession succeeded.
int NWNX_Player_PossessCreature(object oPossessor, object oPossessed, int bMindImmune = TRUE, int bCreateDefaultQB = FALSE);

/// @brief Returns the platform ID of the given player (NWNX_PLAYER_PLATFORM_*)
/// @param oPlayer The player object.
int NWNX_Player_GetPlatformId(object oPlayer);

/// @brief Returns the game language of the given player (uses NWNX_DIALOG_LANGUAGE_*)
/// @details This function returns the ID of the game language displayed to the player.
/// Uses the same constants as nwnx_dialog.
/// @param oPlayer The player object.
int NWNX_Player_GetLanguage(object oPlayer);

/// @brief Override sOldResName with sNewResName of nResType for oPlayer.
/// @warning If sNewResName does not exist on oPlayer's client it will crash their game.
/// @param oPlayer The player object.
/// @param nResType The res type, see nwnx_util.nss for constants.
/// @param sOldResName The old res name, 16 characters or less.
/// @param sNewResName The new res name or "" to clear a previous override, 16 characters or less.
void NWNX_Player_SetResManOverride(object oPlayer, int nResType, string sOldResName, string sNewResName);

/// @}

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

void NWNX_Player_INTERNAL_StopGuiTimingBar(object player, string script = "", int id = -1) ///< @private
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

void NWNX_Player_StartGuiTimingBar(object player, float seconds, string script = "", int type = NWNX_PLAYER_TIMING_BAR_CUSTOM)
{
    if (GetLocalInt(player, "NWNX_PLAYER_GUI_TIMING_ACTIVE"))
        return;

    string sFunc = "StartGuiTimingBar";
    NWNX_PushArgumentInt(NWNX_Player, sFunc, type);
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

void NWNX_Player_UpdateCharacterSheet(object player)
{
    string sFunc = "UpdateCharacterSheet";

    NWNX_PushArgumentObject(NWNX_Player, sFunc, player);

    NWNX_CallFunction(NWNX_Player, sFunc);
}

void NWNX_Player_OpenInventory(object player, object target, int open = TRUE)
{
    string sFunc = "OpenInventory";

    NWNX_PushArgumentInt(NWNX_Player, sFunc, open);
    NWNX_PushArgumentObject(NWNX_Player, sFunc, target);
    NWNX_PushArgumentObject(NWNX_Player, sFunc, player);

    NWNX_CallFunction(NWNX_Player, sFunc);
}

string NWNX_Player_GetAreaExplorationState(object player, object area)
{
    string sFunc = "GetAreaExplorationState";

    NWNX_PushArgumentObject(NWNX_Player, sFunc, area);
    NWNX_PushArgumentObject(NWNX_Player, sFunc, player);

    NWNX_CallFunction(NWNX_Player, sFunc);
    return  NWNX_GetReturnValueString(NWNX_Player, sFunc);
}

void NWNX_Player_SetAreaExplorationState(object player, object area, string str)
{
    string sFunc = "SetAreaExplorationState";

    NWNX_PushArgumentString(NWNX_Player, sFunc, str);
    NWNX_PushArgumentObject(NWNX_Player, sFunc, area);
    NWNX_PushArgumentObject(NWNX_Player, sFunc, player);

    NWNX_CallFunction(NWNX_Player, sFunc);
}

void NWNX_Player_SetRestAnimation(object oPlayer, int nAnimation)
{
    string sFunc = "SetRestAnimation";

    NWNX_PushArgumentInt(NWNX_Player, sFunc, nAnimation);
    NWNX_PushArgumentObject(NWNX_Player, sFunc, oPlayer);

    NWNX_CallFunction(NWNX_Player, sFunc);
}

void NWNX_Player_SetObjectVisualTransformOverride(object oPlayer, object oObject, int nTransform, float fValue)
{
    string sFunc = "SetObjectVisualTransformOverride";

    NWNX_PushArgumentFloat(NWNX_Player, sFunc, fValue);
    NWNX_PushArgumentInt(NWNX_Player, sFunc, nTransform);
    NWNX_PushArgumentObject(NWNX_Player, sFunc, oObject);
    NWNX_PushArgumentObject(NWNX_Player, sFunc, oPlayer);

    NWNX_CallFunction(NWNX_Player, sFunc);
}

void NWNX_Player_ApplyLoopingVisualEffectToObject(object player, object target, int visualeffect)
{
    string sFunc = "ApplyLoopingVisualEffectToObject";

    NWNX_PushArgumentInt(NWNX_Player, sFunc, visualeffect);
    NWNX_PushArgumentObject(NWNX_Player, sFunc, target);
    NWNX_PushArgumentObject(NWNX_Player, sFunc, player);

    NWNX_CallFunction(NWNX_Player, sFunc);
}

void NWNX_Player_SetPlaceableNameOverride(object player, object placeable, string name)
{
    string sFunc = "SetPlaceableNameOverride";

    NWNX_PushArgumentString(NWNX_Player, sFunc, name);
    NWNX_PushArgumentObject(NWNX_Player, sFunc, placeable);
    NWNX_PushArgumentObject(NWNX_Player, sFunc, player);

    NWNX_CallFunction(NWNX_Player, sFunc);
}

int NWNX_Player_GetQuestCompleted(object player, string sQuestName)
{
    string sFunc = "GetQuestCompleted";

    NWNX_PushArgumentString(NWNX_Player, sFunc, sQuestName);
    NWNX_PushArgumentObject(NWNX_Player, sFunc, player);

    NWNX_CallFunction(NWNX_Player, sFunc);
    return NWNX_GetReturnValueInt(NWNX_Player, sFunc);
}

void NWNX_Player_SetPersistentLocation(string sCDKeyOrCommunityName, string sBicFileName, object oWP, int bFirstConnectOnly = TRUE)
{
    string sFunc = "SetPersistentLocation";

    NWNX_PushArgumentInt(NWNX_Player, sFunc, bFirstConnectOnly);
    NWNX_PushArgumentObject(NWNX_Player, sFunc, oWP);
    NWNX_PushArgumentString(NWNX_Player, sFunc, sBicFileName);
    NWNX_PushArgumentString(NWNX_Player, sFunc, sCDKeyOrCommunityName);

    NWNX_CallFunction(NWNX_Player, sFunc);
}

void NWNX_Player_UpdateItemName(object oPlayer, object oItem)
{
    string sFunc = "UpdateItemName";

    NWNX_PushArgumentObject(NWNX_Player, sFunc, oItem);
    NWNX_PushArgumentObject(NWNX_Player, sFunc, oPlayer);

    NWNX_CallFunction(NWNX_Player, sFunc);
}

int NWNX_Player_PossessCreature(object oPossessor, object oPossessed, int bMindImmune = TRUE, int bCreateDefaultQB = FALSE)
{
    string sFunc = "PossessCreature";

    NWNX_PushArgumentInt(NWNX_Player, sFunc, bCreateDefaultQB);
    NWNX_PushArgumentInt(NWNX_Player, sFunc, bMindImmune);
    NWNX_PushArgumentObject(NWNX_Player, sFunc, oPossessed);
    NWNX_PushArgumentObject(NWNX_Player, sFunc, oPossessor);

    NWNX_CallFunction(NWNX_Player, sFunc);
    return NWNX_GetReturnValueInt(NWNX_Player, sFunc);
}

int NWNX_Player_GetPlatformId(object oPlayer)
{
    string sFunc = "GetPlatformId";

    NWNX_PushArgumentObject(NWNX_Player, sFunc, oPlayer);

    NWNX_CallFunction(NWNX_Player, sFunc);
    return NWNX_GetReturnValueInt(NWNX_Player, sFunc);
}

int NWNX_Player_GetLanguage(object oPlayer)
{
    string sFunc = "GetLanguage";

    NWNX_PushArgumentObject(NWNX_Player, sFunc, oPlayer);

    NWNX_CallFunction(NWNX_Player, sFunc);
    return NWNX_GetReturnValueInt(NWNX_Player, sFunc);
}

void NWNX_Player_SetResManOverride(object oPlayer, int nResType, string sOldResName, string sNewResName)
{
    string sFunc = "SetResManOverride";

    NWNX_PushArgumentString(NWNX_Player, sFunc, sNewResName);
    NWNX_PushArgumentString(NWNX_Player, sFunc, sOldResName);
    NWNX_PushArgumentInt(NWNX_Player, sFunc, nResType);
    NWNX_PushArgumentObject(NWNX_Player, sFunc, oPlayer);

    NWNX_CallFunction(NWNX_Player, sFunc);
}
