/// @addtogroup chat Chat
/// @brief Functions related to chat.
/// @{
/// @file nwnx_chat.nss

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
    NWNXPushObject(target);
    NWNXPushObject(sender);
    NWNXPushString(message);
    NWNXPushInt(channel);
    NWNXCall(NWNX_Chat, "SendMessage");
    return NWNXPopInt();
}

void NWNX_Chat_RegisterChatScript(string script)
{
    NWNXPushString(script);
    NWNXCall(NWNX_Chat, "RegisterChatScript");
}

void NWNX_Chat_SkipMessage()
{
    NWNXCall(NWNX_Chat, "SkipMessage");
}

int NWNX_Chat_GetChannel()
{
    NWNXCall(NWNX_Chat, "GetChannel");
    return NWNXPopInt();
}

string NWNX_Chat_GetMessage()
{
    NWNXCall(NWNX_Chat, "GetMessage");
    return NWNXPopString();
}

object NWNX_Chat_GetSender()
{
    NWNXCall(NWNX_Chat, "GetSender");
    return NWNXPopObject();
}

object NWNX_Chat_GetTarget()
{
    NWNXCall(NWNX_Chat, "GetTarget");
    return NWNXPopObject();
}

void NWNX_Chat_SetChatHearingDistance(float distance, object listener = OBJECT_INVALID, int channel = NWNX_CHAT_CHANNEL_PLAYER_TALK)
{
    NWNXPushInt(channel);
    NWNXPushObject(listener);
    NWNXPushFloat(distance);
    NWNXCall(NWNX_Chat, "SetChatHearingDistance");
}

float NWNX_Chat_GetChatHearingDistance(object listener = OBJECT_INVALID, int channel = NWNX_CHAT_CHANNEL_PLAYER_TALK)
{
    NWNXPushInt(channel);
    NWNXPushObject(listener);
    NWNXCall(NWNX_Chat, "GetChatHearingDistance");
    return NWNXPopFloat();
}
