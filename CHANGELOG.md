# Changelog
All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/).

## [Unreleased]

NOTICE: The ABI has changed, please make sure to update your nwnx.nss and recompile all your scripts. 

### Added
- New plugins: Area, CombatModes, Effect, Encounter, Feedback, Rename, Visibility
- Added support to skip building certain plugins by setting an environment variable, for example: `NWNX_SKIP_PLUGINS="JVM;Lua;Mono;Ruby;SpellChecker"`
- Added support to build out of tree plugins with the following environment variable: `NWNX_ADDITIONAL_PLUGINS={pathtoplugins}`
- Core: Allow skipping all plugins on load with the following environment variable: `NWNX_CORE_SKIP_ALL=y`
- Core: Allow passing engine structures to nwnx (Effect/Itemproperty)
- Events: New events: SkillEvents
- Events: The following events are now skippable: FeatEvents, ItemEvents, HealersKitEvents, CombatModeEvents, PartyEvents, SkillEvents
- Profiler: Support profiler perf scopes via nwscript
- SQL: Added support for SQLite
- Tweaks: DisableQuickSave
- Tweaks: HideDMsOnCharList
##### New functions
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
- Creature: GetAttackBonus()
- Creature: GetFeatRemainingUses()
- Creature: GetFeatTotalUses()
- Creature: SetFeatRemainingUses()
- Effect: PackEffect()
- Effect: UnpackEffect()
- Encounter: GetNumberOfCreaturesInEncounterList()
- Encounter: GetEncounterCreatureByIndex()
- Encounter: SetEncounterCreatureByIndex()
- Encounter: GetFactionId()
- Encounter: SetFactionId()
- Encounter: GetPlayerTriggeredOnly()
- Encounter: SetPlayerTriggeredOnly()
- Encounter: GetResetTime()
- Encounter: SetResetTime()
- Feedback: GetMessageHidden()
- Feedback: SetMessageHidden()
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
- Rename: SetPCNameOverride()
- Util: GetCustomToken()
- Util: EffectToItemProperty()
- Util: ItemPropertyToEffect()
- Visibility: GetVisibilityOverride()
- Visibility: SetVisibilityOverride()
- Weapon: SetWeaponIsMonkWeapon()

### Changed
- Core: The nwnx.txt logfile will now be written to the UserDirectory
- Docker: Set default log level to 6
- Docker: Skip all plugins except ServerLogRedirector by default
- Redis: Lots of stuff, be sure to update the redis nwscripts!

### Deprecated
- Player: {Get/Set}VisibilityOverride are deprecated, please use the new Visibility plugin!

### Removed
- The following plugins were removed: Names, BehaviourTree

### Fixed
- Administration: Fixed a nullptr crash in Get{DM/Player}Password()
- Chat: Fix recursive message skipping
- Events: DMActionEvents now return valid TARGET event data

[Unreleased]: https://github.com/nwnxee/unified/compare/build8186-2...HEAD
