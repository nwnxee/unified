# Changelog

All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/).

## Unreleased
https://github.com/nwnxee/unified/compare/build8193.36.12...HEAD

### Added
- N/A

##### New Plugins
- Store: Enables getting and setting store data.

##### New NWScript Functions
- Util: GetModuleTlkFile()
- Object: {Set|Get}LocalizedName()
- Store: GetIsRestrictedBuyItem()
- Store: {Get|Set}BlackMarketMarkDown()
- Store: {Get|Set}MarkDown()
- Store: {Get|Set}MarkUp()
- Player: ReloadTlk()
- Player: ReloadColorPalettes()

### Changed
- N/A

### Deprecated
- N/A

### Removed
- N/A

### Fixed
- N/A

## 8193.36.10
https://github.com/nwnxee/unified/compare/build8193.36.9...build8193.36.10

### Added
- Optimizations: added `NWNX_OPTIMIZATIONS_CACHE_SCRIPTS` to cache scripts after first execution.

##### New NWScript Functions
- Util: CleanResourceDirectory()

### Changed
- NWNX_Item_RestoreItemAppearance() will now force an immediate update to the items AC, depending on new appearance.

### Fixed
- Weapon: fixed SetWeaponFinesseSize() clobbering the baseitems.2da values.

## 8193.36.9
https://github.com/nwnxee/unified/compare/build8193.36.8...build8193.36.9

### Added
- Optimizations: added `NWNX_OPTIMIZATIONS_CACHE_SCRIPTS` to cache scripts after first execution.

## 8193.36.7
https://github.com/nwnxee/unified/compare/build8193.35.40...build8193.36.7

### Added
- Feat: added modifier `NWNX_FEAT_MODIFIER_SPELLSAVEDCFORSCHOOL` to modify a creature's spell DC for a spell school
- Feat: added modifier `NWNX_FEAT_MODIFIER_SPELLSAVEDCFORSPELL` to modify a creature's spell DC for an individual spell
- Events: added event `NWNX_ON_SPELL_FAILED_{BEFORE|AFTER}` which fires when the casting of a spell did not finish for any reason.
- Tweaks: added `NWNX_TWEAKS_FIX_AUTOMAP_CRASH` which fixes a server crash that happens when automap data is outdated for a player.
- Events: added event `NWNX_ON_ATTACK_TARGET_CHANGE_{BEFORE|AFTER}` which fires when a creature changes its attack target.
- Events: added `NWNX_ON_PLACEABLE_OPEN_{BEFORE|AFTER}` which fires when player opens a placeable.
- Events: added `NWNX_ON_PLACEABLE_CLOSE_{BEFORE|AFTER}` which fires when player closes a placeable.
- Events: added event `NWNX_ON_CREATURE_TILE_CHANGE_{BEFORE|AFTER}` which fires when a creature changes the tile it's on.
- Tweaks: added `NWNX_TWEAKS_SETAREA_CALLS_SETPOSITION` which will enable firing of the `NWNX_ON_MATERIALCHANGE_*` and `NWNX_ON_CREATURE_TILE_CHANGE_*` events when a creature is first added to an area.
- Events: added `NWNX_ON_CREATURE_JUMP_TO_POSITION_{BEFORE|AFTER}` which fires when a creature is being jumped to a new location (area + x/y/z coordinates).
- Events: added `NWNX_ON_CREATURE_JUMP_TO_OBJECT_{BEFORE|AFTER}` which fires when a creature is being jumped to a new location (to an object).
- Events: added skippable events `NWNX_ON_ITEMPROPERTY_EFFECT_(APPLIED|REMOVED)_*` which fire when the game applies or removes the effects from an itemproperty.
- Tweaks: added `NWNX_TWEAKS_FIRE_EQUIP_EVENTS_FOR_ALL_CREATURES` which makes the module OnPlayerEquipItem and OnPlayerUnEquipItem events fire for all creatures.
- Tweaks: added `NWNX_TWEAKS_DONT_DELAY_EQUIP_EVENT` which fixes Unequip/Equip events being out of sync if an item is equipped/unequipped multiple times per server tick.

##### New Plugins
- Resources: Adds `RESOURCES_*` variables for adding NWSync as a resource source, and specifying a replacement hak list.
- NWSQLiteExtensions: Adds various extensions for the game's built-in sqlite databases.

##### New NWScript Functions
- Object: GetLastSpellInstant()
- Object: SetTrapCreator()
- Creature: {Get|Set}MaxSellToStorePriceOverride()
- Creature: {Get|Set}AbilityIncreaseByLevel()
- Util: GetModuleFile()
- Creature: NWNX_Creature_GetMaxAttackRange()
- Player: GetTURD()
- Item: {Get|Set}MinEquipLevel{Modifier|Override}()
- Util: UpdateClientObject()

### Changed
- Creature: Added an argument for passing a class package to `NWNX_Creature_LevelUp()`
- Player: Added arguments for passing transform data (scale, translation, rotation) to `NWNX_Player_ShowVisualEffect()` and `NWNX_Player_ApplyInstantVisualEffectToObject()`
- Damage: The damage event now also fires for doors
- Feat: Added the 'Damage'(Increase/Decrease) as an option
- Object: GetInventoryItemCount() will also work on stores.

### Removed
- Tweaks: `NWNX_TWEAKS_FIX_AUTOMAP_CRASH`, fixed in basegame.
- Tweaks: `NWNX_TWEAKS_FIX_TURD_EFFECT_UNLINKING`, fixed in basegame.

### Fixed
- Experimental: PlayerHitpointsAsPercentage: added the new argument nMessageLimit to SendServerToPlayerGameObjUpdate hook
- Reveal: Fixed Reveal plugin always revealing all PCs regardless of plugin usage.
- Area: RotateArea's 'NewOrientation' corrected for NWN bearings, correcting direction of objects within the area after 90 or 270 degree rotation.

## 8193.35.40
https://github.com/nwnxee/unified/compare/build8193.35.37...build8193.35.40

