#include "nwnx_dialog"

void _report()
{
    string sMessage = "NWNX_Dialog debug:";
    int id = NWNX_Dialog_GetCurrentNodeID();
    sMessage = "\nNode ID = " + IntToString(id);

    int type = NWNX_Dialog_GetCurrentNodeType();
    sMessage += "\nCurrent node type = " + IntToString(type) + " (";
    switch (type)
    {
        case NWNX_DIALOG_NODE_TYPE_INVALID: sMessage += "INVALID)"; break;
        case NWNX_DIALOG_NODE_TYPE_STARTING_NODE: sMessage += "STARTING_NODE)"; break;
        case NWNX_DIALOG_NODE_TYPE_ENTRY_NODE: sMessage += "ENTRY_NODE)"; break;
        case NWNX_DIALOG_NODE_TYPE_REPLY_NODE: sMessage += "REPLY_NODE)"; break;
    }

    int scripttype = NWNX_Dialog_GetCurrentScriptType();
    sMessage += "\nScript type = " + IntToString(scripttype) + " (";
    switch (scripttype)
    {
        case NWNX_DIALOG_SCRIPT_TYPE_OTHER: sMessage += "OTHER)"; break;
        case NWNX_DIALOG_SCRIPT_TYPE_STARTING_CONDITIONAL: sMessage += "STARTING_CONDITIONAL)"; break;
        case NWNX_DIALOG_SCRIPT_TYPE_ACTION_TAKEN: sMessage += "ACTION_TAKEN)"; break;
    }

    int index = NWNX_Dialog_GetCurrentNodeIndex();
    sMessage += "\nNode index = " + IntToString(index);

    string text = NWNX_Dialog_GetCurrentNodeText();
    sMessage += "\nText = '" + text + "'";

    NWNX_Dialog_SetCurrentNodeText(text + " [ADDED]");

    SendMessageToPC(GetFirstPC(), sMessage);
}
