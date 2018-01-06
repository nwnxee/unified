#include "nwnx_sql"

#include "nwnx_object"

void report(string func, int bSuccess)
{
    if (bSuccess)
        WriteTimestampedLogEntry("NWNX_SQL: " + func + "() success");
    else
        WriteTimestampedLogEntry("NWNX_SQL: " + func + "() failed");
}

void cleanup() 
{
    int b = NWNX_SQL_ExecuteQuery("DROP TABLE sql_test");
    report("ExecuteQuery", b);
}

void main()
{
    WriteTimestampedLogEntry("NWNX_SQL unit test begin..");

    /* MySQL version */
    string sCreate = "CREATE TABLE sql_test (" +
                        "colInt INT, colFloat FLOAT, colStr VARCHAR(256)," +
                        "colObjId INT, colObj TEXT(1000000) );";

    string sInsert = "INSERT INTO sql_test(colInt, colFloat, colStr, colObjId, colObj) VALUES(?, ?, ?, ?, ?)";

    /* PostgreSQL version */
    /*
    string sCreate = "CREATE TABLE sql_test (" +
                        "colInt INT, colFloat FLOAT, colStr VARCHAR(256)," +
                        "colObjId INT, colObj TEXT );";

    // Even though we're using 0 based parameter numbers, PostgreSQL requires the parameter numbers in the 
    // actual SQL string to be 1 based (e.g. $1, $2...  not $0, $1... )
    string sInsert = "INSERT INTO sql_test(colInt, colFloat, colStr, colObjId, colObj) VALUES($1, $2, $3, $4, $5)";
    */

    int b = NWNX_SQL_PrepareQuery(sCreate);
    report("PrepareQuery", b);

    b = NWNX_SQL_ExecutePreparedQuery();
    report("ExecutePreparedQuery", b);

    object o = CreateObject(OBJECT_TYPE_CREATURE, "nw_chicken", GetStartingLocation());
    if (!GetIsObjectValid(o))
    {
        WriteTimestampedLogEntry("NWNX_SQL test: Failed to create creature");
        cleanup();
        return;
    }

    b = NWNX_SQL_PrepareQuery(sInsert);
    report("Complex PrepareQuery", b);

    NWNX_SQL_PreparedInt(0, 42);
    NWNX_SQL_PreparedFloat(1, 0.42);
    NWNX_SQL_PreparedString(2, "FourtyTwooo");
    NWNX_SQL_PreparedObjectId(3, o);
    NWNX_SQL_PreparedObjectFull(4, o);


    b = NWNX_SQL_ExecutePreparedQuery();
    report("Complex ExecutePreparedQuery", b);

    b = NWNX_SQL_PrepareQuery("SELECT * FROM sql_test;");
    report("Select PrepareQuery", b);
    b = NWNX_SQL_ExecutePreparedQuery();
    report("Select ExecutePreparedQuery", b);

    if (b)
    {
        while (NWNX_SQL_ReadyToReadNextRow())
        {
            NWNX_SQL_ReadNextRow();
            int n = StringToInt(NWNX_SQL_ReadDataInActiveRow(0));
            report("ReadInt", n == 42);
            float f = StringToFloat(NWNX_SQL_ReadDataInActiveRow(1));
            report("ReadFloat", fabs(f - 0.42) < 0.01);
            string s = NWNX_SQL_ReadDataInActiveRow(2);
            report("ReadString", s == "FourtyTwooo");

            string sObjId = NWNX_SQL_ReadDataInActiveRow(3); // In base 10
            object o2 = NWNX_Object_StringToObject(IntToHexString(StringToInt(sObjId)));
            report("ReadObjectId", o == o2);

            object o3 = NWNX_SQL_ReadFullObjectInActiveRow(4);
            report("ReadFullObject", GetIsObjectValid(o3));
            // Alternatively:
            // object o3 = NWNX_Object_Deserialize(NWNX_SQL_ReadDataInActiveRow(4));
        }
    }

    object oPlc = CreateObject(OBJECT_TYPE_PLACEABLE, "nw_plc_chestburd", GetStartingLocation());
    object oItem = CreateObject(OBJECT_TYPE_ITEM, "x0_it_mring013", GetStartingLocation());
    if (!GetIsObjectValid(oPlc) || !GetIsObjectValid(oItem))
    {
        WriteTimestampedLogEntry("NWNX_SQL test: Failed to create objects..");
    }
    else
    {
        object oTmp = GetFirstItemInInventory(oPlc);
        while (GetIsObjectValid(oTmp))
        {
            WriteTimestampedLogEntry("NWNX_SQL Destroying auto created object " + GetTag(oTmp));
            DestroyObject(oTmp);
            oTmp = GetNextItemInInventory(oPlc);
        }

        // Insert statement for MySQL
        NWNX_SQL_PrepareQuery("INSERT INTO sql_test(colInt, colFloat, colStr, colObjId, colObj) VALUES(1337,0.0,'xxx',1337,?)");
        
        // Insert statement for PostgreSQL
        // NWNX_SQL_PrepareQuery("INSERT INTO sql_test(colInt, colFloat, colStr, colObjId, colObj) VALUES(1337,0.0,'xxx',1337,$1)");        
        
        NWNX_SQL_PreparedObjectFull(0, oItem);
        b = NWNX_SQL_ExecutePreparedQuery();
        report("Insert item full", b);

        b = NWNX_SQL_ExecuteQuery("SELECT colObj FROM sql_test WHERE colInt=1337");
        report("Select item", b);

        if (NWNX_SQL_ReadyToReadNextRow())
        {
            NWNX_SQL_ReadNextRow();

            object oItem2 = NWNX_SQL_ReadFullObjectInActiveRow(0, oPlc);
            report("ReadFullObject Item", GetIsObjectValid(oItem2));
            report("Deserialized to placeable's inventory", oItem2 == GetFirstItemInInventory(oPlc));
            report("Deserialized to placeable's inventory - possessor", GetItemPossessor(oItem2) == oPlc);

            object oItem3 = NWNX_SQL_ReadFullObjectInActiveRow(0, GetArea(oPlc));
            report("Deserialized to area", GetArea(oItem3) == GetArea(oPlc));

            object oItem4 = NWNX_SQL_ReadFullObjectInActiveRow(0, o);
            report("Deserialized to creature's inventory - possessor", GetItemPossessor(oItem4) == o);
        }
        else
        {
            WriteTimestampedLogEntry("NWNX_SQL not ready to read item");
        }

    }

    cleanup();
    WriteTimestampedLogEntry("NWNX_SQL unit test end.");
}
