#include "nwnx_events"
#include "inc_openai"
#include "x3_inc_string"

void main()
{
	string response = StringReplace(NWNX_Events_GetEventData("RESPONSE"), "\n", "");
    string token = NWNX_Events_GetEventData("TOKEN");

    string id = StringParse(token);
    string oid = StringRemoveParsed(token, id);
    object npc = StringToObject(oid);

    if (id == "RESPONSE")
    {
        AddConversationPoint(npc, npc, response);
        AssignCommand(npc, ActionSpeakString(response));
    }
    else if (id == "SUMMARY")
    {
        // reset convo history, apply summary
        SetLocalJson(npc, "AI_CONVO_HISTORY", JsonArray());
        SetLocalString(npc, "AI_CONVO_SUMMARY", response);
    }
}
