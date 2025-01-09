/// @addtogroup player
/// @brief Functions exposing additional player properties.
/// @{
/// @file nwnx_player.nss

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

/// @brief A journal entry.
struct NWNX_Player_JournalEntry
{
    string sName;///< @todo Describe
    string sText;///< @todo Describe
    string sTag;///< @todo Describe
    int nState;///< @todo Describe
    int nPriority;///< @todo Describe
    int nQuestCompleted;///< @todo Describe
    int nQuestDisplayed;///< @todo Describe
    int nUpdated;///< @todo Describe
    int nCalendarDay;///< @todo Describe
    int nTimeOfDay;///< @todo Describe
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
/// @param scale The scale of the effect
/// @param translate A translation vector to offset the position of the effect
/// @param rotate A rotation vector to rotate the effect
void NWNX_Player_ShowVisualEffect(object player, int effectId, vector position, float scale=1.0f, vector translate=[], vector rotate=[]);

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
/// @param scale The scale of the effect
/// @param translate A translation vector to offset the position of the effect
/// @param rotate A rotation vector to rotate the effect
/// @note Only works with instant effects: VFX_COM_*, VFX_FNF_*, VFX_IMP_*
void NWNX_Player_ApplyInstantVisualEffectToObject(object player, object target, int visualeffect, float scale=1.0f, vector translate=[], vector rotate=[]);

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

/// @brief Set nCustomTokenNumber to sTokenValue for oPlayer only.
/// @note The basegame SetCustomToken() will override any personal tokens.
/// @param oPlayer The player object.
/// @param nCustomTokenNumber The token number.
/// @param sTokenValue The token text.
void NWNX_Player_SetCustomToken(object oPlayer, int nCustomTokenNumber, string sTokenValue);

/// @brief Override the name of creature for player only
/// @param oPlayer The player object.
/// @param oCreature The creature object.
/// @param sName The name for the creature for this player, "" to clear the override.
void NWNX_Player_SetCreatureNameOverride(object oPlayer, object oCreature, string sName);

/// @brief Display floaty text above oCreature for oPlayer only.
/// @note This will also display the floaty text above creatures that are not part of oPlayer's faction.
/// @param oPlayer The player to display the text to.
/// @param oCreature The creature to display the text above.
/// @param sText The text to display.
/// @param bChatWindow If TRUE, sText will be displayed in oPlayer's chat window.
void NWNX_Player_FloatingTextStringOnCreature(object oPlayer, object oCreature, string sText, int bChatWindow = TRUE);

/// @brief Toggle oPlayer's PlayerDM status.
/// @note This function does nothing for actual DMClient DMs or players with a client version < 8193.14
/// @param oPlayer The player.
/// @param bIsDM TRUE to toggle dm mode on, FALSE for off.
void NWNX_Player_ToggleDM(object oPlayer, int bIsDM);

/// @brief Override the mouse cursor of oObject for oPlayer only
/// @param oPlayer The player object.
/// @param oObject The object.
/// @param nCursor The cursor, one of MOUSECURSOR_*. -1 to clear the override.
void NWNX_Player_SetObjectMouseCursorOverride(object oPlayer, object oObject, int nCursor);

/// @brief Override the hilite color of oObject for oPlayer only
/// @param oPlayer The player object.
/// @param oObject The object.
/// @param nColor The color in 0xRRGGBB format, -1 to clear the override.
void NWNX_Player_SetObjectHiliteColorOverride(object oPlayer, object oObject, int nColor);

/// @brief Remove effects with sEffectTag from oPlayer's TURD
/// @note This function should be called in the NWNX_ON_CLIENT_DISCONNECT_AFTER event, OnClientLeave is too early for the TURD to exist.
/// @param oPlayer The player object.
/// @param sEffectTag The effect tag.
void NWNX_Player_RemoveEffectFromTURD(object oPlayer, string sEffectTag);

/// @brief Set the location oPlayer will spawn when logging in to the server.
/// @note This function is best called in the NWNX_ON_ELC_VALIDATE_CHARACTER_BEFORE event, OnClientEnter will be too late.
/// @param oPlayer The player object.
/// @param locSpawn The location.
void NWNX_Player_SetSpawnLocation(object oPlayer, location locSpawn);

/// @brief Resends palettes to a DM.
/// @param oPlayer - the DM to send them to.
void NWNX_Player_SendDMAllCreatorLists(object oPlayer);

/// @brief Give a custom journal entry to oPlayer.
/// @warning Custom entries are wiped on client enter - they must be reapplied.
/// @param oPlayer The player object.
/// @param journalEntry The journal entry in the form of a struct.
/// @param nSilentUpdate 0 = Notify player via sound effects and feedback message, 1 = Suppress sound effects and feedback message
/// @return a positive number to indicate the new amount of journal entries on the player.
/// @note In contrast to conventional nwn journal entries - this method will overwrite entries with the same tag, so the index / count of entries
/// will only increase if you add new entries with unique tags
int NWNX_Player_AddCustomJournalEntry(object oPlayer, struct NWNX_Player_JournalEntry journalEntry, int nSilentUpdate = 0);

/// @brief Returns a struct containing a journal entry that can then be modified.
/// @param oPlayer The player object.
/// @param questTag The quest tag you wish to get the journal entry for.
/// @return a struct containing the journal entry data.
/// @note This method will return -1 for the Updated field in the event that no matching journal entry was found,
/// only the last matching quest tag will be returned. Eg: If you add 3 journal updates to a player, only the 3rd one will be returned as
/// that is the active one that the player currently sees.
struct NWNX_Player_JournalEntry NWNX_Player_GetJournalEntry(object oPlayer, string questTag);

/// @brief Closes any store oPlayer may have open.
/// @param oPlayer The player object.
void NWNX_Player_CloseStore(object oPlayer);

/// @brief Override nStrRef from the TlkTable with sOverride for oPlayer only.
/// @param oPlayer The player.
/// @param nStrRef The StrRef.
/// @param sOverride The new value for nStrRef or "" to remove the override.
/// @param bRestoreGlobal If TRUE, when removing a personal override it will attempt to restore the global override if it exists.
/// @note Overrides will not persist through relogging.
void NWNX_Player_SetTlkOverride(object oPlayer, int nStrRef, string sOverride, int bRestoreGlobal = TRUE);

/// @brief Make the player reload it's TlkTable.
/// @param oPlayer The player.
void NWNX_Player_ReloadTlk(object oPlayer);

/// @brief Update wind for oPlayer only.
/// @param oPlayer The player.
/// @param vDirection The Wind's direction.
/// @param fMagnitude The Wind's magnitude.
/// @param fYaw The Wind's yaw.
/// @param fPitch The Wind's pitch.
void NWNX_Player_UpdateWind(object oPlayer, vector vDirection, float fMagnitude, float fYaw, float fPitch);

/// @brief Update the SkyBox for oPlayer only.
/// @param oPlayer The player.
/// @param nSkyBox The Skybox ID.
void NWNX_Player_UpdateSkyBox(object oPlayer, int nSkyBox);

/// @brief Update Sun and Moon Fog Color for oPlayer only.
/// @param oPlayer The player.
/// @param nSunFogColor The int value of Sun Fog color.
/// @param nMoonFogColor The int value of Moon Fog color.
void NWNX_Player_UpdateFogColor(object oPlayer, int nSunFogColor, int nMoonFogColor);


/// @brief Update Sun and Moon Fog Amount for oPlayer only.
/// @param oPlayer The player.
/// @param nSunFogAmount The int value of Sun Fog amount (range 0-255).
/// @param nMoonFogAmount The int value of Moon Fog amount (range 0-255).
void NWNX_Player_UpdateFogAmount(object oPlayer, int nSunFogAmount, int nMoonFogAmount);

/// @brief Return's the currently-possessed game object of a player.
/// @param oPlayer The player object (e.g. from GetFirst/NextPC()).
/// @return the actual game object of oPlayer, or OBJECT_INVALID on error.
object NWNX_Player_GetGameObject(object oPlayer);

/// @brief Override the ui discovery mask of oObject for oPlayer only
/// @param oPlayer The player object.
/// @param oObject The target object.
/// @param nMask A mask of OBJECT_UI_DISCOVERY_*, or -1 to clear the override
void NWNX_Player_SetObjectUiDiscoveryMaskOverride(object oPlayer, object oObject, int nMask);

/// @brief Send a party invite from oInviter to oPlayer
/// @param oPlayer The player to invite
/// @param oInviter The one inviting the player
/// @param bForceInvite TRUE: Sends the invite even if the target ignores invites
/// @param bHideDialog TRUE: Does not show the party invitation dialog
void NWNX_Player_SendPartyInvite(object oPlayer, object oInviter, int bForceInvite = FALSE, int bHideDialog = FALSE);

/// @brief Get the TURD for oPlayer
/// @param oPlayer The offline player to get the TURD from
/// @return the TURD object of oPlayer, or OBJECT_INVALID if no TURD exists
object NWNX_Player_GetTURD(object oPlayer);

/// @brief Reloads the color palettes for oPlayer
/// @param oPlayer The player to reload the color palette for
void NWNX_Player_ReloadColorPalettes(object oPlayer);

/// @}

void NWNX_Player_ForcePlaceableExamineWindow(object player, object placeable)
{
    NWNXPushObject(placeable);
    NWNXPushObject(player);
    NWNXCall(NWNX_Player, "ForcePlaceableExamineWindow");
}

void NWNX_Player_ForcePlaceableInventoryWindow(object player, object placeable)
{
    NWNXPushObject(placeable);
    NWNXPushObject(player);
    NWNXCall(NWNX_Player, "ForcePlaceableInventoryWindow");
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
    NWNXPushObject(player);
    NWNXCall(NWNX_Player, "StopGuiTimingBar");
    if(script != "")
    {
        ExecuteScript(script, player);
    }
}

void NWNX_Player_StartGuiTimingBar(object player, float seconds, string script = "", int type = NWNX_PLAYER_TIMING_BAR_CUSTOM)
{
    if (GetLocalInt(player, "NWNX_PLAYER_GUI_TIMING_ACTIVE"))
        return;
    NWNXPushInt(type);
    NWNXPushFloat(seconds);
    NWNXPushObject(player);
    NWNXCall(NWNX_Player, "StartGuiTimingBar");
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
    NWNXPushInt(bWalk);
    NWNXPushObject(player);
    NWNXCall(NWNX_Player, "SetAlwaysWalk");
}

struct NWNX_Player_QuickBarSlot NWNX_Player_GetQuickBarSlot(object player, int slot)
{
    struct NWNX_Player_QuickBarSlot qbs;
    NWNXPushInt(slot);
    NWNXPushObject(player);
    NWNXCall(NWNX_Player, "GetQuickBarSlot");
    qbs.oAssociate     = NWNXPopObject();
    qbs.nAssociateType = NWNXPopInt();
    qbs.nDomainLevel   = NWNXPopInt();
    qbs.nMetaType      = NWNXPopInt();
    qbs.nINTParam1     = NWNXPopInt();
    qbs.sToolTip       = NWNXPopString();
    qbs.sCommandLine   = NWNXPopString();
    qbs.sCommandLabel  = NWNXPopString();
    qbs.sResRef        = NWNXPopString();
    qbs.nMultiClass    = NWNXPopInt();
    qbs.nObjectType    = NWNXPopInt();
    qbs.oSecondaryItem = NWNXPopObject();
    qbs.oItem          = NWNXPopObject();
    return qbs;
}

void NWNX_Player_SetQuickBarSlot(object player, int slot, struct NWNX_Player_QuickBarSlot qbs)
{
    NWNXPushObject(qbs.oItem);
    NWNXPushObject(qbs.oSecondaryItem);
    NWNXPushInt(qbs.nObjectType);
    NWNXPushInt(qbs.nMultiClass);
    NWNXPushString(qbs.sResRef);
    NWNXPushString(qbs.sCommandLabel);
    NWNXPushString(qbs.sCommandLine);
    NWNXPushString(qbs.sToolTip);
    NWNXPushInt(qbs.nINTParam1);
    NWNXPushInt(qbs.nMetaType);
    NWNXPushInt(qbs.nDomainLevel);
    NWNXPushInt(qbs.nAssociateType);
    NWNXPushObject(qbs.oAssociate);
    NWNXPushInt(slot);
    NWNXPushObject(player);
    NWNXCall(NWNX_Player, "SetQuickBarSlot");
}

string NWNX_Player_GetBicFileName(object player)
{
    NWNXPushObject(player);
    NWNXCall(NWNX_Player, "GetBicFileName");
    return NWNXPopString();
}

void NWNX_Player_ShowVisualEffect(object player, int effectId, vector position, float scale=1.0f, vector translate=[], vector rotate=[])
{
    NWNXPushVector(rotate);
    NWNXPushVector(translate);
    NWNXPushFloat(scale);
    NWNXPushVector(position);
    NWNXPushInt(effectId);
    NWNXPushObject(player);
    NWNXCall(NWNX_Player, "ShowVisualEffect");
}

void NWNX_Player_MusicBackgroundChangeDay(object player, int track)
{
    NWNXPushInt(track);
    NWNXPushInt(TRUE);
    NWNXPushObject(player);
    NWNXCall(NWNX_Player, "ChangeBackgroundMusic");
}

void NWNX_Player_MusicBackgroundChangeNight(object player, int track)
{
    NWNXPushInt(track);
    NWNXPushInt(FALSE);
    NWNXPushObject(player);
    NWNXCall(NWNX_Player, "ChangeBackgroundMusic");
}

void NWNX_Player_MusicBackgroundStart(object player)
{
    NWNXPushInt(TRUE);
    NWNXPushObject(player);
    NWNXCall(NWNX_Player, "PlayBackgroundMusic");
}

void NWNX_Player_MusicBackgroundStop(object player)
{
    NWNXPushInt(FALSE);
    NWNXPushObject(player);
    NWNXCall(NWNX_Player, "PlayBackgroundMusic");
}

void NWNX_Player_MusicBattleChange(object player, int track)
{
    NWNXPushInt(track);
    NWNXPushObject(player);
    NWNXCall(NWNX_Player, "ChangeBattleMusic");
}

void NWNX_Player_MusicBattleStart(object player)
{
    NWNXPushInt(TRUE);
    NWNXPushObject(player);
    NWNXCall(NWNX_Player, "PlayBattleMusic");
}

void NWNX_Player_MusicBattleStop(object player)
{
    NWNXPushInt(FALSE);
    NWNXPushObject(player);
    NWNXCall(NWNX_Player, "PlayBattleMusic");
}

void NWNX_Player_PlaySound(object player, string sound, object target = OBJECT_INVALID)
{
    NWNXPushObject(target);
    NWNXPushString(sound);
    NWNXPushObject(player);
    NWNXCall(NWNX_Player, "PlaySound");
}

void NWNX_Player_SetPlaceableUsable(object player, object placeable, int usable)
{
    NWNXPushInt(usable);
    NWNXPushObject(placeable);
    NWNXPushObject(player);
    NWNXCall(NWNX_Player, "SetPlaceableUsable");
}

void NWNX_Player_SetRestDuration(object player, int duration)
{
    NWNXPushInt(duration);
    NWNXPushObject(player);
    NWNXCall(NWNX_Player, "SetRestDuration");
}

void NWNX_Player_ApplyInstantVisualEffectToObject(object player, object target, int visualeffect, float scale=1.0f, vector translate=[], vector rotate=[])
{
    NWNXPushVector(rotate);
    NWNXPushVector(translate);
    NWNXPushFloat(scale);
    NWNXPushInt(visualeffect);
    NWNXPushObject(target);
    NWNXPushObject(player);
    NWNXCall(NWNX_Player, "ApplyInstantVisualEffectToObject");
}

void NWNX_Player_UpdateCharacterSheet(object player)
{
    NWNXPushObject(player);
    NWNXCall(NWNX_Player, "UpdateCharacterSheet");
}

void NWNX_Player_OpenInventory(object player, object target, int open = TRUE)
{
    NWNXPushInt(open);
    NWNXPushObject(target);
    NWNXPushObject(player);
    NWNXCall(NWNX_Player, "OpenInventory");
}

string NWNX_Player_GetAreaExplorationState(object player, object area)
{
    NWNXPushObject(area);
    NWNXPushObject(player);
    NWNXCall(NWNX_Player, "GetAreaExplorationState");
    return  NWNXPopString();
}

void NWNX_Player_SetAreaExplorationState(object player, object area, string str)
{
    NWNXPushString(str);
    NWNXPushObject(area);
    NWNXPushObject(player);
    NWNXCall(NWNX_Player, "SetAreaExplorationState");
}

void NWNX_Player_SetRestAnimation(object oPlayer, int nAnimation)
{
    NWNXPushInt(nAnimation);
    NWNXPushObject(oPlayer);
    NWNXCall(NWNX_Player, "SetRestAnimation");
}

void NWNX_Player_SetObjectVisualTransformOverride(object oPlayer, object oObject, int nTransform, float fValue)
{
    NWNXPushFloat(fValue);
    NWNXPushInt(nTransform);
    NWNXPushObject(oObject);
    NWNXPushObject(oPlayer);
    NWNXCall(NWNX_Player, "SetObjectVisualTransformOverride");
}

void NWNX_Player_ApplyLoopingVisualEffectToObject(object player, object target, int visualeffect)
{
    NWNXPushInt(visualeffect);
    NWNXPushObject(target);
    NWNXPushObject(player);
    NWNXCall(NWNX_Player, "ApplyLoopingVisualEffectToObject");
}

void NWNX_Player_SetPlaceableNameOverride(object player, object placeable, string name)
{
    NWNXPushString(name);
    NWNXPushObject(placeable);
    NWNXPushObject(player);
    NWNXCall(NWNX_Player, "SetPlaceableNameOverride");
}

int NWNX_Player_GetQuestCompleted(object player, string sQuestName)
{
    NWNXPushString(sQuestName);
    NWNXPushObject(player);
    NWNXCall(NWNX_Player, "GetQuestCompleted");
    return NWNXPopInt();
}

void NWNX_Player_SetPersistentLocation(string sCDKeyOrCommunityName, string sBicFileName, object oWP, int bFirstConnectOnly = TRUE)
{
    NWNXPushInt(bFirstConnectOnly);
    NWNXPushObject(oWP);
    NWNXPushString(sBicFileName);
    NWNXPushString(sCDKeyOrCommunityName);
    NWNXCall(NWNX_Player, "SetPersistentLocation");
}

void NWNX_Player_UpdateItemName(object oPlayer, object oItem)
{
    NWNXPushObject(oItem);
    NWNXPushObject(oPlayer);
    NWNXCall(NWNX_Player, "UpdateItemName");
}

int NWNX_Player_PossessCreature(object oPossessor, object oPossessed, int bMindImmune = TRUE, int bCreateDefaultQB = FALSE)
{
    NWNXPushInt(bCreateDefaultQB);
    NWNXPushInt(bMindImmune);
    NWNXPushObject(oPossessed);
    NWNXPushObject(oPossessor);
    NWNXCall(NWNX_Player, "PossessCreature");
    return NWNXPopInt();
}

int NWNX_Player_GetPlatformId(object oPlayer)
{
    NWNXPushObject(oPlayer);
    NWNXCall(NWNX_Player, "GetPlatformId");
    return NWNXPopInt();
}

int NWNX_Player_GetLanguage(object oPlayer)
{
    NWNXPushObject(oPlayer);
    NWNXCall(NWNX_Player, "GetLanguage");
    return NWNXPopInt();
}

void NWNX_Player_SetResManOverride(object oPlayer, int nResType, string sOldResName, string sNewResName)
{
    NWNXPushString(sNewResName);
    NWNXPushString(sOldResName);
    NWNXPushInt(nResType);
    NWNXPushObject(oPlayer);
    NWNXCall(NWNX_Player, "SetResManOverride");
}

void NWNX_Player_SetCustomToken(object oPlayer, int nCustomTokenNumber, string sTokenValue)
{
    NWNXPushString(sTokenValue);
    NWNXPushInt(nCustomTokenNumber);
    NWNXPushObject(oPlayer);
    NWNXCall(NWNX_Player, "SetCustomToken");
}

void NWNX_Player_SetCreatureNameOverride(object oPlayer, object oCreature, string sName)
{
    NWNXPushString(sName);
    NWNXPushObject(oCreature);
    NWNXPushObject(oPlayer);
    NWNXCall(NWNX_Player, "SetCreatureNameOverride");
}

void NWNX_Player_FloatingTextStringOnCreature(object oPlayer, object oCreature, string sText, int bChatWindow = TRUE)
{
    NWNXPushInt(bChatWindow);
    NWNXPushString(sText);
    NWNXPushObject(oCreature);
    NWNXPushObject(oPlayer);
    NWNXCall(NWNX_Player, "FloatingTextStringOnCreature");
}

void NWNX_Player_ToggleDM(object oPlayer, int bIsDM)
{
    NWNXPushInt(bIsDM);
    NWNXPushObject(oPlayer);
    NWNXCall(NWNX_Player, "ToggleDM");
}

void NWNX_Player_SetObjectMouseCursorOverride(object oPlayer, object oObject, int nCursor)
{
    NWNXPushInt(nCursor);
    NWNXPushObject(oObject);
    NWNXPushObject(oPlayer);
    NWNXCall(NWNX_Player, "SetObjectMouseCursorOverride");
}

void NWNX_Player_SetObjectHiliteColorOverride(object oPlayer, object oObject, int nColor)
{
    NWNXPushInt(nColor);
    NWNXPushObject(oObject);
    NWNXPushObject(oPlayer);
    NWNXCall(NWNX_Player, "SetObjectHiliteColorOverride");
}

void NWNX_Player_RemoveEffectFromTURD(object oPlayer, string sEffectTag)
{
    NWNXPushString(sEffectTag);
    NWNXPushObject(oPlayer);
    NWNXCall(NWNX_Player, "RemoveEffectFromTURD");
}

void NWNX_Player_SetSpawnLocation(object oPlayer, location locSpawn)
{
    NWNXPushLocation(locSpawn);
    NWNXPushObject(oPlayer);
    NWNXCall(NWNX_Player, "SetSpawnLocation");
}

void NWNX_Player_SendDMAllCreatorLists(object oPlayer)
{
    NWNXPushObject(oPlayer);
    NWNXCall(NWNX_Player, "SendDMAllCreatorLists");
}

int NWNX_Player_AddCustomJournalEntry(object oPlayer, struct NWNX_Player_JournalEntry journalEntry, int nSilentUpdate = 0)
{
    NWNXPushInt(nSilentUpdate);
    NWNXPushInt(journalEntry.nTimeOfDay);
    NWNXPushInt(journalEntry.nCalendarDay);
    NWNXPushInt(journalEntry.nUpdated);
    NWNXPushInt(journalEntry.nQuestDisplayed);
    NWNXPushInt(journalEntry.nQuestCompleted);
    NWNXPushInt(journalEntry.nPriority);
    NWNXPushInt(journalEntry.nState);
    NWNXPushString(journalEntry.sTag);
    NWNXPushString(journalEntry.sText);
    NWNXPushString(journalEntry.sName);
    NWNXPushObject(oPlayer);
    NWNXCall(NWNX_Player, "AddCustomJournalEntry");
    return NWNXPopInt();
}

struct NWNX_Player_JournalEntry NWNX_Player_GetJournalEntry(object oPlayer, string questTag)
{
    struct NWNX_Player_JournalEntry entry;
    NWNXPushString(questTag);
    NWNXPushObject(oPlayer);
    NWNXCall(NWNX_Player, "GetJournalEntry");
    entry.nUpdated = NWNXPopInt();
    if(entry.nUpdated == -1) // -1 set as an indicator to say that the entry was not found
    {
        return entry;
    }
    entry.nQuestDisplayed = NWNXPopInt();
    entry.nQuestCompleted = NWNXPopInt();
    entry.nPriority = NWNXPopInt();
    entry.nState = NWNXPopInt();
    entry.nTimeOfDay = NWNXPopInt();
    entry.nCalendarDay = NWNXPopInt();
    entry.sName = NWNXPopString();
    entry.sText = NWNXPopString();
    entry.sTag = questTag;
    return entry;
}

void NWNX_Player_CloseStore(object oPlayer)
{
    NWNXPushObject(oPlayer);
    NWNXCall(NWNX_Player, "CloseStore");
}

void NWNX_Player_SetTlkOverride(object oPlayer, int nStrRef, string sOverride, int bRestoreGlobal = TRUE)
{
    NWNXPushInt(bRestoreGlobal);
    NWNXPushString(sOverride);
    NWNXPushInt(nStrRef);
    NWNXPushObject(oPlayer);
    NWNXCall(NWNX_Player, "SetTlkOverride");
}

void NWNX_Player_ReloadTlk(object oPlayer)
{
    NWNXPushObject(oPlayer);
    NWNXCall(NWNX_Player, "ReloadTlk");
}

void NWNX_Player_UpdateWind(object oPlayer, vector vDirection, float fMagnitude, float fYaw, float fPitch)
{
    NWNXPushFloat(fPitch);
    NWNXPushFloat(fYaw);
    NWNXPushFloat(fMagnitude);
    NWNXPushVector(vDirection);
    NWNXPushObject(oPlayer);
    NWNXCall(NWNX_Player, "UpdateWind");
}

void NWNX_Player_UpdateSkyBox(object oPlayer, int nSkyBox)
{
    NWNXPushInt(nSkyBox);
    NWNXPushObject(oPlayer);
    NWNXCall(NWNX_Player, "UpdateSkyBox");
}

void NWNX_Player_UpdateFogColor(object oPlayer, int nSunFogColor, int nMoonFogColor)
{
    NWNXPushInt(nMoonFogColor);
    NWNXPushInt(nSunFogColor);
    NWNXPushObject(oPlayer);
    NWNXCall(NWNX_Player, "UpdateFogColor");
}

void NWNX_Player_UpdateFogAmount(object oPlayer, int nSunFogAmount, int nMoonFogAmount)
{
    NWNXPushInt(nMoonFogAmount);
    NWNXPushInt(nSunFogAmount);
    NWNXPushObject(oPlayer);
    NWNXCall(NWNX_Player, "UpdateFogAmount");
}

object NWNX_Player_GetGameObject(object oPlayer)
{
    NWNXPushObject(oPlayer);
    NWNXCall(NWNX_Player, "GetGameObject");
    return NWNXPopObject();
}

void NWNX_Player_SetObjectUiDiscoveryMaskOverride(object oPlayer, object oObject, int nMask)
{
    NWNXPushInt(nMask);
    NWNXPushObject(oObject);
    NWNXPushObject(oPlayer);
    NWNXCall(NWNX_Player, "SetObjectUiDiscoveryMaskOverride");
}

void NWNX_Player_SendPartyInvite(object oPlayer, object oInviter, int bForceInvite = FALSE, int bHideDialog = FALSE)
{
    NWNXPushInt(bHideDialog);
    NWNXPushInt(bForceInvite);
    NWNXPushObject(oInviter);
    NWNXPushObject(oPlayer);
    NWNXCall(NWNX_Player, "SendPartyInvite");
}

object NWNX_Player_GetTURD(object oPlayer)
{
    NWNXPushObject(oPlayer);
    NWNXCall(NWNX_Player, "GetTURD");
    return NWNXPopObject();
}

void NWNX_Player_ReloadColorPalettes(object oPlayer)
{
    NWNXPushObject(oPlayer);
    NWNXCall(NWNX_Player, "ReloadColorPalettes");
}
