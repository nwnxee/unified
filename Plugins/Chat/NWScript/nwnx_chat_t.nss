#include "nwnx_chat"
#include "nwnx_test"

void main()
{
    while(TEST("Chat"))
    {
        ASSERT(IS_TRUE(NWNX_Test_PluginExists("NWNX_Chat")));

        float fDefaultTalk = NWNX_Chat_GetChatHearingDistance();
        NWNX_Chat_SetChatHearingDistance(fDefaultTalk + 10.0f);
        EXPECT(IS_EQUAL_FLOAT(fDefaultTalk, NWNX_Chat_GetChatHearingDistance() - 10.0f), "SetChatHearingDistance Default");

        while(TEST("PC"))
        {
            object oPC = GetFirstPC();
            ASSERT(IS_VALID(oPC), "GetFirstPC()");
            float fPCWhisper = NWNX_Chat_GetChatHearingDistance(oPC, NWNX_CHAT_CHANNEL_PLAYER_WHISPER);
            NWNX_Chat_SetChatHearingDistance(fPCWhisper + 2.0f, oPC, NWNX_CHAT_CHANNEL_PLAYER_WHISPER);

            EXPECT(IS_EQUAL_FLOAT(fPCWhisper, NWNX_Chat_GetChatHearingDistance(oPC, NWNX_CHAT_CHANNEL_PLAYER_WHISPER) - 2.0f), "SetChatHearingDistance Per PC");
        }
    }
}
