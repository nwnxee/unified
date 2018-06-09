#include "nwnx"

const int NWNX_DIALOG_NODE_TYPE_INVALID                = -1;
const int NWNX_DIALOG_NODE_TYPE_STARTING_NODE          = 0;
const int NWNX_DIALOG_NODE_TYPE_ENTRY_NODE             = 1;
const int NWNX_DIALOG_NODE_TYPE_REPLY_NODE             = 2;

const int NWNX_DIALOG_SCRIPT_TYPE_OTHER                = 0;
const int NWNX_DIALOG_SCRIPT_TYPE_STARTING_CONDITIONAL = 1;
const int NWNX_DIALOG_SCRIPT_TYPE_ACTION_TAKEN         = 2;

const int NWNX_DIALOG_LANGUAGE_ENGLISH                 = 0;
const int NWNX_DIALOG_LANGUAGE_FRENCH                  = 1;
const int NWNX_DIALOG_LANGUAGE_GERMAN                  = 2;
const int NWNX_DIALOG_LANGUAGE_ITALIAN                 = 3;
const int NWNX_DIALOG_LANGUAGE_SPANISH                 = 4;
const int NWNX_DIALOG_LANGUAGE_POLISH                  = 5;
const int NWNX_DIALOG_LANGUAGE_KOREAN                  = 128;
const int NWNX_DIALOG_LANGUAGE_CHINESE_TRADITIONAL     = 129;
const int NWNX_DIALOG_LANGUAGE_CHINESE_SIMPLIFIED      = 130;
const int NWNX_DIALOG_LANGUAGE_JAPANESE                = 131;

// Get the type (NWNX_DIALOG_NODE_TYPE_*) of the current text node
// If called out of dialog, returns INVALID
int NWNX_Dialog_GetCurrentNodeType();

// Get the current script type (NWNX_DIALOG_SCRIPT_TYPE_*)
// If called out of dialog, returns OTHER
int NWNX_Dialog_GetCurrentScriptType();

// Get the absolute ID of the current node in the conversation
// ENTRY and REPLY nodes have different namespaces, so can have double IDs
// If called out of dialog, returns -1
int NWNX_Dialog_GetCurrentNodeID();

// Get the index of the current node in the list of replies/entries.
// The index is zero based, and counts items not displayed due StartingConditional
int NWNX_Dialog_GetCurrentNodeIndex();

// Get the text of the current node for given language/gender
string NWNX_Dialog_GetCurrentNodeText(int language=NWNX_DIALOG_LANGUAGE_ENGLISH, int gender=GENDER_MALE);

// Set the text of the current node for given language/gender
// This will only work in a starting conditional script (action take comes after the text is displayed)
void NWNX_Dialog_SetCurrentNodeText(string text, int language=NWNX_DIALOG_LANGUAGE_ENGLISH, int gender=GENDER_MALE);


const string NWNX_Dialog = "NWNX_Dialog";

int NWNX_Dialog_GetCurrentNodeType()
{
    string sFunc = "GetCurrentNodeType";
    NWNX_CallFunction(NWNX_Dialog, sFunc);
    return NWNX_GetReturnValueInt(NWNX_Dialog, sFunc);
}

int NWNX_Dialog_GetCurrentScriptType()
{
    string sFunc = "GetCurrentScriptType";
    NWNX_CallFunction(NWNX_Dialog, sFunc);
    return NWNX_GetReturnValueInt(NWNX_Dialog, sFunc);
}

int NWNX_Dialog_GetCurrentNodeID()
{
    string sFunc = "GetCurrentNodeID";
    NWNX_CallFunction(NWNX_Dialog, sFunc);
    return NWNX_GetReturnValueInt(NWNX_Dialog, sFunc);
}

int NWNX_Dialog_GetCurrentNodeIndex()
{
    string sFunc = "GetCurrentNodeIndex";
    NWNX_CallFunction(NWNX_Dialog, sFunc);
    return NWNX_GetReturnValueInt(NWNX_Dialog, sFunc);
}

string NWNX_Dialog_GetCurrentNodeText(int language=NWNX_DIALOG_LANGUAGE_ENGLISH, int gender=GENDER_MALE)
{
    string sFunc = "GetCurrentNodeText";
    NWNX_PushArgumentInt(NWNX_Dialog, sFunc, gender);
    NWNX_PushArgumentInt(NWNX_Dialog, sFunc, language);
    NWNX_CallFunction(NWNX_Dialog, sFunc);
    return NWNX_GetReturnValueString(NWNX_Dialog, sFunc);
}

void NWNX_Dialog_SetCurrentNodeText(string text, int language=NWNX_DIALOG_LANGUAGE_ENGLISH, int gender=GENDER_MALE)
{
    string sFunc = "SetCurrentNodeText";
    NWNX_PushArgumentInt(NWNX_Dialog, sFunc, gender);
    NWNX_PushArgumentInt(NWNX_Dialog, sFunc, language);
    NWNX_PushArgumentString(NWNX_Dialog, sFunc, text);
    NWNX_CallFunction(NWNX_Dialog, sFunc);
}
