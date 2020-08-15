#include "nwnx_effect"
#include "nwnx_tests"

void printeff(struct NWNX_EffectUnpacked n)
{
    string s = "Unpacked effect: \n";
    s += "nType = " + IntToString(n.nType) + "\n";
    s += "nSubType = " + IntToString(n.nSubType) + "\n";

    s += "fDuration = " + FloatToString(n.fDuration) + "\n";
    s += "nExpiryCalendarDay = " + IntToString(n.nExpiryCalendarDay) + "\n";
    s += "nExpiryTimeOfDay = " + IntToString(n.nExpiryTimeOfDay) + "\n";

    s += "oCreator = " + ObjectToString(n.oCreator) + "\n";
    s += "nSpellId = " + IntToString(n.nSpellId) + "\n";
    s += "bExpose = " + IntToString(n.bExpose) + "\n";
    s += "bShowIcon = " + IntToString(n.bShowIcon) + "\n";
    s += "nCasterLevel = " + IntToString(n.nCasterLevel) + "\n";

    s += "bLinkLeftValid = " + IntToString(n.bLinkLeftValid) + "\n";
    struct NWNX_EffectUnpacked link = NWNX_Effect_UnpackEffect(n.eLinkLeft);
    s += "bLinkLeft (nType) = " + IntToString(link.nType) + "\n";
    s += "bLinkRightValid = " + IntToString(n.bLinkRightValid) + "\n";
    link = NWNX_Effect_UnpackEffect(n.eLinkRight);
    s += "bLinkRight (nType) = " + IntToString(link.nType) + "\n";

    s += "nNumIntegers = " + IntToString(n.nNumIntegers) + "\n";
    s += "nParam0 = " + IntToString(n.nParam0) + "\n";
    s += "nParam1 = " + IntToString(n.nParam1) + "\n";
    s += "nParam2 = " + IntToString(n.nParam2) + "\n";
    s += "nParam3 = " + IntToString(n.nParam3) + "\n";
    s += "nParam4 = " + IntToString(n.nParam4) + "\n";
    s += "nParam5 = " + IntToString(n.nParam5) + "\n";
    s += "nParam6 = " + IntToString(n.nParam6) + "\n";
    s += "nParam7 = " + IntToString(n.nParam7) + "\n";
    s += "fParam0 = " + FloatToString(n.fParam0) + "\n";
    s += "fParam1 = " + FloatToString(n.fParam1) + "\n";
    s += "fParam2 = " + FloatToString(n.fParam2) + "\n";
    s += "fParam3 = " + FloatToString(n.fParam3) + "\n";
    s += "sParam0 = " + "'" + n.sParam0 + "'" + "\n";
    s += "sParam1 = " + "'" + n.sParam1 + "'" + "\n";
    s += "sParam2 = " + "'" + n.sParam2 + "'" + "\n";
    s += "sParam3 = " + "'" + n.sParam3 + "'" + "\n";
    s += "sParam4 = " + "'" + n.sParam4 + "'" + "\n";
    s += "sParam5 = " + "'" + n.sParam5 + "'" + "\n";
    s += "oParam0 = " + ObjectToString(n.oParam0) + "\n";
    s += "oParam1 = " + ObjectToString(n.oParam1) + "\n";
    s += "oParam2 = " + ObjectToString(n.oParam2) + "\n";
    s += "oParam3 = " + ObjectToString(n.oParam3) + "\n";
    s += "vParam0 = {" + FloatToString(n.vParam0.x) + ", " + FloatToString(n.vParam0.y) + ", " + FloatToString(n.vParam0.z) + "}\n";
    s += "vParam1 = {" + FloatToString(n.vParam1.x) + ", " + FloatToString(n.vParam1.y) + ", " + FloatToString(n.vParam1.z) + "}\n";

    s += "sTag = " + "'" + n.sTag + "'" + "\n";

    WriteTimestampedLogEntry(s);
}

void main()
{
    WriteTimestampedLogEntry("NWNX_Effect unit test begin..");

    effect eCurse = EffectCurse(1, 2, 3, 4, 5, 6);
    effect eVis = EffectVisualEffect(VFX_DUR_PROT_STONESKIN);
    effect e = EffectLinkEffects(eCurse, eVis);
    e = TagEffect(e, "NWNX_EFFECT_TEST");

    struct NWNX_EffectUnpacked unpacked = NWNX_Effect_UnpackEffect(e);
    printeff(unpacked);
    NWNX_Tests_Report("NWNX_Effect", "UnpackEffect", unpacked.sTag == "NWNX_EFFECT_TEST");

    effect packed = NWNX_Effect_PackEffect(unpacked);
    NWNX_Tests_Report("NWNX_Effect", "PackEffect", GetEffectTag(packed) == "NWNX_EFFECT_TEST");

    object oCreature = CreateObject(OBJECT_TYPE_CREATURE, "nw_chicken", GetStartingLocation());
    ApplyEffectToObject(DURATION_TYPE_PERMANENT, packed, oCreature);

    e = NWNX_Effect_SetEffectExpiredScript(EffectDarkness(), "effect_test");
    unpacked = NWNX_Effect_UnpackEffect(e);
    NWNX_Tests_Report("NWNX_Effect", "SetEffectExpiredScript", unpacked.sParam4 == "effect_test");


    e = GetFirstEffect(oCreature);
    while (GetIsEffectValid(e))
    {
        if (GetEffectTag(e) == "NWNX_EFFECT_TEST")
            break;
        e = GetNextEffect(oCreature);
    }
    NWNX_Effect_ReplaceEffect(oCreature, e, TagEffect(e, "NWNX_EFFECT_REPLACED"));
    e = GetFirstEffect(oCreature);
    while (GetIsEffectValid(e))
    {
        if (GetEffectTag(e) == "NWNX_EFFECT_REPLACED")
        {
            NWNX_Tests_Report("NWNX_Effect", "ReplaceEffect", TRUE);
            break;
        }
        e = GetNextEffect(oCreature);
    }

    WriteTimestampedLogEntry("NWNX_Effect unit test end.");
}
