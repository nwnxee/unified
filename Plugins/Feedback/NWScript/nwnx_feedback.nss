/// @addtogroup feedback Feedback
/// @brief Allows combatlog, feedback and journal updated messages to be hidden globally or per player.
/// @note
/// * If oPC == OBJECT_INVALID it will get/set the global state:
///    * TRUE = Message is globally hidden
///    * FALSE = Message is not globally hidden
/// * If oPC is a valid player it will get/set the personal state:
///    * TRUE = Message is hidden for oPC
///    * FALSE = Message is not hidden for oPC
///    * -1 = Personal state is not set for Message
/// @{
/// @file nwnx_feedback.nss
#include "nwnx"

const string NWNX_Feedback = "NWNX_Feedback"; ///< @private

/// @name Combat Log Message Types
/// @anchor combat_log_msgs
/// @{
const int NWNX_FEEDBACK_COMBATLOG_SIMPLE_ADJECTIVE    = 1;
/*
const int NWNX_FEEDBACK_COMBATLOG_SIMPLE_DAMAGE       = 2;
const int NWNX_FEEDBACK_COMBATLOG_COMPLEX_DAMAGE      = 3;
const int NWNX_FEEDBACK_COMBATLOG_COMPLEX_DEATH       = 4;
const int NWNX_FEEDBACK_COMBATLOG_COMPLEX_ATTACK      = 5;
const int NWNX_FEEDBACK_COMBATLOG_SPECIAL_ATTACK      = 6;
const int NWNX_FEEDBACK_COMBATLOG_SAVING_THROW        = 7;
const int NWNX_FEEDBACK_COMBATLOG_CAST_SPELL          = 8;
const int NWNX_FEEDBACK_COMBATLOG_USE_SKILL           = 9;
const int NWNX_FEEDBACK_COMBATLOG_SPELL_RESISTANCE    = 10;
const int NWNX_FEEDBACK_COMBATLOG_FEEDBACK            = 11; // NOTE: This hides ALL feedback messages, to hide individual messages use NWNX_Feedback_SetFeedbackMessageHidden()
const int NWNX_FEEDBACK_COMBATLOG_COUNTERSPELL        = 12;
const int NWNX_FEEDBACK_COMBATLOG_TOUCHATTACK         = 13;
const int NWNX_FEEDBACK_COMBATLOG_INITIATIVE          = 14;
const int NWNX_FEEDBACK_COMBATLOG_DISPEL_MAGIC        = 15;
const int NWNX_FEEDBACK_COMBATLOG_POLYMORPH           = 17;
const int NWNX_FEEDBACK_COMBATLOG_FEEDBACKSTRING      = 18;
const int NWNX_FEEDBACK_COMBATLOG_VIBRATE             = 19;
const int NWNX_FEEDBACK_COMBATLOG_UNLOCKACHIEVEMENT   = 20;

// 1  -> Simple_Adjective: <charname> : <adjective described by strref>
// 2  -> Simple_Damage: <charname> damaged : <amount>
// 3  -> Complex_Damage: <charname> damages <charname> : <amount>
// 4  -> Complex_Death: <charname> killed <charname>
// 5  -> Complex_Attack: <charname> attacks <charname> : *hit* / *miss* / *parried* : (<attack roll> + <attack mod> = <modified total>)
// 6  -> Special_Attack: <charname> attempts <special attack> on <charname> : *success* / *failure* : (<attack roll> + <attack mod> = <modified roll>)
// 7  -> Saving_Throw: <charname> : <saving throw type> : *success* / *failure* : (<saving throw roll> + <saving throw modifier> = <modified total>)
// 8  -> Cast_Spell: <charname> casts <spell name> : Spellcraft check *failure* / *success*
// 9  -> Use_Skill: <charname> : <skill name> : *success* / *failure* : (<skill roll> + <skill modifier> = <modified total> vs <DC> )
// 10 -> Spell_Resistance: <charname> : Spell Resistance <SR value> : *success* / *failure*
// 11 -> Feedback: Reason skill/feat/ability failed.
// 12 -> Counterspel: <charname> casts <spell name> : *spell countered by* : <charname> casting <spell name>
// 13 -> TouchAttack: <charname> attempts <melee/ranged touch attack> on <charname> : *hit/miss/critical* : (<attack roll> + <attack mod> = <modified roll>)
// 14 -> Initiative: <charname> : Initiative Roll : <total> : (<roll> + <modifier> = <total>)
// 15 -> Dispel_Magic: Dispel Magic : <charname> : <spell name>, <spell name>, <spell name>...
// 17 -> Unused, probably
// 18 -> Same as 11, maybe. Might be unused too
// 19 -> Unused
// 20 -> Unused
*/

/// @}

/// @name Feedback Message Types
/// @anchor feedback_msgs
/// @{