### Added
- Tweaks: added `NWNX_TWEAKS_RANGED_WEAPONS_USE_ON_HIT_EFFECT_ITEM_PROPERTIES` which makes all bows, crossbows, and slings use On Hit: Effect item properties (in addition to their ammunition).
- Tweaks: added `NWNX_TWEAKS_RANGED_WEAPONS_USE_ON_HIT_CAST_SPELL_ITEM_PROPERTIES` which makes all bows, crossbows, and slings use On Hit: Cast Spell item properties (in addition to their ammunition).
- Tweaks: added `NWNX_TWEAKS_CAST_ALL_ON_HIT_CAST_SPELL_ITEM_PROPERTIES` which casts all On Hit: Cast Spell item properties on hit, instead of only the first property.
- Events: added skippable event `NWNX_ON_BROADCAST_SAFE_PROJECTILE_{BEFORE|AFTER}` which fires whenever a projectile VFX is created for ranged weapons and spells.
- Events: added skippable event `NWNX_ON_BROADCAST_ATTACK_OF_OPPORTUNITY_{BEFORE|AFTER}` which allows skipping a creature provoking attacks of opportunities from enemies.
- Events: added skippable event `NWNX_ON_COMBAT_ATTACK_OF_OPPORTUNITY_{BEFORE|AFTER}` which allows stopping a creature from performing an attack of opportunity against a target.
- Events: added skippable event `NWNX_ON_AREA_PLAY_BATTLE_MUSIC_{BEFORE|AFTER}` which allows skipping the starting/stopping of an area's battle music.
- Experimental: Added `NWNX_EXPERIMENTAL_END_COMBATROUND_AFTER_SPELLCAST` to end combat rounds right after casting or canceling a spell so that a new spell can be cast immediately after

##### New NWScript Functions
- Object: GetInventoryItemCount()
- Object: OverrideSpellProjectileVFX()
- Util: GetStringLevenshteinDistance()
- Creature: DoCleaveAttack()
- Creature: {Get|Set}LockOrientationToObject()
- Creature: BroadcastAttackOfOpportunity()

### Changed
- Events: Added event data `TARGET_OBJECT_ID`/`TARGET_POSITION_{X|Y|Z}`/`SPELL_DOMAIN`/`SPELL_SPONTANEOUS`/`SPELL_METAMAGIC`/`PROJECTILE_PATH_TYPE` to `NWNX_ON_BROADCAST_CAST_SPELL_*`
- ***ABI BREAKING:*** Creature: DoItemCastSpell() can now override the spell impact script, and set the spell cast item retrieved by GetSpellCastItem().
- ***ABI BREAKING:*** Damage: SetAttackEventData() can now set `AttackEventData.iSneakAttack`. This only affects the attack roll message and floating text feedback. Immunities and damage will have already been resolved by the time the attack event script is ran.

### Fixed
- Tweaks: FixResolveSpecialAttackDamage: fixed a crash involving ranged special attacks interacting oddly with Epic Dodge.
- Player: fixed ToggleDM() not working correctly with EffectTimeStopImmunity().

## 8193.35.37
https://github.com/nwnxee/unified/compare/build8193.35.36...build8193.35.37

### Added
- Events: added event data `TARGET_OBJECT_ID`, `TARGET_POSITION_X`, `TARGET_POSITION_Y` and `TARGET_POSITION_Z` to the `NWNX_ON_TRAP_SET_*` events
- Events: added `NEEDS_TO_MOVE` event data to BEFORE trap events to differentiate between the BEFORE event that will be fired if the player is not in range of its target and the BEFORE event that will be fired right before interacting with the trap. Both BEFORE events are skippable
- Events: added event data `VERSION_POSTFIX` to event `NWNX_ON_CLIENT_CONNECT_*`

##### New NWScript Functions
- Creature: {Get|Set}MaximumBonusAttacks()
- Player: SendPartyInvite()
- Item: MoveTo()

### Changed
- Events: Trap events don't fire 2-3 times for each action, but a single BEFORE and AFTER event plus an additional BEFORE event if the player needs to move to the target first

## 8193.35.36
https://github.com/nwnxee/unified/compare/build8193.34final...build8193.35.36

### Added
- Administration: added `NWNX_ADMINISTRATION_OPTION_SHOW_PLAYER_JOIN_MESSAGES` to {Get|Set}PlayOption.
- Effect: added `NWNX_EFFECT_EXTEND_DURATION_TYPE` which extends ApplyEffectToObject() to apply effects with `DURATION_TYPE_EQUIPPED` and `DURATION_TYPE_INNATE`.
- SQL: added `CHARACTER_SET` support to PostgresSQL.
- Optimizations: added `NWNX_OPTIMIZATIONS_CACHE_DEBUGGER_INSTANCES` to cache nwscript debugger instances, improving GetScriptBacktrace() performance.

##### New NWScript Functions
- Area: SetDefaultObjectUiDiscoveryMask()
- Effect: SetEffectCreator()
- Effect: GetIsEffectValid()
- Effect: GetAppliedEffectCount()
- Effect: GetAppliedEffect()
- Events: UnsubscribeAllStartingWith()
- Object: ForceAssignUUID()
- Player: GetGameObject()
- Player: SetObjectUiDiscoveryMaskOverride()
- SQL: PostgreSQL_SetNextQueryResultsBinaryMode()

### Changed
- SQL: Sqlite support now uses the sqlite3 embedded in NWNX.
- Core: NWScript NWNX Functions are now also blocked in DelayCommand/AssignCommand spawned from script chunks unless disabled by config.
- Item: GetEntireItemAppearance() and RestoreItemAppearance() now support the new extended model part range.

### Removed
- The following tweaks / optimizations have been removed due to being fixed or added in the basegame:
  - `NWNX_TWEAKS_SUMMON_ASSOCIATE_USE_COMPUTE_SAFE_LOCATION`
  - `NWNX_TWEAKS_FIX_DM_FACTION_BUG`
  - `NWNX_TWEAKS_FIX_DM_SELECTION_BOX`
  - `NWNX_TWEAKS_FIX_MULTICLASS_XP_PENALTY_BUG`
  - `NWNX_OPTIMIZATIONS_FIX_PLACEABLE_VFX_REAPPLY_BUG`
  - `NWNX_OPTIMIZATIONS_CLIENT_GAMEOBJECT_UPDATE_TIME` `NWNX_OPTIMIZATIONS_CLIENT_GAMEOBJECT_UPDATE_TIME_LOADING`
  - `NWNX_OPTIMIZATIONS_RECONCILE_AUTOMAP_DATA`
  - `NWNX_OPTIMIZATIONS_UPDATE_LIST_COMPARISONS`
