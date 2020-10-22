#include "nwnx_object"
#include "nwnx_tests"

void main()
{
    WriteTimestampedLogEntry("NWNX_Object unit test begin..");

    object o = CreateObject(OBJECT_TYPE_CREATURE, "nw_chicken", GetStartingLocation());
    if (!GetIsObjectValid(o))
    {
        WriteTimestampedLogEntry("NWNX_Object test: Failed to create creature");
        return;
    }

    int nVarCount = NWNX_Object_GetLocalVariableCount(o);
    SetLocalInt(o, "nwnx_object_test", 1);
    NWNX_Tests_Report("NWNX_Object", "GetLocalVariableCount", NWNX_Object_GetLocalVariableCount(o) == (nVarCount+1));

    struct NWNX_Object_LocalVariable lv = NWNX_Object_GetLocalVariable(o, nVarCount);
    NWNX_Tests_Report("NWNX_Object", "GetLocalVariable", lv.key == "nwnx_object_test");
    NWNX_Tests_Report("NWNX_Object", "GetLocalVariable", lv.type == NWNX_OBJECT_LOCALVAR_TYPE_INT);

    vector vPos = GetPosition(o);
    vPos.x += 1;
    NWNX_Object_SetPosition(o, vPos);
    NWNX_Tests_Report("NWNX_Object", "SetPosition", GetPosition(o).x == vPos.x);

    int nMaxHP = GetMaxHitPoints(o);
    NWNX_Object_SetMaxHitPoints(o, nMaxHP + 1);
    NWNX_Tests_Report("NWNX_Object", "SetMaxHitPoints", GetMaxHitPoints(o) == (nMaxHP + 1));

    int nCurrHP = GetCurrentHitPoints(o);
    NWNX_Object_SetCurrentHitPoints(o, nCurrHP + 1);
    NWNX_Tests_Report("NWNX_Object", "SetCurrentHitPoints", GetCurrentHitPoints(o) == (nCurrHP + 1));

    string dialog = "nwnxtest";
    NWNX_Object_SetDialogResref(o, dialog);
    NWNX_Tests_Report("NWNX_Object", "SetDialogResRef/GetDialogResRef", NWNX_Object_GetDialogResref(o) == dialog);

    NWNX_Object_SetInt(o, "TestInt", 10, TRUE);
    NWNX_Object_SetString(o, "TestString_1", "This is a string.", TRUE);
    NWNX_Object_SetString(o, "TestString_2", "This is another string.", TRUE);
    NWNX_Object_SetFloat(o, "TestFloat", 1.5f, TRUE);
    NWNX_Tests_Report("NWNX_Object", "Set/GetInt", NWNX_Object_GetInt(o, "TestInt") == 10);
    NWNX_Tests_Report("NWNX_Object", "Set/GetString #1", NWNX_Object_GetString(o, "TestString_1") == "This is a string.");
    NWNX_Tests_Report("NWNX_Object", "Set/GetString #2", NWNX_Object_GetString(o, "TestString_2") == "This is another string.");
    NWNX_Tests_Report("NWNX_Object", "Set/GetFloat", NWNX_Object_GetFloat(o, "TestFloat") == 1.5f);

    string sSerialized = NWNX_Object_Serialize(o);
    NWNX_Tests_Report("NWNX_Object", "Serialize", sSerialized != "");
    WriteTimestampedLogEntry("Serialized chicken: " + sSerialized);

    object oDeserialized = NWNX_Object_Deserialize(sSerialized);
    NWNX_Tests_Report("NWNX_Object", "Deserialize", GetIsObjectValid(oDeserialized));

    NWNX_Object_DeleteInt(o, "TestInt");
    NWNX_Object_DeleteString(o, "TestString_1");
    NWNX_Object_DeleteString(o, "TestString_2");
    NWNX_Object_DeleteFloat(o, "TestFloat");
    NWNX_Tests_Report("NWNX_Object", "DeleteInt", NWNX_Object_GetInt(o, "TestInt") == 0);
    NWNX_Tests_Report("NWNX_Object", "DeleteString #1", NWNX_Object_GetString(o, "TestString_1") == "");
    NWNX_Tests_Report("NWNX_Object", "DeleteString #2", NWNX_Object_GetString(o, "TestString_2") == "");
    NWNX_Tests_Report("NWNX_Object", "DeleteFloat", NWNX_Object_GetFloat(o, "TestFloat") == 0.0f);

    NWNX_Tests_Report("NWNX_Object", "(Deserialized Object) GetInt", NWNX_Object_GetInt(oDeserialized, "TestInt") == 10);
    NWNX_Tests_Report("NWNX_Object", "(Deserialized Object) GetString #1", NWNX_Object_GetString(oDeserialized, "TestString_1") == "This is a string.");
    NWNX_Tests_Report("NWNX_Object", "(Deserialized Object) GetString #2", NWNX_Object_GetString(oDeserialized, "TestString_2") == "This is another string.");
    NWNX_Tests_Report("NWNX_Object", "(Deserialized Object) GetFloat", NWNX_Object_GetFloat(oDeserialized, "TestFloat") == 1.5f);

    NWNX_Object_DeleteVarRegex(oDeserialized, ".*TestString.*");

    NWNX_Tests_Report("NWNX_Object", "DeleteVarRegex", NWNX_Object_GetInt(oDeserialized, "TestInt") == 10);
    NWNX_Tests_Report("NWNX_Object", "DeleteVarRegex", NWNX_Object_GetString(oDeserialized, "TestString_1") == "");
    NWNX_Tests_Report("NWNX_Object", "DeleteVarRegex", NWNX_Object_GetString(oDeserialized, "TestString_2") == "");
    NWNX_Tests_Report("NWNX_Object", "DeleteVarRegex", NWNX_Object_GetFloat(oDeserialized, "TestFloat") == 1.5f);

    WriteTimestampedLogEntry("Deserialized " + GetName(oDeserialized) + " in " + GetName(GetArea(oDeserialized)));

    object bag = CreateObject(OBJECT_TYPE_ITEM, "nw_it_contain006", GetStartingLocation()); // Bag of holding
    CreateItemOnObject("x2_it_adaplate", bag, 1);
    CreateItemOnObject("x2_it_adaplate", bag, 1);
    CreateItemOnObject("x2_it_adaplate", bag, 1);
    int iFits = NWNX_Object_CheckFit(bag, BASE_ITEM_ARROW);
    NWNX_Tests_Report("NWNX_Object", "CheckFit", iFits == 1);
    iFits = NWNX_Object_CheckFit(bag, BASE_ITEM_ARMOR);
    NWNX_Tests_Report("NWNX_Object", "CheckFit", iFits == 0);
    object oItem = GetFirstItemInInventory(bag);
    while (oItem != OBJECT_INVALID)
    {
        DestroyObject(oItem);
        oItem = GetNextItemInInventory(bag);
    }
    DestroyObject(bag);

    NWNX_Tests_Report("NWNX_Object", "GetDamageImmunity", NWNX_Object_GetDamageImmunity(o, DAMAGE_TYPE_FIRE) == 0);
    ApplyEffectToObject(DURATION_TYPE_PERMANENT, EffectDamageImmunityIncrease(DAMAGE_TYPE_FIRE, 50), o);
    NWNX_Tests_Report("NWNX_Object", "GetDamageImmunity", NWNX_Object_GetDamageImmunity(o, DAMAGE_TYPE_FIRE) == 50);

    object oPlc = CreateObject(OBJECT_TYPE_PLACEABLE, "nw_defportal", GetStartingLocation());
    NWNX_Object_SetPlaceableIsStatic(oPlc, 1);
    NWNX_Tests_Report("NWNX_Object", "SetPlaceableIsStatic 1", NWNX_Object_GetPlaceableIsStatic(oPlc) == 1);
    DestroyObject(oPlc);

    oPlc = CreateObject(OBJECT_TYPE_PLACEABLE, "nw_plc_driftwd1", GetStartingLocation());
    NWNX_Object_SetPlaceableIsStatic(oPlc, 0);
    NWNX_Tests_Report("NWNX_Object", "SetPlaceableIsStatic 2", NWNX_Object_GetPlaceableIsStatic(oPlc) == 0);
    DestroyObject(oPlc);

    oPlc = CreateObject(OBJECT_TYPE_PLACEABLE, "nw_plc_driftwd1", GetStartingLocation());
    NWNX_Object_SetAutoRemoveKey(oPlc, 1);
    NWNX_Tests_Report("NWNX_Object", "SetAutoRemoveKey", NWNX_Object_GetAutoRemoveKey(oPlc) == 1);
    DestroyObject(oPlc);

    int bHasInventory = GetHasInventory(oPlc);
    oPlc = CreateObject(OBJECT_TYPE_PLACEABLE, "nw_plc_driftwd1", GetStartingLocation());
    NWNX_Object_SetHasInventory(oPlc, !bHasInventory);
    NWNX_Tests_Report("NWNX_Object", "SetHasInventory", GetHasInventory(oPlc) == !bHasInventory);
    DestroyObject(oPlc);

    DestroyObject(o);
    DestroyObject(oDeserialized);
    WriteTimestampedLogEntry("NWNX_Object unit test end.");
}
