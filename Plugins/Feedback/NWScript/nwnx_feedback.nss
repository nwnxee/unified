#include "nwnx"

// Gets if feedback message nMessage is hidden.
// Notes:
// If oPC == OBJECT_INVALID it will return the global state:
//    TRUE      nMessage is globally hidden
//    FALSE     nMessage is not globally hidden
// If oPC is a valid player it will return the personal state:
//    TRUE      nMessage is hidden for oPC
//    FALSE     nMessage is not hidden for oPC
//    -1        Personal state is not set
int NWNX_Feedback_GetFeedbackMessageHidden(int nMessage, object oPC = OBJECT_INVALID);

// Sets if feedback message nMessage is hidden.
// Notes:
// If oPC == OBJECT_INVALID it will set the global state:
//    TRUE      nMessage is globally hidden
//    FALSE     nMessage is not globally hidden
// If oPC is a valid player it will set the personal state:
//    TRUE      nMessage is hidden for oPC
//    FALSE     nMessage is not hidden for oPC
//    -1        Remove the personal state
//
// Personal state overrides the global state which means if a global state is set
// to TRUE but the personal state is set to FALSE, the message will be shown to oPC
void NWNX_Feedback_SetFeedbackMessageHidden(int nMessage, int nState, object oPC = OBJECT_INVALID);

// Gets if combatlog message nMessage is hidden.
// Notes:
// If oPC == OBJECT_INVALID it will return the global state:
//    TRUE      nMessage is globally hidden
//    FALSE     nMessage is not globally hidden
// If oPC is a valid player it will return the personal state:
//    TRUE      nMessage is hidden for oPC
//    FALSE     nMessage is not hidden for oPC
//    -1        Personal state is not set
int NWNX_Feedback_GetCombatLogMessageHidden(int nMessage, object oPC = OBJECT_INVALID);

// Sets if combatlog message nMessage is hidden.
// Notes:
// If oPC == OBJECT_INVALID it will set the global state:
//    TRUE      nMessage is globally hidden
//    FALSE     nMessage is not globally hidden
// If oPC is a valid player it will set the personal state:
//    TRUE      nMessage is hidden for oPC
//    FALSE     nMessage is not hidden for oPC
//    -1        Remove the personal state
//
// Personal state overrides the global state which means if a global state is set
// to TRUE but the personal state is set to FALSE, the message will be shown to oPC
void NWNX_Feedback_SetCombatLogMessageHidden(int nMessage, int nState, object oPC = OBJECT_INVALID);

// ***
// For a list of the various combatlog / feedback messages see below.
// ***

const string NWNX_Feedback = "NWNX_Feedback";


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

