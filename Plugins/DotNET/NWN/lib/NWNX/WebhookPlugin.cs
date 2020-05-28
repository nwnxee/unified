namespace NWNX
{
    [NWNXPlugin(NWNX_WebHook)]
    public class WebhookPlugin
    {
        public const string NWNX_WebHook = "NWNX_WebHook";

        // /< @private
        // / @brief Send a slack compatible webhook.
        // / @param host The web server to send the hook.
        // / @param path The path to the hook.
        // / @param message The message to dispatch.
        // / @param username The username to display as the originator of the hook.
        // / @param mrkdwn Set to false if you do not wish your message's markdown be parsed.
        public static void SendWebHookHTTPS(string host, string path, string message, string username = "", int mrkdwn = 1)
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_WebHook, "SendWebHookHTTPS");
            NWN.Internal.NativeFunctions.nwnxPushInt(mrkdwn);
            NWN.Internal.NativeFunctions.nwnxPushString(username);
            NWN.Internal.NativeFunctions.nwnxPushString(message);
            NWN.Internal.NativeFunctions.nwnxPushString(path);
            NWN.Internal.NativeFunctions.nwnxPushString(host);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
        }

        // / @brief Resends a webhook message after a defined delay.
        // /
        // / Handy when a submission is rate limited, since the message that the event sends in NWNX_Events_GetEventData
        // / is already constructed. So it just resends the WebHook with an optional delay.
        // / @param host The web server to send the hook.
        // / @param path The path to the hook.
        // / @param sMessage The message to dispatch.
        // / @param delay The delay in seconds to send the message again.
        public static void ResendWebHookHTTPS(string host, string path, string sMessage, float delay = 0.0f)
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_WebHook, "ResendWebHookHTTPS");
            NWN.Internal.NativeFunctions.nwnxPushFloat(delay);
            NWN.Internal.NativeFunctions.nwnxPushString(sMessage);
            NWN.Internal.NativeFunctions.nwnxPushString(path);
            NWN.Internal.NativeFunctions.nwnxPushString(host);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
        }

        // / @}
    }
}
