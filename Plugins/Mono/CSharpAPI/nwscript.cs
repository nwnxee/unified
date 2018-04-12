namespace NWN
{
    class NWScript
    {
        //  Constants
        public const int NUM_INVENTORY_SLOTS = 18;
        public const int TRUE = 1;
        public const int FALSE = 0;
        public const float DIRECTION_EAST = 0.0f;
        public const float DIRECTION_NORTH = 90.0f;
        public const float DIRECTION_WEST = 180.0f;
        public const float DIRECTION_SOUTH = 270.0f;
        public const float PI = 3.141592f;
        public const int ATTITUDE_NEUTRAL = 0;
        public const int ATTITUDE_AGGRESSIVE = 1;
        public const int ATTITUDE_DEFENSIVE = 2;
        public const int ATTITUDE_SPECIAL = 3;
        public const int TALKVOLUME_TALK = 0;
        public const int TALKVOLUME_WHISPER = 1;
        public const int TALKVOLUME_SHOUT = 2;
        public const int TALKVOLUME_SILENT_TALK = 3;
        public const int TALKVOLUME_SILENT_SHOUT = 4;
        public const int TALKVOLUME_PARTY = 5;
        public const int TALKVOLUME_TELL = 6;
        public const int INVENTORY_SLOT_HEAD = 0;
        public const int INVENTORY_SLOT_CHEST = 1;
        public const int INVENTORY_SLOT_BOOTS = 2;
        public const int INVENTORY_SLOT_ARMS = 3;
        public const int INVENTORY_SLOT_RIGHTHAND = 4;
        public const int INVENTORY_SLOT_LEFTHAND = 5;
        public const int INVENTORY_SLOT_CLOAK = 6;
        public const int INVENTORY_SLOT_LEFTRING = 7;
        public const int INVENTORY_SLOT_RIGHTRING = 8;
        public const int INVENTORY_SLOT_NECK = 9;
        public const int INVENTORY_SLOT_BELT = 10;
        public const int INVENTORY_SLOT_ARROWS = 11;
        public const int INVENTORY_SLOT_BULLETS = 12;
        public const int INVENTORY_SLOT_BOLTS = 13;
        public const int INVENTORY_SLOT_CWEAPON_L = 14;
        public const int INVENTORY_SLOT_CWEAPON_R = 15;
        public const int INVENTORY_SLOT_CWEAPON_B = 16;
        public const int INVENTORY_SLOT_CARMOUR = 17;
        // Effect type constants
        public const int DURATION_TYPE_INSTANT = 0;
        public const int DURATION_TYPE_TEMPORARY = 1;
        public const int DURATION_TYPE_PERMANENT = 2;
        public const int SUBTYPE_MAGICAL = 8;
        public const int SUBTYPE_SUPERNATURAL = 16;
        public const int SUBTYPE_EXTRAORDINARY = 24;
        public const int ABILITY_STRENGTH = 0;
        //  should be the same as in nwseffectlist.cpp
        public const int ABILITY_DEXTERITY = 1;
        public const int ABILITY_CONSTITUTION = 2;
        public const int ABILITY_INTELLIGENCE = 3;
        public const int ABILITY_WISDOM = 4;
        public const int ABILITY_CHARISMA = 5;
        public const int SHAPE_SPELLCYLINDER = 0;
        public const int SHAPE_CONE = 1;
        public const int SHAPE_CUBE = 2;
        public const int SHAPE_SPELLCONE = 3;
        public const int SHAPE_SPHERE = 4;
        public const int METAMAGIC_NONE = 0;
        public const int METAMAGIC_EMPOWER = 1;
        public const int METAMAGIC_EXTEND = 2;
        public const int METAMAGIC_MAXIMIZE = 4;
        public const int METAMAGIC_QUICKEN = 8;
        public const int METAMAGIC_SILENT = 16;
        public const int METAMAGIC_STILL = 32;
        public const int METAMAGIC_ANY = 255;
        public const int OBJECT_TYPE_CREATURE = 1;
        public const int OBJECT_TYPE_ITEM = 2;
        public const int OBJECT_TYPE_TRIGGER = 4;
        public const int OBJECT_TYPE_DOOR = 8;
        public const int OBJECT_TYPE_AREA_OF_EFFECT = 16;
        public const int OBJECT_TYPE_WAYPOINT = 32;
        public const int OBJECT_TYPE_PLACEABLE = 64;
        public const int OBJECT_TYPE_STORE = 128;
        public const int OBJECT_TYPE_ENCOUNTER = 256;
        public const int OBJECT_TYPE_ALL = 32767;
        public const int OBJECT_TYPE_INVALID = 32767;
        public const int GENDER_MALE = 0;
        public const int GENDER_FEMALE = 1;
        public const int GENDER_BOTH = 2;
        public const int GENDER_OTHER = 3;
        public const int GENDER_NONE = 4;
        public const int DAMAGE_TYPE_BLUDGEONING = 1;
        public const int DAMAGE_TYPE_PIERCING = 2;
        public const int DAMAGE_TYPE_SLASHING = 4;
        public const int DAMAGE_TYPE_MAGICAL = 8;
        public const int DAMAGE_TYPE_ACID = 16;
        public const int DAMAGE_TYPE_COLD = 32;
        public const int DAMAGE_TYPE_DIVINE = 64;
        public const int DAMAGE_TYPE_ELECTRICAL = 128;
        public const int DAMAGE_TYPE_FIRE = 256;
        public const int DAMAGE_TYPE_NEGATIVE = 512;
        public const int DAMAGE_TYPE_POSITIVE = 1024;
        public const int DAMAGE_TYPE_SONIC = 2048;
        //  The base weapon damage is the base damage delivered by the weapon before
        //  any additional types of damage (e.g. fire) have been added.
        public const int DAMAGE_TYPE_BASE_WEAPON = 4096;
        //  Special versus flag just for AC effects
        public const int AC_VS_DAMAGE_TYPE_ALL = 4103;
        public const int DAMAGE_BONUS_1 = 1;
        public const int DAMAGE_BONUS_2 = 2;
        public const int DAMAGE_BONUS_3 = 3;
        public const int DAMAGE_BONUS_4 = 4;
        public const int DAMAGE_BONUS_5 = 5;
        public const int DAMAGE_BONUS_1d4 = 6;
        public const int DAMAGE_BONUS_1d6 = 7;
        public const int DAMAGE_BONUS_1d8 = 8;
        public const int DAMAGE_BONUS_1d10 = 9;
        public const int DAMAGE_BONUS_2d6 = 10;
        public const int DAMAGE_BONUS_2d8 = 11;
        public const int DAMAGE_BONUS_2d4 = 12;
        public const int DAMAGE_BONUS_2d10 = 13;
        public const int DAMAGE_BONUS_1d12 = 14;
        public const int DAMAGE_BONUS_2d12 = 15;
        public const int DAMAGE_BONUS_6 = 16;
        public const int DAMAGE_BONUS_7 = 17;
        public const int DAMAGE_BONUS_8 = 18;
        public const int DAMAGE_BONUS_9 = 19;
        public const int DAMAGE_BONUS_10 = 20;
        public const int DAMAGE_BONUS_11 = 21;
        public const int DAMAGE_BONUS_12 = 22;
        public const int DAMAGE_BONUS_13 = 23;
        public const int DAMAGE_BONUS_14 = 24;
        public const int DAMAGE_BONUS_15 = 25;
        public const int DAMAGE_BONUS_16 = 26;
        public const int DAMAGE_BONUS_17 = 27;
        public const int DAMAGE_BONUS_18 = 28;
        public const int DAMAGE_BONUS_19 = 29;
        public const int DAMAGE_BONUS_20 = 30;
        public const int DAMAGE_POWER_NORMAL = 0;
        public const int DAMAGE_POWER_PLUS_ONE = 1;
        public const int DAMAGE_POWER_PLUS_TWO = 2;
        public const int DAMAGE_POWER_PLUS_THREE = 3;
        public const int DAMAGE_POWER_PLUS_FOUR = 4;
        public const int DAMAGE_POWER_PLUS_FIVE = 5;
        public const int DAMAGE_POWER_ENERGY = 6;
        public const int DAMAGE_POWER_PLUS_SIX = 7;
        public const int DAMAGE_POWER_PLUS_SEVEN = 8;
        public const int DAMAGE_POWER_PLUS_EIGHT = 9;
        public const int DAMAGE_POWER_PLUS_NINE = 10;
        public const int DAMAGE_POWER_PLUS_TEN = 11;
        public const int DAMAGE_POWER_PLUS_ELEVEN = 12;
        public const int DAMAGE_POWER_PLUS_TWELVE = 13;
        public const int DAMAGE_POWER_PLUS_THIRTEEN = 14;
        public const int DAMAGE_POWER_PLUS_FOURTEEN = 15;
        public const int DAMAGE_POWER_PLUS_FIFTEEN = 16;
        public const int DAMAGE_POWER_PLUS_SIXTEEN = 17;
        public const int DAMAGE_POWER_PLUS_SEVENTEEN = 18;
        public const int DAMAGE_POWER_PLUS_EIGHTEEN = 19;
        public const int DAMAGE_POWER_PLUS_NINTEEN = 20;
        public const int DAMAGE_POWER_PLUS_TWENTY = 21;
        public const int ATTACK_BONUS_MISC = 0;
        public const int ATTACK_BONUS_ONHAND = 1;
        public const int ATTACK_BONUS_OFFHAND = 2;
        public const int AC_DODGE_BONUS = 0;
        public const int AC_NATURAL_BONUS = 1;
        public const int AC_ARMOUR_ENCHANTMENT_BONUS = 2;
        public const int AC_SHIELD_ENCHANTMENT_BONUS = 3;
        public const int AC_DEFLECTION_BONUS = 4;
        public const int MISS_CHANCE_TYPE_NORMAL = 0;
        public const int MISS_CHANCE_TYPE_VS_RANGED = 1;
        public const int MISS_CHANCE_TYPE_VS_MELEE = 2;
        public const int DOOR_ACTION_OPEN = 0;
        public const int DOOR_ACTION_UNLOCK = 1;
        public const int DOOR_ACTION_BASH = 2;
        public const int DOOR_ACTION_IGNORE = 3;
        public const int DOOR_ACTION_KNOCK = 4;
        public const int PLACEABLE_ACTION_USE = 0;
        public const int PLACEABLE_ACTION_UNLOCK = 1;
        public const int PLACEABLE_ACTION_BASH = 2;
        public const int PLACEABLE_ACTION_KNOCK = 4;
        public const int RACIAL_TYPE_DWARF = 0;
        public const int RACIAL_TYPE_ELF = 1;
        public const int RACIAL_TYPE_GNOME = 2;
        public const int RACIAL_TYPE_HALFLING = 3;
        public const int RACIAL_TYPE_HALFELF = 4;
        public const int RACIAL_TYPE_HALFORC = 5;
        public const int RACIAL_TYPE_HUMAN = 6;
        public const int RACIAL_TYPE_ABERRATION = 7;
        public const int RACIAL_TYPE_ANIMAL = 8;
        public const int RACIAL_TYPE_BEAST = 9;
        public const int RACIAL_TYPE_CONSTRUCT = 10;
        public const int RACIAL_TYPE_DRAGON = 11;
        public const int RACIAL_TYPE_HUMANOID_GOBLINOID = 12;
        public const int RACIAL_TYPE_HUMANOID_MONSTROUS = 13;
        public const int RACIAL_TYPE_HUMANOID_ORC = 14;
        public const int RACIAL_TYPE_HUMANOID_REPTILIAN = 15;
        public const int RACIAL_TYPE_ELEMENTAL = 16;
        public const int RACIAL_TYPE_FEY = 17;
        public const int RACIAL_TYPE_GIANT = 18;
        public const int RACIAL_TYPE_MAGICAL_BEAST = 19;
        public const int RACIAL_TYPE_OUTSIDER = 20;
        public const int RACIAL_TYPE_SHAPECHANGER = 23;
        public const int RACIAL_TYPE_UNDEAD = 24;
        public const int RACIAL_TYPE_VERMIN = 25;
        public const int RACIAL_TYPE_ALL = 28;
        public const int RACIAL_TYPE_INVALID = 28;
        public const int RACIAL_TYPE_OOZE = 29;
        public const int ALIGNMENT_ALL = 0;
        public const int ALIGNMENT_NEUTRAL = 1;
        public const int ALIGNMENT_LAWFUL = 2;
        public const int ALIGNMENT_CHAOTIC = 3;
        public const int ALIGNMENT_GOOD = 4;
        public const int ALIGNMENT_EVIL = 5;
        public const int SAVING_THROW_ALL = 0;
        public const int SAVING_THROW_FORT = 1;
        public const int SAVING_THROW_REFLEX = 2;
        public const int SAVING_THROW_WILL = 3;
        public const int SAVING_THROW_TYPE_ALL = 0;
        public const int SAVING_THROW_TYPE_NONE = 0;
        public const int SAVING_THROW_TYPE_MIND_SPELLS = 1;
        public const int SAVING_THROW_TYPE_POISON = 2;
        public const int SAVING_THROW_TYPE_DISEASE = 3;
        public const int SAVING_THROW_TYPE_FEAR = 4;
        public const int SAVING_THROW_TYPE_SONIC = 5;
        public const int SAVING_THROW_TYPE_ACID = 6;
        public const int SAVING_THROW_TYPE_FIRE = 7;
        public const int SAVING_THROW_TYPE_ELECTRICITY = 8;
        public const int SAVING_THROW_TYPE_POSITIVE = 9;
        public const int SAVING_THROW_TYPE_NEGATIVE = 10;
        public const int SAVING_THROW_TYPE_DEATH = 11;
        public const int SAVING_THROW_TYPE_COLD = 12;
        public const int SAVING_THROW_TYPE_DIVINE = 13;
        public const int SAVING_THROW_TYPE_TRAP = 14;
        public const int SAVING_THROW_TYPE_SPELL = 15;
        public const int SAVING_THROW_TYPE_GOOD = 16;
        public const int SAVING_THROW_TYPE_EVIL = 17;
        public const int SAVING_THROW_TYPE_LAW = 18;
        public const int SAVING_THROW_TYPE_CHAOS = 19;
        public const int IMMUNITY_TYPE_NONE = 0;
        public const int IMMUNITY_TYPE_MIND_SPELLS = 1;
        public const int IMMUNITY_TYPE_POISON = 2;
        public const int IMMUNITY_TYPE_DISEASE = 3;
        public const int IMMUNITY_TYPE_FEAR = 4;
        public const int IMMUNITY_TYPE_TRAP = 5;
        public const int IMMUNITY_TYPE_PARALYSIS = 6;
        public const int IMMUNITY_TYPE_BLINDNESS = 7;
        public const int IMMUNITY_TYPE_DEAFNESS = 8;
        public const int IMMUNITY_TYPE_SLOW = 9;
        public const int IMMUNITY_TYPE_ENTANGLE = 10;
        public const int IMMUNITY_TYPE_SILENCE = 11;
        public const int IMMUNITY_TYPE_STUN = 12;
        public const int IMMUNITY_TYPE_SLEEP = 13;
        public const int IMMUNITY_TYPE_CHARM = 14;
        public const int IMMUNITY_TYPE_DOMINATE = 15;
        public const int IMMUNITY_TYPE_CONFUSED = 16;
        public const int IMMUNITY_TYPE_CURSED = 17;
        public const int IMMUNITY_TYPE_DAZED = 18;
        public const int IMMUNITY_TYPE_ABILITY_DECREASE = 19;
        public const int IMMUNITY_TYPE_ATTACK_DECREASE = 20;
        public const int IMMUNITY_TYPE_DAMAGE_DECREASE = 21;
        public const int IMMUNITY_TYPE_DAMAGE_IMMUNITY_DECREASE = 22;
        public const int IMMUNITY_TYPE_AC_DECREASE = 23;
        public const int IMMUNITY_TYPE_MOVEMENT_SPEED_DECREASE = 24;
        public const int IMMUNITY_TYPE_SAVING_THROW_DECREASE = 25;
        public const int IMMUNITY_TYPE_SPELL_RESISTANCE_DECREASE = 26;
        public const int IMMUNITY_TYPE_SKILL_DECREASE = 27;
        public const int IMMUNITY_TYPE_KNOCKDOWN = 28;
        public const int IMMUNITY_TYPE_NEGATIVE_LEVEL = 29;
        public const int IMMUNITY_TYPE_SNEAK_ATTACK = 30;
        public const int IMMUNITY_TYPE_CRITICAL_HIT = 31;
        public const int IMMUNITY_TYPE_DEATH = 32;
        public const int AREA_TRANSITION_RANDOM = 0;
        public const int AREA_TRANSITION_USER_DEFINED = 1;
        public const int AREA_TRANSITION_CITY_01 = 2;
        public const int AREA_TRANSITION_CITY_02 = 3;
        public const int AREA_TRANSITION_CITY_03 = 4;
        public const int AREA_TRANSITION_CITY_04 = 5;
        public const int AREA_TRANSITION_CITY_05 = 6;
        public const int AREA_TRANSITION_CRYPT_01 = 7;
        public const int AREA_TRANSITION_CRYPT_02 = 8;
        public const int AREA_TRANSITION_CRYPT_03 = 9;
        public const int AREA_TRANSITION_CRYPT_04 = 10;
        public const int AREA_TRANSITION_CRYPT_05 = 11;
        public const int AREA_TRANSITION_DUNGEON_01 = 12;
        public const int AREA_TRANSITION_DUNGEON_02 = 13;
        public const int AREA_TRANSITION_DUNGEON_03 = 14;
        public const int AREA_TRANSITION_DUNGEON_04 = 15;
        public const int AREA_TRANSITION_DUNGEON_05 = 16;
        public const int AREA_TRANSITION_DUNGEON_06 = 17;
        public const int AREA_TRANSITION_DUNGEON_07 = 18;
        public const int AREA_TRANSITION_DUNGEON_08 = 19;
        public const int AREA_TRANSITION_MINES_01 = 20;
        public const int AREA_TRANSITION_MINES_02 = 21;
        public const int AREA_TRANSITION_MINES_03 = 22;
        public const int AREA_TRANSITION_MINES_04 = 23;
        public const int AREA_TRANSITION_MINES_05 = 24;
        public const int AREA_TRANSITION_MINES_06 = 25;
        public const int AREA_TRANSITION_MINES_07 = 26;
        public const int AREA_TRANSITION_MINES_08 = 27;
        public const int AREA_TRANSITION_MINES_09 = 28;
        public const int AREA_TRANSITION_SEWER_01 = 29;
        public const int AREA_TRANSITION_SEWER_02 = 30;
        public const int AREA_TRANSITION_SEWER_03 = 31;
        public const int AREA_TRANSITION_SEWER_04 = 32;
        public const int AREA_TRANSITION_SEWER_05 = 33;
        public const int AREA_TRANSITION_CASTLE_01 = 34;
        public const int AREA_TRANSITION_CASTLE_02 = 35;
        public const int AREA_TRANSITION_CASTLE_03 = 36;
        public const int AREA_TRANSITION_CASTLE_04 = 37;
        public const int AREA_TRANSITION_CASTLE_05 = 38;
        public const int AREA_TRANSITION_CASTLE_06 = 39;
        public const int AREA_TRANSITION_CASTLE_07 = 40;
        public const int AREA_TRANSITION_CASTLE_08 = 41;
        public const int AREA_TRANSITION_INTERIOR_01 = 42;
        public const int AREA_TRANSITION_INTERIOR_02 = 43;
        public const int AREA_TRANSITION_INTERIOR_03 = 44;
        public const int AREA_TRANSITION_INTERIOR_04 = 45;
        public const int AREA_TRANSITION_INTERIOR_05 = 46;
        public const int AREA_TRANSITION_INTERIOR_06 = 47;
        public const int AREA_TRANSITION_INTERIOR_07 = 48;
        public const int AREA_TRANSITION_INTERIOR_08 = 49;
        public const int AREA_TRANSITION_INTERIOR_09 = 50;
        public const int AREA_TRANSITION_INTERIOR_10 = 51;
        public const int AREA_TRANSITION_INTERIOR_11 = 52;
        public const int AREA_TRANSITION_INTERIOR_12 = 53;
        public const int AREA_TRANSITION_INTERIOR_13 = 54;
        public const int AREA_TRANSITION_INTERIOR_14 = 55;
        public const int AREA_TRANSITION_INTERIOR_15 = 56;
        public const int AREA_TRANSITION_INTERIOR_16 = 57;
        public const int AREA_TRANSITION_FOREST_01 = 58;
        public const int AREA_TRANSITION_FOREST_02 = 59;
        public const int AREA_TRANSITION_FOREST_03 = 60;
        public const int AREA_TRANSITION_FOREST_04 = 61;
        public const int AREA_TRANSITION_FOREST_05 = 62;
        public const int AREA_TRANSITION_RURAL_01 = 63;
        public const int AREA_TRANSITION_RURAL_02 = 64;
        public const int AREA_TRANSITION_RURAL_03 = 65;
        public const int AREA_TRANSITION_RURAL_04 = 66;
        public const int AREA_TRANSITION_RURAL_05 = 67;
        public const int AREA_TRANSITION_WRURAL_01 = 68;
        public const int AREA_TRANSITION_WRURAL_02 = 69;
        public const int AREA_TRANSITION_WRURAL_03 = 70;
        public const int AREA_TRANSITION_WRURAL_04 = 71;
        public const int AREA_TRANSITION_WRURAL_05 = 72;
        public const int AREA_TRANSITION_DESERT_01 = 73;
        public const int AREA_TRANSITION_DESERT_02 = 74;
        public const int AREA_TRANSITION_DESERT_03 = 75;
        public const int AREA_TRANSITION_DESERT_04 = 76;
        public const int AREA_TRANSITION_DESERT_05 = 77;
        public const int AREA_TRANSITION_RUINS_01 = 78;
        public const int AREA_TRANSITION_RUINS_02 = 79;
        public const int AREA_TRANSITION_RUINS_03 = 80;
        public const int AREA_TRANSITION_RUINS_04 = 81;
        public const int AREA_TRANSITION_RUINS_05 = 82;
        public const int AREA_TRANSITION_CARAVAN_WINTER = 83;
        public const int AREA_TRANSITION_CARAVAN_DESERT = 84;
        public const int AREA_TRANSITION_CARAVAN_RURAL = 85;
        public const int AREA_TRANSITION_MAGICAL_01 = 86;
        public const int AREA_TRANSITION_MAGICAL_02 = 87;
        public const int AREA_TRANSITION_UNDERDARK_01 = 88;
        public const int AREA_TRANSITION_UNDERDARK_02 = 89;
        public const int AREA_TRANSITION_UNDERDARK_03 = 90;
        public const int AREA_TRANSITION_UNDERDARK_04 = 91;
        public const int AREA_TRANSITION_UNDERDARK_05 = 92;
        public const int AREA_TRANSITION_UNDERDARK_06 = 93;
        public const int AREA_TRANSITION_UNDERDARK_07 = 94;
        public const int AREA_TRANSITION_BEHOLDER_01 = 95;
        public const int AREA_TRANSITION_BEHOLDER_02 = 96;
        public const int AREA_TRANSITION_DROW_01 = 97;
        public const int AREA_TRANSITION_DROW_02 = 98;
        public const int AREA_TRANSITION_ILLITHID_01 = 99;
        public const int AREA_TRANSITION_ILLITHID_02 = 100;
        public const int AREA_TRANSITION_WASTELAND_01 = 101;
        public const int AREA_TRANSITION_WASTELAND_02 = 102;
        public const int AREA_TRANSITION_WASTELAND_03 = 103;
        public const int AREA_TRANSITION_DROW_03 = 104;
        public const int AREA_TRANSITION_DROW_04 = 105;
        //  Legacy area-transition constants.  Do not delete these.
        public const int AREA_TRANSITION_CITY = 2;
        public const int AREA_TRANSITION_CRYPT = 7;
        public const int AREA_TRANSITION_FOREST = 58;
        public const int AREA_TRANSITION_RURAL = 63;
        public const int BODY_NODE_HAND = 0;
        public const int BODY_NODE_CHEST = 1;
        public const int BODY_NODE_MONSTER_0 = 2;
        public const int BODY_NODE_MONSTER_1 = 3;
        public const int BODY_NODE_MONSTER_2 = 4;
        public const int BODY_NODE_MONSTER_3 = 5;
        public const int BODY_NODE_MONSTER_4 = 6;
        public const int BODY_NODE_MONSTER_5 = 7;
        public const int BODY_NODE_MONSTER_6 = 8;
        public const int BODY_NODE_MONSTER_7 = 9;
        public const int BODY_NODE_MONSTER_8 = 10;
        public const int BODY_NODE_MONSTER_9 = 11;
        public const float RADIUS_SIZE_SMALL = 1.67f;
        public const float RADIUS_SIZE_MEDIUM = 3.33f;
        public const float RADIUS_SIZE_LARGE = 5.0f;
        public const float RADIUS_SIZE_HUGE = 6.67f;
        public const float RADIUS_SIZE_GARGANTUAN = 8.33f;
        public const float RADIUS_SIZE_COLOSSAL = 10.0f;
        //  these are magic numbers.  they should correspond to the values layed out in ExecuteCommandGetEffectType
        public const int EFFECT_TYPE_INVALIDEFFECT = 0;
        public const int EFFECT_TYPE_DAMAGE_RESISTANCE = 1;
        // int EFFECT_TYPE_ABILITY_BONUS               = 2;
        public const int EFFECT_TYPE_REGENERATE = 3;
        // int EFFECT_TYPE_SAVING_THROW_BONUS          = 4;
        // int EFFECT_TYPE_MODIFY_AC                   = 5;
        // int EFFECT_TYPE_ATTACK_BONUS                = 6;
        public const int EFFECT_TYPE_DAMAGE_REDUCTION = 7;
        // int EFFECT_TYPE_DAMAGE_BONUS                = 8;
        public const int EFFECT_TYPE_TEMPORARY_HITPOINTS = 9;
        // int EFFECT_TYPE_DAMAGE_IMMUNITY             = 10;
        public const int EFFECT_TYPE_ENTANGLE = 11;
        public const int EFFECT_TYPE_INVULNERABLE = 12;
        public const int EFFECT_TYPE_DEAF = 13;
        public const int EFFECT_TYPE_RESURRECTION = 14;
        public const int EFFECT_TYPE_IMMUNITY = 15;
        // int EFFECT_TYPE_BLIND                       = 16;
        public const int EFFECT_TYPE_ENEMY_ATTACK_BONUS = 17;
        public const int EFFECT_TYPE_ARCANE_SPELL_FAILURE = 18;
        // int EFFECT_TYPE_MOVEMENT_SPEED              = 19;
        public const int EFFECT_TYPE_AREA_OF_EFFECT = 20;
        public const int EFFECT_TYPE_BEAM = 21;
        // int EFFECT_TYPE_SPELL_RESISTANCE            = 22;
        public const int EFFECT_TYPE_CHARMED = 23;
        public const int EFFECT_TYPE_CONFUSED = 24;
        public const int EFFECT_TYPE_FRIGHTENED = 25;
        public const int EFFECT_TYPE_DOMINATED = 26;
        public const int EFFECT_TYPE_PARALYZE = 27;
        public const int EFFECT_TYPE_DAZED = 28;
        public const int EFFECT_TYPE_STUNNED = 29;
        public const int EFFECT_TYPE_SLEEP = 30;
        public const int EFFECT_TYPE_POISON = 31;
        public const int EFFECT_TYPE_DISEASE = 32;
        public const int EFFECT_TYPE_CURSE = 33;
        public const int EFFECT_TYPE_SILENCE = 34;
        public const int EFFECT_TYPE_TURNED = 35;
        public const int EFFECT_TYPE_HASTE = 36;
        public const int EFFECT_TYPE_SLOW = 37;
        public const int EFFECT_TYPE_ABILITY_INCREASE = 38;
        public const int EFFECT_TYPE_ABILITY_DECREASE = 39;
        public const int EFFECT_TYPE_ATTACK_INCREASE = 40;
        public const int EFFECT_TYPE_ATTACK_DECREASE = 41;
        public const int EFFECT_TYPE_DAMAGE_INCREASE = 42;
        public const int EFFECT_TYPE_DAMAGE_DECREASE = 43;
        public const int EFFECT_TYPE_DAMAGE_IMMUNITY_INCREASE = 44;
        public const int EFFECT_TYPE_DAMAGE_IMMUNITY_DECREASE = 45;
        public const int EFFECT_TYPE_AC_INCREASE = 46;
        public const int EFFECT_TYPE_AC_DECREASE = 47;
        public const int EFFECT_TYPE_MOVEMENT_SPEED_INCREASE = 48;
        public const int EFFECT_TYPE_MOVEMENT_SPEED_DECREASE = 49;
        public const int EFFECT_TYPE_SAVING_THROW_INCREASE = 50;
        public const int EFFECT_TYPE_SAVING_THROW_DECREASE = 51;
        public const int EFFECT_TYPE_SPELL_RESISTANCE_INCREASE = 52;
        public const int EFFECT_TYPE_SPELL_RESISTANCE_DECREASE = 53;
        public const int EFFECT_TYPE_SKILL_INCREASE = 54;
        public const int EFFECT_TYPE_SKILL_DECREASE = 55;
        public const int EFFECT_TYPE_INVISIBILITY = 56;
        public const int EFFECT_TYPE_IMPROVEDINVISIBILITY = 57;
        public const int EFFECT_TYPE_DARKNESS = 58;
        public const int EFFECT_TYPE_DISPELMAGICALL = 59;
        public const int EFFECT_TYPE_ELEMENTALSHIELD = 60;
        public const int EFFECT_TYPE_NEGATIVELEVEL = 61;
        public const int EFFECT_TYPE_POLYMORPH = 62;
        public const int EFFECT_TYPE_SANCTUARY = 63;
        public const int EFFECT_TYPE_TRUESEEING = 64;
        public const int EFFECT_TYPE_SEEINVISIBLE = 65;
        public const int EFFECT_TYPE_TIMESTOP = 66;
        public const int EFFECT_TYPE_BLINDNESS = 67;
        public const int EFFECT_TYPE_SPELLLEVELABSORPTION = 68;
        public const int EFFECT_TYPE_DISPELMAGICBEST = 69;
        public const int EFFECT_TYPE_ULTRAVISION = 70;
        public const int EFFECT_TYPE_MISS_CHANCE = 71;
        public const int EFFECT_TYPE_CONCEALMENT = 72;
        public const int EFFECT_TYPE_SPELL_IMMUNITY = 73;
        public const int EFFECT_TYPE_VISUALEFFECT = 74;
        public const int EFFECT_TYPE_DISAPPEARAPPEAR = 75;
        public const int EFFECT_TYPE_SWARM = 76;
        public const int EFFECT_TYPE_TURN_RESISTANCE_DECREASE = 77;
        public const int EFFECT_TYPE_TURN_RESISTANCE_INCREASE = 78;
        public const int EFFECT_TYPE_PETRIFY = 79;
        public const int EFFECT_TYPE_CUTSCENE_PARALYZE = 80;
        public const int EFFECT_TYPE_ETHEREAL = 81;
        public const int EFFECT_TYPE_SPELL_FAILURE = 82;
        public const int EFFECT_TYPE_CUTSCENEGHOST = 83;
        public const int EFFECT_TYPE_CUTSCENEIMMOBILIZE = 84;
        public const int ITEM_APPR_TYPE_SIMPLE_MODEL = 0;
        public const int ITEM_APPR_TYPE_WEAPON_COLOR = 1;
        public const int ITEM_APPR_TYPE_WEAPON_MODEL = 2;
        public const int ITEM_APPR_TYPE_ARMOR_MODEL = 3;
        public const int ITEM_APPR_TYPE_ARMOR_COLOR = 4;
        public const int ITEM_APPR_NUM_TYPES = 5;
        public const int ITEM_APPR_ARMOR_COLOR_LEATHER1 = 0;
        public const int ITEM_APPR_ARMOR_COLOR_LEATHER2 = 1;
        public const int ITEM_APPR_ARMOR_COLOR_CLOTH1 = 2;
        public const int ITEM_APPR_ARMOR_COLOR_CLOTH2 = 3;
        public const int ITEM_APPR_ARMOR_COLOR_METAL1 = 4;
        public const int ITEM_APPR_ARMOR_COLOR_METAL2 = 5;
        public const int ITEM_APPR_ARMOR_NUM_COLORS = 6;
        public const int ITEM_APPR_ARMOR_MODEL_RFOOT = 0;
        public const int ITEM_APPR_ARMOR_MODEL_LFOOT = 1;
        public const int ITEM_APPR_ARMOR_MODEL_RSHIN = 2;
        public const int ITEM_APPR_ARMOR_MODEL_LSHIN = 3;
        public const int ITEM_APPR_ARMOR_MODEL_LTHIGH = 4;
        public const int ITEM_APPR_ARMOR_MODEL_RTHIGH = 5;
        public const int ITEM_APPR_ARMOR_MODEL_PELVIS = 6;
        public const int ITEM_APPR_ARMOR_MODEL_TORSO = 7;
        public const int ITEM_APPR_ARMOR_MODEL_BELT = 8;
        public const int ITEM_APPR_ARMOR_MODEL_NECK = 9;
        public const int ITEM_APPR_ARMOR_MODEL_RFOREARM = 10;
        public const int ITEM_APPR_ARMOR_MODEL_LFOREARM = 11;
        public const int ITEM_APPR_ARMOR_MODEL_RBICEP = 12;
        public const int ITEM_APPR_ARMOR_MODEL_LBICEP = 13;
        public const int ITEM_APPR_ARMOR_MODEL_RSHOULDER = 14;
        public const int ITEM_APPR_ARMOR_MODEL_LSHOULDER = 15;
        public const int ITEM_APPR_ARMOR_MODEL_RHAND = 16;
        public const int ITEM_APPR_ARMOR_MODEL_LHAND = 17;
        public const int ITEM_APPR_ARMOR_MODEL_ROBE = 18;
        public const int ITEM_APPR_ARMOR_NUM_MODELS = 19;
        public const int ITEM_APPR_WEAPON_MODEL_BOTTOM = 0;
        public const int ITEM_APPR_WEAPON_MODEL_MIDDLE = 1;
        public const int ITEM_APPR_WEAPON_MODEL_TOP = 2;
        public const int ITEM_APPR_WEAPON_COLOR_BOTTOM = 0;
        public const int ITEM_APPR_WEAPON_COLOR_MIDDLE = 1;
        public const int ITEM_APPR_WEAPON_COLOR_TOP = 2;
        public const int ITEM_PROPERTY_ABILITY_BONUS = 0;
        public const int ITEM_PROPERTY_AC_BONUS = 1;
        public const int ITEM_PROPERTY_AC_BONUS_VS_ALIGNMENT_GROUP = 2;
        public const int ITEM_PROPERTY_AC_BONUS_VS_DAMAGE_TYPE = 3;
        public const int ITEM_PROPERTY_AC_BONUS_VS_RACIAL_GROUP = 4;
        public const int ITEM_PROPERTY_AC_BONUS_VS_SPECIFIC_ALIGNMENT = 5;
        public const int ITEM_PROPERTY_ENHANCEMENT_BONUS = 6;
        public const int ITEM_PROPERTY_ENHANCEMENT_BONUS_VS_ALIGNMENT_GROUP = 7;
        public const int ITEM_PROPERTY_ENHANCEMENT_BONUS_VS_RACIAL_GROUP = 8;
        public const int ITEM_PROPERTY_ENHANCEMENT_BONUS_VS_SPECIFIC_ALIGNEMENT = 9;
        public const int ITEM_PROPERTY_DECREASED_ENHANCEMENT_MODIFIER = 10;
        public const int ITEM_PROPERTY_BASE_ITEM_WEIGHT_REDUCTION = 11;
        public const int ITEM_PROPERTY_BONUS_FEAT = 12;
        public const int ITEM_PROPERTY_BONUS_SPELL_SLOT_OF_LEVEL_N = 13;
        public const int ITEM_PROPERTY_CAST_SPELL = 15;
        public const int ITEM_PROPERTY_DAMAGE_BONUS = 16;
        public const int ITEM_PROPERTY_DAMAGE_BONUS_VS_ALIGNMENT_GROUP = 17;
        public const int ITEM_PROPERTY_DAMAGE_BONUS_VS_RACIAL_GROUP = 18;
        public const int ITEM_PROPERTY_DAMAGE_BONUS_VS_SPECIFIC_ALIGNMENT = 19;
        public const int ITEM_PROPERTY_IMMUNITY_DAMAGE_TYPE = 20;
        public const int ITEM_PROPERTY_DECREASED_DAMAGE = 21;
        public const int ITEM_PROPERTY_DAMAGE_REDUCTION = 22;
        public const int ITEM_PROPERTY_DAMAGE_RESISTANCE = 23;
        public const int ITEM_PROPERTY_DAMAGE_VULNERABILITY = 24;
        public const int ITEM_PROPERTY_DARKVISION = 26;
        public const int ITEM_PROPERTY_DECREASED_ABILITY_SCORE = 27;
        public const int ITEM_PROPERTY_DECREASED_AC = 28;
        public const int ITEM_PROPERTY_DECREASED_SKILL_MODIFIER = 29;
        public const int ITEM_PROPERTY_ENHANCED_CONTAINER_REDUCED_WEIGHT = 32;
        public const int ITEM_PROPERTY_EXTRA_MELEE_DAMAGE_TYPE = 33;
        public const int ITEM_PROPERTY_EXTRA_RANGED_DAMAGE_TYPE = 34;
        public const int ITEM_PROPERTY_HASTE = 35;
        public const int ITEM_PROPERTY_HOLY_AVENGER = 36;
        public const int ITEM_PROPERTY_IMMUNITY_MISCELLANEOUS = 37;
        public const int ITEM_PROPERTY_IMPROVED_EVASION = 38;
        public const int ITEM_PROPERTY_SPELL_RESISTANCE = 39;
        public const int ITEM_PROPERTY_SAVING_THROW_BONUS = 40;
        public const int ITEM_PROPERTY_SAVING_THROW_BONUS_SPECIFIC = 41;
        public const int ITEM_PROPERTY_KEEN = 43;
        public const int ITEM_PROPERTY_LIGHT = 44;
        public const int ITEM_PROPERTY_MIGHTY = 45;
        public const int ITEM_PROPERTY_MIND_BLANK = 46;
        public const int ITEM_PROPERTY_NO_DAMAGE = 47;
        public const int ITEM_PROPERTY_ON_HIT_PROPERTIES = 48;
        public const int ITEM_PROPERTY_DECREASED_SAVING_THROWS = 49;
        public const int ITEM_PROPERTY_DECREASED_SAVING_THROWS_SPECIFIC = 50;
        public const int ITEM_PROPERTY_REGENERATION = 51;
        public const int ITEM_PROPERTY_SKILL_BONUS = 52;
        public const int ITEM_PROPERTY_IMMUNITY_SPECIFIC_SPELL = 53;
        public const int ITEM_PROPERTY_IMMUNITY_SPELL_SCHOOL = 54;
        public const int ITEM_PROPERTY_THIEVES_TOOLS = 55;
        public const int ITEM_PROPERTY_ATTACK_BONUS = 56;
        public const int ITEM_PROPERTY_ATTACK_BONUS_VS_ALIGNMENT_GROUP = 57;
        public const int ITEM_PROPERTY_ATTACK_BONUS_VS_RACIAL_GROUP = 58;
        public const int ITEM_PROPERTY_ATTACK_BONUS_VS_SPECIFIC_ALIGNMENT = 59;
        public const int ITEM_PROPERTY_DECREASED_ATTACK_MODIFIER = 60;
        public const int ITEM_PROPERTY_UNLIMITED_AMMUNITION = 61;
        public const int ITEM_PROPERTY_USE_LIMITATION_ALIGNMENT_GROUP = 62;
        public const int ITEM_PROPERTY_USE_LIMITATION_CLASS = 63;
        public const int ITEM_PROPERTY_USE_LIMITATION_RACIAL_TYPE = 64;
        public const int ITEM_PROPERTY_USE_LIMITATION_SPECIFIC_ALIGNMENT = 65;
        public const int ITEM_PROPERTY_USE_LIMITATION_TILESET = 66;
        public const int ITEM_PROPERTY_REGENERATION_VAMPIRIC = 67;
        public const int ITEM_PROPERTY_TRAP = 70;
        public const int ITEM_PROPERTY_TRUE_SEEING = 71;
        public const int ITEM_PROPERTY_ON_MONSTER_HIT = 72;
        public const int ITEM_PROPERTY_TURN_RESISTANCE = 73;
        public const int ITEM_PROPERTY_MASSIVE_CRITICALS = 74;
        public const int ITEM_PROPERTY_FREEDOM_OF_MOVEMENT = 75;
        //  no longer working, poison is now a on_hit subtype
        public const int ITEM_PROPERTY_POISON = 76;
        public const int ITEM_PROPERTY_MONSTER_DAMAGE = 77;
        public const int ITEM_PROPERTY_IMMUNITY_SPELLS_BY_LEVEL = 78;
        public const int ITEM_PROPERTY_SPECIAL_WALK = 79;
        public const int ITEM_PROPERTY_HEALERS_KIT = 80;
        public const int ITEM_PROPERTY_WEIGHT_INCREASE = 81;
        public const int ITEM_PROPERTY_ONHITCASTSPELL = 82;
        public const int ITEM_PROPERTY_VISUALEFFECT = 83;
        public const int ITEM_PROPERTY_ARCANE_SPELL_FAILURE = 84;
        public const int ITEM_PROPERTY_MATERIAL = 85;
        public const int ITEM_PROPERTY_QUALITY = 86;
        public const int ITEM_PROPERTY_ADDITIONAL = 87;
        public const int BASE_ITEM_SHORTSWORD = 0;
        public const int BASE_ITEM_LONGSWORD = 1;
        public const int BASE_ITEM_BATTLEAXE = 2;
        public const int BASE_ITEM_BASTARDSWORD = 3;
        public const int BASE_ITEM_LIGHTFLAIL = 4;
        public const int BASE_ITEM_WARHAMMER = 5;
        public const int BASE_ITEM_HEAVYCROSSBOW = 6;
        public const int BASE_ITEM_LIGHTCROSSBOW = 7;
        public const int BASE_ITEM_LONGBOW = 8;
        public const int BASE_ITEM_LIGHTMACE = 9;
        public const int BASE_ITEM_HALBERD = 10;
        public const int BASE_ITEM_SHORTBOW = 11;
        public const int BASE_ITEM_TWOBLADEDSWORD = 12;
        public const int BASE_ITEM_GREATSWORD = 13;
        public const int BASE_ITEM_SMALLSHIELD = 14;
        public const int BASE_ITEM_TORCH = 15;
        public const int BASE_ITEM_ARMOR = 16;
        public const int BASE_ITEM_HELMET = 17;
        public const int BASE_ITEM_GREATAXE = 18;
        public const int BASE_ITEM_AMULET = 19;
        public const int BASE_ITEM_ARROW = 20;
        public const int BASE_ITEM_BELT = 21;
        public const int BASE_ITEM_DAGGER = 22;
        public const int BASE_ITEM_MISCSMALL = 24;
        public const int BASE_ITEM_BOLT = 25;
        public const int BASE_ITEM_BOOTS = 26;
        public const int BASE_ITEM_BULLET = 27;
        public const int BASE_ITEM_CLUB = 28;
        public const int BASE_ITEM_MISCMEDIUM = 29;
        public const int BASE_ITEM_DART = 31;
        public const int BASE_ITEM_DIREMACE = 32;
        public const int BASE_ITEM_DOUBLEAXE = 33;
        public const int BASE_ITEM_MISCLARGE = 34;
        public const int BASE_ITEM_HEAVYFLAIL = 35;
        public const int BASE_ITEM_GLOVES = 36;
        public const int BASE_ITEM_LIGHTHAMMER = 37;
        public const int BASE_ITEM_HANDAXE = 38;
        public const int BASE_ITEM_HEALERSKIT = 39;
        public const int BASE_ITEM_KAMA = 40;
        public const int BASE_ITEM_KATANA = 41;
        public const int BASE_ITEM_KUKRI = 42;
        public const int BASE_ITEM_MISCTALL = 43;
        public const int BASE_ITEM_MAGICROD = 44;
        public const int BASE_ITEM_MAGICSTAFF = 45;
        public const int BASE_ITEM_MAGICWAND = 46;
        public const int BASE_ITEM_MORNINGSTAR = 47;
        public const int BASE_ITEM_POTIONS = 49;
        public const int BASE_ITEM_QUARTERSTAFF = 50;
        public const int BASE_ITEM_RAPIER = 51;
        public const int BASE_ITEM_RING = 52;
        public const int BASE_ITEM_SCIMITAR = 53;
        public const int BASE_ITEM_SCROLL = 54;
        public const int BASE_ITEM_SCYTHE = 55;
        public const int BASE_ITEM_LARGESHIELD = 56;
        public const int BASE_ITEM_TOWERSHIELD = 57;
        public const int BASE_ITEM_SHORTSPEAR = 58;
        public const int BASE_ITEM_SHURIKEN = 59;
        public const int BASE_ITEM_SICKLE = 60;
        public const int BASE_ITEM_SLING = 61;
        public const int BASE_ITEM_THIEVESTOOLS = 62;
        public const int BASE_ITEM_THROWINGAXE = 63;
        public const int BASE_ITEM_TRAPKIT = 64;
        public const int BASE_ITEM_KEY = 65;
        public const int BASE_ITEM_LARGEBOX = 66;
        public const int BASE_ITEM_MISCWIDE = 68;
        public const int BASE_ITEM_CSLASHWEAPON = 69;
        public const int BASE_ITEM_CPIERCWEAPON = 70;
        public const int BASE_ITEM_CBLUDGWEAPON = 71;
        public const int BASE_ITEM_CSLSHPRCWEAP = 72;
        public const int BASE_ITEM_CREATUREITEM = 73;
        public const int BASE_ITEM_BOOK = 74;
        public const int BASE_ITEM_SPELLSCROLL = 75;
        public const int BASE_ITEM_GOLD = 76;
        public const int BASE_ITEM_GEM = 77;
        public const int BASE_ITEM_BRACER = 78;
        public const int BASE_ITEM_MISCTHIN = 79;
        public const int BASE_ITEM_CLOAK = 80;
        public const int BASE_ITEM_GRENADE = 81;
        public const int BASE_ITEM_TRIDENT = 95;
        public const int BASE_ITEM_BLANK_POTION = 101;
        public const int BASE_ITEM_BLANK_SCROLL = 102;
        public const int BASE_ITEM_BLANK_WAND = 103;
        public const int BASE_ITEM_ENCHANTED_POTION = 104;
        public const int BASE_ITEM_ENCHANTED_SCROLL = 105;
        public const int BASE_ITEM_ENCHANTED_WAND = 106;
        public const int BASE_ITEM_DWARVENWARAXE = 108;
        public const int BASE_ITEM_CRAFTMATERIALMED = 109;
        public const int BASE_ITEM_CRAFTMATERIALSML = 110;
        public const int BASE_ITEM_WHIP = 111;
        public const int BASE_ITEM_INVALID = 256;
        public const int VFX_NONE = -1;
        public const int VFX_DUR_BLUR = 0;
        public const int VFX_DUR_DARKNESS = 1;
        public const int VFX_DUR_ENTANGLE = 2;
        public const int VFX_DUR_FREEDOM_OF_MOVEMENT = 3;
        public const int VFX_DUR_GLOBE_INVULNERABILITY = 4;
        public const int VFX_DUR_BLACKOUT = 5;
        public const int VFX_DUR_INVISIBILITY = 6;
        public const int VFX_DUR_MIND_AFFECTING_NEGATIVE = 7;
        public const int VFX_DUR_MIND_AFFECTING_POSITIVE = 8;
        public const int VFX_DUR_GHOSTLY_VISAGE = 9;
        public const int VFX_DUR_ETHEREAL_VISAGE = 10;
        public const int VFX_DUR_PROT_BARKSKIN = 11;
        public const int VFX_DUR_PROT_GREATER_STONESKIN = 12;
        public const int VFX_DUR_PROT_PREMONITION = 13;
        public const int VFX_DUR_PROT_SHADOW_ARMOR = 14;
        public const int VFX_DUR_PROT_STONESKIN = 15;
        public const int VFX_DUR_SANCTUARY = 16;
        public const int VFX_DUR_WEB = 17;
        public const int VFX_FNF_BLINDDEAF = 18;
        public const int VFX_FNF_DISPEL = 19;
        public const int VFX_FNF_DISPEL_DISJUNCTION = 20;
        public const int VFX_FNF_DISPEL_GREATER = 21;
        public const int VFX_FNF_FIREBALL = 22;
        public const int VFX_FNF_FIRESTORM = 23;
        public const int VFX_FNF_IMPLOSION = 24;
        // int VFX_FNF_MASS_HASTE = 25 ;
        public const int VFX_FNF_MASS_HEAL = 26;
        public const int VFX_FNF_MASS_MIND_AFFECTING = 27;
        public const int VFX_FNF_METEOR_SWARM = 28;
        public const int VFX_FNF_NATURES_BALANCE = 29;
        public const int VFX_FNF_PWKILL = 30;
        public const int VFX_FNF_PWSTUN = 31;
        public const int VFX_FNF_SUMMON_GATE = 32;
        public const int VFX_FNF_SUMMON_MONSTER_1 = 33;
        public const int VFX_FNF_SUMMON_MONSTER_2 = 34;
        public const int VFX_FNF_SUMMON_MONSTER_3 = 35;
        public const int VFX_FNF_SUMMON_UNDEAD = 36;
        public const int VFX_FNF_SUNBEAM = 37;
        public const int VFX_FNF_TIME_STOP = 38;
        public const int VFX_FNF_WAIL_O_BANSHEES = 39;
        public const int VFX_FNF_WEIRD = 40;
        public const int VFX_FNF_WORD = 41;
        public const int VFX_IMP_AC_BONUS = 42;
        public const int VFX_IMP_ACID_L = 43;
        public const int VFX_IMP_ACID_S = 44;
        // int VFX_IMP_ALTER_WEAPON = 45 ;
        public const int VFX_IMP_BLIND_DEAF_M = 46;
        public const int VFX_IMP_BREACH = 47;
        public const int VFX_IMP_CONFUSION_S = 48;
        public const int VFX_IMP_DAZED_S = 49;
        public const int VFX_IMP_DEATH = 50;
        public const int VFX_IMP_DISEASE_S = 51;
        public const int VFX_IMP_DISPEL = 52;
        public const int VFX_IMP_DISPEL_DISJUNCTION = 53;
        public const int VFX_IMP_DIVINE_STRIKE_FIRE = 54;
        public const int VFX_IMP_DIVINE_STRIKE_HOLY = 55;
        public const int VFX_IMP_DOMINATE_S = 56;
        public const int VFX_IMP_DOOM = 57;
        public const int VFX_IMP_FEAR_S = 58;
        // int VFX_IMP_FLAME_L = 59 ;
        public const int VFX_IMP_FLAME_M = 60;
        public const int VFX_IMP_FLAME_S = 61;
        public const int VFX_IMP_FROST_L = 62;
        public const int VFX_IMP_FROST_S = 63;
        public const int VFX_IMP_GREASE = 64;
        public const int VFX_IMP_HASTE = 65;
        public const int VFX_IMP_HEALING_G = 66;
        public const int VFX_IMP_HEALING_L = 67;
        public const int VFX_IMP_HEALING_M = 68;
        public const int VFX_IMP_HEALING_S = 69;
        public const int VFX_IMP_HEALING_X = 70;
        public const int VFX_IMP_HOLY_AID = 71;
        public const int VFX_IMP_KNOCK = 72;
        public const int VFX_BEAM_LIGHTNING = 73;
        public const int VFX_IMP_LIGHTNING_M = 74;
        public const int VFX_IMP_LIGHTNING_S = 75;
        public const int VFX_IMP_MAGBLUE = 76;
        // int VFX_IMP_MAGBLUE2 = 77 ;
        // int VFX_IMP_MAGBLUE3 = 78 ;
        // int VFX_IMP_MAGBLUE4 = 79 ;
        // int VFX_IMP_MAGBLUE5 = 80 ;
        public const int VFX_IMP_NEGATIVE_ENERGY = 81;
        public const int VFX_DUR_PARALYZE_HOLD = 82;
        public const int VFX_IMP_POISON_L = 83;
        public const int VFX_IMP_POISON_S = 84;
        public const int VFX_IMP_POLYMORPH = 85;
        public const int VFX_IMP_PULSE_COLD = 86;
        public const int VFX_IMP_PULSE_FIRE = 87;
        public const int VFX_IMP_PULSE_HOLY = 88;
        public const int VFX_IMP_PULSE_NEGATIVE = 89;
        public const int VFX_IMP_RAISE_DEAD = 90;
        public const int VFX_IMP_REDUCE_ABILITY_SCORE = 91;
        public const int VFX_IMP_REMOVE_CONDITION = 92;
        public const int VFX_IMP_SILENCE = 93;
        public const int VFX_IMP_SLEEP = 94;
        public const int VFX_IMP_SLOW = 95;
        public const int VFX_IMP_SONIC = 96;
        public const int VFX_IMP_STUN = 97;
        public const int VFX_IMP_SUNSTRIKE = 98;
        public const int VFX_IMP_UNSUMMON = 99;
        public const int VFX_COM_SPECIAL_BLUE_RED = 100;
        public const int VFX_COM_SPECIAL_PINK_ORANGE = 101;
        public const int VFX_COM_SPECIAL_RED_WHITE = 102;
        public const int VFX_COM_SPECIAL_RED_ORANGE = 103;
        public const int VFX_COM_SPECIAL_WHITE_BLUE = 104;
        public const int VFX_COM_SPECIAL_WHITE_ORANGE = 105;
        public const int VFX_COM_BLOOD_REG_WIMP = 106;
        public const int VFX_COM_BLOOD_LRG_WIMP = 107;
        public const int VFX_COM_BLOOD_CRT_WIMP = 108;
        public const int VFX_COM_BLOOD_REG_RED = 109;
        public const int VFX_COM_BLOOD_REG_GREEN = 110;
        public const int VFX_COM_BLOOD_REG_YELLOW = 111;
        public const int VFX_COM_BLOOD_LRG_RED = 112;
        public const int VFX_COM_BLOOD_LRG_GREEN = 113;
        public const int VFX_COM_BLOOD_LRG_YELLOW = 114;
        public const int VFX_COM_BLOOD_CRT_RED = 115;
        public const int VFX_COM_BLOOD_CRT_GREEN = 116;
        public const int VFX_COM_BLOOD_CRT_YELLOW = 117;
        public const int VFX_COM_SPARKS_PARRY = 118;
        // int VFX_COM_GIB = 119 ;
        public const int VFX_COM_UNLOAD_MODEL = 120;
        public const int VFX_COM_CHUNK_RED_SMALL = 121;
        public const int VFX_COM_CHUNK_RED_MEDIUM = 122;
        public const int VFX_COM_CHUNK_GREEN_SMALL = 123;
        public const int VFX_COM_CHUNK_GREEN_MEDIUM = 124;
        public const int VFX_COM_CHUNK_YELLOW_SMALL = 125;
        public const int VFX_COM_CHUNK_YELLOW_MEDIUM = 126;
        // int VFX_ITM_ACID = 127 ;
        // int VFX_ITM_FIRE = 128 ;
        // int VFX_ITM_FROST = 129 ;
        // int VFX_ITM_ILLUMINATED_BLUE = 130 ;
        // int VFX_ITM_ILLUMINATED_PURPLE = 131 ;
        // int VFX_ITM_ILLUMINATED_RED = 132 ;
        // int VFX_ITM_LIGHTNING = 133 ;
        // int VFX_ITM_PULSING_BLUE = 134 ;
        // int VFX_ITM_PULSING_PURPLE = 135 ;
        // int VFX_ITM_PULSING_RED = 136 ;
        // int VFX_ITM_SMOKING = 137 ;
        public const int VFX_DUR_SPELLTURNING = 138;
        public const int VFX_IMP_IMPROVE_ABILITY_SCORE = 139;
        public const int VFX_IMP_CHARM = 140;
        public const int VFX_IMP_MAGICAL_VISION = 141;
        // int VFX_IMP_LAW_HELP = 142;
        // int VFX_IMP_CHAOS_HELP = 143;
        public const int VFX_IMP_EVIL_HELP = 144;
        public const int VFX_IMP_GOOD_HELP = 145;
        public const int VFX_IMP_DEATH_WARD = 146;
        public const int VFX_DUR_ELEMENTAL_SHIELD = 147;
        public const int VFX_DUR_LIGHT = 148;
        public const int VFX_IMP_MAGIC_PROTECTION = 149;
        public const int VFX_IMP_SUPER_HEROISM = 150;
        public const int VFX_FNF_STORM = 151;
        public const int VFX_IMP_ELEMENTAL_PROTECTION = 152;
        public const int VFX_DUR_LIGHT_BLUE_5 = 153;
        public const int VFX_DUR_LIGHT_BLUE_10 = 154;
        public const int VFX_DUR_LIGHT_BLUE_15 = 155;
        public const int VFX_DUR_LIGHT_BLUE_20 = 156;
        public const int VFX_DUR_LIGHT_YELLOW_5 = 157;
        public const int VFX_DUR_LIGHT_YELLOW_10 = 158;
        public const int VFX_DUR_LIGHT_YELLOW_15 = 159;
        public const int VFX_DUR_LIGHT_YELLOW_20 = 160;
        public const int VFX_DUR_LIGHT_PURPLE_5 = 161;
        public const int VFX_DUR_LIGHT_PURPLE_10 = 162;
        public const int VFX_DUR_LIGHT_PURPLE_15 = 163;
        public const int VFX_DUR_LIGHT_PURPLE_20 = 164;
        public const int VFX_DUR_LIGHT_RED_5 = 165;
        public const int VFX_DUR_LIGHT_RED_10 = 166;
        public const int VFX_DUR_LIGHT_RED_15 = 167;
        public const int VFX_DUR_LIGHT_RED_20 = 168;
        public const int VFX_DUR_LIGHT_ORANGE_5 = 169;
        public const int VFX_DUR_LIGHT_ORANGE_10 = 170;
        public const int VFX_DUR_LIGHT_ORANGE_15 = 171;
        public const int VFX_DUR_LIGHT_ORANGE_20 = 172;
        public const int VFX_DUR_LIGHT_WHITE_5 = 173;
        public const int VFX_DUR_LIGHT_WHITE_10 = 174;
        public const int VFX_DUR_LIGHT_WHITE_15 = 175;
        public const int VFX_DUR_LIGHT_WHITE_20 = 176;
        public const int VFX_DUR_LIGHT_GREY_5 = 177;
        public const int VFX_DUR_LIGHT_GREY_10 = 178;
        public const int VFX_DUR_LIGHT_GREY_15 = 179;
        public const int VFX_DUR_LIGHT_GREY_20 = 180;
        public const int VFX_IMP_MIRV = 181;
        public const int VFX_DUR_DARKVISION = 182;
        public const int VFX_FNF_SOUND_BURST = 183;
        public const int VFX_FNF_STRIKE_HOLY = 184;
        public const int VFX_FNF_LOS_EVIL_10 = 185;
        public const int VFX_FNF_LOS_EVIL_20 = 186;
        public const int VFX_FNF_LOS_EVIL_30 = 187;
        public const int VFX_FNF_LOS_HOLY_10 = 188;
        public const int VFX_FNF_LOS_HOLY_20 = 189;
        public const int VFX_FNF_LOS_HOLY_30 = 190;
        public const int VFX_FNF_LOS_NORMAL_10 = 191;
        public const int VFX_FNF_LOS_NORMAL_20 = 192;
        public const int VFX_FNF_LOS_NORMAL_30 = 193;
        public const int VFX_IMP_HEAD_ACID = 194;
        public const int VFX_IMP_HEAD_FIRE = 195;
        public const int VFX_IMP_HEAD_SONIC = 196;
        public const int VFX_IMP_HEAD_ELECTRICITY = 197;
        public const int VFX_IMP_HEAD_COLD = 198;
        public const int VFX_IMP_HEAD_HOLY = 199;
        public const int VFX_IMP_HEAD_NATURE = 200;
        public const int VFX_IMP_HEAD_HEAL = 201;
        public const int VFX_IMP_HEAD_MIND = 202;
        public const int VFX_IMP_HEAD_EVIL = 203;
        public const int VFX_IMP_HEAD_ODD = 204;
        public const int VFX_DUR_CESSATE_NEUTRAL = 205;
        public const int VFX_DUR_CESSATE_POSITIVE = 206;
        public const int VFX_DUR_CESSATE_NEGATIVE = 207;
        public const int VFX_DUR_MIND_AFFECTING_DISABLED = 208;
        public const int VFX_DUR_MIND_AFFECTING_DOMINATED = 209;
        public const int VFX_BEAM_FIRE = 210;
        public const int VFX_BEAM_COLD = 211;
        public const int VFX_BEAM_HOLY = 212;
        public const int VFX_BEAM_MIND = 213;
        public const int VFX_BEAM_EVIL = 214;
        public const int VFX_BEAM_ODD = 215;
        public const int VFX_BEAM_FIRE_LASH = 216;
        public const int VFX_IMP_DEATH_L = 217;
        public const int VFX_DUR_MIND_AFFECTING_FEAR = 218;
        public const int VFX_FNF_SUMMON_CELESTIAL = 219;
        public const int VFX_DUR_GLOBE_MINOR = 220;
        public const int VFX_IMP_RESTORATION_LESSER = 221;
        public const int VFX_IMP_RESTORATION = 222;
        public const int VFX_IMP_RESTORATION_GREATER = 223;
        public const int VFX_DUR_PROTECTION_ELEMENTS = 224;
        public const int VFX_DUR_PROTECTION_GOOD_MINOR = 225;
        public const int VFX_DUR_PROTECTION_GOOD_MAJOR = 226;
        public const int VFX_DUR_PROTECTION_EVIL_MINOR = 227;
        public const int VFX_DUR_PROTECTION_EVIL_MAJOR = 228;
        public const int VFX_DUR_MAGICAL_SIGHT = 229;
        public const int VFX_DUR_WEB_MASS = 230;
        public const int VFX_FNF_ICESTORM = 231;
        public const int VFX_DUR_PARALYZED = 232;
        public const int VFX_IMP_MIRV_FLAME = 233;
        public const int VFX_IMP_DESTRUCTION = 234;
        public const int VFX_COM_CHUNK_RED_LARGE = 235;
        public const int VFX_COM_CHUNK_BONE_MEDIUM = 236;
        public const int VFX_COM_BLOOD_SPARK_SMALL = 237;
        public const int VFX_COM_BLOOD_SPARK_MEDIUM = 238;
        public const int VFX_COM_BLOOD_SPARK_LARGE = 239;
        public const int VFX_DUR_GHOSTLY_PULSE = 240;
        public const int VFX_FNF_HORRID_WILTING = 241;
        public const int VFX_DUR_BLINDVISION = 242;
        public const int VFX_DUR_LOWLIGHTVISION = 243;
        public const int VFX_DUR_ULTRAVISION = 244;
        public const int VFX_DUR_MIRV_ACID = 245;
        public const int VFX_IMP_HARM = 246;
        public const int VFX_DUR_BLIND = 247;
        public const int VFX_DUR_ANTI_LIGHT_10 = 248;
        public const int VFX_DUR_MAGIC_RESISTANCE = 249;
        public const int VFX_IMP_MAGIC_RESISTANCE_USE = 250;
        public const int VFX_IMP_GLOBE_USE = 251;
        public const int VFX_IMP_WILL_SAVING_THROW_USE = 252;
        public const int VFX_IMP_SPIKE_TRAP = 253;
        public const int VFX_IMP_SPELL_MANTLE_USE = 254;
        public const int VFX_IMP_FORTITUDE_SAVING_THROW_USE = 255;
        public const int VFX_IMP_REFLEX_SAVE_THROW_USE = 256;
        public const int VFX_FNF_GAS_EXPLOSION_ACID = 257;
        public const int VFX_FNF_GAS_EXPLOSION_EVIL = 258;
        public const int VFX_FNF_GAS_EXPLOSION_NATURE = 259;
        public const int VFX_FNF_GAS_EXPLOSION_FIRE = 260;
        public const int VFX_FNF_GAS_EXPLOSION_GREASE = 261;
        public const int VFX_FNF_GAS_EXPLOSION_MIND = 262;
        public const int VFX_FNF_SMOKE_PUFF = 263;
        public const int VFX_IMP_PULSE_WATER = 264;
        public const int VFX_IMP_PULSE_WIND = 265;
        public const int VFX_IMP_PULSE_NATURE = 266;
        public const int VFX_DUR_AURA_COLD = 267;
        public const int VFX_DUR_AURA_FIRE = 268;
        public const int VFX_DUR_AURA_POISON = 269;
        public const int VFX_DUR_AURA_DISEASE = 270;
        public const int VFX_DUR_AURA_ODD = 271;
        public const int VFX_DUR_AURA_SILENCE = 272;
        public const int VFX_IMP_AURA_HOLY = 273;
        public const int VFX_IMP_AURA_UNEARTHLY = 274;
        public const int VFX_IMP_AURA_FEAR = 275;
        public const int VFX_IMP_AURA_NEGATIVE_ENERGY = 276;
        public const int VFX_DUR_BARD_SONG = 277;
        public const int VFX_FNF_HOWL_MIND = 278;
        public const int VFX_FNF_HOWL_ODD = 279;
        public const int VFX_COM_HIT_FIRE = 280;
        public const int VFX_COM_HIT_FROST = 281;
        public const int VFX_COM_HIT_ELECTRICAL = 282;
        public const int VFX_COM_HIT_ACID = 283;
        public const int VFX_COM_HIT_SONIC = 284;
        public const int VFX_FNF_HOWL_WAR_CRY = 285;
        public const int VFX_FNF_SCREEN_SHAKE = 286;
        public const int VFX_FNF_SCREEN_BUMP = 287;
        public const int VFX_COM_HIT_NEGATIVE = 288;
        public const int VFX_COM_HIT_DIVINE = 289;
        public const int VFX_FNF_HOWL_WAR_CRY_FEMALE = 290;
        public const int VFX_DUR_AURA_DRAGON_FEAR = 291;
        public const int VFX_DUR_FLAG_RED = 303;
        public const int VFX_DUR_FLAG_BLUE = 304;
        public const int VFX_DUR_FLAG_GOLD = 305;
        public const int VFX_DUR_FLAG_PURPLE = 306;
        public const int VFX_DUR_FLAG_GOLD_FIXED = 306;
        public const int VFX_DUR_FLAG_PURPLE_FIXED = 305;
        public const int VFX_DUR_TENTACLE = 346;
        public const int VFX_DUR_PETRIFY = 351;
        public const int VFX_DUR_FREEZE_ANIMATION = 352;
        public const int VFX_COM_CHUNK_STONE_SMALL = 353;
        public const int VFX_COM_CHUNK_STONE_MEDIUM = 354;
        public const int VFX_BEAM_SILENT_LIGHTNING = 307;
        public const int VFX_BEAM_SILENT_FIRE = 308;
        public const int VFX_BEAM_SILENT_COLD = 309;
        public const int VFX_BEAM_SILENT_HOLY = 310;
        public const int VFX_BEAM_SILENT_MIND = 311;
        public const int VFX_BEAM_SILENT_EVIL = 312;
        public const int VFX_BEAM_SILENT_ODD = 313;
        public const int VFX_DUR_BIGBYS_INTERPOSING_HAND = 314;
        public const int VFX_IMP_BIGBYS_FORCEFUL_HAND = 315;
        public const int VFX_DUR_BIGBYS_CLENCHED_FIST = 316;
        public const int VFX_DUR_BIGBYS_CRUSHING_HAND = 317;
        public const int VFX_DUR_BIGBYS_GRASPING_HAND = 318;
        public const int VFX_DUR_CALTROPS = 319;
        public const int VFX_DUR_SMOKE = 320;
        public const int VFX_DUR_PIXIEDUST = 321;
        public const int VFX_FNF_DECK = 322;
        public const int VFX_DUR_CUTSCENE_INVISIBILITY = 355;
        public const int VFX_EYES_RED_FLAME_HUMAN_MALE = 360;
        public const int VFX_EYES_RED_FLAME_HUMAN_FEMALE = 361;
        public const int VFX_EYES_RED_FLAME_HALFELF_MALE = 360;
        public const int VFX_EYES_RED_FLAME_HALFELF_FEMALE = 361;
        public const int VFX_EYES_RED_FLAME_DWARF_MALE = 362;
        public const int VFX_EYES_RED_FLAME_DWARF_FEMALE = 363;
        public const int VFX_EYES_RED_FLAME_ELF_MALE = 364;
        public const int VFX_EYES_RED_FLAME_ELF_FEMALE = 365;
        public const int VFX_EYES_RED_FLAME_GNOME_MALE = 366;
        public const int VFX_EYES_RED_FLAME_GNOME_FEMALE = 367;
        public const int VFX_EYES_RED_FLAME_HALFLING_MALE = 368;
        public const int VFX_EYES_RED_FLAME_HALFLING_FEMALE = 369;
        public const int VFX_EYES_RED_FLAME_HALFORC_MALE = 370;
        public const int VFX_EYES_RED_FLAME_HALFORC_FEMALE = 371;
        public const int VFX_EYES_RED_FLAME_TROGLODYTE = 372;
        public const int VFX_EYES_YEL_HUMAN_MALE = 373;
        public const int VFX_EYES_YEL_HUMAN_FEMALE = 374;
        public const int VFX_EYES_YEL_DWARF_MALE = 375;
        public const int VFX_EYES_YEL_DWARF_FEMALE = 376;
        public const int VFX_EYES_YEL_ELF_MALE = 377;
        public const int VFX_EYES_YEL_ELF_FEMALE = 378;
        public const int VFX_EYES_YEL_GNOME_MALE = 379;
        public const int VFX_EYES_YEL_GNOME_FEMALE = 380;
        public const int VFX_EYES_YEL_HALFLING_MALE = 381;
        public const int VFX_EYES_YEL_HALFLING_FEMALE = 382;
        public const int VFX_EYES_YEL_HALFORC_MALE = 383;
        public const int VFX_EYES_YEL_HALFORC_FEMALE = 384;
        public const int VFX_EYES_YEL_TROGLODYTE = 385;
        public const int VFX_EYES_ORG_HUMAN_MALE = 386;
        public const int VFX_EYES_ORG_HUMAN_FEMALE = 387;
        public const int VFX_EYES_ORG_DWARF_MALE = 388;
        public const int VFX_EYES_ORG_DWARF_FEMALE = 389;
        public const int VFX_EYES_ORG_ELF_MALE = 390;
        public const int VFX_EYES_ORG_ELF_FEMALE = 391;
        public const int VFX_EYES_ORG_GNOME_MALE = 392;
        public const int VFX_EYES_ORG_GNOME_FEMALE = 393;
        public const int VFX_EYES_ORG_HALFLING_MALE = 394;
        public const int VFX_EYES_ORG_HALFLING_FEMALE = 395;
        public const int VFX_EYES_ORG_HALFORC_MALE = 396;
        public const int VFX_EYES_ORG_HALFORC_FEMALE = 397;
        public const int VFX_EYES_ORG_TROGLODYTE = 398;
        public const int VFX_DUR_IOUNSTONE = 403;
        public const int VFX_IMP_TORNADO = 407;
        public const int VFX_DUR_GLOW_LIGHT_BLUE = 408;
        public const int VFX_DUR_GLOW_PURPLE = 409;
        public const int VFX_DUR_GLOW_BLUE = 410;
        public const int VFX_DUR_GLOW_RED = 411;
        public const int VFX_DUR_GLOW_LIGHT_RED = 412;
        public const int VFX_DUR_GLOW_YELLOW = 413;
        public const int VFX_DUR_GLOW_LIGHT_YELLOW = 414;
        public const int VFX_DUR_GLOW_GREEN = 415;
        public const int VFX_DUR_GLOW_LIGHT_GREEN = 416;
        public const int VFX_DUR_GLOW_ORANGE = 417;
        public const int VFX_DUR_GLOW_LIGHT_ORANGE = 418;
        public const int VFX_DUR_GLOW_BROWN = 419;
        public const int VFX_DUR_GLOW_LIGHT_BROWN = 420;
        public const int VFX_DUR_GLOW_GREY = 421;
        public const int VFX_DUR_GLOW_WHITE = 422;
        public const int VFX_DUR_GLOW_LIGHT_PURPLE = 423;
        public const int VFX_DUR_GHOST_TRANSPARENT = 424;
        public const int VFX_DUR_GHOST_SMOKE = 425;
        public const int VFX_DUR_GLYPH_OF_WARDING = 445;
        public const int VFX_FNF_SOUND_BURST_SILENT = 446;
        public const int VFX_BEAM_DISINTEGRATE = 447;
        public const int VFX_FNF_ELECTRIC_EXPLOSION = 459;
        public const int VFX_IMP_DUST_EXPLOSION = 460;
        public const int VFX_IMP_PULSE_HOLY_SILENT = 461;
        public const int VFX_DUR_DEATH_ARMOR = 463;
        public const int VFX_DUR_ICESKIN = 465;
        public const int VFX_FNF_SWINGING_BLADE = 473;
        public const int VFX_DUR_INFERNO = 474;
        public const int VFX_FNF_DEMON_HAND = 475;
        public const int VFX_DUR_STONEHOLD = 476;
        public const int VFX_FNF_MYSTICAL_EXPLOSION = 477;
        public const int VFX_DUR_GHOSTLY_VISAGE_NO_SOUND = 478;
        public const int VFX_DUR_GHOST_SMOKE_2 = 479;
        public const int VFX_DUR_FLIES = 480;
        public const int VFX_FNF_SUMMONDRAGON = 481;
        public const int VFX_BEAM_FIRE_W = 482;
        public const int VFX_BEAM_FIRE_W_SILENT = 483;
        public const int VFX_BEAM_CHAIN = 484;
        public const int VFX_BEAM_BLACK = 485;
        public const int VFX_IMP_WALLSPIKE = 486;
        public const int VFX_FNF_GREATER_RUIN = 487;
        public const int VFX_FNF_UNDEAD_DRAGON = 488;
        public const int VFX_DUR_PROT_EPIC_ARMOR = 495;
        public const int VFX_FNF_SUMMON_EPIC_UNDEAD = 496;
        public const int VFX_DUR_PROT_EPIC_ARMOR_2 = 497;
        public const int VFX_DUR_INFERNO_CHEST = 498;
        public const int VFX_DUR_IOUNSTONE_RED = 499;
        public const int VFX_DUR_IOUNSTONE_BLUE = 500;
        public const int VFX_DUR_IOUNSTONE_YELLOW = 501;
        public const int VFX_DUR_IOUNSTONE_GREEN = 502;
        public const int VFX_IMP_MIRV_ELECTRIC = 503;
        public const int VFX_COM_CHUNK_RED_BALLISTA = 504;
        public const int VFX_DUR_INFERNO_NO_SOUND = 505;
        public const int VFX_DUR_AURA_PULSE_RED_WHITE = 512;
        public const int VFX_DUR_AURA_PULSE_BLUE_WHITE = 513;
        public const int VFX_DUR_AURA_PULSE_GREEN_WHITE = 514;
        public const int VFX_DUR_AURA_PULSE_YELLOW_WHITE = 515;
        public const int VFX_DUR_AURA_PULSE_MAGENTA_WHITE = 516;
        public const int VFX_DUR_AURA_PULSE_CYAN_WHITE = 517;
        public const int VFX_DUR_AURA_PULSE_ORANGE_WHITE = 518;
        public const int VFX_DUR_AURA_PULSE_BROWN_WHITE = 519;
        public const int VFX_DUR_AURA_PULSE_PURPLE_WHITE = 520;
        public const int VFX_DUR_AURA_PULSE_GREY_WHITE = 521;
        public const int VFX_DUR_AURA_PULSE_GREY_BLACK = 522;
        public const int VFX_DUR_AURA_PULSE_BLUE_GREEN = 523;
        public const int VFX_DUR_AURA_PULSE_RED_BLUE = 524;
        public const int VFX_DUR_AURA_PULSE_RED_YELLOW = 525;
        public const int VFX_DUR_AURA_PULSE_GREEN_YELLOW = 526;
        public const int VFX_DUR_AURA_PULSE_RED_GREEN = 527;
        public const int VFX_DUR_AURA_PULSE_BLUE_YELLOW = 528;
        public const int VFX_DUR_AURA_PULSE_BLUE_BLACK = 529;
        public const int VFX_DUR_AURA_PULSE_RED_BLACK = 530;
        public const int VFX_DUR_AURA_PULSE_GREEN_BLACK = 531;
        public const int VFX_DUR_AURA_PULSE_YELLOW_BLACK = 532;
        public const int VFX_DUR_AURA_PULSE_MAGENTA_BLACK = 533;
        public const int VFX_DUR_AURA_PULSE_CYAN_BLACK = 534;
        public const int VFX_DUR_AURA_PULSE_ORANGE_BLACK = 535;
        public const int VFX_DUR_AURA_PULSE_BROWN_BLACK = 536;
        public const int VFX_DUR_AURA_PULSE_PURPLE_BLACK = 537;
        public const int VFX_DUR_AURA_PULSE_CYAN_GREEN = 538;
        public const int VFX_DUR_AURA_PULSE_CYAN_BLUE = 539;
        public const int VFX_DUR_AURA_PULSE_CYAN_RED = 540;
        public const int VFX_DUR_AURA_PULSE_CYAN_YELLOW = 541;
        public const int VFX_DUR_AURA_PULSE_MAGENTA_BLUE = 542;
        public const int VFX_DUR_AURA_PULSE_MAGENTA_RED = 543;
        public const int VFX_DUR_AURA_PULSE_MAGENTA_GREEN = 544;
        public const int VFX_DUR_AURA_PULSE_MAGENTA_YELLOW = 545;
        public const int VFX_DUR_AURA_PULSE_RED_ORANGE = 546;
        public const int VFX_DUR_AURA_PULSE_YELLOW_ORANGE = 547;
        public const int VFX_DUR_AURA_RED = 548;
        public const int VFX_DUR_AURA_GREEN = 549;
        public const int VFX_DUR_AURA_BLUE = 550;
        public const int VFX_DUR_AURA_MAGENTA = 551;
        public const int VFX_DUR_AURA_YELLOW = 552;
        public const int VFX_DUR_AURA_WHITE = 553;
        public const int VFX_DUR_AURA_ORANGE = 554;
        public const int VFX_DUR_AURA_BROWN = 555;
        public const int VFX_DUR_AURA_PURPLE = 556;
        public const int VFX_DUR_AURA_CYAN = 557;
        public const int VFX_DUR_AURA_GREEN_DARK = 558;
        public const int VFX_DUR_AURA_GREEN_LIGHT = 559;
        public const int VFX_DUR_AURA_RED_DARK = 560;
        public const int VFX_DUR_AURA_RED_LIGHT = 561;
        public const int VFX_DUR_AURA_BLUE_DARK = 562;
        public const int VFX_DUR_AURA_BLUE_LIGHT = 563;
        public const int VFX_DUR_AURA_YELLOW_DARK = 564;
        public const int VFX_DUR_AURA_YELLOW_LIGHT = 565;
        public const int VFX_DUR_BUBBLES = 566;
        public const int VFX_EYES_GREEN_HUMAN_MALE = 567;
        public const int VFX_EYES_GREEN_HUMAN_FEMALE = 568;
        public const int VFX_EYES_GREEN_HALFELF_MALE = 567;
        public const int VFX_EYES_GREEN_HALFELF_FEMALE = 568;
        public const int VFX_EYES_GREEN_DWARF_MALE = 569;
        public const int VFX_EYES_GREEN_DWARF_FEMALE = 570;
        public const int VFX_EYES_GREEN_ELF_MALE = 571;
        public const int VFX_EYES_GREEN_ELF_FEMALE = 572;
        public const int VFX_EYES_GREEN_GNOME_MALE = 573;
        public const int VFX_EYES_GREEN_GNOME_FEMALE = 574;
        public const int VFX_EYES_GREEN_HALFLING_MALE = 575;
        public const int VFX_EYES_GREEN_HALFLING_FEMALE = 576;
        public const int VFX_EYES_GREEN_HALFORC_MALE = 577;
        public const int VFX_EYES_GREEN_HALFORC_FEMALE = 578;
        public const int VFX_EYES_GREEN_TROGLODYTE = 579;
        public const int VFX_EYES_PUR_HUMAN_MALE = 580;
        public const int VFX_EYES_PUR_HUMAN_FEMALE = 581;
        public const int VFX_EYES_PUR_DWARF_MALE = 582;
        public const int VFX_EYES_PUR_DWARF_FEMALE = 583;
        public const int VFX_EYES_PUR_ELF_MALE = 584;
        public const int VFX_EYES_PUR_ELF_FEMALE = 585;
        public const int VFX_EYES_PUR_GNOME_MALE = 586;
        public const int VFX_EYES_PUR_GNOME_FEMALE = 587;
        public const int VFX_EYES_PUR_HALFLING_MALE = 588;
        public const int VFX_EYES_PUR_HALFLING_FEMALE = 589;
        public const int VFX_EYES_PUR_HALFORC_MALE = 590;
        public const int VFX_EYES_PUR_HALFORC_FEMALE = 591;
        public const int VFX_EYES_PUR_TROGLODYTE = 592;
        public const int VFX_EYES_CYN_HUMAN_MALE = 593;
        public const int VFX_EYES_CYN_HUMAN_FEMALE = 594;
        public const int VFX_EYES_CYN_DWARF_MALE = 595;
        public const int VFX_EYES_CYN_DWARF_FEMALE = 596;
        public const int VFX_EYES_CYN_ELF_MALE = 597;
        public const int VFX_EYES_CYN_ELF_FEMALE = 598;
        public const int VFX_EYES_CYN_GNOME_MALE = 599;
        public const int VFX_EYES_CYN_GNOME_FEMALE = 600;
        public const int VFX_EYES_CYN_HALFLING_MALE = 601;
        public const int VFX_EYES_CYN_HALFLING_FEMALE = 602;
        public const int VFX_EYES_CYN_HALFORC_MALE = 603;
        public const int VFX_EYES_CYN_HALFORC_FEMALE = 604;
        public const int VFX_EYES_CYN_TROGLODYTE = 605;
        public const int VFX_EYES_WHT_HUMAN_MALE = 606;
        public const int VFX_EYES_WHT_HUMAN_FEMALE = 607;
        public const int VFX_EYES_WHT_DWARF_MALE = 608;
        public const int VFX_EYES_WHT_DWARF_FEMALE = 609;
        public const int VFX_EYES_WHT_ELF_MALE = 610;
        public const int VFX_EYES_WHT_ELF_FEMALE = 611;
        public const int VFX_EYES_WHT_GNOME_MALE = 612;
        public const int VFX_EYES_WHT_GNOME_FEMALE = 613;
        public const int VFX_EYES_WHT_HALFLING_MALE = 614;
        public const int VFX_EYES_WHT_HALFLING_FEMALE = 615;
        public const int VFX_EYES_WHT_HALFORC_MALE = 616;
        public const int VFX_EYES_WHT_HALFORC_FEMALE = 617;
        public const int VFX_EYES_WHT_TROGLODYTE = 618;
        public const int VFX_IMP_PDK_GENERIC_PULSE = 623;
        public const int VFX_IMP_PDK_GENERIC_HEAD_HIT = 624;
        public const int VFX_IMP_PDK_RALLYING_CRY = 625;
        public const int VFX_IMP_PDK_HEROIC_SHIELD = 626;
        public const int VFX_IMP_PDK_INSPIRE_COURAGE = 627;
        public const int VFX_DUR_PDK_FEAR = 628;
        public const int VFX_IMP_PDK_WRATH = 629;
        public const int VFX_IMP_PDK_OATH = 630;
        public const int VFX_IMP_PDK_FINAL_STAND = 631;
        public const int VFX_DUR_ARROW_IN_STERNUM = 632;
        public const int VFX_DUR_ARROW_IN_CHEST_LEFT = 633;
        public const int VFX_DUR_ARROW_IN_CHEST_RIGHT = 634;
        public const int VFX_DUR_ARROW_IN_BACK = 635;
        public const int VFX_DUR_ARROW_IN_TEMPLES = 636;
        public const int VFX_DUR_ARROW_IN_FACE = 637;
        public const int VFX_DUR_ARROW_IN_HEAD = 638;
        public const int VFX_DUR_QUILL_IN_CHEST = 639;
        public const int VFX_IMP_STARBURST_GREEN = 644;
        public const int VFX_IMP_STARBURST_RED = 645;
        public const int VFX_IMP_NIGHTMARE_HEAD_HIT = 670;
        // VFX_Persistent.2da
        public const int AOE_PER_FOGACID = 0;
        public const int AOE_PER_FOGFIRE = 1;
        public const int AOE_PER_FOGSTINK = 2;
        public const int AOE_PER_FOGKILL = 3;
        public const int AOE_PER_FOGMIND = 4;
        public const int AOE_PER_WALLFIRE = 5;
        public const int AOE_PER_WALLWIND = 6;
        public const int AOE_PER_WALLBLADE = 7;
        public const int AOE_PER_WEB = 8;
        public const int AOE_PER_ENTANGLE = 9;
        // int AOE_PER_CHAOS = 10;
        public const int AOE_PER_DARKNESS = 11;
        public const int AOE_MOB_CIRCEVIL = 12;
        public const int AOE_MOB_CIRCGOOD = 13;
        public const int AOE_MOB_CIRCLAW = 14;
        public const int AOE_MOB_CIRCCHAOS = 15;
        public const int AOE_MOB_FEAR = 16;
        public const int AOE_MOB_BLINDING = 17;
        public const int AOE_MOB_UNEARTHLY = 18;
        public const int AOE_MOB_MENACE = 19;
        public const int AOE_MOB_UNNATURAL = 20;
        public const int AOE_MOB_STUN = 21;
        public const int AOE_MOB_PROTECTION = 22;
        public const int AOE_MOB_FIRE = 23;
        public const int AOE_MOB_FROST = 24;
        public const int AOE_MOB_ELECTRICAL = 25;
        public const int AOE_PER_FOGGHOUL = 26;
        public const int AOE_MOB_TYRANT_FOG = 27;
        public const int AOE_PER_STORM = 28;
        public const int AOE_PER_INVIS_SPHERE = 29;
        public const int AOE_MOB_SILENCE = 30;
        public const int AOE_PER_DELAY_BLAST_FIREBALL = 31;
        public const int AOE_PER_GREASE = 32;
        public const int AOE_PER_CREEPING_DOOM = 33;
        public const int AOE_PER_EVARDS_BLACK_TENTACLES = 34;
        public const int AOE_MOB_INVISIBILITY_PURGE = 35;
        public const int AOE_MOB_DRAGON_FEAR = 36;
        public const int AOE_PER_CUSTOM_AOE = 37;
        public const int AOE_PER_GLYPH_OF_WARDING = 38;
        public const int AOE_PER_FOG_OF_BEWILDERMENT = 39;
        public const int AOE_PER_VINE_MINE_CAMOUFLAGE = 40;
        public const int AOE_MOB_TIDE_OF_BATTLE = 41;
        public const int AOE_PER_STONEHOLD = 42;
        public const int AOE_PER_OVERMIND = 43;
        public const int AOE_MOB_HORRIFICAPPEARANCE = 44;
        public const int AOE_MOB_TROGLODYTE_STENCH = 45;
        public const int SPELL_ALL_SPELLS = -1;
        //  used for spell immunity.
        public const int SPELL_ACID_FOG = 0;
        public const int SPELL_AID = 1;
        public const int SPELL_ANIMATE_DEAD = 2;
        public const int SPELL_BARKSKIN = 3;
        public const int SPELL_BESTOW_CURSE = 4;
        public const int SPELL_BLADE_BARRIER = 5;
        public const int SPELL_BLESS = 6;
        public const int SPELL_BLESS_WEAPON = 537;
        public const int SPELL_BLINDNESS_AND_DEAFNESS = 8;
        public const int SPELL_BULLS_STRENGTH = 9;
        public const int SPELL_BURNING_HANDS = 10;
        public const int SPELL_CALL_LIGHTNING = 11;
        // int SPELL_CALM_EMOTIONS = 12;
        public const int SPELL_CATS_GRACE = 13;
        public const int SPELL_CHAIN_LIGHTNING = 14;
        public const int SPELL_CHARM_MONSTER = 15;
        public const int SPELL_CHARM_PERSON = 16;
        public const int SPELL_CHARM_PERSON_OR_ANIMAL = 17;
        public const int SPELL_CIRCLE_OF_DEATH = 18;
        public const int SPELL_CIRCLE_OF_DOOM = 19;
        public const int SPELL_CLAIRAUDIENCE_AND_CLAIRVOYANCE = 20;
        public const int SPELL_CLARITY = 21;
        public const int SPELL_CLOAK_OF_CHAOS = 22;
        public const int SPELL_CLOUDKILL = 23;
        public const int SPELL_COLOR_SPRAY = 24;
        public const int SPELL_CONE_OF_COLD = 25;
        public const int SPELL_CONFUSION = 26;
        public const int SPELL_CONTAGION = 27;
        public const int SPELL_CONTROL_UNDEAD = 28;
        public const int SPELL_CREATE_GREATER_UNDEAD = 29;
        public const int SPELL_CREATE_UNDEAD = 30;
        public const int SPELL_CURE_CRITICAL_WOUNDS = 31;
        public const int SPELL_CURE_LIGHT_WOUNDS = 32;
        public const int SPELL_CURE_MINOR_WOUNDS = 33;
        public const int SPELL_CURE_MODERATE_WOUNDS = 34;
        public const int SPELL_CURE_SERIOUS_WOUNDS = 35;
        public const int SPELL_DARKNESS = 36;
        public const int SPELL_DAZE = 37;
        public const int SPELL_DEATH_WARD = 38;
        public const int SPELL_DELAYED_BLAST_FIREBALL = 39;
        public const int SPELL_DISMISSAL = 40;
        public const int SPELL_DISPEL_MAGIC = 41;
        public const int SPELL_DIVINE_POWER = 42;
        public const int SPELL_DOMINATE_ANIMAL = 43;
        public const int SPELL_DOMINATE_MONSTER = 44;
        public const int SPELL_DOMINATE_PERSON = 45;
        public const int SPELL_DOOM = 46;
        public const int SPELL_ELEMENTAL_SHIELD = 47;
        public const int SPELL_ELEMENTAL_SWARM = 48;
        public const int SPELL_ENDURANCE = 49;
        public const int SPELL_ENDURE_ELEMENTS = 50;
        public const int SPELL_ENERGY_DRAIN = 51;
        public const int SPELL_ENERVATION = 52;
        public const int SPELL_ENTANGLE = 53;
        public const int SPELL_FEAR = 54;
        public const int SPELL_FEEBLEMIND = 55;
        public const int SPELL_FINGER_OF_DEATH = 56;
        public const int SPELL_FIRE_STORM = 57;
        public const int SPELL_FIREBALL = 58;
        public const int SPELL_FLAME_ARROW = 59;
        public const int SPELL_FLAME_LASH = 60;
        public const int SPELL_FLAME_STRIKE = 61;
        public const int SPELL_FREEDOM_OF_MOVEMENT = 62;
        public const int SPELL_GATE = 63;
        public const int SPELL_GHOUL_TOUCH = 64;
        public const int SPELL_GLOBE_OF_INVULNERABILITY = 65;
        public const int SPELL_GREASE = 66;
        public const int SPELL_GREATER_DISPELLING = 67;
        // int SPELL_GREATER_MAGIC_WEAPON              = 68;
        public const int SPELL_GREATER_PLANAR_BINDING = 69;
        public const int SPELL_GREATER_RESTORATION = 70;
        // int SPELL_GREATER_SHADOW_CONJURATION = 71;
        public const int SPELL_GREATER_SPELL_BREACH = 72;
        public const int SPELL_GREATER_SPELL_MANTLE = 73;
        public const int SPELL_GREATER_STONESKIN = 74;
        public const int SPELL_GUST_OF_WIND = 75;
        public const int SPELL_HAMMER_OF_THE_GODS = 76;
        public const int SPELL_HARM = 77;
        public const int SPELL_HASTE = 78;
        public const int SPELL_HEAL = 79;
        public const int SPELL_HEALING_CIRCLE = 80;
        public const int SPELL_HOLD_ANIMAL = 81;
        public const int SPELL_HOLD_MONSTER = 82;
        public const int SPELL_HOLD_PERSON = 83;
        public const int SPELL_HOLY_AURA = 84;
        public const int SPELL_HOLY_SWORD = 538;
        public const int SPELL_IDENTIFY = 86;
        public const int SPELL_IMPLOSION = 87;
        public const int SPELL_IMPROVED_INVISIBILITY = 88;
        public const int SPELL_INCENDIARY_CLOUD = 89;
        public const int SPELL_INVISIBILITY = 90;
        public const int SPELL_INVISIBILITY_PURGE = 91;
        public const int SPELL_INVISIBILITY_SPHERE = 92;
        public const int SPELL_KNOCK = 93;
        public const int SPELL_LESSER_DISPEL = 94;
        public const int SPELL_LESSER_MIND_BLANK = 95;
        public const int SPELL_LESSER_PLANAR_BINDING = 96;
        public const int SPELL_LESSER_RESTORATION = 97;
        public const int SPELL_LESSER_SPELL_BREACH = 98;
        public const int SPELL_LESSER_SPELL_MANTLE = 99;
        public const int SPELL_LIGHT = 100;
        public const int SPELL_LIGHTNING_BOLT = 101;
        public const int SPELL_MAGE_ARMOR = 102;
        public const int SPELL_MAGIC_CIRCLE_AGAINST_CHAOS = 103;
        public const int SPELL_MAGIC_CIRCLE_AGAINST_EVIL = 104;
        public const int SPELL_MAGIC_CIRCLE_AGAINST_GOOD = 105;
        public const int SPELL_MAGIC_CIRCLE_AGAINST_LAW = 106;
        public const int SPELL_MAGIC_MISSILE = 107;
        public const int SPELL_MAGIC_VESTMENT = 546;
        // int SPELL_MAGIC_WEAPON                      = 109;
        public const int SPELL_MASS_BLINDNESS_AND_DEAFNESS = 110;
        public const int SPELL_MASS_CHARM = 111;
        //  int SPELL_MASS_DOMINATION = 112;
        public const int SPELL_MASS_HASTE = 113;
        public const int SPELL_MASS_HEAL = 114;
        public const int SPELL_MELFS_ACID_ARROW = 115;
        public const int SPELL_METEOR_SWARM = 116;
        public const int SPELL_MIND_BLANK = 117;
        public const int SPELL_MIND_FOG = 118;
        public const int SPELL_MINOR_GLOBE_OF_INVULNERABILITY = 119;
        public const int SPELL_GHOSTLY_VISAGE = 120;
        public const int SPELL_ETHEREAL_VISAGE = 121;
        public const int SPELL_MORDENKAINENS_DISJUNCTION = 122;
        public const int SPELL_MORDENKAINENS_SWORD = 123;
        public const int SPELL_NATURES_BALANCE = 124;
        public const int SPELL_NEGATIVE_ENERGY_PROTECTION = 125;
        public const int SPELL_NEUTRALIZE_POISON = 126;
        public const int SPELL_PHANTASMAL_KILLER = 127;
        public const int SPELL_PLANAR_BINDING = 128;
        public const int SPELL_POISON = 129;
        public const int SPELL_POLYMORPH_SELF = 130;
        public const int SPELL_POWER_WORD_KILL = 131;
        public const int SPELL_POWER_WORD_STUN = 132;
        public const int SPELL_PRAYER = 133;
        public const int SPELL_PREMONITION = 134;
        public const int SPELL_PRISMATIC_SPRAY = 135;
        public const int SPELL_PROTECTION__FROM_CHAOS = 136;
        public const int SPELL_PROTECTION_FROM_ELEMENTS = 137;
        public const int SPELL_PROTECTION_FROM_EVIL = 138;
        public const int SPELL_PROTECTION_FROM_GOOD = 139;
        public const int SPELL_PROTECTION_FROM_LAW = 140;
        public const int SPELL_PROTECTION_FROM_SPELLS = 141;
        public const int SPELL_RAISE_DEAD = 142;
        public const int SPELL_RAY_OF_ENFEEBLEMENT = 143;
        public const int SPELL_RAY_OF_FROST = 144;
        public const int SPELL_REMOVE_BLINDNESS_AND_DEAFNESS = 145;
        public const int SPELL_REMOVE_CURSE = 146;
        public const int SPELL_REMOVE_DISEASE = 147;
        public const int SPELL_REMOVE_FEAR = 148;
        public const int SPELL_REMOVE_PARALYSIS = 149;
        public const int SPELL_RESIST_ELEMENTS = 150;
        public const int SPELL_RESISTANCE = 151;
        public const int SPELL_RESTORATION = 152;
        public const int SPELL_RESURRECTION = 153;
        public const int SPELL_SANCTUARY = 154;
        public const int SPELL_SCARE = 155;
        public const int SPELL_SEARING_LIGHT = 156;
        public const int SPELL_SEE_INVISIBILITY = 157;
        // int SPELL_SHADES = 158;
        // int SPELL_SHADOW_CONJURATION = 159;
        public const int SPELL_SHADOW_SHIELD = 160;
        public const int SPELL_SHAPECHANGE = 161;
        public const int SPELL_SHIELD_OF_LAW = 162;
        public const int SPELL_SILENCE = 163;
        public const int SPELL_SLAY_LIVING = 164;
        public const int SPELL_SLEEP = 165;
        public const int SPELL_SLOW = 166;
        public const int SPELL_SOUND_BURST = 167;
        public const int SPELL_SPELL_RESISTANCE = 168;
        public const int SPELL_SPELL_MANTLE = 169;
        public const int SPELL_SPHERE_OF_CHAOS = 170;
        public const int SPELL_STINKING_CLOUD = 171;
        public const int SPELL_STONESKIN = 172;
        public const int SPELL_STORM_OF_VENGEANCE = 173;
        public const int SPELL_SUMMON_CREATURE_I = 174;
        public const int SPELL_SUMMON_CREATURE_II = 175;
        public const int SPELL_SUMMON_CREATURE_III = 176;
        public const int SPELL_SUMMON_CREATURE_IV = 177;
        public const int SPELL_SUMMON_CREATURE_IX = 178;
        public const int SPELL_SUMMON_CREATURE_V = 179;
        public const int SPELL_SUMMON_CREATURE_VI = 180;
        public const int SPELL_SUMMON_CREATURE_VII = 181;
        public const int SPELL_SUMMON_CREATURE_VIII = 182;
        public const int SPELL_SUNBEAM = 183;
        public const int SPELL_TENSERS_TRANSFORMATION = 184;
        public const int SPELL_TIME_STOP = 185;
        public const int SPELL_TRUE_SEEING = 186;
        public const int SPELL_UNHOLY_AURA = 187;
        public const int SPELL_VAMPIRIC_TOUCH = 188;
        public const int SPELL_VIRTUE = 189;
        public const int SPELL_WAIL_OF_THE_BANSHEE = 190;
        public const int SPELL_WALL_OF_FIRE = 191;
        public const int SPELL_WEB = 192;
        public const int SPELL_WEIRD = 193;
        public const int SPELL_WORD_OF_FAITH = 194;
        public const int SPELLABILITY_AURA_BLINDING = 195;
        public const int SPELLABILITY_AURA_COLD = 196;
        public const int SPELLABILITY_AURA_ELECTRICITY = 197;
        public const int SPELLABILITY_AURA_FEAR = 198;
        public const int SPELLABILITY_AURA_FIRE = 199;
        public const int SPELLABILITY_AURA_MENACE = 200;
        public const int SPELLABILITY_AURA_PROTECTION = 201;
        public const int SPELLABILITY_AURA_STUN = 202;
        public const int SPELLABILITY_AURA_UNEARTHLY_VISAGE = 203;
        public const int SPELLABILITY_AURA_UNNATURAL = 204;
        public const int SPELLABILITY_BOLT_ABILITY_DRAIN_CHARISMA = 205;
        public const int SPELLABILITY_BOLT_ABILITY_DRAIN_CONSTITUTION = 206;
        public const int SPELLABILITY_BOLT_ABILITY_DRAIN_DEXTERITY = 207;
        public const int SPELLABILITY_BOLT_ABILITY_DRAIN_INTELLIGENCE = 208;
        public const int SPELLABILITY_BOLT_ABILITY_DRAIN_STRENGTH = 209;
        public const int SPELLABILITY_BOLT_ABILITY_DRAIN_WISDOM = 210;
        public const int SPELLABILITY_BOLT_ACID = 211;
        public const int SPELLABILITY_BOLT_CHARM = 212;
        public const int SPELLABILITY_BOLT_COLD = 213;
        public const int SPELLABILITY_BOLT_CONFUSE = 214;
        public const int SPELLABILITY_BOLT_DAZE = 215;
        public const int SPELLABILITY_BOLT_DEATH = 216;
        public const int SPELLABILITY_BOLT_DISEASE = 217;
        public const int SPELLABILITY_BOLT_DOMINATE = 218;
        public const int SPELLABILITY_BOLT_FIRE = 219;
        public const int SPELLABILITY_BOLT_KNOCKDOWN = 220;
        public const int SPELLABILITY_BOLT_LEVEL_DRAIN = 221;
        public const int SPELLABILITY_BOLT_LIGHTNING = 222;
        public const int SPELLABILITY_BOLT_PARALYZE = 223;
        public const int SPELLABILITY_BOLT_POISON = 224;
        public const int SPELLABILITY_BOLT_SHARDS = 225;
        public const int SPELLABILITY_BOLT_SLOW = 226;
        public const int SPELLABILITY_BOLT_STUN = 227;
        public const int SPELLABILITY_BOLT_WEB = 228;
        public const int SPELLABILITY_CONE_ACID = 229;
        public const int SPELLABILITY_CONE_COLD = 230;
        public const int SPELLABILITY_CONE_DISEASE = 231;
        public const int SPELLABILITY_CONE_FIRE = 232;
        public const int SPELLABILITY_CONE_LIGHTNING = 233;
        public const int SPELLABILITY_CONE_POISON = 234;
        public const int SPELLABILITY_CONE_SONIC = 235;
        public const int SPELLABILITY_DRAGON_BREATH_ACID = 236;
        public const int SPELLABILITY_DRAGON_BREATH_COLD = 237;
        public const int SPELLABILITY_DRAGON_BREATH_FEAR = 238;
        public const int SPELLABILITY_DRAGON_BREATH_FIRE = 239;
        public const int SPELLABILITY_DRAGON_BREATH_GAS = 240;
        public const int SPELLABILITY_DRAGON_BREATH_LIGHTNING = 241;
        public const int SPELLABILITY_DRAGON_BREATH_PARALYZE = 242;
        public const int SPELLABILITY_DRAGON_BREATH_SLEEP = 243;
        public const int SPELLABILITY_DRAGON_BREATH_SLOW = 244;
        public const int SPELLABILITY_DRAGON_BREATH_WEAKEN = 245;
        public const int SPELLABILITY_DRAGON_WING_BUFFET = 246;
        public const int SPELLABILITY_FEROCITY_1 = 247;
        public const int SPELLABILITY_FEROCITY_2 = 248;
        public const int SPELLABILITY_FEROCITY_3 = 249;
        public const int SPELLABILITY_GAZE_CHARM = 250;
        public const int SPELLABILITY_GAZE_CONFUSION = 251;
        public const int SPELLABILITY_GAZE_DAZE = 252;
        public const int SPELLABILITY_GAZE_DEATH = 253;
        public const int SPELLABILITY_GAZE_DESTROY_CHAOS = 254;
        public const int SPELLABILITY_GAZE_DESTROY_EVIL = 255;
        public const int SPELLABILITY_GAZE_DESTROY_GOOD = 256;
        public const int SPELLABILITY_GAZE_DESTROY_LAW = 257;
        public const int SPELLABILITY_GAZE_DOMINATE = 258;
        public const int SPELLABILITY_GAZE_DOOM = 259;
        public const int SPELLABILITY_GAZE_FEAR = 260;
        public const int SPELLABILITY_GAZE_PARALYSIS = 261;
        public const int SPELLABILITY_GAZE_STUNNED = 262;
        public const int SPELLABILITY_GOLEM_BREATH_GAS = 263;
        public const int SPELLABILITY_HELL_HOUND_FIREBREATH = 264;
        public const int SPELLABILITY_HOWL_CONFUSE = 265;
        public const int SPELLABILITY_HOWL_DAZE = 266;
        public const int SPELLABILITY_HOWL_DEATH = 267;
        public const int SPELLABILITY_HOWL_DOOM = 268;
        public const int SPELLABILITY_HOWL_FEAR = 269;
        public const int SPELLABILITY_HOWL_PARALYSIS = 270;
        public const int SPELLABILITY_HOWL_SONIC = 271;
        public const int SPELLABILITY_HOWL_STUN = 272;
        public const int SPELLABILITY_INTENSITY_1 = 273;
        public const int SPELLABILITY_INTENSITY_2 = 274;
        public const int SPELLABILITY_INTENSITY_3 = 275;
        public const int SPELLABILITY_KRENSHAR_SCARE = 276;
        public const int SPELLABILITY_LESSER_BODY_ADJUSTMENT = 277;
        public const int SPELLABILITY_MEPHIT_SALT_BREATH = 278;
        public const int SPELLABILITY_MEPHIT_STEAM_BREATH = 279;
        public const int SPELLABILITY_MUMMY_BOLSTER_UNDEAD = 280;
        public const int SPELLABILITY_PULSE_DROWN = 281;
        public const int SPELLABILITY_PULSE_SPORES = 282;
        public const int SPELLABILITY_PULSE_WHIRLWIND = 283;
        public const int SPELLABILITY_PULSE_FIRE = 284;
        public const int SPELLABILITY_PULSE_LIGHTNING = 285;
        public const int SPELLABILITY_PULSE_COLD = 286;
        public const int SPELLABILITY_PULSE_NEGATIVE = 287;
        public const int SPELLABILITY_PULSE_HOLY = 288;
        public const int SPELLABILITY_PULSE_DEATH = 289;
        public const int SPELLABILITY_PULSE_LEVEL_DRAIN = 290;
        public const int SPELLABILITY_PULSE_ABILITY_DRAIN_INTELLIGENCE = 291;
        public const int SPELLABILITY_PULSE_ABILITY_DRAIN_CHARISMA = 292;
        public const int SPELLABILITY_PULSE_ABILITY_DRAIN_CONSTITUTION = 293;
        public const int SPELLABILITY_PULSE_ABILITY_DRAIN_DEXTERITY = 294;
        public const int SPELLABILITY_PULSE_ABILITY_DRAIN_STRENGTH = 295;
        public const int SPELLABILITY_PULSE_ABILITY_DRAIN_WISDOM = 296;
        public const int SPELLABILITY_PULSE_POISON = 297;
        public const int SPELLABILITY_PULSE_DISEASE = 298;
        public const int SPELLABILITY_RAGE_3 = 299;
        public const int SPELLABILITY_RAGE_4 = 300;
        public const int SPELLABILITY_RAGE_5 = 301;
        public const int SPELLABILITY_SMOKE_CLAW = 302;
        public const int SPELLABILITY_SUMMON_SLAAD = 303;
        public const int SPELLABILITY_SUMMON_TANARRI = 304;
        public const int SPELLABILITY_TRUMPET_BLAST = 305;
        public const int SPELLABILITY_TYRANT_FOG_MIST = 306;
        public const int SPELLABILITY_BARBARIAN_RAGE = 307;
        public const int SPELLABILITY_TURN_UNDEAD = 308;
        public const int SPELLABILITY_WHOLENESS_OF_BODY = 309;
        public const int SPELLABILITY_QUIVERING_PALM = 310;
        public const int SPELLABILITY_EMPTY_BODY = 311;
        public const int SPELLABILITY_DETECT_EVIL = 312;
        public const int SPELLABILITY_LAY_ON_HANDS = 313;
        public const int SPELLABILITY_AURA_OF_COURAGE = 314;
        public const int SPELLABILITY_SMITE_EVIL = 315;
        public const int SPELLABILITY_REMOVE_DISEASE = 316;
        public const int SPELLABILITY_SUMMON_ANIMAL_COMPANION = 317;
        public const int SPELLABILITY_SUMMON_FAMILIAR = 318;
        public const int SPELLABILITY_ELEMENTAL_SHAPE = 319;
        public const int SPELLABILITY_WILD_SHAPE = 320;
        // int SPELL_PROTECTION_FROM_ALIGNMENT = 321;
        // int SPELL_MAGIC_CIRCLE_AGAINST_ALIGNMENT = 322;
        // int SPELL_AURA_VERSUS_ALIGNMENT = 323;
        public const int SPELL_SHADES_SUMMON_SHADOW = 324;
        // int SPELL_PROTECTION_FROM_ELEMENTS_COLD = 325;
        // int SPELL_PROTECTION_FROM_ELEMENTS_FIRE = 326;
        // int SPELL_PROTECTION_FROM_ELEMENTS_ACID = 327;
        // int SPELL_PROTECTION_FROM_ELEMENTS_SONIC = 328;
        // int SPELL_PROTECTION_FROM_ELEMENTS_ELECTRICITY = 329;
        // int SPELL_ENDURE_ELEMENTS_COLD = 330;
        // int SPELL_ENDURE_ELEMENTS_FIRE = 331;
        // int SPELL_ENDURE_ELEMENTS_ACID = 332;
        // int SPELL_ENDURE_ELEMENTS_SONIC = 333;
        // int SPELL_ENDURE_ELEMENTS_ELECTRICITY = 334;
        // int SPELL_RESIST_ELEMENTS_COLD = 335;
        // int SPELL_RESIST_ELEMENTS_FIRE = 336;
        // int SPELL_RESIST_ELEMENTS_ACID = 337;
        // int SPELL_RESIST_ELEMENTS_SONIC = 338;
        // int SPELL_RESIST_ELEMENTS_ELECTRICITY = 339;
        public const int SPELL_SHADES_CONE_OF_COLD = 340;
        public const int SPELL_SHADES_FIREBALL = 341;
        public const int SPELL_SHADES_STONESKIN = 342;
        public const int SPELL_SHADES_WALL_OF_FIRE = 343;
        public const int SPELL_SHADOW_CONJURATION_SUMMON_SHADOW = 344;
        public const int SPELL_SHADOW_CONJURATION_DARKNESS = 345;
        public const int SPELL_SHADOW_CONJURATION_INIVSIBILITY = 346;
        public const int SPELL_SHADOW_CONJURATION_MAGE_ARMOR = 347;
        public const int SPELL_SHADOW_CONJURATION_MAGIC_MISSILE = 348;
        public const int SPELL_GREATER_SHADOW_CONJURATION_SUMMON_SHADOW = 349;
        public const int SPELL_GREATER_SHADOW_CONJURATION_ACID_ARROW = 350;
        public const int SPELL_GREATER_SHADOW_CONJURATION_MIRROR_IMAGE = 351;
        public const int SPELL_GREATER_SHADOW_CONJURATION_WEB = 352;
        public const int SPELL_GREATER_SHADOW_CONJURATION_MINOR_GLOBE = 353;
        public const int SPELL_EAGLE_SPLEDOR = 354;
        public const int SPELL_OWLS_WISDOM = 355;
        public const int SPELL_FOXS_CUNNING = 356;
        public const int SPELL_GREATER_EAGLE_SPLENDOR = 357;
        public const int SPELL_GREATER_OWLS_WISDOM = 358;
        public const int SPELL_GREATER_FOXS_CUNNING = 359;
        public const int SPELL_GREATER_BULLS_STRENGTH = 360;
        public const int SPELL_GREATER_CATS_GRACE = 361;
        public const int SPELL_GREATER_ENDURANCE = 362;
        public const int SPELL_AWAKEN = 363;
        public const int SPELL_CREEPING_DOOM = 364;
        public const int SPELL_DARKVISION = 365;
        public const int SPELL_DESTRUCTION = 366;
        public const int SPELL_HORRID_WILTING = 367;
        public const int SPELL_ICE_STORM = 368;
        public const int SPELL_ENERGY_BUFFER = 369;
        public const int SPELL_NEGATIVE_ENERGY_BURST = 370;
        public const int SPELL_NEGATIVE_ENERGY_RAY = 371;
        public const int SPELL_AURA_OF_VITALITY = 372;
        public const int SPELL_WAR_CRY = 373;
        public const int SPELL_REGENERATE = 374;
        public const int SPELL_EVARDS_BLACK_TENTACLES = 375;
        public const int SPELL_LEGEND_LORE = 376;
        public const int SPELL_FIND_TRAPS = 377;
        public const int SPELLABILITY_SUMMON_MEPHIT = 378;
        public const int SPELLABILITY_SUMMON_CELESTIAL = 379;
        public const int SPELLABILITY_BATTLE_MASTERY = 380;
        public const int SPELLABILITY_DIVINE_STRENGTH = 381;
        public const int SPELLABILITY_DIVINE_PROTECTION = 382;
        public const int SPELLABILITY_NEGATIVE_PLANE_AVATAR = 383;
        public const int SPELLABILITY_DIVINE_TRICKERY = 384;
        public const int SPELLABILITY_ROGUES_CUNNING = 385;
        public const int SPELLABILITY_ACTIVATE_ITEM = 386;
        public const int SPELLABILITY_DRAGON_FEAR = 412;
        public const int SPELL_DIVINE_FAVOR = 414;
        public const int SPELL_TRUE_STRIKE = 415;
        public const int SPELL_FLARE = 416;
        public const int SPELL_SHIELD = 417;
        public const int SPELL_ENTROPIC_SHIELD = 418;
        public const int SPELL_CONTINUAL_FLAME = 419;
        public const int SPELL_ONE_WITH_THE_LAND = 420;
        public const int SPELL_CAMOFLAGE = 421;
        public const int SPELL_BLOOD_FRENZY = 422;
        public const int SPELL_BOMBARDMENT = 423;
        public const int SPELL_ACID_SPLASH = 424;
        public const int SPELL_QUILLFIRE = 425;
        public const int SPELL_EARTHQUAKE = 426;
        public const int SPELL_SUNBURST = 427;
        public const int SPELL_ACTIVATE_ITEM_SELF2 = 428;
        public const int SPELL_AURAOFGLORY = 429;
        public const int SPELL_BANISHMENT = 430;
        public const int SPELL_INFLICT_MINOR_WOUNDS = 431;
        public const int SPELL_INFLICT_LIGHT_WOUNDS = 432;
        public const int SPELL_INFLICT_MODERATE_WOUNDS = 433;
        public const int SPELL_INFLICT_SERIOUS_WOUNDS = 434;
        public const int SPELL_INFLICT_CRITICAL_WOUNDS = 435;
        public const int SPELL_BALAGARNSIRONHORN = 436;
        public const int SPELL_DROWN = 437;
        public const int SPELL_OWLS_INSIGHT = 438;
        public const int SPELL_ELECTRIC_JOLT = 439;
        public const int SPELL_FIREBRAND = 440;
        public const int SPELL_WOUNDING_WHISPERS = 441;
        public const int SPELL_AMPLIFY = 442;
        public const int SPELL_ETHEREALNESS = 443;
        public const int SPELL_UNDEATHS_ETERNAL_FOE = 444;
        public const int SPELL_DIRGE = 445;
        public const int SPELL_INFERNO = 446;
        public const int SPELL_ISAACS_LESSER_MISSILE_STORM = 447;
        public const int SPELL_ISAACS_GREATER_MISSILE_STORM = 448;
        public const int SPELL_BANE = 449;
        public const int SPELL_SHIELD_OF_FAITH = 450;
        public const int SPELL_PLANAR_ALLY = 451;
        public const int SPELL_MAGIC_FANG = 452;
        public const int SPELL_GREATER_MAGIC_FANG = 453;
        public const int SPELL_SPIKE_GROWTH = 454;
        public const int SPELL_MASS_CAMOFLAGE = 455;
        public const int SPELL_EXPEDITIOUS_RETREAT = 456;
        public const int SPELL_TASHAS_HIDEOUS_LAUGHTER = 457;
        public const int SPELL_DISPLACEMENT = 458;
        public const int SPELL_BIGBYS_INTERPOSING_HAND = 459;
        public const int SPELL_BIGBYS_FORCEFUL_HAND = 460;
        public const int SPELL_BIGBYS_GRASPING_HAND = 461;
        public const int SPELL_BIGBYS_CLENCHED_FIST = 462;
        public const int SPELL_BIGBYS_CRUSHING_HAND = 463;
        public const int SPELL_GRENADE_FIRE = 464;
        public const int SPELL_GRENADE_TANGLE = 465;
        public const int SPELL_GRENADE_HOLY = 466;
        public const int SPELL_GRENADE_CHOKING = 467;
        public const int SPELL_GRENADE_THUNDERSTONE = 468;
        public const int SPELL_GRENADE_ACID = 469;
        public const int SPELL_GRENADE_CHICKEN = 470;
        public const int SPELL_GRENADE_CALTROPS = 471;
        public const int SPELL_ACTIVATE_ITEM_PORTAL = 472;
        public const int SPELL_DIVINE_MIGHT = 473;
        public const int SPELL_DIVINE_SHIELD = 474;
        public const int SPELL_SHADOW_DAZE = 475;
        public const int SPELL_SUMMON_SHADOW = 476;
        public const int SPELL_SHADOW_EVADE = 477;
        public const int SPELL_TYMORAS_SMILE = 478;
        public const int SPELL_CRAFT_HARPER_ITEM = 479;
        public const int SPELL_FLESH_TO_STONE = 485;
        public const int SPELL_STONE_TO_FLESH = 486;
        public const int SPELL_TRAP_ARROW = 487;
        public const int SPELL_TRAP_BOLT = 488;
        public const int SPELL_TRAP_DART = 493;
        public const int SPELL_TRAP_SHURIKEN = 494;
        public const int SPELLABILITY_BREATH_PETRIFY = 495;
        public const int SPELLABILITY_TOUCH_PETRIFY = 496;
        public const int SPELLABILITY_GAZE_PETRIFY = 497;
        public const int SPELLABILITY_MANTICORE_SPIKES = 498;
        public const int SPELL_ROD_OF_WONDER = 499;
        public const int SPELL_DECK_OF_MANY_THINGS = 500;
        public const int SPELL_ELEMENTAL_SUMMONING_ITEM = 502;
        public const int SPELL_DECK_AVATAR = 503;
        public const int SPELL_DECK_GEMSPRAY = 504;
        public const int SPELL_DECK_BUTTERFLYSPRAY = 505;
        public const int SPELL_HEALINGKIT = 506;
        public const int SPELL_POWERSTONE = 507;
        public const int SPELL_SPELLSTAFF = 508;
        public const int SPELL_CHARGER = 500;
        public const int SPELL_DECHARGER = 510;
        public const int SPELL_KOBOLD_JUMP = 511;
        public const int SPELL_CRUMBLE = 512;
        public const int SPELL_INFESTATION_OF_MAGGOTS = 513;
        public const int SPELL_HEALING_STING = 514;
        public const int SPELL_GREAT_THUNDERCLAP = 515;
        public const int SPELL_BALL_LIGHTNING = 516;
        public const int SPELL_BATTLETIDE = 517;
        public const int SPELL_COMBUST = 518;
        public const int SPELL_DEATH_ARMOR = 519;
        public const int SPELL_GEDLEES_ELECTRIC_LOOP = 520;
        public const int SPELL_HORIZIKAULS_BOOM = 521;
        public const int SPELL_IRONGUTS = 522;
        public const int SPELL_MESTILS_ACID_BREATH = 523;
        public const int SPELL_MESTILS_ACID_SHEATH = 524;
        public const int SPELL_MONSTROUS_REGENERATION = 525;
        public const int SPELL_SCINTILLATING_SPHERE = 526;
        public const int SPELL_STONE_BONES = 527;
        public const int SPELL_UNDEATH_TO_DEATH = 528;
        public const int SPELL_VINE_MINE = 529;
        public const int SPELL_VINE_MINE_ENTANGLE = 530;
        public const int SPELL_VINE_MINE_HAMPER_MOVEMENT = 531;
        public const int SPELL_VINE_MINE_CAMOUFLAGE = 532;
        public const int SPELL_BLACK_BLADE_OF_DISASTER = 533;
        public const int SPELL_SHELGARNS_PERSISTENT_BLADE = 534;
        public const int SPELL_BLADE_THIRST = 535;
        public const int SPELL_DEAFENING_CLANG = 536;
        public const int SPELL_CLOUD_OF_BEWILDERMENT = 569;
        public const int SPELL_KEEN_EDGE = 539;
        public const int SPELL_BLACKSTAFF = 541;
        public const int SPELL_FLAME_WEAPON = 542;
        public const int SPELL_ICE_DAGGER = 543;
        public const int SPELL_MAGIC_WEAPON = 544;
        public const int SPELL_GREATER_MAGIC_WEAPON = 545;
        public const int SPELL_STONEHOLD = 547;
        public const int SPELL_DARKFIRE = 548;
        public const int SPELL_GLYPH_OF_WARDING = 549;
        public const int SPELLABILITY_MINDBLAST = 551;
        public const int SPELLABILITY_CHARMMONSTER = 552;
        public const int SPELL_IOUN_STONE_DUSTY_ROSE = 554;
        public const int SPELL_IOUN_STONE_PALE_BLUE = 555;
        public const int SPELL_IOUN_STONE_SCARLET_BLUE = 556;
        public const int SPELL_IOUN_STONE_BLUE = 557;
        public const int SPELL_IOUN_STONE_DEEP_RED = 558;
        public const int SPELL_IOUN_STONE_PINK = 559;
        public const int SPELL_IOUN_STONE_PINK_GREEN = 560;
        public const int SPELLABILITY_WHIRLWIND = 561;
        public const int SPELLABILITY_COMMAND_THE_HORDE = 571;
        public const int SPELLABILITY_AA_IMBUE_ARROW = 600;
        public const int SPELLABILITY_AA_SEEKER_ARROW_1 = 601;
        public const int SPELLABILITY_AA_SEEKER_ARROW_2 = 602;
        public const int SPELLABILITY_AA_HAIL_OF_ARROWS = 603;
        public const int SPELLABILITY_AA_ARROW_OF_DEATH = 604;
        public const int SPELLABILITY_AS_GHOSTLY_VISAGE = 605;
        public const int SPELLABILITY_AS_DARKNESS = 606;
        public const int SPELLABILITY_AS_INVISIBILITY = 607;
        public const int SPELLABILITY_AS_IMPROVED_INVISIBLITY = 608;
        public const int SPELLABILITY_BG_CREATEDEAD = 609;
        public const int SPELLABILITY_BG_FIENDISH_SERVANT = 610;
        public const int SPELLABILITY_BG_INFLICT_SERIOUS_WOUNDS = 611;
        public const int SPELLABILITY_BG_INFLICT_CRITICAL_WOUNDS = 612;
        public const int SPELLABILITY_BG_CONTAGION = 613;
        public const int SPELLABILITY_BG_BULLS_STRENGTH = 614;
        public const int SPELL_FLYING_DEBRIS = 620;
        public const int SPELLABILITY_DC_DIVINE_WRATH = 622;
        public const int SPELLABILITY_PM_ANIMATE_DEAD = 623;
        public const int SPELLABILITY_PM_SUMMON_UNDEAD = 624;
        public const int SPELLABILITY_PM_UNDEAD_GRAFT_1 = 625;
        public const int SPELLABILITY_PM_UNDEAD_GRAFT_2 = 626;
        public const int SPELLABILITY_PM_SUMMON_GREATER_UNDEAD = 627;
        public const int SPELLABILITY_PM_DEATHLESS_MASTER_TOUCH = 628;
        public const int SPELL_EPIC_HELLBALL = 636;
        public const int SPELL_EPIC_MUMMY_DUST = 637;
        public const int SPELL_EPIC_DRAGON_KNIGHT = 638;
        public const int SPELL_EPIC_MAGE_ARMOR = 639;
        public const int SPELL_EPIC_RUIN = 640;
        public const int SPELLABILITY_DW_DEFENSIVE_STANCE = 641;
        public const int SPELLABILITY_EPIC_MIGHTY_RAGE = 642;
        public const int SPELLABILITY_EPIC_CURSE_SONG = 644;
        public const int SPELLABILITY_EPIC_IMPROVED_WHIRLWIND = 645;
        public const int SPELLABILITY_EPIC_SHAPE_DRAGONKIN = 646;
        public const int SPELLABILITY_EPIC_SHAPE_DRAGON = 647;
        public const int SPELL_CRAFT_DYE_CLOTHCOLOR_1 = 648;
        public const int SPELL_CRAFT_DYE_CLOTHCOLOR_2 = 649;
        public const int SPELL_CRAFT_DYE_LEATHERCOLOR_1 = 650;
        public const int SPELL_CRAFT_DYE_LEATHERCOLOR_2 = 651;
        public const int SPELL_CRAFT_DYE_METALCOLOR_1 = 652;
        public const int SPELL_CRAFT_DYE_METALCOLOR_2 = 653;
        public const int SPELL_CRAFT_ADD_ITEM_PROPERTY = 654;
        public const int SPELL_CRAFT_POISON_WEAPON_OR_AMMO = 655;
        public const int SPELL_CRAFT_CRAFT_WEAPON_SKILL = 656;
        public const int SPELL_CRAFT_CRAFT_ARMOR_SKILL = 657;
        public const int SPELLABILITY_DRAGON_BREATH_NEGATIVE = 698;
        public const int SPELLABILITY_SEAHAG_EVILEYE = 803;
        public const int SPELLABILITY_AURA_HORRIFICAPPEARANCE = 804;
        public const int SPELLABILITY_TROGLODYTE_STENCH = 805;
        public const int SPELL_HORSE_MENU = 812;
        public const int SPELL_HORSE_MOUNT = 813;
        public const int SPELL_HORSE_DISMOUNT = 814;
        public const int SPELL_HORSE_PARTY_MOUNT = 815;
        public const int SPELL_HORSE_PARTY_DISMOUNT = 816;
        public const int SPELL_HORSE_ASSIGN_MOUNT = 817;
        public const int SPELL_PALADIN_SUMMON_MOUNT = 818;
        //  these constants must match those in poison.2da
        public const int POISON_NIGHTSHADE = 0;
        public const int POISON_SMALL_CENTIPEDE_POISON = 1;
        public const int POISON_BLADE_BANE = 2;
        public const int POISON_GREENBLOOD_OIL = 3;
        public const int POISON_BLOODROOT = 4;
        public const int POISON_PURPLE_WORM_POISON = 5;
        public const int POISON_LARGE_SCORPION_VENOM = 6;
        public const int POISON_WYVERN_POISON = 7;
        public const int POISON_BLUE_WHINNIS = 8;
        public const int POISON_GIANT_WASP_POISON = 9;
        public const int POISON_SHADOW_ESSENCE = 10;
        public const int POISON_BLACK_ADDER_VENOM = 11;
        public const int POISON_DEATHBLADE = 12;
        public const int POISON_MALYSS_ROOT_PASTE = 13;
        public const int POISON_NITHARIT = 14;
        public const int POISON_DRAGON_BILE = 15;
        public const int POISON_SASSONE_LEAF_RESIDUE = 16;
        public const int POISON_TERINAV_ROOT = 17;
        public const int POISON_CARRION_CRAWLER_BRAIN_JUICE = 18;
        public const int POISON_BLACK_LOTUS_EXTRACT = 19;
        public const int POISON_OIL_OF_TAGGIT = 20;
        public const int POISON_ID_MOSS = 21;
        public const int POISON_STRIPED_TOADSTOOL = 22;
        public const int POISON_ARSENIC = 23;
        public const int POISON_LICH_DUST = 24;
        public const int POISON_DARK_REAVER_POWDER = 25;
        public const int POISON_UNGOL_DUST = 26;
        public const int POISON_BURNT_OTHUR_FUMES = 27;
        public const int POISON_CHAOS_MIST = 28;
        public const int POISON_BEBILITH_VENOM = 29;
        public const int POISON_QUASIT_VENOM = 30;
        public const int POISON_PIT_FIEND_ICHOR = 31;
        public const int POISON_ETTERCAP_VENOM = 32;
        public const int POISON_ARANEA_VENOM = 33;
        public const int POISON_TINY_SPIDER_VENOM = 34;
        public const int POISON_SMALL_SPIDER_VENOM = 35;
        public const int POISON_MEDIUM_SPIDER_VENOM = 36;
        public const int POISON_LARGE_SPIDER_VENOM = 37;
        public const int POISON_HUGE_SPIDER_VENOM = 38;
        public const int POISON_GARGANTUAN_SPIDER_VENOM = 39;
        public const int POISON_COLOSSAL_SPIDER_VENOM = 40;
        public const int POISON_PHASE_SPIDER_VENOM = 41;
        public const int POISON_WRAITH_SPIDER_VENOM = 42;
        public const int POISON_IRON_GOLEM = 43;
        //  these constants match those in disease.2da
        public const int DISEASE_BLINDING_SICKNESS = 0;
        public const int DISEASE_CACKLE_FEVER = 1;
        public const int DISEASE_DEVIL_CHILLS = 2;
        public const int DISEASE_DEMON_FEVER = 3;
        public const int DISEASE_FILTH_FEVER = 4;
        public const int DISEASE_MINDFIRE = 5;
        public const int DISEASE_MUMMY_ROT = 6;
        public const int DISEASE_RED_ACHE = 7;
        public const int DISEASE_SHAKES = 8;
        public const int DISEASE_SLIMY_DOOM = 9;
        public const int DISEASE_RED_SLAAD_EGGS = 10;
        public const int DISEASE_GHOUL_ROT = 11;
        public const int DISEASE_ZOMBIE_CREEP = 12;
        public const int DISEASE_DREAD_BLISTERS = 13;
        public const int DISEASE_BURROW_MAGGOTS = 14;
        public const int DISEASE_SOLDIER_SHAKES = 15;
        public const int DISEASE_VERMIN_MADNESS = 16;
        //  the thing after CREATURE_TYPE_ should refer to the
        //  actual "subtype" in the lists given above.
        public const int CREATURE_TYPE_RACIAL_TYPE = 0;
        public const int CREATURE_TYPE_PLAYER_CHAR = 1;
        public const int CREATURE_TYPE_CLASS = 2;
        public const int CREATURE_TYPE_REPUTATION = 3;
        public const int CREATURE_TYPE_IS_ALIVE = 4;
        public const int CREATURE_TYPE_HAS_SPELL_EFFECT = 5;
        public const int CREATURE_TYPE_DOES_NOT_HAVE_SPELL_EFFECT = 6;
        public const int CREATURE_TYPE_PERCEPTION = 7;
        // int CREATURE_TYPE_ALIGNMENT       = 2;
        public const int REPUTATION_TYPE_FRIEND = 0;
        public const int REPUTATION_TYPE_ENEMY = 1;
        public const int REPUTATION_TYPE_NEUTRAL = 2;
        public const int PERCEPTION_SEEN_AND_HEARD = 0;
        public const int PERCEPTION_NOT_SEEN_AND_NOT_HEARD = 1;
        public const int PERCEPTION_HEARD_AND_NOT_SEEN = 2;
        public const int PERCEPTION_SEEN_AND_NOT_HEARD = 3;
        public const int PERCEPTION_NOT_HEARD = 4;
        public const int PERCEPTION_HEARD = 5;
        public const int PERCEPTION_NOT_SEEN = 6;
        public const int PERCEPTION_SEEN = 7;
        public const int PLAYER_CHAR_NOT_PC = FALSE;
        public const int PLAYER_CHAR_IS_PC = TRUE;
        public const int CLASS_TYPE_BARBARIAN = 0;
        public const int CLASS_TYPE_BARD = 1;
        public const int CLASS_TYPE_CLERIC = 2;
        public const int CLASS_TYPE_DRUID = 3;
        public const int CLASS_TYPE_FIGHTER = 4;
        public const int CLASS_TYPE_MONK = 5;
        public const int CLASS_TYPE_PALADIN = 6;
        public const int CLASS_TYPE_RANGER = 7;
        public const int CLASS_TYPE_ROGUE = 8;
        public const int CLASS_TYPE_SORCERER = 9;
        public const int CLASS_TYPE_WIZARD = 10;
        public const int CLASS_TYPE_ABERRATION = 11;
        public const int CLASS_TYPE_ANIMAL = 12;
        public const int CLASS_TYPE_CONSTRUCT = 13;
        public const int CLASS_TYPE_HUMANOID = 14;
        public const int CLASS_TYPE_MONSTROUS = 15;
        public const int CLASS_TYPE_ELEMENTAL = 16;
        public const int CLASS_TYPE_FEY = 17;
        public const int CLASS_TYPE_DRAGON = 18;
        public const int CLASS_TYPE_UNDEAD = 19;
        public const int CLASS_TYPE_COMMONER = 20;
        public const int CLASS_TYPE_BEAST = 21;
        public const int CLASS_TYPE_GIANT = 22;
        public const int CLASS_TYPE_MAGICAL_BEAST = 23;
        public const int CLASS_TYPE_OUTSIDER = 24;
        public const int CLASS_TYPE_SHAPECHANGER = 25;
        public const int CLASS_TYPE_VERMIN = 26;
        public const int CLASS_TYPE_SHADOWDANCER = 27;
        public const int CLASS_TYPE_HARPER = 28;
        public const int CLASS_TYPE_ARCANE_ARCHER = 29;
        public const int CLASS_TYPE_ASSASSIN = 30;
        public const int CLASS_TYPE_BLACKGUARD = 31;
        public const int CLASS_TYPE_DIVINECHAMPION = 32;
        public const int CLASS_TYPE_DIVINE_CHAMPION = 32;
        public const int CLASS_TYPE_WEAPON_MASTER = 33;
        public const int CLASS_TYPE_PALEMASTER = 34;
        public const int CLASS_TYPE_PALE_MASTER = 34;
        public const int CLASS_TYPE_SHIFTER = 35;
        public const int CLASS_TYPE_DWARVENDEFENDER = 36;
        public const int CLASS_TYPE_DWARVEN_DEFENDER = 36;
        public const int CLASS_TYPE_DRAGONDISCIPLE = 37;
        public const int CLASS_TYPE_DRAGON_DISCIPLE = 37;
        public const int CLASS_TYPE_OOZE = 38;
        public const int CLASS_TYPE_EYE_OF_GRUUMSH = 39;
        public const int CLASS_TYPE_SHOU_DISCIPLE = 40;
        public const int CLASS_TYPE_PURPLE_DRAGON_KNIGHT = 41;
        public const int CLASS_TYPE_INVALID = 255;
        //  These are for the LevelUpHenchman command.
        public const int PACKAGE_BARBARIAN = 0;
        public const int PACKAGE_BARD = 1;
        public const int PACKAGE_CLERIC = 2;
        public const int PACKAGE_DRUID = 3;
        public const int PACKAGE_FIGHTER = 4;
        public const int PACKAGE_MONK = 5;
        public const int PACKAGE_PALADIN = 6;
        public const int PACKAGE_RANGER = 7;
        public const int PACKAGE_ROGUE = 8;
        public const int PACKAGE_SORCERER = 9;
        public const int PACKAGE_WIZARDGENERALIST = 10;
        public const int PACKAGE_DRUID_INTERLOPER = 11;
        public const int PACKAGE_DRUID_GRAY = 12;
        public const int PACKAGE_DRUID_DEATH = 13;
        public const int PACKAGE_DRUID_HAWKMASTER = 14;
        public const int PACKAGE_BARBARIAN_BRUTE = 15;
        public const int PACKAGE_BARBARIAN_SLAYER = 16;
        public const int PACKAGE_BARBARIAN_SAVAGE = 17;
        public const int PACKAGE_BARBARIAN_ORCBLOOD = 18;
        public const int PACKAGE_CLERIC_SHAMAN = 19;
        public const int PACKAGE_CLERIC_DEADWALKER = 20;
        public const int PACKAGE_CLERIC_ELEMENTALIST = 21;
        public const int PACKAGE_CLERIC_BATTLE_PRIEST = 22;
        public const int PACKAGE_FIGHTER_FINESSE = 23;
        public const int PACKAGE_FIGHTER_PIRATE = 24;
        public const int PACKAGE_FIGHTER_GLADIATOR = 25;
        public const int PACKAGE_FIGHTER_COMMANDER = 26;
        public const int PACKAGE_WIZARD_ABJURATION = 27;
        public const int PACKAGE_WIZARD_CONJURATION = 28;
        public const int PACKAGE_WIZARD_DIVINATION = 29;
        public const int PACKAGE_WIZARD_ENCHANTMENT = 30;
        public const int PACKAGE_WIZARD_EVOCATION = 31;
        public const int PACKAGE_WIZARD_ILLUSION = 32;
        public const int PACKAGE_WIZARD_NECROMANCY = 33;
        public const int PACKAGE_WIZARD_TRANSMUTATION = 34;
        public const int PACKAGE_SORCERER_ABJURATION = 35;
        public const int PACKAGE_SORCERER_CONJURATION = 36;
        public const int PACKAGE_SORCERER_DIVINATION = 37;
        public const int PACKAGE_SORCERER_ENCHANTMENT = 38;
        public const int PACKAGE_SORCERER_EVOCATION = 39;
        public const int PACKAGE_SORCERER_ILLUSION = 40;
        public const int PACKAGE_SORCERER_NECROMANCY = 41;
        public const int PACKAGE_SORCERER_TRANSMUTATION = 42;
        public const int PACKAGE_BARD_BLADE = 43;
        public const int PACKAGE_BARD_GALLANT = 44;
        public const int PACKAGE_BARD_JESTER = 45;
        public const int PACKAGE_BARD_LOREMASTER = 46;
        public const int PACKAGE_MONK_SPIRIT = 47;
        public const int PACKAGE_MONK_GIFTED = 48;
        public const int PACKAGE_MONK_DEVOUT = 49;
        public const int PACKAGE_MONK_PEASANT = 50;
        public const int PACKAGE_PALADIN_ERRANT = 51;
        public const int PACKAGE_PALADIN_UNDEAD = 52;
        public const int PACKAGE_PALADIN_INQUISITOR = 53;
        public const int PACKAGE_PALADIN_CHAMPION = 54;
        public const int PACKAGE_RANGER_MARKSMAN = 55;
        public const int PACKAGE_RANGER_WARDEN = 56;
        public const int PACKAGE_RANGER_STALKER = 57;
        public const int PACKAGE_RANGER_GIANTKILLER = 58;
        public const int PACKAGE_ROGUE_GYPSY = 59;
        public const int PACKAGE_ROGUE_BANDIT = 60;
        public const int PACKAGE_ROGUE_SCOUT = 61;
        public const int PACKAGE_ROGUE_SWASHBUCKLER = 62;
        public const int PACKAGE_SHADOWDANCER = 63;
        public const int PACKAGE_HARPER = 64;
        public const int PACKAGE_ARCANE_ARCHER = 65;
        public const int PACKAGE_ASSASSIN = 66;
        public const int PACKAGE_BLACKGUARD = 67;
        public const int PACKAGE_NPC_SORCERER = 70;
        public const int PACKAGE_NPC_ROGUE = 71;
        public const int PACKAGE_NPC_BARD = 72;
        public const int PACKAGE_ABERRATION = 73;
        public const int PACKAGE_ANIMAL = 74;
        public const int PACKAGE_CONSTRUCT = 75;
        public const int PACKAGE_HUMANOID = 76;
        public const int PACKAGE_MONSTROUS = 77;
        public const int PACKAGE_ELEMENTAL = 78;
        public const int PACKAGE_FEY = 79;
        public const int PACKAGE_DRAGON = 80;
        public const int PACKAGE_UNDEAD = 81;
        public const int PACKAGE_COMMONER = 82;
        public const int PACKAGE_BEAST = 83;
        public const int PACKAGE_GIANT = 84;
        public const int PACKAGE_MAGICBEAST = 85;
        public const int PACKAGE_OUTSIDER = 86;
        public const int PACKAGE_SHAPECHANGER = 87;
        public const int PACKAGE_VERMIN = 88;
        public const int PACKAGE_DWARVEN_DEFENDER = 89;
        public const int PACKAGE_BARBARIAN_BLACKGUARD = 90;
        public const int PACKAGE_BARD_HARPER = 91;
        public const int PACKAGE_CLERIC_DIVINE = 92;
        public const int PACKAGE_DRUID_SHIFTER = 93;
        public const int PACKAGE_FIGHTER_WEAPONMASTER = 94;
        public const int PACKAGE_MONK_ASSASSIN = 95;
        public const int PACKAGE_PALADIN_DIVINE = 96;
        public const int PACKAGE_RANGER_ARCANEARCHER = 97;
        public const int PACKAGE_ROGUE_SHADOWDANCER = 98;
        public const int PACKAGE_SORCERER_DRAGONDISCIPLE = 99;
        public const int PACKAGE_WIZARD_PALEMASTER = 100;
        public const int PACKAGE_NPC_WIZASSASSIN = 101;
        public const int PACKAGE_NPC_FT_WEAPONMASTER = 102;
        public const int PACKAGE_NPC_RG_SHADOWDANCER = 103;
        public const int PACKAGE_NPC_CLERIC_LINU = 104;
        public const int PACKAGE_NPC_BARBARIAN_DAELAN = 105;
        public const int PACKAGE_NPC_BARD_FIGHTER = 106;
        public const int PACKAGE_NPC_PALADIN_FALLING = 107;
        public const int PACKAGE_SHIFTER = 108;
        public const int PACKAGE_DIVINE_CHAMPION = 109;
        public const int PACKAGE_PALE_MASTER = 110;
        public const int PACKAGE_DRAGON_DISCIPLE = 111;
        public const int PACKAGE_WEAPONMASTER = 112;
        public const int PACKAGE_NPC_FT_WEAPONMASTER_VALEN_2 = 113;
        public const int PACKAGE_NPC_BARD_FIGHTER_SHARWYN2 = 114;
        public const int PACKAGE_NPC_WIZASSASSIN_NATHYRRA = 115;
        public const int PACKAGE_NPC_RG_TOMI_2 = 116;
        public const int PACKAGE_NPC_BARD_DEEKIN_2 = 117;
        public const int PACKAGE_BARBARIAN_BLACKGUARD_2NDCLASS = 118;
        public const int PACKAGE_BARD_HARPER_2NDCLASS = 119;
        public const int PACKAGE_CLERIC_DIVINE_2NDCLASS = 120;
        public const int PACKAGE_DRUID_SHIFTER_2NDCLASS = 121;
        public const int PACKAGE_FIGHTER_WEAPONMASTER_2NDCLASS = 122;
        public const int PACKAGE_MONK_ASSASSIN_2NDCLASS = 123;
        public const int PACKAGE_PALADIN_DIVINE_2NDCLASS = 124;
        public const int PACKAGE_RANGER_ARCANEARCHER_2NDCLASS = 125;
        public const int PACKAGE_ROGUE_SHADOWDANCER_2NDCLASS = 126;
        public const int PACKAGE_SORCERER_DRAGONDISCIPLE_2NDCLASS = 127;
        public const int PACKAGE_WIZARD_PALEMASTER_2NDCLASS = 128;
        public const int PACKAGE_NPC_ARIBETH_PALADIN = 129;
        public const int PACKAGE_NPC_ARIBETH_BLACKGUARD = 130;
        public const int PACKAGE_INVALID = 255;
        //  These are for GetFirstInPersistentObject() and GetNextInPersistentObject()
        public const int PERSISTENT_ZONE_ACTIVE = 0;
        public const int PERSISTENT_ZONE_FOLLOW = 1;
        public const int STANDARD_FACTION_HOSTILE = 0;
        public const int STANDARD_FACTION_COMMONER = 1;
        public const int STANDARD_FACTION_MERCHANT = 2;
        public const int STANDARD_FACTION_DEFENDER = 3;
        //  Skill defines
        public const int SKILL_ANIMAL_EMPATHY = 0;
        public const int SKILL_CONCENTRATION = 1;
        public const int SKILL_DISABLE_TRAP = 2;
        public const int SKILL_DISCIPLINE = 3;
        public const int SKILL_HEAL = 4;
        public const int SKILL_HIDE = 5;
        public const int SKILL_LISTEN = 6;
        public const int SKILL_LORE = 7;
        public const int SKILL_MOVE_SILENTLY = 8;
        public const int SKILL_OPEN_LOCK = 9;
        public const int SKILL_PARRY = 10;
        public const int SKILL_PERFORM = 11;
        public const int SKILL_PERSUADE = 12;
        public const int SKILL_PICK_POCKET = 13;
        public const int SKILL_SEARCH = 14;
        public const int SKILL_SET_TRAP = 15;
        public const int SKILL_SPELLCRAFT = 16;
        public const int SKILL_SPOT = 17;
        public const int SKILL_TAUNT = 18;
        public const int SKILL_USE_MAGIC_DEVICE = 19;
        public const int SKILL_APPRAISE = 20;
        public const int SKILL_TUMBLE = 21;
        public const int SKILL_CRAFT_TRAP = 22;
        public const int SKILL_BLUFF = 23;
        public const int SKILL_INTIMIDATE = 24;
        public const int SKILL_CRAFT_ARMOR = 25;
        public const int SKILL_CRAFT_WEAPON = 26;
        public const int SKILL_RIDE = 27;
        public const int SKILL_ALL_SKILLS = 255;
        public const int SUBSKILL_FLAGTRAP = 100;
        public const int SUBSKILL_RECOVERTRAP = 101;
        public const int SUBSKILL_EXAMINETRAP = 102;
        public const int FEAT_ALERTNESS = 0;
        public const int FEAT_AMBIDEXTERITY = 1;
        public const int FEAT_ARMOR_PROFICIENCY_HEAVY = 2;
        public const int FEAT_ARMOR_PROFICIENCY_LIGHT = 3;
        public const int FEAT_ARMOR_PROFICIENCY_MEDIUM = 4;
        public const int FEAT_CALLED_SHOT = 5;
        public const int FEAT_CLEAVE = 6;
        public const int FEAT_COMBAT_CASTING = 7;
        public const int FEAT_DEFLECT_ARROWS = 8;
        public const int FEAT_DISARM = 9;
        public const int FEAT_DODGE = 10;
        public const int FEAT_EMPOWER_SPELL = 11;
        public const int FEAT_EXTEND_SPELL = 12;
        public const int FEAT_EXTRA_TURNING = 13;
        public const int FEAT_GREAT_FORTITUDE = 14;
        public const int FEAT_IMPROVED_CRITICAL_CLUB = 15;
        public const int FEAT_IMPROVED_DISARM = 16;
        public const int FEAT_IMPROVED_KNOCKDOWN = 17;
        public const int FEAT_IMPROVED_PARRY = 18;
        public const int FEAT_IMPROVED_POWER_ATTACK = 19;
        public const int FEAT_IMPROVED_TWO_WEAPON_FIGHTING = 20;
        public const int FEAT_IMPROVED_UNARMED_STRIKE = 21;
        public const int FEAT_IRON_WILL = 22;
        public const int FEAT_KNOCKDOWN = 23;
        public const int FEAT_LIGHTNING_REFLEXES = 24;
        public const int FEAT_MAXIMIZE_SPELL = 25;
        public const int FEAT_MOBILITY = 26;
        public const int FEAT_POINT_BLANK_SHOT = 27;
        public const int FEAT_POWER_ATTACK = 28;
        public const int FEAT_QUICKEN_SPELL = 29;
        public const int FEAT_RAPID_SHOT = 30;
        public const int FEAT_SAP = 31;
        public const int FEAT_SHIELD_PROFICIENCY = 32;
        public const int FEAT_SILENCE_SPELL = 33;
        public const int FEAT_SKILL_FOCUS_ANIMAL_EMPATHY = 34;
        public const int FEAT_SPELL_FOCUS_ABJURATION = 35;
        public const int FEAT_SPELL_PENETRATION = 36;
        public const int FEAT_STILL_SPELL = 37;
        public const int FEAT_STUNNING_FIST = 39;
        public const int FEAT_TOUGHNESS = 40;
        public const int FEAT_TWO_WEAPON_FIGHTING = 41;
        public const int FEAT_WEAPON_FINESSE = 42;
        public const int FEAT_WEAPON_FOCUS_CLUB = 43;
        public const int FEAT_WEAPON_PROFICIENCY_EXOTIC = 44;
        public const int FEAT_WEAPON_PROFICIENCY_MARTIAL = 45;
        public const int FEAT_WEAPON_PROFICIENCY_SIMPLE = 46;
        public const int FEAT_WEAPON_SPECIALIZATION_CLUB = 47;
        public const int FEAT_WEAPON_PROFICIENCY_DRUID = 48;
        public const int FEAT_WEAPON_PROFICIENCY_MONK = 49;
        public const int FEAT_WEAPON_PROFICIENCY_ROGUE = 50;
        public const int FEAT_WEAPON_PROFICIENCY_WIZARD = 51;
        public const int FEAT_IMPROVED_CRITICAL_DAGGER = 52;
        public const int FEAT_IMPROVED_CRITICAL_DART = 53;
        public const int FEAT_IMPROVED_CRITICAL_HEAVY_CROSSBOW = 54;
        public const int FEAT_IMPROVED_CRITICAL_LIGHT_CROSSBOW = 55;
        public const int FEAT_IMPROVED_CRITICAL_LIGHT_MACE = 56;
        public const int FEAT_IMPROVED_CRITICAL_MORNING_STAR = 57;
        public const int FEAT_IMPROVED_CRITICAL_STAFF = 58;
        public const int FEAT_IMPROVED_CRITICAL_SPEAR = 59;
        public const int FEAT_IMPROVED_CRITICAL_SICKLE = 60;
        public const int FEAT_IMPROVED_CRITICAL_SLING = 61;
        public const int FEAT_IMPROVED_CRITICAL_UNARMED_STRIKE = 62;
        public const int FEAT_IMPROVED_CRITICAL_LONGBOW = 63;
        public const int FEAT_IMPROVED_CRITICAL_SHORTBOW = 64;
        public const int FEAT_IMPROVED_CRITICAL_SHORT_SWORD = 65;
        public const int FEAT_IMPROVED_CRITICAL_RAPIER = 66;
        public const int FEAT_IMPROVED_CRITICAL_SCIMITAR = 67;
        public const int FEAT_IMPROVED_CRITICAL_LONG_SWORD = 68;
        public const int FEAT_IMPROVED_CRITICAL_GREAT_SWORD = 69;
        public const int FEAT_IMPROVED_CRITICAL_HAND_AXE = 70;
        public const int FEAT_IMPROVED_CRITICAL_THROWING_AXE = 71;
        public const int FEAT_IMPROVED_CRITICAL_BATTLE_AXE = 72;
        public const int FEAT_IMPROVED_CRITICAL_GREAT_AXE = 73;
        public const int FEAT_IMPROVED_CRITICAL_HALBERD = 74;
        public const int FEAT_IMPROVED_CRITICAL_LIGHT_HAMMER = 75;
        public const int FEAT_IMPROVED_CRITICAL_LIGHT_FLAIL = 76;
        public const int FEAT_IMPROVED_CRITICAL_WAR_HAMMER = 77;
        public const int FEAT_IMPROVED_CRITICAL_HEAVY_FLAIL = 78;
        public const int FEAT_IMPROVED_CRITICAL_KAMA = 79;
        public const int FEAT_IMPROVED_CRITICAL_KUKRI = 80;
        // int FEAT_IMPROVED_CRITICAL_NUNCHAKU = 81;
        public const int FEAT_IMPROVED_CRITICAL_SHURIKEN = 82;
        public const int FEAT_IMPROVED_CRITICAL_SCYTHE = 83;
        public const int FEAT_IMPROVED_CRITICAL_KATANA = 84;
        public const int FEAT_IMPROVED_CRITICAL_BASTARD_SWORD = 85;
        public const int FEAT_IMPROVED_CRITICAL_DIRE_MACE = 87;
        public const int FEAT_IMPROVED_CRITICAL_DOUBLE_AXE = 88;
        public const int FEAT_IMPROVED_CRITICAL_TWO_BLADED_SWORD = 89;
        public const int FEAT_WEAPON_FOCUS_DAGGER = 90;
        public const int FEAT_WEAPON_FOCUS_DART = 91;
        public const int FEAT_WEAPON_FOCUS_HEAVY_CROSSBOW = 92;
        public const int FEAT_WEAPON_FOCUS_LIGHT_CROSSBOW = 93;
        public const int FEAT_WEAPON_FOCUS_LIGHT_MACE = 94;
        public const int FEAT_WEAPON_FOCUS_MORNING_STAR = 95;
        public const int FEAT_WEAPON_FOCUS_STAFF = 96;
        public const int FEAT_WEAPON_FOCUS_SPEAR = 97;
        public const int FEAT_WEAPON_FOCUS_SICKLE = 98;
        public const int FEAT_WEAPON_FOCUS_SLING = 99;
        public const int FEAT_WEAPON_FOCUS_UNARMED_STRIKE = 100;
        public const int FEAT_WEAPON_FOCUS_LONGBOW = 101;
        public const int FEAT_WEAPON_FOCUS_SHORTBOW = 102;
        public const int FEAT_WEAPON_FOCUS_SHORT_SWORD = 103;
        public const int FEAT_WEAPON_FOCUS_RAPIER = 104;
        public const int FEAT_WEAPON_FOCUS_SCIMITAR = 105;
        public const int FEAT_WEAPON_FOCUS_LONG_SWORD = 106;
        public const int FEAT_WEAPON_FOCUS_GREAT_SWORD = 107;
        public const int FEAT_WEAPON_FOCUS_HAND_AXE = 108;
        public const int FEAT_WEAPON_FOCUS_THROWING_AXE = 109;
        public const int FEAT_WEAPON_FOCUS_BATTLE_AXE = 110;
        public const int FEAT_WEAPON_FOCUS_GREAT_AXE = 111;
        public const int FEAT_WEAPON_FOCUS_HALBERD = 112;
        public const int FEAT_WEAPON_FOCUS_LIGHT_HAMMER = 113;
        public const int FEAT_WEAPON_FOCUS_LIGHT_FLAIL = 114;
        public const int FEAT_WEAPON_FOCUS_WAR_HAMMER = 115;
        public const int FEAT_WEAPON_FOCUS_HEAVY_FLAIL = 116;
        public const int FEAT_WEAPON_FOCUS_KAMA = 117;
        public const int FEAT_WEAPON_FOCUS_KUKRI = 118;
        // int FEAT_WEAPON_FOCUS_NUNCHAKU = 119;
        public const int FEAT_WEAPON_FOCUS_SHURIKEN = 120;
        public const int FEAT_WEAPON_FOCUS_SCYTHE = 121;
        public const int FEAT_WEAPON_FOCUS_KATANA = 122;
        public const int FEAT_WEAPON_FOCUS_BASTARD_SWORD = 123;
        public const int FEAT_WEAPON_FOCUS_DIRE_MACE = 125;
        public const int FEAT_WEAPON_FOCUS_DOUBLE_AXE = 126;
        public const int FEAT_WEAPON_FOCUS_TWO_BLADED_SWORD = 127;
        public const int FEAT_WEAPON_SPECIALIZATION_DAGGER = 128;
        public const int FEAT_WEAPON_SPECIALIZATION_DART = 129;
        public const int FEAT_WEAPON_SPECIALIZATION_HEAVY_CROSSBOW = 130;
        public const int FEAT_WEAPON_SPECIALIZATION_LIGHT_CROSSBOW = 131;
        public const int FEAT_WEAPON_SPECIALIZATION_LIGHT_MACE = 132;
        public const int FEAT_WEAPON_SPECIALIZATION_MORNING_STAR = 133;
        public const int FEAT_WEAPON_SPECIALIZATION_STAFF = 134;
        public const int FEAT_WEAPON_SPECIALIZATION_SPEAR = 135;
        public const int FEAT_WEAPON_SPECIALIZATION_SICKLE = 136;
        public const int FEAT_WEAPON_SPECIALIZATION_SLING = 137;
        public const int FEAT_WEAPON_SPECIALIZATION_UNARMED_STRIKE = 138;
        public const int FEAT_WEAPON_SPECIALIZATION_LONGBOW = 139;
        public const int FEAT_WEAPON_SPECIALIZATION_SHORTBOW = 140;
        public const int FEAT_WEAPON_SPECIALIZATION_SHORT_SWORD = 141;
        public const int FEAT_WEAPON_SPECIALIZATION_RAPIER = 142;
        public const int FEAT_WEAPON_SPECIALIZATION_SCIMITAR = 143;
        public const int FEAT_WEAPON_SPECIALIZATION_LONG_SWORD = 144;
        public const int FEAT_WEAPON_SPECIALIZATION_GREAT_SWORD = 145;
        public const int FEAT_WEAPON_SPECIALIZATION_HAND_AXE = 146;
        public const int FEAT_WEAPON_SPECIALIZATION_THROWING_AXE = 147;
        public const int FEAT_WEAPON_SPECIALIZATION_BATTLE_AXE = 148;
        public const int FEAT_WEAPON_SPECIALIZATION_GREAT_AXE = 149;
        public const int FEAT_WEAPON_SPECIALIZATION_HALBERD = 150;
        public const int FEAT_WEAPON_SPECIALIZATION_LIGHT_HAMMER = 151;
        public const int FEAT_WEAPON_SPECIALIZATION_LIGHT_FLAIL = 152;
        public const int FEAT_WEAPON_SPECIALIZATION_WAR_HAMMER = 153;
        public const int FEAT_WEAPON_SPECIALIZATION_HEAVY_FLAIL = 154;
        public const int FEAT_WEAPON_SPECIALIZATION_KAMA = 155;
        public const int FEAT_WEAPON_SPECIALIZATION_KUKRI = 156;
        // int FEAT_WEAPON_SPECIALIZATION_NUNCHAKU = 157;
        public const int FEAT_WEAPON_SPECIALIZATION_SHURIKEN = 158;
        public const int FEAT_WEAPON_SPECIALIZATION_SCYTHE = 159;
        public const int FEAT_WEAPON_SPECIALIZATION_KATANA = 160;
        public const int FEAT_WEAPON_SPECIALIZATION_BASTARD_SWORD = 161;
        public const int FEAT_WEAPON_SPECIALIZATION_DIRE_MACE = 163;
        public const int FEAT_WEAPON_SPECIALIZATION_DOUBLE_AXE = 164;
        public const int FEAT_WEAPON_SPECIALIZATION_TWO_BLADED_SWORD = 165;
        public const int FEAT_SPELL_FOCUS_CONJURATION = 166;
        public const int FEAT_SPELL_FOCUS_DIVINATION = 167;
        public const int FEAT_SPELL_FOCUS_ENCHANTMENT = 168;
        public const int FEAT_SPELL_FOCUS_EVOCATION = 169;
        public const int FEAT_SPELL_FOCUS_ILLUSION = 170;
        public const int FEAT_SPELL_FOCUS_NECROMANCY = 171;
        public const int FEAT_SPELL_FOCUS_TRANSMUTATION = 172;
        public const int FEAT_SKILL_FOCUS_CONCENTRATION = 173;
        public const int FEAT_SKILL_FOCUS_DISABLE_TRAP = 174;
        public const int FEAT_SKILL_FOCUS_DISCIPLINE = 175;
        public const int FEAT_SKILL_FOCUS_HEAL = 177;
        public const int FEAT_SKILL_FOCUS_HIDE = 178;
        public const int FEAT_SKILL_FOCUS_LISTEN = 179;
        public const int FEAT_SKILL_FOCUS_LORE = 180;
        public const int FEAT_SKILL_FOCUS_MOVE_SILENTLY = 181;
        public const int FEAT_SKILL_FOCUS_OPEN_LOCK = 182;
        public const int FEAT_SKILL_FOCUS_PARRY = 183;
        public const int FEAT_SKILL_FOCUS_PERFORM = 184;
        public const int FEAT_SKILL_FOCUS_PERSUADE = 185;
        public const int FEAT_SKILL_FOCUS_PICK_POCKET = 186;
        public const int FEAT_SKILL_FOCUS_SEARCH = 187;
        public const int FEAT_SKILL_FOCUS_SET_TRAP = 188;
        public const int FEAT_SKILL_FOCUS_SPELLCRAFT = 189;
        public const int FEAT_SKILL_FOCUS_SPOT = 190;
        public const int FEAT_SKILL_FOCUS_TAUNT = 192;
        public const int FEAT_SKILL_FOCUS_USE_MAGIC_DEVICE = 193;
        public const int FEAT_BARBARIAN_ENDURANCE = 194;
        public const int FEAT_UNCANNY_DODGE_1 = 195;
        public const int FEAT_DAMAGE_REDUCTION = 196;
        public const int FEAT_BARDIC_KNOWLEDGE = 197;
        public const int FEAT_NATURE_SENSE = 198;
        public const int FEAT_ANIMAL_COMPANION = 199;
        public const int FEAT_WOODLAND_STRIDE = 200;
        public const int FEAT_TRACKLESS_STEP = 201;
        public const int FEAT_RESIST_NATURES_LURE = 202;
        public const int FEAT_VENOM_IMMUNITY = 203;
        public const int FEAT_FLURRY_OF_BLOWS = 204;
        public const int FEAT_EVASION = 206;
        public const int FEAT_MONK_ENDURANCE = 207;
        public const int FEAT_STILL_MIND = 208;
        public const int FEAT_PURITY_OF_BODY = 209;
        public const int FEAT_WHOLENESS_OF_BODY = 211;
        public const int FEAT_IMPROVED_EVASION = 212;
        public const int FEAT_KI_STRIKE = 213;
        public const int FEAT_DIAMOND_BODY = 214;
        public const int FEAT_DIAMOND_SOUL = 215;
        public const int FEAT_PERFECT_SELF = 216;
        public const int FEAT_DIVINE_GRACE = 217;
        public const int FEAT_DIVINE_HEALTH = 219;
        public const int FEAT_SNEAK_ATTACK = 221;
        public const int FEAT_CRIPPLING_STRIKE = 222;
        public const int FEAT_DEFENSIVE_ROLL = 223;
        public const int FEAT_OPPORTUNIST = 224;
        public const int FEAT_SKILL_MASTERY = 225;
        public const int FEAT_UNCANNY_REFLEX = 226;
        public const int FEAT_STONECUNNING = 227;
        public const int FEAT_DARKVISION = 228;
        public const int FEAT_HARDINESS_VERSUS_POISONS = 229;
        public const int FEAT_HARDINESS_VERSUS_SPELLS = 230;
        public const int FEAT_BATTLE_TRAINING_VERSUS_ORCS = 231;
        public const int FEAT_BATTLE_TRAINING_VERSUS_GOBLINS = 232;
        public const int FEAT_BATTLE_TRAINING_VERSUS_GIANTS = 233;
        public const int FEAT_SKILL_AFFINITY_LORE = 234;
        public const int FEAT_IMMUNITY_TO_SLEEP = 235;
        public const int FEAT_HARDINESS_VERSUS_ENCHANTMENTS = 236;
        public const int FEAT_SKILL_AFFINITY_LISTEN = 237;
        public const int FEAT_SKILL_AFFINITY_SEARCH = 238;
        public const int FEAT_SKILL_AFFINITY_SPOT = 239;
        public const int FEAT_KEEN_SENSE = 240;
        public const int FEAT_HARDINESS_VERSUS_ILLUSIONS = 241;
        public const int FEAT_BATTLE_TRAINING_VERSUS_REPTILIANS = 242;
        public const int FEAT_SKILL_AFFINITY_CONCENTRATION = 243;
        public const int FEAT_PARTIAL_SKILL_AFFINITY_LISTEN = 244;
        public const int FEAT_PARTIAL_SKILL_AFFINITY_SEARCH = 245;
        public const int FEAT_PARTIAL_SKILL_AFFINITY_SPOT = 246;
        public const int FEAT_SKILL_AFFINITY_MOVE_SILENTLY = 247;
        public const int FEAT_LUCKY = 248;
        public const int FEAT_FEARLESS = 249;
        public const int FEAT_GOOD_AIM = 250;
        public const int FEAT_UNCANNY_DODGE_2 = 251;
        public const int FEAT_UNCANNY_DODGE_3 = 252;
        public const int FEAT_UNCANNY_DODGE_4 = 253;
        public const int FEAT_UNCANNY_DODGE_5 = 254;
        public const int FEAT_UNCANNY_DODGE_6 = 255;
        public const int FEAT_WEAPON_PROFICIENCY_ELF = 256;
        public const int FEAT_BARD_SONGS = 257;
        public const int FEAT_QUICK_TO_MASTER = 258;
        public const int FEAT_SLIPPERY_MIND = 259;
        public const int FEAT_MONK_AC_BONUS = 260;
        public const int FEAT_FAVORED_ENEMY_DWARF = 261;
        public const int FEAT_FAVORED_ENEMY_ELF = 262;
        public const int FEAT_FAVORED_ENEMY_GNOME = 263;
        public const int FEAT_FAVORED_ENEMY_HALFLING = 264;
        public const int FEAT_FAVORED_ENEMY_HALFELF = 265;
        public const int FEAT_FAVORED_ENEMY_HALFORC = 266;
        public const int FEAT_FAVORED_ENEMY_HUMAN = 267;
        public const int FEAT_FAVORED_ENEMY_ABERRATION = 268;
        public const int FEAT_FAVORED_ENEMY_ANIMAL = 269;
        public const int FEAT_FAVORED_ENEMY_BEAST = 270;
        public const int FEAT_FAVORED_ENEMY_CONSTRUCT = 271;
        public const int FEAT_FAVORED_ENEMY_DRAGON = 272;
        public const int FEAT_FAVORED_ENEMY_GOBLINOID = 273;
        public const int FEAT_FAVORED_ENEMY_MONSTROUS = 274;
        public const int FEAT_FAVORED_ENEMY_ORC = 275;
        public const int FEAT_FAVORED_ENEMY_REPTILIAN = 276;
        public const int FEAT_FAVORED_ENEMY_ELEMENTAL = 277;
        public const int FEAT_FAVORED_ENEMY_FEY = 278;
        public const int FEAT_FAVORED_ENEMY_GIANT = 279;
        public const int FEAT_FAVORED_ENEMY_MAGICAL_BEAST = 280;
        public const int FEAT_FAVORED_ENEMY_OUTSIDER = 281;
        public const int FEAT_FAVORED_ENEMY_SHAPECHANGER = 284;
        public const int FEAT_FAVORED_ENEMY_UNDEAD = 285;
        public const int FEAT_FAVORED_ENEMY_VERMIN = 286;
        public const int FEAT_WEAPON_PROFICIENCY_CREATURE = 289;
        public const int FEAT_WEAPON_SPECIALIZATION_CREATURE = 290;
        public const int FEAT_WEAPON_FOCUS_CREATURE = 291;
        public const int FEAT_IMPROVED_CRITICAL_CREATURE = 292;
        public const int FEAT_BARBARIAN_RAGE = 293;
        public const int FEAT_TURN_UNDEAD = 294;
        public const int FEAT_QUIVERING_PALM = 296;
        public const int FEAT_EMPTY_BODY = 297;
        // int FEAT_DETECT_EVIL = 298;
        public const int FEAT_LAY_ON_HANDS = 299;
        public const int FEAT_AURA_OF_COURAGE = 300;
        public const int FEAT_SMITE_EVIL = 301;
        public const int FEAT_REMOVE_DISEASE = 302;
        public const int FEAT_SUMMON_FAMILIAR = 303;
        public const int FEAT_ELEMENTAL_SHAPE = 304;
        public const int FEAT_WILD_SHAPE = 305;
        public const int FEAT_WAR_DOMAIN_POWER = 306;
        public const int FEAT_STRENGTH_DOMAIN_POWER = 307;
        public const int FEAT_PROTECTION_DOMAIN_POWER = 308;
        public const int FEAT_LUCK_DOMAIN_POWER = 309;
        public const int FEAT_DEATH_DOMAIN_POWER = 310;
        public const int FEAT_AIR_DOMAIN_POWER = 311;
        public const int FEAT_ANIMAL_DOMAIN_POWER = 312;
        public const int FEAT_DESTRUCTION_DOMAIN_POWER = 313;
        public const int FEAT_EARTH_DOMAIN_POWER = 314;
        public const int FEAT_EVIL_DOMAIN_POWER = 315;
        public const int FEAT_FIRE_DOMAIN_POWER = 316;
        public const int FEAT_GOOD_DOMAIN_POWER = 317;
        public const int FEAT_HEALING_DOMAIN_POWER = 318;
        public const int FEAT_KNOWLEDGE_DOMAIN_POWER = 319;
        public const int FEAT_MAGIC_DOMAIN_POWER = 320;
        public const int FEAT_PLANT_DOMAIN_POWER = 321;
        public const int FEAT_SUN_DOMAIN_POWER = 322;
        public const int FEAT_TRAVEL_DOMAIN_POWER = 323;
        public const int FEAT_TRICKERY_DOMAIN_POWER = 324;
        public const int FEAT_WATER_DOMAIN_POWER = 325;
        public const int FEAT_LOWLIGHTVISION = 354;
        public const int FEAT_IMPROVED_INITIATIVE = 377;
        public const int FEAT_ARTIST = 378;
        public const int FEAT_BLOODED = 379;
        public const int FEAT_BULLHEADED = 380;
        public const int FEAT_COURTLY_MAGOCRACY = 381;
        public const int FEAT_LUCK_OF_HEROES = 382;
        public const int FEAT_RESIST_POISON = 383;
        public const int FEAT_SILVER_PALM = 384;
        public const int FEAT_SNAKEBLOOD = 386;
        public const int FEAT_STEALTHY = 387;
        public const int FEAT_STRONGSOUL = 388;
        public const int FEAT_EXPERTISE = 389;
        public const int FEAT_IMPROVED_EXPERTISE = 390;
        public const int FEAT_GREAT_CLEAVE = 391;
        public const int FEAT_SPRING_ATTACK = 392;
        public const int FEAT_GREATER_SPELL_FOCUS_ABJURATION = 393;
        public const int FEAT_GREATER_SPELL_FOCUS_CONJURATION = 394;
        public const int FEAT_GREATER_SPELL_FOCUS_DIVINIATION = 395;
        public const int FEAT_GREATER_SPELL_FOCUS_DIVINATION = 395;
        public const int FEAT_GREATER_SPELL_FOCUS_ENCHANTMENT = 396;
        public const int FEAT_GREATER_SPELL_FOCUS_EVOCATION = 397;
        public const int FEAT_GREATER_SPELL_FOCUS_ILLUSION = 398;
        public const int FEAT_GREATER_SPELL_FOCUS_NECROMANCY = 399;
        public const int FEAT_GREATER_SPELL_FOCUS_TRANSMUTATION = 400;
        public const int FEAT_GREATER_SPELL_PENETRATION = 401;
        public const int FEAT_THUG = 402;
        public const int FEAT_SKILLFOCUS_APPRAISE = 404;
        public const int FEAT_SKILL_FOCUS_TUMBLE = 406;
        public const int FEAT_SKILL_FOCUS_CRAFT_TRAP = 407;
        public const int FEAT_BLIND_FIGHT = 408;
        public const int FEAT_CIRCLE_KICK = 409;
        public const int FEAT_EXTRA_STUNNING_ATTACK = 410;
        public const int FEAT_RAPID_RELOAD = 411;
        public const int FEAT_ZEN_ARCHERY = 412;
        public const int FEAT_DIVINE_MIGHT = 413;
        public const int FEAT_DIVINE_SHIELD = 414;
        public const int FEAT_ARCANE_DEFENSE_ABJURATION = 415;
        public const int FEAT_ARCANE_DEFENSE_CONJURATION = 416;
        public const int FEAT_ARCANE_DEFENSE_DIVINATION = 417;
        public const int FEAT_ARCANE_DEFENSE_ENCHANTMENT = 418;
        public const int FEAT_ARCANE_DEFENSE_EVOCATION = 419;
        public const int FEAT_ARCANE_DEFENSE_ILLUSION = 420;
        public const int FEAT_ARCANE_DEFENSE_NECROMANCY = 421;
        public const int FEAT_ARCANE_DEFENSE_TRANSMUTATION = 422;
        public const int FEAT_EXTRA_MUSIC = 423;
        public const int FEAT_LINGERING_SONG = 424;
        public const int FEAT_DIRTY_FIGHTING = 425;
        public const int FEAT_RESIST_DISEASE = 426;
        public const int FEAT_RESIST_ENERGY_COLD = 427;
        public const int FEAT_RESIST_ENERGY_ACID = 428;
        public const int FEAT_RESIST_ENERGY_FIRE = 429;
        public const int FEAT_RESIST_ENERGY_ELECTRICAL = 430;
        public const int FEAT_RESIST_ENERGY_SONIC = 431;
        public const int FEAT_HIDE_IN_PLAIN_SIGHT = 433;
        public const int FEAT_SHADOW_DAZE = 434;
        public const int FEAT_SUMMON_SHADOW = 435;
        public const int FEAT_SHADOW_EVADE = 436;
        public const int FEAT_DENEIRS_EYE = 437;
        public const int FEAT_TYMORAS_SMILE = 438;
        public const int FEAT_LLIIRAS_HEART = 439;
        public const int FEAT_CRAFT_HARPER_ITEM = 440;
        public const int FEAT_HARPER_SLEEP = 441;
        public const int FEAT_HARPER_CATS_GRACE = 442;
        public const int FEAT_HARPER_EAGLES_SPLENDOR = 443;
        public const int FEAT_HARPER_INVISIBILITY = 444;
        public const int FEAT_PRESTIGE_ENCHANT_ARROW_1 = 445;
        public const int FEAT_PRESTIGE_ENCHANT_ARROW_2 = 446;
        public const int FEAT_PRESTIGE_ENCHANT_ARROW_3 = 447;
        public const int FEAT_PRESTIGE_ENCHANT_ARROW_4 = 448;
        public const int FEAT_PRESTIGE_ENCHANT_ARROW_5 = 449;
        public const int FEAT_PRESTIGE_IMBUE_ARROW = 450;
        public const int FEAT_PRESTIGE_SEEKER_ARROW_1 = 451;
        public const int FEAT_PRESTIGE_SEEKER_ARROW_2 = 452;
        public const int FEAT_PRESTIGE_HAIL_OF_ARROWS = 453;
        public const int FEAT_PRESTIGE_ARROW_OF_DEATH = 454;
        public const int FEAT_PRESTIGE_DEATH_ATTACK_1 = 455;
        public const int FEAT_PRESTIGE_DEATH_ATTACK_2 = 456;
        public const int FEAT_PRESTIGE_DEATH_ATTACK_3 = 457;
        public const int FEAT_PRESTIGE_DEATH_ATTACK_4 = 458;
        public const int FEAT_PRESTIGE_DEATH_ATTACK_5 = 459;
        public const int FEAT_BLACKGUARD_SNEAK_ATTACK_1D6 = 460;
        public const int FEAT_BLACKGUARD_SNEAK_ATTACK_2D6 = 461;
        public const int FEAT_BLACKGUARD_SNEAK_ATTACK_3D6 = 462;
        public const int FEAT_PRESTIGE_POISON_SAVE_1 = 463;
        public const int FEAT_PRESTIGE_POISON_SAVE_2 = 464;
        public const int FEAT_PRESTIGE_POISON_SAVE_3 = 465;
        public const int FEAT_PRESTIGE_POISON_SAVE_4 = 466;
        public const int FEAT_PRESTIGE_POISON_SAVE_5 = 467;
        public const int FEAT_PRESTIGE_SPELL_GHOSTLY_VISAGE = 468;
        public const int FEAT_PRESTIGE_DARKNESS = 469;
        public const int FEAT_PRESTIGE_INVISIBILITY_1 = 470;
        public const int FEAT_PRESTIGE_INVISIBILITY_2 = 471;
        public const int FEAT_SMITE_GOOD = 472;
        public const int FEAT_PRESTIGE_DARK_BLESSING = 473;
        public const int FEAT_INFLICT_LIGHT_WOUNDS = 474;
        public const int FEAT_INFLICT_MODERATE_WOUNDS = 475;
        public const int FEAT_INFLICT_SERIOUS_WOUNDS = 476;
        public const int FEAT_INFLICT_CRITICAL_WOUNDS = 477;
        public const int FEAT_BULLS_STRENGTH = 478;
        public const int FEAT_CONTAGION = 479;
        public const int FEAT_EYE_OF_GRUUMSH_BLINDING_SPITTLE = 480;
        public const int FEAT_EYE_OF_GRUUMSH_BLINDING_SPITTLE_2 = 481;
        public const int FEAT_EYE_OF_GRUUMSH_COMMAND_THE_HORDE = 482;
        public const int FEAT_EYE_OF_GRUUMSH_SWING_BLINDLY = 483;
        public const int FEAT_EYE_OF_GRUUMSH_RITUAL_SCARRING = 484;
        public const int FEAT_BLINDSIGHT_5_FEET = 485;
        public const int FEAT_BLINDSIGHT_10_FEET = 486;
        public const int FEAT_EYE_OF_GRUUMSH_SIGHT_OF_GRUUMSH = 487;
        public const int FEAT_BLINDSIGHT_60_FEET = 488;
        public const int FEAT_SHOU_DISCIPLE_DODGE_2 = 489;
        public const int FEAT_EPIC_ARMOR_SKIN = 490;
        public const int FEAT_EPIC_BLINDING_SPEED = 491;
        public const int FEAT_EPIC_DAMAGE_REDUCTION_3 = 492;
        public const int FEAT_EPIC_DAMAGE_REDUCTION_6 = 493;
        public const int FEAT_EPIC_DAMAGE_REDUCTION_9 = 494;
        public const int FEAT_EPIC_DEVASTATING_CRITICAL_CLUB = 495;
        public const int FEAT_EPIC_DEVASTATING_CRITICAL_DAGGER = 496;
        public const int FEAT_EPIC_DEVASTATING_CRITICAL_DART = 497;
        public const int FEAT_EPIC_DEVASTATING_CRITICAL_HEAVYCROSSBOW = 498;
        public const int FEAT_EPIC_DEVASTATING_CRITICAL_LIGHTCROSSBOW = 499;
        public const int FEAT_EPIC_DEVASTATING_CRITICAL_LIGHTMACE = 500;
        public const int FEAT_EPIC_DEVASTATING_CRITICAL_MORNINGSTAR = 501;
        public const int FEAT_EPIC_DEVASTATING_CRITICAL_QUARTERSTAFF = 502;
        public const int FEAT_EPIC_DEVASTATING_CRITICAL_SHORTSPEAR = 503;
        public const int FEAT_EPIC_DEVASTATING_CRITICAL_SICKLE = 504;
        public const int FEAT_EPIC_DEVASTATING_CRITICAL_SLING = 505;
        public const int FEAT_EPIC_DEVASTATING_CRITICAL_UNARMED = 506;
        public const int FEAT_EPIC_DEVASTATING_CRITICAL_LONGBOW = 507;
        public const int FEAT_EPIC_DEVASTATING_CRITICAL_SHORTBOW = 508;
        public const int FEAT_EPIC_DEVASTATING_CRITICAL_SHORTSWORD = 509;
        public const int FEAT_EPIC_DEVASTATING_CRITICAL_RAPIER = 510;
        public const int FEAT_EPIC_DEVASTATING_CRITICAL_SCIMITAR = 511;
        public const int FEAT_EPIC_DEVASTATING_CRITICAL_LONGSWORD = 512;
        public const int FEAT_EPIC_DEVASTATING_CRITICAL_GREATSWORD = 513;
        public const int FEAT_EPIC_DEVASTATING_CRITICAL_HANDAXE = 514;
        public const int FEAT_EPIC_DEVASTATING_CRITICAL_THROWINGAXE = 515;
        public const int FEAT_EPIC_DEVASTATING_CRITICAL_BATTLEAXE = 516;
        public const int FEAT_EPIC_DEVASTATING_CRITICAL_GREATAXE = 517;
        public const int FEAT_EPIC_DEVASTATING_CRITICAL_HALBERD = 518;
        public const int FEAT_EPIC_DEVASTATING_CRITICAL_LIGHTHAMMER = 519;
        public const int FEAT_EPIC_DEVASTATING_CRITICAL_LIGHTFLAIL = 520;
        public const int FEAT_EPIC_DEVASTATING_CRITICAL_WARHAMMER = 521;
        public const int FEAT_EPIC_DEVASTATING_CRITICAL_HEAVYFLAIL = 522;
        public const int FEAT_EPIC_DEVASTATING_CRITICAL_KAMA = 523;
        public const int FEAT_EPIC_DEVASTATING_CRITICAL_KUKRI = 524;
        public const int FEAT_EPIC_DEVASTATING_CRITICAL_SHURIKEN = 525;
        public const int FEAT_EPIC_DEVASTATING_CRITICAL_SCYTHE = 526;
        public const int FEAT_EPIC_DEVASTATING_CRITICAL_KATANA = 527;
        public const int FEAT_EPIC_DEVASTATING_CRITICAL_BASTARDSWORD = 528;
        public const int FEAT_EPIC_DEVASTATING_CRITICAL_DIREMACE = 529;
        public const int FEAT_EPIC_DEVASTATING_CRITICAL_DOUBLEAXE = 530;
        public const int FEAT_EPIC_DEVASTATING_CRITICAL_TWOBLADEDSWORD = 531;
        public const int FEAT_EPIC_DEVASTATING_CRITICAL_CREATURE = 532;
        public const int FEAT_EPIC_ENERGY_RESISTANCE_COLD_1 = 533;
        public const int FEAT_EPIC_ENERGY_RESISTANCE_COLD_2 = 534;
        public const int FEAT_EPIC_ENERGY_RESISTANCE_COLD_3 = 535;
        public const int FEAT_EPIC_ENERGY_RESISTANCE_COLD_4 = 536;
        public const int FEAT_EPIC_ENERGY_RESISTANCE_COLD_5 = 537;
        public const int FEAT_EPIC_ENERGY_RESISTANCE_COLD_6 = 538;
        public const int FEAT_EPIC_ENERGY_RESISTANCE_COLD_7 = 539;
        public const int FEAT_EPIC_ENERGY_RESISTANCE_COLD_8 = 540;
        public const int FEAT_EPIC_ENERGY_RESISTANCE_COLD_9 = 541;
        public const int FEAT_EPIC_ENERGY_RESISTANCE_COLD_10 = 542;
        public const int FEAT_EPIC_ENERGY_RESISTANCE_ACID_1 = 543;
        public const int FEAT_EPIC_ENERGY_RESISTANCE_ACID_2 = 544;
        public const int FEAT_EPIC_ENERGY_RESISTANCE_ACID_3 = 545;
        public const int FEAT_EPIC_ENERGY_RESISTANCE_ACID_4 = 546;
        public const int FEAT_EPIC_ENERGY_RESISTANCE_ACID_5 = 547;
        public const int FEAT_EPIC_ENERGY_RESISTANCE_ACID_6 = 548;
        public const int FEAT_EPIC_ENERGY_RESISTANCE_ACID_7 = 549;
        public const int FEAT_EPIC_ENERGY_RESISTANCE_ACID_8 = 550;
        public const int FEAT_EPIC_ENERGY_RESISTANCE_ACID_9 = 551;
        public const int FEAT_EPIC_ENERGY_RESISTANCE_ACID_10 = 552;
        public const int FEAT_EPIC_ENERGY_RESISTANCE_FIRE_1 = 553;
        public const int FEAT_EPIC_ENERGY_RESISTANCE_FIRE_2 = 554;
        public const int FEAT_EPIC_ENERGY_RESISTANCE_FIRE_3 = 555;
        public const int FEAT_EPIC_ENERGY_RESISTANCE_FIRE_4 = 556;
        public const int FEAT_EPIC_ENERGY_RESISTANCE_FIRE_5 = 557;
        public const int FEAT_EPIC_ENERGY_RESISTANCE_FIRE_6 = 558;
        public const int FEAT_EPIC_ENERGY_RESISTANCE_FIRE_7 = 559;
        public const int FEAT_EPIC_ENERGY_RESISTANCE_FIRE_8 = 560;
        public const int FEAT_EPIC_ENERGY_RESISTANCE_FIRE_9 = 561;
        public const int FEAT_EPIC_ENERGY_RESISTANCE_FIRE_10 = 562;
        public const int FEAT_EPIC_ENERGY_RESISTANCE_ELECTRICAL_1 = 563;
        public const int FEAT_EPIC_ENERGY_RESISTANCE_ELECTRICAL_2 = 564;
        public const int FEAT_EPIC_ENERGY_RESISTANCE_ELECTRICAL_3 = 565;
        public const int FEAT_EPIC_ENERGY_RESISTANCE_ELECTRICAL_4 = 566;
        public const int FEAT_EPIC_ENERGY_RESISTANCE_ELECTRICAL_5 = 567;
        public const int FEAT_EPIC_ENERGY_RESISTANCE_ELECTRICAL_6 = 568;
        public const int FEAT_EPIC_ENERGY_RESISTANCE_ELECTRICAL_7 = 569;
        public const int FEAT_EPIC_ENERGY_RESISTANCE_ELECTRICAL_8 = 570;
        public const int FEAT_EPIC_ENERGY_RESISTANCE_ELECTRICAL_9 = 571;
        public const int FEAT_EPIC_ENERGY_RESISTANCE_ELECTRICAL_10 = 572;
        public const int FEAT_EPIC_ENERGY_RESISTANCE_SONIC_1 = 573;
        public const int FEAT_EPIC_ENERGY_RESISTANCE_SONIC_2 = 574;
        public const int FEAT_EPIC_ENERGY_RESISTANCE_SONIC_3 = 575;
        public const int FEAT_EPIC_ENERGY_RESISTANCE_SONIC_4 = 576;
        public const int FEAT_EPIC_ENERGY_RESISTANCE_SONIC_5 = 577;
        public const int FEAT_EPIC_ENERGY_RESISTANCE_SONIC_6 = 578;
        public const int FEAT_EPIC_ENERGY_RESISTANCE_SONIC_7 = 579;
        public const int FEAT_EPIC_ENERGY_RESISTANCE_SONIC_8 = 580;
        public const int FEAT_EPIC_ENERGY_RESISTANCE_SONIC_9 = 581;
        public const int FEAT_EPIC_ENERGY_RESISTANCE_SONIC_10 = 582;
        public const int FEAT_EPIC_FORTITUDE = 583;
        public const int FEAT_EPIC_PROWESS = 584;
        public const int FEAT_EPIC_REFLEXES = 585;
        public const int FEAT_EPIC_REPUTATION = 586;
        public const int FEAT_EPIC_SKILL_FOCUS_ANIMAL_EMPATHY = 587;
        public const int FEAT_EPIC_SKILL_FOCUS_APPRAISE = 588;
        public const int FEAT_EPIC_SKILL_FOCUS_CONCENTRATION = 589;
        public const int FEAT_EPIC_SKILL_FOCUS_CRAFT_TRAP = 590;
        public const int FEAT_EPIC_SKILL_FOCUS_DISABLETRAP = 591;
        public const int FEAT_EPIC_SKILL_FOCUS_DISCIPLINE = 592;
        public const int FEAT_EPIC_SKILL_FOCUS_HEAL = 593;
        public const int FEAT_EPIC_SKILL_FOCUS_HIDE = 594;
        public const int FEAT_EPIC_SKILL_FOCUS_LISTEN = 595;
        public const int FEAT_EPIC_SKILL_FOCUS_LORE = 596;
        public const int FEAT_EPIC_SKILL_FOCUS_MOVESILENTLY = 597;
        public const int FEAT_EPIC_SKILL_FOCUS_OPENLOCK = 598;
        public const int FEAT_EPIC_SKILL_FOCUS_PARRY = 599;
        public const int FEAT_EPIC_SKILL_FOCUS_PERFORM = 600;
        public const int FEAT_EPIC_SKILL_FOCUS_PERSUADE = 601;
        public const int FEAT_EPIC_SKILL_FOCUS_PICKPOCKET = 602;
        public const int FEAT_EPIC_SKILL_FOCUS_SEARCH = 603;
        public const int FEAT_EPIC_SKILL_FOCUS_SETTRAP = 604;
        public const int FEAT_EPIC_SKILL_FOCUS_SPELLCRAFT = 605;
        public const int FEAT_EPIC_SKILL_FOCUS_SPOT = 606;
        public const int FEAT_EPIC_SKILL_FOCUS_TAUNT = 607;
        public const int FEAT_EPIC_SKILL_FOCUS_TUMBLE = 608;
        public const int FEAT_EPIC_SKILL_FOCUS_USEMAGICDEVICE = 609;
        public const int FEAT_EPIC_SPELL_FOCUS_ABJURATION = 610;
        public const int FEAT_EPIC_SPELL_FOCUS_CONJURATION = 611;
        public const int FEAT_EPIC_SPELL_FOCUS_DIVINATION = 612;
        public const int FEAT_EPIC_SPELL_FOCUS_ENCHANTMENT = 613;
        public const int FEAT_EPIC_SPELL_FOCUS_EVOCATION = 614;
        public const int FEAT_EPIC_SPELL_FOCUS_ILLUSION = 615;
        public const int FEAT_EPIC_SPELL_FOCUS_NECROMANCY = 616;
        public const int FEAT_EPIC_SPELL_FOCUS_TRANSMUTATION = 617;
        public const int FEAT_EPIC_SPELL_PENETRATION = 618;
        public const int FEAT_EPIC_WEAPON_FOCUS_CLUB = 619;
        public const int FEAT_EPIC_WEAPON_FOCUS_DAGGER = 620;
        public const int FEAT_EPIC_WEAPON_FOCUS_DART = 621;
        public const int FEAT_EPIC_WEAPON_FOCUS_HEAVYCROSSBOW = 622;
        public const int FEAT_EPIC_WEAPON_FOCUS_LIGHTCROSSBOW = 623;
        public const int FEAT_EPIC_WEAPON_FOCUS_LIGHTMACE = 624;
        public const int FEAT_EPIC_WEAPON_FOCUS_MORNINGSTAR = 625;
        public const int FEAT_EPIC_WEAPON_FOCUS_QUARTERSTAFF = 626;
        public const int FEAT_EPIC_WEAPON_FOCUS_SHORTSPEAR = 627;
        public const int FEAT_EPIC_WEAPON_FOCUS_SICKLE = 628;
        public const int FEAT_EPIC_WEAPON_FOCUS_SLING = 629;
        public const int FEAT_EPIC_WEAPON_FOCUS_UNARMED = 630;
        public const int FEAT_EPIC_WEAPON_FOCUS_LONGBOW = 631;
        public const int FEAT_EPIC_WEAPON_FOCUS_SHORTBOW = 632;
        public const int FEAT_EPIC_WEAPON_FOCUS_SHORTSWORD = 633;
        public const int FEAT_EPIC_WEAPON_FOCUS_RAPIER = 634;
        public const int FEAT_EPIC_WEAPON_FOCUS_SCIMITAR = 635;
        public const int FEAT_EPIC_WEAPON_FOCUS_LONGSWORD = 636;
        public const int FEAT_EPIC_WEAPON_FOCUS_GREATSWORD = 637;
        public const int FEAT_EPIC_WEAPON_FOCUS_HANDAXE = 638;
        public const int FEAT_EPIC_WEAPON_FOCUS_THROWINGAXE = 639;
        public const int FEAT_EPIC_WEAPON_FOCUS_BATTLEAXE = 640;
        public const int FEAT_EPIC_WEAPON_FOCUS_GREATAXE = 641;
        public const int FEAT_EPIC_WEAPON_FOCUS_HALBERD = 642;
        public const int FEAT_EPIC_WEAPON_FOCUS_LIGHTHAMMER = 643;
        public const int FEAT_EPIC_WEAPON_FOCUS_LIGHTFLAIL = 644;
        public const int FEAT_EPIC_WEAPON_FOCUS_WARHAMMER = 645;
        public const int FEAT_EPIC_WEAPON_FOCUS_HEAVYFLAIL = 646;
        public const int FEAT_EPIC_WEAPON_FOCUS_KAMA = 647;
        public const int FEAT_EPIC_WEAPON_FOCUS_KUKRI = 648;
        public const int FEAT_EPIC_WEAPON_FOCUS_SHURIKEN = 649;
        public const int FEAT_EPIC_WEAPON_FOCUS_SCYTHE = 650;
        public const int FEAT_EPIC_WEAPON_FOCUS_KATANA = 651;
        public const int FEAT_EPIC_WEAPON_FOCUS_BASTARDSWORD = 652;
        public const int FEAT_EPIC_WEAPON_FOCUS_DIREMACE = 653;
        public const int FEAT_EPIC_WEAPON_FOCUS_DOUBLEAXE = 654;
        public const int FEAT_EPIC_WEAPON_FOCUS_TWOBLADEDSWORD = 655;
        public const int FEAT_EPIC_WEAPON_FOCUS_CREATURE = 656;
        public const int FEAT_EPIC_WEAPON_SPECIALIZATION_CLUB = 657;
        public const int FEAT_EPIC_WEAPON_SPECIALIZATION_DAGGER = 658;
        public const int FEAT_EPIC_WEAPON_SPECIALIZATION_DART = 659;
        public const int FEAT_EPIC_WEAPON_SPECIALIZATION_HEAVYCROSSBOW = 660;
        public const int FEAT_EPIC_WEAPON_SPECIALIZATION_LIGHTCROSSBOW = 661;
        public const int FEAT_EPIC_WEAPON_SPECIALIZATION_LIGHTMACE = 662;
        public const int FEAT_EPIC_WEAPON_SPECIALIZATION_MORNINGSTAR = 663;
        public const int FEAT_EPIC_WEAPON_SPECIALIZATION_QUARTERSTAFF = 664;
        public const int FEAT_EPIC_WEAPON_SPECIALIZATION_SHORTSPEAR = 665;
        public const int FEAT_EPIC_WEAPON_SPECIALIZATION_SICKLE = 666;
        public const int FEAT_EPIC_WEAPON_SPECIALIZATION_SLING = 667;
        public const int FEAT_EPIC_WEAPON_SPECIALIZATION_UNARMED = 668;
        public const int FEAT_EPIC_WEAPON_SPECIALIZATION_LONGBOW = 669;
        public const int FEAT_EPIC_WEAPON_SPECIALIZATION_SHORTBOW = 670;
        public const int FEAT_EPIC_WEAPON_SPECIALIZATION_SHORTSWORD = 671;
        public const int FEAT_EPIC_WEAPON_SPECIALIZATION_RAPIER = 672;
        public const int FEAT_EPIC_WEAPON_SPECIALIZATION_SCIMITAR = 673;
        public const int FEAT_EPIC_WEAPON_SPECIALIZATION_LONGSWORD = 674;
        public const int FEAT_EPIC_WEAPON_SPECIALIZATION_GREATSWORD = 675;
        public const int FEAT_EPIC_WEAPON_SPECIALIZATION_HANDAXE = 676;
        public const int FEAT_EPIC_WEAPON_SPECIALIZATION_THROWINGAXE = 677;
        public const int FEAT_EPIC_WEAPON_SPECIALIZATION_BATTLEAXE = 678;
        public const int FEAT_EPIC_WEAPON_SPECIALIZATION_GREATAXE = 679;
        public const int FEAT_EPIC_WEAPON_SPECIALIZATION_HALBERD = 680;
        public const int FEAT_EPIC_WEAPON_SPECIALIZATION_LIGHTHAMMER = 681;
        public const int FEAT_EPIC_WEAPON_SPECIALIZATION_LIGHTFLAIL = 682;
        public const int FEAT_EPIC_WEAPON_SPECIALIZATION_WARHAMMER = 683;
        public const int FEAT_EPIC_WEAPON_SPECIALIZATION_HEAVYFLAIL = 684;
        public const int FEAT_EPIC_WEAPON_SPECIALIZATION_KAMA = 685;
        public const int FEAT_EPIC_WEAPON_SPECIALIZATION_KUKRI = 686;
        public const int FEAT_EPIC_WEAPON_SPECIALIZATION_SHURIKEN = 687;
        public const int FEAT_EPIC_WEAPON_SPECIALIZATION_SCYTHE = 688;
        public const int FEAT_EPIC_WEAPON_SPECIALIZATION_KATANA = 689;
        public const int FEAT_EPIC_WEAPON_SPECIALIZATION_BASTARDSWORD = 690;
        public const int FEAT_EPIC_WEAPON_SPECIALIZATION_DIREMACE = 691;
        public const int FEAT_EPIC_WEAPON_SPECIALIZATION_DOUBLEAXE = 692;
        public const int FEAT_EPIC_WEAPON_SPECIALIZATION_TWOBLADEDSWORD = 693;
        public const int FEAT_EPIC_WEAPON_SPECIALIZATION_CREATURE = 694;
        public const int FEAT_EPIC_WILL = 695;
        public const int FEAT_EPIC_IMPROVED_COMBAT_CASTING = 696;
        public const int FEAT_EPIC_IMPROVED_KI_STRIKE_4 = 697;
        public const int FEAT_EPIC_IMPROVED_KI_STRIKE_5 = 698;
        public const int FEAT_EPIC_IMPROVED_SPELL_RESISTANCE_1 = 699;
        public const int FEAT_EPIC_IMPROVED_SPELL_RESISTANCE_2 = 700;
        public const int FEAT_EPIC_IMPROVED_SPELL_RESISTANCE_3 = 701;
        public const int FEAT_EPIC_IMPROVED_SPELL_RESISTANCE_4 = 702;
        public const int FEAT_EPIC_IMPROVED_SPELL_RESISTANCE_5 = 703;
        public const int FEAT_EPIC_IMPROVED_SPELL_RESISTANCE_6 = 704;
        public const int FEAT_EPIC_IMPROVED_SPELL_RESISTANCE_7 = 705;
        public const int FEAT_EPIC_IMPROVED_SPELL_RESISTANCE_8 = 706;
        public const int FEAT_EPIC_IMPROVED_SPELL_RESISTANCE_9 = 707;
        public const int FEAT_EPIC_IMPROVED_SPELL_RESISTANCE_10 = 708;
        public const int FEAT_EPIC_OVERWHELMING_CRITICAL_CLUB = 709;
        public const int FEAT_EPIC_OVERWHELMING_CRITICAL_DAGGER = 710;
        public const int FEAT_EPIC_OVERWHELMING_CRITICAL_DART = 711;
        public const int FEAT_EPIC_OVERWHELMING_CRITICAL_HEAVYCROSSBOW = 712;
        public const int FEAT_EPIC_OVERWHELMING_CRITICAL_LIGHTCROSSBOW = 713;
        public const int FEAT_EPIC_OVERWHELMING_CRITICAL_LIGHTMACE = 714;
        public const int FEAT_EPIC_OVERWHELMING_CRITICAL_MORNINGSTAR = 715;
        public const int FEAT_EPIC_OVERWHELMING_CRITICAL_QUARTERSTAFF = 716;
        public const int FEAT_EPIC_OVERWHELMING_CRITICAL_SHORTSPEAR = 717;
        public const int FEAT_EPIC_OVERWHELMING_CRITICAL_SICKLE = 718;
        public const int FEAT_EPIC_OVERWHELMING_CRITICAL_SLING = 719;
        public const int FEAT_EPIC_OVERWHELMING_CRITICAL_UNARMED = 720;
        public const int FEAT_EPIC_OVERWHELMING_CRITICAL_LONGBOW = 721;
        public const int FEAT_EPIC_OVERWHELMING_CRITICAL_SHORTBOW = 722;
        public const int FEAT_EPIC_OVERWHELMING_CRITICAL_SHORTSWORD = 723;
        public const int FEAT_EPIC_OVERWHELMING_CRITICAL_RAPIER = 724;
        public const int FEAT_EPIC_OVERWHELMING_CRITICAL_SCIMITAR = 725;
        public const int FEAT_EPIC_OVERWHELMING_CRITICAL_LONGSWORD = 726;
        public const int FEAT_EPIC_OVERWHELMING_CRITICAL_GREATSWORD = 727;
        public const int FEAT_EPIC_OVERWHELMING_CRITICAL_HANDAXE = 728;
        public const int FEAT_EPIC_OVERWHELMING_CRITICAL_THROWINGAXE = 729;
        public const int FEAT_EPIC_OVERWHELMING_CRITICAL_BATTLEAXE = 730;
        public const int FEAT_EPIC_OVERWHELMING_CRITICAL_GREATAXE = 731;
        public const int FEAT_EPIC_OVERWHELMING_CRITICAL_HALBERD = 732;
        public const int FEAT_EPIC_OVERWHELMING_CRITICAL_LIGHTHAMMER = 733;
        public const int FEAT_EPIC_OVERWHELMING_CRITICAL_LIGHTFLAIL = 734;
        public const int FEAT_EPIC_OVERWHELMING_CRITICAL_WARHAMMER = 735;
        public const int FEAT_EPIC_OVERWHELMING_CRITICAL_HEAVYFLAIL = 736;
        public const int FEAT_EPIC_OVERWHELMING_CRITICAL_KAMA = 737;
        public const int FEAT_EPIC_OVERWHELMING_CRITICAL_KUKRI = 738;
        public const int FEAT_EPIC_OVERWHELMING_CRITICAL_SHURIKEN = 739;
        public const int FEAT_EPIC_OVERWHELMING_CRITICAL_SCYTHE = 740;
        public const int FEAT_EPIC_OVERWHELMING_CRITICAL_KATANA = 741;
        public const int FEAT_EPIC_OVERWHELMING_CRITICAL_BASTARDSWORD = 742;
        public const int FEAT_EPIC_OVERWHELMING_CRITICAL_DIREMACE = 743;
        public const int FEAT_EPIC_OVERWHELMING_CRITICAL_DOUBLEAXE = 744;
        public const int FEAT_EPIC_OVERWHELMING_CRITICAL_TWOBLADEDSWORD = 745;
        public const int FEAT_EPIC_OVERWHELMING_CRITICAL_CREATURE = 746;
        public const int FEAT_EPIC_PERFECT_HEALTH = 747;
        public const int FEAT_EPIC_SELF_CONCEALMENT_10 = 748;
        public const int FEAT_EPIC_SELF_CONCEALMENT_20 = 749;
        public const int FEAT_EPIC_SELF_CONCEALMENT_30 = 750;
        public const int FEAT_EPIC_SELF_CONCEALMENT_40 = 751;
        public const int FEAT_EPIC_SELF_CONCEALMENT_50 = 752;
        public const int FEAT_EPIC_SUPERIOR_INITIATIVE = 753;
        public const int FEAT_EPIC_TOUGHNESS_1 = 754;
        public const int FEAT_EPIC_TOUGHNESS_2 = 755;
        public const int FEAT_EPIC_TOUGHNESS_3 = 756;
        public const int FEAT_EPIC_TOUGHNESS_4 = 757;
        public const int FEAT_EPIC_TOUGHNESS_5 = 758;
        public const int FEAT_EPIC_TOUGHNESS_6 = 759;
        public const int FEAT_EPIC_TOUGHNESS_7 = 760;
        public const int FEAT_EPIC_TOUGHNESS_8 = 761;
        public const int FEAT_EPIC_TOUGHNESS_9 = 762;
        public const int FEAT_EPIC_TOUGHNESS_10 = 763;
        public const int FEAT_EPIC_GREAT_CHARISMA_1 = 764;
        public const int FEAT_EPIC_GREAT_CHARISMA_2 = 765;
        public const int FEAT_EPIC_GREAT_CHARISMA_3 = 766;
        public const int FEAT_EPIC_GREAT_CHARISMA_4 = 767;
        public const int FEAT_EPIC_GREAT_CHARISMA_5 = 768;
        public const int FEAT_EPIC_GREAT_CHARISMA_6 = 769;
        public const int FEAT_EPIC_GREAT_CHARISMA_7 = 770;
        public const int FEAT_EPIC_GREAT_CHARISMA_8 = 771;
        public const int FEAT_EPIC_GREAT_CHARISMA_9 = 772;
        public const int FEAT_EPIC_GREAT_CHARISMA_10 = 773;
        public const int FEAT_EPIC_GREAT_CONSTITUTION_1 = 774;
        public const int FEAT_EPIC_GREAT_CONSTITUTION_2 = 775;
        public const int FEAT_EPIC_GREAT_CONSTITUTION_3 = 776;
        public const int FEAT_EPIC_GREAT_CONSTITUTION_4 = 777;
        public const int FEAT_EPIC_GREAT_CONSTITUTION_5 = 778;
        public const int FEAT_EPIC_GREAT_CONSTITUTION_6 = 779;
        public const int FEAT_EPIC_GREAT_CONSTITUTION_7 = 780;
        public const int FEAT_EPIC_GREAT_CONSTITUTION_8 = 781;
        public const int FEAT_EPIC_GREAT_CONSTITUTION_9 = 782;
        public const int FEAT_EPIC_GREAT_CONSTITUTION_10 = 783;
        public const int FEAT_EPIC_GREAT_DEXTERITY_1 = 784;
        public const int FEAT_EPIC_GREAT_DEXTERITY_2 = 785;
        public const int FEAT_EPIC_GREAT_DEXTERITY_3 = 786;
        public const int FEAT_EPIC_GREAT_DEXTERITY_4 = 787;
        public const int FEAT_EPIC_GREAT_DEXTERITY_5 = 788;
        public const int FEAT_EPIC_GREAT_DEXTERITY_6 = 789;
        public const int FEAT_EPIC_GREAT_DEXTERITY_7 = 790;
        public const int FEAT_EPIC_GREAT_DEXTERITY_8 = 791;
        public const int FEAT_EPIC_GREAT_DEXTERITY_9 = 792;
        public const int FEAT_EPIC_GREAT_DEXTERITY_10 = 793;
        public const int FEAT_EPIC_GREAT_INTELLIGENCE_1 = 794;
        public const int FEAT_EPIC_GREAT_INTELLIGENCE_2 = 795;
        public const int FEAT_EPIC_GREAT_INTELLIGENCE_3 = 796;
        public const int FEAT_EPIC_GREAT_INTELLIGENCE_4 = 797;
        public const int FEAT_EPIC_GREAT_INTELLIGENCE_5 = 798;
        public const int FEAT_EPIC_GREAT_INTELLIGENCE_6 = 799;
        public const int FEAT_EPIC_GREAT_INTELLIGENCE_7 = 800;
        public const int FEAT_EPIC_GREAT_INTELLIGENCE_8 = 801;
        public const int FEAT_EPIC_GREAT_INTELLIGENCE_9 = 802;
        public const int FEAT_EPIC_GREAT_INTELLIGENCE_10 = 803;
        public const int FEAT_EPIC_GREAT_WISDOM_1 = 804;
        public const int FEAT_EPIC_GREAT_WISDOM_2 = 805;
        public const int FEAT_EPIC_GREAT_WISDOM_3 = 806;
        public const int FEAT_EPIC_GREAT_WISDOM_4 = 807;
        public const int FEAT_EPIC_GREAT_WISDOM_5 = 808;
        public const int FEAT_EPIC_GREAT_WISDOM_6 = 809;
        public const int FEAT_EPIC_GREAT_WISDOM_7 = 810;
        public const int FEAT_EPIC_GREAT_WISDOM_8 = 811;
        public const int FEAT_EPIC_GREAT_WISDOM_9 = 812;
        public const int FEAT_EPIC_GREAT_WISDOM_10 = 813;
        public const int FEAT_EPIC_GREAT_STRENGTH_1 = 814;
        public const int FEAT_EPIC_GREAT_STRENGTH_2 = 815;
        public const int FEAT_EPIC_GREAT_STRENGTH_3 = 816;
        public const int FEAT_EPIC_GREAT_STRENGTH_4 = 817;
        public const int FEAT_EPIC_GREAT_STRENGTH_5 = 818;
        public const int FEAT_EPIC_GREAT_STRENGTH_6 = 819;
        public const int FEAT_EPIC_GREAT_STRENGTH_7 = 820;
        public const int FEAT_EPIC_GREAT_STRENGTH_8 = 821;
        public const int FEAT_EPIC_GREAT_STRENGTH_9 = 822;
        public const int FEAT_EPIC_GREAT_STRENGTH_10 = 823;
        public const int FEAT_EPIC_GREAT_SMITING_1 = 824;
        public const int FEAT_EPIC_GREAT_SMITING_2 = 825;
        public const int FEAT_EPIC_GREAT_SMITING_3 = 826;
        public const int FEAT_EPIC_GREAT_SMITING_4 = 827;
        public const int FEAT_EPIC_GREAT_SMITING_5 = 828;
        public const int FEAT_EPIC_GREAT_SMITING_6 = 829;
        public const int FEAT_EPIC_GREAT_SMITING_7 = 830;
        public const int FEAT_EPIC_GREAT_SMITING_8 = 831;
        public const int FEAT_EPIC_GREAT_SMITING_9 = 832;
        public const int FEAT_EPIC_GREAT_SMITING_10 = 833;
        public const int FEAT_EPIC_IMPROVED_SNEAK_ATTACK_1 = 834;
        public const int FEAT_EPIC_IMPROVED_SNEAK_ATTACK_2 = 835;
        public const int FEAT_EPIC_IMPROVED_SNEAK_ATTACK_3 = 836;
        public const int FEAT_EPIC_IMPROVED_SNEAK_ATTACK_4 = 837;
        public const int FEAT_EPIC_IMPROVED_SNEAK_ATTACK_5 = 838;
        public const int FEAT_EPIC_IMPROVED_SNEAK_ATTACK_6 = 839;
        public const int FEAT_EPIC_IMPROVED_SNEAK_ATTACK_7 = 840;
        public const int FEAT_EPIC_IMPROVED_SNEAK_ATTACK_8 = 841;
        public const int FEAT_EPIC_IMPROVED_SNEAK_ATTACK_9 = 842;
        public const int FEAT_EPIC_IMPROVED_SNEAK_ATTACK_10 = 843;
        public const int FEAT_EPIC_IMPROVED_STUNNING_FIST_1 = 844;
        public const int FEAT_EPIC_IMPROVED_STUNNING_FIST_2 = 845;
        public const int FEAT_EPIC_IMPROVED_STUNNING_FIST_3 = 846;
        public const int FEAT_EPIC_IMPROVED_STUNNING_FIST_4 = 847;
        public const int FEAT_EPIC_IMPROVED_STUNNING_FIST_5 = 848;
        public const int FEAT_EPIC_IMPROVED_STUNNING_FIST_6 = 849;
        public const int FEAT_EPIC_IMPROVED_STUNNING_FIST_7 = 850;
        public const int FEAT_EPIC_IMPROVED_STUNNING_FIST_8 = 851;
        public const int FEAT_EPIC_IMPROVED_STUNNING_FIST_9 = 852;
        public const int FEAT_EPIC_IMPROVED_STUNNING_FIST_10 = 853;
        // int FEAT_EPIC_PLANAR_TURNING     =  854;
        public const int FEAT_EPIC_BANE_OF_ENEMIES = 855;
        public const int FEAT_EPIC_DODGE = 856;
        public const int FEAT_EPIC_AUTOMATIC_QUICKEN_1 = 857;
        public const int FEAT_EPIC_AUTOMATIC_QUICKEN_2 = 858;
        public const int FEAT_EPIC_AUTOMATIC_QUICKEN_3 = 859;
        public const int FEAT_EPIC_AUTOMATIC_SILENT_SPELL_1 = 860;
        public const int FEAT_EPIC_AUTOMATIC_SILENT_SPELL_2 = 861;
        public const int FEAT_EPIC_AUTOMATIC_SILENT_SPELL_3 = 862;
        public const int FEAT_EPIC_AUTOMATIC_STILL_SPELL_1 = 863;
        public const int FEAT_EPIC_AUTOMATIC_STILL_SPELL_2 = 864;
        public const int FEAT_EPIC_AUTOMATIC_STILL_SPELL_3 = 865;
        public const int FEAT_SHOU_DISCIPLE_MARTIAL_FLURRY_LIGHT = 866;
        public const int FEAT_WHIRLWIND_ATTACK = 867;
        public const int FEAT_IMPROVED_WHIRLWIND = 868;
        public const int FEAT_MIGHTY_RAGE = 869;
        public const int FEAT_EPIC_LASTING_INSPIRATION = 870;
        public const int FEAT_CURSE_SONG = 871;
        public const int FEAT_EPIC_WILD_SHAPE_UNDEAD = 872;
        public const int FEAT_EPIC_WILD_SHAPE_DRAGON = 873;
        public const int FEAT_EPIC_SPELL_MUMMY_DUST = 874;
        public const int FEAT_EPIC_SPELL_DRAGON_KNIGHT = 875;
        public const int FEAT_EPIC_SPELL_HELLBALL = 876;
        public const int FEAT_EPIC_SPELL_MAGE_ARMOUR = 877;
        public const int FEAT_EPIC_SPELL_RUIN = 878;
        public const int FEAT_WEAPON_OF_CHOICE_SICKLE = 879;
        public const int FEAT_WEAPON_OF_CHOICE_KAMA = 880;
        public const int FEAT_WEAPON_OF_CHOICE_KUKRI = 881;
        public const int FEAT_KI_DAMAGE = 882;
        public const int FEAT_INCREASE_MULTIPLIER = 883;
        public const int FEAT_SUPERIOR_WEAPON_FOCUS = 884;
        public const int FEAT_KI_CRITICAL = 885;
        public const int FEAT_BONE_SKIN_2 = 886;
        public const int FEAT_BONE_SKIN_4 = 887;
        public const int FEAT_BONE_SKIN_6 = 888;
        public const int FEAT_ANIMATE_DEAD = 889;
        public const int FEAT_SUMMON_UNDEAD = 890;
        public const int FEAT_DEATHLESS_VIGOR = 891;
        public const int FEAT_UNDEAD_GRAFT_1 = 892;
        public const int FEAT_UNDEAD_GRAFT_2 = 893;
        public const int FEAT_TOUGH_AS_BONE = 894;
        public const int FEAT_SUMMON_GREATER_UNDEAD = 895;
        public const int FEAT_DEATHLESS_MASTERY = 896;
        public const int FEAT_DEATHLESS_MASTER_TOUCH = 897;
        public const int FEAT_GREATER_WILDSHAPE_1 = 898;
        public const int FEAT_SHOU_DISCIPLE_MARTIAL_FLURRY_ANY = 899;
        public const int FEAT_GREATER_WILDSHAPE_2 = 900;
        public const int FEAT_GREATER_WILDSHAPE_3 = 901;
        public const int FEAT_HUMANOID_SHAPE = 902;
        public const int FEAT_GREATER_WILDSHAPE_4 = 903;
        public const int FEAT_SACRED_DEFENSE_1 = 904;
        public const int FEAT_SACRED_DEFENSE_2 = 905;
        public const int FEAT_SACRED_DEFENSE_3 = 906;
        public const int FEAT_SACRED_DEFENSE_4 = 907;
        public const int FEAT_SACRED_DEFENSE_5 = 908;
        public const int FEAT_DIVINE_WRATH = 909;
        public const int FEAT_EXTRA_SMITING = 910;
        public const int FEAT_SKILL_FOCUS_CRAFT_ARMOR = 911;
        public const int FEAT_SKILL_FOCUS_CRAFT_WEAPON = 912;
        public const int FEAT_EPIC_SKILL_FOCUS_CRAFT_ARMOR = 913;
        public const int FEAT_EPIC_SKILL_FOCUS_CRAFT_WEAPON = 914;
        public const int FEAT_SKILL_FOCUS_BLUFF = 915;
        public const int FEAT_SKILL_FOCUS_INTIMIDATE = 916;
        public const int FEAT_EPIC_SKILL_FOCUS_BLUFF = 917;
        public const int FEAT_EPIC_SKILL_FOCUS_INTIMIDATE = 918;
        public const int FEAT_WEAPON_OF_CHOICE_CLUB = 919;
        public const int FEAT_WEAPON_OF_CHOICE_DAGGER = 920;
        public const int FEAT_WEAPON_OF_CHOICE_LIGHTMACE = 921;
        public const int FEAT_WEAPON_OF_CHOICE_MORNINGSTAR = 922;
        public const int FEAT_WEAPON_OF_CHOICE_QUARTERSTAFF = 923;
        public const int FEAT_WEAPON_OF_CHOICE_SHORTSPEAR = 924;
        public const int FEAT_WEAPON_OF_CHOICE_SHORTSWORD = 925;
        public const int FEAT_WEAPON_OF_CHOICE_RAPIER = 926;
        public const int FEAT_WEAPON_OF_CHOICE_SCIMITAR = 927;
        public const int FEAT_WEAPON_OF_CHOICE_LONGSWORD = 928;
        public const int FEAT_WEAPON_OF_CHOICE_GREATSWORD = 929;
        public const int FEAT_WEAPON_OF_CHOICE_HANDAXE = 930;
        public const int FEAT_WEAPON_OF_CHOICE_BATTLEAXE = 931;
        public const int FEAT_WEAPON_OF_CHOICE_GREATAXE = 932;
        public const int FEAT_WEAPON_OF_CHOICE_HALBERD = 933;
        public const int FEAT_WEAPON_OF_CHOICE_LIGHTHAMMER = 934;
        public const int FEAT_WEAPON_OF_CHOICE_LIGHTFLAIL = 935;
        public const int FEAT_WEAPON_OF_CHOICE_WARHAMMER = 936;
        public const int FEAT_WEAPON_OF_CHOICE_HEAVYFLAIL = 937;
        public const int FEAT_WEAPON_OF_CHOICE_SCYTHE = 938;
        public const int FEAT_WEAPON_OF_CHOICE_KATANA = 939;
        public const int FEAT_WEAPON_OF_CHOICE_BASTARDSWORD = 940;
        public const int FEAT_WEAPON_OF_CHOICE_DIREMACE = 941;
        public const int FEAT_WEAPON_OF_CHOICE_DOUBLEAXE = 942;
        public const int FEAT_WEAPON_OF_CHOICE_TWOBLADEDSWORD = 943;
        public const int FEAT_BREW_POTION = 944;
        public const int FEAT_SCRIBE_SCROLL = 945;
        public const int FEAT_CRAFT_WAND = 946;
        public const int FEAT_DWARVEN_DEFENDER_DEFENSIVE_STANCE = 947;
        public const int FEAT_DAMAGE_REDUCTION_6 = 948;
        public const int FEAT_PRESTIGE_DEFENSIVE_AWARENESS_1 = 949;
        public const int FEAT_PRESTIGE_DEFENSIVE_AWARENESS_2 = 950;
        public const int FEAT_PRESTIGE_DEFENSIVE_AWARENESS_3 = 951;
        public const int FEAT_WEAPON_FOCUS_DWAXE = 952;
        public const int FEAT_WEAPON_SPECIALIZATION_DWAXE = 953;
        public const int FEAT_IMPROVED_CRITICAL_DWAXE = 954;
        public const int FEAT_EPIC_DEVASTATING_CRITICAL_DWAXE = 955;
        public const int FEAT_EPIC_WEAPON_FOCUS_DWAXE = 956;
        public const int FEAT_EPIC_WEAPON_SPECIALIZATION_DWAXE = 957;
        public const int FEAT_EPIC_OVERWHELMING_CRITICAL_DWAXE = 958;
        public const int FEAT_WEAPON_OF_CHOICE_DWAXE = 959;
        public const int FEAT_USE_POISON = 960;
        public const int FEAT_DRAGON_ARMOR = 961;
        public const int FEAT_DRAGON_ABILITIES = 962;
        public const int FEAT_DRAGON_IMMUNE_PARALYSIS = 963;
        public const int FEAT_DRAGON_IMMUNE_FIRE = 964;
        public const int FEAT_DRAGON_DIS_BREATH = 965;
        public const int FEAT_EPIC_FIGHTER = 966;
        public const int FEAT_EPIC_BARBARIAN = 967;
        public const int FEAT_EPIC_BARD = 968;
        public const int FEAT_EPIC_CLERIC = 969;
        public const int FEAT_EPIC_DRUID = 970;
        public const int FEAT_EPIC_MONK = 971;
        public const int FEAT_EPIC_PALADIN = 972;
        public const int FEAT_EPIC_RANGER = 973;
        public const int FEAT_EPIC_ROGUE = 974;
        public const int FEAT_EPIC_SORCERER = 975;
        public const int FEAT_EPIC_WIZARD = 976;
        public const int FEAT_EPIC_ARCANE_ARCHER = 977;
        public const int FEAT_EPIC_ASSASSIN = 978;
        public const int FEAT_EPIC_BLACKGUARD = 979;
        public const int FEAT_EPIC_SHADOWDANCER = 980;
        public const int FEAT_EPIC_HARPER_SCOUT = 981;
        public const int FEAT_EPIC_DIVINE_CHAMPION = 982;
        public const int FEAT_EPIC_WEAPON_MASTER = 983;
        public const int FEAT_EPIC_PALE_MASTER = 984;
        public const int FEAT_EPIC_DWARVEN_DEFENDER = 985;
        public const int FEAT_EPIC_SHIFTER = 986;
        public const int FEAT_EPIC_RED_DRAGON_DISC = 987;
        public const int FEAT_EPIC_THUNDERING_RAGE = 988;
        public const int FEAT_EPIC_TERRIFYING_RAGE = 989;
        public const int FEAT_EPIC_SPELL_EPIC_WARDING = 990;
        public const int FEAT_WEAPON_FOCUS_WHIP = 993;
        public const int FEAT_WEAPON_SPECIALIZATION_WHIP = 994;
        public const int FEAT_IMPROVED_CRITICAL_WHIP = 995;
        public const int FEAT_EPIC_DEVASTATING_CRITICAL_WHIP = 996;
        public const int FEAT_EPIC_WEAPON_FOCUS_WHIP = 997;
        public const int FEAT_EPIC_WEAPON_SPECIALIZATION_WHIP = 998;
        public const int FEAT_EPIC_OVERWHELMING_CRITICAL_WHIP = 999;
        public const int FEAT_WEAPON_OF_CHOICE_WHIP = 1000;
        public const int FEAT_EPIC_CHARACTER = 1001;
        public const int FEAT_EPIC_EPIC_SHADOWLORD = 1002;
        public const int FEAT_EPIC_EPIC_FIEND = 1003;
        public const int FEAT_PRESTIGE_DEATH_ATTACK_6 = 1004;
        public const int FEAT_PRESTIGE_DEATH_ATTACK_7 = 1005;
        public const int FEAT_PRESTIGE_DEATH_ATTACK_8 = 1006;
        public const int FEAT_BLACKGUARD_SNEAK_ATTACK_4D6 = 1007;
        public const int FEAT_BLACKGUARD_SNEAK_ATTACK_5D6 = 1008;
        public const int FEAT_BLACKGUARD_SNEAK_ATTACK_6D6 = 1009;
        public const int FEAT_BLACKGUARD_SNEAK_ATTACK_7D6 = 1010;
        public const int FEAT_BLACKGUARD_SNEAK_ATTACK_8D6 = 1011;
        public const int FEAT_BLACKGUARD_SNEAK_ATTACK_9D6 = 1012;
        public const int FEAT_BLACKGUARD_SNEAK_ATTACK_10D6 = 1013;
        public const int FEAT_BLACKGUARD_SNEAK_ATTACK_11D6 = 1014;
        public const int FEAT_BLACKGUARD_SNEAK_ATTACK_12D6 = 1015;
        public const int FEAT_BLACKGUARD_SNEAK_ATTACK_13D6 = 1016;
        public const int FEAT_BLACKGUARD_SNEAK_ATTACK_14D6 = 1017;
        public const int FEAT_BLACKGUARD_SNEAK_ATTACK_15D6 = 1018;
        public const int FEAT_PRESTIGE_DEATH_ATTACK_9 = 1019;
        public const int FEAT_PRESTIGE_DEATH_ATTACK_10 = 1020;
        public const int FEAT_PRESTIGE_DEATH_ATTACK_11 = 1021;
        public const int FEAT_PRESTIGE_DEATH_ATTACK_12 = 1022;
        public const int FEAT_PRESTIGE_DEATH_ATTACK_13 = 1023;
        public const int FEAT_PRESTIGE_DEATH_ATTACK_14 = 1024;
        public const int FEAT_PRESTIGE_DEATH_ATTACK_15 = 1025;
        public const int FEAT_PRESTIGE_DEATH_ATTACK_16 = 1026;
        public const int FEAT_PRESTIGE_DEATH_ATTACK_17 = 1027;
        public const int FEAT_PRESTIGE_DEATH_ATTACK_18 = 1028;
        public const int FEAT_PRESTIGE_DEATH_ATTACK_19 = 1029;
        public const int FEAT_PRESTIGE_DEATH_ATTACK_20 = 1030;
        public const int FEAT_SHOU_DISCIPLE_DODGE_3 = 1031;
        public const int FEAT_DRAGON_HDINCREASE_D6 = 1042;
        public const int FEAT_DRAGON_HDINCREASE_D8 = 1043;
        public const int FEAT_DRAGON_HDINCREASE_D10 = 1044;
        public const int FEAT_PRESTIGE_ENCHANT_ARROW_6 = 1045;
        public const int FEAT_PRESTIGE_ENCHANT_ARROW_7 = 1046;
        public const int FEAT_PRESTIGE_ENCHANT_ARROW_8 = 1047;
        public const int FEAT_PRESTIGE_ENCHANT_ARROW_9 = 1048;
        public const int FEAT_PRESTIGE_ENCHANT_ARROW_10 = 1049;
        public const int FEAT_PRESTIGE_ENCHANT_ARROW_11 = 1050;
        public const int FEAT_PRESTIGE_ENCHANT_ARROW_12 = 1051;
        public const int FEAT_PRESTIGE_ENCHANT_ARROW_13 = 1052;
        public const int FEAT_PRESTIGE_ENCHANT_ARROW_14 = 1053;
        public const int FEAT_PRESTIGE_ENCHANT_ARROW_15 = 1054;
        public const int FEAT_PRESTIGE_ENCHANT_ARROW_16 = 1055;
        public const int FEAT_PRESTIGE_ENCHANT_ARROW_17 = 1056;
        public const int FEAT_PRESTIGE_ENCHANT_ARROW_18 = 1057;
        public const int FEAT_PRESTIGE_ENCHANT_ARROW_19 = 1058;
        public const int FEAT_PRESTIGE_ENCHANT_ARROW_20 = 1059;
        public const int FEAT_EPIC_OUTSIDER_SHAPE = 1060;
        public const int FEAT_EPIC_CONSTRUCT_SHAPE = 1061;
        public const int FEAT_EPIC_SHIFTER_INFINITE_WILDSHAPE_1 = 1062;
        public const int FEAT_EPIC_SHIFTER_INFINITE_WILDSHAPE_2 = 1063;
        public const int FEAT_EPIC_SHIFTER_INFINITE_WILDSHAPE_3 = 1064;
        public const int FEAT_EPIC_SHIFTER_INFINITE_WILDSHAPE_4 = 1065;
        public const int FEAT_EPIC_SHIFTER_INFINITE_HUMANOID_SHAPE = 1066;
        public const int FEAT_EPIC_BARBARIAN_DAMAGE_REDUCTION = 1067;
        public const int FEAT_EPIC_DRUID_INFINITE_WILDSHAPE = 1068;
        public const int FEAT_EPIC_DRUID_INFINITE_ELEMENTAL_SHAPE = 1069;
        public const int FEAT_PRESTIGE_POISON_SAVE_EPIC = 1070;
        public const int FEAT_EPIC_SUPERIOR_WEAPON_FOCUS = 1071;
        public const int FEAT_WEAPON_FOCUS_TRIDENT = 1072;
        public const int FEAT_WEAPON_SPECIALIZATION_TRIDENT = 1073;
        public const int FEAT_IMPROVED_CRITICAL_TRIDENT = 1074;
        public const int FEAT_EPIC_DEVASTATING_CRITICAL_TRIDENT = 1075;
        public const int FEAT_EPIC_WEAPON_FOCUS_TRIDENT = 1076;
        public const int FEAT_EPIC_WEAPON_SPECIALIZATION_TRIDENT = 1077;
        public const int FEAT_EPIC_OVERWHELMING_CRITICAL_TRIDENT = 1078;
        public const int FEAT_WEAPON_OF_CHOICE_TRIDENT = 1079;
        public const int FEAT_PDK_RALLY = 1080;
        public const int FEAT_PDK_SHIELD = 1081;
        public const int FEAT_PDK_FEAR = 1082;
        public const int FEAT_PDK_WRATH = 1083;
        public const int FEAT_PDK_STAND = 1084;
        public const int FEAT_PDK_INSPIRE_1 = 1085;
        public const int FEAT_PDK_INSPIRE_2 = 1086;
        public const int FEAT_MOUNTED_COMBAT = 1087;
        public const int FEAT_MOUNTED_ARCHERY = 1088;
        public const int FEAT_HORSE_MENU = 1089;
        public const int FEAT_HORSE_MOUNT = 1090;
        public const int FEAT_HORSE_DISMOUNT = 1091;
        public const int FEAT_HORSE_PARTY_MOUNT = 1092;
        public const int FEAT_HORSE_PARTY_DISMOUNT = 1093;
        public const int FEAT_HORSE_ASSIGN_MOUNT = 1094;
        public const int FEAT_PALADIN_SUMMON_MOUNT = 1095;
        public const int FEAT_PLAYER_TOOL_01 = 1106;
        public const int FEAT_PLAYER_TOOL_02 = 1107;
        public const int FEAT_PLAYER_TOOL_03 = 1108;
        public const int FEAT_PLAYER_TOOL_04 = 1109;
        public const int FEAT_PLAYER_TOOL_05 = 1110;
        public const int FEAT_PLAYER_TOOL_06 = 1111;
        public const int FEAT_PLAYER_TOOL_07 = 1112;
        public const int FEAT_PLAYER_TOOL_08 = 1113;
        public const int FEAT_PLAYER_TOOL_09 = 1114;
        public const int FEAT_PLAYER_TOOL_10 = 1115;
        //  Special Attack Defines
        public const int SPECIAL_ATTACK_INVALID = 0;
        public const int SPECIAL_ATTACK_CALLED_SHOT_LEG = 1;
        public const int SPECIAL_ATTACK_CALLED_SHOT_ARM = 2;
        public const int SPECIAL_ATTACK_SAP = 3;
        public const int SPECIAL_ATTACK_DISARM = 4;
        public const int SPECIAL_ATTACK_IMPROVED_DISARM = 5;
        public const int SPECIAL_ATTACK_KNOCKDOWN = 6;
        public const int SPECIAL_ATTACK_IMPROVED_KNOCKDOWN = 7;
        public const int SPECIAL_ATTACK_STUNNING_FIST = 8;
        public const int SPECIAL_ATTACK_FLURRY_OF_BLOWS = 9;
        public const int SPECIAL_ATTACK_RAPID_SHOT = 10;
        //  Combat Mode Defines
        public const int COMBAT_MODE_INVALID = 0;
        public const int COMBAT_MODE_PARRY = 1;
        public const int COMBAT_MODE_POWER_ATTACK = 2;
        public const int COMBAT_MODE_IMPROVED_POWER_ATTACK = 3;
        public const int COMBAT_MODE_FLURRY_OF_BLOWS = 4;
        public const int COMBAT_MODE_RAPID_SHOT = 5;
        public const int COMBAT_MODE_EXPERTISE = 6;
        public const int COMBAT_MODE_IMPROVED_EXPERTISE = 7;
        public const int COMBAT_MODE_DEFENSIVE_CASTING = 8;
        public const int COMBAT_MODE_DIRTY_FIGHTING = 9;
        public const int COMBAT_MODE_DEFENSIVE_STANCE = 10;
        //  These represent the row in the difficulty 2da, rather than
        //  a difficulty value.
        public const int ENCOUNTER_DIFFICULTY_VERY_EASY = 0;
        public const int ENCOUNTER_DIFFICULTY_EASY = 1;
        public const int ENCOUNTER_DIFFICULTY_NORMAL = 2;
        public const int ENCOUNTER_DIFFICULTY_HARD = 3;
        public const int ENCOUNTER_DIFFICULTY_IMPOSSIBLE = 4;
        //  Looping animation constants.
        public const int ANIMATION_LOOPING_PAUSE = 0;
        public const int ANIMATION_LOOPING_PAUSE2 = 1;
        public const int ANIMATION_LOOPING_LISTEN = 2;
        public const int ANIMATION_LOOPING_MEDITATE = 3;
        public const int ANIMATION_LOOPING_WORSHIP = 4;
        public const int ANIMATION_LOOPING_LOOK_FAR = 5;
        public const int ANIMATION_LOOPING_SIT_CHAIR = 6;
        public const int ANIMATION_LOOPING_SIT_CROSS = 7;
        public const int ANIMATION_LOOPING_TALK_NORMAL = 8;
        public const int ANIMATION_LOOPING_TALK_PLEADING = 9;
        public const int ANIMATION_LOOPING_TALK_FORCEFUL = 10;
        public const int ANIMATION_LOOPING_TALK_LAUGHING = 11;
        public const int ANIMATION_LOOPING_GET_LOW = 12;
        public const int ANIMATION_LOOPING_GET_MID = 13;
        public const int ANIMATION_LOOPING_PAUSE_TIRED = 14;
        public const int ANIMATION_LOOPING_PAUSE_DRUNK = 15;
        public const int ANIMATION_LOOPING_DEAD_FRONT = 16;
        public const int ANIMATION_LOOPING_DEAD_BACK = 17;
        public const int ANIMATION_LOOPING_CONJURE1 = 18;
        public const int ANIMATION_LOOPING_CONJURE2 = 19;
        public const int ANIMATION_LOOPING_SPASM = 20;
        public const int ANIMATION_LOOPING_CUSTOM1 = 21;
        public const int ANIMATION_LOOPING_CUSTOM2 = 22;
        public const int ANIMATION_LOOPING_CUSTOM3 = 23;
        public const int ANIMATION_LOOPING_CUSTOM4 = 24;
        public const int ANIMATION_LOOPING_CUSTOM5 = 25;
        public const int ANIMATION_LOOPING_CUSTOM6 = 26;
        public const int ANIMATION_LOOPING_CUSTOM7 = 27;
        public const int ANIMATION_LOOPING_CUSTOM8 = 28;
        public const int ANIMATION_LOOPING_CUSTOM9 = 29;
        public const int ANIMATION_LOOPING_CUSTOM10 = 30;
        public const int ANIMATION_LOOPING_CUSTOM11 = 31;
        public const int ANIMATION_LOOPING_CUSTOM12 = 32;
        public const int ANIMATION_LOOPING_CUSTOM13 = 33;
        public const int ANIMATION_LOOPING_CUSTOM14 = 34;
        public const int ANIMATION_LOOPING_CUSTOM15 = 35;
        public const int ANIMATION_LOOPING_CUSTOM16 = 36;
        public const int ANIMATION_LOOPING_CUSTOM17 = 37;
        public const int ANIMATION_LOOPING_CUSTOM18 = 38;
        public const int ANIMATION_LOOPING_CUSTOM19 = 39;
        public const int ANIMATION_LOOPING_CUSTOM20 = 40;
        public const int ANIMATION_MOUNT1 = 41;
        public const int ANIMATION_DISMOUNT1 = 42;
        //  Fire and forget animation constants.
        public const int ANIMATION_FIREFORGET_HEAD_TURN_LEFT = 100;
        public const int ANIMATION_FIREFORGET_HEAD_TURN_RIGHT = 101;
        public const int ANIMATION_FIREFORGET_PAUSE_SCRATCH_HEAD = 102;
        public const int ANIMATION_FIREFORGET_PAUSE_BORED = 103;
        public const int ANIMATION_FIREFORGET_SALUTE = 104;
        public const int ANIMATION_FIREFORGET_BOW = 105;
        public const int ANIMATION_FIREFORGET_STEAL = 106;
        public const int ANIMATION_FIREFORGET_GREETING = 107;
        public const int ANIMATION_FIREFORGET_TAUNT = 108;
        public const int ANIMATION_FIREFORGET_VICTORY1 = 109;
        public const int ANIMATION_FIREFORGET_VICTORY2 = 110;
        public const int ANIMATION_FIREFORGET_VICTORY3 = 111;
        public const int ANIMATION_FIREFORGET_READ = 112;
        public const int ANIMATION_FIREFORGET_DRINK = 113;
        public const int ANIMATION_FIREFORGET_DODGE_SIDE = 114;
        public const int ANIMATION_FIREFORGET_DODGE_DUCK = 115;
        public const int ANIMATION_FIREFORGET_SPASM = 116;
        //  Placeable animation constants
        public const int ANIMATION_PLACEABLE_ACTIVATE = 200;
        public const int ANIMATION_PLACEABLE_DEACTIVATE = 201;
        public const int ANIMATION_PLACEABLE_OPEN = 202;
        public const int ANIMATION_PLACEABLE_CLOSE = 203;
        //  Door animation constants
        public const int ANIMATION_DOOR_CLOSE = 204;
        public const int ANIMATION_DOOR_OPEN1 = 205;
        public const int ANIMATION_DOOR_OPEN2 = 206;
        public const int ANIMATION_DOOR_DESTROY = 207;
        public const int TALENT_TYPE_SPELL = 0;
        public const int TALENT_TYPE_FEAT = 1;
        public const int TALENT_TYPE_SKILL = 2;
        //  These must match the values in nwscreature.h and nwccreaturemenu.cpp
        //  Cannot use the value -1 because that is used to start a conversation
        public const int ASSOCIATE_COMMAND_STANDGROUND = -2;
        public const int ASSOCIATE_COMMAND_ATTACKNEAREST = -3;
        public const int ASSOCIATE_COMMAND_HEALMASTER = -4;
        public const int ASSOCIATE_COMMAND_FOLLOWMASTER = -5;
        public const int ASSOCIATE_COMMAND_MASTERFAILEDLOCKPICK = -6;
        public const int ASSOCIATE_COMMAND_GUARDMASTER = -7;
        public const int ASSOCIATE_COMMAND_UNSUMMONFAMILIAR = -8;
        public const int ASSOCIATE_COMMAND_UNSUMMONANIMALCOMPANION = -9;
        public const int ASSOCIATE_COMMAND_UNSUMMONSUMMONED = -10;
        public const int ASSOCIATE_COMMAND_MASTERUNDERATTACK = -11;
        public const int ASSOCIATE_COMMAND_RELEASEDOMINATION = -12;
        public const int ASSOCIATE_COMMAND_UNPOSSESSFAMILIAR = -13;
        public const int ASSOCIATE_COMMAND_MASTERSAWTRAP = -14;
        public const int ASSOCIATE_COMMAND_MASTERATTACKEDOTHER = -15;
        public const int ASSOCIATE_COMMAND_MASTERGOINGTOBEATTACKED = -16;
        public const int ASSOCIATE_COMMAND_LEAVEPARTY = -17;
        public const int ASSOCIATE_COMMAND_PICKLOCK = -18;
        public const int ASSOCIATE_COMMAND_INVENTORY = -19;
        public const int ASSOCIATE_COMMAND_DISARMTRAP = -20;
        public const int ASSOCIATE_COMMAND_TOGGLECASTING = -21;
        public const int ASSOCIATE_COMMAND_TOGGLESTEALTH = -22;
        public const int ASSOCIATE_COMMAND_TOGGLESEARCH = -23;
        //  These match the values in nwscreature.h
        public const int ASSOCIATE_TYPE_NONE = 0;
        public const int ASSOCIATE_TYPE_HENCHMAN = 1;
        public const int ASSOCIATE_TYPE_ANIMALCOMPANION = 2;
        public const int ASSOCIATE_TYPE_FAMILIAR = 3;
        public const int ASSOCIATE_TYPE_SUMMONED = 4;
        public const int ASSOCIATE_TYPE_DOMINATED = 5;
        //  These must match the list in nwscreaturestats.cpp
        public const int TALENT_CATEGORY_HARMFUL_AREAEFFECT_DISCRIMINANT = 1;
        public const int TALENT_CATEGORY_HARMFUL_RANGED = 2;
        public const int TALENT_CATEGORY_HARMFUL_TOUCH = 3;
        public const int TALENT_CATEGORY_BENEFICIAL_HEALING_AREAEFFECT = 4;
        public const int TALENT_CATEGORY_BENEFICIAL_HEALING_TOUCH = 5;
        public const int TALENT_CATEGORY_BENEFICIAL_CONDITIONAL_AREAEFFECT = 6;
        public const int TALENT_CATEGORY_BENEFICIAL_CONDITIONAL_SINGLE = 7;
        public const int TALENT_CATEGORY_BENEFICIAL_ENHANCEMENT_AREAEFFECT = 8;
        public const int TALENT_CATEGORY_BENEFICIAL_ENHANCEMENT_SINGLE = 9;
        public const int TALENT_CATEGORY_BENEFICIAL_ENHANCEMENT_SELF = 10;
        public const int TALENT_CATEGORY_HARMFUL_AREAEFFECT_INDISCRIMINANT = 11;
        public const int TALENT_CATEGORY_BENEFICIAL_PROTECTION_SELF = 12;
        public const int TALENT_CATEGORY_BENEFICIAL_PROTECTION_SINGLE = 13;
        public const int TALENT_CATEGORY_BENEFICIAL_PROTECTION_AREAEFFECT = 14;
        public const int TALENT_CATEGORY_BENEFICIAL_OBTAIN_ALLIES = 15;
        public const int TALENT_CATEGORY_PERSISTENT_AREA_OF_EFFECT = 16;
        public const int TALENT_CATEGORY_BENEFICIAL_HEALING_POTION = 17;
        public const int TALENT_CATEGORY_BENEFICIAL_CONDITIONAL_POTION = 18;
        public const int TALENT_CATEGORY_DRAGONS_BREATH = 19;
        public const int TALENT_CATEGORY_BENEFICIAL_PROTECTION_POTION = 20;
        public const int TALENT_CATEGORY_BENEFICIAL_ENHANCEMENT_POTION = 21;
        public const int TALENT_CATEGORY_HARMFUL_MELEE = 22;
        public const int INVENTORY_DISTURB_TYPE_ADDED = 0;
        public const int INVENTORY_DISTURB_TYPE_REMOVED = 1;
        public const int INVENTORY_DISTURB_TYPE_STOLEN = 2;
        public const int GUI_PANEL_PLAYER_DEATH = 0;
        public const int VOICE_CHAT_ATTACK = 0;
        public const int VOICE_CHAT_BATTLECRY1 = 1;
        public const int VOICE_CHAT_BATTLECRY2 = 2;
        public const int VOICE_CHAT_BATTLECRY3 = 3;
        public const int VOICE_CHAT_HEALME = 4;
        public const int VOICE_CHAT_HELP = 5;
        public const int VOICE_CHAT_ENEMIES = 6;
        public const int VOICE_CHAT_FLEE = 7;
        public const int VOICE_CHAT_TAUNT = 8;
        public const int VOICE_CHAT_GUARDME = 9;
        public const int VOICE_CHAT_HOLD = 10;
        public const int VOICE_CHAT_GATTACK1 = 11;
        public const int VOICE_CHAT_GATTACK2 = 12;
        public const int VOICE_CHAT_GATTACK3 = 13;
        public const int VOICE_CHAT_PAIN1 = 14;
        public const int VOICE_CHAT_PAIN2 = 15;
        public const int VOICE_CHAT_PAIN3 = 16;
        public const int VOICE_CHAT_NEARDEATH = 17;
        public const int VOICE_CHAT_DEATH = 18;
        public const int VOICE_CHAT_POISONED = 19;
        public const int VOICE_CHAT_SPELLFAILED = 20;
        public const int VOICE_CHAT_WEAPONSUCKS = 21;
        public const int VOICE_CHAT_FOLLOWME = 22;
        public const int VOICE_CHAT_LOOKHERE = 23;
        public const int VOICE_CHAT_GROUP = 24;
        public const int VOICE_CHAT_MOVEOVER = 25;
        public const int VOICE_CHAT_PICKLOCK = 26;
        public const int VOICE_CHAT_SEARCH = 27;
        public const int VOICE_CHAT_HIDE = 28;
        public const int VOICE_CHAT_CANDO = 29;
        public const int VOICE_CHAT_CANTDO = 30;
        public const int VOICE_CHAT_TASKCOMPLETE = 31;
        public const int VOICE_CHAT_ENCUMBERED = 32;
        public const int VOICE_CHAT_SELECTED = 33;
        public const int VOICE_CHAT_HELLO = 34;
        public const int VOICE_CHAT_YES = 35;
        public const int VOICE_CHAT_NO = 36;
        public const int VOICE_CHAT_STOP = 37;
        public const int VOICE_CHAT_REST = 38;
        public const int VOICE_CHAT_BORED = 39;
        public const int VOICE_CHAT_GOODBYE = 40;
        public const int VOICE_CHAT_THANKS = 41;
        public const int VOICE_CHAT_LAUGH = 42;
        public const int VOICE_CHAT_CUSS = 43;
        public const int VOICE_CHAT_CHEER = 44;
        public const int VOICE_CHAT_TALKTOME = 45;
        public const int VOICE_CHAT_GOODIDEA = 46;
        public const int VOICE_CHAT_BADIDEA = 47;
        public const int VOICE_CHAT_THREATEN = 48;
        public const int POLYMORPH_TYPE_WEREWOLF = 0;
        public const int POLYMORPH_TYPE_WERERAT = 1;
        public const int POLYMORPH_TYPE_WERECAT = 2;
        public const int POLYMORPH_TYPE_GIANT_SPIDER = 3;
        public const int POLYMORPH_TYPE_TROLL = 4;
        public const int POLYMORPH_TYPE_UMBER_HULK = 5;
        public const int POLYMORPH_TYPE_PIXIE = 6;
        public const int POLYMORPH_TYPE_ZOMBIE = 7;
        public const int POLYMORPH_TYPE_RED_DRAGON = 8;
        public const int POLYMORPH_TYPE_FIRE_GIANT = 9;
        public const int POLYMORPH_TYPE_BALOR = 10;
        public const int POLYMORPH_TYPE_DEATH_SLAAD = 11;
        public const int POLYMORPH_TYPE_IRON_GOLEM = 12;
        public const int POLYMORPH_TYPE_HUGE_FIRE_ELEMENTAL = 13;
        public const int POLYMORPH_TYPE_HUGE_WATER_ELEMENTAL = 14;
        public const int POLYMORPH_TYPE_HUGE_EARTH_ELEMENTAL = 15;
        public const int POLYMORPH_TYPE_HUGE_AIR_ELEMENTAL = 16;
        public const int POLYMORPH_TYPE_ELDER_FIRE_ELEMENTAL = 17;
        public const int POLYMORPH_TYPE_ELDER_WATER_ELEMENTAL = 18;
        public const int POLYMORPH_TYPE_ELDER_EARTH_ELEMENTAL = 19;
        public const int POLYMORPH_TYPE_ELDER_AIR_ELEMENTAL = 20;
        public const int POLYMORPH_TYPE_BROWN_BEAR = 21;
        public const int POLYMORPH_TYPE_PANTHER = 22;
        public const int POLYMORPH_TYPE_WOLF = 23;
        public const int POLYMORPH_TYPE_BOAR = 24;
        public const int POLYMORPH_TYPE_BADGER = 25;
        public const int POLYMORPH_TYPE_PENGUIN = 26;
        public const int POLYMORPH_TYPE_COW = 27;
        public const int POLYMORPH_TYPE_DOOM_KNIGHT = 28;
        public const int POLYMORPH_TYPE_YUANTI = 29;
        public const int POLYMORPH_TYPE_IMP = 30;
        public const int POLYMORPH_TYPE_QUASIT = 31;
        public const int POLYMORPH_TYPE_SUCCUBUS = 32;
        public const int POLYMORPH_TYPE_DIRE_BROWN_BEAR = 33;
        public const int POLYMORPH_TYPE_DIRE_PANTHER = 34;
        public const int POLYMORPH_TYPE_DIRE_WOLF = 35;
        public const int POLYMORPH_TYPE_DIRE_BOAR = 36;
        public const int POLYMORPH_TYPE_DIRE_BADGER = 37;
        public const int POLYMORPH_TYPE_CELESTIAL_AVENGER = 38;
        public const int POLYMORPH_TYPE_VROCK = 39;
        public const int POLYMORPH_TYPE_CHICKEN = 40;
        public const int POLYMORPH_TYPE_FROST_GIANT_MALE = 41;
        public const int POLYMORPH_TYPE_FROST_GIANT_FEMALE = 42;
        public const int POLYMORPH_TYPE_HEURODIS = 43;
        public const int POLYMORPH_TYPE_JNAH_GIANT_MALE = 44;
        public const int POLYMORPH_TYPE_JNAH_GIANT_FEMAL = 45;
        public const int POLYMORPH_TYPE_WYRMLING_WHITE = 52;
        public const int POLYMORPH_TYPE_WYRMLING_BLUE = 53;
        public const int POLYMORPH_TYPE_WYRMLING_RED = 54;
        public const int POLYMORPH_TYPE_WYRMLING_GREEN = 55;
        public const int POLYMORPH_TYPE_WYRMLING_BLACK = 56;
        public const int POLYMORPH_TYPE_GOLEM_AUTOMATON = 57;
        public const int POLYMORPH_TYPE_MANTICORE = 58;
        public const int POLYMORPH_TYPE_MALE_DROW = 59;
        public const int POLYMORPH_TYPE_HARPY = 60;
        public const int POLYMORPH_TYPE_BASILISK = 61;
        public const int POLYMORPH_TYPE_DRIDER = 62;
        public const int POLYMORPH_TYPE_BEHOLDER = 63;
        public const int POLYMORPH_TYPE_MEDUSA = 64;
        public const int POLYMORPH_TYPE_GARGOYLE = 65;
        public const int POLYMORPH_TYPE_MINOTAUR = 66;
        public const int POLYMORPH_TYPE_SUPER_CHICKEN = 67;
        public const int POLYMORPH_TYPE_MINDFLAYER = 68;
        public const int POLYMORPH_TYPE_DIRETIGER = 69;
        public const int POLYMORPH_TYPE_FEMALE_DROW = 70;
        public const int POLYMORPH_TYPE_ANCIENT_BLUE_DRAGON = 71;
        public const int POLYMORPH_TYPE_ANCIENT_RED_DRAGON = 72;
        public const int POLYMORPH_TYPE_ANCIENT_GREEN_DRAGON = 73;
        public const int POLYMORPH_TYPE_VAMPIRE_MALE = 74;
        public const int POLYMORPH_TYPE_RISEN_LORD = 75;
        public const int POLYMORPH_TYPE_SPECTRE = 76;
        public const int POLYMORPH_TYPE_VAMPIRE_FEMALE = 77;
        public const int POLYMORPH_TYPE_NULL_HUMAN = 78;
        public const int INVISIBILITY_TYPE_NORMAL = 1;
        public const int INVISIBILITY_TYPE_DARKNESS = 2;
        public const int INVISIBILITY_TYPE_IMPROVED = 4;
        public const int CREATURE_SIZE_INVALID = 0;
        public const int CREATURE_SIZE_TINY = 1;
        public const int CREATURE_SIZE_SMALL = 2;
        public const int CREATURE_SIZE_MEDIUM = 3;
        public const int CREATURE_SIZE_LARGE = 4;
        public const int CREATURE_SIZE_HUGE = 5;
        public const int SPELL_SCHOOL_GENERAL = 0;
        public const int SPELL_SCHOOL_ABJURATION = 1;
        public const int SPELL_SCHOOL_CONJURATION = 2;
        public const int SPELL_SCHOOL_DIVINATION = 3;
        public const int SPELL_SCHOOL_ENCHANTMENT = 4;
        public const int SPELL_SCHOOL_EVOCATION = 5;
        public const int SPELL_SCHOOL_ILLUSION = 6;
        public const int SPELL_SCHOOL_NECROMANCY = 7;
        public const int SPELL_SCHOOL_TRANSMUTATION = 8;
        public const int ANIMAL_COMPANION_CREATURE_TYPE_BADGER = 0;
        public const int ANIMAL_COMPANION_CREATURE_TYPE_WOLF = 1;
        public const int ANIMAL_COMPANION_CREATURE_TYPE_BEAR = 2;
        public const int ANIMAL_COMPANION_CREATURE_TYPE_BOAR = 3;
        public const int ANIMAL_COMPANION_CREATURE_TYPE_HAWK = 4;
        public const int ANIMAL_COMPANION_CREATURE_TYPE_PANTHER = 5;
        public const int ANIMAL_COMPANION_CREATURE_TYPE_SPIDER = 6;
        public const int ANIMAL_COMPANION_CREATURE_TYPE_DIREWOLF = 7;
        public const int ANIMAL_COMPANION_CREATURE_TYPE_DIRERAT = 8;
        public const int ANIMAL_COMPANION_CREATURE_TYPE_NONE = 255;
        public const int FAMILIAR_CREATURE_TYPE_BAT = 0;
        public const int FAMILIAR_CREATURE_TYPE_CRAGCAT = 1;
        public const int FAMILIAR_CREATURE_TYPE_HELLHOUND = 2;
        public const int FAMILIAR_CREATURE_TYPE_IMP = 3;
        public const int FAMILIAR_CREATURE_TYPE_FIREMEPHIT = 4;
        public const int FAMILIAR_CREATURE_TYPE_ICEMEPHIT = 5;
        public const int FAMILIAR_CREATURE_TYPE_PIXIE = 6;
        public const int FAMILIAR_CREATURE_TYPE_RAVEN = 7;
        public const int FAMILIAR_CREATURE_TYPE_FAIRY_DRAGON = 8;
        public const int FAMILIAR_CREATURE_TYPE_PSEUDO_DRAGON = 9;
        public const int FAMILIAR_CREATURE_TYPE_EYEBALL = 10;
        public const int FAMILIAR_CREATURE_TYPE_NONE = 255;
        public const int CAMERA_MODE_CHASE_CAMERA = 0;
        public const int CAMERA_MODE_TOP_DOWN = 1;
        public const int CAMERA_MODE_STIFF_CHASE_CAMERA = 2;
        public const int WEATHER_INVALID = -1;
        public const int WEATHER_CLEAR = 0;
        public const int WEATHER_RAIN = 1;
        public const int WEATHER_SNOW = 2;
        public const int WEATHER_USE_AREA_SETTINGS = -1;
        public const int REST_EVENTTYPE_REST_INVALID = 0;
        public const int REST_EVENTTYPE_REST_STARTED = 1;
        public const int REST_EVENTTYPE_REST_FINISHED = 2;
        public const int REST_EVENTTYPE_REST_CANCELLED = 3;
        public const int PROJECTILE_PATH_TYPE_DEFAULT = 0;
        public const int PROJECTILE_PATH_TYPE_HOMING = 1;
        public const int PROJECTILE_PATH_TYPE_BALLISTIC = 2;
        public const int PROJECTILE_PATH_TYPE_HIGH_BALLISTIC = 3;
        public const int PROJECTILE_PATH_TYPE_ACCELERATING = 4;
        public const int GAME_DIFFICULTY_VERY_EASY = 0;
        public const int GAME_DIFFICULTY_EASY = 1;
        public const int GAME_DIFFICULTY_NORMAL = 2;
        public const int GAME_DIFFICULTY_CORE_RULES = 3;
        public const int GAME_DIFFICULTY_DIFFICULT = 4;
        public const int TILE_MAIN_LIGHT_COLOR_BLACK = 0;
        public const int TILE_MAIN_LIGHT_COLOR_DIM_WHITE = 1;
        public const int TILE_MAIN_LIGHT_COLOR_WHITE = 2;
        public const int TILE_MAIN_LIGHT_COLOR_BRIGHT_WHITE = 3;
        public const int TILE_MAIN_LIGHT_COLOR_PALE_DARK_YELLOW = 4;
        public const int TILE_MAIN_LIGHT_COLOR_DARK_YELLOW = 5;
        public const int TILE_MAIN_LIGHT_COLOR_PALE_YELLOW = 6;
        public const int TILE_MAIN_LIGHT_COLOR_YELLOW = 7;
        public const int TILE_MAIN_LIGHT_COLOR_PALE_DARK_GREEN = 8;
        public const int TILE_MAIN_LIGHT_COLOR_DARK_GREEN = 9;
        public const int TILE_MAIN_LIGHT_COLOR_PALE_GREEN = 10;
        public const int TILE_MAIN_LIGHT_COLOR_GREEN = 11;
        public const int TILE_MAIN_LIGHT_COLOR_PALE_DARK_AQUA = 12;
        public const int TILE_MAIN_LIGHT_COLOR_DARK_AQUA = 13;
        public const int TILE_MAIN_LIGHT_COLOR_PALE_AQUA = 14;
        public const int TILE_MAIN_LIGHT_COLOR_AQUA = 15;
        public const int TILE_MAIN_LIGHT_COLOR_PALE_DARK_BLUE = 16;
        public const int TILE_MAIN_LIGHT_COLOR_DARK_BLUE = 17;
        public const int TILE_MAIN_LIGHT_COLOR_PALE_BLUE = 18;
        public const int TILE_MAIN_LIGHT_COLOR_BLUE = 19;
        public const int TILE_MAIN_LIGHT_COLOR_PALE_DARK_PURPLE = 20;
        public const int TILE_MAIN_LIGHT_COLOR_DARK_PURPLE = 21;
        public const int TILE_MAIN_LIGHT_COLOR_PALE_PURPLE = 22;
        public const int TILE_MAIN_LIGHT_COLOR_PURPLE = 23;
        public const int TILE_MAIN_LIGHT_COLOR_PALE_DARK_RED = 24;
        public const int TILE_MAIN_LIGHT_COLOR_DARK_RED = 25;
        public const int TILE_MAIN_LIGHT_COLOR_PALE_RED = 26;
        public const int TILE_MAIN_LIGHT_COLOR_RED = 27;
        public const int TILE_MAIN_LIGHT_COLOR_PALE_DARK_ORANGE = 28;
        public const int TILE_MAIN_LIGHT_COLOR_DARK_ORANGE = 29;
        public const int TILE_MAIN_LIGHT_COLOR_PALE_ORANGE = 30;
        public const int TILE_MAIN_LIGHT_COLOR_ORANGE = 31;
        public const int TILE_SOURCE_LIGHT_COLOR_BLACK = 0;
        public const int TILE_SOURCE_LIGHT_COLOR_WHITE = 1;
        public const int TILE_SOURCE_LIGHT_COLOR_PALE_DARK_YELLOW = 2;
        public const int TILE_SOURCE_LIGHT_COLOR_PALE_YELLOW = 3;
        public const int TILE_SOURCE_LIGHT_COLOR_PALE_DARK_GREEN = 4;
        public const int TILE_SOURCE_LIGHT_COLOR_PALE_GREEN = 5;
        public const int TILE_SOURCE_LIGHT_COLOR_PALE_DARK_AQUA = 6;
        public const int TILE_SOURCE_LIGHT_COLOR_PALE_AQUA = 7;
        public const int TILE_SOURCE_LIGHT_COLOR_PALE_DARK_BLUE = 8;
        public const int TILE_SOURCE_LIGHT_COLOR_PALE_BLUE = 9;
        public const int TILE_SOURCE_LIGHT_COLOR_PALE_DARK_PURPLE = 10;
        public const int TILE_SOURCE_LIGHT_COLOR_PALE_PURPLE = 11;
        public const int TILE_SOURCE_LIGHT_COLOR_PALE_DARK_RED = 12;
        public const int TILE_SOURCE_LIGHT_COLOR_PALE_RED = 13;
        public const int TILE_SOURCE_LIGHT_COLOR_PALE_DARK_ORANGE = 14;
        public const int TILE_SOURCE_LIGHT_COLOR_PALE_ORANGE = 15;
        public const int PANEL_BUTTON_MAP = 0;
        public const int PANEL_BUTTON_INVENTORY = 1;
        public const int PANEL_BUTTON_JOURNAL = 2;
        public const int PANEL_BUTTON_CHARACTER = 3;
        public const int PANEL_BUTTON_OPTIONS = 4;
        public const int PANEL_BUTTON_SPELLS = 5;
        public const int PANEL_BUTTON_REST = 6;
        public const int PANEL_BUTTON_PLAYER_VERSUS_PLAYER = 7;
        public const int ACTION_MOVETOPOINT = 0;
        public const int ACTION_PICKUPITEM = 1;
        public const int ACTION_DROPITEM = 2;
        public const int ACTION_ATTACKOBJECT = 3;
        public const int ACTION_CASTSPELL = 4;
        public const int ACTION_OPENDOOR = 5;
        public const int ACTION_CLOSEDOOR = 6;
        public const int ACTION_DIALOGOBJECT = 7;
        public const int ACTION_DISABLETRAP = 8;
        public const int ACTION_RECOVERTRAP = 9;
        public const int ACTION_FLAGTRAP = 10;
        public const int ACTION_EXAMINETRAP = 11;
        public const int ACTION_SETTRAP = 12;
        public const int ACTION_OPENLOCK = 13;
        public const int ACTION_LOCK = 14;
        public const int ACTION_USEOBJECT = 15;
        public const int ACTION_ANIMALEMPATHY = 16;
        public const int ACTION_REST = 17;
        public const int ACTION_TAUNT = 18;
        public const int ACTION_ITEMCASTSPELL = 19;
        public const int ACTION_COUNTERSPELL = 31;
        public const int ACTION_HEAL = 33;
        public const int ACTION_PICKPOCKET = 34;
        public const int ACTION_FOLLOW = 35;
        public const int ACTION_WAIT = 36;
        public const int ACTION_SIT = 37;
        public const int ACTION_SMITEGOOD = 40;
        public const int ACTION_KIDAMAGE = 41;
        public const int ACTION_RANDOMWALK = 43;
        public const int ACTION_INVALID = 65535;
        public const int TRAP_BASE_TYPE_MINOR_SPIKE = 0;
        public const int TRAP_BASE_TYPE_AVERAGE_SPIKE = 1;
        public const int TRAP_BASE_TYPE_STRONG_SPIKE = 2;
        public const int TRAP_BASE_TYPE_DEADLY_SPIKE = 3;
        public const int TRAP_BASE_TYPE_MINOR_HOLY = 4;
        public const int TRAP_BASE_TYPE_AVERAGE_HOLY = 5;
        public const int TRAP_BASE_TYPE_STRONG_HOLY = 6;
        public const int TRAP_BASE_TYPE_DEADLY_HOLY = 7;
        public const int TRAP_BASE_TYPE_MINOR_TANGLE = 8;
        public const int TRAP_BASE_TYPE_AVERAGE_TANGLE = 9;
        public const int TRAP_BASE_TYPE_STRONG_TANGLE = 10;
        public const int TRAP_BASE_TYPE_DEADLY_TANGLE = 11;
        public const int TRAP_BASE_TYPE_MINOR_ACID = 12;
        public const int TRAP_BASE_TYPE_AVERAGE_ACID = 13;
        public const int TRAP_BASE_TYPE_STRONG_ACID = 14;
        public const int TRAP_BASE_TYPE_DEADLY_ACID = 15;
        public const int TRAP_BASE_TYPE_MINOR_FIRE = 16;
        public const int TRAP_BASE_TYPE_AVERAGE_FIRE = 17;
        public const int TRAP_BASE_TYPE_STRONG_FIRE = 18;
        public const int TRAP_BASE_TYPE_DEADLY_FIRE = 19;
        public const int TRAP_BASE_TYPE_MINOR_ELECTRICAL = 20;
        public const int TRAP_BASE_TYPE_AVERAGE_ELECTRICAL = 21;
        public const int TRAP_BASE_TYPE_STRONG_ELECTRICAL = 22;
        public const int TRAP_BASE_TYPE_DEADLY_ELECTRICAL = 23;
        public const int TRAP_BASE_TYPE_MINOR_GAS = 24;
        public const int TRAP_BASE_TYPE_AVERAGE_GAS = 25;
        public const int TRAP_BASE_TYPE_STRONG_GAS = 26;
        public const int TRAP_BASE_TYPE_DEADLY_GAS = 27;
        public const int TRAP_BASE_TYPE_MINOR_FROST = 28;
        public const int TRAP_BASE_TYPE_AVERAGE_FROST = 29;
        public const int TRAP_BASE_TYPE_STRONG_FROST = 30;
        public const int TRAP_BASE_TYPE_DEADLY_FROST = 31;
        public const int TRAP_BASE_TYPE_MINOR_NEGATIVE = 32;
        public const int TRAP_BASE_TYPE_AVERAGE_NEGATIVE = 33;
        public const int TRAP_BASE_TYPE_STRONG_NEGATIVE = 34;
        public const int TRAP_BASE_TYPE_DEADLY_NEGATIVE = 35;
        public const int TRAP_BASE_TYPE_MINOR_SONIC = 36;
        public const int TRAP_BASE_TYPE_AVERAGE_SONIC = 37;
        public const int TRAP_BASE_TYPE_STRONG_SONIC = 38;
        public const int TRAP_BASE_TYPE_DEADLY_SONIC = 39;
        public const int TRAP_BASE_TYPE_MINOR_ACID_SPLASH = 40;
        public const int TRAP_BASE_TYPE_AVERAGE_ACID_SPLASH = 41;
        public const int TRAP_BASE_TYPE_STRONG_ACID_SPLASH = 42;
        public const int TRAP_BASE_TYPE_DEADLY_ACID_SPLASH = 43;
        public const int TRAP_BASE_TYPE_EPIC_ELECTRICAL = 44;
        public const int TRAP_BASE_TYPE_EPIC_FIRE = 45;
        public const int TRAP_BASE_TYPE_EPIC_FROST = 46;
        public const int TRAP_BASE_TYPE_EPIC_SONIC = 47;
        public const int TRACK_RURALDAY1 = 1;
        public const int TRACK_RURALDAY2 = 2;
        public const int TRACK_RURALNIGHT = 3;
        public const int TRACK_FORESTDAY1 = 4;
        public const int TRACK_FORESTDAY2 = 5;
        public const int TRACK_FORESTNIGHT = 6;
        public const int TRACK_DUNGEON1 = 7;
        public const int TRACK_SEWER = 8;
        public const int TRACK_MINES1 = 9;
        public const int TRACK_MINES2 = 10;
        public const int TRACK_CRYPT1 = 11;
        public const int TRACK_CRYPT2 = 12;
        public const int TRACK_DESERT_DAY = 58;
        public const int TRACK_DESERT_NIGHT = 61;
        public const int TRACK_WINTER_DAY = 59;
        public const int TRACK_EVILDUNGEON1 = 13;
        public const int TRACK_EVILDUNGEON2 = 14;
        public const int TRACK_CITYSLUMDAY = 15;
        public const int TRACK_CITYSLUMNIGHT = 16;
        public const int TRACK_CITYDOCKDAY = 17;
        public const int TRACK_CITYDOCKNIGHT = 18;
        public const int TRACK_CITYWEALTHY = 19;
        public const int TRACK_CITYMARKET = 20;
        public const int TRACK_CITYNIGHT = 21;
        public const int TRACK_TAVERN1 = 22;
        public const int TRACK_TAVERN2 = 23;
        public const int TRACK_TAVERN3 = 24;
        public const int TRACK_TAVERN4 = 56;
        public const int TRACK_RICHHOUSE = 25;
        public const int TRACK_STORE = 26;
        public const int TRACK_TEMPLEGOOD = 27;
        public const int TRACK_TEMPLEGOOD2 = 49;
        public const int TRACK_TEMPLEEVIL = 28;
        public const int TRACK_THEME_NWN = 29;
        public const int TRACK_THEME_CHAPTER1 = 30;
        public const int TRACK_THEME_CHAPTER2 = 31;
        public const int TRACK_THEME_CHAPTER3 = 32;
        public const int TRACK_THEME_CHAPTER4 = 33;
        public const int TRACK_BATTLE_RURAL1 = 34;
        public const int TRACK_BATTLE_FOREST1 = 35;
        public const int TRACK_BATTLE_FOREST2 = 36;
        public const int TRACK_BATTLE_DUNGEON1 = 37;
        public const int TRACK_BATTLE_DUNGEON2 = 38;
        public const int TRACK_BATTLE_DUNGEON3 = 39;
        public const int TRACK_BATTLE_CITY1 = 40;
        public const int TRACK_BATTLE_CITY2 = 41;
        public const int TRACK_BATTLE_CITY3 = 42;
        public const int TRACK_BATTLE_CITYBOSS = 43;
        public const int TRACK_BATTLE_FORESTBOSS = 44;
        public const int TRACK_BATTLE_LIZARDBOSS = 45;
        public const int TRACK_BATTLE_DRAGON = 46;
        public const int TRACK_BATTLE_ARIBETH = 47;
        public const int TRACK_BATTLE_ENDBOSS = 48;
        public const int TRACK_BATTLE_DESERT = 57;
        public const int TRACK_BATTLE_WINTER = 60;
        public const int TRACK_CASTLE = 50;
        public const int TRACK_THEME_ARIBETH1 = 51;
        public const int TRACK_THEME_ARIBETH2 = 52;
        public const int TRACK_THEME_GEND = 53;
        public const int TRACK_THEME_MAUGRIM = 54;
        public const int TRACK_THEME_MORAG = 55;
        public const int TRACK_HOTU_THEME = 62;
        public const int TRACK_HOTU_WATERDEEP = 63;
        public const int TRACK_HOTU_UNDERMOUNTAIN = 64;
        public const int TRACK_HOTU_REBELCAMP = 65;
        public const int TRACK_HOTU_FIREPLANE = 66;
        public const int TRACK_HOTU_QUEEN = 67;
        public const int TRACK_HOTU_HELLFROZEOVER = 68;
        public const int TRACK_HOTU_DRACOLICH = 69;
        public const int TRACK_HOTU_BATTLE_SMALL = 70;
        public const int TRACK_HOTU_BATTLE_MED = 71;
        public const int TRACK_HOTU_BATTLE_LARGE = 72;
        public const int TRACK_HOTU_BATTLE_HELL = 73;
        public const int TRACK_HOTU_BATTLE_BOSS1 = 74;
        public const int TRACK_HOTU_BATTLE_BOSS2 = 75;
        public const int STEALTH_MODE_DISABLED = 0;
        public const int STEALTH_MODE_ACTIVATED = 1;
        public const int DETECT_MODE_PASSIVE = 0;
        public const int DETECT_MODE_ACTIVE = 1;
        public const int DEFENSIVE_CASTING_MODE_DISABLED = 0;
        public const int DEFENSIVE_CASTING_MODE_ACTIVATED = 1;
        public const int APPEARANCE_TYPE_INVALID = -1;
        public const int APPEARANCE_TYPE_ALLIP = 186;
        public const int APPEARANCE_TYPE_ARANEA = 157;
        public const int APPEARANCE_TYPE_ARCH_TARGET = 200;
        public const int APPEARANCE_TYPE_ARIBETH = 190;
        public const int APPEARANCE_TYPE_ASABI_CHIEFTAIN = 353;
        public const int APPEARANCE_TYPE_ASABI_SHAMAN = 354;
        public const int APPEARANCE_TYPE_ASABI_WARRIOR = 355;
        public const int APPEARANCE_TYPE_BADGER = 8;
        public const int APPEARANCE_TYPE_BADGER_DIRE = 9;
        public const int APPEARANCE_TYPE_BALOR = 38;
        public const int APPEARANCE_TYPE_BARTENDER = 234;
        public const int APPEARANCE_TYPE_BASILISK = 369;
        public const int APPEARANCE_TYPE_BAT = 10;
        public const int APPEARANCE_TYPE_BAT_HORROR = 11;
        public const int APPEARANCE_TYPE_BEAR_BLACK = 12;
        public const int APPEARANCE_TYPE_BEAR_BROWN = 13;
        public const int APPEARANCE_TYPE_BEAR_DIRE = 15;
        public const int APPEARANCE_TYPE_BEAR_KODIAK = 204;
        public const int APPEARANCE_TYPE_BEAR_POLAR = 14;
        public const int APPEARANCE_TYPE_BEETLE_FIRE = 18;
        public const int APPEARANCE_TYPE_BEETLE_SLICER = 17;
        public const int APPEARANCE_TYPE_BEETLE_STAG = 19;
        public const int APPEARANCE_TYPE_BEETLE_STINK = 20;
        public const int APPEARANCE_TYPE_BEGGER = 220;
        public const int APPEARANCE_TYPE_BLOOD_SAILER = 221;
        public const int APPEARANCE_TYPE_BOAR = 21;
        public const int APPEARANCE_TYPE_BOAR_DIRE = 22;
        public const int APPEARANCE_TYPE_BODAK = 23;
        public const int APPEARANCE_TYPE_BUGBEAR_A = 29;
        public const int APPEARANCE_TYPE_BUGBEAR_B = 30;
        public const int APPEARANCE_TYPE_BUGBEAR_CHIEFTAIN_A = 25;
        public const int APPEARANCE_TYPE_BUGBEAR_CHIEFTAIN_B = 26;
        public const int APPEARANCE_TYPE_BUGBEAR_SHAMAN_A = 27;
        public const int APPEARANCE_TYPE_BUGBEAR_SHAMAN_B = 28;
        public const int APPEARANCE_TYPE_BULETTE = 481;
        public const int APPEARANCE_TYPE_CAT_CAT_DIRE = 95;
        public const int APPEARANCE_TYPE_CAT_COUGAR = 203;
        public const int APPEARANCE_TYPE_CAT_CRAG_CAT = 94;
        public const int APPEARANCE_TYPE_CAT_JAGUAR = 98;
        public const int APPEARANCE_TYPE_CAT_KRENSHAR = 96;
        public const int APPEARANCE_TYPE_CAT_LEOPARD = 93;
        public const int APPEARANCE_TYPE_CAT_LION = 97;
        public const int APPEARANCE_TYPE_CAT_MPANTHER = 306;
        public const int APPEARANCE_TYPE_CAT_PANTHER = 202;
        public const int APPEARANCE_TYPE_CHICKEN = 31;
        public const int APPEARANCE_TYPE_COCKATRICE = 368;
        public const int APPEARANCE_TYPE_COMBAT_DUMMY = 201;
        public const int APPEARANCE_TYPE_CONVICT = 238;
        public const int APPEARANCE_TYPE_COW = 34;
        public const int APPEARANCE_TYPE_CULT_MEMBER = 212;
        public const int APPEARANCE_TYPE_DEER = 35;
        public const int APPEARANCE_TYPE_DEER_STAG = 37;
        public const int APPEARANCE_TYPE_DEVIL = 392;
        public const int APPEARANCE_TYPE_DOG = 176;
        public const int APPEARANCE_TYPE_DOG_BLINKDOG = 174;
        public const int APPEARANCE_TYPE_DOG_DIRE_WOLF = 175;
        public const int APPEARANCE_TYPE_DOG_FENHOUND = 177;
        public const int APPEARANCE_TYPE_DOG_HELL_HOUND = 179;
        public const int APPEARANCE_TYPE_DOG_SHADOW_MASTIF = 180;
        public const int APPEARANCE_TYPE_DOG_WINTER_WOLF = 184;
        public const int APPEARANCE_TYPE_DOG_WOLF = 181;
        public const int APPEARANCE_TYPE_DOG_WORG = 185;
        public const int APPEARANCE_TYPE_DOOM_KNIGHT = 40;
        public const int APPEARANCE_TYPE_DRAGON_BLACK = 41;
        public const int APPEARANCE_TYPE_DRAGON_BLUE = 47;
        public const int APPEARANCE_TYPE_DRAGON_BRASS = 42;
        public const int APPEARANCE_TYPE_DRAGON_BRONZE = 45;
        public const int APPEARANCE_TYPE_DRAGON_COPPER = 43;
        public const int APPEARANCE_TYPE_DRAGON_GOLD = 46;
        public const int APPEARANCE_TYPE_DRAGON_GREEN = 48;
        public const int APPEARANCE_TYPE_DRAGON_RED = 49;
        public const int APPEARANCE_TYPE_DRAGON_SILVER = 44;
        public const int APPEARANCE_TYPE_DRAGON_WHITE = 50;
        public const int APPEARANCE_TYPE_DROW_CLERIC = 215;
        public const int APPEARANCE_TYPE_DROW_FIGHTER = 216;
        public const int APPEARANCE_TYPE_DRUEGAR_CLERIC = 218;
        public const int APPEARANCE_TYPE_DRUEGAR_FIGHTER = 217;
        public const int APPEARANCE_TYPE_DRYAD = 51;
        public const int APPEARANCE_TYPE_DWARF = 0;
        public const int APPEARANCE_TYPE_DWARF_NPC_FEMALE = 248;
        public const int APPEARANCE_TYPE_DWARF_NPC_MALE = 249;
        public const int APPEARANCE_TYPE_ELEMENTAL_AIR = 52;
        public const int APPEARANCE_TYPE_ELEMENTAL_AIR_ELDER = 53;
        public const int APPEARANCE_TYPE_ELEMENTAL_EARTH = 56;
        public const int APPEARANCE_TYPE_ELEMENTAL_EARTH_ELDER = 57;
        public const int APPEARANCE_TYPE_ELEMENTAL_FIRE = 60;
        public const int APPEARANCE_TYPE_ELEMENTAL_FIRE_ELDER = 61;
        public const int APPEARANCE_TYPE_ELEMENTAL_WATER = 69;
        public const int APPEARANCE_TYPE_ELEMENTAL_WATER_ELDER = 68;
        public const int APPEARANCE_TYPE_ELF = 1;
        public const int APPEARANCE_TYPE_ELF_NPC_FEMALE = 245;
        public const int APPEARANCE_TYPE_ELF_NPC_MALE_01 = 246;
        public const int APPEARANCE_TYPE_ELF_NPC_MALE_02 = 247;
        public const int APPEARANCE_TYPE_ETTERCAP = 166;
        public const int APPEARANCE_TYPE_ETTIN = 72;
        public const int APPEARANCE_TYPE_FAERIE_DRAGON = 374;
        public const int APPEARANCE_TYPE_FAIRY = 55;
        public const int APPEARANCE_TYPE_FALCON = 144;
        public const int APPEARANCE_TYPE_FEMALE_01 = 222;
        public const int APPEARANCE_TYPE_FEMALE_02 = 223;
        public const int APPEARANCE_TYPE_FEMALE_03 = 224;
        public const int APPEARANCE_TYPE_FEMALE_04 = 225;
        public const int APPEARANCE_TYPE_FORMIAN_MYRMARCH = 362;
        public const int APPEARANCE_TYPE_FORMIAN_QUEEN = 363;
        public const int APPEARANCE_TYPE_FORMIAN_WARRIOR = 361;
        public const int APPEARANCE_TYPE_FORMIAN_WORKER = 360;
        public const int APPEARANCE_TYPE_GARGOYLE = 73;
        public const int APPEARANCE_TYPE_GHAST = 74;
        public const int APPEARANCE_TYPE_GHOUL = 76;
        public const int APPEARANCE_TYPE_GHOUL_LORD = 77;
        public const int APPEARANCE_TYPE_GIANT_FIRE = 80;
        public const int APPEARANCE_TYPE_GIANT_FIRE_FEMALE = 351;
        public const int APPEARANCE_TYPE_GIANT_FROST = 81;
        public const int APPEARANCE_TYPE_GIANT_FROST_FEMALE = 350;
        public const int APPEARANCE_TYPE_GIANT_HILL = 78;
        public const int APPEARANCE_TYPE_GIANT_MOUNTAIN = 79;
        public const int APPEARANCE_TYPE_GNOLL_WARRIOR = 388;
        public const int APPEARANCE_TYPE_GNOLL_WIZ = 389;
        public const int APPEARANCE_TYPE_GNOME = 2;
        public const int APPEARANCE_TYPE_GNOME_NPC_FEMALE = 243;
        public const int APPEARANCE_TYPE_GNOME_NPC_MALE = 244;
        public const int APPEARANCE_TYPE_GOBLIN_A = 86;
        public const int APPEARANCE_TYPE_GOBLIN_B = 87;
        public const int APPEARANCE_TYPE_GOBLIN_CHIEF_A = 82;
        public const int APPEARANCE_TYPE_GOBLIN_CHIEF_B = 83;
        public const int APPEARANCE_TYPE_GOBLIN_SHAMAN_A = 84;
        public const int APPEARANCE_TYPE_GOBLIN_SHAMAN_B = 85;
        public const int APPEARANCE_TYPE_GOLEM_BONE = 24;
        public const int APPEARANCE_TYPE_GOLEM_CLAY = 91;
        public const int APPEARANCE_TYPE_GOLEM_FLESH = 88;
        public const int APPEARANCE_TYPE_GOLEM_IRON = 89;
        public const int APPEARANCE_TYPE_GOLEM_STONE = 92;
        public const int APPEARANCE_TYPE_GORGON = 367;
        public const int APPEARANCE_TYPE_GRAY_OOZE = 393;
        public const int APPEARANCE_TYPE_GREY_RENDER = 205;
        public const int APPEARANCE_TYPE_GYNOSPHINX = 365;
        public const int APPEARANCE_TYPE_HALFLING = 3;
        public const int APPEARANCE_TYPE_HALFLING_NPC_FEMALE = 250;
        public const int APPEARANCE_TYPE_HALFLING_NPC_MALE = 251;
        public const int APPEARANCE_TYPE_HALF_ELF = 4;
        public const int APPEARANCE_TYPE_HALF_ORC = 5;
        public const int APPEARANCE_TYPE_HALF_ORC_NPC_FEMALE = 252;
        public const int APPEARANCE_TYPE_HALF_ORC_NPC_MALE_01 = 253;
        public const int APPEARANCE_TYPE_HALF_ORC_NPC_MALE_02 = 254;
        public const int APPEARANCE_TYPE_HELMED_HORROR = 100;
        public const int APPEARANCE_TYPE_HEURODIS_LICH = 370;
        public const int APPEARANCE_TYPE_HOBGOBLIN_WARRIOR = 390;
        public const int APPEARANCE_TYPE_HOBGOBLIN_WIZARD = 391;
        public const int APPEARANCE_TYPE_HOOK_HORROR = 102;
        public const int APPEARANCE_TYPE_HOUSE_GUARD = 219;
        public const int APPEARANCE_TYPE_HUMAN = 6;
        public const int APPEARANCE_TYPE_HUMAN_NPC_FEMALE_01 = 255;
        public const int APPEARANCE_TYPE_HUMAN_NPC_FEMALE_02 = 256;
        public const int APPEARANCE_TYPE_HUMAN_NPC_FEMALE_03 = 257;
        public const int APPEARANCE_TYPE_HUMAN_NPC_FEMALE_04 = 258;
        public const int APPEARANCE_TYPE_HUMAN_NPC_FEMALE_05 = 259;
        public const int APPEARANCE_TYPE_HUMAN_NPC_FEMALE_06 = 260;
        public const int APPEARANCE_TYPE_HUMAN_NPC_FEMALE_07 = 261;
        public const int APPEARANCE_TYPE_HUMAN_NPC_FEMALE_08 = 262;
        public const int APPEARANCE_TYPE_HUMAN_NPC_FEMALE_09 = 263;
        public const int APPEARANCE_TYPE_HUMAN_NPC_FEMALE_10 = 264;
        public const int APPEARANCE_TYPE_HUMAN_NPC_FEMALE_11 = 265;
        public const int APPEARANCE_TYPE_HUMAN_NPC_FEMALE_12 = 266;
        public const int APPEARANCE_TYPE_HUMAN_NPC_MALE_01 = 267;
        public const int APPEARANCE_TYPE_HUMAN_NPC_MALE_02 = 268;
        public const int APPEARANCE_TYPE_HUMAN_NPC_MALE_03 = 269;
        public const int APPEARANCE_TYPE_HUMAN_NPC_MALE_04 = 270;
        public const int APPEARANCE_TYPE_HUMAN_NPC_MALE_05 = 271;
        public const int APPEARANCE_TYPE_HUMAN_NPC_MALE_06 = 272;
        public const int APPEARANCE_TYPE_HUMAN_NPC_MALE_07 = 273;
        public const int APPEARANCE_TYPE_HUMAN_NPC_MALE_08 = 274;
        public const int APPEARANCE_TYPE_HUMAN_NPC_MALE_09 = 275;
        public const int APPEARANCE_TYPE_HUMAN_NPC_MALE_10 = 276;
        public const int APPEARANCE_TYPE_HUMAN_NPC_MALE_11 = 277;
        public const int APPEARANCE_TYPE_HUMAN_NPC_MALE_12 = 278;
        public const int APPEARANCE_TYPE_HUMAN_NPC_MALE_13 = 279;
        public const int APPEARANCE_TYPE_HUMAN_NPC_MALE_14 = 280;
        public const int APPEARANCE_TYPE_HUMAN_NPC_MALE_15 = 281;
        public const int APPEARANCE_TYPE_HUMAN_NPC_MALE_16 = 282;
        public const int APPEARANCE_TYPE_HUMAN_NPC_MALE_17 = 283;
        public const int APPEARANCE_TYPE_HUMAN_NPC_MALE_18 = 284;
        public const int APPEARANCE_TYPE_IMP = 105;
        public const int APPEARANCE_TYPE_INN_KEEPER = 233;
        public const int APPEARANCE_TYPE_INTELLECT_DEVOURER = 117;
        public const int APPEARANCE_TYPE_INVISIBLE_HUMAN_MALE = 298;
        public const int APPEARANCE_TYPE_INVISIBLE_STALKER = 64;
        public const int APPEARANCE_TYPE_KID_FEMALE = 242;
        public const int APPEARANCE_TYPE_KID_MALE = 241;
        public const int APPEARANCE_TYPE_KOBOLD_A = 302;
        public const int APPEARANCE_TYPE_KOBOLD_B = 305;
        public const int APPEARANCE_TYPE_KOBOLD_CHIEF_A = 300;
        public const int APPEARANCE_TYPE_KOBOLD_CHIEF_B = 303;
        public const int APPEARANCE_TYPE_KOBOLD_SHAMAN_A = 301;
        public const int APPEARANCE_TYPE_KOBOLD_SHAMAN_B = 304;
        public const int APPEARANCE_TYPE_LANTERN_ARCHON = 103;
        public const int APPEARANCE_TYPE_LICH = 39;
        public const int APPEARANCE_TYPE_LIZARDFOLK_A = 134;
        public const int APPEARANCE_TYPE_LIZARDFOLK_B = 135;
        public const int APPEARANCE_TYPE_LIZARDFOLK_SHAMAN_A = 132;
        public const int APPEARANCE_TYPE_LIZARDFOLK_SHAMAN_B = 133;
        public const int APPEARANCE_TYPE_LIZARDFOLK_WARRIOR_A = 130;
        public const int APPEARANCE_TYPE_LIZARDFOLK_WARRIOR_B = 131;
        public const int APPEARANCE_TYPE_LUSKAN_GUARD = 211;
        public const int APPEARANCE_TYPE_MALE_01 = 226;
        public const int APPEARANCE_TYPE_MALE_02 = 227;
        public const int APPEARANCE_TYPE_MALE_03 = 228;
        public const int APPEARANCE_TYPE_MALE_04 = 229;
        public const int APPEARANCE_TYPE_MALE_05 = 230;
        public const int APPEARANCE_TYPE_MANTICORE = 366;
        public const int APPEARANCE_TYPE_MEDUSA = 352;
        public const int APPEARANCE_TYPE_MEPHIT_AIR = 106;
        public const int APPEARANCE_TYPE_MEPHIT_DUST = 107;
        public const int APPEARANCE_TYPE_MEPHIT_EARTH = 108;
        public const int APPEARANCE_TYPE_MEPHIT_FIRE = 109;
        public const int APPEARANCE_TYPE_MEPHIT_ICE = 110;
        public const int APPEARANCE_TYPE_MEPHIT_MAGMA = 114;
        public const int APPEARANCE_TYPE_MEPHIT_OOZE = 112;
        public const int APPEARANCE_TYPE_MEPHIT_SALT = 111;
        public const int APPEARANCE_TYPE_MEPHIT_STEAM = 113;
        public const int APPEARANCE_TYPE_MEPHIT_WATER = 115;
        public const int APPEARANCE_TYPE_MINOGON = 119;
        public const int APPEARANCE_TYPE_MINOTAUR = 120;
        public const int APPEARANCE_TYPE_MINOTAUR_CHIEFTAIN = 121;
        public const int APPEARANCE_TYPE_MINOTAUR_SHAMAN = 122;
        public const int APPEARANCE_TYPE_MOHRG = 123;
        public const int APPEARANCE_TYPE_MUMMY_COMMON = 58;
        public const int APPEARANCE_TYPE_MUMMY_FIGHTER_2 = 59;
        public const int APPEARANCE_TYPE_MUMMY_GREATER = 124;
        public const int APPEARANCE_TYPE_MUMMY_WARRIOR = 125;
        public const int APPEARANCE_TYPE_NWN_AARIN = 188;
        public const int APPEARANCE_TYPE_NWN_ARIBETH_EVIL = 189;
        public const int APPEARANCE_TYPE_NWN_HAEDRALINE = 191;
        public const int APPEARANCE_TYPE_NWN_MAUGRIM = 193;
        public const int APPEARANCE_TYPE_NWN_MORAG = 192;
        public const int APPEARANCE_TYPE_NWN_NASHER = 296;
        public const int APPEARANCE_TYPE_NWN_SEDOS = 297;
        public const int APPEARANCE_TYPE_NW_MILITIA_MEMBER = 210;
        public const int APPEARANCE_TYPE_NYMPH = 126;
        public const int APPEARANCE_TYPE_OCHRE_JELLY_LARGE = 394;
        public const int APPEARANCE_TYPE_OCHRE_JELLY_MEDIUM = 396;
        public const int APPEARANCE_TYPE_OCHRE_JELLY_SMALL = 398;
        public const int APPEARANCE_TYPE_OGRE = 127;
        public const int APPEARANCE_TYPE_OGREB = 207;
        public const int APPEARANCE_TYPE_OGRE_CHIEFTAIN = 128;
        public const int APPEARANCE_TYPE_OGRE_CHIEFTAINB = 208;
        public const int APPEARANCE_TYPE_OGRE_MAGE = 129;
        public const int APPEARANCE_TYPE_OGRE_MAGEB = 209;
        public const int APPEARANCE_TYPE_OLD_MAN = 239;
        public const int APPEARANCE_TYPE_OLD_WOMAN = 240;
        public const int APPEARANCE_TYPE_ORC_A = 140;
        public const int APPEARANCE_TYPE_ORC_B = 141;
        public const int APPEARANCE_TYPE_ORC_CHIEFTAIN_A = 136;
        public const int APPEARANCE_TYPE_ORC_CHIEFTAIN_B = 137;
        public const int APPEARANCE_TYPE_ORC_SHAMAN_A = 138;
        public const int APPEARANCE_TYPE_ORC_SHAMAN_B = 139;
        public const int APPEARANCE_TYPE_OX = 142;
        public const int APPEARANCE_TYPE_PARROT = 7;
        public const int APPEARANCE_TYPE_PENGUIN = 206;
        public const int APPEARANCE_TYPE_PLAGUE_VICTIM = 231;
        public const int APPEARANCE_TYPE_PROSTITUTE_01 = 236;
        public const int APPEARANCE_TYPE_PROSTITUTE_02 = 237;
        public const int APPEARANCE_TYPE_PSEUDODRAGON = 375;
        public const int APPEARANCE_TYPE_QUASIT = 104;
        public const int APPEARANCE_TYPE_RAKSHASA_BEAR_MALE = 294;
        public const int APPEARANCE_TYPE_RAKSHASA_TIGER_FEMALE = 290;
        public const int APPEARANCE_TYPE_RAKSHASA_TIGER_MALE = 293;
        public const int APPEARANCE_TYPE_RAKSHASA_WOLF_MALE = 295;
        public const int APPEARANCE_TYPE_RAT = 386;
        public const int APPEARANCE_TYPE_RAT_DIRE = 387;
        public const int APPEARANCE_TYPE_RAVEN = 145;
        public const int APPEARANCE_TYPE_SAHUAGIN = 65;
        public const int APPEARANCE_TYPE_SAHUAGIN_LEADER = 66;
        public const int APPEARANCE_TYPE_SAHUAGIN_CLERIC = 67;
        public const int APPEARANCE_TYPE_SEAGULL_FLYING = 291;
        public const int APPEARANCE_TYPE_SEAGULL_WALKING = 292;
        public const int APPEARANCE_TYPE_SHADOW = 146;
        public const int APPEARANCE_TYPE_SHADOW_FIEND = 147;
        public const int APPEARANCE_TYPE_SHARK_MAKO = 447;
        public const int APPEARANCE_TYPE_SHARK_HAMMERHEAD = 448;
        public const int APPEARANCE_TYPE_SHARK_GOBLIN = 449;
        public const int APPEARANCE_TYPE_SHIELD_GUARDIAN = 90;
        public const int APPEARANCE_TYPE_SHOP_KEEPER = 232;
        public const int APPEARANCE_TYPE_SKELETAL_DEVOURER = 36;
        public const int APPEARANCE_TYPE_SKELETON_CHIEFTAIN = 182;
        public const int APPEARANCE_TYPE_SKELETON_COMMON = 63;
        public const int APPEARANCE_TYPE_SKELETON_MAGE = 148;
        public const int APPEARANCE_TYPE_SKELETON_PRIEST = 62;
        public const int APPEARANCE_TYPE_SKELETON_WARRIOR = 150;
        public const int APPEARANCE_TYPE_SKELETON_WARRIOR_1 = 70;
        public const int APPEARANCE_TYPE_SKELETON_WARRIOR_2 = 71;
        public const int APPEARANCE_TYPE_SLAAD_BLUE = 151;
        public const int APPEARANCE_TYPE_SLAAD_DEATH = 152;
        public const int APPEARANCE_TYPE_SLAAD_GRAY = 153;
        public const int APPEARANCE_TYPE_SLAAD_GREEN = 154;
        public const int APPEARANCE_TYPE_SLAAD_RED = 155;
        public const int APPEARANCE_TYPE_SPECTRE = 156;
        public const int APPEARANCE_TYPE_SPHINX = 364;
        public const int APPEARANCE_TYPE_SPIDER_DIRE = 158;
        public const int APPEARANCE_TYPE_SPIDER_GIANT = 159;
        public const int APPEARANCE_TYPE_SPIDER_PHASE = 160;
        public const int APPEARANCE_TYPE_SPIDER_SWORD = 161;
        public const int APPEARANCE_TYPE_SPIDER_WRAITH = 162;
        public const int APPEARANCE_TYPE_STINGER = 356;
        public const int APPEARANCE_TYPE_STINGER_CHIEFTAIN = 358;
        public const int APPEARANCE_TYPE_STINGER_MAGE = 359;
        public const int APPEARANCE_TYPE_STINGER_WARRIOR = 357;
        public const int APPEARANCE_TYPE_SUCCUBUS = 163;
        public const int APPEARANCE_TYPE_TROGLODYTE = 451;
        public const int APPEARANCE_TYPE_TROGLODYTE_WARRIOR = 452;
        public const int APPEARANCE_TYPE_TROGLODYTE_CLERIC = 453;
        public const int APPEARANCE_TYPE_TROLL = 167;
        public const int APPEARANCE_TYPE_TROLL_CHIEFTAIN = 164;
        public const int APPEARANCE_TYPE_TROLL_SHAMAN = 165;
        public const int APPEARANCE_TYPE_UMBERHULK = 168;
        public const int APPEARANCE_TYPE_UTHGARD_ELK_TRIBE = 213;
        public const int APPEARANCE_TYPE_UTHGARD_TIGER_TRIBE = 214;
        public const int APPEARANCE_TYPE_VAMPIRE_FEMALE = 288;
        public const int APPEARANCE_TYPE_VAMPIRE_MALE = 289;
        public const int APPEARANCE_TYPE_VROCK = 101;
        public const int APPEARANCE_TYPE_WAITRESS = 235;
        public const int APPEARANCE_TYPE_WAR_DEVOURER = 54;
        public const int APPEARANCE_TYPE_WERECAT = 99;
        public const int APPEARANCE_TYPE_WERERAT = 170;
        public const int APPEARANCE_TYPE_WEREWOLF = 171;
        public const int APPEARANCE_TYPE_WIGHT = 172;
        public const int APPEARANCE_TYPE_WILL_O_WISP = 116;
        public const int APPEARANCE_TYPE_WRAITH = 187;
        public const int APPEARANCE_TYPE_WYRMLING_BLACK = 378;
        public const int APPEARANCE_TYPE_WYRMLING_BLUE = 377;
        public const int APPEARANCE_TYPE_WYRMLING_BRASS = 381;
        public const int APPEARANCE_TYPE_WYRMLING_BRONZE = 383;
        public const int APPEARANCE_TYPE_WYRMLING_COPPER = 382;
        public const int APPEARANCE_TYPE_WYRMLING_GOLD = 385;
        public const int APPEARANCE_TYPE_WYRMLING_GREEN = 379;
        public const int APPEARANCE_TYPE_WYRMLING_RED = 376;
        public const int APPEARANCE_TYPE_WYRMLING_SILVER = 384;
        public const int APPEARANCE_TYPE_WYRMLING_WHITE = 380;
        public const int APPEARANCE_TYPE_YUAN_TI = 285;
        public const int APPEARANCE_TYPE_YUAN_TI_CHIEFTEN = 286;
        public const int APPEARANCE_TYPE_YUAN_TI_WIZARD = 287;
        public const int APPEARANCE_TYPE_ZOMBIE = 198;
        public const int APPEARANCE_TYPE_ZOMBIE_ROTTING = 195;
        public const int APPEARANCE_TYPE_ZOMBIE_TYRANT_FOG = 199;
        public const int APPEARANCE_TYPE_ZOMBIE_WARRIOR_1 = 196;
        public const int APPEARANCE_TYPE_ZOMBIE_WARRIOR_2 = 197;
        public const int APPEARANCE_TYPE_BEHOLDER = 401;
        public const int APPEARANCE_TYPE_BEHOLDER_MAGE = 402;
        public const int APPEARANCE_TYPE_BEHOLDER_EYEBALL = 403;
        public const int APPEARANCE_TYPE_MEPHISTO_BIG = 404;
        public const int APPEARANCE_TYPE_DRACOLICH = 405;
        public const int APPEARANCE_TYPE_DRIDER = 406;
        public const int APPEARANCE_TYPE_DRIDER_CHIEF = 407;
        public const int APPEARANCE_TYPE_DROW_SLAVE = 408;
        public const int APPEARANCE_TYPE_DROW_WIZARD = 409;
        public const int APPEARANCE_TYPE_DROW_MATRON = 410;
        public const int APPEARANCE_TYPE_DUERGAR_SLAVE = 411;
        public const int APPEARANCE_TYPE_DUERGAR_CHIEF = 412;
        public const int APPEARANCE_TYPE_MINDFLAYER = 413;
        public const int APPEARANCE_TYPE_MINDFLAYER_2 = 414;
        public const int APPEARANCE_TYPE_MINDFLAYER_ALHOON = 415;
        public const int APPEARANCE_TYPE_DEEP_ROTHE = 416;
        public const int APPEARANCE_TYPE_DRAGON_SHADOW = 418;
        public const int APPEARANCE_TYPE_HARPY = 419;
        public const int APPEARANCE_TYPE_GOLEM_MITHRAL = 420;
        public const int APPEARANCE_TYPE_GOLEM_ADAMANTIUM = 421;
        public const int APPEARANCE_TYPE_SPIDER_DEMON = 422;
        public const int APPEARANCE_TYPE_SVIRF_MALE = 423;
        public const int APPEARANCE_TYPE_SVIRF_FEMALE = 424;
        public const int APPEARANCE_TYPE_DRAGON_PRIS = 425;
        public const int APPEARANCE_TYPE_SLAAD_BLACK = 426;
        public const int APPEARANCE_TYPE_SLAAD_WHITE = 427;
        public const int APPEARANCE_TYPE_AZER_MALE = 428;
        public const int APPEARANCE_TYPE_AZER_FEMALE = 429;
        public const int APPEARANCE_TYPE_DEMI_LICH = 430;
        public const int APPEARANCE_TYPE_OBJECT_CHAIR = 431;
        public const int APPEARANCE_TYPE_OBJECT_TABLE = 432;
        public const int APPEARANCE_TYPE_OBJECT_CANDLE = 433;
        public const int APPEARANCE_TYPE_OBJECT_CHEST = 434;
        public const int APPEARANCE_TYPE_OBJECT_WHITE = 435;
        public const int APPEARANCE_TYPE_OBJECT_BLUE = 436;
        public const int APPEARANCE_TYPE_OBJECT_CYAN = 437;
        public const int APPEARANCE_TYPE_OBJECT_GREEN = 438;
        public const int APPEARANCE_TYPE_OBJECT_YELLOW = 439;
        public const int APPEARANCE_TYPE_OBJECT_ORANGE = 440;
        public const int APPEARANCE_TYPE_OBJECT_RED = 441;
        public const int APPEARANCE_TYPE_OBJECT_PURPLE = 442;
        public const int APPEARANCE_TYPE_OBJECT_FLAME_SMALL = 443;
        public const int APPEARANCE_TYPE_OBJECT_FLAME_MEDIUM = 444;
        public const int APPEARANCE_TYPE_OBJECT_FLAME_LARGE = 445;
        public const int APPEARANCE_TYPE_DRIDER_FEMALE = 446;
        public const int APPEARANCE_TYPE_SEA_HAG = 454;
        public const int APPEARANCE_TYPE_GOLEM_DEMONFLESH = 468;
        public const int APPEARANCE_TYPE_ANIMATED_CHEST = 469;
        public const int APPEARANCE_TYPE_GELATINOUS_CUBE = 470;
        public const int APPEARANCE_TYPE_MEPHISTO_NORM = 471;
        public const int APPEARANCE_TYPE_BEHOLDER_MOTHER = 472;
        public const int APPEARANCE_TYPE_OBJECT_BOAT = 473;
        public const int APPEARANCE_TYPE_DWARF_GOLEM = 474;
        public const int APPEARANCE_TYPE_DWARF_HALFORC = 475;
        public const int APPEARANCE_TYPE_DROW_WARRIOR_1 = 476;
        public const int APPEARANCE_TYPE_DROW_WARRIOR_2 = 477;
        public const int APPEARANCE_TYPE_DROW_FEMALE_1 = 478;
        public const int APPEARANCE_TYPE_DROW_FEMALE_2 = 479;
        public const int APPEARANCE_TYPE_DROW_WARRIOR_3 = 480;
        public const int PHENOTYPE_NORMAL = 0;
        public const int PHENOTYPE_BIG = 2;
        public const int PHENOTYPE_CUSTOM1 = 3;
        public const int PHENOTYPE_CUSTOM2 = 4;
        public const int PHENOTYPE_CUSTOM3 = 5;
        public const int PHENOTYPE_CUSTOM4 = 6;
        public const int PHENOTYPE_CUSTOM5 = 7;
        public const int PHENOTYPE_CUSTOM6 = 8;
        public const int PHENOTYPE_CUSTOM7 = 9;
        public const int PHENOTYPE_CUSTOM8 = 10;
        public const int PHENOTYPE_CUSTOM9 = 11;
        public const int PHENOTYPE_CUSTOM10 = 12;
        public const int PHENOTYPE_CUSTOM11 = 13;
        public const int PHENOTYPE_CUSTOM12 = 14;
        public const int PHENOTYPE_CUSTOM13 = 15;
        public const int PHENOTYPE_CUSTOM14 = 16;
        public const int PHENOTYPE_CUSTOM15 = 17;
        public const int PHENOTYPE_CUSTOM16 = 18;
        public const int PHENOTYPE_CUSTOM17 = 19;
        public const int PHENOTYPE_CUSTOM18 = 20;
        public const int CAMERA_TRANSITION_TYPE_SNAP = 0;
        public const int CAMERA_TRANSITION_TYPE_CRAWL = 2;
        public const int CAMERA_TRANSITION_TYPE_VERY_SLOW = 5;
        public const int CAMERA_TRANSITION_TYPE_SLOW = 20;
        public const int CAMERA_TRANSITION_TYPE_MEDIUM = 40;
        public const int CAMERA_TRANSITION_TYPE_FAST = 70;
        public const int CAMERA_TRANSITION_TYPE_VERY_FAST = 100;
        public const float FADE_SPEED_SLOWEST = 0.003f;
        public const float FADE_SPEED_SLOW = 0.005f;
        public const float FADE_SPEED_MEDIUM = 0.01f;
        public const float FADE_SPEED_FAST = 0.017f;
        public const float FADE_SPEED_FASTEST = 0.25f;
        public const int EVENT_HEARTBEAT = 1001;
        public const int EVENT_PERCEIVE = 1002;
        public const int EVENT_END_COMBAT_ROUND = 1003;
        public const int EVENT_DIALOGUE = 1004;
        public const int EVENT_ATTACKED = 1005;
        public const int EVENT_DAMAGED = 1006;
        public const int EVENT_DISTURBED = 1008;
        public const int EVENT_SPELL_CAST_AT = 1011;
        public const int AI_LEVEL_INVALID = -1;
        public const int AI_LEVEL_DEFAULT = -1;
        public const int AI_LEVEL_VERY_LOW = 0;
        public const int AI_LEVEL_LOW = 1;
        public const int AI_LEVEL_NORMAL = 2;
        public const int AI_LEVEL_HIGH = 3;
        public const int AI_LEVEL_VERY_HIGH = 4;
        public const int AREA_INVALID = -1;
        public const int AREA_NATURAL = 1;
        public const int AREA_ARTIFICIAL = 0;
        public const int AREA_ABOVEGROUND = 1;
        public const int AREA_UNDERGROUND = 0;
        public const int AREA_HEIGHT = 0;
        public const int AREA_WIDTH = 1;
        public const int PORTRAIT_INVALID = 65535;
        public const int USE_CREATURE_LEVEL = 0;
        //  The following is all the item property constants...
        public const int IP_CONST_ABILITY_STR = 0;
        public const int IP_CONST_ABILITY_DEX = 1;
        public const int IP_CONST_ABILITY_CON = 2;
        public const int IP_CONST_ABILITY_INT = 3;
        public const int IP_CONST_ABILITY_WIS = 4;
        public const int IP_CONST_ABILITY_CHA = 5;
        public const int IP_CONST_ACMODIFIERTYPE_DODGE = 0;
        public const int IP_CONST_ACMODIFIERTYPE_NATURAL = 1;
        public const int IP_CONST_ACMODIFIERTYPE_ARMOR = 2;
        public const int IP_CONST_ACMODIFIERTYPE_SHIELD = 3;
        public const int IP_CONST_ACMODIFIERTYPE_DEFLECTION = 4;
        public const int IP_CONST_ADDITIONAL_UNKNOWN = 0;
        public const int IP_CONST_ADDITIONAL_CURSED = 1;
        public const int IP_CONST_ALIGNMENTGROUP_ALL = 0;
        public const int IP_CONST_ALIGNMENTGROUP_NEUTRAL = 1;
        public const int IP_CONST_ALIGNMENTGROUP_LAWFUL = 2;
        public const int IP_CONST_ALIGNMENTGROUP_CHAOTIC = 3;
        public const int IP_CONST_ALIGNMENTGROUP_GOOD = 4;
        public const int IP_CONST_ALIGNMENTGROUP_EVIL = 5;
        public const int IP_CONST_ALIGNMENT_LG = 0;
        public const int IP_CONST_ALIGNMENT_LN = 1;
        public const int IP_CONST_ALIGNMENT_LE = 2;
        public const int IP_CONST_ALIGNMENT_NG = 3;
        public const int IP_CONST_ALIGNMENT_TN = 4;
        public const int IP_CONST_ALIGNMENT_NE = 5;
        public const int IP_CONST_ALIGNMENT_CG = 6;
        public const int IP_CONST_ALIGNMENT_CN = 7;
        public const int IP_CONST_ALIGNMENT_CE = 8;
        public const int IP_CONST_RACIALTYPE_DWARF = 0;
        public const int IP_CONST_RACIALTYPE_ELF = 1;
        public const int IP_CONST_RACIALTYPE_GNOME = 2;
        public const int IP_CONST_RACIALTYPE_HALFLING = 3;
        public const int IP_CONST_RACIALTYPE_HALFELF = 4;
        public const int IP_CONST_RACIALTYPE_HALFORC = 5;
        public const int IP_CONST_RACIALTYPE_HUMAN = 6;
        public const int IP_CONST_RACIALTYPE_ABERRATION = 7;
        public const int IP_CONST_RACIALTYPE_ANIMAL = 8;
        public const int IP_CONST_RACIALTYPE_BEAST = 9;
        public const int IP_CONST_RACIALTYPE_CONSTRUCT = 10;
        public const int IP_CONST_RACIALTYPE_DRAGON = 11;
        public const int IP_CONST_RACIALTYPE_HUMANOID_GOBLINOID = 12;
        public const int IP_CONST_RACIALTYPE_HUMANOID_MONSTROUS = 13;
        public const int IP_CONST_RACIALTYPE_HUMANOID_ORC = 14;
        public const int IP_CONST_RACIALTYPE_HUMANOID_REPTILIAN = 15;
        public const int IP_CONST_RACIALTYPE_ELEMENTAL = 16;
        public const int IP_CONST_RACIALTYPE_FEY = 17;
        public const int IP_CONST_RACIALTYPE_GIANT = 18;
        public const int IP_CONST_RACIALTYPE_MAGICAL_BEAST = 19;
        public const int IP_CONST_RACIALTYPE_OUTSIDER = 20;
        public const int IP_CONST_RACIALTYPE_SHAPECHANGER = 23;
        public const int IP_CONST_RACIALTYPE_UNDEAD = 24;
        public const int IP_CONST_RACIALTYPE_VERMIN = 25;
        public const int IP_CONST_UNLIMITEDAMMO_BASIC = 1;
        public const int IP_CONST_UNLIMITEDAMMO_1D6FIRE = 2;
        public const int IP_CONST_UNLIMITEDAMMO_1D6COLD = 3;
        public const int IP_CONST_UNLIMITEDAMMO_1D6LIGHT = 4;
        public const int IP_CONST_UNLIMITEDAMMO_PLUS1 = 11;
        public const int IP_CONST_UNLIMITEDAMMO_PLUS2 = 12;
        public const int IP_CONST_UNLIMITEDAMMO_PLUS3 = 13;
        public const int IP_CONST_UNLIMITEDAMMO_PLUS4 = 14;
        public const int IP_CONST_UNLIMITEDAMMO_PLUS5 = 15;
        public const int IP_CONST_AMMOTYPE_ARROW = 0;
        public const int IP_CONST_AMMOTYPE_BOLT = 1;
        public const int IP_CONST_AMMOTYPE_BULLET = 2;
        public const int IP_CONST_CASTSPELL_NUMUSES_SINGLE_USE = 1;
        public const int IP_CONST_CASTSPELL_NUMUSES_5_CHARGES_PER_USE = 2;
        public const int IP_CONST_CASTSPELL_NUMUSES_4_CHARGES_PER_USE = 3;
        public const int IP_CONST_CASTSPELL_NUMUSES_3_CHARGES_PER_USE = 4;
        public const int IP_CONST_CASTSPELL_NUMUSES_2_CHARGES_PER_USE = 5;
        public const int IP_CONST_CASTSPELL_NUMUSES_1_CHARGE_PER_USE = 6;
        public const int IP_CONST_CASTSPELL_NUMUSES_0_CHARGES_PER_USE = 7;
        public const int IP_CONST_CASTSPELL_NUMUSES_1_USE_PER_DAY = 8;
        public const int IP_CONST_CASTSPELL_NUMUSES_2_USES_PER_DAY = 9;
        public const int IP_CONST_CASTSPELL_NUMUSES_3_USES_PER_DAY = 10;
        public const int IP_CONST_CASTSPELL_NUMUSES_4_USES_PER_DAY = 11;
        public const int IP_CONST_CASTSPELL_NUMUSES_5_USES_PER_DAY = 12;
        public const int IP_CONST_CASTSPELL_NUMUSES_UNLIMITED_USE = 13;
        public const int IP_CONST_DAMAGEBONUS_1 = 1;
        public const int IP_CONST_DAMAGEBONUS_2 = 2;
        public const int IP_CONST_DAMAGEBONUS_3 = 3;
        public const int IP_CONST_DAMAGEBONUS_4 = 4;
        public const int IP_CONST_DAMAGEBONUS_5 = 5;
        public const int IP_CONST_DAMAGEBONUS_1d4 = 6;
        public const int IP_CONST_DAMAGEBONUS_1d6 = 7;
        public const int IP_CONST_DAMAGEBONUS_1d8 = 8;
        public const int IP_CONST_DAMAGEBONUS_1d10 = 9;
        public const int IP_CONST_DAMAGEBONUS_2d6 = 10;
        public const int IP_CONST_DAMAGEBONUS_2d8 = 11;
        public const int IP_CONST_DAMAGEBONUS_2d4 = 12;
        public const int IP_CONST_DAMAGEBONUS_2d10 = 13;
        public const int IP_CONST_DAMAGEBONUS_1d12 = 14;
        public const int IP_CONST_DAMAGEBONUS_2d12 = 15;
        public const int IP_CONST_DAMAGEBONUS_6 = 16;
        public const int IP_CONST_DAMAGEBONUS_7 = 17;
        public const int IP_CONST_DAMAGEBONUS_8 = 18;
        public const int IP_CONST_DAMAGEBONUS_9 = 19;
        public const int IP_CONST_DAMAGEBONUS_10 = 20;
        public const int IP_CONST_DAMAGETYPE_BLUDGEONING = 0;
        public const int IP_CONST_DAMAGETYPE_PIERCING = 1;
        public const int IP_CONST_DAMAGETYPE_SLASHING = 2;
        public const int IP_CONST_DAMAGETYPE_SUBDUAL = 3;
        public const int IP_CONST_DAMAGETYPE_PHYSICAL = 4;
        public const int IP_CONST_DAMAGETYPE_MAGICAL = 5;
        public const int IP_CONST_DAMAGETYPE_ACID = 6;
        public const int IP_CONST_DAMAGETYPE_COLD = 7;
        public const int IP_CONST_DAMAGETYPE_DIVINE = 8;
        public const int IP_CONST_DAMAGETYPE_ELECTRICAL = 9;
        public const int IP_CONST_DAMAGETYPE_FIRE = 10;
        public const int IP_CONST_DAMAGETYPE_NEGATIVE = 11;
        public const int IP_CONST_DAMAGETYPE_POSITIVE = 12;
        public const int IP_CONST_DAMAGETYPE_SONIC = 13;
        public const int IP_CONST_DAMAGEIMMUNITY_5_PERCENT = 1;
        public const int IP_CONST_DAMAGEIMMUNITY_10_PERCENT = 2;
        public const int IP_CONST_DAMAGEIMMUNITY_25_PERCENT = 3;
        public const int IP_CONST_DAMAGEIMMUNITY_50_PERCENT = 4;
        public const int IP_CONST_DAMAGEIMMUNITY_75_PERCENT = 5;
        public const int IP_CONST_DAMAGEIMMUNITY_90_PERCENT = 6;
        public const int IP_CONST_DAMAGEIMMUNITY_100_PERCENT = 7;
        public const int IP_CONST_DAMAGEVULNERABILITY_5_PERCENT = 1;
        public const int IP_CONST_DAMAGEVULNERABILITY_10_PERCENT = 2;
        public const int IP_CONST_DAMAGEVULNERABILITY_25_PERCENT = 3;
        public const int IP_CONST_DAMAGEVULNERABILITY_50_PERCENT = 4;
        public const int IP_CONST_DAMAGEVULNERABILITY_75_PERCENT = 5;
        public const int IP_CONST_DAMAGEVULNERABILITY_90_PERCENT = 6;
        public const int IP_CONST_DAMAGEVULNERABILITY_100_PERCENT = 7;
        public const int IP_CONST_FEAT_ALERTNESS = 0;
        public const int IP_CONST_FEAT_AMBIDEXTROUS = 1;
        public const int IP_CONST_FEAT_CLEAVE = 2;
        public const int IP_CONST_FEAT_COMBAT_CASTING = 3;
        public const int IP_CONST_FEAT_DODGE = 4;
        public const int IP_CONST_FEAT_EXTRA_TURNING = 5;
        public const int IP_CONST_FEAT_KNOCKDOWN = 6;
        public const int IP_CONST_FEAT_POINTBLANK = 7;
        public const int IP_CONST_FEAT_SPELLFOCUSABJ = 8;
        public const int IP_CONST_FEAT_SPELLFOCUSCON = 9;
        public const int IP_CONST_FEAT_SPELLFOCUSDIV = 10;
        public const int IP_CONST_FEAT_SPELLFOCUSENC = 11;
        public const int IP_CONST_FEAT_SPELLFOCUSEVO = 12;
        public const int IP_CONST_FEAT_SPELLFOCUSILL = 13;
        public const int IP_CONST_FEAT_SPELLFOCUSNEC = 14;
        public const int IP_CONST_FEAT_SPELLPENETRATION = 15;
        public const int IP_CONST_FEAT_POWERATTACK = 16;
        public const int IP_CONST_FEAT_TWO_WEAPON_FIGHTING = 17;
        public const int IP_CONST_FEAT_WEAPSPEUNARM = 18;
        public const int IP_CONST_FEAT_WEAPFINESSE = 19;
        public const int IP_CONST_FEAT_IMPCRITUNARM = 20;
        public const int IP_CONST_FEAT_WEAPON_PROF_EXOTIC = 21;
        public const int IP_CONST_FEAT_WEAPON_PROF_MARTIAL = 22;
        public const int IP_CONST_FEAT_WEAPON_PROF_SIMPLE = 23;
        public const int IP_CONST_FEAT_ARMOR_PROF_HEAVY = 24;
        public const int IP_CONST_FEAT_ARMOR_PROF_LIGHT = 25;
        public const int IP_CONST_FEAT_ARMOR_PROF_MEDIUM = 26;
        public const int IP_CONST_FEAT_MOBILITY = 27;
        public const int IP_CONST_FEAT_DISARM = 28;
        public const int IP_CONST_FEAT_WHIRLWIND = 29;
        public const int IP_CONST_FEAT_RAPID_SHOT = 30;
        public const int IP_CONST_FEAT_HIDE_IN_PLAIN_SIGHT = 31;
        public const int IP_CONST_FEAT_SNEAK_ATTACK_1D6 = 32;
        public const int IP_CONST_FEAT_SNEAK_ATTACK_2D6 = 33;
        public const int IP_CONST_FEAT_SNEAK_ATTACK_3D6 = 34;
        public const int IP_CONST_FEAT_SHIELD_PROFICIENCY = 35;
        public const int IP_CONST_FEAT_USE_POISON = 36;
        public const int IP_CONST_FEAT_DISARM_WHIP = 37;
        public const int IP_CONST_FEAT_WEAPON_PROF_CREATURE = 38;
        public const int IP_CONST_FEAT_SNEAK_ATTACK_5D6 = 39;
        public const int IP_CONST_FEAT_PLAYER_TOOL_01 = 53;
        public const int IP_CONST_FEAT_PLAYER_TOOL_02 = 54;
        public const int IP_CONST_FEAT_PLAYER_TOOL_03 = 55;
        public const int IP_CONST_FEAT_PLAYER_TOOL_04 = 56;
        public const int IP_CONST_FEAT_PLAYER_TOOL_05 = 57;
        public const int IP_CONST_FEAT_PLAYER_TOOL_06 = 58;
        public const int IP_CONST_FEAT_PLAYER_TOOL_07 = 59;
        public const int IP_CONST_FEAT_PLAYER_TOOL_08 = 60;
        public const int IP_CONST_FEAT_PLAYER_TOOL_09 = 61;
        public const int IP_CONST_FEAT_PLAYER_TOOL_10 = 62;
        public const int IP_CONST_IMMUNITYMISC_BACKSTAB = 0;
        public const int IP_CONST_IMMUNITYMISC_LEVEL_ABIL_DRAIN = 1;
        public const int IP_CONST_IMMUNITYMISC_MINDSPELLS = 2;
        public const int IP_CONST_IMMUNITYMISC_POISON = 3;
        public const int IP_CONST_IMMUNITYMISC_DISEASE = 4;
        public const int IP_CONST_IMMUNITYMISC_FEAR = 5;
        public const int IP_CONST_IMMUNITYMISC_KNOCKDOWN = 6;
        public const int IP_CONST_IMMUNITYMISC_PARALYSIS = 7;
        public const int IP_CONST_IMMUNITYMISC_CRITICAL_HITS = 8;
        public const int IP_CONST_IMMUNITYMISC_DEATH_MAGIC = 9;
        public const int IP_CONST_LIGHTBRIGHTNESS_DIM = 1;
        public const int IP_CONST_LIGHTBRIGHTNESS_LOW = 2;
        public const int IP_CONST_LIGHTBRIGHTNESS_NORMAL = 3;
        public const int IP_CONST_LIGHTBRIGHTNESS_BRIGHT = 4;
        public const int IP_CONST_LIGHTCOLOR_BLUE = 0;
        public const int IP_CONST_LIGHTCOLOR_YELLOW = 1;
        public const int IP_CONST_LIGHTCOLOR_PURPLE = 2;
        public const int IP_CONST_LIGHTCOLOR_RED = 3;
        public const int IP_CONST_LIGHTCOLOR_GREEN = 4;
        public const int IP_CONST_LIGHTCOLOR_ORANGE = 5;
        public const int IP_CONST_LIGHTCOLOR_WHITE = 6;
        public const int IP_CONST_MONSTERDAMAGE_1d2 = 1;
        public const int IP_CONST_MONSTERDAMAGE_1d3 = 2;
        public const int IP_CONST_MONSTERDAMAGE_1d4 = 3;
        public const int IP_CONST_MONSTERDAMAGE_2d4 = 4;
        public const int IP_CONST_MONSTERDAMAGE_3d4 = 5;
        public const int IP_CONST_MONSTERDAMAGE_4d4 = 6;
        public const int IP_CONST_MONSTERDAMAGE_5d4 = 7;
        public const int IP_CONST_MONSTERDAMAGE_1d6 = 8;
        public const int IP_CONST_MONSTERDAMAGE_2d6 = 9;
        public const int IP_CONST_MONSTERDAMAGE_3d6 = 10;
        public const int IP_CONST_MONSTERDAMAGE_4d6 = 11;
        public const int IP_CONST_MONSTERDAMAGE_5d6 = 12;
        public const int IP_CONST_MONSTERDAMAGE_6d6 = 13;
        public const int IP_CONST_MONSTERDAMAGE_7d6 = 14;
        public const int IP_CONST_MONSTERDAMAGE_8d6 = 15;
        public const int IP_CONST_MONSTERDAMAGE_9d6 = 16;
        public const int IP_CONST_MONSTERDAMAGE_10d6 = 17;
        public const int IP_CONST_MONSTERDAMAGE_1d8 = 18;
        public const int IP_CONST_MONSTERDAMAGE_2d8 = 19;
        public const int IP_CONST_MONSTERDAMAGE_3d8 = 20;
        public const int IP_CONST_MONSTERDAMAGE_4d8 = 21;
        public const int IP_CONST_MONSTERDAMAGE_5d8 = 22;
        public const int IP_CONST_MONSTERDAMAGE_6d8 = 23;
        public const int IP_CONST_MONSTERDAMAGE_7d8 = 24;
        public const int IP_CONST_MONSTERDAMAGE_8d8 = 25;
        public const int IP_CONST_MONSTERDAMAGE_9d8 = 26;
        public const int IP_CONST_MONSTERDAMAGE_10d8 = 27;
        public const int IP_CONST_MONSTERDAMAGE_1d10 = 28;
        public const int IP_CONST_MONSTERDAMAGE_2d10 = 29;
        public const int IP_CONST_MONSTERDAMAGE_3d10 = 30;
        public const int IP_CONST_MONSTERDAMAGE_4d10 = 31;
        public const int IP_CONST_MONSTERDAMAGE_5d10 = 32;
        public const int IP_CONST_MONSTERDAMAGE_6d10 = 33;
        public const int IP_CONST_MONSTERDAMAGE_7d10 = 34;
        public const int IP_CONST_MONSTERDAMAGE_8d10 = 35;
        public const int IP_CONST_MONSTERDAMAGE_9d10 = 36;
        public const int IP_CONST_MONSTERDAMAGE_10d10 = 37;
        public const int IP_CONST_MONSTERDAMAGE_1d12 = 38;
        public const int IP_CONST_MONSTERDAMAGE_2d12 = 39;
        public const int IP_CONST_MONSTERDAMAGE_3d12 = 40;
        public const int IP_CONST_MONSTERDAMAGE_4d12 = 41;
        public const int IP_CONST_MONSTERDAMAGE_5d12 = 42;
        public const int IP_CONST_MONSTERDAMAGE_6d12 = 43;
        public const int IP_CONST_MONSTERDAMAGE_7d12 = 44;
        public const int IP_CONST_MONSTERDAMAGE_8d12 = 45;
        public const int IP_CONST_MONSTERDAMAGE_9d12 = 46;
        public const int IP_CONST_MONSTERDAMAGE_10d12 = 47;
        public const int IP_CONST_MONSTERDAMAGE_1d20 = 48;
        public const int IP_CONST_MONSTERDAMAGE_2d20 = 49;
        public const int IP_CONST_MONSTERDAMAGE_3d20 = 50;
        public const int IP_CONST_MONSTERDAMAGE_4d20 = 51;
        public const int IP_CONST_MONSTERDAMAGE_5d20 = 52;
        public const int IP_CONST_MONSTERDAMAGE_6d20 = 53;
        public const int IP_CONST_MONSTERDAMAGE_7d20 = 54;
        public const int IP_CONST_MONSTERDAMAGE_8d20 = 55;
        public const int IP_CONST_MONSTERDAMAGE_9d20 = 56;
        public const int IP_CONST_MONSTERDAMAGE_10d20 = 57;
        public const int IP_CONST_ONMONSTERHIT_ABILITYDRAIN = 0;
        public const int IP_CONST_ONMONSTERHIT_CONFUSION = 1;
        public const int IP_CONST_ONMONSTERHIT_DISEASE = 2;
        public const int IP_CONST_ONMONSTERHIT_DOOM = 3;
        public const int IP_CONST_ONMONSTERHIT_FEAR = 4;
        public const int IP_CONST_ONMONSTERHIT_LEVELDRAIN = 5;
        public const int IP_CONST_ONMONSTERHIT_POISON = 6;
        public const int IP_CONST_ONMONSTERHIT_SLOW = 7;
        public const int IP_CONST_ONMONSTERHIT_STUN = 8;
        public const int IP_CONST_ONMONSTERHIT_WOUNDING = 9;
        public const int IP_CONST_ONHIT_SLEEP = 0;
        public const int IP_CONST_ONHIT_STUN = 1;
        public const int IP_CONST_ONHIT_HOLD = 2;
        public const int IP_CONST_ONHIT_CONFUSION = 3;
        public const int IP_CONST_ONHIT_DAZE = 5;
        public const int IP_CONST_ONHIT_DOOM = 6;
        public const int IP_CONST_ONHIT_FEAR = 7;
        public const int IP_CONST_ONHIT_KNOCK = 8;
        public const int IP_CONST_ONHIT_SLOW = 9;
        public const int IP_CONST_ONHIT_LESSERDISPEL = 10;
        public const int IP_CONST_ONHIT_DISPELMAGIC = 11;
        public const int IP_CONST_ONHIT_GREATERDISPEL = 12;
        public const int IP_CONST_ONHIT_MORDSDISJUNCTION = 13;
        public const int IP_CONST_ONHIT_SILENCE = 14;
        public const int IP_CONST_ONHIT_DEAFNESS = 15;
        public const int IP_CONST_ONHIT_BLINDNESS = 16;
        public const int IP_CONST_ONHIT_LEVELDRAIN = 17;
        public const int IP_CONST_ONHIT_ABILITYDRAIN = 18;
        public const int IP_CONST_ONHIT_ITEMPOISON = 19;
        public const int IP_CONST_ONHIT_DISEASE = 20;
        public const int IP_CONST_ONHIT_SLAYRACE = 21;
        public const int IP_CONST_ONHIT_SLAYALIGNMENTGROUP = 22;
        public const int IP_CONST_ONHIT_SLAYALIGNMENT = 23;
        public const int IP_CONST_ONHIT_VORPAL = 24;
        public const int IP_CONST_ONHIT_WOUNDING = 25;
        public const int IP_CONST_ONHIT_SAVEDC_14 = 0;
        public const int IP_CONST_ONHIT_SAVEDC_16 = 1;
        public const int IP_CONST_ONHIT_SAVEDC_18 = 2;
        public const int IP_CONST_ONHIT_SAVEDC_20 = 3;
        public const int IP_CONST_ONHIT_SAVEDC_22 = 4;
        public const int IP_CONST_ONHIT_SAVEDC_24 = 5;
        public const int IP_CONST_ONHIT_SAVEDC_26 = 6;
        public const int IP_CONST_ONHIT_DURATION_5_PERCENT_5_ROUNDS = 0;
        public const int IP_CONST_ONHIT_DURATION_10_PERCENT_4_ROUNDS = 1;
        public const int IP_CONST_ONHIT_DURATION_25_PERCENT_3_ROUNDS = 2;
        public const int IP_CONST_ONHIT_DURATION_50_PERCENT_2_ROUNDS = 3;
        public const int IP_CONST_ONHIT_DURATION_75_PERCENT_1_ROUND = 4;
        public const int IP_CONST_ONHIT_CASTSPELL_ACID_FOG = 0;
        public const int IP_CONST_ONHIT_CASTSPELL_BESTOW_CURSE = 1;
        public const int IP_CONST_ONHIT_CASTSPELL_BLADE_BARRIER = 2;
        public const int IP_CONST_ONHIT_CASTSPELL_BLINDNESS_AND_DEAFNESS = 3;
        public const int IP_CONST_ONHIT_CASTSPELL_CALL_LIGHTNING = 4;
        public const int IP_CONST_ONHIT_CASTSPELL_CHAIN_LIGHTNING = 5;
        public const int IP_CONST_ONHIT_CASTSPELL_CLOUDKILL = 6;
        public const int IP_CONST_ONHIT_CASTSPELL_CONFUSION = 7;
        public const int IP_CONST_ONHIT_CASTSPELL_CONTAGION = 8;
        public const int IP_CONST_ONHIT_CASTSPELL_DARKNESS = 9;
        public const int IP_CONST_ONHIT_CASTSPELL_DAZE = 10;
        public const int IP_CONST_ONHIT_CASTSPELL_DELAYED_BLAST_FIREBALL = 11;
        public const int IP_CONST_ONHIT_CASTSPELL_DISMISSAL = 12;
        public const int IP_CONST_ONHIT_CASTSPELL_DISPEL_MAGIC = 13;
        public const int IP_CONST_ONHIT_CASTSPELL_DOOM = 14;
        public const int IP_CONST_ONHIT_CASTSPELL_ENERGY_DRAIN = 15;
        public const int IP_CONST_ONHIT_CASTSPELL_ENERVATION = 16;
        public const int IP_CONST_ONHIT_CASTSPELL_ENTANGLE = 17;
        public const int IP_CONST_ONHIT_CASTSPELL_FEAR = 18;
        public const int IP_CONST_ONHIT_CASTSPELL_FEEBLEMIND = 19;
        public const int IP_CONST_ONHIT_CASTSPELL_FIRE_STORM = 20;
        public const int IP_CONST_ONHIT_CASTSPELL_FIREBALL = 21;
        public const int IP_CONST_ONHIT_CASTSPELL_FLAME_LASH = 22;
        public const int IP_CONST_ONHIT_CASTSPELL_FLAME_STRIKE = 23;
        public const int IP_CONST_ONHIT_CASTSPELL_GHOUL_TOUCH = 24;
        public const int IP_CONST_ONHIT_CASTSPELL_GREASE = 25;
        public const int IP_CONST_ONHIT_CASTSPELL_GREATER_DISPELLING = 26;
        public const int IP_CONST_ONHIT_CASTSPELL_GREATER_SPELL_BREACH = 27;
        public const int IP_CONST_ONHIT_CASTSPELL_GUST_OF_WIND = 28;
        public const int IP_CONST_ONHIT_CASTSPELL_HAMMER_OF_THE_GODS = 29;
        public const int IP_CONST_ONHIT_CASTSPELL_HARM = 30;
        public const int IP_CONST_ONHIT_CASTSPELL_HOLD_ANIMAL = 31;
        public const int IP_CONST_ONHIT_CASTSPELL_HOLD_MONSTER = 32;
        public const int IP_CONST_ONHIT_CASTSPELL_HOLD_PERSON = 33;
        public const int IP_CONST_ONHIT_CASTSPELL_IMPLOSION = 34;
        public const int IP_CONST_ONHIT_CASTSPELL_INCENDIARY_CLOUD = 35;
        public const int IP_CONST_ONHIT_CASTSPELL_LESSER_DISPEL = 36;
        public const int IP_CONST_ONHIT_CASTSPELL_LESSER_SPELL_BREACH = 38;
        public const int IP_CONST_ONHIT_CASTSPELL_LIGHT = 40;
        public const int IP_CONST_ONHIT_CASTSPELL_LIGHTNING_BOLT = 41;
        public const int IP_CONST_ONHIT_CASTSPELL_MAGIC_MISSILE = 42;
        public const int IP_CONST_ONHIT_CASTSPELL_MASS_BLINDNESS_AND_DEAFNESS = 43;
        public const int IP_CONST_ONHIT_CASTSPELL_MASS_CHARM = 44;
        public const int IP_CONST_ONHIT_CASTSPELL_MELFS_ACID_ARROW = 45;
        public const int IP_CONST_ONHIT_CASTSPELL_METEOR_SWARM = 46;
        public const int IP_CONST_ONHIT_CASTSPELL_MIND_FOG = 47;
        public const int IP_CONST_ONHIT_CASTSPELL_PHANTASMAL_KILLER = 49;
        public const int IP_CONST_ONHIT_CASTSPELL_POISON = 50;
        public const int IP_CONST_ONHIT_CASTSPELL_POWER_WORD_KILL = 51;
        public const int IP_CONST_ONHIT_CASTSPELL_POWER_WORD_STUN = 52;
        public const int IP_CONST_ONHIT_CASTSPELL_SCARE = 54;
        public const int IP_CONST_ONHIT_CASTSPELL_SEARING_LIGHT = 55;
        public const int IP_CONST_ONHIT_CASTSPELL_SILENCE = 56;
        public const int IP_CONST_ONHIT_CASTSPELL_SLAY_LIVING = 57;
        public const int IP_CONST_ONHIT_CASTSPELL_SLEEP = 58;
        public const int IP_CONST_ONHIT_CASTSPELL_SLOW = 59;
        public const int IP_CONST_ONHIT_CASTSPELL_SOUND_BURST = 60;
        public const int IP_CONST_ONHIT_CASTSPELL_STINKING_CLOUD = 61;
        public const int IP_CONST_ONHIT_CASTSPELL_STORM_OF_VENGEANCE = 63;
        public const int IP_CONST_ONHIT_CASTSPELL_SUNBEAM = 64;
        public const int IP_CONST_ONHIT_CASTSPELL_VAMPIRIC_TOUCH = 65;
        public const int IP_CONST_ONHIT_CASTSPELL_WAIL_OF_THE_BANSHEE = 66;
        public const int IP_CONST_ONHIT_CASTSPELL_WALL_OF_FIRE = 67;
        public const int IP_CONST_ONHIT_CASTSPELL_WEB = 68;
        public const int IP_CONST_ONHIT_CASTSPELL_WEIRD = 69;
        public const int IP_CONST_ONHIT_CASTSPELL_WORD_OF_FAITH = 70;
        public const int IP_CONST_ONHIT_CASTSPELL_CREEPING_DOOM = 72;
        public const int IP_CONST_ONHIT_CASTSPELL_DESTRUCTION = 73;
        public const int IP_CONST_ONHIT_CASTSPELL_HORRID_WILTING = 74;
        public const int IP_CONST_ONHIT_CASTSPELL_ICE_STORM = 75;
        public const int IP_CONST_ONHIT_CASTSPELL_NEGATIVE_ENERGY_BURST = 76;
        public const int IP_CONST_ONHIT_CASTSPELL_EVARDS_BLACK_TENTACLES = 77;
        public const int IP_CONST_ONHIT_CASTSPELL_ACTIVATE_ITEM = 78;
        public const int IP_CONST_ONHIT_CASTSPELL_FLARE = 79;
        public const int IP_CONST_ONHIT_CASTSPELL_BOMBARDMENT = 80;
        public const int IP_CONST_ONHIT_CASTSPELL_ACID_SPLASH = 81;
        public const int IP_CONST_ONHIT_CASTSPELL_QUILLFIRE = 82;
        public const int IP_CONST_ONHIT_CASTSPELL_EARTHQUAKE = 83;
        public const int IP_CONST_ONHIT_CASTSPELL_SUNBURST = 84;
        public const int IP_CONST_ONHIT_CASTSPELL_BANISHMENT = 85;
        public const int IP_CONST_ONHIT_CASTSPELL_INFLICT_MINOR_WOUNDS = 86;
        public const int IP_CONST_ONHIT_CASTSPELL_INFLICT_LIGHT_WOUNDS = 87;
        public const int IP_CONST_ONHIT_CASTSPELL_INFLICT_MODERATE_WOUNDS = 88;
        public const int IP_CONST_ONHIT_CASTSPELL_INFLICT_SERIOUS_WOUNDS = 89;
        public const int IP_CONST_ONHIT_CASTSPELL_INFLICT_CRITICAL_WOUNDS = 90;
        public const int IP_CONST_ONHIT_CASTSPELL_BALAGARNSIRONHORN = 91;
        public const int IP_CONST_ONHIT_CASTSPELL_DROWN = 92;
        public const int IP_CONST_ONHIT_CASTSPELL_ELECTRIC_JOLT = 93;
        public const int IP_CONST_ONHIT_CASTSPELL_FIREBRAND = 94;
        public const int IP_CONST_ONHIT_CASTSPELL_WOUNDING_WHISPERS = 95;
        public const int IP_CONST_ONHIT_CASTSPELL_UNDEATHS_ETERNAL_FOE = 96;
        public const int IP_CONST_ONHIT_CASTSPELL_INFERNO = 97;
        public const int IP_CONST_ONHIT_CASTSPELL_ISAACS_LESSER_MISSILE_STORM = 98;
        public const int IP_CONST_ONHIT_CASTSPELL_ISAACS_GREATER_MISSILE_STORM = 99;
        public const int IP_CONST_ONHIT_CASTSPELL_BANE = 100;
        public const int IP_CONST_ONHIT_CASTSPELL_SPIKE_GROWTH = 101;
        public const int IP_CONST_ONHIT_CASTSPELL_TASHAS_HIDEOUS_LAUGHTER = 102;
        public const int IP_CONST_ONHIT_CASTSPELL_BIGBYS_INTERPOSING_HAND = 103;
        public const int IP_CONST_ONHIT_CASTSPELL_BIGBYS_FORCEFUL_HAND = 104;
        public const int IP_CONST_ONHIT_CASTSPELL_BIGBYS_GRASPING_HAND = 105;
        public const int IP_CONST_ONHIT_CASTSPELL_BIGBYS_CLENCHED_FIST = 106;
        public const int IP_CONST_ONHIT_CASTSPELL_BIGBYS_CRUSHING_HAND = 107;
        public const int IP_CONST_ONHIT_CASTSPELL_FLESH_TO_STONE = 108;
        public const int IP_CONST_ONHIT_CASTSPELL_STONE_TO_FLESH = 109;
        public const int IP_CONST_ONHIT_CASTSPELL_CRUMBLE = 110;
        public const int IP_CONST_ONHIT_CASTSPELL_INFESTATION_OF_MAGGOTS = 111;
        public const int IP_CONST_ONHIT_CASTSPELL_GREAT_THUNDERCLAP = 112;
        public const int IP_CONST_ONHIT_CASTSPELL_BALL_LIGHTNING = 113;
        public const int IP_CONST_ONHIT_CASTSPELL_GEDLEES_ELECTRIC_LOOP = 114;
        public const int IP_CONST_ONHIT_CASTSPELL_HORIZIKAULS_BOOM = 115;
        public const int IP_CONST_ONHIT_CASTSPELL_MESTILS_ACID_BREATH = 116;
        public const int IP_CONST_ONHIT_CASTSPELL_SCINTILLATING_SPHERE = 117;
        public const int IP_CONST_ONHIT_CASTSPELL_UNDEATH_TO_DEATH = 118;
        public const int IP_CONST_ONHIT_CASTSPELL_STONEHOLD = 119;
        public const int IP_CONST_ONHIT_CASTSPELL_EVIL_BLIGHT = 121;
        public const int IP_CONST_ONHIT_CASTSPELL_ONHIT_TELEPORT = 122;
        public const int IP_CONST_ONHIT_CASTSPELL_ONHIT_SLAYRAKSHASA = 123;
        public const int IP_CONST_ONHIT_CASTSPELL_ONHIT_FIREDAMAGE = 124;
        public const int IP_CONST_ONHIT_CASTSPELL_ONHIT_UNIQUEPOWER = 125;
        public const int IP_CONST_ONHIT_CASTSPELL_ONHIT_PLANARRIFT = 126;
        public const int IP_CONST_ONHIT_CASTSPELL_ONHIT_DARKFIRE = 127;
        public const int IP_CONST_ONHIT_CASTSPELL_ONHIT_EXTRACTBRAIN = 128;
        public const int IP_CONST_ONHIT_CASTSPELL_ONHITFLAMINGSKIN = 129;
        public const int IP_CONST_ONHIT_CASTSPELL_ONHIT_CHAOSSHIELD = 130;
        public const int IP_CONST_ONHIT_CASTSPELL_ONHIT_CONSTRICTWEAPON = 131;
        public const int IP_CONST_ONHIT_CASTSPELL_ONHITRUINARMORBEBILITH = 132;
        public const int IP_CONST_ONHIT_CASTSPELL_ONHITDEMILICHTOUCH = 133;
        public const int IP_CONST_ONHIT_CASTSPELL_ONHITDRACOLICHTOUCH = 134;
        public const int IP_CONST_ONHIT_CASTSPELL_INTELLIGENT_WEAPON_ONHIT = 135;
        public const int IP_CONST_ONHIT_CASTSPELL_PARALYZE_2 = 136;
        public const int IP_CONST_ONHIT_CASTSPELL_DEAFENING_CLNG = 137;
        public const int IP_CONST_ONHIT_CASTSPELL_KNOCKDOWN = 138;
        public const int IP_CONST_ONHIT_CASTSPELL_FREEZE = 139;
        public const int IP_CONST_ONHIT_CASTSPELL_COMBUST = 140;
        public const int IP_CONST_POISON_1D2_STRDAMAGE = 0;
        public const int IP_CONST_POISON_1D2_DEXDAMAGE = 1;
        public const int IP_CONST_POISON_1D2_CONDAMAGE = 2;
        public const int IP_CONST_POISON_1D2_INTDAMAGE = 3;
        public const int IP_CONST_POISON_1D2_WISDAMAGE = 4;
        public const int IP_CONST_POISON_1D2_CHADAMAGE = 5;
        public const int IP_CONST_QUALITY_UNKOWN = 0;
        public const int IP_CONST_QUALITY_DESTROYED = 1;
        public const int IP_CONST_QUALITY_RUINED = 2;
        public const int IP_CONST_QUALITY_VERY_POOR = 3;
        public const int IP_CONST_QUALITY_POOR = 4;
        public const int IP_CONST_QUALITY_BELOW_AVERAGE = 5;
        public const int IP_CONST_QUALITY_AVERAGE = 6;
        public const int IP_CONST_QUALITY_ABOVE_AVERAGE = 7;
        public const int IP_CONST_QUALITY_GOOD = 8;
        public const int IP_CONST_QUALITY_VERY_GOOD = 9;
        public const int IP_CONST_QUALITY_EXCELLENT = 10;
        public const int IP_CONST_QUALITY_MASTERWORK = 11;
        public const int IP_CONST_QUALITY_GOD_LIKE = 12;
        public const int IP_CONST_QUALITY_RAW = 13;
        public const int IP_CONST_QUALITY_CUT = 14;
        public const int IP_CONST_QUALITY_POLISHED = 15;
        public const int IP_CONST_CONTAINERWEIGHTRED_20_PERCENT = 1;
        public const int IP_CONST_CONTAINERWEIGHTRED_40_PERCENT = 2;
        public const int IP_CONST_CONTAINERWEIGHTRED_60_PERCENT = 3;
        public const int IP_CONST_CONTAINERWEIGHTRED_80_PERCENT = 4;
        public const int IP_CONST_CONTAINERWEIGHTRED_100_PERCENT = 5;
        public const int IP_CONST_DAMAGERESIST_5 = 1;
        public const int IP_CONST_DAMAGERESIST_10 = 2;
        public const int IP_CONST_DAMAGERESIST_15 = 3;
        public const int IP_CONST_DAMAGERESIST_20 = 4;
        public const int IP_CONST_DAMAGERESIST_25 = 5;
        public const int IP_CONST_DAMAGERESIST_30 = 6;
        public const int IP_CONST_DAMAGERESIST_35 = 7;
        public const int IP_CONST_DAMAGERESIST_40 = 8;
        public const int IP_CONST_DAMAGERESIST_45 = 9;
        public const int IP_CONST_DAMAGERESIST_50 = 10;
        public const int IP_CONST_SAVEVS_ACID = 1;
        public const int IP_CONST_SAVEVS_COLD = 3;
        public const int IP_CONST_SAVEVS_DEATH = 4;
        public const int IP_CONST_SAVEVS_DISEASE = 5;
        public const int IP_CONST_SAVEVS_DIVINE = 6;
        public const int IP_CONST_SAVEVS_ELECTRICAL = 7;
        public const int IP_CONST_SAVEVS_FEAR = 8;
        public const int IP_CONST_SAVEVS_FIRE = 9;
        public const int IP_CONST_SAVEVS_MINDAFFECTING = 11;
        public const int IP_CONST_SAVEVS_NEGATIVE = 12;
        public const int IP_CONST_SAVEVS_POISON = 13;
        public const int IP_CONST_SAVEVS_POSITIVE = 14;
        public const int IP_CONST_SAVEVS_SONIC = 15;
        public const int IP_CONST_SAVEVS_UNIVERSAL = 0;
        public const int IP_CONST_SAVEBASETYPE_FORTITUDE = 1;
        public const int IP_CONST_SAVEBASETYPE_WILL = 2;
        public const int IP_CONST_SAVEBASETYPE_REFLEX = 3;
        public const int IP_CONST_DAMAGESOAK_5_HP = 1;
        public const int IP_CONST_DAMAGESOAK_10_HP = 2;
        public const int IP_CONST_DAMAGESOAK_15_HP = 3;
        public const int IP_CONST_DAMAGESOAK_20_HP = 4;
        public const int IP_CONST_DAMAGESOAK_25_HP = 5;
        public const int IP_CONST_DAMAGESOAK_30_HP = 6;
        public const int IP_CONST_DAMAGESOAK_35_HP = 7;
        public const int IP_CONST_DAMAGESOAK_40_HP = 8;
        public const int IP_CONST_DAMAGESOAK_45_HP = 9;
        public const int IP_CONST_DAMAGESOAK_50_HP = 10;
        public const int IP_CONST_DAMAGEREDUCTION_1 = 0;
        public const int IP_CONST_DAMAGEREDUCTION_2 = 1;
        public const int IP_CONST_DAMAGEREDUCTION_3 = 2;
        public const int IP_CONST_DAMAGEREDUCTION_4 = 3;
        public const int IP_CONST_DAMAGEREDUCTION_5 = 4;
        public const int IP_CONST_DAMAGEREDUCTION_6 = 5;
        public const int IP_CONST_DAMAGEREDUCTION_7 = 6;
        public const int IP_CONST_DAMAGEREDUCTION_8 = 7;
        public const int IP_CONST_DAMAGEREDUCTION_9 = 8;
        public const int IP_CONST_DAMAGEREDUCTION_10 = 9;
        public const int IP_CONST_DAMAGEREDUCTION_11 = 10;
        public const int IP_CONST_DAMAGEREDUCTION_12 = 11;
        public const int IP_CONST_DAMAGEREDUCTION_13 = 12;
        public const int IP_CONST_DAMAGEREDUCTION_14 = 13;
        public const int IP_CONST_DAMAGEREDUCTION_15 = 14;
        public const int IP_CONST_DAMAGEREDUCTION_16 = 15;
        public const int IP_CONST_DAMAGEREDUCTION_17 = 16;
        public const int IP_CONST_DAMAGEREDUCTION_18 = 17;
        public const int IP_CONST_DAMAGEREDUCTION_19 = 18;
        public const int IP_CONST_DAMAGEREDUCTION_20 = 19;
        public const int IP_CONST_IMMUNITYSPELL_ACID_FOG = 0;
        public const int IP_CONST_IMMUNITYSPELL_AID = 1;
        public const int IP_CONST_IMMUNITYSPELL_BARKSKIN = 2;
        public const int IP_CONST_IMMUNITYSPELL_BESTOW_CURSE = 3;
        public const int IP_CONST_IMMUNITYSPELL_BLINDNESS_AND_DEAFNESS = 6;
        public const int IP_CONST_IMMUNITYSPELL_BURNING_HANDS = 8;
        public const int IP_CONST_IMMUNITYSPELL_CALL_LIGHTNING = 9;
        public const int IP_CONST_IMMUNITYSPELL_CHAIN_LIGHTNING = 12;
        public const int IP_CONST_IMMUNITYSPELL_CHARM_MONSTER = 13;
        public const int IP_CONST_IMMUNITYSPELL_CHARM_PERSON = 14;
        public const int IP_CONST_IMMUNITYSPELL_CHARM_PERSON_OR_ANIMAL = 15;
        public const int IP_CONST_IMMUNITYSPELL_CIRCLE_OF_DEATH = 16;
        public const int IP_CONST_IMMUNITYSPELL_CIRCLE_OF_DOOM = 17;
        public const int IP_CONST_IMMUNITYSPELL_CLOUDKILL = 21;
        public const int IP_CONST_IMMUNITYSPELL_COLOR_SPRAY = 22;
        public const int IP_CONST_IMMUNITYSPELL_CONE_OF_COLD = 23;
        public const int IP_CONST_IMMUNITYSPELL_CONFUSION = 24;
        public const int IP_CONST_IMMUNITYSPELL_CONTAGION = 25;
        public const int IP_CONST_IMMUNITYSPELL_CONTROL_UNDEAD = 26;
        public const int IP_CONST_IMMUNITYSPELL_CURE_CRITICAL_WOUNDS = 27;
        public const int IP_CONST_IMMUNITYSPELL_CURE_LIGHT_WOUNDS = 28;
        public const int IP_CONST_IMMUNITYSPELL_CURE_MINOR_WOUNDS = 29;
        public const int IP_CONST_IMMUNITYSPELL_CURE_MODERATE_WOUNDS = 30;
        public const int IP_CONST_IMMUNITYSPELL_CURE_SERIOUS_WOUNDS = 31;
        public const int IP_CONST_IMMUNITYSPELL_DARKNESS = 32;
        public const int IP_CONST_IMMUNITYSPELL_DAZE = 33;
        public const int IP_CONST_IMMUNITYSPELL_DEATH_WARD = 34;
        public const int IP_CONST_IMMUNITYSPELL_DELAYED_BLAST_FIREBALL = 35;
        public const int IP_CONST_IMMUNITYSPELL_DISMISSAL = 36;
        public const int IP_CONST_IMMUNITYSPELL_DISPEL_MAGIC = 37;
        public const int IP_CONST_IMMUNITYSPELL_DOMINATE_ANIMAL = 39;
        public const int IP_CONST_IMMUNITYSPELL_DOMINATE_MONSTER = 40;
        public const int IP_CONST_IMMUNITYSPELL_DOMINATE_PERSON = 41;
        public const int IP_CONST_IMMUNITYSPELL_DOOM = 42;
        public const int IP_CONST_IMMUNITYSPELL_ENERGY_DRAIN = 46;
        public const int IP_CONST_IMMUNITYSPELL_ENERVATION = 47;
        public const int IP_CONST_IMMUNITYSPELL_ENTANGLE = 48;
        public const int IP_CONST_IMMUNITYSPELL_FEAR = 49;
        public const int IP_CONST_IMMUNITYSPELL_FEEBLEMIND = 50;
        public const int IP_CONST_IMMUNITYSPELL_FINGER_OF_DEATH = 51;
        public const int IP_CONST_IMMUNITYSPELL_FIRE_STORM = 52;
        public const int IP_CONST_IMMUNITYSPELL_FIREBALL = 53;
        public const int IP_CONST_IMMUNITYSPELL_FLAME_ARROW = 54;
        public const int IP_CONST_IMMUNITYSPELL_FLAME_LASH = 55;
        public const int IP_CONST_IMMUNITYSPELL_FLAME_STRIKE = 56;
        public const int IP_CONST_IMMUNITYSPELL_FREEDOM_OF_MOVEMENT = 57;
        public const int IP_CONST_IMMUNITYSPELL_GREASE = 59;
        public const int IP_CONST_IMMUNITYSPELL_GREATER_DISPELLING = 60;
        public const int IP_CONST_IMMUNITYSPELL_GREATER_PLANAR_BINDING = 62;
        public const int IP_CONST_IMMUNITYSPELL_GREATER_SHADOW_CONJURATION = 64;
        public const int IP_CONST_IMMUNITYSPELL_GREATER_SPELL_BREACH = 65;
        public const int IP_CONST_IMMUNITYSPELL_HAMMER_OF_THE_GODS = 68;
        public const int IP_CONST_IMMUNITYSPELL_HARM = 69;
        public const int IP_CONST_IMMUNITYSPELL_HEAL = 71;
        public const int IP_CONST_IMMUNITYSPELL_HEALING_CIRCLE = 72;
        public const int IP_CONST_IMMUNITYSPELL_HOLD_ANIMAL = 73;
        public const int IP_CONST_IMMUNITYSPELL_HOLD_MONSTER = 74;
        public const int IP_CONST_IMMUNITYSPELL_HOLD_PERSON = 75;
        public const int IP_CONST_IMMUNITYSPELL_IMPLOSION = 78;
        public const int IP_CONST_IMMUNITYSPELL_IMPROVED_INVISIBILITY = 79;
        public const int IP_CONST_IMMUNITYSPELL_INCENDIARY_CLOUD = 80;
        public const int IP_CONST_IMMUNITYSPELL_INVISIBILITY_PURGE = 82;
        public const int IP_CONST_IMMUNITYSPELL_LESSER_DISPEL = 84;
        public const int IP_CONST_IMMUNITYSPELL_LESSER_PLANAR_BINDING = 86;
        public const int IP_CONST_IMMUNITYSPELL_LESSER_SPELL_BREACH = 88;
        public const int IP_CONST_IMMUNITYSPELL_LIGHTNING_BOLT = 91;
        public const int IP_CONST_IMMUNITYSPELL_MAGIC_MISSILE = 97;
        public const int IP_CONST_IMMUNITYSPELL_MASS_BLINDNESS_AND_DEAFNESS = 100;
        public const int IP_CONST_IMMUNITYSPELL_MASS_CHARM = 101;
        public const int IP_CONST_IMMUNITYSPELL_MASS_HEAL = 104;
        public const int IP_CONST_IMMUNITYSPELL_MELFS_ACID_ARROW = 105;
        public const int IP_CONST_IMMUNITYSPELL_METEOR_SWARM = 106;
        public const int IP_CONST_IMMUNITYSPELL_MIND_FOG = 108;
        public const int IP_CONST_IMMUNITYSPELL_MORDENKAINENS_DISJUNCTION = 112;
        public const int IP_CONST_IMMUNITYSPELL_PHANTASMAL_KILLER = 116;
        public const int IP_CONST_IMMUNITYSPELL_PLANAR_BINDING = 117;
        public const int IP_CONST_IMMUNITYSPELL_POISON = 118;
        public const int IP_CONST_IMMUNITYSPELL_POWER_WORD_KILL = 120;
        public const int IP_CONST_IMMUNITYSPELL_POWER_WORD_STUN = 121;
        public const int IP_CONST_IMMUNITYSPELL_PRISMATIC_SPRAY = 124;
        public const int IP_CONST_IMMUNITYSPELL_RAY_OF_ENFEEBLEMENT = 131;
        public const int IP_CONST_IMMUNITYSPELL_RAY_OF_FROST = 132;
        public const int IP_CONST_IMMUNITYSPELL_SCARE = 142;
        public const int IP_CONST_IMMUNITYSPELL_SEARING_LIGHT = 143;
        public const int IP_CONST_IMMUNITYSPELL_SHADES = 145;
        public const int IP_CONST_IMMUNITYSPELL_SHADOW_CONJURATION = 146;
        public const int IP_CONST_IMMUNITYSPELL_SILENCE = 150;
        public const int IP_CONST_IMMUNITYSPELL_SLAY_LIVING = 151;
        public const int IP_CONST_IMMUNITYSPELL_SLEEP = 152;
        public const int IP_CONST_IMMUNITYSPELL_SLOW = 153;
        public const int IP_CONST_IMMUNITYSPELL_SOUND_BURST = 154;
        public const int IP_CONST_IMMUNITYSPELL_STINKING_CLOUD = 158;
        public const int IP_CONST_IMMUNITYSPELL_STONESKIN = 159;
        public const int IP_CONST_IMMUNITYSPELL_STORM_OF_VENGEANCE = 160;
        public const int IP_CONST_IMMUNITYSPELL_SUNBEAM = 161;
        public const int IP_CONST_IMMUNITYSPELL_VIRTUE = 165;
        public const int IP_CONST_IMMUNITYSPELL_WAIL_OF_THE_BANSHEE = 166;
        public const int IP_CONST_IMMUNITYSPELL_WEB = 167;
        public const int IP_CONST_IMMUNITYSPELL_WEIRD = 168;
        public const int IP_CONST_IMMUNITYSPELL_WORD_OF_FAITH = 169;
        public const int IP_CONST_IMMUNITYSPELL_MAGIC_CIRCLE_AGAINST_ALIGNMENT = 171;
        public const int IP_CONST_IMMUNITYSPELL_EAGLE_SPLEDOR = 173;
        public const int IP_CONST_IMMUNITYSPELL_OWLS_WISDOM = 174;
        public const int IP_CONST_IMMUNITYSPELL_FOXS_CUNNING = 175;
        public const int IP_CONST_IMMUNITYSPELL_GREATER_EAGLES_SPLENDOR = 176;
        public const int IP_CONST_IMMUNITYSPELL_GREATER_OWLS_WISDOM = 177;
        public const int IP_CONST_IMMUNITYSPELL_GREATER_FOXS_CUNNING = 178;
        public const int IP_CONST_IMMUNITYSPELL_GREATER_BULLS_STRENGTH = 179;
        public const int IP_CONST_IMMUNITYSPELL_GREATER_CATS_GRACE = 180;
        public const int IP_CONST_IMMUNITYSPELL_GREATER_ENDURANCE = 181;
        public const int IP_CONST_IMMUNITYSPELL_AURA_OF_VITALITY = 182;
        public const int IP_CONST_IMMUNITYSPELL_WAR_CRY = 183;
        public const int IP_CONST_IMMUNITYSPELL_REGENERATE = 184;
        public const int IP_CONST_IMMUNITYSPELL_EVARDS_BLACK_TENTACLES = 185;
        public const int IP_CONST_IMMUNITYSPELL_LEGEND_LORE = 186;
        public const int IP_CONST_IMMUNITYSPELL_FIND_TRAPS = 187;
        public const int IP_CONST_SPELLLEVEL_0 = 0;
        //  hmm are these necessary?
        public const int IP_CONST_SPELLLEVEL_1 = 1;
        public const int IP_CONST_SPELLLEVEL_2 = 2;
        public const int IP_CONST_SPELLLEVEL_3 = 3;
        public const int IP_CONST_SPELLLEVEL_4 = 4;
        public const int IP_CONST_SPELLLEVEL_5 = 5;
        public const int IP_CONST_SPELLLEVEL_6 = 6;
        public const int IP_CONST_SPELLLEVEL_7 = 7;
        public const int IP_CONST_SPELLLEVEL_8 = 8;
        public const int IP_CONST_SPELLLEVEL_9 = 9;
        public const int IP_CONST_CASTSPELL_ACID_FOG_11 = 0;
        public const int IP_CONST_CASTSPELL_ACID_SPLASH_1 = 355;
        public const int IP_CONST_CASTSPELL_ACTIVATE_ITEM = 359;
        public const int IP_CONST_CASTSPELL_AID_3 = 1;
        public const int IP_CONST_CASTSPELL_AMPLIFY_5 = 373;
        public const int IP_CONST_CASTSPELL_ANIMATE_DEAD_10 = 3;
        public const int IP_CONST_CASTSPELL_ANIMATE_DEAD_15 = 4;
        public const int IP_CONST_CASTSPELL_ANIMATE_DEAD_5 = 2;
        public const int IP_CONST_CASTSPELL_AURA_OF_VITALITY_13 = 321;
        public const int IP_CONST_CASTSPELL_AURA_VERSUS_ALIGNMENT_15 = 287;
        public const int IP_CONST_CASTSPELL_AURAOFGLORY_7 = 360;
        public const int IP_CONST_CASTSPELL_AWAKEN_9 = 303;
        public const int IP_CONST_CASTSPELL_BALAGARNSIRONHORN_7 = 367;
        public const int IP_CONST_CASTSPELL_BANE_5 = 380;
        public const int IP_CONST_CASTSPELL_BANISHMENT_15 = 361;
        public const int IP_CONST_CASTSPELL_BARKSKIN_12 = 7;
        public const int IP_CONST_CASTSPELL_BARKSKIN_3 = 5;
        public const int IP_CONST_CASTSPELL_BARKSKIN_6 = 6;
        public const int IP_CONST_CASTSPELL_BESTOW_CURSE_5 = 8;
        public const int IP_CONST_CASTSPELL_BIGBYS_CLENCHED_FIST_20 = 393;
        public const int IP_CONST_CASTSPELL_BIGBYS_CRUSHING_HAND_20 = 394;
        public const int IP_CONST_CASTSPELL_BIGBYS_FORCEFUL_HAND_15 = 391;
        public const int IP_CONST_CASTSPELL_BIGBYS_GRASPING_HAND_17 = 392;
        public const int IP_CONST_CASTSPELL_BIGBYS_INTERPOSING_HAND_15 = 390;
        public const int IP_CONST_CASTSPELL_BLADE_BARRIER_11 = 9;
        public const int IP_CONST_CASTSPELL_BLADE_BARRIER_15 = 10;
        public const int IP_CONST_CASTSPELL_BLESS_2 = 11;
        public const int IP_CONST_CASTSPELL_BLINDNESS_DEAFNESS_3 = 14;
        public const int IP_CONST_CASTSPELL_BLOOD_FRENZY_7 = 353;
        public const int IP_CONST_CASTSPELL_BOMBARDMENT_20 = 354;
        public const int IP_CONST_CASTSPELL_BULLS_STRENGTH_10 = 16;
        public const int IP_CONST_CASTSPELL_BULLS_STRENGTH_15 = 17;
        public const int IP_CONST_CASTSPELL_BULLS_STRENGTH_3 = 15;
        public const int IP_CONST_CASTSPELL_BURNING_HANDS_2 = 18;
        public const int IP_CONST_CASTSPELL_BURNING_HANDS_5 = 19;
        public const int IP_CONST_CASTSPELL_CALL_LIGHTNING_10 = 21;
        public const int IP_CONST_CASTSPELL_CALL_LIGHTNING_5 = 20;
        public const int IP_CONST_CASTSPELL_CAMOFLAGE_5 = 352;
        public const int IP_CONST_CASTSPELL_CATS_GRACE_10 = 26;
        public const int IP_CONST_CASTSPELL_CATS_GRACE_15 = 27;
        public const int IP_CONST_CASTSPELL_CATS_GRACE_3 = 25;
        public const int IP_CONST_CASTSPELL_CHAIN_LIGHTNING_11 = 28;
        public const int IP_CONST_CASTSPELL_CHAIN_LIGHTNING_15 = 29;
        public const int IP_CONST_CASTSPELL_CHAIN_LIGHTNING_20 = 30;
        public const int IP_CONST_CASTSPELL_CHARM_MONSTER_10 = 32;
        public const int IP_CONST_CASTSPELL_CHARM_MONSTER_5 = 31;
        public const int IP_CONST_CASTSPELL_CHARM_PERSON_10 = 34;
        public const int IP_CONST_CASTSPELL_CHARM_PERSON_2 = 33;
        public const int IP_CONST_CASTSPELL_CHARM_PERSON_OR_ANIMAL_10 = 36;
        public const int IP_CONST_CASTSPELL_CHARM_PERSON_OR_ANIMAL_3 = 35;
        public const int IP_CONST_CASTSPELL_CIRCLE_OF_DEATH_11 = 37;
        public const int IP_CONST_CASTSPELL_CIRCLE_OF_DEATH_15 = 38;
        public const int IP_CONST_CASTSPELL_CIRCLE_OF_DEATH_20 = 39;
        public const int IP_CONST_CASTSPELL_CIRCLE_OF_DOOM_15 = 41;
        public const int IP_CONST_CASTSPELL_CIRCLE_OF_DOOM_20 = 42;
        public const int IP_CONST_CASTSPELL_CIRCLE_OF_DOOM_9 = 40;
        public const int IP_CONST_CASTSPELL_CLAIRAUDIENCE_CLAIRVOYANCE_10 = 44;
        public const int IP_CONST_CASTSPELL_CLAIRAUDIENCE_CLAIRVOYANCE_15 = 45;
        public const int IP_CONST_CASTSPELL_CLAIRAUDIENCE_CLAIRVOYANCE_5 = 43;
        public const int IP_CONST_CASTSPELL_CLARITY_3 = 46;
        public const int IP_CONST_CASTSPELL_CLOUDKILL_9 = 48;
        public const int IP_CONST_CASTSPELL_COLOR_SPRAY_2 = 49;
        public const int IP_CONST_CASTSPELL_CONE_OF_COLD_15 = 51;
        public const int IP_CONST_CASTSPELL_CONE_OF_COLD_9 = 50;
        public const int IP_CONST_CASTSPELL_CONFUSION_10 = 53;
        public const int IP_CONST_CASTSPELL_CONFUSION_5 = 52;
        public const int IP_CONST_CASTSPELL_CONTAGION_5 = 54;
        public const int IP_CONST_CASTSPELL_CONTINUAL_FLAME_7 = 350;
        public const int IP_CONST_CASTSPELL_CONTROL_UNDEAD_13 = 55;
        public const int IP_CONST_CASTSPELL_CONTROL_UNDEAD_20 = 56;
        public const int IP_CONST_CASTSPELL_CREATE_GREATER_UNDEAD_15 = 57;
        public const int IP_CONST_CASTSPELL_CREATE_GREATER_UNDEAD_16 = 58;
        public const int IP_CONST_CASTSPELL_CREATE_GREATER_UNDEAD_18 = 59;
        public const int IP_CONST_CASTSPELL_CREATE_UNDEAD_11 = 60;
        public const int IP_CONST_CASTSPELL_CREATE_UNDEAD_14 = 61;
        public const int IP_CONST_CASTSPELL_CREATE_UNDEAD_16 = 62;
        public const int IP_CONST_CASTSPELL_CREEPING_DOOM_13 = 304;
        public const int IP_CONST_CASTSPELL_CURE_CRITICAL_WOUNDS_12 = 64;
        public const int IP_CONST_CASTSPELL_CURE_CRITICAL_WOUNDS_15 = 65;
        public const int IP_CONST_CASTSPELL_CURE_CRITICAL_WOUNDS_7 = 63;
        public const int IP_CONST_CASTSPELL_CURE_LIGHT_WOUNDS_2 = 66;
        public const int IP_CONST_CASTSPELL_CURE_LIGHT_WOUNDS_5 = 67;
        public const int IP_CONST_CASTSPELL_CURE_MINOR_WOUNDS_1 = 68;
        public const int IP_CONST_CASTSPELL_CURE_MODERATE_WOUNDS_10 = 71;
        public const int IP_CONST_CASTSPELL_CURE_MODERATE_WOUNDS_3 = 69;
        public const int IP_CONST_CASTSPELL_CURE_MODERATE_WOUNDS_6 = 70;
        public const int IP_CONST_CASTSPELL_CURE_SERIOUS_WOUNDS_10 = 73;
        public const int IP_CONST_CASTSPELL_CURE_SERIOUS_WOUNDS_5 = 72;
        public const int IP_CONST_CASTSPELL_DARKNESS_3 = 75;
        public const int IP_CONST_CASTSPELL_DARKVISION_3 = 305;
        public const int IP_CONST_CASTSPELL_DARKVISION_6 = 306;
        public const int IP_CONST_CASTSPELL_DAZE_1 = 76;
        public const int IP_CONST_CASTSPELL_DEATH_WARD_7 = 77;
        public const int IP_CONST_CASTSPELL_DELAYED_BLAST_FIREBALL_13 = 78;
        public const int IP_CONST_CASTSPELL_DELAYED_BLAST_FIREBALL_15 = 79;
        public const int IP_CONST_CASTSPELL_DELAYED_BLAST_FIREBALL_20 = 80;
        public const int IP_CONST_CASTSPELL_DESTRUCTION_13 = 307;
        public const int IP_CONST_CASTSPELL_DIRGE_15 = 376;
        public const int IP_CONST_CASTSPELL_DISMISSAL_12 = 82;
        public const int IP_CONST_CASTSPELL_DISMISSAL_18 = 83;
        public const int IP_CONST_CASTSPELL_DISMISSAL_7 = 81;
        public const int IP_CONST_CASTSPELL_DISPEL_MAGIC_10 = 85;
        public const int IP_CONST_CASTSPELL_DISPEL_MAGIC_5 = 84;
        public const int IP_CONST_CASTSPELL_DISPLACEMENT_9 = 389;
        public const int IP_CONST_CASTSPELL_DIVINE_FAVOR_5 = 345;
        public const int IP_CONST_CASTSPELL_DIVINE_MIGHT_5 = 395;
        public const int IP_CONST_CASTSPELL_DIVINE_POWER_7 = 86;
        public const int IP_CONST_CASTSPELL_DIVINE_SHIELD_5 = 396;
        public const int IP_CONST_CASTSPELL_DOMINATE_ANIMAL_5 = 87;
        public const int IP_CONST_CASTSPELL_DOMINATE_MONSTER_17 = 88;
        public const int IP_CONST_CASTSPELL_DOMINATE_PERSON_7 = 89;
        public const int IP_CONST_CASTSPELL_DOOM_2 = 90;
        public const int IP_CONST_CASTSPELL_DOOM_5 = 91;
        public const int IP_CONST_CASTSPELL_DRAGON_BREATH_ACID_10 = 400;
        public const int IP_CONST_CASTSPELL_DRAGON_BREATH_COLD_10 = 401;
        public const int IP_CONST_CASTSPELL_DRAGON_BREATH_FEAR_10 = 402;
        public const int IP_CONST_CASTSPELL_DRAGON_BREATH_FIRE_10 = 403;
        public const int IP_CONST_CASTSPELL_DRAGON_BREATH_GAS_10 = 404;
        public const int IP_CONST_CASTSPELL_DRAGON_BREATH_LIGHTNING_10 = 405;
        public const int IP_CONST_CASTSPELL_DRAGON_BREATH_PARALYZE_10 = 406;
        public const int IP_CONST_CASTSPELL_DRAGON_BREATH_SLEEP_10 = 407;
        public const int IP_CONST_CASTSPELL_DRAGON_BREATH_SLOW_10 = 408;
        public const int IP_CONST_CASTSPELL_DRAGON_BREATH_WEAKEN_10 = 409;
        public const int IP_CONST_CASTSPELL_DROWN_15 = 368;
        public const int IP_CONST_CASTSPELL_EAGLE_SPLEDOR_10 = 289;
        public const int IP_CONST_CASTSPELL_EAGLE_SPLEDOR_15 = 290;
        public const int IP_CONST_CASTSPELL_EAGLE_SPLEDOR_3 = 288;
        public const int IP_CONST_CASTSPELL_EARTHQUAKE_20 = 357;
        public const int IP_CONST_CASTSPELL_ELECTRIC_JOLT_1 = 370;
        public const int IP_CONST_CASTSPELL_ELEMENTAL_SHIELD_12 = 93;
        public const int IP_CONST_CASTSPELL_ELEMENTAL_SHIELD_7 = 92;
        public const int IP_CONST_CASTSPELL_ELEMENTAL_SWARM_17 = 94;
        public const int IP_CONST_CASTSPELL_ENDURANCE_10 = 96;
        public const int IP_CONST_CASTSPELL_ENDURANCE_15 = 97;
        public const int IP_CONST_CASTSPELL_ENDURANCE_3 = 95;
        public const int IP_CONST_CASTSPELL_ENDURE_ELEMENTS_2 = 98;
        public const int IP_CONST_CASTSPELL_ENERGY_BUFFER_11 = 311;
        public const int IP_CONST_CASTSPELL_ENERGY_BUFFER_15 = 312;
        public const int IP_CONST_CASTSPELL_ENERGY_BUFFER_20 = 313;
        public const int IP_CONST_CASTSPELL_ENERGY_DRAIN_17 = 99;
        public const int IP_CONST_CASTSPELL_ENERVATION_7 = 100;
        public const int IP_CONST_CASTSPELL_ENTANGLE_2 = 101;
        public const int IP_CONST_CASTSPELL_ENTANGLE_5 = 102;
        public const int IP_CONST_CASTSPELL_ENTROPIC_SHIELD_5 = 349;
        public const int IP_CONST_CASTSPELL_ETHEREAL_VISAGE_15 = 196;
        public const int IP_CONST_CASTSPELL_ETHEREAL_VISAGE_9 = 195;
        public const int IP_CONST_CASTSPELL_ETHEREALNESS_18 = 374;
        public const int IP_CONST_CASTSPELL_EVARDS_BLACK_TENTACLES_15 = 325;
        public const int IP_CONST_CASTSPELL_EVARDS_BLACK_TENTACLES_7 = 324;
        public const int IP_CONST_CASTSPELL_EXPEDITIOUS_RETREAT_5 = 387;
        public const int IP_CONST_CASTSPELL_FEAR_5 = 103;
        public const int IP_CONST_CASTSPELL_FEEBLEMIND_9 = 104;
        public const int IP_CONST_CASTSPELL_FIND_TRAPS_3 = 327;
        public const int IP_CONST_CASTSPELL_FINGER_OF_DEATH_13 = 105;
        public const int IP_CONST_CASTSPELL_FIRE_STORM_13 = 106;
        public const int IP_CONST_CASTSPELL_FIRE_STORM_18 = 107;
        public const int IP_CONST_CASTSPELL_FIREBALL_10 = 109;
        public const int IP_CONST_CASTSPELL_FIREBALL_5 = 108;
        public const int IP_CONST_CASTSPELL_FIREBRAND_15 = 371;
        public const int IP_CONST_CASTSPELL_FLAME_ARROW_12 = 111;
        public const int IP_CONST_CASTSPELL_FLAME_ARROW_18 = 112;
        public const int IP_CONST_CASTSPELL_FLAME_ARROW_5 = 110;
        public const int IP_CONST_CASTSPELL_FLAME_LASH_10 = 114;
        public const int IP_CONST_CASTSPELL_FLAME_LASH_3 = 113;
        public const int IP_CONST_CASTSPELL_FLAME_STRIKE_12 = 116;
        public const int IP_CONST_CASTSPELL_FLAME_STRIKE_18 = 117;
        public const int IP_CONST_CASTSPELL_FLAME_STRIKE_7 = 115;
        public const int IP_CONST_CASTSPELL_FLARE_1 = 347;
        public const int IP_CONST_CASTSPELL_FLESH_TO_STONE_5 = 398;
        public const int IP_CONST_CASTSPELL_FOXS_CUNNING_10 = 295;
        public const int IP_CONST_CASTSPELL_FOXS_CUNNING_15 = 296;
        public const int IP_CONST_CASTSPELL_FOXS_CUNNING_3 = 294;
        public const int IP_CONST_CASTSPELL_FREEDOM_OF_MOVEMENT_7 = 118;
        public const int IP_CONST_CASTSPELL_GATE_17 = 119;
        public const int IP_CONST_CASTSPELL_GHOSTLY_VISAGE_15 = 194;
        public const int IP_CONST_CASTSPELL_GHOSTLY_VISAGE_3 = 192;
        public const int IP_CONST_CASTSPELL_GHOSTLY_VISAGE_9 = 193;
        public const int IP_CONST_CASTSPELL_GHOUL_TOUCH_3 = 120;
        public const int IP_CONST_CASTSPELL_GLOBE_OF_INVULNERABILITY_11 = 121;
        public const int IP_CONST_CASTSPELL_GREASE_2 = 122;
        public const int IP_CONST_CASTSPELL_GREATER_BULLS_STRENGTH_11 = 300;
        public const int IP_CONST_CASTSPELL_GREATER_CATS_GRACE_11 = 301;
        public const int IP_CONST_CASTSPELL_GREATER_DISPELLING_15 = 124;
        public const int IP_CONST_CASTSPELL_GREATER_DISPELLING_7 = 123;
        public const int IP_CONST_CASTSPELL_GREATER_EAGLES_SPLENDOR_11 = 297;
        public const int IP_CONST_CASTSPELL_GREATER_ENDURANCE_11 = 302;
        public const int IP_CONST_CASTSPELL_GREATER_FOXS_CUNNING_11 = 299;
        public const int IP_CONST_CASTSPELL_GREATER_MAGIC_FANG_9 = 384;
        public const int IP_CONST_CASTSPELL_GREATER_OWLS_WISDOM_11 = 298;
        public const int IP_CONST_CASTSPELL_GREATER_PLANAR_BINDING_15 = 126;
        public const int IP_CONST_CASTSPELL_GREATER_RESTORATION_13 = 127;
        public const int IP_CONST_CASTSPELL_GREATER_SHADOW_CONJURATION_9 = 128;
        public const int IP_CONST_CASTSPELL_GREATER_SPELL_BREACH_11 = 129;
        public const int IP_CONST_CASTSPELL_GREATER_SPELL_MANTLE_17 = 130;
        public const int IP_CONST_CASTSPELL_GREATER_STONESKIN_11 = 131;
        public const int IP_CONST_CASTSPELL_GRENADE_ACID_1 = 341;
        public const int IP_CONST_CASTSPELL_GRENADE_CALTROPS_1 = 343;
        public const int IP_CONST_CASTSPELL_GRENADE_CHICKEN_1 = 342;
        public const int IP_CONST_CASTSPELL_GRENADE_CHOKING_1 = 339;
        public const int IP_CONST_CASTSPELL_GRENADE_FIRE_1 = 336;
        public const int IP_CONST_CASTSPELL_GRENADE_HOLY_1 = 338;
        public const int IP_CONST_CASTSPELL_GRENADE_TANGLE_1 = 337;
        public const int IP_CONST_CASTSPELL_GRENADE_THUNDERSTONE_1 = 340;
        public const int IP_CONST_CASTSPELL_GUST_OF_WIND_10 = 410;
        public const int IP_CONST_CASTSPELL_HAMMER_OF_THE_GODS_12 = 134;
        public const int IP_CONST_CASTSPELL_HAMMER_OF_THE_GODS_7 = 133;
        public const int IP_CONST_CASTSPELL_HARM_11 = 136;
        public const int IP_CONST_CASTSPELL_HASTE_10 = 138;
        public const int IP_CONST_CASTSPELL_HASTE_5 = 137;
        public const int IP_CONST_CASTSPELL_HEAL_11 = 139;
        public const int IP_CONST_CASTSPELL_HEALING_CIRCLE_16 = 141;
        public const int IP_CONST_CASTSPELL_HEALING_CIRCLE_9 = 140;
        public const int IP_CONST_CASTSPELL_HOLD_ANIMAL_3 = 142;
        public const int IP_CONST_CASTSPELL_HOLD_MONSTER_7 = 143;
        public const int IP_CONST_CASTSPELL_HOLD_PERSON_3 = 144;
        public const int IP_CONST_CASTSPELL_HORRID_WILTING_15 = 308;
        public const int IP_CONST_CASTSPELL_HORRID_WILTING_20 = 309;
        public const int IP_CONST_CASTSPELL_ICE_STORM_9 = 310;
        public const int IP_CONST_CASTSPELL_IDENTIFY_3 = 147;
        public const int IP_CONST_CASTSPELL_IMPLOSION_17 = 148;
        public const int IP_CONST_CASTSPELL_IMPROVED_INVISIBILITY_7 = 149;
        public const int IP_CONST_CASTSPELL_INCENDIARY_CLOUD_15 = 150;
        public const int IP_CONST_CASTSPELL_INFERNO_15 = 377;
        public const int IP_CONST_CASTSPELL_INFLICT_CRITICAL_WOUNDS_12 = 366;
        public const int IP_CONST_CASTSPELL_INFLICT_LIGHT_WOUNDS_5 = 363;
        public const int IP_CONST_CASTSPELL_INFLICT_MINOR_WOUNDS_1 = 362;
        public const int IP_CONST_CASTSPELL_INFLICT_MODERATE_WOUNDS_7 = 364;
        public const int IP_CONST_CASTSPELL_INFLICT_SERIOUS_WOUNDS_9 = 365;
        public const int IP_CONST_CASTSPELL_INVISIBILITY_3 = 151;
        public const int IP_CONST_CASTSPELL_INVISIBILITY_PURGE_5 = 152;
        public const int IP_CONST_CASTSPELL_INVISIBILITY_SPHERE_5 = 153;
        public const int IP_CONST_CASTSPELL_ISAACS_GREATER_MISSILE_STORM_15 = 379;
        public const int IP_CONST_CASTSPELL_ISAACS_LESSER_MISSILE_STORM_13 = 378;
        public const int IP_CONST_CASTSPELL_KNOCK_3 = 154;
        public const int IP_CONST_CASTSPELL_LEGEND_LORE_5 = 326;
        public const int IP_CONST_CASTSPELL_LESSER_DISPEL_3 = 155;
        public const int IP_CONST_CASTSPELL_LESSER_DISPEL_5 = 156;
        public const int IP_CONST_CASTSPELL_LESSER_MIND_BLANK_9 = 157;
        public const int IP_CONST_CASTSPELL_LESSER_PLANAR_BINDING_9 = 158;
        public const int IP_CONST_CASTSPELL_LESSER_RESTORATION_3 = 159;
        public const int IP_CONST_CASTSPELL_LESSER_SPELL_BREACH_7 = 160;
        public const int IP_CONST_CASTSPELL_LESSER_SPELL_MANTLE_9 = 161;
        public const int IP_CONST_CASTSPELL_LIGHT_1 = 162;
        public const int IP_CONST_CASTSPELL_LIGHT_5 = 163;
        public const int IP_CONST_CASTSPELL_LIGHTNING_BOLT_10 = 165;
        public const int IP_CONST_CASTSPELL_LIGHTNING_BOLT_5 = 164;
        public const int IP_CONST_CASTSPELL_MAGE_ARMOR_2 = 167;
        public const int IP_CONST_CASTSPELL_MAGIC_CIRCLE_AGAINST_ALIGNMENT_5 = 286;
        public const int IP_CONST_CASTSPELL_MAGIC_FANG_5 = 383;
        public const int IP_CONST_CASTSPELL_MAGIC_MISSILE_3 = 172;
        public const int IP_CONST_CASTSPELL_MAGIC_MISSILE_5 = 173;
        public const int IP_CONST_CASTSPELL_MAGIC_MISSILE_9 = 174;
        public const int IP_CONST_CASTSPELL_MANIPULATE_PORTAL_STONE = 344;
        public const int IP_CONST_CASTSPELL_MASS_BLINDNESS_DEAFNESS_15 = 179;
        public const int IP_CONST_CASTSPELL_MASS_CAMOFLAGE_13 = 386;
        public const int IP_CONST_CASTSPELL_MASS_CHARM_15 = 180;
        public const int IP_CONST_CASTSPELL_MASS_HASTE_11 = 182;
        public const int IP_CONST_CASTSPELL_MASS_HEAL_15 = 183;
        public const int IP_CONST_CASTSPELL_MELFS_ACID_ARROW_3 = 184;
        public const int IP_CONST_CASTSPELL_MELFS_ACID_ARROW_6 = 185;
        public const int IP_CONST_CASTSPELL_MELFS_ACID_ARROW_9 = 186;
        public const int IP_CONST_CASTSPELL_METEOR_SWARM_17 = 187;
        public const int IP_CONST_CASTSPELL_MIND_BLANK_15 = 188;
        public const int IP_CONST_CASTSPELL_MIND_FOG_9 = 189;
        public const int IP_CONST_CASTSPELL_MINOR_GLOBE_OF_INVULNERABILITY_15 = 191;
        public const int IP_CONST_CASTSPELL_MINOR_GLOBE_OF_INVULNERABILITY_7 = 190;
        public const int IP_CONST_CASTSPELL_MORDENKAINENS_DISJUNCTION_17 = 197;
        public const int IP_CONST_CASTSPELL_MORDENKAINENS_SWORD_13 = 198;
        public const int IP_CONST_CASTSPELL_MORDENKAINENS_SWORD_18 = 199;
        public const int IP_CONST_CASTSPELL_NATURES_BALANCE_15 = 200;
        public const int IP_CONST_CASTSPELL_NEGATIVE_ENERGY_BURST_10 = 315;
        public const int IP_CONST_CASTSPELL_NEGATIVE_ENERGY_BURST_5 = 314;
        public const int IP_CONST_CASTSPELL_NEGATIVE_ENERGY_PROTECTION_10 = 202;
        public const int IP_CONST_CASTSPELL_NEGATIVE_ENERGY_PROTECTION_15 = 203;
        public const int IP_CONST_CASTSPELL_NEGATIVE_ENERGY_PROTECTION_5 = 201;
        public const int IP_CONST_CASTSPELL_NEGATIVE_ENERGY_RAY_1 = 316;
        public const int IP_CONST_CASTSPELL_NEGATIVE_ENERGY_RAY_3 = 317;
        public const int IP_CONST_CASTSPELL_NEGATIVE_ENERGY_RAY_5 = 318;
        public const int IP_CONST_CASTSPELL_NEGATIVE_ENERGY_RAY_7 = 319;
        public const int IP_CONST_CASTSPELL_NEGATIVE_ENERGY_RAY_9 = 320;
        public const int IP_CONST_CASTSPELL_NEUTRALIZE_POISON_5 = 204;
        public const int IP_CONST_CASTSPELL_ONE_WITH_THE_LAND_7 = 351;
        public const int IP_CONST_CASTSPELL_OWLS_INSIGHT_15 = 369;
        public const int IP_CONST_CASTSPELL_OWLS_WISDOM_10 = 292;
        public const int IP_CONST_CASTSPELL_OWLS_WISDOM_15 = 293;
        public const int IP_CONST_CASTSPELL_OWLS_WISDOM_3 = 291;
        public const int IP_CONST_CASTSPELL_PHANTASMAL_KILLER_7 = 205;
        public const int IP_CONST_CASTSPELL_PLANAR_ALLY_15 = 382;
        public const int IP_CONST_CASTSPELL_PLANAR_BINDING_11 = 206;
        public const int IP_CONST_CASTSPELL_POISON_5 = 207;
        public const int IP_CONST_CASTSPELL_POLYMORPH_SELF_7 = 208;
        public const int IP_CONST_CASTSPELL_POWER_WORD_KILL_17 = 209;
        public const int IP_CONST_CASTSPELL_POWER_WORD_STUN_13 = 210;
        public const int IP_CONST_CASTSPELL_PRAYER_5 = 211;
        public const int IP_CONST_CASTSPELL_PREMONITION_15 = 212;
        public const int IP_CONST_CASTSPELL_PRISMATIC_SPRAY_13 = 213;
        public const int IP_CONST_CASTSPELL_PROTECTION_FROM_ALIGNMENT_2 = 284;
        public const int IP_CONST_CASTSPELL_PROTECTION_FROM_ALIGNMENT_5 = 285;
        public const int IP_CONST_CASTSPELL_PROTECTION_FROM_ELEMENTS_10 = 217;
        public const int IP_CONST_CASTSPELL_PROTECTION_FROM_ELEMENTS_3 = 216;
        public const int IP_CONST_CASTSPELL_PROTECTION_FROM_SPELLS_13 = 224;
        public const int IP_CONST_CASTSPELL_PROTECTION_FROM_SPELLS_20 = 225;
        public const int IP_CONST_CASTSPELL_QUILLFIRE_8 = 356;
        public const int IP_CONST_CASTSPELL_RAISE_DEAD_9 = 226;
        public const int IP_CONST_CASTSPELL_RAY_OF_ENFEEBLEMENT_2 = 227;
        public const int IP_CONST_CASTSPELL_RAY_OF_FROST_1 = 228;
        public const int IP_CONST_CASTSPELL_REGENERATE_13 = 323;
        public const int IP_CONST_CASTSPELL_REMOVE_BLINDNESS_DEAFNESS_5 = 229;
        public const int IP_CONST_CASTSPELL_REMOVE_CURSE_5 = 230;
        public const int IP_CONST_CASTSPELL_REMOVE_DISEASE_5 = 231;
        public const int IP_CONST_CASTSPELL_REMOVE_FEAR_2 = 232;
        public const int IP_CONST_CASTSPELL_REMOVE_PARALYSIS_3 = 233;
        public const int IP_CONST_CASTSPELL_RESIST_ELEMENTS_10 = 235;
        public const int IP_CONST_CASTSPELL_RESIST_ELEMENTS_3 = 234;
        public const int IP_CONST_CASTSPELL_RESISTANCE_2 = 236;
        public const int IP_CONST_CASTSPELL_RESISTANCE_5 = 237;
        public const int IP_CONST_CASTSPELL_RESTORATION_7 = 238;
        public const int IP_CONST_CASTSPELL_RESURRECTION_13 = 239;
        public const int IP_CONST_CASTSPELL_ROGUES_CUNNING_3 = 328;
        public const int IP_CONST_CASTSPELL_SANCTUARY_2 = 240;
        public const int IP_CONST_CASTSPELL_SCARE_2 = 241;
        public const int IP_CONST_CASTSPELL_SEARING_LIGHT_5 = 242;
        public const int IP_CONST_CASTSPELL_SEE_INVISIBILITY_3 = 243;
        public const int IP_CONST_CASTSPELL_SHADES_11 = 244;
        public const int IP_CONST_CASTSPELL_SHADOW_CONJURATION_7 = 245;
        public const int IP_CONST_CASTSPELL_SHADOW_SHIELD_13 = 246;
        public const int IP_CONST_CASTSPELL_SHAPECHANGE_17 = 247;
        public const int IP_CONST_CASTSPELL_SHIELD_5 = 348;
        public const int IP_CONST_CASTSPELL_SHIELD_OF_FAITH_5 = 381;
        public const int IP_CONST_CASTSPELL_SILENCE_3 = 249;
        public const int IP_CONST_CASTSPELL_SLAY_LIVING_9 = 250;
        public const int IP_CONST_CASTSPELL_SLEEP_2 = 251;
        public const int IP_CONST_CASTSPELL_SLEEP_5 = 252;
        public const int IP_CONST_CASTSPELL_SLOW_5 = 253;
        public const int IP_CONST_CASTSPELL_SOUND_BURST_3 = 254;
        public const int IP_CONST_CASTSPELL_SPECIAL_ALCOHOL_BEER = 330;
        public const int IP_CONST_CASTSPELL_SPECIAL_ALCOHOL_SPIRITS = 332;
        public const int IP_CONST_CASTSPELL_SPECIAL_ALCOHOL_WINE = 331;
        public const int IP_CONST_CASTSPELL_SPECIAL_HERB_BELLADONNA = 333;
        public const int IP_CONST_CASTSPELL_SPECIAL_HERB_GARLIC = 334;
        public const int IP_CONST_CASTSPELL_SPELL_MANTLE_13 = 257;
        public const int IP_CONST_CASTSPELL_SPELL_RESISTANCE_15 = 256;
        public const int IP_CONST_CASTSPELL_SPELL_RESISTANCE_9 = 255;
        public const int IP_CONST_CASTSPELL_SPIKE_GROWTH_9 = 385;
        public const int IP_CONST_CASTSPELL_STINKING_CLOUD_5 = 259;
        public const int IP_CONST_CASTSPELL_STONE_TO_FLESH_5 = 399;
        public const int IP_CONST_CASTSPELL_STONESKIN_7 = 260;
        public const int IP_CONST_CASTSPELL_STORM_OF_VENGEANCE_17 = 261;
        public const int IP_CONST_CASTSPELL_SUMMON_CREATURE_I_2 = 262;
        public const int IP_CONST_CASTSPELL_SUMMON_CREATURE_I_5 = 263;
        public const int IP_CONST_CASTSPELL_SUMMON_CREATURE_II_3 = 264;
        public const int IP_CONST_CASTSPELL_SUMMON_CREATURE_III_5 = 265;
        public const int IP_CONST_CASTSPELL_SUMMON_CREATURE_IV_7 = 266;
        public const int IP_CONST_CASTSPELL_SUMMON_CREATURE_IX_17 = 267;
        public const int IP_CONST_CASTSPELL_SUMMON_CREATURE_V_9 = 268;
        public const int IP_CONST_CASTSPELL_SUMMON_CREATURE_VI_11 = 269;
        public const int IP_CONST_CASTSPELL_SUMMON_CREATURE_VII_13 = 270;
        public const int IP_CONST_CASTSPELL_SUMMON_CREATURE_VIII_15 = 271;
        public const int IP_CONST_CASTSPELL_SUNBEAM_13 = 272;
        public const int IP_CONST_CASTSPELL_SUNBURST_20 = 358;
        public const int IP_CONST_CASTSPELL_TASHAS_HIDEOUS_LAUGHTER_7 = 388;
        public const int IP_CONST_CASTSPELL_TENSERS_TRANSFORMATION_11 = 273;
        public const int IP_CONST_CASTSPELL_TIME_STOP_17 = 274;
        public const int IP_CONST_CASTSPELL_TRUE_SEEING_9 = 275;
        public const int IP_CONST_CASTSPELL_TRUE_STRIKE_5 = 346;
        public const int IP_CONST_CASTSPELL_UNDEATHS_ETERNAL_FOE_20 = 375;
        public const int IP_CONST_CASTSPELL_UNIQUE_POWER = 329;
        public const int IP_CONST_CASTSPELL_UNIQUE_POWER_SELF_ONLY = 335;
        public const int IP_CONST_CASTSPELL_VAMPIRIC_TOUCH_5 = 277;
        public const int IP_CONST_CASTSPELL_VIRTUE_1 = 278;
        public const int IP_CONST_CASTSPELL_WAIL_OF_THE_BANSHEE_17 = 279;
        public const int IP_CONST_CASTSPELL_WALL_OF_FIRE_9 = 280;
        public const int IP_CONST_CASTSPELL_WAR_CRY_7 = 322;
        public const int IP_CONST_CASTSPELL_WEB_3 = 281;
        public const int IP_CONST_CASTSPELL_WEIRD_17 = 282;
        public const int IP_CONST_CASTSPELL_WORD_OF_FAITH_13 = 283;
        public const int IP_CONST_CASTSPELL_WOUNDING_WHISPERS_9 = 372;
        public const int IP_CONST_SPELLSCHOOL_ABJURATION = 0;
        public const int IP_CONST_SPELLSCHOOL_CONJURATION = 1;
        public const int IP_CONST_SPELLSCHOOL_DIVINATION = 2;
        public const int IP_CONST_SPELLSCHOOL_ENCHANTMENT = 3;
        public const int IP_CONST_SPELLSCHOOL_EVOCATION = 4;
        public const int IP_CONST_SPELLSCHOOL_ILLUSION = 5;
        public const int IP_CONST_SPELLSCHOOL_NECROMANCY = 6;
        public const int IP_CONST_SPELLSCHOOL_TRANSMUTATION = 7;
        public const int IP_CONST_SPELLRESISTANCEBONUS_10 = 0;
        public const int IP_CONST_SPELLRESISTANCEBONUS_12 = 1;
        public const int IP_CONST_SPELLRESISTANCEBONUS_14 = 2;
        public const int IP_CONST_SPELLRESISTANCEBONUS_16 = 3;
        public const int IP_CONST_SPELLRESISTANCEBONUS_18 = 4;
        public const int IP_CONST_SPELLRESISTANCEBONUS_20 = 5;
        public const int IP_CONST_SPELLRESISTANCEBONUS_22 = 6;
        public const int IP_CONST_SPELLRESISTANCEBONUS_24 = 7;
        public const int IP_CONST_SPELLRESISTANCEBONUS_26 = 8;
        public const int IP_CONST_SPELLRESISTANCEBONUS_28 = 9;
        public const int IP_CONST_SPELLRESISTANCEBONUS_30 = 10;
        public const int IP_CONST_SPELLRESISTANCEBONUS_32 = 11;
        public const int IP_CONST_TRAPTYPE_SPIKE = 1;
        public const int IP_CONST_TRAPTYPE_HOLY = 2;
        public const int IP_CONST_TRAPTYPE_TANGLE = 3;
        public const int IP_CONST_TRAPTYPE_BLOBOFACID = 4;
        public const int IP_CONST_TRAPTYPE_FIRE = 5;
        public const int IP_CONST_TRAPTYPE_ELECTRICAL = 6;
        public const int IP_CONST_TRAPTYPE_GAS = 7;
        public const int IP_CONST_TRAPTYPE_FROST = 8;
        public const int IP_CONST_TRAPTYPE_ACID_SPLASH = 9;
        public const int IP_CONST_TRAPTYPE_SONIC = 10;
        public const int IP_CONST_TRAPTYPE_NEGATIVE = 11;
        public const int IP_CONST_TRAPSTRENGTH_MINOR = 0;
        public const int IP_CONST_TRAPSTRENGTH_AVERAGE = 1;
        public const int IP_CONST_TRAPSTRENGTH_STRONG = 2;
        public const int IP_CONST_TRAPSTRENGTH_DEADLY = 3;
        public const int IP_CONST_REDUCEDWEIGHT_80_PERCENT = 1;
        public const int IP_CONST_REDUCEDWEIGHT_60_PERCENT = 2;
        public const int IP_CONST_REDUCEDWEIGHT_40_PERCENT = 3;
        public const int IP_CONST_REDUCEDWEIGHT_20_PERCENT = 4;
        public const int IP_CONST_REDUCEDWEIGHT_10_PERCENT = 5;
        public const int IP_CONST_WEIGHTINCREASE_5_LBS = 0;
        public const int IP_CONST_WEIGHTINCREASE_10_LBS = 1;
        public const int IP_CONST_WEIGHTINCREASE_15_LBS = 2;
        public const int IP_CONST_WEIGHTINCREASE_30_LBS = 3;
        public const int IP_CONST_WEIGHTINCREASE_50_LBS = 4;
        public const int IP_CONST_WEIGHTINCREASE_100_LBS = 5;
        public const int IP_CONST_CLASS_BARBARIAN = 0;
        public const int IP_CONST_CLASS_BARD = 1;
        public const int IP_CONST_CLASS_CLERIC = 2;
        public const int IP_CONST_CLASS_DRUID = 3;
        public const int IP_CONST_CLASS_FIGHTER = 4;
        public const int IP_CONST_CLASS_MONK = 5;
        public const int IP_CONST_CLASS_PALADIN = 6;
        public const int IP_CONST_CLASS_RANGER = 7;
        public const int IP_CONST_CLASS_ROGUE = 8;
        public const int IP_CONST_CLASS_SORCERER = 9;
        public const int IP_CONST_CLASS_WIZARD = 10;
        public const int IP_CONST_ARCANE_SPELL_FAILURE_MINUS_50_PERCENT = 0;
        public const int IP_CONST_ARCANE_SPELL_FAILURE_MINUS_45_PERCENT = 1;
        public const int IP_CONST_ARCANE_SPELL_FAILURE_MINUS_40_PERCENT = 2;
        public const int IP_CONST_ARCANE_SPELL_FAILURE_MINUS_35_PERCENT = 3;
        public const int IP_CONST_ARCANE_SPELL_FAILURE_MINUS_30_PERCENT = 4;
        public const int IP_CONST_ARCANE_SPELL_FAILURE_MINUS_25_PERCENT = 5;
        public const int IP_CONST_ARCANE_SPELL_FAILURE_MINUS_20_PERCENT = 6;
        public const int IP_CONST_ARCANE_SPELL_FAILURE_MINUS_15_PERCENT = 7;
        public const int IP_CONST_ARCANE_SPELL_FAILURE_MINUS_10_PERCENT = 8;
        public const int IP_CONST_ARCANE_SPELL_FAILURE_MINUS_5_PERCENT = 9;
        public const int IP_CONST_ARCANE_SPELL_FAILURE_PLUS_5_PERCENT = 10;
        public const int IP_CONST_ARCANE_SPELL_FAILURE_PLUS_10_PERCENT = 11;
        public const int IP_CONST_ARCANE_SPELL_FAILURE_PLUS_15_PERCENT = 12;
        public const int IP_CONST_ARCANE_SPELL_FAILURE_PLUS_20_PERCENT = 13;
        public const int IP_CONST_ARCANE_SPELL_FAILURE_PLUS_25_PERCENT = 14;
        public const int IP_CONST_ARCANE_SPELL_FAILURE_PLUS_30_PERCENT = 15;
        public const int IP_CONST_ARCANE_SPELL_FAILURE_PLUS_35_PERCENT = 16;
        public const int IP_CONST_ARCANE_SPELL_FAILURE_PLUS_40_PERCENT = 17;
        public const int IP_CONST_ARCANE_SPELL_FAILURE_PLUS_45_PERCENT = 18;
        public const int IP_CONST_ARCANE_SPELL_FAILURE_PLUS_50_PERCENT = 19;
        public const int ACTION_MODE_DETECT = 0;
        public const int ACTION_MODE_STEALTH = 1;
        public const int ACTION_MODE_PARRY = 2;
        public const int ACTION_MODE_POWER_ATTACK = 3;
        public const int ACTION_MODE_IMPROVED_POWER_ATTACK = 4;
        public const int ACTION_MODE_COUNTERSPELL = 5;
        public const int ACTION_MODE_FLURRY_OF_BLOWS = 6;
        public const int ACTION_MODE_RAPID_SHOT = 7;
        public const int ACTION_MODE_EXPERTISE = 8;
        public const int ACTION_MODE_IMPROVED_EXPERTISE = 9;
        public const int ACTION_MODE_DEFENSIVE_CAST = 10;
        public const int ACTION_MODE_DIRTY_FIGHTING = 11;
        public const int ITEM_VISUAL_ACID = 0;
        public const int ITEM_VISUAL_COLD = 1;
        public const int ITEM_VISUAL_ELECTRICAL = 2;
        public const int ITEM_VISUAL_FIRE = 3;
        public const int ITEM_VISUAL_SONIC = 4;
        public const int ITEM_VISUAL_HOLY = 5;
        public const int ITEM_VISUAL_EVIL = 6;
        //  these constants must match those in the skyboxes.2da
        public const int SKYBOX_NONE = 0;
        public const int SKYBOX_GRASS_CLEAR = 1;
        public const int SKYBOX_GRASS_STORM = 2;
        public const int SKYBOX_DESERT_CLEAR = 3;
        public const int SKYBOX_WINTER_CLEAR = 4;
        public const int SKYBOX_ICY = 5;
        public const int FOG_TYPE_ALL = 0;
        public const int FOG_TYPE_SUN = 1;
        public const int FOG_TYPE_MOON = 2;
        public const int FOG_COLOR_RED = 16711680;
        public const int FOG_COLOR_RED_DARK = 6684672;
        public const int FOG_COLOR_GREEN = 65280;
        public const int FOG_COLOR_GREEN_DARK = 23112;
        public const int FOG_COLOR_BLUE = 255;
        public const int FOG_COLOR_BLUE_DARK = 102;
        public const int FOG_COLOR_BLACK = 0;
        public const int FOG_COLOR_WHITE = 16777215;
        public const int FOG_COLOR_GREY = 10066329;
        public const int FOG_COLOR_YELLOW = 16776960;
        public const int FOG_COLOR_YELLOW_DARK = 11184640;
        public const int FOG_COLOR_CYAN = 65535;
        public const int FOG_COLOR_MAGENTA = 16711935;
        public const int FOG_COLOR_ORANGE = 16750848;
        public const int FOG_COLOR_ORANGE_DARK = 13395456;
        public const int FOG_COLOR_BROWN = 10053120;
        public const int FOG_COLOR_BROWN_DARK = 6697728;
        //  these constants must match those in the AmbientSound.2da
        public const int AMBIENT_SOUND_NONE = 0;
        public const int AMBIENT_SOUND_MEN_WHISPER_INSIDE = 1;
        public const int AMBIENT_SOUND_WOMEN_WHISPER_INSIDE = 2;
        public const int AMBIENT_SOUND_PEOPLE_WHISPER_INSIDE = 3;
        public const int AMBIENT_SOUND_SMALL_GROUP_TALKS_INSIDE = 4;
        public const int AMBIENT_SOUND_MEDIUM_GROUP_TALKS_INSIDE = 5;
        public const int AMBIENT_SOUND_LARGE_GROUP_TALKS_INSIDE = 6;
        public const int AMBIENT_SOUND_COMMONER_TAVERN_TALK = 7;
        public const int AMBIENT_SOUND_NOBLE_TAVERN_TALK = 8;
        public const int AMBIENT_SOUND_CITY_SLUMS_DAY_CROWDED = 9;
        public const int AMBIENT_SOUND_CITY_SLUMS_DAY_SPARSE = 10;
        public const int AMBIENT_SOUND_CITY_SLUMS_NIGHT = 11;
        public const int AMBIENT_SOUND_CITY_DAY_CROWDED = 12;
        public const int AMBIENT_SOUND_CITY_DAY_SPARSE = 13;
        public const int AMBIENT_SOUND_CITY_NIGHT = 14;
        public const int AMBIENT_SOUND_CITY_MARKET = 15;
        public const int AMBIENT_SOUND_CITY_TEMPLE_DISTRICT = 16;
        public const int AMBIENT_SOUND_TOWN_DAY_CROWDED = 17;
        public const int AMBIENT_SOUND_TOWN_DAY_SPARSE = 18;
        public const int AMBIENT_SOUND_TOWN_NIGHT = 19;
        public const int AMBIENT_SOUND_BORDELLO_WOMEN = 20;
        public const int AMBIENT_SOUND_BORDELLO_MEN_AND_WOMEN = 21;
        public const int AMBIENT_SOUND_RIOT_OUTSIDE = 22;
        public const int AMBIENT_SOUND_RIOT_MUFFLED = 23;
        public const int AMBIENT_SOUND_COMBAT_OUTSIDE_1 = 24;
        public const int AMBIENT_SOUND_COMBAT_OUTSIDE_2 = 25;
        public const int AMBIENT_SOUND_COMBAT_MUFFLED_1 = 26;
        public const int AMBIENT_SOUND_COMBAT_MUFFLED_2 = 27;
        public const int AMBIENT_SOUND_DUNGEON_LAKE_LAVA = 28;
        public const int AMBIENT_SOUND_SEWER_SLUDGE_LAKE = 29;
        public const int AMBIENT_SOUND_WIND_SOFT = 30;
        public const int AMBIENT_SOUND_WIND_MEDIUM = 31;
        public const int AMBIENT_SOUND_WIND_STRONG = 32;
        public const int AMBIENT_SOUND_WIND_FOREST = 33;
        public const int AMBIENT_SOUND_GUST_CHASM = 34;
        public const int AMBIENT_SOUND_GUST_CAVERN = 35;
        public const int AMBIENT_SOUND_GUST_GRASS = 36;
        public const int AMBIENT_SOUND_GUST_DRAFT = 37;
        public const int AMBIENT_SOUND_RAIN_LIGHT = 38;
        public const int AMBIENT_SOUND_RAIN_HARD = 39;
        public const int AMBIENT_SOUND_RAIN_STORM_SMALL = 40;
        public const int AMBIENT_SOUND_RAIN_STORM_BIG = 41;
        public const int AMBIENT_SOUND_CAVE_INSECTS_1 = 42;
        public const int AMBIENT_SOUND_CAVE_INSECTS_2 = 43;
        public const int AMBIENT_SOUND_INTERIOR_INSECTS_1 = 44;
        public const int AMBIENT_SOUND_INTERIOR_INSECTS_2 = 45;
        public const int AMBIENT_SOUND_LIZARD_FOLK_CAVE_CRYSTALS = 46;
        public const int AMBIENT_SOUND_SEWERS_1 = 47;
        public const int AMBIENT_SOUND_SEWERS_2 = 48;
        public const int AMBIENT_SOUND_FOREST_DAY_1 = 49;
        public const int AMBIENT_SOUND_FOREST_DAY_2 = 50;
        public const int AMBIENT_SOUND_FOREST_DAY_3 = 51;
        public const int AMBIENT_SOUND_FOREST_DAY_SCARY = 52;
        public const int AMBIENT_SOUND_FOREST_NIGHT_1 = 53;
        public const int AMBIENT_SOUND_FOREST_NIGHT_2 = 54;
        public const int AMBIENT_SOUND_FOREST_NIGHT_SCARY = 55;
        public const int AMBIENT_SOUND_FOREST_MAGICAL = 56;
        public const int AMBIENT_SOUND_EVIL_DUNGEON_SMALL = 57;
        public const int AMBIENT_SOUND_EVIL_DUNGEON_MEDIUM = 58;
        public const int AMBIENT_SOUND_EVIL_DUNGEON_LARGE = 59;
        public const int AMBIENT_SOUND_CAVE_SMALL = 60;
        public const int AMBIENT_SOUND_CAVE_MEDIUM = 61;
        public const int AMBIENT_SOUND_CAVE_LARGE = 62;
        public const int AMBIENT_SOUND_MINE_SMALL = 63;
        public const int AMBIENT_SOUND_MINE_MEDIUM = 64;
        public const int AMBIENT_SOUND_MINE_LARGE = 65;
        public const int AMBIENT_SOUND_CASTLE_INTERIOR_SMALL = 66;
        public const int AMBIENT_SOUND_CASTLE_INTERIOR_MEDIUM = 67;
        public const int AMBIENT_SOUND_CASTLE_INTERIOR_LARGE = 68;
        public const int AMBIENT_SOUND_CRYPT_SMALL = 69;
        public const int AMBIENT_SOUND_CRYPT_MEDIUM_1 = 70;
        public const int AMBIENT_SOUND_CRYPT_MEDIUM_2 = 71;
        public const int AMBIENT_SOUND_HOUSE_INTERIOR_1 = 72;
        public const int AMBIENT_SOUND_HOUSE_INTERIOR_2 = 73;
        public const int AMBIENT_SOUND_HOUSE_INTERIOR_3 = 74;
        public const int AMBIENT_SOUND_KITCHEN_INTERIOR_SMALL = 75;
        public const int AMBIENT_SOUND_KITCHEN_INTERIOR_LARGE = 76;
        public const int AMBIENT_SOUND_HAUNTED_INTERIOR_1 = 77;
        public const int AMBIENT_SOUND_HAUNTED_INTERIOR_2 = 78;
        public const int AMBIENT_SOUND_HAUNTED_INTERIOR_3 = 79;
        public const int AMBIENT_SOUND_BLACK_SMITH = 80;
        public const int AMBIENT_SOUND_PIT_CRIES = 81;
        public const int AMBIENT_SOUND_MAGIC_INTERIOR_SMALL = 82;
        public const int AMBIENT_SOUND_MAGIC_INTERIOR_MEDIUM = 83;
        public const int AMBIENT_SOUND_MAGIC_INTERIOR_LARGE = 84;
        public const int AMBIENT_SOUND_MAGIC_INTERIOR_EVIL = 85;
        public const int AMBIENT_SOUND_MAGICAL_INTERIOR_FIRELAB = 86;
        public const int AMBIENT_SOUND_MAGICAL_INTERIOR_EARTHLAB = 87;
        public const int AMBIENT_SOUND_MAGICAL_INTERIOR_AIRLAB = 88;
        public const int AMBIENT_SOUND_MAGICAL_INTERIOR_WATERLAB = 89;
        public const int AMBIENT_SOUND_WINTER_DAY_WET_XP1 = 90;
        public const int AMBIENT_SOUND_WINTER_DAY_WINDY_XP1 = 91;
        public const int AMBIENT_SOUND_DESERT_DAY_XP1 = 92;
        public const int AMBIENT_SOUND_DESERT_NIGHT_XP1 = 93;
        public const int AMBIENT_SOUND_MONASTERY_INTERIOR_XP1 = 94;
        public const int AMBIENT_SOUND_RUIN_WET_XP1 = 96;
        public const int AMBIENT_SOUND_RUIN_RUMBLING_XP1 = 97;
        public const int AMBIENT_SOUND_RUIN_HAUNTED_XP1 = 98;
        public const int AMBIENT_SOUND_SAND_STORM_LIGHT_XP1 = 99;
        public const int AMBIENT_SOUND_SAND_STORM_EXTREME_XP1 = 100;
        public const int AMBIENT_SOUND_EVIL_DRONE_XP2 = 101;
        public const int AMBIENT_SOUND_PLAIN_OF_FIRE_XP2 = 102;
        public const int AMBIENT_SOUND_FROZEN_HELL_XP2 = 103;
        public const int AMBIENT_SOUND_CAVE_EVIL_1_XP2 = 104;
        public const int AMBIENT_SOUND_CAVE_EVIL_2_XP2 = 105;
        public const int AMBIENT_SOUND_CAVE_EVIL_3_XP2 = 106;
        public const int AMBIENT_SOUND_TAVERN_ROWDY = 107;
        //  these constants must match those in the FootstepSounds.2da
        public const int FOOTSTEP_TYPE_INVALID = -1;
        public const int FOOTSTEP_TYPE_NORMAL = 0;
        public const int FOOTSTEP_TYPE_LARGE = 1;
        public const int FOOTSTEP_TYPE_DRAGON = 2;
        public const int FOOTSTEP_TYPE_SOFT = 3;
        public const int FOOTSTEP_TYPE_HOOF = 4;
        public const int FOOTSTEP_TYPE_HOOF_LARGE = 5;
        public const int FOOTSTEP_TYPE_BEETLE = 6;
        public const int FOOTSTEP_TYPE_SPIDER = 7;
        public const int FOOTSTEP_TYPE_SKELETON = 8;
        public const int FOOTSTEP_TYPE_LEATHER_WING = 9;
        public const int FOOTSTEP_TYPE_FEATHER_WING = 10;
        // int FOOTSTEP_TYPE_LIZARD                      = 11; // Was not ever used/fully implemented.
        public const int FOOTSTEP_TYPE_NONE = 12;
        public const int FOOTSTEP_TYPE_SEAGULL = 13;
        public const int FOOTSTEP_TYPE_SHARK = 14;
        public const int FOOTSTEP_TYPE_WATER_NORMAL = 15;
        public const int FOOTSTEP_TYPE_WATER_LARGE = 16;
        public const int FOOTSTEP_TYPE_HORSE = 17;
        public const int FOOTSTEP_TYPE_DEFAULT = 65535;
        //  these constants must match those in the WingModel.2da
        public const int CREATURE_WING_TYPE_NONE = 0;
        public const int CREATURE_WING_TYPE_DEMON = 1;
        public const int CREATURE_WING_TYPE_ANGEL = 2;
        public const int CREATURE_WING_TYPE_BAT = 3;
        public const int CREATURE_WING_TYPE_DRAGON = 4;
        public const int CREATURE_WING_TYPE_BUTTERFLY = 5;
        public const int CREATURE_WING_TYPE_BIRD = 6;
        //  these constants must match those in the TailModel.2da
        public const int CREATURE_TAIL_TYPE_NONE = 0;
        public const int CREATURE_TAIL_TYPE_LIZARD = 1;
        public const int CREATURE_TAIL_TYPE_BONE = 2;
        public const int CREATURE_TAIL_TYPE_DEVIL = 3;
        //  these constants must match those in the CAPart.2da
        public const int CREATURE_PART_RIGHT_FOOT = 0;
        public const int CREATURE_PART_LEFT_FOOT = 1;
        public const int CREATURE_PART_RIGHT_SHIN = 2;
        public const int CREATURE_PART_LEFT_SHIN = 3;
        public const int CREATURE_PART_LEFT_THIGH = 4;
        public const int CREATURE_PART_RIGHT_THIGH = 5;
        public const int CREATURE_PART_PELVIS = 6;
        public const int CREATURE_PART_TORSO = 7;
        public const int CREATURE_PART_BELT = 8;
        public const int CREATURE_PART_NECK = 9;
        public const int CREATURE_PART_RIGHT_FOREARM = 10;
        public const int CREATURE_PART_LEFT_FOREARM = 11;
        public const int CREATURE_PART_RIGHT_BICEP = 12;
        public const int CREATURE_PART_LEFT_BICEP = 13;
        public const int CREATURE_PART_RIGHT_SHOULDER = 14;
        public const int CREATURE_PART_LEFT_SHOULDER = 15;
        public const int CREATURE_PART_RIGHT_HAND = 16;
        public const int CREATURE_PART_LEFT_HAND = 17;
        public const int CREATURE_PART_HEAD = 20;
        public const int CREATURE_MODEL_TYPE_NONE = 0;
        public const int CREATURE_MODEL_TYPE_SKIN = 1;
        public const int CREATURE_MODEL_TYPE_TATTOO = 2;
        public const int CREATURE_MODEL_TYPE_UNDEAD = 255;
        public const int COLOR_CHANNEL_SKIN = 0;
        public const int COLOR_CHANNEL_HAIR = 1;
        public const int COLOR_CHANNEL_TATTOO_1 = 2;
        public const int COLOR_CHANNEL_TATTOO_2 = 3;
        //  The following resrefs must match those in the tileset's set file.
        public const string TILESET_RESREF_BEHOLDER_CAVES = "tib01";
        public const string TILESET_RESREF_CASTLE_INTERIOR = "tic01";
        public const string TILESET_RESREF_CITY_EXTERIOR = "tcn01";
        public const string TILESET_RESREF_CITY_INTERIOR = "tin01";
        public const string TILESET_RESREF_CRYPT = "tdc01";
        public const string TILESET_RESREF_DESERT = "ttd01";
        public const string TILESET_RESREF_DROW_INTERIOR = "tid01";
        public const string TILESET_RESREF_DUNGEON = "tde01";
        public const string TILESET_RESREF_FOREST = "ttf01";
        public const string TILESET_RESREF_FROZEN_WASTES = "tti01";
        public const string TILESET_RESREF_ILLITHID_INTERIOR = "tii01";
        public const string TILESET_RESREF_MICROSET = "tms01";
        public const string TILESET_RESREF_MINES_AND_CAVERNS = "tdm01";
        public const string TILESET_RESREF_RUINS = "tdr01";
        public const string TILESET_RESREF_RURAL = "ttr01";
        public const string TILESET_RESREF_RURAL_WINTER = "tts01";
        public const string TILESET_RESREF_SEWERS = "tds01";
        public const string TILESET_RESREF_UNDERDARK = "ttu01";
        //  These constants determine which name table to use when generating random names.
        public const int NAME_FIRST_GENERIC_MALE = -1;
        public const int NAME_ANIMAL = 0;
        public const int NAME_FAMILIAR = 1;
        public const int NAME_FIRST_DWARF_MALE = 2;
        public const int NAME_FIRST_DWARF_FEMALE = 3;
        public const int NAME_LAST_DWARF = 4;
        public const int NAME_FIRST_ELF_MALE = 5;
        public const int NAME_FIRST_ELF_FEMALE = 6;
        public const int NAME_LAST_ELF = 7;
        public const int NAME_FIRST_GNOME_MALE = 8;
        public const int NAME_FIRST_GNOME_FEMALE = 9;
        public const int NAME_LAST_GNOME = 10;
        public const int NAME_FIRST_HALFELF_MALE = 11;
        public const int NAME_FIRST_HALFELF_FEMALE = 12;
        public const int NAME_LAST_HALFELF = 13;
        public const int NAME_FIRST_HALFLING_MALE = 14;
        public const int NAME_FIRST_HALFLING_FEMALE = 15;
        public const int NAME_LAST_HALFLING = 16;
        public const int NAME_FIRST_HALFORC_MALE = 17;
        public const int NAME_FIRST_HALFORC_FEMALE = 18;
        public const int NAME_LAST_HALFORC = 19;
        public const int NAME_FIRST_HUMAN_MALE = 20;
        public const int NAME_FIRST_HUMAN_FEMALE = 21;
        public const int NAME_LAST_HUMAN = 22;
        public const int EVENT_SCRIPT_MODULE_ON_HEARTBEAT = 3000;
        public const int EVENT_SCRIPT_MODULE_ON_USER_DEFINED_EVENT = 3001;
        public const int EVENT_SCRIPT_MODULE_ON_MODULE_LOAD = 3002;
        public const int EVENT_SCRIPT_MODULE_ON_MODULE_START = 3003;
        public const int EVENT_SCRIPT_MODULE_ON_CLIENT_ENTER = 3004;
        public const int EVENT_SCRIPT_MODULE_ON_CLIENT_EXIT = 3005;
        public const int EVENT_SCRIPT_MODULE_ON_ACTIVATE_ITEM = 3006;
        public const int EVENT_SCRIPT_MODULE_ON_ACQUIRE_ITEM = 3007;
        public const int EVENT_SCRIPT_MODULE_ON_LOSE_ITEM = 3008;
        public const int EVENT_SCRIPT_MODULE_ON_PLAYER_DEATH = 3009;
        public const int EVENT_SCRIPT_MODULE_ON_PLAYER_DYING = 3010;
        public const int EVENT_SCRIPT_MODULE_ON_RESPAWN_BUTTON_PRESSED = 3011;
        public const int EVENT_SCRIPT_MODULE_ON_PLAYER_REST = 3012;
        public const int EVENT_SCRIPT_MODULE_ON_PLAYER_LEVEL_UP = 3013;
        public const int EVENT_SCRIPT_MODULE_ON_PLAYER_CANCEL_CUTSCENE = 3014;
        public const int EVENT_SCRIPT_MODULE_ON_EQUIP_ITEM = 3015;
        public const int EVENT_SCRIPT_MODULE_ON_UNEQUIP_ITEM = 3016;
        public const int EVENT_SCRIPT_MODULE_ON_PLAYER_CHAT = 3017;
        public const int EVENT_SCRIPT_AREA_ON_HEARTBEAT = 4000;
        public const int EVENT_SCRIPT_AREA_ON_USER_DEFINED_EVENT = 4001;
        public const int EVENT_SCRIPT_AREA_ON_ENTER = 4002;
        public const int EVENT_SCRIPT_AREA_ON_EXIT = 4003;
        public const int EVENT_SCRIPT_AREAOFEFFECT_ON_HEARTBEAT = 11000;
        public const int EVENT_SCRIPT_AREAOFEFFECT_ON_USER_DEFINED_EVENT = 11001;
        public const int EVENT_SCRIPT_AREAOFEFFECT_ON_OBJECT_ENTER = 11002;
        public const int EVENT_SCRIPT_AREAOFEFFECT_ON_OBJECT_EXIT = 11003;
        public const int EVENT_SCRIPT_CREATURE_ON_HEARTBEAT = 5000;
        public const int EVENT_SCRIPT_CREATURE_ON_NOTICE = 5001;
        public const int EVENT_SCRIPT_CREATURE_ON_SPELLCASTAT = 5002;
        public const int EVENT_SCRIPT_CREATURE_ON_MELEE_ATTACKED = 5003;
        public const int EVENT_SCRIPT_CREATURE_ON_DAMAGED = 5004;
        public const int EVENT_SCRIPT_CREATURE_ON_DISTURBED = 5005;
        public const int EVENT_SCRIPT_CREATURE_ON_END_COMBATROUND = 5006;
        public const int EVENT_SCRIPT_CREATURE_ON_DIALOGUE = 5007;
        public const int EVENT_SCRIPT_CREATURE_ON_SPAWN_IN = 5008;
        public const int EVENT_SCRIPT_CREATURE_ON_RESTED = 5009;
        public const int EVENT_SCRIPT_CREATURE_ON_DEATH = 5010;
        public const int EVENT_SCRIPT_CREATURE_ON_USER_DEFINED_EVENT = 5011;
        public const int EVENT_SCRIPT_CREATURE_ON_BLOCKED_BY_DOOR = 5012;
        public const int EVENT_SCRIPT_TRIGGER_ON_HEARTBEAT = 7000;
        public const int EVENT_SCRIPT_TRIGGER_ON_OBJECT_ENTER = 7001;
        public const int EVENT_SCRIPT_TRIGGER_ON_OBJECT_EXIT = 7002;
        public const int EVENT_SCRIPT_TRIGGER_ON_USER_DEFINED_EVENT = 7003;
        public const int EVENT_SCRIPT_TRIGGER_ON_TRAPTRIGGERED = 7004;
        public const int EVENT_SCRIPT_TRIGGER_ON_DISARMED = 7005;
        public const int EVENT_SCRIPT_TRIGGER_ON_CLICKED = 7006;
        public const int EVENT_SCRIPT_PLACEABLE_ON_CLOSED = 9000;
        public const int EVENT_SCRIPT_PLACEABLE_ON_DAMAGED = 9001;
        public const int EVENT_SCRIPT_PLACEABLE_ON_DEATH = 9002;
        public const int EVENT_SCRIPT_PLACEABLE_ON_DISARM = 9003;
        public const int EVENT_SCRIPT_PLACEABLE_ON_HEARTBEAT = 9004;
        public const int EVENT_SCRIPT_PLACEABLE_ON_INVENTORYDISTURBED = 9005;
        public const int EVENT_SCRIPT_PLACEABLE_ON_LOCK = 9006;
        public const int EVENT_SCRIPT_PLACEABLE_ON_MELEEATTACKED = 9007;
        public const int EVENT_SCRIPT_PLACEABLE_ON_OPEN = 9008;
        public const int EVENT_SCRIPT_PLACEABLE_ON_SPELLCASTAT = 9009;
        public const int EVENT_SCRIPT_PLACEABLE_ON_TRAPTRIGGERED = 9010;
        public const int EVENT_SCRIPT_PLACEABLE_ON_UNLOCK = 9011;
        public const int EVENT_SCRIPT_PLACEABLE_ON_USED = 9012;
        public const int EVENT_SCRIPT_PLACEABLE_ON_USER_DEFINED_EVENT = 9013;
        public const int EVENT_SCRIPT_PLACEABLE_ON_DIALOGUE = 9014;
        public const int EVENT_SCRIPT_PLACEABLE_ON_LEFT_CLICK = 9015;
        public const int EVENT_SCRIPT_DOOR_ON_OPEN = 10000;
        public const int EVENT_SCRIPT_DOOR_ON_CLOSE = 10001;
        public const int EVENT_SCRIPT_DOOR_ON_DAMAGE = 10002;
        public const int EVENT_SCRIPT_DOOR_ON_DEATH = 10003;
        public const int EVENT_SCRIPT_DOOR_ON_DISARM = 10004;
        public const int EVENT_SCRIPT_DOOR_ON_HEARTBEAT = 10005;
        public const int EVENT_SCRIPT_DOOR_ON_LOCK = 10006;
        public const int EVENT_SCRIPT_DOOR_ON_MELEE_ATTACKED = 10007;
        public const int EVENT_SCRIPT_DOOR_ON_SPELLCASTAT = 10008;
        public const int EVENT_SCRIPT_DOOR_ON_TRAPTRIGGERED = 10009;
        public const int EVENT_SCRIPT_DOOR_ON_UNLOCK = 10010;
        public const int EVENT_SCRIPT_DOOR_ON_USERDEFINED = 10011;
        public const int EVENT_SCRIPT_DOOR_ON_CLICKED = 10012;
        public const int EVENT_SCRIPT_DOOR_ON_DIALOGUE = 10013;
        public const int EVENT_SCRIPT_DOOR_ON_FAIL_TO_OPEN = 10014;
        public const int EVENT_SCRIPT_ENCOUNTER_ON_OBJECT_ENTER = 13000;
        public const int EVENT_SCRIPT_ENCOUNTER_ON_OBJECT_EXIT = 13001;
        public const int EVENT_SCRIPT_ENCOUNTER_ON_HEARTBEAT = 13002;
        public const int EVENT_SCRIPT_ENCOUNTER_ON_ENCOUNTER_EXHAUSTED = 13003;
        public const int EVENT_SCRIPT_ENCOUNTER_ON_USER_DEFINED_EVENT = 13004;
        public const int EVENT_SCRIPT_STORE_ON_OPEN = 14000;
        public const int EVENT_SCRIPT_STORE_ON_CLOSE = 14001;
        public const string sLanguage = "nwscript";
        //  Get an integer between 0 and nMaxInteger-1.
        //  Return value on error: 0
        public static int Random(int nMaxInteger)
        {
            NWN.Internal.StackPushInteger(nMaxInteger);
            NWN.Internal.CallBuiltIn(0);
            return NWN.Internal.StackPopInteger();
        }

        //  Output sString to the log file.
        public static void PrintString(string sString)
        {
            NWN.Internal.StackPushString(sString);
            NWN.Internal.CallBuiltIn(1);
        }

        //  Output a formatted float to the log file.
        //  - nWidth should be a value from 0 to 18 inclusive.
        //  - nDecimals should be a value from 0 to 9 inclusive.
        public static void PrintFloat(float fFloat, int nWidth = 18, int nDecimals = 9)
        {
            NWN.Internal.StackPushInteger(nDecimals);
            NWN.Internal.StackPushInteger(nWidth);
            NWN.Internal.StackPushFloat(fFloat);
            NWN.Internal.CallBuiltIn(2);
        }

        //  Convert fFloat into a string.
        //  - nWidth should be a value from 0 to 18 inclusive.
        //  - nDecimals should be a value from 0 to 9 inclusive.
        public static string FloatToString(float fFloat, int nWidth = 18, int nDecimals = 9)
        {
            NWN.Internal.StackPushInteger(nDecimals);
            NWN.Internal.StackPushInteger(nWidth);
            NWN.Internal.StackPushFloat(fFloat);
            NWN.Internal.CallBuiltIn(3);
            return NWN.Internal.StackPopString();
        }

        //  Output nInteger to the log file.
        public static void PrintInteger(int nInteger)
        {
            NWN.Internal.StackPushInteger(nInteger);
            NWN.Internal.CallBuiltIn(4);
        }

        //  Output oObject's ID to the log file.
        public static void PrintObject(NWN.Object oObject)
        {
            NWN.Internal.StackPushObject(oObject, false);
            NWN.Internal.CallBuiltIn(5);
        }

        //  Assign aActionToAssign to oActionSubject.
        //  * No return value, but if an error occurs, the log file will contain
        //    "AssignCommand failed."
        //    (If the object doesn't exist, nothing happens.)
        //  Delay aActionToDelay by fSeconds.
        //  * No return value, but if an error occurs, the log file will contain
        //    "DelayCommand failed.".
        //  It is suggested that functions which create effects should not be used
        //  as parameters to delayed actions.  Instead, the effect should be created in the
        //  script and then passed into the action.  For example:
        //  effect eDamage = EffectDamage(nDamage, DAMAGE_TYPE_MAGICAL);
        //  DelayCommand(fDelay, ApplyEffectToObject(DURATION_TYPE_INSTANT, eDamage, oTarget);
        //  Make oTarget run sScript and then return execution to the calling script.
        //  If sScript does not specify a compiled script, nothing happens.
        public static void ExecuteScript(string sScript, NWN.Object oTarget)
        {
            NWN.Internal.StackPushObject(oTarget, false);
            NWN.Internal.StackPushString(sScript);
            NWN.Internal.CallBuiltIn(8);
        }

        //  Clear all the actions of the caller.
        //  * No return value, but if an error occurs, the log file will contain
        //    "ClearAllActions failed.".
        //  - nClearCombatState: if true, this will immediately clear the combat state
        //    on a creature, which will stop the combat music and allow them to rest,
        //    engage in dialog, or other actions that they would normally have to wait for.
        public static void ClearAllActions(int nClearCombatState = FALSE)
        {
            NWN.Internal.StackPushInteger(nClearCombatState);
            NWN.Internal.CallBuiltIn(9);
        }

        //  Cause the caller to face fDirection.
        //  - fDirection is expressed as anticlockwise degrees from Due East.
        //    DIRECTION_EAST, DIRECTION_NORTH, DIRECTION_WEST and DIRECTION_SOUTH are
        //    predefined. (0.0f=East, 90.0f=North, 180.0f=West, 270.0f=South)
        public static void SetFacing(float fDirection)
        {
            NWN.Internal.StackPushFloat(fDirection);
            NWN.Internal.CallBuiltIn(10);
        }

        //  Set the calendar to the specified date.
        //  - nYear should be from 0 to 32000 inclusive
        //  - nMonth should be from 1 to 12 inclusive
        //  - nDay should be from 1 to 28 inclusive
        //  1) Time can only be advanced forwards; attempting to set the time backwards
        //     will result in no change to the calendar.
        //  2) If values larger than the month or day are specified, they will be wrapped
        //     around and the overflow will be used to advance the next field.
        //     e.g. Specifying a year of 1350, month of 33 and day of 10 will result in
        //     the calender being set to a year of 1352, a month of 9 and a day of 10.
        public static void SetCalendar(int nYear, int nMonth, int nDay)
        {
            NWN.Internal.StackPushInteger(nDay);
            NWN.Internal.StackPushInteger(nMonth);
            NWN.Internal.StackPushInteger(nYear);
            NWN.Internal.CallBuiltIn(11);
        }

        //  Set the time to the time specified.
        //  - nHour should be from 0 to 23 inclusive
        //  - nMinute should be from 0 to 59 inclusive
        //  - nSecond should be from 0 to 59 inclusive
        //  - nMillisecond should be from 0 to 999 inclusive
        //  1) Time can only be advanced forwards; attempting to set the time backwards
        //     will result in the day advancing and then the time being set to that
        //     specified, e.g. if the current hour is 15 and then the hour is set to 3,
        //     the day will be advanced by 1 and the hour will be set to 3.
        //  2) If values larger than the max hour, minute, second or millisecond are
        //     specified, they will be wrapped around and the overflow will be used to
        //     advance the next field, e.g. specifying 62 hours, 250 minutes, 10 seconds
        //     and 10 milliseconds will result in the calendar day being advanced by 2
        //     and the time being set to 18 hours, 10 minutes, 10 milliseconds.
        public static void SetTime(int nHour, int nMinute, int nSecond, int nMillisecond)
        {
            NWN.Internal.StackPushInteger(nMillisecond);
            NWN.Internal.StackPushInteger(nSecond);
            NWN.Internal.StackPushInteger(nMinute);
            NWN.Internal.StackPushInteger(nHour);
            NWN.Internal.CallBuiltIn(12);
        }

        //  Get the current calendar year.
        public static int GetCalendarYear()
        {
            NWN.Internal.CallBuiltIn(13);
            return NWN.Internal.StackPopInteger();
        }

        //  Get the current calendar month.
        public static int GetCalendarMonth()
        {
            NWN.Internal.CallBuiltIn(14);
            return NWN.Internal.StackPopInteger();
        }

        //  Get the current calendar day.
        public static int GetCalendarDay()
        {
            NWN.Internal.CallBuiltIn(15);
            return NWN.Internal.StackPopInteger();
        }

        //  Get the current hour.
        public static int GetTimeHour()
        {
            NWN.Internal.CallBuiltIn(16);
            return NWN.Internal.StackPopInteger();
        }

        //  Get the current minute
        public static int GetTimeMinute()
        {
            NWN.Internal.CallBuiltIn(17);
            return NWN.Internal.StackPopInteger();
        }

        //  Get the current second
        public static int GetTimeSecond()
        {
            NWN.Internal.CallBuiltIn(18);
            return NWN.Internal.StackPopInteger();
        }

        //  Get the current millisecond
        public static int GetTimeMillisecond()
        {
            NWN.Internal.CallBuiltIn(19);
            return NWN.Internal.StackPopInteger();
        }

        //  The action subject will generate a random location near its current location
        //  and pathfind to it.  ActionRandomwalk never ends, which means it is neccessary
        //  to call ClearAllActions in order to allow a creature to perform any other action
        //  once ActionRandomWalk has been called.
        //  * No return value, but if an error occurs the log file will contain
        //    "ActionRandomWalk failed."
        public static void ActionRandomWalk()
        {
            NWN.Internal.CallBuiltIn(20);
        }

        //  The action subject will move to lDestination.
        //  - lDestination: The object will move to this location.  If the location is
        //    invalid or a path cannot be found to it, the command does nothing.
        //  - bRun: If this is TRUE, the action subject will run rather than walk
        //  * No return value, but if an error occurs the log file will contain
        //    "MoveToPoint failed."
        public static void ActionMoveToLocation(NWN.Location lDestination, int bRun = FALSE)
        {
            NWN.Internal.StackPushInteger(bRun);
            NWN.Internal.StackPushLocation(lDestination);
            NWN.Internal.CallBuiltIn(21);
        }

        //  Cause the action subject to move to a certain distance from oMoveTo.
        //  If there is no path to oMoveTo, this command will do nothing.
        //  - oMoveTo: This is the object we wish the action subject to move to
        //  - bRun: If this is TRUE, the action subject will run rather than walk
        //  - fRange: This is the desired distance between the action subject and oMoveTo
        //  * No return value, but if an error occurs the log file will contain
        //    "ActionMoveToObject failed."
        public static void ActionMoveToObject(NWN.Object oMoveTo, int bRun = FALSE, float fRange = 1.0f)
        {
            NWN.Internal.StackPushFloat(fRange);
            NWN.Internal.StackPushInteger(bRun);
            NWN.Internal.StackPushObject(oMoveTo, false);
            NWN.Internal.CallBuiltIn(22);
        }

        //  Cause the action subject to move to a certain distance away from oFleeFrom.
        //  - oFleeFrom: This is the object we wish the action subject to move away from.
        //    If oFleeFrom is not in the same area as the action subject, nothing will
        //    happen.
        //  - bRun: If this is TRUE, the action subject will run rather than walk
        //  - fMoveAwayRange: This is the distance we wish the action subject to put
        //    between themselves and oFleeFrom
        //  * No return value, but if an error occurs the log file will contain
        //    "ActionMoveAwayFromObject failed."
        public static void ActionMoveAwayFromObject(NWN.Object oFleeFrom, int bRun = FALSE, float fMoveAwayRange = 40.0f)
        {
            NWN.Internal.StackPushFloat(fMoveAwayRange);
            NWN.Internal.StackPushInteger(bRun);
            NWN.Internal.StackPushObject(oFleeFrom, false);
            NWN.Internal.CallBuiltIn(23);
        }

        //  Get the area that oTarget is currently in
        //  * Return value on error: OBJECT_INVALID
        public static NWN.Object GetArea(NWN.Object oTarget)
        {
            NWN.Internal.StackPushObject(oTarget, false);
            NWN.Internal.CallBuiltIn(24);
            return NWN.Internal.StackPopObject();
        }

        //  The value returned by this function depends on the object type of the caller:
        //  1) If the caller is a door it returns the object that last
        //     triggered it.
        //  2) If the caller is a trigger, area of effect, module, area or encounter it
        //     returns the object that last entered it.
        //  * Return value on error: OBJECT_INVALID
        //   When used for doors, this should only be called from the OnAreaTransitionClick
        //   event.  Otherwise, it should only be called in OnEnter scripts.
        public static NWN.Object GetEnteringObject()
        {
            NWN.Internal.CallBuiltIn(25);
            return NWN.Internal.StackPopObject();
        }

        //  Get the object that last left the caller.  This function works on triggers,
        //  areas of effect, modules, areas and encounters.
        //  * Return value on error: OBJECT_INVALID
        //  Should only be called in OnExit scripts.
        public static NWN.Object GetExitingObject()
        {
            NWN.Internal.CallBuiltIn(26);
            return NWN.Internal.StackPopObject();
        }

        //  Get the position of oTarget
        //  * Return value on error: vector (0.0f, 0.0f, 0.0f)
        public static NWN.Vector GetPosition(NWN.Object oTarget)
        {
            NWN.Internal.StackPushObject(oTarget, false);
            NWN.Internal.CallBuiltIn(27);
            return NWN.Internal.StackPopVector();
        }

        //  Get the direction in which oTarget is facing, expressed as a float between
        //  0.0f and 360.0f
        //  * Return value on error: -1.0f
        public static float GetFacing(NWN.Object oTarget)
        {
            NWN.Internal.StackPushObject(oTarget, false);
            NWN.Internal.CallBuiltIn(28);
            return NWN.Internal.StackPopFloat();
        }

        //  Get the possessor of oItem
        //  * Return value on error: OBJECT_INVALID
        public static NWN.Object GetItemPossessor(NWN.Object oItem)
        {
            NWN.Internal.StackPushObject(oItem, false);
            NWN.Internal.CallBuiltIn(29);
            return NWN.Internal.StackPopObject();
        }

        //  Get the object possessed by oCreature with the tag sItemTag
        //  * Return value on error: OBJECT_INVALID
        public static NWN.Object GetItemPossessedBy(NWN.Object oCreature, string sItemTag)
        {
            NWN.Internal.StackPushString(sItemTag);
            NWN.Internal.StackPushObject(oCreature, false);
            NWN.Internal.CallBuiltIn(30);
            return NWN.Internal.StackPopObject();
        }

        //  Create an item with the template sItemTemplate in oTarget's inventory.
        //  - nStackSize: This is the stack size of the item to be created
        //  - sNewTag: If this string is not empty, it will replace the default tag from the template
        //  * Return value: The object that has been created.  On error, this returns
        //    OBJECT_INVALID.
        //  If the item created was merged into an existing stack of similar items,
        //  the function will return the merged stack object. If the merged stack
        //  overflowed, the function will return the overflowed stack that was created.
        public static NWN.Object CreateItemOnObject(string sItemTemplate, NWN.Object oTarget = null, int nStackSize = 1, string sNewTag = "")
        {
            NWN.Internal.StackPushString(sNewTag);
            NWN.Internal.StackPushInteger(nStackSize);
            NWN.Internal.StackPushObject(oTarget, false);
            NWN.Internal.StackPushString(sItemTemplate);
            NWN.Internal.CallBuiltIn(31);
            return NWN.Internal.StackPopObject();
        }

        //  Equip oItem into nInventorySlot.
        //  - nInventorySlot: INVENTORY_SLOT_*
        //  * No return value, but if an error occurs the log file will contain
        //    "ActionEquipItem failed."
        // 
        //  Note: 
        //        If the creature already has an item equipped in the slot specified, it will be 
        //        unequipped automatically by the call to ActionEquipItem.
        //      
        //        In order for ActionEquipItem to succeed the creature must be able to equip the
        //        item oItem normally. This means that:
        //        1) The item is in the creature's inventory.
        //        2) The item must already be identified (if magical). 
        //        3) The creature has the level required to equip the item (if magical and ILR is on).
        //        4) The creature possesses the required feats to equip the item (such as weapon proficiencies).
        public static void ActionEquipItem(NWN.Object oItem, int nInventorySlot)
        {
            NWN.Internal.StackPushInteger(nInventorySlot);
            NWN.Internal.StackPushObject(oItem, false);
            NWN.Internal.CallBuiltIn(32);
        }

        //  Unequip oItem from whatever slot it is currently in.
        public static void ActionUnequipItem(NWN.Object oItem)
        {
            NWN.Internal.StackPushObject(oItem, false);
            NWN.Internal.CallBuiltIn(33);
        }

        //  Pick up oItem from the ground.
        //  * No return value, but if an error occurs the log file will contain
        //    "ActionPickUpItem failed."
        public static void ActionPickUpItem(NWN.Object oItem)
        {
            NWN.Internal.StackPushObject(oItem, false);
            NWN.Internal.CallBuiltIn(34);
        }

        //  Put down oItem on the ground.
        //  * No return value, but if an error occurs the log file will contain
        //    "ActionPutDownItem failed."
        public static void ActionPutDownItem(NWN.Object oItem)
        {
            NWN.Internal.StackPushObject(oItem, false);
            NWN.Internal.CallBuiltIn(35);
        }

        //  Get the last attacker of oAttackee.  This should only be used ONLY in the
        //  OnAttacked events for creatures, placeables and doors.
        //  * Return value on error: OBJECT_INVALID
        public static NWN.Object GetLastAttacker(NWN.Object oAttackee = null)
        {
            NWN.Internal.StackPushObject(oAttackee, false);
            NWN.Internal.CallBuiltIn(36);
            return NWN.Internal.StackPopObject();
        }

        //  Attack oAttackee.
        //  - bPassive: If this is TRUE, attack is in passive mode.
        public static void ActionAttack(NWN.Object oAttackee, int bPassive = FALSE)
        {
            NWN.Internal.StackPushInteger(bPassive);
            NWN.Internal.StackPushObject(oAttackee, false);
            NWN.Internal.CallBuiltIn(37);
        }

        //  Get the creature nearest to oTarget, subject to all the criteria specified.
        //  - nFirstCriteriaType: CREATURE_TYPE_*
        //  - nFirstCriteriaValue:
        //    -> CLASS_TYPE_* if nFirstCriteriaType was CREATURE_TYPE_CLASS
        //    -> SPELL_* if nFirstCriteriaType was CREATURE_TYPE_DOES_NOT_HAVE_SPELL_EFFECT
        //       or CREATURE_TYPE_HAS_SPELL_EFFECT
        //    -> TRUE or FALSE if nFirstCriteriaType was CREATURE_TYPE_IS_ALIVE
        //    -> PERCEPTION_* if nFirstCriteriaType was CREATURE_TYPE_PERCEPTION
        //    -> PLAYER_CHAR_IS_PC or PLAYER_CHAR_NOT_PC if nFirstCriteriaType was
        //       CREATURE_TYPE_PLAYER_CHAR
        //    -> RACIAL_TYPE_* if nFirstCriteriaType was CREATURE_TYPE_RACIAL_TYPE
        //    -> REPUTATION_TYPE_* if nFirstCriteriaType was CREATURE_TYPE_REPUTATION
        //    For example, to get the nearest PC, use:
        //    (CREATURE_TYPE_PLAYER_CHAR, PLAYER_CHAR_IS_PC)
        //  - oTarget: We're trying to find the creature of the specified type that is
        //    nearest to oTarget
        //  - nNth: We don't have to find the first nearest: we can find the Nth nearest...
        //  - nSecondCriteriaType: This is used in the same way as nFirstCriteriaType to
        //    further specify the type of creature that we are looking for.
        //  - nSecondCriteriaValue: This is used in the same way as nFirstCriteriaValue
        //    to further specify the type of creature that we are looking for.
        //  - nThirdCriteriaType: This is used in the same way as nFirstCriteriaType to
        //    further specify the type of creature that we are looking for.
        //  - nThirdCriteriaValue: This is used in the same way as nFirstCriteriaValue to
        //    further specify the type of creature that we are looking for.
        //  * Return value on error: OBJECT_INVALID
        public static NWN.Object GetNearestCreature(int nFirstCriteriaType, int nFirstCriteriaValue, NWN.Object oTarget = null, int nNth = 1, int nSecondCriteriaType = -1, int nSecondCriteriaValue = -1, int nThirdCriteriaType = -1, int nThirdCriteriaValue = -1)
        {
            NWN.Internal.StackPushInteger(nThirdCriteriaValue);
            NWN.Internal.StackPushInteger(nThirdCriteriaType);
            NWN.Internal.StackPushInteger(nSecondCriteriaValue);
            NWN.Internal.StackPushInteger(nSecondCriteriaType);
            NWN.Internal.StackPushInteger(nNth);
            NWN.Internal.StackPushObject(oTarget, false);
            NWN.Internal.StackPushInteger(nFirstCriteriaValue);
            NWN.Internal.StackPushInteger(nFirstCriteriaType);
            NWN.Internal.CallBuiltIn(38);
            return NWN.Internal.StackPopObject();
        }

        //  Add a speak action to the action subject.
        //  - sStringToSpeak: String to be spoken
        //  - nTalkVolume: TALKVOLUME_*
        public static void ActionSpeakString(string sStringToSpeak, int nTalkVolume = TALKVOLUME_TALK)
        {
            NWN.Internal.StackPushInteger(nTalkVolume);
            NWN.Internal.StackPushString(sStringToSpeak);
            NWN.Internal.CallBuiltIn(39);
        }

        //  Cause the action subject to play an animation
        //  - nAnimation: ANIMATION_*
        //  - fSpeed: Speed of the animation
        //  - fDurationSeconds: Duration of the animation (this is not used for Fire and
        //    Forget animations)
        public static void ActionPlayAnimation(int nAnimation, float fSpeed = 1.0f, float fDurationSeconds = 0.0f)
        {
            NWN.Internal.StackPushFloat(fDurationSeconds);
            NWN.Internal.StackPushFloat(fSpeed);
            NWN.Internal.StackPushInteger(nAnimation);
            NWN.Internal.CallBuiltIn(40);
        }

        //  Get the distance from the caller to oObject in metres.
        //  * Return value on error: -1.0f
        public static float GetDistanceToObject(NWN.Object oObject)
        {
            NWN.Internal.StackPushObject(oObject, false);
            NWN.Internal.CallBuiltIn(41);
            return NWN.Internal.StackPopFloat();
        }

        //  * Returns TRUE if oObject is a valid object.
        public static int GetIsObjectValid(NWN.Object oObject)
        {
            NWN.Internal.StackPushObject(oObject, false);
            NWN.Internal.CallBuiltIn(42);
            return NWN.Internal.StackPopInteger();
        }

        //  Cause the action subject to open oDoor
        public static void ActionOpenDoor(NWN.Object oDoor)
        {
            NWN.Internal.StackPushObject(oDoor, false);
            NWN.Internal.CallBuiltIn(43);
        }

        //  Cause the action subject to close oDoor
        public static void ActionCloseDoor(NWN.Object oDoor)
        {
            NWN.Internal.StackPushObject(oDoor, false);
            NWN.Internal.CallBuiltIn(44);
        }

        //  Change the direction in which the camera is facing
        //  - fDirection is expressed as anticlockwise degrees from Due East.
        //    (0.0f=East, 90.0f=North, 180.0f=West, 270.0f=South)
        //  A value of -1.0f for any parameter will be ignored and instead it will
        //  use the current camera value.
        //  This can be used to change the way the camera is facing after the player
        //  emerges from an area transition.
        //  - nTransitionType: CAMERA_TRANSITION_TYPE_*  SNAP will immediately move the
        //    camera to the new position, while the other types will result in the camera moving gradually into position
        //  Pitch and distance are limited to valid values for the current camera mode:
        //  Top Down: Distance = 5-20, Pitch = 1-50
        //  Driving camera: Distance = 6 (can't be changed), Pitch = 1-62
        //  Chase: Distance = 5-20, Pitch = 1-50
        //  *** NOTE *** In NWN:Hordes of the Underdark the camera limits have been relaxed to the following:
        //  Distance 1-25
        //  Pitch 1-89
        public static void SetCameraFacing(float fDirection, float fDistance = -1.0f, float fPitch = -1.0f, int nTransitionType = CAMERA_TRANSITION_TYPE_SNAP)
        {
            NWN.Internal.StackPushInteger(nTransitionType);
            NWN.Internal.StackPushFloat(fPitch);
            NWN.Internal.StackPushFloat(fDistance);
            NWN.Internal.StackPushFloat(fDirection);
            NWN.Internal.CallBuiltIn(45);
        }

        //  Play sSoundName
        //  - sSoundName: TBD - SS
        //  This will play a mono sound from the location of the object running the command.
        public static void PlaySound(string sSoundName)
        {
            NWN.Internal.StackPushString(sSoundName);
            NWN.Internal.CallBuiltIn(46);
        }

        //  Get the object at which the caller last cast a spell
        //  * Return value on error: OBJECT_INVALID
        public static NWN.Object GetSpellTargetObject()
        {
            NWN.Internal.CallBuiltIn(47);
            return NWN.Internal.StackPopObject();
        }

        //  This action casts a spell at oTarget.
        //  - nSpell: SPELL_*
        //  - oTarget: Target for the spell
        //  - nMetamagic: METAMAGIC_*
        //  - bCheat: If this is TRUE, then the executor of the action doesn't have to be
        //    able to cast the spell.
        //  - nDomainLevel: TBD - SS
        //  - nProjectilePathType: PROJECTILE_PATH_TYPE_*
        //  - bInstantSpell: If this is TRUE, the spell is cast immediately. This allows
        //    the end-user to simulate a high-level magic-user having lots of advance
        //    warning of impending trouble
        public static void ActionCastSpellAtObject(int nSpell, NWN.Object oTarget, int nMetaMagic = METAMAGIC_ANY, int bCheat = FALSE, int nDomainLevel = 0, int nProjectilePathType = PROJECTILE_PATH_TYPE_DEFAULT, int bInstantSpell = FALSE)
        {
            NWN.Internal.StackPushInteger(bInstantSpell);
            NWN.Internal.StackPushInteger(nProjectilePathType);
            NWN.Internal.StackPushInteger(nDomainLevel);
            NWN.Internal.StackPushInteger(bCheat);
            NWN.Internal.StackPushInteger(nMetaMagic);
            NWN.Internal.StackPushObject(oTarget, false);
            NWN.Internal.StackPushInteger(nSpell);
            NWN.Internal.CallBuiltIn(48);
        }

        //  Get the current hitpoints of oObject
        //  * Return value on error: 0
        public static int GetCurrentHitPoints(NWN.Object oObject = null)
        {
            NWN.Internal.StackPushObject(oObject, false);
            NWN.Internal.CallBuiltIn(49);
            return NWN.Internal.StackPopInteger();
        }

        //  Get the maximum hitpoints of oObject
        //  * Return value on error: 0
        public static int GetMaxHitPoints(NWN.Object oObject = null)
        {
            NWN.Internal.StackPushObject(oObject, false);
            NWN.Internal.CallBuiltIn(50);
            return NWN.Internal.StackPopInteger();
        }

        //  Get oObject's local integer variable sVarName
        //  * Return value on error: 0
        public static int GetLocalInt(NWN.Object oObject, string sVarName)
        {
            NWN.Internal.StackPushString(sVarName);
            NWN.Internal.StackPushObject(oObject, false);
            NWN.Internal.CallBuiltIn(51);
            return NWN.Internal.StackPopInteger();
        }

        //  Get oObject's local float variable sVarName
        //  * Return value on error: 0.0f
        public static float GetLocalFloat(NWN.Object oObject, string sVarName)
        {
            NWN.Internal.StackPushString(sVarName);
            NWN.Internal.StackPushObject(oObject, false);
            NWN.Internal.CallBuiltIn(52);
            return NWN.Internal.StackPopFloat();
        }

        //  Get oObject's local string variable sVarName
        //  * Return value on error: ""
        public static string GetLocalString(NWN.Object oObject, string sVarName)
        {
            NWN.Internal.StackPushString(sVarName);
            NWN.Internal.StackPushObject(oObject, false);
            NWN.Internal.CallBuiltIn(53);
            return NWN.Internal.StackPopString();
        }

        //  Get oObject's local object variable sVarName
        //  * Return value on error: OBJECT_INVALID
        public static NWN.Object GetLocalObject(NWN.Object oObject, string sVarName)
        {
            NWN.Internal.StackPushString(sVarName);
            NWN.Internal.StackPushObject(oObject, false);
            NWN.Internal.CallBuiltIn(54);
            return NWN.Internal.StackPopObject();
        }

        //  Set oObject's local integer variable sVarName to nValue
        public static void SetLocalInt(NWN.Object oObject, string sVarName, int nValue)
        {
            NWN.Internal.StackPushInteger(nValue);
            NWN.Internal.StackPushString(sVarName);
            NWN.Internal.StackPushObject(oObject, false);
            NWN.Internal.CallBuiltIn(55);
        }

        //  Set oObject's local float variable sVarName to nValue
        public static void SetLocalFloat(NWN.Object oObject, string sVarName, float fValue)
        {
            NWN.Internal.StackPushFloat(fValue);
            NWN.Internal.StackPushString(sVarName);
            NWN.Internal.StackPushObject(oObject, false);
            NWN.Internal.CallBuiltIn(56);
        }

        //  Set oObject's local string variable sVarName to nValue
        public static void SetLocalString(NWN.Object oObject, string sVarName, string sValue)
        {
            NWN.Internal.StackPushString(sValue);
            NWN.Internal.StackPushString(sVarName);
            NWN.Internal.StackPushObject(oObject, false);
            NWN.Internal.CallBuiltIn(57);
        }

        //  Set oObject's local object variable sVarName to nValue
        public static void SetLocalObject(NWN.Object oObject, string sVarName, NWN.Object oValue)
        {
            NWN.Internal.StackPushObject(oValue, false);
            NWN.Internal.StackPushString(sVarName);
            NWN.Internal.StackPushObject(oObject, false);
            NWN.Internal.CallBuiltIn(58);
        }

        //  Get the length of sString
        //  * Return value on error: -1
        public static int GetStringLength(string sString)
        {
            NWN.Internal.StackPushString(sString);
            NWN.Internal.CallBuiltIn(59);
            return NWN.Internal.StackPopInteger();
        }

        //  Convert sString into upper case
        //  * Return value on error: ""
        public static string GetStringUpperCase(string sString)
        {
            NWN.Internal.StackPushString(sString);
            NWN.Internal.CallBuiltIn(60);
            return NWN.Internal.StackPopString();
        }

        //  Convert sString into lower case
        //  * Return value on error: ""
        public static string GetStringLowerCase(string sString)
        {
            NWN.Internal.StackPushString(sString);
            NWN.Internal.CallBuiltIn(61);
            return NWN.Internal.StackPopString();
        }

        //  Get nCount characters from the right end of sString
        //  * Return value on error: ""
        public static string GetStringRight(string sString, int nCount)
        {
            NWN.Internal.StackPushInteger(nCount);
            NWN.Internal.StackPushString(sString);
            NWN.Internal.CallBuiltIn(62);
            return NWN.Internal.StackPopString();
        }

        //  Get nCounter characters from the left end of sString
        //  * Return value on error: ""
        public static string GetStringLeft(string sString, int nCount)
        {
            NWN.Internal.StackPushInteger(nCount);
            NWN.Internal.StackPushString(sString);
            NWN.Internal.CallBuiltIn(63);
            return NWN.Internal.StackPopString();
        }

        //  Insert sString into sDestination at nPosition
        //  * Return value on error: ""
        public static string InsertString(string sDestination, string sString, int nPosition)
        {
            NWN.Internal.StackPushInteger(nPosition);
            NWN.Internal.StackPushString(sString);
            NWN.Internal.StackPushString(sDestination);
            NWN.Internal.CallBuiltIn(64);
            return NWN.Internal.StackPopString();
        }

        //  Get nCount characters from sString, starting at nStart
        //  * Return value on error: ""
        public static string GetSubString(string sString, int nStart, int nCount)
        {
            NWN.Internal.StackPushInteger(nCount);
            NWN.Internal.StackPushInteger(nStart);
            NWN.Internal.StackPushString(sString);
            NWN.Internal.CallBuiltIn(65);
            return NWN.Internal.StackPopString();
        }

        //  Find the position of sSubstring inside sString
        //  - nStart: The character position to start searching at (from the left end of the string). 
        //  * Return value on error: -1
        public static int FindSubString(string sString, string sSubString, int nStart = 0)
        {
            NWN.Internal.StackPushInteger(nStart);
            NWN.Internal.StackPushString(sSubString);
            NWN.Internal.StackPushString(sString);
            NWN.Internal.CallBuiltIn(66);
            return NWN.Internal.StackPopInteger();
        }

        //  math operations
        //  Maths operation: absolute value of fValue
        public static float fabs(float fValue)
        {
            NWN.Internal.StackPushFloat(fValue);
            NWN.Internal.CallBuiltIn(67);
            return NWN.Internal.StackPopFloat();
        }

        //  Maths operation: cosine of fValue
        public static float cos(float fValue)
        {
            NWN.Internal.StackPushFloat(fValue);
            NWN.Internal.CallBuiltIn(68);
            return NWN.Internal.StackPopFloat();
        }

        //  Maths operation: sine of fValue
        public static float sin(float fValue)
        {
            NWN.Internal.StackPushFloat(fValue);
            NWN.Internal.CallBuiltIn(69);
            return NWN.Internal.StackPopFloat();
        }

        //  Maths operation: tan of fValue
        public static float tan(float fValue)
        {
            NWN.Internal.StackPushFloat(fValue);
            NWN.Internal.CallBuiltIn(70);
            return NWN.Internal.StackPopFloat();
        }

        //  Maths operation: arccosine of fValue
        //  * Returns zero if fValue > 1 or fValue < -1
        public static float acos(float fValue)
        {
            NWN.Internal.StackPushFloat(fValue);
            NWN.Internal.CallBuiltIn(71);
            return NWN.Internal.StackPopFloat();
        }

        //  Maths operation: arcsine of fValue
        //  * Returns zero if fValue >1 or fValue < -1
        public static float asin(float fValue)
        {
            NWN.Internal.StackPushFloat(fValue);
            NWN.Internal.CallBuiltIn(72);
            return NWN.Internal.StackPopFloat();
        }

        //  Maths operation: arctan of fValue
        public static float atan(float fValue)
        {
            NWN.Internal.StackPushFloat(fValue);
            NWN.Internal.CallBuiltIn(73);
            return NWN.Internal.StackPopFloat();
        }

        //  Maths operation: log of fValue
        //  * Returns zero if fValue <= zero
        public static float log(float fValue)
        {
            NWN.Internal.StackPushFloat(fValue);
            NWN.Internal.CallBuiltIn(74);
            return NWN.Internal.StackPopFloat();
        }

        //  Maths operation: fValue is raised to the power of fExponent
        //  * Returns zero if fValue ==0 and fExponent <0
        public static float pow(float fValue, float fExponent)
        {
            NWN.Internal.StackPushFloat(fExponent);
            NWN.Internal.StackPushFloat(fValue);
            NWN.Internal.CallBuiltIn(75);
            return NWN.Internal.StackPopFloat();
        }

        //  Maths operation: square root of fValue
        //  * Returns zero if fValue <0
        public static float sqrt(float fValue)
        {
            NWN.Internal.StackPushFloat(fValue);
            NWN.Internal.CallBuiltIn(76);
            return NWN.Internal.StackPopFloat();
        }

        //  Maths operation: integer absolute value of nValue
        //  * Return value on error: 0
        public static int abs(int nValue)
        {
            NWN.Internal.StackPushInteger(nValue);
            NWN.Internal.CallBuiltIn(77);
            return NWN.Internal.StackPopInteger();
        }

        //  Create a Heal effect. This should be applied as an instantaneous effect.
        //  * Returns an effect of type EFFECT_TYPE_INVALIDEFFECT if nDamageToHeal < 0.
        public static NWN.Effect EffectHeal(int nDamageToHeal)
        {
            NWN.Internal.StackPushInteger(nDamageToHeal);
            NWN.Internal.CallBuiltIn(78);
            return NWN.Internal.StackPopEffect();
        }

        //  Create a Damage effect
        //  - nDamageAmount: amount of damage to be dealt. This should be applied as an
        //    instantaneous effect.
        //  - nDamageType: DAMAGE_TYPE_*
        //  - nDamagePower: DAMAGE_POWER_*
        public static NWN.Effect EffectDamage(int nDamageAmount, int nDamageType = DAMAGE_TYPE_MAGICAL, int nDamagePower = DAMAGE_POWER_NORMAL)
        {
            NWN.Internal.StackPushInteger(nDamagePower);
            NWN.Internal.StackPushInteger(nDamageType);
            NWN.Internal.StackPushInteger(nDamageAmount);
            NWN.Internal.CallBuiltIn(79);
            return NWN.Internal.StackPopEffect();
        }

        //  Create an Ability Increase effect
        //  - bAbilityToIncrease: ABILITY_*
        public static NWN.Effect EffectAbilityIncrease(int nAbilityToIncrease, int nModifyBy)
        {
            NWN.Internal.StackPushInteger(nModifyBy);
            NWN.Internal.StackPushInteger(nAbilityToIncrease);
            NWN.Internal.CallBuiltIn(80);
            return NWN.Internal.StackPopEffect();
        }

        //  Create a Damage Resistance effect that removes the first nAmount points of
        //  damage of type nDamageType, up to nLimit (or infinite if nLimit is 0)
        //  - nDamageType: DAMAGE_TYPE_*
        //  - nAmount
        //  - nLimit
        public static NWN.Effect EffectDamageResistance(int nDamageType, int nAmount, int nLimit = 0)
        {
            NWN.Internal.StackPushInteger(nLimit);
            NWN.Internal.StackPushInteger(nAmount);
            NWN.Internal.StackPushInteger(nDamageType);
            NWN.Internal.CallBuiltIn(81);
            return NWN.Internal.StackPopEffect();
        }

        //  Create a Resurrection effect. This should be applied as an instantaneous effect.
        public static NWN.Effect EffectResurrection()
        {
            NWN.Internal.CallBuiltIn(82);
            return NWN.Internal.StackPopEffect();
        }

        //  Create a Summon Creature effect.  The creature is created and placed into the
        //  caller's party/faction.
        //  - sCreatureResref: Identifies the creature to be summoned
        //  - nVisualEffectId: VFX_*
        //  - fDelaySeconds: There can be delay between the visual effect being played, and the
        //    creature being added to the area
        //  - nUseAppearAnimation: should this creature play it's "appear" animation when it is
        //    summoned. If zero, it will just fade in somewhere near the target.  If the value is 1
        //    it will use the appear animation, and if it's 2 it will use appear2 (which doesn't exist for most creatures)
        public static NWN.Effect EffectSummonCreature(string sCreatureResref, int nVisualEffectId = VFX_NONE, float fDelaySeconds = 0.0f, int nUseAppearAnimation = 0)
        {
            NWN.Internal.StackPushInteger(nUseAppearAnimation);
            NWN.Internal.StackPushFloat(fDelaySeconds);
            NWN.Internal.StackPushInteger(nVisualEffectId);
            NWN.Internal.StackPushString(sCreatureResref);
            NWN.Internal.CallBuiltIn(83);
            return NWN.Internal.StackPopEffect();
        }

        //  Get the level at which this creature cast it's last spell (or spell-like ability)
        //  * Return value on error, or if oCreature has not yet cast a spell: 0;
        public static int GetCasterLevel(NWN.Object oCreature)
        {
            NWN.Internal.StackPushObject(oCreature, false);
            NWN.Internal.CallBuiltIn(84);
            return NWN.Internal.StackPopInteger();
        }

        //  Get the first in-game effect on oCreature.
        public static NWN.Effect GetFirstEffect(NWN.Object oCreature)
        {
            NWN.Internal.StackPushObject(oCreature, false);
            NWN.Internal.CallBuiltIn(85);
            return NWN.Internal.StackPopEffect();
        }

        //  Get the next in-game effect on oCreature.
        public static NWN.Effect GetNextEffect(NWN.Object oCreature)
        {
            NWN.Internal.StackPushObject(oCreature, false);
            NWN.Internal.CallBuiltIn(86);
            return NWN.Internal.StackPopEffect();
        }

        //  Remove eEffect from oCreature.
        //  * No return value
        public static void RemoveEffect(NWN.Object oCreature, NWN.Effect eEffect)
        {
            NWN.Internal.StackPushEffect(eEffect);
            NWN.Internal.StackPushObject(oCreature, false);
            NWN.Internal.CallBuiltIn(87);
        }

        //  * Returns TRUE if eEffect is a valid effect. The effect must have been applied to
        //  * an object or else it will return FALSE
        public static int GetIsEffectValid(NWN.Effect eEffect)
        {
            NWN.Internal.StackPushEffect(eEffect);
            NWN.Internal.CallBuiltIn(88);
            return NWN.Internal.StackPopInteger();
        }

        //  Get the duration type (DURATION_TYPE_*) of eEffect.
        //  * Return value if eEffect is not valid: -1
        public static int GetEffectDurationType(NWN.Effect eEffect)
        {
            NWN.Internal.StackPushEffect(eEffect);
            NWN.Internal.CallBuiltIn(89);
            return NWN.Internal.StackPopInteger();
        }

        //  Get the subtype (SUBTYPE_*) of eEffect.
        //  * Return value on error: 0
        public static int GetEffectSubType(NWN.Effect eEffect)
        {
            NWN.Internal.StackPushEffect(eEffect);
            NWN.Internal.CallBuiltIn(90);
            return NWN.Internal.StackPopInteger();
        }

        //  Get the object that created eEffect.
        //  * Returns OBJECT_INVALID if eEffect is not a valid effect.
        public static NWN.Object GetEffectCreator(NWN.Effect eEffect)
        {
            NWN.Internal.StackPushEffect(eEffect);
            NWN.Internal.CallBuiltIn(91);
            return NWN.Internal.StackPopObject();
        }

        //  Convert nInteger into a string.
        //  * Return value on error: ""
        public static string IntToString(int nInteger)
        {
            NWN.Internal.StackPushInteger(nInteger);
            NWN.Internal.CallBuiltIn(92);
            return NWN.Internal.StackPopString();
        }

        //  Get the first object in oArea.
        //  If no valid area is specified, it will use the caller's area.
        //  * Return value on error: OBJECT_INVALID
        public static NWN.Object GetFirstObjectInArea(NWN.Object oArea = null)
        {
            NWN.Internal.StackPushObject(oArea, false);
            NWN.Internal.CallBuiltIn(93);
            return NWN.Internal.StackPopObject();
        }

        //  Get the next object in oArea.
        //  If no valid area is specified, it will use the caller's area.
        //  * Return value on error: OBJECT_INVALID
        public static NWN.Object GetNextObjectInArea(NWN.Object oArea = null)
        {
            NWN.Internal.StackPushObject(oArea, false);
            NWN.Internal.CallBuiltIn(94);
            return NWN.Internal.StackPopObject();
        }

        //  Get the total from rolling (nNumDice x d2 dice).
        //  - nNumDice: If this is less than 1, the value 1 will be used.
        public static int d2(int nNumDice = 1)
        {
            NWN.Internal.StackPushInteger(nNumDice);
            NWN.Internal.CallBuiltIn(95);
            return NWN.Internal.StackPopInteger();
        }

        //  Get the total from rolling (nNumDice x d3 dice).
        //  - nNumDice: If this is less than 1, the value 1 will be used.
        public static int d3(int nNumDice = 1)
        {
            NWN.Internal.StackPushInteger(nNumDice);
            NWN.Internal.CallBuiltIn(96);
            return NWN.Internal.StackPopInteger();
        }

        //  Get the total from rolling (nNumDice x d4 dice).
        //  - nNumDice: If this is less than 1, the value 1 will be used.
        public static int d4(int nNumDice = 1)
        {
            NWN.Internal.StackPushInteger(nNumDice);
            NWN.Internal.CallBuiltIn(97);
            return NWN.Internal.StackPopInteger();
        }

        //  Get the total from rolling (nNumDice x d6 dice).
        //  - nNumDice: If this is less than 1, the value 1 will be used.
        public static int d6(int nNumDice = 1)
        {
            NWN.Internal.StackPushInteger(nNumDice);
            NWN.Internal.CallBuiltIn(98);
            return NWN.Internal.StackPopInteger();
        }

        //  Get the total from rolling (nNumDice x d8 dice).
        //  - nNumDice: If this is less than 1, the value 1 will be used.
        public static int d8(int nNumDice = 1)
        {
            NWN.Internal.StackPushInteger(nNumDice);
            NWN.Internal.CallBuiltIn(99);
            return NWN.Internal.StackPopInteger();
        }

        //  Get the total from rolling (nNumDice x d10 dice).
        //  - nNumDice: If this is less than 1, the value 1 will be used.
        public static int d10(int nNumDice = 1)
        {
            NWN.Internal.StackPushInteger(nNumDice);
            NWN.Internal.CallBuiltIn(100);
            return NWN.Internal.StackPopInteger();
        }

        //  Get the total from rolling (nNumDice x d12 dice).
        //  - nNumDice: If this is less than 1, the value 1 will be used.
        public static int d12(int nNumDice = 1)
        {
            NWN.Internal.StackPushInteger(nNumDice);
            NWN.Internal.CallBuiltIn(101);
            return NWN.Internal.StackPopInteger();
        }

        //  Get the total from rolling (nNumDice x d20 dice).
        //  - nNumDice: If this is less than 1, the value 1 will be used.
        public static int d20(int nNumDice = 1)
        {
            NWN.Internal.StackPushInteger(nNumDice);
            NWN.Internal.CallBuiltIn(102);
            return NWN.Internal.StackPopInteger();
        }

        //  Get the total from rolling (nNumDice x d100 dice).
        //  - nNumDice: If this is less than 1, the value 1 will be used.
        public static int d100(int nNumDice = 1)
        {
            NWN.Internal.StackPushInteger(nNumDice);
            NWN.Internal.CallBuiltIn(103);
            return NWN.Internal.StackPopInteger();
        }

        //  Get the magnitude of vVector; this can be used to determine the
        //  distance between two points.
        //  * Return value on error: 0.0f
        public static float VectorMagnitude(NWN.Vector? vVector)
        {
            NWN.Internal.StackPushVector(vVector);
            NWN.Internal.CallBuiltIn(104);
            return NWN.Internal.StackPopFloat();
        }

        //  Get the metamagic type (METAMAGIC_*) of the last spell cast by the caller
        //  * Return value if the caster is not a valid object: -1
        public static int GetMetaMagicFeat()
        {
            NWN.Internal.CallBuiltIn(105);
            return NWN.Internal.StackPopInteger();
        }

        //  Get the object type (OBJECT_TYPE_*) of oTarget
        //  * Return value if oTarget is not a valid object: -1
        public static int GetObjectType(NWN.Object oTarget)
        {
            NWN.Internal.StackPushObject(oTarget, false);
            NWN.Internal.CallBuiltIn(106);
            return NWN.Internal.StackPopInteger();
        }

        //  Get the racial type (RACIAL_TYPE_*) of oCreature
        //  * Return value if oCreature is not a valid creature: RACIAL_TYPE_INVALID
        public static int GetRacialType(NWN.Object oCreature)
        {
            NWN.Internal.StackPushObject(oCreature, false);
            NWN.Internal.CallBuiltIn(107);
            return NWN.Internal.StackPopInteger();
        }

        //  Do a Fortitude Save check for the given DC
        //  - oCreature
        //  - nDC: Difficulty check
        //  - nSaveType: SAVING_THROW_TYPE_*
        //  - oSaveVersus
        //  Returns: 0 if the saving throw roll failed
        //  Returns: 1 if the saving throw roll succeeded
        //  Returns: 2 if the target was immune to the save type specified
        //  Note: If used within an Area of Effect Object Script (On Enter, OnExit, OnHeartbeat), you MUST pass
        //  GetAreaOfEffectCreator() into oSaveVersus!!
        public static int FortitudeSave(NWN.Object oCreature, int nDC, int nSaveType = SAVING_THROW_TYPE_NONE, NWN.Object oSaveVersus = null)
        {
            NWN.Internal.StackPushObject(oSaveVersus, false);
            NWN.Internal.StackPushInteger(nSaveType);
            NWN.Internal.StackPushInteger(nDC);
            NWN.Internal.StackPushObject(oCreature, false);
            NWN.Internal.CallBuiltIn(108);
            return NWN.Internal.StackPopInteger();
        }

        //  Does a Reflex Save check for the given DC
        //  - oCreature
        //  - nDC: Difficulty check
        //  - nSaveType: SAVING_THROW_TYPE_*
        //  - oSaveVersus
        //  Returns: 0 if the saving throw roll failed
        //  Returns: 1 if the saving throw roll succeeded
        //  Returns: 2 if the target was immune to the save type specified
        //  Note: If used within an Area of Effect Object Script (On Enter, OnExit, OnHeartbeat), you MUST pass
        //  GetAreaOfEffectCreator() into oSaveVersus!!
        public static int ReflexSave(NWN.Object oCreature, int nDC, int nSaveType = SAVING_THROW_TYPE_NONE, NWN.Object oSaveVersus = null)
        {
            NWN.Internal.StackPushObject(oSaveVersus, false);
            NWN.Internal.StackPushInteger(nSaveType);
            NWN.Internal.StackPushInteger(nDC);
            NWN.Internal.StackPushObject(oCreature, false);
            NWN.Internal.CallBuiltIn(109);
            return NWN.Internal.StackPopInteger();
        }

        //  Does a Will Save check for the given DC
        //  - oCreature
        //  - nDC: Difficulty check
        //  - nSaveType: SAVING_THROW_TYPE_*
        //  - oSaveVersus
        //  Returns: 0 if the saving throw roll failed
        //  Returns: 1 if the saving throw roll succeeded
        //  Returns: 2 if the target was immune to the save type specified
        //  Note: If used within an Area of Effect Object Script (On Enter, OnExit, OnHeartbeat), you MUST pass
        //  GetAreaOfEffectCreator() into oSaveVersus!!
        public static int WillSave(NWN.Object oCreature, int nDC, int nSaveType = SAVING_THROW_TYPE_NONE, NWN.Object oSaveVersus = null)
        {
            NWN.Internal.StackPushObject(oSaveVersus, false);
            NWN.Internal.StackPushInteger(nSaveType);
            NWN.Internal.StackPushInteger(nDC);
            NWN.Internal.StackPushObject(oCreature, false);
            NWN.Internal.CallBuiltIn(110);
            return NWN.Internal.StackPopInteger();
        }

        //  Get the DC to save against for a spell (10 + spell level + relevant ability
        //  bonus).  This can be called by a creature or by an Area of Effect object.
        public static int GetSpellSaveDC()
        {
            NWN.Internal.CallBuiltIn(111);
            return NWN.Internal.StackPopInteger();
        }

        //  Set the subtype of eEffect to Magical and return eEffect.
        //  (Effects default to magical if the subtype is not set)
        //  Magical effects are removed by resting, and by dispel magic
        public static NWN.Effect MagicalEffect(NWN.Effect eEffect)
        {
            NWN.Internal.StackPushEffect(eEffect);
            NWN.Internal.CallBuiltIn(112);
            return NWN.Internal.StackPopEffect();
        }

        //  Set the subtype of eEffect to Supernatural and return eEffect.
        //  (Effects default to magical if the subtype is not set)
        //  Permanent supernatural effects are not removed by resting
        public static NWN.Effect SupernaturalEffect(NWN.Effect eEffect)
        {
            NWN.Internal.StackPushEffect(eEffect);
            NWN.Internal.CallBuiltIn(113);
            return NWN.Internal.StackPopEffect();
        }

        //  Set the subtype of eEffect to Extraordinary and return eEffect.
        //  (Effects default to magical if the subtype is not set)
        //  Extraordinary effects are removed by resting, but not by dispel magic
        public static NWN.Effect ExtraordinaryEffect(NWN.Effect eEffect)
        {
            NWN.Internal.StackPushEffect(eEffect);
            NWN.Internal.CallBuiltIn(114);
            return NWN.Internal.StackPopEffect();
        }

        //  Create an AC Increase effect
        //  - nValue: size of AC increase
        //  - nModifyType: AC_*_BONUS
        //  - nDamageType: DAMAGE_TYPE_*
        //    * Default value for nDamageType should only ever be used in this function prototype.
        public static NWN.Effect EffectACIncrease(int nValue, int nModifyType = AC_DODGE_BONUS, int nDamageType = AC_VS_DAMAGE_TYPE_ALL)
        {
            NWN.Internal.StackPushInteger(nDamageType);
            NWN.Internal.StackPushInteger(nModifyType);
            NWN.Internal.StackPushInteger(nValue);
            NWN.Internal.CallBuiltIn(115);
            return NWN.Internal.StackPopEffect();
        }

        //  If oObject is a creature, this will return that creature's armour class
        //  If oObject is an item, door or placeable, this will return zero.
        //  - nForFutureUse: this parameter is not currently used
        //  * Return value if oObject is not a creature, item, door or placeable: -1
        public static int GetAC(NWN.Object oObject, int nForFutureUse = 0)
        {
            NWN.Internal.StackPushInteger(nForFutureUse);
            NWN.Internal.StackPushObject(oObject, false);
            NWN.Internal.CallBuiltIn(116);
            return NWN.Internal.StackPopInteger();
        }

        //  Create a Saving Throw Increase effect
        //  - nSave: SAVING_THROW_* (not SAVING_THROW_TYPE_*)
        //           SAVING_THROW_ALL
        //           SAVING_THROW_FORT
        //           SAVING_THROW_REFLEX
        //           SAVING_THROW_WILL 
        //  - nValue: size of the Saving Throw increase
        //  - nSaveType: SAVING_THROW_TYPE_* (e.g. SAVING_THROW_TYPE_ACID )
        public static NWN.Effect EffectSavingThrowIncrease(int nSave, int nValue, int nSaveType = SAVING_THROW_TYPE_ALL)
        {
            NWN.Internal.StackPushInteger(nSaveType);
            NWN.Internal.StackPushInteger(nValue);
            NWN.Internal.StackPushInteger(nSave);
            NWN.Internal.CallBuiltIn(117);
            return NWN.Internal.StackPopEffect();
        }

        //  Create an Attack Increase effect
        //  - nBonus: size of attack bonus
        //  - nModifierType: ATTACK_BONUS_*
        public static NWN.Effect EffectAttackIncrease(int nBonus, int nModifierType = ATTACK_BONUS_MISC)
        {
            NWN.Internal.StackPushInteger(nModifierType);
            NWN.Internal.StackPushInteger(nBonus);
            NWN.Internal.CallBuiltIn(118);
            return NWN.Internal.StackPopEffect();
        }

        //  Create a Damage Reduction effect
        //  - nAmount: amount of damage reduction
        //  - nDamagePower: DAMAGE_POWER_*
        //  - nLimit: How much damage the effect can absorb before disappearing.
        //    Set to zero for infinite
        public static NWN.Effect EffectDamageReduction(int nAmount, int nDamagePower, int nLimit = 0)
        {
            NWN.Internal.StackPushInteger(nLimit);
            NWN.Internal.StackPushInteger(nDamagePower);
            NWN.Internal.StackPushInteger(nAmount);
            NWN.Internal.CallBuiltIn(119);
            return NWN.Internal.StackPopEffect();
        }

        //  Create a Damage Increase effect
        //  - nBonus: DAMAGE_BONUS_*
        //  - nDamageType: DAMAGE_TYPE_*
        //  NOTE! You *must* use the DAMAGE_BONUS_* constants! Using other values may
        //        result in odd behaviour.
        public static NWN.Effect EffectDamageIncrease(int nBonus, int nDamageType = DAMAGE_TYPE_MAGICAL)
        {
            NWN.Internal.StackPushInteger(nDamageType);
            NWN.Internal.StackPushInteger(nBonus);
            NWN.Internal.CallBuiltIn(120);
            return NWN.Internal.StackPopEffect();
        }

        //  Convert nRounds into a number of seconds
        //  A round is always 6.0 seconds
        public static float RoundsToSeconds(int nRounds)
        {
            NWN.Internal.StackPushInteger(nRounds);
            NWN.Internal.CallBuiltIn(121);
            return NWN.Internal.StackPopFloat();
        }

        //  Convert nHours into a number of seconds
        //  The result will depend on how many minutes there are per hour (game-time)
        public static float HoursToSeconds(int nHours)
        {
            NWN.Internal.StackPushInteger(nHours);
            NWN.Internal.CallBuiltIn(122);
            return NWN.Internal.StackPopFloat();
        }

        //  Convert nTurns into a number of seconds
        //  A turn is always 60.0 seconds
        public static float TurnsToSeconds(int nTurns)
        {
            NWN.Internal.StackPushInteger(nTurns);
            NWN.Internal.CallBuiltIn(123);
            return NWN.Internal.StackPopFloat();
        }

        //  Get an integer between 0 and 100 (inclusive) to represent oCreature's
        //  Law/Chaos alignment
        //  (100=law, 0=chaos)
        //  * Return value if oCreature is not a valid creature: -1
        public static int GetLawChaosValue(NWN.Object oCreature)
        {
            NWN.Internal.StackPushObject(oCreature, false);
            NWN.Internal.CallBuiltIn(124);
            return NWN.Internal.StackPopInteger();
        }

        //  Get an integer between 0 and 100 (inclusive) to represent oCreature's
        //  Good/Evil alignment
        //  (100=good, 0=evil)
        //  * Return value if oCreature is not a valid creature: -1
        public static int GetGoodEvilValue(NWN.Object oCreature)
        {
            NWN.Internal.StackPushObject(oCreature, false);
            NWN.Internal.CallBuiltIn(125);
            return NWN.Internal.StackPopInteger();
        }

        //  Return an ALIGNMENT_* constant to represent oCreature's law/chaos alignment
        //  * Return value if oCreature is not a valid creature: -1
        public static int GetAlignmentLawChaos(NWN.Object oCreature)
        {
            NWN.Internal.StackPushObject(oCreature, false);
            NWN.Internal.CallBuiltIn(126);
            return NWN.Internal.StackPopInteger();
        }

        //  Return an ALIGNMENT_* constant to represent oCreature's good/evil alignment
        //  * Return value if oCreature is not a valid creature: -1
        public static int GetAlignmentGoodEvil(NWN.Object oCreature)
        {
            NWN.Internal.StackPushObject(oCreature, false);
            NWN.Internal.CallBuiltIn(127);
            return NWN.Internal.StackPopInteger();
        }

        //  Get the first object in nShape
        //  - nShape: SHAPE_*
        //  - fSize:
        //    -> If nShape == SHAPE_SPHERE, this is the radius of the sphere
        //    -> If nShape == SHAPE_SPELLCYLINDER, this is the length of the cylinder
        //       Spell Cylinder's always have a radius of 1.5m.
        //    -> If nShape == SHAPE_CONE, this is the widest radius of the cone
        //    -> If nShape == SHAPE_SPELLCONE, this is the length of the cone in the
        //       direction of lTarget. Spell cones are always 60 degrees with the origin
        //       at OBJECT_SELF.
        //    -> If nShape == SHAPE_CUBE, this is half the length of one of the sides of
        //       the cube
        //  - lTarget: This is the centre of the effect, usually GetSpellTargetLocation(),
        //    or the end of a cylinder or cone.
        //  - bLineOfSight: This controls whether to do a line-of-sight check on the
        //    object returned. Line of sight check is done from origin to target object
        //    at a height 1m above the ground
        //    (This can be used to ensure that spell effects do not go through walls.)
        //  - nObjectFilter: This allows you to filter out undesired object types, using
        //    bitwise "or".
        //    For example, to return only creatures and doors, the value for this
        //    parameter would be OBJECT_TYPE_CREATURE | OBJECT_TYPE_DOOR
        //  - vOrigin: This is only used for cylinders and cones, and specifies the
        //    origin of the effect(normally the spell-caster's position).
        //  Return value on error: OBJECT_INVALID
        public static NWN.Object GetFirstObjectInShape(int nShape, float fSize, NWN.Location lTarget, int bLineOfSight = FALSE, int nObjectFilter = OBJECT_TYPE_CREATURE, NWN.Vector? vOrigin = null)
        {
            NWN.Internal.StackPushVector(vOrigin);
            NWN.Internal.StackPushInteger(nObjectFilter);
            NWN.Internal.StackPushInteger(bLineOfSight);
            NWN.Internal.StackPushLocation(lTarget);
            NWN.Internal.StackPushFloat(fSize);
            NWN.Internal.StackPushInteger(nShape);
            NWN.Internal.CallBuiltIn(128);
            return NWN.Internal.StackPopObject();
        }

        //  Get the next object in nShape
        //  - nShape: SHAPE_*
        //  - fSize:
        //    -> If nShape == SHAPE_SPHERE, this is the radius of the sphere
        //    -> If nShape == SHAPE_SPELLCYLINDER, this is the length of the cylinder.
        //       Spell Cylinder's always have a radius of 1.5m.
        //    -> If nShape == SHAPE_CONE, this is the widest radius of the cone
        //    -> If nShape == SHAPE_SPELLCONE, this is the length of the cone in the
        //       direction of lTarget. Spell cones are always 60 degrees with the origin
        //       at OBJECT_SELF.
        //    -> If nShape == SHAPE_CUBE, this is half the length of one of the sides of
        //       the cube
        //  - lTarget: This is the centre of the effect, usually GetSpellTargetLocation(),
        //    or the end of a cylinder or cone.
        //  - bLineOfSight: This controls whether to do a line-of-sight check on the
        //    object returned. (This can be used to ensure that spell effects do not go
        //    through walls.) Line of sight check is done from origin to target object
        //    at a height 1m above the ground
        //  - nObjectFilter: This allows you to filter out undesired object types, using
        //    bitwise "or". For example, to return only creatures and doors, the value for
        //    this parameter would be OBJECT_TYPE_CREATURE | OBJECT_TYPE_DOOR
        //  - vOrigin: This is only used for cylinders and cones, and specifies the origin
        //    of the effect (normally the spell-caster's position).
        //  Return value on error: OBJECT_INVALID
        public static NWN.Object GetNextObjectInShape(int nShape, float fSize, NWN.Location lTarget, int bLineOfSight = FALSE, int nObjectFilter = OBJECT_TYPE_CREATURE, NWN.Vector? vOrigin = null)
        {
            NWN.Internal.StackPushVector(vOrigin);
            NWN.Internal.StackPushInteger(nObjectFilter);
            NWN.Internal.StackPushInteger(bLineOfSight);
            NWN.Internal.StackPushLocation(lTarget);
            NWN.Internal.StackPushFloat(fSize);
            NWN.Internal.StackPushInteger(nShape);
            NWN.Internal.CallBuiltIn(129);
            return NWN.Internal.StackPopObject();
        }

        //  Create an Entangle effect
        //  When applied, this effect will restrict the creature's movement and apply a
        //  (-2) to all attacks and a -4 to AC.
        public static NWN.Effect EffectEntangle()
        {
            NWN.Internal.CallBuiltIn(130);
            return NWN.Internal.StackPopEffect();
        }

        //  Causes object oObject to run the event evToRun. The script on the object that is
        //  associated with the event specified will run.
        //  Events can be created using the following event functions:
        //     EventActivateItem() - This creates an OnActivateItem module event. The script for handling
        //                           this event can be set in Module Properties on the Event Tab.
        //     EventConversation() - This creates on OnConversation creature event. The script for handling
        //                           this event can be set by viewing the Creature Properties on a 
        //                           creature and then clicking on the Scripts Tab.
        //     EventSpellCastAt()  - This creates an OnSpellCastAt event. The script for handling this
        //                           event can be set in the Scripts Tab of the Properties menu 
        //                           for the object.
        //     EventUserDefined()  - This creates on OnUserDefined event. The script for handling this event
        //                           can be set in the Scripts Tab of the Properties menu for the object/area/module.
        public static void SignalEvent(NWN.Object oObject, NWN.Event evToRun)
        {
            NWN.Internal.StackPushEvent(evToRun);
            NWN.Internal.StackPushObject(oObject, false);
            NWN.Internal.CallBuiltIn(131);
        }

        //  Create an event of the type nUserDefinedEventNumber
        //  Note: This only creates the event. The event wont actually trigger until SignalEvent()
        //  is called using this created UserDefined event as an argument.
        //  For example:
        //      SignalEvent(oObject, EventUserDefined(9999));
        //  Once the event has been signaled. The script associated with the OnUserDefined event will
        //  run on the object oObject.
        // 
        //  To specify the OnUserDefined script that should run, view the object's Properties
        //  and click on the Scripts Tab. Then specify a script for the OnUserDefined event.
        //  From inside the OnUserDefined script call:
        //     GetUserDefinedEventNumber() to retrieve the value of nUserDefinedEventNumber
        //     that was used when the event was signaled.
        public static NWN.Event EventUserDefined(int nUserDefinedEventNumber)
        {
            NWN.Internal.StackPushInteger(nUserDefinedEventNumber);
            NWN.Internal.CallBuiltIn(132);
            return NWN.Internal.StackPopEvent();
        }

        //  Create a Death effect
        //  - nSpectacularDeath: if this is TRUE, the creature to which this effect is
        //    applied will die in an extraordinary fashion
        //  - nDisplayFeedback
        public static NWN.Effect EffectDeath(int nSpectacularDeath = FALSE, int nDisplayFeedback = TRUE)
        {
            NWN.Internal.StackPushInteger(nDisplayFeedback);
            NWN.Internal.StackPushInteger(nSpectacularDeath);
            NWN.Internal.CallBuiltIn(133);
            return NWN.Internal.StackPopEffect();
        }

        //  Create a Knockdown effect
        //  This effect knocks creatures off their feet, they will sit until the effect
        //  is removed. This should be applied as a temporary effect with a 3 second
        //  duration minimum (1 second to fall, 1 second sitting, 1 second to get up).
        public static NWN.Effect EffectKnockdown()
        {
            NWN.Internal.CallBuiltIn(134);
            return NWN.Internal.StackPopEffect();
        }

        //  Give oItem to oGiveTo
        //  If oItem is not a valid item, or oGiveTo is not a valid object, nothing will
        //  happen.
        public static void ActionGiveItem(NWN.Object oItem, NWN.Object oGiveTo)
        {
            NWN.Internal.StackPushObject(oGiveTo, false);
            NWN.Internal.StackPushObject(oItem, false);
            NWN.Internal.CallBuiltIn(135);
        }

        //  Take oItem from oTakeFrom
        //  If oItem is not a valid item, or oTakeFrom is not a valid object, nothing
        //  will happen.
        public static void ActionTakeItem(NWN.Object oItem, NWN.Object oTakeFrom)
        {
            NWN.Internal.StackPushObject(oTakeFrom, false);
            NWN.Internal.StackPushObject(oItem, false);
            NWN.Internal.CallBuiltIn(136);
        }

        //  Normalize vVector
        public static NWN.Vector VectorNormalize(NWN.Vector? vVector)
        {
            NWN.Internal.StackPushVector(vVector);
            NWN.Internal.CallBuiltIn(137);
            return NWN.Internal.StackPopVector();
        }

        //  Create a Curse effect.
        //  - nStrMod: strength modifier
        //  - nDexMod: dexterity modifier
        //  - nConMod: constitution modifier
        //  - nIntMod: intelligence modifier
        //  - nWisMod: wisdom modifier
        //  - nChaMod: charisma modifier
        public static NWN.Effect EffectCurse(int nStrMod = 1, int nDexMod = 1, int nConMod = 1, int nIntMod = 1, int nWisMod = 1, int nChaMod = 1)
        {
            NWN.Internal.StackPushInteger(nChaMod);
            NWN.Internal.StackPushInteger(nWisMod);
            NWN.Internal.StackPushInteger(nIntMod);
            NWN.Internal.StackPushInteger(nConMod);
            NWN.Internal.StackPushInteger(nDexMod);
            NWN.Internal.StackPushInteger(nStrMod);
            NWN.Internal.CallBuiltIn(138);
            return NWN.Internal.StackPopEffect();
        }

        //  Get the ability score of type nAbility for a creature (otherwise 0)
        //  - oCreature: the creature whose ability score we wish to find out
        //  - nAbilityType: ABILITY_*
        //  - nBaseAbilityScore: if set to true will return the base ability score without
        //                       bonuses (e.g. ability bonuses granted from equipped items).
        //  Return value on error: 0
        public static int GetAbilityScore(NWN.Object oCreature, int nAbilityType, int nBaseAbilityScore = FALSE)
        {
            NWN.Internal.StackPushInteger(nBaseAbilityScore);
            NWN.Internal.StackPushInteger(nAbilityType);
            NWN.Internal.StackPushObject(oCreature, false);
            NWN.Internal.CallBuiltIn(139);
            return NWN.Internal.StackPopInteger();
        }

        //  * Returns TRUE if oCreature is a dead NPC, dead PC or a dying PC.
        public static int GetIsDead(NWN.Object oCreature)
        {
            NWN.Internal.StackPushObject(oCreature, false);
            NWN.Internal.CallBuiltIn(140);
            return NWN.Internal.StackPopInteger();
        }

        //  Output vVector to the logfile.
        //  - vVector
        //  - bPrepend: if this is TRUE, the message will be prefixed with "PRINTVECTOR:"
        public static void PrintVector(NWN.Vector? vVector, int bPrepend)
        {
            NWN.Internal.StackPushInteger(bPrepend);
            NWN.Internal.StackPushVector(vVector);
            NWN.Internal.CallBuiltIn(141);
        }

        //  Create a vector with the specified values for x, y and z
        public static NWN.Vector Vector(float x = 0.0f, float y = 0.0f, float z = 0.0f)
        {
            NWN.Internal.StackPushFloat(z);
            NWN.Internal.StackPushFloat(y);
            NWN.Internal.StackPushFloat(x);
            NWN.Internal.CallBuiltIn(142);
            return NWN.Internal.StackPopVector();
        }

        //  Cause the caller to face vTarget
        public static void SetFacingPoint(NWN.Vector? vTarget)
        {
            NWN.Internal.StackPushVector(vTarget);
            NWN.Internal.CallBuiltIn(143);
        }

        //  Convert fAngle to a vector
        public static NWN.Vector AngleToVector(float fAngle)
        {
            NWN.Internal.StackPushFloat(fAngle);
            NWN.Internal.CallBuiltIn(144);
            return NWN.Internal.StackPopVector();
        }

        //  Convert vVector to an angle
        public static float VectorToAngle(NWN.Vector? vVector)
        {
            NWN.Internal.StackPushVector(vVector);
            NWN.Internal.CallBuiltIn(145);
            return NWN.Internal.StackPopFloat();
        }

        //  The caller will perform a Melee Touch Attack on oTarget
        //  This is not an action, and it assumes the caller is already within range of
        //  oTarget
        //  * Returns 0 on a miss, 1 on a hit and 2 on a critical hit
        public static int TouchAttackMelee(NWN.Object oTarget, int bDisplayFeedback = TRUE)
        {
            NWN.Internal.StackPushInteger(bDisplayFeedback);
            NWN.Internal.StackPushObject(oTarget, false);
            NWN.Internal.CallBuiltIn(146);
            return NWN.Internal.StackPopInteger();
        }

        //  The caller will perform a Ranged Touch Attack on oTarget
        //  * Returns 0 on a miss, 1 on a hit and 2 on a critical hit
        public static int TouchAttackRanged(NWN.Object oTarget, int bDisplayFeedback = TRUE)
        {
            NWN.Internal.StackPushInteger(bDisplayFeedback);
            NWN.Internal.StackPushObject(oTarget, false);
            NWN.Internal.CallBuiltIn(147);
            return NWN.Internal.StackPopInteger();
        }

        //  Create a Paralyze effect
        public static NWN.Effect EffectParalyze()
        {
            NWN.Internal.CallBuiltIn(148);
            return NWN.Internal.StackPopEffect();
        }

        //  Create a Spell Immunity effect.
        //  There is a known bug with this function. There *must* be a parameter specified
        //  when this is called (even if the desired parameter is SPELL_ALL_SPELLS),
        //  otherwise an effect of type EFFECT_TYPE_INVALIDEFFECT will be returned.
        //  - nImmunityToSpell: SPELL_*
        //  * Returns an effect of type EFFECT_TYPE_INVALIDEFFECT if nImmunityToSpell is
        //    invalid.
        public static NWN.Effect EffectSpellImmunity(int nImmunityToSpell = SPELL_ALL_SPELLS)
        {
            NWN.Internal.StackPushInteger(nImmunityToSpell);
            NWN.Internal.CallBuiltIn(149);
            return NWN.Internal.StackPopEffect();
        }

        //  Create a Deaf effect
        public static NWN.Effect EffectDeaf()
        {
            NWN.Internal.CallBuiltIn(150);
            return NWN.Internal.StackPopEffect();
        }

        //  Get the distance in metres between oObjectA and oObjectB.
        //  * Return value if either object is invalid: 0.0f
        public static float GetDistanceBetween(NWN.Object oObjectA, NWN.Object oObjectB)
        {
            NWN.Internal.StackPushObject(oObjectB, false);
            NWN.Internal.StackPushObject(oObjectA, false);
            NWN.Internal.CallBuiltIn(151);
            return NWN.Internal.StackPopFloat();
        }

        //  Set oObject's local location variable sVarname to lValue
        public static void SetLocalLocation(NWN.Object oObject, string sVarName, NWN.Location lValue)
        {
            NWN.Internal.StackPushLocation(lValue);
            NWN.Internal.StackPushString(sVarName);
            NWN.Internal.StackPushObject(oObject, false);
            NWN.Internal.CallBuiltIn(152);
        }

        //  Get oObject's local location variable sVarname
        public static NWN.Location GetLocalLocation(NWN.Object oObject, string sVarName)
        {
            NWN.Internal.StackPushString(sVarName);
            NWN.Internal.StackPushObject(oObject, false);
            NWN.Internal.CallBuiltIn(153);
            return NWN.Internal.StackPopLocation();
        }

        //  Create a Sleep effect
        public static NWN.Effect EffectSleep()
        {
            NWN.Internal.CallBuiltIn(154);
            return NWN.Internal.StackPopEffect();
        }

        //  Get the object which is in oCreature's specified inventory slot
        //  - nInventorySlot: INVENTORY_SLOT_*
        //  - oCreature
        //  * Returns OBJECT_INVALID if oCreature is not a valid creature or there is no
        //    item in nInventorySlot.
        public static NWN.Object GetItemInSlot(int nInventorySlot, NWN.Object oCreature = null)
        {
            NWN.Internal.StackPushObject(oCreature, false);
            NWN.Internal.StackPushInteger(nInventorySlot);
            NWN.Internal.CallBuiltIn(155);
            return NWN.Internal.StackPopObject();
        }

        //  Create a Charm effect
        public static NWN.Effect EffectCharmed()
        {
            NWN.Internal.CallBuiltIn(156);
            return NWN.Internal.StackPopEffect();
        }

        //  Create a Confuse effect
        public static NWN.Effect EffectConfused()
        {
            NWN.Internal.CallBuiltIn(157);
            return NWN.Internal.StackPopEffect();
        }

        //  Create a Frighten effect
        public static NWN.Effect EffectFrightened()
        {
            NWN.Internal.CallBuiltIn(158);
            return NWN.Internal.StackPopEffect();
        }

        //  Create a Dominate effect
        public static NWN.Effect EffectDominated()
        {
            NWN.Internal.CallBuiltIn(159);
            return NWN.Internal.StackPopEffect();
        }

        //  Create a Daze effect
        public static NWN.Effect EffectDazed()
        {
            NWN.Internal.CallBuiltIn(160);
            return NWN.Internal.StackPopEffect();
        }

        //  Create a Stun effect
        public static NWN.Effect EffectStunned()
        {
            NWN.Internal.CallBuiltIn(161);
            return NWN.Internal.StackPopEffect();
        }

        //  Set whether oTarget's action stack can be modified
        public static void SetCommandable(int bCommandable, NWN.Object oTarget = null)
        {
            NWN.Internal.StackPushObject(oTarget, false);
            NWN.Internal.StackPushInteger(bCommandable);
            NWN.Internal.CallBuiltIn(162);
        }

        //  Determine whether oTarget's action stack can be modified.
        public static int GetCommandable(NWN.Object oTarget = null)
        {
            NWN.Internal.StackPushObject(oTarget, false);
            NWN.Internal.CallBuiltIn(163);
            return NWN.Internal.StackPopInteger();
        }

        //  Create a Regenerate effect.
        //  - nAmount: amount of damage to be regenerated per time interval
        //  - fIntervalSeconds: length of interval in seconds
        public static NWN.Effect EffectRegenerate(int nAmount, float fIntervalSeconds)
        {
            NWN.Internal.StackPushFloat(fIntervalSeconds);
            NWN.Internal.StackPushInteger(nAmount);
            NWN.Internal.CallBuiltIn(164);
            return NWN.Internal.StackPopEffect();
        }

        //  Create a Movement Speed Increase effect.
        //  - nPercentChange - range 0 through 99
        //  eg.
        //     0 = no change in speed
        //    50 = 50% faster
        //    99 = almost twice as fast
        public static NWN.Effect EffectMovementSpeedIncrease(int nPercentChange)
        {
            NWN.Internal.StackPushInteger(nPercentChange);
            NWN.Internal.CallBuiltIn(165);
            return NWN.Internal.StackPopEffect();
        }

        //  Get the number of hitdice for oCreature.
        //  * Return value if oCreature is not a valid creature: 0
        public static int GetHitDice(NWN.Object oCreature)
        {
            NWN.Internal.StackPushObject(oCreature, false);
            NWN.Internal.CallBuiltIn(166);
            return NWN.Internal.StackPopInteger();
        }

        //  The action subject will follow oFollow until a ClearAllActions() is called.
        //  - oFollow: this is the object to be followed
        //  - fFollowDistance: follow distance in metres
        //  * No return value
        public static void ActionForceFollowObject(NWN.Object oFollow, float fFollowDistance = 0.0f)
        {
            NWN.Internal.StackPushFloat(fFollowDistance);
            NWN.Internal.StackPushObject(oFollow, false);
            NWN.Internal.CallBuiltIn(167);
        }

        //  Get the Tag of oObject
        //  * Return value if oObject is not a valid object: ""
        public static string GetTag(NWN.Object oObject)
        {
            NWN.Internal.StackPushObject(oObject, false);
            NWN.Internal.CallBuiltIn(168);
            return NWN.Internal.StackPopString();
        }

        //  Do a Spell Resistance check between oCaster and oTarget, returning TRUE if
        //  the spell was resisted.
        //  * Return value if oCaster or oTarget is an invalid object: FALSE
        //  * Return value if spell cast is not a player spell: - 1
        //  * Return value if spell resisted: 1
        //  * Return value if spell resisted via magic immunity: 2
        //  * Return value if spell resisted via spell absorption: 3
        public static int ResistSpell(NWN.Object oCaster, NWN.Object oTarget)
        {
            NWN.Internal.StackPushObject(oTarget, false);
            NWN.Internal.StackPushObject(oCaster, false);
            NWN.Internal.CallBuiltIn(169);
            return NWN.Internal.StackPopInteger();
        }

        //  Get the effect type (EFFECT_TYPE_*) of eEffect.
        //  * Return value if eEffect is invalid: EFFECT_INVALIDEFFECT
        public static int GetEffectType(NWN.Effect eEffect)
        {
            NWN.Internal.StackPushEffect(eEffect);
            NWN.Internal.CallBuiltIn(170);
            return NWN.Internal.StackPopInteger();
        }

        //  Create an Area Of Effect effect in the area of the creature it is applied to.
        //  If the scripts are not specified, default ones will be used.
        public static NWN.Effect EffectAreaOfEffect(int nAreaEffectId, string sOnEnterScript = "", string sHeartbeatScript = "", string sOnExitScript = "")
        {
            NWN.Internal.StackPushString(sOnExitScript);
            NWN.Internal.StackPushString(sHeartbeatScript);
            NWN.Internal.StackPushString(sOnEnterScript);
            NWN.Internal.StackPushInteger(nAreaEffectId);
            NWN.Internal.CallBuiltIn(171);
            return NWN.Internal.StackPopEffect();
        }

        //  * Returns TRUE if the Faction Ids of the two objects are the same
        public static int GetFactionEqual(NWN.Object oFirstObject, NWN.Object oSecondObject = null)
        {
            NWN.Internal.StackPushObject(oSecondObject, false);
            NWN.Internal.StackPushObject(oFirstObject, false);
            NWN.Internal.CallBuiltIn(172);
            return NWN.Internal.StackPopInteger();
        }

        //  Make oObjectToChangeFaction join the faction of oMemberOfFactionToJoin.
        //  NB. ** This will only work for two NPCs **
        public static void ChangeFaction(NWN.Object oObjectToChangeFaction, NWN.Object oMemberOfFactionToJoin)
        {
            NWN.Internal.StackPushObject(oMemberOfFactionToJoin, false);
            NWN.Internal.StackPushObject(oObjectToChangeFaction, false);
            NWN.Internal.CallBuiltIn(173);
        }

        //  * Returns TRUE if oObject is listening for something
        public static int GetIsListening(NWN.Object oObject)
        {
            NWN.Internal.StackPushObject(oObject, false);
            NWN.Internal.CallBuiltIn(174);
            return NWN.Internal.StackPopInteger();
        }

        //  Set whether oObject is listening.
        public static void SetListening(NWN.Object oObject, int bValue)
        {
            NWN.Internal.StackPushInteger(bValue);
            NWN.Internal.StackPushObject(oObject, false);
            NWN.Internal.CallBuiltIn(175);
        }

        //  Set the string for oObject to listen for.
        //  Note: this does not set oObject to be listening.
        public static void SetListenPattern(NWN.Object oObject, string sPattern, int nNumber = 0)
        {
            NWN.Internal.StackPushInteger(nNumber);
            NWN.Internal.StackPushString(sPattern);
            NWN.Internal.StackPushObject(oObject, false);
            NWN.Internal.CallBuiltIn(176);
        }

        //  * Returns TRUE if sStringToTest matches sPattern.
        public static int TestStringAgainstPattern(string sPattern, string sStringToTest)
        {
            NWN.Internal.StackPushString(sStringToTest);
            NWN.Internal.StackPushString(sPattern);
            NWN.Internal.CallBuiltIn(177);
            return NWN.Internal.StackPopInteger();
        }

        //  Get the appropriate matched string (this should only be used in
        //  OnConversation scripts).
        //  * Returns the appropriate matched string, otherwise returns ""
        public static string GetMatchedSubstring(int nString)
        {
            NWN.Internal.StackPushInteger(nString);
            NWN.Internal.CallBuiltIn(178);
            return NWN.Internal.StackPopString();
        }

        //  Get the number of string parameters available.
        //  * Returns -1 if no string matched (this could be because of a dialogue event)
        public static int GetMatchedSubstringsCount()
        {
            NWN.Internal.CallBuiltIn(179);
            return NWN.Internal.StackPopInteger();
        }

        //  * Create a Visual Effect that can be applied to an object.
        //  - nVisualEffectId
        //  - nMissEffect: if this is TRUE, a random vector near or past the target will
        //    be generated, on which to play the effect
        public static NWN.Effect EffectVisualEffect(int nVisualEffectId, int nMissEffect = FALSE)
        {
            NWN.Internal.StackPushInteger(nMissEffect);
            NWN.Internal.StackPushInteger(nVisualEffectId);
            NWN.Internal.CallBuiltIn(180);
            return NWN.Internal.StackPopEffect();
        }

        //  Get the weakest member of oFactionMember's faction.
        //  * Returns OBJECT_INVALID if oFactionMember's faction is invalid.
        public static NWN.Object GetFactionWeakestMember(NWN.Object oFactionMember = null, int bMustBeVisible = TRUE)
        {
            NWN.Internal.StackPushInteger(bMustBeVisible);
            NWN.Internal.StackPushObject(oFactionMember, false);
            NWN.Internal.CallBuiltIn(181);
            return NWN.Internal.StackPopObject();
        }

        //  Get the strongest member of oFactionMember's faction.
        //  * Returns OBJECT_INVALID if oFactionMember's faction is invalid.
        public static NWN.Object GetFactionStrongestMember(NWN.Object oFactionMember = null, int bMustBeVisible = TRUE)
        {
            NWN.Internal.StackPushInteger(bMustBeVisible);
            NWN.Internal.StackPushObject(oFactionMember, false);
            NWN.Internal.CallBuiltIn(182);
            return NWN.Internal.StackPopObject();
        }

        //  Get the member of oFactionMember's faction that has taken the most hit points
        //  of damage.
        //  * Returns OBJECT_INVALID if oFactionMember's faction is invalid.
        public static NWN.Object GetFactionMostDamagedMember(NWN.Object oFactionMember = null, int bMustBeVisible = TRUE)
        {
            NWN.Internal.StackPushInteger(bMustBeVisible);
            NWN.Internal.StackPushObject(oFactionMember, false);
            NWN.Internal.CallBuiltIn(183);
            return NWN.Internal.StackPopObject();
        }

        //  Get the member of oFactionMember's faction that has taken the fewest hit
        //  points of damage.
        //  * Returns OBJECT_INVALID if oFactionMember's faction is invalid.
        public static NWN.Object GetFactionLeastDamagedMember(NWN.Object oFactionMember = null, int bMustBeVisible = TRUE)
        {
            NWN.Internal.StackPushInteger(bMustBeVisible);
            NWN.Internal.StackPushObject(oFactionMember, false);
            NWN.Internal.CallBuiltIn(184);
            return NWN.Internal.StackPopObject();
        }

        //  Get the amount of gold held by oFactionMember's faction.
        //  * Returns -1 if oFactionMember's faction is invalid.
        public static int GetFactionGold(NWN.Object oFactionMember)
        {
            NWN.Internal.StackPushObject(oFactionMember, false);
            NWN.Internal.CallBuiltIn(185);
            return NWN.Internal.StackPopInteger();
        }

        //  Get an integer between 0 and 100 (inclusive) that represents how
        //  oSourceFactionMember's faction feels about oTarget.
        //  * Return value on error: -1
        public static int GetFactionAverageReputation(NWN.Object oSourceFactionMember, NWN.Object oTarget)
        {
            NWN.Internal.StackPushObject(oTarget, false);
            NWN.Internal.StackPushObject(oSourceFactionMember, false);
            NWN.Internal.CallBuiltIn(186);
            return NWN.Internal.StackPopInteger();
        }

        //  Get an integer between 0 and 100 (inclusive) that represents the average
        //  good/evil alignment of oFactionMember's faction.
        //  * Return value on error: -1
        public static int GetFactionAverageGoodEvilAlignment(NWN.Object oFactionMember)
        {
            NWN.Internal.StackPushObject(oFactionMember, false);
            NWN.Internal.CallBuiltIn(187);
            return NWN.Internal.StackPopInteger();
        }

        //  Get an integer between 0 and 100 (inclusive) that represents the average
        //  law/chaos alignment of oFactionMember's faction.
        //  * Return value on error: -1
        public static int GetFactionAverageLawChaosAlignment(NWN.Object oFactionMember)
        {
            NWN.Internal.StackPushObject(oFactionMember, false);
            NWN.Internal.CallBuiltIn(188);
            return NWN.Internal.StackPopInteger();
        }

        //  Get the average level of the members of the faction.
        //  * Return value on error: -1
        public static int GetFactionAverageLevel(NWN.Object oFactionMember)
        {
            NWN.Internal.StackPushObject(oFactionMember, false);
            NWN.Internal.CallBuiltIn(189);
            return NWN.Internal.StackPopInteger();
        }

        //  Get the average XP of the members of the faction.
        //  * Return value on error: -1
        public static int GetFactionAverageXP(NWN.Object oFactionMember)
        {
            NWN.Internal.StackPushObject(oFactionMember, false);
            NWN.Internal.CallBuiltIn(190);
            return NWN.Internal.StackPopInteger();
        }

        //  Get the most frequent class in the faction - this can be compared with the
        //  constants CLASS_TYPE_*.
        //  * Return value on error: -1
        public static int GetFactionMostFrequentClass(NWN.Object oFactionMember)
        {
            NWN.Internal.StackPushObject(oFactionMember, false);
            NWN.Internal.CallBuiltIn(191);
            return NWN.Internal.StackPopInteger();
        }

        //  Get the object faction member with the lowest armour class.
        //  * Returns OBJECT_INVALID if oFactionMember's faction is invalid.
        public static NWN.Object GetFactionWorstAC(NWN.Object oFactionMember = null, int bMustBeVisible = TRUE)
        {
            NWN.Internal.StackPushInteger(bMustBeVisible);
            NWN.Internal.StackPushObject(oFactionMember, false);
            NWN.Internal.CallBuiltIn(192);
            return NWN.Internal.StackPopObject();
        }

        //  Get the object faction member with the highest armour class.
        //  * Returns OBJECT_INVALID if oFactionMember's faction is invalid.
        public static NWN.Object GetFactionBestAC(NWN.Object oFactionMember = null, int bMustBeVisible = TRUE)
        {
            NWN.Internal.StackPushInteger(bMustBeVisible);
            NWN.Internal.StackPushObject(oFactionMember, false);
            NWN.Internal.CallBuiltIn(193);
            return NWN.Internal.StackPopObject();
        }

        //  Sit in oChair.
        //  Note: Not all creatures will be able to sit and not all
        //        objects can be sat on.
        //        The object oChair must also be marked as usable in the toolset.
        // 
        //  For Example: To get a player to sit in oChair when they click on it,
        //  place the following script in the OnUsed event for the object oChair.
        //  void main()
        //  {
        //     object oChair = OBJECT_SELF;
        //     AssignCommand(GetLastUsedBy(),ActionSit(oChair));
        //  }
        public static void ActionSit(NWN.Object oChair)
        {
            NWN.Internal.StackPushObject(oChair, false);
            NWN.Internal.CallBuiltIn(194);
        }

        //  In an onConversation script this gets the number of the string pattern
        //  matched (the one that triggered the script).
        //  * Returns -1 if no string matched
        public static int GetListenPatternNumber()
        {
            NWN.Internal.CallBuiltIn(195);
            return NWN.Internal.StackPopInteger();
        }

        //  Jump to an object ID, or as near to it as possible.
        public static void ActionJumpToObject(NWN.Object oToJumpTo, int bWalkStraightLineToPoint = TRUE)
        {
            NWN.Internal.StackPushInteger(bWalkStraightLineToPoint);
            NWN.Internal.StackPushObject(oToJumpTo, false);
            NWN.Internal.CallBuiltIn(196);
        }

        //  Get the first waypoint with the specified tag.
        //  * Returns OBJECT_INVALID if the waypoint cannot be found.
        public static NWN.Object GetWaypointByTag(string sWaypointTag)
        {
            NWN.Internal.StackPushString(sWaypointTag);
            NWN.Internal.CallBuiltIn(197);
            return NWN.Internal.StackPopObject();
        }

        //  Get the destination object for the given object.
        // 
        //  All objects can hold a transition target, but only Doors and Triggers
        //  will be made clickable by the game engine (This may change in the
        //  future). You can set and query transition targets on other objects for
        //  your own scripted purposes.
        // 
        //  * Returns OBJECT_INVALID if oTransition does not hold a target.
        public static NWN.Object GetTransitionTarget(NWN.Object oTransition)
        {
            NWN.Internal.StackPushObject(oTransition, false);
            NWN.Internal.CallBuiltIn(198);
            return NWN.Internal.StackPopObject();
        }

        //  Link the two supplied effects, returning eChildEffect as a child of
        //  eParentEffect.
        //  Note: When applying linked effects if the target is immune to all valid
        //  effects all other effects will be removed as well. This means that if you
        //  apply a visual effect and a silence effect (in a link) and the target is
        //  immune to the silence effect that the visual effect will get removed as well.
        //  Visual Effects are not considered "valid" effects for the purposes of
        //  determining if an effect will be removed or not and as such should never be
        //  packaged *only* with other visual effects in a link.
        public static NWN.Effect EffectLinkEffects(NWN.Effect eChildEffect, NWN.Effect eParentEffect)
        {
            NWN.Internal.StackPushEffect(eParentEffect);
            NWN.Internal.StackPushEffect(eChildEffect);
            NWN.Internal.CallBuiltIn(199);
            return NWN.Internal.StackPopEffect();
        }

        //  Get the nNth object with the specified tag.
        //  - sTag
        //  - nNth: the nth object with this tag may be requested
        //  * Returns OBJECT_INVALID if the object cannot be found.
        //  Note: The module cannot be retrieved by GetObjectByTag(), use GetModule() instead.
        public static NWN.Object GetObjectByTag(string sTag, int nNth = 0)
        {
            NWN.Internal.StackPushInteger(nNth);
            NWN.Internal.StackPushString(sTag);
            NWN.Internal.CallBuiltIn(200);
            return NWN.Internal.StackPopObject();
        }

        //  Adjust the alignment of oSubject.
        //  - oSubject
        //  - nAlignment:
        //    -> ALIGNMENT_LAWFUL/ALIGNMENT_CHAOTIC/ALIGNMENT_GOOD/ALIGNMENT_EVIL: oSubject's
        //       alignment will be shifted in the direction specified
        //    -> ALIGNMENT_ALL: nShift will be added to oSubject's law/chaos and
        //       good/evil alignment values
        //    -> ALIGNMENT_NEUTRAL: nShift is applied to oSubject's law/chaos and
        //       good/evil alignment values in the direction which is towards neutrality.
        //      e.g. If oSubject has a law/chaos value of 10 (i.e. chaotic) and a
        //           good/evil value of 80 (i.e. good) then if nShift is 15, the
        //           law/chaos value will become (10+15)=25 and the good/evil value will
        //           become (80-25)=55
        //      Furthermore, the shift will at most take the alignment value to 50 and
        //      not beyond.
        //      e.g. If oSubject has a law/chaos value of 40 and a good/evil value of 70,
        //           then if nShift is 15, the law/chaos value will become 50 and the
        //           good/evil value will become 55
        //  - nShift: this is the desired shift in alignment
        //  - bAllPartyMembers: when TRUE the alignment shift of oSubject also has a 
        //                      diminished affect all members of oSubject's party (if oSubject is a Player).
        //                      When FALSE the shift only affects oSubject.
        //  * No return value
        public static void AdjustAlignment(NWN.Object oSubject, int nAlignment, int nShift, int bAllPartyMembers = TRUE)
        {
            NWN.Internal.StackPushInteger(bAllPartyMembers);
            NWN.Internal.StackPushInteger(nShift);
            NWN.Internal.StackPushInteger(nAlignment);
            NWN.Internal.StackPushObject(oSubject, false);
            NWN.Internal.CallBuiltIn(201);
        }

        //  Do nothing for fSeconds seconds.
        public static void ActionWait(float fSeconds)
        {
            NWN.Internal.StackPushFloat(fSeconds);
            NWN.Internal.CallBuiltIn(202);
        }

        //  Set the transition bitmap of a player; this should only be called in area
        //  transition scripts. This action should be run by the person "clicking" the
        //  area transition via AssignCommand.
        //  - nPredefinedAreaTransition:
        //    -> To use a predefined area transition bitmap, use one of AREA_TRANSITION_*
        //    -> To use a custom, user-defined area transition bitmap, use
        //       AREA_TRANSITION_USER_DEFINED and specify the filename in the second
        //       parameter
        //  - sCustomAreaTransitionBMP: this is the filename of a custom, user-defined
        //    area transition bitmap
        public static void SetAreaTransitionBMP(int nPredefinedAreaTransition, string sCustomAreaTransitionBMP = "")
        {
            NWN.Internal.StackPushString(sCustomAreaTransitionBMP);
            NWN.Internal.StackPushInteger(nPredefinedAreaTransition);
            NWN.Internal.CallBuiltIn(203);
        }

        //  Starts a conversation with oObjectToConverseWith - this will cause their
        //  OnDialog event to fire.
        //  - oObjectToConverseWith
        //  - sDialogResRef: If this is blank, the creature's own dialogue file will be used
        //  - bPrivateConversation
        //  Turn off bPlayHello if you don't want the initial greeting to play
        public static void ActionStartConversation(NWN.Object oObjectToConverseWith, string sDialogResRef = "", int bPrivateConversation = FALSE, int bPlayHello = TRUE)
        {
            NWN.Internal.StackPushInteger(bPlayHello);
            NWN.Internal.StackPushInteger(bPrivateConversation);
            NWN.Internal.StackPushString(sDialogResRef);
            NWN.Internal.StackPushObject(oObjectToConverseWith, false);
            NWN.Internal.CallBuiltIn(204);
        }

        //  Pause the current conversation.
        public static void ActionPauseConversation()
        {
            NWN.Internal.CallBuiltIn(205);
        }

        //  Resume a conversation after it has been paused.
        public static void ActionResumeConversation()
        {
            NWN.Internal.CallBuiltIn(206);
        }

        //  Create a Beam effect.
        //  - nBeamVisualEffect: VFX_BEAM_*
        //  - oEffector: the beam is emitted from this creature
        //  - nBodyPart: BODY_NODE_*
        //  - bMissEffect: If this is TRUE, the beam will fire to a random vector near or
        //    past the target
        //  * Returns an effect of type EFFECT_TYPE_INVALIDEFFECT if nBeamVisualEffect is
        //    not valid.
        public static NWN.Effect EffectBeam(int nBeamVisualEffect, NWN.Object oEffector, int nBodyPart, int bMissEffect = FALSE)
        {
            NWN.Internal.StackPushInteger(bMissEffect);
            NWN.Internal.StackPushInteger(nBodyPart);
            NWN.Internal.StackPushObject(oEffector, false);
            NWN.Internal.StackPushInteger(nBeamVisualEffect);
            NWN.Internal.CallBuiltIn(207);
            return NWN.Internal.StackPopEffect();
        }

        //  Get an integer between 0 and 100 (inclusive) that represents how oSource
        //  feels about oTarget.
        //  -> 0-10 means oSource is hostile to oTarget
        //  -> 11-89 means oSource is neutral to oTarget
        //  -> 90-100 means oSource is friendly to oTarget
        //  * Returns -1 if oSource or oTarget does not identify a valid object
        public static int GetReputation(NWN.Object oSource, NWN.Object oTarget)
        {
            NWN.Internal.StackPushObject(oTarget, false);
            NWN.Internal.StackPushObject(oSource, false);
            NWN.Internal.CallBuiltIn(208);
            return NWN.Internal.StackPopInteger();
        }

        //  Adjust how oSourceFactionMember's faction feels about oTarget by the
        //  specified amount.
        //  Note: This adjusts Faction Reputation, how the entire faction that
        //  oSourceFactionMember is in, feels about oTarget.
        //  * No return value
        //  Note: You can't adjust a player character's (PC) faction towards
        //        NPCs, so attempting to make an NPC hostile by passing in a PC object
        //        as oSourceFactionMember in the following call will fail:
        //        AdjustReputation(oNPC,oPC,-100);
        //        Instead you should pass in the PC object as the first
        //        parameter as in the following call which should succeed: 
        //        AdjustReputation(oPC,oNPC,-100);
        //  Note: Will fail if oSourceFactionMember is a plot object.
        public static void AdjustReputation(NWN.Object oTarget, NWN.Object oSourceFactionMember, int nAdjustment)
        {
            NWN.Internal.StackPushInteger(nAdjustment);
            NWN.Internal.StackPushObject(oSourceFactionMember, false);
            NWN.Internal.StackPushObject(oTarget, false);
            NWN.Internal.CallBuiltIn(209);
        }

        //  Get the creature that is currently sitting on the specified object.
        //  - oChair
        //  * Returns OBJECT_INVALID if oChair is not a valid placeable.
        public static NWN.Object GetSittingCreature(NWN.Object oChair)
        {
            NWN.Internal.StackPushObject(oChair, false);
            NWN.Internal.CallBuiltIn(210);
            return NWN.Internal.StackPopObject();
        }

        //  Get the creature that is going to attack oTarget.
        //  Note: This value is cleared out at the end of every combat round and should
        //  not be used in any case except when getting a "going to be attacked" shout
        //  from the master creature (and this creature is a henchman)
        //  * Returns OBJECT_INVALID if oTarget is not a valid creature.
        public static NWN.Object GetGoingToBeAttackedBy(NWN.Object oTarget)
        {
            NWN.Internal.StackPushObject(oTarget, false);
            NWN.Internal.CallBuiltIn(211);
            return NWN.Internal.StackPopObject();
        }

        //  Create a Spell Resistance Increase effect.
        //  - nValue: size of spell resistance increase
        public static NWN.Effect EffectSpellResistanceIncrease(int nValue)
        {
            NWN.Internal.StackPushInteger(nValue);
            NWN.Internal.CallBuiltIn(212);
            return NWN.Internal.StackPopEffect();
        }

        //  Get the location of oObject.
        public static NWN.Location GetLocation(NWN.Object oObject)
        {
            NWN.Internal.StackPushObject(oObject, false);
            NWN.Internal.CallBuiltIn(213);
            return NWN.Internal.StackPopLocation();
        }

        //  The subject will jump to lLocation instantly (even between areas).
        //  If lLocation is invalid, nothing will happen.
        public static void ActionJumpToLocation(NWN.Location lLocation)
        {
            NWN.Internal.StackPushLocation(lLocation);
            NWN.Internal.CallBuiltIn(214);
        }

        //  Create a location.
        public static NWN.Location Location(NWN.Object oArea, NWN.Vector? vPosition, float fOrientation)
        {
            NWN.Internal.StackPushFloat(fOrientation);
            NWN.Internal.StackPushVector(vPosition);
            NWN.Internal.StackPushObject(oArea, false);
            NWN.Internal.CallBuiltIn(215);
            return NWN.Internal.StackPopLocation();
        }

        //  Apply eEffect at lLocation.
        public static void ApplyEffectAtLocation(int nDurationType, NWN.Effect eEffect, NWN.Location lLocation, float fDuration = 0.0f)
        {
            NWN.Internal.StackPushFloat(fDuration);
            NWN.Internal.StackPushLocation(lLocation);
            NWN.Internal.StackPushEffect(eEffect);
            NWN.Internal.StackPushInteger(nDurationType);
            NWN.Internal.CallBuiltIn(216);
        }

        //  * Returns TRUE if oCreature is a Player Controlled character.
        public static int GetIsPC(NWN.Object oCreature)
        {
            NWN.Internal.StackPushObject(oCreature, false);
            NWN.Internal.CallBuiltIn(217);
            return NWN.Internal.StackPopInteger();
        }

        //  Convert fFeet into a number of meters.
        public static float FeetToMeters(float fFeet)
        {
            NWN.Internal.StackPushFloat(fFeet);
            NWN.Internal.CallBuiltIn(218);
            return NWN.Internal.StackPopFloat();
        }

        //  Convert fYards into a number of meters.
        public static float YardsToMeters(float fYards)
        {
            NWN.Internal.StackPushFloat(fYards);
            NWN.Internal.CallBuiltIn(219);
            return NWN.Internal.StackPopFloat();
        }

        //  Apply eEffect to oTarget.
        public static void ApplyEffectToObject(int nDurationType, NWN.Effect eEffect, NWN.Object oTarget, float fDuration = 0.0f)
        {
            NWN.Internal.StackPushFloat(fDuration);
            NWN.Internal.StackPushObject(oTarget, false);
            NWN.Internal.StackPushEffect(eEffect);
            NWN.Internal.StackPushInteger(nDurationType);
            NWN.Internal.CallBuiltIn(220);
        }

        //  The caller will immediately speak sStringToSpeak (this is different from
        //  ActionSpeakString)
        //  - sStringToSpeak
        //  - nTalkVolume: TALKVOLUME_*
        public static void SpeakString(string sStringToSpeak, int nTalkVolume = TALKVOLUME_TALK)
        {
            NWN.Internal.StackPushInteger(nTalkVolume);
            NWN.Internal.StackPushString(sStringToSpeak);
            NWN.Internal.CallBuiltIn(221);
        }

        //  Get the location of the caller's last spell target.
        public static NWN.Location GetSpellTargetLocation()
        {
            NWN.Internal.CallBuiltIn(222);
            return NWN.Internal.StackPopLocation();
        }

        //  Get the position vector from lLocation.
        public static NWN.Vector GetPositionFromLocation(NWN.Location lLocation)
        {
            NWN.Internal.StackPushLocation(lLocation);
            NWN.Internal.CallBuiltIn(223);
            return NWN.Internal.StackPopVector();
        }

        //  Get the area's object ID from lLocation.
        public static NWN.Object GetAreaFromLocation(NWN.Location lLocation)
        {
            NWN.Internal.StackPushLocation(lLocation);
            NWN.Internal.CallBuiltIn(224);
            return NWN.Internal.StackPopObject();
        }

        //  Get the orientation value from lLocation.
        public static float GetFacingFromLocation(NWN.Location lLocation)
        {
            NWN.Internal.StackPushLocation(lLocation);
            NWN.Internal.CallBuiltIn(225);
            return NWN.Internal.StackPopFloat();
        }

        //  Get the creature nearest to lLocation, subject to all the criteria specified.
        //  - nFirstCriteriaType: CREATURE_TYPE_*
        //  - nFirstCriteriaValue:
        //    -> CLASS_TYPE_* if nFirstCriteriaType was CREATURE_TYPE_CLASS
        //    -> SPELL_* if nFirstCriteriaType was CREATURE_TYPE_DOES_NOT_HAVE_SPELL_EFFECT
        //       or CREATURE_TYPE_HAS_SPELL_EFFECT
        //    -> TRUE or FALSE if nFirstCriteriaType was CREATURE_TYPE_IS_ALIVE
        //    -> PERCEPTION_* if nFirstCriteriaType was CREATURE_TYPE_PERCEPTION
        //    -> PLAYER_CHAR_IS_PC or PLAYER_CHAR_NOT_PC if nFirstCriteriaType was
        //       CREATURE_TYPE_PLAYER_CHAR
        //    -> RACIAL_TYPE_* if nFirstCriteriaType was CREATURE_TYPE_RACIAL_TYPE
        //    -> REPUTATION_TYPE_* if nFirstCriteriaType was CREATURE_TYPE_REPUTATION
        //    For example, to get the nearest PC, use
        //    (CREATURE_TYPE_PLAYER_CHAR, PLAYER_CHAR_IS_PC)
        //  - lLocation: We're trying to find the creature of the specified type that is
        //    nearest to lLocation
        //  - nNth: We don't have to find the first nearest: we can find the Nth nearest....
        //  - nSecondCriteriaType: This is used in the same way as nFirstCriteriaType to
        //    further specify the type of creature that we are looking for.
        //  - nSecondCriteriaValue: This is used in the same way as nFirstCriteriaValue
        //    to further specify the type of creature that we are looking for.
        //  - nThirdCriteriaType: This is used in the same way as nFirstCriteriaType to
        //    further specify the type of creature that we are looking for.
        //  - nThirdCriteriaValue: This is used in the same way as nFirstCriteriaValue to
        //    further specify the type of creature that we are looking for.
        //  * Return value on error: OBJECT_INVALID
        public static NWN.Object GetNearestCreatureToLocation(int nFirstCriteriaType, int nFirstCriteriaValue, NWN.Location lLocation, int nNth = 1, int nSecondCriteriaType = -1, int nSecondCriteriaValue = -1, int nThirdCriteriaType = -1, int nThirdCriteriaValue = -1)
        {
            NWN.Internal.StackPushInteger(nThirdCriteriaValue);
            NWN.Internal.StackPushInteger(nThirdCriteriaType);
            NWN.Internal.StackPushInteger(nSecondCriteriaValue);
            NWN.Internal.StackPushInteger(nSecondCriteriaType);
            NWN.Internal.StackPushInteger(nNth);
            NWN.Internal.StackPushLocation(lLocation);
            NWN.Internal.StackPushInteger(nFirstCriteriaValue);
            NWN.Internal.StackPushInteger(nFirstCriteriaType);
            NWN.Internal.CallBuiltIn(226);
            return NWN.Internal.StackPopObject();
        }

        //  Get the Nth object nearest to oTarget that is of the specified type.
        //  - nObjectType: OBJECT_TYPE_*
        //  - oTarget
        //  - nNth
        //  * Return value on error: OBJECT_INVALID
        public static NWN.Object GetNearestObject(int nObjectType = OBJECT_TYPE_ALL, NWN.Object oTarget = null, int nNth = 1)
        {
            NWN.Internal.StackPushInteger(nNth);
            NWN.Internal.StackPushObject(oTarget, false);
            NWN.Internal.StackPushInteger(nObjectType);
            NWN.Internal.CallBuiltIn(227);
            return NWN.Internal.StackPopObject();
        }

        //  Get the nNth object nearest to lLocation that is of the specified type.
        //  - nObjectType: OBJECT_TYPE_*
        //  - lLocation
        //  - nNth
        //  * Return value on error: OBJECT_INVALID
        public static NWN.Object GetNearestObjectToLocation(int nObjectType, NWN.Location lLocation, int nNth = 1)
        {
            NWN.Internal.StackPushInteger(nNth);
            NWN.Internal.StackPushLocation(lLocation);
            NWN.Internal.StackPushInteger(nObjectType);
            NWN.Internal.CallBuiltIn(228);
            return NWN.Internal.StackPopObject();
        }

        //  Get the nth Object nearest to oTarget that has sTag as its tag.
        //  * Return value on error: OBJECT_INVALID
        public static NWN.Object GetNearestObjectByTag(string sTag, NWN.Object oTarget = null, int nNth = 1)
        {
            NWN.Internal.StackPushInteger(nNth);
            NWN.Internal.StackPushObject(oTarget, false);
            NWN.Internal.StackPushString(sTag);
            NWN.Internal.CallBuiltIn(229);
            return NWN.Internal.StackPopObject();
        }

        //  Convert nInteger into a floating point number.
        public static float IntToFloat(int nInteger)
        {
            NWN.Internal.StackPushInteger(nInteger);
            NWN.Internal.CallBuiltIn(230);
            return NWN.Internal.StackPopFloat();
        }

        //  Convert fFloat into the nearest integer.
        public static int FloatToInt(float fFloat)
        {
            NWN.Internal.StackPushFloat(fFloat);
            NWN.Internal.CallBuiltIn(231);
            return NWN.Internal.StackPopInteger();
        }

        //  Convert sNumber into an integer.
        public static int StringToInt(string sNumber)
        {
            NWN.Internal.StackPushString(sNumber);
            NWN.Internal.CallBuiltIn(232);
            return NWN.Internal.StackPopInteger();
        }

        //  Convert sNumber into a floating point number.
        public static float StringToFloat(string sNumber)
        {
            NWN.Internal.StackPushString(sNumber);
            NWN.Internal.CallBuiltIn(233);
            return NWN.Internal.StackPopFloat();
        }

        //  Cast spell nSpell at lTargetLocation.
        //  - nSpell: SPELL_*
        //  - lTargetLocation
        //  - nMetaMagic: METAMAGIC_*
        //  - bCheat: If this is TRUE, then the executor of the action doesn't have to be
        //    able to cast the spell.
        //  - nProjectilePathType: PROJECTILE_PATH_TYPE_*
        //  - bInstantSpell: If this is TRUE, the spell is cast immediately; this allows
        //    the end-user to simulate
        //    a high-level magic user having lots of advance warning of impending trouble.
        public static void ActionCastSpellAtLocation(int nSpell, NWN.Location lTargetLocation, int nMetaMagic = METAMAGIC_ANY, int bCheat = FALSE, int nProjectilePathType = PROJECTILE_PATH_TYPE_DEFAULT, int bInstantSpell = FALSE)
        {
            NWN.Internal.StackPushInteger(bInstantSpell);
            NWN.Internal.StackPushInteger(nProjectilePathType);
            NWN.Internal.StackPushInteger(bCheat);
            NWN.Internal.StackPushInteger(nMetaMagic);
            NWN.Internal.StackPushLocation(lTargetLocation);
            NWN.Internal.StackPushInteger(nSpell);
            NWN.Internal.CallBuiltIn(234);
        }

        //  * Returns TRUE if oSource considers oTarget as an enemy.
        public static int GetIsEnemy(NWN.Object oTarget, NWN.Object oSource = null)
        {
            NWN.Internal.StackPushObject(oSource, false);
            NWN.Internal.StackPushObject(oTarget, false);
            NWN.Internal.CallBuiltIn(235);
            return NWN.Internal.StackPopInteger();
        }

        //  * Returns TRUE if oSource considers oTarget as a friend.
        public static int GetIsFriend(NWN.Object oTarget, NWN.Object oSource = null)
        {
            NWN.Internal.StackPushObject(oSource, false);
            NWN.Internal.StackPushObject(oTarget, false);
            NWN.Internal.CallBuiltIn(236);
            return NWN.Internal.StackPopInteger();
        }

        //  * Returns TRUE if oSource considers oTarget as neutral.
        public static int GetIsNeutral(NWN.Object oTarget, NWN.Object oSource = null)
        {
            NWN.Internal.StackPushObject(oSource, false);
            NWN.Internal.StackPushObject(oTarget, false);
            NWN.Internal.CallBuiltIn(237);
            return NWN.Internal.StackPopInteger();
        }

        //  Get the PC that is involved in the conversation.
        //  * Returns OBJECT_INVALID on error.
        public static NWN.Object GetPCSpeaker()
        {
            NWN.Internal.CallBuiltIn(238);
            return NWN.Internal.StackPopObject();
        }

        //  Get a string from the talk table using nStrRef.
        public static string GetStringByStrRef(int nStrRef, int nGender = GENDER_MALE)
        {
            NWN.Internal.StackPushInteger(nGender);
            NWN.Internal.StackPushInteger(nStrRef);
            NWN.Internal.CallBuiltIn(239);
            return NWN.Internal.StackPopString();
        }

        //  Causes the creature to speak a translated string.
        //  - nStrRef: Reference of the string in the talk table
        //  - nTalkVolume: TALKVOLUME_*
        public static void ActionSpeakStringByStrRef(int nStrRef, int nTalkVolume = TALKVOLUME_TALK)
        {
            NWN.Internal.StackPushInteger(nTalkVolume);
            NWN.Internal.StackPushInteger(nStrRef);
            NWN.Internal.CallBuiltIn(240);
        }

        //  Destroy oObject (irrevocably).
        //  This will not work on modules and areas.
        public static void DestroyObject(NWN.Object oDestroy, float fDelay = 0.0f)
        {
            NWN.Internal.StackPushFloat(fDelay);
            NWN.Internal.StackPushObject(oDestroy, false);
            NWN.Internal.CallBuiltIn(241);
        }

        //  Get the module.
        //  * Return value on error: OBJECT_INVALID
        public static NWN.Object GetModule()
        {
            NWN.Internal.CallBuiltIn(242);
            return NWN.Internal.StackPopObject();
        }

        //  Create an object of the specified type at lLocation.
        //  - nObjectType: OBJECT_TYPE_ITEM, OBJECT_TYPE_CREATURE, OBJECT_TYPE_PLACEABLE,
        //    OBJECT_TYPE_STORE, OBJECT_TYPE_WAYPOINT
        //  - sTemplate
        //  - lLocation
        //  - bUseAppearAnimation
        //  - sNewTag - if this string is not empty, it will replace the default tag from the template
        public static NWN.Object CreateObject(int nObjectType, string sTemplate, NWN.Location lLocation, int bUseAppearAnimation = FALSE, string sNewTag = "")
        {
            NWN.Internal.StackPushString(sNewTag);
            NWN.Internal.StackPushInteger(bUseAppearAnimation);
            NWN.Internal.StackPushLocation(lLocation);
            NWN.Internal.StackPushString(sTemplate);
            NWN.Internal.StackPushInteger(nObjectType);
            NWN.Internal.CallBuiltIn(243);
            return NWN.Internal.StackPopObject();
        }

        //  Create an event which triggers the "SpellCastAt" script
        //  Note: This only creates the event. The event wont actually trigger until SignalEvent()
        //  is called using this created SpellCastAt event as an argument.
        //  For example:
        //      SignalEvent(oCreature, EventSpellCastAt(oCaster, SPELL_MAGIC_MISSILE, TRUE));
        //  This function doesn't cast the spell specified, it only creates an event so that
        //  when the event is signaled on an object, the object will use its OnSpellCastAt script
        //  to react to the spell being cast.
        // 
        //  To specify the OnSpellCastAt script that should run, view the Object's Properties 
        //  and click on the Scripts Tab. Then specify a script for the OnSpellCastAt event.
        //  From inside the OnSpellCastAt script call:
        //      GetLastSpellCaster() to get the object that cast the spell (oCaster).
        //      GetLastSpell() to get the type of spell cast (nSpell)
        //      GetLastSpellHarmful() to determine if the spell cast at the object was harmful.
        public static NWN.Event EventSpellCastAt(NWN.Object oCaster, int nSpell, int bHarmful = TRUE)
        {
            NWN.Internal.StackPushInteger(bHarmful);
            NWN.Internal.StackPushInteger(nSpell);
            NWN.Internal.StackPushObject(oCaster, false);
            NWN.Internal.CallBuiltIn(244);
            return NWN.Internal.StackPopEvent();
        }

        //  This is for use in a "Spell Cast" script, it gets who cast the spell.
        //  The spell could have been cast by a creature, placeable or door.
        //  * Returns OBJECT_INVALID if the caller is not a creature, placeable or door.
        public static NWN.Object GetLastSpellCaster()
        {
            NWN.Internal.CallBuiltIn(245);
            return NWN.Internal.StackPopObject();
        }

        //  This is for use in a "Spell Cast" script, it gets the ID of the spell that
        //  was cast.
        public static int GetLastSpell()
        {
            NWN.Internal.CallBuiltIn(246);
            return NWN.Internal.StackPopInteger();
        }

        //  This is for use in a user-defined script, it gets the event number.
        public static int GetUserDefinedEventNumber()
        {
            NWN.Internal.CallBuiltIn(247);
            return NWN.Internal.StackPopInteger();
        }

        //  This is for use in a Spell script, it gets the ID of the spell that is being
        //  cast (SPELL_*).
        public static int GetSpellId()
        {
            NWN.Internal.CallBuiltIn(248);
            return NWN.Internal.StackPopInteger();
        }

        //  Generate a random name.
        //  nNameType: The type of random name to be generated (NAME_*)
        public static string RandomName(int nNameType = NAME_FIRST_GENERIC_MALE)
        {
            NWN.Internal.StackPushInteger(nNameType);
            NWN.Internal.CallBuiltIn(249);
            return NWN.Internal.StackPopString();
        }

        //  Create a Poison effect.
        //  - nPoisonType: POISON_*
        public static NWN.Effect EffectPoison(int nPoisonType)
        {
            NWN.Internal.StackPushInteger(nPoisonType);
            NWN.Internal.CallBuiltIn(250);
            return NWN.Internal.StackPopEffect();
        }

        //  Create a Disease effect.
        //  - nDiseaseType: DISEASE_*
        public static NWN.Effect EffectDisease(int nDiseaseType)
        {
            NWN.Internal.StackPushInteger(nDiseaseType);
            NWN.Internal.CallBuiltIn(251);
            return NWN.Internal.StackPopEffect();
        }

        //  Create a Silence effect.
        public static NWN.Effect EffectSilence()
        {
            NWN.Internal.CallBuiltIn(252);
            return NWN.Internal.StackPopEffect();
        }

        //  Set the name of oObject.
        // 
        //  - oObject: the object for which you are changing the name (area, creature, placeable, item, or door).
        //  - sNewName: the new name that the object will use.
        //  Note: SetName() does not work on player objects.
        //        Setting an object's name to "" will make the object
        //        revert to using the name it had originally before any
        //        SetName() calls were made on the object.
        public static string GetName(NWN.Object oObject, int bOriginalName = FALSE)
        {
            NWN.Internal.StackPushInteger(bOriginalName);
            NWN.Internal.StackPushObject(oObject, false);
            NWN.Internal.CallBuiltIn(253);
            return NWN.Internal.StackPopString();
        }

        //  Use this in a conversation script to get the person with whom you are conversing.
        //  * Returns OBJECT_INVALID if the caller is not a valid creature.
        public static NWN.Object GetLastSpeaker()
        {
            NWN.Internal.CallBuiltIn(254);
            return NWN.Internal.StackPopObject();
        }

        //  Use this in an OnDialog script to start up the dialog tree.
        //  - sResRef: if this is not specified, the default dialog file will be used
        //  - oObjectToDialog: if this is not specified the person that triggered the
        //    event will be used
        public static int BeginConversation(string sResRef = "", NWN.Object oObjectToDialog = null)
        {
            NWN.Internal.StackPushObject(oObjectToDialog, false);
            NWN.Internal.StackPushString(sResRef);
            NWN.Internal.CallBuiltIn(255);
            return NWN.Internal.StackPopInteger();
        }

        //  Use this in an OnPerception script to get the object that was perceived.
        //  * Returns OBJECT_INVALID if the caller is not a valid creature.
        public static NWN.Object GetLastPerceived()
        {
            NWN.Internal.CallBuiltIn(256);
            return NWN.Internal.StackPopObject();
        }

        //  Use this in an OnPerception script to determine whether the object that was
        //  perceived was heard.
        public static int GetLastPerceptionHeard()
        {
            NWN.Internal.CallBuiltIn(257);
            return NWN.Internal.StackPopInteger();
        }

        //  Use this in an OnPerception script to determine whether the object that was
        //  perceived has become inaudible.
        public static int GetLastPerceptionInaudible()
        {
            NWN.Internal.CallBuiltIn(258);
            return NWN.Internal.StackPopInteger();
        }

        //  Use this in an OnPerception script to determine whether the object that was
        //  perceived was seen.
        public static int GetLastPerceptionSeen()
        {
            NWN.Internal.CallBuiltIn(259);
            return NWN.Internal.StackPopInteger();
        }

        //  Use this in an OnClosed script to get the object that closed the door or placeable.
        //  * Returns OBJECT_INVALID if the caller is not a valid door or placeable.
        public static NWN.Object GetLastClosedBy()
        {
            NWN.Internal.CallBuiltIn(260);
            return NWN.Internal.StackPopObject();
        }

        //  Use this in an OnPerception script to determine whether the object that was
        //  perceived has vanished.
        public static int GetLastPerceptionVanished()
        {
            NWN.Internal.CallBuiltIn(261);
            return NWN.Internal.StackPopInteger();
        }

        //  Get the first object within oPersistentObject.
        //  - oPersistentObject
        //  - nResidentObjectType: OBJECT_TYPE_*
        //  - nPersistentZone: PERSISTENT_ZONE_ACTIVE. [This could also take the value
        //    PERSISTENT_ZONE_FOLLOW, but this is no longer used.]
        //  * Returns OBJECT_INVALID if no object is found.
        public static NWN.Object GetFirstInPersistentObject(NWN.Object oPersistentObject = null, int nResidentObjectType = OBJECT_TYPE_CREATURE, int nPersistentZone = PERSISTENT_ZONE_ACTIVE)
        {
            NWN.Internal.StackPushInteger(nPersistentZone);
            NWN.Internal.StackPushInteger(nResidentObjectType);
            NWN.Internal.StackPushObject(oPersistentObject, false);
            NWN.Internal.CallBuiltIn(262);
            return NWN.Internal.StackPopObject();
        }

        //  Get the next object within oPersistentObject.
        //  - oPersistentObject
        //  - nResidentObjectType: OBJECT_TYPE_*
        //  - nPersistentZone: PERSISTENT_ZONE_ACTIVE. [This could also take the value
        //    PERSISTENT_ZONE_FOLLOW, but this is no longer used.]
        //  * Returns OBJECT_INVALID if no object is found.
        public static NWN.Object GetNextInPersistentObject(NWN.Object oPersistentObject = null, int nResidentObjectType = OBJECT_TYPE_CREATURE, int nPersistentZone = PERSISTENT_ZONE_ACTIVE)
        {
            NWN.Internal.StackPushInteger(nPersistentZone);
            NWN.Internal.StackPushInteger(nResidentObjectType);
            NWN.Internal.StackPushObject(oPersistentObject, false);
            NWN.Internal.CallBuiltIn(263);
            return NWN.Internal.StackPopObject();
        }

        //  This returns the creator of oAreaOfEffectObject.
        //  * Returns OBJECT_INVALID if oAreaOfEffectObject is not a valid Area of Effect object.
        public static NWN.Object GetAreaOfEffectCreator(NWN.Object oAreaOfEffectObject = null)
        {
            NWN.Internal.StackPushObject(oAreaOfEffectObject, false);
            NWN.Internal.CallBuiltIn(264);
            return NWN.Internal.StackPopObject();
        }

        //  Delete oObject's local integer variable sVarName
        public static void DeleteLocalInt(NWN.Object oObject, string sVarName)
        {
            NWN.Internal.StackPushString(sVarName);
            NWN.Internal.StackPushObject(oObject, false);
            NWN.Internal.CallBuiltIn(265);
        }

        //  Delete oObject's local float variable sVarName
        public static void DeleteLocalFloat(NWN.Object oObject, string sVarName)
        {
            NWN.Internal.StackPushString(sVarName);
            NWN.Internal.StackPushObject(oObject, false);
            NWN.Internal.CallBuiltIn(266);
        }

        //  Delete oObject's local string variable sVarName
        public static void DeleteLocalString(NWN.Object oObject, string sVarName)
        {
            NWN.Internal.StackPushString(sVarName);
            NWN.Internal.StackPushObject(oObject, false);
            NWN.Internal.CallBuiltIn(267);
        }

        //  Delete oObject's local object variable sVarName
        public static void DeleteLocalObject(NWN.Object oObject, string sVarName)
        {
            NWN.Internal.StackPushString(sVarName);
            NWN.Internal.StackPushObject(oObject, false);
            NWN.Internal.CallBuiltIn(268);
        }

        //  Delete oObject's local location variable sVarName
        public static void DeleteLocalLocation(NWN.Object oObject, string sVarName)
        {
            NWN.Internal.StackPushString(sVarName);
            NWN.Internal.StackPushObject(oObject, false);
            NWN.Internal.CallBuiltIn(269);
        }

        //  Create a Haste effect.
        public static NWN.Effect EffectHaste()
        {
            NWN.Internal.CallBuiltIn(270);
            return NWN.Internal.StackPopEffect();
        }

        //  Create a Slow effect.
        public static NWN.Effect EffectSlow()
        {
            NWN.Internal.CallBuiltIn(271);
            return NWN.Internal.StackPopEffect();
        }

        //  Convert oObject into a hexadecimal string.
        public static string ObjectToString(NWN.Object oObject)
        {
            NWN.Internal.StackPushObject(oObject, false);
            NWN.Internal.CallBuiltIn(272);
            return NWN.Internal.StackPopString();
        }

        //  Create an Immunity effect.
        //  - nImmunityType: IMMUNITY_TYPE_*
        public static NWN.Effect EffectImmunity(int nImmunityType)
        {
            NWN.Internal.StackPushInteger(nImmunityType);
            NWN.Internal.CallBuiltIn(273);
            return NWN.Internal.StackPopEffect();
        }

        //  - oCreature
        //  - nImmunityType: IMMUNITY_TYPE_*
        //  - oVersus: if this is specified, then we also check for the race and
        //    alignment of oVersus
        //  * Returns TRUE if oCreature has immunity of type nImmunity versus oVersus.
        public static int GetIsImmune(NWN.Object oCreature, int nImmunityType, NWN.Object oVersus = null)
        {
            NWN.Internal.StackPushObject(oVersus, false);
            NWN.Internal.StackPushInteger(nImmunityType);
            NWN.Internal.StackPushObject(oCreature, false);
            NWN.Internal.CallBuiltIn(274);
            return NWN.Internal.StackPopInteger();
        }

        //  Creates a Damage Immunity Increase effect.
        //  - nDamageType: DAMAGE_TYPE_*
        //  - nPercentImmunity
        public static NWN.Effect EffectDamageImmunityIncrease(int nDamageType, int nPercentImmunity)
        {
            NWN.Internal.StackPushInteger(nPercentImmunity);
            NWN.Internal.StackPushInteger(nDamageType);
            NWN.Internal.CallBuiltIn(275);
            return NWN.Internal.StackPopEffect();
        }

        //  Determine whether oEncounter is active.
        public static int GetEncounterActive(NWN.Object oEncounter = null)
        {
            NWN.Internal.StackPushObject(oEncounter, false);
            NWN.Internal.CallBuiltIn(276);
            return NWN.Internal.StackPopInteger();
        }

        //  Set oEncounter's active state to nNewValue.
        //  - nNewValue: TRUE/FALSE
        //  - oEncounter
        public static void SetEncounterActive(int nNewValue, NWN.Object oEncounter = null)
        {
            NWN.Internal.StackPushObject(oEncounter, false);
            NWN.Internal.StackPushInteger(nNewValue);
            NWN.Internal.CallBuiltIn(277);
        }

        //  Get the maximum number of times that oEncounter will spawn.
        public static int GetEncounterSpawnsMax(NWN.Object oEncounter = null)
        {
            NWN.Internal.StackPushObject(oEncounter, false);
            NWN.Internal.CallBuiltIn(278);
            return NWN.Internal.StackPopInteger();
        }

        //  Set the maximum number of times that oEncounter can spawn
        public static void SetEncounterSpawnsMax(int nNewValue, NWN.Object oEncounter = null)
        {
            NWN.Internal.StackPushObject(oEncounter, false);
            NWN.Internal.StackPushInteger(nNewValue);
            NWN.Internal.CallBuiltIn(279);
        }

        //  Get the number of times that oEncounter has spawned so far
        public static int GetEncounterSpawnsCurrent(NWN.Object oEncounter = null)
        {
            NWN.Internal.StackPushObject(oEncounter, false);
            NWN.Internal.CallBuiltIn(280);
            return NWN.Internal.StackPopInteger();
        }

        //  Set the number of times that oEncounter has spawned so far
        public static void SetEncounterSpawnsCurrent(int nNewValue, NWN.Object oEncounter = null)
        {
            NWN.Internal.StackPushObject(oEncounter, false);
            NWN.Internal.StackPushInteger(nNewValue);
            NWN.Internal.CallBuiltIn(281);
        }

        //  Use this in an OnItemAcquired script to get the item that was acquired.
        //  * Returns OBJECT_INVALID if the module is not valid.
        public static NWN.Object GetModuleItemAcquired()
        {
            NWN.Internal.CallBuiltIn(282);
            return NWN.Internal.StackPopObject();
        }

        //  Use this in an OnItemAcquired script to get the creatre that previously
        //  possessed the item.
        //  * Returns OBJECT_INVALID if the item was picked up from the ground.
        public static NWN.Object GetModuleItemAcquiredFrom()
        {
            NWN.Internal.CallBuiltIn(283);
            return NWN.Internal.StackPopObject();
        }

        //  Set the value for a custom token.
        public static void SetCustomToken(int nCustomTokenNumber, string sTokenValue)
        {
            NWN.Internal.StackPushString(sTokenValue);
            NWN.Internal.StackPushInteger(nCustomTokenNumber);
            NWN.Internal.CallBuiltIn(284);
        }

        //  Determine whether oCreature has nFeat, and nFeat is useable.
        //  - nFeat: FEAT_*
        //  - oCreature
        public static int GetHasFeat(int nFeat, NWN.Object oCreature = null)
        {
            NWN.Internal.StackPushObject(oCreature, false);
            NWN.Internal.StackPushInteger(nFeat);
            NWN.Internal.CallBuiltIn(285);
            return NWN.Internal.StackPopInteger();
        }

        //  Determine whether oCreature has nSkill, and nSkill is useable.
        //  - nSkill: SKILL_*
        //  - oCreature
        public static int GetHasSkill(int nSkill, NWN.Object oCreature = null)
        {
            NWN.Internal.StackPushObject(oCreature, false);
            NWN.Internal.StackPushInteger(nSkill);
            NWN.Internal.CallBuiltIn(286);
            return NWN.Internal.StackPopInteger();
        }

        //  Use nFeat on oTarget.
        //  - nFeat: FEAT_*
        //  - oTarget
        public static void ActionUseFeat(int nFeat, NWN.Object oTarget)
        {
            NWN.Internal.StackPushObject(oTarget, false);
            NWN.Internal.StackPushInteger(nFeat);
            NWN.Internal.CallBuiltIn(287);
        }

        //  Runs the action "UseSkill" on the current creature
        //  Use nSkill on oTarget.
        //  - nSkill: SKILL_*
        //  - oTarget
        //  - nSubSkill: SUBSKILL_*
        //  - oItemUsed: Item to use in conjunction with the skill
        public static void ActionUseSkill(int nSkill, NWN.Object oTarget, int nSubSkill = 0, NWN.Object oItemUsed = null)
        {
            NWN.Internal.StackPushObject(oItemUsed, false);
            NWN.Internal.StackPushInteger(nSubSkill);
            NWN.Internal.StackPushObject(oTarget, false);
            NWN.Internal.StackPushInteger(nSkill);
            NWN.Internal.CallBuiltIn(288);
        }

        //  Determine whether oSource sees oTarget.
        //  NOTE: This *only* works on creatures, as visibility lists are not
        //        maintained for non-creature objects.
        public static int GetObjectSeen(NWN.Object oTarget, NWN.Object oSource = null)
        {
            NWN.Internal.StackPushObject(oSource, false);
            NWN.Internal.StackPushObject(oTarget, false);
            NWN.Internal.CallBuiltIn(289);
            return NWN.Internal.StackPopInteger();
        }

        //  Determine whether oSource hears oTarget.
        //  NOTE: This *only* works on creatures, as visibility lists are not
        //        maintained for non-creature objects.
        public static int GetObjectHeard(NWN.Object oTarget, NWN.Object oSource = null)
        {
            NWN.Internal.StackPushObject(oSource, false);
            NWN.Internal.StackPushObject(oTarget, false);
            NWN.Internal.CallBuiltIn(290);
            return NWN.Internal.StackPopInteger();
        }

        //  Use this in an OnPlayerDeath module script to get the last player that died.
        public static NWN.Object GetLastPlayerDied()
        {
            NWN.Internal.CallBuiltIn(291);
            return NWN.Internal.StackPopObject();
        }

        //  Use this in an OnItemLost script to get the item that was lost/dropped.
        //  * Returns OBJECT_INVALID if the module is not valid.
        public static NWN.Object GetModuleItemLost()
        {
            NWN.Internal.CallBuiltIn(292);
            return NWN.Internal.StackPopObject();
        }

        //  Use this in an OnItemLost script to get the creature that lost the item.
        //  * Returns OBJECT_INVALID if the module is not valid.
        public static NWN.Object GetModuleItemLostBy()
        {
            NWN.Internal.CallBuiltIn(293);
            return NWN.Internal.StackPopObject();
        }

        //  Do aActionToDo.
        //  Creates a conversation event.
        //  Note: This only creates the event. The event wont actually trigger until SignalEvent()
        //  is called using this created conversation event as an argument.
        //  For example:
        //      SignalEvent(oCreature, EventConversation());
        //  Once the event has been signaled. The script associated with the OnConversation event will
        //  run on the creature oCreature.
        // 
        //  To specify the OnConversation script that should run, view the Creature Properties on
        //  the creature and click on the Scripts Tab. Then specify a script for the OnConversation event.
        public static NWN.Event EventConversation()
        {
            NWN.Internal.CallBuiltIn(295);
            return NWN.Internal.StackPopEvent();
        }

        //  Set the difficulty level of oEncounter.
        //  - nEncounterDifficulty: ENCOUNTER_DIFFICULTY_*
        //  - oEncounter
        public static void SetEncounterDifficulty(int nEncounterDifficulty, NWN.Object oEncounter = null)
        {
            NWN.Internal.StackPushObject(oEncounter, false);
            NWN.Internal.StackPushInteger(nEncounterDifficulty);
            NWN.Internal.CallBuiltIn(296);
        }

        //  Get the difficulty level of oEncounter.
        public static int GetEncounterDifficulty(NWN.Object oEncounter = null)
        {
            NWN.Internal.StackPushObject(oEncounter, false);
            NWN.Internal.CallBuiltIn(297);
            return NWN.Internal.StackPopInteger();
        }

        //  Get the distance between lLocationA and lLocationB.
        public static float GetDistanceBetweenLocations(NWN.Location lLocationA, NWN.Location lLocationB)
        {
            NWN.Internal.StackPushLocation(lLocationB);
            NWN.Internal.StackPushLocation(lLocationA);
            NWN.Internal.CallBuiltIn(298);
            return NWN.Internal.StackPopFloat();
        }

        //  Use this in spell scripts to get nDamage adjusted by oTarget's reflex and
        //  evasion saves.
        //  - nDamage
        //  - oTarget
        //  - nDC: Difficulty check
        //  - nSaveType: SAVING_THROW_TYPE_*
        //  - oSaveVersus
        public static int GetReflexAdjustedDamage(int nDamage, NWN.Object oTarget, int nDC, int nSaveType = SAVING_THROW_TYPE_NONE, NWN.Object oSaveVersus = null)
        {
            NWN.Internal.StackPushObject(oSaveVersus, false);
            NWN.Internal.StackPushInteger(nSaveType);
            NWN.Internal.StackPushInteger(nDC);
            NWN.Internal.StackPushObject(oTarget, false);
            NWN.Internal.StackPushInteger(nDamage);
            NWN.Internal.CallBuiltIn(299);
            return NWN.Internal.StackPopInteger();
        }

        //  Play nAnimation immediately.
        //  - nAnimation: ANIMATION_*
        //  - fSpeed
        //  - fSeconds
        public static void PlayAnimation(int nAnimation, float fSpeed = 1.0f, float fSeconds = 0.0f)
        {
            NWN.Internal.StackPushFloat(fSeconds);
            NWN.Internal.StackPushFloat(fSpeed);
            NWN.Internal.StackPushInteger(nAnimation);
            NWN.Internal.CallBuiltIn(300);
        }

        //  Create a Spell Talent.
        //  - nSpell: SPELL_*
        public static NWN.Talent TalentSpell(int nSpell)
        {
            NWN.Internal.StackPushInteger(nSpell);
            NWN.Internal.CallBuiltIn(301);
            return NWN.Internal.StackPopTalent();
        }

        //  Create a Feat Talent.
        //  - nFeat: FEAT_*
        public static NWN.Talent TalentFeat(int nFeat)
        {
            NWN.Internal.StackPushInteger(nFeat);
            NWN.Internal.CallBuiltIn(302);
            return NWN.Internal.StackPopTalent();
        }

        //  Create a Skill Talent.
        //  - nSkill: SKILL_*
        public static NWN.Talent TalentSkill(int nSkill)
        {
            NWN.Internal.StackPushInteger(nSkill);
            NWN.Internal.CallBuiltIn(303);
            return NWN.Internal.StackPopTalent();
        }

        //  Determines whether oObject has any effects applied by nSpell
        //  - nSpell: SPELL_*
        //  - oObject
        //  * The spell id on effects is only valid if the effect is created
        //    when the spell script runs. If it is created in a delayed command
        //    then the spell id on the effect will be invalid.
        public static int GetHasSpellEffect(int nSpell, NWN.Object oObject = null)
        {
            NWN.Internal.StackPushObject(oObject, false);
            NWN.Internal.StackPushInteger(nSpell);
            NWN.Internal.CallBuiltIn(304);
            return NWN.Internal.StackPopInteger();
        }

        //  Get the spell (SPELL_*) that applied eSpellEffect.
        //  * Returns -1 if eSpellEffect was applied outside a spell script.
        public static int GetEffectSpellId(NWN.Effect eSpellEffect)
        {
            NWN.Internal.StackPushEffect(eSpellEffect);
            NWN.Internal.CallBuiltIn(305);
            return NWN.Internal.StackPopInteger();
        }

        //  Determine whether oCreature has tTalent.
        public static int GetCreatureHasTalent(NWN.Talent tTalent, NWN.Object oCreature = null)
        {
            NWN.Internal.StackPushObject(oCreature, false);
            NWN.Internal.StackPushTalent(tTalent);
            NWN.Internal.CallBuiltIn(306);
            return NWN.Internal.StackPopInteger();
        }

        //  Get a random talent of oCreature, within nCategory.
        //  - nCategory: TALENT_CATEGORY_*
        //  - oCreature
        public static NWN.Talent GetCreatureTalentRandom(int nCategory, NWN.Object oCreature = null)
        {
            NWN.Internal.StackPushObject(oCreature, false);
            NWN.Internal.StackPushInteger(nCategory);
            NWN.Internal.CallBuiltIn(307);
            return NWN.Internal.StackPopTalent();
        }

        //  Get the best talent (i.e. closest to nCRMax without going over) of oCreature,
        //  within nCategory.
        //  - nCategory: TALENT_CATEGORY_*
        //  - nCRMax: Challenge Rating of the talent
        //  - oCreature
        public static NWN.Talent GetCreatureTalentBest(int nCategory, int nCRMax, NWN.Object oCreature = null)
        {
            NWN.Internal.StackPushObject(oCreature, false);
            NWN.Internal.StackPushInteger(nCRMax);
            NWN.Internal.StackPushInteger(nCategory);
            NWN.Internal.CallBuiltIn(308);
            return NWN.Internal.StackPopTalent();
        }

        //  Use tChosenTalent on oTarget.
        public static void ActionUseTalentOnObject(NWN.Talent tChosenTalent, NWN.Object oTarget)
        {
            NWN.Internal.StackPushObject(oTarget, false);
            NWN.Internal.StackPushTalent(tChosenTalent);
            NWN.Internal.CallBuiltIn(309);
        }

        //  Use tChosenTalent at lTargetLocation.
        public static void ActionUseTalentAtLocation(NWN.Talent tChosenTalent, NWN.Location lTargetLocation)
        {
            NWN.Internal.StackPushLocation(lTargetLocation);
            NWN.Internal.StackPushTalent(tChosenTalent);
            NWN.Internal.CallBuiltIn(310);
        }

        //  Get the gold piece value of oItem.
        //  * Returns 0 if oItem is not a valid item.
        public static int GetGoldPieceValue(NWN.Object oItem)
        {
            NWN.Internal.StackPushObject(oItem, false);
            NWN.Internal.CallBuiltIn(311);
            return NWN.Internal.StackPopInteger();
        }

        //  * Returns TRUE if oCreature is of a playable racial type.
        public static int GetIsPlayableRacialType(NWN.Object oCreature)
        {
            NWN.Internal.StackPushObject(oCreature, false);
            NWN.Internal.CallBuiltIn(312);
            return NWN.Internal.StackPopInteger();
        }

        //  Jump to lDestination.  The action is added to the TOP of the action queue.
        public static void JumpToLocation(NWN.Location lDestination)
        {
            NWN.Internal.StackPushLocation(lDestination);
            NWN.Internal.CallBuiltIn(313);
        }

        //  Create a Temporary Hitpoints effect.
        //  - nHitPoints: a positive integer
        //  * Returns an effect of type EFFECT_TYPE_INVALIDEFFECT if nHitPoints < 0.
        public static NWN.Effect EffectTemporaryHitpoints(int nHitPoints)
        {
            NWN.Internal.StackPushInteger(nHitPoints);
            NWN.Internal.CallBuiltIn(314);
            return NWN.Internal.StackPopEffect();
        }

        //  Get the number of ranks that oTarget has in nSkill.
        //  - nSkill: SKILL_*
        //  - oTarget
        //  - nBaseSkillRank: if set to true returns the number of base skill ranks the target
        //                    has (i.e. not including any bonuses from ability scores, feats, etc).
        //  * Returns -1 if oTarget doesn't have nSkill.
        //  * Returns 0 if nSkill is untrained.
        public static int GetSkillRank(int nSkill, NWN.Object oTarget = null, int nBaseSkillRank = FALSE)
        {
            NWN.Internal.StackPushInteger(nBaseSkillRank);
            NWN.Internal.StackPushObject(oTarget, false);
            NWN.Internal.StackPushInteger(nSkill);
            NWN.Internal.CallBuiltIn(315);
            return NWN.Internal.StackPopInteger();
        }

        //  Get the attack target of oCreature.
        //  This only works when oCreature is in combat.
        public static NWN.Object GetAttackTarget(NWN.Object oCreature = null)
        {
            NWN.Internal.StackPushObject(oCreature, false);
            NWN.Internal.CallBuiltIn(316);
            return NWN.Internal.StackPopObject();
        }

        //  Get the attack type (SPECIAL_ATTACK_*) of oCreature's last attack.
        //  This only works when oCreature is in combat.
        public static int GetLastAttackType(NWN.Object oCreature = null)
        {
            NWN.Internal.StackPushObject(oCreature, false);
            NWN.Internal.CallBuiltIn(317);
            return NWN.Internal.StackPopInteger();
        }

        //  Get the attack mode (COMBAT_MODE_*) of oCreature's last attack.
        //  This only works when oCreature is in combat.
        public static int GetLastAttackMode(NWN.Object oCreature = null)
        {
            NWN.Internal.StackPushObject(oCreature, false);
            NWN.Internal.CallBuiltIn(318);
            return NWN.Internal.StackPopInteger();
        }

        //  Get the master of oAssociate.
        public static NWN.Object GetMaster(NWN.Object oAssociate = null)
        {
            NWN.Internal.StackPushObject(oAssociate, false);
            NWN.Internal.CallBuiltIn(319);
            return NWN.Internal.StackPopObject();
        }

        //  * Returns TRUE if oCreature is in combat.
        public static int GetIsInCombat(NWN.Object oCreature = null)
        {
            NWN.Internal.StackPushObject(oCreature, false);
            NWN.Internal.CallBuiltIn(320);
            return NWN.Internal.StackPopInteger();
        }

        //  Get the last command (ASSOCIATE_COMMAND_*) issued to oAssociate.
        public static int GetLastAssociateCommand(NWN.Object oAssociate = null)
        {
            NWN.Internal.StackPushObject(oAssociate, false);
            NWN.Internal.CallBuiltIn(321);
            return NWN.Internal.StackPopInteger();
        }

        //  Give nGP gold to oCreature.
        public static void GiveGoldToCreature(NWN.Object oCreature, int nGP)
        {
            NWN.Internal.StackPushInteger(nGP);
            NWN.Internal.StackPushObject(oCreature, false);
            NWN.Internal.CallBuiltIn(322);
        }

        //  Set the destroyable status of the caller.
        //  - bDestroyable: If this is FALSE, the caller does not fade out on death, but
        //    sticks around as a corpse.
        //  - bRaiseable: If this is TRUE, the caller can be raised via resurrection.
        //  - bSelectableWhenDead: If this is TRUE, the caller is selectable after death.
        public static void SetIsDestroyable(int bDestroyable, int bRaiseable = TRUE, int bSelectableWhenDead = FALSE)
        {
            NWN.Internal.StackPushInteger(bSelectableWhenDead);
            NWN.Internal.StackPushInteger(bRaiseable);
            NWN.Internal.StackPushInteger(bDestroyable);
            NWN.Internal.CallBuiltIn(323);
        }

        //  Set the locked state of oTarget, which can be a door or a placeable object.
        public static void SetLocked(NWN.Object oTarget, int bLocked)
        {
            NWN.Internal.StackPushInteger(bLocked);
            NWN.Internal.StackPushObject(oTarget, false);
            NWN.Internal.CallBuiltIn(324);
        }

        //  Get the locked state of oTarget, which can be a door or a placeable object.
        public static int GetLocked(NWN.Object oTarget)
        {
            NWN.Internal.StackPushObject(oTarget, false);
            NWN.Internal.CallBuiltIn(325);
            return NWN.Internal.StackPopInteger();
        }

        //  Use this in a trigger's OnClick event script to get the object that last
        //  clicked on it.
        //  This is identical to GetEnteringObject.
        //  GetClickingObject() should not be called from a placeable's OnClick event,
        //  instead use GetPlaceableLastClickedBy();
        public static NWN.Object GetClickingObject()
        {
            NWN.Internal.CallBuiltIn(326);
            return NWN.Internal.StackPopObject();
        }

        //  Initialise oTarget to listen for the standard Associates commands.
        public static void SetAssociateListenPatterns(NWN.Object oTarget = null)
        {
            NWN.Internal.StackPushObject(oTarget, false);
            NWN.Internal.CallBuiltIn(327);
        }

        //  Get the last weapon that oCreature used in an attack.
        //  * Returns OBJECT_INVALID if oCreature did not attack, or has no weapon equipped.
        public static NWN.Object GetLastWeaponUsed(NWN.Object oCreature)
        {
            NWN.Internal.StackPushObject(oCreature, false);
            NWN.Internal.CallBuiltIn(328);
            return NWN.Internal.StackPopObject();
        }

        //  Use oPlaceable.
        public static void ActionInteractObject(NWN.Object oPlaceable)
        {
            NWN.Internal.StackPushObject(oPlaceable, false);
            NWN.Internal.CallBuiltIn(329);
        }

        //  Get the last object that used the placeable object that is calling this function.
        //  * Returns OBJECT_INVALID if it is called by something other than a placeable or
        //    a door.
        public static NWN.Object GetLastUsedBy()
        {
            NWN.Internal.CallBuiltIn(330);
            return NWN.Internal.StackPopObject();
        }

        //  Returns the ability modifier for the specified ability
        //  Get oCreature's ability modifier for nAbility.
        //  - nAbility: ABILITY_*
        //  - oCreature
        public static int GetAbilityModifier(int nAbility, NWN.Object oCreature = null)
        {
            NWN.Internal.StackPushObject(oCreature, false);
            NWN.Internal.StackPushInteger(nAbility);
            NWN.Internal.CallBuiltIn(331);
            return NWN.Internal.StackPopInteger();
        }

        //  Determined whether oItem has been identified.
        public static int GetIdentified(NWN.Object oItem)
        {
            NWN.Internal.StackPushObject(oItem, false);
            NWN.Internal.CallBuiltIn(332);
            return NWN.Internal.StackPopInteger();
        }

        //  Set whether oItem has been identified.
        public static void SetIdentified(NWN.Object oItem, int bIdentified)
        {
            NWN.Internal.StackPushInteger(bIdentified);
            NWN.Internal.StackPushObject(oItem, false);
            NWN.Internal.CallBuiltIn(333);
        }

        //  Summon an Animal Companion
        public static void SummonAnimalCompanion(NWN.Object oMaster = null)
        {
            NWN.Internal.StackPushObject(oMaster, false);
            NWN.Internal.CallBuiltIn(334);
        }

        //  Summon a Familiar
        public static void SummonFamiliar(NWN.Object oMaster = null)
        {
            NWN.Internal.StackPushObject(oMaster, false);
            NWN.Internal.CallBuiltIn(335);
        }

        //  Get the last blocking door encountered by the caller of this function.
        //  * Returns OBJECT_INVALID if the caller is not a valid creature.
        public static NWN.Object GetBlockingDoor()
        {
            NWN.Internal.CallBuiltIn(336);
            return NWN.Internal.StackPopObject();
        }

        //  - oTargetDoor
        //  - nDoorAction: DOOR_ACTION_*
        //  * Returns TRUE if nDoorAction can be performed on oTargetDoor.
        public static int GetIsDoorActionPossible(NWN.Object oTargetDoor, int nDoorAction)
        {
            NWN.Internal.StackPushInteger(nDoorAction);
            NWN.Internal.StackPushObject(oTargetDoor, false);
            NWN.Internal.CallBuiltIn(337);
            return NWN.Internal.StackPopInteger();
        }

        //  Perform nDoorAction on oTargetDoor.
        public static void DoDoorAction(NWN.Object oTargetDoor, int nDoorAction)
        {
            NWN.Internal.StackPushInteger(nDoorAction);
            NWN.Internal.StackPushObject(oTargetDoor, false);
            NWN.Internal.CallBuiltIn(338);
        }

        //  Get the first item in oTarget's inventory (start to cycle through oTarget's
        //  inventory).
        //  * Returns OBJECT_INVALID if the caller is not a creature, item, placeable or store,
        //    or if no item is found.
        public static NWN.Object GetFirstItemInInventory(NWN.Object oTarget = null)
        {
            NWN.Internal.StackPushObject(oTarget, false);
            NWN.Internal.CallBuiltIn(339);
            return NWN.Internal.StackPopObject();
        }

        //  Get the next item in oTarget's inventory (continue to cycle through oTarget's
        //  inventory).
        //  * Returns OBJECT_INVALID if the caller is not a creature, item, placeable or store,
        //    or if no item is found.
        public static NWN.Object GetNextItemInInventory(NWN.Object oTarget = null)
        {
            NWN.Internal.StackPushObject(oTarget, false);
            NWN.Internal.CallBuiltIn(340);
            return NWN.Internal.StackPopObject();
        }

        //  A creature can have up to three classes.  This function determines the
        //  creature's class (CLASS_TYPE_*) based on nClassPosition.
        //  - nClassPosition: 1, 2 or 3
        //  - oCreature
        //  * Returns CLASS_TYPE_INVALID if the oCreature does not have a class in
        //    nClassPosition (i.e. a single-class creature will only have a value in
        //    nClassLocation=1) or if oCreature is not a valid creature.
        public static int GetClassByPosition(int nClassPosition, NWN.Object oCreature = null)
        {
            NWN.Internal.StackPushObject(oCreature, false);
            NWN.Internal.StackPushInteger(nClassPosition);
            NWN.Internal.CallBuiltIn(341);
            return NWN.Internal.StackPopInteger();
        }

        //  A creature can have up to three classes.  This function determines the
        //  creature's class level based on nClass Position.
        //  - nClassPosition: 1, 2 or 3
        //  - oCreature
        //  * Returns 0 if oCreature does not have a class in nClassPosition
        //    (i.e. a single-class creature will only have a value in nClassLocation=1)
        //    or if oCreature is not a valid creature.
        public static int GetLevelByPosition(int nClassPosition, NWN.Object oCreature = null)
        {
            NWN.Internal.StackPushObject(oCreature, false);
            NWN.Internal.StackPushInteger(nClassPosition);
            NWN.Internal.CallBuiltIn(342);
            return NWN.Internal.StackPopInteger();
        }

        //  Determine the levels that oCreature holds in nClassType.
        //  - nClassType: CLASS_TYPE_*
        //  - oCreature
        public static int GetLevelByClass(int nClassType, NWN.Object oCreature = null)
        {
            NWN.Internal.StackPushObject(oCreature, false);
            NWN.Internal.StackPushInteger(nClassType);
            NWN.Internal.CallBuiltIn(343);
            return NWN.Internal.StackPopInteger();
        }

        //  Get the amount of damage of type nDamageType that has been dealt to the caller.
        //  - nDamageType: DAMAGE_TYPE_*
        public static int GetDamageDealtByType(int nDamageType)
        {
            NWN.Internal.StackPushInteger(nDamageType);
            NWN.Internal.CallBuiltIn(344);
            return NWN.Internal.StackPopInteger();
        }

        //  Get the total amount of damage that has been dealt to the caller.
        public static int GetTotalDamageDealt()
        {
            NWN.Internal.CallBuiltIn(345);
            return NWN.Internal.StackPopInteger();
        }

        //  Get the last object that damaged oObject
        //  * Returns OBJECT_INVALID if the passed in object is not a valid object.
        public static NWN.Object GetLastDamager(NWN.Object oObject = null)
        {
            NWN.Internal.StackPushObject(oObject, false);
            NWN.Internal.CallBuiltIn(346);
            return NWN.Internal.StackPopObject();
        }

        //  Get the last object that disarmed the trap on the caller.
        //  * Returns OBJECT_INVALID if the caller is not a valid placeable, trigger or
        //    door.
        public static NWN.Object GetLastDisarmed()
        {
            NWN.Internal.CallBuiltIn(347);
            return NWN.Internal.StackPopObject();
        }

        //  Get the last object that disturbed the inventory of the caller.
        //  * Returns OBJECT_INVALID if the caller is not a valid creature or placeable.
        public static NWN.Object GetLastDisturbed()
        {
            NWN.Internal.CallBuiltIn(348);
            return NWN.Internal.StackPopObject();
        }

        //  Get the last object that locked the caller.
        //  * Returns OBJECT_INVALID if the caller is not a valid door or placeable.
        public static NWN.Object GetLastLocked()
        {
            NWN.Internal.CallBuiltIn(349);
            return NWN.Internal.StackPopObject();
        }

        //  Get the last object that unlocked the caller.
        //  * Returns OBJECT_INVALID if the caller is not a valid door or placeable.
        public static NWN.Object GetLastUnlocked()
        {
            NWN.Internal.CallBuiltIn(350);
            return NWN.Internal.StackPopObject();
        }

        //  Create a Skill Increase effect.
        //  - nSkill: SKILL_*
        //  - nValue
        //  * Returns an effect of type EFFECT_TYPE_INVALIDEFFECT if nSkill is invalid.
        public static NWN.Effect EffectSkillIncrease(int nSkill, int nValue)
        {
            NWN.Internal.StackPushInteger(nValue);
            NWN.Internal.StackPushInteger(nSkill);
            NWN.Internal.CallBuiltIn(351);
            return NWN.Internal.StackPopEffect();
        }

        //  Get the type of disturbance (INVENTORY_DISTURB_*) that caused the caller's
        //  OnInventoryDisturbed script to fire.  This will only work for creatures and
        //  placeables.
        public static int GetInventoryDisturbType()
        {
            NWN.Internal.CallBuiltIn(352);
            return NWN.Internal.StackPopInteger();
        }

        //  get the item that caused the caller's OnInventoryDisturbed script to fire.
        //  * Returns OBJECT_INVALID if the caller is not a valid object.
        public static NWN.Object GetInventoryDisturbItem()
        {
            NWN.Internal.CallBuiltIn(353);
            return NWN.Internal.StackPopObject();
        }

        //  Get the henchman belonging to oMaster.
        //  * Return OBJECT_INVALID if oMaster does not have a henchman.
        //  -nNth: Which henchman to return.
        public static NWN.Object GetHenchman(NWN.Object oMaster = null, int nNth = 1)
        {
            NWN.Internal.StackPushInteger(nNth);
            NWN.Internal.StackPushObject(oMaster, false);
            NWN.Internal.CallBuiltIn(354);
            return NWN.Internal.StackPopObject();
        }

        //  Set eEffect to be versus a specific alignment.
        //  - eEffect
        //  - nLawChaos: ALIGNMENT_LAWFUL/ALIGNMENT_CHAOTIC/ALIGNMENT_ALL
        //  - nGoodEvil: ALIGNMENT_GOOD/ALIGNMENT_EVIL/ALIGNMENT_ALL
        public static NWN.Effect VersusAlignmentEffect(NWN.Effect eEffect, int nLawChaos = ALIGNMENT_ALL, int nGoodEvil = ALIGNMENT_ALL)
        {
            NWN.Internal.StackPushInteger(nGoodEvil);
            NWN.Internal.StackPushInteger(nLawChaos);
            NWN.Internal.StackPushEffect(eEffect);
            NWN.Internal.CallBuiltIn(355);
            return NWN.Internal.StackPopEffect();
        }

        //  Set eEffect to be versus nRacialType.
        //  - eEffect
        //  - nRacialType: RACIAL_TYPE_*
        public static NWN.Effect VersusRacialTypeEffect(NWN.Effect eEffect, int nRacialType)
        {
            NWN.Internal.StackPushInteger(nRacialType);
            NWN.Internal.StackPushEffect(eEffect);
            NWN.Internal.CallBuiltIn(356);
            return NWN.Internal.StackPopEffect();
        }

        //  Set eEffect to be versus traps.
        public static NWN.Effect VersusTrapEffect(NWN.Effect eEffect)
        {
            NWN.Internal.StackPushEffect(eEffect);
            NWN.Internal.CallBuiltIn(357);
            return NWN.Internal.StackPopEffect();
        }

        //  Get the gender of oCreature.
        public static int GetGender(NWN.Object oCreature)
        {
            NWN.Internal.StackPushObject(oCreature, false);
            NWN.Internal.CallBuiltIn(358);
            return NWN.Internal.StackPopInteger();
        }

        //  * Returns TRUE if tTalent is valid.
        public static int GetIsTalentValid(NWN.Talent tTalent)
        {
            NWN.Internal.StackPushTalent(tTalent);
            NWN.Internal.CallBuiltIn(359);
            return NWN.Internal.StackPopInteger();
        }

        //  Causes the action subject to move away from lMoveAwayFrom.
        public static void ActionMoveAwayFromLocation(NWN.Location lMoveAwayFrom, int bRun = FALSE, float fMoveAwayRange = 40.0f)
        {
            NWN.Internal.StackPushFloat(fMoveAwayRange);
            NWN.Internal.StackPushInteger(bRun);
            NWN.Internal.StackPushLocation(lMoveAwayFrom);
            NWN.Internal.CallBuiltIn(360);
        }

        //  Get the target that the caller attempted to attack - this should be used in
        //  conjunction with GetAttackTarget(). This value is set every time an attack is
        //  made, and is reset at the end of combat.
        //  * Returns OBJECT_INVALID if the caller is not a valid creature.
        public static NWN.Object GetAttemptedAttackTarget()
        {
            NWN.Internal.CallBuiltIn(361);
            return NWN.Internal.StackPopObject();
        }

        //  Get the type (TALENT_TYPE_*) of tTalent.
        public static int GetTypeFromTalent(NWN.Talent tTalent)
        {
            NWN.Internal.StackPushTalent(tTalent);
            NWN.Internal.CallBuiltIn(362);
            return NWN.Internal.StackPopInteger();
        }

        //  Get the ID of tTalent.  This could be a SPELL_*, FEAT_* or SKILL_*.
        public static int GetIdFromTalent(NWN.Talent tTalent)
        {
            NWN.Internal.StackPushTalent(tTalent);
            NWN.Internal.CallBuiltIn(363);
            return NWN.Internal.StackPopInteger();
        }

        //  Get the associate of type nAssociateType belonging to oMaster.
        //  - nAssociateType: ASSOCIATE_TYPE_*
        //  - nMaster
        //  - nTh: Which associate of the specified type to return
        //  * Returns OBJECT_INVALID if no such associate exists.
        public static NWN.Object GetAssociate(int nAssociateType, NWN.Object oMaster = null, int nTh = 1)
        {
            NWN.Internal.StackPushInteger(nTh);
            NWN.Internal.StackPushObject(oMaster, false);
            NWN.Internal.StackPushInteger(nAssociateType);
            NWN.Internal.CallBuiltIn(364);
            return NWN.Internal.StackPopObject();
        }

        //  Add oHenchman as a henchman to oMaster
        //  If oHenchman is either a DM or a player character, this will have no effect.
        public static void AddHenchman(NWN.Object oMaster, NWN.Object oHenchman = null)
        {
            NWN.Internal.StackPushObject(oHenchman, false);
            NWN.Internal.StackPushObject(oMaster, false);
            NWN.Internal.CallBuiltIn(365);
        }

        //  Remove oHenchman from the service of oMaster, returning them to their original faction.
        public static void RemoveHenchman(NWN.Object oMaster, NWN.Object oHenchman = null)
        {
            NWN.Internal.StackPushObject(oHenchman, false);
            NWN.Internal.StackPushObject(oMaster, false);
            NWN.Internal.CallBuiltIn(366);
        }

        //  Add a journal quest entry to oCreature.
        //  - szPlotID: the plot identifier used in the toolset's Journal Editor
        //  - nState: the state of the plot as seen in the toolset's Journal Editor
        //  - oCreature
        //  - bAllPartyMembers: If this is TRUE, the entry will show up in the journal of
        //    everyone in the party
        //  - bAllPlayers: If this is TRUE, the entry will show up in the journal of
        //    everyone in the world
        //  - bAllowOverrideHigher: If this is TRUE, you can set the state to a lower
        //    number than the one it is currently on
        public static void AddJournalQuestEntry(string szPlotID, int nState, NWN.Object oCreature, int bAllPartyMembers = TRUE, int bAllPlayers = FALSE, int bAllowOverrideHigher = FALSE)
        {
            NWN.Internal.StackPushInteger(bAllowOverrideHigher);
            NWN.Internal.StackPushInteger(bAllPlayers);
            NWN.Internal.StackPushInteger(bAllPartyMembers);
            NWN.Internal.StackPushObject(oCreature, false);
            NWN.Internal.StackPushInteger(nState);
            NWN.Internal.StackPushString(szPlotID);
            NWN.Internal.CallBuiltIn(367);
        }

        //  Remove a journal quest entry from oCreature.
        //  - szPlotID: the plot identifier used in the toolset's Journal Editor
        //  - oCreature
        //  - bAllPartyMembers: If this is TRUE, the entry will be removed from the
        //    journal of everyone in the party
        //  - bAllPlayers: If this is TRUE, the entry will be removed from the journal of
        //    everyone in the world
        public static void RemoveJournalQuestEntry(string szPlotID, NWN.Object oCreature, int bAllPartyMembers = TRUE, int bAllPlayers = FALSE)
        {
            NWN.Internal.StackPushInteger(bAllPlayers);
            NWN.Internal.StackPushInteger(bAllPartyMembers);
            NWN.Internal.StackPushObject(oCreature, false);
            NWN.Internal.StackPushString(szPlotID);
            NWN.Internal.CallBuiltIn(368);
        }

        //  Get the public part of the CD Key that oPlayer used when logging in.
        //  - nSinglePlayerCDKey: If set to TRUE, the player's public CD Key will 
        //    be returned when the player is playing in single player mode 
        //    (otherwise returns an empty string in single player mode).
        public static string GetPCPublicCDKey(NWN.Object oPlayer, int nSinglePlayerCDKey = FALSE)
        {
            NWN.Internal.StackPushInteger(nSinglePlayerCDKey);
            NWN.Internal.StackPushObject(oPlayer, false);
            NWN.Internal.CallBuiltIn(369);
            return NWN.Internal.StackPopString();
        }

        //  Get the IP address from which oPlayer has connected.
        public static string GetPCIPAddress(NWN.Object oPlayer)
        {
            NWN.Internal.StackPushObject(oPlayer, false);
            NWN.Internal.CallBuiltIn(370);
            return NWN.Internal.StackPopString();
        }

        //  Get the name of oPlayer.
        public static string GetPCPlayerName(NWN.Object oPlayer)
        {
            NWN.Internal.StackPushObject(oPlayer, false);
            NWN.Internal.CallBuiltIn(371);
            return NWN.Internal.StackPopString();
        }

        //  Sets oPlayer and oTarget to like each other.
        public static void SetPCLike(NWN.Object oPlayer, NWN.Object oTarget)
        {
            NWN.Internal.StackPushObject(oTarget, false);
            NWN.Internal.StackPushObject(oPlayer, false);
            NWN.Internal.CallBuiltIn(372);
        }

        //  Sets oPlayer and oTarget to dislike each other.
        public static void SetPCDislike(NWN.Object oPlayer, NWN.Object oTarget)
        {
            NWN.Internal.StackPushObject(oTarget, false);
            NWN.Internal.StackPushObject(oPlayer, false);
            NWN.Internal.CallBuiltIn(373);
        }

        //  Send a server message (szMessage) to the oPlayer.
        public static void SendMessageToPC(NWN.Object oPlayer, string szMessage)
        {
            NWN.Internal.StackPushString(szMessage);
            NWN.Internal.StackPushObject(oPlayer, false);
            NWN.Internal.CallBuiltIn(374);
        }

        //  Get the target at which the caller attempted to cast a spell.
        //  This value is set every time a spell is cast and is reset at the end of
        //  combat.
        //  * Returns OBJECT_INVALID if the caller is not a valid creature.
        public static NWN.Object GetAttemptedSpellTarget()
        {
            NWN.Internal.CallBuiltIn(375);
            return NWN.Internal.StackPopObject();
        }

        //  Get the last creature that opened the caller.
        //  * Returns OBJECT_INVALID if the caller is not a valid door, placeable or store.
        public static NWN.Object GetLastOpenedBy()
        {
            NWN.Internal.CallBuiltIn(376);
            return NWN.Internal.StackPopObject();
        }

        //  Determines the number of times that oCreature has nSpell memorised.
        //  - nSpell: SPELL_*
        //  - oCreature
        public static int GetHasSpell(int nSpell, NWN.Object oCreature = null)
        {
            NWN.Internal.StackPushObject(oCreature, false);
            NWN.Internal.StackPushInteger(nSpell);
            NWN.Internal.CallBuiltIn(377);
            return NWN.Internal.StackPopInteger();
        }

        //  Open oStore for oPC.
        //  - nBonusMarkUp is added to the stores default mark up percentage on items sold (-100 to 100)
        //  - nBonusMarkDown is added to the stores default mark down percentage on items bought (-100 to 100)
        public static void OpenStore(NWN.Object oStore, NWN.Object oPC, int nBonusMarkUp = 0, int nBonusMarkDown = 0)
        {
            NWN.Internal.StackPushInteger(nBonusMarkDown);
            NWN.Internal.StackPushInteger(nBonusMarkUp);
            NWN.Internal.StackPushObject(oPC, false);
            NWN.Internal.StackPushObject(oStore, false);
            NWN.Internal.CallBuiltIn(378);
        }

        //  Create a Turned effect.
        //  Turned effects are supernatural by default.
        public static NWN.Effect EffectTurned()
        {
            NWN.Internal.CallBuiltIn(379);
            return NWN.Internal.StackPopEffect();
        }

        //  Get the first member of oMemberOfFaction's faction (start to cycle through
        //  oMemberOfFaction's faction).
        //  * Returns OBJECT_INVALID if oMemberOfFaction's faction is invalid.
        public static NWN.Object GetFirstFactionMember(NWN.Object oMemberOfFaction, int bPCOnly = TRUE)
        {
            NWN.Internal.StackPushInteger(bPCOnly);
            NWN.Internal.StackPushObject(oMemberOfFaction, false);
            NWN.Internal.CallBuiltIn(380);
            return NWN.Internal.StackPopObject();
        }

        //  Get the next member of oMemberOfFaction's faction (continue to cycle through
        //  oMemberOfFaction's faction).
        //  * Returns OBJECT_INVALID if oMemberOfFaction's faction is invalid.
        public static NWN.Object GetNextFactionMember(NWN.Object oMemberOfFaction, int bPCOnly = TRUE)
        {
            NWN.Internal.StackPushInteger(bPCOnly);
            NWN.Internal.StackPushObject(oMemberOfFaction, false);
            NWN.Internal.CallBuiltIn(381);
            return NWN.Internal.StackPopObject();
        }

        //  Force the action subject to move to lDestination.
        public static void ActionForceMoveToLocation(NWN.Location lDestination, int bRun = FALSE, float fTimeout = 30.0f)
        {
            NWN.Internal.StackPushFloat(fTimeout);
            NWN.Internal.StackPushInteger(bRun);
            NWN.Internal.StackPushLocation(lDestination);
            NWN.Internal.CallBuiltIn(382);
        }

        //  Force the action subject to move to oMoveTo.
        public static void ActionForceMoveToObject(NWN.Object oMoveTo, int bRun = FALSE, float fRange = 1.0f, float fTimeout = 30.0f)
        {
            NWN.Internal.StackPushFloat(fTimeout);
            NWN.Internal.StackPushFloat(fRange);
            NWN.Internal.StackPushInteger(bRun);
            NWN.Internal.StackPushObject(oMoveTo, false);
            NWN.Internal.CallBuiltIn(383);
        }

        //  Get the experience assigned in the journal editor for szPlotID.
        public static int GetJournalQuestExperience(string szPlotID)
        {
            NWN.Internal.StackPushString(szPlotID);
            NWN.Internal.CallBuiltIn(384);
            return NWN.Internal.StackPopInteger();
        }

        //  Jump to oToJumpTo (the action is added to the top of the action queue).
        public static void JumpToObject(NWN.Object oToJumpTo, int nWalkStraightLineToPoint = 1)
        {
            NWN.Internal.StackPushInteger(nWalkStraightLineToPoint);
            NWN.Internal.StackPushObject(oToJumpTo, false);
            NWN.Internal.CallBuiltIn(385);
        }

        //  Set whether oMapPin is enabled.
        //  - oMapPin
        //  - nEnabled: 0=Off, 1=On
        public static void SetMapPinEnabled(NWN.Object oMapPin, int nEnabled)
        {
            NWN.Internal.StackPushInteger(nEnabled);
            NWN.Internal.StackPushObject(oMapPin, false);
            NWN.Internal.CallBuiltIn(386);
        }

        //  Create a Hit Point Change When Dying effect.
        //  - fHitPointChangePerRound: this can be positive or negative, but not zero.
        //  * Returns an effect of type EFFECT_TYPE_INVALIDEFFECT if fHitPointChangePerRound is 0.
        public static NWN.Effect EffectHitPointChangeWhenDying(float fHitPointChangePerRound)
        {
            NWN.Internal.StackPushFloat(fHitPointChangePerRound);
            NWN.Internal.CallBuiltIn(387);
            return NWN.Internal.StackPopEffect();
        }

        //  Spawn a GUI panel for the client that controls oPC.
        //  - oPC
        //  - nGUIPanel: GUI_PANEL_*
        //  * Nothing happens if oPC is not a player character or if an invalid value is
        //    used for nGUIPanel.
        public static void PopUpGUIPanel(NWN.Object oPC, int nGUIPanel)
        {
            NWN.Internal.StackPushInteger(nGUIPanel);
            NWN.Internal.StackPushObject(oPC, false);
            NWN.Internal.CallBuiltIn(388);
        }

        //  Clear all personal feelings that oSource has about oTarget.
        public static void ClearPersonalReputation(NWN.Object oTarget, NWN.Object oSource = null)
        {
            NWN.Internal.StackPushObject(oSource, false);
            NWN.Internal.StackPushObject(oTarget, false);
            NWN.Internal.CallBuiltIn(389);
        }

        //  oSource will temporarily be friends towards oTarget.
        //  bDecays determines whether the personal reputation value decays over time
        //  fDurationInSeconds is the length of time that the temporary friendship lasts
        //  Make oSource into a temporary friend of oTarget using personal reputation.
        //  - oTarget
        //  - oSource
        //  - bDecays: If this is TRUE, the friendship decays over fDurationInSeconds;
        //    otherwise it is indefinite.
        //  - fDurationInSeconds: This is only used if bDecays is TRUE, it is how long
        //    the friendship lasts.
        //  Note: If bDecays is TRUE, the personal reputation amount decreases in size
        //  over fDurationInSeconds. Friendship will only be in effect as long as
        //  (faction reputation + total personal reputation) >= REPUTATION_TYPE_FRIEND.
        public static void SetIsTemporaryFriend(NWN.Object oTarget, NWN.Object oSource = null, int bDecays = FALSE, float fDurationInSeconds = 180.0f)
        {
            NWN.Internal.StackPushFloat(fDurationInSeconds);
            NWN.Internal.StackPushInteger(bDecays);
            NWN.Internal.StackPushObject(oSource, false);
            NWN.Internal.StackPushObject(oTarget, false);
            NWN.Internal.CallBuiltIn(390);
        }

        //  Make oSource into a temporary enemy of oTarget using personal reputation.
        //  - oTarget
        //  - oSource
        //  - bDecays: If this is TRUE, the enmity decays over fDurationInSeconds;
        //    otherwise it is indefinite.
        //  - fDurationInSeconds: This is only used if bDecays is TRUE, it is how long
        //    the enmity lasts.
        //  Note: If bDecays is TRUE, the personal reputation amount decreases in size
        //  over fDurationInSeconds. Enmity will only be in effect as long as
        //  (faction reputation + total personal reputation) <= REPUTATION_TYPE_ENEMY.
        public static void SetIsTemporaryEnemy(NWN.Object oTarget, NWN.Object oSource = null, int bDecays = FALSE, float fDurationInSeconds = 180.0f)
        {
            NWN.Internal.StackPushFloat(fDurationInSeconds);
            NWN.Internal.StackPushInteger(bDecays);
            NWN.Internal.StackPushObject(oSource, false);
            NWN.Internal.StackPushObject(oTarget, false);
            NWN.Internal.CallBuiltIn(391);
        }

        //  Make oSource temporarily neutral to oTarget using personal reputation.
        //  - oTarget
        //  - oSource
        //  - bDecays: If this is TRUE, the neutrality decays over fDurationInSeconds;
        //    otherwise it is indefinite.
        //  - fDurationInSeconds: This is only used if bDecays is TRUE, it is how long
        //    the neutrality lasts.
        //  Note: If bDecays is TRUE, the personal reputation amount decreases in size
        //  over fDurationInSeconds. Neutrality will only be in effect as long as
        //  (faction reputation + total personal reputation) > REPUTATION_TYPE_ENEMY and
        //  (faction reputation + total personal reputation) < REPUTATION_TYPE_FRIEND.
        public static void SetIsTemporaryNeutral(NWN.Object oTarget, NWN.Object oSource = null, int bDecays = FALSE, float fDurationInSeconds = 180.0f)
        {
            NWN.Internal.StackPushFloat(fDurationInSeconds);
            NWN.Internal.StackPushInteger(bDecays);
            NWN.Internal.StackPushObject(oSource, false);
            NWN.Internal.StackPushObject(oTarget, false);
            NWN.Internal.CallBuiltIn(392);
        }

        //  Gives nXpAmount to oCreature.
        public static void GiveXPToCreature(NWN.Object oCreature, int nXpAmount)
        {
            NWN.Internal.StackPushInteger(nXpAmount);
            NWN.Internal.StackPushObject(oCreature, false);
            NWN.Internal.CallBuiltIn(393);
        }

        //  Sets oCreature's experience to nXpAmount.
        public static void SetXP(NWN.Object oCreature, int nXpAmount)
        {
            NWN.Internal.StackPushInteger(nXpAmount);
            NWN.Internal.StackPushObject(oCreature, false);
            NWN.Internal.CallBuiltIn(394);
        }

        //  Get oCreature's experience.
        public static int GetXP(NWN.Object oCreature)
        {
            NWN.Internal.StackPushObject(oCreature, false);
            NWN.Internal.CallBuiltIn(395);
            return NWN.Internal.StackPopInteger();
        }

        //  Convert nInteger to hex, returning the hex value as a string.
        //  * Return value has the format "0x????????" where each ? will be a hex digit
        //    (8 digits in total).
        public static string IntToHexString(int nInteger)
        {
            NWN.Internal.StackPushInteger(nInteger);
            NWN.Internal.CallBuiltIn(396);
            return NWN.Internal.StackPopString();
        }

        //  Get the base item type (BASE_ITEM_*) of oItem.
        //  * Returns BASE_ITEM_INVALID if oItem is an invalid item.
        public static int GetBaseItemType(NWN.Object oItem)
        {
            NWN.Internal.StackPushObject(oItem, false);
            NWN.Internal.CallBuiltIn(397);
            return NWN.Internal.StackPopInteger();
        }

        //  Determines whether oItem has nProperty.
        //  - oItem
        //  - nProperty: ITEM_PROPERTY_*
        //  * Returns FALSE if oItem is not a valid item, or if oItem does not have
        //    nProperty.
        public static int GetItemHasItemProperty(NWN.Object oItem, int nProperty)
        {
            NWN.Internal.StackPushInteger(nProperty);
            NWN.Internal.StackPushObject(oItem, false);
            NWN.Internal.CallBuiltIn(398);
            return NWN.Internal.StackPopInteger();
        }

        //  The creature will equip the melee weapon in its possession that can do the
        //  most damage. If no valid melee weapon is found, it will equip the most
        //  damaging range weapon. This function should only ever be called in the
        //  EndOfCombatRound scripts, because otherwise it would have to stop the combat
        //  round to run simulation.
        //  - oVersus: You can try to get the most damaging weapon against oVersus
        //  - bOffHand
        public static void ActionEquipMostDamagingMelee(NWN.Object oVersus = null, int bOffHand = FALSE)
        {
            NWN.Internal.StackPushInteger(bOffHand);
            NWN.Internal.StackPushObject(oVersus, false);
            NWN.Internal.CallBuiltIn(399);
        }

        //  The creature will equip the range weapon in its possession that can do the
        //  most damage.
        //  If no valid range weapon can be found, it will equip the most damaging melee
        //  weapon.
        //  - oVersus: You can try to get the most damaging weapon against oVersus
        public static void ActionEquipMostDamagingRanged(NWN.Object oVersus = null)
        {
            NWN.Internal.StackPushObject(oVersus, false);
            NWN.Internal.CallBuiltIn(400);
        }

        //  Get the Armour Class of oItem.
        //  * Return 0 if the oItem is not a valid item, or if oItem has no armour value.
        public static int GetItemACValue(NWN.Object oItem)
        {
            NWN.Internal.StackPushObject(oItem, false);
            NWN.Internal.CallBuiltIn(401);
            return NWN.Internal.StackPopInteger();
        }

        //  The creature will rest if not in combat and no enemies are nearby.
        //  - bCreatureToEnemyLineOfSightCheck: TRUE to allow the creature to rest if enemies
        //                                      are nearby, but the creature can't see the enemy.
        //                                      FALSE the creature will not rest if enemies are
        //                                      nearby regardless of whether or not the creature
        //                                      can see them, such as if an enemy is close by,
        //                                      but is in a different room behind a closed door.
        public static void ActionRest(int bCreatureToEnemyLineOfSightCheck = FALSE)
        {
            NWN.Internal.StackPushInteger(bCreatureToEnemyLineOfSightCheck);
            NWN.Internal.CallBuiltIn(402);
        }

        //  Expose/Hide the entire map of oArea for oPlayer.
        //  - oArea: The area that the map will be exposed/hidden for.
        //  - oPlayer: The player the map will be exposed/hidden for.
        //  - bExplored: TRUE/FALSE. Whether the map should be completely explored or hidden.
        public static void ExploreAreaForPlayer(NWN.Object oArea, NWN.Object oPlayer, int bExplored = TRUE)
        {
            NWN.Internal.StackPushInteger(bExplored);
            NWN.Internal.StackPushObject(oPlayer, false);
            NWN.Internal.StackPushObject(oArea, false);
            NWN.Internal.CallBuiltIn(403);
        }

        //  The creature will equip the armour in its possession that has the highest
        //  armour class.
        public static void ActionEquipMostEffectiveArmor()
        {
            NWN.Internal.CallBuiltIn(404);
        }

        //  * Returns TRUE if it is currently day.
        public static int GetIsDay()
        {
            NWN.Internal.CallBuiltIn(405);
            return NWN.Internal.StackPopInteger();
        }

        //  * Returns TRUE if it is currently night.
        public static int GetIsNight()
        {
            NWN.Internal.CallBuiltIn(406);
            return NWN.Internal.StackPopInteger();
        }

        //  * Returns TRUE if it is currently dawn.
        public static int GetIsDawn()
        {
            NWN.Internal.CallBuiltIn(407);
            return NWN.Internal.StackPopInteger();
        }

        //  * Returns TRUE if it is currently dusk.
        public static int GetIsDusk()
        {
            NWN.Internal.CallBuiltIn(408);
            return NWN.Internal.StackPopInteger();
        }

        //  * Returns TRUE if oCreature was spawned from an encounter.
        public static int GetIsEncounterCreature(NWN.Object oCreature = null)
        {
            NWN.Internal.StackPushObject(oCreature, false);
            NWN.Internal.CallBuiltIn(409);
            return NWN.Internal.StackPopInteger();
        }

        //  Use this in an OnPlayerDying module script to get the last player who is dying.
        public static NWN.Object GetLastPlayerDying()
        {
            NWN.Internal.CallBuiltIn(410);
            return NWN.Internal.StackPopObject();
        }

        //  Get the starting location of the module.
        public static NWN.Location GetStartingLocation()
        {
            NWN.Internal.CallBuiltIn(411);
            return NWN.Internal.StackPopLocation();
        }

        //  Make oCreatureToChange join one of the standard factions.
        //  ** This will only work on an NPC **
        //  - nStandardFaction: STANDARD_FACTION_*
        public static void ChangeToStandardFaction(NWN.Object oCreatureToChange, int nStandardFaction)
        {
            NWN.Internal.StackPushInteger(nStandardFaction);
            NWN.Internal.StackPushObject(oCreatureToChange, false);
            NWN.Internal.CallBuiltIn(412);
        }

        //  Play oSound.
        public static void SoundObjectPlay(NWN.Object oSound)
        {
            NWN.Internal.StackPushObject(oSound, false);
            NWN.Internal.CallBuiltIn(413);
        }

        //  Stop playing oSound.
        public static void SoundObjectStop(NWN.Object oSound)
        {
            NWN.Internal.StackPushObject(oSound, false);
            NWN.Internal.CallBuiltIn(414);
        }

        //  Set the volume of oSound.
        //  - oSound
        //  - nVolume: 0-127
        public static void SoundObjectSetVolume(NWN.Object oSound, int nVolume)
        {
            NWN.Internal.StackPushInteger(nVolume);
            NWN.Internal.StackPushObject(oSound, false);
            NWN.Internal.CallBuiltIn(415);
        }

        //  Set the position of oSound.
        public static void SoundObjectSetPosition(NWN.Object oSound, NWN.Vector? vPosition)
        {
            NWN.Internal.StackPushVector(vPosition);
            NWN.Internal.StackPushObject(oSound, false);
            NWN.Internal.CallBuiltIn(416);
        }

        //  Immediately speak a conversation one-liner.
        //  - sDialogResRef
        //  - oTokenTarget: This must be specified if there are creature-specific tokens
        //    in the string.
        public static void SpeakOneLinerConversation(string sDialogResRef = "", NWN.Object oTokenTarget = null)
        {
            NWN.Internal.StackPushObject(oTokenTarget, false);
            NWN.Internal.StackPushString(sDialogResRef);
            NWN.Internal.CallBuiltIn(417);
        }

        //  Get the amount of gold possessed by oTarget.
        public static int GetGold(NWN.Object oTarget = null)
        {
            NWN.Internal.StackPushObject(oTarget, false);
            NWN.Internal.CallBuiltIn(418);
            return NWN.Internal.StackPopInteger();
        }

        //  Use this in an OnRespawnButtonPressed module script to get the object id of
        //  the player who last pressed the respawn button.
        public static NWN.Object GetLastRespawnButtonPresser()
        {
            NWN.Internal.CallBuiltIn(419);
            return NWN.Internal.StackPopObject();
        }

        //  * Returns TRUE if oCreature is the Dungeon Master.
        //  Note: This will return FALSE if oCreature is a DM Possessed creature.
        //  To determine if oCreature is a DM Possessed creature, use GetIsDMPossessed()
        public static int GetIsDM(NWN.Object oCreature)
        {
            NWN.Internal.StackPushObject(oCreature, false);
            NWN.Internal.CallBuiltIn(420);
            return NWN.Internal.StackPopInteger();
        }

        //  Play a voice chat.
        //  - nVoiceChatID: VOICE_CHAT_*
        //  - oTarget
        public static void PlayVoiceChat(int nVoiceChatID, NWN.Object oTarget = null)
        {
            NWN.Internal.StackPushObject(oTarget, false);
            NWN.Internal.StackPushInteger(nVoiceChatID);
            NWN.Internal.CallBuiltIn(421);
        }

        //  * Returns TRUE if the weapon equipped is capable of damaging oVersus.
        public static int GetIsWeaponEffective(NWN.Object oVersus = null, int bOffHand = FALSE)
        {
            NWN.Internal.StackPushInteger(bOffHand);
            NWN.Internal.StackPushObject(oVersus, false);
            NWN.Internal.CallBuiltIn(422);
            return NWN.Internal.StackPopInteger();
        }

        //  Use this in a SpellCast script to determine whether the spell was considered
        //  harmful.
        //  * Returns TRUE if the last spell cast was harmful.
        public static int GetLastSpellHarmful()
        {
            NWN.Internal.CallBuiltIn(423);
            return NWN.Internal.StackPopInteger();
        }

        //  Activate oItem.
        public static NWN.Event EventActivateItem(NWN.Object oItem, NWN.Location lTarget, NWN.Object oTarget = null)
        {
            NWN.Internal.StackPushObject(oTarget, false);
            NWN.Internal.StackPushLocation(lTarget);
            NWN.Internal.StackPushObject(oItem, false);
            NWN.Internal.CallBuiltIn(424);
            return NWN.Internal.StackPopEvent();
        }

        //  Play the background music for oArea.
        public static void MusicBackgroundPlay(NWN.Object oArea)
        {
            NWN.Internal.StackPushObject(oArea, false);
            NWN.Internal.CallBuiltIn(425);
        }

        //  Stop the background music for oArea.
        public static void MusicBackgroundStop(NWN.Object oArea)
        {
            NWN.Internal.StackPushObject(oArea, false);
            NWN.Internal.CallBuiltIn(426);
        }

        //  Set the delay for the background music for oArea.
        //  - oArea
        //  - nDelay: delay in milliseconds
        public static void MusicBackgroundSetDelay(NWN.Object oArea, int nDelay)
        {
            NWN.Internal.StackPushInteger(nDelay);
            NWN.Internal.StackPushObject(oArea, false);
            NWN.Internal.CallBuiltIn(427);
        }

        //  Change the background day track for oArea to nTrack.
        //  - oArea
        //  - nTrack
        public static void MusicBackgroundChangeDay(NWN.Object oArea, int nTrack)
        {
            NWN.Internal.StackPushInteger(nTrack);
            NWN.Internal.StackPushObject(oArea, false);
            NWN.Internal.CallBuiltIn(428);
        }

        //  Change the background night track for oArea to nTrack.
        //  - oArea
        //  - nTrack
        public static void MusicBackgroundChangeNight(NWN.Object oArea, int nTrack)
        {
            NWN.Internal.StackPushInteger(nTrack);
            NWN.Internal.StackPushObject(oArea, false);
            NWN.Internal.CallBuiltIn(429);
        }

        //  Play the battle music for oArea.
        public static void MusicBattlePlay(NWN.Object oArea)
        {
            NWN.Internal.StackPushObject(oArea, false);
            NWN.Internal.CallBuiltIn(430);
        }

        //  Stop the battle music for oArea.
        public static void MusicBattleStop(NWN.Object oArea)
        {
            NWN.Internal.StackPushObject(oArea, false);
            NWN.Internal.CallBuiltIn(431);
        }

        //  Change the battle track for oArea.
        //  - oArea
        //  - nTrack
        public static void MusicBattleChange(NWN.Object oArea, int nTrack)
        {
            NWN.Internal.StackPushInteger(nTrack);
            NWN.Internal.StackPushObject(oArea, false);
            NWN.Internal.CallBuiltIn(432);
        }

        //  Play the ambient sound for oArea.
        public static void AmbientSoundPlay(NWN.Object oArea)
        {
            NWN.Internal.StackPushObject(oArea, false);
            NWN.Internal.CallBuiltIn(433);
        }

        //  Stop the ambient sound for oArea.
        public static void AmbientSoundStop(NWN.Object oArea)
        {
            NWN.Internal.StackPushObject(oArea, false);
            NWN.Internal.CallBuiltIn(434);
        }

        //  Change the ambient day track for oArea to nTrack.
        //  - oArea
        //  - nTrack
        public static void AmbientSoundChangeDay(NWN.Object oArea, int nTrack)
        {
            NWN.Internal.StackPushInteger(nTrack);
            NWN.Internal.StackPushObject(oArea, false);
            NWN.Internal.CallBuiltIn(435);
        }

        //  Change the ambient night track for oArea to nTrack.
        //  - oArea
        //  - nTrack
        public static void AmbientSoundChangeNight(NWN.Object oArea, int nTrack)
        {
            NWN.Internal.StackPushInteger(nTrack);
            NWN.Internal.StackPushObject(oArea, false);
            NWN.Internal.CallBuiltIn(436);
        }

        //  Get the object that killed the caller.
        public static NWN.Object GetLastKiller()
        {
            NWN.Internal.CallBuiltIn(437);
            return NWN.Internal.StackPopObject();
        }

        //  Use this in a spell script to get the item used to cast the spell.
        public static NWN.Object GetSpellCastItem()
        {
            NWN.Internal.CallBuiltIn(438);
            return NWN.Internal.StackPopObject();
        }

        //  Use this in an OnItemActivated module script to get the item that was activated.
        public static NWN.Object GetItemActivated()
        {
            NWN.Internal.CallBuiltIn(439);
            return NWN.Internal.StackPopObject();
        }

        //  Use this in an OnItemActivated module script to get the creature that
        //  activated the item.
        public static NWN.Object GetItemActivator()
        {
            NWN.Internal.CallBuiltIn(440);
            return NWN.Internal.StackPopObject();
        }

        //  Use this in an OnItemActivated module script to get the location of the item's
        //  target.
        public static NWN.Location GetItemActivatedTargetLocation()
        {
            NWN.Internal.CallBuiltIn(441);
            return NWN.Internal.StackPopLocation();
        }

        //  Use this in an OnItemActivated module script to get the item's target.
        public static NWN.Object GetItemActivatedTarget()
        {
            NWN.Internal.CallBuiltIn(442);
            return NWN.Internal.StackPopObject();
        }

        //  * Returns TRUE if oObject (which is a placeable or a door) is currently open.
        public static int GetIsOpen(NWN.Object oObject)
        {
            NWN.Internal.StackPushObject(oObject, false);
            NWN.Internal.CallBuiltIn(443);
            return NWN.Internal.StackPopInteger();
        }

        //  Take nAmount of gold from oCreatureToTakeFrom.
        //  - nAmount
        //  - oCreatureToTakeFrom: If this is not a valid creature, nothing will happen.
        //  - bDestroy: If this is TRUE, the caller will not get the gold.  Instead, the
        //    gold will be destroyed and will vanish from the game.
        public static void TakeGoldFromCreature(int nAmount, NWN.Object oCreatureToTakeFrom, int bDestroy = FALSE)
        {
            NWN.Internal.StackPushInteger(bDestroy);
            NWN.Internal.StackPushObject(oCreatureToTakeFrom, false);
            NWN.Internal.StackPushInteger(nAmount);
            NWN.Internal.CallBuiltIn(444);
        }

        //  Determine whether oObject is in conversation.
        public static int IsInConversation(NWN.Object oObject)
        {
            NWN.Internal.StackPushObject(oObject, false);
            NWN.Internal.CallBuiltIn(445);
            return NWN.Internal.StackPopInteger();
        }

        //  Create an Ability Decrease effect.
        //  - nAbility: ABILITY_*
        //  - nModifyBy: This is the amount by which to decrement the ability
        public static NWN.Effect EffectAbilityDecrease(int nAbility, int nModifyBy)
        {
            NWN.Internal.StackPushInteger(nModifyBy);
            NWN.Internal.StackPushInteger(nAbility);
            NWN.Internal.CallBuiltIn(446);
            return NWN.Internal.StackPopEffect();
        }

        //  Create an Attack Decrease effect.
        //  - nPenalty
        //  - nModifierType: ATTACK_BONUS_*
        public static NWN.Effect EffectAttackDecrease(int nPenalty, int nModifierType = ATTACK_BONUS_MISC)
        {
            NWN.Internal.StackPushInteger(nModifierType);
            NWN.Internal.StackPushInteger(nPenalty);
            NWN.Internal.CallBuiltIn(447);
            return NWN.Internal.StackPopEffect();
        }

        //  Create a Damage Decrease effect.
        //  - nPenalty
        //  - nDamageType: DAMAGE_TYPE_*
        public static NWN.Effect EffectDamageDecrease(int nPenalty, int nDamageType = DAMAGE_TYPE_MAGICAL)
        {
            NWN.Internal.StackPushInteger(nDamageType);
            NWN.Internal.StackPushInteger(nPenalty);
            NWN.Internal.CallBuiltIn(448);
            return NWN.Internal.StackPopEffect();
        }

        //  Create a Damage Immunity Decrease effect.
        //  - nDamageType: DAMAGE_TYPE_*
        //  - nPercentImmunity
        public static NWN.Effect EffectDamageImmunityDecrease(int nDamageType, int nPercentImmunity)
        {
            NWN.Internal.StackPushInteger(nPercentImmunity);
            NWN.Internal.StackPushInteger(nDamageType);
            NWN.Internal.CallBuiltIn(449);
            return NWN.Internal.StackPopEffect();
        }

        //  Create an AC Decrease effect.
        //  - nValue
        //  - nModifyType: AC_*
        //  - nDamageType: DAMAGE_TYPE_*
        //    * Default value for nDamageType should only ever be used in this function prototype.
        public static NWN.Effect EffectACDecrease(int nValue, int nModifyType = AC_DODGE_BONUS, int nDamageType = AC_VS_DAMAGE_TYPE_ALL)
        {
            NWN.Internal.StackPushInteger(nDamageType);
            NWN.Internal.StackPushInteger(nModifyType);
            NWN.Internal.StackPushInteger(nValue);
            NWN.Internal.CallBuiltIn(450);
            return NWN.Internal.StackPopEffect();
        }

        //  Create a Movement Speed Decrease effect.
        //  - nPercentChange - range 0 through 99
        //  eg.
        //     0 = no change in speed
        //    50 = 50% slower
        //    99 = almost immobile
        public static NWN.Effect EffectMovementSpeedDecrease(int nPercentChange)
        {
            NWN.Internal.StackPushInteger(nPercentChange);
            NWN.Internal.CallBuiltIn(451);
            return NWN.Internal.StackPopEffect();
        }

        //  Create a Saving Throw Decrease effect.
        //  - nSave: SAVING_THROW_* (not SAVING_THROW_TYPE_*)
        //           SAVING_THROW_ALL
        //           SAVING_THROW_FORT
        //           SAVING_THROW_REFLEX
        //           SAVING_THROW_WILL 
        //  - nValue: size of the Saving Throw decrease
        //  - nSaveType: SAVING_THROW_TYPE_* (e.g. SAVING_THROW_TYPE_ACID )
        public static NWN.Effect EffectSavingThrowDecrease(int nSave, int nValue, int nSaveType = SAVING_THROW_TYPE_ALL)
        {
            NWN.Internal.StackPushInteger(nSaveType);
            NWN.Internal.StackPushInteger(nValue);
            NWN.Internal.StackPushInteger(nSave);
            NWN.Internal.CallBuiltIn(452);
            return NWN.Internal.StackPopEffect();
        }

        //  Create a Skill Decrease effect.
        //  * Returns an effect of type EFFECT_TYPE_INVALIDEFFECT if nSkill is invalid.
        public static NWN.Effect EffectSkillDecrease(int nSkill, int nValue)
        {
            NWN.Internal.StackPushInteger(nValue);
            NWN.Internal.StackPushInteger(nSkill);
            NWN.Internal.CallBuiltIn(453);
            return NWN.Internal.StackPopEffect();
        }

        //  Create a Spell Resistance Decrease effect.
        public static NWN.Effect EffectSpellResistanceDecrease(int nValue)
        {
            NWN.Internal.StackPushInteger(nValue);
            NWN.Internal.CallBuiltIn(454);
            return NWN.Internal.StackPopEffect();
        }

        //  Determine whether oTarget is a plot object.
        public static int GetPlotFlag(NWN.Object oTarget = null)
        {
            NWN.Internal.StackPushObject(oTarget, false);
            NWN.Internal.CallBuiltIn(455);
            return NWN.Internal.StackPopInteger();
        }

        //  Set oTarget's plot object status.
        public static void SetPlotFlag(NWN.Object oTarget, int nPlotFlag)
        {
            NWN.Internal.StackPushInteger(nPlotFlag);
            NWN.Internal.StackPushObject(oTarget, false);
            NWN.Internal.CallBuiltIn(456);
        }

        //  Create an Invisibility effect.
        //  - nInvisibilityType: INVISIBILITY_TYPE_*
        //  * Returns an effect of type EFFECT_TYPE_INVALIDEFFECT if nInvisibilityType
        //    is invalid.
        public static NWN.Effect EffectInvisibility(int nInvisibilityType)
        {
            NWN.Internal.StackPushInteger(nInvisibilityType);
            NWN.Internal.CallBuiltIn(457);
            return NWN.Internal.StackPopEffect();
        }

        //  Create a Concealment effect.
        //  - nPercentage: 1-100 inclusive
        //  - nMissChanceType: MISS_CHANCE_TYPE_*
        //  * Returns an effect of type EFFECT_TYPE_INVALIDEFFECT if nPercentage < 1 or
        //    nPercentage > 100.
        public static NWN.Effect EffectConcealment(int nPercentage, int nMissType = MISS_CHANCE_TYPE_NORMAL)
        {
            NWN.Internal.StackPushInteger(nMissType);
            NWN.Internal.StackPushInteger(nPercentage);
            NWN.Internal.CallBuiltIn(458);
            return NWN.Internal.StackPopEffect();
        }

        //  Create a Darkness effect.
        public static NWN.Effect EffectDarkness()
        {
            NWN.Internal.CallBuiltIn(459);
            return NWN.Internal.StackPopEffect();
        }

        //  Create a Dispel Magic All effect.
        //  If no parameter is specified, USE_CREATURE_LEVEL will be used. This will
        //  cause the dispel effect to use the level of the creature that created the
        //  effect.
        public static NWN.Effect EffectDispelMagicAll(int nCasterLevel = USE_CREATURE_LEVEL)
        {
            NWN.Internal.StackPushInteger(nCasterLevel);
            NWN.Internal.CallBuiltIn(460);
            return NWN.Internal.StackPopEffect();
        }

        //  Create an Ultravision effect.
        public static NWN.Effect EffectUltravision()
        {
            NWN.Internal.CallBuiltIn(461);
            return NWN.Internal.StackPopEffect();
        }

        //  Create a Negative Level effect.
        //  - nNumLevels: the number of negative levels to apply.
        //  * Returns an effect of type EFFECT_TYPE_INVALIDEFFECT if nNumLevels > 100.
        public static NWN.Effect EffectNegativeLevel(int nNumLevels, int bHPBonus = FALSE)
        {
            NWN.Internal.StackPushInteger(bHPBonus);
            NWN.Internal.StackPushInteger(nNumLevels);
            NWN.Internal.CallBuiltIn(462);
            return NWN.Internal.StackPopEffect();
        }

        //  Create a Polymorph effect.
        public static NWN.Effect EffectPolymorph(int nPolymorphSelection, int nLocked = FALSE)
        {
            NWN.Internal.StackPushInteger(nLocked);
            NWN.Internal.StackPushInteger(nPolymorphSelection);
            NWN.Internal.CallBuiltIn(463);
            return NWN.Internal.StackPopEffect();
        }

        //  Create a Sanctuary effect.
        //  - nDifficultyClass: must be a non-zero, positive number
        //  * Returns an effect of type EFFECT_TYPE_INVALIDEFFECT if nDifficultyClass <= 0.
        public static NWN.Effect EffectSanctuary(int nDifficultyClass)
        {
            NWN.Internal.StackPushInteger(nDifficultyClass);
            NWN.Internal.CallBuiltIn(464);
            return NWN.Internal.StackPopEffect();
        }

        //  Create a True Seeing effect.
        public static NWN.Effect EffectTrueSeeing()
        {
            NWN.Internal.CallBuiltIn(465);
            return NWN.Internal.StackPopEffect();
        }

        //  Create a See Invisible effect.
        public static NWN.Effect EffectSeeInvisible()
        {
            NWN.Internal.CallBuiltIn(466);
            return NWN.Internal.StackPopEffect();
        }

        //  Create a Time Stop effect.
        public static NWN.Effect EffectTimeStop()
        {
            NWN.Internal.CallBuiltIn(467);
            return NWN.Internal.StackPopEffect();
        }

        //  Create a Blindness effect.
        public static NWN.Effect EffectBlindness()
        {
            NWN.Internal.CallBuiltIn(468);
            return NWN.Internal.StackPopEffect();
        }

        //  Determine whether oSource has a friendly reaction towards oTarget, depending
        //  on the reputation, PVP setting and (if both oSource and oTarget are PCs),
        //  oSource's Like/Dislike setting for oTarget.
        //  Note: If you just want to know how two objects feel about each other in terms
        //  of faction and personal reputation, use GetIsFriend() instead.
        //  * Returns TRUE if oSource has a friendly reaction towards oTarget
        public static int GetIsReactionTypeFriendly(NWN.Object oTarget, NWN.Object oSource = null)
        {
            NWN.Internal.StackPushObject(oSource, false);
            NWN.Internal.StackPushObject(oTarget, false);
            NWN.Internal.CallBuiltIn(469);
            return NWN.Internal.StackPopInteger();
        }

        //  Determine whether oSource has a neutral reaction towards oTarget, depending
        //  on the reputation, PVP setting and (if both oSource and oTarget are PCs),
        //  oSource's Like/Dislike setting for oTarget.
        //  Note: If you just want to know how two objects feel about each other in terms
        //  of faction and personal reputation, use GetIsNeutral() instead.
        //  * Returns TRUE if oSource has a neutral reaction towards oTarget
        public static int GetIsReactionTypeNeutral(NWN.Object oTarget, NWN.Object oSource = null)
        {
            NWN.Internal.StackPushObject(oSource, false);
            NWN.Internal.StackPushObject(oTarget, false);
            NWN.Internal.CallBuiltIn(470);
            return NWN.Internal.StackPopInteger();
        }

        //  Determine whether oSource has a Hostile reaction towards oTarget, depending
        //  on the reputation, PVP setting and (if both oSource and oTarget are PCs),
        //  oSource's Like/Dislike setting for oTarget.
        //  Note: If you just want to know how two objects feel about each other in terms
        //  of faction and personal reputation, use GetIsEnemy() instead.
        //  * Returns TRUE if oSource has a hostile reaction towards oTarget
        public static int GetIsReactionTypeHostile(NWN.Object oTarget, NWN.Object oSource = null)
        {
            NWN.Internal.StackPushObject(oSource, false);
            NWN.Internal.StackPushObject(oTarget, false);
            NWN.Internal.CallBuiltIn(471);
            return NWN.Internal.StackPopInteger();
        }

        //  Create a Spell Level Absorption effect.
        //  - nMaxSpellLevelAbsorbed: maximum spell level that will be absorbed by the
        //    effect
        //  - nTotalSpellLevelsAbsorbed: maximum number of spell levels that will be
        //    absorbed by the effect
        //  - nSpellSchool: SPELL_SCHOOL_*
        //  * Returns an effect of type EFFECT_TYPE_INVALIDEFFECT if:
        //    nMaxSpellLevelAbsorbed is not between -1 and 9 inclusive, or nSpellSchool
        //    is invalid.
        public static NWN.Effect EffectSpellLevelAbsorption(int nMaxSpellLevelAbsorbed, int nTotalSpellLevelsAbsorbed = 0, int nSpellSchool = SPELL_SCHOOL_GENERAL)
        {
            NWN.Internal.StackPushInteger(nSpellSchool);
            NWN.Internal.StackPushInteger(nTotalSpellLevelsAbsorbed);
            NWN.Internal.StackPushInteger(nMaxSpellLevelAbsorbed);
            NWN.Internal.CallBuiltIn(472);
            return NWN.Internal.StackPopEffect();
        }

        //  Create a Dispel Magic Best effect.
        //  If no parameter is specified, USE_CREATURE_LEVEL will be used. This will
        //  cause the dispel effect to use the level of the creature that created the
        //  effect.
        public static NWN.Effect EffectDispelMagicBest(int nCasterLevel = USE_CREATURE_LEVEL)
        {
            NWN.Internal.StackPushInteger(nCasterLevel);
            NWN.Internal.CallBuiltIn(473);
            return NWN.Internal.StackPopEffect();
        }

        //  Try to send oTarget to a new server defined by sIPaddress.
        //  - oTarget
        //  - sIPaddress: this can be numerical "192.168.0.84" or alphanumeric
        //    "www.bioware.com". It can also contain a port "192.168.0.84:5121" or
        //    "www.bioware.com:5121"; if the port is not specified, it will default to
        //    5121.
        //  - sPassword: login password for the destination server
        //  - sWaypointTag: if this is set, after portalling the character will be moved
        //    to this waypoint if it exists
        //  - bSeamless: if this is set, the client wil not be prompted with the
        //    information window telling them about the server, and they will not be
        //    allowed to save a copy of their character if they are using a local vault
        //    character.
        public static void ActivatePortal(NWN.Object oTarget, string sIPaddress = "", string sPassword = "", string sWaypointTag = "", int bSeemless = FALSE)
        {
            NWN.Internal.StackPushInteger(bSeemless);
            NWN.Internal.StackPushString(sWaypointTag);
            NWN.Internal.StackPushString(sPassword);
            NWN.Internal.StackPushString(sIPaddress);
            NWN.Internal.StackPushObject(oTarget, false);
            NWN.Internal.CallBuiltIn(474);
        }

        //  Get the number of stacked items that oItem comprises.
        public static int GetNumStackedItems(NWN.Object oItem)
        {
            NWN.Internal.StackPushObject(oItem, false);
            NWN.Internal.CallBuiltIn(475);
            return NWN.Internal.StackPopInteger();
        }

        //  Use this on an NPC to cause all creatures within a 10-metre radius to stop
        //  what they are doing and sets the NPC's enemies within this range to be
        //  neutral towards the NPC for roughly 3 minutes. If this command is run on a PC
        //  or an object that is not a creature, nothing will happen.
        public static void SurrenderToEnemies()
        {
            NWN.Internal.CallBuiltIn(476);
        }

        //  Create a Miss Chance effect.
        //  - nPercentage: 1-100 inclusive
        //  - nMissChanceType: MISS_CHANCE_TYPE_*
        //  * Returns an effect of type EFFECT_TYPE_INVALIDEFFECT if nPercentage < 1 or
        //    nPercentage > 100.
        public static NWN.Effect EffectMissChance(int nPercentage, int nMissChanceType = MISS_CHANCE_TYPE_NORMAL)
        {
            NWN.Internal.StackPushInteger(nMissChanceType);
            NWN.Internal.StackPushInteger(nPercentage);
            NWN.Internal.CallBuiltIn(477);
            return NWN.Internal.StackPopEffect();
        }

        //  Get the number of Hitdice worth of Turn Resistance that oUndead may have.
        //  This will only work on undead creatures.
        public static int GetTurnResistanceHD(NWN.Object oUndead = null)
        {
            NWN.Internal.StackPushObject(oUndead, false);
            NWN.Internal.CallBuiltIn(478);
            return NWN.Internal.StackPopInteger();
        }

        //  Get the size (CREATURE_SIZE_*) of oCreature.
        public static int GetCreatureSize(NWN.Object oCreature)
        {
            NWN.Internal.StackPushObject(oCreature, false);
            NWN.Internal.CallBuiltIn(479);
            return NWN.Internal.StackPopInteger();
        }

        //  Create a Disappear/Appear effect.
        //  The object will "fly away" for the duration of the effect and will reappear
        //  at lLocation.
        //  - nAnimation determines which appear and disappear animations to use. Most creatures
        //  only have animation 1, although a few have 2 (like beholders)
        public static NWN.Effect EffectDisappearAppear(NWN.Location lLocation, int nAnimation = 1)
        {
            NWN.Internal.StackPushInteger(nAnimation);
            NWN.Internal.StackPushLocation(lLocation);
            NWN.Internal.CallBuiltIn(480);
            return NWN.Internal.StackPopEffect();
        }

        //  Create a Disappear effect to make the object "fly away" and then destroy
        //  itself.
        //  - nAnimation determines which appear and disappear animations to use. Most creatures
        //  only have animation 1, although a few have 2 (like beholders)
        public static NWN.Effect EffectDisappear(int nAnimation = 1)
        {
            NWN.Internal.StackPushInteger(nAnimation);
            NWN.Internal.CallBuiltIn(481);
            return NWN.Internal.StackPopEffect();
        }

        //  Create an Appear effect to make the object "fly in".
        //  - nAnimation determines which appear and disappear animations to use. Most creatures
        //  only have animation 1, although a few have 2 (like beholders)
        public static NWN.Effect EffectAppear(int nAnimation = 1)
        {
            NWN.Internal.StackPushInteger(nAnimation);
            NWN.Internal.CallBuiltIn(482);
            return NWN.Internal.StackPopEffect();
        }

        //  The action subject will unlock oTarget, which can be a door or a placeable
        //  object.
        public static void ActionUnlockObject(NWN.Object oTarget)
        {
            NWN.Internal.StackPushObject(oTarget, false);
            NWN.Internal.CallBuiltIn(483);
        }

        //  The action subject will lock oTarget, which can be a door or a placeable
        //  object.
        public static void ActionLockObject(NWN.Object oTarget)
        {
            NWN.Internal.StackPushObject(oTarget, false);
            NWN.Internal.CallBuiltIn(484);
        }

        //  Create a Modify Attacks effect to add attacks.
        //  - nAttacks: maximum is 5, even with the effect stacked
        //  * Returns an effect of type EFFECT_TYPE_INVALIDEFFECT if nAttacks > 5.
        public static NWN.Effect EffectModifyAttacks(int nAttacks)
        {
            NWN.Internal.StackPushInteger(nAttacks);
            NWN.Internal.CallBuiltIn(485);
            return NWN.Internal.StackPopEffect();
        }

        //  Get the last trap detected by oTarget.
        //  * Return value on error: OBJECT_INVALID
        public static NWN.Object GetLastTrapDetected(NWN.Object oTarget = null)
        {
            NWN.Internal.StackPushObject(oTarget, false);
            NWN.Internal.CallBuiltIn(486);
            return NWN.Internal.StackPopObject();
        }

        //  Create a Damage Shield effect which does (nDamageAmount + nRandomAmount)
        //  damage to any melee attacker on a successful attack of damage type nDamageType.
        //  - nDamageAmount: an integer value
        //  - nRandomAmount: DAMAGE_BONUS_*
        //  - nDamageType: DAMAGE_TYPE_*
        //  NOTE! You *must* use the DAMAGE_BONUS_* constants! Using other values may
        //        result in odd behaviour.
        public static NWN.Effect EffectDamageShield(int nDamageAmount, int nRandomAmount, int nDamageType)
        {
            NWN.Internal.StackPushInteger(nDamageType);
            NWN.Internal.StackPushInteger(nRandomAmount);
            NWN.Internal.StackPushInteger(nDamageAmount);
            NWN.Internal.CallBuiltIn(487);
            return NWN.Internal.StackPopEffect();
        }

        //  Get the trap nearest to oTarget.
        //  Note : "trap objects" are actually any trigger, placeable or door that is
        //  trapped in oTarget's area.
        //  - oTarget
        //  - nTrapDetected: if this is TRUE, the trap returned has to have been detected
        //    by oTarget.
        public static NWN.Object GetNearestTrapToObject(NWN.Object oTarget = null, int nTrapDetected = TRUE)
        {
            NWN.Internal.StackPushInteger(nTrapDetected);
            NWN.Internal.StackPushObject(oTarget, false);
            NWN.Internal.CallBuiltIn(488);
            return NWN.Internal.StackPopObject();
        }

        //  Get the name of oCreature's deity.
        //  * Returns "" if oCreature is invalid (or if the deity name is blank for
        //    oCreature).
        public static string GetDeity(NWN.Object oCreature)
        {
            NWN.Internal.StackPushObject(oCreature, false);
            NWN.Internal.CallBuiltIn(489);
            return NWN.Internal.StackPopString();
        }

        //  Get the name of oCreature's sub race.
        //  * Returns "" if oCreature is invalid (or if sub race is blank for oCreature).
        public static string GetSubRace(NWN.Object oTarget)
        {
            NWN.Internal.StackPushObject(oTarget, false);
            NWN.Internal.CallBuiltIn(490);
            return NWN.Internal.StackPopString();
        }

        //  Get oTarget's base fortitude saving throw value (this will only work for
        //  creatures, doors, and placeables).
        //  * Returns 0 if oTarget is invalid.
        public static int GetFortitudeSavingThrow(NWN.Object oTarget)
        {
            NWN.Internal.StackPushObject(oTarget, false);
            NWN.Internal.CallBuiltIn(491);
            return NWN.Internal.StackPopInteger();
        }

        //  Get oTarget's base will saving throw value (this will only work for creatures,
        //  doors, and placeables).
        //  * Returns 0 if oTarget is invalid.
        public static int GetWillSavingThrow(NWN.Object oTarget)
        {
            NWN.Internal.StackPushObject(oTarget, false);
            NWN.Internal.CallBuiltIn(492);
            return NWN.Internal.StackPopInteger();
        }

        //  Get oTarget's base reflex saving throw value (this will only work for
        //  creatures, doors, and placeables).
        //  * Returns 0 if oTarget is invalid.
        public static int GetReflexSavingThrow(NWN.Object oTarget)
        {
            NWN.Internal.StackPushObject(oTarget, false);
            NWN.Internal.CallBuiltIn(493);
            return NWN.Internal.StackPopInteger();
        }

        //  Get oCreature's challenge rating.
        //  * Returns 0.0 if oCreature is invalid.
        public static float GetChallengeRating(NWN.Object oCreature)
        {
            NWN.Internal.StackPushObject(oCreature, false);
            NWN.Internal.CallBuiltIn(494);
            return NWN.Internal.StackPopFloat();
        }

        //  Get oCreature's age.
        //  * Returns 0 if oCreature is invalid.
        public static int GetAge(NWN.Object oCreature)
        {
            NWN.Internal.StackPushObject(oCreature, false);
            NWN.Internal.CallBuiltIn(495);
            return NWN.Internal.StackPopInteger();
        }

        //  Get oCreature's movement rate.
        //  * Returns 0 if oCreature is invalid.
        public static int GetMovementRate(NWN.Object oCreature)
        {
            NWN.Internal.StackPushObject(oCreature, false);
            NWN.Internal.CallBuiltIn(496);
            return NWN.Internal.StackPopInteger();
        }

        //  Get oCreature's familiar creature type (FAMILIAR_CREATURE_TYPE_*).
        //  * Returns FAMILIAR_CREATURE_TYPE_NONE if oCreature is invalid or does not
        //    currently have a familiar.
        public static int GetFamiliarCreatureType(NWN.Object oCreature)
        {
            NWN.Internal.StackPushObject(oCreature, false);
            NWN.Internal.CallBuiltIn(497);
            return NWN.Internal.StackPopInteger();
        }

        //  Get oCreature's animal companion creature type
        //  (ANIMAL_COMPANION_CREATURE_TYPE_*).
        //  * Returns ANIMAL_COMPANION_CREATURE_TYPE_NONE if oCreature is invalid or does
        //    not currently have an animal companion.
        public static int GetAnimalCompanionCreatureType(NWN.Object oCreature)
        {
            NWN.Internal.StackPushObject(oCreature, false);
            NWN.Internal.CallBuiltIn(498);
            return NWN.Internal.StackPopInteger();
        }

        //  Get oCreature's familiar's name.
        //  * Returns "" if oCreature is invalid, does not currently
        //  have a familiar or if the familiar's name is blank.
        public static string GetFamiliarName(NWN.Object oCreature)
        {
            NWN.Internal.StackPushObject(oCreature, false);
            NWN.Internal.CallBuiltIn(499);
            return NWN.Internal.StackPopString();
        }

        //  Get oCreature's animal companion's name.
        //  * Returns "" if oCreature is invalid, does not currently
        //  have an animal companion or if the animal companion's name is blank.
        public static string GetAnimalCompanionName(NWN.Object oTarget)
        {
            NWN.Internal.StackPushObject(oTarget, false);
            NWN.Internal.CallBuiltIn(500);
            return NWN.Internal.StackPopString();
        }

        //  The action subject will fake casting a spell at oTarget; the conjure and cast
        //  animations and visuals will occur, nothing else.
        //  - nSpell
        //  - oTarget
        //  - nProjectilePathType: PROJECTILE_PATH_TYPE_*
        public static void ActionCastFakeSpellAtObject(int nSpell, NWN.Object oTarget, int nProjectilePathType = PROJECTILE_PATH_TYPE_DEFAULT)
        {
            NWN.Internal.StackPushInteger(nProjectilePathType);
            NWN.Internal.StackPushObject(oTarget, false);
            NWN.Internal.StackPushInteger(nSpell);
            NWN.Internal.CallBuiltIn(501);
        }

        //  The action subject will fake casting a spell at lLocation; the conjure and
        //  cast animations and visuals will occur, nothing else.
        //  - nSpell
        //  - lTarget
        //  - nProjectilePathType: PROJECTILE_PATH_TYPE_*
        public static void ActionCastFakeSpellAtLocation(int nSpell, NWN.Location lTarget, int nProjectilePathType = PROJECTILE_PATH_TYPE_DEFAULT)
        {
            NWN.Internal.StackPushInteger(nProjectilePathType);
            NWN.Internal.StackPushLocation(lTarget);
            NWN.Internal.StackPushInteger(nSpell);
            NWN.Internal.CallBuiltIn(502);
        }

        //  Removes oAssociate from the service of oMaster, returning them to their
        //  original faction.
        public static void RemoveSummonedAssociate(NWN.Object oMaster, NWN.Object oAssociate = null)
        {
            NWN.Internal.StackPushObject(oAssociate, false);
            NWN.Internal.StackPushObject(oMaster, false);
            NWN.Internal.CallBuiltIn(503);
        }

        //  Set the camera mode for oPlayer.
        //  - oPlayer
        //  - nCameraMode: CAMERA_MODE_*
        //  * If oPlayer is not player-controlled or nCameraMode is invalid, nothing
        //    happens.
        public static void SetCameraMode(NWN.Object oPlayer, int nCameraMode)
        {
            NWN.Internal.StackPushInteger(nCameraMode);
            NWN.Internal.StackPushObject(oPlayer, false);
            NWN.Internal.CallBuiltIn(504);
        }

        //  * Returns TRUE if oCreature is resting.
        public static int GetIsResting(NWN.Object oCreature = null)
        {
            NWN.Internal.StackPushObject(oCreature, false);
            NWN.Internal.CallBuiltIn(505);
            return NWN.Internal.StackPopInteger();
        }

        //  Get the last PC that has rested in the module.
        public static NWN.Object GetLastPCRested()
        {
            NWN.Internal.CallBuiltIn(506);
            return NWN.Internal.StackPopObject();
        }

        //  Set the weather for oTarget.
        //  - oTarget: if this is GetModule(), all outdoor areas will be modified by the
        //    weather constant. If it is an area, oTarget will play the weather only if
        //    it is an outdoor area.
        //  - nWeather: WEATHER_*
        //    -> WEATHER_USER_AREA_SETTINGS will set the area back to random weather.
        //    -> WEATHER_CLEAR, WEATHER_RAIN, WEATHER_SNOW will make the weather go to
        //       the appropriate precipitation *without stopping*.
        public static void SetWeather(NWN.Object oTarget, int nWeather)
        {
            NWN.Internal.StackPushInteger(nWeather);
            NWN.Internal.StackPushObject(oTarget, false);
            NWN.Internal.CallBuiltIn(507);
        }

        //  Determine the type (REST_EVENTTYPE_REST_*) of the last rest event (as
        //  returned from the OnPCRested module event).
        public static int GetLastRestEventType()
        {
            NWN.Internal.CallBuiltIn(508);
            return NWN.Internal.StackPopInteger();
        }

        //  Shut down the currently loaded module and start a new one (moving all
        //  currently-connected players to the starting point.
        public static void StartNewModule(string sModuleName)
        {
            NWN.Internal.StackPushString(sModuleName);
            NWN.Internal.CallBuiltIn(509);
        }

        //  Create a Swarm effect.
        //  - nLooping: If this is TRUE, for the duration of the effect when one creature
        //    created by this effect dies, the next one in the list will be created.  If
        //    the last creature in the list dies, we loop back to the beginning and
        //    sCreatureTemplate1 will be created, and so on...
        //  - sCreatureTemplate1
        //  - sCreatureTemplate2
        //  - sCreatureTemplate3
        //  - sCreatureTemplate4
        public static NWN.Effect EffectSwarm(int nLooping, string sCreatureTemplate1, string sCreatureTemplate2 = "", string sCreatureTemplate3 = "", string sCreatureTemplate4 = "")
        {
            NWN.Internal.StackPushString(sCreatureTemplate4);
            NWN.Internal.StackPushString(sCreatureTemplate3);
            NWN.Internal.StackPushString(sCreatureTemplate2);
            NWN.Internal.StackPushString(sCreatureTemplate1);
            NWN.Internal.StackPushInteger(nLooping);
            NWN.Internal.CallBuiltIn(510);
            return NWN.Internal.StackPopEffect();
        }

        //  * Returns TRUE if oItem is a ranged weapon.
        public static int GetWeaponRanged(NWN.Object oItem)
        {
            NWN.Internal.StackPushObject(oItem, false);
            NWN.Internal.CallBuiltIn(511);
            return NWN.Internal.StackPopInteger();
        }

        //  Only if we are in a single player game, AutoSave the game.
        public static void DoSinglePlayerAutoSave()
        {
            NWN.Internal.CallBuiltIn(512);
        }

        //  Get the game difficulty (GAME_DIFFICULTY_*).
        public static int GetGameDifficulty()
        {
            NWN.Internal.CallBuiltIn(513);
            return NWN.Internal.StackPopInteger();
        }

        //  Set the main light color on the tile at lTileLocation.
        //  - lTileLocation: the vector part of this is the tile grid (x,y) coordinate of
        //    the tile.
        //  - nMainLight1Color: TILE_MAIN_LIGHT_COLOR_*
        //  - nMainLight2Color: TILE_MAIN_LIGHT_COLOR_*
        public static void SetTileMainLightColor(NWN.Location lTileLocation, int nMainLight1Color, int nMainLight2Color)
        {
            NWN.Internal.StackPushInteger(nMainLight2Color);
            NWN.Internal.StackPushInteger(nMainLight1Color);
            NWN.Internal.StackPushLocation(lTileLocation);
            NWN.Internal.CallBuiltIn(514);
        }

        //  Set the source light color on the tile at lTileLocation.
        //  - lTileLocation: the vector part of this is the tile grid (x,y) coordinate of
        //    the tile.
        //  - nSourceLight1Color: TILE_SOURCE_LIGHT_COLOR_*
        //  - nSourceLight2Color: TILE_SOURCE_LIGHT_COLOR_*
        public static void SetTileSourceLightColor(NWN.Location lTileLocation, int nSourceLight1Color, int nSourceLight2Color)
        {
            NWN.Internal.StackPushInteger(nSourceLight2Color);
            NWN.Internal.StackPushInteger(nSourceLight1Color);
            NWN.Internal.StackPushLocation(lTileLocation);
            NWN.Internal.CallBuiltIn(515);
        }

        //  All clients in oArea will recompute the static lighting.
        //  This can be used to update the lighting after changing any tile lights or if
        //  placeables with lights have been added/deleted.
        public static void RecomputeStaticLighting(NWN.Object oArea)
        {
            NWN.Internal.StackPushObject(oArea, false);
            NWN.Internal.CallBuiltIn(516);
        }

        //  Get the color (TILE_MAIN_LIGHT_COLOR_*) for the main light 1 of the tile at
        //  lTile.
        //  - lTile: the vector part of this is the tile grid (x,y) coordinate of the tile.
        public static int GetTileMainLight1Color(NWN.Location lTile)
        {
            NWN.Internal.StackPushLocation(lTile);
            NWN.Internal.CallBuiltIn(517);
            return NWN.Internal.StackPopInteger();
        }

        //  Get the color (TILE_MAIN_LIGHT_COLOR_*) for the main light 2 of the tile at
        //  lTile.
        //  - lTile: the vector part of this is the tile grid (x,y) coordinate of the
        //    tile.
        public static int GetTileMainLight2Color(NWN.Location lTile)
        {
            NWN.Internal.StackPushLocation(lTile);
            NWN.Internal.CallBuiltIn(518);
            return NWN.Internal.StackPopInteger();
        }

        //  Get the color (TILE_SOURCE_LIGHT_COLOR_*) for the source light 1 of the tile
        //  at lTile.
        //  - lTile: the vector part of this is the tile grid (x,y) coordinate of the
        //    tile.
        public static int GetTileSourceLight1Color(NWN.Location lTile)
        {
            NWN.Internal.StackPushLocation(lTile);
            NWN.Internal.CallBuiltIn(519);
            return NWN.Internal.StackPopInteger();
        }

        //  Get the color (TILE_SOURCE_LIGHT_COLOR_*) for the source light 2 of the tile
        //  at lTile.
        //  - lTile: the vector part of this is the tile grid (x,y) coordinate of the
        //    tile.
        public static int GetTileSourceLight2Color(NWN.Location lTile)
        {
            NWN.Internal.StackPushLocation(lTile);
            NWN.Internal.CallBuiltIn(520);
            return NWN.Internal.StackPopInteger();
        }

        //  Make the corresponding panel button on the player's client start or stop
        //  flashing.
        //  - oPlayer
        //  - nButton: PANEL_BUTTON_*
        //  - nEnableFlash: if this is TRUE nButton will start flashing.  It if is FALSE,
        //    nButton will stop flashing.
        public static void SetPanelButtonFlash(NWN.Object oPlayer, int nButton, int nEnableFlash)
        {
            NWN.Internal.StackPushInteger(nEnableFlash);
            NWN.Internal.StackPushInteger(nButton);
            NWN.Internal.StackPushObject(oPlayer, false);
            NWN.Internal.CallBuiltIn(521);
        }

        //  Get the current action (ACTION_*) that oObject is executing.
        public static int GetCurrentAction(NWN.Object oObject = null)
        {
            NWN.Internal.StackPushObject(oObject, false);
            NWN.Internal.CallBuiltIn(522);
            return NWN.Internal.StackPopInteger();
        }

        //  Set how nStandardFaction feels about oCreature.
        //  - nStandardFaction: STANDARD_FACTION_*
        //  - nNewReputation: 0-100 (inclusive)
        //  - oCreature
        public static void SetStandardFactionReputation(int nStandardFaction, int nNewReputation, NWN.Object oCreature = null)
        {
            NWN.Internal.StackPushObject(oCreature, false);
            NWN.Internal.StackPushInteger(nNewReputation);
            NWN.Internal.StackPushInteger(nStandardFaction);
            NWN.Internal.CallBuiltIn(523);
        }

        //  Find out how nStandardFaction feels about oCreature.
        //  - nStandardFaction: STANDARD_FACTION_*
        //  - oCreature
        //  Returns -1 on an error.
        //  Returns 0-100 based on the standing of oCreature within the faction nStandardFaction.
        //  0-10   :  Hostile.
        //  11-89  :  Neutral.
        //  90-100 :  Friendly.
        public static int GetStandardFactionReputation(int nStandardFaction, NWN.Object oCreature = null)
        {
            NWN.Internal.StackPushObject(oCreature, false);
            NWN.Internal.StackPushInteger(nStandardFaction);
            NWN.Internal.CallBuiltIn(524);
            return NWN.Internal.StackPopInteger();
        }

        //  Display floaty text above the specified creature.
        //  The text will also appear in the chat buffer of each player that receives the
        //  floaty text.
        //  - nStrRefToDisplay: String ref (therefore text is translated)
        //  - oCreatureToFloatAbove
        //  - bBroadcastToFaction: If this is TRUE then only creatures in the same faction
        //    as oCreatureToFloatAbove
        //    will see the floaty text, and only if they are within range (30 metres).
        public static void FloatingTextStrRefOnCreature(int nStrRefToDisplay, NWN.Object oCreatureToFloatAbove, int bBroadcastToFaction = TRUE)
        {
            NWN.Internal.StackPushInteger(bBroadcastToFaction);
            NWN.Internal.StackPushObject(oCreatureToFloatAbove, false);
            NWN.Internal.StackPushInteger(nStrRefToDisplay);
            NWN.Internal.CallBuiltIn(525);
        }

        //  Display floaty text above the specified creature.
        //  The text will also appear in the chat buffer of each player that receives the
        //  floaty text.
        //  - sStringToDisplay: String
        //  - oCreatureToFloatAbove
        //  - bBroadcastToFaction: If this is TRUE then only creatures in the same faction
        //    as oCreatureToFloatAbove
        //    will see the floaty text, and only if they are within range (30 metres).
        public static void FloatingTextStringOnCreature(string sStringToDisplay, NWN.Object oCreatureToFloatAbove, int bBroadcastToFaction = TRUE)
        {
            NWN.Internal.StackPushInteger(bBroadcastToFaction);
            NWN.Internal.StackPushObject(oCreatureToFloatAbove, false);
            NWN.Internal.StackPushString(sStringToDisplay);
            NWN.Internal.CallBuiltIn(526);
        }

        //  - oTrapObject: a placeable, door or trigger
        //  * Returns TRUE if oTrapObject is disarmable.
        public static int GetTrapDisarmable(NWN.Object oTrapObject)
        {
            NWN.Internal.StackPushObject(oTrapObject, false);
            NWN.Internal.CallBuiltIn(527);
            return NWN.Internal.StackPopInteger();
        }

        //  - oTrapObject: a placeable, door or trigger
        //  * Returns TRUE if oTrapObject is detectable.
        public static int GetTrapDetectable(NWN.Object oTrapObject)
        {
            NWN.Internal.StackPushObject(oTrapObject, false);
            NWN.Internal.CallBuiltIn(528);
            return NWN.Internal.StackPopInteger();
        }

        //  - oTrapObject: a placeable, door or trigger
        //  - oCreature
        //  * Returns TRUE if oCreature has detected oTrapObject
        public static int GetTrapDetectedBy(NWN.Object oTrapObject, NWN.Object oCreature)
        {
            NWN.Internal.StackPushObject(oCreature, false);
            NWN.Internal.StackPushObject(oTrapObject, false);
            NWN.Internal.CallBuiltIn(529);
            return NWN.Internal.StackPopInteger();
        }

        //  - oTrapObject: a placeable, door or trigger
        //  * Returns TRUE if oTrapObject has been flagged as visible to all creatures.
        public static int GetTrapFlagged(NWN.Object oTrapObject)
        {
            NWN.Internal.StackPushObject(oTrapObject, false);
            NWN.Internal.CallBuiltIn(530);
            return NWN.Internal.StackPopInteger();
        }

        //  Get the trap base type (TRAP_BASE_TYPE_*) of oTrapObject.
        //  - oTrapObject: a placeable, door or trigger
        public static int GetTrapBaseType(NWN.Object oTrapObject)
        {
            NWN.Internal.StackPushObject(oTrapObject, false);
            NWN.Internal.CallBuiltIn(531);
            return NWN.Internal.StackPopInteger();
        }

        //  - oTrapObject: a placeable, door or trigger
        //  * Returns TRUE if oTrapObject is one-shot (i.e. it does not reset itself
        //    after firing.
        public static int GetTrapOneShot(NWN.Object oTrapObject)
        {
            NWN.Internal.StackPushObject(oTrapObject, false);
            NWN.Internal.CallBuiltIn(532);
            return NWN.Internal.StackPopInteger();
        }

        //  Get the creator of oTrapObject, the creature that set the trap.
        //  - oTrapObject: a placeable, door or trigger
        //  * Returns OBJECT_INVALID if oTrapObject was created in the toolset.
        public static NWN.Object GetTrapCreator(NWN.Object oTrapObject)
        {
            NWN.Internal.StackPushObject(oTrapObject, false);
            NWN.Internal.CallBuiltIn(533);
            return NWN.Internal.StackPopObject();
        }

        //  Get the tag of the key that will disarm oTrapObject.
        //  - oTrapObject: a placeable, door or trigger
        public static string GetTrapKeyTag(NWN.Object oTrapObject)
        {
            NWN.Internal.StackPushObject(oTrapObject, false);
            NWN.Internal.CallBuiltIn(534);
            return NWN.Internal.StackPopString();
        }

        //  Get the DC for disarming oTrapObject.
        //  - oTrapObject: a placeable, door or trigger
        public static int GetTrapDisarmDC(NWN.Object oTrapObject)
        {
            NWN.Internal.StackPushObject(oTrapObject, false);
            NWN.Internal.CallBuiltIn(535);
            return NWN.Internal.StackPopInteger();
        }

        //  Get the DC for detecting oTrapObject.
        //  - oTrapObject: a placeable, door or trigger
        public static int GetTrapDetectDC(NWN.Object oTrapObject)
        {
            NWN.Internal.StackPushObject(oTrapObject, false);
            NWN.Internal.CallBuiltIn(536);
            return NWN.Internal.StackPopInteger();
        }

        //  * Returns TRUE if a specific key is required to open the lock on oObject.
        public static int GetLockKeyRequired(NWN.Object oObject)
        {
            NWN.Internal.StackPushObject(oObject, false);
            NWN.Internal.CallBuiltIn(537);
            return NWN.Internal.StackPopInteger();
        }

        //  Get the tag of the key that will open the lock on oObject.
        public static string GetLockKeyTag(NWN.Object oObject)
        {
            NWN.Internal.StackPushObject(oObject, false);
            NWN.Internal.CallBuiltIn(538);
            return NWN.Internal.StackPopString();
        }

        //  * Returns TRUE if the lock on oObject is lockable.
        public static int GetLockLockable(NWN.Object oObject)
        {
            NWN.Internal.StackPushObject(oObject, false);
            NWN.Internal.CallBuiltIn(539);
            return NWN.Internal.StackPopInteger();
        }

        //  Get the DC for unlocking oObject.
        public static int GetLockUnlockDC(NWN.Object oObject)
        {
            NWN.Internal.StackPushObject(oObject, false);
            NWN.Internal.CallBuiltIn(540);
            return NWN.Internal.StackPopInteger();
        }

        //  Get the DC for locking oObject.
        public static int GetLockLockDC(NWN.Object oObject)
        {
            NWN.Internal.StackPushObject(oObject, false);
            NWN.Internal.CallBuiltIn(541);
            return NWN.Internal.StackPopInteger();
        }

        //  Get the last PC that levelled up.
        public static NWN.Object GetPCLevellingUp()
        {
            NWN.Internal.CallBuiltIn(542);
            return NWN.Internal.StackPopObject();
        }

        //  - nFeat: FEAT_*
        //  - oObject
        //  * Returns TRUE if oObject has effects on it originating from nFeat.
        public static int GetHasFeatEffect(int nFeat, NWN.Object oObject = null)
        {
            NWN.Internal.StackPushObject(oObject, false);
            NWN.Internal.StackPushInteger(nFeat);
            NWN.Internal.CallBuiltIn(543);
            return NWN.Internal.StackPopInteger();
        }

        //  Set the status of the illumination for oPlaceable.
        //  - oPlaceable
        //  - bIlluminate: if this is TRUE, oPlaceable's illumination will be turned on.
        //    If this is FALSE, oPlaceable's illumination will be turned off.
        //  Note: You must call RecomputeStaticLighting() after calling this function in
        //  order for the changes to occur visually for the players.
        //  SetPlaceableIllumination() buffers the illumination changes, which are then
        //  sent out to the players once RecomputeStaticLighting() is called.  As such,
        //  it is best to call SetPlaceableIllumination() for all the placeables you wish
        //  to set the illumination on, and then call RecomputeStaticLighting() once after
        //  all the placeable illumination has been set.
        //  * If oPlaceable is not a placeable object, or oPlaceable is a placeable that
        //    doesn't have a light, nothing will happen.
        public static void SetPlaceableIllumination(NWN.Object oPlaceable = null, int bIlluminate = TRUE)
        {
            NWN.Internal.StackPushInteger(bIlluminate);
            NWN.Internal.StackPushObject(oPlaceable, false);
            NWN.Internal.CallBuiltIn(544);
        }

        //  * Returns TRUE if the illumination for oPlaceable is on
        public static int GetPlaceableIllumination(NWN.Object oPlaceable = null)
        {
            NWN.Internal.StackPushObject(oPlaceable, false);
            NWN.Internal.CallBuiltIn(545);
            return NWN.Internal.StackPopInteger();
        }

        //  - oPlaceable
        //  - nPlaceableAction: PLACEABLE_ACTION_*
        //  * Returns TRUE if nPlacebleAction is valid for oPlaceable.
        public static int GetIsPlaceableObjectActionPossible(NWN.Object oPlaceable, int nPlaceableAction)
        {
            NWN.Internal.StackPushInteger(nPlaceableAction);
            NWN.Internal.StackPushObject(oPlaceable, false);
            NWN.Internal.CallBuiltIn(546);
            return NWN.Internal.StackPopInteger();
        }

        //  The caller performs nPlaceableAction on oPlaceable.
        //  - oPlaceable
        //  - nPlaceableAction: PLACEABLE_ACTION_*
        public static void DoPlaceableObjectAction(NWN.Object oPlaceable, int nPlaceableAction)
        {
            NWN.Internal.StackPushInteger(nPlaceableAction);
            NWN.Internal.StackPushObject(oPlaceable, false);
            NWN.Internal.CallBuiltIn(547);
        }

        //  Get the first PC in the player list.
        //  This resets the position in the player list for GetNextPC().
        public static NWN.Object GetFirstPC()
        {
            NWN.Internal.CallBuiltIn(548);
            return NWN.Internal.StackPopObject();
        }

        //  Get the next PC in the player list.
        //  This picks up where the last GetFirstPC() or GetNextPC() left off.
        public static NWN.Object GetNextPC()
        {
            NWN.Internal.CallBuiltIn(549);
            return NWN.Internal.StackPopObject();
        }

        //  Set whether or not the creature oDetector has detected the trapped object oTrap.
        //  - oTrap: A trapped trigger, placeable or door object.
        //  - oDetector: This is the creature that the detected status of the trap is being adjusted for.
        //  - bDetected: A Boolean that sets whether the trapped object has been detected or not.
        public static int SetTrapDetectedBy(NWN.Object oTrap, NWN.Object oDetector, int bDetected = TRUE)
        {
            NWN.Internal.StackPushInteger(bDetected);
            NWN.Internal.StackPushObject(oDetector, false);
            NWN.Internal.StackPushObject(oTrap, false);
            NWN.Internal.CallBuiltIn(550);
            return NWN.Internal.StackPopInteger();
        }

        //  Note: Only placeables, doors and triggers can be trapped.
        //  * Returns TRUE if oObject is trapped.
        public static int GetIsTrapped(NWN.Object oObject)
        {
            NWN.Internal.StackPushObject(oObject, false);
            NWN.Internal.CallBuiltIn(551);
            return NWN.Internal.StackPopInteger();
        }

        //  Create a Turn Resistance Decrease effect.
        //  - nHitDice: a positive number representing the number of hit dice for the
        // /  decrease
        public static NWN.Effect EffectTurnResistanceDecrease(int nHitDice)
        {
            NWN.Internal.StackPushInteger(nHitDice);
            NWN.Internal.CallBuiltIn(552);
            return NWN.Internal.StackPopEffect();
        }

        //  Create a Turn Resistance Increase effect.
        //  - nHitDice: a positive number representing the number of hit dice for the
        //    increase
        public static NWN.Effect EffectTurnResistanceIncrease(int nHitDice)
        {
            NWN.Internal.StackPushInteger(nHitDice);
            NWN.Internal.CallBuiltIn(553);
            return NWN.Internal.StackPopEffect();
        }

        //  Spawn in the Death GUI.
        //  The default (as defined by BioWare) can be spawned in by PopUpGUIPanel, but
        //  if you want to turn off the "Respawn" or "Wait for Help" buttons, this is the
        //  function to use.
        //  - oPC
        //  - bRespawnButtonEnabled: if this is TRUE, the "Respawn" button will be enabled
        //    on the Death GUI.
        //  - bWaitForHelpButtonEnabled: if this is TRUE, the "Wait For Help" button will
        //    be enabled on the Death GUI (Note: This button will not appear in single player games).
        //  - nHelpStringReference
        //  - sHelpString
        public static void PopUpDeathGUIPanel(NWN.Object oPC, int bRespawnButtonEnabled = TRUE, int bWaitForHelpButtonEnabled = TRUE, int nHelpStringReference = 0, string sHelpString = "")
        {
            NWN.Internal.StackPushString(sHelpString);
            NWN.Internal.StackPushInteger(nHelpStringReference);
            NWN.Internal.StackPushInteger(bWaitForHelpButtonEnabled);
            NWN.Internal.StackPushInteger(bRespawnButtonEnabled);
            NWN.Internal.StackPushObject(oPC, false);
            NWN.Internal.CallBuiltIn(554);
        }

        //  Disable oTrap.
        //  - oTrap: a placeable, door or trigger.
        public static void SetTrapDisabled(NWN.Object oTrap)
        {
            NWN.Internal.StackPushObject(oTrap, false);
            NWN.Internal.CallBuiltIn(555);
        }

        //  Get the last object that was sent as a GetLastAttacker(), GetLastDamager(),
        //  GetLastSpellCaster() (for a hostile spell), or GetLastDisturbed() (when a
        //  creature is pickpocketed).
        //  Note: Return values may only ever be:
        //  1) A Creature
        //  2) Plot Characters will never have this value set
        //  3) Area of Effect Objects will return the AOE creator if they are registered
        //     as this value, otherwise they will return INVALID_OBJECT_ID
        //  4) Traps will not return the creature that set the trap.
        //  5) This value will never be overwritten by another non-creature object.
        //  6) This value will never be a dead/destroyed creature
        public static NWN.Object GetLastHostileActor(NWN.Object oVictim = null)
        {
            NWN.Internal.StackPushObject(oVictim, false);
            NWN.Internal.CallBuiltIn(556);
            return NWN.Internal.StackPopObject();
        }

        //  Force all the characters of the players who are currently in the game to
        //  be exported to their respective directories i.e. LocalVault/ServerVault/ etc.
        public static void ExportAllCharacters()
        {
            NWN.Internal.CallBuiltIn(557);
        }

        //  Get the Day Track for oArea.
        public static int MusicBackgroundGetDayTrack(NWN.Object oArea)
        {
            NWN.Internal.StackPushObject(oArea, false);
            NWN.Internal.CallBuiltIn(558);
            return NWN.Internal.StackPopInteger();
        }

        //  Get the Night Track for oArea.
        public static int MusicBackgroundGetNightTrack(NWN.Object oArea)
        {
            NWN.Internal.StackPushObject(oArea, false);
            NWN.Internal.CallBuiltIn(559);
            return NWN.Internal.StackPopInteger();
        }

        //  Write sLogEntry as a timestamped entry into the log file
        public static void WriteTimestampedLogEntry(string sLogEntry)
        {
            NWN.Internal.StackPushString(sLogEntry);
            NWN.Internal.CallBuiltIn(560);
        }

        //  Get the module's name in the language of the server that's running it.
        //  * If there is no entry for the language of the server, it will return an
        //    empty string
        public static string GetModuleName()
        {
            NWN.Internal.CallBuiltIn(561);
            return NWN.Internal.StackPopString();
        }

        //  Get the player leader of the faction of which oMemberOfFaction is a member.
        //  * Returns OBJECT_INVALID if oMemberOfFaction is not a valid creature,
        //    or oMemberOfFaction is a member of a NPC faction.
        public static NWN.Object GetFactionLeader(NWN.Object oMemberOfFaction)
        {
            NWN.Internal.StackPushObject(oMemberOfFaction, false);
            NWN.Internal.CallBuiltIn(562);
            return NWN.Internal.StackPopObject();
        }

        //  Sends szMessage to all the Dungeon Masters currently on the server.
        public static void SendMessageToAllDMs(string szMessage)
        {
            NWN.Internal.StackPushString(szMessage);
            NWN.Internal.CallBuiltIn(563);
        }

        //  End the currently running game, play sEndMovie then return all players to the
        //  game's main menu.
        public static void EndGame(string sEndMovie)
        {
            NWN.Internal.StackPushString(sEndMovie);
            NWN.Internal.CallBuiltIn(564);
        }

        //  Remove oPlayer from the server.
        //  You can optionally specify a reason to override the text shown to the player.
        public static void BootPC(NWN.Object oPlayer, string sReason = "")
        {
            NWN.Internal.StackPushString(sReason);
            NWN.Internal.StackPushObject(oPlayer, false);
            NWN.Internal.CallBuiltIn(565);
        }

        //  Counterspell oCounterSpellTarget.
        public static void ActionCounterSpell(NWN.Object oCounterSpellTarget)
        {
            NWN.Internal.StackPushObject(oCounterSpellTarget, false);
            NWN.Internal.CallBuiltIn(566);
        }

        //  Set the ambient day volume for oArea to nVolume.
        //  - oArea
        //  - nVolume: 0 - 100
        public static void AmbientSoundSetDayVolume(NWN.Object oArea, int nVolume)
        {
            NWN.Internal.StackPushInteger(nVolume);
            NWN.Internal.StackPushObject(oArea, false);
            NWN.Internal.CallBuiltIn(567);
        }

        //  Set the ambient night volume for oArea to nVolume.
        //  - oArea
        //  - nVolume: 0 - 100
        public static void AmbientSoundSetNightVolume(NWN.Object oArea, int nVolume)
        {
            NWN.Internal.StackPushInteger(nVolume);
            NWN.Internal.StackPushObject(oArea, false);
            NWN.Internal.CallBuiltIn(568);
        }

        //  Get the Battle Track for oArea.
        public static int MusicBackgroundGetBattleTrack(NWN.Object oArea)
        {
            NWN.Internal.StackPushObject(oArea, false);
            NWN.Internal.CallBuiltIn(569);
            return NWN.Internal.StackPopInteger();
        }

        //  Determine whether oObject has an inventory.
        //  * Returns TRUE for creatures and stores, and checks to see if an item or placeable object is a container.
        //  * Returns FALSE for all other object types.
        public static int GetHasInventory(NWN.Object oObject)
        {
            NWN.Internal.StackPushObject(oObject, false);
            NWN.Internal.CallBuiltIn(570);
            return NWN.Internal.StackPopInteger();
        }

        //  Get the duration (in seconds) of the sound attached to nStrRef
        //  * Returns 0.0f if no duration is stored or if no sound is attached
        public static float GetStrRefSoundDuration(int nStrRef)
        {
            NWN.Internal.StackPushInteger(nStrRef);
            NWN.Internal.CallBuiltIn(571);
            return NWN.Internal.StackPopFloat();
        }

        //  Add oPC to oPartyLeader's party.  This will only work on two PCs.
        //  - oPC: player to add to a party
        //  - oPartyLeader: player already in the party
        public static void AddToParty(NWN.Object oPC, NWN.Object oPartyLeader)
        {
            NWN.Internal.StackPushObject(oPartyLeader, false);
            NWN.Internal.StackPushObject(oPC, false);
            NWN.Internal.CallBuiltIn(572);
        }

        //  Remove oPC from their current party. This will only work on a PC.
        //  - oPC: removes this player from whatever party they're currently in.
        public static void RemoveFromParty(NWN.Object oPC)
        {
            NWN.Internal.StackPushObject(oPC, false);
            NWN.Internal.CallBuiltIn(573);
        }

        //  Returns the stealth mode of the specified creature.
        //  - oCreature
        //  * Returns a constant STEALTH_MODE_*
        public static int GetStealthMode(NWN.Object oCreature)
        {
            NWN.Internal.StackPushObject(oCreature, false);
            NWN.Internal.CallBuiltIn(574);
            return NWN.Internal.StackPopInteger();
        }

        //  Returns the detection mode of the specified creature.
        //  - oCreature
        //  * Returns a constant DETECT_MODE_*
        public static int GetDetectMode(NWN.Object oCreature)
        {
            NWN.Internal.StackPushObject(oCreature, false);
            NWN.Internal.CallBuiltIn(575);
            return NWN.Internal.StackPopInteger();
        }

        //  Returns the defensive casting mode of the specified creature.
        //  - oCreature
        //  * Returns a constant DEFENSIVE_CASTING_MODE_*
        public static int GetDefensiveCastingMode(NWN.Object oCreature)
        {
            NWN.Internal.StackPushObject(oCreature, false);
            NWN.Internal.CallBuiltIn(576);
            return NWN.Internal.StackPopInteger();
        }

        //  returns the appearance type of the specified creature.
        //  * returns a constant APPEARANCE_TYPE_* for valid creatures
        //  * returns APPEARANCE_TYPE_INVALID for non creatures/invalid creatures
        public static int GetAppearanceType(NWN.Object oCreature)
        {
            NWN.Internal.StackPushObject(oCreature, false);
            NWN.Internal.CallBuiltIn(577);
            return NWN.Internal.StackPopInteger();
        }

        //  SpawnScriptDebugger() will cause the script debugger to be executed
        //  after this command is executed!  
        //  In order to compile the script for debugging go to Tools->Options->Script Editor
        //  and check the box labeled "Generate Debug Information When Compiling Scripts"
        //  After you have checked the above box, recompile the script that you want to debug.
        //  If the script file isn't compiled for debugging, this command will do nothing.
        //  Remove any SpawnScriptDebugger() calls once you have finished 
        //  debugging the script.
        public static void SpawnScriptDebugger()
        {
            NWN.Internal.CallBuiltIn(578);
        }

        //  in an onItemAcquired script, returns the size of the stack of the item
        //  that was just acquired.
        //  * returns the stack size of the item acquired
        public static int GetModuleItemAcquiredStackSize()
        {
            NWN.Internal.CallBuiltIn(579);
            return NWN.Internal.StackPopInteger();
        }

        //  Decrement the remaining uses per day for this creature by one.
        //  - oCreature: creature to modify
        //  - nFeat: constant FEAT_*
        public static void DecrementRemainingFeatUses(NWN.Object oCreature, int nFeat)
        {
            NWN.Internal.StackPushInteger(nFeat);
            NWN.Internal.StackPushObject(oCreature, false);
            NWN.Internal.CallBuiltIn(580);
        }

        //  Decrement the remaining uses per day for this creature by one.
        //  - oCreature: creature to modify
        //  - nSpell: constant SPELL_*
        public static void DecrementRemainingSpellUses(NWN.Object oCreature, int nSpell)
        {
            NWN.Internal.StackPushInteger(nSpell);
            NWN.Internal.StackPushObject(oCreature, false);
            NWN.Internal.CallBuiltIn(581);
        }

        //  returns the template used to create this object (if appropriate)
        //  * returns an empty string when no template found
        public static string GetResRef(NWN.Object oObject)
        {
            NWN.Internal.StackPushObject(oObject, false);
            NWN.Internal.CallBuiltIn(582);
            return NWN.Internal.StackPopString();
        }

        //  returns an effect that will petrify the target
        //  * currently applies EffectParalyze and the stoneskin visual effect.
        public static NWN.Effect EffectPetrify()
        {
            NWN.Internal.CallBuiltIn(583);
            return NWN.Internal.StackPopEffect();
        }

        //  duplicates the item and returns a new object
        //  oItem - item to copy
        //  oTargetInventory - create item in this object's inventory. If this parameter
        //                     is not valid, the item will be created in oItem's location
        //  bCopyVars - copy the local variables from the old item to the new one
        //  * returns the new item
        //  * returns OBJECT_INVALID for non-items.
        //  * can only copy empty item containers. will return OBJECT_INVALID if oItem contains
        //    other items.
        //  * if it is possible to merge this item with any others in the target location,
        //    then it will do so and return the merged object.
        public static NWN.Object CopyItem(NWN.Object oItem, NWN.Object oTargetInventory = null, int bCopyVars = FALSE)
        {
            NWN.Internal.StackPushInteger(bCopyVars);
            NWN.Internal.StackPushObject(oTargetInventory, false);
            NWN.Internal.StackPushObject(oItem, false);
            NWN.Internal.CallBuiltIn(584);
            return NWN.Internal.StackPopObject();
        }

        //  returns an effect that is guaranteed to paralyze a creature.
        //  this effect is identical to EffectParalyze except that it cannot be resisted.
        public static NWN.Effect EffectCutsceneParalyze()
        {
            NWN.Internal.CallBuiltIn(585);
            return NWN.Internal.StackPopEffect();
        }

        //  returns TRUE if the item CAN be dropped
        //  Droppable items will appear on a creature's remains when the creature is killed.
        public static int GetDroppableFlag(NWN.Object oItem)
        {
            NWN.Internal.StackPushObject(oItem, false);
            NWN.Internal.CallBuiltIn(586);
            return NWN.Internal.StackPopInteger();
        }

        //  returns TRUE if the placeable object is usable
        public static int GetUseableFlag(NWN.Object oObject = null)
        {
            NWN.Internal.StackPushObject(oObject, false);
            NWN.Internal.CallBuiltIn(587);
            return NWN.Internal.StackPopInteger();
        }

        //  returns TRUE if the item is stolen
        public static int GetStolenFlag(NWN.Object oStolen)
        {
            NWN.Internal.StackPushObject(oStolen, false);
            NWN.Internal.CallBuiltIn(588);
            return NWN.Internal.StackPopInteger();
        }

        //  This stores a float out to the specified campaign database
        //  The database name IS case sensitive and it must be the same for both set and get functions.
        //  The var name must be unique across the entire database, regardless of the variable type.
        //  If you want a variable to pertain to a specific player in the game, provide a player object.
        public static void SetCampaignFloat(string sCampaignName, string sVarName, float flFloat, NWN.Object oPlayer = null)
        {
            NWN.Internal.StackPushObject(oPlayer, false);
            NWN.Internal.StackPushFloat(flFloat);
            NWN.Internal.StackPushString(sVarName);
            NWN.Internal.StackPushString(sCampaignName);
            NWN.Internal.CallBuiltIn(589);
        }

        //  This stores an int out to the specified campaign database
        //  The database name IS case sensitive and it must be the same for both set and get functions.
        //  The var name must be unique across the entire database, regardless of the variable type.
        //  If you want a variable to pertain to a specific player in the game, provide a player object.
        public static void SetCampaignInt(string sCampaignName, string sVarName, int nInt, NWN.Object oPlayer = null)
        {
            NWN.Internal.StackPushObject(oPlayer, false);
            NWN.Internal.StackPushInteger(nInt);
            NWN.Internal.StackPushString(sVarName);
            NWN.Internal.StackPushString(sCampaignName);
            NWN.Internal.CallBuiltIn(590);
        }

        //  This stores a vector out to the specified campaign database
        //  The database name IS case sensitive and it must be the same for both set and get functions.
        //  The var name must be unique across the entire database, regardless of the variable type.
        //  If you want a variable to pertain to a specific player in the game, provide a player object.
        public static void SetCampaignVector(string sCampaignName, string sVarName, NWN.Vector? vVector, NWN.Object oPlayer = null)
        {
            NWN.Internal.StackPushObject(oPlayer, false);
            NWN.Internal.StackPushVector(vVector);
            NWN.Internal.StackPushString(sVarName);
            NWN.Internal.StackPushString(sCampaignName);
            NWN.Internal.CallBuiltIn(591);
        }

        //  This stores a location out to the specified campaign database
        //  The database name IS case sensitive and it must be the same for both set and get functions.
        //  The var name must be unique across the entire database, regardless of the variable type.
        //  If you want a variable to pertain to a specific player in the game, provide a player object.
        public static void SetCampaignLocation(string sCampaignName, string sVarName, NWN.Location locLocation, NWN.Object oPlayer = null)
        {
            NWN.Internal.StackPushObject(oPlayer, false);
            NWN.Internal.StackPushLocation(locLocation);
            NWN.Internal.StackPushString(sVarName);
            NWN.Internal.StackPushString(sCampaignName);
            NWN.Internal.CallBuiltIn(592);
        }

        //  This stores a string out to the specified campaign database
        //  The database name IS case sensitive and it must be the same for both set and get functions.
        //  The var name must be unique across the entire database, regardless of the variable type.
        //  If you want a variable to pertain to a specific player in the game, provide a player object.
        public static void SetCampaignString(string sCampaignName, string sVarName, string sString, NWN.Object oPlayer = null)
        {
            NWN.Internal.StackPushObject(oPlayer, false);
            NWN.Internal.StackPushString(sString);
            NWN.Internal.StackPushString(sVarName);
            NWN.Internal.StackPushString(sCampaignName);
            NWN.Internal.CallBuiltIn(593);
        }

        //  This will delete the entire campaign database if it exists.
        public static void DestroyCampaignDatabase(string sCampaignName)
        {
            NWN.Internal.StackPushString(sCampaignName);
            NWN.Internal.CallBuiltIn(594);
        }

        //  This will read a float from the  specified campaign database
        //  The database name IS case sensitive and it must be the same for both set and get functions.
        //  The var name must be unique across the entire database, regardless of the variable type.
        //  If you want a variable to pertain to a specific player in the game, provide a player object.
        public static float GetCampaignFloat(string sCampaignName, string sVarName, NWN.Object oPlayer = null)
        {
            NWN.Internal.StackPushObject(oPlayer, false);
            NWN.Internal.StackPushString(sVarName);
            NWN.Internal.StackPushString(sCampaignName);
            NWN.Internal.CallBuiltIn(595);
            return NWN.Internal.StackPopFloat();
        }

        //  This will read an int from the  specified campaign database
        //  The database name IS case sensitive and it must be the same for both set and get functions.
        //  The var name must be unique across the entire database, regardless of the variable type.
        //  If you want a variable to pertain to a specific player in the game, provide a player object.
        public static int GetCampaignInt(string sCampaignName, string sVarName, NWN.Object oPlayer = null)
        {
            NWN.Internal.StackPushObject(oPlayer, false);
            NWN.Internal.StackPushString(sVarName);
            NWN.Internal.StackPushString(sCampaignName);
            NWN.Internal.CallBuiltIn(596);
            return NWN.Internal.StackPopInteger();
        }

        //  This will read a vector from the  specified campaign database
        //  The database name IS case sensitive and it must be the same for both set and get functions.
        //  The var name must be unique across the entire database, regardless of the variable type.
        //  If you want a variable to pertain to a specific player in the game, provide a player object.
        public static NWN.Vector GetCampaignVector(string sCampaignName, string sVarName, NWN.Object oPlayer = null)
        {
            NWN.Internal.StackPushObject(oPlayer, false);
            NWN.Internal.StackPushString(sVarName);
            NWN.Internal.StackPushString(sCampaignName);
            NWN.Internal.CallBuiltIn(597);
            return NWN.Internal.StackPopVector();
        }

        //  This will read a location from the  specified campaign database
        //  The database name IS case sensitive and it must be the same for both set and get functions.
        //  The var name must be unique across the entire database, regardless of the variable type.
        //  If you want a variable to pertain to a specific player in the game, provide a player object.
        public static NWN.Location GetCampaignLocation(string sCampaignName, string sVarName, NWN.Object oPlayer = null)
        {
            NWN.Internal.StackPushObject(oPlayer, false);
            NWN.Internal.StackPushString(sVarName);
            NWN.Internal.StackPushString(sCampaignName);
            NWN.Internal.CallBuiltIn(598);
            return NWN.Internal.StackPopLocation();
        }

        //  This will read a string from the  specified campaign database
        //  The database name IS case sensitive and it must be the same for both set and get functions.
        //  The var name must be unique across the entire database, regardless of the variable type.
        //  If you want a variable to pertain to a specific player in the game, provide a player object.
        public static string GetCampaignString(string sCampaignName, string sVarName, NWN.Object oPlayer = null)
        {
            NWN.Internal.StackPushObject(oPlayer, false);
            NWN.Internal.StackPushString(sVarName);
            NWN.Internal.StackPushString(sCampaignName);
            NWN.Internal.CallBuiltIn(599);
            return NWN.Internal.StackPopString();
        }

        //  Duplicates the object specified by oSource.
        //  ONLY creatures and items can be specified.
        //  If an owner is specified and the object is an item, it will be put into their inventory
        //  If the object is a creature, they will be created at the location.
        //  If a new tag is specified, it will be assigned to the new object.
        public static NWN.Object CopyObject(NWN.Object oSource, NWN.Location locLocation, NWN.Object oOwner = null, string sNewTag = "")
        {
            NWN.Internal.StackPushString(sNewTag);
            NWN.Internal.StackPushObject(oOwner, false);
            NWN.Internal.StackPushLocation(locLocation);
            NWN.Internal.StackPushObject(oSource, false);
            NWN.Internal.CallBuiltIn(600);
            return NWN.Internal.StackPopObject();
        }

        //  This will remove ANY campaign variable. Regardless of type.
        //  Note that by normal database standards, deleting does not actually removed the entry from
        //  the database, but flags it as deleted. Do not expect the database files to shrink in size
        //  from this command. If you want to 'pack' the database, you will have to do it externally
        //  from the game.
        public static void DeleteCampaignVariable(string sCampaignName, string sVarName, NWN.Object oPlayer = null)
        {
            NWN.Internal.StackPushObject(oPlayer, false);
            NWN.Internal.StackPushString(sVarName);
            NWN.Internal.StackPushString(sCampaignName);
            NWN.Internal.CallBuiltIn(601);
        }

        //  Stores an object with the given id.
        //  NOTE: this command can only be used for storing Creatures and Items.
        //  Returns 0 if it failled, 1 if it worked.
        public static int StoreCampaignObject(string sCampaignName, string sVarName, NWN.Object oObject, NWN.Object oPlayer = null)
        {
            NWN.Internal.StackPushObject(oPlayer, false);
            NWN.Internal.StackPushObject(oObject, false);
            NWN.Internal.StackPushString(sVarName);
            NWN.Internal.StackPushString(sCampaignName);
            NWN.Internal.CallBuiltIn(602);
            return NWN.Internal.StackPopInteger();
        }

        //  Use RetrieveCampaign with the given id to restore it.
        //  If you specify an owner, the object will try to be created in their repository
        //  If the owner can't handle the item (or if it's a creature) it will be created on the ground.
        public static NWN.Object RetrieveCampaignObject(string sCampaignName, string sVarName, NWN.Location locLocation, NWN.Object oOwner = null, NWN.Object oPlayer = null)
        {
            NWN.Internal.StackPushObject(oPlayer, false);
            NWN.Internal.StackPushObject(oOwner, false);
            NWN.Internal.StackPushLocation(locLocation);
            NWN.Internal.StackPushString(sVarName);
            NWN.Internal.StackPushString(sCampaignName);
            NWN.Internal.CallBuiltIn(603);
            return NWN.Internal.StackPopObject();
        }

        //  Returns an effect that is guaranteed to dominate a creature
        //  Like EffectDominated but cannot be resisted
        public static NWN.Effect EffectCutsceneDominated()
        {
            NWN.Internal.CallBuiltIn(604);
            return NWN.Internal.StackPopEffect();
        }

        //  Returns stack size of an item
        //  - oItem: item to query
        public static int GetItemStackSize(NWN.Object oItem)
        {
            NWN.Internal.StackPushObject(oItem, false);
            NWN.Internal.CallBuiltIn(605);
            return NWN.Internal.StackPopInteger();
        }

        //  Sets stack size of an item.
        //  - oItem: item to change
        //  - nSize: new size of stack.  Will be restricted to be between 1 and the
        //    maximum stack size for the item type.  If a value less than 1 is passed it
        //    will set the stack to 1.  If a value greater than the max is passed
        //    then it will set the stack to the maximum size
        public static void SetItemStackSize(NWN.Object oItem, int nSize)
        {
            NWN.Internal.StackPushInteger(nSize);
            NWN.Internal.StackPushObject(oItem, false);
            NWN.Internal.CallBuiltIn(606);
        }

        //  Returns charges left on an item
        //  - oItem: item to query
        public static int GetItemCharges(NWN.Object oItem)
        {
            NWN.Internal.StackPushObject(oItem, false);
            NWN.Internal.CallBuiltIn(607);
            return NWN.Internal.StackPopInteger();
        }

        //  Sets charges left on an item.
        //  - oItem: item to change
        //  - nCharges: number of charges.  If value below 0 is passed, # charges will
        //    be set to 0.  If value greater than maximum is passed, # charges will
        //    be set to maximum.  If the # charges drops to 0 the item
        //    will be destroyed.
        public static void SetItemCharges(NWN.Object oItem, int nCharges)
        {
            NWN.Internal.StackPushInteger(nCharges);
            NWN.Internal.StackPushObject(oItem, false);
            NWN.Internal.CallBuiltIn(608);
        }

        //  ***********************  START OF ITEM PROPERTY FUNCTIONS  **********************
        //  adds an item property to the specified item
        //  Only temporary and permanent duration types are allowed.
        public static void AddItemProperty(int nDurationType, NWN.ItemProperty ipProperty, NWN.Object oItem, float fDuration = 0.0f)
        {
            NWN.Internal.StackPushFloat(fDuration);
            NWN.Internal.StackPushObject(oItem, false);
            NWN.Internal.StackPushItemProperty(ipProperty);
            NWN.Internal.StackPushInteger(nDurationType);
            NWN.Internal.CallBuiltIn(609);
        }

        //  removes an item property from the specified item
        public static void RemoveItemProperty(NWN.Object oItem, NWN.ItemProperty ipProperty)
        {
            NWN.Internal.StackPushItemProperty(ipProperty);
            NWN.Internal.StackPushObject(oItem, false);
            NWN.Internal.CallBuiltIn(610);
        }

        //  if the item property is valid this will return true
        public static int GetIsItemPropertyValid(NWN.ItemProperty ipProperty)
        {
            NWN.Internal.StackPushItemProperty(ipProperty);
            NWN.Internal.CallBuiltIn(611);
            return NWN.Internal.StackPopInteger();
        }

        //  Gets the first item property on an item
        public static NWN.ItemProperty GetFirstItemProperty(NWN.Object oItem)
        {
            NWN.Internal.StackPushObject(oItem, false);
            NWN.Internal.CallBuiltIn(612);
            return NWN.Internal.StackPopItemProperty();
        }

        //  Will keep retrieving the next and the next item property on an Item,
        //  will return an invalid item property when the list is empty.
        public static NWN.ItemProperty GetNextItemProperty(NWN.Object oItem)
        {
            NWN.Internal.StackPushObject(oItem, false);
            NWN.Internal.CallBuiltIn(613);
            return NWN.Internal.StackPopItemProperty();
        }

        //  will return the item property type (ie. holy avenger)
        public static int GetItemPropertyType(NWN.ItemProperty ip)
        {
            NWN.Internal.StackPushItemProperty(ip);
            NWN.Internal.CallBuiltIn(614);
            return NWN.Internal.StackPopInteger();
        }

        //  will return the duration type of the item property
        public static int GetItemPropertyDurationType(NWN.ItemProperty ip)
        {
            NWN.Internal.StackPushItemProperty(ip);
            NWN.Internal.CallBuiltIn(615);
            return NWN.Internal.StackPopInteger();
        }

        //  Returns Item property ability bonus.  You need to specify an
        //  ability constant(IP_CONST_ABILITY_*) and the bonus.  The bonus should
        //  be a positive integer between 1 and 12.
        public static NWN.ItemProperty ItemPropertyAbilityBonus(int nAbility, int nBonus)
        {
            NWN.Internal.StackPushInteger(nBonus);
            NWN.Internal.StackPushInteger(nAbility);
            NWN.Internal.CallBuiltIn(616);
            return NWN.Internal.StackPopItemProperty();
        }

        //  Returns Item property AC bonus.  You need to specify the bonus.
        //  The bonus should be a positive integer between 1 and 20. The modifier
        //  type depends on the item it is being applied to.
        public static NWN.ItemProperty ItemPropertyACBonus(int nBonus)
        {
            NWN.Internal.StackPushInteger(nBonus);
            NWN.Internal.CallBuiltIn(617);
            return NWN.Internal.StackPopItemProperty();
        }

        //  Returns Item property AC bonus vs. alignment group.  An example of
        //  an alignment group is Chaotic, or Good.  You need to specify the
        //  alignment group constant(IP_CONST_ALIGNMENTGROUP_*) and the AC bonus.
        //  The AC bonus should be an integer between 1 and 20.  The modifier
        //  type depends on the item it is being applied to.
        public static NWN.ItemProperty ItemPropertyACBonusVsAlign(int nAlignGroup, int nACBonus)
        {
            NWN.Internal.StackPushInteger(nACBonus);
            NWN.Internal.StackPushInteger(nAlignGroup);
            NWN.Internal.CallBuiltIn(618);
            return NWN.Internal.StackPopItemProperty();
        }

        //  Returns Item property AC bonus vs. Damage type (ie. piercing).  You
        //  need to specify the damage type constant(IP_CONST_DAMAGETYPE_*) and the
        //  AC bonus.  The AC bonus should be an integer between 1 and 20.  The
        //  modifier type depends on the item it is being applied to.
        //  NOTE: Only the first 3 damage types may be used here, the 3 basic
        //        physical types.
        public static NWN.ItemProperty ItemPropertyACBonusVsDmgType(int nDamageType, int nACBonus)
        {
            NWN.Internal.StackPushInteger(nACBonus);
            NWN.Internal.StackPushInteger(nDamageType);
            NWN.Internal.CallBuiltIn(619);
            return NWN.Internal.StackPopItemProperty();
        }

        //  Returns Item property AC bonus vs. Racial group.  You need to specify
        //  the racial group constant(IP_CONST_RACIALTYPE_*) and the AC bonus.  The AC
        //  bonus should be an integer between 1 and 20.  The modifier type depends
        //  on the item it is being applied to.
        public static NWN.ItemProperty ItemPropertyACBonusVsRace(int nRace, int nACBonus)
        {
            NWN.Internal.StackPushInteger(nACBonus);
            NWN.Internal.StackPushInteger(nRace);
            NWN.Internal.CallBuiltIn(620);
            return NWN.Internal.StackPopItemProperty();
        }

        //  Returns Item property AC bonus vs. Specific alignment.  You need to
        //  specify the specific alignment constant(IP_CONST_ALIGNMENT_*) and the AC
        //  bonus.  The AC bonus should be an integer between 1 and 20.  The
        //  modifier type depends on the item it is being applied to.
        public static NWN.ItemProperty ItemPropertyACBonusVsSAlign(int nAlign, int nACBonus)
        {
            NWN.Internal.StackPushInteger(nACBonus);
            NWN.Internal.StackPushInteger(nAlign);
            NWN.Internal.CallBuiltIn(621);
            return NWN.Internal.StackPopItemProperty();
        }

        //  Returns Item property Enhancement bonus.  You need to specify the
        //  enhancement bonus.  The Enhancement bonus should be an integer between
        //  1 and 20.
        public static NWN.ItemProperty ItemPropertyEnhancementBonus(int nEnhancementBonus)
        {
            NWN.Internal.StackPushInteger(nEnhancementBonus);
            NWN.Internal.CallBuiltIn(622);
            return NWN.Internal.StackPopItemProperty();
        }

        //  Returns Item property Enhancement bonus vs. an Alignment group.  You
        //  need to specify the alignment group constant(IP_CONST_ALIGNMENTGROUP_*)
        //  and the enhancement bonus.  The Enhancement bonus should be an integer
        //  between 1 and 20.
        public static NWN.ItemProperty ItemPropertyEnhancementBonusVsAlign(int nAlignGroup, int nBonus)
        {
            NWN.Internal.StackPushInteger(nBonus);
            NWN.Internal.StackPushInteger(nAlignGroup);
            NWN.Internal.CallBuiltIn(623);
            return NWN.Internal.StackPopItemProperty();
        }

        //  Returns Item property Enhancement bonus vs. Racial group.  You need
        //  to specify the racial group constant(IP_CONST_RACIALTYPE_*) and the
        //  enhancement bonus.  The enhancement bonus should be an integer between
        //  1 and 20.
        public static NWN.ItemProperty ItemPropertyEnhancementBonusVsRace(int nRace, int nBonus)
        {
            NWN.Internal.StackPushInteger(nBonus);
            NWN.Internal.StackPushInteger(nRace);
            NWN.Internal.CallBuiltIn(624);
            return NWN.Internal.StackPopItemProperty();
        }

        //  Returns Item property Enhancement bonus vs. a specific alignment.  You
        //  need to specify the alignment constant(IP_CONST_ALIGNMENT_*) and the
        //  enhancement bonus.  The enhancement bonus should be an integer between
        //  1 and 20.
        public static NWN.ItemProperty ItemPropertyEnhancementBonusVsSAlign(int nAlign, int nBonus)
        {
            NWN.Internal.StackPushInteger(nBonus);
            NWN.Internal.StackPushInteger(nAlign);
            NWN.Internal.CallBuiltIn(625);
            return NWN.Internal.StackPopItemProperty();
        }

        //  Returns Item property Enhancment penalty.  You need to specify the
        //  enhancement penalty.  The enhancement penalty should be a POSITIVE
        //  integer between 1 and 5 (ie. 1 = -1).
        public static NWN.ItemProperty ItemPropertyEnhancementPenalty(int nPenalty)
        {
            NWN.Internal.StackPushInteger(nPenalty);
            NWN.Internal.CallBuiltIn(626);
            return NWN.Internal.StackPopItemProperty();
        }

        //  Returns Item property weight reduction.  You need to specify the weight
        //  reduction constant(IP_CONST_REDUCEDWEIGHT_*).
        public static NWN.ItemProperty ItemPropertyWeightReduction(int nReduction)
        {
            NWN.Internal.StackPushInteger(nReduction);
            NWN.Internal.CallBuiltIn(627);
            return NWN.Internal.StackPopItemProperty();
        }

        //  Returns Item property Bonus Feat.  You need to specify the the feat
        //  constant(IP_CONST_FEAT_*).
        public static NWN.ItemProperty ItemPropertyBonusFeat(int nFeat)
        {
            NWN.Internal.StackPushInteger(nFeat);
            NWN.Internal.CallBuiltIn(628);
            return NWN.Internal.StackPopItemProperty();
        }

        //  Returns Item property Bonus level spell (Bonus spell of level).  You must
        //  specify the class constant(IP_CONST_CLASS_*) of the bonus spell(MUST BE a
        //  spell casting class) and the level of the bonus spell.  The level of the
        //  bonus spell should be an integer between 0 and 9.
        public static NWN.ItemProperty ItemPropertyBonusLevelSpell(int nClass, int nSpellLevel)
        {
            NWN.Internal.StackPushInteger(nSpellLevel);
            NWN.Internal.StackPushInteger(nClass);
            NWN.Internal.CallBuiltIn(629);
            return NWN.Internal.StackPopItemProperty();
        }

        //  Returns Item property Cast spell.  You must specify the spell constant
        //  (IP_CONST_CASTSPELL_*) and the number of uses constant(IP_CONST_CASTSPELL_NUMUSES_*).
        //  NOTE: The number after the name of the spell in the constant is the level
        //        at which the spell will be cast.  Sometimes there are multiple copies
        //        of the same spell but they each are cast at a different level.  The higher
        //        the level, the more cost will be added to the item.
        //  NOTE: The list of spells that can be applied to an item will depend on the
        //        item type.  For instance there are spells that can be applied to a wand
        //        that cannot be applied to a potion.  Below is a list of the types and the
        //        spells that are allowed to be placed on them.  If you try to put a cast
        //        spell effect on an item that is not allowed to have that effect it will
        //        not work.
        //  NOTE: Even if spells have multiple versions of different levels they are only
        //        listed below once.
        // 
        //  WANDS:
        //           Acid_Splash
        //           Activate_Item
        //           Aid
        //           Amplify
        //           Animate_Dead
        //           AuraOfGlory
        //           BalagarnsIronHorn
        //           Bane
        //           Banishment
        //           Barkskin
        //           Bestow_Curse
        //           Bigbys_Clenched_Fist
        //           Bigbys_Crushing_Hand
        //           Bigbys_Forceful_Hand
        //           Bigbys_Grasping_Hand
        //           Bigbys_Interposing_Hand
        //           Bless
        //           Bless_Weapon
        //           Blindness/Deafness
        //           Blood_Frenzy
        //           Bombardment
        //           Bulls_Strength
        //           Burning_Hands
        //           Call_Lightning
        //           Camoflage
        //           Cats_Grace
        //           Charm_Monster
        //           Charm_Person
        //           Charm_Person_or_Animal
        //           Clairaudience/Clairvoyance
        //           Clarity
        //           Color_Spray
        //           Confusion
        //           Continual_Flame
        //           Cure_Critical_Wounds
        //           Cure_Light_Wounds
        //           Cure_Minor_Wounds
        //           Cure_Moderate_Wounds
        //           Cure_Serious_Wounds
        //           Darkness
        //           Darkvision
        //           Daze
        //           Death_Ward
        //           Dirge
        //           Dismissal
        //           Dispel_Magic
        //           Displacement
        //           Divine_Favor
        //           Divine_Might
        //           Divine_Power
        //           Divine_Shield
        //           Dominate_Animal
        //           Dominate_Person
        //           Doom
        //           Dragon_Breath_Acid
        //           Dragon_Breath_Cold
        //           Dragon_Breath_Fear
        //           Dragon_Breath_Fire
        //           Dragon_Breath_Gas
        //           Dragon_Breath_Lightning
        //           Dragon_Breath_Paralyze
        //           Dragon_Breath_Sleep
        //           Dragon_Breath_Slow
        //           Dragon_Breath_Weaken
        //           Drown
        //           Eagle_Spledor
        //           Earthquake
        //           Electric_Jolt
        //           Elemental_Shield
        //           Endurance
        //           Endure_Elements
        //           Enervation
        //           Entangle
        //           Entropic_Shield
        //           Etherealness
        //           Expeditious_Retreat
        //           Fear
        //           Find_Traps
        //           Fireball
        //           Firebrand
        //           Flame_Arrow
        //           Flame_Lash
        //           Flame_Strike
        //           Flare
        //           Foxs_Cunning
        //           Freedom_of_Movement
        //           Ghostly_Visage
        //           Ghoul_Touch
        //           Grease
        //           Greater_Magic_Fang
        //           Greater_Magic_Weapon
        //           Grenade_Acid
        //           Grenade_Caltrops
        //           Grenade_Chicken
        //           Grenade_Choking
        //           Grenade_Fire
        //           Grenade_Holy
        //           Grenade_Tangle
        //           Grenade_Thunderstone
        //           Gust_of_wind
        //           Hammer_of_the_Gods
        //           Haste
        //           Hold_Animal
        //           Hold_Monster
        //           Hold_Person
        //           Ice_Storm
        //           Identify
        //           Improved_Invisibility
        //           Inferno
        //           Inflict_Critical_Wounds
        //           Inflict_Light_Wounds
        //           Inflict_Minor_Wounds
        //           Inflict_Moderate_Wounds
        //           Inflict_Serious_Wounds
        //           Invisibility
        //           Invisibility_Purge
        //           Invisibility_Sphere
        //           Isaacs_Greater_Missile_Storm
        //           Isaacs_Lesser_Missile_Storm
        //           Knock
        //           Lesser_Dispel
        //           Lesser_Restoration
        //           Lesser_Spell_Breach
        //           Light
        //           Lightning_Bolt
        //           Mage_Armor
        //           Magic_Circle_against_Alignment
        //           Magic_Fang
        //           Magic_Missile
        //           Manipulate_Portal_Stone
        //           Mass_Camoflage
        //           Melfs_Acid_Arrow
        //           Meteor_Swarm
        //           Mind_Blank
        //           Mind_Fog
        //           Negative_Energy_Burst
        //           Negative_Energy_Protection
        //           Negative_Energy_Ray
        //           Neutralize_Poison
        //           One_With_The_Land
        //           Owls_Insight
        //           Owls_Wisdom
        //           Phantasmal_Killer
        //           Planar_Ally
        //           Poison
        //           Polymorph_Self
        //           Prayer
        //           Protection_from_Alignment
        //           Protection_From_Elements
        //           Quillfire
        //           Ray_of_Enfeeblement
        //           Ray_of_Frost
        //           Remove_Blindness/Deafness
        //           Remove_Curse
        //           Remove_Disease
        //           Remove_Fear
        //           Remove_Paralysis
        //           Resist_Elements
        //           Resistance
        //           Restoration
        //           Sanctuary
        //           Scare
        //           Searing_Light
        //           See_Invisibility
        //           Shadow_Conjuration
        //           Shield
        //           Shield_of_Faith
        //           Silence
        //           Sleep
        //           Slow
        //           Sound_Burst
        //           Spike_Growth
        //           Stinking_Cloud
        //           Stoneskin
        //           Summon_Creature_I
        //           Summon_Creature_I
        //           Summon_Creature_II
        //           Summon_Creature_III
        //           Summon_Creature_IV
        //           Sunburst
        //           Tashas_Hideous_Laughter
        //           True_Strike
        //           Undeaths_Eternal_Foe
        //           Unique_Power
        //           Unique_Power_Self_Only
        //           Vampiric_Touch
        //           Virtue
        //           Wall_of_Fire
        //           Web
        //           Wounding_Whispers
        // 
        //  POTIONS:
        //           Activate_Item
        //           Aid
        //           Amplify
        //           AuraOfGlory
        //           Bane
        //           Barkskin
        //           Barkskin
        //           Barkskin
        //           Bless
        //           Bless_Weapon
        //           Bless_Weapon
        //           Blood_Frenzy
        //           Bulls_Strength
        //           Bulls_Strength
        //           Bulls_Strength
        //           Camoflage
        //           Cats_Grace
        //           Cats_Grace
        //           Cats_Grace
        //           Clairaudience/Clairvoyance
        //           Clairaudience/Clairvoyance
        //           Clairaudience/Clairvoyance
        //           Clarity
        //           Continual_Flame
        //           Cure_Critical_Wounds
        //           Cure_Critical_Wounds
        //           Cure_Critical_Wounds
        //           Cure_Light_Wounds
        //           Cure_Light_Wounds
        //           Cure_Minor_Wounds
        //           Cure_Moderate_Wounds
        //           Cure_Moderate_Wounds
        //           Cure_Moderate_Wounds
        //           Cure_Serious_Wounds
        //           Cure_Serious_Wounds
        //           Cure_Serious_Wounds
        //           Darkness
        //           Darkvision
        //           Darkvision
        //           Death_Ward
        //           Dispel_Magic
        //           Dispel_Magic
        //           Displacement
        //           Divine_Favor
        //           Divine_Might
        //           Divine_Power
        //           Divine_Shield
        //           Dragon_Breath_Acid
        //           Dragon_Breath_Cold
        //           Dragon_Breath_Fear
        //           Dragon_Breath_Fire
        //           Dragon_Breath_Gas
        //           Dragon_Breath_Lightning
        //           Dragon_Breath_Paralyze
        //           Dragon_Breath_Sleep
        //           Dragon_Breath_Slow
        //           Dragon_Breath_Weaken
        //           Eagle_Spledor
        //           Eagle_Spledor
        //           Eagle_Spledor
        //           Elemental_Shield
        //           Elemental_Shield
        //           Endurance
        //           Endurance
        //           Endurance
        //           Endure_Elements
        //           Entropic_Shield
        //           Ethereal_Visage
        //           Ethereal_Visage
        //           Etherealness
        //           Expeditious_Retreat
        //           Find_Traps
        //           Foxs_Cunning
        //           Foxs_Cunning
        //           Foxs_Cunning
        //           Freedom_of_Movement
        //           Ghostly_Visage
        //           Ghostly_Visage
        //           Ghostly_Visage
        //           Globe_of_Invulnerability
        //           Greater_Bulls_Strength
        //           Greater_Cats_Grace
        //           Greater_Dispelling
        //           Greater_Dispelling
        //           Greater_Eagles_Splendor
        //           Greater_Endurance
        //           Greater_Foxs_Cunning
        //           Greater_Magic_Weapon
        //           Greater_Owls_Wisdom
        //           Greater_Restoration
        //           Greater_Spell_Mantle
        //           Greater_Stoneskin
        //           Grenade_Acid
        //           Grenade_Caltrops
        //           Grenade_Chicken
        //           Grenade_Choking
        //           Grenade_Fire
        //           Grenade_Holy
        //           Grenade_Tangle
        //           Grenade_Thunderstone
        //           Haste
        //           Haste
        //           Heal
        //           Hold_Animal
        //           Hold_Monster
        //           Hold_Person
        //           Identify
        //           Invisibility
        //           Lesser_Dispel
        //           Lesser_Dispel
        //           Lesser_Mind_Blank
        //           Lesser_Restoration
        //           Lesser_Spell_Mantle
        //           Light
        //           Light
        //           Mage_Armor
        //           Manipulate_Portal_Stone
        //           Mass_Camoflage
        //           Mind_Blank
        //           Minor_Globe_of_Invulnerability
        //           Minor_Globe_of_Invulnerability
        //           Mordenkainens_Disjunction
        //           Negative_Energy_Protection
        //           Negative_Energy_Protection
        //           Negative_Energy_Protection
        //           Neutralize_Poison
        //           One_With_The_Land
        //           Owls_Insight
        //           Owls_Wisdom
        //           Owls_Wisdom
        //           Owls_Wisdom
        //           Polymorph_Self
        //           Prayer
        //           Premonition
        //           Protection_From_Elements
        //           Protection_From_Elements
        //           Protection_from_Spells
        //           Protection_from_Spells
        //           Raise_Dead
        //           Remove_Blindness/Deafness
        //           Remove_Curse
        //           Remove_Disease
        //           Remove_Fear
        //           Remove_Paralysis
        //           Resist_Elements
        //           Resist_Elements
        //           Resistance
        //           Resistance
        //           Restoration
        //           Resurrection
        //           Rogues_Cunning
        //           See_Invisibility
        //           Shadow_Shield
        //           Shapechange
        //           Shield
        //           Shield_of_Faith
        //           Special_Alcohol_Beer
        //           Special_Alcohol_Spirits
        //           Special_Alcohol_Wine
        //           Special_Herb_Belladonna
        //           Special_Herb_Garlic
        //           Spell_Mantle
        //           Spell_Resistance
        //           Spell_Resistance
        //           Stoneskin
        //           Tensers_Transformation
        //           True_Seeing
        //           True_Strike
        //           Unique_Power
        //           Unique_Power_Self_Only
        //           Virtue
        // 
        //  GENERAL USE (ie. everything else):
        //           Just about every spell is useable by all the general use items so instead we
        //           will only list the ones that are not allowed:
        //           Special_Alcohol_Beer
        //           Special_Alcohol_Spirits
        //           Special_Alcohol_Wine
        // 
        public static NWN.ItemProperty ItemPropertyCastSpell(int nSpell, int nNumUses)
        {
            NWN.Internal.StackPushInteger(nNumUses);
            NWN.Internal.StackPushInteger(nSpell);
            NWN.Internal.CallBuiltIn(630);
            return NWN.Internal.StackPopItemProperty();
        }

        //  Returns Item property damage bonus.  You must specify the damage type constant
        //  (IP_CONST_DAMAGETYPE_*) and the amount of damage constant(IP_CONST_DAMAGEBONUS_*).
        //  NOTE: not all the damage types will work, use only the following: Acid, Bludgeoning,
        //        Cold, Electrical, Fire, Piercing, Slashing, Sonic.
        public static NWN.ItemProperty ItemPropertyDamageBonus(int nDamageType, int nDamage)
        {
            NWN.Internal.StackPushInteger(nDamage);
            NWN.Internal.StackPushInteger(nDamageType);
            NWN.Internal.CallBuiltIn(631);
            return NWN.Internal.StackPopItemProperty();
        }

        //  Returns Item property damage bonus vs. Alignment groups.  You must specify the
        //  alignment group constant(IP_CONST_ALIGNMENTGROUP_*) and the damage type constant
        //  (IP_CONST_DAMAGETYPE_*) and the amount of damage constant(IP_CONST_DAMAGEBONUS_*).
        //  NOTE: not all the damage types will work, use only the following: Acid, Bludgeoning,
        //        Cold, Electrical, Fire, Piercing, Slashing, Sonic.
        public static NWN.ItemProperty ItemPropertyDamageBonusVsAlign(int nAlignGroup, int nDamageType, int nDamage)
        {
            NWN.Internal.StackPushInteger(nDamage);
            NWN.Internal.StackPushInteger(nDamageType);
            NWN.Internal.StackPushInteger(nAlignGroup);
            NWN.Internal.CallBuiltIn(632);
            return NWN.Internal.StackPopItemProperty();
        }

        //  Returns Item property damage bonus vs. specific race.  You must specify the
        //  racial group constant(IP_CONST_RACIALTYPE_*) and the damage type constant
        //  (IP_CONST_DAMAGETYPE_*) and the amount of damage constant(IP_CONST_DAMAGEBONUS_*).
        //  NOTE: not all the damage types will work, use only the following: Acid, Bludgeoning,
        //        Cold, Electrical, Fire, Piercing, Slashing, Sonic.
        public static NWN.ItemProperty ItemPropertyDamageBonusVsRace(int nRace, int nDamageType, int nDamage)
        {
            NWN.Internal.StackPushInteger(nDamage);
            NWN.Internal.StackPushInteger(nDamageType);
            NWN.Internal.StackPushInteger(nRace);
            NWN.Internal.CallBuiltIn(633);
            return NWN.Internal.StackPopItemProperty();
        }

        //  Returns Item property damage bonus vs. specific alignment.  You must specify the
        //  specific alignment constant(IP_CONST_ALIGNMENT_*) and the damage type constant
        //  (IP_CONST_DAMAGETYPE_*) and the amount of damage constant(IP_CONST_DAMAGEBONUS_*).
        //  NOTE: not all the damage types will work, use only the following: Acid, Bludgeoning,
        //        Cold, Electrical, Fire, Piercing, Slashing, Sonic.
        public static NWN.ItemProperty ItemPropertyDamageBonusVsSAlign(int nAlign, int nDamageType, int nDamage)
        {
            NWN.Internal.StackPushInteger(nDamage);
            NWN.Internal.StackPushInteger(nDamageType);
            NWN.Internal.StackPushInteger(nAlign);
            NWN.Internal.CallBuiltIn(634);
            return NWN.Internal.StackPopItemProperty();
        }

        //  Returns Item property damage immunity.  You must specify the damage type constant
        //  (IP_CONST_DAMAGETYPE_*) that you want to be immune to and the immune bonus percentage
        //  constant(IP_CONST_DAMAGEIMMUNITY_*).
        //  NOTE: not all the damage types will work, use only the following: Acid, Bludgeoning,
        //        Cold, Electrical, Fire, Piercing, Slashing, Sonic.
        public static NWN.ItemProperty ItemPropertyDamageImmunity(int nDamageType, int nImmuneBonus)
        {
            NWN.Internal.StackPushInteger(nImmuneBonus);
            NWN.Internal.StackPushInteger(nDamageType);
            NWN.Internal.CallBuiltIn(635);
            return NWN.Internal.StackPopItemProperty();
        }

        //  Returns Item property damage penalty.  You must specify the damage penalty.
        //  The damage penalty should be a POSITIVE integer between 1 and 5 (ie. 1 = -1).
        public static NWN.ItemProperty ItemPropertyDamagePenalty(int nPenalty)
        {
            NWN.Internal.StackPushInteger(nPenalty);
            NWN.Internal.CallBuiltIn(636);
            return NWN.Internal.StackPopItemProperty();
        }

        //  Returns Item property damage reduction.  You must specify the enhancment level
        //  (IP_CONST_DAMAGEREDUCTION_*) that is required to get past the damage reduction
        //  and the amount of HP of damage constant(IP_CONST_DAMAGESOAK_*) will be soaked
        //  up if your weapon is not of high enough enhancement.
        public static NWN.ItemProperty ItemPropertyDamageReduction(int nEnhancement, int nHPSoak)
        {
            NWN.Internal.StackPushInteger(nHPSoak);
            NWN.Internal.StackPushInteger(nEnhancement);
            NWN.Internal.CallBuiltIn(637);
            return NWN.Internal.StackPopItemProperty();
        }

        //  Returns Item property damage resistance.  You must specify the damage type
        //  constant(IP_CONST_DAMAGETYPE_*) and the amount of HP of damage constant
        //  (IP_CONST_DAMAGERESIST_*) that will be resisted against each round.
        public static NWN.ItemProperty ItemPropertyDamageResistance(int nDamageType, int nHPResist)
        {
            NWN.Internal.StackPushInteger(nHPResist);
            NWN.Internal.StackPushInteger(nDamageType);
            NWN.Internal.CallBuiltIn(638);
            return NWN.Internal.StackPopItemProperty();
        }

        //  Returns Item property damage vulnerability.  You must specify the damage type
        //  constant(IP_CONST_DAMAGETYPE_*) that you want the user to be extra vulnerable to
        //  and the percentage vulnerability constant(IP_CONST_DAMAGEVULNERABILITY_*).
        public static NWN.ItemProperty ItemPropertyDamageVulnerability(int nDamageType, int nVulnerability)
        {
            NWN.Internal.StackPushInteger(nVulnerability);
            NWN.Internal.StackPushInteger(nDamageType);
            NWN.Internal.CallBuiltIn(639);
            return NWN.Internal.StackPopItemProperty();
        }

        //  Return Item property Darkvision.
        public static NWN.ItemProperty ItemPropertyDarkvision()
        {
            NWN.Internal.CallBuiltIn(640);
            return NWN.Internal.StackPopItemProperty();
        }

        //  Return Item property decrease ability score.  You must specify the ability
        //  constant(IP_CONST_ABILITY_*) and the modifier constant.  The modifier must be
        //  a POSITIVE integer between 1 and 10 (ie. 1 = -1).
        public static NWN.ItemProperty ItemPropertyDecreaseAbility(int nAbility, int nModifier)
        {
            NWN.Internal.StackPushInteger(nModifier);
            NWN.Internal.StackPushInteger(nAbility);
            NWN.Internal.CallBuiltIn(641);
            return NWN.Internal.StackPopItemProperty();
        }

        //  Returns Item property decrease Armor Class.  You must specify the armor
        //  modifier type constant(IP_CONST_ACMODIFIERTYPE_*) and the armor class penalty.
        //  The penalty must be a POSITIVE integer between 1 and 5 (ie. 1 = -1).
        public static NWN.ItemProperty ItemPropertyDecreaseAC(int nModifierType, int nPenalty)
        {
            NWN.Internal.StackPushInteger(nPenalty);
            NWN.Internal.StackPushInteger(nModifierType);
            NWN.Internal.CallBuiltIn(642);
            return NWN.Internal.StackPopItemProperty();
        }

        //  Returns Item property decrease skill.  You must specify the constant for the
        //  skill to be decreased(SKILL_*) and the amount of the penalty.  The penalty
        //  must be a POSITIVE integer between 1 and 10 (ie. 1 = -1).
        public static NWN.ItemProperty ItemPropertyDecreaseSkill(int nSkill, int nPenalty)
        {
            NWN.Internal.StackPushInteger(nPenalty);
            NWN.Internal.StackPushInteger(nSkill);
            NWN.Internal.CallBuiltIn(643);
            return NWN.Internal.StackPopItemProperty();
        }

        //  Returns Item property container reduced weight.  This is used for special
        //  containers that reduce the weight of the objects inside them.  You must
        //  specify the container weight reduction type constant(IP_CONST_CONTAINERWEIGHTRED_*).
        public static NWN.ItemProperty ItemPropertyContainerReducedWeight(int nContainerType)
        {
            NWN.Internal.StackPushInteger(nContainerType);
            NWN.Internal.CallBuiltIn(644);
            return NWN.Internal.StackPopItemProperty();
        }

        //  Returns Item property extra melee damage type.  You must specify the extra
        //  melee base damage type that you want applied.  It is a constant(IP_CONST_DAMAGETYPE_*).
        //  NOTE: only the first 3 base types (piercing, slashing, & bludgeoning are applicable
        //        here.
        //  NOTE: It is also only applicable to melee weapons.
        public static NWN.ItemProperty ItemPropertyExtraMeleeDamageType(int nDamageType)
        {
            NWN.Internal.StackPushInteger(nDamageType);
            NWN.Internal.CallBuiltIn(645);
            return NWN.Internal.StackPopItemProperty();
        }

        //  Returns Item property extra ranged damage type.  You must specify the extra
        //  melee base damage type that you want applied.  It is a constant(IP_CONST_DAMAGETYPE_*).
        //  NOTE: only the first 3 base types (piercing, slashing, & bludgeoning are applicable
        //        here.
        //  NOTE: It is also only applicable to ranged weapons.
        public static NWN.ItemProperty ItemPropertyExtraRangeDamageType(int nDamageType)
        {
            NWN.Internal.StackPushInteger(nDamageType);
            NWN.Internal.CallBuiltIn(646);
            return NWN.Internal.StackPopItemProperty();
        }

        //  Returns Item property haste.
        public static NWN.ItemProperty ItemPropertyHaste()
        {
            NWN.Internal.CallBuiltIn(647);
            return NWN.Internal.StackPopItemProperty();
        }

        //  Returns Item property Holy Avenger.
        public static NWN.ItemProperty ItemPropertyHolyAvenger()
        {
            NWN.Internal.CallBuiltIn(648);
            return NWN.Internal.StackPopItemProperty();
        }

        //  Returns Item property immunity to miscellaneous effects.  You must specify the
        //  effect to which the user is immune, it is a constant(IP_CONST_IMMUNITYMISC_*).
        public static NWN.ItemProperty ItemPropertyImmunityMisc(int nImmunityType)
        {
            NWN.Internal.StackPushInteger(nImmunityType);
            NWN.Internal.CallBuiltIn(649);
            return NWN.Internal.StackPopItemProperty();
        }

        //  Returns Item property improved evasion.
        public static NWN.ItemProperty ItemPropertyImprovedEvasion()
        {
            NWN.Internal.CallBuiltIn(650);
            return NWN.Internal.StackPopItemProperty();
        }

        //  Returns Item property bonus spell resistance.  You must specify the bonus spell
        //  resistance constant(IP_CONST_SPELLRESISTANCEBONUS_*).
        public static NWN.ItemProperty ItemPropertyBonusSpellResistance(int nBonus)
        {
            NWN.Internal.StackPushInteger(nBonus);
            NWN.Internal.CallBuiltIn(651);
            return NWN.Internal.StackPopItemProperty();
        }

        //  Returns Item property saving throw bonus vs. a specific effect or damage type.
        //  You must specify the save type constant(IP_CONST_SAVEVS_*) that the bonus is
        //  applied to and the bonus that is be applied.  The bonus must be an integer
        //  between 1 and 20.
        public static NWN.ItemProperty ItemPropertyBonusSavingThrowVsX(int nBonusType, int nBonus)
        {
            NWN.Internal.StackPushInteger(nBonus);
            NWN.Internal.StackPushInteger(nBonusType);
            NWN.Internal.CallBuiltIn(652);
            return NWN.Internal.StackPopItemProperty();
        }

        //  Returns Item property saving throw bonus to the base type (ie. will, reflex,
        //  fortitude).  You must specify the base type constant(IP_CONST_SAVEBASETYPE_*)
        //  to which the user gets the bonus and the bonus that he/she will get.  The
        //  bonus must be an integer between 1 and 20.
        public static NWN.ItemProperty ItemPropertyBonusSavingThrow(int nBaseSaveType, int nBonus)
        {
            NWN.Internal.StackPushInteger(nBonus);
            NWN.Internal.StackPushInteger(nBaseSaveType);
            NWN.Internal.CallBuiltIn(653);
            return NWN.Internal.StackPopItemProperty();
        }

        //  Returns Item property keen.  This means a critical threat range of 19-20 on a
        //  weapon will be increased to 17-20 etc.
        public static NWN.ItemProperty ItemPropertyKeen()
        {
            NWN.Internal.CallBuiltIn(654);
            return NWN.Internal.StackPopItemProperty();
        }

        //  Returns Item property light.  You must specify the intesity constant of the
        //  light(IP_CONST_LIGHTBRIGHTNESS_*) and the color constant of the light
        //  (IP_CONST_LIGHTCOLOR_*).
        public static NWN.ItemProperty ItemPropertyLight(int nBrightness, int nColor)
        {
            NWN.Internal.StackPushInteger(nColor);
            NWN.Internal.StackPushInteger(nBrightness);
            NWN.Internal.CallBuiltIn(655);
            return NWN.Internal.StackPopItemProperty();
        }

        //  Returns Item property Max range strength modification (ie. mighty).  You must
        //  specify the maximum modifier for strength that is allowed on a ranged weapon.
        //  The modifier must be a positive integer between 1 and 20.
        public static NWN.ItemProperty ItemPropertyMaxRangeStrengthMod(int nModifier)
        {
            NWN.Internal.StackPushInteger(nModifier);
            NWN.Internal.CallBuiltIn(656);
            return NWN.Internal.StackPopItemProperty();
        }

        //  Returns Item property no damage.  This means the weapon will do no damage in
        //  combat.
        public static NWN.ItemProperty ItemPropertyNoDamage()
        {
            NWN.Internal.CallBuiltIn(657);
            return NWN.Internal.StackPopItemProperty();
        }

        //  Returns Item property on hit -> do effect property.  You must specify the on
        //  hit property constant(IP_CONST_ONHIT_*) and the save DC constant(IP_CONST_ONHIT_SAVEDC_*).
        //  Some of the item properties require a special parameter as well.  If the
        //  property does not require one you may leave out the last one.  The list of
        //  the ones with 3 parameters and what they are are as follows:
        //       ABILITYDRAIN      :nSpecial is the ability it is to drain.
        //                          constant(IP_CONST_ABILITY_*)
        //       BLINDNESS         :nSpecial is the duration/percentage of effecting victim.
        //                          constant(IP_CONST_ONHIT_DURATION_*)
        //       CONFUSION         :nSpecial is the duration/percentage of effecting victim.
        //                          constant(IP_CONST_ONHIT_DURATION_*)
        //       DAZE              :nSpecial is the duration/percentage of effecting victim.
        //                          constant(IP_CONST_ONHIT_DURATION_*)
        //       DEAFNESS          :nSpecial is the duration/percentage of effecting victim.
        //                          constant(IP_CONST_ONHIT_DURATION_*)
        //       DISEASE           :nSpecial is the type of desease that will effect the victim.
        //                          constant(DISEASE_*)
        //       DOOM              :nSpecial is the duration/percentage of effecting victim.
        //                          constant(IP_CONST_ONHIT_DURATION_*)
        //       FEAR              :nSpecial is the duration/percentage of effecting victim.
        //                          constant(IP_CONST_ONHIT_DURATION_*)
        //       HOLD              :nSpecial is the duration/percentage of effecting victim.
        //                          constant(IP_CONST_ONHIT_DURATION_*)
        //       ITEMPOISON        :nSpecial is the type of poison that will effect the victim.
        //                          constant(IP_CONST_POISON_*)
        //       SILENCE           :nSpecial is the duration/percentage of effecting victim.
        //                          constant(IP_CONST_ONHIT_DURATION_*)
        //       SLAYRACE          :nSpecial is the race that will be slain.
        //                          constant(IP_CONST_RACIALTYPE_*)
        //       SLAYALIGNMENTGROUP:nSpecial is the alignment group that will be slain(ie. chaotic).
        //                          constant(IP_CONST_ALIGNMENTGROUP_*)
        //       SLAYALIGNMENT     :nSpecial is the specific alignment that will be slain.
        //                          constant(IP_CONST_ALIGNMENT_*)
        //       SLEEP             :nSpecial is the duration/percentage of effecting victim.
        //                          constant(IP_CONST_ONHIT_DURATION_*)
        //       SLOW              :nSpecial is the duration/percentage of effecting victim.
        //                          constant(IP_CONST_ONHIT_DURATION_*)
        //       STUN              :nSpecial is the duration/percentage of effecting victim.
        //                          constant(IP_CONST_ONHIT_DURATION_*)
        public static NWN.ItemProperty ItemPropertyOnHitProps(int nProperty, int nSaveDC, int nSpecial = 0)
        {
            NWN.Internal.StackPushInteger(nSpecial);
            NWN.Internal.StackPushInteger(nSaveDC);
            NWN.Internal.StackPushInteger(nProperty);
            NWN.Internal.CallBuiltIn(658);
            return NWN.Internal.StackPopItemProperty();
        }

        //  Returns Item property reduced saving throw vs. an effect or damage type.  You must
        //  specify the constant to which the penalty applies(IP_CONST_SAVEVS_*) and the
        //  penalty to be applied.  The penalty must be a POSITIVE integer between 1 and 20
        //  (ie. 1 = -1).
        public static NWN.ItemProperty ItemPropertyReducedSavingThrowVsX(int nBaseSaveType, int nPenalty)
        {
            NWN.Internal.StackPushInteger(nPenalty);
            NWN.Internal.StackPushInteger(nBaseSaveType);
            NWN.Internal.CallBuiltIn(659);
            return NWN.Internal.StackPopItemProperty();
        }

        //  Returns Item property reduced saving to base type.  You must specify the base
        //  type to which the penalty applies (ie. will, reflex, or fortitude) and the penalty
        //  to be applied.  The constant for the base type starts with (IP_CONST_SAVEBASETYPE_*).
        //  The penalty must be a POSITIVE integer between 1 and 20 (ie. 1 = -1).
        public static NWN.ItemProperty ItemPropertyReducedSavingThrow(int nBonusType, int nPenalty)
        {
            NWN.Internal.StackPushInteger(nPenalty);
            NWN.Internal.StackPushInteger(nBonusType);
            NWN.Internal.CallBuiltIn(660);
            return NWN.Internal.StackPopItemProperty();
        }

        //  Returns Item property regeneration.  You must specify the regeneration amount.
        //  The amount must be an integer between 1 and 20.
        public static NWN.ItemProperty ItemPropertyRegeneration(int nRegenAmount)
        {
            NWN.Internal.StackPushInteger(nRegenAmount);
            NWN.Internal.CallBuiltIn(661);
            return NWN.Internal.StackPopItemProperty();
        }

        //  Returns Item property skill bonus.  You must specify the skill to which the user
        //  will get a bonus(SKILL_*) and the amount of the bonus.  The bonus amount must
        //  be an integer between 1 and 50.
        public static NWN.ItemProperty ItemPropertySkillBonus(int nSkill, int nBonus)
        {
            NWN.Internal.StackPushInteger(nBonus);
            NWN.Internal.StackPushInteger(nSkill);
            NWN.Internal.CallBuiltIn(662);
            return NWN.Internal.StackPopItemProperty();
        }

        //  Returns Item property spell immunity vs. specific spell.  You must specify the
        //  spell to which the user will be immune(IP_CONST_IMMUNITYSPELL_*).
        public static NWN.ItemProperty ItemPropertySpellImmunitySpecific(int nSpell)
        {
            NWN.Internal.StackPushInteger(nSpell);
            NWN.Internal.CallBuiltIn(663);
            return NWN.Internal.StackPopItemProperty();
        }

        //  Returns Item property spell immunity vs. spell school.  You must specify the
        //  school to which the user will be immune(IP_CONST_SPELLSCHOOL_*).
        public static NWN.ItemProperty ItemPropertySpellImmunitySchool(int nSchool)
        {
            NWN.Internal.StackPushInteger(nSchool);
            NWN.Internal.CallBuiltIn(664);
            return NWN.Internal.StackPopItemProperty();
        }

        //  Returns Item property Thieves tools.  You must specify the modifier you wish
        //  the tools to have.  The modifier must be an integer between 1 and 12.
        public static NWN.ItemProperty ItemPropertyThievesTools(int nModifier)
        {
            NWN.Internal.StackPushInteger(nModifier);
            NWN.Internal.CallBuiltIn(665);
            return NWN.Internal.StackPopItemProperty();
        }

        //  Returns Item property Attack bonus.  You must specify an attack bonus.  The bonus
        //  must be an integer between 1 and 20.
        public static NWN.ItemProperty ItemPropertyAttackBonus(int nBonus)
        {
            NWN.Internal.StackPushInteger(nBonus);
            NWN.Internal.CallBuiltIn(666);
            return NWN.Internal.StackPopItemProperty();
        }

        //  Returns Item property Attack bonus vs. alignment group.  You must specify the
        //  alignment group constant(IP_CONST_ALIGNMENTGROUP_*) and the attack bonus.  The
        //  bonus must be an integer between 1 and 20.
        public static NWN.ItemProperty ItemPropertyAttackBonusVsAlign(int nAlignGroup, int nBonus)
        {
            NWN.Internal.StackPushInteger(nBonus);
            NWN.Internal.StackPushInteger(nAlignGroup);
            NWN.Internal.CallBuiltIn(667);
            return NWN.Internal.StackPopItemProperty();
        }

        //  Returns Item property attack bonus vs. racial group.  You must specify the
        //  racial group constant(IP_CONST_RACIALTYPE_*) and the attack bonus.  The bonus
        //  must be an integer between 1 and 20.
        public static NWN.ItemProperty ItemPropertyAttackBonusVsRace(int nRace, int nBonus)
        {
            NWN.Internal.StackPushInteger(nBonus);
            NWN.Internal.StackPushInteger(nRace);
            NWN.Internal.CallBuiltIn(668);
            return NWN.Internal.StackPopItemProperty();
        }

        //  Returns Item property attack bonus vs. a specific alignment.  You must specify
        //  the alignment you want the bonus to work against(IP_CONST_ALIGNMENT_*) and the
        //  attack bonus.  The bonus must be an integer between 1 and 20.
        public static NWN.ItemProperty ItemPropertyAttackBonusVsSAlign(int nAlignment, int nBonus)
        {
            NWN.Internal.StackPushInteger(nBonus);
            NWN.Internal.StackPushInteger(nAlignment);
            NWN.Internal.CallBuiltIn(669);
            return NWN.Internal.StackPopItemProperty();
        }

        //  Returns Item property attack penalty.  You must specify the attack penalty.
        //  The penalty must be a POSITIVE integer between 1 and 5 (ie. 1 = -1).
        public static NWN.ItemProperty ItemPropertyAttackPenalty(int nPenalty)
        {
            NWN.Internal.StackPushInteger(nPenalty);
            NWN.Internal.CallBuiltIn(670);
            return NWN.Internal.StackPopItemProperty();
        }

        //  Returns Item property unlimited ammo.  If you leave the parameter field blank
        //  it will be just a normal bolt, arrow, or bullet.  However you may specify that
        //  you want the ammunition to do special damage (ie. +1d6 Fire, or +1 enhancement
        //  bonus).  For this parmeter you use the constants beginning with:
        //       (IP_CONST_UNLIMITEDAMMO_*).
        public static NWN.ItemProperty ItemPropertyUnlimitedAmmo(int nAmmoDamage = IP_CONST_UNLIMITEDAMMO_BASIC)
        {
            NWN.Internal.StackPushInteger(nAmmoDamage);
            NWN.Internal.CallBuiltIn(671);
            return NWN.Internal.StackPopItemProperty();
        }

        //  Returns Item property limit use by alignment group.  You must specify the
        //  alignment group(s) that you want to be able to use this item(IP_CONST_ALIGNMENTGROUP_*).
        public static NWN.ItemProperty ItemPropertyLimitUseByAlign(int nAlignGroup)
        {
            NWN.Internal.StackPushInteger(nAlignGroup);
            NWN.Internal.CallBuiltIn(672);
            return NWN.Internal.StackPopItemProperty();
        }

        //  Returns Item property limit use by class.  You must specify the class(es) who
        //  are able to use this item(IP_CONST_CLASS_*).
        public static NWN.ItemProperty ItemPropertyLimitUseByClass(int nClass)
        {
            NWN.Internal.StackPushInteger(nClass);
            NWN.Internal.CallBuiltIn(673);
            return NWN.Internal.StackPopItemProperty();
        }

        //  Returns Item property limit use by race.  You must specify the race(s) who are
        //  allowed to use this item(IP_CONST_RACIALTYPE_*).
        public static NWN.ItemProperty ItemPropertyLimitUseByRace(int nRace)
        {
            NWN.Internal.StackPushInteger(nRace);
            NWN.Internal.CallBuiltIn(674);
            return NWN.Internal.StackPopItemProperty();
        }

        //  Returns Item property limit use by specific alignment.  You must specify the
        //  alignment(s) of those allowed to use the item(IP_CONST_ALIGNMENT_*).
        public static NWN.ItemProperty ItemPropertyLimitUseBySAlign(int nAlignment)
        {
            NWN.Internal.StackPushInteger(nAlignment);
            NWN.Internal.CallBuiltIn(675);
            return NWN.Internal.StackPopItemProperty();
        }

        //  replace this function it does nothing.
        public static NWN.ItemProperty BadBadReplaceMeThisDoesNothing()
        {
            NWN.Internal.CallBuiltIn(676);
            return NWN.Internal.StackPopItemProperty();
        }

        //  Returns Item property vampiric regeneration.  You must specify the amount of
        //  regeneration.  The regen amount must be an integer between 1 and 20.
        public static NWN.ItemProperty ItemPropertyVampiricRegeneration(int nRegenAmount)
        {
            NWN.Internal.StackPushInteger(nRegenAmount);
            NWN.Internal.CallBuiltIn(677);
            return NWN.Internal.StackPopItemProperty();
        }

        //  Returns Item property Trap.  You must specify the trap level constant
        //  (IP_CONST_TRAPSTRENGTH_*) and the trap type constant(IP_CONST_TRAPTYPE_*).
        public static NWN.ItemProperty ItemPropertyTrap(int nTrapLevel, int nTrapType)
        {
            NWN.Internal.StackPushInteger(nTrapType);
            NWN.Internal.StackPushInteger(nTrapLevel);
            NWN.Internal.CallBuiltIn(678);
            return NWN.Internal.StackPopItemProperty();
        }

        //  Returns Item property true seeing.
        public static NWN.ItemProperty ItemPropertyTrueSeeing()
        {
            NWN.Internal.CallBuiltIn(679);
            return NWN.Internal.StackPopItemProperty();
        }

        //  Returns Item property Monster on hit apply effect property.  You must specify
        //  the property that you want applied on hit.  There are some properties that
        //  require an additional special parameter to be specified.  The others that
        //  don't require any additional parameter you may just put in the one.  The
        //  special cases are as follows:
        //       ABILITYDRAIN:nSpecial is the ability to drain.
        //                    constant(IP_CONST_ABILITY_*)
        //       DISEASE     :nSpecial is the disease that you want applied.
        //                    constant(DISEASE_*)
        //       LEVELDRAIN  :nSpecial is the number of levels that you want drained.
        //                    integer between 1 and 5.
        //       POISON      :nSpecial is the type of poison that will effect the victim.
        //                    constant(IP_CONST_POISON_*)
        //       WOUNDING    :nSpecial is the amount of wounding.
        //                    integer between 1 and 5.
        //  NOTE: Any that do not appear in the above list do not require the second
        //        parameter.
        //  NOTE: These can only be applied to monster NATURAL weapons (ie. bite, claw,
        //        gore, and slam).  IT WILL NOT WORK ON NORMAL WEAPONS.
        public static NWN.ItemProperty ItemPropertyOnMonsterHitProperties(int nProperty, int nSpecial = 0)
        {
            NWN.Internal.StackPushInteger(nSpecial);
            NWN.Internal.StackPushInteger(nProperty);
            NWN.Internal.CallBuiltIn(680);
            return NWN.Internal.StackPopItemProperty();
        }

        //  Returns Item property turn resistance.  You must specify the resistance bonus.
        //  The bonus must be an integer between 1 and 50.
        public static NWN.ItemProperty ItemPropertyTurnResistance(int nModifier)
        {
            NWN.Internal.StackPushInteger(nModifier);
            NWN.Internal.CallBuiltIn(681);
            return NWN.Internal.StackPopItemProperty();
        }

        //  Returns Item property Massive Critical.  You must specify the extra damage
        //  constant(IP_CONST_DAMAGEBONUS_*) of the criticals.
        public static NWN.ItemProperty ItemPropertyMassiveCritical(int nDamage)
        {
            NWN.Internal.StackPushInteger(nDamage);
            NWN.Internal.CallBuiltIn(682);
            return NWN.Internal.StackPopItemProperty();
        }

        //  Returns Item property free action.
        public static NWN.ItemProperty ItemPropertyFreeAction()
        {
            NWN.Internal.CallBuiltIn(683);
            return NWN.Internal.StackPopItemProperty();
        }

        //  Returns Item property monster damage.  You must specify the amount of damage
        //  the monster's attack will do(IP_CONST_MONSTERDAMAGE_*).
        //  NOTE: These can only be applied to monster NATURAL weapons (ie. bite, claw,
        //        gore, and slam).  IT WILL NOT WORK ON NORMAL WEAPONS.
        public static NWN.ItemProperty ItemPropertyMonsterDamage(int nDamage)
        {
            NWN.Internal.StackPushInteger(nDamage);
            NWN.Internal.CallBuiltIn(684);
            return NWN.Internal.StackPopItemProperty();
        }

        //  Returns Item property immunity to spell level.  You must specify the level of
        //  which that and below the user will be immune.  The level must be an integer
        //  between 1 and 9.  By putting in a 3 it will mean the user is immune to all
        //  3rd level and lower spells.
        public static NWN.ItemProperty ItemPropertyImmunityToSpellLevel(int nLevel)
        {
            NWN.Internal.StackPushInteger(nLevel);
            NWN.Internal.CallBuiltIn(685);
            return NWN.Internal.StackPopItemProperty();
        }

        //  Returns Item property special walk.  If no parameters are specified it will
        //  automatically use the zombie walk.  This will apply the special walk animation
        //  to the user.
        public static NWN.ItemProperty ItemPropertySpecialWalk(int nWalkType = 0)
        {
            NWN.Internal.StackPushInteger(nWalkType);
            NWN.Internal.CallBuiltIn(686);
            return NWN.Internal.StackPopItemProperty();
        }

        //  Returns Item property healers kit.  You must specify the level of the kit.
        //  The modifier must be an integer between 1 and 12.
        public static NWN.ItemProperty ItemPropertyHealersKit(int nModifier)
        {
            NWN.Internal.StackPushInteger(nModifier);
            NWN.Internal.CallBuiltIn(687);
            return NWN.Internal.StackPopItemProperty();
        }

        //  Returns Item property weight increase.  You must specify the weight increase
        //  constant(IP_CONST_WEIGHTINCREASE_*).
        public static NWN.ItemProperty ItemPropertyWeightIncrease(int nWeight)
        {
            NWN.Internal.StackPushInteger(nWeight);
            NWN.Internal.CallBuiltIn(688);
            return NWN.Internal.StackPopItemProperty();
        }

        //  ***********************  END OF ITEM PROPERTY FUNCTIONS  **************************
        //  Returns true if 1d20 roll + skill rank is greater than or equal to difficulty
        //  - oTarget: the creature using the skill
        //  - nSkill: the skill being used
        //  - nDifficulty: Difficulty class of skill
        public static int GetIsSkillSuccessful(NWN.Object oTarget, int nSkill, int nDifficulty)
        {
            NWN.Internal.StackPushInteger(nDifficulty);
            NWN.Internal.StackPushInteger(nSkill);
            NWN.Internal.StackPushObject(oTarget, false);
            NWN.Internal.CallBuiltIn(689);
            return NWN.Internal.StackPopInteger();
        }

        //  Creates an effect that inhibits spells
        //  - nPercent - percentage of failure
        //  - nSpellSchool - the school of spells affected.
        public static NWN.Effect EffectSpellFailure(int nPercent = 100, int nSpellSchool = SPELL_SCHOOL_GENERAL)
        {
            NWN.Internal.StackPushInteger(nSpellSchool);
            NWN.Internal.StackPushInteger(nPercent);
            NWN.Internal.CallBuiltIn(690);
            return NWN.Internal.StackPopEffect();
        }

        //  Causes the object to instantly speak a translated string.
        //  (not an action, not blocked when uncommandable)
        //  - nStrRef: Reference of the string in the talk table
        //  - nTalkVolume: TALKVOLUME_*
        public static void SpeakStringByStrRef(int nStrRef, int nTalkVolume = TALKVOLUME_TALK)
        {
            NWN.Internal.StackPushInteger(nTalkVolume);
            NWN.Internal.StackPushInteger(nStrRef);
            NWN.Internal.CallBuiltIn(691);
        }

        //  Sets the given creature into cutscene mode.  This prevents the player from
        //  using the GUI and camera controls.
        //  - oCreature: creature in a cutscene
        //  - nInCutscene: TRUE to move them into cutscene, FALSE to remove cutscene mode
        //  - nLeftClickingEnabled: TRUE to allow the user to interact with the game world using the left mouse button only.
        //                          FALSE to stop the user from interacting with the game world.
        //  Note: SetCutsceneMode(oPlayer, TRUE) will also make the player 'plot' (unkillable).
        //  SetCutsceneMode(oPlayer, FALSE) will restore the player's plot flag to what it
        //  was when SetCutsceneMode(oPlayer, TRUE) was called.
        public static void SetCutsceneMode(NWN.Object oCreature, int nInCutscene = TRUE, int nLeftClickingEnabled = FALSE)
        {
            NWN.Internal.StackPushInteger(nLeftClickingEnabled);
            NWN.Internal.StackPushInteger(nInCutscene);
            NWN.Internal.StackPushObject(oCreature, false);
            NWN.Internal.CallBuiltIn(692);
        }

        //  Gets the last player character to cancel from a cutscene.
        public static NWN.Object GetLastPCToCancelCutscene()
        {
            NWN.Internal.CallBuiltIn(693);
            return NWN.Internal.StackPopObject();
        }

        //  Gets the length of the specified wavefile, in seconds
        //  Only works for sounds used for dialog.
        public static float GetDialogSoundLength(int nStrRef)
        {
            NWN.Internal.StackPushInteger(nStrRef);
            NWN.Internal.CallBuiltIn(694);
            return NWN.Internal.StackPopFloat();
        }

        //  Fades the screen for the given creature/player from black to regular screen
        //  - oCreature: creature controlled by player that should fade from black
        public static void FadeFromBlack(NWN.Object oCreature, float fSpeed = FADE_SPEED_MEDIUM)
        {
            NWN.Internal.StackPushFloat(fSpeed);
            NWN.Internal.StackPushObject(oCreature, false);
            NWN.Internal.CallBuiltIn(695);
        }

        //  Fades the screen for the given creature/player from regular screen to black
        //  - oCreature: creature controlled by player that should fade to black
        public static void FadeToBlack(NWN.Object oCreature, float fSpeed = FADE_SPEED_MEDIUM)
        {
            NWN.Internal.StackPushFloat(fSpeed);
            NWN.Internal.StackPushObject(oCreature, false);
            NWN.Internal.CallBuiltIn(696);
        }

        //  Removes any fading or black screen.
        //  - oCreature: creature controlled by player that should be cleared
        public static void StopFade(NWN.Object oCreature)
        {
            NWN.Internal.StackPushObject(oCreature, false);
            NWN.Internal.CallBuiltIn(697);
        }

        //  Sets the screen to black.  Can be used in preparation for a fade-in (FadeFromBlack)
        //  Can be cleared by either doing a FadeFromBlack, or by calling StopFade.
        //  - oCreature: creature controlled by player that should see black screen
        public static void BlackScreen(NWN.Object oCreature)
        {
            NWN.Internal.StackPushObject(oCreature, false);
            NWN.Internal.CallBuiltIn(698);
        }

        //  Returns the base attach bonus for the given creature.
        public static int GetBaseAttackBonus(NWN.Object oCreature)
        {
            NWN.Internal.StackPushObject(oCreature, false);
            NWN.Internal.CallBuiltIn(699);
            return NWN.Internal.StackPopInteger();
        }

        //  Set a creature's immortality flag.
        //  -oCreature: creature affected
        //  -bImmortal: TRUE = creature is immortal and cannot be killed (but still takes damage)
        //              FALSE = creature is not immortal and is damaged normally.
        //  This scripting command only works on Creature objects.
        public static void SetImmortal(NWN.Object oCreature, int bImmortal)
        {
            NWN.Internal.StackPushInteger(bImmortal);
            NWN.Internal.StackPushObject(oCreature, false);
            NWN.Internal.CallBuiltIn(700);
        }

        //  Open's this creature's inventory panel for this player
        //  - oCreature: creature to view
        //  - oPlayer: the owner of this creature will see the panel pop up
        //  * DM's can view any creature's inventory
        //  * Players can view their own inventory, or that of their henchman, familiar or animal companion
        public static void OpenInventory(NWN.Object oCreature, NWN.Object oPlayer)
        {
            NWN.Internal.StackPushObject(oPlayer, false);
            NWN.Internal.StackPushObject(oCreature, false);
            NWN.Internal.CallBuiltIn(701);
        }

        //  Stores the current camera mode and position so that it can be restored (using
        //  RestoreCameraFacing())
        public static void StoreCameraFacing()
        {
            NWN.Internal.CallBuiltIn(702);
        }

        //  Restores the camera mode and position to what they were last time StoreCameraFacing
        //  was called.  RestoreCameraFacing can only be called once, and must correspond to a
        //  previous call to StoreCameraFacing.
        public static void RestoreCameraFacing()
        {
            NWN.Internal.CallBuiltIn(703);
        }

        //  Levels up a creature using default settings.
        //  If successfull it returns the level the creature now is, or 0 if it fails.
        //  If you want to give them a different level (ie: Give a Fighter a level of Wizard)
        //     you can specify that in the nClass.
        //  However, if you specify a class to which the creature no package specified,
        //    they will use the default package for that class for their levelup choices.
        //    (ie: no Barbarian Savage/Wizard Divination combinations)
        //  If you turn on bReadyAllSpells, all memorized spells will be ready to cast without resting.
        //  if nPackage is PACKAGE_INVALID then it will use the starting package assigned to that class or just the class package
        public static int LevelUpHenchman(NWN.Object oCreature, int nClass = CLASS_TYPE_INVALID, int bReadyAllSpells = FALSE, int nPackage = PACKAGE_INVALID)
        {
            NWN.Internal.StackPushInteger(nPackage);
            NWN.Internal.StackPushInteger(bReadyAllSpells);
            NWN.Internal.StackPushInteger(nClass);
            NWN.Internal.StackPushObject(oCreature, false);
            NWN.Internal.CallBuiltIn(704);
            return NWN.Internal.StackPopInteger();
        }

        //  Sets the droppable flag on an item
        //  - oItem: the item to change
        //  - bDroppable: TRUE or FALSE, whether the item should be droppable
        //  Droppable items will appear on a creature's remains when the creature is killed.
        public static void SetDroppableFlag(NWN.Object oItem, int bDroppable)
        {
            NWN.Internal.StackPushInteger(bDroppable);
            NWN.Internal.StackPushObject(oItem, false);
            NWN.Internal.CallBuiltIn(705);
        }

        //  Gets the weight of an item, or the total carried weight of a creature in tenths
        //  of pounds (as per the baseitems.2da).
        //  - oTarget: the item or creature for which the weight is needed
        public static int GetWeight(NWN.Object oTarget = null)
        {
            NWN.Internal.StackPushObject(oTarget, false);
            NWN.Internal.CallBuiltIn(706);
            return NWN.Internal.StackPopInteger();
        }

        //  Gets the object that acquired the module item.  May be a creature, item, or placeable
        public static NWN.Object GetModuleItemAcquiredBy()
        {
            NWN.Internal.CallBuiltIn(707);
            return NWN.Internal.StackPopObject();
        }

        //  Get the immortal flag on a creature
        public static int GetImmortal(NWN.Object oTarget = null)
        {
            NWN.Internal.StackPushObject(oTarget, false);
            NWN.Internal.CallBuiltIn(708);
            return NWN.Internal.StackPopInteger();
        }

        //  Does a single attack on every hostile creature within 10ft. of the attacker
        //  and determines damage accordingly.  If the attacker has a ranged weapon
        //  equipped, this will have no effect.
        //  ** NOTE ** This is meant to be called inside the spell script for whirlwind
        //  attack, it is not meant to be used to queue up a new whirlwind attack.  To do
        //  that you need to call ActionUseFeat(FEAT_WHIRLWIND_ATTACK, oEnemy)
        //  - int bDisplayFeedback: TRUE or FALSE, whether or not feedback should be
        //    displayed
        //  - int bImproved: If TRUE, the improved version of whirlwind is used
        public static void DoWhirlwindAttack(int bDisplayFeedback = TRUE, int bImproved = FALSE)
        {
            NWN.Internal.StackPushInteger(bImproved);
            NWN.Internal.StackPushInteger(bDisplayFeedback);
            NWN.Internal.CallBuiltIn(709);
        }

        //  Gets a value from a 2DA file on the server and returns it as a string
        //  avoid using this function in loops
        //  - s2DA: the name of the 2da file, 16 chars max
        //  - sColumn: the name of the column in the 2da
        //  - nRow: the row in the 2da
        //  * returns an empty string if file, row, or column not found
        public static string Get2DAString(string s2DA, string sColumn, int nRow)
        {
            NWN.Internal.StackPushInteger(nRow);
            NWN.Internal.StackPushString(sColumn);
            NWN.Internal.StackPushString(s2DA);
            NWN.Internal.CallBuiltIn(710);
            return NWN.Internal.StackPopString();
        }

        //  Returns an effect of type EFFECT_TYPE_ETHEREAL which works just like EffectSanctuary
        //  except that the observers get no saving throw
        public static NWN.Effect EffectEthereal()
        {
            NWN.Internal.CallBuiltIn(711);
            return NWN.Internal.StackPopEffect();
        }

        //  Gets the current AI Level that the creature is running at.
        //  Returns one of the following:
        //  AI_LEVEL_INVALID, AI_LEVEL_VERY_LOW, AI_LEVEL_LOW, AI_LEVEL_NORMAL, AI_LEVEL_HIGH, AI_LEVEL_VERY_HIGH
        public static int GetAILevel(NWN.Object oTarget = null)
        {
            NWN.Internal.StackPushObject(oTarget, false);
            NWN.Internal.CallBuiltIn(712);
            return NWN.Internal.StackPopInteger();
        }

        //  Sets the current AI Level of the creature to the value specified. Does not work on Players.
        //  The game by default will choose an appropriate AI level for
        //  creatures based on the circumstances that the creature is in.
        //  Explicitly setting an AI level will over ride the game AI settings.
        //  The new setting will last until SetAILevel is called again with the argument AI_LEVEL_DEFAULT.
        //  AI_LEVEL_DEFAULT  - Default setting. The game will take over seting the appropriate AI level when required.
        //  AI_LEVEL_VERY_LOW - Very Low priority, very stupid, but low CPU usage for AI. Typically used when no players are in the area.
        //  AI_LEVEL_LOW      - Low priority, mildly stupid, but slightly more CPU usage for AI. Typically used when not in combat, but a player is in the area.
        //  AI_LEVEL_NORMAL   - Normal priority, average AI, but more CPU usage required for AI. Typically used when creature is in combat.
        //  AI_LEVEL_HIGH     - High priority, smartest AI, but extremely high CPU usage required for AI. Avoid using this. It is most likely only ever needed for cutscenes.
        public static void SetAILevel(NWN.Object oTarget, int nAILevel)
        {
            NWN.Internal.StackPushInteger(nAILevel);
            NWN.Internal.StackPushObject(oTarget, false);
            NWN.Internal.CallBuiltIn(713);
        }

        //  This will return TRUE if the creature running the script is a familiar currently
        //  possessed by his master.
        //  returns FALSE if not or if the creature object is invalid
        public static int GetIsPossessedFamiliar(NWN.Object oCreature)
        {
            NWN.Internal.StackPushObject(oCreature, false);
            NWN.Internal.CallBuiltIn(714);
            return NWN.Internal.StackPopInteger();
        }

        //  This will cause a Player Creature to unpossess his/her familiar.  It will work if run
        //  on the player creature or the possessed familiar.  It does not work in conjunction with
        //  any DM possession.
        public static void UnpossessFamiliar(NWN.Object oCreature)
        {
            NWN.Internal.StackPushObject(oCreature, false);
            NWN.Internal.CallBuiltIn(715);
        }

        //  This will return TRUE if the area is flagged as either interior or underground.
        public static int GetIsAreaInterior(NWN.Object oArea = null)
        {
            NWN.Internal.StackPushObject(oArea, false);
            NWN.Internal.CallBuiltIn(716);
            return NWN.Internal.StackPopInteger();
        }

        //  Send a server message (szMessage) to the oPlayer.
        public static void SendMessageToPCByStrRef(NWN.Object oPlayer, int nStrRef)
        {
            NWN.Internal.StackPushInteger(nStrRef);
            NWN.Internal.StackPushObject(oPlayer, false);
            NWN.Internal.CallBuiltIn(717);
        }

        //  Increment the remaining uses per day for this creature by one.
        //  Total number of feats per day can not exceed the maximum.
        //  - oCreature: creature to modify
        //  - nFeat: constant FEAT_*
        public static void IncrementRemainingFeatUses(NWN.Object oCreature, int nFeat)
        {
            NWN.Internal.StackPushInteger(nFeat);
            NWN.Internal.StackPushObject(oCreature, false);
            NWN.Internal.CallBuiltIn(718);
        }

        //  Force the character of the player specified to be exported to its respective directory
        //  i.e. LocalVault/ServerVault/ etc.
        public static void ExportSingleCharacter(NWN.Object oPlayer)
        {
            NWN.Internal.StackPushObject(oPlayer, false);
            NWN.Internal.CallBuiltIn(719);
        }

        //  This will play a sound that is associated with a stringRef, it will be a mono sound from the location of the object running the command.
        //  if nRunAsAction is off then the sound is forced to play intantly.
        public static void PlaySoundByStrRef(int nStrRef, int nRunAsAction = TRUE)
        {
            NWN.Internal.StackPushInteger(nRunAsAction);
            NWN.Internal.StackPushInteger(nStrRef);
            NWN.Internal.CallBuiltIn(720);
        }

        //  Set the name of oCreature's sub race to sSubRace.
        public static void SetSubRace(NWN.Object oCreature, string sSubRace)
        {
            NWN.Internal.StackPushString(sSubRace);
            NWN.Internal.StackPushObject(oCreature, false);
            NWN.Internal.CallBuiltIn(721);
        }

        //  Set the name of oCreature's Deity to sDeity.
        public static void SetDeity(NWN.Object oCreature, string sDeity)
        {
            NWN.Internal.StackPushString(sDeity);
            NWN.Internal.StackPushObject(oCreature, false);
            NWN.Internal.CallBuiltIn(722);
        }

        //  Returns TRUE if the creature oCreature is currently possessed by a DM character.
        //  Returns FALSE otherwise.
        //  Note: GetIsDMPossessed() will return FALSE if oCreature is the DM character.
        //  To determine if oCreature is a DM character use GetIsDM()
        public static int GetIsDMPossessed(NWN.Object oCreature)
        {
            NWN.Internal.StackPushObject(oCreature, false);
            NWN.Internal.CallBuiltIn(723);
            return NWN.Internal.StackPopInteger();
        }

        //  Gets the current weather conditions for the area oArea.
        //    Returns: WEATHER_CLEAR, WEATHER_RAIN, WEATHER_SNOW, WEATHER_INVALID
        //    Note: If called on an Interior area, this will always return WEATHER_CLEAR.
        public static int GetWeather(NWN.Object oArea)
        {
            NWN.Internal.StackPushObject(oArea, false);
            NWN.Internal.CallBuiltIn(724);
            return NWN.Internal.StackPopInteger();
        }

        //  Returns AREA_NATURAL if the area oArea is natural, AREA_ARTIFICIAL otherwise.
        //  Returns AREA_INVALID, on an error.
        public static int GetIsAreaNatural(NWN.Object oArea)
        {
            NWN.Internal.StackPushObject(oArea, false);
            NWN.Internal.CallBuiltIn(725);
            return NWN.Internal.StackPopInteger();
        }

        //  Returns AREA_ABOVEGROUND if the area oArea is above ground, AREA_UNDERGROUND otherwise.
        //  Returns AREA_INVALID, on an error.
        public static int GetIsAreaAboveGround(NWN.Object oArea)
        {
            NWN.Internal.StackPushObject(oArea, false);
            NWN.Internal.CallBuiltIn(726);
            return NWN.Internal.StackPopInteger();
        }

        //  Use this to get the item last equipped by a player character in OnPlayerEquipItem..
        public static NWN.Object GetPCItemLastEquipped()
        {
            NWN.Internal.CallBuiltIn(727);
            return NWN.Internal.StackPopObject();
        }

        //  Use this to get the player character who last equipped an item in OnPlayerEquipItem..
        public static NWN.Object GetPCItemLastEquippedBy()
        {
            NWN.Internal.CallBuiltIn(728);
            return NWN.Internal.StackPopObject();
        }

        //  Use this to get the item last unequipped by a player character in OnPlayerEquipItem..
        public static NWN.Object GetPCItemLastUnequipped()
        {
            NWN.Internal.CallBuiltIn(729);
            return NWN.Internal.StackPopObject();
        }

        //  Use this to get the player character who last unequipped an item in OnPlayerUnEquipItem..
        public static NWN.Object GetPCItemLastUnequippedBy()
        {
            NWN.Internal.CallBuiltIn(730);
            return NWN.Internal.StackPopObject();
        }

        //  Creates a new copy of an item, while making a single change to the appearance of the item.
        //  Helmet models and simple items ignore iIndex.
        //  iType                            iIndex                              iNewValue
        //  ITEM_APPR_TYPE_SIMPLE_MODEL      [Ignored]                           Model #
        //  ITEM_APPR_TYPE_WEAPON_COLOR      ITEM_APPR_WEAPON_COLOR_*            1-4
        //  ITEM_APPR_TYPE_WEAPON_MODEL      ITEM_APPR_WEAPON_MODEL_*            Model #
        //  ITEM_APPR_TYPE_ARMOR_MODEL       ITEM_APPR_ARMOR_MODEL_*             Model #
        //  ITEM_APPR_TYPE_ARMOR_COLOR       ITEM_APPR_ARMOR_COLOR_* [0]         0-175 [1]
        // 
        //  [0] Alternatively, where ITEM_APPR_TYPE_ARMOR_COLOR is specified, if per-part coloring is
        //  desired, the following equation can be used for nIndex to achieve that:
        // 
        //    ITEM_APPR_ARMOR_NUM_COLORS + (ITEM_APPR_ARMOR_MODEL_ * ITEM_APPR_ARMOR_NUM_COLORS) + ITEM_APPR_ARMOR_COLOR_
        // 
        //  For example, to change the CLOTH1 channel of the torso, nIndex would be:
        // 
        //    6 + (7 * 6) + 2 = 50
        // 
        //  [1] When specifying per-part coloring, the value 255 is allowed and corresponds with the logical
        //  function 'clear colour override', which clears the per-part override for that part.
        public static NWN.Object CopyItemAndModify(NWN.Object oItem, int nType, int nIndex, int nNewValue, int bCopyVars = FALSE)
        {
            NWN.Internal.StackPushInteger(bCopyVars);
            NWN.Internal.StackPushInteger(nNewValue);
            NWN.Internal.StackPushInteger(nIndex);
            NWN.Internal.StackPushInteger(nType);
            NWN.Internal.StackPushObject(oItem, false);
            NWN.Internal.CallBuiltIn(731);
            return NWN.Internal.StackPopObject();
        }

        //  Queries the current value of the appearance settings on an item. The parameters are
        //  identical to those of CopyItemAndModify().
        public static int GetItemAppearance(NWN.Object oItem, int nType, int nIndex)
        {
            NWN.Internal.StackPushInteger(nIndex);
            NWN.Internal.StackPushInteger(nType);
            NWN.Internal.StackPushObject(oItem, false);
            NWN.Internal.CallBuiltIn(732);
            return NWN.Internal.StackPopInteger();
        }

        //  Creates an item property that (when applied to a weapon item) causes a spell to be cast
        //  when a successful strike is made, or (when applied to armor) is struck by an opponent.
        //  - nSpell uses the IP_CONST_ONHIT_CASTSPELL_* constants
        public static NWN.ItemProperty ItemPropertyOnHitCastSpell(int nSpell, int nLevel)
        {
            NWN.Internal.StackPushInteger(nLevel);
            NWN.Internal.StackPushInteger(nSpell);
            NWN.Internal.CallBuiltIn(733);
            return NWN.Internal.StackPopItemProperty();
        }

        //  Returns the SubType number of the item property. See the 2DA files for value definitions.
        public static int GetItemPropertySubType(NWN.ItemProperty iProperty)
        {
            NWN.Internal.StackPushItemProperty(iProperty);
            NWN.Internal.CallBuiltIn(734);
            return NWN.Internal.StackPopInteger();
        }

        //  Gets the status of ACTION_MODE_* modes on a creature.
        public static int GetActionMode(NWN.Object oCreature, int nMode)
        {
            NWN.Internal.StackPushInteger(nMode);
            NWN.Internal.StackPushObject(oCreature, false);
            NWN.Internal.CallBuiltIn(735);
            return NWN.Internal.StackPopInteger();
        }

        //  Sets the status of modes ACTION_MODE_* on a creature.
        public static void SetActionMode(NWN.Object oCreature, int nMode, int nStatus)
        {
            NWN.Internal.StackPushInteger(nStatus);
            NWN.Internal.StackPushInteger(nMode);
            NWN.Internal.StackPushObject(oCreature, false);
            NWN.Internal.CallBuiltIn(736);
        }

        //  Returns the current arcane spell failure factor of a creature
        public static int GetArcaneSpellFailure(NWN.Object oCreature)
        {
            NWN.Internal.StackPushObject(oCreature, false);
            NWN.Internal.CallBuiltIn(737);
            return NWN.Internal.StackPopInteger();
        }

        //  Makes a player examine the object oExamine. This causes the examination
        //  pop-up box to appear for the object specified.
        public static void ActionExamine(NWN.Object oExamine)
        {
            NWN.Internal.StackPushObject(oExamine, false);
            NWN.Internal.CallBuiltIn(738);
        }

        //  Creates a visual effect (ITEM_VISUAL_*) that may be applied to
        //  melee weapons only.
        public static NWN.ItemProperty ItemPropertyVisualEffect(int nEffect)
        {
            NWN.Internal.StackPushInteger(nEffect);
            NWN.Internal.CallBuiltIn(739);
            return NWN.Internal.StackPopItemProperty();
        }

        //  Sets the lootable state of a *living* NPC creature.
        //  This function will *not* work on players or dead creatures.
        public static void SetLootable(NWN.Object oCreature, int bLootable)
        {
            NWN.Internal.StackPushInteger(bLootable);
            NWN.Internal.StackPushObject(oCreature, false);
            NWN.Internal.CallBuiltIn(740);
        }

        //  Returns the lootable state of a creature.
        public static int GetLootable(NWN.Object oCreature)
        {
            NWN.Internal.StackPushObject(oCreature, false);
            NWN.Internal.CallBuiltIn(741);
            return NWN.Internal.StackPopInteger();
        }

        //  Returns the current movement rate factor
        //  of the cutscene 'camera man'.
        //  NOTE: This will be a value between 0.1, 2.0 (10%-200%)
        public static float GetCutsceneCameraMoveRate(NWN.Object oCreature)
        {
            NWN.Internal.StackPushObject(oCreature, false);
            NWN.Internal.CallBuiltIn(742);
            return NWN.Internal.StackPopFloat();
        }

        //  Sets the current movement rate factor for the cutscene
        //  camera man.
        //  NOTE: You can only set values between 0.1, 2.0 (10%-200%)
        public static void SetCutsceneCameraMoveRate(NWN.Object oCreature, float fRate)
        {
            NWN.Internal.StackPushFloat(fRate);
            NWN.Internal.StackPushObject(oCreature, false);
            NWN.Internal.CallBuiltIn(743);
        }

        //  Returns TRUE if the item is cursed and cannot be dropped
        public static int GetItemCursedFlag(NWN.Object oItem)
        {
            NWN.Internal.StackPushObject(oItem, false);
            NWN.Internal.CallBuiltIn(744);
            return NWN.Internal.StackPopInteger();
        }

        //  When cursed, items cannot be dropped
        public static void SetItemCursedFlag(NWN.Object oItem, int nCursed)
        {
            NWN.Internal.StackPushInteger(nCursed);
            NWN.Internal.StackPushObject(oItem, false);
            NWN.Internal.CallBuiltIn(745);
        }

        //  Sets the maximum number of henchmen
        public static void SetMaxHenchmen(int nNumHenchmen)
        {
            NWN.Internal.StackPushInteger(nNumHenchmen);
            NWN.Internal.CallBuiltIn(746);
        }

        //  Gets the maximum number of henchmen
        public static int GetMaxHenchmen()
        {
            NWN.Internal.CallBuiltIn(747);
            return NWN.Internal.StackPopInteger();
        }

        //  Returns the associate type of the specified creature.
        //  - Returns ASSOCIATE_TYPE_NONE if the creature is not the associate of anyone.
        public static int GetAssociateType(NWN.Object oAssociate)
        {
            NWN.Internal.StackPushObject(oAssociate, false);
            NWN.Internal.CallBuiltIn(748);
            return NWN.Internal.StackPopInteger();
        }

        //  Returns the spell resistance of the specified creature.
        //  - Returns 0 if the creature has no spell resistance or an invalid
        //    creature is passed in.
        public static int GetSpellResistance(NWN.Object oCreature)
        {
            NWN.Internal.StackPushObject(oCreature, false);
            NWN.Internal.CallBuiltIn(749);
            return NWN.Internal.StackPopInteger();
        }

        //  Changes the current Day/Night cycle for this player to night
        //  - oPlayer: which player to change the lighting for
        //  - fTransitionTime: how long the transition should take
        public static void DayToNight(NWN.Object oPlayer, float fTransitionTime = 0.0f)
        {
            NWN.Internal.StackPushFloat(fTransitionTime);
            NWN.Internal.StackPushObject(oPlayer, false);
            NWN.Internal.CallBuiltIn(750);
        }

        //  Changes the current Day/Night cycle for this player to daylight
        //  - oPlayer: which player to change the lighting for
        //  - fTransitionTime: how long the transition should take
        public static void NightToDay(NWN.Object oPlayer, float fTransitionTime = 0.0f)
        {
            NWN.Internal.StackPushFloat(fTransitionTime);
            NWN.Internal.StackPushObject(oPlayer, false);
            NWN.Internal.CallBuiltIn(751);
        }

        //  Returns whether or not there is a direct line of sight
        //  between the two objects. (Not blocked by any geometry).
        // 
        //  PLEASE NOTE: This is an expensive function and may
        //               degrade performance if used frequently.
        public static int LineOfSightObject(NWN.Object oSource, NWN.Object oTarget)
        {
            NWN.Internal.StackPushObject(oTarget, false);
            NWN.Internal.StackPushObject(oSource, false);
            NWN.Internal.CallBuiltIn(752);
            return NWN.Internal.StackPopInteger();
        }

        //  Returns whether or not there is a direct line of sight
        //  between the two vectors. (Not blocked by any geometry).
        // 
        //  This function must be run on a valid object in the area
        //  it will not work on the module or area.
        // 
        //  PLEASE NOTE: This is an expensive function and may
        //               degrade performance if used frequently.
        public static int LineOfSightVector(NWN.Vector? vSource, NWN.Vector? vTarget)
        {
            NWN.Internal.StackPushVector(vTarget);
            NWN.Internal.StackPushVector(vSource);
            NWN.Internal.CallBuiltIn(753);
            return NWN.Internal.StackPopInteger();
        }

        //  Returns the class that the spellcaster cast the
        //  spell as.
        //  - Returns CLASS_TYPE_INVALID if the caster has
        //    no valid class (placeables, etc...)
        public static int GetLastSpellCastClass()
        {
            NWN.Internal.CallBuiltIn(754);
            return NWN.Internal.StackPopInteger();
        }

        //  Sets the number of base attacks for the specified
        //  creatures. The range of values accepted are from
        //  1 to 6
        //  Note: This function does not work on Player Characters
        public static void SetBaseAttackBonus(int nBaseAttackBonus, NWN.Object oCreature = null)
        {
            NWN.Internal.StackPushObject(oCreature, false);
            NWN.Internal.StackPushInteger(nBaseAttackBonus);
            NWN.Internal.CallBuiltIn(755);
        }

        //  Restores the number of base attacks back to it's
        //  original state.
        public static void RestoreBaseAttackBonus(NWN.Object oCreature = null)
        {
            NWN.Internal.StackPushObject(oCreature, false);
            NWN.Internal.CallBuiltIn(756);
        }

        //  Creates a cutscene ghost effect, this will allow creatures
        //  to pathfind through other creatures without bumping into them
        //  for the duration of the effect.
        public static NWN.Effect EffectCutsceneGhost()
        {
            NWN.Internal.CallBuiltIn(757);
            return NWN.Internal.StackPopEffect();
        }

        //  Creates an item property that offsets the effect on arcane spell failure
        //  that a particular item has. Parameters come from the ITEM_PROP_ASF_* group.
        public static NWN.ItemProperty ItemPropertyArcaneSpellFailure(int nModLevel)
        {
            NWN.Internal.StackPushInteger(nModLevel);
            NWN.Internal.CallBuiltIn(758);
            return NWN.Internal.StackPopItemProperty();
        }

        //  Returns the amount of gold a store currently has. -1 indicates it is not using gold.
        //  -2 indicates the store could not be located.
        public static int GetStoreGold(NWN.Object oidStore)
        {
            NWN.Internal.StackPushObject(oidStore, false);
            NWN.Internal.CallBuiltIn(759);
            return NWN.Internal.StackPopInteger();
        }

        //  Sets the amount of gold a store has. -1 means the store does not use gold.
        public static void SetStoreGold(NWN.Object oidStore, int nGold)
        {
            NWN.Internal.StackPushInteger(nGold);
            NWN.Internal.StackPushObject(oidStore, false);
            NWN.Internal.CallBuiltIn(760);
        }

        //  Gets the maximum amount a store will pay for any item. -1 means price unlimited.
        //  -2 indicates the store could not be located.
        public static int GetStoreMaxBuyPrice(NWN.Object oidStore)
        {
            NWN.Internal.StackPushObject(oidStore, false);
            NWN.Internal.CallBuiltIn(761);
            return NWN.Internal.StackPopInteger();
        }

        //  Sets the maximum amount a store will pay for any item. -1 means price unlimited.
        public static void SetStoreMaxBuyPrice(NWN.Object oidStore, int nMaxBuy)
        {
            NWN.Internal.StackPushInteger(nMaxBuy);
            NWN.Internal.StackPushObject(oidStore, false);
            NWN.Internal.CallBuiltIn(762);
        }

        //  Gets the amount a store charges for identifying an item. Default is 100. -1 means
        //  the store will not identify items.
        //  -2 indicates the store could not be located.
        public static int GetStoreIdentifyCost(NWN.Object oidStore)
        {
            NWN.Internal.StackPushObject(oidStore, false);
            NWN.Internal.CallBuiltIn(763);
            return NWN.Internal.StackPopInteger();
        }

        //  Sets the amount a store charges for identifying an item. Default is 100. -1 means
        //  the store will not identify items.
        public static void SetStoreIdentifyCost(NWN.Object oidStore, int nCost)
        {
            NWN.Internal.StackPushInteger(nCost);
            NWN.Internal.StackPushObject(oidStore, false);
            NWN.Internal.CallBuiltIn(764);
        }

        //  Sets the creature's appearance type to the value specified (uses the APPEARANCE_TYPE_XXX constants)
        public static void SetCreatureAppearanceType(NWN.Object oCreature, int nAppearanceType)
        {
            NWN.Internal.StackPushInteger(nAppearanceType);
            NWN.Internal.StackPushObject(oCreature, false);
            NWN.Internal.CallBuiltIn(765);
        }

        //  Returns the default package selected for this creature to level up with
        //  - returns PACKAGE_INVALID if error occurs
        public static int GetCreatureStartingPackage(NWN.Object oCreature)
        {
            NWN.Internal.StackPushObject(oCreature, false);
            NWN.Internal.CallBuiltIn(766);
            return NWN.Internal.StackPopInteger();
        }

        //  Returns an effect that when applied will paralyze the target's legs, rendering
        //  them unable to walk but otherwise unpenalized. This effect cannot be resisted.
        public static NWN.Effect EffectCutsceneImmobilize()
        {
            NWN.Internal.CallBuiltIn(767);
            return NWN.Internal.StackPopEffect();
        }

        //  Is this creature in the given subarea? (trigger, area of effect object, etc..)
        //  This function will tell you if the creature has triggered an onEnter event,
        //  not if it is physically within the space of the subarea
        public static int GetIsInSubArea(NWN.Object oCreature, NWN.Object oSubArea = null)
        {
            NWN.Internal.StackPushObject(oSubArea, false);
            NWN.Internal.StackPushObject(oCreature, false);
            NWN.Internal.CallBuiltIn(768);
            return NWN.Internal.StackPopInteger();
        }

        //  Returns the Cost Table number of the item property. See the 2DA files for value definitions.
        public static int GetItemPropertyCostTable(NWN.ItemProperty iProp)
        {
            NWN.Internal.StackPushItemProperty(iProp);
            NWN.Internal.CallBuiltIn(769);
            return NWN.Internal.StackPopInteger();
        }

        //  Returns the Cost Table value (index of the cost table) of the item property.
        //  See the 2DA files for value definitions.
        public static int GetItemPropertyCostTableValue(NWN.ItemProperty iProp)
        {
            NWN.Internal.StackPushItemProperty(iProp);
            NWN.Internal.CallBuiltIn(770);
            return NWN.Internal.StackPopInteger();
        }

        //  Returns the Param1 number of the item property. See the 2DA files for value definitions.
        public static int GetItemPropertyParam1(NWN.ItemProperty iProp)
        {
            NWN.Internal.StackPushItemProperty(iProp);
            NWN.Internal.CallBuiltIn(771);
            return NWN.Internal.StackPopInteger();
        }

        //  Returns the Param1 value of the item property. See the 2DA files for value definitions.
        public static int GetItemPropertyParam1Value(NWN.ItemProperty iProp)
        {
            NWN.Internal.StackPushItemProperty(iProp);
            NWN.Internal.CallBuiltIn(772);
            return NWN.Internal.StackPopInteger();
        }

        //  Is this creature able to be disarmed? (checks disarm flag on creature, and if
        //  the creature actually has a weapon equipped in their right hand that is droppable)
        public static int GetIsCreatureDisarmable(NWN.Object oCreature)
        {
            NWN.Internal.StackPushObject(oCreature, false);
            NWN.Internal.CallBuiltIn(773);
            return NWN.Internal.StackPopInteger();
        }

        //  Sets whether this item is 'stolen' or not
        public static void SetStolenFlag(NWN.Object oItem, int nStolenFlag)
        {
            NWN.Internal.StackPushInteger(nStolenFlag);
            NWN.Internal.StackPushObject(oItem, false);
            NWN.Internal.CallBuiltIn(774);
        }

        //  Instantly gives this creature the benefits of a rest (restored hitpoints, spells, feats, etc..)
        public static void ForceRest(NWN.Object oCreature)
        {
            NWN.Internal.StackPushObject(oCreature, false);
            NWN.Internal.CallBuiltIn(775);
        }

        //  Forces this player's camera to be set to this height. Setting this value to zero will
        //  restore the camera to the racial default height.
        public static void SetCameraHeight(NWN.Object oPlayer, float fHeight = 0.0f)
        {
            NWN.Internal.StackPushFloat(fHeight);
            NWN.Internal.StackPushObject(oPlayer, false);
            NWN.Internal.CallBuiltIn(776);
        }

        //  Changes the sky that is displayed in the specified area.
        //  nSkyBox = SKYBOX_* constants (associated with skyboxes.2da)
        //  If no valid area (or object) is specified, it uses the area of caller.
        //  If an object other than an area is specified, will use the area that the object is currently in.
        public static void SetSkyBox(int nSkyBox, NWN.Object oArea = null)
        {
            NWN.Internal.StackPushObject(oArea, false);
            NWN.Internal.StackPushInteger(nSkyBox);
            NWN.Internal.CallBuiltIn(777);
        }

        //  Returns the creature's currently set PhenoType (body type).
        public static int GetPhenoType(NWN.Object oCreature)
        {
            NWN.Internal.StackPushObject(oCreature, false);
            NWN.Internal.CallBuiltIn(778);
            return NWN.Internal.StackPopInteger();
        }

        //  Sets the creature's PhenoType (body type) to the type specified.
        //  nPhenoType = PHENOTYPE_NORMAL
        //  nPhenoType = PHENOTYPE_BIG
        //  nPhenoType = PHENOTYPE_CUSTOM* - The custom PhenoTypes should only ever
        //  be used if you have specifically created your own custom content that
        //  requires the use of a new PhenoType and you have specified the appropriate
        //  custom PhenoType in your custom content.
        //  SetPhenoType will only work on part based creature (i.e. the starting
        //  default playable races).
        public static void SetPhenoType(int nPhenoType, NWN.Object oCreature = null)
        {
            NWN.Internal.StackPushObject(oCreature, false);
            NWN.Internal.StackPushInteger(nPhenoType);
            NWN.Internal.CallBuiltIn(779);
        }

        //  Sets the fog color in the area specified.
        //  nFogType = FOG_TYPE_* specifies wether the Sun, Moon, or both fog types are set.
        //  nFogColor = FOG_COLOR_* specifies the color the fog is being set to.
        //  The fog color can also be represented as a hex RGB number if specific color shades
        //  are desired.
        //  The format of a hex specified color would be 0xFFEEDD where
        //  FF would represent the amount of red in the color
        //  EE would represent the amount of green in the color
        //  DD would represent the amount of blue in the color.
        //  If no valid area (or object) is specified, it uses the area of caller.
        //  If an object other than an area is specified, will use the area that the object is currently in.
        public static void SetFogColor(int nFogType, int nFogColor, NWN.Object oArea = null)
        {
            NWN.Internal.StackPushObject(oArea, false);
            NWN.Internal.StackPushInteger(nFogColor);
            NWN.Internal.StackPushInteger(nFogType);
            NWN.Internal.CallBuiltIn(780);
        }

        //  Gets the current cutscene state of the player specified by oCreature.
        //  Returns TRUE if the player is in cutscene mode.
        //  Returns FALSE if the player is not in cutscene mode, or on an error
        //  (such as specifying a non creature object).
        public static int GetCutsceneMode(NWN.Object oCreature = null)
        {
            NWN.Internal.StackPushObject(oCreature, false);
            NWN.Internal.CallBuiltIn(781);
            return NWN.Internal.StackPopInteger();
        }

        //  Gets the skybox that is currently displayed in the specified area.
        //  Returns:
        //      SKYBOX_* constant
        //  If no valid area (or object) is specified, it uses the area of caller.
        //  If an object other than an area is specified, will use the area that the object is currently in.
        public static int GetSkyBox(NWN.Object oArea = null)
        {
            NWN.Internal.StackPushObject(oArea, false);
            NWN.Internal.CallBuiltIn(782);
            return NWN.Internal.StackPopInteger();
        }

        //  Gets the fog color in the area specified.
        //  nFogType specifies wether the Sun, or Moon fog type is returned. 
        //     Valid values for nFogType are FOG_TYPE_SUN or FOG_TYPE_MOON.
        //  If no valid area (or object) is specified, it uses the area of caller.
        //  If an object other than an area is specified, will use the area that the object is currently in.
        public static int GetFogColor(int nFogType, NWN.Object oArea = null)
        {
            NWN.Internal.StackPushObject(oArea, false);
            NWN.Internal.StackPushInteger(nFogType);
            NWN.Internal.CallBuiltIn(783);
            return NWN.Internal.StackPopInteger();
        }

        //  Sets the fog amount in the area specified.
        //  nFogType = FOG_TYPE_* specifies wether the Sun, Moon, or both fog types are set.
        //  nFogAmount = specifies the density that the fog is being set to.
        //  If no valid area (or object) is specified, it uses the area of caller.
        //  If an object other than an area is specified, will use the area that the object is currently in.
        public static void SetFogAmount(int nFogType, int nFogAmount, NWN.Object oArea = null)
        {
            NWN.Internal.StackPushObject(oArea, false);
            NWN.Internal.StackPushInteger(nFogAmount);
            NWN.Internal.StackPushInteger(nFogType);
            NWN.Internal.CallBuiltIn(784);
        }

        //  Gets the fog amount in the area specified.
        //  nFogType = nFogType specifies wether the Sun, or Moon fog type is returned. 
        //     Valid values for nFogType are FOG_TYPE_SUN or FOG_TYPE_MOON.
        //  If no valid area (or object) is specified, it uses the area of caller.
        //  If an object other than an area is specified, will use the area that the object is currently in.
        public static int GetFogAmount(int nFogType, NWN.Object oArea = null)
        {
            NWN.Internal.StackPushObject(oArea, false);
            NWN.Internal.StackPushInteger(nFogType);
            NWN.Internal.CallBuiltIn(785);
            return NWN.Internal.StackPopInteger();
        }

        //  returns TRUE if the item CAN be pickpocketed
        public static int GetPickpocketableFlag(NWN.Object oItem)
        {
            NWN.Internal.StackPushObject(oItem, false);
            NWN.Internal.CallBuiltIn(786);
            return NWN.Internal.StackPopInteger();
        }

        //  Sets the Pickpocketable flag on an item
        //  - oItem: the item to change
        //  - bPickpocketable: TRUE or FALSE, whether the item can be pickpocketed.
        public static void SetPickpocketableFlag(NWN.Object oItem, int bPickpocketable)
        {
            NWN.Internal.StackPushInteger(bPickpocketable);
            NWN.Internal.StackPushObject(oItem, false);
            NWN.Internal.CallBuiltIn(787);
        }

        //  returns the footstep type of the creature specified.
        //  The footstep type determines what the creature's footsteps sound
        //  like when ever they take a step.
        //  returns FOOTSTEP_TYPE_INVALID if used on a non-creature object, or if
        //  used on creature that has no footstep sounds by default (e.g. Will-O'-Wisp).
        public static int GetFootstepType(NWN.Object oCreature = null)
        {
            NWN.Internal.StackPushObject(oCreature, false);
            NWN.Internal.CallBuiltIn(788);
            return NWN.Internal.StackPopInteger();
        }

        //  Sets the footstep type of the creature specified.
        //  Changing a creature's footstep type will change the sound that
        //  its feet make when ever the creature makes takes a step.
        //  By default a creature's footsteps are detemined by the appearance
        //  type of the creature. SetFootstepType() allows you to make a
        //  creature use a difference footstep type than it would use by default
        //  for its given appearance.
        //  - nFootstepType (FOOTSTEP_TYPE_*):
        //       FOOTSTEP_TYPE_NORMAL
        //       FOOTSTEP_TYPE_LARGE
        //       FOOTSTEP_TYPE_DRAGON
        //       FOOTSTEP_TYPE_SoFT
        //       FOOTSTEP_TYPE_HOOF
        //       FOOTSTEP_TYPE_HOOF_LARGE
        //       FOOTSTEP_TYPE_BEETLE
        //       FOOTSTEP_TYPE_SPIDER
        //       FOOTSTEP_TYPE_SKELETON
        //       FOOTSTEP_TYPE_LEATHER_WING
        //       FOOTSTEP_TYPE_FEATHER_WING
        //       FOOTSTEP_TYPE_DEFAULT - Makes the creature use its original default footstep sounds.
        //       FOOTSTEP_TYPE_NONE
        //  - oCreature: the creature to change the footstep sound for.
        public static void SetFootstepType(int nFootstepType, NWN.Object oCreature = null)
        {
            NWN.Internal.StackPushObject(oCreature, false);
            NWN.Internal.StackPushInteger(nFootstepType);
            NWN.Internal.CallBuiltIn(789);
        }

        //  returns the Wing type of the creature specified.
        //       CREATURE_WING_TYPE_NONE
        //       CREATURE_WING_TYPE_DEMON
        //       CREATURE_WING_TYPE_ANGEL
        //       CREATURE_WING_TYPE_BAT
        //       CREATURE_WING_TYPE_DRAGON
        //       CREATURE_WING_TYPE_BUTTERFLY
        //       CREATURE_WING_TYPE_BIRD
        //  returns CREATURE_WING_TYPE_NONE if used on a non-creature object,
        //  if the creature has no wings, or if the creature can not have its
        //  wing type changed in the toolset.
        public static int GetCreatureWingType(NWN.Object oCreature = null)
        {
            NWN.Internal.StackPushObject(oCreature, false);
            NWN.Internal.CallBuiltIn(790);
            return NWN.Internal.StackPopInteger();
        }

        //  Sets the Wing type of the creature specified.
        //  - nWingType (CREATURE_WING_TYPE_*)
        //       CREATURE_WING_TYPE_NONE
        //       CREATURE_WING_TYPE_DEMON
        //       CREATURE_WING_TYPE_ANGEL
        //       CREATURE_WING_TYPE_BAT
        //       CREATURE_WING_TYPE_DRAGON
        //       CREATURE_WING_TYPE_BUTTERFLY
        //       CREATURE_WING_TYPE_BIRD
        //  - oCreature: the creature to change the wing type for.
        //  Note: Only two creature model types will support wings. 
        //  The MODELTYPE for the part based (playable races) 'P' 
        //  and MODELTYPE 'W'in the appearance.2da
        public static void SetCreatureWingType(int nWingType, NWN.Object oCreature = null)
        {
            NWN.Internal.StackPushObject(oCreature, false);
            NWN.Internal.StackPushInteger(nWingType);
            NWN.Internal.CallBuiltIn(791);
        }

        //  returns the model number being used for the body part and creature specified
        //  The model number returned is for the body part when the creature is not wearing
        //  armor (i.e. whether or not the creature is wearing armor does not affect
        //  the return value).
        //  Note: Only works on part based creatures, which is typically restricted to
        //  the playable races (unless some new part based custom content has been 
        //  added to the module).
        // 
        //  returns CREATURE_PART_INVALID if used on a non-creature object,
        //  or if the creature does not use a part based model.
        // 
        //  - nPart (CREATURE_PART_*)
        //       CREATURE_PART_RIGHT_FOOT
        //       CREATURE_PART_LEFT_FOOT
        //       CREATURE_PART_RIGHT_SHIN
        //       CREATURE_PART_LEFT_SHIN
        //       CREATURE_PART_RIGHT_THIGH
        //       CREATURE_PART_LEFT_THIGH
        //       CREATURE_PART_PELVIS
        //       CREATURE_PART_TORSO
        //       CREATURE_PART_BELT
        //       CREATURE_PART_NECK
        //       CREATURE_PART_RIGHT_FOREARM
        //       CREATURE_PART_LEFT_FOREARM
        //       CREATURE_PART_RIGHT_BICEP
        //       CREATURE_PART_LEFT_BICEP
        //       CREATURE_PART_RIGHT_SHOULDER
        //       CREATURE_PART_LEFT_SHOULDER
        //       CREATURE_PART_RIGHT_HAND
        //       CREATURE_PART_LEFT_HAND
        //       CREATURE_PART_HEAD
        public static int GetCreatureBodyPart(int nPart, NWN.Object oCreature = null)
        {
            NWN.Internal.StackPushObject(oCreature, false);
            NWN.Internal.StackPushInteger(nPart);
            NWN.Internal.CallBuiltIn(792);
            return NWN.Internal.StackPopInteger();
        }

        //  Sets the body part model to be used on the creature specified.
        //  The model names for parts need to be in the following format:
        //    p<m/f><race letter><phenotype>_<body part><model number>.mdl
        // 
        //  - nPart (CREATURE_PART_*)
        //       CREATURE_PART_RIGHT_FOOT
        //       CREATURE_PART_LEFT_FOOT
        //       CREATURE_PART_RIGHT_SHIN
        //       CREATURE_PART_LEFT_SHIN
        //       CREATURE_PART_RIGHT_THIGH
        //       CREATURE_PART_LEFT_THIGH
        //       CREATURE_PART_PELVIS
        //       CREATURE_PART_TORSO
        //       CREATURE_PART_BELT
        //       CREATURE_PART_NECK
        //       CREATURE_PART_RIGHT_FOREARM
        //       CREATURE_PART_LEFT_FOREARM
        //       CREATURE_PART_RIGHT_BICEP
        //       CREATURE_PART_LEFT_BICEP
        //       CREATURE_PART_RIGHT_SHOULDER
        //       CREATURE_PART_LEFT_SHOULDER
        //       CREATURE_PART_RIGHT_HAND
        //       CREATURE_PART_LEFT_HAND
        //       CREATURE_PART_HEAD
        //  - nModelNumber: CREATURE_MODEL_TYPE_*
        //       CREATURE_MODEL_TYPE_NONE
        //       CREATURE_MODEL_TYPE_SKIN (not for use on shoulders, pelvis or head).
        //       CREATURE_MODEL_TYPE_TATTOO (for body parts that support tattoos, i.e. not heads/feet/hands).
        //       CREATURE_MODEL_TYPE_UNDEAD (undead model only exists for the right arm parts).
        //  - oCreature: the creature to change the body part for.
        //  Note: Only part based creature appearance types are supported. 
        //  i.e. The model types for the playable races ('P') in the appearance.2da
        public static void SetCreatureBodyPart(int nPart, int nModelNumber, NWN.Object oCreature = null)
        {
            NWN.Internal.StackPushObject(oCreature, false);
            NWN.Internal.StackPushInteger(nModelNumber);
            NWN.Internal.StackPushInteger(nPart);
            NWN.Internal.CallBuiltIn(793);
        }

        //  returns the Tail type of the creature specified.
        //       CREATURE_TAIL_TYPE_NONE
        //       CREATURE_TAIL_TYPE_LIZARD
        //       CREATURE_TAIL_TYPE_BONE
        //       CREATURE_TAIL_TYPE_DEVIL
        //  returns CREATURE_TAIL_TYPE_NONE if used on a non-creature object,
        //  if the creature has no Tail, or if the creature can not have its
        //  Tail type changed in the toolset.
        public static int GetCreatureTailType(NWN.Object oCreature = null)
        {
            NWN.Internal.StackPushObject(oCreature, false);
            NWN.Internal.CallBuiltIn(794);
            return NWN.Internal.StackPopInteger();
        }

        //  Sets the Tail type of the creature specified.
        //  - nTailType (CREATURE_TAIL_TYPE_*)
        //       CREATURE_TAIL_TYPE_NONE
        //       CREATURE_TAIL_TYPE_LIZARD
        //       CREATURE_TAIL_TYPE_BONE
        //       CREATURE_TAIL_TYPE_DEVIL
        //  - oCreature: the creature to change the Tail type for.
        //  Note: Only two creature model types will support Tails. 
        //  The MODELTYPE for the part based (playable) races 'P' 
        //  and MODELTYPE 'T'in the appearance.2da
        public static void SetCreatureTailType(int nTailType, NWN.Object oCreature = null)
        {
            NWN.Internal.StackPushObject(oCreature, false);
            NWN.Internal.StackPushInteger(nTailType);
            NWN.Internal.CallBuiltIn(795);
        }

        //  returns the Hardness of a Door or Placeable object.
        //  - oObject: a door or placeable object.
        //  returns -1 on an error or if used on an object that is
        //  neither a door nor a placeable object.
        public static int GetHardness(NWN.Object oObject = null)
        {
            NWN.Internal.StackPushObject(oObject, false);
            NWN.Internal.CallBuiltIn(796);
            return NWN.Internal.StackPopInteger();
        }

        //  Sets the Hardness of a Door or Placeable object.
        //  - nHardness: must be between 0 and 250.
        //  - oObject: a door or placeable object.
        //  Does nothing if used on an object that is neither
        //  a door nor a placeable.
        public static void SetHardness(int nHardness, NWN.Object oObject = null)
        {
            NWN.Internal.StackPushObject(oObject, false);
            NWN.Internal.StackPushInteger(nHardness);
            NWN.Internal.CallBuiltIn(797);
        }

        //  When set the object can not be opened unless the
        //  opener possesses the required key. The key tag required
        //  can be specified either in the toolset, or by using
        //  the SetLockKeyTag() scripting command.
        //  - oObject: a door, or placeable.
        //  - nKeyRequired: TRUE/FALSE
        public static void SetLockKeyRequired(NWN.Object oObject, int nKeyRequired = TRUE)
        {
            NWN.Internal.StackPushInteger(nKeyRequired);
            NWN.Internal.StackPushObject(oObject, false);
            NWN.Internal.CallBuiltIn(798);
        }

        //  Set the key tag required to open object oObject.
        //  This will only have an effect if the object is set to
        //  "Key required to unlock or lock" either in the toolset
        //  or by using the scripting command SetLockKeyRequired().
        //  - oObject: a door, placeable or trigger.
        //  - sNewKeyTag: the key tag required to open the locked object.
        public static void SetLockKeyTag(NWN.Object oObject, string sNewKeyTag)
        {
            NWN.Internal.StackPushString(sNewKeyTag);
            NWN.Internal.StackPushObject(oObject, false);
            NWN.Internal.CallBuiltIn(799);
        }

        //  Sets whether or not the object can be locked.
        //  - oObject: a door or placeable.
        //  - nLockable: TRUE/FALSE
        public static void SetLockLockable(NWN.Object oObject, int nLockable = TRUE)
        {
            NWN.Internal.StackPushInteger(nLockable);
            NWN.Internal.StackPushObject(oObject, false);
            NWN.Internal.CallBuiltIn(800);
        }

        //  Sets the DC for unlocking the object.
        //  - oObject: a door or placeable object.
        //  - nNewUnlockDC: must be between 0 and 250.
        public static void SetLockUnlockDC(NWN.Object oObject, int nNewUnlockDC)
        {
            NWN.Internal.StackPushInteger(nNewUnlockDC);
            NWN.Internal.StackPushObject(oObject, false);
            NWN.Internal.CallBuiltIn(801);
        }

        //  Sets the DC for locking the object.
        //  - oObject: a door or placeable object.
        //  - nNewLockDC: must be between 0 and 250.
        public static void SetLockLockDC(NWN.Object oObject, int nNewLockDC)
        {
            NWN.Internal.StackPushInteger(nNewLockDC);
            NWN.Internal.StackPushObject(oObject, false);
            NWN.Internal.CallBuiltIn(802);
        }

        //  Sets whether or not the trapped object can be disarmed.
        //  - oTrapObject: a placeable, door or trigger
        //  - nDisarmable: TRUE/FALSE
        public static void SetTrapDisarmable(NWN.Object oTrapObject, int nDisarmable = TRUE)
        {
            NWN.Internal.StackPushInteger(nDisarmable);
            NWN.Internal.StackPushObject(oTrapObject, false);
            NWN.Internal.CallBuiltIn(803);
        }

        //  Sets whether or not the trapped object can be detected.
        //  - oTrapObject: a placeable, door or trigger
        //  - nDetectable: TRUE/FALSE
        //  Note: Setting a trapped object to not be detectable will
        //  not make the trap disappear if it has already been detected.
        public static void SetTrapDetectable(NWN.Object oTrapObject, int nDetectable = TRUE)
        {
            NWN.Internal.StackPushInteger(nDetectable);
            NWN.Internal.StackPushObject(oTrapObject, false);
            NWN.Internal.CallBuiltIn(804);
        }

        //  Sets whether or not the trap is a one-shot trap
        //  (i.e. whether or not the trap resets itself after firing).
        //  - oTrapObject: a placeable, door or trigger
        //  - nOneShot: TRUE/FALSE
        public static void SetTrapOneShot(NWN.Object oTrapObject, int nOneShot = TRUE)
        {
            NWN.Internal.StackPushInteger(nOneShot);
            NWN.Internal.StackPushObject(oTrapObject, false);
            NWN.Internal.CallBuiltIn(805);
        }

        //  Set the tag of the key that will disarm oTrapObject.
        //  - oTrapObject: a placeable, door or trigger
        public static void SetTrapKeyTag(NWN.Object oTrapObject, string sKeyTag)
        {
            NWN.Internal.StackPushString(sKeyTag);
            NWN.Internal.StackPushObject(oTrapObject, false);
            NWN.Internal.CallBuiltIn(806);
        }

        //  Set the DC for disarming oTrapObject.
        //  - oTrapObject: a placeable, door or trigger
        //  - nDisarmDC: must be between 0 and 250.
        public static void SetTrapDisarmDC(NWN.Object oTrapObject, int nDisarmDC)
        {
            NWN.Internal.StackPushInteger(nDisarmDC);
            NWN.Internal.StackPushObject(oTrapObject, false);
            NWN.Internal.CallBuiltIn(807);
        }

        //  Set the DC for detecting oTrapObject.
        //  - oTrapObject: a placeable, door or trigger
        //  - nDetectDC: must be between 0 and 250.
        public static void SetTrapDetectDC(NWN.Object oTrapObject, int nDetectDC)
        {
            NWN.Internal.StackPushInteger(nDetectDC);
            NWN.Internal.StackPushObject(oTrapObject, false);
            NWN.Internal.CallBuiltIn(808);
        }

        //  Creates a square Trap object.
        //  - nTrapType: The base type of trap (TRAP_BASE_TYPE_*)
        //  - lLocation: The location and orientation that the trap will be created at.
        //  - fSize: The size of the trap. Minimum size allowed is 1.0f.
        //  - sTag: The tag of the trap being created.
        //  - nFaction: The faction of the trap (STANDARD_FACTION_*).
        //  - sOnDisarmScript: The OnDisarm script that will fire when the trap is disarmed.
        //                     If "" no script will fire.
        //  - sOnTrapTriggeredScript: The OnTrapTriggered script that will fire when the
        //                            trap is triggered.
        //                            If "" the default OnTrapTriggered script for the trap
        //                            type specified will fire instead (as specified in the
        //                            traps.2da).
        public static NWN.Object CreateTrapAtLocation(int nTrapType, NWN.Location lLocation, float fSize = 2.0f, string sTag = "", int nFaction = STANDARD_FACTION_HOSTILE, string sOnDisarmScript = "", string sOnTrapTriggeredScript = "")
        {
            NWN.Internal.StackPushString(sOnTrapTriggeredScript);
            NWN.Internal.StackPushString(sOnDisarmScript);
            NWN.Internal.StackPushInteger(nFaction);
            NWN.Internal.StackPushString(sTag);
            NWN.Internal.StackPushFloat(fSize);
            NWN.Internal.StackPushLocation(lLocation);
            NWN.Internal.StackPushInteger(nTrapType);
            NWN.Internal.CallBuiltIn(809);
            return NWN.Internal.StackPopObject();
        }

        //  Creates a Trap on the object specified.
        //  - nTrapType: The base type of trap (TRAP_BASE_TYPE_*)
        //  - oObject: The object that the trap will be created on. Works only on Doors and Placeables.
        //  - nFaction: The faction of the trap (STANDARD_FACTION_*).
        //  - sOnDisarmScript: The OnDisarm script that will fire when the trap is disarmed.
        //                     If "" no script will fire.
        //  - sOnTrapTriggeredScript: The OnTrapTriggered script that will fire when the
        //                            trap is triggered.
        //                            If "" the default OnTrapTriggered script for the trap
        //                            type specified will fire instead (as specified in the
        //                            traps.2da).
        //  Note: After creating a trap on an object, you can change the trap's properties
        //        using the various SetTrap* scripting commands by passing in the object
        //        that the trap was created on (i.e. oObject) to any subsequent SetTrap* commands.
        public static void CreateTrapOnObject(int nTrapType, NWN.Object oObject, int nFaction = STANDARD_FACTION_HOSTILE, string sOnDisarmScript = "", string sOnTrapTriggeredScript = "")
        {
            NWN.Internal.StackPushString(sOnTrapTriggeredScript);
            NWN.Internal.StackPushString(sOnDisarmScript);
            NWN.Internal.StackPushInteger(nFaction);
            NWN.Internal.StackPushObject(oObject, false);
            NWN.Internal.StackPushInteger(nTrapType);
            NWN.Internal.CallBuiltIn(810);
        }

        //  Set the Will saving throw value of the Door or Placeable object oObject.
        //  - oObject: a door or placeable object.
        //  - nWillSave: must be between 0 and 250.
        public static void SetWillSavingThrow(NWN.Object oObject, int nWillSave)
        {
            NWN.Internal.StackPushInteger(nWillSave);
            NWN.Internal.StackPushObject(oObject, false);
            NWN.Internal.CallBuiltIn(811);
        }

        //  Set the Reflex saving throw value of the Door or Placeable object oObject.
        //  - oObject: a door or placeable object.
        //  - nReflexSave: must be between 0 and 250.
        public static void SetReflexSavingThrow(NWN.Object oObject, int nReflexSave)
        {
            NWN.Internal.StackPushInteger(nReflexSave);
            NWN.Internal.StackPushObject(oObject, false);
            NWN.Internal.CallBuiltIn(812);
        }

        //  Set the Fortitude saving throw value of the Door or Placeable object oObject.
        //  - oObject: a door or placeable object.
        //  - nFortitudeSave: must be between 0 and 250.
        public static void SetFortitudeSavingThrow(NWN.Object oObject, int nFortitudeSave)
        {
            NWN.Internal.StackPushInteger(nFortitudeSave);
            NWN.Internal.StackPushObject(oObject, false);
            NWN.Internal.CallBuiltIn(813);
        }

        //  returns the resref (TILESET_RESREF_*) of the tileset used to create area oArea.
        //       TILESET_RESREF_BEHOLDER_CAVES
        //       TILESET_RESREF_CASTLE_INTERIOR
        //       TILESET_RESREF_CITY_EXTERIOR
        //       TILESET_RESREF_CITY_INTERIOR
        //       TILESET_RESREF_CRYPT
        //       TILESET_RESREF_DESERT
        //       TILESET_RESREF_DROW_INTERIOR
        //       TILESET_RESREF_DUNGEON
        //       TILESET_RESREF_FOREST
        //       TILESET_RESREF_FROZEN_WASTES
        //       TILESET_RESREF_ILLITHID_INTERIOR
        //       TILESET_RESREF_MICROSET
        //       TILESET_RESREF_MINES_AND_CAVERNS
        //       TILESET_RESREF_RUINS
        //       TILESET_RESREF_RURAL
        //       TILESET_RESREF_RURAL_WINTER
        //       TILESET_RESREF_SEWERS
        //       TILESET_RESREF_UNDERDARK
        //  * returns an empty string on an error.
        public static string GetTilesetResRef(NWN.Object oArea)
        {
            NWN.Internal.StackPushObject(oArea, false);
            NWN.Internal.CallBuiltIn(814);
            return NWN.Internal.StackPopString();
        }

        //  - oTrapObject: a placeable, door or trigger
        //  * Returns TRUE if oTrapObject can be recovered.
        public static int GetTrapRecoverable(NWN.Object oTrapObject)
        {
            NWN.Internal.StackPushObject(oTrapObject, false);
            NWN.Internal.CallBuiltIn(815);
            return NWN.Internal.StackPopInteger();
        }

        //  Sets whether or not the trapped object can be recovered.
        //  - oTrapObject: a placeable, door or trigger
        public static void SetTrapRecoverable(NWN.Object oTrapObject, int nRecoverable = TRUE)
        {
            NWN.Internal.StackPushInteger(nRecoverable);
            NWN.Internal.StackPushObject(oTrapObject, false);
            NWN.Internal.CallBuiltIn(816);
        }

        //  Get the XP scale being used for the module.
        public static int GetModuleXPScale()
        {
            NWN.Internal.CallBuiltIn(817);
            return NWN.Internal.StackPopInteger();
        }

        //  Set the XP scale used by the module.
        //  - nXPScale: The XP scale to be used. Must be between 0 and 200.
        public static void SetModuleXPScale(int nXPScale)
        {
            NWN.Internal.StackPushInteger(nXPScale);
            NWN.Internal.CallBuiltIn(818);
        }

        //  Get the feedback message that will be displayed when trying to unlock the object oObject.
        //  - oObject: a door or placeable.
        //  Returns an empty string "" on an error or if the game's default feedback message is being used
        public static string GetKeyRequiredFeedback(NWN.Object oObject)
        {
            NWN.Internal.StackPushObject(oObject, false);
            NWN.Internal.CallBuiltIn(819);
            return NWN.Internal.StackPopString();
        }

        //  Set the feedback message that is displayed when trying to unlock the object oObject.
        //  This will only have an effect if the object is set to
        //  "Key required to unlock or lock" either in the toolset
        //  or by using the scripting command SetLockKeyRequired().
        //  - oObject: a door or placeable.
        //  - sFeedbackMessage: the string to be displayed in the player's text window.
        //                      to use the game's default message, set sFeedbackMessage to ""
        public static void SetKeyRequiredFeedback(NWN.Object oObject, string sFeedbackMessage)
        {
            NWN.Internal.StackPushString(sFeedbackMessage);
            NWN.Internal.StackPushObject(oObject, false);
            NWN.Internal.CallBuiltIn(820);
        }

        //  - oTrapObject: a placeable, door or trigger
        //  * Returns TRUE if oTrapObject is active
        public static int GetTrapActive(NWN.Object oTrapObject)
        {
            NWN.Internal.StackPushObject(oTrapObject, false);
            NWN.Internal.CallBuiltIn(821);
            return NWN.Internal.StackPopInteger();
        }

        //  Sets whether or not the trap is an active trap
        //  - oTrapObject: a placeable, door or trigger
        //  - nActive: TRUE/FALSE
        //  Notes:
        //  Setting a trap as inactive will not make the
        //  trap disappear if it has already been detected.
        //  Call SetTrapDetectedBy() to make a detected trap disappear.
        //  To make an inactive trap not detectable call SetTrapDetectable()
        public static void SetTrapActive(NWN.Object oTrapObject, int nActive = TRUE)
        {
            NWN.Internal.StackPushInteger(nActive);
            NWN.Internal.StackPushObject(oTrapObject, false);
            NWN.Internal.CallBuiltIn(822);
        }

        //  Locks the player's camera pitch to its current pitch setting,
        //  or unlocks the player's camera pitch.
        //  Stops the player from tilting their camera angle. 
        //  - oPlayer: A player object.
        //  - bLocked: TRUE/FALSE.
        public static void LockCameraPitch(NWN.Object oPlayer, int bLocked = TRUE)
        {
            NWN.Internal.StackPushInteger(bLocked);
            NWN.Internal.StackPushObject(oPlayer, false);
            NWN.Internal.CallBuiltIn(823);
        }

        //  Locks the player's camera distance to its current distance setting,
        //  or unlocks the player's camera distance.
        //  Stops the player from being able to zoom in/out the camera.
        //  - oPlayer: A player object.
        //  - bLocked: TRUE/FALSE.
        public static void LockCameraDistance(NWN.Object oPlayer, int bLocked = TRUE)
        {
            NWN.Internal.StackPushInteger(bLocked);
            NWN.Internal.StackPushObject(oPlayer, false);
            NWN.Internal.CallBuiltIn(824);
        }

        //  Locks the player's camera direction to its current direction,
        //  or unlocks the player's camera direction to enable it to move
        //  freely again.
        //  Stops the player from being able to rotate the camera direction.
        //  - oPlayer: A player object.
        //  - bLocked: TRUE/FALSE.
        public static void LockCameraDirection(NWN.Object oPlayer, int bLocked = TRUE)
        {
            NWN.Internal.StackPushInteger(bLocked);
            NWN.Internal.StackPushObject(oPlayer, false);
            NWN.Internal.CallBuiltIn(825);
        }

        //  Get the last object that default clicked (left clicked) on the placeable object
        //  that is calling this function.
        //  Should only be called from a placeables OnClick event.
        //  * Returns OBJECT_INVALID if it is called by something other than a placeable.
        public static NWN.Object GetPlaceableLastClickedBy()
        {
            NWN.Internal.CallBuiltIn(826);
            return NWN.Internal.StackPopObject();
        }

        //  returns TRUE if the item is flagged as infinite.
        //  - oItem: an item.
        //  The infinite property affects the buying/selling behavior of the item in a store.
        //  An infinite item will still be available to purchase from a store after a player
        //  buys the item (non-infinite items will disappear from the store when purchased).
        public static int GetInfiniteFlag(NWN.Object oItem)
        {
            NWN.Internal.StackPushObject(oItem, false);
            NWN.Internal.CallBuiltIn(827);
            return NWN.Internal.StackPopInteger();
        }

        //  Sets the Infinite flag on an item
        //  - oItem: the item to change
        //  - bInfinite: TRUE or FALSE, whether the item should be Infinite
        //  The infinite property affects the buying/selling behavior of the item in a store.
        //  An infinite item will still be available to purchase from a store after a player
        //  buys the item (non-infinite items will disappear from the store when purchased).
        public static void SetInfiniteFlag(NWN.Object oItem, int bInfinite = TRUE)
        {
            NWN.Internal.StackPushInteger(bInfinite);
            NWN.Internal.StackPushObject(oItem, false);
            NWN.Internal.CallBuiltIn(828);
        }

        //  Gets the size of the area.
        //  - nAreaDimension: The area dimension that you wish to determine.
        //       AREA_HEIGHT
        //       AREA_WIDTH
        //  - oArea: The area that you wish to get the size of.
        //  Returns: The number of tiles that the area is wide/high, or zero on an error.
        //  If no valid area (or object) is specified, it uses the area of the caller.
        //  If an object other than an area is specified, will use the area that the object is currently in.
        public static int GetAreaSize(int nAreaDimension, NWN.Object oArea = null)
        {
            NWN.Internal.StackPushObject(oArea, false);
            NWN.Internal.StackPushInteger(nAreaDimension);
            NWN.Internal.CallBuiltIn(829);
            return NWN.Internal.StackPopInteger();
        }

        //  Set the name of oObject.
        //  - oObject: the object for which you are changing the name (a creature, placeable, item, or door).
        //  - sNewName: the new name that the object will use.
        //  Note: SetName() does not work on player objects.
        //        Setting an object's name to "" will make the object
        //        revert to using the name it had originally before any
        //        SetName() calls were made on the object.
        public static void SetName(NWN.Object oObject, string sNewName = "")
        {
            NWN.Internal.StackPushString(sNewName);
            NWN.Internal.StackPushObject(oObject, false);
            NWN.Internal.CallBuiltIn(830);
        }

        //  Get the PortraitId of oTarget.
        //  - oTarget: the object for which you are getting the portrait Id.
        //  Returns: The Portrait Id number being used for the object oTarget.
        //           The Portrait Id refers to the row number of the Portraits.2da
        //           that this portrait is from.
        //           If a custom portrait is being used, oTarget is a player object,
        //           or on an error returns PORTRAIT_INVALID. In these instances
        //           try using GetPortraitResRef() instead.
        public static int GetPortraitId(NWN.Object oTarget = null)
        {
            NWN.Internal.StackPushObject(oTarget, false);
            NWN.Internal.CallBuiltIn(831);
            return NWN.Internal.StackPopInteger();
        }

        //  Change the portrait of oTarget to use the Portrait Id specified.
        //  - oTarget: the object for which you are changing the portrait.
        //  - nPortraitId: The Id of the new portrait to use. 
        //                 nPortraitId refers to a row in the Portraits.2da
        //  Note: Not all portrait Ids are suitable for use with all object types.
        //        Setting the portrait Id will also cause the portrait ResRef
        //        to be set to the appropriate portrait ResRef for the Id specified.
        public static void SetPortraitId(NWN.Object oTarget, int nPortraitId)
        {
            NWN.Internal.StackPushInteger(nPortraitId);
            NWN.Internal.StackPushObject(oTarget, false);
            NWN.Internal.CallBuiltIn(832);
        }

        //  Get the Portrait ResRef of oTarget.
        //  - oTarget: the object for which you are getting the portrait ResRef.
        //  Returns: The Portrait ResRef being used for the object oTarget.
        //           The Portrait ResRef will not include a trailing size letter.
        public static string GetPortraitResRef(NWN.Object oTarget = null)
        {
            NWN.Internal.StackPushObject(oTarget, false);
            NWN.Internal.CallBuiltIn(833);
            return NWN.Internal.StackPopString();
        }

        //  Change the portrait of oTarget to use the Portrait ResRef specified.
        //  - oTarget: the object for which you are changing the portrait.
        //  - sPortraitResRef: The ResRef of the new portrait to use. 
        //                     The ResRef should not include any trailing size letter ( e.g. po_el_f_09_ ).
        //  Note: Not all portrait ResRefs are suitable for use with all object types.
        //        Setting the portrait ResRef will also cause the portrait Id
        //        to be set to PORTRAIT_INVALID.
        public static void SetPortraitResRef(NWN.Object oTarget, string sPortraitResRef)
        {
            NWN.Internal.StackPushString(sPortraitResRef);
            NWN.Internal.StackPushObject(oTarget, false);
            NWN.Internal.CallBuiltIn(834);
        }

        //  Set oPlaceable's useable object status.
        //  Note: Only works on non-static placeables.
        public static void SetUseableFlag(NWN.Object oPlaceable, int nUseableFlag)
        {
            NWN.Internal.StackPushInteger(nUseableFlag);
            NWN.Internal.StackPushObject(oPlaceable, false);
            NWN.Internal.CallBuiltIn(835);
        }

        //  Get the description of oObject.
        //  - oObject: the object from which you are obtaining the description. 
        //             Can be a creature, item, placeable, door, trigger or module object.
        //  - bOriginalDescription:  if set to true any new description specified via a SetDescription scripting command
        //                    is ignored and the original object's description is returned instead.
        //  - bIdentified: If oObject is an item, setting this to TRUE will return the identified description,
        //                 setting this to FALSE will return the unidentified description. This flag has no
        //                 effect on objects other than items.
        public static string GetDescription(NWN.Object oObject, int bOriginalDescription = FALSE, int bIdentifiedDescription = TRUE)
        {
            NWN.Internal.StackPushInteger(bIdentifiedDescription);
            NWN.Internal.StackPushInteger(bOriginalDescription);
            NWN.Internal.StackPushObject(oObject, false);
            NWN.Internal.CallBuiltIn(836);
            return NWN.Internal.StackPopString();
        }

        //  Set the description of oObject.
        //  - oObject: the object for which you are changing the description 
        //             Can be a creature, placeable, item, door, or trigger.
        //  - sNewDescription: the new description that the object will use.
        //  - bIdentified: If oObject is an item, setting this to TRUE will set the identified description,
        //                 setting this to FALSE will set the unidentified description. This flag has no
        //                 effect on objects other than items.
        //  Note: Setting an object's description to "" will make the object
        //        revert to using the description it originally had before any
        //        SetDescription() calls were made on the object.
        public static void SetDescription(NWN.Object oObject, string sNewDescription = "", int bIdentifiedDescription = TRUE)
        {
            NWN.Internal.StackPushInteger(bIdentifiedDescription);
            NWN.Internal.StackPushString(sNewDescription);
            NWN.Internal.StackPushObject(oObject, false);
            NWN.Internal.CallBuiltIn(837);
        }

        //  Get the PC that sent the last player chat(text) message.
        //  Should only be called from a module's OnPlayerChat event script.
        //  * Returns OBJECT_INVALID on error.
        //  Note: Private tells do not trigger a OnPlayerChat event.
        public static NWN.Object GetPCChatSpeaker()
        {
            NWN.Internal.CallBuiltIn(838);
            return NWN.Internal.StackPopObject();
        }

        //  Get the last player chat(text) message that was sent.
        //  Should only be called from a module's OnPlayerChat event script.
        //  * Returns empty string "" on error.
        //  Note: Private tells do not trigger a OnPlayerChat event.
        public static string GetPCChatMessage()
        {
            NWN.Internal.CallBuiltIn(839);
            return NWN.Internal.StackPopString();
        }

        //  Get the volume of the last player chat(text) message that was sent.
        //  Returns one of the following TALKVOLUME_* constants based on the volume setting
        //  that the player used to send the chat message.
        //                 TALKVOLUME_TALK
        //                 TALKVOLUME_WHISPER
        //                 TALKVOLUME_SHOUT
        //                 TALKVOLUME_SILENT_SHOUT (used for DM chat channel)
        //                 TALKVOLUME_PARTY
        //  Should only be called from a module's OnPlayerChat event script.
        //  * Returns -1 on error.
        //  Note: Private tells do not trigger a OnPlayerChat event.
        public static int GetPCChatVolume()
        {
            NWN.Internal.CallBuiltIn(840);
            return NWN.Internal.StackPopInteger();
        }

        //  Set the last player chat(text) message before it gets sent to other players.
        //  - sNewChatMessage: The new chat text to be sent onto other players.
        //                     Setting the player chat message to an empty string "",
        //                     will cause the chat message to be discarded 
        //                     (i.e. it will not be sent to other players).
        //  Note: The new chat message gets sent after the OnPlayerChat script exits.
        public static void SetPCChatMessage(string sNewChatMessage = "")
        {
            NWN.Internal.StackPushString(sNewChatMessage);
            NWN.Internal.CallBuiltIn(841);
        }

        //  Set the last player chat(text) volume before it gets sent to other players.
        //  - nTalkVolume: The new volume of the chat text to be sent onto other players.
        //                 TALKVOLUME_TALK
        //                 TALKVOLUME_WHISPER
        //                 TALKVOLUME_SHOUT
        //                 TALKVOLUME_SILENT_SHOUT (used for DM chat channel)
        //                 TALKVOLUME_PARTY
        //                 TALKVOLUME_TELL (sends the chat message privately back to the original speaker)
        //  Note: The new chat message gets sent after the OnPlayerChat script exits.
        public static void SetPCChatVolume(int nTalkVolume = TALKVOLUME_TALK)
        {
            NWN.Internal.StackPushInteger(nTalkVolume);
            NWN.Internal.CallBuiltIn(842);
        }

        //  Get the Color of oObject from the color channel specified.
        //  - oObject: the object from which you are obtaining the color. 
        //             Can be a creature that has color information (i.e. the playable races).
        //  - nColorChannel: The color channel that you want to get the color value of.
        //                    COLOR_CHANNEL_SKIN
        //                    COLOR_CHANNEL_HAIR
        //                    COLOR_CHANNEL_TATTOO_1
        //                    COLOR_CHANNEL_TATTOO_2
        //  * Returns -1 on error.
        public static int GetColor(NWN.Object oObject, int nColorChannel)
        {
            NWN.Internal.StackPushInteger(nColorChannel);
            NWN.Internal.StackPushObject(oObject, false);
            NWN.Internal.CallBuiltIn(843);
            return NWN.Internal.StackPopInteger();
        }

        //  Set the color channel of oObject to the color specified.
        //  - oObject: the object for which you are changing the color.
        //             Can be a creature that has color information (i.e. the playable races).
        //  - nColorChannel: The color channel that you want to set the color value of.
        //                    COLOR_CHANNEL_SKIN
        //                    COLOR_CHANNEL_HAIR
        //                    COLOR_CHANNEL_TATTOO_1
        //                    COLOR_CHANNEL_TATTOO_2
        //  - nColorValue: The color you want to set (0-175).
        public static void SetColor(NWN.Object oObject, int nColorChannel, int nColorValue)
        {
            NWN.Internal.StackPushInteger(nColorValue);
            NWN.Internal.StackPushInteger(nColorChannel);
            NWN.Internal.StackPushObject(oObject, false);
            NWN.Internal.CallBuiltIn(844);
        }

        //  Returns Item property Material.  You need to specify the Material Type.
        //  - nMasterialType: The Material Type should be a positive integer between 0 and 77 (see iprp_matcost.2da).
        //  Note: The Material Type property will only affect the cost of the item if you modify the cost in the iprp_matcost.2da.
        public static NWN.ItemProperty ItemPropertyMaterial(int nMaterialType)
        {
            NWN.Internal.StackPushInteger(nMaterialType);
            NWN.Internal.CallBuiltIn(845);
            return NWN.Internal.StackPopItemProperty();
        }

        //  Returns Item property Quality. You need to specify the Quality.
        //  - nQuality:  The Quality of the item property to create (see iprp_qualcost.2da).
        //               IP_CONST_QUALITY_*
        //  Note: The quality property will only affect the cost of the item if you modify the cost in the iprp_qualcost.2da.
        public static NWN.ItemProperty ItemPropertyQuality(int nQuality)
        {
            NWN.Internal.StackPushInteger(nQuality);
            NWN.Internal.CallBuiltIn(846);
            return NWN.Internal.StackPopItemProperty();
        }

        //  Returns a generic Additional Item property. You need to specify the Additional property.
        //  - nProperty: The item property to create (see iprp_addcost.2da).
        //               IP_CONST_ADDITIONAL_*
        //  Note: The additional property only affects the cost of the item if you modify the cost in the iprp_addcost.2da.
        public static NWN.ItemProperty ItemPropertyAdditional(int nAdditionalProperty)
        {
            NWN.Internal.StackPushInteger(nAdditionalProperty);
            NWN.Internal.CallBuiltIn(847);
            return NWN.Internal.StackPopItemProperty();
        }

        //  Sets a new tag for oObject.
        //  Will do nothing for invalid objects or the module object.
        // 
        //  Note: Care needs to be taken with this function.
        //        Changing the tag for creature with waypoints will make them stop walking them.
        //        Changing waypoint, door or trigger tags will break their area transitions.
        public static void SetTag(NWN.Object oObject, string sNewTag)
        {
            NWN.Internal.StackPushString(sNewTag);
            NWN.Internal.StackPushObject(oObject, false);
            NWN.Internal.CallBuiltIn(848);
        }

        //  Returns the string tag set for the provided effect.
        //  - If no tag has been set, returns an empty string.
        public static string GetEffectTag(NWN.Effect eEffect)
        {
            NWN.Internal.StackPushEffect(eEffect);
            NWN.Internal.CallBuiltIn(849);
            return NWN.Internal.StackPopString();
        }

        //  Tags the effect with the provided string.
        //  - Any other tags in the link will be overwritten.
        public static NWN.Effect TagEffect(NWN.Effect eEffect, string sNewTag)
        {
            NWN.Internal.StackPushString(sNewTag);
            NWN.Internal.StackPushEffect(eEffect);
            NWN.Internal.CallBuiltIn(850);
            return NWN.Internal.StackPopEffect();
        }

        //  Returns the caster level of the creature who created the effect.
        //  - If not created by a creature, returns 0.
        //  - If created by a spell-like ability, returns 0.
        public static int GetEffectCasterLevel(NWN.Effect eEffect)
        {
            NWN.Internal.StackPushEffect(eEffect);
            NWN.Internal.CallBuiltIn(851);
            return NWN.Internal.StackPopInteger();
        }

        //  Returns the total duration of the effect in seconds.
        //  - Returns 0 if the duration type of the effect is not DURATION_TYPE_TEMPORARY.
        public static int GetEffectDuration(NWN.Effect eEffect)
        {
            NWN.Internal.StackPushEffect(eEffect);
            NWN.Internal.CallBuiltIn(852);
            return NWN.Internal.StackPopInteger();
        }

        //  Returns the remaining duration of the effect in seconds.
        //  - Returns 0 if the duration type of the effect is not DURATION_TYPE_TEMPORARY.
        public static int GetEffectDurationRemaining(NWN.Effect eEffect)
        {
            NWN.Internal.StackPushEffect(eEffect);
            NWN.Internal.CallBuiltIn(853);
            return NWN.Internal.StackPopInteger();
        }

        //  Returns the string tag set for the provided item property.
        //  - If no tag has been set, returns an empty string.
        public static string GetItemPropertyTag(NWN.ItemProperty nProperty)
        {
            NWN.Internal.StackPushItemProperty(nProperty);
            NWN.Internal.CallBuiltIn(854);
            return NWN.Internal.StackPopString();
        }

        //  Tags the item property with the provided string.
        //  - Any tags currently set on the item property will be overwritten.
        public static NWN.ItemProperty TagItemProperty(NWN.ItemProperty nProperty, string sNewTag)
        {
            NWN.Internal.StackPushString(sNewTag);
            NWN.Internal.StackPushItemProperty(nProperty);
            NWN.Internal.CallBuiltIn(855);
            return NWN.Internal.StackPopItemProperty();
        }

        //  Returns the total duration of the item property in seconds.
        //  - Returns 0 if the duration type of the item property is not DURATION_TYPE_TEMPORARY.
        public static int GetItemPropertyDuration(NWN.ItemProperty nProperty)
        {
            NWN.Internal.StackPushItemProperty(nProperty);
            NWN.Internal.CallBuiltIn(856);
            return NWN.Internal.StackPopInteger();
        }

        //  Returns the remaining duration of the item property in seconds.
        //  - Returns 0 if the duration type of the item property is not DURATION_TYPE_TEMPORARY.
        public static int GetItemPropertyDurationRemaining(NWN.ItemProperty nProperty)
        {
            NWN.Internal.StackPushItemProperty(nProperty);
            NWN.Internal.CallBuiltIn(857);
            return NWN.Internal.StackPopInteger();
        }

        //  Instances a new area from the given resref, which needs to be a existing module area.
        //  Will optionally set a new area tag and displayed name. The new area is accessible
        //  immediately, but initialisation scripts for the area and all contained creatures will only
        //  run after the current script finishes (so you can clean up objects before returning).
        // 
        //  Returns the new area, or OBJECT_INVALID on failure.
        // 
        //  Note: When spawning a second instance of a existing area, you will have to manually
        //        adjust all transitions (doors, triggers) with the relevant script commands,
        //        or players might end up in the wrong area.
        public static NWN.Object CreateArea(string sResRef, string sNewTag = "", string sNewName = "")
        {
            NWN.Internal.StackPushString(sNewName);
            NWN.Internal.StackPushString(sNewTag);
            NWN.Internal.StackPushString(sResRef);
            NWN.Internal.CallBuiltIn(858);
            return NWN.Internal.StackPopObject();
        }

        //  Destroys the given area object and everything in it.
        // 
        //  Return values:
        //     0: Object not an area or invalid.
        //    -1: Area contains spawn location and removal would leave module without entrypoint.
        //    -2: Players in area.
        //     1: Area destroyed successfully.
        public static int DestroyArea(NWN.Object oArea)
        {
            NWN.Internal.StackPushObject(oArea, false);
            NWN.Internal.CallBuiltIn(859);
            return NWN.Internal.StackPopInteger();
        }

        //  Creates a copy of a existing area, including everything inside of it (except players).
        // 
        //  Returns the new area, or OBJECT_INVALID on error.
        // 
        //  Note: You will have to manually adjust all transitions (doors, triggers) with the
        //        relevant script commands, or players might end up in the wrong area.
        public static NWN.Object CopyArea(NWN.Object oArea)
        {
            NWN.Internal.StackPushObject(oArea, false);
            NWN.Internal.CallBuiltIn(860);
            return NWN.Internal.StackPopObject();
        }

        //  Returns the first area in the module.
        public static NWN.Object GetFirstArea()
        {
            NWN.Internal.CallBuiltIn(861);
            return NWN.Internal.StackPopObject();
        }

        //  Returns the next area in the module (after GetFirstArea), or OBJECT_INVALID if no more
        //  areas are loaded.
        public static NWN.Object GetNextArea()
        {
            NWN.Internal.CallBuiltIn(862);
            return NWN.Internal.StackPopObject();
        }

        //  Sets the transition target for oTransition.
        // 
        //  Notes:
        //  - oTransition can be any valid game object, except areas.
        //  - oTarget can be any valid game object with a location, or OBJECT_INVALID (to unlink).
        //  - Rebinding a transition will NOT change the other end of the transition; for example,
        //    with normal doors you will have to do either end separately.
        //  - Any valid game object can hold a transition target, but only some are used by the game engine
        //    (doors and triggers). This might change in the future. You can still set and query them for
        //    other game objects from nwscript.
        //  - Transition target objects are cached: The toolset-configured destination tag is
        //    used for a lookup only once, at first use. Thus, attempting to use SetTag() to change the
        //    destination for a transition will not work in a predictable fashion.
        public static void SetTransitionTarget(NWN.Object oTransition, NWN.Object oTarget)
        {
            NWN.Internal.StackPushObject(oTarget, false);
            NWN.Internal.StackPushObject(oTransition, false);
            NWN.Internal.CallBuiltIn(863);
        }

        //  Sets whether the provided item should be hidden when equipped.
        //  - The intended usage of this function is to provide an easy way to hide helmets, but it
        //    can be used equally for any slot which has creature mesh visibility when equipped,
        //    e.g.: armour, helm, cloak, left hand, and right hand.
        //  - nValue should be TRUE or FALSE.
        public static void SetHiddenWhenEquipped(NWN.Object oItem, int nValue)
        {
            NWN.Internal.StackPushInteger(nValue);
            NWN.Internal.StackPushObject(oItem, false);
            NWN.Internal.CallBuiltIn(864);
        }

        //  Returns whether the provided item is hidden when equipped.
        public static int GetHiddenWhenEquipped(NWN.Object oItem)
        {
            NWN.Internal.StackPushObject(oItem, false);
            NWN.Internal.CallBuiltIn(865);
            return NWN.Internal.StackPopInteger();
        }

        //  Sets if the given creature has explored tile at x, y of the given area.
        //  Note that creature needs to be a player- or player-possessed creature.
        // 
        //  Keep in mind that tile exploration also controls object visibility in areas
        //  and the fog of war for interior and underground areas.
        // 
        //  Return values:
        //   -1: Area or creature invalid.
        //    0: Tile was not explored before setting newState.
        //    1: Tile was explored before setting newState.
        public static int SetTileExplored(NWN.Object creature, NWN.Object area, int x, int y, int newState)
        {
            NWN.Internal.StackPushInteger(newState);
            NWN.Internal.StackPushInteger(y);
            NWN.Internal.StackPushInteger(x);
            NWN.Internal.StackPushObject(area, false);
            NWN.Internal.StackPushObject(creature, false);
            NWN.Internal.CallBuiltIn(866);
            return NWN.Internal.StackPopInteger();
        }

        //  Returns whether the given tile at x, y, for the given creature in the stated
        //  area is visible on the map.
        //  Note that creature needs to be a player- or player-possessed creature.
        // 
        //  Keep in mind that tile exploration also controls object visibility in areas
        //  and the fog of war for interior and underground areas.
        // 
        //  Return values:
        //   -1: Area or creature invalid.
        //    0: Tile is not explored yet.
        //    1: Tile is explored.
        public static int GetTileExplored(NWN.Object creature, NWN.Object area, int x, int y)
        {
            NWN.Internal.StackPushInteger(y);
            NWN.Internal.StackPushInteger(x);
            NWN.Internal.StackPushObject(area, false);
            NWN.Internal.StackPushObject(creature, false);
            NWN.Internal.CallBuiltIn(867);
            return NWN.Internal.StackPopInteger();
        }

        //  Sets the creature to auto-explore the map as it walks around.
        // 
        //  Keep in mind that tile exploration also controls object visibility in areas
        //  and the fog of war for interior and underground areas.
        // 
        //  This means that if you turn off auto exploration, it falls to you to manage this
        //  through SetTileExplored(); otherwise, the player will not be able to see anything.
        // 
        //  Valid arguments: TRUE and FALSE.
        //  Does nothing for non-creatures.
        //  Returns the previous state (or -1 if non-creature).
        public static int SetCreatureExploresMinimap(NWN.Object creature, int newState)
        {
            NWN.Internal.StackPushInteger(newState);
            NWN.Internal.StackPushObject(creature, false);
            NWN.Internal.CallBuiltIn(868);
            return NWN.Internal.StackPopInteger();
        }

        //  Returns TRUE if the creature is set to auto-explore the map as it walks around (on by default).
        //  Returns FALSE if creature is not actually a creature.
        public static int GetCreatureExploresMinimap(NWN.Object creature)
        {
            NWN.Internal.StackPushObject(creature, false);
            NWN.Internal.CallBuiltIn(869);
            return NWN.Internal.StackPopInteger();
        }

        //  Get the surface material at the given location. (This is
        //  equivalent to the walkmesh type).
        //  Returns 0 if the location is invalid or has no surface type.
        public static int GetSurfaceMaterial(NWN.Location at)
        {
            NWN.Internal.StackPushLocation(at);
            NWN.Internal.CallBuiltIn(870);
            return NWN.Internal.StackPopInteger();
        }

        //  Returns the z-offset at which the walkmesh is at the given location.
        //  Returns -6.0 for invalid locations.
        public static float GetGroundHeight(NWN.Location at)
        {
            NWN.Internal.StackPushLocation(at);
            NWN.Internal.CallBuiltIn(871);
            return NWN.Internal.StackPopFloat();
        }

        //  Gets the attack bonus limit.
        //  - The default value is 20.
        public static int GetAttackBonusLimit()
        {
            NWN.Internal.CallBuiltIn(872);
            return NWN.Internal.StackPopInteger();
        }

        //  Gets the damage bonus limit.
        //  - The default value is 100.
        public static int GetDamageBonusLimit()
        {
            NWN.Internal.CallBuiltIn(873);
            return NWN.Internal.StackPopInteger();
        }

        //  Gets the saving throw bonus limit.
        //  - The default value is 20.
        public static int GetSavingThrowBonusLimit()
        {
            NWN.Internal.CallBuiltIn(874);
            return NWN.Internal.StackPopInteger();
        }

        //  Gets the ability bonus limit.
        //  - The default value is 12.
        public static int GetAbilityBonusLimit()
        {
            NWN.Internal.CallBuiltIn(875);
            return NWN.Internal.StackPopInteger();
        }

        //  Gets the ability penalty limit.
        //  - The default value is 30.
        public static int GetAbilityPenaltyLimit()
        {
            NWN.Internal.CallBuiltIn(876);
            return NWN.Internal.StackPopInteger();
        }

        //  Gets the skill bonus limit.
        //  - The default value is 50.
        public static int GetSkillBonusLimit()
        {
            NWN.Internal.CallBuiltIn(877);
            return NWN.Internal.StackPopInteger();
        }

        //  Sets the attack bonus limit.
        //  - The minimum value is 0.
        public static void SetAttackBonusLimit(int nNewLimit)
        {
            NWN.Internal.StackPushInteger(nNewLimit);
            NWN.Internal.CallBuiltIn(878);
        }

        //  Sets the damage bonus limit.
        //  - The minimum value is 0.
        public static void SetDamageBonusLimit(int nNewLimit)
        {
            NWN.Internal.StackPushInteger(nNewLimit);
            NWN.Internal.CallBuiltIn(879);
        }

        //  Sets the saving throw bonus limit.
        //  - The minimum value is 0.
        public static void SetSavingThrowBonusLimit(int nNewLimit)
        {
            NWN.Internal.StackPushInteger(nNewLimit);
            NWN.Internal.CallBuiltIn(880);
        }

        //  Sets the ability bonus limit.
        //  - The minimum value is 0.
        public static void SetAbilityBonusLimit(int nNewLimit)
        {
            NWN.Internal.StackPushInteger(nNewLimit);
            NWN.Internal.CallBuiltIn(881);
        }

        //  Sets the ability penalty limit.
        //  - The minimum value is 0.
        public static void SetAbilityPenaltyLimit(int nNewLimit)
        {
            NWN.Internal.StackPushInteger(nNewLimit);
            NWN.Internal.CallBuiltIn(882);
        }

        //  Sets the skill bonus limit.
        //  - The minimum value is 0.
        public static void SetSkillBonusLimit(int nNewLimit)
        {
            NWN.Internal.StackPushInteger(nNewLimit);
            NWN.Internal.CallBuiltIn(883);
        }

        //  Get if oPlayer is currently connected over a relay (instead of directly).
        //  Returns FALSE for any other object, including OBJECT_INVALID.
        public static int GetIsPlayerConnectionRelayed(NWN.Object oPlayer)
        {
            NWN.Internal.StackPushObject(oPlayer, false);
            NWN.Internal.CallBuiltIn(884);
            return NWN.Internal.StackPopInteger();
        }

        //  Returns the event script for the given object and handler.
        //  Will return "" if unset, the object is invalid, or the object cannot
        //  have the requested handler.
        public static string GetEventScript(NWN.Object oObject, int nHandler)
        {
            NWN.Internal.StackPushInteger(nHandler);
            NWN.Internal.StackPushObject(oObject, false);
            NWN.Internal.CallBuiltIn(885);
            return NWN.Internal.StackPopString();
        }

        //  Sets the given event script for the given object and handler.
        //  Returns 1 on success, 0 on failure.
        //  Will fail if oObject is invalid or does not have the requested handler.
        public static int SetEventScript(NWN.Object oObject, int nHandler, string sScript)
        {
            NWN.Internal.StackPushString(sScript);
            NWN.Internal.StackPushInteger(nHandler);
            NWN.Internal.StackPushObject(oObject, false);
            NWN.Internal.CallBuiltIn(886);
            return NWN.Internal.StackPopInteger();
        }

    }
}