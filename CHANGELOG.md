# Changelog 

All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/).

## Unreleased
https://github.com/nwnxee/unified/compare/build8193.10...HEAD

### Added
N/A

##### New Plugins
N/A

##### New NWScript Functions
N/A

### Changed
N/A

### Deprecated
N/A

### Removed
N/A

### Fixed
N/A

## 8193.9
https://github.com/nwnxee/unified/compare/build8193.9...build8193.10

### Added
- SQL: Added optional support for object storage in binary fields via an optional parameter `base64` in `NWNX_SQL_PreparedObjectFull` and `NWNX_SQL_ReadFullObjectInActiveRow`
- Events: Added OnServerCharacterSave events to ClientEvents. Called when a server vault character will be saved either manually, or when the server saves/exits.
- ELC: Added `NWNX_ON_ELC_VALIDATE_CHARACTER_{BEFORE|AFTER}` events, can be subscribed to with NWNX_Events.
- Events: Added skippable CastSpell event to InputEvents, the WalkToWayPoint and AttackObject events are also skippable now 

##### New Plugins
N/A

##### New NWScript Functions
- Creature: GetFeatGrantLevel()
- Object: GetInternalObjectType()
- Util: GetUserDirectory()
- Util: PluginExists()
- Util: GetScriptReturnValue()
- Object: AcquireItem()
- Object: SetFacing()

### Changed
N/A

### Deprecated
- Creature: Get{Domain|Specialization}

### Removed
N/A

### Fixed
N/A

## 8193.7
https://github.com/nwnxee/unified/compare/build8193.7...build8193.9

### Added
- SQL: `NWNX_SQL_PORT` to set the port used for MySQL database connections.
- Events: Added OnResource{Added|Removed|Modified} events to ResourceEvents, these events fire when a file gets added/removed/modified in the /nwnx or /development folders

##### New Plugins
N/A

##### New NWScript Functions
- Administration: GetServerName()
- Events: UnsubscribeEvent()
- Creature: Get|SetFaction()
- Util: (Un)RegisterServerConsoleCommand()
- Area: GetTileModuleResRef()

### Changed
- Core: the console commands `eval` and `evalx` will now provide an error message if the script chunk fails to execute.
- Damage: Added a Ranged flag to NWNX_Damage_DealDamage()

### Deprecated
N/A

### Removed
- Tweaks: Removed scroll learning freeze bugfix.

### Fixed
- Optimizations: GameObjectLookup no longer breaks `NWNX_Util_GetLastCreatedObject()` and `NWNX_ON_DM_SPAWN_OBJECT` functionality.

## 8193.7
https://github.com/nwnxee/unified/compare/build8193.6...build8193.7

### Added
- Events: Added OnUUIDCollision event to UUIDEvents
- Core: `NWNX_CORE_LOG_ASYNC` variable to asynchronously flush the nwnx log to disk
- Core: `NWNX_CORE_LOG_DATE` variable to add the date in Y-M-D format to the timestamp. Timestamps must be enabled. Default: Off
- Tweaks: `NWNX_TWEAKS_ITEM_CHARGES_COST_MODE` to revert the cost of items with charges to 1.69 values
- Core: `NWNX_CORE_NWNX_RESOURCE_DIRECTORY_PATH` variable to override the default path of the UserDirectory/nwnx folder
 
##### New Plugins
- Optimizations: Tweaks that (potentially) improve performance
    - AsyncLogFlush to asynchronously flush the game log to disk
    - GameObjectLookup to speed up ObjectID to pointer lookups
    - ObjectTagLookup to speed GetObjectByTag() and similar functions

##### New NWScript Functions
- Player: SetResManOverride()
- Creature: {Get|Set}{Domain|Specialization}()
- Util: SetInstructionLimit()
- Area: CreateGenericTrigger()
- Object: GetPositionIsInTrigger()

### Changed
- ELC: Updated for custom spellcaster changes
- Events: exposed TARGET and TYPE event data for DMActionEvent DumpLocals
- Tweaks: added temporary fix for server freeze when learning a spell from a scroll (NWNX_TWEAKS_FIX_SCROLL_LEARNING_BUG)
- Events: OnStealthExit will no longer fire if OnStealthEnter was skipped

### Deprecated
- Creature: {Get|Set}{ClericDomain|WizardSpecialization}()

