namespace NWNX
{
    [NWNXPlugin(NWNX_Weapon)]
    public class WeaponPlugin
    {
        public const string NWNX_Weapon = "NWNX_Weapon";

        // /< @private
        // / @name Weapons Options
        // / @anchor wpn_opts
        // /
        // / Options constants to be used with NWNX_Weapon_SetOption function.
        // / @{
        public const int NWNX_WEAPON_OPT_GRTFOCUS_AB_BONUS = 0;

        // /< Greater Focus Attack Bonus
        public const int NWNX_WEAPON_OPT_GRTSPEC_DAM_BONUS = 1;

        // /< Greater Specialization Damage Bonus
        // /@}
        //  Get Event Data Constants
        public const int NWNX_WEAPON_GETDATA_DC = 0;

        // /< Get Devastating Critical Data
        //  Set Event Data Constants
        public const int NWNX_WEAPON_SETDATA_DC_BYPASS = 0;

        // /< Set Devastating Critical Bypass
        // / Devastating critical event data
        // / @brief Set nFeat as weapon focus feat for a base item.
        // / @param nBaseItem The base item id.
        // / @param nFeat The feat to set.
        public static void SetWeaponFocusFeat(int nBaseItem, int nFeat)
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Weapon, "SetWeaponFocusFeat");
            NWN.Internal.NativeFunctions.nwnxPushInt(nFeat);
            NWN.Internal.NativeFunctions.nwnxPushInt(nBaseItem);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
        }

        // / @brief Set required creature size for a weapon base item to be finessable.
        // / @param nBaseItem The base item id.
        // / @param nSize The creature size minimum to consider this weapon finessable.
        public static void SetWeaponFinesseSize(int nBaseItem, int nSize)
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Weapon, "SetWeaponFinesseSize");
            NWN.Internal.NativeFunctions.nwnxPushInt(nSize);
            NWN.Internal.NativeFunctions.nwnxPushInt(nBaseItem);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
        }

        // / @brief Get required creature size for a weapon base item to be finessable.
        // / @param nBaseItem The base item id.
        public static int GetWeaponFinesseSize(int nBaseItem)
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Weapon, "GetWeaponFinesseSize");
            NWN.Internal.NativeFunctions.nwnxPushInt(nBaseItem);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
            return NWN.Internal.NativeFunctions.nwnxPopInt();
        }

        // / @brief Set weapon base item to be considered as unarmed for weapon finesse feat.
        // / @param nBaseItem The base item id.
        public static void SetWeaponUnarmed(int nBaseItem)
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Weapon, "SetWeaponUnarmed");
            NWN.Internal.NativeFunctions.nwnxPushInt(nBaseItem);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
        }

        // / @brief Set a feat as weapon improved critical for a base item.
        // / @param nBaseItem The base item id.
        // / @param nFeat The feat to set.
        public static void SetWeaponImprovedCriticalFeat(int nBaseItem, int nFeat)
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Weapon, "SetWeaponImprovedCriticalFeat");
            NWN.Internal.NativeFunctions.nwnxPushInt(nFeat);
            NWN.Internal.NativeFunctions.nwnxPushInt(nBaseItem);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
        }

        // / @brief Set a feat as weapon specialization for a base item.
        // / @param nBaseItem The base item id.
        // / @param nFeat The feat to set.
        public static void SetWeaponSpecializationFeat(int nBaseItem, int nFeat)
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Weapon, "SetWeaponSpecializationFeat");
            NWN.Internal.NativeFunctions.nwnxPushInt(nFeat);
            NWN.Internal.NativeFunctions.nwnxPushInt(nBaseItem);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
        }

        // / @brief Set a feat as epic weapon focus for a base item.
        // / @param nBaseItem The base item id.
        // / @param nFeat The feat to set.
        public static void SetEpicWeaponFocusFeat(int nBaseItem, int nFeat)
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Weapon, "SetEpicWeaponFocusFeat");
            NWN.Internal.NativeFunctions.nwnxPushInt(nFeat);
            NWN.Internal.NativeFunctions.nwnxPushInt(nBaseItem);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
        }

        // / @brief Set a feat as epic weapon specialization for a base item.
        // / @param nBaseItem The base item id.
        // / @param nFeat The feat to set.
        public static void SetEpicWeaponSpecializationFeat(int nBaseItem, int nFeat)
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Weapon, "SetEpicWeaponSpecializationFeat");
            NWN.Internal.NativeFunctions.nwnxPushInt(nFeat);
            NWN.Internal.NativeFunctions.nwnxPushInt(nBaseItem);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
        }

        // / @brief Set a feat as epic weapon overwhelming critical for a base item.
        // / @param nBaseItem The base item id.
        // / @param nFeat The feat to set.
        public static void SetEpicWeaponOverwhelmingCriticalFeat(int nBaseItem, int nFeat)
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Weapon, "SetEpicWeaponOverwhelmingCriticalFeat");
            NWN.Internal.NativeFunctions.nwnxPushInt(nFeat);
            NWN.Internal.NativeFunctions.nwnxPushInt(nBaseItem);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
        }

        // / @brief Set a feat as epic weapon devastating critical for a base item.
        // / @param nBaseItem The base item id.
        // / @param nFeat The feat to set.
        public static void SetEpicWeaponDevastatingCriticalFeat(int nBaseItem, int nFeat)
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Weapon, "SetEpicWeaponDevastatingCriticalFeat");
            NWN.Internal.NativeFunctions.nwnxPushInt(nFeat);
            NWN.Internal.NativeFunctions.nwnxPushInt(nBaseItem);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
        }

        // / @brief Set a feat as weapon of choice for a base item.
        // / @param nBaseItem The base item id.
        // / @param nFeat The feat to set.
        public static void SetWeaponOfChoiceFeat(int nBaseItem, int nFeat)
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Weapon, "SetWeaponOfChoiceFeat");
            NWN.Internal.NativeFunctions.nwnxPushInt(nFeat);
            NWN.Internal.NativeFunctions.nwnxPushInt(nBaseItem);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
        }

        // / @brief Set a feat as greater weapon specialization for a base item.
        // / @param nBaseItem The base item id.
        // / @param nFeat The feat to set.
        public static void SetGreaterWeaponSpecializationFeat(int nBaseItem, int nFeat)
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Weapon, "SetGreaterWeaponSpecializationFeat");
            NWN.Internal.NativeFunctions.nwnxPushInt(nFeat);
            NWN.Internal.NativeFunctions.nwnxPushInt(nBaseItem);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
        }

        // / @brief Set a feat as greater weapon focus for a base item.
        // / @param nBaseItem The base item id.
        // / @param nFeat The feat to set.
        public static void SetGreaterWeaponFocusFeat(int nBaseItem, int nFeat)
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Weapon, "SetGreaterWeaponFocusFeat");
            NWN.Internal.NativeFunctions.nwnxPushInt(nFeat);
            NWN.Internal.NativeFunctions.nwnxPushInt(nBaseItem);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
        }

        // / @brief Set base item as monk weapon.
        // / @param nBaseItem The base item id.
        public static void SetWeaponIsMonkWeapon(int nBaseItem)
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Weapon, "SetWeaponIsMonkWeapon");
            NWN.Internal.NativeFunctions.nwnxPushInt(nBaseItem);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
        }

        // / @brief Set plugin options.
        // / @param nOption The option to change from @ref wpn_opts "Weapon Options".
        // / @param nVal The new value of the option.
        public static void SetOption(int nOption, int nVal)
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Weapon, "SetOption");
            NWN.Internal.NativeFunctions.nwnxPushInt(nVal);
            NWN.Internal.NativeFunctions.nwnxPushInt(nOption);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
        }

        // / @brief Set Devastating Critical Event Script.
        // / @param sScript The script to call when a Devastating Critical occurs.
        public static void SetDevastatingCriticalEventScript(string sScript)
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Weapon, "SetDevastatingCriticalEventScript");
            NWN.Internal.NativeFunctions.nwnxPushString(sScript);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
        }

        // / @brief Get Devastating Critical Event Data.
        // / @note This is only for use with the Devastating Critical Event Script.
        // / @return An NWNX_Weapon_DevastatingCriticalEvent_Data struct.
        public static DevastatingCriticalEvent_Data GetDevastatingCriticalEventData()
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Weapon, "GetDevastatingCriticalEventData");
            NWN.Internal.NativeFunctions.nwnxCallFunction();
            DevastatingCriticalEvent_Data retVal;
            retVal.nDamage = NWN.Internal.NativeFunctions.nwnxPopInt();
            retVal.oTarget = NWN.Internal.NativeFunctions.nwnxPopObject();
            retVal.oWeapon = NWN.Internal.NativeFunctions.nwnxPopObject();
            return retVal;
        }

        // / @brief Bypass Devastating Critical.
        // / @note This is only for use with the Devastating Critical Event Script.
        public static void BypassDevastatingCritical()
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Weapon, "BypassDevastatingCritical");
            NWN.Internal.NativeFunctions.nwnxCallFunction();
        }

        // / @}
    }

        public struct DevastatingCriticalEvent_Data
        {
            public uint oWeapon;
            public uint oTarget;
            public int nDamage;
        }
}
