/// @defgroup events Events
/// @brief Provides an interface for plugins to create event-based systems, and exposes some events through that interface.
/// @{
/// @file nwnx_events.nss
#include "nwnx"

const string NWNX_Events = "NWNX_Events"; ///< @private

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
        TRAP_EXAMINE_SUCCESS    int         For trap examine only, whether the examine succeeded
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
        ITEM_SUB_PROPERTY_INDEX int
        TARGET_POSITION_X       float
        TARGET_POSITION_Y       float
        TARGET_POSITION_Z       float

    NWNX_ON_ITEM_INVENTORY_OPEN_BEFORE
    NWNX_ON_ITEM_INVENTORY_OPEN_AFTER
    NWNX_ON_ITEM_INVENTORY_CLOSE_BEFORE
    NWNX_ON_ITEM_INVENTORY_CLOSE_AFTER

    Usage:
        OBJECT_SELF = The container

    Event data:
        Variable Name           Type        Notes
        OWNER                   object      Convert to object with NWNX_Object_StringToObject()

    NWNX_ON_ITEM_INVENTORY_ADD_ITEM_BEFORE
    NWNX_ON_ITEM_INVENTORY_ADD_ITEM_AFTER
    NWNX_ON_ITEM_INVENTORY_REMOVE_ITEM_BEFORE
    NWNX_ON_ITEM_INVENTORY_REMOVE_ITEM_AFTER

    Note: NWNX_ON_ITEM_INVENTORY_REMOVE_ITEM_* is not skippable

    Usage:
        OBJECT_SELF = The container

    Event data:
        Variable Name           Type        Notes
        ITEM                    object      Convert to object with NWNX_Object_StringToObject()

    NWNX_ON_ITEM_AMMO_RELOAD_BEFORE
    NWNX_ON_ITEM_AMMO_RELOAD_AFTER

    Note: Search for the next available ammunition to autoequip

    Usage:
        OBJECT_SELF = The creature whose inventory we're searching for the item type

    Event data:
        Variable Name           Type        Notes
        BASE_ITEM_ID            int
        BASE_ITEM_NTH           int         Find the Nth instance of this item
        ACTION_RESULT           int         The object that was determined in BEFORE (only in after)

    NWNX_ON_ITEM_SCROLL_LEARN_BEFORE
    NWNX_ON_ITEM_SCROLL_LEARN_AFTER

    Usage:
        OBJECT_SELF = The creature learning the scroll

    Event data:
        Variable Name           Type        Notes
        SCROLL                  object      Convert to object with NWNX_Object_StringToObject()

    NWNX_ON_ITEM_EQUIP_BEFORE
    NWNX_ON_ITEM_EQUIP_AFTER

    Usage:
        OBJECT_SELF = The creature equipping the item

    Event data:
        Variable Name           Type        Notes
        ITEM                    object      Convert to object with NWNX_Object_StringToObject()
        SLOT                    int

    NWNX_ON_ITEM_UNEQUIP_BEFORE
    NWNX_ON_ITEM_UNEQUIP_AFTER

    Usage:
        OBJECT_SELF = The creature unequipping the item

    Event data:
        Variable Name           Type        Notes
        ITEM                    object      Convert to object with NWNX_Object_StringToObject()

    NWNX_ON_ITEM_DESTROY_OBJECT_BEFORE
    NWNX_ON_ITEM_DESTROY_OBJECT_AFTER
    NWNX_ON_ITEM_DECREMENT_STACKSIZE_BEFORE
    NWNX_ON_ITEM_DECREMENT_STACKSIZE_AFTER

    Usage:
        OBJECT_SELF = The item triggering the event

    Note: Use of NWNX_ON_ITEM_(DESTROY_OBJECT|DECREMENT_STACKSIZE)_* conflicts with object event handler profiling

    NWNX_ON_ITEM_USE_LORE_BEFORE
    NWNX_ON_ITEM_USE_LORE_AFTER

    Usage:
        OBJECT_SELF = The player attempting to identify an item with their lore skill

    Event data:
        Variable Name           Type        Notes
        ITEM                    object      Convert to object with NWNX_Object_StringToObject()

    NWNX_ON_ITEM_PAY_TO_IDENTIFY_BEFORE
    NWNX_ON_ITEM_PAY_TO_IDENTIFY_AFTER

    Usage:
        OBJECT_SELF = The player attempting to pay to identify an item

    Event data:
        Variable Name           Type        Notes
        ITEM                    object      Convert to object with NWNX_Object_StringToObject()
        STORE                   object      Convert to object with NWNX_Object_StringToObject()

    NWNX_ON_ITEM_SPLIT_BEFORE
    NWNX_ON_ITEM_SPLIT_AFTER

    Usage:
        OBJECT_SELF = The player attempting to split an item

    Event data:
        Variable Name           Type        Notes
        ITEM                    object      Convert to object with NWNX_Object_StringToObject()
        NUMBER_SPLIT_OFF        int

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
    NWNX_ON_DM_GIVE_LEVEL_BEFORE
    NWNX_ON_DM_GIVE_LEVEL_AFTER
    NWNX_ON_DM_GIVE_ALIGNMENT_BEFORE
    NWNX_ON_DM_GIVE_ALIGNMENT_AFTER

    Usage:
        OBJECT_SELF = The DM

    Event data:
        Variable Name           Type        Notes
        AMOUNT                  int
        OBJECT                  object      Convert to object with NWNX_Object_StringToObject()
        ALIGNMENT_TYPE          int         Only valid for NWNX_ON_DM_GIVE_ALIGNMENT_*

    NWNX_ON_DM_SPAWN_OBJECT_BEFORE
    NWNX_ON_DM_SPAWN_OBJECT_AFTER

    Usage:
        OBJECT_SELF = The DM

    Event data:
        Variable Name           Type        Notes
        AREA                    object      Convert to object with NWNX_Object_StringToObject()
        OBJECT                  object      Only returns a valid object in *_AFTER
        OBJECT_TYPE             int         Returns NWNX_EVENTS_OBJECT_TYPE_*, see below
        POS_X                   float
        POS_Y                   float
        POS_Z                   float

    NWNX_ON_DM_GIVE_ITEM_BEFORE
    NWNX_ON_DM_GIVE_ITEM_AFTER

    Usage:
        OBJECT_SELF = The DM

    Event data:
        Variable Name           Type        Notes
        TARGET                  object      Convert to object with NWNX_Object_StringToObject()
        ITEM                    object      Only returns a valid object in *_AFTER

    NWNX_ON_DM_HEAL_BEFORE
    NWNX_ON_DM_HEAL_AFTER
    NWNX_ON_DM_KILL_BEFORE
    NWNX_ON_DM_KILL_AFTER
    NWNX_ON_DM_TOGGLE_INVULNERABLE_BEFORE
    NWNX_ON_DM_TOGGLE_INVULNERABLE_AFTER
    NWNX_ON_DM_FORCE_REST_BEFORE
    NWNX_ON_DM_FORCE_REST_AFTER
    NWNX_ON_DM_LIMBO_BEFORE
    NWNX_ON_DM_LIMBO_AFTER
    NWNX_ON_DM_TOGGLE_AI_BEFORE
    NWNX_ON_DM_TOGGLE_AI_AFTER
    NWNX_ON_DM_TOGGLE_IMMORTAL_BEFORE
    NWNX_ON_DM_TOGGLE_IMMORTAL_AFTER

    Usage:
        OBJECT_SELF = The DM

    Event data:
        Variable Name           Type        Notes
        NUM_TARGETS             int         The number of targets affected
        TARGET_*                object      * = 1 <= NUM_TARGETS

    NWNX_ON_DM_GOTO_BEFORE
    NWNX_ON_DM_GOTO_AFTER
    NWNX_ON_DM_POSSESS_BEFORE
    NWNX_ON_DM_POSSESS_AFTER
    NWNX_ON_DM_POSSESS_FULL_POWER_BEFORE
    NWNX_ON_DM_POSSESS_FULL_POWER_AFTER
    NWNX_ON_DM_TOGGLE_LOCK_BEFORE
    NWNX_ON_DM_TOGGLE_LOCK_AFTER
    NWNX_ON_DM_DISABLE_TRAP_BEFORE
    NWNX_ON_DM_DISABLE_TRAP_AFTER

    !!! Notice: If TARGET is OBJECT_INVALID for NWNX_ON_DM_POSSESS_*, the DM is unpossessing. !!!

    Usage:
        OBJECT_SELF = The DM

    Event data:
        Variable Name           Type        Notes
        TARGET                  object      Convert to object with NWNX_Object_StringToObject()

    NWNX_ON_DM_JUMP_TO_POINT_BEFORE
    NWNX_ON_DM_JUMP_TO_POINT_AFTER
    NWNX_ON_DM_JUMP_TARGET_TO_POINT_BEFORE
    NWNX_ON_DM_JUMP_TARGET_TO_POINT_AFTER
    NWNX_ON_DM_JUMP_ALL_PLAYERS_TO_POINT_BEFORE
    NWNX_ON_DM_JUMP_ALL_PLAYERS_TO_POINT_AFTER

    Usage:
        OBJECT_SELF = The DM

    Event data:
        Variable Name           Type        Notes
        TARGET_AREA             object      Convert to object with NWNX_Object_StringToObject()
        POS_X                   float
        POS_Y                   float
        POS_Z                   float
        NUM_TARGETS             int         Only valid for NWNX_ON_DM_JUMP_TARGET_TO_POINT_*
        TARGET_*                object      * = 1 <= NUM_TARGETS, Only valid for NWNX_ON_DM_JUMP_TARGET_TO_POINT_*

    NWNX_ON_DM_CHANGE_DIFFICULTY_BEFORE
    NWNX_ON_DM_CHANGE_DIFFICULTY_AFTER

    Usage:
        OBJECT_SELF = The DM

    Event data:
        Variable Name           Type        Notes
        DIFFICULTY_SETTING      int

    NWNX_ON_DM_VIEW_INVENTORY_BEFORE
    NWNX_ON_DM_VIEW_INVENTORY_AFTER

    Usage:
        OBJECT_SELF = The DM

    Event data:
        Variable Name           Type        Notes
        OPEN_INVENTORY          int         TRUE if opening an inventory, FALSE if closing
        TARGET                  object      Convert to object with NWNX_Object_StringToObject()

    NWNX_ON_DM_SPAWN_TRAP_ON_OBJECT_BEFORE
    NWNX_ON_DM_SPAWN_TRAP_ON_OBJECT_AFTER

    Usage:
        OBJECT_SELF = The DM

    Event data:
        Variable Name           Type        Notes
        AREA                    object      Convert to object with NWNX_Object_StringToObject()
        TARGET                  object      Convert to object with NWNX_Object_StringToObject()

    NWNX_ON_DM_APPEAR_BEFORE
    NWNX_ON_DM_APPEAR_AFTER
    NWNX_ON_DM_DISAPPEAR_BEFORE
    NWNX_ON_DM_DISAPPEAR_AFTER
    NWNX_ON_DM_SET_FACTION_BEFORE
    NWNX_ON_DM_SET_FACTION_AFTER
    NWNX_ON_DM_TAKE_ITEM_BEFORE
    NWNX_ON_DM_TAKE_ITEM_AFTER
    NWNX_ON_DM_SET_STAT_BEFORE
    NWNX_ON_DM_SET_STAT_AFTER
    NWNX_ON_DM_GET_VARIABLE_BEFORE
    NWNX_ON_DM_GET_VARIABLE_AFTER
    NWNX_ON_DM_SET_VARIABLE_BEFORE
    NWNX_ON_DM_SET_VARIABLE_AFTER
    NWNX_ON_DM_SET_TIME_BEFORE
    NWNX_ON_DM_SET_TIME_AFTER
    NWNX_ON_DM_SET_DATE_BEFORE
    NWNX_ON_DM_SET_DATE_AFTER
    NWNX_ON_DM_SET_FACTION_REPUTATION_BEFORE
    NWNX_ON_DM_SET_FACTION_REPUTATION_AFTER
    NWNX_ON_DM_GET_FACTION_REPUTATION_BEFORE
    NWNX_ON_DM_GET_FACTION_REPUTATION_AFTER
    NWNX_ON_DM_DUMP_LOCALS_BEFORE
    NWNX_ON_DM_DUMP_LOCALS_AFTER

    These events do not have event data implemented and can only be skipped

    Usage:
        OBJECT_SELF = The DM

    Event data:
        Variable Name           Type        Notes
