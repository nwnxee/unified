#include "nwnx"

const string NWNX_Layonara = "NWNX_Layonara";

// Set the slots you can equip a base item
void NWNX_Layonara_SetEquippableSlots(int nBaseItem, int nSlots);

void NWNX_Layonara_SetEquippableSlots(int nBaseItem, int nSlots)
{
    string sFunc = "SetEquippableSlots";

    NWNX_PushArgumentInt(NWNX_Layonara, sFunc, nSlots);
    NWNX_PushArgumentInt(NWNX_Layonara, sFunc, nBaseItem);

    NWNX_CallFunction(NWNX_Layonara, sFunc);
}
