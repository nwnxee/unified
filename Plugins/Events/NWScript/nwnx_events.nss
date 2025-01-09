/// @addtogroup events Events
/// @brief Provides an interface for plugins to create event-based systems, and exposes some events through that interface.
/// @{
/// @file nwnx_events.nss

const string NWNX_Events = "NWNX_Events"; ///< @private

/**
 # Events
__________________________________________
    ## Associate Events
    - NWNX_ON_ADD_ASSOCIATE_BEFORE
    - NWNX_ON_ADD_ASSOCIATE_AFTER
    - NWNX_ON_REMOVE_ASSOCIATE_BEFORE
    - NWNX_ON_REMOVE_ASSOCIATE_AFTER

    `OBJECT_SELF` = The owner of the associate.

    Event Data Tag        | Type   | Notes
    ----------------------|--------|-------
    ASSOCIATE_OBJECT_ID   | object | Convert to object with StringToObject()

_______________________________________
    ## Stealth Events
    - NWNX_ON_STEALTH_ENTER_BEFORE
    - NWNX_ON_STEALTH_ENTER_AFTER
    - NWNX_ON_STEALTH_EXIT_BEFORE
    - NWNX_ON_STEALTH_EXIT_AFTER

    `OBJECT_SELF` = The creature entering or exiting stealth.

    @note NWNX_ON_{ENTER|EXIT}_STEALTH_{BEFORE|AFTER} has been deprecated. Please use these new event names.
_______________________________________
    ## Detect Events
    - NWNX_ON_DETECT_ENTER_BEFORE
    - NWNX_ON_DETECT_ENTER_AFTER
    - NWNX_ON_DETECT_EXIT_BEFORE
    - NWNX_ON_DETECT_EXIT_AFTER

    `OBJECT_SELF` = The creature entering or exiting detect mode.

_______________________________________
    ## Examine Events
    - NWNX_ON_EXAMINE_OBJECT_BEFORE
    - NWNX_ON_EXAMINE_OBJECT_AFTER

    `OBJECT_SELF` = The player examining the object

    Event Data Tag        | Type   | Notes
    ----------------------|--------|-------
    EXAMINEE_OBJECT_ID    | object | Convert to object with StringToObject()
    TRAP_EXAMINE_SUCCESS  | int    | For trap examine only, whether the examine succeeded

_______________________________________
    ## Faction Events
    - NWNX_ON_SET_NPC_FACTION_REPUTATION_BEFORE
    - NWNX_ON_SET_NPC_FACTION_REPUTATION_AFTER

    `OBJECT_SELF` = The module

    Event Data Tag        | Type   | Notes
    ----------------------|--------|-------
    FACTION_ID            | int    | Not the STANDARD_FACTION_* constants. See nwnx_creature->GetFaction(). |
    SUBJECT_FACTION_ID    | int    | Not the STANDARD_FACTION_* constants. See nwnx_creature->GetFaction(). |
    PREVIOUS_REPUTATION   | int    | |
    NEW_REPUTATION        | int    | Not yet clamped between 0-100. In the AFTER event, this will equal the EventResult set in the BEFORE event. |

_______________________________________
    ## Validate Use Item Events
    - NWNX_ON_VALIDATE_USE_ITEM_BEFORE
    - NWNX_ON_VALIDATE_USE_ITEM_AFTER

    `OBJECT_SELF` = The creature using the item

    Event Data Tag          | Type   | Notes |
    ------------------------|--------|-------|
    ITEM_OBJECT_ID          | object | Convert to object with StringToObject()|
    BEFORE_RESULT           | int    | TRUE/FALSE, only in _AFTER events|

    @note The event result should be one of:
      "0" - Equip denied
      "1" - Equip okay
      "2" - Swap currently equipped item
      "3" - Unequip items in both hands before equipping
    @note Setting the result of this event will NOT prevent the item from being equipped, only used (e.g. scrolls/wands). See the "NWNX_ON_VALIDATE_ITEM_EQUIP_*" events to control equip behaviour.
    @note If the BEFORE event is not skipped, BEFORE_RESULT is the value of running the function normally. Otherwise, this is the set result value.

_______________________________________
    ## Use Item Events
    - NWNX_ON_USE_ITEM_BEFORE
    - NWNX_ON_USE_ITEM_AFTER

    `OBJECT_SELF` = The creature using the item

    Event Data Tag          | Type   | Notes |
    ------------------------|--------|-------|
    ITEM_OBJECT_ID          | object | Convert to object with StringToObject()|
    TARGET_OBJECT_ID        | object | Convert to object with StringToObject()|
    ITEM_PROPERTY_INDEX     | int    | |
    ITEM_SUB_PROPERTY_INDEX | int    | |
    TARGET_POSITION_X       | float  | |
    TARGET_POSITION_Y       | float  | |
    TARGET_POSITION_Z       | float  | |
    USE_CHARGES             | int  | |

    @note You can set the event result to "0" (send feedback to the client that the item cannot be used, default)
    or "1" to suppress that feedback.

_______________________________________
    ## Item Container Events
    - NWNX_ON_ITEM_INVENTORY_OPEN_BEFORE
    - NWNX_ON_ITEM_INVENTORY_OPEN_AFTER
    - NWNX_ON_ITEM_INVENTORY_CLOSE_BEFORE
    - NWNX_ON_ITEM_INVENTORY_CLOSE_AFTER

    `OBJECT_SELF` = The container

    Event Data Tag        | Type   | Notes
    ----------------------|--------|-------
    OWNER                 | object |Convert to object with StringToObject()

_______________________________________
    ## Ammunition Reload Events
    - NWNX_ON_ITEM_AMMO_RELOAD_BEFORE
    - NWNX_ON_ITEM_AMMO_RELOAD_AFTER

    `OBJECT_SELF` = The creature whose inventory we're searching for the item type

    Event Data Tag        | Type | Notes
    ----------------------|------|-------
    BASE_ITEM_ID          |  int | The base item type being sought (arrow, bolt, bullet)
    BASE_ITEM_NTH         |  int | Find the Nth instance of this item
    ACTION_RESULT         |  int | The object that was determined in BEFORE (only in after)

_______________________________________
    ## Scroll Learn Events
    - NWNX_ON_ITEM_SCROLL_LEARN_BEFORE
    - NWNX_ON_ITEM_SCROLL_LEARN_AFTER

    `OBJECT_SELF` = The creature learning the scroll

    Event Data Tag        | Type   | Notes
    ----------------------|--------|-------
    SCROLL                | object | Convert to object with StringToObject()
    RESULT                | int    | Returns TRUE in the _AFTER if the learning was successful, FALSE otherwise

_______________________________________
    ## Validate Item Equip Events
    - NWNX_ON_VALIDATE_ITEM_EQUIP_BEFORE
    - NWNX_ON_VALIDATE_ITEM_EQUIP_AFTER

    `OBJECT_SELF` = The creature trying to equip the item

    Event Data Tag        | Type   | Notes |
    ----------------------|--------|-------|
    ITEM_OBJECT_ID        | object | Convert to object with StringToObject()|
    SLOT                  | int    | INVENTORY_SLOT_* Constant|
    BEFORE_RESULT         | int    | TRUE/FALSE, only in _AFTER events|

    @note Manually setting the result of this event will skip all game checks for item slot validity. The client will block incompatible types (weapons into armor slots) in the GUI, but this will work using ActionEquipItem().
    @note To show this item as unusable to the PC (red in the inventory), use in combination with the "NWNX_ON_VALIDATE_USE_ITEM_*" events.
    @note If the BEFORE event is not skipped, BEFORE_RESULT is the value of running the function normally. Otherwise, this is the set result value.

_______________________________________
    ## Item Equip Events
    - NWNX_ON_ITEM_EQUIP_BEFORE
    - NWNX_ON_ITEM_EQUIP_AFTER

    `OBJECT_SELF` = The creature equipping the item

    Event Data Tag        | Type   | Notes |
    ----------------------|--------|-------|
    ITEM                  | object | Convert to object with StringToObject()|
    SLOT                  | int    | |

    @note This event does not run on login as the base game OnPlayerEquipItem event does. (Because this event hooks CNWSCreature::RunEquip which calls CNWSCreature::EquipItem. When the player character is first loaded, EquipItem is called directly.)
    @note If the goal is to prevent items from being equiped under certain conditions, and since this event does not run on login, it could be helpful to additionally use NWNX_Creature_RunUnequip() in the OnClientEnter (or similar) event.

_______________________________________
    ## Item Unequip Events
    - NWNX_ON_ITEM_UNEQUIP_BEFORE
    - NWNX_ON_ITEM_UNEQUIP_AFTER

    `OBJECT_SELF` = The creature unequipping the item

    Event Data Tag        | Type   | Notes
    ----------------------|--------|-------
    ITEM                  | object | Convert to object with StringToObject()

    @note These events do not trigger when equipment is replaced by equipping another item.
_______________________________________
    ## Item Destroy Events
    - NWNX_ON_ITEM_DESTROY_OBJECT_BEFORE
    - NWNX_ON_ITEM_DESTROY_OBJECT_AFTER
    - NWNX_ON_ITEM_DECREMENT_STACKSIZE_BEFORE
    - NWNX_ON_ITEM_DECREMENT_STACKSIZE_AFTER

    `OBJECT_SELF` = The item triggering the event

    @note Use of `NWNX_ON_ITEM_(DESTROY_OBJECT|DECREMENT_STACKSIZE)_*` conflicts with object event handler profiling

_______________________________________
    ## Item Use Lore To Identify Events
    - NWNX_ON_ITEM_USE_LORE_BEFORE
    - NWNX_ON_ITEM_USE_LORE_AFTER

    `OBJECT_SELF` = The player attempting to identify an item with their lore skill

    Event Data Tag        | Type   | Notes
    ----------------------|--------|-------
    ITEM                  | object |Convert to object with StringToObject()

_______________________________________
    ## Item Pay To Identify Events
    - NWNX_ON_ITEM_PAY_TO_IDENTIFY_BEFORE
    - NWNX_ON_ITEM_PAY_TO_IDENTIFY_AFTER

    `OBJECT_SELF` = The player attempting to pay to identify an item

    Event Data Tag        | Type   | Notes
    ----------------------|--------|-------
    ITEM                  | object | Convert to object with StringToObject()
    STORE                 | object | Convert to object with StringToObject()

_______________________________________
    ## Item Split Events
    - NWNX_ON_ITEM_SPLIT_BEFORE
    - NWNX_ON_ITEM_SPLIT_AFTER

    `OBJECT_SELF` = The player attempting to split an item

    Event Data Tag        | Type   | Notes|
    ----------------------|--------|-------|
    ITEM                  | object | Convert to object with StringToObject()|
    NUMBER_SPLIT_OFF      | int    | |

_______________________________________
    ## Item Merge Events
    - NWNX_ON_ITEM_MERGE_BEFORE
    - NWNX_ON_ITEM_MERGE_AFTER

    `OBJECT_SELF` = The player attempting to merge an item

    Event Data Tag        | Type   | Notes                                                                             |
    ----------------------|--------|-----------------------------------------------------------------------------------|
    ITEM_TO_MERGE_INTO    | object | Convert to object with StringToObject()                                           |
    ITEM_TO_MERGE         | object | Convert to object with StringToObject() (May be OBJECT_INVALID in the AFTER event)|

_______________________________________
    ## Acquire Item Events
    - NWNX_ON_ITEM_ACQUIRE_BEFORE
    - NWNX_ON_ITEM_ACQUIRE_AFTER

    `OBJECT_SELF` = The creature trying to acquire the item

    Event Data Tag        | Type   | Notes |
    ----------------------|--------|-------|
    ITEM                  | object | Convert to object with StringToObject() (May be OBJECT_INVALID in the AFTER event) |
    GIVER                 | object | Convert to object with StringToObject() (will be INVALID if picked up from ground)|
    RESULT                | int    | Returns TRUE in the _AFTER if the acquisition was successful, FALSE otherwise

    @note This event currently only works with creatures

_______________________________________
    ## Feat Use Events
    - NWNX_ON_USE_FEAT_BEFORE
    - NWNX_ON_USE_FEAT_AFTER

    `OBJECT_SELF` = The object using the feat

    Event Data Tag        | Type   | Notes |
    ----------------------|--------|-------|
    FEAT_ID               | int    | |
    SUBFEAT_ID            | int    | |
    TARGET_OBJECT_ID      | object | Convert to object with StringToObject() |
    AREA_OBJECT_ID        | object | Convert to object with StringToObject() |
    TARGET_POSITION_X     | float  | |
    TARGET_POSITION_Y     | float  | |
    TARGET_POSITION_Z     | float  | |
    ACTION_RESULT         | int    | TRUE/FALSE, only in _AFTER events

_______________________________________
    ## Has Feat Events
    - NWNX_ON_HAS_FEAT_BEFORE
    - NWNX_ON_HAS_FEAT_AFTER

    `OBJECT_SELF` = The player being checked for the feat

    Event Data Tag        | Type   | Notes |
    ----------------------|--------|-------|
    FEAT_ID               | int    | |
    HAS_FEAT              | int    |  Whether they truly have the feat or not |

    @note This event should definitely be used with the Event ID Whitelist, which is turned on by default
    for this event. Until you add your Feat ID to the whitelist on module load this event will not function.
    For example if you wish an event to fire when nwn is checking if the creature has Epic Dodge you would perform
    the following functions on_module_load.
    ```c
    NWNX_Events_SubscribeEvent("NWNX_ON_HAS_FEAT_BEFORE", "event_has_feat");
    NWNX_Events_AddIDToWhitelist("NWNX_ON_HAS_FEAT", FEAT_EPIC_DODGE);
    ```
    @warning Toggling the Whitelist to be off for this event will degrade performance.
_______________________________________
    ## DM Give Events
    - NWNX_ON_DM_GIVE_GOLD_BEFORE
    - NWNX_ON_DM_GIVE_GOLD_AFTER
    - NWNX_ON_DM_GIVE_XP_BEFORE
    - NWNX_ON_DM_GIVE_XP_AFTER
    - NWNX_ON_DM_GIVE_LEVEL_BEFORE
    - NWNX_ON_DM_GIVE_LEVEL_AFTER
    - NWNX_ON_DM_GIVE_ALIGNMENT_BEFORE
    - NWNX_ON_DM_GIVE_ALIGNMENT_AFTER

    `OBJECT_SELF` = The DM

    Event Data Tag        | Type   | Notes |
    ----------------------|--------|-------|
    AMOUNT                | int    | |
    OBJECT                | object | Convert to object with StringToObject() |
    ALIGNMENT_TYPE        | int    | Only valid for `NWNX_ON_DM_GIVE_ALIGNMENT_*` |

_______________________________________
    ## DM Spawn Object Events
    - NWNX_ON_DM_SPAWN_OBJECT_BEFORE
    - NWNX_ON_DM_SPAWN_OBJECT_AFTER

    `OBJECT_SELF` = The DM

    Event Data Tag        | Type   | Notes |
    ----------------------|--------|-------|
    AREA                  | object | Convert to object with StringToObject() |
    OBJECT                | object | Only returns a valid object in *_AFTER |
    OBJECT_TYPE           | int    | Returns `NWNX_EVENTS_OBJECT_TYPE_*` |
    POS_X                 | float  | |
    POS_Y                 | float  | |
    POS_Z                 | float  | |
    RESREF                | string | The resref of the object that's being spawned. |

    @note When spawning a standard trap, the resref will be an index into traps.2da.

_______________________________________
    ## DM Give Item Events
    - NWNX_ON_DM_GIVE_ITEM_BEFORE
    - NWNX_ON_DM_GIVE_ITEM_AFTER

    `OBJECT_SELF` = The DM

    Event Data Tag        | Type   | Notes
    ----------------------|--------|-------
    TARGET                | object | Convert to object with StringToObject()
    ITEM                  | object | Only returns a valid object in *_AFTER

_______________________________________
    ## DM Multiple Object Action Events
    - NWNX_ON_DM_HEAL_BEFORE
    - NWNX_ON_DM_HEAL_AFTER
    - NWNX_ON_DM_KILL_BEFORE
    - NWNX_ON_DM_KILL_AFTER
    - NWNX_ON_DM_TOGGLE_INVULNERABLE_BEFORE
    - NWNX_ON_DM_TOGGLE_INVULNERABLE_AFTER
    - NWNX_ON_DM_FORCE_REST_BEFORE
    - NWNX_ON_DM_FORCE_REST_AFTER
    - NWNX_ON_DM_LIMBO_BEFORE
    - NWNX_ON_DM_LIMBO_AFTER
    - NWNX_ON_DM_TOGGLE_AI_BEFORE
    - NWNX_ON_DM_TOGGLE_AI_AFTER
    - NWNX_ON_DM_TOGGLE_IMMORTAL_BEFORE
    - NWNX_ON_DM_TOGGLE_IMMORTAL_AFTER

    `OBJECT_SELF` = The DM

    Event Data Tag        | Type   | Notes
    ----------------------|--------|-------
    NUM_TARGETS           | int    | The number of targets affected
    TARGET_*              | object | * = 1 <= NUM_TARGETS

_______________________________________
    ## DM Single Object Action Events
    - NWNX_ON_DM_GOTO_BEFORE
    - NWNX_ON_DM_GOTO_AFTER
    - NWNX_ON_DM_POSSESS_BEFORE
    - NWNX_ON_DM_POSSESS_AFTER
    - NWNX_ON_DM_POSSESS_FULL_POWER_BEFORE
    - NWNX_ON_DM_POSSESS_FULL_POWER_AFTER
    - NWNX_ON_DM_TOGGLE_LOCK_BEFORE
    - NWNX_ON_DM_TOGGLE_LOCK_AFTER
    - NWNX_ON_DM_DISABLE_TRAP_BEFORE
    - NWNX_ON_DM_DISABLE_TRAP_AFTER

    `OBJECT_SELF` = The DM

    Event Data Tag        | Type   | Notes
    ----------------------|--------|-------
    TARGET                | object | Convert to object with StringToObject()

    @note If `TARGET` is `OBJECT_INVALID` for `NWNX_ON_DM_POSSESS_*`, the DM is unpossessing.

_______________________________________
    ## DM Jump Events
    - NWNX_ON_DM_JUMP_TO_POINT_BEFORE
    - NWNX_ON_DM_JUMP_TO_POINT_AFTER
    - NWNX_ON_DM_JUMP_TARGET_TO_POINT_BEFORE
    - NWNX_ON_DM_JUMP_TARGET_TO_POINT_AFTER
    - NWNX_ON_DM_JUMP_ALL_PLAYERS_TO_POINT_BEFORE
    - NWNX_ON_DM_JUMP_ALL_PLAYERS_TO_POINT_AFTER

    `OBJECT_SELF` = The DM

    Event Data Tag        | Type   | Notes |
    ----------------------|--------|-------|
    TARGET_AREA           | object | Convert to object with StringToObject() |
    POS_X                 | float  | |
    POS_Y                 | float  | |
    POS_Z                 | float  | |
    NUM_TARGETS           | int    | Only valid for NWNX_ON_DM_JUMP_TARGET_TO_POINT_* |
    TARGET_*              | object | * = 1 <= NUM_TARGETS, Only valid for NWNX_ON_DM_JUMP_TARGET_TO_POINT_* |

_______________________________________
    ## DM Change Difficulty Events
    - NWNX_ON_DM_CHANGE_DIFFICULTY_BEFORE
    - NWNX_ON_DM_CHANGE_DIFFICULTY_AFTER

    `OBJECT_SELF` = The DM

    Event Data Tag        | Type   | Notes |
    ----------------------|--------|-------|
    DIFFICULTY_SETTING    | int    | |

_______________________________________
    ## DM View Inventory Events
    - NWNX_ON_DM_VIEW_INVENTORY_BEFORE
    - NWNX_ON_DM_VIEW_INVENTORY_AFTER

    `OBJECT_SELF` = The DM

    Event Data Tag        | Type   | Notes
    ----------------------|--------|-------
    OPEN_INVENTORY        | int    | TRUE if opening an inventory, FALSE if closing
    TARGET                | object | Convert to object with StringToObject()

_______________________________________
    ## DM Spawn Trap Events
    - NWNX_ON_DM_SPAWN_TRAP_ON_OBJECT_BEFORE
    - NWNX_ON_DM_SPAWN_TRAP_ON_OBJECT_AFTER

    `OBJECT_SELF` = The DM

    Event Data Tag        | Type   | Notes
    ----------------------|--------|-------
    AREA                  | object | Convert to object with StringToObject()
    TARGET                | object | Convert to object with StringToObject()

_______________________________________
    ## DM Dump Locals Events
    - NWNX_ON_DM_DUMP_LOCALS_BEFORE
    - NWNX_ON_DM_DUMP_LOCALS_AFTER

    `OBJECT_SELF` = The DM

    Event Data Tag        | Type   | Notes
    ----------------------|--------|-------
    TYPE                  | int    | 0 = dm_dumplocals, 1 = dm_dumparealocals, 3 = dm_dumpmodulelocals
    TARGET                | object | Convert to object with StringToObject()

    Note: For TYPE 1/2, use GetArea(TARGET) or GetModule()

_______________________________________
    ## DM PlayerDM Login/Logout Events
    - NWNX_ON_DM_PLAYERDM_LOGIN_BEFORE
    - NWNX_ON_DM_PLAYERDM_LOGIN_AFTER
    - NWNX_ON_DM_PLAYERDM_LOGOUT_BEFORE
    - NWNX_ON_DM_PLAYERDM_LOGOUT_AFTER

    `OBJECT_SELF` = The DM

    Event Data Tag        | Type   | Notes
    ----------------------|--------|-------
    PASSWORD              | string | The password the DM provided, only valid for NWNX_ON_DM_PLAYERDM_LOGIN_*

_______________________________________
    ## DM Set Stat Events
    - NWNX_ON_DM_SET_STAT_BEFORE
    - NWNX_ON_DM_SET_STAT_AFTER

    `OBJECT_SELF` = The DM

    Event Data Tag        | Type   | Notes
    ----------------------|--------|-------
    STAT                  | int    | Returns ABILITY_* constant
    VALUE                 | int    |
    TARGET                | object | Convert to object with StringToObject()
    SET                   | int    | TRUE if setting stat, FALSE if modifying

_______________________________________
    ## DM Get Variable Events
    - NWNX_ON_DM_GET_VARIABLE_BEFORE
    - NWNX_ON_DM_GET_VARIABLE_AFTER

    `OBJECT_SELF` = The DM

    Event Data Tag        | Type   | Notes
    ----------------------|--------|-------
    TYPE                  | int    | Returns NWNX_EVENTS_DM_SET_VARIABLE_TYPE_*
    TARGET                | object | Convert to object with StringToObject()
    KEY                   | string | Variable name

    @note Vector variable types aren't supported.

_______________________________________
    ## DM Set Variable Events
    - NWNX_ON_DM_SET_VARIABLE_BEFORE
    - NWNX_ON_DM_SET_VARIABLE_AFTER

    `OBJECT_SELF` = The DM

    Event Data Tag        | Type   | Notes
    ----------------------|--------|-------
    TYPE                  | int    | Returns NWNX_EVENTS_DM_SET_VARIABLE_TYPE_*
    TARGET                | object | Convert to object with StringToObject()
    KEY                   | string | Variable name
    VALUE                 | string | Variable value

    @note Vector variable types aren't supported.

_______________________________________
    ## DM Set Faction Events
    - NWNX_ON_DM_SET_FACTION_BEFORE
    - NWNX_ON_DM_SET_FACTION_AFTER

    `OBJECT_SELF` = The DM

    Event Data Tag        | Type   | Notes
    ----------------------|--------|-------
    TARGET                | object | Convert to object with StringToObject()
    FACTION_ID            | int    | Not the STANDARD_FACTION_* constants. See nwnx_creature->GetFaction().
    FACTION_NAME          | string |

_______________________________________
    ## DM Other Events
    - NWNX_ON_DM_APPEAR_BEFORE
    - NWNX_ON_DM_APPEAR_AFTER
    - NWNX_ON_DM_DISAPPEAR_BEFORE
    - NWNX_ON_DM_DISAPPEAR_AFTER
    - NWNX_ON_DM_TAKE_ITEM_BEFORE
    - NWNX_ON_DM_TAKE_ITEM_AFTER
    - NWNX_ON_DM_SET_TIME_BEFORE
    - NWNX_ON_DM_SET_TIME_AFTER
    - NWNX_ON_DM_SET_DATE_BEFORE
    - NWNX_ON_DM_SET_DATE_AFTER
    - NWNX_ON_DM_SET_FACTION_REPUTATION_BEFORE
    - NWNX_ON_DM_SET_FACTION_REPUTATION_AFTER
    - NWNX_ON_DM_GET_FACTION_REPUTATION_BEFORE
    - NWNX_ON_DM_GET_FACTION_REPUTATION_AFTER

    `OBJECT_SELF` = The DM

_______________________________________
    ## Client Disconnect Events
    - NWNX_ON_CLIENT_DISCONNECT_BEFORE
    - NWNX_ON_CLIENT_DISCONNECT_AFTER

    `OBJECT_SELF` = The player disconnecting from the server

    Event Data Tag        | Type   | Notes
    ----------------------|--------|-------
    PLAYER_NAME           | string | Player name of the disconnecting client
    CDKEY                 | string | Public cdkey of the disconnecting client

    @note This event also runs when a player connects to the server but cancels out of character select.
    OBJECT_SELF will be OBJECT_INVALID in this case.

_______________________________________
    ## Client Connect Events
    - NWNX_ON_CLIENT_CONNECT_BEFORE
    - NWNX_ON_CLIENT_CONNECT_AFTER

    `OBJECT_SELF` = The module

    Event Data Tag        | Type   | Notes
    ----------------------|--------|-------
    PLAYER_NAME           | string | Player name of the connecting client
    CDKEY                 | string | Public cdkey of the connecting client
    IS_DM                 | int    | Whether the client is connect as DM (1/0)
    IP_ADDRESS            | string | The IP address of the connecting client
    VERSION_MAJOR         | int    | The client's major version, eg 8193, or 0 if unavailable.
    VERSION_MINOR         | int    | The client's minor version, eg 34, or 0 if unavailable.
    VERSION_POSTFIX       | int    | The client's postfix version, eg 37, or 0 if unavailable.
    PLATFORM_ID           | int    | The client's platform id, PLAYER_DEVICE_PLATFORM_*, or 0 if unavailable.

    @note Skipping the _BEFORE event will cause the client's connection to be denied.
    You can optionally pass a reason for this in the event result.

_______________________________________
    ## CombatEnter/Exit Events
    - NWNX_ON_COMBAT_ENTER_BEFORE
    - NWNX_ON_COMBAT_ENTER_AFTER
    - NWNX_ON_COMBAT_EXIT_BEFORE
    - NWNX_ON_COMBAT_EXIT_AFTER

    `OBJECT_SELF` = The player entering/exiting combat.

    @note Only works for PCs.

_______________________________________
    ## Combat Round Start Events
    - NWNX_ON_START_COMBAT_ROUND_BEFORE
    - NWNX_ON_START_COMBAT_ROUND_AFTER

    `OBJECT_SELF` = The creature starting the combat round

    Event Data Tag        | Type   | Notes
    ----------------------|--------|-------
    TARGET_OBJECT_ID      | object | Convert to object with StringToObject()

_______________________________________
    ## Disarm Events
    - NWNX_ON_DISARM_BEFORE
    - NWNX_ON_DISARM_AFTER

    `OBJECT_SELF` = The creature who is being disarmed

    Event Data Tag        | Type   | Notes
    ----------------------|--------|-------
    DISARMER_OBJECT_ID    | object | The object disarming the creature
    FEAT_ID               | int    | The feat used to perform the disarming (Normal vs Improved Disarm)
    ACTION_RESULT         | int    | TRUE/FALSE, only in _AFTER events

_______________________________________
    ## Cast Spell Events
    - NWNX_ON_CAST_SPELL_BEFORE
    - NWNX_ON_CAST_SPELL_AFTER

    `OBJECT_SELF` = The creature casting the spell

    Event Data Tag        | Type   | Notes |
    ----------------------|--------|-------|
    SPELL_ID              | int    | |
    TARGET_POSITION_X     | float  | |
    TARGET_POSITION_Y     | float  | |
    TARGET_POSITION_Z     | float  | |
    TARGET_OBJECT_ID      | object | Convert to object with StringToObject() |
    ITEM_OBJECT_ID        | object | Convert to object with StringToObject() |
    MULTI_CLASS           | int    | |
    SPELL_COUNTERED       | int    | Returns TRUE if spell was countered else FALSE |
    COUNTERING_SPELL      | int    | Returns TRUE if cast as counter else FALSE |
    PROJECTILE_PATH_TYPE  | int    | |
    IS_INSTANT_SPELL      | int    | Returns TRUE if spell was instant else FALSE |

@note the stock nwscript GetMetaMagicFeat() function will return any metamagic used.

_______________________________________
    ## Set Memorized Spell Slot Events
    - NWNX_SET_MEMORIZED_SPELL_SLOT_BEFORE
    - NWNX_SET_MEMORIZED_SPELL_SLOT_AFTER

    `OBJECT_SELF` = The creature who's memorizing the spell

    Event Data Tag        | Type   | Notes |
    ----------------------|--------|-------|
    SPELL_MULTICLASS      | int | Index of the spell casting class (0-7) |
    SPELL_SLOT            | int | |
    SPELL_ID              | int | |
    SPELL_DOMAIN          | int | |
    SPELL_METAMAGIC       | int | |
    SPELL_FROMCLIENT      | int | |
    ACTION_RESULT         | int | |

_______________________________________
    ## Clear Memorized Spell Slot Events
    - NWNX_CLEAR_MEMORIZED_SPELL_SLOT_BEFORE
    - NWNX_CLEAR_MEMORIZED_SPELL_SLOT_AFTER

    `OBJECT_SELF` = The creature whose spellbook is being changed

    Event Data Tag        | Type   | Notes |
    ----------------------|--------|-------|
    SPELL_MULTICLASS      | int    | Index of the spell casting class (0-7) |
    SPELL_LEVEL           | int    | |
    SPELL_SLOT            | int    | |

_______________________________________
    ## Spell Interrupted Events
    - NWNX_ON_SPELL_INTERRUPTED_BEFORE
    - NWNX_ON_SPELL_INTERRUPTED_AFTER

    `OBJECT_SELF` = The creature whose spell was interrupted

    Event Data Tag        | Type   | Notes |
    ----------------------|--------|-------|
    SPELL_ID              | int | |
    SPELL_CLASS           | int | Index of the spell casting class (0-2) |
    SPELL_DOMAIN          | int | |
    SPELL_METAMAGIC       | int | |
    SPELL_FEAT            | int | |
    SPELL_SPONTANEOUS     | int | |

_______________________________________
    ## Spell Failed Events
    - NWNX_ON_SPELL_FAILED_BEFORE
    - NWNX_ON_SPELL_FAILED_AFTER

    `OBJECT_SELF` = The creature whose spell failed

    Event Data Tag        | Type   | Notes |
    ----------------------|--------|-------|
    SPELL_ID              | int    | |
    MULTI_CLASS           | int    | Index of the spell casting class (0-7) |
    DOMAIN                | int    | |
    METAMAGIC             | int    | |
    FEAT                  | int    | |
    SPELL_SPONTANEOUS     | int    | |
    DEFENSIVELY_CAST      | int    | |
    TARGET_OBJECT_ID      | object | Convert to object with StringToObject() |
    TARGET_POSITION_X     | float  | |
    TARGET_POSITION_Y     | float  | |
    TARGET_POSITION_Z     | float  | |
    IS_INSTANT_SPELL      | int    | |
    PROJECTILE_PATH_TYPE  | int    | |
    CASTERLEVEL           | int    | |
    IS_FAKE               | int    | |
    REASON                | int    | @ref events_spellfailreason "NWNX_EVENTS_SPELLFAIL_REASON_*" |

_______________________________________
    ## Healer Kit Use Events
    - NWNX_ON_HEALER_KIT_BEFORE
    - NWNX_ON_HEALER_KIT_AFTER

    `OBJECT_SELF` = The creature using the Healer's Kit

    Event Data Tag        | Type   | Notes |
    ----------------------|--------|-------|
    TARGET_OBJECT_ID      | object | Convert to object with StringToObject() |
    ITEM_OBJECT_ID        | object | Convert to object with StringToObject() |
    ITEM_PROPERTY_INDEX   | int    | |
    MOVE_TO_TARGET        | int    | |
    ACTION_RESULT         | int    | |

_______________________________________
    ## Healing Events
    - NWNX_ON_HEAL_BEFORE
    - NWNX_ON_HEAL_AFTER

    `OBJECT_SELF` = The creature performing the heal

    Event Data Tag        | Type   | Notes |
    ----------------------|--------|-------|
    TARGET_OBJECT_ID      | object | Convert to object with StringToObject() |
    HEAL_AMOUNT           | int    | How many HP the heal will provide |

_______________________________________
    ## Party Action Events
    - NWNX_ON_PARTY_*_BEFORE
    - NWNX_ON_PARTY_*_AFTER

    `OBJECT_SELF` = The player doing the action

    Replace * with an event listed below

    Event           | Event Data Tag        | Type   | Notes |
    ----------------|-----------------------|--------|-------|
    LEAVE | LEAVING | object | Convert to object with StringToObject() |
    KICK  | KICKED  | object | Convert to object with StringToObject() |
    TRANSFER_LEADERSHIP  | NEW_LEADER  | object | Convert to object with StringToObject() |
    INVITE  | INVITED  | object | Convert to object with StringToObject() |
    IGNORE_INVITATION  | INVITED_BY  | object | Convert to object with StringToObject() |
    ACCEPT_INVITATION  | INVITED_BY  | object | Convert to object with StringToObject() |
    REJECT_INVITATION  | INVITED_BY  | object | Convert to object with StringToObject() |
    KICK_HENCHMAN  | INVITED_BY  | object | Convert to object with StringToObject() |

_______________________________________
    ## Combat Mode Toggle Events
    - NWNX_ON_COMBAT_MODE_ON
    - NWNX_ON_COMBAT_MODE_OFF

    `OBJECT_SELF` = The Player Character toggling the mode

    Event Data Tag        | Type   | Notes
    ----------------------|--------|-------
    COMBAT_MODE_ID        | int    | See below

    The `COMBAT_MODE_ID` returned does not match the `COMBAT_MODE_*` NWScript constants. Use the following:
    Combat Mode           | ID
    ----------------------|----
    NONE                  | 0
    PARRY                 | 1
    POWER_ATTACK          | 2
    IMPROVED_POWER_ATTACK | 3
    COUNTERSPELL          | 4
    FLURRY_OF_BLOWS       | 5
    RAPID_SHOT            | 6
    EXPERTISE             | 7
    IMPROVED_EXPERTISE    | 8
    DEFENSIVE_CASTING     | 9
    DIRTY_FIGHTING        | 10
    DEFENSIVE_STANCE      | 11

_______________________________________
    ## Use Skill Events
    - NWNX_ON_USE_SKILL_BEFORE
    - NWNX_ON_USE_SKILL_AFTER

    `OBJECT_SELF` = The creature using the skill

    Event Data Tag        | Type   | Notes |
    ----------------------|--------|-------|
    USED_ITEM_OBJECT_ID   | object | Convert to object with StringToObject() |
    TARGET_OBJECT_ID      | object | Convert to object with StringToObject() |
    SKILL_ID              | int | |
    SUB_SKILL_ID          | int | |
    TARGET_POSITION_X     | float | |
    TARGET_POSITION_Y     | float | |
    TARGET_POSITION_Z     | float | |
    ACTION_RESULT         | int    | TRUE/FALSE, only in _AFTER events

    @note Probably only really works with the following activated skills:
    `SKILL_ANIMAL_EMPATHY`, `SKILL_DISABLE_TRAP`, `SKILL_HEAL`, `SKILL_OPEN_LOCK`,
    `SKILL_PICK_POCKET`, `SKILL_TAUNT`

_______________________________________
    ## Map Pin Events
    - NWNX_ON_MAP_PIN_ADD_PIN_BEFORE
    - NWNX_ON_MAP_PIN_ADD_PIN_AFTER
    - NWNX_ON_MAP_PIN_CHANGE_PIN_BEFORE
    - NWNX_ON_MAP_PIN_CHANGE_PIN_AFTER
    - NWNX_ON_MAP_PIN_DESTROY_PIN_BEFORE
    - NWNX_ON_MAP_PIN_DESTROY_PIN_AFTER

    `OBJECT_SELF` = The player performing the map pin action

    Event Data Tag        | Type   | Notes
    ----------------------|--------|-------
    PIN_X                 | float  | Not available in DESTROY event
    PIN_Y                 | float  | Not available in DESTROY event
    PIN_ID                | int    | Not available in ADD events. Use `GetLocalInt(oPC, "NW_TOTAL_MAP_PINS")`
    PIN_NOTE              | string | Not available in DESTROY event

_______________________________________
    ## Spot/Listen Detection Events
    - NWNX_ON_DO_LISTEN_DETECTION_BEFORE
    - NWNX_ON_DO_LISTEN_DETECTION_AFTER
    - NWNX_ON_DO_SPOT_DETECTION_BEFORE
    - NWNX_ON_DO_SPOT_DETECTION_AFTER

    `OBJECT_SELF` = The creature doing the detecting

    Event Data Tag        | Type   | Notes
    ----------------------|--------|-------
    TARGET                | object | Convert to object with StringToObject()
    TARGET_INVISIBLE      | int    | TRUE/FALSE
    BEFORE_RESULT         | int    | TRUE/FALSE, only in _AFTER events

_______________________________________
    ## Polymorph Events
    - NWNX_ON_POLYMORPH_BEFORE
    - NWNX_ON_POLYMORPH_AFTER
    - NWNX_ON_UNPOLYMORPH_BEFORE
    - NWNX_ON_UNPOLYMORPH_AFTER

   `OBJECT_SELF` = The creature doing the un/polymorphing

    Event Data Tag        | Type   | Notes
    ----------------------|--------|-------
    POLYMORPH_TYPE        | int    | Appearance polymorphing into. Only for ON_POLYMORPH

    @warning If skipping the ON_POLYMORPH event, in some cases bioware scripts will enter an endless loop
    trying to merge item properties.\n
     This can be seen in `x2_s2_gwildshp` with the minotaur form with the following line:
    `IPWildShapeCopyItemProperties(oWeaponOld,oWeaponNew, TRUE);`
     If you want to skip this, you need to make sure oWeaponOld != oWeaponNew

_______________________________________
    ## Effect Applied/Removed Events
    - NWNX_ON_EFFECT_APPLIED_BEFORE
    - NWNX_ON_EFFECT_APPLIED_AFTER
    - NWNX_ON_EFFECT_REMOVED_BEFORE
    - NWNX_ON_EFFECT_REMOVED_AFTER

    `OBJECT_SELF` = The target of the effect

    Event Data Tag        | Type   | Notes |
    ----------------------|--------|-------|
    UNIQUE_ID             | int    | |
    CREATOR               | object | Convert to object with StringToObject() |
    TYPE                  | int    | The effect type, does not match NWScript constants See: https://github.com/nwnxee/unified/blob/master/NWNXLib/API/Constants/Effect.hpp#L8 |
    SUB_TYPE              | int    | SUBTYPE_* |
    DURATION_TYPE         | int    | DURATION_TYPE_* |
    DURATION              | float  | |
    SPELL_ID              | int    | |
    CASTER_LEVEL          | int    | |
    CUSTOM_TAG            | string | |
    INT_PARAM_*           | int    | * = 1-8 |
    FLOAT_PARAM_*         | float  | * = 1-4 |
    STRING_PARAM_*        | string | * = 1-6 |
    OBJECT_PARAM_*        | object | * = 1-4, Convert to object with StringToObject() |

    @note Only fires for Temporary or Permanent effects, does not include VisualEffects or ItemProperty effects.

_______________________________________
    ## Quickchat Events
    - NWNX_ON_QUICKCHAT_BEFORE
    - NWNX_ON_QUICKCHAT_AFTER

    `OBJECT_SELF` = The player using the quick chat command

    Event Data Tag        | Type   | Notes
    ----------------------|--------|-------
    QUICKCHAT_COMMAND     | int    | `VOICE_CHAT_*` constants

_______________________________________
    ## Inventory Open Events
    - NWNX_ON_INVENTORY_OPEN_BEFORE
    - NWNX_ON_INVENTORY_OPEN_AFTER

    `OBJECT_SELF` = The player opening the inventory

    Event Data Tag        | Type   | Notes
    ----------------------|--------|-------
    TARGET_INVENTORY      | object | Pretty sure this is always the player

_______________________________________
    ## Inventory Select Panel Events
    - NWNX_ON_INVENTORY_SELECT_PANEL_BEFORE
    - NWNX_ON_INVENTORY_SELECT_PANEL_AFTER

    `OBJECT_SELF` = The player changing inventory panels

    Event Data Tag        | Type   | Notes
    ----------------------|--------|-------
    CURRENT_PANEL         | int    | The current panel, index starts at 0
    SELECTED_PANEL        | int    | The selected panel, index starts at 0

_______________________________________
    ## Barter Start Events
    - NWNX_ON_BARTER_START_BEFORE
    - NWNX_ON_BARTER_START_AFTER

    `OBJECT_SELF` = The player who initiated the barter

    Event Data Tag        | Type   | Notes
    ----------------------|--------|-------
    BARTER_TARGET         | object | The other player involved in the barter

_______________________________________
    ## Barter End Events
    - NWNX_ON_BARTER_END_BEFORE
    - NWNX_ON_BARTER_END_AFTER

    `OBJECT_SELF` = The player who initiated the barter

    Event Data Tag                | Type   | Notes
    ------------------------------|--------|-------
    BARTER_TARGET                 | object | The other player involved in the barter
    BARTER_COMPLETE               | int    | TRUE/FALSE - whether the barter completed successfully
    BARTER_INITIATOR_ITEM_COUNT   | int    | How many items the initiator traded away, only in _BEFORE events
    BARTER_TARGET_ITEM_COUNT      | int    | How many items the target traded away, only in _BEFORE events
    BARTER_INITIATOR_ITEM_*       | object | Convert to object with StringToObject(), only in _BEFORE events
    BARTER_TARGET_ITEM_*          | object | Convert to object with StringToObject(), only in _BEFORE events

_______________________________________
    ## Barter AddItem Events
    - NWNX_ON_BARTER_ADD_ITEM_BEFORE
    - NWNX_ON_BARTER_ADD_ITEM_AFTER

    `OBJECT_SELF` = The player trying to add an item to the barter window

    Event Data Tag        | Type   | Notes
    ----------------------|--------|-------
    ITEM                  | object | The item being added
    BARTER_TARGET         | object | The other player involved in the barter
_______________________________________
    ## Trap Events
    - NWNX_ON_TRAP_DISARM_BEFORE
    - NWNX_ON_TRAP_DISARM_AFTER
    - NWNX_ON_TRAP_ENTER_BEFORE
    - NWNX_ON_TRAP_ENTER_AFTER
    - NWNX_ON_TRAP_EXAMINE_BEFORE
    - NWNX_ON_TRAP_EXAMINE_AFTER
    - NWNX_ON_TRAP_FLAG_BEFORE
    - NWNX_ON_TRAP_FLAG_AFTER
    - NWNX_ON_TRAP_RECOVER_BEFORE
    - NWNX_ON_TRAP_RECOVER_AFTER
    - NWNX_ON_TRAP_SET_BEFORE
    - NWNX_ON_TRAP_SET_AFTER

    `OBJECT_SELF` = The creature performing the trap action

    Event Data Tag        | Type   | Notes
    ----------------------|--------|-------
    TRAP_OBJECT_ID        | object | Convert to object with StringToObject()
    TARGET_OBJECT_ID      | object | Convert to object with StringToObject(), only in SET events
    TARGET_POSITION_X     | float  | Only in SET events
    TARGET_POSITION_Y     | float  | Only in SET events
    TARGET_POSITION_Z     | float  | Only in SET events
    NEEDS_TO_MOVE         | int    | TRUE/FALSE, only in _BEFORE events (not ENTER), if TRUE another _BEFORE event will be fired before the actual interaction with the trap
    TRAP_FORCE_SET        | int    | TRUE/FALSE, only in ENTER events
    ACTION_RESULT         | int    | TRUE/FALSE, only in _AFTER events (not ENTER)

_______________________________________
    ## Timing Bar Events
    - NWNX_ON_TIMING_BAR_START_BEFORE
    - NWNX_ON_TIMING_BAR_START_AFTER
    - NWNX_ON_TIMING_BAR_STOP_BEFORE
    - NWNX_ON_TIMING_BAR_STOP_AFTER
    - NWNX_ON_TIMING_BAR_CANCEL_BEFORE
    - NWNX_ON_TIMING_BAR_CANCEL_AFTER

    `OBJECT_SELF` = The player the timing bar is for

    Event Data Tag        | Type   | Notes
    ----------------------|--------|-------
    EVENT_ID              | int    | The type of timing bar, see constants below, only in _START_ events
    DURATION              | int    | Length of time (in milliseconds) the bar is set to last, only in _START_ events

_______________________________________
    ## Webhook Events
    - NWNX_ON_WEBHOOK_SUCCESS
    - NWNX_ON_WEBHOOK_FAILURE

    `OBJECT_SELF` = The module object

    Event Data Tag        | Type   | Notes |
    ----------------------|--------|-------|
    STATUS                | int    | The return code after posting to the server |
    MESSAGE               | string | The full constructed message sent |
    HOST                  | string | |
    PATH                  | string | |
    RATELIMIT_LIMIT       | int    | Discord: The number of requests that can be made in a limited period |
    RATELIMIT_REMAINING   | int    | Discord: The number of remaining requests that can be made before rate limited |
    RATELIMIT_RESET       | int    | Discord: Timestamp when the rate limit resets |
    RETRY_AFTER           | float  | Milliseconds until another webhook is allowed when rate limited |
    FAIL_INFO             | string | The reason the hook failed aside from rate limits |

    @note Requires @ref webhook "NWNX_WebHook" plugin to work.

_______________________________________
    ## Servervault Events
    - NWNX_ON_CHECK_STICKY_PLAYER_NAME_RESERVED_BEFORE
    - NWNX_ON_CHECK_STICKY_PLAYER_NAME_RESERVED_AFTER

    `OBJECT_SELF` = The module

    Event Data Tag        | Type   | Notes
    ----------------------|--------|-------
    PLAYER_NAME           | string | Player name of the connecting client
    CDKEY                 | string | Public cdkey of the connecting client
    LEGACY_CDKEY          | string | Public cdkey from earlier versions of NWN
    IS_DM                 | int    | Whether the client is connecting as DM (1/0)

    @note Skipping the _BEFORE event will cause no player names to be accepted unless you SetEventResult("1")

_______________________________________
    ## Server Character Save Events
    - NWNX_ON_SERVER_CHARACTER_SAVE_BEFORE
    - NWNX_ON_SERVER_CHARACTER_SAVE_AFTER

    `OBJECT_SELF` = The player character being saved.

    @note This is called once for every character when the server is exiting and when the server is saved, or when ExportSingleCharacter() & ExportAllCharacters() is called.

_______________________________________
     ## Export Character Events
    - NWNX_ON_CLIENT_EXPORT_CHARACTER_BEFORE
    - NWNX_ON_CLIENT_EXPORT_CHARACTER_AFTER

    `OBJECT_SELF` = The player

    Note: This event runs when the player clicks the "Save Character" button in the options menu to export their character to their localvault.

_______________________________________
    ## Levelling Events
    - NWNX_ON_LEVEL_UP_BEFORE
    - NWNX_ON_LEVEL_UP_AFTER
    - NWNX_ON_LEVEL_UP_AUTOMATIC_BEFORE
    - NWNX_ON_LEVEL_UP_AUTOMATIC_AFTER
    - NWNX_ON_LEVEL_DOWN_BEFORE
    - NWNX_ON_LEVEL_DOWN_AFTER

    `OBJECT_SELF` = The creature levelling up or down, automatic is for henchmen levelling

_______________________________________
    ## Container Change Events
    - NWNX_ON_INVENTORY_ADD_ITEM_BEFORE
    - NWNX_ON_INVENTORY_ADD_ITEM_AFTER
    - NWNX_ON_INVENTORY_REMOVE_ITEM_BEFORE
    - NWNX_ON_INVENTORY_REMOVE_ITEM_AFTER

    @note NWNX_ON_INVENTORY_REMOVE_ITEM_* is not skippable

    `OBJECT_SELF` = The container

    Event Data Tag        | Type   | Notes
    ----------------------|--------|-------
    ITEM                  | object | Convert to object with StringToObject()

_______________________________________
    ## Gold Events
    - NWNX_ON_INVENTORY_ADD_GOLD_BEFORE
    - NWNX_ON_INVENTORY_ADD_GOLD_AFTER
    - NWNX_ON_INVENTORY_REMOVE_GOLD_BEFORE
    - NWNX_ON_INVENTORY_REMOVE_GOLD_AFTER

    `OBJECT_SELF` = The creature gaining or losing gold

    Event Data Tag        | Type   | Notes
    ----------------------|--------|-------
    GOLD                  | int    | The amount of gold added or removed

    @warning While these events are skippable, you should be very careful about doing so.
             It's very easy to create situations where players can dupe their gold or worse.

_______________________________________
    ## PVP Attitude Change Events
    - NWNX_ON_PVP_ATTITUDE_CHANGE_BEFORE
    - NWNX_ON_PVP_ATTITUDE_CHANGE_AFTER

    `OBJECT_SELF` = The player performing the attitude change

    Event Data Tag        | Type   | Notes
    ----------------------|--------|-------
    TARGET_OBJECT_ID      | object | Convert to object with StringToObject()
    ATTITUDE              | int    | 0 = Dislike, 1 = Like

_______________________________________
    ## Input Walk To Events
    - NWNX_ON_INPUT_WALK_TO_WAYPOINT_BEFORE
    - NWNX_ON_INPUT_WALK_TO_WAYPOINT_AFTER

    `OBJECT_SELF` = The player clicking somewhere to move

    Event Data Tag        | Type   | Notes |
    ----------------------|--------|-------|
    AREA                  | object | Convert to object with StringToObject() |
    POS_X                 | float  | |
    POS_Y                 | float  | |
    POS_Z                 | float  | |
    RUN_TO_POINT          | int    | TRUE if player is running, FALSE if player is walking (eg when shift clicking) |

_______________________________________
    ## Material Change Events
    - NWNX_ON_MATERIALCHANGE_BEFORE
    - NWNX_ON_MATERIALCHANGE_AFTER

    `OBJECT_SELF` = The creature walking on a different surface material

    Event Data Tag        | Type   | Notes
    ----------------------|--------|-------
    MATERIAL_TYPE         | int    | See surfacemat.2da for values

    @note: After a PC transitions to a new area, a surface material change event
    won't fire until after the PC moves.

_______________________________________
    ## Input Attack Events
    - NWNX_ON_INPUT_ATTACK_OBJECT_BEFORE
    - NWNX_ON_INPUT_ATTACK_OBJECT_AFTER

    `OBJECT_SELF` = The creature attacking

    Event Data Tag        | Type   | Notes
    ----------------------|--------|-------
    TARGET                | object | Convert to object with StringToObject()
    PASSIVE               | int    | TRUE / FALSE
    CLEAR_ALL_ACTIONS     | int    | TRUE / FALSE
    ADD_TO_FRONT          | int    | TRUE / FALSE

_______________________________________
    ## Input Force Move To Events
    - NWNX_ON_INPUT_FORCE_MOVE_TO_OBJECT_BEFORE
    - NWNX_ON_INPUT_FORCE_MOVE_TO_OBJECT_AFTER

    `OBJECT_SELF` = The creature forcibly moving

    Event Data Tag        | Type   | Notes
    ----------------------|--------|-------
    TARGET                | object | Convert to object with StringToObject()

 _______________________________________
    ## Input Cast Spell Events
    - NWNX_ON_INPUT_CAST_SPELL_BEFORE
    - NWNX_ON_INPUT_CAST_SPELL_AFTER

    `OBJECT_SELF` = The creature casting a spell

    Event Data Tag        | Type   | Notes
    ----------------------|--------|-------
    TARGET                | object | Convert to object with StringToObject() |
    SPELL_ID              | int    | |
    MULTICLASS            | int    | |
    DOMAIN_LEVEL          | int    | |
    META_TYPE             | int    | |
    INSTANT               | int    | TRUE / FALSE |
    PROJECTILE_PATH       | int    | |
    SPONTANEOUS           | int    | TRUE / FALSE |
    FAKE                  | int    | TRUE / FALSE |
    FEAT                  | int    | -1 when not cast from a feat |
    CASTER_LEVEL          | int    | |
    IS_AREA_TARGET        | int    | TRUE / FALSE |
    POS_X                 | float  | |
    POS_Y                 | float  | |
    POS_Z                 | float  | |

    @note This event runs the moment a creature starts casting

_______________________________________
    ## Input Keyboard Events
    - NWNX_ON_INPUT_KEYBOARD_BEFORE
    - NWNX_ON_INPUT_KEYBOARD_AFTER

    `OBJECT_SELF` = The player

    Event Data Tag        | Type   | Notes
    ----------------------|--------|-------
    KEY                   | string | The key pressed by the player, one of the following: W A S D Q E

    @note To stop the player from moving you can do something like below, since normal immobilizing effects stop the client
          from sending input.

          location locPlayer = GetLocation(oPlayer);
          object oBoulder = CreateObject(OBJECT_TYPE_PLACEABLE, "plc_boulder", locPlayer, FALSE, "TESTPLC");
          NWNX_Object_SetPosition(oPlayer, GetPositionFromLocation(locPlayer));
          ApplyEffectToObject(DURATION_TYPE_PERMANENT, EffectVisualEffect(VFX_DUR_CUTSCENE_INVISIBILITY), oBoulder);

_______________________________________
    ## Input Keyboard Events
    - NWNX_ON_INPUT_TOGGLE_PAUSE_BEFORE
    - NWNX_ON_INPUT_TOGGLE_PAUSE_AFTER

    `OBJECT_SELF` = The player or DM

    Event Data Tag        | Type   | Notes
    ----------------------|--------|-------
    PAUSE_STATE           | int    | TRUE = Pausing, FALSE = Unpausing

    @note This event also fires when a non-dm player presses the spacebar.

_______________________________________
    ## Object Lock Events
    - NWNX_ON_OBJECT_LOCK_BEFORE
    - NWNX_ON_OBJECT_LOCK_AFTER

    `OBJECT_SELF` = The object doing the locking

    Event Data Tag        | Type   | Notes
    ----------------------|--------|-------
    DOOR                  | object | Convert to object with StringToObject()
    ACTION_RESULT         | int    | TRUE/FALSE, only in _AFTER events

_______________________________________
    ## Object Unlock Events
    - NWNX_ON_OBJECT_UNLOCK_BEFORE
    - NWNX_ON_OBJECT_UNLOCK_AFTER

    `OBJECT_SELF` = The object doing the unlocking

    Event Data Tag        | Type   | Notes
    ----------------------|--------|-------
    DOOR                  | object | Convert to object with StringToObject() |
    THIEVES_TOOL          | object | Convert to object with StringToObject() |
    ACTIVE_PROPERTY_INDEX | int    | |
    ACTION_RESULT         | int    | TRUE/FALSE, only in _AFTER events |

_______________________________________
    ## UUID Collision Events
    - NWNX_ON_UUID_COLLISION_BEFORE
    - NWNX_ON_UUID_COLLISION_AFTER

    `OBJECT_SELF` = The object that caused the UUID collision

    Event Data Tag        | Type   | Notes
    ----------------------|--------|-------
    UUID                  | string | The UUID

    Note: To get the existing object with `UUID` you can use GetObjectByUUID(), be aware that this event runs before the
          object is added to the world which means many functions (for example `GetArea(OBJECT_SELF)`) will not work.

_______________________________________
    ## Resource Events
    - NWNX_ON_RESOURCE_ADDED
    - NWNX_ON_RESOURCE_REMOVED
    - NWNX_ON_RESOURCE_MODIFIED

    `OBJECT_SELF` = The module

    Event Data Tag        | Type   | Notes
    ----------------------|--------|-------
    ALIAS                 | string | NWNX for /nwnx, DEVELOPMENT for /development. Also supports valid aliases from the Custom Resman Definition File
    RESREF                | string | The ResRef of the file
    TYPE                  | int    | The type of the file, see NWNX_UTIL_RESREF_TYPE_*

    Note: These events fire when a file gets added/removed/modified in resource folders like /nwnx, /development and those defined in the Custom Resman Definition File

_______________________________________
    ## ELC Events
    - NWNX_ON_ELC_VALIDATE_CHARACTER_BEFORE
    - NWNX_ON_ELC_VALIDATE_CHARACTER_AFTER

    `OBJECT_SELF` = The player

    Note: NWNX_ELC must be loaded for these events to work. The `_AFTER` event only fires if the character successfully
          completes validation.

_______________________________________
     ## Quickbar Events
    - NWNX_ON_QUICKBAR_SET_BUTTON_BEFORE
    - NWNX_ON_QUICKBAR_SET_BUTTON_AFTER

    `OBJECT_SELF` = The player

    Event Data Tag        | Type   | Notes
    ----------------------|--------|-------
    BUTTON                | int    | The quickbar button slot, 0-35
    TYPE                  | int    | The type of quickbar button set, see NWNX_PLAYER_QBS_TYPE_* in nwnx_player_qbs.nss

    Note: Skipping the event does not prevent the client from changing the button clientside, the change won't however
          be saved to the bic file.

_______________________________________
     ## Calendar Events
    - NWNX_ON_CALENDAR_HOUR
    - NWNX_ON_CALENDAR_DAY
    - NWNX_ON_CALENDAR_MONTH
    - NWNX_ON_CALENDAR_YEAR
    - NWNX_ON_CALENDAR_DAWN
    - NWNX_ON_CALENDAR_DUSK

    `OBJECT_SELF` = The module

    Event Data Tag        | Type   | Notes
    ----------------------|--------|-------
    OLD                   | int    | The (Hour/Day/Month/Year) before the change. Not available in DAWN/DUSK.
    NEW                   | int    | The (Hour/Day/Month/Year) after the change. Not available in DAWN/DUSK.

_______________________________________
    ## Broadcast Spell Cast Events
    - NWNX_ON_BROADCAST_CAST_SPELL_BEFORE
    - NWNX_ON_BROADCAST_CAST_SPELL_AFTER

    `OBJECT_SELF` = The creature casting the spell

    Event Data Tag        | Type   | Notes |
    ----------------------|--------|-------|
    SPELL_ID              | int    | |
    MULTI_CLASS           | int    | |
    FEAT                  | int    | 65535 if a feat wasn't used, otherwise the feat ID |
    TARGET_OBJECT_ID      | object | Convert to object with StringToObject() |
    TARGET_POSITION_X     | float  | |
    TARGET_POSITION_Y     | float  | |
    TARGET_POSITION_Z     | float  | |
    SPELL_DOMAIN          | int    | |
    SPELL_SPONTANEOUS     | int    | |
    SPELL_METAMAGIC       | int    | METAMAGIC_* |
    PROJECTILE_PATH_TYPE  | int    | PROJECTILE_PATH_TYPE_* |

    @note TARGET_OBJECT_ID, TARGET_POSITION_*, SPELL_DOMAIN, SPELL_SPONTANEOUS, SPELL_METAMAGIC, and PROJECTILE_PATH_TYPE may
          be invalid if BroadcastCastSpell was called outside AIActionCastSpell.
          This can be tested for by checking if TARGET_OBJECT_ID is the caster's area and if all three TARGET_POSITION_* equal 0.0.
          \code{.c}
          if (oTarget == GetArea(oCaster) && Vector(vX, vY, fZ) == Vector())
          {
            // ...
          }
          \endcode
_______________________________________
    ## RunScript Debug Event
    - NWNX_ON_DEBUG_RUN_SCRIPT_BEFORE
    - NWNX_ON_DEBUG_RUN_SCRIPT_AFTER

    `OBJECT_SELF` = The player executing the RunScript debug command

    Event Data Tag        | Type   | Notes |
    ----------------------|--------|-------|
    SCRIPT_NAME           | string | The script to execute |
    TARGET                | object | The target to run the script on. Convert to object with StringToObject() |

    @note This event also runs for players that do not have permission to execute the command.

_______________________________________
    ## RunScriptChunk Debug Event
    - NWNX_ON_DEBUG_RUN_SCRIPT_CHUNK_BEFORE
    - NWNX_ON_DEBUG_RUN_SCRIPT_CHUNK_AFTER

    `OBJECT_SELF` = The player executing the RunScriptChunk debug command

    Event Data Tag        | Type   | Notes |
    ----------------------|--------|-------|
    SCRIPT_CHUNK          | string | The script chunk |
    TARGET                | object | The target to run the script chunk on. Convert to object with StringToObject() |
    WRAP_INTO_MAIN        | int    | TRUE if the WrapIntoMain checkbox is checked, otherwise FALSE |

    @note This event also runs for players that do not have permission to execute the command.

_______________________________________
    ## Play Visual Effect Event
    - NWNX_ON_DEBUG_PLAY_VISUAL_EFFECT_BEFORE
    - NWNX_ON_DEBUG_PLAY_VISUAL_EFFECT_AFTER

    `OBJECT_SELF` = The DM

    Event Data Tag        | Type   | Notes
    ----------------------|--------|-------
    TARGET_OBJECT_ID      | object | Convert to object with StringToObject()
    VISUAL_EFFECT         | int    | Index into visualeffects.2da
    DURATION              | float  |
    TARGET_POSITION_X     | float  | Will be 0.0 when playing visual effects on an object
    TARGET_POSITION_Y     | float  | Will be 0.0 when playing visual effects on an object
    TARGET_POSITION_Z     | float  | Will be 0.0 when playing visual effects on an object

    @note This is the `dm_visualeffect` console command.
    `TARGET_OBJECT_ID` will be `OBJECT_INVALID` when playing visual effects at a position in an area.

_______________________________________
    ## Buy/Sell Store Events
    - NWNX_ON_STORE_REQUEST_BUY_BEFORE
    - NWNX_ON_STORE_REQUEST_BUY_AFTER
    - NWNX_ON_STORE_REQUEST_SELL_BEFORE
    - NWNX_ON_STORE_REQUEST_SELL_AFTER

    `OBJECT_SELF` = The creature buying or selling an item

    Event Data Tag        | Type   | Notes |
    ----------------------|--------|-------|
    ITEM                  | object | The item being bought or sold. Convert to object with StringToObject()  |
    STORE                 | object | The store the item is being sold to or bought from. Convert to object with StringToObject() |
    PRICE                 | int    | The buy or sell price |
    RESULT                | int    | TRUE/FALSE whether the request was successful. Only in *_AFTER events.

    @warning RESULT in NWNX_ON_STORE_REQUEST_BUY_AFTER only fails if it's due to lack of gold.  It will not fail if item does not fit in player's inventory.  If you want to check and fail on that condition, you can do something like this in the NWNX_ON_STORE_REQUEST_BUY_AFTER event:
    ```c
	if (!GetBaseItemFitsInInventory(GetBaseItemType(oItem), oPlayer))
	{
		NWNX_Events_SetEventResult("0");
		return;
	}
    ```

_______________________________________
    ## Server Send Area Events
    - NWNX_ON_SERVER_SEND_AREA_BEFORE
    - NWNX_ON_SERVER_SEND_AREA_AFTER

    `OBJECT_SELF` = The player

    Event Data Tag        | Type   | Notes
    ----------------------|--------|-------
    AREA                  | object | The area the server is sending. Convert to object with StringToObject() |
    PLAYER_NEW_TO_MODULE  | int    | TRUE if it's the player's first time logging into the server since a restart |

_______________________________________
    ## Journal Open/Close Events
    - NWNX_ON_JOURNAL_OPEN_BEFORE
    - NWNX_ON_JOURNAL_OPEN_AFTER
    - NWNX_ON_JOURNAL_CLOSE_BEFORE
    - NWNX_ON_JOURNAL_CLOSE_AFTER

    `OBJECT_SELF` = The player

    Event Data Tag        | Type   | Notes
    ----------------------|--------|-------

_______________________________________
    ## Input Emote Event
    - NWNX_ON_INPUT_EMOTE_BEFORE
    - NWNX_ON_INPUT_EMOTE_AFTER

    `OBJECT_SELF` = The creature using a radial menu emote

    Event Data Tag        | Type   | Notes
    ----------------------|--------|-------
    ANIMATION             | int    | An engine animation constant, convent to NWScript animation constant with NWNX_Consts_TranslateEngineAnimation() |

    @note Some emotes have a voiceline that will still play when the event is skipped. These voicelines can be skipped in the NWNX_ON_QUICKCHAT_* event.

_______________________________________
    ## Combat Damage Resistance/Reduction Broken Event
    - NWNX_ON_COMBAT_DR_BROKEN_BEFORE
    - NWNX_ON_COMBAT_DR_BROKEN_AFTER

    `OBJECT_SELF` = The creature whose DR gets broken

    Event Data Tag        | Type   | Notes
    ----------------------|--------|-------
    TYPE                  | int    | 1 for DamageResistance, 0 for DamageReduction |

    @note This event only fires when DR gets broken in combat.

_______________________________________
    ## Creature Unpossess Familiar Event
    - NWNX_ON_UNPOSSESS_FAMILIAR_BEFORE
    - NWNX_ON_UNPOSSESS_FAMILIAR_AFTER

    `OBJECT_SELF` = The creature unpossessing a familiar

    Event Data Tag        | Type   | Notes
    ----------------------|--------|-------
    FAMILIAR              | object | The familiar. Convert to object with StringToObject() |

_______________________________________
    ## Client Levelup Begin Event
    - NWNX_ON_CLIENT_LEVEL_UP_BEGIN_BEFORE
    - NWNX_ON_CLIENT_LEVEL_UP_BEGIN_AFTER

    `OBJECT_SELF` = The player clicking the levelup button

    Event Data Tag        | Type   | Notes
    ----------------------|--------|-------

_______________________________________
    ## Creature Possess Familiar Event
    - NWNX_ON_POSSESS_FAMILIAR_BEFORE
    - NWNX_ON_POSSESS_FAMILIAR_AFTER

    `OBJECT_SELF` = The creature possessing a familiar

    Event Data Tag        | Type   | Notes
    ----------------------|--------|-------
    FAMILIAR              | object | The familiar. Convert to object with StringToObject() |
_______________________________________
    ## Player CharacterSheet Permitted Event
    - NWNX_ON_CHARACTER_SHEET_PERMITTED_BEFORE
    - NWNX_ON_CHARACTER_SHEET_PERMITTED_AFTER

    `OBJECT_SELF` = The player trying to view a charactersheet

    Event Data Tag        | Type   | Notes
    ----------------------|--------|-------
    TARGET                | object | Convert to object with StringToObject() |

    @note When skipping this event, be sure to set the event result.
_______________________________________
    ## Player CharacterSheet Open/Close Events
    - NWNX_ON_CHARACTER_SHEET_OPEN_BEFORE
    - NWNX_ON_CHARACTER_SHEET_OPEN_AFTER
    - NWNX_ON_CHARACTER_SHEET_CLOSE_BEFORE
    - NWNX_ON_CHARACTER_SHEET_CLOSE_AFTER

    `OBJECT_SELF` = The player opening or closing a charactersheet

    Event Data Tag        | Type   | Notes
    ----------------------|--------|-------
    TARGET                | object | Convert to object with StringToObject() |
_______________________________________
    ## Player Device Property Events
    - NWNX_ON_CLIENT_SET_DEVICE_PROPERTY_BEFORE
    - NWNX_ON_CLIENT_SET_DEVICE_PROPERTY_AFTER

    `OBJECT_SELF` = The player changing a device property (window size/gui scale)

    Event Data Tag        | Type   | Notes
    ----------------------|--------|-------
    PROPERTY              | string | A PLAYER_DEVICE_PROPERTY_GUI_* constant |
    OLD_VALUE             | int    | |
    NEW_VALUE             | int    | |
_______________________________________
    ## Input Drop Item Events
    - NWNX_ON_INPUT_DROP_ITEM_BEFORE
    - NWNX_ON_INPUT_DROP_ITEM_AFTER

    `OBJECT_SELF` = The player dropping an item

    Event Data Tag        | Type   | Notes
    ----------------------|--------|-------
    ITEM                  | object | Convert to object with StringToObject() |
    POS_X                 | float  | |
    POS_Y                 | float  | |
    POS_Z                 | float  | |
_______________________________________
    ## Decrement Spell Count Events
    - NWNX_ON_DECREMENT_SPELL_COUNT_BEFORE
    - NWNX_ON_DECREMENT_SPELL_COUNT_AFTER

    `OBJECT_SELF` = The player losing a spell slot

    Event Data Tag        | Type   | Notes
    ----------------------|--------|-------
    SPELL_ID              | int    | |
    CLASS                 | int    | Index of the spell casting class (0-2). Returns 254 for spell-like abilities |
    DOMAIN                | int    | Spell level if non-default due to Domain |
    METAMAGIC             | int    | |
    CASTERLEVEL           | int    | Only returns for spell-like abilities |
_______________________________________
    ## EventScript Events
    - NWNX_ON_RUN_EVENT_SCRIPT_BEFORE
    - NWNX_ON_RUN_EVENT_SCRIPT_AFTER

    `OBJECT_SELF` = The object the event script is running on

    Event Data Tag        | Type   | Notes
    ----------------------|--------|-------
    EVENT_TYPE            | int    | EVENT_SCRIPT_* in nwscript.nss |
    EVENT_SCRIPT          | int    | Script name running (can be empty) |

    @note This event should definitely be used with the Event ID Whitelist, which is turned on by default
    for this event. Until you add your EVENT_SCRIPT_ to the whitelist this event will not function:
    ```c
    NWNX_Events_SubscribeEvent("NWNX_ON_RUN_EVENT_SCRIPT_BEFORE", "creature_hb_ovr");
    NWNX_Events_AddIDToWhitelist("NWNX_ON_RUN_EVENT_SCRIPT", EVENT_SCRIPT_MODULE_ON_HEARTBEAT);
    ```
    @warning Toggling the Whitelist to be off for this event will degrade performance.
_______________________________________
    ## Object Use Events (Placeables)
    - NWNX_ON_OBJECT_USE_BEFORE
    - NWNX_ON_OBJECT_USE_AFTER

    `OBJECT_SELF` = The player using the object

    Event Data Tag        | Type   | Notes
    ----------------------|--------|-------
    OBJECT                | object | The Object being used |
_______________________________________
    ## Placeable Open Events (Placeables with inventory)
    - NWNX_ON_PLACEABLE_OPEN_BEFORE
    - NWNX_ON_PLACEABLE_OPEN_AFTER

    `OBJECT_SELF` = The placeable being openeed.

    Event Data Tag        | Type   | Notes
    ----------------------|--------|-------
    OBJECT                | object | The player opening. |
    BEFORE_SKIPPED        | int    | TRUE/FALSE, only in _AFTER events|
_______________________________________
    ## Placeable Close Events (Placeables with inventory)
    - NWNX_ON_PLACEABLE_CLOSE_BEFORE
    - NWNX_ON_PLACEABLE_CLOSE_AFTER

    `OBJECT_SELF` = The placeable being closed.

    Event Data Tag        | Type   | Notes
    ----------------------|--------|-------
    OBJECT                | object | The player closing. |

    @note Skipping event is not allowed (since otherwise client UI will hang and be glitchy)
_______________________________________
    ## Broadcast Safe Projectile Events
    - NWNX_ON_BROADCAST_SAFE_PROJECTILE_BEFORE
    - NWNX_ON_BROADCAST_SAFE_PROJECTILE_AFTER

    `OBJECT_SELF` = The creature casting the spell

    Event Data Tag        | Type   | Notes |
    ----------------------|--------|-------|
    TARGET_OBJECT_ID      | string | Convert to object with StringToObject() |
    TARGET_POSITION_X     | float  | |
    TARGET_POSITION_Y     | float  | |
    TARGET_POSITION_Z     | float  | |
    DELTA                 | int    | Time in milliseconds before the projectile reaches its destination |
    PROJECTILE_TYPE       | int    | @ref events_projtype "NWNX_EVENTS_BROADCAST_SAFE_PROJECTILE_TYPE_*" |
    SPELL_ID              | int    | |
    ATTACK_RESULT         | int    | 0=n/a, 1=hit, 2=parried, 3=critical hit, 4=miss, 5=resisted, 7=automatic hit, 8=concealed, 9=miss chance, 10=devastating crit |
    PROJECTILE_PATH_TYPE  | int    | @nwn{Projectile_path_type,PROJECTILE_PATH_TYPE_*} |

    @note This event fires for all projectiles. It's recommended to use ID whitelists with this event. You can whitelist the event by the projectile type, spell id, or both:
          \code{.c}
          NWNX_Events_AddIDToWhitelist("NWNX_ON_BROADCAST_SAFE_PROJECTILE_TYPE", NWNX_EVENTS_BROADCAST_SAFE_PROJECTILE_TYPE_*);
          NWNX_Events_AddIDToWhitelist("NWNX_ON_BROADCAST_SAFE_PROJECTILE_SPELL", SPELL_*);
          \endcode
          `TARGET_OBJECT_ID` will be `OBJECT_INVALID` if the projectile is cast at a location
_______________________________________
    ## SetExperience Events
    - NWNX_ON_SET_EXPERIENCE_BEFORE
    - NWNX_ON_SET_EXPERIENCE_AFTER

    `OBJECT_SELF` = The player the xp is being set on

    Event Data Tag        | Type   | Notes
    ----------------------|--------|-------
    XP                    | int    | The xp value to be set. |

    @note To set a different xp value in the BEFORE event: Skip the event and call NWNX_Events_SetEventResult() with the new value.
_______________________________________
    ## Broadcast Attack of Opportunity Events
    - NWNX_ON_BROADCAST_ATTACK_OF_OPPORTUNITY_BEFORE
    - NWNX_ON_BROADCAST_ATTACK_OF_OPPORTUNITY_AFTER

    `OBJECT_SELF` = The creature broadcasting the Attack of Opportunity event

    Event Data Tag        | Type   | Notes
    ----------------------|--------|-------
    TARGET_OBJECT_ID      | object | A single object the attack of opportunity is being broadcast to. Convert to object with StringToObject() |
    MOVEMENT              | int    | Whether this attack of opportunity is being triggered from movement |
_______________________________________
    ## Combat Attack of Opportunity Events
    - NWNX_ON_COMBAT_ATTACK_OF_OPPORTUNITY_BEFORE
    - NWNX_ON_COMBAT_ATTACK_OF_OPPORTUNITY_AFTER

    `OBJECT_SELF` = The creature performing the Attack of Opportunity against the broadcasting target.

    Event Data Tag        | Type   | Notes
    ----------------------|--------|-------
    TARGET_OBJECT_ID      | object | The target of the attack of opportunity. Convert to object with StringToObject() |

    @note If the BEFORE event is skipped the broadcasting creature will still make a tumble skill roll if moving.
_______________________________________
    ## Area Play Battle Music Events
    - NWNX_ON_AREA_PLAY_BATTLE_MUSIC_BEFORE
    - NWNX_ON_AREA_PLAY_BATTLE_MUSIC_AFTER

    `OBJECT_SELF` = The area playing or stopping the battle music.

    Event Data Tag        | Type   | Notes
    ----------------------|--------|-------
    PLAY                  | int | TRUE if the area is starting to play battle music, FALSE if stopping. |
_______________________________________
    ## Combat Attack Target Change Events
    - NWNX_ON_ATTACK_TARGET_CHANGE_BEFORE
    - NWNX_ON_ATTACK_TARGET_CHANGE_AFTER

    `OBJECT_SELF` = The creature changing the target its attacking.

    Event Data Tag        | Type   | Notes
    ----------------------|--------|-------
    OLD_TARGET_OBJECT_ID  | object | The old attack target. OBJECT_INVALID if there was no old target. Old target may be dead/invalid. Convert to object with StringToObject() |
    NEW_TARGET_OBJECT_ID  | object | The new attack target. OBJECT_INVALID if there is no new target. Convert to object with StringToObject() |
    AUTOMATIC_CHANGE      | int    | TRUE if the game automatically decided on the new target, FALSE if explicitly chosen |
    RETARGETABLE          | int    | TRUE if the new target can be changed using NWNX_Events_SetEventResult() (Only in BEFORE) |
_______________________________________
    ## Creature Tile Change Events
    - NWNX_ON_CREATURE_TILE_CHANGE_BEFORE
    - NWNX_ON_CREATURE_TILE_CHANGE_AFTER

    `OBJECT_SELF` = The creature changing tile positions.

    Event Data Tag        | Type   | Notes
    ----------------------|--------|-------
    OLD_TILE_INDEX        | int    | The index of the old tile. |
    OLD_TILE_X            | int    | The tile grid x position of the old tile. |
    OLD_TILE_Y            | int    | The tile grid y position of the old tile. |
    NEW_TILE_INDEX        | int    | The index of the new tile. |
    NEW_TILE_X            | int    | The tile grid x position of the new tile. |
    NEW_TILE_Y            | int    | The tile grid y position of the new tile. |
_______________________________________
    ## Creature Jump To Point Events
    - NWNX_ON_CREATURE_JUMP_TO_POINT_BEFORE
    - NWNX_ON_CREATURE_JUMP_TO_POINT_AFTER

    `OBJECT_SELF` = The creature jumping.

    Event Data Tag        | Type   | Notes
    ----------------------|--------|-------
    TARGET_AREA           | object | The target area. Convert to object with StringToObject() |
    POS_X                 | float  | The x position the target is being moved to |
    POS_Y                 | float  | The y position the target is being moved to |
    POS_Z                 | float  | The z position the target is being moved to |
_______________________________________
    ## Creature Jump To Object Events
    - NWNX_ON_CREATURE_JUMP_TO_OBJECT_BEFORE
    - NWNX_ON_CREATURE_JUMP_TO_OBJECT_AFTER

    `OBJECT_SELF` = The creature jumping.

    Event Data Tag        | Type   | Notes
    ----------------------|--------|-------
    OBJECT                | object | The object the creature is jumping to. Convert to object with StringToObject() |
_______________________________________
    ## Item Property Effect Apply/Remove Events
    - NWNX_ON_ITEMPROPERTY_EFFECT_APPLIED_BEFORE
    - NWNX_ON_ITEMPROPERTY_EFFECT_APPLIED_AFTER
    - NWNX_ON_ITEMPROPERTY_EFFECT_REMOVED_BEFORE
    - NWNX_ON_ITEMPROPERTY_EFFECT_REMOVED_AFTER

    `OBJECT_SELF` = The item source of the item property.

    Event Data Tag        | Type   | Notes
    ----------------------|--------|-------
    CREATURE              | object | The creature to which Convert to object with StringToObject() |
    LOADING_GAME          | int    | TRUE if the itemproperty is being applied when loading into the game and not due to equipping the item. |
    INVENTORY_SLOT        | int    | The INVENTORY_SLOT_* the item is (un)equipped to/from. |
    PROPERTY              | int    | The ITEM_PROPERTY_* type. |
    SUBTYPE               | int    | The subtype of the itemproperty. |
    TAG                   | string | The optional tag set by TagItemProperty() |
    COST_TABLE            | int    | The index into iprp_costtable.2da |
    COST_TABLE_VALUE      | int    | The index into the 2da pointed at by COST_TABLE |
    PARAM1                | int    | The index into iprp_paramtable.2da |
    PARAM1_VALUE          | int    | The index into the 2da pointed at by PARAM1 |

    @note These events fire when the game applies or removes the effects from an itemproperty.
          Skipping NWNX_ON_ITEMPROPERTY_EFFECT_APPLIED_BEFORE will stop the basegame effects for that itemproperty to not be applied.
          If you skip the application of ITEM_PROPERTY_BONUS_SPELL_SLOT_OF_LEVEL_N or ITEM_PROPERTY_UNLIMITED_AMMUNITION you must also skip its removal event.

    @note Any non-DURATION_TYPE_INSTANT effects applied to the creature in NWNX_ON_ITEMPROPERTY_EFFECT_APPLIED_BEFORE **must** be of type DURATION_TYPE_EQUIPPED
          See the `NWNX_EFFECT_EXTEND_DURATION_TYPE` environment variable in NWNX_Effect on how to enable this duration type.

    @note See the NWNX_Events README.md for an example script!

    @note The whitelist is enabled by default for these events, to whitelist a particular itemproperty, do the following:
          \code{.c}
          NWNX_Events_AddIDToWhitelist("NWNX_ON_ITEMPROPERTY_EFFECT", ITEM_PROPERTY_*);
          \endcode
*/

