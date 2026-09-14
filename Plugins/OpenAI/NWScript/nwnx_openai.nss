#include "nwnx"

void NWNX_OpenAI_ChatAsync(string prompt, string token = "", float randomness = 0.8, int maxTokens = 300);

void NWNX_OpenAI_ChatAsync(string prompt, string token, float randomness, int maxTokens)
{
    NWNX_PushArgumentInt(maxTokens);
    NWNX_PushArgumentFloat(randomness);
    NWNX_PushArgumentString(token);
    NWNX_PushArgumentString(prompt);
    NWNX_CallFunction("NWNX_OpenAI", "ChatAsync");
}
