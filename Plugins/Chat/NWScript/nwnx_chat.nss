/// @addtogroup chat Chat
/// @brief Functions related to chat.
/// @{
/// @file nwnx_chat.nss
#include "nwnx"
#include "nwnx_consts"

const string NWNX_Chat = "NWNX_Chat"; ///< @private

/// @brief Sends a chat message.
/// @remark If no target is provided, then it broadcasts to all eligible targets.
/// @param channel The @ref chat_channels "channel" to send the message.
/// @param message The message to send.
/// @param sender The sender of the message.
/// @param target The receiver of the message.
/// @return TRUE if successful, FALSE otherwise.
/// @deprecated Please use NWNX_Creature_SendMessage()
int NWNX_Chat_SendMessage(int channel, string message, object sender = OBJECT_SELF, object target = OBJECT_INVALID);

/// @brief Registers the script which receives all chat messages.
/// @note If a script was previously registered, this one will take over.
/// @param script The script name to handle the chat events.
/// @deprecated Please use the events system (NWNX_ON_CHAT_SEND_*)
void NWNX_Chat_RegisterChatScript(string script);

/// @brief Skips a chat message
/// @note Must be called from a chat or system script handler.
/// @deprecated Please use the events system (NWNX_ON_CHAT_SEND_*) and NWNX_Events_SkipEvent()
void NWNX_Chat_SkipMessage();

/// @brief Gets the chat @ref chat_channels "channel".
/// @note Must be called from a chat or system script handler.
/// @return The @ref chat_channels "channel" the message is sent.
/// @deprecated Please use the events system (NWNX_ON_CHAT_SEND_*) and NWNX_Events_GetEventData("CHANNEL")
int NWNX_Chat_GetChannel();

/// @brief Gets the message.
/// @note Must be called from a chat or system script handler.
/// @return The message sent.
/// @deprecated Please use the events system (NWNX_ON_CHAT_SEND_*) and NWNX_Events_GetEventData("MESSAGE")
string NWNX_Chat_GetMessage();

/// @brief Gets the sender of the message.
/// @note Must be called from a chat or system script handler.
/// @return The object sending the message.
/// @deprecated Please use the events system (NWNX_ON_CHAT_SEND_*) OBJECT_SELF
object NWNX_Chat_GetSender();

/// @brief Gets the target of the message.
/// @note Must be called from an chat or system script handler.
/// @return The target of the message or OBJECT_INVALID if no target.
/// @deprecated Please use the events system (NWNX_ON_CHAT_SEND_*) and NWNX_Events_GetEventData("TARGET")
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
    WriteTimestampedLogEntry("NWNX_Chat: NWNX_Chat_SendMessage() is deprecated. Please use NWNX_Creature_SendMessage() now. Note the argument order has changed");
    string sFunc = "SendMessage";
    NWNX_PushArgumentObject("NWNX_Creature", sFunc, target);
    NWNX_PushArgumentInt("NWNX_Creature", sFunc, channel);
    NWNX_PushArgumentString("NWNX_Creature", sFunc, message);
    NWNX_PushArgumentObject("NWNX_Creature", sFunc, sender);
    NWNX_CallFunction("NWNX_Creature", sFunc);

    return NWNX_GetReturnValueInt("NWNX_Creature", sFunc);
}

void NWNX_Chat_RegisterChatScript(string script)
{
    WriteTimestampedLogEntry("NWNX_Chat: RegisterChatScript() is deprecated. Please use the event system (NWNX_ON_CHAT_SEND_*)");

    NWNX_PushArgumentString("NWNX_Events", "SubscribeEvent", script);
    NWNX_PushArgumentString("NWNX_Events", "SubscribeEvent", "NWNX_ON_CHAT_SEND_BEFORE");
    NWNX_CallFunction("NWNX_Events", "SubscribeEvent");
}

void NWNX_Chat_SkipMessage()
{
    WriteTimestampedLogEntry("NWNX_Chat: SkipMessage() is deprecated. Please use the event system (NWNX_ON_CHAT_SEND_*)");

    NWNX_CallFunction("NWNX_Events", "SkipEvent");
}

int NWNX_Chat_GetChannel()
{
    WriteTimestampedLogEntry("NWNX_Chat: GetChannel() is deprecated. Please use the event system (NWNX_ON_CHAT_SEND_*)");

    NWNX_PushArgumentString("NWNX_Events", "GetEventData", "CHANNEL");
    NWNX_CallFunction("NWNX_Events", "GetEventData");
    return StringToInt(NWNX_GetReturnValueString("NWNX_Events", "GetEventData"));
}

string NWNX_Chat_GetMessage()
{
    WriteTimestampedLogEntry("NWNX_Chat: GetMessage() is deprecated. Please use the event system (NWNX_ON_CHAT_SEND_*)");

    NWNX_PushArgumentString("NWNX_Events", "GetEventData", "MESSAGE");
    NWNX_CallFunction("NWNX_Events", "GetEventData");
    return NWNX_GetReturnValueString("NWNX_Events", "GetEventData");
}

object NWNX_Chat_GetSender()
{
    WriteTimestampedLogEntry("NWNX_Chat: GetSender() is deprecated. Please use the event system (NWNX_ON_CHAT_SEND_*)");

    NWNX_PushArgumentString("NWNX_Events", "GetEventData", "SENDER");
    NWNX_CallFunction("NWNX_Events", "GetEventData");
    return StringToObject(NWNX_GetReturnValueString("NWNX_Events", "GetEventData"));
}

object NWNX_Chat_GetTarget()
{
    WriteTimestampedLogEntry("NWNX_Chat: GetTarget() is deprecated. This function is no longer useful since targets are only determined in tells and those have been suppressed.");

    NWNX_PushArgumentString("NWNX_Events", "GetEventData", "TARGET");
    NWNX_CallFunction("NWNX_Events", "GetEventData");
    return StringToObject(NWNX_GetReturnValueString("NWNX_Events", "GetEventData"));
}

void NWNX_Chat_SetChatHearingDistance(float distance, object listener = OBJECT_INVALID, int channel = NWNX_CHAT_CHANNEL_PLAYER_TALK)
{
    WriteTimestampedLogEntry("NWNX_Chat: SetChatHearingDistance() is deprecated. This function has been moved to NWNX_Player. Note the argument order has changed");

    string sFunc = "SetChatHearingDistance";

    NWNX_PushArgumentInt("NWNX_Player", sFunc, channel);
    NWNX_PushArgumentFloat("NWNX_Player", sFunc, distance);
    NWNX_PushArgumentObject("NWNX_Player", sFunc, listener);
    NWNX_CallFunction("NWNX_Player", sFunc);
}

float NWNX_Chat_GetChatHearingDistance(object listener = OBJECT_INVALID, int channel = NWNX_CHAT_CHANNEL_PLAYER_TALK)
{
    WriteTimestampedLogEntry("NWNX_Chat: GetChatHearingDistance() is deprecated. This function has been moved to NWNX_Player. Note the argument order has changed.");

    string sFunc = "GetChatHearingDistance";

    NWNX_PushArgumentInt("NWNX_Player", sFunc, channel);
    NWNX_PushArgumentObject("NWNX_Player", sFunc, listener);
    NWNX_CallFunction("NWNX_Player", sFunc);
    return NWNX_GetReturnValueFloat("NWNX_Player", sFunc);
}