void NWNX_Feedback_SetFeedbackMessageHidden(int nMessage, int nState, object oPC = OBJECT_INVALID)
{
    string sFunc = "SetMessageHidden";
    int nMessageType = 0;

    NWNX_PushArgumentInt(NWNX_Feedback, sFunc, nState);
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

void NWNX_Feedback_SetCombatLogMessageHidden(int nMessage, int nState, object oPC = OBJECT_INVALID)
{
    string sFunc = "SetMessageHidden";
    int nMessageType = 1;

    NWNX_PushArgumentInt(NWNX_Feedback, sFunc, nState);
    NWNX_PushArgumentInt(NWNX_Feedback, sFunc, nMessage);
    NWNX_PushArgumentInt(NWNX_Feedback, sFunc, nMessageType);
    NWNX_PushArgumentObject(NWNX_Feedback, sFunc, oPC);
    NWNX_CallFunction(NWNX_Feedback, sFunc);
}

/*
// CombatLog Messages
// For use with NWNX_Feedback_GetCombatLogMessageHidden() and
//              NWNX_Feedback_GetCombatLogMessageHidden()

const int COMBATLOG_SIMPLE_ADJECTIVE    = 1;
const int COMBATLOG_SIMPLE_DAMAGE       = 2;
const int COMBATLOG_COMPLEX_DAMAGE      = 3;
const int COMBATLOG_COMPLEX_DEATH       = 4;
const int COMBATLOG_COMPLEX_ATTACK      = 5;
const int COMBATLOG_SPECIAL_ATTACK      = 6;
const int COMBATLOG_SAVING_THROW        = 7;
const int COMBATLOG_CAST_SPELL          = 8;
const int COMBATLOG_USE_SKILL           = 9;
const int COMBATLOG_SPELL_RESISTANCE    = 10;
const int COMBATLOG_FEEDBACK            = 11; // NOTE: This hides ALL feedback messages, to hide individual messages use NWNX_Feedback_SetFeedbackMessageHidden()
const int COMBATLOG_COUNTERSPELL        = 12;
const int COMBATLOG_TOUCHATTACK         = 13;
const int COMBATLOG_INITIATIVE          = 14;
const int COMBATLOG_DISPEL_MAGIC        = 15;
const int COMBATLOG_POLYMORPH           = 17;
const int COMBATLOG_FEEDBACKSTRING      = 18;
const int COMBATLOG_VIBRATE             = 19;
const int COMBATLOG_UNLOCKACHIEVEMENT   = 20;

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
// 18 -> Same as 11, probably, maybe
// 19 -> Unused
// 20 -> Unused
*/

/*
// Feedback Messages
// For use with NWNX_Feedback_GetFeedbackMessageHidden() and
//              NWNX_Feedback_GetFeedbackMessageHidden()

// Skill Feedback Messages
const int FEEDBACK_SKILL_CANT_USE                     = 0;
const int FEEDBACK_SKILL_CANT_USE_TIMER               = 1;
const int FEEDBACK_SKILL_ANIMALEMPATHY_VALID_TARGETS  = 2;
const int FEEDBACK_SKILL_TAUNT_VALID_TARGETS          = 3;
const int FEEDBACK_SKILL_TAUNT_TARGET_IMMUNE          = 223;
const int FEEDBACK_SKILL_PICKPOCKET_STOLE_ITEM        = 4;
const int FEEDBACK_SKILL_PICKPOCKET_STOLE_GOLD        = 5;
const int FEEDBACK_SKILL_PICKPOCKET_ATTEMPTING_TO_STEAL = 46;
const int FEEDBACK_SKILL_PICKPOCKET_ATTEMPT_DETECTED  = 150;
const int FEEDBACK_SKILL_PICKPOCKET_STOLE_ITEM_TARGET = 47;
const int FEEDBACK_SKILL_PICKPOCKET_STOLE_GOLD_TARGET = 48;
const int FEEDBACK_SKILL_PICKPOCKET_TARGET_BROKE      = 57;
const int FEEDBACK_SKILL_HEAL_TARGET_NOT_DISPSND      = 55;
const int FEEDBACK_SKILL_HEAL_VALID_TARGETS           = 56;
const int FEEDBACK_SKILL_STEALTH_IN_COMBAT            = 60;

// Miscellaneous Targetting Messages
const int FEEDBACK_TARGET_UNAWARE                     = 6;
const int FEEDBACK_ACTION_NOT_POSSIBLE_STATUS         = 7;
const int FEEDBACK_ACTION_NOT_POSSIBLE_PVP            = 187;
const int FEEDBACK_ACTION_CANT_REACH_TARGET           = 218;
const int FEEDBACK_ACTION_NO_LOOT                     = 247;

// Miscellaneous Feedback Messages
const int FEEDBACK_WEIGHT_TOO_ENCUMBERED_TO_RUN       = 8;
const int FEEDBACK_WEIGHT_TOO_ENCUMBERED_WALK_SLOW    = 9;
const int FEEDBACK_WEIGHT_TOO_ENCUMBERED_CANT_PICKUP  = 10;
const int FEEDBACK_STATS_LEVELUP                      = 11;
const int FEEDBACK_INVENTORY_FULL                     = 12;
const int FEEDBACK_CONTAINER_FULL                     = 212;
const int FEEDBACK_TRAP_TRIGGERED                     = 82;
const int FEEDBACK_DAMAGE_HEALED                      = 151;
const int FEEDBACK_EXPERIENCE_GAINNED                 = 182;
const int FEEDBACK_EXPERIENCE_LOST                    = 183;
const int FEEDBACK_JOURNALUPDATED                     = 184;
const int FEEDBACK_BARTER_CANCELLED                   = 185;

// Mode activation/deactivation Messages
const int FEEDBACK_DETECT_MODE_ACTIVATED              = 83;
const int FEEDBACK_DETECT_MODE_DEACTIVATED            = 84;
const int FEEDBACK_STEALTH_MODE_ACTIVATED             = 85;
const int FEEDBACK_STEALTH_MODE_DEACTIVATED           = 86;
const int FEEDBACK_PARRY_MODE_ACTIVATED               = 87;
const int FEEDBACK_PARRY_MODE_DEACTIVATED             = 88;
const int FEEDBACK_POWER_ATTACK_MODE_ACTIVATED        = 89;
const int FEEDBACK_POWER_ATTACK_MODE_DEACTIVATED      = 90;
const int FEEDBACK_IMPROVED_POWER_ATTACK_MODE_ACTIVATED = 91;
const int FEEDBACK_IMPROVED_POWER_ATTACK_MODE_DEACTIVATED = 92;
const int FEEDBACK_RAPID_SHOT_MODE_ACTIVATED          = 166;
const int FEEDBACK_RAPID_SHOT_MODE_DEACTIVATED        = 167;
const int FEEDBACK_FLURRY_OF_BLOWS_MODE_ACTIVATED     = 168;
const int FEEDBACK_FLURRY_OF_BLOWS_MODE_DEACTIVATED   = 169;
const int FEEDBACK_EXPERTISE_MODE_ACTIVATED           = 227;
const int FEEDBACK_EXPERTISE_MODE_DEACTIVATED         = 228;
const int FEEDBACK_IMPROVED_EXPERTISE_MODE_ACTIVATED  = 229;
const int FEEDBACK_IMPROVED_EXPERTISE_MODE_DEACTIVATED = 230;
const int FEEDBACK_DEFENSIVE_CAST_MODE_ACTIVATED      = 231;
const int FEEDBACK_DEFENSIVE_CAST_MODE_DEACTIVATED    = 232;
const int FEEDBACK_MODE_CANNOT_USE_WEAPONS            = 188;
const int FEEDBACK_DIRTY_FIGHTING_MODE_ACTIVATED      = 237;
const int FEEDBACK_DIRTY_FIGHTING_MODE_DEACTIVATED    = 238;

const int FEEDBACK_DEFENSIVE_STANCE_MODE_ACTIVATED      = 252;
const int FEEDBACK_DEFENSIVE_STANCE_MODE_DEACTIVATED    = 253;

// Equipping Feedback Messages
const int FEEDBACK_EQUIP_SKILL_SPELL_MODIFIERS        = 71;
const int FEEDBACK_EQUIP_UNIDENTIFIED                 = 76;
const int FEEDBACK_EQUIP_MONK_ABILITIES               = 77;
const int FEEDBACK_EQUIP_INSUFFICIENT_LEVEL           = 98;
const int FEEDBACK_EQUIP_PROFICIENCIES                = 119;
const int FEEDBACK_EQUIP_WEAPON_TOO_LARGE             = 120;
const int FEEDBACK_EQUIP_WEAPON_TOO_SMALL             = 260;
const int FEEDBACK_EQUIP_ONE_HANDED_WEAPON            = 121;
const int FEEDBACK_EQUIP_TWO_HANDED_WEAPON            = 122;
const int FEEDBACK_EQUIP_WEAPON_SWAPPED_OUT           = 123;
const int FEEDBACK_EQUIP_ONE_CHAIN_WEAPON             = 124;
const int FEEDBACK_EQUIP_NATURAL_AC_NO_STACK          = 189;
const int FEEDBACK_EQUIP_ARMOUR_AC_NO_STACK           = 190;
const int FEEDBACK_EQUIP_SHIELD_AC_NO_STACK           = 191;
const int FEEDBACK_EQUIP_DEFLECTION_AC_NO_STACK       = 192;
const int FEEDBACK_EQUIP_NO_ARMOR_COMBAT              = 193;
const int FEEDBACK_EQUIP_RANGER_ABILITIES             = 200;
const int FEEDBACK_EQUIP_ALIGNMENT                    = 207;
const int FEEDBACK_EQUIP_CLASS                        = 208;
const int FEEDBACK_EQUIP_RACE                         = 209;
const int FEEDBACK_UNEQUIP_NO_ARMOR_COMBAT            = 194;

// Action Feedback Messages
const int FEEDBACK_OBJECT_LOCKED                      = 13;
const int FEEDBACK_OBJECT_NOT_LOCKED                  = 14;
const int FEEDBACK_OBJECT_SPECIAL_KEY                 = 15;
const int FEEDBACK_OBJECT_USED_KEY                    = 16;
const int FEEDBACK_REST_EXCITED_CANT_REST             = 17;
const int FEEDBACK_REST_BEGINNING_REST                = 18;
const int FEEDBACK_REST_FINISHED_REST                 = 19;
const int FEEDBACK_REST_CANCEL_REST                   = 20;
const int FEEDBACK_REST_NOT_ALLOWED_IN_AREA           = 54;
const int FEEDBACK_REST_NOT_ALLOWED_BY_POSSESSED_FAMILIAR = 153;
const int FEEDBACK_REST_NOT_ALLOWED_ENEMIES           = 186;
const int FEEDBACK_REST_CANT_UNDER_THIS_EFFECT        = 213;
const int FEEDBACK_CAST_LOST_TARGET                   = 21;
const int FEEDBACK_CAST_CANT_CAST                     = 22;
const int FEEDBACK_CAST_CNTRSPELL_TARGET_LOST_TARGET  = 52;
const int FEEDBACK_CAST_ARCANE_SPELL_FAILURE          = 61;
const int FEEDBACK_CAST_CNTRSPELL_TARGET_ARCANE_SPELL_FAILURE = 118;
const int FEEDBACK_CAST_ENTANGLE_CONCENTRATION_FAILURE = 65;
const int FEEDBACK_CAST_CNTRSPELL_TARGET_ENTANGLE_CONCENTRATION_FAILURE = 147;
const int FEEDBACK_CAST_SPELL_INTERRUPTED             = 72;
const int FEEDBACK_CAST_EFFECT_SPELL_FAILURE          = 236;
const int FEEDBACK_CAST_CANT_CAST_WHILE_POLYMORPHED   = 107;
const int FEEDBACK_CAST_USE_HANDS                     = 210;
const int FEEDBACK_CAST_USE_MOUTH                     = 211;
const int FEEDBACK_CAST_DEFCAST_CONCENTRATION_FAILURE = 233;
const int FEEDBACK_CAST_DEFCAST_CONCENTRATION_SUCCESS = 240;
const int FEEDBACK_USEITEM_CANT_USE                   = 23;
const int FEEDBACK_CONVERSATION_TOOFAR                = 58;
const int FEEDBACK_CONVERSATION_BUSY                  = 59;
const int FEEDBACK_CONVERSATION_IN_COMBAT             = 152;
const int FEEDBACK_CHARACTER_INTRANSIT                = 74;
const int FEEDBACK_CHARACTER_OUTTRANSIT               = 75;
const int FEEDBACK_USEITEM_NOT_EQUIPPED               = 244;
const int FEEDBACK_DROPITEM_CANT_DROP                 = 245;
const int FEEDBACK_DROPITEM_CANT_GIVE                 = 246;
const int FEEDBACK_CLIENT_SERVER_SPELL_MISMATCH       = 259;

// Combat feedback messages
const int FEEDBACK_COMBAT_RUNNING_OUT_OF_AMMO         = 24;
const int FEEDBACK_COMBAT_OUT_OF_AMMO                 = 25;
const int FEEDBACK_COMBAT_HENCHMAN_OUT_OF_AMMO        = 241;
const int FEEDBACK_COMBAT_DAMAGE_IMMUNITY             = 62;
const int FEEDBACK_COMBAT_SPELL_IMMUNITY              = 68;
const int FEEDBACK_COMBAT_DAMAGE_RESISTANCE           = 63;
const int FEEDBACK_COMBAT_DAMAGE_RESISTANCE_REMAINING = 66;
const int FEEDBACK_COMBAT_DAMAGE_REDUCTION            = 64;
const int FEEDBACK_COMBAT_DAMAGE_REDUCTION_REMAINING  = 67;
const int FEEDBACK_COMBAT_SPELL_LEVEL_ABSORPTION      = 69;
const int FEEDBACK_COMBAT_SPELL_LEVEL_ABSORPTION_REMAINING = 70;
const int FEEDBACK_COMBAT_WEAPON_NOT_EFFECTIVE        = 117;
const int FEEDBACK_COMBAT_EPIC_DODGE_ATTACK_EVADED    = 234;
const int FEEDBACK_COMBAT_MASSIVE_DAMAGE              = 235;
const int FEEDBACK_COMBAT_SAVED_VS_MASSIVE_DAMAGE     = 254;
const int FEEDBACK_COMBAT_SAVED_VS_DEVASTATING_CRITICAL = 257;

// Feat Feedback Messages
const int FEEDBACK_FEAT_SAP_VALID_TARGETS             = 26;
const int FEEDBACK_FEAT_KNOCKDOWN_VALID_TARGETS       = 27;
const int FEEDBACK_FEAT_IMPKNOCKDOWN_VALID_TARGETS    = 28;
const int FEEDBACK_FEAT_CALLED_SHOT_NO_LEGS           = 29;
const int FEEDBACK_FEAT_CALLED_SHOT_NO_ARMS           = 30;
const int FEEDBACK_FEAT_SMITE_GOOD_TARGET_NOT_GOOD    = 239;
const int FEEDBACK_FEAT_SMITE_EVIL_TARGET_NOT_EVIL    = 53;
const int FEEDBACK_FEAT_QUIVERING_PALM_HIGHER_LEVEL   = 73;
const int FEEDBACK_FEAT_KEEN_SENSE_DETECT             = 195;
const int FEEDBACK_FEAT_USE_UNARMED                   = 198;
const int FEEDBACK_FEAT_USES                          = 199;
const int FEEDBACK_FEAT_USE_WEAPON_OF_CHOICE          = 243;

// Party Feedback Messages
const int FEEDBACK_PARTY_NEW_LEADER                   = 31;
const int FEEDBACK_PARTY_MEMBER_KICKED                = 32;
const int FEEDBACK_PARTY_KICKED_YOU                   = 33;
const int FEEDBACK_PARTY_ALREADY_CONSIDERING          = 34;
const int FEEDBACK_PARTY_ALREADY_INVOLVED             = 35;
const int FEEDBACK_PARTY_SENT_INVITATION              = 36;
const int FEEDBACK_PARTY_RECEIVED_INVITATION          = 37;
const int FEEDBACK_PARTY_JOINED                       = 38;
const int FEEDBACK_PARTY_INVITATION_IGNORED           = 39;
const int FEEDBACK_PARTY_YOU_IGNORED_INVITATION       = 40;
const int FEEDBACK_PARTY_INVITATION_REJECTED          = 41;
const int FEEDBACK_PARTY_YOU_REJECTED_INVITATION      = 42;
const int FEEDBACK_PARTY_INVITATION_EXPIRED           = 43;
const int FEEDBACK_PARTY_LEFT_PARTY                   = 44;
const int FEEDBACK_PARTY_YOU_LEFT                     = 45;
const int FEEDBACK_PARTY_HENCHMAN_LIMIT               = 49;
const int FEEDBACK_PARTY_CANNOT_LEAVE_THE_ONE_PARTY   = 196;
const int FEEDBACK_PARTY_CANNOT_KICK_FROM_THE_ONE_PARTY = 197;
const int FEEDBACK_PARTY_YOU_INVITED_NON_SINGLETON    = 202;
const int FEEDBACK_PVP_REACTION_DISLIKESYOU           = 203;

// Item Feedback Messages
const int FEEDBACK_ITEM_RECEIVED                      = 50;
const int FEEDBACK_ITEM_LOST                          = 51;
const int FEEDBACK_ITEM_EJECTED                       = 96;
const int FEEDBACK_ITEM_USE_UNIDENTIFIED              = 97;
const int FEEDBACK_ITEM_GOLD_GAINED                   = 148;
const int FEEDBACK_ITEM_GOLD_LOST                     = 149;

// Spell Scroll Learning
const int FEEDBACK_LEARN_SCROLL_NOT_SCROLL            = 78;
const int FEEDBACK_LEARN_SCROLL_CANT_LEARN_CLASS      = 79;
const int FEEDBACK_LEARN_SCROLL_CANT_LEARN_LEVEL      = 80;
const int FEEDBACK_LEARN_SCROLL_CANT_LEARN_ABILITY    = 81;
const int FEEDBACK_LEARN_SCROLL_CANT_LEARN_OPPOSITION = 219;
const int FEEDBACK_LEARN_SCROLL_CANT_LEARN_POSSESS    = 220;
const int FEEDBACK_LEARN_SCROLL_CANT_LEARN_KNOWN      = 221;
const int FEEDBACK_LEARN_SCROLL_CANT_LEARN_DIVINE     = 224;
const int FEEDBACK_LEARN_SCROLL_SUCCESS               = 222;

// Floaty text feedback
const int FEEDBACK_FLOATY_TEXT_STRREF                 = 93;
const int FEEDBACK_FLOATY_TEXT_STRING                 = 94;

// store feedback
const int FEEDBACK_CANNOT_SELL_PLOT_ITEM              = 99;
const int FEEDBACK_CANNOT_SELL_CONTAINER              = 100;
const int FEEDBACK_CANNOT_SELL_ITEM                   = 101;
const int FEEDBACK_NOT_ENOUGH_GOLD                    = 102;
const int FEEDBACK_TRANSACTION_SUCCEEDED              = 103;
const int FEEDBACK_PRICE_TOO_HIGH                     = 248;
const int FEEDBACK_STORE_NOT_ENOUGH_GOLD              = 249;
const int FEEDBACK_CANNOT_SELL_STOLEN_ITEM            = 250;
const int FEEDBACK_CANNOT_SELL_RESTRICTED_ITEM        = 251;

// Portal control feedback
const int FEEDBACK_PORTAL_TIMEDOUT                    = 104;
const int FEEDBACK_PORTAL_INVALID                     = 105;

// Chat feedback
const int FEEDBACK_CHAT_TELL_PLAYER_NOT_FOUND         = 106;

// Alignment Feedback
const int FEEDBACK_ALIGNMENT_SHIFT                    = 108;
const int FEEDBACK_ALIGNMENT_PARTY_SHIFT              = 111;
const int FEEDBACK_ALIGNMENT_CHANGE                   = 109;
const int FEEDBACK_ALIGNMENT_RESTRICTED_BY_CLASS_LOST = 110;
const int FEEDBACK_ALIGNMENT_RESTRICTED_BY_CLASS_GAIN = 115;
const int FEEDBACK_ALIGNMENT_RESTRICTED_WARNING_LOSS  = 116;
const int FEEDBACK_ALIGNMENT_RESTRICTED_WARNING_GAIN  = 112;
const int FEEDBACK_ALIGNMENT_EPITOME_GAINED           = 113;
const int FEEDBACK_ALIGNMENT_EPITOME_LOST             = 114;

// Immunity Feedback
const int FEEDBACK_IMMUNITY_DISEASE                   = 125;
const int FEEDBACK_IMMUNITY_CRITICAL_HIT              = 126;
const int FEEDBACK_IMMUNITY_DEATH_MAGIC               = 127;
const int FEEDBACK_IMMUNITY_FEAR                      = 128;
const int FEEDBACK_IMMUNITY_KNOCKDOWN                 = 129;
const int FEEDBACK_IMMUNITY_PARALYSIS                 = 130;
const int FEEDBACK_IMMUNITY_NEGATIVE_LEVEL            = 131;
const int FEEDBACK_IMMUNITY_MIND_SPELLS               = 132;
const int FEEDBACK_IMMUNITY_POISON                    = 133;
const int FEEDBACK_IMMUNITY_SNEAK_ATTACK              = 134;
const int FEEDBACK_IMMUNITY_SLEEP                     = 135;
const int FEEDBACK_IMMUNITY_DAZE                      = 136;
const int FEEDBACK_IMMUNITY_CONFUSION                 = 137;
const int FEEDBACK_IMMUNITY_STUN                      = 138;
const int FEEDBACK_IMMUNITY_BLINDNESS                 = 139;
const int FEEDBACK_IMMUNITY_DEAFNESS                  = 140;
const int FEEDBACK_IMMUNITY_CURSE                     = 141;
const int FEEDBACK_IMMUNITY_CHARM                     = 142;
const int FEEDBACK_IMMUNITY_DOMINATE                  = 143;
const int FEEDBACK_IMMUNITY_ENTANGLE                  = 144;
const int FEEDBACK_IMMUNITY_SILENCE                   = 145;
const int FEEDBACK_IMMUNITY_SLOW                      = 146;

// Associates
const int FEEDBACK_ASSOCIATE_SUMMONED                 = 154;
const int FEEDBACK_ASSOCIATE_UNSUMMONING              = 155;
const int FEEDBACK_ASSOCIATE_UNSUMMONING_BECAUSE_REST = 156;
const int FEEDBACK_ASSOCIATE_UNSUMMONING_BECAUSE_DIED = 157;
const int FEEDBACK_ASSOCIATE_DOMINATED                = 158;
const int FEEDBACK_ASSOCIATE_DOMINATION_ENDED         = 159;
const int FEEDBACK_ASSOCIATE_POSSESSED_CANNOT_RECOVER_TRAP = 170;
const int FEEDBACK_ASSOCIATE_POSSESSED_CANNOT_BARTER  = 171;
const int FEEDBACK_ASSOCIATE_POSSESSED_CANNOT_EQUIP   = 172;
const int FEEDBACK_ASSOCIATE_POSSESSED_CANNOT_REPOSITORY_MOVE = 173;
const int FEEDBACK_ASSOCIATE_POSSESSED_CANNOT_PICK_UP = 174;
const int FEEDBACK_ASSOCIATE_POSSESSED_CANNOT_DROP    = 175;
const int FEEDBACK_ASSOCIATE_POSSESSED_CANNOT_UNEQUIP = 176;
const int FEEDBACK_ASSOCIATE_POSSESSED_CANNOT_REST    = 177;
const int FEEDBACK_ASSOCIATE_POSSESSED_CANNOT_DIALOGUE = 178;
const int FEEDBACK_ASSOCIATE_POSSESSED_CANNOT_GIVE_ITEM = 179;
const int FEEDBACK_ASSOCIATE_POSSESSED_CANNOT_TAKE_ITEM = 180;
const int FEEDBACK_ASSOCIATE_POSSESSED_CANNOT_USE_CONTAINER = 181;

const int FEEDBACK_SCRIPT_ERROR                       = 160;
const int FEEDBACK_ACTION_LIST_OVERFLOW               = 161;
const int FEEDBACK_EFFECT_LIST_OVERFLOW               = 162;
const int FEEDBACK_AI_UPDATE_TIME_OVERFLOW            = 163;
const int FEEDBACK_ACTION_LIST_WIPE_OVERFLOW          = 164;
const int FEEDBACK_EFFECT_LIST_WIPE_OVERFLOW          = 165;
const int FEEDBACK_SEND_MESSAGE_TO_PC                 = 204;
const int FEEDBACK_SEND_MESSAGE_TO_PC_STRREF          = 242;

// Misc GUI feedback
const int FEEDBACK_GUI_ONLY_PARTY_LEADER_MAY_CLICK    = 201;
const int FEEDBACK_PAUSED                             = 205;
const int FEEDBACK_UNPAUSED                           = 206;
const int FEEDBACK_REST_YOU_MAY_NOT_AT_THIS_TIME      = 214;
const int FEEDBACK_GUI_CHAR_EXPORT_REQUEST_SENT       = 215;
const int FEEDBACK_GUI_CHAR_EXPORTED_SUCCESSFULLY     = 216;
const int FEEDBACK_GUI_ERROR_CHAR_NOT_EXPORTED        = 217;
const int FEEDBACK_CAMERA_BG                          = 255;
const int FEEDBACK_CAMERA_EQ                          = 256;
const int FEEDBACK_CAMERA_CHASECAM                    = 258;

const int FEEDBACK_SAVING                             = 225;
const int FEEDBACK_SAVE_COMPLETE                      = 226;
*/