### Fixed
- Tweaks: Fixed bug that prevented sneak attacks on flanked creatures when using NWNX_TWEAKS_SNEAK_ATTACK_IGNORE_CRIT_IMMUNITY
- Webhook: fixed a crash that would happen when trying to send a message in the shutdown script
- Core: POS is now saved for characters who were online when the server was shut down
- Core: Fixed issue where POS would occasionally get corrupted and print errors to the log
- ServerLogRedirector: Fixed dropped prefixes when using PrintString()

## 8193.6
https://github.com/nwnxee/unified/compare/build8193.5...build8193.6

##### New NWScript Functions
- Object: {Get|Set|Delete}{Int|String|Float}()
- Object: DeleteVarRegex()
- Util: AddNSSFile()
- Util: RemoveNWNXResourceFile()

### Changed
- Object: Renamed {Get|Set|Delete}Persistent{Int|String|Float}() to {Get|Set|Delete}{Int|String|Float}() and added a parameter to the latter to allow persisting of variables on a case-by-case basis 
- Util: `NWNX_UTIL_PRE_MODULE_START_SCRIPT_CHUNK` will now provide an error message if it fails to run a script chunk

### Deprecated
- Object: {Get|Set|Delete}Persistent{Int|String|Float}()

## 8193.5
https://github.com/nwnxee/unified/compare/build8193.4...build8193.5

### Added

##### New NWScript Functions
- Administration: ReloadRules() (DANGER, DRAGONS)

### Changed
- Core: NWNX now also checks the build revision of nwserver-linux when starting.

### Fixed
- Tweaks: DisablePause works yet again, woo.

## 8193.4
https://github.com/nwnxee/unified/compare/build8193.3...build8193.4

### Added

##### New NWScript Functions
- Object: {Get|Set|Delete}Persistent{Int|String|Float}()

### Changed
- Tweaks: SneakAttackCritImmunity now takes `FLANK_LEVEL_RANGE` ruleset.2da setting into account

## 8193.3
https://github.com/nwnxee/unified/compare/build8193.2...build8193.3

### Added
- Events: Added skippable {Lock|Unlock} events to ObjectEvents
- Player: GetLanguage() function

### Changed
- DotNET: C# API has moved from using `NWN.Object` to plain `uint` for NWScript `object` type

### Fixed
- ELC: RDDs now pass NWNX_ELC

## 8193.2
https://github.com/nwnxee/unified/compare/build8193.1...build8193.2

### Changed
- Per Object Storage can now be persisted to GFF. The following variables will now persist: `NWNX_Player!ALWAYS_WALK`, `NWNX_Player!REST_DURATION`, , `NWNX_Player!REST_ANIMATION`, `NWNX_Creature!WALK_RATE_CAP`, `NWNX_Chat!HEARING_DISTANCE*`, `NWNX_Damage!*_EVENT_SCRIPT`, `NWNX_Feedback!*`, `NWNX_Reveal!*`, `NWNX_SkillRanks!SKILLRANK_MOD_*`. This means you no longer need to re-apply these to your players and objects after every restart.

## 8193.1
https://github.com/nwnxee/unified/compare/build8193...build8193.1

Note: Some nwscript files have changed. You will need to update them and recompile all scripts.

### Added

##### New NWScript Functions
- Area: GetMusicIsPlaying()
- Player: GetPlatformId()

### Changed
- Core: NWNX will now provide you with better error messages when you try to call a NWScript NWNX function and you haven't updated your nwnx_*.nss files or the plugin is not loaded.
- We no longer have separate build types (except for symbols and compiler optimizations). All builds now include error messaging and handling.

### Fixed
- Fixed an issue where the `cwd` value was garbled, causing plugin load to fail unless `NWNX_CORE_LOAD_PATH` was set.

## 8193
https://github.com/nwnxee/unified/compare/build8186-lts...build8193

NWNX has moved to 64bit. This is a major change, with many breaking changes listed below, so please examine them carefully.

NOTE: There may be more breaking changes added here until the next official release happens.

