@addtogroup testplayer TestPlayer
@page testplayer Readme
@ingroup testplayer

Turns an existing creature into a player character with no client behind it, so scripts that only work on PCs (`GetIsPC()`, `GetFirstPC()`, `GetPCPlayerName()`, `GetPCPublicCDKey()`, SQLite object databases, ...) can be tested on a headless server without anyone logging in.

A fake player takes a free player slot and is added to the server's player list. Everything the server sends it is dropped before it reaches the network, but counted by message type (see `NWNX_TestPlayer_GetMessageCount()`), so a test can check what a client would have been sent. A fake player's character is never saved.

**This plugin is for test servers only.** It does nothing unless `NWNX_TESTPLAYER_ENABLE` is set, so loading it by accident on a live server can't create fake players.

## Environment Variables

| Variable Name | Value | Notes |
| ------------- | :---: | ----- |
| `NWNX_TESTPLAYER_ENABLE` | true or false | Default false. Must be true for `NWNX_TestPlayer_Attach()` to work. |

## Limitations

* Anything that needs a client to answer doesn't work: conversations, NUI events, area transitions started by the client.
* A fake player can't be made a DM.
* The creature should be detached with `NWNX_TestPlayer_Detach()` before it is destroyed: like any PC, it can't be destroyed while it is attached.
* Message counts only cover what goes through `CNWSMessage::SendServerToPlayerMessage()`. The per-tick object updates are one message each, so what is inside them can't be checked.