- The following NWNX NWScript functions have been removed due to being implemented in the basegame, see [Compatibility/nwnx_deprecated.nss](Compatibility/nwnx_deprecated.nss) for more information!
  - Creature: GetMemorisedSpellCountByLevel()
  - Creature: GetMemorisedSpell()
  - Creature: SetMemorisedSpell()
  - Creature: GetKnownSpellCount()
  - Creature: GetKnownSpell()
  - Creature: ClearMemorisedKnownSpells()
  - Creature: ClearMemorisedSpell()
  - Creature: {Get|Set}Soundset()
  - Creature: SetGender()
  - Creature: RestoreSpells()
  - Creature: GetDomain()
  - Creature: GetSpecialization()
  - Creature: GetSpellUsesLeft()
  - Creature: GetMemorizedSpellReadyCount()
  - Creature: SetEffectIconFlashing()
  - Effect: SetEffectExpiredScript()
  - Effect: GetEffectExpiredData()
  - Effect: GetEffectExpiredCreator()
  - Effect: AccessorizeVisualEffect()
  - Object: StringToObject()
  - Object: CheckFit()
  - Object: AddIconEffect()
  - Object: RemoveIconEffect()
  - Object: SetFacing()
  - Regex: Search()
  - Regex: Replace()
  - Regex: Match()
  - Util: IsValidResRef()
  - Util: Get2DARowCount()
  - Util: GetNSSContents()
  - Util: GetServerTicksPerSecond()

### Fixed
- Item: SetItemAppearance() now properly works with WeaponColor/Model, identical to CopyItemAndModify()

## 8193.34Final
https://github.com/nwnxee/unified/compare/build8193.34...build8193.34final

### Added
- Tweaks: added `NWNX_TWEAKS_CANUSEITEM_CHECK_ILR_FOR_HENCHMEN` to have the CNWSCreature::CanUseItem() function also check ILR for Henchmen.
- Tweaks: added `NWNX_TWEAKS_FIX_DM_SELECTION_BOX` to fix the DM creature selection box not showing up when player party control is off.
- Tweaks: added `NWNX_TWEAKS_FIX_TRIGGER_ENTER_DETECTION` to fix a rare issue where triggers/traps fire enter events without a creature inside.
- Tweaks: added `NWNX_TWEAKS_FIX_MULTICLASS_XP_PENALTY_BUG` to fix a bug where multiclass xp penalties are calculated incorrectly.
- Tweaks: added `NWNX_TWEAKS_UNCAP_DAMAGE_RESISTANCE_DAMAGE_FLAGS` to uncap the compounded damage type flags of EffectDamageResistance().
- Tweaks: added `NWNX_TWEAKS_FIX_RESOLVE_SPECIAL_ATTACK_DAMAGE` to fix special attacks dealing damage on a miss.
- Tweaks: added `NWNX_TWEAKS_FIX_TURD_EFFECT_UNLINKING` to fix effects unlinking when restored from a TURD due to their effect id changing.
- Optimizations: added `NWNX_OPTIMIZATIONS_FIX_PLACEABLE_VFX_REAPPLY_BUG` to fix a bug where VFXs keep getting reapplied to placeables.
- Optimizations: added `NWNX_OPTIMIZATIONS_CACHE_SCRIPT_CHUNKS` to cache script chunks after first execution.
- Optimizations: added `NWNX_OPTIMIZATIONS_CLIENT_GAMEOBJECT_UPDATE_TIME` to change the global client gameobject update time.
- Optimizations: added `NWNX_OPTIMIZATIONS_CLIENT_GAMEOBJECT_UPDATE_TIME_LOADING` to change the client gameobject update time for players loading an area.
- Optimizations: added `NWNX_OPTIMIZATIONS_UPDATE_LIST_COMPARISONS` which optimizes the visibility and vvf list comparisons.
- Events: added skippable event `NWNX_ON_INPUT_DROP_ITEM_{BEFORE|AFTER}` which fires when a player attempts to drop an item.
- Events: added skippable event `NWNX_ON_DECREMENT_SPELL_COUNT_{BEFORE|AFTER}` which fires when spell count (Memorized, non-memorized, or spell-like ability) decreases.
- Events: added skippable event `NWNX_ON_DEBUG_PLAY_VISUAL_EFFECT_{BEFORE|AFTER}` which fires when the dm_visualeffect console command is used.
- Events: added skippable event `NWNX_ON_RUN_EVENT_SCRIPT_{BEFORE|AFTER}` which fires on all object event scripts.
- Events: added skippable event `NWNX_ON_BARTER_ADD_ITEM_{BEFORE|AFTER}` which fires when an item is added to the barter window.
- Experimental: added `NWNX_EXPERIMENTAL_IGNORE_MODULE_VERSION` to ignore the module version when loading.
- Events: added `NWNX_ON_OBJECT_USE_{BEFORE|AFTER}` which fires when player uses a placeable.

##### New NWScript Functions
- Area: GetTileInfoByTileIndex()
- Area: GetPathExists()
- Area: {Get|Set}AreaFlags()
- Area: GetAreaWind()
- Creature: {Get|Set}SkillPointsRemainingByLevel()
- Creature: {Get|Set}InitiativeModifier()
- Creature: GetBodyBag()
- Creature: GetMovementRateFactorCap()
- Creature: AddCastSpellActions()
- Creature: GetSpellUsesLeft()
- Creature: GetMemorizedSpellReadyCount()
- Creature: GetIsFlanking()
- Creature: DecrementRemainingSpellSlots()
- Creature: IncrementRemainingSpellSlots()
- Effect: AccessorizeVisualEffect()
- Encounter: Destroy()
- Events: SubscribeEventScriptChunk()
- Events: UnsubscribeEventScriptChunk()
- Events: GetNumSubscribers()
- Feat: LoadFeatModifiers()
- Object: SetConversationPrivate()
- Object: {Get|Set}AoEObjectRadius()
- Object: GetLastSpellCastSpontaneous()
- Object: GetLastSpellCastDomainLevel()
- Player: UpdateWind();
- Player: UpdateSkyBox();
- Player: UpdateFogColor();
- Player: UpdateFogAmount();
- Player: GetGameObject()
- Regex: Match()
- Core: PluginExists()