### Added
- Core: Added the environment variable `NWNX_CORE_ALLOW_NWNX_FUNCTIONS_IN_EXECUTE_SCRIPT_CHUNK` to enable NWNX function calls in ExecuteScriptChunk(), by default these will be blocked
- Core: NWNX will now create a `/nwnx` folder in your UserDirectory, its resman priority is slightly below the `/development` folder. Currently it's used by NWNX_Object_Export() and NWNX_Util_AddScript() to place their objects/scripts in.
- Core: Added the environment variable `NWNX_CORE_CLEAN_UP_NWNX_RESOURCE_DIRECTORY`, setting this to true will delete all contents in the `/nwnx` folder on startup of the server. Default: false
- Core: Added the environment variable `NWNX_CORE_NWNX_RESOURCE_DIRECTORY_PRIORITY` which lets you change the resman priority of the `/nwnx` folder. Default: 70000000
- Core: Added the following console commands: `runscript`, `eval`, `evalx`, `loglevel`, `logformat`
  - `runscript <scriptname>`: Executes the given nwscript. Example: `runscript dm_killallplayers`
  - `eval <script chunk>`: Executes the given nwscript chunk. Example: `eval ApplyEffectToObject(DURATION_TYPE_INSTANT, EffectDeath(), GetFirstPC());`
  - `evalx <script chunk>`: Executes the given nwscript chunk, this command already includes all nwnx headers available in the module. Example: `evalx NWNX_Administration_ShutdownServer();`
  - `loglevel <plugin> [<loglevel>]`: Sets or gets the log level of the given plugin. Example: Set: `loglevel Events 7`, Get: `loglevel Events`
  - `logformat [timestamp|notimestamp] [plugin|noplugin] [source|nosource] [color|nocolor] [force|noforce]`: Control the output format of logs. Example: `logformat color timestamp noplugin nosource`
- Core: Added the following log related environment variables: `NWNX_CORE_LOG_TIMESTAMP`, `NWNX_CORE_LOG_PLUGIN`, `NWNX_CORE_LOG_SOURCE`, `NWNX_CORE_LOG_COLOR`, `NWNX_CORE_LOG_FORCE_COLOR`
- Util: Added the environment variable `NWNX_UTIL_PRE_MODULE_START_SCRIPT_CHUNK` which lets you set a nwscript chunk that runs before the OnModuleLoad event

##### New Plugins
The following plugins were added:
- **DotNET**: Implement your server scripts in C# (and other dotnet languages)

##### New NWScript Functions
- Administration: {Get|Set}DebugValue()
- Creature: {Get|Set}Disarmable()
- Data: Array_Set()
- Dialog: End()
- Object: Export()
- Player: PossessCreature()
- Util: AddScript()
- Util: GetNSSContents()
- Weapon: GetWeaponFinesseSize()

### Changed
- Administration: DeleteTURD() now returns TRUE on success
- Data: Array_Insert() will now actually do an insert instead of a set
- Effect: Removed the EffectID parameter from the struct
- ELC: Updated with the new ruleset changes
- Events: `NWNX_ON_ITEM_INVENTORY_{ADD|REMOVE}_ITEM_*` has been changed to `NWNX_ON_INVENTORY_{ADD|REMOVE}_ITEM_*`
- Itemproperty: Removed the EffectID parameter from the struct
- SQL: The SQLite database extension has been changed to `.sqlite3nwnxee`

### Removed
- The following plugins were removed: JVM, Mono
- Administration: BootPC()
- Experimental: RemoveACABModifiersFromExpertise
- Object: {Get|Set}EventHandler(), {Get|Set}Portrait()
- Player: {Get|Set}VisibilityOverride()
- Util: GenerateUUID()

## 8186 LTS
https://github.com/nwnxee/unified/compare/build8186-2...build8186-lts

NOTICE: The ABI has changed, please make sure to update your nwnx.nss and recompile all your scripts.

