# Changelog
All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/).

## [Unreleased]

NOTICE: The ABI has changed, please make sure to update your nwnx.nss and recompile all your scripts.

### Added
- Added support to skip building certain plugins by setting an environment variable, for example: `NWNX_SKIP_PLUGINS="JVM;Lua;Mono;Ruby;SpellChecker"`
- Added support to build out of tree plugins with the following environment variable: `NWNX_ADDITIONAL_PLUGINS=/path/to/Plugin1;/path/to/Plugin2`
- Added string localization support. Only Russian/Cyrillic supported at the moment. Use environment variable `NWNX_CORE_LOCALE=ru`
- Core: Allow changing default plugin state from 'load all' to 'skip all' with the following environment variable: `NWNX_CORE_SKIP_ALL=y`. Use `NWNX_PLUGIN_SKIP=n` to enable specific plugins in this case.
- Core: Allow passing engine structures to nwnx (Effect/Itemproperty)
- Events: New events: SkillEvents, MapEvents, EffectEvents, QuickChatEvents
- Events: The following events are now skippable: FeatEvents, ItemEvents, HealersKitEvents, CombatModeEvents, PartyEvents, SkillEvents, MapEvents, PolymorphEvents, DMActionEvents, ClientConnectEvents, SpellEvents, QuickChatEvents
- Events: You can now get the current event name with a nwscript function
- Events: Added On{Listen/Spot}Detection events to StealthEvents
- Events: Added On{Un}Polymorph events as PolymorphEvents
- Events: Added Event Data for SpawnObject, GiveItem and GiveAlignment, Heal, Kill, ToggleInvulnerabilty, ForceRest, Limbo, ToggleAI, ToggleImmortal, Goto, Possess, PossessFullPower, ToggleLock, DisableTrap, JumpToPoint, JumpTargetToPoint, JumpAllPlayersToPoint, ChangeDifficulty, ViewInventory, SpawnTrapOnObject events in DMActionEvents
- Events: Added OnClientConnect events that fire before the player sees the server vault.
- Events: Added ItemInventory{Open/Close} and ItemInventory{Add/Remove}Item events to ItemEvents
- Events: Added AmmoReload events that are used when the engine is looking for ammunition to reload
- Profiler: Support profiler perf scopes via nwscript
- SQL: Added support for SQLite
- Tweaks: DisableQuickSave
- Tweaks: HideDMsOnCharList
##### New Plugins
The following plugins were added:
- **Area**: Adds functions exposing additional area properties
- **CombatModes**: Allows subscribing to Combat Mode toggle events. The Events plugin is needed to subscribe to the CombatMode events
- **Effect**: Provides various utility functions to manipulate builtin effect types
- **Experimental**: Adds experimental functionality that's not really useful for the general user. The following environmental variable needs to be true for the plugin to load: `NWNX_CORE_LOAD_EXPERIMENTAL_PLUGIN=y`
- **Encounter**: Adds functions exposing additional encounter properties
- **Feedback**: Allows combatlog and feedback messages to be hidden globally or per player
- **ItemProperty**: Provides various utility functions to manipulate builtin itemproperty types
- **Rename**: Adds functions to facilitate renaming, overriding and customization of player names
- **Reveal**: Adds functions to allow the selective revealing of a stealthed character to another character or their party.
- **Visibility**: Allows the visibility of objects to be overridden globally or per player
##### New NWScript Functions
- Administration: GetPlayOption()
- Administration: SetPlayOption()
- Administration: DeleteTURD()
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
- Area: SetSunMoonColors()
- Creature: GetAttackBonus()
- Creature: GetFeatRemainingUses()
- Creature: GetFeatTotalUses()
- Creature: SetFeatRemainingUses()
- Creature: GetTotalEffectBonus()
- Creature: SetOriginalName()
- Creature: GetOriginalName()
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
- Events: GetCurrentEvent()
- Feedback: GetMessageHidden()
- Feedback: SetMessageHidden()
- ItemProperty: PackIP()
- ItemProperty: UnpackIP()
- Object: GetHasVisualEffect()
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
- Rename: SetPCNameOverride()
- Reveal: RevealTo()
- Reveal: SetRevealToParty()
- Util: GenerateUUID()
- Util: GetCustomToken()
- Util: EffectToItemProperty()
- Util: ItemPropertyToEffect()
- Util: StripColors()
- Visibility: GetVisibilityOverride()
- Visibility: SetVisibilityOverride()
- Weapon: SetWeaponIsMonkWeapon()

### Changed
- Core: The nwnx.txt logfile will now be written to the UserDirectory
- Docker: Set default log level to 6
- Docker: Skip all plugins except ServerLogRedirector by default
- Redis: Lots of stuff, be sure to update the redis nwscripts!
- Events: Changed `NUM_LEVELS` to `AMOUNT` for DMActionEvent GiveLevel

### Deprecated
- Player: {Get/Set}VisibilityOverride are deprecated, please use the new Visibility plugin!

### Removed
- The following plugins were removed: Names, BehaviourTree

### Fixed
- Administration: Fixed a nullptr crash in Get{DM/Player}Password()
- Chat: Fix recursive message skipping
- Events: DMActionEvents now return valid TARGET event data

[Unreleased]: https://github.com/nwnxee/unified/compare/build8186-2...HEAD
