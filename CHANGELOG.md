# Changelog {#changelog}

[TOC]

All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/).

## Unreleased

https://github.com/nwnxee/unified/compare/build8186-2...HEAD

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
