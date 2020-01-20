/// @addtogroup webhook Webhook
/// @brief Send messages to external entities through web hooks.
/// @{
/// @file nwnx_webhook.nss
#include "nwnx"

const string NWNX_WebHook = "NWNX_WebHook"; ///< @private

/// @brief Send a slack compatible webhook.
/// @param host The web server to send the hook.
/// @param path The path to the hook.
/// @param message The message to dispatch.
/// @param username The username to display as the originator of the hook.
/// @param mrkdwn Set to false if you do not wish your message's markdown be parsed.
void NWNX_WebHook_SendWebHookHTTPS(string host, string path, string message, string username = "", int mrkdwn = 1);

/// @brief Resends a webhook message after a defined delay.
///
/// Handy when a submission is rate limited, since the message that the event sends in NWNX_Events_GetEventData
/// is already constructed. So it just resends the WebHook with an optional delay.
/// @param host The web server to send the hook.
/// @param path The path to the hook.
/// @param sMessage The message to dispatch.
/// @param delay The delay in seconds to send the message again.
void NWNX_WebHook_ResendWebHookHTTPS(string host, string path, string sMessage, float delay = 0.0f);

/// @}

void NWNX_WebHook_SendWebHookHTTPS(string host, string path, string message, string username = "", int mrkdwn = 1)
{
    string sFunc = "SendWebHookHTTPS";
    NWNX_PushArgumentInt(NWNX_WebHook, sFunc, mrkdwn);
    NWNX_PushArgumentString(NWNX_WebHook, sFunc, username);
    NWNX_PushArgumentString(NWNX_WebHook, sFunc, message);
    NWNX_PushArgumentString(NWNX_WebHook, sFunc, path);
    NWNX_PushArgumentString(NWNX_WebHook, sFunc, host);
    NWNX_CallFunction(NWNX_WebHook, sFunc);
}

void NWNX_WebHook_ResendWebHookHTTPS(string host, string path, string sMessage, float delay = 0.0f)
{
    DelayCommand(delay, NWNX_WebHook_SendWebHookHTTPS(host, path, sMessage));
}
