#include "nwnx_events"
#include "nwnx_openai"

string Npc(object npc)
{
    string ctx = "You are " + GetName(npc) + ". " + GetDescription(npc, TRUE);
    
    string extraCtx = GetLocalString(npc, "AI_CONTEXT");
    if (extraCtx != "")
    {
        ctx += "\n\nYou would describe yourself in this way: " + extraCtx + "\n\n";
    }

    return ctx;
}

string Area(object npc)
{
    string ctx = "You are in a place called " + GetName(GetArea(npc)) + ". ";
    ctx += "It is " + (GetIsNight() ? "night-time" : "day-time") + ". ";
    return ctx;
}

string ConvoHistory(object npc)
{
    string ctx = "";
    
    string summary = GetLocalString(npc, "AI_CONVO_SUMMARY");
    if (summary != "")
    {
        ctx += "Some of the past conversation has been lost, but this is a summary: " + summary + "\n\n";
    }
    
    ctx += "This is a transcript of your past conversation:\n";

    int i;
    json entries = GetLocalJson(npc, "AI_CONVO_HISTORY");

    for (i = 0; i < JsonGetLength(entries); i++)
    {
        json entry = JsonArrayGet(entries, i);
        object sender = StringToObject(JsonGetString(JsonArrayGet(entry, 0)));
        string message = JsonGetString(JsonArrayGet(entry, 1));

        string senderName = sender == npc ? "You" : GetName(sender);
        ctx += "\n" + IntToString(i + 1) + ": " + senderName + " said: \"" + message + "\"";
    }

    return ctx;
}

string ConvoPartner(object npc, object partner)
{
    string ctx = "You are speaking with a " + (GetGender(partner) == GENDER_FEMALE ? "woman" : "man") + " called " + GetName(partner) + ". ";

    if (JsonGetLength(GetLocalJson(npc, "AI_CONVO_HISTORY")) == 1)
    {
        ctx += "This is the first time you have spoken to " + (GetGender(partner) == GENDER_FEMALE ? "her" : "him");
    }

    return ctx;
}

void RequestResponse(object npc, object partner, string token)
{
    // TODO: Rate limit? Do not do if outstanding query?
    // TODO: Any safety concerns?

    string ctx = "";

    string npcTxt = Npc(npc);
    string areaTxt = Area(npc);
    string partnerTxt = ConvoPartner(npc, partner);
    string historyTxt = ConvoHistory(npc);

    ctx += npcTxt + "\n\n";
    ctx += areaTxt + "\n\n";
    ctx += "<|endoftext|>";


    ctx += partnerTxt + "\n\n";
    ctx += historyTxt + "\n\n";
    ctx += "<|endoftext|>";

    ctx += "Write the next roleplaying post using a mixture of first-person dialogue and third-person narrative. ";
    ctx += "You should only control your own character, " + GetName(npc) + ". Minimize narrative related to thoughts - focus on actions. ";
    ctx += "Your writing should be creative, captivating, and penned with originality and panache. ";
    ctx += "Limit your response to a single paragraph.";
    ctx += "<|endoftext|>"; 
    
    if (GetStringLength(ctx) >= 3500 /* nearing OpenAI token limit */)
    {
        // Request summary of the conversation so far which will be applied later.
        string token = "SUMMARY " + ObjectToString(npc);
        NWNX_OpenAI_ChatAsync("Summarize this past conversation between you and " + GetName(partner) + ":\n" + historyTxt, token);
    }

    string token = "RESPONSE " + ObjectToString(npc);
    NWNX_OpenAI_ChatAsync(ctx, token);
}

void AddConversationPoint(object npc, object speaker, string text)
{
    json entries = GetLocalJson(npc, "AI_CONVO_HISTORY");

    if (JsonGetType(entries) != JSON_TYPE_ARRAY)
    {
        entries = JsonArray();
    }

    json entry = JsonArray();
    entry = JsonArrayInsert(entry, JsonString(ObjectToString(speaker)));
    entry = JsonArrayInsert(entry, JsonString(text));

    entries = JsonArrayInsert(entries, entry);

    SetLocalJson(npc, "AI_CONVO_HISTORY", entries);
}