////////////////////////////////////////////////////////////////////////////////
    NWNX_ON_CLIENT_DISCONNECT_BEFORE
    NWNX_ON_CLIENT_DISCONNECT_AFTER

    Usage:
        OBJECT_SELF = The player disconnecting from the server
////////////////////////////////////////////////////////////////////////////////
    NWNX_ON_CLIENT_CONNECT_BEFORE
    NWNX_ON_CLIENT_CONNECT_AFTER

    Skipping the _BEFORE event will cause the client's connection to be denied.
    You can optionally pass a reason for this in the event result.

    Usage:
        OBJECT_SELF = The module

    Event data:
        Variable Name           Type        Notes
        PLAYER_NAME             string      Player name of the connecting client
        CDKEY                   string      Public cdkey of the connecting client
        IS_DM                   int         Whether the client is connect as DM (1/0)
        IP_ADDRESS              string      The IP address of the connecting client
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

    NWNX_SET_MEMORIZED_SPELL_SLOT_BEFORE
    NWNX_SET_MEMORIZED_SPELL_SLOT_AFTER

    Usage:
        OBJECT_SELF = The creature who's memorizing the spell

    Event data:
        Variable Name           Type        Notes
        SPELL_MULTICLASS        int         Index of the spell casting class (0-2)
        SPELL_LEVEL             int
        SPELL_SLOT              int
        SPELL_ID                int
        SPELL_DOMAIN            int
        SPELL_METAMAGIC         int
        SPELL_FROMCLIENT        int
        ACTION_RESULT           int

    NWNX_CLEAR_MEMORIZED_SPELL_SLOT_BEFORE
    NWNX_CLEAR_MEMORIZED_SPELL_SLOT_AFTER

    Usage:
        OBJECT_SELF = The creature whose spellbook is being changed

    Event data:
        Variable Name           Type        Notes
        SPELL_MULTICLASS        int         Index of the spell casting class (0-2)
        SPELL_LEVEL             int
        SPELL_SLOT              int