### Changed
- Events: added event data `VERSION_MAJOR`/`VERSION_MINOR`/`PLATFORM_ID` to `NWNX_ON_CLIENT_CONNECT_*`
- Object: DoSpellLevelAbsorption() can now override the spellId, the level and the school of the casted spell
- Object: DoSpellImmunity() can now override the spellId
- Events: added event data `STAT`/`VALUE`/`TARGET`/`SET` to `NWNX_ON_DM_SET_STAT_*`
- Events: added event data `TYPE`/`TARGET`/`KEY` to `NWNX_ON_DM_GET_VARIABLE_*`
- Events: added event data `TYPE`/`TARGET`/`KEY`/`VALUE` to `NWNX_ON_DM_SET_VARIABLE_*`
- Events: added event data `TARGET`/`FACTION_ID`/`FACTION_NAME` to `NWNX_ON_DM_SET_FACTION_*`

### Deprecated
- Util: PluginExists()

### Fixed
- Race: Fixed an issue with feat usages being reset upon character relog
- Feat: Fixed an issue with an Ability Score feat counting towards the server capped limit when they should not
- Feat: Fixed an issue with bonus feats not properly being removed
- Object: GetLocalVariable() now recognizes variables of type json.
- Tweaks: Language override tweak now works for area names.
- Events: Fixed a crash when skipping `NWNX_ON_CLIENT_CONNECT_BEFORE`
- Tweaks: Fixed an issue where lobby PC list viewers would see new characters logged in when those names should be suppressed
- Tweaks: Classes are not hidden from DMs when using `NWNX_TWEAKS_HIDE_CLASSES_ON_CHAR_LIST`

## 8193.34
https://github.com/nwnxee/unified/compare/build8193.33...build8193.34

### Added
- Tweaks: added `NWNX_TWEAKS_HIDE_HARDCODED_ITEM_VFX` to hide various hardcoded item vfx.
- Tweaks: added `NWNX_TWEAKS_FIX_RESMAN_MEMLEAK` that fixes a memory leak in Resman / CResGFF.
- Tweaks: added `NWNX_TWEAKS_FIX_DM_FACTION_BUG` that fixes a DM faction bug when using a non-DMClient BIC file.

##### New NWScript Functions
- Area: RotateArea()
- Creature: OverrideRangedProjectileVFX()
- Object: GetAoEObjectDurationRemaining()

### Changed
- Object: `NWNX_Object_Export` added argument sAlias, default 'NWNX'

### Removed
- Tweaks: `NWNX_TWEAKS_FIX_RESMAN_MEMLEAK`, fixed in basegame.

## 8193.33
https://github.com/nwnxee/unified/compare/build8193.32...build8193.33

### Added
- Events: added event `NWNX_ON_CLIENT_SET_DEVICE_PROPERTY_BEFORE__*` which fires when a player changes a device property (window size/gui scale).
- Tweaks: added `NWNX_TWEAKS_SUMMON_ASSOCIATE_USE_COMPUTE_SAFE_LOCATION` which makes CNWSCreature::SummonAssociate() will use ComputeSafeLocation() instead of ComputeNonVisibleLocation(), possibly fixing some Familiar/AnimalCompanion summon issues.

##### New NWScript Functions
- Util: GetModuleMtime()

### Fixed
- Chat: When using custom hearing distances, broadcast the actual message instead of the tellname.
- Chat: When using custom hearing distances, check if a player actually has one set and don't just overwrite the distance with 0.0f if not set.
- Chat: When using custom hearing distances, don't send messages to players that don't have a valid creature object causing a server crash.

## 8193.32
https://github.com/nwnxee/unified/compare/build8193.31...build8193.32

### Added
- Administration: added `NWNX_ADMINISTRATION_OPTION_PLAYER_PARTY_CONTROL` to {Get|Set}PlayOption() to toggle player party control.

### Fixed
- Util: fixed a memory leak in GetFirstResRef()

## 8193.31
https://github.com/nwnxee/unified/compare/build8193.30...build8193.31

### Added
- Events: Added NWNX_ON_ITEM_MERGE_BEFORE and NWNX_ON_ITEM_MERGE_AFTER.
- ELC: added `NWNX_ELC_ENFORCE_CASTER_PRIMARY_STAT_IS_11`, if enabled, ELC will check when a character's first level class is a spellcaster, if their primary casting stat is >= 11.

##### New NWScript Functions
- Creature: RemoveFeatByLevel()
- Creature: GetSkillRankByLevel()
- Creature: SetSkillRankByLevel()
- SQL: PreparedNULL()

### Changed
- Core: **POLICY CHANGE:** Only `stdout` output will be accepted in bug reports.
- Core: Assert backtraces now show up in the log file.
- Core: Assert backtraces are now printed to `stdout` instead of `stderr`.
- Core: Other error messages are now printed to `stdout` instead of `stderr`
- Core: The default NWN crash handler is no longer called by default. Set `NWNX_CORE_BASE_GAME_CRASH_HANDLER=y` to call it.
- Core: `nwnx.txt` is no longer created by default. Set `NWNX_CORE_LOG_FILE_PATH="path/to/nwnx.txt"` to use it.
- Race: The AC modifier now supports specifying the AC type.

### Fixed
- Core: Fixed a minor memory leak when asserts were triggered.
- Rename: Fixed SetPCNameOverride() subscribing to `NWNX_CREATURE_ORIGINALNAME_SIGNAL` whenever the function is called, causing bad performance.
- Player: Fixed a nullptr deref crash in ApplyLoopingVisualEffectToObject()

## 8193.30
https://github.com/nwnxee/unified/compare/build8193.29...build8193.30

### Added

##### New NWScript Functions
- Object: SetLastTriggered()

### Changed
- ***ABI BREAKING*** Creature: SetClassByPosition by default replaces all occurrences of the old class in CNWLevelStats. This can be disabled with the argument 'bUpdateLevels'.

### Deprecated
- Weapon: SetWeaponIsMonkWeapon()

