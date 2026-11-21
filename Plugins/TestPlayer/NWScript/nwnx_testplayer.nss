/// @addtogroup testplayer TestPlayer
/// @brief Fake players for headless test servers.
/// @remark Does nothing unless NWNX_TESTPLAYER_ENABLE is set. Never enable it on a live server.
/// @{
/// @file nwnx_testplayer.nss

const string NWNX_TestPlayer = "NWNX_TestPlayer"; ///< @private

/// @brief Make a creature a player character with no client behind it.
/// @param oCreature An existing creature that isn't a player character.
/// @param sPlayerName What GetPCPlayerName() will return.
/// @param sCDKey What GetPCPublicCDKey() will return.
/// @return The fake player's id, or 0 on failure.
int NWNX_TestPlayer_Attach(object oCreature, string sPlayerName, string sCDKey);

/// @brief Turn a fake player's creature back into an ordinary creature.
/// @param oCreature The fake player's creature.
/// @return TRUE if oCreature had a fake player.
int NWNX_TestPlayer_Detach(object oCreature);

/// @brief Get whether a creature is controlled by a fake player.
/// @param oCreature The creature.
/// @return TRUE if oCreature is controlled by a fake player.
int NWNX_TestPlayer_GetIsFake(object oCreature);

/// @brief Get a fake player's player id.
/// @param oCreature The fake player's creature.
/// @return The fake player's id, or 0 if oCreature has none.
int NWNX_TestPlayer_GetPlayerId(object oCreature);

/// @brief Get the number of fake players.
/// @return How many fake players there are.
int NWNX_TestPlayer_GetCount();

/// @brief Count the messages the server has sent a fake player, by type.
/// @remark Counts since the player was attached or last cleared. For example, a destroyed item is
/// major 5 (game object update) minor 7. The message types are in NWNXLib/API/Constants/Messages.hpp.
/// @param oCreature The fake player's creature.
/// @param nMajor The message's major type.
/// @param nMinor The message's minor type, or -1 for all of them.
/// @return The number of messages, or 0 if oCreature has no fake player.
int NWNX_TestPlayer_GetMessageCount(object oCreature, int nMajor, int nMinor = -1);

/// @brief Reset a fake player's message counts.
/// @param oCreature The fake player's creature.
/// @return TRUE if oCreature had a fake player.
int NWNX_TestPlayer_ClearMessages(object oCreature);

/// @brief Set whether the server thinks a fake player's inventory window is open.
/// @remark A real client reports this itself. Some functions, like NWNX_Item_RefreshInventoryWindow(), only do something while it is open.
/// @param oCreature The fake player's creature.
/// @param bOpen TRUE for open, FALSE for closed.
/// @return TRUE if oCreature had a fake player.
int NWNX_TestPlayer_SetInventoryOpen(object oCreature, int bOpen = TRUE);

/// @}

int NWNX_TestPlayer_Attach(object oCreature, string sPlayerName, string sCDKey)
{
    NWNXPushString(sCDKey);
    NWNXPushString(sPlayerName);
    NWNXPushObject(oCreature);
    NWNXCall(NWNX_TestPlayer, "Attach");
    return NWNXPopInt();
}

int NWNX_TestPlayer_Detach(object oCreature)
{
    NWNXPushObject(oCreature);
    NWNXCall(NWNX_TestPlayer, "Detach");
    return NWNXPopInt();
}

int NWNX_TestPlayer_GetIsFake(object oCreature)
{
    NWNXPushObject(oCreature);
    NWNXCall(NWNX_TestPlayer, "GetIsFake");
    return NWNXPopInt();
}

int NWNX_TestPlayer_GetPlayerId(object oCreature)
{
    NWNXPushObject(oCreature);
    NWNXCall(NWNX_TestPlayer, "GetPlayerId");
    return NWNXPopInt();
}

int NWNX_TestPlayer_GetCount()
{
    NWNXCall(NWNX_TestPlayer, "GetCount");
    return NWNXPopInt();
}

int NWNX_TestPlayer_GetMessageCount(object oCreature, int nMajor, int nMinor = -1)
{
    NWNXPushInt(nMinor);
    NWNXPushInt(nMajor);
    NWNXPushObject(oCreature);
    NWNXCall(NWNX_TestPlayer, "GetMessageCount");
    return NWNXPopInt();
}

int NWNX_TestPlayer_ClearMessages(object oCreature)
{
    NWNXPushObject(oCreature);
    NWNXCall(NWNX_TestPlayer, "ClearMessages");
    return NWNXPopInt();
}

int NWNX_TestPlayer_SetInventoryOpen(object oCreature, int bOpen = TRUE)
{
    NWNXPushInt(bOpen);
    NWNXPushObject(oCreature);
    NWNXCall(NWNX_TestPlayer, "SetInventoryOpen");
    return NWNXPopInt();
}