const int NWNX_FEEDBACK_SKILL_CANT_USE                     = 0;
/*
/// Skill Feedback Messages
const int NWNX_FEEDBACK_SKILL_CANT_USE_TIMER               = 1;
const int NWNX_FEEDBACK_SKILL_ANIMALEMPATHY_VALID_TARGETS  = 2;
const int NWNX_FEEDBACK_SKILL_TAUNT_VALID_TARGETS          = 3;
const int NWNX_FEEDBACK_SKILL_TAUNT_TARGET_IMMUNE          = 223;
const int NWNX_FEEDBACK_SKILL_PICKPOCKET_STOLE_ITEM        = 4;
const int NWNX_FEEDBACK_SKILL_PICKPOCKET_STOLE_GOLD        = 5;
const int NWNX_FEEDBACK_SKILL_PICKPOCKET_ATTEMPTING_TO_STEAL = 46;
const int NWNX_FEEDBACK_SKILL_PICKPOCKET_ATTEMPT_DETECTED  = 150;
const int NWNX_FEEDBACK_SKILL_PICKPOCKET_STOLE_ITEM_TARGET = 47;
const int NWNX_FEEDBACK_SKILL_PICKPOCKET_STOLE_GOLD_TARGET = 48;
const int NWNX_FEEDBACK_SKILL_PICKPOCKET_TARGET_BROKE      = 57;
const int NWNX_FEEDBACK_SKILL_HEAL_TARGET_NOT_DISPSND      = 55;
const int NWNX_FEEDBACK_SKILL_HEAL_VALID_TARGETS           = 56;
const int NWNX_FEEDBACK_SKILL_STEALTH_IN_COMBAT            = 60;

/// Miscellaneous Targetting Messages
const int NWNX_FEEDBACK_TARGET_UNAWARE                     = 6;
const int NWNX_FEEDBACK_ACTION_NOT_POSSIBLE_STATUS         = 7;
const int NWNX_FEEDBACK_ACTION_NOT_POSSIBLE_PVP            = 187;
const int NWNX_FEEDBACK_ACTION_CANT_REACH_TARGET           = 218;
const int NWNX_FEEDBACK_ACTION_NO_LOOT                     = 247;

/// Miscellaneous Feedback Messages
const int NWNX_FEEDBACK_WEIGHT_TOO_ENCUMBERED_TO_RUN       = 8;
const int NWNX_FEEDBACK_WEIGHT_TOO_ENCUMBERED_WALK_SLOW    = 9;
const int NWNX_FEEDBACK_WEIGHT_TOO_ENCUMBERED_CANT_PICKUP  = 10;
const int NWNX_FEEDBACK_STATS_LEVELUP                      = 11;
const int NWNX_FEEDBACK_INVENTORY_FULL                     = 12;
const int NWNX_FEEDBACK_CONTAINER_FULL                     = 212;
const int NWNX_FEEDBACK_TRAP_TRIGGERED                     = 82;
const int NWNX_FEEDBACK_DAMAGE_HEALED                      = 151;
const int NWNX_FEEDBACK_EXPERIENCE_GAINNED                 = 182;
const int NWNX_FEEDBACK_EXPERIENCE_LOST                    = 183;
const int NWNX_FEEDBACK_JOURNALUPDATED                     = 184; // Doesn't actually work, use:
                                                                  // NWNX_Feedback_{Get/Set}JournalUpdatedMessageHidden()
const int NWNX_FEEDBACK_BARTER_CANCELLED                   = 185;

/// Mode activation/deactivation Messages
const int NWNX_FEEDBACK_DETECT_MODE_ACTIVATED              = 83;
const int NWNX_FEEDBACK_DETECT_MODE_DEACTIVATED            = 84;
const int NWNX_FEEDBACK_STEALTH_MODE_ACTIVATED             = 85;
const int NWNX_FEEDBACK_STEALTH_MODE_DEACTIVATED           = 86;
const int NWNX_FEEDBACK_PARRY_MODE_ACTIVATED               = 87;
const int NWNX_FEEDBACK_PARRY_MODE_DEACTIVATED             = 88;
const int NWNX_FEEDBACK_POWER_ATTACK_MODE_ACTIVATED        = 89;
const int NWNX_FEEDBACK_POWER_ATTACK_MODE_DEACTIVATED      = 90;
const int NWNX_FEEDBACK_IMPROVED_POWER_ATTACK_MODE_ACTIVATED = 91;
const int NWNX_FEEDBACK_IMPROVED_POWER_ATTACK_MODE_DEACTIVATED = 92;
const int NWNX_FEEDBACK_RAPID_SHOT_MODE_ACTIVATED          = 166;
const int NWNX_FEEDBACK_RAPID_SHOT_MODE_DEACTIVATED        = 167;
const int NWNX_FEEDBACK_FLURRY_OF_BLOWS_MODE_ACTIVATED     = 168;
const int NWNX_FEEDBACK_FLURRY_OF_BLOWS_MODE_DEACTIVATED   = 169;
const int NWNX_FEEDBACK_EXPERTISE_MODE_ACTIVATED           = 227;
const int NWNX_FEEDBACK_EXPERTISE_MODE_DEACTIVATED         = 228;
const int NWNX_FEEDBACK_IMPROVED_EXPERTISE_MODE_ACTIVATED  = 229;
const int NWNX_FEEDBACK_IMPROVED_EXPERTISE_MODE_DEACTIVATED = 230;
const int NWNX_FEEDBACK_DEFENSIVE_CAST_MODE_ACTIVATED      = 231;
const int NWNX_FEEDBACK_DEFENSIVE_CAST_MODE_DEACTIVATED    = 232;
const int NWNX_FEEDBACK_MODE_CANNOT_USE_WEAPONS            = 188;
const int NWNX_FEEDBACK_DIRTY_FIGHTING_MODE_ACTIVATED      = 237;
const int NWNX_FEEDBACK_DIRTY_FIGHTING_MODE_DEACTIVATED    = 238;

const int NWNX_FEEDBACK_DEFENSIVE_STANCE_MODE_ACTIVATED    = 252;
const int NWNX_FEEDBACK_DEFENSIVE_STANCE_MODE_DEACTIVATED  = 253;

/// Equipping Feedback Messages
const int NWNX_FEEDBACK_EQUIP_SKILL_SPELL_MODIFIERS        = 71;
const int NWNX_FEEDBACK_EQUIP_UNIDENTIFIED                 = 76;
const int NWNX_FEEDBACK_EQUIP_MONK_ABILITIES               = 77;
const int NWNX_FEEDBACK_EQUIP_INSUFFICIENT_LEVEL           = 98;
const int NWNX_FEEDBACK_EQUIP_PROFICIENCIES                = 119;
const int NWNX_FEEDBACK_EQUIP_WEAPON_TOO_LARGE             = 120;
const int NWNX_FEEDBACK_EQUIP_WEAPON_TOO_SMALL             = 260;
const int NWNX_FEEDBACK_EQUIP_ONE_HANDED_WEAPON            = 121;
const int NWNX_FEEDBACK_EQUIP_TWO_HANDED_WEAPON            = 122;
const int NWNX_FEEDBACK_EQUIP_WEAPON_SWAPPED_OUT           = 123;
const int NWNX_FEEDBACK_EQUIP_ONE_CHAIN_WEAPON             = 124;
const int NWNX_FEEDBACK_EQUIP_NATURAL_AC_NO_STACK          = 189;
const int NWNX_FEEDBACK_EQUIP_ARMOUR_AC_NO_STACK           = 190;
const int NWNX_FEEDBACK_EQUIP_SHIELD_AC_NO_STACK           = 191;
const int NWNX_FEEDBACK_EQUIP_DEFLECTION_AC_NO_STACK       = 192;
const int NWNX_FEEDBACK_EQUIP_NO_ARMOR_COMBAT              = 193;
const int NWNX_FEEDBACK_EQUIP_RANGER_ABILITIES             = 200;
const int NWNX_FEEDBACK_EQUIP_ALIGNMENT                    = 207;
const int NWNX_FEEDBACK_EQUIP_CLASS                        = 208;
const int NWNX_FEEDBACK_EQUIP_RACE                         = 209;
const int NWNX_FEEDBACK_UNEQUIP_NO_ARMOR_COMBAT            = 194;

/// Action Feedback Messages
const int NWNX_FEEDBACK_OBJECT_LOCKED                      = 13;
const int NWNX_FEEDBACK_OBJECT_NOT_LOCKED                  = 14;
const int NWNX_FEEDBACK_OBJECT_SPECIAL_KEY                 = 15;
const int NWNX_FEEDBACK_OBJECT_USED_KEY                    = 16;
const int NWNX_FEEDBACK_REST_EXCITED_CANT_REST             = 17;
const int NWNX_FEEDBACK_REST_BEGINNING_REST                = 18;
const int NWNX_FEEDBACK_REST_FINISHED_REST                 = 19;
const int NWNX_FEEDBACK_REST_CANCEL_REST                   = 20;
const int NWNX_FEEDBACK_REST_NOT_ALLOWED_IN_AREA           = 54;
const int NWNX_FEEDBACK_REST_NOT_ALLOWED_BY_POSSESSED_FAMILIAR = 153;
const int NWNX_FEEDBACK_REST_NOT_ALLOWED_ENEMIES           = 186;
const int NWNX_FEEDBACK_REST_CANT_UNDER_THIS_EFFECT        = 213;
const int NWNX_FEEDBACK_CAST_LOST_TARGET                   = 21;
const int NWNX_FEEDBACK_CAST_CANT_CAST                     = 22;
const int NWNX_FEEDBACK_CAST_CNTRSPELL_TARGET_LOST_TARGET  = 52;
const int NWNX_FEEDBACK_CAST_ARCANE_SPELL_FAILURE          = 61;
const int NWNX_FEEDBACK_CAST_CNTRSPELL_TARGET_ARCANE_SPELL_FAILURE = 118;
const int NWNX_FEEDBACK_CAST_ENTANGLE_CONCENTRATION_FAILURE = 65;
const int NWNX_FEEDBACK_CAST_CNTRSPELL_TARGET_ENTANGLE_CONCENTRATION_FAILURE = 147;
const int NWNX_FEEDBACK_CAST_SPELL_INTERRUPTED             = 72;
const int NWNX_FEEDBACK_CAST_EFFECT_SPELL_FAILURE          = 236;
const int NWNX_FEEDBACK_CAST_CANT_CAST_WHILE_POLYMORPHED   = 107;
const int NWNX_FEEDBACK_CAST_USE_HANDS                     = 210;
const int NWNX_FEEDBACK_CAST_USE_MOUTH                     = 211;
const int NWNX_FEEDBACK_CAST_DEFCAST_CONCENTRATION_FAILURE = 233;
const int NWNX_FEEDBACK_CAST_DEFCAST_CONCENTRATION_SUCCESS = 240;
const int NWNX_FEEDBACK_USEITEM_CANT_USE                   = 23;
const int NWNX_FEEDBACK_CONVERSATION_TOOFAR                = 58;
const int NWNX_FEEDBACK_CONVERSATION_BUSY                  = 59;
const int NWNX_FEEDBACK_CONVERSATION_IN_COMBAT             = 152;
const int NWNX_FEEDBACK_CHARACTER_INTRANSIT                = 74;
const int NWNX_FEEDBACK_CHARACTER_OUTTRANSIT               = 75;
const int NWNX_FEEDBACK_USEITEM_NOT_EQUIPPED               = 244;
const int NWNX_FEEDBACK_DROPITEM_CANT_DROP                 = 245;
const int NWNX_FEEDBACK_DROPITEM_CANT_GIVE                 = 246;
const int NWNX_FEEDBACK_CLIENT_SERVER_SPELL_MISMATCH       = 259;

/// Combat feedback messages
const int NWNX_FEEDBACK_COMBAT_RUNNING_OUT_OF_AMMO         = 24;
const int NWNX_FEEDBACK_COMBAT_OUT_OF_AMMO                 = 25;
const int NWNX_FEEDBACK_COMBAT_HENCHMAN_OUT_OF_AMMO        = 241;
const int NWNX_FEEDBACK_COMBAT_DAMAGE_IMMUNITY             = 62;
const int NWNX_FEEDBACK_COMBAT_SPELL_IMMUNITY              = 68;
const int NWNX_FEEDBACK_COMBAT_DAMAGE_RESISTANCE           = 63;
const int NWNX_FEEDBACK_COMBAT_DAMAGE_RESISTANCE_REMAINING = 66;
const int NWNX_FEEDBACK_COMBAT_DAMAGE_REDUCTION            = 64;
const int NWNX_FEEDBACK_COMBAT_DAMAGE_REDUCTION_REMAINING  = 67;
const int NWNX_FEEDBACK_COMBAT_SPELL_LEVEL_ABSORPTION      = 69;
const int NWNX_FEEDBACK_COMBAT_SPELL_LEVEL_ABSORPTION_REMAINING = 70;
const int NWNX_FEEDBACK_COMBAT_WEAPON_NOT_EFFECTIVE        = 117;
const int NWNX_FEEDBACK_COMBAT_EPIC_DODGE_ATTACK_EVADED    = 234;
const int NWNX_FEEDBACK_COMBAT_MASSIVE_DAMAGE              = 235;
const int NWNX_FEEDBACK_COMBAT_SAVED_VS_MASSIVE_DAMAGE     = 254;
const int NWNX_FEEDBACK_COMBAT_SAVED_VS_DEVASTATING_CRITICAL = 257;

/// Feat Feedback Messages
const int NWNX_FEEDBACK_FEAT_SAP_VALID_TARGETS             = 26;
const int NWNX_FEEDBACK_FEAT_KNOCKDOWN_VALID_TARGETS       = 27;
const int NWNX_FEEDBACK_FEAT_IMPKNOCKDOWN_VALID_TARGETS    = 28;
const int NWNX_FEEDBACK_FEAT_CALLED_SHOT_NO_LEGS           = 29;
const int NWNX_FEEDBACK_FEAT_CALLED_SHOT_NO_ARMS           = 30;
const int NWNX_FEEDBACK_FEAT_SMITE_GOOD_TARGET_NOT_GOOD    = 239;
const int NWNX_FEEDBACK_FEAT_SMITE_EVIL_TARGET_NOT_EVIL    = 53;
const int NWNX_FEEDBACK_FEAT_QUIVERING_PALM_HIGHER_LEVEL   = 73;
const int NWNX_FEEDBACK_FEAT_KEEN_SENSE_DETECT             = 195;
const int NWNX_FEEDBACK_FEAT_USE_UNARMED                   = 198;
const int NWNX_FEEDBACK_FEAT_USES                          = 199;
const int NWNX_FEEDBACK_FEAT_USE_WEAPON_OF_CHOICE          = 243;

/// Party Feedback Messages
const int NWNX_FEEDBACK_PARTY_NEW_LEADER                   = 31;
const int NWNX_FEEDBACK_PARTY_MEMBER_KICKED                = 32;
const int NWNX_FEEDBACK_PARTY_KICKED_YOU                   = 33;
const int NWNX_FEEDBACK_PARTY_ALREADY_CONSIDERING          = 34;
const int NWNX_FEEDBACK_PARTY_ALREADY_INVOLVED             = 35;
const int NWNX_FEEDBACK_PARTY_SENT_INVITATION              = 36;
const int NWNX_FEEDBACK_PARTY_RECEIVED_INVITATION          = 37;
const int NWNX_FEEDBACK_PARTY_JOINED                       = 38;
const int NWNX_FEEDBACK_PARTY_INVITATION_IGNORED           = 39;
const int NWNX_FEEDBACK_PARTY_YOU_IGNORED_INVITATION       = 40;
const int NWNX_FEEDBACK_PARTY_INVITATION_REJECTED          = 41;
const int NWNX_FEEDBACK_PARTY_YOU_REJECTED_INVITATION      = 42;
const int NWNX_FEEDBACK_PARTY_INVITATION_EXPIRED           = 43;
const int NWNX_FEEDBACK_PARTY_LEFT_PARTY                   = 44;
const int NWNX_FEEDBACK_PARTY_YOU_LEFT                     = 45;
const int NWNX_FEEDBACK_PARTY_HENCHMAN_LIMIT               = 49;
const int NWNX_FEEDBACK_PARTY_CANNOT_LEAVE_THE_ONE_PARTY   = 196;
const int NWNX_FEEDBACK_PARTY_CANNOT_KICK_FROM_THE_ONE_PARTY = 197;
const int NWNX_FEEDBACK_PARTY_YOU_INVITED_NON_SINGLETON    = 202;
const int NWNX_FEEDBACK_PVP_REACTION_DISLIKESYOU           = 203;

/// Item Feedback Messages
const int NWNX_FEEDBACK_ITEM_RECEIVED                      = 50;
const int NWNX_FEEDBACK_ITEM_LOST                          = 51;
const int NWNX_FEEDBACK_ITEM_EJECTED                       = 96;
const int NWNX_FEEDBACK_ITEM_USE_UNIDENTIFIED              = 97;
const int NWNX_FEEDBACK_ITEM_GOLD_GAINED                   = 148;
const int NWNX_FEEDBACK_ITEM_GOLD_LOST                     = 149;

/// Spell Scroll Learning
const int NWNX_FEEDBACK_LEARN_SCROLL_NOT_SCROLL            = 78;
const int NWNX_FEEDBACK_LEARN_SCROLL_CANT_LEARN_CLASS      = 79;
const int NWNX_FEEDBACK_LEARN_SCROLL_CANT_LEARN_LEVEL      = 80;
const int NWNX_FEEDBACK_LEARN_SCROLL_CANT_LEARN_ABILITY    = 81;
const int NWNX_FEEDBACK_LEARN_SCROLL_CANT_LEARN_OPPOSITION = 219;
const int NWNX_FEEDBACK_LEARN_SCROLL_CANT_LEARN_POSSESS    = 220;
const int NWNX_FEEDBACK_LEARN_SCROLL_CANT_LEARN_KNOWN      = 221;
const int NWNX_FEEDBACK_LEARN_SCROLL_CANT_LEARN_DIVINE     = 224;
const int NWNX_FEEDBACK_LEARN_SCROLL_SUCCESS               = 222;

/// Floaty text feedback
const int NWNX_FEEDBACK_FLOATY_TEXT_STRREF                 = 93;
const int NWNX_FEEDBACK_FLOATY_TEXT_STRING                 = 94;

/// Store feedback
const int NWNX_FEEDBACK_CANNOT_SELL_PLOT_ITEM              = 99;
const int NWNX_FEEDBACK_CANNOT_SELL_CONTAINER              = 100;
const int NWNX_FEEDBACK_CANNOT_SELL_ITEM                   = 101;
const int NWNX_FEEDBACK_NOT_ENOUGH_GOLD                    = 102;
const int NWNX_FEEDBACK_TRANSACTION_SUCCEEDED              = 103;
const int NWNX_FEEDBACK_PRICE_TOO_HIGH                     = 248;
const int NWNX_FEEDBACK_STORE_NOT_ENOUGH_GOLD              = 249;
const int NWNX_FEEDBACK_CANNOT_SELL_STOLEN_ITEM            = 250;
const int NWNX_FEEDBACK_CANNOT_SELL_RESTRICTED_ITEM        = 251;

/// Portal control feedback
const int NWNX_FEEDBACK_PORTAL_TIMEDOUT                    = 104;
const int NWNX_FEEDBACK_PORTAL_INVALID                     = 105;

/// Chat feedback
const int NWNX_FEEDBACK_CHAT_TELL_PLAYER_NOT_FOUND         = 106;

/// Alignment Feedback
const int NWNX_FEEDBACK_ALIGNMENT_SHIFT                    = 108;
const int NWNX_FEEDBACK_ALIGNMENT_PARTY_SHIFT              = 111;
const int NWNX_FEEDBACK_ALIGNMENT_CHANGE                   = 109;
const int NWNX_FEEDBACK_ALIGNMENT_RESTRICTED_BY_CLASS_LOST = 110;
const int NWNX_FEEDBACK_ALIGNMENT_RESTRICTED_BY_CLASS_GAIN = 115;
const int NWNX_FEEDBACK_ALIGNMENT_RESTRICTED_WARNING_LOSS  = 116;
const int NWNX_FEEDBACK_ALIGNMENT_RESTRICTED_WARNING_GAIN  = 112;
const int NWNX_FEEDBACK_ALIGNMENT_EPITOME_GAINED           = 113;
const int NWNX_FEEDBACK_ALIGNMENT_EPITOME_LOST             = 114;

/// Immunity Feedback
const int NWNX_FEEDBACK_IMMUNITY_DISEASE                   = 125;
const int NWNX_FEEDBACK_IMMUNITY_CRITICAL_HIT              = 126;
const int NWNX_FEEDBACK_IMMUNITY_DEATH_MAGIC               = 127;
const int NWNX_FEEDBACK_IMMUNITY_FEAR                      = 128;
const int NWNX_FEEDBACK_IMMUNITY_KNOCKDOWN                 = 129;
const int NWNX_FEEDBACK_IMMUNITY_PARALYSIS                 = 130;
const int NWNX_FEEDBACK_IMMUNITY_NEGATIVE_LEVEL            = 131;
const int NWNX_FEEDBACK_IMMUNITY_MIND_SPELLS               = 132;
const int NWNX_FEEDBACK_IMMUNITY_POISON                    = 133;
const int NWNX_FEEDBACK_IMMUNITY_SNEAK_ATTACK              = 134;
const int NWNX_FEEDBACK_IMMUNITY_SLEEP                     = 135;
const int NWNX_FEEDBACK_IMMUNITY_DAZE                      = 136;
const int NWNX_FEEDBACK_IMMUNITY_CONFUSION                 = 137;
const int NWNX_FEEDBACK_IMMUNITY_STUN                      = 138;
const int NWNX_FEEDBACK_IMMUNITY_BLINDNESS                 = 139;
const int NWNX_FEEDBACK_IMMUNITY_DEAFNESS                  = 140;
const int NWNX_FEEDBACK_IMMUNITY_CURSE                     = 141;
const int NWNX_FEEDBACK_IMMUNITY_CHARM                     = 142;
const int NWNX_FEEDBACK_IMMUNITY_DOMINATE                  = 143;
const int NWNX_FEEDBACK_IMMUNITY_ENTANGLE                  = 144;
const int NWNX_FEEDBACK_IMMUNITY_SILENCE                   = 145;
const int NWNX_FEEDBACK_IMMUNITY_SLOW                      = 146;

/// Associates
const int NWNX_FEEDBACK_ASSOCIATE_SUMMONED                 = 154;
const int NWNX_FEEDBACK_ASSOCIATE_UNSUMMONING              = 155;
const int NWNX_FEEDBACK_ASSOCIATE_UNSUMMONING_BECAUSE_REST = 156;
const int NWNX_FEEDBACK_ASSOCIATE_UNSUMMONING_BECAUSE_DIED = 157;
const int NWNX_FEEDBACK_ASSOCIATE_DOMINATED                = 158;
const int NWNX_FEEDBACK_ASSOCIATE_DOMINATION_ENDED         = 159;
const int NWNX_FEEDBACK_ASSOCIATE_POSSESSED_CANNOT_RECOVER_TRAP = 170;
const int NWNX_FEEDBACK_ASSOCIATE_POSSESSED_CANNOT_BARTER  = 171;
const int NWNX_FEEDBACK_ASSOCIATE_POSSESSED_CANNOT_EQUIP   = 172;
const int NWNX_FEEDBACK_ASSOCIATE_POSSESSED_CANNOT_REPOSITORY_MOVE = 173;
const int NWNX_FEEDBACK_ASSOCIATE_POSSESSED_CANNOT_PICK_UP = 174;
const int NWNX_FEEDBACK_ASSOCIATE_POSSESSED_CANNOT_DROP    = 175;
const int NWNX_FEEDBACK_ASSOCIATE_POSSESSED_CANNOT_UNEQUIP = 176;
const int NWNX_FEEDBACK_ASSOCIATE_POSSESSED_CANNOT_REST    = 177;
const int NWNX_FEEDBACK_ASSOCIATE_POSSESSED_CANNOT_DIALOGUE = 178;
const int NWNX_FEEDBACK_ASSOCIATE_POSSESSED_CANNOT_GIVE_ITEM = 179;
const int NWNX_FEEDBACK_ASSOCIATE_POSSESSED_CANNOT_TAKE_ITEM = 180;
const int NWNX_FEEDBACK_ASSOCIATE_POSSESSED_CANNOT_USE_CONTAINER = 181;

/// Miscellaneous Feedback
const int NWNX_FEEDBACK_SCRIPT_ERROR                       = 160;
const int NWNX_FEEDBACK_ACTION_LIST_OVERFLOW               = 161;
const int NWNX_FEEDBACK_EFFECT_LIST_OVERFLOW               = 162;
const int NWNX_FEEDBACK_AI_UPDATE_TIME_OVERFLOW            = 163;
const int NWNX_FEEDBACK_ACTION_LIST_WIPE_OVERFLOW          = 164;
const int NWNX_FEEDBACK_EFFECT_LIST_WIPE_OVERFLOW          = 165;
const int NWNX_FEEDBACK_SEND_MESSAGE_TO_PC                 = 204;
const int NWNX_FEEDBACK_SEND_MESSAGE_TO_PC_STRREF          = 242;

/// Misc GUI feedback
const int NWNX_FEEDBACK_GUI_ONLY_PARTY_LEADER_MAY_CLICK    = 201;
const int NWNX_FEEDBACK_PAUSED                             = 205;
const int NWNX_FEEDBACK_UNPAUSED                           = 206;
const int NWNX_FEEDBACK_REST_YOU_MAY_NOT_AT_THIS_TIME      = 214;
const int NWNX_FEEDBACK_GUI_CHAR_EXPORT_REQUEST_SENT       = 215;
const int NWNX_FEEDBACK_GUI_CHAR_EXPORTED_SUCCESSFULLY     = 216;
const int NWNX_FEEDBACK_GUI_ERROR_CHAR_NOT_EXPORTED        = 217;
const int NWNX_FEEDBACK_CAMERA_BG                          = 255;
const int NWNX_FEEDBACK_CAMERA_EQ                          = 256;
const int NWNX_FEEDBACK_CAMERA_CHASECAM                    = 258;

const int NWNX_FEEDBACK_SAVING                             = 225;
const int NWNX_FEEDBACK_SAVE_COMPLETE                      = 226;
*/
/// @}

