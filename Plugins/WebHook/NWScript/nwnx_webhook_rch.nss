#include "nwnx_webhook"

struct NWNX_WebHook_Message {
    string sUsername;
    string sText;
    string sAvatarURL;
    string sColor;
    string sAuthorName;
    string sAuthorURL;
    string sAuthorIconURL;
    string sTitle;
    string sURL;
    string sDescription;
    string sThumbnailURL;
    string sImageURL;
    string sFooterText;
    string sFooterURL;
    int iTimestamp;
    string sField1Name;
    string sField1Value;
    int iField1Inline;
    string sField2Name;
    string sField2Value;
    int iField2Inline;
    string sField3Name;
    string sField3Value;
    int iField3Inline;
    string sField4Name;
    string sField4Value;
    int iField4Inline;
    string sField5Name;
    string sField5Value;
    int iField5Inline;
    string sField6Name;
    string sField6Value;
    int iField6Inline;
    string sField7Name;
    string sField7Value;
    int iField7Inline;
    string sField8Name;
    string sField8Value;
    int iField8Inline;
    string sField9Name;
    string sField9Value;
    int iField9Inline;
    string sField10Name;
    string sField10Value;
    int iField10Inline;
};

// Helper function
string IntToBoolString(int iBool);

// Constructs the Slack-compatible JSON message from the struct
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

    // Force a text string of at least a space
    string sMainText = " ";

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