### Removed
- CombatModes: plugin has been removed. The NWNX_ON_COMBAT_MODE_* events and NWNX_Weapon_SetWeaponIsMonkWeapon() Flurry of Blows functionality has been preserved.
- Tweaks: removed `NWNX_TWEAKS_FIX_AOE_OBJECT_POSITION_BUG`, fixed in basegame.

## 8193.29
https://github.com/nwnxee/unified/compare/build8193.26...build8193.29

### Added
- Tweaks: added `NWNX_TWEAKS_MATERIAL_NAME_NULL_IS_ALL` to allow setting params on all applicable materials at once.
- Tweaks: added `NWNX_TWEAKS_FIX_AOE_OBJECT_POSITION_BUG` to stop AreaOfEffect objects (auras, etc) from breaking GetNearestXXX() stuff.

## 8193.26
https://github.com/nwnxee/unified/compare/build8193.25...build8193.26

- No user facing changes

## 8193.25
https://github.com/nwnxee/unified/compare/build8193.24...build8193.25

- No user facing changes

## 8193.24
https://github.com/nwnxee/unified/compare/build8193.23...build8193.24

### Added
- Feat: added environment variable `NWNX_FEAT_CUSTOM_SPELL_ID` to give a custom spellid to all effects created by this plugin.

##### New NWScript Functions
- Creature: RunEquip()
- Creature: RunUnequip()
- Util: SetCurrentlyRunningEvent()

### Changed
- Damage: added ToHitRoll and ToHitModifier data to the AttackEvent structure.

### Fixed
- Core: {Get|Set}LocalCassowary() actually work and no longer throw asserts.
- Dialog: fixed a crash when calling GetCurrentNodeID() in an OnConversationAborted script.
- Events: InputEvents: NWNX_ON_INPUT_FORCE_MOVE_TO_OBJECT_* now uses the right hook.

## 8193.22
https://github.com/nwnxee/unified/compare/build8193.22...build8193.23

### Added

##### New NWScript Functions
- Creature: DoItemCastSpell()
- Object: GetLastSpellCastFeat()

##### New Plugins
- Compiler: Adds command-line compilation of nss files using the in-built compiler.

### Changed
- ***ABI BREAKING:*** Effect: Apply() switched the order in which the arguments are pushed and renamed the internal function name.
- ***API BREAKING:*** Tileset: NWNX_Tileset_GetTilesetGroupTile() needs the tileset name and group index in addition to the tile index.

## 8193.21
https://github.com/nwnxee/unified/compare/build8193.21...build8193.22

### Added
- Events: added skippable event `NWNX_ON_CLIENT_LEVEL_UP_BEGIN_*` which fires when a player clicks the levelup button.
- Events: added skippable event `NWNX_ON_POSSESS_FAMILIAR_*` which fires when a player attempts to possess their familiar.
- Events: added skippable event `NWNX_ON_CHARACTER_SHEET_PERMITTED_*` which fires when a player attempts to view a charactersheet.
- Events: added events `NWNX_ON_CHARACTER_SHEET_{OPEN|CLOSE}_*` which fire when a player opens or closes a charactersheeet.
- Tweaks: added `NWNX_TWEAKS_SEND_TLK_OVERRIDE_BEFORE_CHARGEN` to send TlkTable overrides before Character Generation.
- Tweaks: added `NWNX_TWEAKS_RETAIN_LOCAL_VARIABLES_ON_ITEM_SPLIT` to retain local variables when an item is split.
- Tweaks: added `NWNX_TWEAKS_PREVENT_ATTACK_BONUS_BYPASSING_REDUCTION` to make attack bonuses not bypass reductions (soak).

##### New Plugins
- NoStack: Adds `NWNX_NOSTACK_*` variables to control ability, skill, attack and/or saving throw bonuses stacking

##### New NWScript Functions
- Creature: Get{Armor|Shield}CheckPenalty()
- Creature: {Get/Set}BypassEffectImmunity()
- Creature: SetLastKiller()
- Effect: GetTrueEffectCount()
- Effect: GetTrueEffect()
- Effect: RemoveEffectById()
- Effect: ReplaceEffectByIndex()
- Effect: Apply()
- Player: SetTlkOverride()
- Util: GetTTY()

### Changed
- The argument stack is now cleared after every NWNX function call.
- Effect: (Un)PackEffect functions now can retrieve the id and Item Property Source. _**ABI breaking:** You will need to update nwnx_effect.nss if you are using these functions_.
- Events: `NWNX_ON_UNPOSSESS_FAMILIAR_*` is now skippable.
- ItemProperty: UnpackIP now can retrieve the item property's id. _**ABI breaking:** You will need to update nwnx_itemprop.nss if you are using these functions_.
- ***API BREAKING*** Damage: The NWNX_Damage_AttackEventData fields have changed their names: `iAttackType -> iWeaponAttackType`, `iAttackType_REAL -> iAttackType`.
- ***API BREAKING*** Object: The `NWNX_Object_Export` function has had its arguments reordered.
- ***ABI BREAKING:*** `nwnx.nss` has changed, please update all your `nwnx_*.nss` scripts including `nwnx.nss` and recompile. Existing compiled scripts will still work.

### Removed
- Data and Time plugins have been removed. Compatibility scripts are provided [here](Compatibility/)
- ***API BREAKING*** Events: removed deprecated `NWNX_ON_{ENTER|EXIT}_STEALTH_*` events. Use `NWNX_ON_STEALTH_{ENTER|EXIT}_*`
- Tweaks: removed deprecated `NWNX_TWEAKS_HIDE_DMS_ON_CHAR_LIST` environment variable. Use `NWNX_TWEAKS_HIDE_PLAYERS_ON_CHAR_LIST`

### Fixed
- Race: Effects vs Child Races are now functional. Battle Training Vs. * feats now apply their bonus against child races as well.

## 8193.20
https://github.com/nwnxee/unified/compare/build8193.20...build8193.21

