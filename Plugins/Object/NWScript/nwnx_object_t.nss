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

    string sObj = ObjectToString(o);
    report("StringToObject", NWNX_Object_StringToObject(sObj) == o);


    string sHandler = NWNX_Object_GetEventHandler(o, 0);
    report("GetEventHandler", sHandler != "");

    NWNX_Object_SetEventHandler(o, 0, "nwnx_object_t");
    report("SetEventHandler", NWNX_Object_GetEventHandler(o, 0) == "nwnx_object_t");
    // Restore original
    NWNX_Object_SetEventHandler(o, 0, sHandler);

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


    string sPortrait = NWNX_Object_GetPortrait(o);
    report("GetPortrait", sPortrait == "po_Chicken_");

    NWNX_Object_SetPortrait(o, "po_Badger_");
    report("SetPortrait", NWNX_Object_GetPortrait(o) == "po_Badger_");

    WriteTimestampedLogEntry("NWNX_Object unit test end.");
}
