#include "nwnx_player"
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
    float fDefaultTalk = NWNX_Player_GetChatHearingDistance();
    NWNX_Player_SetChatHearingDistance(OBJECT_INVALID, fDefaultTalk + 10.0f, NWNX_CHAT_CHANNEL_PLAYER_TALK);

    NWNX_Tests_Report("NWNX_Player", "SetChatHearingDistance Default", fDefaultTalk == NWNX_Player_GetChatHearingDistance() - 10.0f);

    float fPCWhisper = NWNX_Player_GetChatHearingDistance(oPC, NWNX_CHAT_CHANNEL_PLAYER_WHISPER);
    NWNX_Player_SetChatHearingDistance(oPC, fPCWhisper + 2.0f, NWNX_CHAT_CHANNEL_PLAYER_WHISPER);

    NWNX_Tests_Report("NWNX_Player", "SetChatHearingDistance Per PC", fPCWhisper == NWNX_Player_GetChatHearingDistance(oPC, NWNX_CHAT_CHANNEL_PLAYER_WHISPER) - 2.0f);
    WriteTimestampedLogEntry("NWNX_Player unit test end.");
}
