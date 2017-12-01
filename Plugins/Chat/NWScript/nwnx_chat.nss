#include "nwnx"

const int NWNX_CHAT_CHANNEL_PLAYER_TALK     = 1;
const int NWNX_CHAT_CHANNEL_PLAYER_SHOUT    = 2;
const int NWNX_CHAT_CHANNEL_PLAYER_WHISPER  = 3;
const int NWNX_CHAT_CHANNEL_PLAYER_TELL     = 4;
const int NWNX_CHAT_CHANNEL_SERVER_MSG      = 5;
const int NWNX_CHAT_CHANNEL_PLAYER_PARTY    = 6;
const int NWNX_CHAT_CHANNEL_PLAYER_DM       = 14;
const int NWNX_CHAT_CHANNEL_DM_TALK         = 17;
const int NWNX_CHAT_CHANNEL_DM_SHOUT        = 18;
const int NWNX_CHAT_CHANNEL_DM_WHISPER      = 19;
const int NWNX_CHAT_CHANNEL_DM_TELL         = 20;
const int NWNX_CHAT_CHANNEL_DM_PARTY        = 22;
const int NWNX_CHAT_CHANNEL_DM_DM           = 30;

// Sends a chat message. Channel is a NWNX_* constant.
// If no target is provided, then it broadcasts to all eligible targets.
// Returns TRUE if successful, FALSE otherwise.
int NWNX_Chat_SendMessage(int channel, string message, object sender = OBJECT_SELF, object target = OBJECT_INVALID);

// Registers the script which receives all chat messages.
// If a script was previously registered, this one will take over.
void NWNX_Chat_RegisterChatScript(string script);

// Skips the message.
// Must be called from an chat or system script handler.
void NWNX_Chat_SkipMessage();

// Gets the channel. Channel is a NWNX_* constant.
// Must be called from an chat or system script handler.
int NWNX_Chat_GetChannel();

// Gets the message.
// Must be called from an chat or system script handler.
string NWNX_Chat_GetMessage();

// Gets the sender.
// Must be called from an chat or system script handler.
object NWNX_Chat_GetSender();

// Gets the target. May be OBJECT_INVALID if no target.
// Must be called from an chat or system script handler.
object NWNX_Chat_GetTarget();

int NWNX_Chat_SendMessage(int channel, string message, object sender = OBJECT_SELF, object target = OBJECT_INVALID)
{
    NWNX_PushArgumentObject("NWNX_Chat", "SEND_MESSAGE", target);
    NWNX_PushArgumentObject("NWNX_Chat", "SEND_MESSAGE", sender);
    NWNX_PushArgumentString("NWNX_Chat", "SEND_MESSAGE", message);
    NWNX_PushArgumentInt("NWNX_Chat", "SEND_MESSAGE", channel);
    NWNX_CallFunction("NWNX_Chat", "SEND_MESSAGE");
    return NWNX_GetReturnValueInt("NWNX_Chat", "SEND_MESSAGE");
}

void NWNX_Chat_RegisterChatScript(string script)
{
    NWNX_PushArgumentString("NWNX_Chat", "REGISTER_CHAT_SCRIPT", script);
    NWNX_CallFunction("NWNX_Chat", "REGISTER_CHAT_SCRIPT");
}

void NWNX_Chat_SkipMessage()
{
    NWNX_CallFunction("NWNX_Chat", "SKIP_MESSAGE");
}

int NWNX_Chat_GetChannel()
{
    NWNX_CallFunction("NWNX_Chat", "GET_CHANNEL");
    return NWNX_GetReturnValueInt("NWNX_Chat", "GET_CHANNEL");
}

string NWNX_Chat_GetMessage()
{
    NWNX_CallFunction("NWNX_Chat", "GET_MESSAGE");
    return NWNX_GetReturnValueString("NWNX_Chat", "GET_MESSAGE");
}

object NWNX_Chat_GetSender()
{
    NWNX_CallFunction("NWNX_Chat", "GET_SENDER");
    return NWNX_GetReturnValueObject("NWNX_Chat", "GET_SENDER");
}

object NWNX_Chat_GetTarget()
{
    NWNX_CallFunction("NWNX_Chat", "GET_TARGET");
    return NWNX_GetReturnValueObject("NWNX_Chat", "GET_TARGET");
}