/// @name Events Event Constants
/// @anchor events_events
/// @{
const string NWNX_ON_ADD_ASSOCIATE_BEFORE = "NWNX_ON_ADD_ASSOCIATE_BEFORE";
const string NWNX_ON_ADD_ASSOCIATE_AFTER = "NWNX_ON_ADD_ASSOCIATE_AFTER";
const string NWNX_ON_REMOVE_ASSOCIATE_BEFORE = "NWNX_ON_REMOVE_ASSOCIATE_BEFORE";
const string NWNX_ON_REMOVE_ASSOCIATE_AFTER = "NWNX_ON_REMOVE_ASSOCIATE_AFTER";
const string NWNX_ON_STEALTH_ENTER_BEFORE = "NWNX_ON_STEALTH_ENTER_BEFORE";
const string NWNX_ON_STEALTH_ENTER_AFTER = "NWNX_ON_STEALTH_ENTER_AFTER";
const string NWNX_ON_STEALTH_EXIT_BEFORE = "NWNX_ON_STEALTH_EXIT_BEFORE";
const string NWNX_ON_STEALTH_EXIT_AFTER = "NWNX_ON_STEALTH_EXIT_AFTER";
const string NWNX_ON_DETECT_ENTER_BEFORE = "NWNX_ON_DETECT_ENTER_BEFORE";
const string NWNX_ON_DETECT_ENTER_AFTER = "NWNX_ON_DETECT_ENTER_AFTER";
const string NWNX_ON_DETECT_EXIT_BEFORE = "NWNX_ON_DETECT_EXIT_BEFORE";
const string NWNX_ON_DETECT_EXIT_AFTER = "NWNX_ON_DETECT_EXIT_AFTER";
const string NWNX_ON_EXAMINE_OBJECT_BEFORE = "NWNX_ON_EXAMINE_OBJECT_BEFORE";
const string NWNX_ON_EXAMINE_OBJECT_AFTER = "NWNX_ON_EXAMINE_OBJECT_AFTER";
const string NWNX_ON_SET_NPC_FACTION_REPUTATION_BEFORE = "NWNX_ON_SET_NPC_FACTION_REPUTATION_BEFORE";
const string NWNX_ON_SET_NPC_FACTION_REPUTATION_AFTER = "NWNX_ON_SET_NPC_FACTION_REPUTATION_AFTER";
const string NWNX_ON_VALIDATE_USE_ITEM_BEFORE = "NWNX_ON_VALIDATE_USE_ITEM_BEFORE";
const string NWNX_ON_VALIDATE_USE_ITEM_AFTER = "NWNX_ON_VALIDATE_USE_ITEM_AFTER";
const string NWNX_ON_USE_ITEM_BEFORE = "NWNX_ON_USE_ITEM_BEFORE";
const string NWNX_ON_USE_ITEM_AFTER = "NWNX_ON_USE_ITEM_AFTER";
const string NWNX_ON_ITEM_INVENTORY_OPEN_BEFORE = "NWNX_ON_ITEM_INVENTORY_OPEN_BEFORE";
const string NWNX_ON_ITEM_INVENTORY_OPEN_AFTER = "NWNX_ON_ITEM_INVENTORY_OPEN_AFTER";
const string NWNX_ON_ITEM_INVENTORY_CLOSE_BEFORE = "NWNX_ON_ITEM_INVENTORY_CLOSE_BEFORE";
const string NWNX_ON_ITEM_INVENTORY_CLOSE_AFTER = "NWNX_ON_ITEM_INVENTORY_CLOSE_AFTER";
const string NWNX_ON_ITEM_AMMO_RELOAD_BEFORE = "NWNX_ON_ITEM_AMMO_RELOAD_BEFORE";
const string NWNX_ON_ITEM_AMMO_RELOAD_AFTER = "NWNX_ON_ITEM_AMMO_RELOAD_AFTER";
const string NWNX_ON_ITEM_SCROLL_LEARN_BEFORE = "NWNX_ON_ITEM_SCROLL_LEARN_BEFORE";
const string NWNX_ON_ITEM_SCROLL_LEARN_AFTER = "NWNX_ON_ITEM_SCROLL_LEARN_AFTER";
const string NWNX_ON_VALIDATE_ITEM_EQUIP_BEFORE = "NWNX_ON_VALIDATE_ITEM_EQUIP_BEFORE";
const string NWNX_ON_VALIDATE_ITEM_EQUIP_AFTER = "NWNX_ON_VALIDATE_ITEM_EQUIP_AFTER";
const string NWNX_ON_ITEM_EQUIP_BEFORE = "NWNX_ON_ITEM_EQUIP_BEFORE";
const string NWNX_ON_ITEM_EQUIP_AFTER = "NWNX_ON_ITEM_EQUIP_AFTER";
const string NWNX_ON_ITEM_UNEQUIP_BEFORE = "NWNX_ON_ITEM_UNEQUIP_BEFORE";
const string NWNX_ON_ITEM_UNEQUIP_AFTER = "NWNX_ON_ITEM_UNEQUIP_AFTER";
const string NWNX_ON_ITEM_DESTROY_OBJECT_BEFORE = "NWNX_ON_ITEM_DESTROY_OBJECT_BEFORE";
const string NWNX_ON_ITEM_DESTROY_OBJECT_AFTER = "NWNX_ON_ITEM_DESTROY_OBJECT_AFTER";
const string NWNX_ON_ITEM_DECREMENT_STACKSIZE_BEFORE = "NWNX_ON_ITEM_DECREMENT_STACKSIZE_BEFORE";
const string NWNX_ON_ITEM_DECREMENT_STACKSIZE_AFTER = "NWNX_ON_ITEM_DECREMENT_STACKSIZE_AFTER";
const string NWNX_ON_ITEM_USE_LORE_BEFORE = "NWNX_ON_ITEM_USE_LORE_BEFORE";
const string NWNX_ON_ITEM_USE_LORE_AFTER = "NWNX_ON_ITEM_USE_LORE_AFTER";
const string NWNX_ON_ITEM_PAY_TO_IDENTIFY_BEFORE = "NWNX_ON_ITEM_PAY_TO_IDENTIFY_BEFORE";
const string NWNX_ON_ITEM_PAY_TO_IDENTIFY_AFTER = "NWNX_ON_ITEM_PAY_TO_IDENTIFY_AFTER";
const string NWNX_ON_ITEM_SPLIT_BEFORE = "NWNX_ON_ITEM_SPLIT_BEFORE";
const string NWNX_ON_ITEM_SPLIT_AFTER = "NWNX_ON_ITEM_SPLIT_AFTER";
const string NWNX_ON_ITEM_MERGE_BEFORE = "NWNX_ON_ITEM_MERGE_BEFORE";
const string NWNX_ON_ITEM_MERGE_AFTER = "NWNX_ON_ITEM_MERGE_AFTER";
const string NWNX_ON_ITEM_ACQUIRE_BEFORE = "NWNX_ON_ITEM_ACQUIRE_BEFORE";
const string NWNX_ON_ITEM_ACQUIRE_AFTER = "NWNX_ON_ITEM_ACQUIRE_AFTER";
const string NWNX_ON_USE_FEAT_BEFORE = "NWNX_ON_USE_FEAT_BEFORE";
const string NWNX_ON_USE_FEAT_AFTER = "NWNX_ON_USE_FEAT_AFTER";
const string NWNX_ON_HAS_FEAT_BEFORE = "NWNX_ON_HAS_FEAT_BEFORE";
const string NWNX_ON_HAS_FEAT_AFTER = "NWNX_ON_HAS_FEAT_AFTER";
const string NWNX_ON_DM_GIVE_GOLD_BEFORE = "NWNX_ON_DM_GIVE_GOLD_BEFORE";
const string NWNX_ON_DM_GIVE_GOLD_AFTER = "NWNX_ON_DM_GIVE_GOLD_AFTER";
const string NWNX_ON_DM_GIVE_XP_BEFORE = "NWNX_ON_DM_GIVE_XP_BEFORE";
const string NWNX_ON_DM_GIVE_XP_AFTER = "NWNX_ON_DM_GIVE_XP_AFTER";
const string NWNX_ON_DM_GIVE_LEVEL_BEFORE = "NWNX_ON_DM_GIVE_LEVEL_BEFORE";
const string NWNX_ON_DM_GIVE_LEVEL_AFTER = "NWNX_ON_DM_GIVE_LEVEL_AFTER";
const string NWNX_ON_DM_GIVE_ALIGNMENT_BEFORE = "NWNX_ON_DM_GIVE_ALIGNMENT_BEFORE";
const string NWNX_ON_DM_GIVE_ALIGNMENT_AFTER = "NWNX_ON_DM_GIVE_ALIGNMENT_AFTER";
const string NWNX_ON_DM_SPAWN_OBJECT_BEFORE = "NWNX_ON_DM_SPAWN_OBJECT_BEFORE";
const string NWNX_ON_DM_SPAWN_OBJECT_AFTER = "NWNX_ON_DM_SPAWN_OBJECT_AFTER";
const string NWNX_ON_DM_GIVE_ITEM_BEFORE = "NWNX_ON_DM_GIVE_ITEM_BEFORE";
const string NWNX_ON_DM_GIVE_ITEM_AFTER = "NWNX_ON_DM_GIVE_ITEM_AFTER";
const string NWNX_ON_DM_HEAL_BEFORE = "NWNX_ON_DM_HEAL_BEFORE";
const string NWNX_ON_DM_HEAL_AFTER = "NWNX_ON_DM_HEAL_AFTER";
const string NWNX_ON_DM_KILL_BEFORE = "NWNX_ON_DM_KILL_BEFORE";
const string NWNX_ON_DM_KILL_AFTER = "NWNX_ON_DM_KILL_AFTER";
const string NWNX_ON_DM_TOGGLE_INVULNERABLE_BEFORE = "NWNX_ON_DM_TOGGLE_INVULNERABLE_BEFORE";
const string NWNX_ON_DM_TOGGLE_INVULNERABLE_AFTER = "NWNX_ON_DM_TOGGLE_INVULNERABLE_AFTER";
const string NWNX_ON_DM_FORCE_REST_BEFORE = "NWNX_ON_DM_FORCE_REST_BEFORE";
const string NWNX_ON_DM_FORCE_REST_AFTER = "NWNX_ON_DM_FORCE_REST_AFTER";
const string NWNX_ON_DM_LIMBO_BEFORE = "NWNX_ON_DM_LIMBO_BEFORE";
const string NWNX_ON_DM_LIMBO_AFTER = "NWNX_ON_DM_LIMBO_AFTER";
const string NWNX_ON_DM_TOGGLE_AI_BEFORE = "NWNX_ON_DM_TOGGLE_AI_BEFORE";
const string NWNX_ON_DM_TOGGLE_AI_AFTER = "NWNX_ON_DM_TOGGLE_AI_AFTER";
const string NWNX_ON_DM_TOGGLE_IMMORTAL_BEFORE = "NWNX_ON_DM_TOGGLE_IMMORTAL_BEFORE";
const string NWNX_ON_DM_TOGGLE_IMMORTAL_AFTER = "NWNX_ON_DM_TOGGLE_IMMORTAL_AFTER";
const string NWNX_ON_DM_GOTO_BEFORE = "NWNX_ON_DM_GOTO_BEFORE";
const string NWNX_ON_DM_GOTO_AFTER = "NWNX_ON_DM_GOTO_AFTER";
const string NWNX_ON_DM_POSSESS_BEFORE = "NWNX_ON_DM_POSSESS_BEFORE";
const string NWNX_ON_DM_POSSESS_AFTER = "NWNX_ON_DM_POSSESS_AFTER";
const string NWNX_ON_DM_POSSESS_FULL_POWER_BEFORE = "NWNX_ON_DM_POSSESS_FULL_POWER_BEFORE";
const string NWNX_ON_DM_POSSESS_FULL_POWER_AFTER = "NWNX_ON_DM_POSSESS_FULL_POWER_AFTER";
const string NWNX_ON_DM_TOGGLE_LOCK_BEFORE = "NWNX_ON_DM_TOGGLE_LOCK_BEFORE";
const string NWNX_ON_DM_TOGGLE_LOCK_AFTER = "NWNX_ON_DM_TOGGLE_LOCK_AFTER";
const string NWNX_ON_DM_DISABLE_TRAP_BEFORE = "NWNX_ON_DM_DISABLE_TRAP_BEFORE";
const string NWNX_ON_DM_DISABLE_TRAP_AFTER = "NWNX_ON_DM_DISABLE_TRAP_AFTER";
const string NWNX_ON_DM_JUMP_TO_POINT_BEFORE = "NWNX_ON_DM_JUMP_TO_POINT_BEFORE";
const string NWNX_ON_DM_JUMP_TO_POINT_AFTER = "NWNX_ON_DM_JUMP_TO_POINT_AFTER";
const string NWNX_ON_DM_JUMP_TARGET_TO_POINT_BEFORE = "NWNX_ON_DM_JUMP_TARGET_TO_POINT_BEFORE";
const string NWNX_ON_DM_JUMP_TARGET_TO_POINT_AFTER = "NWNX_ON_DM_JUMP_TARGET_TO_POINT_AFTER";
const string NWNX_ON_DM_JUMP_ALL_PLAYERS_TO_POINT_BEFORE = "NWNX_ON_DM_JUMP_ALL_PLAYERS_TO_POINT_BEFORE";
const string NWNX_ON_DM_JUMP_ALL_PLAYERS_TO_POINT_AFTER = "NWNX_ON_DM_JUMP_ALL_PLAYERS_TO_POINT_AFTER";
const string NWNX_ON_DM_CHANGE_DIFFICULTY_BEFORE = "NWNX_ON_DM_CHANGE_DIFFICULTY_BEFORE";
const string NWNX_ON_DM_CHANGE_DIFFICULTY_AFTER = "NWNX_ON_DM_CHANGE_DIFFICULTY_AFTER";
const string NWNX_ON_DM_VIEW_INVENTORY_BEFORE = "NWNX_ON_DM_VIEW_INVENTORY_BEFORE";
const string NWNX_ON_DM_VIEW_INVENTORY_AFTER = "NWNX_ON_DM_VIEW_INVENTORY_AFTER";
const string NWNX_ON_DM_SPAWN_TRAP_ON_OBJECT_BEFORE = "NWNX_ON_DM_SPAWN_TRAP_ON_OBJECT_BEFORE";
const string NWNX_ON_DM_SPAWN_TRAP_ON_OBJECT_AFTER = "NWNX_ON_DM_SPAWN_TRAP_ON_OBJECT_AFTER";
const string NWNX_ON_DM_DUMP_LOCALS_BEFORE = "NWNX_ON_DM_DUMP_LOCALS_BEFORE";
const string NWNX_ON_DM_DUMP_LOCALS_AFTER = "NWNX_ON_DM_DUMP_LOCALS_AFTER";
const string NWNX_ON_DM_PLAYERDM_LOGIN_BEFORE = "NWNX_ON_DM_PLAYERDM_LOGIN_BEFORE";
const string NWNX_ON_DM_PLAYERDM_LOGIN_AFTER = "NWNX_ON_DM_PLAYERDM_LOGIN_AFTER";
const string NWNX_ON_DM_PLAYERDM_LOGOUT_BEFORE = "NWNX_ON_DM_PLAYERDM_LOGOUT_BEFORE";
const string NWNX_ON_DM_PLAYERDM_LOGOUT_AFTER = "NWNX_ON_DM_PLAYERDM_LOGOUT_AFTER";
const string NWNX_ON_DM_SET_STAT_BEFORE = "NWNX_ON_DM_SET_STAT_BEFORE";
const string NWNX_ON_DM_SET_STAT_AFTER = "NWNX_ON_DM_SET_STAT_AFTER";
const string NWNX_ON_DM_GET_VARIABLE_BEFORE = "NWNX_ON_DM_GET_VARIABLE_BEFORE";
const string NWNX_ON_DM_GET_VARIABLE_AFTER = "NWNX_ON_DM_GET_VARIABLE_AFTER";
const string NWNX_ON_DM_SET_VARIABLE_BEFORE = "NWNX_ON_DM_SET_VARIABLE_BEFORE";
const string NWNX_ON_DM_SET_VARIABLE_AFTER = "NWNX_ON_DM_SET_VARIABLE_AFTER";
const string NWNX_ON_DM_SET_FACTION_BEFORE = "NWNX_ON_DM_SET_FACTION_BEFORE";
const string NWNX_ON_DM_SET_FACTION_AFTER = "NWNX_ON_DM_SET_FACTION_AFTER";
const string NWNX_ON_DM_APPEAR_BEFORE = "NWNX_ON_DM_APPEAR_BEFORE";
const string NWNX_ON_DM_APPEAR_AFTER = "NWNX_ON_DM_APPEAR_AFTER";
const string NWNX_ON_DM_DISAPPEAR_BEFORE = "NWNX_ON_DM_DISAPPEAR_BEFORE";
const string NWNX_ON_DM_DISAPPEAR_AFTER = "NWNX_ON_DM_DISAPPEAR_AFTER";
const string NWNX_ON_DM_TAKE_ITEM_BEFORE = "NWNX_ON_DM_TAKE_ITEM_BEFORE";
const string NWNX_ON_DM_TAKE_ITEM_AFTER = "NWNX_ON_DM_TAKE_ITEM_AFTER";
const string NWNX_ON_DM_SET_TIME_BEFORE = "NWNX_ON_DM_SET_TIME_BEFORE";
const string NWNX_ON_DM_SET_TIME_AFTER = "NWNX_ON_DM_SET_TIME_AFTER";
const string NWNX_ON_DM_SET_DATE_BEFORE = "NWNX_ON_DM_SET_DATE_BEFORE";
const string NWNX_ON_DM_SET_DATE_AFTER = "NWNX_ON_DM_SET_DATE_AFTER";
const string NWNX_ON_DM_SET_FACTION_REPUTATION_BEFORE = "NWNX_ON_DM_SET_FACTION_REPUTATION_BEFORE";
const string NWNX_ON_DM_SET_FACTION_REPUTATION_AFTER = "NWNX_ON_DM_SET_FACTION_REPUTATION_AFTER";
const string NWNX_ON_DM_GET_FACTION_REPUTATION_BEFORE = "NWNX_ON_DM_GET_FACTION_REPUTATION_BEFORE";
const string NWNX_ON_DM_GET_FACTION_REPUTATION_AFTER = "NWNX_ON_DM_GET_FACTION_REPUTATION_AFTER";
const string NWNX_ON_CLIENT_DISCONNECT_BEFORE = "NWNX_ON_CLIENT_DISCONNECT_BEFORE";
const string NWNX_ON_CLIENT_DISCONNECT_AFTER = "NWNX_ON_CLIENT_DISCONNECT_AFTER";
const string NWNX_ON_CLIENT_CONNECT_BEFORE = "NWNX_ON_CLIENT_CONNECT_BEFORE";
const string NWNX_ON_CLIENT_CONNECT_AFTER = "NWNX_ON_CLIENT_CONNECT_AFTER";
const string NWNX_ON_COMBAT_ENTER_BEFORE = "NWNX_ON_COMBAT_ENTER_BEFORE";
const string NWNX_ON_COMBAT_ENTER_AFTER = "NWNX_ON_COMBAT_ENTER_AFTER";
const string NWNX_ON_COMBAT_EXIT_BEFORE = "NWNX_ON_COMBAT_EXIT_BEFORE";
const string NWNX_ON_COMBAT_EXIT_AFTER = "NWNX_ON_COMBAT_EXIT_AFTER";
const string NWNX_ON_START_COMBAT_ROUND_BEFORE = "NWNX_ON_START_COMBAT_ROUND_BEFORE";
const string NWNX_ON_START_COMBAT_ROUND_AFTER = "NWNX_ON_START_COMBAT_ROUND_AFTER";
const string NWNX_ON_DISARM_BEFORE = "NWNX_ON_DISARM_BEFORE";
const string NWNX_ON_DISARM_AFTER = "NWNX_ON_DISARM_AFTER";
const string NWNX_ON_CAST_SPELL_BEFORE = "NWNX_ON_CAST_SPELL_BEFORE";
const string NWNX_ON_CAST_SPELL_AFTER = "NWNX_ON_CAST_SPELL_AFTER";
const string NWNX_ON_SET_MEMORIZED_SPELL_SLOT_BEFORE = "NWNX_SET_MEMORIZED_SPELL_SLOT_BEFORE";
const string NWNX_ON_SET_MEMORIZED_SPELL_SLOT_AFTER = "NWNX_SET_MEMORIZED_SPELL_SLOT_AFTER";
const string NWNX_ON_CLEAR_MEMORIZED_SPELL_SLOT_BEFORE = "NWNX_CLEAR_MEMORIZED_SPELL_SLOT_BEFORE";
const string NWNX_ON_CLEAR_MEMORIZED_SPELL_SLOT_AFTER = "NWNX_CLEAR_MEMORIZED_SPELL_SLOT_AFTER";
const string NWNX_ON_SPELL_INTERRUPTED_BEFORE = "NWNX_ON_SPELL_INTERRUPTED_BEFORE";
const string NWNX_ON_SPELL_INTERRUPTED_AFTER = "NWNX_ON_SPELL_INTERRUPTED_AFTER";
const string NWNX_ON_SPELL_FAILED_BEFORE = "NWNX_ON_SPELL_FAILED_BEFORE";
const string NWNX_ON_SPELL_FAILED_AFTER = "NWNX_ON_SPELL_FAILED_AFTER";
const string NWNX_ON_HEALER_KIT_BEFORE = "NWNX_ON_HEALER_KIT_BEFORE";
const string NWNX_ON_HEALER_KIT_AFTER = "NWNX_ON_HEALER_KIT_AFTER";
const string NWNX_ON_HEAL_BEFORE = "NWNX_ON_HEAL_BEFORE";
const string NWNX_ON_HEAL_AFTER = "NWNX_ON_HEAL_AFTER";
const string NWNX_ON_PARTY_LEAVE_BEFORE = "NWNX_ON_PARTY_LEAVE_BEFORE";
const string NWNX_ON_PARTY_LEAVE_AFTER = "NWNX_ON_PARTY_LEAVE_AFTER";
const string NWNX_ON_PARTY_KICK_BEFORE = "NWNX_ON_PARTY_KICK_BEFORE";
const string NWNX_ON_PARTY_KICK_AFTER = "NWNX_ON_PARTY_KICK_AFTER";
const string NWNX_ON_PARTY_TRANSFER_LEADERSHIP_BEFORE = "NWNX_ON_PARTY_TRANSFER_LEADERSHIP_BEFORE";
const string NWNX_ON_PARTY_TRANSFER_LEADERSHIP_AFTER = "NWNX_ON_PARTY_TRANSFER_LEADERSHIP_AFTER";
const string NWNX_ON_PARTY_INVITE_BEFORE = "NWNX_ON_PARTY_INVITE_BEFORE";
const string NWNX_ON_PARTY_INVITE_AFTER = "NWNX_ON_PARTY_INVITE_AFTER";
const string NWNX_ON_PARTY_IGNORE_INVITATION_BEFORE = "NWNX_ON_PARTY_IGNORE_INVITATION_BEFORE";
const string NWNX_ON_PARTY_IGNORE_INVITATION_AFTER = "NWNX_ON_PARTY_IGNORE_INVITATION_AFTER";
const string NWNX_ON_PARTY_ACCEPT_INVITATION_BEFORE = "NWNX_ON_PARTY_ACCEPT_INVITATION_BEFORE";
const string NWNX_ON_PARTY_ACCEPT_INVITATION_AFTER = "NWNX_ON_PARTY_ACCEPT_INVITATION_AFTER";
const string NWNX_ON_PARTY_REJECT_INVITATION_BEFORE = "NWNX_ON_PARTY_REJECT_INVITATION_BEFORE";
const string NWNX_ON_PARTY_REJECT_INVITATION_AFTER = "NWNX_ON_PARTY_REJECT_INVITATION_AFTER";
const string NWNX_ON_PARTY_KICK_HENCHMAN_BEFORE = "NWNX_ON_PARTY_KICK_HENCHMAN_BEFORE";
const string NWNX_ON_PARTY_KICK_HENCHMAN_AFTER = "NWNX_ON_PARTY_KICK_HENCHMAN_AFTER";
const string NWNX_ON_COMBAT_MODE_ON = "NWNX_ON_COMBAT_MODE_ON";
const string NWNX_ON_COMBAT_MODE_OFF = "NWNX_ON_COMBAT_MODE_OFF";
const string NWNX_ON_USE_SKILL_BEFORE = "NWNX_ON_USE_SKILL_BEFORE";
const string NWNX_ON_USE_SKILL_AFTER = "NWNX_ON_USE_SKILL_AFTER";
const string NWNX_ON_MAP_PIN_ADD_PIN_BEFORE = "NWNX_ON_MAP_PIN_ADD_PIN_BEFORE";
const string NWNX_ON_MAP_PIN_ADD_PIN_AFTER = "NWNX_ON_MAP_PIN_ADD_PIN_AFTER";
const string NWNX_ON_MAP_PIN_CHANGE_PIN_BEFORE = "NWNX_ON_MAP_PIN_CHANGE_PIN_BEFORE";
const string NWNX_ON_MAP_PIN_CHANGE_PIN_AFTER = "NWNX_ON_MAP_PIN_CHANGE_PIN_AFTER";
const string NWNX_ON_MAP_PIN_DESTROY_PIN_BEFORE = "NWNX_ON_MAP_PIN_DESTROY_PIN_BEFORE";
const string NWNX_ON_MAP_PIN_DESTROY_PIN_AFTER = "NWNX_ON_MAP_PIN_DESTROY_PIN_AFTER";
const string NWNX_ON_DO_LISTEN_DETECTION_BEFORE = "NWNX_ON_DO_LISTEN_DETECTION_BEFORE";
const string NWNX_ON_DO_LISTEN_DETECTION_AFTER = "NWNX_ON_DO_LISTEN_DETECTION_AFTER";
const string NWNX_ON_DO_SPOT_DETECTION_BEFORE = "NWNX_ON_DO_SPOT_DETECTION_BEFORE";
const string NWNX_ON_DO_SPOT_DETECTION_AFTER = "NWNX_ON_DO_SPOT_DETECTION_AFTER";
const string NWNX_ON_POLYMORPH_BEFORE = "NWNX_ON_POLYMORPH_BEFORE";
const string NWNX_ON_POLYMORPH_AFTER = "NWNX_ON_POLYMORPH_AFTER";
const string NWNX_ON_UNPOLYMORPH_BEFORE = "NWNX_ON_UNPOLYMORPH_BEFORE";
const string NWNX_ON_UNPOLYMORPH_AFTER = "NWNX_ON_UNPOLYMORPH_AFTER";
const string NWNX_ON_EFFECT_APPLIED_BEFORE = "NWNX_ON_EFFECT_APPLIED_BEFORE";
const string NWNX_ON_EFFECT_APPLIED_AFTER = "NWNX_ON_EFFECT_APPLIED_AFTER";
const string NWNX_ON_EFFECT_REMOVED_BEFORE = "NWNX_ON_EFFECT_REMOVED_BEFORE";
const string NWNX_ON_EFFECT_REMOVED_AFTER = "NWNX_ON_EFFECT_REMOVED_AFTER";
const string NWNX_ON_QUICKCHAT_BEFORE = "NWNX_ON_QUICKCHAT_BEFORE";
const string NWNX_ON_QUICKCHAT_AFTER = "NWNX_ON_QUICKCHAT_AFTER";
const string NWNX_ON_INVENTORY_OPEN_BEFORE = "NWNX_ON_INVENTORY_OPEN_BEFORE";
const string NWNX_ON_INVENTORY_OPEN_AFTER = "NWNX_ON_INVENTORY_OPEN_AFTER";
const string NWNX_ON_INVENTORY_SELECT_PANEL_BEFORE = "NWNX_ON_INVENTORY_SELECT_PANEL_BEFORE";
const string NWNX_ON_INVENTORY_SELECT_PANEL_AFTER = "NWNX_ON_INVENTORY_SELECT_PANEL_AFTER";
const string NWNX_ON_BARTER_START_BEFORE = "NWNX_ON_BARTER_START_BEFORE";
const string NWNX_ON_BARTER_START_AFTER = "NWNX_ON_BARTER_START_AFTER";
const string NWNX_ON_BARTER_END_BEFORE = "NWNX_ON_BARTER_END_BEFORE";
const string NWNX_ON_BARTER_END_AFTER = "NWNX_ON_BARTER_END_AFTER";
const string NWNX_ON_BARTER_ADD_ITEM_BEFORE = "NWNX_ON_BARTER_ADD_ITEM_BEFORE";
const string NWNX_ON_BARTER_ADD_ITEM_AFTER = "NWNX_ON_BARTER_ADD_ITEM_AFTER";
const string NWNX_ON_TRAP_DISARM_BEFORE = "NWNX_ON_TRAP_DISARM_BEFORE";
const string NWNX_ON_TRAP_DISARM_AFTER = "NWNX_ON_TRAP_DISARM_AFTER";
const string NWNX_ON_TRAP_ENTER_BEFORE = "NWNX_ON_TRAP_ENTER_BEFORE";
const string NWNX_ON_TRAP_ENTER_AFTER = "NWNX_ON_TRAP_ENTER_AFTER";
const string NWNX_ON_TRAP_EXAMINE_BEFORE = "NWNX_ON_TRAP_EXAMINE_BEFORE";
const string NWNX_ON_TRAP_EXAMINE_AFTER = "NWNX_ON_TRAP_EXAMINE_AFTER";
const string NWNX_ON_TRAP_FLAG_BEFORE = "NWNX_ON_TRAP_FLAG_BEFORE";
const string NWNX_ON_TRAP_FLAG_AFTER = "NWNX_ON_TRAP_FLAG_AFTER";
const string NWNX_ON_TRAP_RECOVER_BEFORE = "NWNX_ON_TRAP_RECOVER_BEFORE";
const string NWNX_ON_TRAP_RECOVER_AFTER = "NWNX_ON_TRAP_RECOVER_AFTER";
const string NWNX_ON_TRAP_SET_BEFORE = "NWNX_ON_TRAP_SET_BEFORE";
const string NWNX_ON_TRAP_SET_AFTER = "NWNX_ON_TRAP_SET_AFTER";
const string NWNX_ON_TIMING_BAR_START_BEFORE = "NWNX_ON_TIMING_BAR_START_BEFORE";
const string NWNX_ON_TIMING_BAR_START_AFTER = "NWNX_ON_TIMING_BAR_START_AFTER";
const string NWNX_ON_TIMING_BAR_STOP_BEFORE = "NWNX_ON_TIMING_BAR_STOP_BEFORE";
const string NWNX_ON_TIMING_BAR_STOP_AFTER = "NWNX_ON_TIMING_BAR_STOP_AFTER";
const string NWNX_ON_TIMING_BAR_CANCEL_BEFORE = "NWNX_ON_TIMING_BAR_CANCEL_BEFORE";
const string NWNX_ON_TIMING_BAR_CANCEL_AFTER = "NWNX_ON_TIMING_BAR_CANCEL_AFTER";
const string NWNX_ON_WEBHOOK_SUCCESS = "NWNX_ON_WEBHOOK_SUCCESS";
const string NWNX_ON_WEBHOOK_FAILURE = "NWNX_ON_WEBHOOK_FAILURE";
const string NWNX_ON_CHECK_STICKY_PLAYER_NAME_RESERVED_BEFORE = "NWNX_ON_CHECK_STICKY_PLAYER_NAME_RESERVED_BEFORE";
const string NWNX_ON_CHECK_STICKY_PLAYER_NAME_RESERVED_AFTER = "NWNX_ON_CHECK_STICKY_PLAYER_NAME_RESERVED_AFTER";
const string NWNX_ON_SERVER_CHARACTER_SAVE_BEFORE = "NWNX_ON_SERVER_CHARACTER_SAVE_BEFORE";
const string NWNX_ON_SERVER_CHARACTER_SAVE_AFTER = "NWNX_ON_SERVER_CHARACTER_SAVE_AFTER";
const string NWNX_ON_CLIENT_EXPORT_CHARACTER_BEFORE = "NWNX_ON_CLIENT_EXPORT_CHARACTER_BEFORE";
const string NWNX_ON_CLIENT_EXPORT_CHARACTER_AFTER = "NWNX_ON_CLIENT_EXPORT_CHARACTER_AFTER";
const string NWNX_ON_LEVEL_UP_BEFORE = "NWNX_ON_LEVEL_UP_BEFORE";
const string NWNX_ON_LEVEL_UP_AFTER = "NWNX_ON_LEVEL_UP_AFTER";
const string NWNX_ON_LEVEL_UP_AUTOMATIC_BEFORE = "NWNX_ON_LEVEL_UP_AUTOMATIC_BEFORE";
const string NWNX_ON_LEVEL_UP_AUTOMATIC_AFTER = "NWNX_ON_LEVEL_UP_AUTOMATIC_AFTER";
const string NWNX_ON_LEVEL_DOWN_BEFORE = "NWNX_ON_LEVEL_DOWN_BEFORE";
const string NWNX_ON_LEVEL_DOWN_AFTER = "NWNX_ON_LEVEL_DOWN_AFTER";
const string NWNX_ON_INVENTORY_ADD_ITEM_BEFORE = "NWNX_ON_INVENTORY_ADD_ITEM_BEFORE";
const string NWNX_ON_INVENTORY_ADD_ITEM_AFTER = "NWNX_ON_INVENTORY_ADD_ITEM_AFTER";
const string NWNX_ON_INVENTORY_REMOVE_ITEM_BEFORE = "NWNX_ON_INVENTORY_REMOVE_ITEM_BEFORE";
const string NWNX_ON_INVENTORY_REMOVE_ITEM_AFTER = "NWNX_ON_INVENTORY_REMOVE_ITEM_AFTER";
const string NWNX_ON_INVENTORY_ADD_GOLD_BEFORE = "NWNX_ON_INVENTORY_ADD_GOLD_BEFORE";
const string NWNX_ON_INVENTORY_ADD_GOLD_AFTER = "NWNX_ON_INVENTORY_ADD_GOLD_AFTER";
const string NWNX_ON_INVENTORY_REMOVE_GOLD_BEFORE = "NWNX_ON_INVENTORY_REMOVE_GOLD_BEFORE";
const string NWNX_ON_INVENTORY_REMOVE_GOLD_AFTER = "NWNX_ON_INVENTORY_REMOVE_GOLD_AFTER";
const string NWNX_ON_PVP_ATTITUDE_CHANGE_BEFORE = "NWNX_ON_PVP_ATTITUDE_CHANGE_BEFORE";
const string NWNX_ON_PVP_ATTITUDE_CHANGE_AFTER = "NWNX_ON_PVP_ATTITUDE_CHANGE_AFTER";
const string NWNX_ON_INPUT_WALK_TO_WAYPOINT_BEFORE = "NWNX_ON_INPUT_WALK_TO_WAYPOINT_BEFORE";
const string NWNX_ON_INPUT_WALK_TO_WAYPOINT_AFTER = "NWNX_ON_INPUT_WALK_TO_WAYPOINT_AFTER";
const string NWNX_ON_MATERIALCHANGE_BEFORE = "NWNX_ON_MATERIALCHANGE_BEFORE";
const string NWNX_ON_MATERIALCHANGE_AFTER = "NWNX_ON_MATERIALCHANGE_AFTER";
const string NWNX_ON_INPUT_ATTACK_OBJECT_BEFORE = "NWNX_ON_INPUT_ATTACK_OBJECT_BEFORE";
const string NWNX_ON_INPUT_ATTACK_OBJECT_AFTER = "NWNX_ON_INPUT_ATTACK_OBJECT_AFTER";
const string NWNX_ON_INPUT_FORCE_MOVE_TO_OBJECT_BEFORE = "NWNX_ON_INPUT_FORCE_MOVE_TO_OBJECT_BEFORE";
const string NWNX_ON_INPUT_FORCE_MOVE_TO_OBJECT_AFTER = "NWNX_ON_INPUT_FORCE_MOVE_TO_OBJECT_AFTER";
const string NWNX_ON_INPUT_CAST_SPELL_BEFORE = "NWNX_ON_INPUT_CAST_SPELL_BEFORE";
const string NWNX_ON_INPUT_CAST_SPELL_AFTER = "NWNX_ON_INPUT_CAST_SPELL_AFTER";
const string NWNX_ON_INPUT_KEYBOARD_BEFORE = "NWNX_ON_INPUT_KEYBOARD_BEFORE";
const string NWNX_ON_INPUT_KEYBOARD_AFTER = "NWNX_ON_INPUT_KEYBOARD_AFTER";
const string NWNX_ON_INPUT_TOGGLE_PAUSE_BEFORE = "NWNX_ON_INPUT_TOGGLE_PAUSE_BEFORE";
const string NWNX_ON_INPUT_TOGGLE_PAUSE_AFTER = "NWNX_ON_INPUT_TOGGLE_PAUSE_AFTER";
const string NWNX_ON_OBJECT_LOCK_BEFORE = "NWNX_ON_OBJECT_LOCK_BEFORE";
const string NWNX_ON_OBJECT_LOCK_AFTER = "NWNX_ON_OBJECT_LOCK_AFTER";
const string NWNX_ON_OBJECT_UNLOCK_BEFORE = "NWNX_ON_OBJECT_UNLOCK_BEFORE";
const string NWNX_ON_OBJECT_UNLOCK_AFTER = "NWNX_ON_OBJECT_UNLOCK_AFTER";
const string NWNX_ON_UUID_COLLISION_BEFORE = "NWNX_ON_UUID_COLLISION_BEFORE";
const string NWNX_ON_UUID_COLLISION_AFTER = "NWNX_ON_UUID_COLLISION_AFTER";
const string NWNX_ON_RESOURCE_ADDED = "NWNX_ON_RESOURCE_ADDED";
const string NWNX_ON_RESOURCE_REMOVED = "NWNX_ON_RESOURCE_REMOVED";
const string NWNX_ON_RESOURCE_MODIFIED = "NWNX_ON_RESOURCE_MODIFIED";
const string NWNX_ON_ELC_VALIDATE_CHARACTER_BEFORE = "NWNX_ON_ELC_VALIDATE_CHARACTER_BEFORE";
const string NWNX_ON_ELC_VALIDATE_CHARACTER_AFTER = "NWNX_ON_ELC_VALIDATE_CHARACTER_AFTER";
const string NWNX_ON_QUICKBAR_SET_BUTTON_BEFORE = "NWNX_ON_QUICKBAR_SET_BUTTON_BEFORE";
const string NWNX_ON_QUICKBAR_SET_BUTTON_AFTER = "NWNX_ON_QUICKBAR_SET_BUTTON_AFTER";
const string NWNX_ON_CALENDAR_HOUR = "NWNX_ON_CALENDAR_HOUR";
const string NWNX_ON_CALENDAR_DAY = "NWNX_ON_CALENDAR_DAY";
const string NWNX_ON_CALENDAR_MONTH = "NWNX_ON_CALENDAR_MONTH";
const string NWNX_ON_CALENDAR_YEAR = "NWNX_ON_CALENDAR_YEAR";
const string NWNX_ON_CALENDAR_DAWN = "NWNX_ON_CALENDAR_DAWN";
const string NWNX_ON_CALENDAR_DUSK = "NWNX_ON_CALENDAR_DUSK";
const string NWNX_ON_BROADCAST_CAST_SPELL_BEFORE = "NWNX_ON_BROADCAST_CAST_SPELL_BEFORE";
const string NWNX_ON_BROADCAST_CAST_SPELL_AFTER = "NWNX_ON_BROADCAST_CAST_SPELL_AFTER";
const string NWNX_ON_DEBUG_RUN_SCRIPT_BEFORE = "NWNX_ON_DEBUG_RUN_SCRIPT_BEFORE";
const string NWNX_ON_DEBUG_RUN_SCRIPT_AFTER = "NWNX_ON_DEBUG_RUN_SCRIPT_AFTER";
const string NWNX_ON_DEBUG_RUN_SCRIPT_CHUNK_BEFORE = "NWNX_ON_DEBUG_RUN_SCRIPT_CHUNK_BEFORE";
const string NWNX_ON_DEBUG_RUN_SCRIPT_CHUNK_AFTER = "NWNX_ON_DEBUG_RUN_SCRIPT_CHUNK_AFTER";
const string NWNX_ON_DEBUG_PLAY_VISUAL_EFFECT_BEFORE = "NWNX_ON_DEBUG_PLAY_VISUAL_EFFECT_BEFORE";
const string NWNX_ON_DEBUG_PLAY_VISUAL_EFFECT_AFTER = "NWNX_ON_DEBUG_PLAY_VISUAL_EFFECT_AFTER";
const string NWNX_ON_STORE_REQUEST_BUY_BEFORE = "NWNX_ON_STORE_REQUEST_BUY_BEFORE";
const string NWNX_ON_STORE_REQUEST_BUY_AFTER = "NWNX_ON_STORE_REQUEST_BUY_AFTER";
const string NWNX_ON_STORE_REQUEST_SELL_BEFORE = "NWNX_ON_STORE_REQUEST_SELL_BEFORE";
const string NWNX_ON_STORE_REQUEST_SELL_AFTER = "NWNX_ON_STORE_REQUEST_SELL_AFTER";
const string NWNX_ON_SERVER_SEND_AREA_BEFORE = "NWNX_ON_SERVER_SEND_AREA_BEFORE";
const string NWNX_ON_SERVER_SEND_AREA_AFTER = "NWNX_ON_SERVER_SEND_AREA_AFTER";
const string NWNX_ON_JOURNAL_OPEN_BEFORE = "NWNX_ON_JOURNAL_OPEN_BEFORE";
const string NWNX_ON_JOURNAL_OPEN_AFTER = "NWNX_ON_JOURNAL_OPEN_AFTER";
const string NWNX_ON_JOURNAL_CLOSE_BEFORE = "NWNX_ON_JOURNAL_CLOSE_BEFORE";
const string NWNX_ON_JOURNAL_CLOSE_AFTER = "NWNX_ON_JOURNAL_CLOSE_AFTER";
const string NWNX_ON_INPUT_EMOTE_BEFORE = "NWNX_ON_INPUT_EMOTE_BEFORE";
const string NWNX_ON_INPUT_EMOTE_AFTER = "NWNX_ON_INPUT_EMOTE_AFTER";
const string NWNX_ON_COMBAT_DR_BROKEN_BEFORE = "NWNX_ON_COMBAT_DR_BROKEN_BEFORE";
const string NWNX_ON_COMBAT_DR_BROKEN_AFTER = "NWNX_ON_COMBAT_DR_BROKEN_AFTER";
const string NWNX_ON_UNPOSSESS_FAMILIAR_BEFORE = "NWNX_ON_UNPOSSESS_FAMILIAR_BEFORE";
const string NWNX_ON_UNPOSSESS_FAMILIAR_AFTER = "NWNX_ON_UNPOSSESS_FAMILIAR_AFTER";
const string NWNX_ON_CLIENT_LEVEL_UP_BEGIN_BEFORE = "NWNX_ON_CLIENT_LEVEL_UP_BEGIN_BEFORE";
const string NWNX_ON_CLIENT_LEVEL_UP_BEGIN_AFTER = "NWNX_ON_CLIENT_LEVEL_UP_BEGIN_AFTER";
const string NWNX_ON_POSSESS_FAMILIAR_BEFORE = "NWNX_ON_POSSESS_FAMILIAR_BEFORE";
const string NWNX_ON_POSSESS_FAMILIAR_AFTER = "NWNX_ON_POSSESS_FAMILIAR_AFTER";
const string NWNX_ON_CHARACTER_SHEET_PERMITTED_BEFORE = "NWNX_ON_CHARACTER_SHEET_PERMITTED_BEFORE";
const string NWNX_ON_CHARACTER_SHEET_PERMITTED_AFTER = "NWNX_ON_CHARACTER_SHEET_PERMITTED_AFTER";
const string NWNX_ON_CHARACTER_SHEET_OPEN_BEFORE = "NWNX_ON_CHARACTER_SHEET_OPEN_BEFORE";
const string NWNX_ON_CHARACTER_SHEET_OPEN_AFTER = "NWNX_ON_CHARACTER_SHEET_OPEN_AFTER";
const string NWNX_ON_CHARACTER_SHEET_CLOSE_BEFORE = "NWNX_ON_CHARACTER_SHEET_CLOSE_BEFORE";
const string NWNX_ON_CHARACTER_SHEET_CLOSE_AFTER = "NWNX_ON_CHARACTER_SHEET_CLOSE_AFTER";
const string NWNX_ON_CLIENT_SET_DEVICE_PROPERTY_BEFORE = "NWNX_ON_CLIENT_SET_DEVICE_PROPERTY_BEFORE";
const string NWNX_ON_CLIENT_SET_DEVICE_PROPERTY_AFTER = "NWNX_ON_CLIENT_SET_DEVICE_PROPERTY_AFTER";
const string NWNX_ON_INPUT_DROP_ITEM_BEFORE = "NWNX_ON_INPUT_DROP_ITEM_BEFORE";
const string NWNX_ON_INPUT_DROP_ITEM_AFTER = "NWNX_ON_INPUT_DROP_ITEM_AFTER";
const string NWNX_ON_DECREMENT_SPELL_COUNT_BEFORE = "NWNX_ON_DECREMENT_SPELL_COUNT_BEFORE";
const string NWNX_ON_DECREMENT_SPELL_COUNT_AFTER = "NWNX_ON_DECREMENT_SPELL_COUNT_AFTER";
const string NWNX_ON_RUN_EVENT_SCRIPT_BEFORE = "NWNX_ON_RUN_EVENT_SCRIPT_BEFORE";
const string NWNX_ON_RUN_EVENT_SCRIPT_AFTER = "NWNX_ON_RUN_EVENT_SCRIPT_AFTER";
const string NWNX_ON_OBJECT_USE_BEFORE = "NWNX_ON_OBJECT_USE_BEFORE";
const string NWNX_ON_OBJECT_USE_AFTER = "NWNX_ON_OBJECT_USE_AFTER";
const string NWNX_ON_PLACEABLE_OPEN_BEFORE = "NWNX_ON_PLACEABLE_OPEN_BEFORE";
const string NWNX_ON_PLACEABLE_OPEN_AFTER = "NWNX_ON_PLACEABLE_OPEN_AFTER";
const string NWNX_ON_PLACEABLE_CLOSE_BEFORE = "NWNX_ON_PLACEABLE_CLOSE_BEFORE";
const string NWNX_ON_PLACEABLE_CLOSE_AFTER = "NWNX_ON_PLACEABLE_CLOSE_AFTER";
const string NWNX_ON_BROADCAST_SAFE_PROJECTILE_BEFORE = "NWNX_ON_BROADCAST_SAFE_PROJECTILE_BEFORE";
const string NWNX_ON_BROADCAST_SAFE_PROJECTILE_AFTER = "NWNX_ON_BROADCAST_SAFE_PROJECTILE_AFTER";
const string NWNX_ON_BROADCAST_ATTACK_OF_OPPORTUNITY_BEFORE = "NWNX_ON_BROADCAST_ATTACK_OF_OPPORTUNITY_BEFORE";
const string NWNX_ON_BROADCAST_ATTACK_OF_OPPORTUNITY_AFTER = "NWNX_ON_BROADCAST_ATTACK_OF_OPPORTUNITY_AFTER";
const string NWNX_ON_COMBAT_ATTACK_OF_OPPORTUNITY_BEFORE = "NWNX_ON_COMBAT_ATTACK_OF_OPPORTUNITY_BEFORE";
const string NWNX_ON_COMBAT_ATTACK_OF_OPPORTUNITY_AFTER = "NWNX_ON_COMBAT_ATTACK_OF_OPPORTUNITY_AFTER";
const string NWNX_ON_AREA_PLAY_BATTLE_MUSIC_BEFORE = "NWNX_ON_AREA_PLAY_BATTLE_MUSIC_BEFORE";
const string NWNX_ON_AREA_PLAY_BATTLE_MUSIC_AFTER = "NWNX_ON_AREA_PLAY_BATTLE_MUSIC_AFTER";
const string NWNX_ON_ATTACK_TARGET_CHANGE_BEFORE = "NWNX_ON_ATTACK_TARGET_CHANGE_BEFORE";
const string NWNX_ON_ATTACK_TARGET_CHANGE_AFTER = "NWNX_ON_ATTACK_TARGET_CHANGE_AFTER";
const string NWNX_ON_CREATURE_TILE_CHANGE_BEFORE = "NWNX_ON_CREATURE_TILE_CHANGE_BEFORE";
const string NWNX_ON_CREATURE_TILE_CHANGE_AFTER = "NWNX_ON_CREATURE_TILE_CHANGE_AFTER";
const string NWNX_ON_CREATURE_JUMP_TO_POINT_BEFORE = "NWNX_ON_CREATURE_JUMP_TO_POINT_BEFORE";
const string NWNX_ON_CREATURE_JUMP_TO_POINT_AFTER = "NWNX_ON_CREATURE_JUMP_TO_POINT_AFTER";
const string NWNX_ON_CREATURE_JUMP_TO_OBJECT_BEFORE = "NWNX_ON_CREATURE_JUMP_TO_OBJECT_BEFORE";
const string NWNX_ON_CREATURE_JUMP_TO_OBJECT_AFTER = "NWNX_ON_CREATURE_JUMP_TO_OBJECT_AFTER";
const string NWNX_ON_ITEMPROPERTY_EFFECT_APPLIED_BEFORE = "NWNX_ON_ITEMPROPERTY_EFFECT_APPLIED_BEFORE";
const string NWNX_ON_ITEMPROPERTY_EFFECT_APPLIED_AFTER = "NWNX_ON_ITEMPROPERTY_EFFECT_APPLIED_AFTER";
const string NWNX_ON_ITEMPROPERTY_EFFECT_REMOVED_BEFORE = "NWNX_ON_ITEMPROPERTY_EFFECT_REMOVED_BEFORE";
const string NWNX_ON_ITEMPROPERTY_EFFECT_REMOVED_AFTER = "NWNX_ON_ITEMPROPERTY_EFFECT_REMOVED_AFTER";
/// @}

