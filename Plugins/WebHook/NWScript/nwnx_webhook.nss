#include "nwnx"

// Send a slack compatible webhook
void NWNX_WebHook_SendWebHookHTTPS(string host, string path, string message, string username = "", int mrkdwn = 1);

// Handy when a submission is rate limited, since the message that the event sends in NWNX_Events_GetEventData
// is already constructed. So it just resends the WebHook with an optional delay
void NWNX_WebHook_ResendWebHookHTTPS(string host, string path, string sMessage, float delay = 0.0f);

void NWNX_WebHook_SendWebHookHTTPS(string host, string path, string message, string username = "", int mrkdwn = 1)
{
    string sFunc = "SEND_WEBHOOK_HTTPS";
    NWNX_PushArgumentInt("NWNX_WebHook", sFunc, mrkdwn);
    NWNX_PushArgumentString("NWNX_WebHook", sFunc, username);
    NWNX_PushArgumentString("NWNX_WebHook", sFunc, message);
    NWNX_PushArgumentString("NWNX_WebHook", sFunc, path);
    NWNX_PushArgumentString("NWNX_WebHook", sFunc, host);
    NWNX_CallFunction("NWNX_WebHook", sFunc);
}

void NWNX_WebHook_ResendWebHookHTTPS(string host, string path, string sMessage, float delay = 0.0f)
{
    DelayCommand(delay, NWNX_WebHook_SendWebHookHTTPS(host, path, sMessage));
}
