/// @addtogroup player
/// @{
/// @file nwnx_player_qbs.nss
/// @brief Helper script for quickbar management.
#include "nwnx_player"

/// @name Quickbar Slot Types
/// @anchor qbs_types
/// @{
const int NWNX_PLAYER_QBS_TYPE_EMPTY                        = 0;
const int NWNX_PLAYER_QBS_TYPE_ITEM                         = 1;
const int NWNX_PLAYER_QBS_TYPE_SPELL                        = 2;
const int NWNX_PLAYER_QBS_TYPE_SKILL                        = 3;
const int NWNX_PLAYER_QBS_TYPE_FEAT                         = 4;
const int NWNX_PLAYER_QBS_TYPE_DIALOG                       = 6;
const int NWNX_PLAYER_QBS_TYPE_ATTACK                       = 7;
const int NWNX_PLAYER_QBS_TYPE_EMOTE                        = 8;
const int NWNX_PLAYER_QBS_TYPE_ITEM_PROPERTY_CASTSPELL      = 9;
const int NWNX_PLAYER_QBS_TYPE_MODE_TOGGLE                  = 10;
const int NWNX_PLAYER_QBS_TYPE_COMMAND                      = 18;
const int NWNX_PLAYER_QBS_TYPE_POSSESS_FAMILIAR             = 38;
const int NWNX_PLAYER_QBS_TYPE_ASSOCIATE_COMMAND            = 39;
const int NWNX_PLAYER_QBS_TYPE_EXAMINE                      = 40;
const int NWNX_PLAYER_QBS_TYPE_BARTER                       = 41;
const int NWNX_PLAYER_QBS_TYPE_QUICK_CHAT                   = 42;
const int NWNX_PLAYER_QBS_TYPE_CANCELPOLYMORPH              = 43;
const int NWNX_PLAYER_QBS_TYPE_SPELLLIKEABILITY             = 44;
/// @}

/// Create an empty QBS of given type
struct NWNX_Player_QuickBarSlot NWNX_Player_QBS_Empty(int type = NWNX_PLAYER_QBS_TYPE_EMPTY);
/// Create a QBS for using an item
struct NWNX_Player_QuickBarSlot NWNX_Player_QBS_UseItem(object oItem, int nPropertyID = 0);
/// Create a QBS for equipping an item
struct NWNX_Player_QuickBarSlot NWNX_Player_QBS_EquipItem(object oItem, object oSecondaryItem = OBJECT_INVALID);
/// Create a QBS for casting a spell
struct NWNX_Player_QuickBarSlot NWNX_Player_QBS_CastSpell(int nSpell, int nClassIndex = 0, int nMetamagic = METAMAGIC_NONE, int nDomainLevel = -1);
/// Create a QBS for using a skill
struct NWNX_Player_QuickBarSlot NWNX_Player_QBS_UseSkill(int nSkill);
/// Create a QBS for using a feat
struct NWNX_Player_QuickBarSlot NWNX_Player_QBS_UseFeat(int nFeat);
/// Create a QBS for starting a dialog
struct NWNX_Player_QuickBarSlot NWNX_Player_QBS_StartDialog();
/// Create a QBS for attacking
struct NWNX_Player_QuickBarSlot NWNX_Player_QBS_Attack();
/// Create a QBS for emoting
struct NWNX_Player_QuickBarSlot NWNX_Player_QBS_Emote(int nEmote);
/// Create a QBS for toggling a mode
struct NWNX_Player_QuickBarSlot NWNX_Player_QBS_ToggleMode(int nMode);
/// Create a QBS for examining
struct NWNX_Player_QuickBarSlot NWNX_Player_QBS_Examine();
/// Create a QBS for bartering
struct NWNX_Player_QuickBarSlot NWNX_Player_QBS_Barter();
/// Create a QBS for quickchat command
struct NWNX_Player_QuickBarSlot NWNX_Player_QBS_QuickChat(int nCommand);
/// Create a QBS for examining
struct NWNX_Player_QuickBarSlot NWNX_Player_QBS_PossessFamiliar();
/// Create a QBS for casting a spell
struct NWNX_Player_QuickBarSlot NWNX_Player_QBS_UseSpecialAbility(int nSpell, int nCasterLevel);
/// Create a QBS for running a command
struct NWNX_Player_QuickBarSlot NWNX_Player_QBS_Command(string sCommandLabel, string sCommandLine);

/// @}


struct NWNX_Player_QuickBarSlot NWNX_Player_QBS_Empty(int type = NWNX_PLAYER_QBS_TYPE_EMPTY)
{
    struct NWNX_Player_QuickBarSlot qbs;

    qbs.nObjectType    = type;

    qbs.oItem          = OBJECT_INVALID;
    qbs.oSecondaryItem = OBJECT_INVALID;
    qbs.nMultiClass    = 0;
    qbs.sResRef        = "";
    qbs.sCommandLabel  = "";
    qbs.sCommandLine   = "";
    qbs.sToolTip       = "";
    qbs.nINTParam1     = 0;
    qbs.nMetaType      = 0;
    qbs.nDomainLevel   = 0;
    qbs.nAssociateType = 0;
    qbs.oAssociate     = OBJECT_INVALID;

