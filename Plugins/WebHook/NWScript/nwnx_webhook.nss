#include "nwnx"

// Over HTTPS, sends message (formatted as application/json in slack compatible format) to hostpath.
// For a Discord webhook, the call to this function would look something like:
//     NWNX_WebHook_SendWebHookHTTPS("discordapp.com", "/api/webhooks/biglongwebhooktoken/slack", "This is my message!");
void NWNX_WebHook_SendWebHookHTTPS(string host, string path, string message, string username="", int mrkdwn=1);

void NWNX_WebHook_SendWebHookHTTPS(string host, string path, string message, string username="", int mrkdwn=1)
{
    NWNX_PushArgumentInt("NWNX_WebHook", "SEND_WEBHOOK_HTTPS", mrkdwn);
    NWNX_PushArgumentString("NWNX_WebHook", "SEND_WEBHOOK_HTTPS", username);
    NWNX_PushArgumentString("NWNX_WebHook", "SEND_WEBHOOK_HTTPS", message);
    NWNX_PushArgumentString("NWNX_WebHook", "SEND_WEBHOOK_HTTPS", path);
    NWNX_PushArgumentString("NWNX_WebHook", "SEND_WEBHOOK_HTTPS", host);
    NWNX_CallFunction("NWNX_WebHook", "SEND_WEBHOOK_HTTPS");
}
