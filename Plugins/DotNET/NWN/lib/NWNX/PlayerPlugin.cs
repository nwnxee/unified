namespace NWNX
{
    [NWNXPlugin(NWNX_Player)]
    public class PlayerPlugin
    {
        public const string NWNX_Player = "NWNX_Player";

        // /< @private
        // / @brief A quickbar slot.
        // / @name Timing Bar Types
        // / @anchor timing_bar_types
        // /
        // / The various types of timing bars.
        // / @{
        public const int NWNX_PLAYER_TIMING_BAR_TRAP_FLAG = 1;
        public const int NWNX_PLAYER_TIMING_BAR_TRAP_RECOVER = 2;
        public const int NWNX_PLAYER_TIMING_BAR_TRAP_DISARM = 3;
        public const int NWNX_PLAYER_TIMING_BAR_TRAP_EXAMINE = 4;
        public const int NWNX_PLAYER_TIMING_BAR_TRAP_SET = 5;
        public const int NWNX_PLAYER_TIMING_BAR_REST = 6;
        public const int NWNX_PLAYER_TIMING_BAR_UNLOCK = 7;
        public const int NWNX_PLAYER_TIMING_BAR_LOCK = 8;
        public const int NWNX_PLAYER_TIMING_BAR_CUSTOM = 10;

        // / @}
        // / @name Platform IDs
        // / @anchor platform_ids
        // / @{
        public const int NWNX_PLAYER_PLATFORM_INVALID = 0;
        public const int NWNX_PLAYER_PLATFORM_WINDOWS_X86 = 1;
        public const int NWNX_PLAYER_PLATFORM_WINDOWS_X64 = 2;
        public const int NWNX_PLAYER_PLATFORM_LINUX_X86 = 10;
        public const int NWNX_PLAYER_PLATFORM_LINUX_X64 = 11;
        public const int NWNX_PLAYER_PLATFORM_LINUX_ARM32 = 12;
        public const int NWNX_PLAYER_PLATFORM_LINUX_ARM64 = 13;
        public const int NWNX_PLAYER_PLATFORM_MAC_X86 = 20;
        public const int NWNX_PLAYER_PLATFORM_MAC_X64 = 21;
        public const int NWNX_PLAYER_PLATFORM_IOS = 30;
        public const int NWNX_PLAYER_PLATFORM_ANDROID_ARM32 = 40;
        public const int NWNX_PLAYER_PLATFORM_ANDROID_ARM64 = 41;
        public const int NWNX_PLAYER_PLATFORM_ANDROID_X64 = 42;
        public const int NWNX_PLAYER_PLATFORM_NINTENDO_SWITCH = 50;
        public const int NWNX_PLAYER_PLATFORM_MICROSOFT_XBOXONE = 60;
        public const int NWNX_PLAYER_PLATFORM_SONY_PS4 = 70;

        // / @}
        // / @brief Force display placeable examine window for player
        // / @note If used on a placeable in a different area than the player, the portait will not be shown.
        // / @param player The player object.
        // / @param placeable The placeable object.
        public static void ForcePlaceableExamineWindow(uint player, uint placeable)
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Player, "ForcePlaceableExamineWindow");
            NWN.Internal.NativeFunctions.nwnxPushObject(placeable);
            NWN.Internal.NativeFunctions.nwnxPushObject(player);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
        }

        // / @brief Force opens the target object's inventory for the player.
        // / @note
        // / * If the placeable is in a different area than the player, the portrait will not be shown
        // / * The placeable's open/close animations will be played
        // / * Clicking the 'close' button will cause the player to walk to the placeable If the placeable is in a
        // / different area, the player will just walk to the edge of the current area and stop.
        // / This action can be cancelled manually.
        // / * Walking will close the placeable automatically.
        // / @param player The player object.
        // / @param placeable The placeable object.
        public static void ForcePlaceableInventoryWindow(uint player, uint placeable)
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Player, "ForcePlaceableInventoryWindow");
            NWN.Internal.NativeFunctions.nwnxPushObject(placeable);
            NWN.Internal.NativeFunctions.nwnxPushObject(player);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
        }

        // / @brief Starts displaying a timing bar.
        // / @param player The player object.
        // / @param seconds The length of time the timing bar will complete.
        // / @param script The script to run at the bar's completion.
        // / @param type The @ref timing_bar_types "Timing Bar Type"
        // / @remark Only one timing bar can be ran at the same time.
        public static void StartGuiTimingBar(uint player, float seconds, string script = "", int type = NWNX_PLAYER_TIMING_BAR_CUSTOM)
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Player, "StartGuiTimingBar");
            NWN.Internal.NativeFunctions.nwnxPushInt(type);
            NWN.Internal.NativeFunctions.nwnxPushString(script);
            NWN.Internal.NativeFunctions.nwnxPushFloat(seconds);
            NWN.Internal.NativeFunctions.nwnxPushObject(player);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
        }

        // / @brief Stop displaying a timing bar.
        // / @param player The player object.
        // / @param script The script to run when stopped.
        public static void StopGuiTimingBar(uint player, string script = "")
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Player, "StopGuiTimingBar");
            NWN.Internal.NativeFunctions.nwnxPushString(script);
            NWN.Internal.NativeFunctions.nwnxPushObject(player);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
        }

        // / @brief Sets whether the player should always walk when given movement commands.
        // / @param player The player object.
        // / @param bWalk TRUE to set the player to always walk.
        // / @remark Clicking on the ground or using WASD will trigger walking instead of running.
        public static void SetAlwaysWalk(uint player, int bWalk = NWN.NWScript.TRUE)
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Player, "SetAlwaysWalk");
            NWN.Internal.NativeFunctions.nwnxPushInt(bWalk);
            NWN.Internal.NativeFunctions.nwnxPushObject(player);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
        }

        // / @brief Gets the player's quickbar slot info
        // / @param player The player object.
        // / @param slot Slot ID 0-35
        // / @return An NWNX_Player_QuickBarSlot struct.
        public static QuickBarSlot GetQuickBarSlot(uint player, int slot)
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Player, "GetQuickBarSlot");
            NWN.Internal.NativeFunctions.nwnxPushInt(slot);
            NWN.Internal.NativeFunctions.nwnxPushObject(player);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
            QuickBarSlot retVal;
            retVal.oAssociate = NWN.Internal.NativeFunctions.nwnxPopObject();
            retVal.nAssociateType = NWN.Internal.NativeFunctions.nwnxPopInt();
            retVal.nDomainLevel = NWN.Internal.NativeFunctions.nwnxPopInt();
            retVal.nMetaType = NWN.Internal.NativeFunctions.nwnxPopInt();
            retVal.nINTParam1 = NWN.Internal.NativeFunctions.nwnxPopInt();
            retVal.sToolTip = NWN.Internal.NativeFunctions.nwnxPopString();
            retVal.sCommandLine = NWN.Internal.NativeFunctions.nwnxPopString();
            retVal.sCommandLabel = NWN.Internal.NativeFunctions.nwnxPopString();
            retVal.sResRef = NWN.Internal.NativeFunctions.nwnxPopString();
            retVal.nMultiClass = NWN.Internal.NativeFunctions.nwnxPopInt();
            retVal.nObjectType = NWN.Internal.NativeFunctions.nwnxPopInt();
            retVal.oSecondaryItem = NWN.Internal.NativeFunctions.nwnxPopObject();
            retVal.oItem = NWN.Internal.NativeFunctions.nwnxPopObject();
            return retVal;
        }

        // / @brief Sets the player's quickbar slot info
        // / @param player The player object.
        // / @param slot Slot ID 0-35
        // / @param qbs An NWNX_Player_QuickBarSlot struct.
        public static void SetQuickBarSlot(uint player, int slot, QuickBarSlot qbs)
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Player, "SetQuickBarSlot");
            NWN.Internal.NativeFunctions.nwnxPushObject(qbs.oItem);
            NWN.Internal.NativeFunctions.nwnxPushObject(qbs.oSecondaryItem);
            NWN.Internal.NativeFunctions.nwnxPushInt(qbs.nObjectType);
            NWN.Internal.NativeFunctions.nwnxPushInt(qbs.nMultiClass);
            NWN.Internal.NativeFunctions.nwnxPushString(qbs.sResRef);
            NWN.Internal.NativeFunctions.nwnxPushString(qbs.sCommandLabel);
            NWN.Internal.NativeFunctions.nwnxPushString(qbs.sCommandLine);
            NWN.Internal.NativeFunctions.nwnxPushString(qbs.sToolTip);
            NWN.Internal.NativeFunctions.nwnxPushInt(qbs.nINTParam1);
            NWN.Internal.NativeFunctions.nwnxPushInt(qbs.nMetaType);
            NWN.Internal.NativeFunctions.nwnxPushInt(qbs.nDomainLevel);
            NWN.Internal.NativeFunctions.nwnxPushInt(qbs.nAssociateType);
            NWN.Internal.NativeFunctions.nwnxPushObject(qbs.oAssociate);
            NWN.Internal.NativeFunctions.nwnxPushInt(slot);
            NWN.Internal.NativeFunctions.nwnxPushObject(player);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
        }

        // / @brief Get the name of the .bic file associated with the player's character.
        // / @param player The player object.
        // / @return The filename for this player's bic. (Not including the ".bic")
        public static string GetBicFileName(uint player)
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Player, "GetBicFileName");
            NWN.Internal.NativeFunctions.nwnxPushObject(player);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
            return NWN.Internal.NativeFunctions.nwnxPopString();
        }

        // / @brief Plays the VFX at the target position in current area for the given player only
        // / @param player The player object.
        // / @param effectId The effect id.
        // / @param position The position to play the visual effect.
        public static void ShowVisualEffect(uint player, int effectId, NWN.Vector position)
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Player, "ShowVisualEffect");
            NWN.Internal.NativeFunctions.nwnxPushFloat(position.z);
            NWN.Internal.NativeFunctions.nwnxPushFloat(position.y);
            NWN.Internal.NativeFunctions.nwnxPushFloat(position.x);
            NWN.Internal.NativeFunctions.nwnxPushInt(effectId);
            NWN.Internal.NativeFunctions.nwnxPushObject(player);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
        }

        // / @brief Changes the daytime music track for the given player only
        // / @param player The player object.
        // / @param track The track id to play.
        public static void MusicBackgroundChangeDay(uint player, int track)
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Player, "MusicBackgroundChangeDay");
            NWN.Internal.NativeFunctions.nwnxPushInt(track);
            NWN.Internal.NativeFunctions.nwnxPushObject(player);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
        }

        // / @brief Changes the nighttime music track for the given player only
        // / @param player The player object.
        // / @param track The track id to play.
        public static void MusicBackgroundChangeNight(uint player, int track)
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Player, "MusicBackgroundChangeNight");
            NWN.Internal.NativeFunctions.nwnxPushInt(track);
            NWN.Internal.NativeFunctions.nwnxPushObject(player);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
        }

        // / @brief Starts the background music for the given player only
        // / @param player The player object.
        public static void MusicBackgroundStart(uint player)
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Player, "MusicBackgroundStart");
            NWN.Internal.NativeFunctions.nwnxPushObject(player);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
        }

        // / @brief Stops the background music for the given player only
        // / @param player The player object.
        public static void MusicBackgroundStop(uint player)
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Player, "MusicBackgroundStop");
            NWN.Internal.NativeFunctions.nwnxPushObject(player);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
        }

        // / @brief Changes the battle music track for the given player only
        // / @param player The player object.
        // / @param track The track id to play.
        public static void MusicBattleChange(uint player, int track)
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Player, "MusicBattleChange");
            NWN.Internal.NativeFunctions.nwnxPushInt(track);
            NWN.Internal.NativeFunctions.nwnxPushObject(player);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
        }

        // / @brief Starts the battle music for the given player only
        // / @param player The player object.
        public static void MusicBattleStart(uint player)
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Player, "MusicBattleStart");
            NWN.Internal.NativeFunctions.nwnxPushObject(player);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
        }

        // / @brief Stops the battle music for the given player only
        // / @param player The player object.
        public static void MusicBattleStop(uint player)
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Player, "MusicBattleStop");
            NWN.Internal.NativeFunctions.nwnxPushObject(player);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
        }

        // / @brief Play a sound at the location of target for the given player only
        // / @param player The player object.
        // / @param sound The sound resref.
        // / @param target The target object for the sound to originate. If target OBJECT_INVALID the sound
        // / will play at the location of the player.
        public static void PlaySound(uint player, string sound, uint target = NWN.NWScript.OBJECT_INVALID)
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Player, "PlaySound");
            NWN.Internal.NativeFunctions.nwnxPushObject(target);
            NWN.Internal.NativeFunctions.nwnxPushString(sound);
            NWN.Internal.NativeFunctions.nwnxPushObject(player);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
        }

        // / @brief Toggle a placeable's usable flag for the given player only
        // / @param player The player object.
        // / @param placeable The placeable object.
        // / @param usable TRUE for usable.
        public static void SetPlaceableUsable(uint player, uint placeable, int usable)
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Player, "SetPlaceableUsable");
            NWN.Internal.NativeFunctions.nwnxPushInt(usable);
            NWN.Internal.NativeFunctions.nwnxPushObject(placeable);
            NWN.Internal.NativeFunctions.nwnxPushObject(player);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
        }

        // / @brief Override player's rest duration
        // / @param player The player object.
        // / @param duration The duration of rest in milliseconds, 1000 = 1 second. Minimum duration of 10ms. -1 clears the override.
        public static void SetRestDuration(uint player, int duration)
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Player, "SetRestDuration");
            NWN.Internal.NativeFunctions.nwnxPushInt(duration);
            NWN.Internal.NativeFunctions.nwnxPushObject(player);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
        }

        // / @brief Apply visualeffect to target that only player can see
        // / @param player The player object.
        // / @param target The target object to play the effect upon.
        // / @param visualeffect The visual effect id.
        // / @note Only works with instant effects: VFX_COM_*, VFX_FNF_*, VFX_IMP_*
        public static void ApplyInstantVisualEffectToObject(uint player, uint target, int visualeffect)
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Player, "ApplyInstantVisualEffectToObject");
            NWN.Internal.NativeFunctions.nwnxPushInt(visualeffect);
            NWN.Internal.NativeFunctions.nwnxPushObject(target);
            NWN.Internal.NativeFunctions.nwnxPushObject(player);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
        }

        // / @brief Refreshes the players character sheet
        // / @param player The player object.
        // / @note You may need to use DelayCommand if you're manipulating values
        // / through nwnx and forcing a UI refresh, 0.5s seemed to be fine
        public static void UpdateCharacterSheet(uint player)
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Player, "UpdateCharacterSheet");
            NWN.Internal.NativeFunctions.nwnxPushObject(player);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
        }

        // / @brief Allows player to open target's inventory
        // / @param player The player object.
        // / @param target The target object, must be a creature or another player.
        // / @param open TRUE to open.
        // / @remark Only works if player and target are in the same area.
        public static void OpenInventory(uint player, uint target, int open = NWN.NWScript.TRUE)
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Player, "OpenInventory");
            NWN.Internal.NativeFunctions.nwnxPushInt(open);
            NWN.Internal.NativeFunctions.nwnxPushObject(target);
            NWN.Internal.NativeFunctions.nwnxPushObject(player);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
        }

        // / @brief Get player's area exploration state
        // / @param player The player object.
        // / @param area The area object.
        // / @return A string representation of the tiles explored for that area.
        public static string GetAreaExplorationState(uint player, uint area)
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Player, "GetAreaExplorationState");
            NWN.Internal.NativeFunctions.nwnxPushObject(area);
            NWN.Internal.NativeFunctions.nwnxPushObject(player);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
            return NWN.Internal.NativeFunctions.nwnxPopString();
        }

        // / @brief Set player's area exploration state.
        // / @param player The player object.
        // / @param area The area object.
        // / @param str An encoded string obtained with NWNX_Player_GetAreaExplorationState()
        public static void SetAreaExplorationState(uint player, uint area, string str)
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Player, "SetAreaExplorationState");
            NWN.Internal.NativeFunctions.nwnxPushString(str);
            NWN.Internal.NativeFunctions.nwnxPushObject(area);
            NWN.Internal.NativeFunctions.nwnxPushObject(player);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
        }

        // / @brief Override player's rest animation.
        // / @param oPlayer The player object.
        // / @param nAnimation The NWNX animation id. This does not take ANIMATION_LOOPING_* or
        // / ANIMATION_FIREFORGET_* constants. Instead use NWNX_Consts_TranslateNWScriptAnimation() to get
        // / the NWNX equivalent. -1 to clear the override.
        public static void SetRestAnimation(uint oPlayer, int nAnimation)
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Player, "SetRestAnimation");
            NWN.Internal.NativeFunctions.nwnxPushInt(nAnimation);
            NWN.Internal.NativeFunctions.nwnxPushObject(oPlayer);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
        }

        // / @brief Override a visual transform on the given object that only player will see.
        // / @param oPlayer The player object.
        // / @param oObject The target object. Can be any valid Creature, Placeable, Item or Door.
        // / @param nTransform One of OBJECT_VISUAL_TRANSFORM_* or -1 to remove the override.
        // / @param fValue Depends on the transformation to apply.
        public static void SetObjectVisualTransformOverride(uint oPlayer, uint oObject, int nTransform, float fValue)
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Player, "SetObjectVisualTransformOverride");
            NWN.Internal.NativeFunctions.nwnxPushFloat(fValue);
            NWN.Internal.NativeFunctions.nwnxPushInt(nTransform);
            NWN.Internal.NativeFunctions.nwnxPushObject(oObject);
            NWN.Internal.NativeFunctions.nwnxPushObject(oPlayer);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
        }

        // / @brief Apply a looping visualeffect to a target that only player can see
        // / @param player The player object.
        // / @param target The target object.
        // / @param visualeffect A VFX_DUR_*. Calling again will remove an applied effect. -1 to remove all effects
        // / @note Only really works with looping effects: VFX_DUR_*. Other types *kind* of work, they'll play when
        // / reentering the area and the object is in view or when they come back in view range.
        public static void ApplyLoopingVisualEffectToObject(uint player, uint target, int visualeffect)
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Player, "ApplyLoopingVisualEffectToObject");
            NWN.Internal.NativeFunctions.nwnxPushInt(visualeffect);
            NWN.Internal.NativeFunctions.nwnxPushObject(target);
            NWN.Internal.NativeFunctions.nwnxPushObject(player);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
        }

        // / @brief Override the name of placeable for player only
        // / @param player The player object.
        // / @param placeable The placeable object.
        // / @param name The name for the placeable for this player, "" to clear the override.
        public static void SetPlaceableNameOverride(uint player, uint placeable, string name)
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Player, "SetPlaceableNameOverride");
            NWN.Internal.NativeFunctions.nwnxPushString(name);
            NWN.Internal.NativeFunctions.nwnxPushObject(placeable);
            NWN.Internal.NativeFunctions.nwnxPushObject(player);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
        }

        // / @brief Gets whether a quest has been completed by a player
        // / @param player The player object.
        // / @param sQuestName The name identifier of the quest from the Journal Editor.
        // / @return TRUE if the quest has been completed. -1 if the player does not have the journal entry.
        public static int GetQuestCompleted(uint player, string sQuestName)
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Player, "GetQuestCompleted");
            NWN.Internal.NativeFunctions.nwnxPushString(sQuestName);
            NWN.Internal.NativeFunctions.nwnxPushObject(player);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
            return NWN.Internal.NativeFunctions.nwnxPopInt();
        }

        // / @brief Place waypoints on module load representing where a PC should start
        // /
        // / This will require storing the PC's cd key or community name (depending on how you store in your vault)
        // / and bic_filename along with routinely updating their location in some persistent method like OnRest,
        // / OnAreaEnter and OnClentExit.
        // /
        // / @param sCDKeyOrCommunityName The Public CD Key or Community Name of the player, this will depend on your vault type.
        // / @param sBicFileName The filename for the character. Retrieved with NWNX_Player_GetBicFileName().
        // / @param oWP The waypoint object to place where the PC should start.
        // / @param bFirstConnectOnly Set to FALSE if you would like the PC to go to this location every time they login instead
        // / of just every server restart.
        public static void SetPersistentLocation(string sCDKeyOrCommunityName, string sBicFileName, uint oWP, int bFirstConnectOnly = NWN.NWScript.TRUE)
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Player, "SetPersistentLocation");
            NWN.Internal.NativeFunctions.nwnxPushInt(bFirstConnectOnly);
            NWN.Internal.NativeFunctions.nwnxPushObject(oWP);
            NWN.Internal.NativeFunctions.nwnxPushString(sBicFileName);
            NWN.Internal.NativeFunctions.nwnxPushString(sCDKeyOrCommunityName);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
        }

        // / @brief Force an item name to be updated.
        // / @note This is a workaround for bug that occurs when updating item names in open containers.
        // / @param oPlayer The player object.
        // / @param oItem The item object.
        public static void UpdateItemName(uint oPlayer, uint oItem)
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Player, "UpdateItemName");
            NWN.Internal.NativeFunctions.nwnxPushObject(oItem);
            NWN.Internal.NativeFunctions.nwnxPushObject(oPlayer);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
        }

        // / @brief Possesses a creature by temporarily making them a familiar
        // / @details This command allows a PC to possess an NPC by temporarily adding them as a familiar. It will work
        // / if the player already has an existing familiar. The creatures must be in the same area. Unpossession can be
        // / done with the regular @nwn{UnpossessFamiliar} commands.
        // / @note The possessed creature will send automap data back to the possessor.
        // / If you wish to prevent this you may wish to use NWNX_Player_GetAreaExplorationState() and
        // / NWNX_Player_SetAreaExplorationState() before and after the possession.
        // / @note The possessing creature will be left wherever they were when beginning the possession. You may wish
        // / to use @nwn{EffectCutsceneImmobilize} and @nwn{EffectCutsceneGhost} to hide them.
        // / @param oPossessor The possessor player object.
        // / @param oPossessed The possessed creature object. Only works on NPCs.
        // / @param bMindImmune If FALSE will remove the mind immunity effect on the possessor.
        // / @param bCreateDefaultQB If TRUE will populate the quick bar with default buttons.
        // / @return TRUE if possession succeeded.
        public static int PossessCreature(uint oPossessor, uint oPossessed, int bMindImmune = NWN.NWScript.TRUE, int bCreateDefaultQB = NWN.NWScript.FALSE)
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Player, "PossessCreature");
            NWN.Internal.NativeFunctions.nwnxPushInt(bCreateDefaultQB);
            NWN.Internal.NativeFunctions.nwnxPushInt(bMindImmune);
            NWN.Internal.NativeFunctions.nwnxPushObject(oPossessed);
            NWN.Internal.NativeFunctions.nwnxPushObject(oPossessor);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
            return NWN.Internal.NativeFunctions.nwnxPopInt();
        }

        // / @brief Returns the platform ID of the given player (NWNX_PLAYER_PLATFORM_*)
        // / @param oPlayer The player object.
        public static int GetPlatformId(uint oPlayer)
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Player, "GetPlatformId");
            NWN.Internal.NativeFunctions.nwnxPushObject(oPlayer);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
            return NWN.Internal.NativeFunctions.nwnxPopInt();
        }

        // / @brief Returns the game language of the given player (uses NWNX_DIALOG_LANGUAGE_*)
        // / @details This function returns the ID of the game language displayed to the player.
        // / Uses the same constants as nwnx_dialog.
        // / @param oPlayer The player object.
        public static int GetLanguage(uint oPlayer)
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Player, "GetLanguage");
            NWN.Internal.NativeFunctions.nwnxPushObject(oPlayer);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
            return NWN.Internal.NativeFunctions.nwnxPopInt();
        }

        // / @brief Override sOldResName with sNewResName of nResType for oPlayer.
        // / @warning If sNewResName does not exist on oPlayer's client it will crash their game.
        // / @param oPlayer The player object.
        // / @param nResType The res type, see nwnx_util.nss for constants.
        // / @param sOldResName The old res name, 16 characters or less.
        // / @param sNewResName The new res name or "" to clear a previous override, 16 characters or less.
        public static void SetResManOverride(uint oPlayer, int nResType, string sOldResName, string sNewResName)
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Player, "SetResManOverride");
            NWN.Internal.NativeFunctions.nwnxPushString(sNewResName);
            NWN.Internal.NativeFunctions.nwnxPushString(sOldResName);
            NWN.Internal.NativeFunctions.nwnxPushInt(nResType);
            NWN.Internal.NativeFunctions.nwnxPushObject(oPlayer);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
        }

        // / @}
    }

        public struct QuickBarSlot
        {
            public uint oItem;
            public uint oSecondaryItem;
            public int nObjectType;
            public int nMultiClass;
            public string sResRef;
            public string sCommandLabel;
            public string sCommandLine;
            public string sToolTip;
            public int nINTParam1;
            public int nMetaType;
            public int nDomainLevel;
            public int nAssociateType;
            public uint oAssociate;
        }
}
