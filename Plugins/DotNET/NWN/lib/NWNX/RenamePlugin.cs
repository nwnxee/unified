namespace NWNX
{
    [NWNXPlugin(NWNX_Rename)]
    public class RenamePlugin
    {
        public const string NWNX_Rename = "NWNX_Rename";

        // /< @private
        // / @anchor rename_comm_name_override_type
        // / @name Community Name Override Type
        // / @{
        public const int NWNX_RENAME_PLAYERNAME_DEFAULT = 0;

        // /< Don't rename
        public const int NWNX_RENAME_PLAYERNAME_OBFUSCATE = 1;

        // /< Generate random string for Community Name
        public const int NWNX_RENAME_PLAYERNAME_OVERRIDE = 2;

        // /< Use character name specified
        public const int NWNX_RENAME_PLAYERNAME_ANONYMOUS = 3;

        // /< Use the value of the NWNX_RENAME_ANONYMOUS_NAME environment variable
        // /@}
        // / @brief Set a PC's character name and community name on the player list.
        // / @param oTarget The PC whose name is being overridden.
        // / @param sNewName The new name.
        // / @param sPrefix The prefix for their character name, sometimes used for a color code.
        // / @param sSuffix The suffix for their character name.
        // / @param iPlayerNameState How to change the Community Name, use @ref rename_comm_name_override_type "Community Name Override Type".
        // / @param oObserver If specified, the character name will appear to that specific observer as set, this overrides a global setting.
        // / @note Will not persist through saving, resets or logout.
        public static void SetPCNameOverride(uint oTarget, string sNewName, string sPrefix = "", string sSuffix = "", int iPlayerNameState = NWNX_RENAME_PLAYERNAME_DEFAULT, uint oObserver = NWN.NWScript.OBJECT_INVALID)
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Rename, "SetPCNameOverride");
            NWN.Internal.NativeFunctions.nwnxPushObject(oObserver);
            NWN.Internal.NativeFunctions.nwnxPushInt(iPlayerNameState);
            NWN.Internal.NativeFunctions.nwnxPushString(sSuffix);
            NWN.Internal.NativeFunctions.nwnxPushString(sPrefix);
            NWN.Internal.NativeFunctions.nwnxPushString(sNewName);
            NWN.Internal.NativeFunctions.nwnxPushObject(oTarget);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
        }

        // / @brief Gets a PC's name as overridden.
        // / @param oTarget The PC whose name to query.
        // / @param oObserver The specific observer.
        // / @return The PC's name as overridden either per observer or globally.
        // / @note If you wish to get a PC's true name use `GetName(oPC, TRUE)`.
        public static string GetPCNameOverride(uint oTarget, uint oObserver = NWN.NWScript.OBJECT_INVALID)
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Rename, "GetPCNameOverride");
            NWN.Internal.NativeFunctions.nwnxPushObject(oObserver);
            NWN.Internal.NativeFunctions.nwnxPushObject(oTarget);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
            return NWN.Internal.NativeFunctions.nwnxPopString();
        }

        // / @brief Clears an overridden PC Name.
        // / @param oTarget The PC whose overridden name to clear, use OBJECT_INVALID if you're clearing all overrides for an observer.
        // / @param oObserver The observer whose overriden name of oTarget is being cleared.
        // / If oTarget is OBJECT_INVALID then all overrides are cleared.
        // / @param clearAll If true, both the global and personal overrides will be cleared for that target PC.
        // / Requires oObserver be OBJECT_INVALID.
        public static void ClearPCNameOverride(uint oTarget, uint oObserver = NWN.NWScript.OBJECT_INVALID, int clearAll = NWN.NWScript.FALSE)
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Rename, "ClearPCNameOverride");
            NWN.Internal.NativeFunctions.nwnxPushInt(clearAll);
            NWN.Internal.NativeFunctions.nwnxPushObject(oObserver);
            NWN.Internal.NativeFunctions.nwnxPushObject(oTarget);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
        }

        // / @}
    }
}
