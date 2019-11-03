/// @ingroup webhook
/// @file nwnx_webhook_rch.nss
/// @brief Create richer webhook messages suitable for Discord
#include "nwnx_webhook"

/// @ingroup webhook
/// @brief For more information on these fields see https://birdie0.github.io/discord-webhooks-guide/
/// @note URL fields may require NWNX_Util_EncodeStringForURL().
struct NWNX_WebHook_Message {
    string sUsername; ///< https://birdie0.github.io/discord-webhooks-guide/structure/username.html
    string sText; ///< https://birdie0.github.io/discord-webhooks-guide/structure/content.html
    string sAvatarURL; ///< https://birdie0.github.io/discord-webhooks-guide/structure/avatar_url.html
    string sColor; ///< https://birdie0.github.io/discord-webhooks-guide/structure/embed/color.html
    string sAuthorName; ///< https://birdie0.github.io/discord-webhooks-guide/structure/embed/author.html
    string sAuthorURL; ///< https://birdie0.github.io/discord-webhooks-guide/structure/embed/author.html
    string sAuthorIconURL; ///< https://birdie0.github.io/discord-webhooks-guide/structure/embed/author.html
    string sTitle; ///< https://birdie0.github.io/discord-webhooks-guide/structure/embed/title.html
    string sURL; ///< https://birdie0.github.io/discord-webhooks-guide/structure/embed/url.html
    string sDescription; ///< https://birdie0.github.io/discord-webhooks-guide/structure/embed/description.html
    string sThumbnailURL; ///< https://birdie0.github.io/discord-webhooks-guide/structure/embed/thumbnail.html
    string sImageURL; ///< https://birdie0.github.io/discord-webhooks-guide/structure/embed/image.html
    string sFooterText; ///< https://birdie0.github.io/discord-webhooks-guide/structure/embed/footer.html
    string sFooterURL; ///< https://birdie0.github.io/discord-webhooks-guide/structure/embed/footer.html
    int iTimestamp; ///< https://birdie0.github.io/discord-webhooks-guide/structure/embed/timestamp.html
    string sField1Name; ///< https://birdie0.github.io/discord-webhooks-guide/structure/embed/fields.html
    string sField1Value; ///< https://birdie0.github.io/discord-webhooks-guide/structure/embed/fields.html
    int iField1Inline; ///< https://birdie0.github.io/discord-webhooks-guide/structure/embed/fields.html
    string sField2Name; ///< https://birdie0.github.io/discord-webhooks-guide/structure/embed/fields.html
    string sField2Value; ///< https://birdie0.github.io/discord-webhooks-guide/structure/embed/fields.html
    int iField2Inline; ///< https://birdie0.github.io/discord-webhooks-guide/structure/embed/fields.html
    string sField3Name; ///< https://birdie0.github.io/discord-webhooks-guide/structure/embed/fields.html
    string sField3Value; ///< https://birdie0.github.io/discord-webhooks-guide/structure/embed/fields.html
    int iField3Inline; ///< https://birdie0.github.io/discord-webhooks-guide/structure/embed/fields.html
    string sField4Name; ///< https://birdie0.github.io/discord-webhooks-guide/structure/embed/fields.html
    string sField4Value; ///< https://birdie0.github.io/discord-webhooks-guide/structure/embed/fields.html
    int iField4Inline; ///< https://birdie0.github.io/discord-webhooks-guide/structure/embed/fields.html
    string sField5Name; ///< https://birdie0.github.io/discord-webhooks-guide/structure/embed/fields.html
    string sField5Value; ///< https://birdie0.github.io/discord-webhooks-guide/structure/embed/fields.html
    int iField5Inline; ///< https://birdie0.github.io/discord-webhooks-guide/structure/embed/fields.html
    string sField6Name; ///< https://birdie0.github.io/discord-webhooks-guide/structure/embed/fields.html
    string sField6Value; ///< https://birdie0.github.io/discord-webhooks-guide/structure/embed/fields.html
    int iField6Inline; ///< https://birdie0.github.io/discord-webhooks-guide/structure/embed/fields.html
    string sField7Name; ///< https://birdie0.github.io/discord-webhooks-guide/structure/embed/fields.html
    string sField7Value; ///< https://birdie0.github.io/discord-webhooks-guide/structure/embed/fields.html
    int iField7Inline; ///< https://birdie0.github.io/discord-webhooks-guide/structure/embed/fields.html
    string sField8Name; ///< https://birdie0.github.io/discord-webhooks-guide/structure/embed/fields.html
    string sField8Value; ///< https://birdie0.github.io/discord-webhooks-guide/structure/embed/fields.html
    int iField8Inline; ///< https://birdie0.github.io/discord-webhooks-guide/structure/embed/fields.html
    string sField9Name; ///< https://birdie0.github.io/discord-webhooks-guide/structure/embed/fields.html
    string sField9Value; ///< https://birdie0.github.io/discord-webhooks-guide/structure/embed/fields.html
    int iField9Inline; ///< https://birdie0.github.io/discord-webhooks-guide/structure/embed/fields.html
    string sField10Name; ///< https://birdie0.github.io/discord-webhooks-guide/structure/embed/fields.html
    string sField10Value; ///< https://birdie0.github.io/discord-webhooks-guide/structure/embed/fields.html
    int iField10Inline; ///< https://birdie0.github.io/discord-webhooks-guide/structure/embed/fields.html
};