/// @brief Gets if feedback message is hidden.
/// @param nMessage The message identifier from @ref feedback_msgs "Feedback Messages".
/// @param oPC The PC or OBJECT_INVALID for a global setting.
/// @return TRUE if the message is hidden.
int NWNX_Feedback_GetFeedbackMessageHidden(int nMessage, object oPC = OBJECT_INVALID);

/// @brief Sets if feedback message is hidden.
/// @param nMessage The message identifier.
/// @param isHidden TRUE/FALSE
/// @param oPC The PC or OBJECT_INVALID for a global setting.
/// @note Personal state overrides the global state which means if a global state is set
/// to TRUE but the personal state is set to FALSE, the message will be shown to the PC.
void NWNX_Feedback_SetFeedbackMessageHidden(int nMessage, int isHidden, object oPC = OBJECT_INVALID);

/// @brief Gets if combat log message is hidden.
/// @param nMessage The message identifier from @ref combat_log_msgs "Combat Log Messages".
/// @param oPC The PC or OBJECT_INVALID for a global setting.
/// @return TRUE if the message is hidden.
int NWNX_Feedback_GetCombatLogMessageHidden(int nMessage, object oPC = OBJECT_INVALID);

/// @brief Sets if combat log message is hidden.
/// @param nMessage The message identifier.
/// @param isHidden TRUE/FALSE
/// @param oPC The PC or OBJECT_INVALID for a global setting.
/// @note Personal state overrides the global state which means if a global state is set
/// to TRUE but the personal state is set to FALSE, the message will be shown to the PC.
void NWNX_Feedback_SetCombatLogMessageHidden(int nMessage, int isHidden, object oPC = OBJECT_INVALID);

