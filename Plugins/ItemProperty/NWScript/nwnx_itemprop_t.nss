#include "nwnx_itemprop"
#include "nwnx_test"

string IPToString(struct NWNX_IPUnpacked n)
{
    string s = "Unpacked IP: ";
    s += "nProperty = " + IntToString(n.nProperty) + "\n";
    s += "nSubType = " + IntToString(n.nSubType) + "\n";
    s += "nCostTable = " + IntToString(n.nCostTable) + "\n";
    s += "nCostTableValue = " + IntToString(n.nCostTableValue) + "\n";
    s += "nParam1 = " + IntToString(n.nParam1) + "\n";
    s += "nParam1Value = " + IntToString(n.nParam1Value) + "\n";
    s += "nUsesPerDay = " + IntToString(n.nUsesPerDay) + "\n";
    s += "nChanceToAppear = " + IntToString(n.nChanceToAppear) + "\n";
    s += "bUsable = " + IntToString(n.bUsable) + "\n";
    s += "nSpellId = " + IntToString(n.nSpellId) + "\n";
    s += "sTag = " + "'" + n.sTag + "'" + "\n";
    return s;
}

void main()
{
    while(TEST("ItemProperty"))
    {
        ASSERT(IS_TRUE(NWNX_Test_PluginExists("NWNX_ItemProperty")));

        itemproperty ip = ItemPropertyDamageBonusVsRace(1,2,3);
        ip = TagItemProperty(ip, "NWNX_ItemProperty_TEST");
        struct NWNX_IPUnpacked unpacked = NWNX_ItemProperty_UnpackIP(ip);

        if(!EXPECT(IS_EQUAL_STRING(unpacked.sTag, "NWNX_ItemProperty_TEST"), "UnpackIP"))
        {
            NWNX_Test_Context(IPToString(unpacked));
        }

        itemproperty ip2 = NWNX_ItemProperty_PackIP(unpacked);
        EXPECT(IS_TRUE(GetIsItemPropertyValid(ip2)), "PackIP");
        EXPECT(IS_EQUAL_STRING(GetItemPropertyTag(ip2), "NWNX_ItemProperty_TEST"), "PackIP");
        EXPECT(IS_EQUAL_INT(GetItemPropertyCostTable(ip2), unpacked.nCostTable), "PackIP");
        EXPECT(IS_EQUAL_INT(GetItemPropertyCostTableValue(ip2), unpacked.nCostTableValue), "PackIP");
        EXPECT(IS_EQUAL_INT(GetItemPropertyParam1(ip2), unpacked.nParam1), "PackIP");
        EXPECT(IS_EQUAL_INT(GetItemPropertyParam1Value(ip2), unpacked.nParam1Value), "PackIP");
    }
}
