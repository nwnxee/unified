/// @addtogroup dialog Dialog
/// @brief Functions exposing additional dialog properties
/// @{
/// @file nwnx_dialog.nss

#include "nwnx"

const string NWNX_Dialog = "NWNX_Dialog"; ///< @private

/// @name Dialog Node Types
/// @anchor dialog_node_types
/// @{
const int NWNX_DIALOG_NODE_TYPE_INVALID                = -1;
const int NWNX_DIALOG_NODE_TYPE_STARTING_NODE          = 0;
const int NWNX_DIALOG_NODE_TYPE_ENTRY_NODE             = 1;
const int NWNX_DIALOG_NODE_TYPE_REPLY_NODE             = 2;
/// @}

/// @name Dialog Script Types
/// @anchor dialog_script_types
/// @{
const int NWNX_DIALOG_SCRIPT_TYPE_OTHER                = 0;
const int NWNX_DIALOG_SCRIPT_TYPE_STARTING_CONDITIONAL = 1;
const int NWNX_DIALOG_SCRIPT_TYPE_ACTION_TAKEN         = 2;
/// @}

/// @name Dialog Languages
/// @anchor dialog_languages
/// @{
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
/// @}

/// @brief Get the @ref dialog_node_types "Node Type" of the current text node
/// @return A @ref dialog_node_types "Node Type".  If called out of dialog, returns NWNX_DIALOG_NODE_TYPE_INVALID
int NWNX_Dialog_GetCurrentNodeType();

/// @brief Get the @ref dialog_script_types "Script Type" of the current text node
/// @return A @ref dialog_script_types "Node Type". If called out of dialog, returns NWNX_DIALOG_SCRIPT_TYPE_OTHER
int NWNX_Dialog_GetCurrentScriptType();

/// @brief Get the absolute ID of the current node in the conversation
/// @note NWNX_DIALOG_NODE_TYPE_ENTRY_NODE and NWNX_DIALOG_NODE_TYPE_REPLY_NODE nodes
/// have different namespaces, so they can share the same ID
/// @return The absolute ID in the dialog. If called out of dialog, returns -1
int NWNX_Dialog_GetCurrentNodeID();

/// @brief Get the index of the current node in the list of replies/entries.
/// @note The index is zero based, and counts items not displayed due to a StartingConditional.
/// @return The index of the current node.
int NWNX_Dialog_GetCurrentNodeIndex();

/// @brief Get the text of the current node
/// @param language The @ref dialog_languages "language" of the text.
/// @param gender The gender for the text.
string NWNX_Dialog_GetCurrentNodeText(int language=NWNX_DIALOG_LANGUAGE_ENGLISH, int gender=GENDER_MALE);

/// @brief Set the text of the current node for given language/gender
/// @note This will only work in a starting conditional script (action take comes after the text is displayed)
/// @param text The text for the node.
/// @param language The @ref dialog_languages "language" of the text.
/// @param gender The gender for the text.
void NWNX_Dialog_SetCurrentNodeText(string text, int language=NWNX_DIALOG_LANGUAGE_ENGLISH, int gender=GENDER_MALE);

/// @brief End a conversation oObject is involved in, it will fire the OnAbort script of the conversation
/// @warning Calling this from a conversation script will crash your server.
/// @param oObject The object in a conversation
void NWNX_Dialog_End(object oObject);

/// @}


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

void NWNX_Dialog_End(object oObject)
{
    string sFunc = "End";

    NWNX_PushArgumentObject(NWNX_Dialog, sFunc, oObject);
    NWNX_CallFunction(NWNX_Dialog, sFunc);
}