////////////////////////////////////////////////////////////////////////////////
    NWNX_ON_HEALER_KIT_BEFORE
    NWNX_ON_HEALER_KIT_AFTER

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
////////////////////////////////////////////////////////////////////////////////
    NWNX_ON_COMBAT_MODE_ON
    NWNX_ON_COMBAT_MODE_OFF

    !!! NOTICE: NEEDS THE NWNX_CombatModes PLUGIN TO WORK !!!

    Usage:
        OBJECT_SELF = The Player Character toggling the mode

    Event data:
        Variable Name           Type        Notes
        COMBAT_MODE_ID          int         See below

    The Combat Mode ID returned does not match the COMBAT_MODE_* NWScript constants

    Use the following:
    NONE                    0
    PARRY                   1
    POWER_ATTACK            2
    IMPROVED_POWER_ATTACK   3
    COUNTERSPELL            4
    FLURRY_OF_BLOWS         5
    RAPID_SHOT              6
    EXPERTISE               7
    IMPROVED_EXPERTISE      8
    DEFENSIVE_CASTING       9
    DIRTY_FIGHTING          10
    DEFENSIVE_STANCE        11
////////////////////////////////////////////////////////////////////////////////
    NWNX_ON_USE_SKILL_BEFORE
    NWNX_ON_USE_SKILL_AFTER

    Probably only really works with the following activated skills:
    SKILL_ANIMAL_EMPATHY, SKILL_DISABLE_TRAP, SKILL_HEAL, SKILL_OPEN_LOCK,
    SKILL_PICK_POCKET, SKILL_TAUNT

    Usage:
        OBJECT_SELF = The creature using the skill

    Event data:
        Variable Name           Type        Notes
        USED_ITEM_OBJECT_ID     object      Convert to object with NWNX_Object_StringToObject()
        TARGET_OBJECT_ID        object      ...
        SKILL_ID                int
        SUB_SKILL_ID            int
        TARGET_POSITION_X       float
        TARGET_POSITION_Y       float
        TARGET_POSITION_Z       float
