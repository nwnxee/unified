namespace NWNX
{
    [NWNXPlugin(NWNX_ItemProperty)]
    public class ItempropPlugin
    {
        public const string NWNX_ItemProperty = "NWNX_ItemProperty";

        // /< @private
        // / @brief An unpacked itemproperty.
        // / @brief Convert native itemproperty type to unpacked structure.
        // / @param ip The itemproperty to convert.
        // / @return A constructed NWNX_IPUnpacked.
        public static IPUnpacked UnpackIP(NWN.ItemProperty ip)
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_ItemProperty, "UnpackIP");
            NWN.Internal.NativeFunctions.nwnxPushItemProperty(ip.Handle);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
            IPUnpacked retVal;
            retVal.sTag = NWN.Internal.NativeFunctions.nwnxPopString();
            retVal.oCreator = NWN.Internal.NativeFunctions.nwnxPopObject();
            retVal.nSpellId = NWN.Internal.NativeFunctions.nwnxPopInt();
            retVal.bUsable = NWN.Internal.NativeFunctions.nwnxPopInt();
            retVal.nChanceToAppear = NWN.Internal.NativeFunctions.nwnxPopInt();
            retVal.nUsesPerDay = NWN.Internal.NativeFunctions.nwnxPopInt();
            retVal.nParam1Value = NWN.Internal.NativeFunctions.nwnxPopInt();
            retVal.nParam1 = NWN.Internal.NativeFunctions.nwnxPopInt();
            retVal.nCostTableValue = NWN.Internal.NativeFunctions.nwnxPopInt();
            retVal.nCostTable = NWN.Internal.NativeFunctions.nwnxPopInt();
            retVal.nSubType = NWN.Internal.NativeFunctions.nwnxPopInt();
            retVal.nProperty = NWN.Internal.NativeFunctions.nwnxPopInt();
            return retVal;
        }

        // / @brief Convert unpacked itemproperty structure to native type.
        // / @param ip The NWNX_IPUnpacked structure to convert.
        // / @return The itemproperty.
        public static NWN.ItemProperty PackIP(IPUnpacked ip)
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_ItemProperty, "PackIP");
            NWN.Internal.NativeFunctions.nwnxPushInt(ip.nProperty);
            NWN.Internal.NativeFunctions.nwnxPushInt(ip.nSubType);
            NWN.Internal.NativeFunctions.nwnxPushInt(ip.nCostTable);
            NWN.Internal.NativeFunctions.nwnxPushInt(ip.nCostTableValue);
            NWN.Internal.NativeFunctions.nwnxPushInt(ip.nParam1);
            NWN.Internal.NativeFunctions.nwnxPushInt(ip.nParam1Value);
            NWN.Internal.NativeFunctions.nwnxPushInt(ip.nUsesPerDay);
            NWN.Internal.NativeFunctions.nwnxPushInt(ip.nChanceToAppear);
            NWN.Internal.NativeFunctions.nwnxPushInt(ip.bUsable);
            NWN.Internal.NativeFunctions.nwnxPushInt(ip.nSpellId);
            NWN.Internal.NativeFunctions.nwnxPushObject(ip.oCreator);
            NWN.Internal.NativeFunctions.nwnxPushString(ip.sTag);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
            return new NWN.ItemProperty(NWN.Internal.NativeFunctions.nwnxPopItemProperty());
        }

        // / @}
    }

        public struct IPUnpacked
        {
            public int nProperty;
            public int nSubType;
            public int nCostTable;
            public int nCostTableValue;
            public int nParam1;
            public int nParam1Value;
            public int nUsesPerDay;
            public int nChanceToAppear;
            public int bUsable;
            public int nSpellId;
            public uint oCreator;
            public string sTag;
        }
}