### Added
- Added support to skip building certain plugins by setting an environment variable, for example: `NWNX_SKIP_PLUGINS="JVM;Lua;Mono;Ruby;SpellChecker"`
- Added support to build out of tree plugins with the following environment variable: `NWNX_ADDITIONAL_PLUGINS=/path/to/Plugin1;/path/to/Plugin2`
- Added string localization support. Only Russian/Cyrillic supported at the moment. Use environment variable `NWNX_CORE_LOCALE=ru`
- Core: Allow changing default plugin state from 'load all' to 'skip all' with the following environment variable: `NWNX_CORE_SKIP_ALL=y`. Use `NWNX_PLUGIN_SKIP=n` to enable specific plugins in this case.
- Core: Allow passing engine structures to nwnx (Effect/Itemproperty)
- Core: Added the environment variable `NWNX_CORE_SHUTDOWN_SCRIPT=scriptname` which lets you set a nwscript that runs when the server shuts down
- Core: Added Util functions to call various script events
- Core: NWNX will now log the resref of areas it's trying to load when running log level `7`
- Events: New events: SkillEvents, MapEvents, EffectEvents, QuickChatEvents, InventoryEvents, BarterEvents, TrapEvents, TimingBarEvents, LevelEvents, WebHookEvents
- Events: The following events are now skippable: FeatEvents, ItemEvents, HealersKitEvents, CombatModeEvents, PartyEvents, SkillEvents, MapEvents, PolymorphEvents, DMActionEvents, ClientConnectEvents, SpellEvents, QuickChatEvents, InventoryEvents, BarterEvents (START only), TrapEvents, StickyPlayerNameReservedEvent, StealthEvent
- Events: You can now get the current event name with a nwscript function
- Events: Added On{Listen/Spot}Detection events to StealthEvents
- Events: Added On{Un}Polymorph events as PolymorphEvents
- Events: Added Event Data for SpawnObject, GiveItem, GiveAlignment, Heal, Kill, ToggleInvulnerabilty, ForceRest, Limbo, ToggleAI, ToggleImmortal, Goto, Possess, PossessFullPower, ToggleLock, DisableTrap, JumpToPoint, JumpTargetToPoint, JumpAllPlayersToPoint, ChangeDifficulty, ViewInventory, SpawnTrapOnObject events in DMActionEvents
- Events: Added OnClientConnect events that fire before the player sees the server vault.
- Events: Added ItemInventory{Open/Close}, ItemInventory{Add/Remove}Item, ScrollLearn, DestroyObject and DecrementStackSize events to ItemEvents
- Events: Added {Set|Clear}MemorizedSpellSlot events to SpellEvents
- Events: Added AmmoReload events that are used when the engine is looking for ammunition to reload
- Events: Added Run{Un}Equip events to ItemEvents
- Events: Added Barter Start/End events
- Events: Added AIAction{Disarm|Examine|Flag|Recover|Set}Trap events
- Events: Added Timing Bar events
- Events: Added Sticky Player Name Reserved event allowing builders to use another method instead of knownservernames.2da to validate player names and cd keys
- Events: Added Level{Up|UpAutomatic|Down} events to LevelEvents
- Events: Added WebHook Success/Failure events with rate limit feedback
- Events: Added UseLoreOnItem and PayToIdentifyItem events
- Events: Added {Add|Remove}Gold events to InventoryEvents
- Events: Added PVP Attitude Change event
- Events: Added SplitItem event to ItemEvents
- Events: Added WalkToWaypoint, AttackObject and ForceMoveToObject events to InputEvents
- Events: Added Surface Material Change events
- Profiler: Support profiler perf scopes via nwscript
- SQL: Added support for SQLite
- Tweaks: DisableQuickSave
- Tweaks: HideDMsOnCharList
- Tweaks: DisableMonkAbilitiesWhenPolymorphed
- Tweaks: StringToIntBaseToAuto
- Tweaks: DeadCreatureFiresOnAreaExit
- Tweaks: PreserveActionsOnDMPossess
- Tweaks: FixGreaterSanctuaryBug
- Weapon: Feat and Base Item names were added to LOG_INFO feedback
- WebHook: Added support for richer Slack-compatible messages
- Util: Added the environment variable `NWNX_UTIL_PRE_MODULE_START_SCRIPT=scriptname` which lets you set a nwscript that runs before the OnModuleLoad event
##### New Plugins
The following plugins were added:
- **Appearance**: Allows the appearance and some other things of creatures to be overridden per player
- **Area**: Adds functions exposing additional area properties
- **CombatModes**: Allows subscribing to Combat Mode toggle events. The Events plugin is needed to subscribe to the CombatMode events
- **Effect**: Provides various utility functions to manipulate builtin effect types
- **Experimental**: Adds experimental functionality that's not really useful for the general user. The following environmental variable needs to be true for the plugin to load: `NWNX_CORE_LOAD_EXPERIMENTAL_PLUGIN=y`
- **ELC**: A customisable replacement for ValidateCharacter: ELC & ILR
- **Encounter**: Adds functions exposing additional encounter properties
- **Feedback**: Allows combatlog, feedback and 'quest journal updated' messages to be hidden globally or per player
- **ItemProperty**: Provides various utility functions to manipulate builtin itemproperty types
- **MaxLevel**: Extends support for levels up to 60
- **Race**: Provides the ability to specify a variety of inate modifiers for new or existing races or subraces via script or 2da
- **Regex**: Adds functions to search and replace strings using regular expressions.
- **Rename**: Adds functions to facilitate renaming, overriding and customization of player names
- **Reveal**: Adds functions to allow the selective revealing of a stealthed character to another character or their party.
- **SkillRanks**: Adds functions to create feats and perform actions that manipulate the calculations of skill ranks
- **Visibility**: Allows the visibility of objects to be overridden globally or per player
##### New NWScript Functions
- Administration: GetPlayOption()
- Administration: SetPlayOption()
- Administration: DeleteTURD()
- Appearance: {Get|Set}Override()
- Area: GetNumberOfPlayersInArea()
- Area: GetLastEntered()
- Area: GetLastLeft()
- Area: GetPVPSetting()
- Area: SetPVPSetting()
- Area: GetAreaSpotModifier()
- Area: SetAreaSpotModifier()
- Area: GetAreaListenModifier()
- Area: SetAreaListenModifier()
- Area: GetNoRestingAllowed()
- Area: SetNoRestingAllowed()
- Area: GetWindPower()
- Area: SetWindPower()
- Area: GetWeatherChance()
- Area: SetWeatherChance()
- Area: GetFogClipDistance()
- Area: SetFogClipDistance()
- Area: GetShadowOpacity()
- Area: SetShadowOpacity()
- Area: GetDayNightCycle()
- Area: SetDayNightCycle()
- Area: {Get|Set}SunMoonColors()
- Area: CreateTransition()
- Area: {Get|Set}TileAnimationLoop()
- Area: TestDirectLine()
- Chat: GetChatHearingDistance()
- Chat: SetChatHearingDistance()
- Creature: GetAttackBonus()
- Creature: GetHighestLevelOfFeat()
- Creature: GetFeatRemainingUses()
- Creature: GetFeatTotalUses()
- Creature: SetFeatRemainingUses()
- Creature: GetTotalEffectBonus()
- Creature: SetOriginalName()
- Creature: GetOriginalName()
- Creature: SetSpellResistance()
- Creature: GetPrePolymorphAbilityScore()
- Creature: {Get|Set}MovementRateFactor()
- Creature: Set{AnimalCompanion|Familiar}CreatureType()
- Creature: Set{AnimalCompanion|Familiar}Name()
- Damage: SetAttackEventScript()
- Damage: GetAttackEventData()
- Damage: SetAttackEventData()
- Damage: DealDamage()
- Effect: PackEffect()
- Effect: UnpackEffect()
- Effect: SetEffectExpiredScript()
- Effect: GetEffectExpiredData()
- Effect: GetEffectExpiredCreator()
- Encounter: GetNumberOfCreaturesInEncounterList()
- Encounter: GetEncounterCreatureByIndex()
- Encounter: SetEncounterCreatureByIndex()
- Encounter: GetFactionId()
- Encounter: SetFactionId()
- Encounter: GetPlayerTriggeredOnly()
- Encounter: SetPlayerTriggeredOnly()
- Encounter: GetResetTime()
- Encounter: SetResetTime()
- ELC: SetELCScript()
- ELC: EnableCustomELCCheck()
- ELC: SkipValidationFailure()
- ELC: GetValidationFailureType()
- ELC: GetValidationFailureSubType()
- ELC: GetValidationFailureMessageStrRef()
- ELC: SetValidationFailureMessageStrRef()
- ELC: GetValidationFailureItem();
- ELC: GetValidationFailureLevel();
- ELC: GetValidationFailureSkillID();
- ELC: GetValidationFailureFeatID();
- ELC: GetValidationFailureSpellID();
- Events: GetCurrentEvent()
- Events: ToggleDispatchListMode()
- Events: AddObjectToDispatchList()
- Events: RemoveObjectFromDispatchList()
- Feedback: Get{Feedback|CombatLog|JournalUpdated}MessageHidden()
- Feedback: Set{Feedback|CombatLog|JournalUpdated}MessageHidden()
- Feedback: Set{Feedback|CombatLog}MessageMode()
- Item: GetBaseArmorClass()
- Item: GetMinEquipLevel()
- ItemProperty: PackIP()
- ItemProperty: UnpackIP()
- Object: GetHasVisualEffect()
- Object: CheckFit()
- Object: GetDamageImmunity()
- Object: AddToArea()
- Object: GetPlaceableIsStatic()
- Object: SetPlaceableIsStatic()
- Object: {Get|Set}AutoRemoveKey()
- Object: {Get|Set}TriggerGeometry()
- Object: {Add|Remove}IconEffect()
- Player: ShowVisualEffect()
- Player: ForcePlaceableInventoryWindow()
- Player: MusicBackgroundChangeDay()
- Player: MusicBackgroundChangeNight()
- Player: MusicBackgroundStart()
- Player: MusicBackgroundStop()
- Player: MusicBattleChange()
- Player: MusicBattleStart()
- Player: MusicBattleStop()
- Player: PlaySound()
- Player: SetPlaceableUsable()
- Player: SetRestDuration()
- Player: ApplyInstantVisualEffectToObject()
- Player: UpdateCharacterSheet()
- Player: OpenInventory()
- Player: GetAreaExplorationState()
- Player: SetAreaExplorationState()
- Player: SetRestAnimation()
- Player: SetObjectVisualTransformOverride()
- Player: ApplyLoopingVisualEffectToObject()
- Player: SetPlaceableNameOverride()
- Player: GetQuestCompleted()
- Player: SetPersistentLocation()
- Player: UpdateItemName()
- Race: SetRacialModifier()
- Race: GetParentRace()
- Regex: Search()
- Regex: Replace()
- Rename: SetPCNameOverride()
- Rename: GetPCNameOverride()
- Rename: ClearPCNameOverride()
- Reveal: RevealTo()
- Reveal: SetRevealToParty()
- SkillRanks: GetSkillFeat()
- SkillRanks: GetSkillFeatCountForSkill()
- SkillRanks: GetSkillFeatForSkillByIndex()
- SkillRanks: SetSkillFeat()
- SkillRanks: SetSkillFeatFocusModifier()
- SkillRanks: GetBlindnessPenalty()
- SkillRanks: SetBlindnessPenalty()
- SkillRanks: GetAreaModifier()
- SkillRanks: SetAreaModifier()
- Util: GenerateUUID()
- Util: GetCustomToken()
- Util: GetEnvironmentVariable()
- Util: EffectToItemProperty()
- Util: ItemPropertyToEffect()
- Util: StripColors()
- Util: IsValidResRef()
- Util: GetMinutesPerHour()
- Util: SetMinutesPerHour()
- Util: EncodeStringForURL()
- Util: Get2DARowCount()
- Util: Get{First|Next}ResRef()
- Util: GetServerTicksPerSecond()
- Util: GetLastCreatedObject()
- Visibility: GetVisibilityOverride()
- Visibility: SetVisibilityOverride()
- Weapon: SetWeaponIsMonkWeapon()

### Changed
- Core: The nwnx.txt logfile will now be written to the UserDirectory
- Chat: LOG_DEBUG suppresses player to player tell specifics
- Item: SetWeight now recomputes the possessor's encumbrance
- Docker: Set default log level to 6
- Docker: Skip all plugins except ServerLogRedirector by default
- Redis: Lots of stuff, be sure to update the redis nwscripts!
- Events: Changed `NUM_LEVELS` to `AMOUNT` for DMActionEvent GiveLevel
- Player: StartGuiTimingBar() now accepts a type for pre-defined text

### Deprecated
- Player: {Get/Set}VisibilityOverride() are deprecated, please use the new Visibility plugin!
- Object: {Get/Set}Portrait() are deprecated, please use the native {Get/Set}PortraitResRef() functions instead!

### Removed
- The following plugins were removed: Names, BehaviourTree

### Fixed
- Administration: Fixed a nullptr crash in Get{DM/Player}Password()
- Chat: Fix recursive message skipping
- Object: GetLocalVariable and GetLocalVariableCount now work with Area and Module object
- Events: DMActionEvents now return valid TARGET event data
- Core: Serialization now stores locals and effects for all objects, instead of only items
