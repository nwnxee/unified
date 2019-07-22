#include "nwnx_chat"

void report(string func, int bSuccess)
{
    if (bSuccess)
        WriteTimestampedLogEntry("NWNX_Chat: " + func + "() success");
    else
        WriteTimestampedLogEntry("NWNX_Chat: " + func + "() failed");
}

void main()
{
    WriteTimestampedLogEntry("NWNX_Chat unit test begin..");

    float fDefaultTalk = NWNX_Chat_GetChatHearingDistance();
    NWNX_Chat_SetChatHearingDistance(fDefaultTalk + 10.0f);

    report("SetChatHearingDistance Default", fDefaultTalk == NWNX_Chat_GetChatHearingDistance() - 10.0f);

    object oPC = GetFirstPC();
    float fPCWhisper = NWNX_Chat_GetChatHearingDistance(oPC, NWNX_CHAT_CHANNEL_PLAYER_WHISPER);
    NWNX_Chat_SetChatHearingDistance(fPCWhisper + 2.0f, oPC, NWNX_CHAT_CHANNEL_PLAYER_WHISPER);

    report("SetChatHearingDistance Per PC", fPCWhisper == NWNX_Chat_GetChatHearingDistance(oPC, NWNX_CHAT_CHANNEL_PLAYER_WHISPER) - 2.0f);

    WriteTimestampedLogEntry("NWNX_Chat unit test end.");
}