### Added
- Events: added `NWNX_ON_INPUT_EMOTE_*` events to InputEvents, this event fires when a player uses a radial menu emote.
- Events: added `NWNX_ON_COMBAT_DR_BROKEN_*` events to CombatEvents, this event fires when a creature's limited Damage{Resistance|Reduction} gets broken.
- Events: added `NWNX_ON_UNPOSSESS_FAMILIAR_*` events to AssociateEvents, this event fires when a player unpossesses a familiar.
- Experimental: Added `NWNX_EXPERIMENTAL_DISABLE_LEVELUP_VALIDATION` to disable levelup validation.
- Experimental: Added `NWNX_EXPERIMENTAL_UNHARDCODE_RANGER_DUALWIELD` to remove the hardcoded effects of the Ranger's Dual-wield feat. This functionality is not compatible with the NWNX_ON_HAS_FEAT_* event.
- Tweaks: Added `NWNX_TWEAKS_ALWAYS_RETURN_FULL_DEX_STAT` to have GetDEXStat() always return a creature's full dexterity stat.
- Tweaks: added `NWNX_TWEAKS_DISPLAY_NUM_ATTACKS_OVERRIDE_IN_CHARACTER_SHEET` to display the correct amount of attacks per round on the character sheet when overridden with SetBaseAttackBonus()
- Tweaks: added `NWNX_TWEAKS_TURD_BY_CDKEY` to associate TURDs by CDKey/CharacterName instead of PlayerName/CharacterName. Note: pass the CDKey instead of PlayerName when calling NWNX_Administration_DeleteTURD().
- DotNET: Added native function hook support.
- Optimizations: Added `LuoLookup` optimization that speeds up per-player object updates.
- Optimizations: Added `PlayerLookup` optimization that speeds up some player related functions on highly populated servers.

##### New Plugins
- SWIG: Native Interop support added for DotNET.

##### New NWScript Functions
- Admin: {Get/Set}MinLevel()
- Admin: {Get/Set}MaxLevel()
- Area: GetAmbientSound{Day/Night}()
- Area: GetAmbientSound{Day/Night}Volume
- Area: CreateSoundObject()
- Creature: ComputeSafeLocation()
- Creature: DoPerceptionUpdateOnCreature()
- Creature: {Get/Set}PersonalSpace()
- Creature: {Get/Set}CreaturePersonalSpace()
- Creature: {Get/Set}Height()
- Creature: {Get/Set}HitDistance()
- Creature: {Get/Set}PreferredAttackDistance()
- Encounter: GetGeometry()
- Encounter: SetGeometry()
- Encounter: {Get/Set}CanReset()
- Object: {Get|Set}AILevel()
- Object: {Get|Set}MapNote()
- Util: GetInstructionLimit()
- Util: {Get|Set}InstructionsExecuted()
- Util: GetHighResTimeStamp() (in preparation for removing the now deprecated NWNX_Time)
- Weapon: SetMaxRangedAttackDistanceOverride()

### Changed
- Creature: Functions for CriticalMultipler and CriticalRange extended to allow declaration of nBaseItem. Order of Overrides is Specified Baseitem > Specified Hand > non-Specified. Modifiers now apply in addition to overrides (rather than only in the absence of overrides). _**ABI breaking:** You will need to update nwnx_creature.nss if you are using these functions_.
- Damage: added `iAttackType_REAL` and `bKillingBlow` to the `AttackEventData` struct. Updated struct documentation.
- Race: SetFavoredEnemyFeat() now supports multiple feats per race.
- Rename: NWNX_Rename can now co-exist with `NWNX_TWEAKS_HIDE_CLASSES_ON_CHAR_LIST`, as such NWNX_Rename's handling of said tweak has been removed.
- Optimizations: `GameObjectLookup` no longer reads nwn config for cache size, and instead just assumes 1 million (uses 64MB RAM).

### Deprecated
- Data: The NWNX_Data array implementation is deprecated. SQLite implementation available.  Shim include file provided for compatibility.
- Time: The NWNX_Time implementation is deprecated. A SQLite implementation is now in use. The include file inc_sqlite_time is provided.

### Fixed
- Feedback: Fixed a memory leak when suppressing messages.
- Utils: Fixed a memory corruption in `GetAsciiTableString()`

## 8193.16
https://github.com/nwnxee/unified/compare/build8193.16...build8193.20

### Added
- Chat: targeted messages can now be sent on the Party or DM channels
- Core: log file and crash dumps now include version and commit sha information
- Core: added support for cp1251 (Central European) locale
- Events: added skippable Acquire events to ItemEvents
- Events: added skippable Disarm event to CombatEvents
- Events: added `ACTION_RESULT` to Feat/Skill/Lock events for use in the _AFTER
- Events: added Spell Interruption events to SpellEvents
- Events: added skippable Has Feat event to FeatEvents
- Events: added Journal Open/Close events to JournalEvents
- Events: added Detect Mode event to StealthEvents
- Events: added Combat Enter/Exit events to CombatEvents
- Events: Stealth Mode can now bypass or perform Hide in Plain Sight with return values of "0" or "1" respectively
- Events: Added Skippable/Result Changeable Faction Reputation event to FactionEvents
- Experimental: Added `NWNX_EXPERIMENTAL_ADJUST_REPUTATION_FIX` in an effort to correct a crash with factions/reputation
- Tweaks: `NWNX_TWEAKS_HIDE_PLAYERS_ON_CHAR_LIST`
- Tweaks: `NWNX_TWEAKS_FIX_ARMOR_DEX_BONUS_UNDER_ONE`
- Tweaks: `NWNX_TWEAKS_FIX_ITEM_NULLPTR_IN_CITEMREPOSITORY`
- Tweaks: `NWNX_TWEAKS_CLEAR_SPELL_EFFECTS_ON_TURDS`

##### New Plugins
The following plugins were added:
- Feat: Allows to define a variety of effects that are granted to feat holders.
- Tileset: An advanced plugin that exposes additional tileset and tile properties and allows builders to override the tiles of an area created with CreateArea().
- Diagnostics: Plugin exposing diagnostic facilities to help server debugging.

##### New NWScript Functions
- Area: GetTileInfo()
- Area: ExportARE()
- Creature: {Get|Set}WalkAnimation()
- Creature: SetAttackRollOverride()
- Creature: SetParryAllAttacks()
- Creature: {Get|Set}NoPermanentDeath()
- Events: ToggleIDWhitelist()
- Events: AddIDToWhitelist()
- Events: RemoveIDFromWhitelist()
- Feat: SetFeatModifier()
- Object: GetCurrentAnimation()
- Player: AddCustomJournalEntry() and GetJournalEntry()
- Player: CloseStore()
- Race: SetFavoredEnemyFeat()
- Util: GetScriptParamIsSet()
- Util: SetDawnHour()
- Util: SetDuskHour()