////////////////////////////////////////////////////////////////////////////////
    NWNX_ON_MAP_PIN_ADD_PIN_BEFORE
    NWNX_ON_MAP_PIN_ADD_PIN_AFTER
    NWNX_ON_MAP_PIN_CHANGE_PIN_BEFORE
    NWNX_ON_MAP_PIN_CHANGE_PIN_AFTER
    NWNX_ON_MAP_PIN_DESTROY_PIN_BEFORE
    NWNX_ON_MAP_PIN_DESTROY_PIN_AFTER

    Usage:
        OBJECT_SELF = The player doing the action

    Event data:
        Variable Name           Type        Notes
        PIN_X                   float
        PIN_Y                   float
        PIN_ID                  int
        PIN_NOTE                string
////////////////////////////////////////////////////////////////////////////////
    NWNX_ON_DO_LISTEN_DETECTION_BEFORE
    NWNX_ON_DO_LISTEN_DETECTION_AFTER
    NWNX_ON_DO_SPOT_DETECTION_BEFORE
    NWNX_ON_DO_SPOT_DETECTION_AFTER

    Usage:
        OBJECT_SELF = The creature doing the detecting

    Event data:
        Variable Name           Type        Notes
        TARGET                  object      Convert to object with NWNX_Object_StringToObject()
        TARGET_INVISIBLE        int         TRUE/FALSE
        BEFORE_RESULT           int         TRUE/FALSE, only in _AFTER events
////////////////////////////////////////////////////////////////////////////////
    NWNX_ON_POLYMORPH_BEFORE
    NWNX_ON_POLYMORPH_AFTER
    NWNX_ON_UNPOLYMORPH_BEFORE
    NWNX_ON_UNPOLYMORPH_AFTER

    Usage:
        OBJECT_SELF = The creature doing the un/polymorphing

    Event data:
        Variable Name           Type        Notes
        POLYMORPH_TYPE          int         Appearance polymorphing into. Only for ON_POLYMORPH

    Note:
        If skipping the ON_POLYMORPH event, in some cases bioware scripts will
        enter an endless loop trying to merge item properties. This can be seen
        in x2_s2_gwildshp with the minotaur form with the following line:
            IPWildShapeCopyItemProperties(oWeaponOld,oWeaponNew, TRUE);
        If you want to skip this, you need to make sure oWeaponOld != oWeaponNew
