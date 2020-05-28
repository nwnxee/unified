namespace NWNX
{
    [NWNXPlugin(NWNX_Effect)]
    public class EffectPlugin
    {
        public const string NWNX_Effect = "NWNX_Effect";

        // /< @private
        // / An unpacked effect
        // / @brief Convert native effect type to unpacked structure.
        // / @param e The effect to convert.
        // / @return A constructed NWNX_EffectUnpacked.
        public static EffectUnpacked UnpackEffect(NWN.Effect e)
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Effect, "UnpackEffect");
            NWN.Internal.NativeFunctions.nwnxPushEffect(e.Handle);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
            EffectUnpacked retVal;
            retVal.sTag = NWN.Internal.NativeFunctions.nwnxPopString();
            retVal.oParam3 = NWN.Internal.NativeFunctions.nwnxPopObject();
            retVal.oParam2 = NWN.Internal.NativeFunctions.nwnxPopObject();
            retVal.oParam1 = NWN.Internal.NativeFunctions.nwnxPopObject();
            retVal.oParam0 = NWN.Internal.NativeFunctions.nwnxPopObject();
            retVal.sParam5 = NWN.Internal.NativeFunctions.nwnxPopString();
            retVal.sParam4 = NWN.Internal.NativeFunctions.nwnxPopString();
            retVal.sParam3 = NWN.Internal.NativeFunctions.nwnxPopString();
            retVal.sParam2 = NWN.Internal.NativeFunctions.nwnxPopString();
            retVal.sParam1 = NWN.Internal.NativeFunctions.nwnxPopString();
            retVal.sParam0 = NWN.Internal.NativeFunctions.nwnxPopString();
            retVal.fParam3 = NWN.Internal.NativeFunctions.nwnxPopFloat();
            retVal.fParam2 = NWN.Internal.NativeFunctions.nwnxPopFloat();
            retVal.fParam1 = NWN.Internal.NativeFunctions.nwnxPopFloat();
            retVal.fParam0 = NWN.Internal.NativeFunctions.nwnxPopFloat();
            retVal.nParam7 = NWN.Internal.NativeFunctions.nwnxPopInt();
            retVal.nParam6 = NWN.Internal.NativeFunctions.nwnxPopInt();
            retVal.nParam5 = NWN.Internal.NativeFunctions.nwnxPopInt();
            retVal.nParam4 = NWN.Internal.NativeFunctions.nwnxPopInt();
            retVal.nParam3 = NWN.Internal.NativeFunctions.nwnxPopInt();
            retVal.nParam2 = NWN.Internal.NativeFunctions.nwnxPopInt();
            retVal.nParam1 = NWN.Internal.NativeFunctions.nwnxPopInt();
            retVal.nParam0 = NWN.Internal.NativeFunctions.nwnxPopInt();
            retVal.nNumIntegers = NWN.Internal.NativeFunctions.nwnxPopInt();
            retVal.bLinkRightValid = NWN.Internal.NativeFunctions.nwnxPopInt();
            retVal.eLinkRight = new NWN.Effect(NWN.Internal.NativeFunctions.nwnxPopEffect());
            retVal.bLinkLeftValid = NWN.Internal.NativeFunctions.nwnxPopInt();
            retVal.eLinkLeft = new NWN.Effect(NWN.Internal.NativeFunctions.nwnxPopEffect());
            retVal.nCasterLevel = NWN.Internal.NativeFunctions.nwnxPopInt();
            retVal.bShowIcon = NWN.Internal.NativeFunctions.nwnxPopInt();
            retVal.bExpose = NWN.Internal.NativeFunctions.nwnxPopInt();
            retVal.nSpellId = NWN.Internal.NativeFunctions.nwnxPopInt();
            retVal.oCreator = NWN.Internal.NativeFunctions.nwnxPopObject();
            retVal.nExpiryTimeOfDay = NWN.Internal.NativeFunctions.nwnxPopInt();
            retVal.nExpiryCalendarDay = NWN.Internal.NativeFunctions.nwnxPopInt();
            retVal.fDuration = NWN.Internal.NativeFunctions.nwnxPopFloat();
            retVal.nSubType = NWN.Internal.NativeFunctions.nwnxPopInt();
            retVal.nType = NWN.Internal.NativeFunctions.nwnxPopInt();
            return retVal;
        }

        // / @brief Convert unpacked effect structure to native type.
        // / @param e The NWNX_EffectUnpacked structure to convert.
        // / @return The effect.
        public static NWN.Effect PackEffect(EffectUnpacked e)
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Effect, "PackEffect");
            NWN.Internal.NativeFunctions.nwnxPushInt(e.nType);
            NWN.Internal.NativeFunctions.nwnxPushInt(e.nSubType);
            NWN.Internal.NativeFunctions.nwnxPushFloat(e.fDuration);
            NWN.Internal.NativeFunctions.nwnxPushInt(e.nExpiryCalendarDay);
            NWN.Internal.NativeFunctions.nwnxPushInt(e.nExpiryTimeOfDay);
            NWN.Internal.NativeFunctions.nwnxPushObject(e.oCreator);
            NWN.Internal.NativeFunctions.nwnxPushInt(e.nSpellId);
            NWN.Internal.NativeFunctions.nwnxPushInt(e.bExpose);
            NWN.Internal.NativeFunctions.nwnxPushInt(e.bShowIcon);
            NWN.Internal.NativeFunctions.nwnxPushInt(e.nCasterLevel);
            NWN.Internal.NativeFunctions.nwnxPushEffect(e.eLinkLeft.Handle);
            NWN.Internal.NativeFunctions.nwnxPushInt(e.bLinkLeftValid);
            NWN.Internal.NativeFunctions.nwnxPushEffect(e.eLinkRight.Handle);
            NWN.Internal.NativeFunctions.nwnxPushInt(e.bLinkRightValid);
            NWN.Internal.NativeFunctions.nwnxPushInt(e.nNumIntegers);
            NWN.Internal.NativeFunctions.nwnxPushInt(e.nParam0);
            NWN.Internal.NativeFunctions.nwnxPushInt(e.nParam1);
            NWN.Internal.NativeFunctions.nwnxPushInt(e.nParam2);
            NWN.Internal.NativeFunctions.nwnxPushInt(e.nParam3);
            NWN.Internal.NativeFunctions.nwnxPushInt(e.nParam4);
            NWN.Internal.NativeFunctions.nwnxPushInt(e.nParam5);
            NWN.Internal.NativeFunctions.nwnxPushInt(e.nParam6);
            NWN.Internal.NativeFunctions.nwnxPushInt(e.nParam7);
            NWN.Internal.NativeFunctions.nwnxPushFloat(e.fParam0);
            NWN.Internal.NativeFunctions.nwnxPushFloat(e.fParam1);
            NWN.Internal.NativeFunctions.nwnxPushFloat(e.fParam2);
            NWN.Internal.NativeFunctions.nwnxPushFloat(e.fParam3);
            NWN.Internal.NativeFunctions.nwnxPushString(e.sParam0);
            NWN.Internal.NativeFunctions.nwnxPushString(e.sParam1);
            NWN.Internal.NativeFunctions.nwnxPushString(e.sParam2);
            NWN.Internal.NativeFunctions.nwnxPushString(e.sParam3);
            NWN.Internal.NativeFunctions.nwnxPushString(e.sParam4);
            NWN.Internal.NativeFunctions.nwnxPushString(e.sParam5);
            NWN.Internal.NativeFunctions.nwnxPushObject(e.oParam0);
            NWN.Internal.NativeFunctions.nwnxPushObject(e.oParam1);
            NWN.Internal.NativeFunctions.nwnxPushObject(e.oParam2);
            NWN.Internal.NativeFunctions.nwnxPushObject(e.oParam3);
            NWN.Internal.NativeFunctions.nwnxPushString(e.sTag);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
            return new NWN.Effect(NWN.Internal.NativeFunctions.nwnxPopEffect());
        }

        // / @brief Set a script with optional data that runs when an effect expires
        // / @param e The effect.
        // / @param script The script to run when the effect expires.
        // / @param data Any other data you wish to send back to the script.
        // / @remark OBJECT_SELF in the script is the object the effect is applied to.
        // / @note Only works for TEMPORARY and PERMANENT effects applied to an object.
        public static NWN.Effect SetEffectExpiredScript(NWN.Effect e, string script, string data = "")
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Effect, "SetEffectExpiredScript");
            NWN.Internal.NativeFunctions.nwnxPushString(data);
            NWN.Internal.NativeFunctions.nwnxPushString(script);
            NWN.Internal.NativeFunctions.nwnxPushEffect(e.Handle);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
            return new NWN.Effect(NWN.Internal.NativeFunctions.nwnxPopEffect());
        }

        // / @brief Get the data set with NWNX_Effect_SetEffectExpiredScript()
        // / @note Should only be called from a script set with NWNX_Effect_SetEffectExpiredScript().
        // / @return The data attached to the effect.
        public static string GetEffectExpiredData()
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Effect, "GetEffectExpiredData");
            NWN.Internal.NativeFunctions.nwnxCallFunction();
            return NWN.Internal.NativeFunctions.nwnxPopString();
        }

        // / @brief Get the effect creator.
        // / @note Should only be called from a script set with NWNX_Effect_SetEffectExpiredScript().
        // / @return The object from which the effect originated.
        public static uint GetEffectExpiredCreator()
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Effect, "GetEffectExpiredCreator");
            NWN.Internal.NativeFunctions.nwnxCallFunction();
            return NWN.Internal.NativeFunctions.nwnxPopObject();
        }

        // / @}
    }

        public struct EffectUnpacked
        {
            public int nType;
            public int nSubType;
            public float fDuration;
            public int nExpiryCalendarDay;
            public int nExpiryTimeOfDay;
            public uint oCreator;
            public int nSpellId;
            public int bExpose;
            public int bShowIcon;
            public int nCasterLevel;
            public NWN.Effect eLinkLeft;
            public int bLinkLeftValid;
            public NWN.Effect eLinkRight;
            public int bLinkRightValid;
            public int nNumIntegers;
            public int nParam0;
            public int nParam1;
            public int nParam2;
            public int nParam3;
            public int nParam4;
            public int nParam5;
            public int nParam6;
            public int nParam7;
            public float fParam0;
            public float fParam1;
            public float fParam2;
            public float fParam3;
            public string sParam0;
            public string sParam1;
            public string sParam2;
            public string sParam3;
            public string sParam4;
            public string sParam5;
            public uint oParam0;
            public uint oParam1;
            public uint oParam2;
            public uint oParam3;
            public string sTag;
        }
}
