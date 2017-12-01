#include "nwnx"

// Gets, sets, and clears the current player password.
// Note that this password can be an empty string.
string NWNX_Administration_GetPlayerPassword();
void NWNX_Administration_SetPlayerPassword(string password);
void NWNX_Administration_ClearPlayerPassword();

// Gets and sets the current DM password.
// Note that this password can be an empty string.
string NWNX_Administration_GetDMPassword();
void NWNX_Administration_SetDMPassword(string password);

// Signals the server to immediately shut down.
void NWNX_Administration_ShutdownServer();

// Boots the provided player from the server with the provided strref as message.
void NWNX_Administration_BootPCWithMessage(object pc, int strref);

string NWNX_Administration_GetPlayerPassword()
{
    NWNX_CallFunction("NWNX_Administration", "GET_PLAYER_PASSWORD");
    return NWNX_GetReturnValueString("NWNX_Administration", "GET_PLAYER_PASSWORD");
}

void NWNX_Administration_SetPlayerPassword(string password)
{
    NWNX_PushArgumentString("NWNX_Administration", "SET_PLAYER_PASSWORD", password);
    NWNX_CallFunction("NWNX_Administration", "SET_PLAYER_PASSWORD");
}

void NWNX_Administration_ClearPlayerPassword()
{
    NWNX_CallFunction("NWNX_Administration", "CLEAR_PLAYER_PASSWORD");
}

string NWNX_Administration_GetDMPassword()
{
    NWNX_CallFunction("NWNX_Administration", "GET_DM_PASSWORD");
    return NWNX_GetReturnValueString("NWNX_Administration", "GET_DM_PASSWORD");
}

void NWNX_Administration_SetDMPassword(string password)
{
    NWNX_PushArgumentString("NWNX_Administration", "SET_DM_PASSWORD", password);
    NWNX_CallFunction("NWNX_Administration", "SET_DM_PASSWORD");
}

void NWNX_Administration_ShutdownServer()
{
    NWNX_CallFunction("NWNX_Administration", "SHUTDOWN_SERVER");
}

void NWNX_Administration_BootPCWithMessage(object pc, int strref)
{
    NWNX_PushArgumentInt("NWNX_Administration", "BOOT_PC_WITH_MESSAGE", strref);
    NWNX_PushArgumentObject("NWNX_Administration", "BOOT_PC_WITH_MESSAGE", pc);
    NWNX_CallFunction("NWNX_Administration", "BOOT_PC_WITH_MESSAGE");
}
