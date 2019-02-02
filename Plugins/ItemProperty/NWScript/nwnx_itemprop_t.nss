#include "nwnx_itemprop"

void printip(struct NWNX_IPUnpacked n)
{
    string s = "Unpacked IP: \n";
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

void report(string func, int bSuccess)
{
    if (bSuccess)
        WriteTimestampedLogEntry("NWNX_ItemProperty: " + func + "() success");
    else
        WriteTimestampedLogEntry("NWNX_ItemProperty: " + func + "() failed");
}

void main()
{
    WriteTimestampedLogEntry("NWNX_ItemProperty unit test begin..");

    itemproperty ip = ItemPropertyDamageBonusVsRace(1,2,3);
    ip = TagItemProperty(ip, "NWNX_ItemProperty_TEST");

    struct NWNX_IPUnpacked unpacked = NWNX_ItemProperty_UnpackIP(ip);
    printip(unpacked);
    report("UnpackIP", unpacked.sTag == "NWNX_ItemProperty_TEST");

    itemproperty ip2 = NWNX_ItemProperty_PackIP(unpacked);
    report("PackIP", GetIsItemPropertyValid(ip2));
    report("PackIP", GetItemPropertyTag(ip2) == "NWNX_ItemProperty_TEST");
    report("PackIP", GetItemPropertyCostTable(ip2) == unpacked.nCostTable);
    report("PackIP", GetItemPropertyCostTableValue(ip2) == unpacked.nCostTableValue);
    report("PackIP", GetItemPropertyParam1(ip2) == unpacked.nParam1);
    report("PackIP", GetItemPropertyParam1Value(ip2) == unpacked.nParam1Value);

    WriteTimestampedLogEntry("NWNX_ItemProperty unit test end.");
}