/// @brief Gets if the journal update message is hidden.
/// @param oPC The PC or OBJECT_INVALID for a global setting.
/// @return TRUE if the message is hidden.
int NWNX_Feedback_GetJournalUpdatedMessageHidden(object oPC = OBJECT_INVALID);

/// @brief Sets if journal update message is hidden.
/// @param isHidden TRUE/FALSE
/// @param oPC The PC or OBJECT_INVALID for a global setting.
/// @note Personal state overrides the global state which means if a global state is set
/// to TRUE but the personal state is set to FALSE, the message will be shown to the PC.
void NWNX_Feedback_SetJournalUpdatedMessageHidden(int isHidden, object oPC = OBJECT_INVALID);

/// @brief Set whether to use a blacklist or whitelist mode for feedback messages
/// @param bWhitelist TRUE for all messages to be hidden by default, default FALSE.
void NWNX_Feedback_SetFeedbackMessageMode(int bWhitelist);


/// @brief Set whether to use a blacklist or whitelist mode for combat log messages
/// @param bWhitelist TRUE for all messages to be hidden by default, default FALSE.
/// @note If using Whitelist, be sure to whitelist NWNX_FEEDBACK_COMBATLOG_FEEDBACK for feedback messages to work.
void NWNX_Feedback_SetCombatLogMessageMode(int bWhitelist);

