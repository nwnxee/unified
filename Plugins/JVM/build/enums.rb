Enums = {
  'CreaturePart' => {
    0 => 'RightFootPart', 1 => 'LeftFootPart', 2 => 'RightShinPart', 3 =>
    'LeftShinPart', 4 => 'LeftThighPart', 5 => 'RightThighPart', 6 =>
    'PelvisPart', 7 => 'TorsoPart', 8 => 'BeltPart', 9 => 'NeckPart', 10 =>
    'RightForearmPart', 11 => 'LeftForearmPart', 12 => 'RightBicepPart', 13 =>
    'LeftBicepPart', 14 => 'RightShoulderPart', 15 => 'LeftShoulderPart', 16 =>
    'RightHandPart', 17 => 'LeftHandPart', 20 => 'HeadPart', },
  'IPMiscImmunityType' => {
    0 => 'BackstabIPImmunity', 1 => 'LevelAbilDrainIPImmunity', 2 =>
    'MindSpellsIPImmunity', 3 => 'PoisonIPImmunity', 4 => 'DiseaseIPImmunity', 5 =>
    'FearIPImmunity', 6 => 'KnockdownIPImmunity', 7 => 'ParalysisIPImmunity', 8 =>
    'CriticalHitsIPImmunity', 9 => 'DeathMagicIPImmunity', },
  'ImmunityType' => {
    0 => 'NoneImmunity', 1 => 'MindSpellsImmunity', 2 => 'PoisonImmunity', 3 =>
    'DiseaseImmunity', 4 => 'FearImmunity', 5 => 'TrapImmunity', 6 =>
    'ParalysisImmunity', 7 => 'BlindnessImmunity', 8 => 'DeafnessImmunity',
    9 => 'SlowImmunity', 10 => 'EntangleImmunity', 11 => 'SilenceImmunity', 12 =>
    'StunImmunity', 13 => 'SleepImmunity', 14 => 'CharmImmunity', 15 =>
    'DominateImmunity', 16 => 'ConfusedImmunity', 17 => 'CursedImmunity', 18 =>
    'DazedImmunity', 19 => 'AbilityDecreaseImmunity', 20 =>
    'AttackDecreaseImmunity', 21 => 'DamageDecreaseImmunity', 22 =>
    'DamageImmunityDecreaseImmunity', 23 => 'AcDecreaseImmunity', 24 =>
    'MovementSpeedDecreaseImmunity', 25 => 'SavingThrowDecreaseImmunity', 26 =>
    'SpellResistanceDecreaseImmunity', 27 => 'SkillDecreaseImmunity', 28 =>
    'KnockdownImmunity', 29 => 'NegativeLevelImmunity', 30 =>
    'SneakAttackImmunity', 31 => 'CriticalHitImmunity', 32 => 'DeathImmunity', },
  'AttackBonus' => { 0 => 'MiscBonus', 1 => 'OnhandBonus', 2 => 'OffhandBonus', },
  'AILevel' => { -1 => 'DefaultAI', 0 => 'VeryLowAI', 1 => 'LowAI', 2 => 'NormalAI', 3 => 'HighAI', 4 => 'VeryHighAI' },
  'ACModifyType' => { 0 => 'ACDodgeBonus', 1 => 'ACNaturalBonus', 2 => 'ACArmorEnchantmentBonus', 3 => 'ACShieldEnchantmentBonus',
    4 => 'ACDeflectionBonus' },
  'DamageType'   => {1 => 'BludgeoningDamage', 2 => 'PiercingDamage', 4 => 'SlashingDamage', 8 => 'MagicalDamage',
    16 => 'AcidDamage', 32 => 'ColdDamage', 64 => 'DivineDamage', 128 => 'ElectricalDamage', 256 => 'FireDamage',
    512 => 'NegativeDamage', 1024 => 'PositiveDamage', 2048 => 'SonicDamage', 4096 => 'BaseDamage', 4103 => 'ACVsAllDamage' },
  'IPDamageType'   => {0 => 'BludgeoningIPDamage', 1 => 'PiercingIPDamage', 2 => 'SlashingIPDamage', 3 => 'SubdualIPDamage',
    4 => 'PhysicalIPDamage', 5 => 'MagicalIPDamage', 6 => 'AcidIPDamage', 7 => 'ColdIPDamage', 8 => 'DivineIPDamage',
    9 => 'ElectricalIPDamage', 10 => 'FireIPDamage', 11 => 'NegativeIPDamage', 12 => 'PositiveIPDamage', 13 => 'SonicIPDamage',
   },
  'DamagePower' => {
    0 => 'NormalDamage', 1 => 'PlusOneDamage', 2 => 'PlusTwoDamage', 3 => 'PlusThreeDamage',
    4 => 'PlusFourDamage', 5 => 'PlusFiveDamage', 6 => 'EnergyDamage', 7 => 'PlusSixDamage',
    8 => 'PlusSevenDamage', 9 => 'PlusEightDamage', 10 => 'PlusNineDamage', 11 => 'PlusTenDamage',
    12 => 'PlusElevenDamage', 13 => 'PlusTwelveDamage', 14 => 'PlusThirteenDamage', 15 => 'PlusFourteenDamage',
    16 => 'PlusFifteenDamage', 17 => 'PlusSixteenDamage', 18 => 'PlusSeventeenDamage',
    19 => 'PlusEighteenDamage', 20 => 'PlusNinteenDamage', 21 => 'PlusTwentyDamage'
  },
  #'DamageBonus' => {
  #  1 => 'OneBonus', 2 => 'TwoBonus', 3 => 'ThreeBonus', 4 => 'FourBonus', 5 => 'FiveBonus',
  #  6 => 'Bonus1d4',
  #},

  'TrapType' => {
    0 => 'MinorSpikeTrap', 1 => 'AverageSpikeTrap', 2 => 'StrongSpikeTrap', 3 => 'DeadlySpikeTrap',
    4 => 'MinorHolyTrap', 5 => 'AverageHolyTrap', 6 => 'StrongHolyTrap', 7 => 'DeadlyHolyTrap',
    8 => 'MinorTangleTrap', 9 => 'AverageTangleTrap', 10 => 'StrongTangleTrap', 11 => 'DeadlyTangleTrap',
    12 => 'MinorAcidTrap', 13 => 'AverageAcidTrap', 14 => 'StrongAcidTrap', 15 => 'DeadlyAcidTrap', 16 => 'MinorFireTrap',
    17 => 'AverageFireTrap', 18 => 'StrongFireTrap', 19 => 'DeadlyFireTrap', 20 => 'MinorElectricalTrap',
    21 => 'AverageElectricalTrap', 22 => 'StrongElectricalTrap', 23 => 'DeadlyElectricalTrap', 24 => 'MinorGasTrap',
    25 => 'AverageGasTrap', 26 => 'StrongGasTrap', 27 => 'DeadlyGasTrap', 28 => 'MinorFrostTrap', 29 => 'AverageFrostTrap',
    30 => 'StrongFrostTrap', 31 => 'DeadlyFrostTrap', 32 => 'MinorNegativeTrap', 33 => 'AverageNegativeTrap',
    34 => 'StrongNegativeTrap', 35 => 'DeadlyNegativeTrap', 36 => 'MinorSonicTrap', 37 => 'AverageSonicTrap',
    38 => 'StrongSonicTrap', 39 => 'DeadlySonicTrap', 40 => 'MinorAcidSplashTrap', 41 => 'AverageAcidSplashTrap',
    42 => 'StrongAcidSplashTrap', 43 => 'DeadlyAcidSplashTrap', 44 => 'EpicElectricalTrap', 45 => 'EpicFireTrap',
    46 => 'EpicFrostTrap', 47 => 'EpicSonicTrap'
  },
  'IPTrapType' => {
    1 => 'SpikeIPTrap', 2 => 'HolyIPTrap', 3 => 'TangleIPTrap', 4 => 'BlobOfAcidIPTrap', 5 => 'FireIPTrap',
    6 => 'ElectricalIPTrap', 7 => 'GasIPTrap', 8 => 'FrostIPTrap', 9 => 'AcidSplashIPTrap',
    10 => 'SonicIPTrap', 11 => 'NegativeIPTrap',
  },

  'Alignment'    => {0 => 'Any', 1 => 'Neutral', 2 => 'Lawful', 3 => 'Chaotic', 4 => 'Good', 5 => 'Evil'},
  'IPAlignment' => { 0 => 'LgAlignment', 1 => 'LnAlignment', 2 => 'LeAlignment', 3 => 'NgAlignment',
    4 => 'TnAlignment', 5 => 'NeAlignment', 6 => 'CgAlignment', 7 => 'CnAlignment', 8 => 'CeAlignment' },
  'IPAlignGroup' => { 0 => 'AllAlignGroup', 1 => 'NeutralAlignGroup', 2 => 'LawfulAlignGroup',
    3 => 'ChaoticAlignGroup', 4 => 'GoodAlignGroup', 5 => 'EvilAlignGroup' },
  'MissChanceType' => { 0 => 'MissChanceVSAll', 1=> 'MissChanceVSRanged', 2=> 'MissChanceVSMelee' },
  'SpellSchool' => {
    "GeneralSchool" => 0, "AbjurationSchool" => 1, "ConjurationSchool" => 2, "DivinationSchool" => 3, "EnchantmentSchool" => 4,
    "EvocationSchool" => 5, "IllusionSchool" => 6, "NecromancySchool" => 7, "TransmutationSchool" => 8,
  }.invert,
  'IPSpellSchool' => {
    0 => 'AbjurationIPSchool', 1 => 'ConjurationIPSchool', 2 =>
    'DivinationIPSchool', 3 => 'EnchantmentIPSchool', 4 => 'EvocationIPSchool',
    5 => 'IllusionIPSchool', 6 => 'NecromancyIPSchool', 7 => 'TransmutationIPSchool', },
  'Ability' => { 0 => 'Strength', 1 => 'Dexterity', 2 => 'Constitution', 3 => 'Intelligence', 4 => 'Wisdom', 5 => 'Charisma' },
  'ActionMode' => {0 => 'DetectMode', 1 => 'StealthMode', 2 => 'ParryMode', 3 => 'PowerAttackMode',
    4 => 'ImprovedPowerAttackMode', 5 => 'CounterspellMode', 6 => 'FlurryOfBlowsMode',
    7 => 'RapidShotMode', 8 => 'ExpertiseMode', 9 => 'ImprovedExpertiseMode', 10 => 'DefensiveCastMode',
    11 => 'DirtyFightingMode' },
  'Action' => {
    0 => 'MoveToPointAction', 1 => 'PickupItemAction', 2 => 'DropItemAction', 3 => 'AttackObjectAction',
    4 => 'CastSpellAction', 5 => 'OpenDoorAction', 6 => 'CloseDoorAction', 7 => 'DialogObjectAction',
    8 => 'DisableTrapAction', 9 => 'RecoverTrapAction', 10 => 'FlagTrapAction', 11 => 'ExamineTrapAction',
    12 => 'SetTrapAction', 13 => 'OpenLockAction', 14 => 'LockAction', 15 => 'UseObjectAction',
    16 => 'AnimalEmpathyAction', 17 => 'RestAction', 18 => 'TauntAction', 19 => 'ItemCastSpellAction',
    31 => 'CounterSpellAction', 33 => 'HealAction', 34 => 'PickpocketAction', 35 => 'FollowAction',
    36 => 'WaitAction', 37 => 'SitAction', 40 => 'SmiteGoodAction', 41 => 'KIDamageAction',
    43 => 'RandomWalkAction', 65535  => 'InvalidAction',
  },
  'AttackResult' => { 0 => 'MissedAttack', 1 => 'HitAttack', 2 => 'CriticalHitAttack' },
  'SavingThrowResult' => { 0 => 'FailedRoll', 1 => 'SucceededRoll', 3 => 'ImmuneToSaveType' },
  'SpecialAttack' => {
    0 => 'InvalidSpecialAttack', 1 => 'CalledShotLegSpecialAttack', 2 => 'CalledShotArmSpecialAttack',
    3 => 'SapSpecialAttack', 4 => 'DisarmSpecialAttack', 5 => 'ImprovedDisarmSpecialAttack',
    6 => 'KnockdownSpecialAttack', 7 => 'ImprovedKnockdownSpecialAttack', 8 => 'StunningFistSpecialAttack',
    9 => 'FlurryOfBlowsSpecialAttack', 10 => 'RapidShotSpecialAttack',
  },
  'CombatMode' => {
    0 => 'InvalidCombatMode', 1 => 'ParryCombatMode', 2 => 'PowerAttackCombatMode',
    3 => 'ImprovedPowerAttackCombatMode', 4 => 'FlurryOfBlowsCombatMode', 5 => 'RapidShotCombatMode',
    6 => 'ExpertiseCombatMode', 7 => 'ImprovedExpertiseCombatMode', 8 => 'DefensiveCastingCombatMode',
    9 => 'DirtyFightingCombatMode', 10 => 'DefensiveStanceCombatMode',
  },
  'AssociateType' => {
    0 => 'NoAssociate', 1 => 'HenchmanAssociate', 2 => 'AnimalCompanionAssociate',
    3 => 'FamiliarAssociate', 4 => 'SummonedAssociate', 5 => 'DominatedAssociate',
  },
  'AssociateCommand' => {
    -2 => 'StandGroundCommand', -3 => 'AttackNearestCommand', -4 => 'HealMasterCommand', -5 => 'FollowMasterCommand',
    -6 => 'MasterFailedLockpickCommand', -7 => 'GuardMasterCommand', -8 => 'UnsummonFamiliarCommand',
    -9 => 'UnsummonAnimalCompanionCommand', -10 => 'UnsummonSummonedCommand', -11 => 'MasterUnderAttackCommand',
    -12 => 'ReleaseDominationCommand', -13 => 'UnpossessFamiliarCommand', -14 => 'MasterSawTrapCommand',
    -15 => 'MasterAttackedOtherCommand', -16 => 'MasterGoingToBeAttackedCommand', -17 => 'LeavePartyCommand',
    -18 => 'PickLockCommand', -19 => 'InventoryCommand', -20 => 'DisarmTrapCommand', -21 => 'ToggleCastingCommand',
    -22 => 'ToggleStealthCommand', -23 => 'ToggleSearchCommand',
  },
  'Button'  => { 0 => 'MapButton', 1 => 'InventoryButton', 2 => 'JournalButton',
    3 => 'CharacterButton', 4 => 'OptionsButton', 5 => 'SpellsButton',
    6 => 'RestButton', 7 => 'PvPButton'
  },
  'CreatureSize' => {
    0 => 'InvalidSize', 1 => 'TinySize', 2 => 'SmallSize', 3 => 'MediumSize', 4 => 'LargeSize', 5 => 'HugeSize',
  },
  'TalkVolume'   => {0 => 'TalkVol', 1 => 'WhisperVol', 2 => 'ShoutVol',
    3 => 'SilentTalkVol', 4 => 'SilentShoutVol', 5 => 'PartyVol', 6 => 'TellVol'},
  'DurationType' => {-1 => 'InvalidDuration', 0 => 'Instant', 1 => 'Temporary', 2 => 'Permanent'},
  'ObjectType'   => {0 => 'InvalidObject', 1 => 'Creature', 2 => 'Item', 4 => 'Trigger', 8 => 'Door',
    16 => 'AOE', 32 => 'Waypoint', 64 => 'Placeable', 128 => 'Store', 256 => 'Encounter',
    32767 => 'All' },
  'ShapeType' => {0 => 'SpellCylinderShape', 1 => 'ConeShape', 2 => 'CubeShape', 3 => 'SpellConeShape',
    4 => 'SphereShape' },
  'ProjectilePathType' => {0 => 'DefaultPath', 1 => 'HomingPath', 2 => 'BallisticPath',
    3 => 'HighBallisticPath', 4 => 'AcceleratingPath' },
  'DoorAction' => {0 => 'OpenDoor', 1 => 'UnlockDoor', 2 => 'BashDoor', 3 => 'IgnoreDoor', 4 => 'KnockDoor'},
  'PlaceableAction' => {0 => 'UsePlaceable', 1 => 'UnlockPlaceable', 2 => 'BashPlaceable', 4 => 'KnockPlaceable'},
  'RacialType' => { 0 => 'DwarfRace', 1 => 'ElfRace', 2 => 'GnomeRace', 3 => 'HalflingRace',
    4 => 'HalfelfRace', 5 => 'HalforcRace', 6 => 'HumanRace', 7 => 'AberrationRace', 8 => 'AnimalRace',
    9 => 'BeastRace', 10 => 'ConstructRace', 11 => 'DragonRace', 12 => 'HumanoidGoblinoidRace',
    13 => 'HumanoidMonstrousRace', 14 => 'HumanoidOrcRace', 15 => 'HumanoidReptilianRace',
    16 => 'ElementalRace', 17 => 'FeyRace', 18 => 'GiantRace', 19 => 'MagicalBeastRace', 20 => 'OutsiderRace',
    23 => 'ShapechangerRace', 24 => 'UndeadRace', 25 => 'VerminRace', 28 => 'AllRace',
    28 => 'InvalidRace', 29 => 'OozeRace' },
  'IPRacialType' => { 0 => 'DwarfIPRace', 1 => 'ElfIPRace', 2 => 'GnomeIPRace', 3 => 'HalflingIPRace', 4 => 'HalfelfIPRace',
    5 => 'HalforcIPRace', 6 => 'HumanIPRace', 7 => 'AberrationIPRace', 8 => 'AnimalIPRace', 9 => 'BeastIPRace',
    10 => 'ConstructIPRace', 11 => 'DragonIPRace', 12 => 'HumanoidGoblinoidIPRace', 13 => 'HumanoidMonstrousIPRace',
    14 => 'HumanoidOrcIPRace', 15 => 'HumanoidReptilianIPRace', 16 => 'ElementalIPRace', 17 => 'FeyIPRace',
    18 => 'GiantIPRace', 19 => 'MagicalBeastIPRace', 20 => 'OutsiderIPRace', 23 => 'ShapechangerIPRace',
    24 => 'UndeadIPRace', 25 => 'VerminIPRace' },
  'StandardFaction' => {0 => 'Hostile', 1 => 'Commoner', 2 => 'Merchant', 3 => 'Defender'},
  'TileMainLightColor' => {
    0 => 'BlackTileMainLightColor', 1 => 'DimWhiteTileMainLightColor', 2 => 'WhiteTileMainLightColor',
    3 => 'BrightWhiteTileMainLightColor', 4 => 'PaleDarkYellowTileMainLightColor', 5 => 'DarkYellowTileMainLightColor',
    6 => 'PaleYellowTileMainLightColor', 7 => 'YellowTileMainLightColor', 8 => 'PaleDarkGreenTileMainLightColor',
    9 => 'DarkGreenTileMainLightColor', 10 => 'PaleGreenTileMainLightColor', 11 => 'GreenTileMainLightColor',
    12 => 'PaleDarkAquaTileMainLightColor', 13 => 'DarkAquaTileMainLightColor', 14 => 'PaleAquaTileMainLightColor',
    15 => 'AquaTileMainLightColor', 16 => 'PaleDarkBlueTileMainLightColor', 17 => 'DarkBlueTileMainLightColor',
    18 => 'PaleBlueTileMainLightColor', 19 => 'BlueTileMainLightColor', 20 => 'PaleDarkPurpleTileMainLightColor',
    21 => 'DarkPurpleTileMainLightColor', 22 => 'PalePurpleTileMainLightColor', 23 => 'PurpleTileMainLightColor',
    24 => 'PaleDarkRedTileMainLightColor', 25 => 'DarkRedTileMainLightColor', 26 => 'PaleRedTileMainLightColor',
    27 => 'RedTileMainLightColor', 28 => 'PaleDarkOrangeTileMainLightColor', 29 => 'DarkOrangeTileMainLightColor',
    30 => 'PaleOrangeTileMainLightColor', 31 => 'OrangeTileMainLightColor',
  },
  'TileSourceLightColor' => {
    0 => 'BlackTileSourceLightColor', 1 => 'WhiteTileSourceLightColor', 2 => 'PaleDarkYellowTileSourceLightColor',
    3 => 'PaleYellowTileSourceLightColor', 4 => 'PaleDarkGreenTileSourceLightColor', 5 => 'PaleGreenTileSourceLightColor',
    6 => 'PaleDarkAquaTileSourceLightColor', 7 => 'PaleAquaTileSourceLightColor', 8 => 'PaleDarkBlueTileSourceLightColor',
    9 => 'PaleBlueTileSourceLightColor', 10 => 'PaleDarkPurpleTileSourceLightColor', 11 => 'PalePurpleTileSourceLightColor',
    12 => 'PaleDarkRedTileSourceLightColor', 13 => 'PaleRedTileSourceLightColor', 14 => 'PaleDarkOrangeTileSourceLightColor',
    15 => 'PaleOrangeTileSourceLightColor',
  },
  'SaveType' => {
    0 => 'AllOrNoneSaveType', 1 => 'MindSpellsSaveType', 2 => 'PoisonSaveType',
    3 => 'DiseaseSaveType', 4 => 'FearSaveType', 5 => 'SonicSaveType', 6 => 'AcidSaveType', 7 => 'FireSaveType',
    8 => 'ElectricitySaveType', 9 => 'PositiveSaveType', 10 => 'NegativeSaveType', 11 => 'DeathSaveType',
    12 => 'ColdSaveType', 13 => 'DivineSaveType', 14 => 'TrapSaveType', 15 => 'SpellSaveType', 16 => 'GoodSaveType',
    17 => 'EvilSaveType', 18 => 'LawSaveType', 19 => 'ChaosSaveType',
  },
  'Weather' => {
    -1 => 'InvalidWeather', 0 => 'ClearWeather', 1 => 'RainWeather', 2 => 'SnowWeather', 3 => 'AreaDefaultsWeather',
  },
  'MetaMagic' => {
    'CATCHALL' => 'InvalidMeta',
    0 => 'NoneMeta', 1 => 'EmpowerMeta', 2 => 'ExtendMeta', 4 => 'MaximizeMeta', 8 => 'QuickenMeta', 16 => 'SilentMeta',
    32 => 'StillMeta', 255 => 'AnyMeta',
  },
  'Gender' => {
    0 => 'MaleGender', 1 => 'Female', 2 => 'BothGender', 3 => 'OtherGender', 4 => 'NoneGender',
  },
  'InventorySlot' => {
    0 => 'HeadSlot', 1 => 'ChestSlot', 2 => 'BootsSlot', 3 => 'ArmsSlot', 4 => 'RighthandSlot', 5 => 'LefthandSlot',
    6 => 'CloakSlot', 7 => 'LeftringSlot', 8 => 'RightringSlot', 9 => 'NeckSlot', 10 => 'BeltSlot', 11 => 'ArrowsSlot',
    12 => 'BulletsSlot', 13 => 'BoltsSlot', 14 => 'CreatureLefthandSlot', 15 => 'CreatureRighthandSlot',
    16 => 'CreatureBiteSlot', 17 => 'CreatureArmorSlot',
  },

  'EffectState' => {
    1 => 'CharmedState', 2 => 'ConfusedState', 3 => 'FrightenedState', 4 =>
    'TurnedState', 5 => 'DazedState', 6 => 'StunnedState', 7 =>
    'DominatedState', 8 => 'ParalyzeState', 9 => 'SleepState'
  },

  'EffectSubType' => {
    0 => 'InvalidSubType', 8 => 'MagicalSubType', 16 => 'SupernaturalSubType', 24 => 'ExtraordinarySubType',
  },
  'EffectTrueType' => {
    0 => 'InvalidEffectType', 1 => 'HasteEffectType', 2 =>
    'DamageResistanceEffectType', 3 => 'SlowEffectType', 4 =>
    'ResurrectionEffectType', 5 => 'DiseaseEffectType', 6 =>
    'SummonCreatureEffectType', 7 => 'RegenerateEffectType', 8 =>
    'SetStateEffectType', 9 => 'SetStateInternalEffectType', 10 =>
    'AttackIncreaseEffectType', 11 => 'AttackDecreaseEffectType', 12 =>
    'DamageReductionEffectType', 13 => 'DamageIncreaseEffectType', 14 =>
    'DamageDecreaseEffectType', 15 => 'TemporaryHitpointsEffectType', 16 =>
    'DamageImmunityIncreaseEffectType', 17 =>
    'DamageImmunityDecreaseEffectType', 18 => 'EntangleEffectType', 19 =>
    'DeathEffectType', 20 => 'KnockdownEffectType', 21 => 'DeafEffectType',
    22 => 'ImmunityEffectType', 23 => 'SetAIStateEffectType', 24 =>
    'EnemyAttackBonusEffectType', 25 => 'ArcaneSpellFailureEffectType', 26 =>
    'SavingThrowIncreaseEffectType', 27 => 'SavingThrowDecreaseEffectType',
    28 => 'MovementSpeedIncreaseEffectType', 29 =>
    'MovementSpeedDecreaseEffectType', 30 => 'VisualEffectType', 31 =>
    'AOEEffectType', 32 => 'BeamEffectType', 33 =>
    'SpellResistanceIncreaseEffectType', 34 =>
    'SpellResistanceDecreaseEffectType', 35 => 'PoisonEffectType', 36 =>
    'AbilityIncreaseEffectType', 37 => 'AbilityDecreaseEffectType', 38 =>
    'DamageEffectType', 39 => 'HealEffectType', 40 => 'LinkEffectType', 41 =>
    'HasteInternalEffectType', 42 => 'SlowInternalEffectType', 44 =>
    'ModifynumattacksEffectType', 45 => 'CurseEffectType', 46 =>
    'SilenceEffectType', 47 => 'InvisibilityEffectType', 48 =>
    'AcIncreaseEffectType', 49 => 'AcDecreaseEffectType', 50 =>
    'SpellImmunityEffectType', 51 => 'DispelAllMagicEffectType', 52 =>
    'DispelBestMagicEffectType', 53 => 'TauntEffectType', 54 =>
    'LightEffectType', 55 => 'SkillIncreaseEffectType', 56 =>
    'SkillDecreaseEffectType', 57 => 'HitpointChangeWhenDyingEffectType', 58 =>
    'SetWalkAnimationEffectType', 59 => 'LimitMovementSpeedEffectType', 61 =>
    'DamageShieldEffectType', 62 => 'PolymorphEffectType', 63 =>
    'SanctuaryEffectType', 64 => 'TimestopEffectType', 65 =>
    'SpellLevelAbsorptionEffectType', 67 => 'IconEffectType', 68 =>
    'RacialTypeEffectType', 69 => 'VisionEffectType', 70 =>
    'SeeInvisibleEffectType', 71 => 'UltravisionEffectType', 72 =>
    'TrueSeeingEffectType', 73 => 'BlindnessEffectType', 74 =>
    'DarknessEffectType', 75 => 'MissChanceEffectType', 76 =>
    'ConcealmentEffectType', 77 => 'TurnResistanceIncreaseEffectType', 78 =>
    'BonusSpellOfLevelEffectType', 79 => 'DisappearAppearEffectType', 80 =>
    'DisappearEffectType', 81 => 'AppearEffectType', 82 =>
    'NegativeLevelEffectType', 83 => 'BonusFeatEffectType', 84 =>
    'WoundingEffectType', 85 => 'SwarmEffectType', 86 =>
    'VampiricRegenerationEffectType', 87 => 'DisarmEffectType', 88 =>
    'TurnResistanceDecreaseEffectType', 89 => 'BlindnessInactiveEffectType',
    90 => 'PetrifyEffectType', 91 => 'ItempropertyEffectType', 92 =>
    'SpellFailureEffectType', 93 => 'CutsceneGhostEffectType', 94 =>
    'CutsceneImmobileEffectType', 95 => 'DefensiveStanceEffectType'
  },

  'EffectType' => {
    0 => 'InvalidEffect', 1 => 'DamageResistanceEffect', 3 => 'RegenerateEffect', 7 => 'DamageReductionEffect',
    9 => 'TemporaryHitpointsEffect', 11 => 'EntangleEffect', 12 => 'InvulnerableEffect', 13 => 'DeafEffect',
    14 => 'ResurrectionEffect', 15 => 'ImmunityEffect', 17 => 'EnemyAttackBonusEffect', 18 => 'ArcaneSpellFailureEffect',
    20 => 'AreaOfEffectEffect', 21 => 'BeamEffect', 23 => 'CharmedEffect', 24 => 'ConfusedEffect', 25 => 'FrightenedEffect',
    26 => 'DominatedEffect', 27 => 'ParalyzeEffect', 28 => 'DazedEffect', 29 => 'StunnedEffect', 30 => 'SleepEffect',
    31 => 'PoisonEffect', 32 => 'DiseaseEffect', 33 => 'CurseEffect', 34 => 'SilenceEffect', 35 => 'TurnedEffect',
    36 => 'HasteEffect', 37 => 'SlowEffect', 38 => 'AbilityIncreaseEffect', 39 => 'AbilityDecreaseEffect',
    40 => 'AttackIncreaseEffect', 41 => 'AttackDecreaseEffect', 42 => 'DamageIncreaseEffect', 43 => 'DamageDecreaseEffect',
    44 => 'DamageImmunityIncreaseEffect', 45 => 'DamageImmunityDecreaseEffect', 46 => 'ACIncreaseEffect',
    47 => 'ACDecreaseEffect', 48 => 'MovementSpeedIncreaseEffect', 49 => 'MovementSpeedDecreaseEffect',
    50 => 'SavingThrowIncreaseEffect', 51 => 'SavingThrowDecreaseEffect', 52 => 'SpellResistanceIncreaseEffect',
    53 => 'SpellResistanceDecreaseEffect', 54 => 'SkillIncreaseEffect', 55 => 'SkillDecreaseEffect',
    56 => 'InvisibilityEffect', 57 => 'ImprovedInvisibilityEffect', 58 => 'DarknessEffect',
    59 => 'DispelMagicAllEffect', 60 => 'ElementalShieldEffect', 61 => 'NegativeLevelEffect',
    62 => 'PolymorphEffect', 63 => 'SanctuaryEffect', 64 => 'TrueSeeingEffect', 65 => 'SeeInvisibleEffect',
    66 => 'TimestopEffect', 67 => 'BlindnessEffect', 68 => 'SpellLevelAbsorptionEffect', 69 => 'DispelMagicBestEffect',
    70 => 'UltravisionEffect', 71 => 'MissChanceEffect', 72 => 'ConcealmentEffect', 73 => 'SpellImmunityEffect',
    74 => 'VisualEffect', 75 => 'DisappearAppearEffect', 76 => 'SwarmEffect', 77 => 'TurnResistanceDecreaseEffect',
    78 => 'TurnResistanceIncreaseEffect', 79 => 'PetrifyEffect', 80 => 'CutsceneParalyzeEffect', 81 => 'EtherealEffect',
    82 => 'SpellFailureEffect', 83 => 'CutsceneGhostEffect', 84 => 'CutsceneImmobilizeEffect',
  },
  'PhenoType' => {
    0 => 'NormalPhenoType', 2 => 'BigPhenoType', 3 => 'Custom1PhenoType', 4 => 'Custom2PhenoType',
    5 => 'Custom3PhenoType', 6 => 'Custom4PhenoType', 7 => 'Custom5PhenoType', 8 => 'Custom6PhenoType',
    9 => 'Custom7PhenoType', 10 => 'Custom8PhenoType', 11 => 'Custom9PhenoType', 12 => 'Custom10PhenoType',
    13 => 'Custom11PhenoType', 14 => 'Custom12PhenoType', 15 => 'Custom13PhenoType', 16 => 'Custom14PhenoType',
    17 => 'Custom15PhenoType', 18 => 'Custom16PhenoType', 19 => 'Custom17PhenoType', 20 => 'Custom18PhenoType',
  },

  # Changes for 1.74
  'ExploredType' => {
    -1 => 'InvalidAreaOrCreature', 0 => 'TileNotExplored', 1 => 'TileExplored' 
  }
}

