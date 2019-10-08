# WebHook Plugin Reference

## Description

Allows the sending of WebHooks. At the moment, only slack application/json format is supported. See https://api.slack.com/incoming-webhooks.

Events exist for SUCCESS or FAILURE.

- Top tip: Append `/slack` to the end of a Discord webhook url for it to work.

## Limitations

For added security, it is highly recommended to set your webhook path as an environment variable and use NWNX_Util_GetEnvironmentVariable() to construct your path.

## Example usage

#### Example 1
The builder wants to be notified with a simple message when the module has completed start up
* At the end of the `on_module_load` script, add the following:
```c
#include "nwnx_webhook"
...
NWNX_WebHook_SendWebHookHTTPS("discordapp.com", NWNX_Util_GetEnvironmentVariable("NWNX_WEBHOOK_DEVELOPER_CHANNEL"), "Module has completed start up.");
...
```

#### Example 2

The builder wishes to create a function to post a bug report to the Discord developer channel.

```c
#include "nwnx_time"
#include "nwnx_util"
#include "nwnx_webhook_rch"

void ReportBug(string sMessage, object oReporter=OBJECT_INVALID)
{
    object oArea = GetArea(oReporter);
    struct NWNX_WebHook_Message stMessage;
    stMessage.sUsername = "NWN Reporter";
    stMessage.sText = "Bug Report";
    stMessage.sAvatarURL = "https://example.com/img/icon.png";
    stMessage.sTitle = "Add to Gitlab?";
    stMessage.sURL = "https://gitlab.example.com/nwn/module/issues/new?issue[title]="+
                     "NWN+Bug+Report&issue[description]="+NWNX_Util_EncodeStringForURL(sMessage);
    stMessage.sColor = "#FF0000";
    stMessage.sAuthorName = GetName(oReporter) + " ("+ GetPCPlayerName(oReporter)+")";
    stMessage.sAuthorIconURL = "https://example.com/img/portrait/" + GetStringLowerCase(GetPortraitResRef(oReporter)) + "t.png";
    stMessage.sThumbnailURL = "https://example.com/img/portrait/po_beetle_s.png";
    stMessage.sDescription = sMessage;
    stMessage.sFooterText = "My_Module_1.00";
    stMessage.sField1Name = "Area Name";
    stMessage.sField1Value = GetName(oArea);
    stMessage.iField1Inline = TRUE;
    stMessage.sField2Name = "Area Tag";
    stMessage.sField2Value = GetTag(oArea);
    stMessage.iField2Inline = TRUE;
    stMessage.sField3Name = "Location";
    stMessage.sField3Value = NWNXLocationToString(GetLocation(oReporter));
    stMessage.iTimestamp = NWNX_Time_GetTimeStamp();
    string sConstructedMsg = NWNX_WebHook_BuildMessageForWebHook("discordapp.com", NWNX_Util_GetEnvironmentVariable("NWNX_WEBHOOK_DEVELOPER_CHANNEL"), stMessage);
    NWNX_WebHook_SendWebHookHTTPS("discordapp.com", NWNX_Util_GetEnvironmentVariable("NWNX_WEBHOOK_DEVELOPER_CHANNEL"), sConstructedMsg);
}

```

#### Example 3
The builder wishes to resend a WebHook when one is disallowed due to rate limitations.
* In module `OnModuleLoad` add:
```c
NWNX_Events_SubscribeEvent("NWNX_ON_WEBHOOK_FAILED", "event_webhook");
```
* Create new `event_webhook` script and enter the following:
```c
#include "nwnx_events"
#include "nwnx_webhook"

void main()
{
    object oModule = OBJECT_SELF;
    string sCurrentEvent = NWNX_Events_GetCurrentEvent();
    if (sCurrentEvent == "NWNX_ON_WEBHOOK_FAILED")
    {
        int iStatus = StringToInt(NWNX_Events_GetEventData("STATUS"));
        // Status 429 means it was Rate Limited
        if (iStatus == 429)
        {
            // Reset is sent in milliseconds
            float delayToSend = StringToFloat(NWNX_Events_GetEventData("RETRY_AFTER")) / 1000.0f;
            PrintString("WebHook rate limited, resending in "+FloatToString(delayToSend)+" seconds.");
            string sMessage = NWNX_Events_GetEventData("MESSAGE");
            string sHost = NWNX_Events_GetEventData("HOST");
            string sPath = NWNX_Events_GetEventData("PATH");
            NWNX_WebHook_ResendWebHookHTTPS(sHost, sPath, sMessage, delayToSend);
        }
    }
}
```

#### Example 4
The builder wishes to notify the general discord channel when a PC reaches a new level.
* In module `OnModuleLoad` add:
```c
NWNX_Events_SubscribeEvent("NWNX_ON_LEVEL_UP_AFTER", "event_level");
```
* Create new `event_level` script and enter the following:
```c
#include "nwnx_events"
#include "nwnx_time"
#include "nwnx_util"
#include "nwnx_webhook_rch"

void main()
{
    object oPC = OBJECT_SELF;
    string sCurrentEvent = NWNX_Events_GetCurrentEvent();
    if (sCurrentEvent == "NWNX_ON_LEVEL_UP_AFTER")
    {
        struct NWNX_WebHook_Message stMessage;
        stMessage.sUsername = "NWN Reporter";
        stMessage.sAvatarURL = "https://example.com/img/icon.png";
        stMessage.sTitle = "New Level!";
        stMessage.sColor = "#0000FF";
        stMessage.sAuthorName = GetName(oPC);
        stMessage.sAuthorIconURL = "https://example.com/img/portrait/" + GetStringLowerCase(GetPortraitResRef(oPC)) + "t.png";
        stMessage.sThumbnailURL = "https://example.com/img/portrait/" + GetStringLowerCase(GetPortraitResRef(oPC)) + "s.png";
        stMessage.sDescription = "**" + GetName(oPC) + "** has reached level **"+IntToString(GetHitDice(oPC))+"**! :tada:";
        stMessage.sFooterText = "My_Module_1.00";
        stMessage.iTimestamp = NWNX_Time_GetTimeStamp();
        string sConstructedMsg = NWNX_WebHook_BuildMessageForWebHook("hook.slack.com", NWNX_Util_GetEnvironmentVariable("NWNX_WEBHOOK_PUBLIC_CHANNEL"), stMessage);
        NWNX_WebHook_SendWebHookHTTPS("hook.slack.com", NWNX_Util_GetEnvironmentVariable("NWNX_WEBHOOK_PUBLIC_CHANNEL"), sConstructedMsg);
    }
}
```

##### Note on Portraits as Images
You may have noticed in this example how portraits are being used in the WebHooks as images. If you want to know how I converted portraits to images to use for this, here were the commands used:
```bash
mkdir /tmp/tga
# From the top level you wish to search for your portraits
# Don't forget to include the stock portraits here as well!
find . \( -iname "*_t.tga" -o -iname "*_s.tga" \) -exec cp -- "{}" /tmp/tga \;
cd /tmp/tga
# Make them all lowercase
rename -f 'y/A-Z/a-z/' *
# Convert to png while cropping bottom unused portion of tga
for i in *_t.tga; do convert $i -crop 16x25+0+0 $i.png; done
for i in *_s.tga; do convert $i -crop 32x50+0+0 $i.png; done
# Rename from foo.tga.png to foo.png
rename s/tga.png/png/ *.tga.png
mkdir /tmp/png
mv *.png /tmp/png
# Now upload to your web server
```