/// @}

int NWNX_Feedback_GetFeedbackMessageHidden(int nMessage, object oPC = OBJECT_INVALID)
{
    string sFunc = "GetMessageHidden";
    int nMessageType = 0;

    NWNX_PushArgumentInt(NWNX_Feedback, sFunc, nMessage);
    NWNX_PushArgumentInt(NWNX_Feedback, sFunc, nMessageType);
    NWNX_PushArgumentObject(NWNX_Feedback, sFunc, oPC);
    NWNX_CallFunction(NWNX_Feedback, sFunc);

    return NWNX_GetReturnValueInt(NWNX_Feedback, sFunc);
}

void NWNX_Feedback_SetFeedbackMessageHidden(int nMessage, int isHidden, object oPC = OBJECT_INVALID)
{
    string sFunc = "SetMessageHidden";
    int nMessageType = 0;

    NWNX_PushArgumentInt(NWNX_Feedback, sFunc, isHidden);
    NWNX_PushArgumentInt(NWNX_Feedback, sFunc, nMessage);
    NWNX_PushArgumentInt(NWNX_Feedback, sFunc, nMessageType);
    NWNX_PushArgumentObject(NWNX_Feedback, sFunc, oPC);
    NWNX_CallFunction(NWNX_Feedback, sFunc);
}

