namespace NWNX
{
    [NWNXPlugin(NWNX_Dialog)]
    public class DialogPlugin
    {
        public const string NWNX_Dialog = "NWNX_Dialog";

        // /< @private
        // / @name Dialog Node Types
        // / @anchor dialog_node_types
        // / @{
        public const int NWNX_DIALOG_NODE_TYPE_INVALID = -1;
        public const int NWNX_DIALOG_NODE_TYPE_STARTING_NODE = 0;
        public const int NWNX_DIALOG_NODE_TYPE_ENTRY_NODE = 1;
        public const int NWNX_DIALOG_NODE_TYPE_REPLY_NODE = 2;

        // / @}
        // / @name Dialog Script Types
        // / @anchor dialog_script_types
        // / @{
        public const int NWNX_DIALOG_SCRIPT_TYPE_OTHER = 0;
        public const int NWNX_DIALOG_SCRIPT_TYPE_STARTING_CONDITIONAL = 1;
        public const int NWNX_DIALOG_SCRIPT_TYPE_ACTION_TAKEN = 2;

        // / @}
        // / @name Dialog Languages
        // / @anchor dialog_languages
        // / @{
        public const int NWNX_DIALOG_LANGUAGE_ENGLISH = 0;
        public const int NWNX_DIALOG_LANGUAGE_FRENCH = 1;
        public const int NWNX_DIALOG_LANGUAGE_GERMAN = 2;
        public const int NWNX_DIALOG_LANGUAGE_ITALIAN = 3;
        public const int NWNX_DIALOG_LANGUAGE_SPANISH = 4;
        public const int NWNX_DIALOG_LANGUAGE_POLISH = 5;
        public const int NWNX_DIALOG_LANGUAGE_KOREAN = 128;
        public const int NWNX_DIALOG_LANGUAGE_CHINESE_TRADITIONAL = 129;
        public const int NWNX_DIALOG_LANGUAGE_CHINESE_SIMPLIFIED = 130;
        public const int NWNX_DIALOG_LANGUAGE_JAPANESE = 131;

        // / @}
        // / @brief Get the @ref dialog_node_types "Node Type" of the current text node
        // / @return A @ref dialog_node_types "Node Type".  If called out of dialog, returns NWNX_DIALOG_NODE_TYPE_INVALID
        public static int GetCurrentNodeType()
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Dialog, "GetCurrentNodeType");
            NWN.Internal.NativeFunctions.nwnxCallFunction();
            return NWN.Internal.NativeFunctions.nwnxPopInt();
        }

        // / @brief Get the @ref dialog_script_types "Script Type" of the current text node
        // / @return A @ref dialog_script_types "Node Type". If called out of dialog, returns NWNX_DIALOG_SCRIPT_TYPE_OTHER
        public static int GetCurrentScriptType()
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Dialog, "GetCurrentScriptType");
            NWN.Internal.NativeFunctions.nwnxCallFunction();
            return NWN.Internal.NativeFunctions.nwnxPopInt();
        }

        // / @brief Get the absolute ID of the current node in the conversation
        // / @note NWNX_DIALOG_NODE_TYPE_ENTRY_NODE and NWNX_DIALOG_NODE_TYPE_REPLY_NODE nodes
        // / have different namespaces, so they can share the same ID
        // / @return The absolute ID in the dialog. If called out of dialog, returns -1
        public static int GetCurrentNodeID()
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Dialog, "GetCurrentNodeID");
            NWN.Internal.NativeFunctions.nwnxCallFunction();
            return NWN.Internal.NativeFunctions.nwnxPopInt();
        }

        // / @brief Get the index of the current node in the list of replies/entries.
        // / @note The index is zero based, and counts items not displayed due to a StartingConditional.
        // / @return The index of the current node.
        public static int GetCurrentNodeIndex()
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Dialog, "GetCurrentNodeIndex");
            NWN.Internal.NativeFunctions.nwnxCallFunction();
            return NWN.Internal.NativeFunctions.nwnxPopInt();
        }

        // / @brief Get the text of the current node
        // / @param language The @ref dialog_languages "language" of the text.
        // / @param gender The gender for the text.
        public static string GetCurrentNodeText(int language = NWNX_DIALOG_LANGUAGE_ENGLISH, int gender = NWN.NWScript.GENDER_MALE)
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Dialog, "GetCurrentNodeText");
            NWN.Internal.NativeFunctions.nwnxPushInt(gender);
            NWN.Internal.NativeFunctions.nwnxPushInt(language);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
            return NWN.Internal.NativeFunctions.nwnxPopString();
        }

        // / @brief Set the text of the current node for given language/gender
        // / @note This will only work in a starting conditional script (action take comes after the text is displayed)
        // / @param text The text for the node.
        // / @param language The @ref dialog_languages "language" of the text.
        // / @param gender The gender for the text.
        public static void SetCurrentNodeText(string text, int language = NWNX_DIALOG_LANGUAGE_ENGLISH, int gender = NWN.NWScript.GENDER_MALE)
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Dialog, "SetCurrentNodeText");
            NWN.Internal.NativeFunctions.nwnxPushInt(gender);
            NWN.Internal.NativeFunctions.nwnxPushInt(language);
            NWN.Internal.NativeFunctions.nwnxPushString(text);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
        }

        // / @brief End a conversation oObject is involved in, it will fire the OnAbort script of the conversation
        // / @warning Calling this from a conversation script will crash your server.
        // / @param oObject The object in a conversation
        public static void End(uint oObject)
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Dialog, "End");
            NWN.Internal.NativeFunctions.nwnxPushObject(oObject);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
        }

        // / @}
    }
}