////////////////////////////////////////////////////////////////////////////////
    NWNX_ON_EFFECT_APPLIED_BEFORE
    NWNX_ON_EFFECT_APPLIED_AFTER
    NWNX_ON_EFFECT_REMOVED_BEFORE
    NWNX_ON_EFFECT_REMOVED_AFTER

    Usage:
        OBJECT_SELF = The target of the effect

    Event data:
        Variable Name           Type        Notes
        UNIQUE_ID               int
        CREATOR                 object      Convert to object with NWNX_Object_StringToObject()
        TYPE                    int         The effect type, does not match NWScript constants
                                            See: https://github.com/nwnxee/unified/blob/master/NWNXLib/API/Constants/Effect.hpp#L8
        SUB_TYPE                int         SUBTYPE_*
        DURATION_TYPE           int         DURATION_TYPE_*
        DURATION                float
        SPELL_ID                int
        CASTER_LEVEL            int
        CUSTOM_TAG              string
        INT_PARAM_*             int         * = 1-8
        FLOAT_PARAM_*           float       * = 1-4
        STRING_PARAM_*          string      * = 1-6
        OBJECT_PARAM_*          object      * = 1-4, Convert to object with NWNX_Object_StringToObject()

    Note:
        Only fires for Temporary or Permanent effects, does not include VisualEffects or ItemProperty effects.
////////////////////////////////////////////////////////////////////////////////
    NWNX_ON_QUICKCHAT_BEFORE
    NWNX_ON_QUICKCHAT_AFTER

    Usage:
        OBJECT_SELF = The player using the quick chat command

    Event data:
        Variable Name           Type        Notes
        QUICKCHAT_COMMAND       int
////////////////////////////////////////////////////////////////////////////////
    NWNX_ON_INVENTORY_OPEN_BEFORE
    NWNX_ON_INVENTORY_OPEN_AFTER

    Usage:
        OBJECT_SELF = The player opening the inventory

    Event data:
        Variable Name           Type        Notes
        TARGET_INVENTORY        object      Pretty sure this is always the player

    NWNX_ON_INVENTORY_SELECT_PANEL_BEFORE
    NWNX_ON_INVENTORY_SELECT_PANEL_AFTER

    Usage:
        OBJECT_SELF = The player changing inventory panels

    Event data:
        Variable Name           Type        Notes
        CURRENT_PANEL           int         The current panel, index starts at 0
        SELECTED_PANEL          int         The selected panel, index starts at 0
////////////////////////////////////////////////////////////////////////////////
    NWNX_ON_BARTER_START_BEFORE
    NWNX_ON_BARTER_START_AFTER

    Usage:
        OBJECT_SELF = The player who initiated the barter

    Event data:
        Variable Name           Type        Notes
        BARTER_TARGET           object      The other player involved in the barter

    NWNX_ON_BARTER_END_BEFORE
    NWNX_ON_BARTER_END_AFTER

    Usage:
        OBJECT_SELF = The player who initiated the barter

    Event data:
        Variable Name                 Type        Notes
        BARTER_TARGET                 object      The other player involved in the barter
        BARTER_COMPLETE               int         TRUE/FALSE - whether the barter completed successfully
        BARTER_INITIATOR_ITEM_COUNT   int         How many items the initiator traded away, only in _BEFORE events
        BARTER_TARGET_ITEM_COUNT      int         How many items the target traded away, only in _BEFORE events
        BARTER_INITIATOR_ITEM_*       object      Convert to object with NWNX_Object_StringToObject(), only in _BEFORE events
        BARTER_TARGET_ITEM_*          object      Convert to object with NWNX_Object_StringToObject(), only in _BEFORE events
////////////////////////////////////////////////////////////////////////////////
    NWNX_ON_TRAP_DISARM_BEFORE
    NWNX_ON_TRAP_DISARM_AFTER
    NWNX_ON_TRAP_ENTER_BEFORE
    NWNX_ON_TRAP_ENTER_AFTER
    NWNX_ON_TRAP_EXAMINE_BEFORE
    NWNX_ON_TRAP_EXAMINE_AFTER
    NWNX_ON_TRAP_FLAG_BEFORE
    NWNX_ON_TRAP_FLAG_AFTER
    NWNX_ON_TRAP_RECOVER_BEFORE
    NWNX_ON_TRAP_RECOVER_AFTER
    NWNX_ON_TRAP_SET_BEFORE
    NWNX_ON_TRAP_SET_AFTER
    Usage:
        OBJECT_SELF = The creature performing the trap action

    Event data:
        Variable Name     Type        Notes
        TRAP_OBJECT_ID    object      Convert to object with NWNX_Object_StringToObject()
        TRAP_FORCE_SET    int         TRUE/FALSE, only in ENTER events
        ACTION_RESULT     int         TRUE/FALSE, only in _AFTER events (not ENTER)