/// @name Events ObjectType Constants
/// @anchor events_objtype
/// @{
const int NWNX_EVENTS_OBJECT_TYPE_CREATURE          = 5;
const int NWNX_EVENTS_OBJECT_TYPE_ITEM              = 6;
const int NWNX_EVENTS_OBJECT_TYPE_TRIGGER           = 7;
const int NWNX_EVENTS_OBJECT_TYPE_PLACEABLE         = 9;
const int NWNX_EVENTS_OBJECT_TYPE_WAYPOINT          = 12;
const int NWNX_EVENTS_OBJECT_TYPE_ENCOUNTER         = 13;
const int NWNX_EVENTS_OBJECT_TYPE_PORTAL            = 15;
/// @}

/// @name Events TimingBar Constants
/// @anchor events_timingbar
/// @{
const int NWNX_EVENTS_TIMING_BAR_TRAP_FLAG     = 1;
const int NWNX_EVENTS_TIMING_BAR_TRAP_RECOVER  = 2;
const int NWNX_EVENTS_TIMING_BAR_TRAP_DISARM   = 3;
const int NWNX_EVENTS_TIMING_BAR_TRAP_EXAMINE  = 4;
const int NWNX_EVENTS_TIMING_BAR_TRAP_SET      = 5;
const int NWNX_EVENTS_TIMING_BAR_REST          = 6;
const int NWNX_EVENTS_TIMING_BAR_UNLOCK        = 7;
const int NWNX_EVENTS_TIMING_BAR_LOCK          = 8;
const int NWNX_EVENTS_TIMING_BAR_CUSTOM        = 10;
/// @}

