#include "nwnx"

////////////////////////////////////////////////////////////////////////////////
/* The following events are exposed by this plugin:
////////////////////////////////////////////////////////////////////////////////
    NWNX_ON_ADD_ASSOCIATE_BEFORE
    NWNX_ON_ADD_ASSOCIATE_AFTER
    NWNX_ON_REMOVE_ASSOCIATE_BEFORE
    NWNX_ON_REMOVE_ASSOCIATE_AFTER

    Usage:
        OBJECT_SELF = The owner of the associate

    Event data:
        Variable Name           Type                Notes
        ASSOCIATE_OBJECT_ID     object              Convert to object with NWNX_Object_StringToObject()
////////////////////////////////////////////////////////////////////////////////
    NWNX_ON_ENTER_STEALTH_BEFORE
    NWNX_ON_ENTER_STEALTH_AFTER
    NWNX_ON_EXIT_STEALTH_BEFORE
    NWNX_ON_EXIT_STEALTH_AFTER

    Usage:
        OBJECT_SELF = The creature entering or exiting stealth
////////////////////////////////////////////////////////////////////////////////
    NWNX_ON_EXAMINE_OBJECT_BEFORE
    NWNX_ON_EXAMINE_OBJECT_AFTER

    Usage:
        OBJECT_SELF = The player examining the object

    Event data:
        Variable Name           Type        Notes
        EXAMINEE_OBJECT_ID      object      Convert to object with NWNX_Object_StringToObject()
////////////////////////////////////////////////////////////////////////////////
    NWNX_ON_USE_ITEM_BEFORE
    NWNX_ON_USE_ITEM_AFTER

    Usage:
        OBJECT_SELF = The creature using the item

    Event data:
        Variable Name           Type        Notes
        ITEM_OBJECT_ID          object      Convert to object with NWNX_Object_StringToObject()
        TARGET_OBJECT_ID        object      ...
        ITEM_PROPERTY_INDEX     int
////////////////////////////////////////////////////////////////////////////////
    NWNX_ON_USE_FEAT_BEFORE
    NWNX_ON_USE_FEAT_AFTER

    Usage:
        OBJECT_SELF = The object using the feat

    Event data:
        Variable Name           Type        Notes
        FEAT_ID                 int
        SUBFEAT_ID              int
        TARGET_OBJECT_ID        object      Convert to object with NWNX_Object_StringToObject()
        AREA_OBJECT_ID          object      ...
        TARGET_POSITION_X       float
        TARGET_POSITION_Y       float
        TARGET_POSITION_Z       float
////////////////////////////////////////////////////////////////////////////////
    NWNX_ON_DM_GIVE_GOLD_BEFORE
    NWNX_ON_DM_GIVE_GOLD_AFTER
    NWNX_ON_DM_GIVE_XP_BEFORE
    NWNX_ON_DM_GIVE_XP_AFTER

    Usage:
        OBJECT_SELF = The DM giving the gold/xp

    Event data:
        Variable Name           Type        Notes
        AMOUNT                  int
        TARGET                  object      Convert to object with NWNX_Object_StringToObject()

    NWNX_ON_DM_GIVE_LEVEL_BEFORE
    NWNX_ON_DM_GIVE_LEVEL_AFTER

    Usage:
        OBJECT_SELF = The DM giving the levels

    Event data:
        Variable Name           Type        Notes
        NUM_LEVELS              int
        TARGET                  object      Convert to object with NWNX_Object_StringToObject()
////////////////////////////////////////////////////////////////////////////////
    NWNX_ON_CLIENT_DISCONNECT_BEFORE
    NWNX_ON_CLIENT_DISCONNECT_AFTER

    Usage:
        OBJECT_SELF = The player disconnecting from the server
////////////////////////////////////////////////////////////////////////////////
    NWNX_ON_START_COMBAT_ROUND_BEFORE
    NWNX_ON_START_COMBAT_ROUND_AFTER

    Usage:
        OBJECT_SELF = The creature starting the combat round

    Event data:
        Variable Name           Type        Notes
        TARGET_OBJECT_ID        object      Convert to object with NWNX_Object_StringToObject()
////////////////////////////////////////////////////////////////////////////////
    NWNX_ON_CAST_SPELL_BEFORE
    NWNX_ON_CAST_SPELL_AFTER

    Usage:
        OBJECT_SELF = The creature casting the spell

    Event data:
        Variable Name           Type        Notes
        SPELL_ID                int
        TARGET_POSITION_X       float
        TARGET_POSITION_Y       float
        TARGET_POSITION_Z       float
        TARGET_OBJECT_ID        object      Convert to object with NWNX_Object_StringToObject()
        ITEM_OBJECT_ID          object      ...
        MULTI_CLASS             int
        SPELL_COUNTERED         int         Returns TRUE if spell was countered else FALSE
        COUNTERING_SPELL        int         Returns TRUE if cast as counter else FALSE
        PROJECTILE_PATH_TYPE    int
        IS_INSTANT_SPELL        int         Returns TRUE if spell was instant else FALSE
////////////////////////////////////////////////////////////////////////////////
    NWNX_ON_USE_HEALER_KIT_BEFORE
    NWNX_ON_USE_HEALER_KIT_AFTER

    Usage:
        OBJECT_SELF = The creature using the Healer's Kit

    Event data:
        Variable Name           Type        Notes
        TARGET_OBJECT_ID        object      Convert to object with NWNX_Object_StringToObject()
        ITEM_OBJECT_ID          object      ...
        ITEM_PROPERTY_INDEX     int
        MOVE_TO_TARGET          int
        ACTION_RESULT           int
////////////////////////////////////////////////////////////////////////////////
    NWNX_ON_PARTY_*_BEFORE
    NWNX_ON_PARTY_*_AFTER

    Replace * with an event listed below

    Usage:
        OBJECT_SELF = The player doing the action

    *** FORMAT ***
    Event
        Event data:
        Variable Name       Type        Notes
    *** ***

    LEAVE
        LEAVING             object      Convert to object with NWNX_Object_StringToObject()

    KICK
        KICKED              object      ...

    TRANSFER_LEADERSHIP
        NEW_LEADER          object      ...

    INVITE
        INVITED             object      ...

    IGNORE_INVITATION
        INVITED_BY          object      ...

    ACCEPT_INVITATION
        INVITED_BY          object      ...

    REJECT_INVITATION
        INVITED_BY          object      ...

    KICK_HENCHMAN
        INVITED_BY          object      ...
*///////////////////////////////////////////////////////////////////////////////

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

// Skips execution of the currently executing event.
// If this is a NWNX event, that means that the base function call won't be called.
// This won't impact any other subscribers, nor dispatch for before / after functions.
// For example, if you are subscribing to NWNX_ON_EXAMINE_OBJECT_BEFORE, and you skip ...
// - The other subscribers will still be called.
// - The original function in the base game will be skipped.
// - The matching after event (NWNX_ON_EXAMINE_OBJECT_AFTER) will also be executed.
//
// THIS SHOULD ONLY BE CALLED FROM WITHIN AN EVENT HANDLER.
// ONLY WORKS WITH HEALER'S KIT EVENT
void NWNX_Events_SkipEvent();

// Set the return value of the event.
//
// THIS SHOULD ONLY BE CALLED FROM WITHIN AN EVENT HANDLER.
void NWNX_Events_SetEventResult(string data);


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

void NWNX_Events_SkipEvent()
{
    NWNX_CallFunction("NWNX_Events", "SKIP_EVENT");
}

void NWNX_Events_SetEventResult(string data)
{
    NWNX_PushArgumentString("NWNX_Events", "EVENT_RESULT", data);
    NWNX_CallFunction("NWNX_Events", "EVENT_RESULT");
}