////////////////////////////////////////////////////////////////////////////////
    NWNX_ON_TIMING_BAR_START_BEFORE
    NWNX_ON_TIMING_BAR_START_AFTER
    NWNX_ON_TIMING_BAR_STOP_BEFORE
    NWNX_ON_TIMING_BAR_STOP_AFTER
    NWNX_ON_TIMING_BAR_CANCEL_BEFORE
    NWNX_ON_TIMING_BAR_CANCEL_AFTER

    Usage:
        OBJECT_SELF = The player the timing bar is for

    Event data:
        Variable Name     Type        Notes
        EVENT_ID          int         The type of timing bar, see constants below, only in _START_ events
        DURATION          int         Length of time (in milliseconds) the bar is set to last, only in _START_ events
////////////////////////////////////////////////////////////////////////////////
    NWNX_ON_WEBHOOK_SUCCESS
    NWNX_ON_WEBHOOK_FAILURE

    !!! NOTICE: NEEDS THE NWNX_WebHook PLUGIN TO WORK !!!

    Usage:
        OBJECT_SELF = The module object

    Event data:
        Variable Name           Type        Notes
        STATUS                  int         The return code after posting to the server
        MESSAGE                 string      The full constructed message sent
        HOST                    string
        PATH                    string
        RATELIMIT_LIMIT         int          Discord: The number of requests that can be made in a limited period
        RATELIMIT_REMAINING     int          Discord: The number of remaining requests that can be made before rate limited
        RATELIMIT_RESET         int          Discord: Timestamp when the rate limit resets
        RETRY_AFTER             float        Milliseconds until another webhook is allowed when rate limited
        FAIL_INFO               string       The reason the hook failed aside from rate limits
////////////////////////////////////////////////////////////////////////////////
    NWNX_ON_CHECK_STICKY_PLAYER_NAME_RESERVED_BEFORE
    NWNX_ON_CHECK_STICKY_PLAYER_NAME_RESERVED_AFTER

    Skipping the _BEFORE event will cause no player names to be accepted unless you SetEventResult("1")

    Usage:
        OBJECT_SELF = The module

    Event data:
        Variable Name           Type        Notes
        PLAYER_NAME             string      Player name of the connecting client
        CDKEY                   string      Public cdkey of the connecting client
        LEGACY_CDKEY            string      Public cdkey from earlier versions of NWN
        IS_DM                   int         Whether the client is connecting as DM (1/0)
////////////////////////////////////////////////////////////////////////////////
    NWNX_ON_LEVEL_UP_BEFORE
    NWNX_ON_LEVEL_UP_AFTER
    NWNX_ON_LEVEL_UP_AUTOMATIC_BEFORE
    NWNX_ON_LEVEL_UP_AUTOMATIC_AFTER
    NWNX_ON_LEVEL_DOWN_BEFORE
    NWNX_ON_LEVEL_DOWN_AFTER

    Usage:
        OBJECT_SELF = The creature levelling up or down, automatic is for henchmen levelling

    Event data:
        Variable Name           Type        Notes
////////////////////////////////////////////////////////////////////////////////
    NWNX_ON_INVENTORY_ADD_GOLD_BEFORE
    NWNX_ON_INVENTORY_ADD_GOLD_AFTER
    NWNX_ON_INVENTORY_REMOVE_GOLD_BEFORE
    NWNX_ON_INVENTORY_REMOVE_GOLD_AFTER

    WARNING: While these events are skippable, you should be very careful about doing so.
             It's very easy to create situations where players can dupe their gold or worse.

    Usage:
        OBJECT_SELF = The creature gaining or losing gold

    Event data:
        Variable Name           Type        Notes
        GOLD                    int         The amount of gold added or removed
////////////////////////////////////////////////////////////////////////////////
    NWNX_ON_PVP_ATTITUDE_CHANGE_BEFORE
    NWNX_ON_PVP_ATTITUDE_CHANGE_AFTER

    Usage:
        OBJECT_SELF = The player performing the attitude change

    Event data:
        Variable Name           Type        Notes
        TARGET_OBJECT_ID        object      Convert to object with NWNX_Object_StringToObject()
        ATTITUDE                int         0 = Dislike, 1 = Like
////////////////////////////////////////////////////////////////////////////////
    NWNX_ON_INPUT_WALK_TO_WAYPOINT_BEFORE
    NWNX_ON_INPUT_WALK_TO_WAYPOINT_AFTER

    Usage:
        OBJECT_SELF = The player clicking somewhere to move

    Event data:
        Variable Name           Type        Notes
        AREA                    object      Convert to object with NWNX_Object_StringToObject()
        POS_X                   float
        POS_Y                   float
        POS_Z                   float
        RUN_TO_POINT            int         TRUE if player is running, FALSE if player is walking (eg when shift clicking)
////////////////////////////////////////////////////////////////////////////////
    NWNX_ON_MATERIALCHANGE_BEFORE
    NWNX_ON_MATERIALCHANGE_AFTER

    Usage:
        OBJECT_SELF = The creature walking on a different surface material

    Event data:
        Variable Name           Type        Notes
        MATERIAL_TYPE           int         See surfacemat.2da for values

    Note:
        After a PC transitions to a new area, a surface material change event
        won't fire until after the PC moves.
