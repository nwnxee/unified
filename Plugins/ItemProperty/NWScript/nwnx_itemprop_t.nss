#include "nwnx_itemprop"
#include "nwnx_tests"

void printip(struct NWNX_IPUnpacked n)
{
    string s = "Unpacked IP: \n";

    s += "sID = " + "'" + n.sID + "'" + "\n";
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

    WriteTimestampedLogEntry(s);
}

void main()
{
    WriteTimestampedLogEntry("NWNX_ItemProperty unit test begin..");

    itemproperty ip = ItemPropertyDamageBonusVsRace(1,2,3);
    ip = TagItemProperty(ip, "NWNX_ItemProperty_TEST");

    struct NWNX_IPUnpacked unpacked = NWNX_ItemProperty_UnpackIP(ip);
    printip(unpacked);
    NWNX_Tests_Report("NWNX_ItemProperty", "UnpackIP", unpacked.sTag == "NWNX_ItemProperty_TEST");

    itemproperty ip2 = NWNX_ItemProperty_PackIP(unpacked);
    NWNX_Tests_Report("NWNX_ItemProperty", "PackIP", GetIsItemPropertyValid(ip2));
    NWNX_Tests_Report("NWNX_ItemProperty", "PackIP", GetItemPropertyTag(ip2) == "NWNX_ItemProperty_TEST");
    NWNX_Tests_Report("NWNX_ItemProperty", "PackIP", GetItemPropertyCostTable(ip2) == unpacked.nCostTable);
    NWNX_Tests_Report("NWNX_ItemProperty", "PackIP", GetItemPropertyCostTableValue(ip2) == unpacked.nCostTableValue);
    NWNX_Tests_Report("NWNX_ItemProperty", "PackIP", GetItemPropertyParam1(ip2) == unpacked.nParam1);
    NWNX_Tests_Report("NWNX_ItemProperty", "PackIP", GetItemPropertyParam1Value(ip2) == unpacked.nParam1Value);

    object oItem = CreateObject(OBJECT_TYPE_ITEM, "nw_it_sparscr604", GetStartingLocation());
    if(!GetIsObjectValid(oItem))
    {
        WriteTimestampedLogEntry("No item created for NWNX_ItemProp tests.");
        return;
    }
    unpacked = NWNX_ItemProperty_GetActiveProperty(oItem, 0);
    printip(unpacked);
    NWNX_Tests_Report("NWNX_ItemProperty", "GetActiveProperty", unpacked.nProperty == ITEM_PROPERTY_CAST_SPELL);

    WriteTimestampedLogEntry("NWNX_ItemProperty unit test end.");
}