int NWNX_Feedback_GetCombatLogMessageHidden(int nMessage, object oPC = OBJECT_INVALID)
{
    string sFunc = "GetMessageHidden";
    int nMessageType = 1;

    NWNX_PushArgumentInt(NWNX_Feedback, sFunc, nMessage);
    NWNX_PushArgumentInt(NWNX_Feedback, sFunc, nMessageType);
    NWNX_PushArgumentObject(NWNX_Feedback, sFunc, oPC);
    NWNX_CallFunction(NWNX_Feedback, sFunc);

    return NWNX_GetReturnValueInt(NWNX_Feedback, sFunc);
}

void NWNX_Feedback_SetCombatLogMessageHidden(int nMessage, int isHidden, object oPC = OBJECT_INVALID)
{
    string sFunc = "SetMessageHidden";
    int nMessageType = 1;

    NWNX_PushArgumentInt(NWNX_Feedback, sFunc, isHidden);
    NWNX_PushArgumentInt(NWNX_Feedback, sFunc, nMessage);
    NWNX_PushArgumentInt(NWNX_Feedback, sFunc, nMessageType);
    NWNX_PushArgumentObject(NWNX_Feedback, sFunc, oPC);
    NWNX_CallFunction(NWNX_Feedback, sFunc);
}

int NWNX_Feedback_GetJournalUpdatedMessageHidden(object oPC = OBJECT_INVALID)
{
    string sFunc = "GetMessageHidden";
    int nMessageType = 2;

    NWNX_PushArgumentInt(NWNX_Feedback, sFunc, 0);
    NWNX_PushArgumentInt(NWNX_Feedback, sFunc, nMessageType);
    NWNX_PushArgumentObject(NWNX_Feedback, sFunc, oPC);
    NWNX_CallFunction(NWNX_Feedback, sFunc);

    return NWNX_GetReturnValueInt(NWNX_Feedback, sFunc);
}

