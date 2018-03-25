#include "nwnx_player"

const int NWNX_PLAYER_QBS_TYPE_ITEM = 1;

struct NWNX_Player_QuickBarSlot NWNX_Player_QBS_Empty(int type)
{
    struct NWNX_Player_QuickBarSlot qbs;

    qbs.oItem          = OBJECT_INVALID;
    qbs.oSecondaryItem = OBJECT_INVALID;
    qbs.nObjectType    = type;
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
};


// Create a QBS for using an item
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