/// @private We don't need this to be a part of the docs.
/// @brief Helper function to convert 0 or 1 to false or true.
/// @param iBool The integer representation of the boolean.
/// @return The string representation (true or false) of the boolean.
string IntToBoolString(int iBool);

/// @ingroup webhook
/// @brief Builds and sends a rich webhook message based on the constructed NWNX_WebHook_Message.
/// @param host The web server to send the hook.
/// @param path The path to the hook.
/// @param stMessage A constructed NWNX_Webhook_Message.
/// @param mrkdwn Set to false if you do not wish your message's markdown be parsed.
/// @warning Your path must end with /slack if using a Discord webhook.
string NWNX_WebHook_BuildMessageForWebHook(string host, string path, struct NWNX_WebHook_Message stMessage, int mrkdwn = 1);

string IntToBoolString(int iBool)
{
    return iBool == 0 ? "false" : "true";
}

string NWNX_WebHook_BuildMessageForWebHook(string host, string path, struct NWNX_WebHook_Message stMessage, int mrkdwn = 1)
{
    if (host == "discordapp.com" && GetStringRight(path, 6) != "/slack")
    {
        PrintString("Discord WebHook specified but path does not end with /slack");
        return "";
    }

    // Open JSON
    string message = "{";

    string sMainText = "";

    // The only way to turn off markdown for discord is to surround the text in backticks
    if (stMessage.sText != "")
    {
        if (host == "discordapp.com" && !mrkdwn)
            sMainText = "```text\\n" + stMessage.sText + "```";
        else
            sMainText = stMessage.sText;
    }
    message = message + "\"text\": \"" + sMainText + "\"";

    // Slack will turn off markdown
    if (host != "discordapp.com" && !mrkdwn)
        message = message + ",\"mrkdwn\": false";

    // Set the user attributes for the poster
    if (stMessage.sUsername != "")
        message = message + ",\"username\": \"" + stMessage.sUsername + "\"";
    if (stMessage.sAvatarURL != "")
        message = message +  ",\"icon_url\": \"" + stMessage.sAvatarURL + "\"";

    // We need to construct an attachment (embed) object
    if (stMessage.sAuthorName != "" || stMessage.sAuthorURL != "" || stMessage.sAuthorIconURL != "" ||
        stMessage.sTitle != "" || stMessage.sURL != "" || stMessage.sDescription != "" ||
        stMessage.sFooterText != "" || stMessage.sFooterURL != "" || stMessage.iTimestamp > 0 ||
        stMessage.sColor != "" || stMessage.sThumbnailURL != "" || stMessage.sImageURL != "" || stMessage.sField1Name != "")
    {
        message = message + ",\"attachments\": [{\"author_name\": \"" + stMessage.sAuthorName + "\",\"author_link\": \"" + stMessage.sAuthorURL +
                  "\",\"author_icon\": \"" + stMessage.sAuthorIconURL + "\",\"title\": \"" + stMessage.sTitle + "\",\"title_link\": \"" + stMessage.sURL +
                  "\",\"text\": \"" + stMessage.sDescription + "\",\"footer\": \"" + stMessage.sFooterText + "\",\"footer_icon\": \"" + stMessage.sFooterURL +
                  "\",\"color\": \"" + stMessage.sColor + "\",\"thumb_url\": \"" + stMessage.sThumbnailURL +
                  "\",\"image_url\": \"" + stMessage.sImageURL + "\"";

        // Dont post an empty timestamp
        if (stMessage.iTimestamp > 0)
            message = message + ",\"ts\": \"" + IntToString(stMessage.iTimestamp) + "\"";

        // Fields to handle
        if (stMessage.sField1Name != "")
        {
            message = message + ",\"fields\": [";
            message = message + "{\"title\": \"" + stMessage.sField1Name + "\",\"value\": \"" + stMessage.sField1Value + "\",\"short\": " + IntToBoolString(stMessage.iField1Inline) + "}";
            if (stMessage.sField2Name != "")
                message = message + ",{\"title\": \"" + stMessage.sField2Name + "\",\"value\": \"" + stMessage.sField2Value + "\",\"short\": " + IntToBoolString(stMessage.iField2Inline) + "}";
            if (stMessage.sField3Name != "")
                message = message + ",{\"title\": \"" + stMessage.sField3Name + "\",\"value\": \"" + stMessage.sField3Value + "\",\"short\": " + IntToBoolString(stMessage.iField3Inline) + "}";
            if (stMessage.sField4Name != "")
                message = message + ",{\"title\": \"" + stMessage.sField4Name + "\",\"value\": \"" + stMessage.sField4Value + "\",\"short\": " + IntToBoolString(stMessage.iField4Inline) + "}";
            if (stMessage.sField5Name != "")
                message = message + ",{\"title\": \"" + stMessage.sField5Name + "\",\"value\": \"" + stMessage.sField5Value + "\",\"short\": " + IntToBoolString(stMessage.iField5Inline) + "}";
            if (stMessage.sField6Name != "")
                message = message + ",{\"title\": \"" + stMessage.sField6Name + "\",\"value\": \"" + stMessage.sField6Value + "\",\"short\": " + IntToBoolString(stMessage.iField6Inline) + "}";
            if (stMessage.sField7Name != "")
                message = message + ",{\"title\": \"" + stMessage.sField7Name + "\",\"value\": \"" + stMessage.sField7Value + "\",\"short\": " + IntToBoolString(stMessage.iField7Inline) + "}";
            if (stMessage.sField8Name != "")
                message = message + ",{\"title\": \"" + stMessage.sField8Name + "\",\"value\": \"" + stMessage.sField8Value + "\",\"short\": " + IntToBoolString(stMessage.iField8Inline) + "}";
            if (stMessage.sField9Name != "")
                message = message + ",{\"title\": \"" + stMessage.sField9Name + "\",\"value\": \"" + stMessage.sField9Value + "\",\"short\": " + IntToBoolString(stMessage.iField9Inline) + "}";
            if (stMessage.sField10Name != "")
                message = message + ",{\"title\": \"" + stMessage.sField10Name + "\",\"value\": \"" + stMessage.sField10Value + "\",\"short\": " + IntToBoolString(stMessage.iField10Inline) + "}";
            // Close fields array
            message = message + "]";
        }
        // Close attachments array
        message = message + "}]";
    }
    // Close JSON
    message = message + "}";

    return message;
}