    return qbs;
}

struct NWNX_Player_QuickBarSlot NWNX_Player_QBS_UseItem(object oItem, int nPropertyID = 0)
{
    struct NWNX_Player_QuickBarSlot qbs = NWNX_Player_QBS_Empty(NWNX_PLAYER_QBS_TYPE_ITEM);

    qbs.oItem          = oItem;
    qbs.nINTParam1     = nPropertyID;

    return qbs;
}

struct NWNX_Player_QuickBarSlot NWNX_Player_QBS_EquipItem(object oItem, object oSecondaryItem = OBJECT_INVALID)
{
    struct NWNX_Player_QuickBarSlot qbs = NWNX_Player_QBS_Empty(NWNX_PLAYER_QBS_TYPE_ITEM);

    qbs.oItem          = oItem;
    qbs.oSecondaryItem = oSecondaryItem;

    return qbs;
}

struct NWNX_Player_QuickBarSlot NWNX_Player_QBS_CastSpell(int nSpell, int nClassIndex = 0, int nMetamagic = METAMAGIC_NONE, int nDomainLevel = -1)
{
    struct NWNX_Player_QuickBarSlot qbs = NWNX_Player_QBS_Empty(NWNX_PLAYER_QBS_TYPE_SPELL);

    qbs.nINTParam1     = nSpell;
    qbs.nMultiClass    = nClassIndex;
    qbs.nMetaType      = nMetamagic;
    qbs.nDomainLevel   = nDomainLevel;

    return qbs;
}

struct NWNX_Player_QuickBarSlot NWNX_Player_QBS_UseSkill(int nSkill)
{
    struct NWNX_Player_QuickBarSlot qbs = NWNX_Player_QBS_Empty(NWNX_PLAYER_QBS_TYPE_SKILL);

    qbs.nINTParam1     = nSkill;

    return qbs;
}

struct NWNX_Player_QuickBarSlot NWNX_Player_QBS_UseFeat(int nFeat)
{
    struct NWNX_Player_QuickBarSlot qbs = NWNX_Player_QBS_Empty(NWNX_PLAYER_QBS_TYPE_FEAT);

    qbs.nINTParam1     = nFeat;

    return qbs;
}

struct NWNX_Player_QuickBarSlot NWNX_Player_QBS_StartDialog()
{
    return NWNX_Player_QBS_Empty(NWNX_PLAYER_QBS_TYPE_DIALOG);
}

struct NWNX_Player_QuickBarSlot NWNX_Player_QBS_Attack()
{
    return NWNX_Player_QBS_Empty(NWNX_PLAYER_QBS_TYPE_ATTACK);
}

struct NWNX_Player_QuickBarSlot NWNX_Player_QBS_Emote(int nEmote)
{
    struct NWNX_Player_QuickBarSlot qbs = NWNX_Player_QBS_Empty(NWNX_PLAYER_QBS_TYPE_EMOTE);

    qbs.nINTParam1     = nEmote;

    return qbs;
}

struct NWNX_Player_QuickBarSlot NWNX_Player_QBS_ToggleMode(int nMode)
{
    struct NWNX_Player_QuickBarSlot qbs = NWNX_Player_QBS_Empty(NWNX_PLAYER_QBS_TYPE_MODE_TOGGLE);

    qbs.nINTParam1     = nMode;

    return qbs;
}

struct NWNX_Player_QuickBarSlot NWNX_Player_QBS_Examine()
{
    return NWNX_Player_QBS_Empty(NWNX_PLAYER_QBS_TYPE_EXAMINE);
}

struct NWNX_Player_QuickBarSlot NWNX_Player_QBS_Barter()
{
    return NWNX_Player_QBS_Empty(NWNX_PLAYER_QBS_TYPE_BARTER);
}

struct NWNX_Player_QuickBarSlot NWNX_Player_QBS_QuickChat(int nCommand)
{
    struct NWNX_Player_QuickBarSlot qbs = NWNX_Player_QBS_Empty(NWNX_PLAYER_QBS_TYPE_QUICK_CHAT);

    qbs.nINTParam1     = nCommand;

    return qbs;
}

struct NWNX_Player_QuickBarSlot NWNX_Player_QBS_PossessFamiliar()
{
    return NWNX_Player_QBS_Empty(NWNX_PLAYER_QBS_TYPE_POSSESS_FAMILIAR);
}

struct NWNX_Player_QuickBarSlot NWNX_Player_QBS_UseSpecialAbility(int nSpell, int nCasterLevel)
{
    struct NWNX_Player_QuickBarSlot qbs = NWNX_Player_QBS_Empty(NWNX_PLAYER_QBS_TYPE_SPELL);

    qbs.nINTParam1     = nSpell;
    qbs.nDomainLevel   = nCasterLevel;

    return qbs;
}
struct NWNX_Player_QuickBarSlot NWNX_Player_QBS_Command(string sCommandLabel, string sCommandLine)
{
    struct NWNX_Player_QuickBarSlot qbs = NWNX_Player_QBS_Empty(NWNX_PLAYER_QBS_TYPE_COMMAND);

    qbs.sCommandLabel     = sCommandLabel;
    qbs.sCommandLine      = sCommandLine;

    return qbs;
}