### Changed
- Area: ExportGIT() now supports valid custom resource directory aliases.
- DotNET: Upgraded to Dotnet-5.
- Events: `NWNX_ON_DM_SPAWN_OBJECT_*` now provides the resref as event data.
- Events: `NWNX_ON_STORE_REQUEST_*_AFTER` now provides the result as event data.
- Events: ResourceEvents now support valid custom resource directory aliases.
- Util: added an optional appearance type parameter to CreateDoor()
- Util: AddScript(), AddNSSFile() and RemoveNWNXResourceFile() now support valid custom resource directory aliases.
- Visibility: added two new visibility types to always show an object regardless of range.
- Weapon: Good Aim Feat now takes value from ruleset.2da
- We now only allow builds with the `CMAKE_BUILD_TYPE=RelWithDebInfo` configuration. `Debug` builds produce unexpected behaviour and `Release` builds are generally unnecessary and mess with Assert functionality.

### Deprecated
- Events: Stealth Events have had their name changed from NWNX_ON_{ENTER|EXIT}_STEALTH_* to NWNX_ON_STEALTH_{ENTER|EXIT}_*. Please update your scripts as the old names will eventually be removed.
- Tweaks: `NWNX_TWEAKS_HIDE_DMS_ON_CHAR_LIST` has been deprecated, use `NWNX_TWEAKS_HIDE_PLAYERS_ON_CHAR_LIST` now

### Removed
- Optimizations: `OBJECT_TAG_LOOKUP` optimization has been removed. It caused instability and didn't really improve perf.

### Fixed
- Administration: fix crash in DeletePlayerCharacter()
- Core: debug dumps now properly resolve nwserver functions regardless of path and binary name used
- Creature: removed an unnecessary free() in GetMeetsFeatRequirements() that may have led to crashes
- Events: fixed a nullptr deref crash in BarterEvents
- Events: fixed a nullptr deref crash in the AcquireItem event
- Feedback: fixed a bug where global combatlog and journal feedback message overrides couldn't be removed
- MaxLevel: fixed bug interfering with leveling down NPCs
- MaxLevel: fixed an issue with the plugin failing after a restart when reload-when-empty was set to true
- Object: fixed a possible crash in CheckFit()
- Player: fixed bic getting overwritten when using PossessCreature() and crashing in between areas
- Race: fixed effect clean up after level up
- Rename: community name only obfuscates once a server reset
- Rename: properly updates original name if NWNX_Creature_SetOriginalName() is used
- SkillRanks: fixed skill bonus for abilities not properly calculating when ability scores were negative
- Weapon: fixed bug in SetGreaterWeaponFocusFeat()
- Weapon: fixed bug in offhand attack and damage bonus calculations with Greater Weapon feats and two handed weapons

## 8193.16
https://github.com/nwnxee/unified/compare/build8193.13...build8193.16

### Added
- Core: added environment variable `NWNX_CORE_CUSTOM_RESMAN_DEFINITION` to specify a file with additional resource directories.
- Events: added skippable PlayerDM Login/Logout events to DMActionEvents
- Events: added skippable RunScript and RunScriptChunk events to DebugEvents
- Events: added skippable RequestBuy/Sell events to StoreEvents
- Events: added skippable Heal events to new HealingEvents
- Events: added ServerSendArea event to ClientEvents
- Tweaks: added `NWNX_TWEAKS_BLOCK_DM_SPAWNITEM` to block the usage of dm_spawnitem
- Weapon: added 'NWNX_WEAPON_GOOD_AIM_SLING' non-halfling sling users with the feat Good Aim gain an additional +1 AB as a halfling currently does. Note: Throwing weapons are already included in the base game

##### New NWScript Functions
- Area: AddObjectToExclusionList()
- Area: RemoveObjectFromExclusionList()
- Area: ExportGIT()
- Creature: {Get|Set}Encounter()
- Creature: SetEffectIconFlashing()
- Creature: OverrideDamageLevel()
- Creature: GetIsBartering()
- Creature: {Get|Set}LastItemCasterLeve()
- Creature: GetArmorClassVersus()
- Effect: ReplaceEffect()
- Player: ToggleDM()
- ItemProperty: GetActiveProperty()
- Object: DoSpellImmunity()
- Object: DoSpellLevelAbsorption()
- Object: SetHasInventory()
- Player: SetObjectMouseCursorOverride()
- Player: SetObjectHiliteColorOverride()
- Player: RemoveEffectFromTURD()
- Player: SetSpawnLocation()
- Player: SendDMAllCreatorLists()
- Util: GetWorldTime()
- Util: {Get|Set}ResourceOverride()
- Weapon: {Get|Set}OneHalfStrength()

### Changed
- Administration: added an optional sKickReason parameter to DeleteCharacter()
- Damage: damage event script now also triggered by damage to placeables
- Effect: (Un)PackEffect now supports vector params
- Events: added a `RESULT` event data tag to LearnScroll in ItemEvents
- Weapon: SetWeapon****Feat functions may be called multiple times for the same weapon, associating a new feat each time
- Weapon: weapon feats defined in the 2da are no longer overridden by SetWeapon****Feat and will be used in addition to any set feats

### Deprecated
- Object: StringToObject();

### Removed
- Creature: {Get|Set}{ClericDomain|WizardSpecialization}()
- Creature: SetAbilityScore()
- Object: {Get|Set|Delete}Persistent{Int|String|Float}()

### Fixed
- Administration: DeletePlayerCharacter() now deletes the TURD as well
- Creature: SetMovementRate() now properly reattaches the creature's legs when switching from NWNX_CREATURE_MOVEMENT_RATE_IMMOBILE to the other constants

## 8193.14
https://github.com/nwnxee/unified/compare/build8193.13...build8193.14

