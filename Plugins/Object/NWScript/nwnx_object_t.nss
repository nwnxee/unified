#include "nwnx_object"



void report(string func, int bSuccess)
{
    if (bSuccess)
        WriteTimestampedLogEntry("NWNX_Object: " + func + "() success");
    else
        WriteTimestampedLogEntry("NWNX_Object: " + func + "() failed");
}
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
    report("GetLocalVariableCount", NWNX_Object_GetLocalVariableCount(o) == (nVarCount+1));

    struct NWNX_Object_LocalVariable lv = NWNX_Object_GetLocalVariable(o, nVarCount);
    report("GetLocalVariable", lv.key == "nwnx_object_test");
    report("GetLocalVariable", lv.type == NWNX_OBJECT_LOCALVAR_TYPE_INT);

    string sObj = ObjectToString(o);
    report("StringToObject", NWNX_Object_StringToObject(sObj) == o);
    report("Negative: StringToObject", NWNX_Object_StringToObject("!@#!@#!@#!") == OBJECT_INVALID);

    vector vPos = GetPosition(o);
    vPos.x += 1;
    NWNX_Object_SetPosition(o, vPos);
    report("SetPosition", GetPosition(o).x == vPos.x);

    int nMaxHP = GetMaxHitPoints(o);
    NWNX_Object_SetMaxHitPoints(o, nMaxHP + 1);
    report("SetMaxHitPoints", GetMaxHitPoints(o) == (nMaxHP + 1));

    int nCurrHP = GetCurrentHitPoints(o);
    NWNX_Object_SetCurrentHitPoints(o, nCurrHP + 1);
    report("SetCurrentHitPoints", GetCurrentHitPoints(o) == (nCurrHP + 1));

    string dialog = "nwnxtest";
    NWNX_Object_SetDialogResref(o, dialog);
    report("SetDialogResRef/GetDialogResRef", NWNX_Object_GetDialogResref(o) == dialog);

    string sSerialized = NWNX_Object_Serialize(o);
    report("Serialize", sSerialized != "");
    WriteTimestampedLogEntry("Serialized chicken: " + sSerialized);

    object oDeserialized = NWNX_Object_Deserialize(sSerialized);
    report("Deserialize", GetIsObjectValid(oDeserialized));

    WriteTimestampedLogEntry("Deserialized " + GetName(oDeserialized) + " in " + GetName(GetArea(oDeserialized)));

    object bag = CreateObject(OBJECT_TYPE_ITEM, "nw_it_contain006", GetStartingLocation()); // Bag of holding
    CreateItemOnObject("x2_it_adaplate", bag, 1);
    CreateItemOnObject("x2_it_adaplate", bag, 1);
    CreateItemOnObject("x2_it_adaplate", bag, 1);
    int iFits = NWNX_Object_CheckFit(bag, BASE_ITEM_ARROW);
    report("CheckFit", iFits == 1);
    iFits = NWNX_Object_CheckFit(bag, BASE_ITEM_ARMOR);
    report("CheckFit", iFits == 0);
    object oItem = GetFirstItemInInventory(bag);
    while (oItem != OBJECT_INVALID)
    {
        DestroyObject(oItem);
        oItem = GetNextItemInInventory(bag);
    }
    DestroyObject(bag);

    report("GetDamageImmunity", NWNX_Object_GetDamageImmunity(o, DAMAGE_TYPE_FIRE) == 0);
    ApplyEffectToObject(DURATION_TYPE_PERMANENT, EffectDamageImmunityIncrease(DAMAGE_TYPE_FIRE, 50), o);
    report("GetDamageImmunity", NWNX_Object_GetDamageImmunity(o, DAMAGE_TYPE_FIRE) == 50);

    object oPlc = CreateObject(OBJECT_TYPE_PLACEABLE, "nw_defportal", GetStartingLocation());
    NWNX_Object_SetPlaceableIsStatic(oPlc, 1);
    report("SetPlaceableIsStatic 1", NWNX_Object_GetPlaceableIsStatic(oPlc) == 1);
    DestroyObject(oPlc);

    oPlc = CreateObject(OBJECT_TYPE_PLACEABLE, "nw_plc_driftwd1", GetStartingLocation());
    NWNX_Object_SetPlaceableIsStatic(oPlc, 0);
    report("SetPlaceableIsStatic 2", NWNX_Object_GetPlaceableIsStatic(oPlc) == 0);
    DestroyObject(oPlc);

    oPlc = CreateObject(OBJECT_TYPE_PLACEABLE, "nw_plc_driftwd1", GetStartingLocation());
    NWNX_Object_SetAutoRemoveKey(oPlc, 1);
    report("SetAutoRemoveKey", NWNX_Object_GetAutoRemoveKey(oPlc) == 1);
    DestroyObject(oPlc);

    DestroyObject(o);
    DestroyObject(oDeserialized);
    WriteTimestampedLogEntry("NWNX_Object unit test end.");
}
