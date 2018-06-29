#include "nwnx"


struct NWNX_Player_QuickBarSlot
{
    object oItem;
    object oSecondaryItem;
    int    nObjectType;
    int    nMultiClass;
    string sResRef;
    string sCommandLabel;
    string sCommandLine;
    string sToolTip;
    int    nINTParam1;
    int    nMetaType;
    int    nDomainLevel;
    int    nAssociateType;
    object oAssociate;
};

// Force display placeable examine window for player
void NWNX_Player_ForcePlaceableExamineWindow(object player, object placeable);

// Starts displaying a timing bar.
// Will run a script at the end of the timing bar, if specified.
void NWNX_Player_StartGuiTimingBar(object player, float seconds, string script = "");

// Stops displaying a timing bar.
// Runs a script if specified.
void NWNX_Player_StopGuiTimingBar(object player, string script = "");

// Sets whether the player should always walk when given movement commands.
// If true, clicking on the ground or using WASD will trigger walking instead of running.
void NWNX_Player_SetAlwaysWalk(object player, int bWalk=TRUE);

// Gets the player's quickbar slot info
struct NWNX_Player_QuickBarSlot NWNX_Player_GetQuickBarSlot(object player, int slot);

// Sets a player's quickbar slot
void NWNX_Player_SetQuickBarSlot(object player, int slot, struct NWNX_Player_QuickBarSlot qbs);

// Get the name of the .bic file associated with the player's character.
string NWNX_Player_GetBicFileName(object player);

const string NWNX_Player = "NWNX_Player";

void NWNX_Player_ForcePlaceableExamineWindow(object player, object placeable)
{
    string sFunc = "ForcePlaceableExamineWindow";
    NWNX_PushArgumentObject(NWNX_Player, sFunc, placeable);
    NWNX_PushArgumentObject(NWNX_Player, sFunc, player);

    NWNX_CallFunction(NWNX_Player, sFunc);
}

void NWNX_Player_INTERNAL_StopGuiTimingBar(object player, string script = "", int id = -1)
{
    int activeId = GetLocalInt(player, "NWNX_PLAYER_GUI_TIMING_ACTIVE");
    // Either the timing event was never started, or it already finished.
    if (activeId == 0)
        return;

    // If id != -1, we ended up here through DelayCommand. Make sure it's for the right ID
    if (id != -1 && id != activeId)
        return;

    DeleteLocalInt(player, "NWNX_PLAYER_GUI_TIMING_ACTIVE");

    string sFunc = "StopGuiTimingBar";
    NWNX_PushArgumentObject(NWNX_Player, sFunc, player);
    NWNX_CallFunction(NWNX_Player, sFunc);

    if(script != "")
    {
        ExecuteScript(script, player);
    }
}

void NWNX_Player_StartGuiTimingBar(object player, float seconds, string script = "")
{
    // only one timing bar at a time!
    if (GetLocalInt(player, "NWNX_PLAYER_GUI_TIMING_ACTIVE"))
        return;

    string sFunc = "StartGuiTimingBar";
    NWNX_PushArgumentFloat(NWNX_Player, sFunc, seconds);
    NWNX_PushArgumentObject(NWNX_Player, sFunc, player);

    NWNX_CallFunction(NWNX_Player, sFunc);

    int id = GetLocalInt(player, "NWNX_PLAYER_GUI_TIMING_ID") + 1;
    SetLocalInt(player, "NWNX_PLAYER_GUI_TIMING_ACTIVE", id);
    SetLocalInt(player, "NWNX_PLAYER_GUI_TIMING_ID", id);

    DelayCommand(seconds, NWNX_Player_INTERNAL_StopGuiTimingBar(player, script, id));
}

void NWNX_Player_StopGuiTimingBar(object player, string script = "")
{
    NWNX_Player_INTERNAL_StopGuiTimingBar(player, script, -1);
}

void NWNX_Player_SetAlwaysWalk(object player, int bWalk=TRUE)
{
    string sFunc = "SetAlwaysWalk";
    NWNX_PushArgumentInt(NWNX_Player, sFunc, bWalk);
    NWNX_PushArgumentObject(NWNX_Player, sFunc, player);

    NWNX_CallFunction(NWNX_Player, sFunc);
}

