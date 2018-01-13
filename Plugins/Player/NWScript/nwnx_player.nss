#include "nwnx"

// Force display placeable examine window for player
void NWNX_Player_ForcePlaceableExamineWindow(object player, object placeable);

// Starts displaying a timing bar.
// Will run a script at the end of the timing bar, if specified.
void NWNX_Player_StartGuiTimingBar(object player, int seconds, string script = "");

// Stops displaying a timing bar.
// Runs a script if specified.
void NWNX_Player_StopGuiTimingBar(object player, string script = "");

const string NWNX_Player = "NWNX_Player";

void NWNX_Player_ForcePlaceableExamineWindow(object player, object placeable)
{
    string sFunc = "ForcePlaceableExamineWindow";
    NWNX_PushArgumentObject(NWNX_Player, sFunc, placeable);
    NWNX_PushArgumentObject(NWNX_Player, sFunc, player);

    NWNX_CallFunction(NWNX_Player, sFunc);
}

void NWNX_Player_StartGuiTimingBar(object player, int seconds, string script = "")
{
    string sFunc = "StartGuiTimingBar";
    NWNX_PushArgumentInt(NWNX_Player, sFunc, seconds);
    NWNX_PushArgumentObject(NWNX_Player, sFunc, player);

    NWNX_CallFunction(NWNX_Player, sFunc);

    DelayCommand(IntToFloat(seconds), NWNX_Player_StopGuiTimingBar(player, script));
}

void NWNX_Player_StopGuiTimingBar(object player, string script = "")
{
    string sFunc = "StopGuiTimingBar";
    NWNX_PushArgumentObject(NWNX_Player, sFunc, player);
    NWNX_CallFunction(NWNX_Player, sFunc);

    if(script != "")
    {
        ExecuteScript(script, player);
    }
}