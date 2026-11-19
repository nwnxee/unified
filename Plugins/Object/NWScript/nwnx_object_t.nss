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

    SetLocalString(o, "nwnx_object_test", "x");
    SetLocalFloat(o, "nwnx_object_test_f", 1.0);
    json jAll = NWNX_Object_GetLocalVariables(o);
    NWNX_Tests_Report("NWNX_Object", "GetLocalVariables", JsonGetLength(jAll) >= nVarCount + 3);
    json jTest = NWNX_Object_GetLocalVariables(o, -1, "nwnx_object_test");
    NWNX_Tests_Report("NWNX_Object", "GetLocalVariables (prefix)", JsonGetLength(jTest) == 3);
    json jInts = NWNX_Object_GetLocalVariables(o, NWNX_OBJECT_LOCALVAR_TYPE_INT, "nwnx_object_test");
    NWNX_Tests_Report("NWNX_Object", "GetLocalVariables (type)", JsonGetLength(jInts) == 1 &&
        JsonGetString(JsonObjectGet(JsonArrayGet(jInts, 0), "key")) == "nwnx_object_test" &&
        JsonGetInt(JsonObjectGet(JsonArrayGet(jInts, 0), "type")) == NWNX_OBJECT_LOCALVAR_TYPE_INT);
    json jFloats = NWNX_Object_GetLocalVariables(o, NWNX_OBJECT_LOCALVAR_TYPE_FLOAT, "nwnx_object_test");
    NWNX_Tests_Report("NWNX_Object", "GetLocalVariables (type)", JsonGetLength(jFloats) == 1 &&
        JsonGetString(JsonObjectGet(JsonArrayGet(jFloats, 0), "key")) == "nwnx_object_test_f");
    NWNX_Tests_Report("NWNX_Object", "GetLocalVariables (no match)", JsonGetLength(NWNX_Object_GetLocalVariables(o, -1, "nwnx_object_test_zz")) == 0);
    NWNX_Tests_Report("NWNX_Object", "GetLocalVariables (invalid)", JsonGetLength(NWNX_Object_GetLocalVariables(OBJECT_INVALID)) == 0);
    DeleteLocalString(o, "nwnx_object_test");
    DeleteLocalFloat(o, "nwnx_object_test_f");

    vector vPos = GetPosition(o);
    vPos.x += 1;
    NWNX_Object_SetPosition(o, vPos);
    NWNX_Tests_Report("NWNX_Object", "SetPosition", GetPosition(o).x == vPos.x);

    int nMaxHP = GetMaxHitPoints(o);
    NWNX_Object_SetMaxHitPoints(o, nMaxHP + 1);
    NWNX_Tests_Report("NWNX_Object", "SetMaxHitPoints", GetMaxHitPoints(o) == (nMaxHP + 1));

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

    oPlc = CreateObject(OBJECT_TYPE_PLACEABLE, "nw_plc_driftwd1", GetStartingLocation());
    NWNX_Object_SetAILevel(oPlc, AI_LEVEL_VERY_HIGH);
    NWNX_Tests_Report("NWNX_Object", "{Get/Set}AILevel", NWNX_Object_GetAILevel(oPlc) == AI_LEVEL_VERY_HIGH);
    DestroyObject(oPlc);

    DestroyObject(o);
    DestroyObject(oDeserialized);
    WriteTimestampedLogEntry("NWNX_Object unit test end.");
}