/// @name Events SetVariable Constants
/// @anchor events_setvariable
/// @{
const int NWNX_EVENTS_DM_SET_VARIABLE_TYPE_INT          = 0;
const int NWNX_EVENTS_DM_SET_VARIABLE_TYPE_FLOAT        = 1;
const int NWNX_EVENTS_DM_SET_VARIABLE_TYPE_STRING       = 2;
const int NWNX_EVENTS_DM_SET_VARIABLE_TYPE_OBJECT       = 3;
/// @}

/// @name Events BroadcastSafeProjectile Constants
/// @anchor events_projtype
/// @{
const int NWNX_EVENTS_BROADCAST_SAFE_PROJECTILE_TYPE_WEAPON_VFX_NONE = 0;
const int NWNX_EVENTS_BROADCAST_SAFE_PROJECTILE_TYPE_WEAPON_VFX_ACID = 1;
const int NWNX_EVENTS_BROADCAST_SAFE_PROJECTILE_TYPE_WEAPON_VFX_COLD = 2;
const int NWNX_EVENTS_BROADCAST_SAFE_PROJECTILE_TYPE_WEAPON_VFX_ELECTRICAL = 3;
const int NWNX_EVENTS_BROADCAST_SAFE_PROJECTILE_TYPE_WEAPON_VFX_FIRE = 4;
const int NWNX_EVENTS_BROADCAST_SAFE_PROJECTILE_TYPE_WEAPON_VFX_SONIC = 5;
const int NWNX_EVENTS_BROADCAST_SAFE_PROJECTILE_TYPE_SPELL_DEFAULT = 6;
const int NWNX_EVENTS_BROADCAST_SAFE_PROJECTILE_TYPE_SPELL_USE_PATH = 7;
/// @}

