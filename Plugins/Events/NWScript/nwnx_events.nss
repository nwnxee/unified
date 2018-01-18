#include "nwnx"

// The following events are exposed by this plugin:
//
//     NWNX_ON_ADD_ASSOCIATE_BEFORE
//     NWNX_ON_ADD_ASSOCIATE_AFTER
//     NWNX_ON_REMOVE_ASSOCIATE_BEFORE
//     NWNX_ON_REMOVE_ASSOCIATE_AFTER
//
//     NWNX_ON_ENTER_STEALTH_BEFORE
//     NWNX_ON_ENTER_STEALTH_AFTER
//     NWNX_ON_EXIT_STEALTH_BEFORE
//     NWNX_ON_EXIT_STEALTH_AFTER
//
//     NWNX_ON_EXAMINE_OBJECT_BEFORE
//     NWNX_ON_EXAMINE_OBJECT_AFTER
//
//     NWNX_ON_USE_ITEM_BEFORE
//     NWNX_ON_USE_ITEM_AFTER
//
//     NWNX_ON_USE_FEAT_BEFORE
//     NWNX_ON_USE_FEAT_AFTER
//
//     NWNX_ON_DM_GIVE_GOLD (TODO: Upgrade - Currently disabled)
//     NWNX_ON_DM_SET_EXP (TODO: Upgrade - Currently disabled)
//
//     NWNX_ON_CLIENT_DISCONNECT_BEFORE
//     NWNX_ON_CLIENT_DISCONNECT_AFTER
//

// The following variables can be retrieved with the NWNX_Events_GetEventData function.
// Information about the meaning of OBJECT_SELF is also included.
//
//
//      ASSOCIATE EVENTS
//      General Notes:
//      OBJECT_SELF = The owner of the associate
//
//      Variable Name           Type                Notes
//      ASSOCIATE_OBJECT_ID     object              Convert to object with NWNX_Object_StringToObject
//
//
//      STEALTH EVENTS
//      General Notes:
//      OBJECT_SELF = The creature entering or leaving stealth.
//
//
//      Variable Name           Type                Notes
//                      === No Variables ===
//
//
//      EXAMINE OBJECT EVENTS
//      General Notes:
//      OBJECT_SELF = The player examining the object.
//
//
//      Variable Name           Type                Notes
//      EXAMINEE_OBJECT_ID      object              Convert to object with NWNX_Object_StringToObject
//
//
//      USE ITEM EVENTS
//      General Notes:
//      OBJECT_SELF = The creature using the item.
//
//
//      Variable Name           Type                Notes
//      ITEM_OBJECT_ID          object              Convert to object with NWNX_Object_StringToObject
//      TARGET_OBJECT_ID        object              Convert to object with NWNX_Object_StringToObject
//
//
//      USE FEAT EVENTS
//      General Notes:
//      OBJECT_SELF = The creature using the feat.
//
//
//      Variable Name           Type                Notes
//      FEAT_ID                 int
//      SUBFEAT_ID              int
//      TARGET_OBJECT_ID        object              Convert to object with NWNX_Object_StringToObject
//      AREA_OBJECT_ID          object              Convert to object with NWNX_Object_StringToObject
//      TARGET_POSITION_X       float
//      TARGET_POSITION_Y       float
//      TARGET_POSITION_Z       float
//
//
//      CLIENT DISCONNECT EVENTS
//      General Notes: Events won't be processed for disconnecting characters, e.g. RemoveEffect events.
//      OBJECT_SELF = The player leaving the server
//
//
//      Variable Name           Type                Notes
//                      === No Variables ===



// Scripts can subscribe to events.
// Some events are dispatched via the NWNX plugin (see NWNX_EVENTS_EVENT_* constants).
// Others can be signalled via script code (see NWNX_Events_SignalEvent).
void NWNX_Events_SubscribeEvent(string evt, string script);

// Pushes event data at the provided tag, which subscribers can access with GetEventData.
// Thsi should be called BEFORE SignalEvent.
void NWNX_Events_PushEventData(string tag, string data);

// Signals an event. This will dispatch a notification to all subscribed handlers.
// Returns TRUE if anyone was subscribed to the event, FALSE otherwise.
int NWNX_Events_SignalEvent(string evt, object target);

// Retrieves the event data for the currently executing script.
// THIS SHOULD ONLY BE CALLED FROM WITHIN AN EVENT HANDLER.
string NWNX_Events_GetEventData(string tag);

void NWNX_Events_SubscribeEvent(string evt, string script)
{
    NWNX_PushArgumentString("NWNX_Events", "SUBSCRIBE_EVENT", script);
    NWNX_PushArgumentString("NWNX_Events", "SUBSCRIBE_EVENT", evt);
    NWNX_CallFunction("NWNX_Events", "SUBSCRIBE_EVENT");
}

void NWNX_Events_PushEventData(string tag, string data)
{
    NWNX_PushArgumentString("NWNX_Events", "PUSH_EVENT_DATA", data);
    NWNX_PushArgumentString("NWNX_Events", "PUSH_EVENT_DATA", tag);
    NWNX_CallFunction("NWNX_Events", "PUSH_EVENT_DATA");
}

int NWNX_Events_SignalEvent(string evt, object target)
{
    NWNX_PushArgumentObject("NWNX_Events", "SIGNAL_EVENT", target);
    NWNX_PushArgumentString("NWNX_Events", "SIGNAL_EVENT", evt);
    NWNX_CallFunction("NWNX_Events", "SIGNAL_EVENT");
    return NWNX_GetReturnValueInt("NWNX_Events", "SIGNAL_EVENT");
}

string NWNX_Events_GetEventData(string tag)
{
    NWNX_PushArgumentString("NWNX_Events", "GET_EVENT_DATA", tag);
    NWNX_CallFunction("NWNX_Events", "GET_EVENT_DATA");
    return NWNX_GetReturnValueString("NWNX_Events", "GET_EVENT_DATA");
}