////////////////////////////////////////////////////////////////////////////////
    NWNX_ON_INPUT_ATTACK_OBJECT_BEFORE
    NWNX_ON_INPUT_ATTACK_OBJECT_AFTER

    Usage:
        OBJECT_SELF = The creature attacking

    Event data:
        Variable Name           Type        Notes
        TARGET                  object      Convert to object with NWNX_Object_StringToObject()
        PASSIVE                 int         TRUE / FALSE
        CLEAR_ALL_ACTIONS       int         TRUE / FALSE
        ADD_TO_FRONT            int         TRUE / FALSE
////////////////////////////////////////////////////////////////////////////////
    NWNX_ON_INPUT_FORCE_MOVE_TO_OBJECT_BEFORE
    NWNX_ON_INPUT_FORCE_MOVE_TO_OBJECT_AFTER

    Usage:
        OBJECT_SELF = The creature forcibly moving

    Event data:
        Variable Name           Type        Notes
        TARGET                  object      Convert to object with NWNX_Object_StringToObject()
*///////////////////////////////////////////////////////////////////////////////

/*
const int NWNX_EVENTS_OBJECT_TYPE_CREATURE          = 5;
const int NWNX_EVENTS_OBJECT_TYPE_ITEM              = 6;
const int NWNX_EVENTS_OBJECT_TYPE_TRIGGER           = 7;
const int NWNX_EVENTS_OBJECT_TYPE_PLACEABLE         = 9;
const int NWNX_EVENTS_OBJECT_TYPE_WAYPOINT          = 12;
const int NWNX_EVENTS_OBJECT_TYPE_ENCOUNTER         = 13;
const int NWNX_EVENTS_OBJECT_TYPE_PORTAL            = 15;
*/

/*
const int NWNX_EVENTS_TIMING_BAR_TRAP_FLAG     = 1;
const int NWNX_EVENTS_TIMING_BAR_TRAP_RECOVER  = 2;
const int NWNX_EVENTS_TIMING_BAR_TRAP_DISARM   = 3;
const int NWNX_EVENTS_TIMING_BAR_TRAP_EXAMINE  = 4;
const int NWNX_EVENTS_TIMING_BAR_TRAP_SET      = 5;
const int NWNX_EVENTS_TIMING_BAR_REST          = 6;
const int NWNX_EVENTS_TIMING_BAR_UNLOCK        = 7;
const int NWNX_EVENTS_TIMING_BAR_LOCK          = 8;
const int NWNX_EVENTS_TIMING_BAR_CUSTOM        = 10;
*/

/// @brief Scripts can subscribe to events.
///
/// Some events are dispatched via the NWNX plugin (see NWNX_EVENTS_EVENT_* constants).
/// Others can be signalled via script code via NWNX_Events_SignalEvent().
/// @param evt The event name.
/// @param script The script to call when the event fires.
void NWNX_Events_SubscribeEvent(string evt, string script);

/// Pushes event data at the provided tag, which subscribers can access with GetEventData.
/// This should be called BEFORE SignalEvent.
void NWNX_Events_PushEventData(string tag, string data);

/// Signals an event. This will dispatch a notification to all subscribed handlers.
/// Returns TRUE if anyone was subscribed to the event, FALSE otherwise.
int NWNX_Events_SignalEvent(string evt, object target);

/// Retrieves the event data for the currently executing script.
/// THIS SHOULD ONLY BE CALLED FROM WITHIN AN EVENT HANDLER.
string NWNX_Events_GetEventData(string tag);

/// Skips execution of the currently executing event.
/// If this is a NWNX event, that means that the base function call won't be called.
/// This won't impact any other subscribers, nor dispatch for before / after functions.
/// For example, if you are subscribing to NWNX_ON_EXAMINE_OBJECT_BEFORE, and you skip ...
/// - The other subscribers will still be called.
/// - The original function in the base game will be skipped.
/// - The matching after event (NWNX_ON_EXAMINE_OBJECT_AFTER) will also be executed.
///
/// THIS SHOULD ONLY BE CALLED FROM WITHIN AN EVENT HANDLER.
/// ONLY WORKS WITH THE FOLLOWING EVENTS:
/// - Feat events
/// - Item events
/// - Healer's Kit event
/// - CombatMode events
/// - Party events
/// - Skill events
/// - Map events
/// - Listen/Spot Detection events
/// - Polymorph events
/// - DMAction events
/// - Client connect event
/// - Spell events
/// - QuickChat events
/// - Barter event (START only)
/// - Trap events
/// - Sticky Player Name event
/// - Add/RemoveGold events
/// - PVP Attitude Change events
/// - {Enter|Exit}Stealth events
void NWNX_Events_SkipEvent();