/// @name Spell failed event reasons
/// @anchor events_spellfailreason
/// @{
const int NWNX_EVENTS_SPELLFAIL_REASON_CANCELED               = 0;
const int NWNX_EVENTS_SPELLFAIL_REASON_COUNTERSPELL           = 1;
const int NWNX_EVENTS_SPELLFAIL_REASON_ASF                    = 2;
const int NWNX_EVENTS_SPELLFAIL_REASON_SPELLFAILURE           = 3;
const int NWNX_EVENTS_SPELLFAIL_REASON_LOST_TARGET            = 4;
const int NWNX_EVENTS_SPELLFAIL_REASON_SILENCED               = 5;
const int NWNX_EVENTS_SPELLFAIL_REASON_DEFCAST_CONCENTRATION  = 6;
const int NWNX_EVENTS_SPELLFAIL_REASON_ENTANGLE_CONCENTRATION = 7;
const int NWNX_EVENTS_SPELLFAIL_REASON_POLYMORPHED            = 8;
const int NWNX_EVENTS_SPELLFAIL_REASON_CANT_CAST              = 9;
const int NWNX_EVENTS_SPELLFAIL_REASON_CANT_USE_HANDS         = 10;
/// @}

/// @brief Scripts can subscribe to events.
///
/// Some events are dispatched via the NWNX plugin (see NWNX_EVENTS_EVENT_* constants).
/// Others can be signalled via script code via NWNX_Events_SignalEvent().
/// @param evt The event name.
/// @param script The script to call when the event fires.
void NWNX_Events_SubscribeEvent(string evt, string script);

