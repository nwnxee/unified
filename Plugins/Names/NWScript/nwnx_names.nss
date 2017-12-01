#include "nwnx"

// Sets the dynamic name of target to name.
// Optionally, observer can be set so the name only changes for them (must be PC).
void NWNX_Names_SetName(object target, string name, object observer = OBJECT_INVALID);

// Gets the dynamic name of target.
// Optionally, observer can be set to get the name as perceived by observer (must be a PC).
string NWNX_Names_GetName(object target, object observer = OBJECT_INVALID);

void NWNX_Names_SetName(object target, string name, object observer)
{
    NWNX_PushArgumentObject("NWNX_Names", "SET_NAME", target);
    NWNX_PushArgumentString("NWNX_Names", "SET_NAME", name);
    NWNX_PushArgumentObject("NWNX_Names", "SET_NAME", observer);
    NWNX_CallFunction("NWNX_Names", "SET_NAME");
}

string NWNX_Names_GetName(object target, object observer)
{
    NWNX_PushArgumentObject("NWNX_Names", "GET_NAME", target);
    NWNX_PushArgumentObject("NWNX_Names", "GET_NAME", observer);
    NWNX_CallFunction("NWNX_Names", "GET_NAME");
    return NWNX_GetReturnValueString("NWNX_Names", "GET_NAME");
}