/// Set the return value of the event.
///
/// THIS SHOULD ONLY BE CALLED FROM WITHIN AN EVENT HANDLER.
/// ONLY WORKS WITH THE FOLLOWING EVENTS:
/// - Healer's Kit event
/// - Listen/Spot Detection events -> "1" or "0"
/// - OnClientConnectBefore -> Reason for disconnect if skipped
/// - Ammo Reload event -> Forced ammunition returned
/// - Trap events -> "1" or "0"
/// - Sticky Player Name event -> "1" or "0"
void NWNX_Events_SetEventResult(string data);

/// Returns the current event name
///
/// Returns "" on error
string NWNX_Events_GetCurrentEvent();

/// Toggles DispatchListMode for sEvent+sScript
/// If enabled, sEvent for sScript will only be signalled if the target object is on its dispatch list.
void NWNX_Events_ToggleDispatchListMode(string sEvent, string sScript, int bEnable);

/// Add oObject to the dispatch list for sEvent+sScript.
void NWNX_Events_AddObjectToDispatchList(string sEvent, string sScript, object oObject);

/// Remove oObject from the dispatch list for sEvent+sScript.
void NWNX_Events_RemoveObjectFromDispatchList(string sEvent, string sScript, object oObject);

/// @}

void NWNX_Events_SubscribeEvent(string evt, string script)
{
    string sFunc = "SUBSCRIBE_EVENT";

    NWNX_PushArgumentString(NWNX_Events, sFunc, script);
    NWNX_PushArgumentString(NWNX_Events, sFunc, evt);
    NWNX_CallFunction(NWNX_Events, sFunc);
}

void NWNX_Events_PushEventData(string tag, string data)
{
    string sFunc = "PUSH_EVENT_DATA";

    NWNX_PushArgumentString(NWNX_Events, sFunc, data);
    NWNX_PushArgumentString(NWNX_Events, sFunc, tag);
    NWNX_CallFunction(NWNX_Events, sFunc);
}

int NWNX_Events_SignalEvent(string evt, object target)
{
    string sFunc = "SIGNAL_EVENT";

    NWNX_PushArgumentObject(NWNX_Events, sFunc, target);
    NWNX_PushArgumentString(NWNX_Events, sFunc, evt);
    NWNX_CallFunction(NWNX_Events, sFunc);
    return NWNX_GetReturnValueInt(NWNX_Events, sFunc);
}

string NWNX_Events_GetEventData(string tag)
{
    string sFunc = "GET_EVENT_DATA";

    NWNX_PushArgumentString(NWNX_Events, sFunc, tag);
    NWNX_CallFunction(NWNX_Events, sFunc);
    return NWNX_GetReturnValueString(NWNX_Events, sFunc);
}

void NWNX_Events_SkipEvent()
{
    string sFunc = "SKIP_EVENT";

    NWNX_CallFunction(NWNX_Events, sFunc);
}

void NWNX_Events_SetEventResult(string data)
{
    string sFunc = "EVENT_RESULT";

    NWNX_PushArgumentString(NWNX_Events, sFunc, data);
    NWNX_CallFunction(NWNX_Events, sFunc);
}

string NWNX_Events_GetCurrentEvent()
{
    string sFunc = "GET_CURRENT_EVENT";

    NWNX_CallFunction(NWNX_Events, sFunc);
    return NWNX_GetReturnValueString(NWNX_Events, sFunc);
}

void NWNX_Events_ToggleDispatchListMode(string sEvent, string sScript, int bEnable)
{
    string sFunc = "ToggleDispatchListMode";

    NWNX_PushArgumentInt(NWNX_Events, sFunc, bEnable);
    NWNX_PushArgumentString(NWNX_Events, sFunc, sScript);
    NWNX_PushArgumentString(NWNX_Events, sFunc, sEvent);
    NWNX_CallFunction(NWNX_Events, sFunc);
}

void NWNX_Events_AddObjectToDispatchList(string sEvent, string sScript, object oObject)
{
    string sFunc = "AddObjectToDispatchList";

    NWNX_PushArgumentObject(NWNX_Events, sFunc, oObject);
    NWNX_PushArgumentString(NWNX_Events, sFunc, sScript);
    NWNX_PushArgumentString(NWNX_Events, sFunc, sEvent);
    NWNX_CallFunction(NWNX_Events, sFunc);
}

void NWNX_Events_RemoveObjectFromDispatchList(string sEvent, string sScript, object oObject)
{
    string sFunc = "RemoveObjectFromDispatchList";

    NWNX_PushArgumentObject(NWNX_Events, sFunc, oObject);
    NWNX_PushArgumentString(NWNX_Events, sFunc, sScript);
    NWNX_PushArgumentString(NWNX_Events, sFunc, sEvent);
    NWNX_CallFunction(NWNX_Events, sFunc);
}