/// @brief Unsubscribe a script from an event
/// @param evt The event name.
/// @param script The script.
void NWNX_Events_UnsubscribeEvent(string evt, string script);

/// @brief Unsubscribe all scripts from all events starting with prefix.
/// @param prefix the prefix to match against. Can be empty.
void NWNX_Events_UnsubscribeAllStartingWith(string prefix);

/// @brief Script chunks can subscribe to events.
///
/// Some events are dispatched via the NWNX plugin (see NWNX_EVENTS_EVENT_* constants).
/// Others can be signalled via script code via NWNX_Events_SignalEvent().
/// @param sEvent The event name.
/// @param sScriptChunk The script chunk to execute when the event fires.
/// @param bWrapIntoMain TRUE if the script chunk needs to be wrapped into a void main(){}.
void NWNX_Events_SubscribeEventScriptChunk(string sEvent, string sScriptChunk, int bWrapIntoMain = TRUE);

/// @brief Unsubscribe a script chunk from an event
/// @param sEvent The event name.
/// @param sScriptChunk The script chunk.
/// @param bWrapIntoMain TRUE if the script chunk needs to be wrapped into a void main(){}. Must match the value used when subscribing.
void NWNX_Events_UnsubscribeEventScriptChunk(string sEvent, string sScriptChunk, int bWrapIntoMain = TRUE);

