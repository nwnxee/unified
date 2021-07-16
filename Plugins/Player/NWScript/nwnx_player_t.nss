#include "nwnx_player"
#include "nwnx_consts"
#include "nwnx_tests"

void main()
{
    WriteTimestampedLogEntry("NWNX_Player unit test begin..");

    object oPC = GetFirstPC();
    if (!GetIsObjectValid(oPC))
    {
        WriteTimestampedLogEntry("NWNX_Player test: No PC found");
        return;
    }

    //
    // Player Attack Animation Override
    // Recommend hooking into Attack Event
    //

    //Ranged Weapon Check / Reverts to Normal Animation
    if (GetBaseItemType(GetItemInSlot(INVENTORY_SLOT_RIGHTHAND, oAttacker)) == BASE_ITEM_SHORTBOW)
        NWNX_Player_SetAttackAnimation(oAttacker, -1);
    //Otherwise, adjust Attack Animation
    else NWNX_Player_SetAttackAnimation(oAttacker, NWNX_Consts_TranslateNWScriptAnimation(ANIMATION_LOOPING_SPASM));

    //DelayCommand Recommended to return Attack state to original
    DelayCommand(0.1f, NWNX_Player_SetAttackAnimation(oAttacker, -1));

    WriteTimestampedLogEntry("NWNX_Player unit test end.");
}