### Added
- ServerLogRedirector: added environment variable `NWNX_SERVERLOGREDIRECTOR_HIDE_VALIDATEGFFRESOURCE_MESSAGES` to hide `*** ValidateGFFResource sent by user.` messages from the NWNX log.
- Events: added BroadcastSpellCast event to SpellEvents
- Events: added TogglePause to InputEvents
- Tweaks: added `NWNX_TWEAKS_FIX_UNLIMITED_POTIONS_BUG` to prevent the unlimited potions/scrolls bug.
- Tweaks: added `NWNX_TWEAKS_UNHARDCODE_SHIELDS` to change shield AC and create new shield-like items using the BaseAC column in baseitems.2da.

##### New NWScript Functions
- Creature: {Get|Set}CriticalMultiplier{Modifier|Override}() and {Get|Set}CriticalRange{Modifier|Override}()
- Creature: AddAssociate()
- Encounter: GetNumberOfSpawnPoints()
- Encounter: GetSpawnPointByIndex()
- Encounter: GetMinNumSpawned()
- Encounter: GetMaxNumSpawned()
- Encounter: GetCurrentNumSpawned()
- Object: GetDoorHasVisibleModel()
- Object: GetIsDestroyable()
- Object: GetCurrentHitPoints()
- Player: SetCustomToken()
- Player: SetCreatureNameOverride()
- Player: FloatingTextStringOnCreature();
- Util: CreateDoor()
- Util: SetItemActivator()

### Changed
- Object: SetPosition() now has a toggle(default true) to update subareas if oObject is a creature, this means any traps/triggers at the new position will fire their events.
- Object: `GetLocalVariable()` behavior has changed. See function documentation for details.
- Profiler: Corrected a typo preventing the retrieval of certain event data (OVERHEAD_COMPENSTION_FORCE -> OVERHEAD_COMPENSATION_FORCE). Note: breaking change.

### Fixed
- Core: fixed NWNX ResourceDirectory init crashing on failed module load
- ELC: fixed ELC not respecting `CHARGEN_BASE_ABILITY_*` ruleset.2da values
- Weapon: fixed a nullptr reference crash in GetEpicWeaponDevastatingCritical()
- Player: fixed possessed associates from losing their associate type on unpossess

## 8193.13
https://github.com/nwnxee/unified/compare/build8193.12...build8193.13

### Added

##### New NWScript Functions
- Creature: JumpToLimbo()

### Fixed
- SkillRanks: Now respects ruleset.2da values.

## 8193.12
https://github.com/nwnxee/unified/compare/build8193.11...build8193.12

### Added
- Events: added QuickbarSetButton event to QuickbarEvents
- Events: added Calendar events for change in Hour, Day, Month, Year, and Dawn/Dusk.
- Tweaks: `NWNX_TWEAKS_FIX_DISPEL_EFFECT_LEVELS` to enable a fix for effects losing the caster level vs. dispel checks when the effect creator is deleted.
- Tweaks: `NWNX_TWEAKS_ADD_PRESTIGECLASS_CASTER_LEVELS` to automatically add caster levels from prestige classes based on the {Arc|Div}SpellLvlMod columns in classes.2da

##### New NWScript Functions
- Creature: GetFlatFooted()
- Creature: {Serialize|Deserialize}Quickbar()
- Creature: {Get|Set}CasterLevelModifier() and {Get|Set}CasterLevelOverride()
- Object: ClearSpellEffectsOnOthers()
- Object: PeekUUID()

### Changed
- ELC: Updated with recent changes.

## 8193.11
https://github.com/nwnxee/unified/compare/build8193.10...build8193.11

### Added
- Events: Added Keyboard Input event to InputEvents
- Events: Added Use Item validation event to allow control of item use restrictions, and unusable red inventory highlight.
- Events: Added Equip Item validation event to allow control of item equip restrictions.
- Events: Added OnExportCharacter event to ClientEvents

### Changed
- Events: "You cannot use that item" feedback can now be suppressed for skipped Use Item events by setting the event result to 1
- Rename: Added the environment variable `NWNX_RENAME_OVERWRITE_DISPLAY_NAME` to control whether display names should be overwritten globally (for scripts and DMs) when global override is set. Then new default is now `false`, meaning that global overrides are only applied to players, and DMs and scripts see the original name by default.
- Core: Stack traces will now resolve base game functions

### Fixed
- MaxLevel: Fixed a crash when a PC had exactly 41 levels in bard/sorcerer.
- Player: NWNX_Player_SetPlaceableNameOverride() once again updates in realtime.

## 8193.10
https://github.com/nwnxee/unified/compare/build8193.9...build8193.10

### Added
- SQL: Added optional support for object storage in binary fields via an optional parameter `base64` in `NWNX_SQL_PreparedObjectFull` and `NWNX_SQL_ReadFullObjectInActiveRow`
- Events: Added OnServerCharacterSave events to ClientEvents. Called when a server vault character will be saved either manually, or when the server saves/exits.
- ELC: Added `NWNX_ON_ELC_VALIDATE_CHARACTER_{BEFORE|AFTER}` events, can be subscribed to with NWNX_Events.
- Events: Added skippable CastSpell event to InputEvents, the WalkToWayPoint and AttackObject events are also skippable now

##### New NWScript Functions
- Creature: GetFeatGrantLevel()
- Object: GetInternalObjectType()
- Util: GetUserDirectory()
- Util: PluginExists()
- Util: GetScriptReturnValue()
- Object: AcquireItem()
- Object: SetFacing()

### Deprecated
- Creature: Get{Domain|Specialization}

## 8193.9
https://github.com/nwnxee/unified/compare/build8193.7...build8193.9

### Added
- SQL: `NWNX_SQL_PORT` to set the port used for MySQL database connections.
- Events: Added OnResource{Added|Removed|Modified} events to ResourceEvents, these events fire when a file gets added/removed/modified in the /nwnx or /development folders

##### New NWScript Functions
- Administration: GetServerName()
- Events: UnsubscribeEvent()
- Creature: Get|SetFaction()
- Util: (Un)RegisterServerConsoleCommand()
- Area: GetTileModuleResRef()

### Changed
- Core: the console commands `eval` and `evalx` will now provide an error message if the script chunk fails to execute.
- Damage: Added a Ranged flag to NWNX_Damage_DealDamage()

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
