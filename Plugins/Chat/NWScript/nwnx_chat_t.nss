#include "nwnx_chat"
#include "nwnx_tests"

void main()
{
    WriteTimestampedLogEntry("NWNX_Chat unit test begin..");

    float fDefaultTalk = NWNX_Chat_GetChatHearingDistance();
    NWNX_Chat_SetChatHearingDistance(fDefaultTalk + 10.0f);

    NWNX_Tests_Report("NWNX_Chat", "SetChatHearingDistance Default", fDefaultTalk == NWNX_Chat_GetChatHearingDistance() - 10.0f);

    object oPC = GetFirstPC();
    float fPCWhisper = NWNX_Chat_GetChatHearingDistance(oPC, NWNX_CHAT_CHANNEL_PLAYER_WHISPER);
    NWNX_Chat_SetChatHearingDistance(fPCWhisper + 2.0f, oPC, NWNX_CHAT_CHANNEL_PLAYER_WHISPER);

    NWNX_Tests_Report("NWNX_Chat", "SetChatHearingDistance Per PC", fPCWhisper == NWNX_Chat_GetChatHearingDistance(oPC, NWNX_CHAT_CHANNEL_PLAYER_WHISPER) - 2.0f);

    WriteTimestampedLogEntry("NWNX_Chat unit test end.");
}