/// Pushes event data at the provided tag, which subscribers can access with GetEventData.
/// This should be called BEFORE SignalEvent.
void NWNX_Events_PushEventData(string tag, string data);

/// Signals an event. This will dispatch a notification to all subscribed handlers.
/// Returns TRUE if anyone was subscribed to the event, FALSE otherwise.
/// @remark target will be available as OBJECT_SELF in subscribed event scripts.
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
/// - Healing events
/// - CombatMode events
/// - Party events
/// - Skill events
/// - Map events
/// - Listen/Spot Detection events
/// - Polymorph events
/// - DMAction events
/// - Client connect event
/// - Client Export Character event
/// - Spell events (except SPELL_FAILED)
/// - QuickChat events
/// - Barter event (START/ADD_ITEM only)
/// - Trap events
/// - Sticky Player Name event
/// - Server Character Save Events
/// - Add/RemoveGold events
/// - PVP Attitude Change events
/// - {Enter|Exit}Stealth events
/// - Object {Lock|Unlock} events
/// - Quickbar Events
/// - Input Pause Event
/// - Input Emote Event
/// - Debug events
/// - Store events
/// - Disarm event
/// - {Enter|Exit}Detect events
/// - Faction events
/// - UnpossessFamiliar event
/// - ClientLevelUpBegin event
/// - CharacterSheetPermitted event
/// - Input Drop Item
/// - Decrement Spell Count event
/// - Play Visual Effect event
/// - EventScript event
/// - Broadcast Safe Projectile event
/// - Attack of Opportunity events
/// - Creature Jump events
/// - SetExperience Events
void NWNX_Events_SkipEvent();