void NWNX_Feedback_SetJournalUpdatedMessageHidden(int isHidden, object oPC = OBJECT_INVALID)
{
    string sFunc = "SetMessageHidden";
    int nMessageType = 2;

    NWNX_PushArgumentInt(NWNX_Feedback, sFunc, isHidden);
    NWNX_PushArgumentInt(NWNX_Feedback, sFunc, 0);
    NWNX_PushArgumentInt(NWNX_Feedback, sFunc, nMessageType);
    NWNX_PushArgumentObject(NWNX_Feedback, sFunc, oPC);
    NWNX_CallFunction(NWNX_Feedback, sFunc);
}

void NWNX_Feedback_SetFeedbackMessageMode(int bWhitelist)
{
    string sFunc = "SetFeedbackMode";
    int nMessageType = 0;

    NWNX_PushArgumentInt(NWNX_Feedback, sFunc, bWhitelist);
    NWNX_PushArgumentInt(NWNX_Feedback, sFunc, nMessageType);
    NWNX_CallFunction(NWNX_Feedback, sFunc);
}

void NWNX_Feedback_SetCombatLogMessageMode(int bWhitelist)
{
    string sFunc = "SetFeedbackMode";
    int nMessageType = 1;

    NWNX_PushArgumentInt(NWNX_Feedback, sFunc, bWhitelist);
    NWNX_PushArgumentInt(NWNX_Feedback, sFunc, nMessageType);
    NWNX_CallFunction(NWNX_Feedback, sFunc);
}
