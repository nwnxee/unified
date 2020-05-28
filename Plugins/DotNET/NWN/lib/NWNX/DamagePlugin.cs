namespace NWNX
{
    [NWNXPlugin(NWNX_Damage)]
    public class DamagePlugin
    {
        public const string NWNX_Damage = "NWNX_Damage";

        // /< @private
        // / @struct NWNX_Damage_DamageEventData
        // / @brief Damage Event Data
        // / @struct NWNX_Damage_AttackEventData
        // / @brief Attack Event Data
        // / @struct NWNX_Damage_DamageData
        // / @brief Used for DealDamage
        // / @brief Sets the script to run with a damage event.
        // / @param sScript The script that will handle the damage event.
        // / @param oOwner An object if only executing for a specific object or OBJECT_INVALID for global.
        public static void SetDamageEventScript(string sScript, uint oOwner = NWN.NWScript.OBJECT_INVALID)
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Damage, "SetDamageEventScript");
            NWN.Internal.NativeFunctions.nwnxPushObject(oOwner);
            NWN.Internal.NativeFunctions.nwnxPushString(sScript);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
        }

        // / @brief Get Damage Event Data
        // / @return A NWNX_Damage_DamageEventData struct.
        // / @note To use only in the Damage Event Script.
        public static DamageEventData GetDamageEventData()
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Damage, "GetDamageEventData");
            NWN.Internal.NativeFunctions.nwnxCallFunction();
            DamageEventData retVal;
            retVal.iBase = NWN.Internal.NativeFunctions.nwnxPopInt();
            retVal.iSonic = NWN.Internal.NativeFunctions.nwnxPopInt();
            retVal.iPositive = NWN.Internal.NativeFunctions.nwnxPopInt();
            retVal.iNegative = NWN.Internal.NativeFunctions.nwnxPopInt();
            retVal.iFire = NWN.Internal.NativeFunctions.nwnxPopInt();
            retVal.iElectrical = NWN.Internal.NativeFunctions.nwnxPopInt();
            retVal.iDivine = NWN.Internal.NativeFunctions.nwnxPopInt();
            retVal.iCold = NWN.Internal.NativeFunctions.nwnxPopInt();
            retVal.iAcid = NWN.Internal.NativeFunctions.nwnxPopInt();
            retVal.iMagical = NWN.Internal.NativeFunctions.nwnxPopInt();
            retVal.iSlash = NWN.Internal.NativeFunctions.nwnxPopInt();
            retVal.iPierce = NWN.Internal.NativeFunctions.nwnxPopInt();
            retVal.iBludgeoning = NWN.Internal.NativeFunctions.nwnxPopInt();
            retVal.oDamager = NWN.Internal.NativeFunctions.nwnxPopObject();
            return retVal;
        }

        // / @brief Set Damage Event Data
        // / @param data A NWNX_Damage_DamageEventData struct.
        // / @note To use only in the Damage Event Script.
        public static void SetDamageEventData(DamageEventData data)
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Damage, "SetDamageEventData");
            NWN.Internal.NativeFunctions.nwnxPushObject(data.oDamager);
            NWN.Internal.NativeFunctions.nwnxPushInt(data.iBludgeoning);
            NWN.Internal.NativeFunctions.nwnxPushInt(data.iPierce);
            NWN.Internal.NativeFunctions.nwnxPushInt(data.iSlash);
            NWN.Internal.NativeFunctions.nwnxPushInt(data.iMagical);
            NWN.Internal.NativeFunctions.nwnxPushInt(data.iAcid);
            NWN.Internal.NativeFunctions.nwnxPushInt(data.iCold);
            NWN.Internal.NativeFunctions.nwnxPushInt(data.iDivine);
            NWN.Internal.NativeFunctions.nwnxPushInt(data.iElectrical);
            NWN.Internal.NativeFunctions.nwnxPushInt(data.iFire);
            NWN.Internal.NativeFunctions.nwnxPushInt(data.iNegative);
            NWN.Internal.NativeFunctions.nwnxPushInt(data.iPositive);
            NWN.Internal.NativeFunctions.nwnxPushInt(data.iSonic);
            NWN.Internal.NativeFunctions.nwnxPushInt(data.iBase);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
        }

        // / @brief Sets the script to run with an attack event.
        // / @param sScript The script that will handle the attack event.
        // / @param oOwner An object if only executing for a specific object or OBJECT_INVALID for global.
        public static void SetAttackEventScript(string sScript, uint oOwner = NWN.NWScript.OBJECT_INVALID)
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Damage, "SetAttackEventScript");
            NWN.Internal.NativeFunctions.nwnxPushObject(oOwner);
            NWN.Internal.NativeFunctions.nwnxPushString(sScript);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
        }

        // / @brief Get Attack Event Data
        // / @return A NWNX_Damage_AttackEventData struct.
        // / @note To use only in the Attack Event Script.
        public static AttackEventData GetAttackEventData()
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Damage, "GetAttackEventData");
            NWN.Internal.NativeFunctions.nwnxCallFunction();
            AttackEventData retVal;
            retVal.iSneakAttack = NWN.Internal.NativeFunctions.nwnxPopInt();
            retVal.iAttackType = NWN.Internal.NativeFunctions.nwnxPopInt();
            retVal.iAttackResult = NWN.Internal.NativeFunctions.nwnxPopInt();
            retVal.iAttackNumber = NWN.Internal.NativeFunctions.nwnxPopInt();
            retVal.iBase = NWN.Internal.NativeFunctions.nwnxPopInt();
            retVal.iSonic = NWN.Internal.NativeFunctions.nwnxPopInt();
            retVal.iPositive = NWN.Internal.NativeFunctions.nwnxPopInt();
            retVal.iNegative = NWN.Internal.NativeFunctions.nwnxPopInt();
            retVal.iFire = NWN.Internal.NativeFunctions.nwnxPopInt();
            retVal.iElectrical = NWN.Internal.NativeFunctions.nwnxPopInt();
            retVal.iDivine = NWN.Internal.NativeFunctions.nwnxPopInt();
            retVal.iCold = NWN.Internal.NativeFunctions.nwnxPopInt();
            retVal.iAcid = NWN.Internal.NativeFunctions.nwnxPopInt();
            retVal.iMagical = NWN.Internal.NativeFunctions.nwnxPopInt();
            retVal.iSlash = NWN.Internal.NativeFunctions.nwnxPopInt();
            retVal.iPierce = NWN.Internal.NativeFunctions.nwnxPopInt();
            retVal.iBludgeoning = NWN.Internal.NativeFunctions.nwnxPopInt();
            retVal.oTarget = NWN.Internal.NativeFunctions.nwnxPopObject();
            return retVal;
        }

        // / @brief Set Attack Event Data
        // / @param data A NWNX_Damage_AttackEventData struct.
        // / @note To use only in the Attack Event Script.
        public static void SetAttackEventData(AttackEventData data)
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Damage, "SetAttackEventData");
            NWN.Internal.NativeFunctions.nwnxPushObject(data.oTarget);
            NWN.Internal.NativeFunctions.nwnxPushInt(data.iBludgeoning);
            NWN.Internal.NativeFunctions.nwnxPushInt(data.iPierce);
            NWN.Internal.NativeFunctions.nwnxPushInt(data.iSlash);
            NWN.Internal.NativeFunctions.nwnxPushInt(data.iMagical);
            NWN.Internal.NativeFunctions.nwnxPushInt(data.iAcid);
            NWN.Internal.NativeFunctions.nwnxPushInt(data.iCold);
            NWN.Internal.NativeFunctions.nwnxPushInt(data.iDivine);
            NWN.Internal.NativeFunctions.nwnxPushInt(data.iElectrical);
            NWN.Internal.NativeFunctions.nwnxPushInt(data.iFire);
            NWN.Internal.NativeFunctions.nwnxPushInt(data.iNegative);
            NWN.Internal.NativeFunctions.nwnxPushInt(data.iPositive);
            NWN.Internal.NativeFunctions.nwnxPushInt(data.iSonic);
            NWN.Internal.NativeFunctions.nwnxPushInt(data.iBase);
            NWN.Internal.NativeFunctions.nwnxPushInt(data.iAttackNumber);
            NWN.Internal.NativeFunctions.nwnxPushInt(data.iAttackResult);
            NWN.Internal.NativeFunctions.nwnxPushInt(data.iAttackType);
            NWN.Internal.NativeFunctions.nwnxPushInt(data.iSneakAttack);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
        }

        // / @brief Deal damage to a target.
        // / @remark Permits multiple damage types and checks enhancement bonus for overcoming DR.
        // / @param data A NWNX_Damage_DamageData struct.
        // / @param oTarget The target object on whom the damage is dealt.
        // / @param oSource The source of the damage.
        // / @param iRanged Whether the attack should be treated as ranged by the engine (for example when considering damage inflicted by Acid Sheath and other such effects)
        public static void DealDamage(DamageData data, uint oTarget, uint oSource = NWN.NWScript.OBJECT_INVALID, int iRanged = NWN.NWScript.FALSE)
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Damage, "DealDamage");
            NWN.Internal.NativeFunctions.nwnxPushInt(iRanged);
            NWN.Internal.NativeFunctions.nwnxPushObject(oSource);
            NWN.Internal.NativeFunctions.nwnxPushObject(oTarget);
            NWN.Internal.NativeFunctions.nwnxPushInt(data.iBludgeoning);
            NWN.Internal.NativeFunctions.nwnxPushInt(data.iPierce);
            NWN.Internal.NativeFunctions.nwnxPushInt(data.iSlash);
            NWN.Internal.NativeFunctions.nwnxPushInt(data.iMagical);
            NWN.Internal.NativeFunctions.nwnxPushInt(data.iAcid);
            NWN.Internal.NativeFunctions.nwnxPushInt(data.iCold);
            NWN.Internal.NativeFunctions.nwnxPushInt(data.iDivine);
            NWN.Internal.NativeFunctions.nwnxPushInt(data.iElectrical);
            NWN.Internal.NativeFunctions.nwnxPushInt(data.iFire);
            NWN.Internal.NativeFunctions.nwnxPushInt(data.iNegative);
            NWN.Internal.NativeFunctions.nwnxPushInt(data.iPositive);
            NWN.Internal.NativeFunctions.nwnxPushInt(data.iSonic);
            NWN.Internal.NativeFunctions.nwnxPushInt(data.iPower);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
        }

        // / @}
    }

        public struct DamageEventData
        {
            public uint oDamager;
            public int iBludgeoning;
            public int iPierce;
            public int iSlash;
            public int iMagical;
            public int iAcid;
            public int iCold;
            public int iDivine;
            public int iElectrical;
            public int iFire;
            public int iNegative;
            public int iPositive;
            public int iSonic;
            public int iBase;
        }

        public struct AttackEventData
        {
            public uint oTarget;
            public int iBludgeoning;
            public int iPierce;
            public int iSlash;
            public int iMagical;
            public int iAcid;
            public int iCold;
            public int iDivine;
            public int iElectrical;
            public int iFire;
            public int iNegative;
            public int iPositive;
            public int iSonic;
            public int iBase;
            public int iAttackNumber;
            public int iAttackResult;
            public int iAttackType;
            public int iSneakAttack;
        }

        public struct DamageData
        {
            public int iBludgeoning;
            public int iPierce;
            public int iSlash;
            public int iMagical;
            public int iAcid;
            public int iCold;
            public int iDivine;
            public int iElectrical;
            public int iFire;
            public int iNegative;
            public int iPositive;
            public int iSonic;
            public int iPower;
        }
}
