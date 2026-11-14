#include "inc_openai"
#include "x3_inc_string"

void main()
{
    if (GetListenPatternNumber() == 1)
    {
        object partner = GetLastSpeaker();
        AddConversationPoint(OBJECT_SELF, partner, StringReplace(GetMatchedSubstring(0), "\n", ""));
        RequestResponse(OBJECT_SELF, partner, ObjectToString(OBJECT_SELF));
    }
}
