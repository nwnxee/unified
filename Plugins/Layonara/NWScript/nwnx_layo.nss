#include "nwnx"

const string NWNX_Layonara = "NWNX_Layonara";

// Set the slots you can equip a base item
void NWNX_Layonara_SetEquippableSlots(int nBaseItem, int nSlots);

// Sets a feat as hostile
void NWNX_Layonara_SetHostileFeat(int nFeatID, int bHostile);

void NWNX_Layonara_SetEquippableSlots(int nBaseItem, int nSlots)
{
    string sFunc = "SetEquippableSlots";

    NWNX_PushArgumentInt(NWNX_Layonara, sFunc, nSlots);
    NWNX_PushArgumentInt(NWNX_Layonara, sFunc, nBaseItem);

    NWNX_CallFunction(NWNX_Layonara, sFunc);
}

void NWNX_Layonara_SetHostileFeat(int nFeatID, int bHostile)
{
    string sFunc = "SetHostileFeat";

    NWNX_PushArgumentInt(NWNX_Layonara, sFunc, bHostile);
    NWNX_PushArgumentInt(NWNX_Layonara, sFunc, nFeatID);

    NWNX_CallFunction(NWNX_Layonara, sFunc);
}