struct NWNX_Player_QuickBarSlot NWNX_Player_GetQuickBarSlot(object player, int slot)
{
    string sFunc = "GetQuickBarSlot";
    struct NWNX_Player_QuickBarSlot qbs;

    NWNX_PushArgumentInt(NWNX_Player, sFunc, slot);
    NWNX_PushArgumentObject(NWNX_Player, sFunc, player);
    NWNX_CallFunction(NWNX_Player, sFunc);

     qbs.oAssociate     = NWNX_GetReturnValueObject(NWNX_Player, sFunc);
     qbs.nAssociateType = NWNX_GetReturnValueInt(NWNX_Player,    sFunc);
     qbs.nDomainLevel   = NWNX_GetReturnValueInt(NWNX_Player,    sFunc);
     qbs.nMetaType      = NWNX_GetReturnValueInt(NWNX_Player,    sFunc);
     qbs.nINTParam1     = NWNX_GetReturnValueInt(NWNX_Player,    sFunc);
     qbs.sToolTip       = NWNX_GetReturnValueString(NWNX_Player, sFunc);
     qbs.sCommandLine   = NWNX_GetReturnValueString(NWNX_Player, sFunc);
     qbs.sCommandLabel  = NWNX_GetReturnValueString(NWNX_Player, sFunc);
     qbs.sResRef        = NWNX_GetReturnValueString(NWNX_Player, sFunc);
     qbs.nMultiClass    = NWNX_GetReturnValueInt(NWNX_Player,    sFunc);
     qbs.nObjectType    = NWNX_GetReturnValueInt(NWNX_Player,    sFunc);
     qbs.oSecondaryItem = NWNX_GetReturnValueObject(NWNX_Player, sFunc);
     qbs.oItem          = NWNX_GetReturnValueObject(NWNX_Player, sFunc);

     return qbs;
}

void NWNX_Player_SetQuickBarSlot(object player, int slot, struct NWNX_Player_QuickBarSlot qbs)
{
    string sFunc = "SetQuickBarSlot";

    NWNX_PushArgumentObject(NWNX_Player, sFunc, qbs.oItem);
    NWNX_PushArgumentObject(NWNX_Player, sFunc, qbs.oSecondaryItem);
    NWNX_PushArgumentInt(NWNX_Player,    sFunc, qbs.nObjectType);
    NWNX_PushArgumentInt(NWNX_Player,    sFunc, qbs.nMultiClass);
    NWNX_PushArgumentString(NWNX_Player, sFunc, qbs.sResRef);
    NWNX_PushArgumentString(NWNX_Player, sFunc, qbs.sCommandLabel);
    NWNX_PushArgumentString(NWNX_Player, sFunc, qbs.sCommandLine);
    NWNX_PushArgumentString(NWNX_Player, sFunc, qbs.sToolTip);
    NWNX_PushArgumentInt(NWNX_Player,    sFunc, qbs.nINTParam1);
    NWNX_PushArgumentInt(NWNX_Player,    sFunc, qbs.nMetaType);
    NWNX_PushArgumentInt(NWNX_Player,    sFunc, qbs.nDomainLevel);
    NWNX_PushArgumentInt(NWNX_Player,    sFunc, qbs.nAssociateType);
    NWNX_PushArgumentObject(NWNX_Player, sFunc, qbs.oAssociate);

    NWNX_PushArgumentInt(NWNX_Player, sFunc, slot);
    NWNX_PushArgumentObject(NWNX_Player, sFunc, player);
    NWNX_CallFunction(NWNX_Player, sFunc);
}

string NWNX_Player_GetBicFileName(object player)
{
    string sFunc = "GetBicFileName";
    NWNX_PushArgumentObject(NWNX_Player, sFunc, player);
    NWNX_CallFunction(NWNX_Player, sFunc);
    return NWNX_GetReturnValueString(NWNX_Player, sFunc);
}