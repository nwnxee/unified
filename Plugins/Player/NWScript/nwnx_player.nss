#include "nwnx"

// Force display placeable examine window for player
void NWNX_Player_ForcePlaceableExamineWindow(object player, object placeable);

const string NWNX_Player = "NWNX_Player";

void NWNX_Player_ForcePlaceableExamineWindow(object player, object placeable)
{
    string sFunc = "ForcePlaceableExamineWindow";
    NWNX_PushArgumentObject(NWNX_Player, sFunc, placeable);
    NWNX_PushArgumentObject(NWNX_Player, sFunc, player);

    NWNX_CallFunction(NWNX_Player, sFunc);
}

