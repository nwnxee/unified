/// @addtogroup chat Chat
/// @brief Functions related to chat.
/// @{
/// @file nwnx_chat.nss
#include "nwnx"

const string NWNX_Chat = "NWNX_Chat"; ///< @private

/// @name Chat Channels
/// @anchor chat_channels
///
/// Constants defining the various chat channels.
/// @{
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
/// @}

/// @brief Sends a chat message.
/// @remark If no target is provided, then it broadcasts to all eligible targets.
/// @param channel The @ref chat_channels "channel" to send the message.
/// @param message The message to send.
/// @param sender The sender of the message.
/// @param target The receiver of the message.
/// @return TRUE if successful, FALSE otherwise.
int NWNX_Chat_SendMessage(int channel, string message, object sender = OBJECT_SELF, object target = OBJECT_INVALID);

/// @brief Registers the script which receives all chat messages.
/// @note If a script was previously registered, this one will take over.
/// @param script The script name to handle the chat events.
void NWNX_Chat_RegisterChatScript(string script);

/// @brief Skips a chat message
/// @note Must be called from a chat or system script handler.
void NWNX_Chat_SkipMessage();

/// @brief Gets the chat @ref chat_channels "channel".
/// @note Must be called from a chat or system script handler.
/// @return The @ref chat_channels "channel" the message is sent.
int NWNX_Chat_GetChannel();

/// @brief Gets the message.
/// @note Must be called from a chat or system script handler.
/// @return The message sent.
string NWNX_Chat_GetMessage();

/// @brief Gets the sender of the message.
/// @note Must be called from a chat or system script handler.
/// @return The object sending the message.
object NWNX_Chat_GetSender();

/// @brief Gets the target of the message.
/// @note Must be called from an chat or system script handler.
/// @return The target of the message or OBJECT_INVALID if no target.
object NWNX_Chat_GetTarget();

/// @brief Sets the distance with which the player hears talks or whispers.
/// @remark Per player settings override server wide.
/// @param distance The distance in meters.
/// @param listener The listener, if OBJECT_INVALID then it will be set server wide.
/// @param channel The @ref chat_channels "channel" to modify the distance heard. Only applicable for talk and whisper.
void NWNX_Chat_SetChatHearingDistance(float distance, object listener = OBJECT_INVALID, int channel = NWNX_CHAT_CHANNEL_PLAYER_TALK);

/// @brief Gets the distance with which the player hears talks or whisper
/// @param listener The listener, if OBJECT_INVALID then will return server wide setting.
/// @param channel The @ref chat_channels "channel". Only applicable for talk and whisper.
float NWNX_Chat_GetChatHearingDistance(object listener = OBJECT_INVALID, int channel = NWNX_CHAT_CHANNEL_PLAYER_TALK);

/// @}

int NWNX_Chat_SendMessage(int channel, string message, object sender = OBJECT_SELF, object target = OBJECT_INVALID)
{
    string sFunc = "SendMessage";

    NWNX_PushArgumentObject(NWNX_Chat, sFunc, target);
    NWNX_PushArgumentObject(NWNX_Chat, sFunc, sender);
    NWNX_PushArgumentString(NWNX_Chat, sFunc, message);
    NWNX_PushArgumentInt(NWNX_Chat, sFunc, channel);
    NWNX_CallFunction(NWNX_Chat, sFunc);
    return NWNX_GetReturnValueInt(NWNX_Chat, sFunc);
}

void NWNX_Chat_RegisterChatScript(string script)
{
    string sFunc = "RegisterChatScript";

    NWNX_PushArgumentString(NWNX_Chat, sFunc, script);
    NWNX_CallFunction(NWNX_Chat, sFunc);
}

void NWNX_Chat_SkipMessage()
{
    string sFunc = "SkipMessage";

    NWNX_CallFunction(NWNX_Chat, sFunc);
}

int NWNX_Chat_GetChannel()
{
    string sFunc = "GetChannel";

    NWNX_CallFunction(NWNX_Chat, sFunc);
    return NWNX_GetReturnValueInt(NWNX_Chat, sFunc);
}

string NWNX_Chat_GetMessage()
{
    string sFunc = "GetMessage";

    NWNX_CallFunction(NWNX_Chat, sFunc);
    return NWNX_GetReturnValueString(NWNX_Chat, sFunc);
}

object NWNX_Chat_GetSender()
{
    string sFunc = "GetSender";

    NWNX_CallFunction(NWNX_Chat, sFunc);
    return NWNX_GetReturnValueObject(NWNX_Chat, sFunc);
}

object NWNX_Chat_GetTarget()
{
    string sFunc = "GetTarget";

    NWNX_CallFunction(NWNX_Chat, sFunc);
    return NWNX_GetReturnValueObject(NWNX_Chat, sFunc);
}

void NWNX_Chat_SetChatHearingDistance(float distance, object listener = OBJECT_INVALID, int channel = NWNX_CHAT_CHANNEL_PLAYER_TALK)
{
    string sFunc = "SetChatHearingDistance";

    NWNX_PushArgumentInt(NWNX_Chat, sFunc, channel);
    NWNX_PushArgumentObject(NWNX_Chat, sFunc, listener);
    NWNX_PushArgumentFloat(NWNX_Chat, sFunc, distance);
    NWNX_CallFunction(NWNX_Chat, sFunc);
}

float NWNX_Chat_GetChatHearingDistance(object listener = OBJECT_INVALID, int channel = NWNX_CHAT_CHANNEL_PLAYER_TALK)
{
    string sFunc = "GetChatHearingDistance";

    NWNX_PushArgumentInt(NWNX_Chat, sFunc, channel);
    NWNX_PushArgumentObject(NWNX_Chat, sFunc, listener);
    NWNX_CallFunction(NWNX_Chat, sFunc);
    return NWNX_GetReturnValueFloat(NWNX_Chat, sFunc);
}