/// Set the return value of the event.
///
/// THIS SHOULD ONLY BE CALLED FROM WITHIN AN EVENT HANDLER.
/// ONLY WORKS WITH THE FOLLOWING EVENTS:
/// - Use Item event - "1" or "0" to send feedback whether item use is allowed
/// - Validate Use Item Event - "1" or "0" to show the item is unusable (red) in the player inventory.
/// - Healer's Kit event
/// - Listen/Spot Detection events -> "1" or "0"
/// - OnClientConnectBefore -> Reason for disconnect if skipped
/// - Ammo Reload event -> Forced ammunition returned
/// - Trap events -> "1" or "0"
/// - Sticky Player Name event -> "1" or "0"
/// - Heal event -> Amount of HP to heal
/// - Has Feat event -> "1" or "0"
/// - Stealth event -> "1" to perform HiPS (without the feat), "0" to bypass HiPS
/// - Faction set reputation event -> The new reputation to apply instead. ("0" - "100")
/// - CharacterSheetPermitted event -> "1" allow the player to view the character sheet or "0" to disallow
/// - Attack target change event -> The new target object. Convert to string with ObjectToString()
void NWNX_Events_SetEventResult(string data);

/// Returns the current event name
///
/// Returns "" on error
string NWNX_Events_GetCurrentEvent();

/// Toggles DispatchListMode for sEvent+sScript(Chunk)
/// If enabled, sEvent for sScript(Chunk) will only be signalled if the target object is on its dispatch list.
void NWNX_Events_ToggleDispatchListMode(string sEvent, string sScriptOrChunk, int bEnable);

/// Add oObject to the dispatch list for sEvent+sScript(Chunk).
void NWNX_Events_AddObjectToDispatchList(string sEvent, string sScriptOrChunk, object oObject);

/// Remove oObject from the dispatch list for sEvent+sScript(Chunk).
void NWNX_Events_RemoveObjectFromDispatchList(string sEvent, string sScriptOrChunk, object oObject);

/// @brief Toggle the whitelisting of IDs for sEvent. If whitelisting is enabled, the event will only fire for IDs that are
/// on its whitelist.
///
/// ONLY WORKS WITH THE FOLLOWING EVENTS -> ID TYPES:
/// - NWNX_ON_CAST_SPELL -> SpellID
/// - NWNX_ON_SPELL_FAILED -> SpellID
/// - NWNX_ON_HAS_FEAT -> FeatID (default enabled)
/// - NWNX_ON_RUN_EVENT_SCRIPT -> EVENT_SCRIPT_* (default enabled)
/// - NWNX_ON_BROADCAST_SAFE_PROJECTILE -> NWNX_ON_BROADCAST_SAFE_PROJECTILE_TYPE for ProjectileType, NWNX_ON_BROADCAST_SAFE_PROJECTILE_SPELL for SpellID
///
/// @note This enables the whitelist for ALL scripts subscribed to sEvent.
/// @param sEvent The event name without _BEFORE / _AFTER.
/// @param bEnable TRUE to enable the whitelist, FALSE to disable
void NWNX_Events_ToggleIDWhitelist(string sEvent, int bEnable);

/// @brief Add nID to the whitelist of sEvent.
/// @note See NWNX_Events_ToggleIDWhitelist for valid events and ID types.
/// @param sEvent The event name without _BEFORE / _AFTER.
/// @param nID The ID.
void NWNX_Events_AddIDToWhitelist(string sEvent, int nID);

/// @brief Remove nID from the whitelist of sEvent.
/// @note See NWNX_Events_ToggleIDWhitelist for valid events and ID types.
/// @param sEvent The event name without _BEFORE / _AFTER.
/// @param nID The ID.
void NWNX_Events_RemoveIDFromWhitelist(string sEvent, int nID);

/// @brief Get the number of subscribers to sEvent.
/// @param sEvent The event.
/// @return The number of subscribers sEvent has or 0 on error.
int NWNX_Events_GetNumSubscribers(string sEvent);

/// @}

void NWNX_Events_SubscribeEvent(string evt, string script)
{
    NWNXPushString(script);
    NWNXPushString(evt);
    NWNXCall(NWNX_Events, "SubscribeEvent");
}

void NWNX_Events_UnsubscribeEvent(string evt, string script)
{
    NWNXPushString(script);
    NWNXPushString(evt);
    NWNXCall(NWNX_Events, "UnsubscribeEvent");
}

void NWNX_Events_UnsubscribeAllStartingWith(string prefix)
{
    NWNXPushString(prefix);
    NWNXCall(NWNX_Events, "UnsubscribeAllStartingWith");
}

void NWNX_Events_SubscribeEventScriptChunk(string sEvent, string sScriptChunk, int bWrapIntoMain = TRUE)
{
    NWNXPushInt(bWrapIntoMain);
    NWNXPushString(sScriptChunk);
    NWNXPushString(sEvent);
    NWNXCall(NWNX_Events, "SubscribeEventScriptChunk");
}

void NWNX_Events_UnsubscribeEventScriptChunk(string sEvent, string sScriptChunk, int bWrapIntoMain = TRUE)
{
    NWNXPushInt(bWrapIntoMain);
    NWNXPushString(sScriptChunk);
    NWNXPushString(sEvent);
    NWNXCall(NWNX_Events, "UnsubscribeEventScriptChunk");
}

void NWNX_Events_PushEventData(string tag, string data)
{
    NWNXPushString(data);
    NWNXPushString(tag);
    NWNXCall(NWNX_Events, "PushEventData");
}

int NWNX_Events_SignalEvent(string evt, object target)
{
    NWNXPushObject(target);
    NWNXPushString(evt);
    NWNXCall(NWNX_Events, "SignalEvent");
    return NWNXPopInt();
}

string NWNX_Events_GetEventData(string tag)
{
    NWNXPushString(tag);
    NWNXCall(NWNX_Events, "GetEventData");
    return NWNXPopString();
}

void NWNX_Events_SkipEvent()
{
    NWNXCall(NWNX_Events, "SkipEvent");
}

void NWNX_Events_SetEventResult(string data)
{
    NWNXPushString(data);
    NWNXCall(NWNX_Events, "SetEventResult");
}

string NWNX_Events_GetCurrentEvent()
{
    NWNXCall(NWNX_Events, "GetCurrentEvent");
    return NWNXPopString();
}

void NWNX_Events_ToggleDispatchListMode(string sEvent, string sScriptOrChunk, int bEnable)
{
    NWNXPushInt(bEnable);
    NWNXPushString(sScriptOrChunk);
    NWNXPushString(sEvent);
    NWNXCall(NWNX_Events, "ToggleDispatchListMode");
}

void NWNX_Events_AddObjectToDispatchList(string sEvent, string sScriptOrChunk, object oObject)
{
    NWNXPushObject(oObject);
    NWNXPushString(sScriptOrChunk);
    NWNXPushString(sEvent);
    NWNXCall(NWNX_Events, "AddObjectToDispatchList");
}

void NWNX_Events_RemoveObjectFromDispatchList(string sEvent, string sScriptOrChunk, object oObject)
{
    NWNXPushObject(oObject);
    NWNXPushString(sScriptOrChunk);
    NWNXPushString(sEvent);
    NWNXCall(NWNX_Events, "RemoveObjectFromDispatchList");
}

void NWNX_Events_ToggleIDWhitelist(string sEvent, int bEnable)
{
    NWNXPushInt(bEnable);
    NWNXPushString(sEvent);
    NWNXCall(NWNX_Events, "ToggleIDWhitelist");
}

void NWNX_Events_AddIDToWhitelist(string sEvent, int nID)
{
    NWNXPushInt(nID);
    NWNXPushString(sEvent);
    NWNXCall(NWNX_Events, "AddIDToWhitelist");
}

void NWNX_Events_RemoveIDFromWhitelist(string sEvent, int nID)
{
    NWNXPushInt(nID);
    NWNXPushString(sEvent);
    NWNXCall(NWNX_Events, "RemoveIDFromWhitelist");
}

int NWNX_Events_GetNumSubscribers(string sEvent)
{
    NWNXPushString(sEvent);
    NWNXCall(NWNX_Events, "GetNumSubscribers");
    return NWNXPopInt();
}
