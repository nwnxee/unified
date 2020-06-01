#include "nwnx_object"
#include "nwnx_test"

void main()
{
    while (TEST("Object"))
    {
        ASSERT(IS_TRUE(NWNX_Test_PluginExists("NWNX_SkillRanks")));

        object o = CreateObject(OBJECT_TYPE_CREATURE, "nw_chicken", GetStartingLocation());
        ASSERT(IS_VALID(o));

        int nVarCount = NWNX_Object_GetLocalVariableCount(o);
        SetLocalInt(o, "nwnx_object_test", 1);
        EXPECT(IS_EQUAL_INT(NWNX_Object_GetLocalVariableCount(o), (nVarCount+1)), "GetLocalVariableCount");

        struct NWNX_Object_LocalVariable lv = NWNX_Object_GetLocalVariable(o, nVarCount);
        EXPECT(IS_EQUAL_STRING(lv.key, "nwnx_object_test"), "GetLocalVariable");
        EXPECT(IS_EQUAL_INT(lv.type, NWNX_OBJECT_LOCALVAR_TYPE_INT), "GetLocalVariable");

        string sObj = ObjectToString(o);
        EXPECT(IS_TRUE(NWNX_Object_StringToObject(sObj) == o), "StringToObject");
        // NOTE: this test throws an expception.
        EXPECT(IS_INVALID(NWNX_Object_StringToObject("!@#!@#!@#!")), "Negative: StringToObject");

        vector vPos = GetPosition(o);
        vPos.x += 1;
        NWNX_Object_SetPosition(o, vPos);
        EXPECT(IS_EQUAL_FLOAT(GetPosition(o).x, vPos.x), "SetPosition");

        object bag = CreateObject(OBJECT_TYPE_ITEM, "nw_it_contain006", GetStartingLocation()); // Bag of holding
        ASSERT(IS_VALID(bag));

        // NOTE: This test will fail on nw_chicken.
        int nMaxHP = GetMaxHitPoints(bag);
        NWNX_Object_SetMaxHitPoints(bag, nMaxHP + 1);
        EXPECT(IS_EQUAL_INT(GetMaxHitPoints(bag), (nMaxHP + 1)), "SetMaxHitPoints");

        int nCurrHP = GetCurrentHitPoints(o);
        NWNX_Object_SetCurrentHitPoints(o, nCurrHP + 1);
        EXPECT(IS_EQUAL_INT(GetCurrentHitPoints(o), (nCurrHP + 1)), "SetCurrentHitPoints");

        string dialog = "nwnxtest";
        NWNX_Object_SetDialogResref(o, dialog);
        EXPECT(IS_EQUAL_STRING(NWNX_Object_GetDialogResref(o), dialog), "SetDialogResRef/GetDialogResRef");

        NWNX_Object_SetInt(o, "TestInt", 10, TRUE);
        NWNX_Object_SetString(o, "TestString_1", "This is a string.", TRUE);
        NWNX_Object_SetString(o, "TestString_2", "This is another string.", TRUE);
        NWNX_Object_SetFloat(o, "TestFloat", 1.5f, TRUE);
        EXPECT(IS_EQUAL_INT(NWNX_Object_GetInt(o, "TestInt"), 10), "Set/GetInt");
        EXPECT(IS_EQUAL_STRING(NWNX_Object_GetString(o, "TestString_1"), "This is a string."), "Set/GetString #1");
        EXPECT(IS_EQUAL_STRING(NWNX_Object_GetString(o, "TestString_2"), "This is another string."), "Set/GetString #2");
        EXPECT(IS_EQUAL_FLOAT(NWNX_Object_GetFloat(o, "TestFloat"), 1.5f), "Set/GetFloat");

        while(TEST("Serialization"))
        {
            string sSerialized = NWNX_Object_Serialize(o);
            EXPECT(IS_TRUE(sSerialized != ""), "Serialize");
            WriteTimestampedLogEntry("Serialized chicken: " + sSerialized);

            object oDeserialized = NWNX_Object_Deserialize(sSerialized);
            EXPECT(IS_VALID(oDeserialized), "Deserialize");

            NWNX_Object_DeleteInt(o, "TestInt");
            NWNX_Object_DeleteString(o, "TestString_1");
            NWNX_Object_DeleteString(o, "TestString_2");
            NWNX_Object_DeleteFloat(o, "TestFloat");
            EXPECT(IS_EQUAL_INT(NWNX_Object_GetInt(o, "TestInt"), 0), "DeleteInt");
            EXPECT(IS_EQUAL_STRING(NWNX_Object_GetString(o, "TestString_1"), ""), "DeleteString #1");
            EXPECT(IS_EQUAL_STRING(NWNX_Object_GetString(o, "TestString_2"), ""), "DeleteString #2");
            EXPECT(IS_EQUAL_FLOAT(NWNX_Object_GetFloat(o, "TestFloat"), 0.0f), "DeleteFloat");

            EXPECT(IS_EQUAL_INT(NWNX_Object_GetInt(oDeserialized, "TestInt"), 10), "(Deserialized Object) GetInt");
            EXPECT(IS_EQUAL_STRING(NWNX_Object_GetString(oDeserialized, "TestString_1"), "This is a string."), "(Deserialized Object) GetString #1");
            EXPECT(IS_EQUAL_STRING(NWNX_Object_GetString(oDeserialized, "TestString_2"), "This is another string."), "(Deserialized Object) GetString #2");
            EXPECT(IS_EQUAL_FLOAT(NWNX_Object_GetFloat(oDeserialized, "TestFloat"), 1.5f), "(Deserialized Object) GetFloat");

            NWNX_Object_DeleteVarRegex(oDeserialized, ".*TestString.*");

            EXPECT(IS_EQUAL_INT(NWNX_Object_GetInt(oDeserialized, "TestInt"), 10), "DeleteVarRegex");
            EXPECT(IS_EQUAL_STRING(NWNX_Object_GetString(oDeserialized, "TestString_1"), ""), "DeleteVarRegex");
            EXPECT(IS_EQUAL_STRING(NWNX_Object_GetString(oDeserialized, "TestString_2"), ""), "DeleteVarRegex");
            EXPECT(IS_EQUAL_FLOAT(NWNX_Object_GetFloat(oDeserialized, "TestFloat"), 1.5f), "DeleteVarRegex");

            WriteTimestampedLogEntry("Deserialized " + GetName(oDeserialized) + " in " + GetName(GetArea(oDeserialized)));
            DestroyObject(oDeserialized);
        }

        while(TEST("Inventory"))
        {
            CreateItemOnObject("x2_it_adaplate", bag, 1);
            CreateItemOnObject("x2_it_adaplate", bag, 1);
            CreateItemOnObject("x2_it_adaplate", bag, 1);
            int iFits = NWNX_Object_CheckFit(bag, BASE_ITEM_ARROW);
            EXPECT(IS_EQUAL_INT(iFits, 1), "CheckFit");
            iFits = NWNX_Object_CheckFit(bag, BASE_ITEM_ARMOR);
            EXPECT(IS_EQUAL_INT(iFits, 0), "CheckFit");
            object oItem = GetFirstItemInInventory(bag);
            while (oItem != OBJECT_INVALID)
            {
                DestroyObject(oItem);
                oItem = GetNextItemInInventory(bag);
            }
            DestroyObject(bag);
        }
/*

        EXPECT("GetDamageImmunity", NWNX_Object_GetDamageImmunity(o, DAMAGE_TYPE_FIRE) == 0);
        ApplyEffectToObject(DURATION_TYPE_PERMANENT, EffectDamageImmunityIncrease(DAMAGE_TYPE_FIRE, 50), o);
        EXPECT("GetDamageImmunity", NWNX_Object_GetDamageImmunity(o, DAMAGE_TYPE_FIRE) == 50);

        object oPlc = CreateObject(OBJECT_TYPE_PLACEABLE, "nw_defportal", GetStartingLocation());
        NWNX_Object_SetPlaceableIsStatic(oPlc, 1);
        EXPECT("SetPlaceableIsStatic 1", NWNX_Object_GetPlaceableIsStatic(oPlc) == 1);
        DestroyObject(oPlc);

        oPlc = CreateObject(OBJECT_TYPE_PLACEABLE, "nw_plc_driftwd1", GetStartingLocation());
        NWNX_Object_SetPlaceableIsStatic(oPlc, 0);
        EXPECT("SetPlaceableIsStatic 2", NWNX_Object_GetPlaceableIsStatic(oPlc) == 0);
        DestroyObject(oPlc);

        oPlc = CreateObject(OBJECT_TYPE_PLACEABLE, "nw_plc_driftwd1", GetStartingLocation());
        NWNX_Object_SetAutoRemoveKey(oPlc, 1);
        EXPECT("SetAutoRemoveKey", NWNX_Object_GetAutoRemoveKey(oPlc) == 1);

        DestroyObject(oPlc);
        DestroyObject(o);
*/
    }

}
