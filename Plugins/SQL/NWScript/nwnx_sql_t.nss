#include "nwnx_sql"
#include "nwnx_object"
#include "nwnx_tests"

void cleanup()
{
    NWNX_Tests_Report("NWNX_SQL", "Cleanup sql_test",    NWNX_SQL_ExecuteQuery("DROP TABLE sql_test"));
    NWNX_Tests_Report("NWNX_SQL", "Cleanup stress_test", NWNX_SQL_ExecuteQuery("DROP TABLE stress_test"));
    NWNX_Tests_Report("NWNX_SQL", "Cleanup error_test",  NWNX_SQL_ExecuteQuery("DROP TABLE error_test"));
}

void main()
{
    WriteTimestampedLogEntry("NWNX_SQL unit test begin..");

    string db_type = GetStringUpperCase(NWNX_SQL_GetDatabaseType());
    WriteTimestampedLogEntry("Testing database " + db_type);

    string sCreate = "";
    string sInsert = "";

    /* MySQL and SQLite version */
    if (db_type == "MYSQL" || db_type == "SQLITE")
    {
        sCreate = "CREATE TABLE sql_test (" +
                  "colInt INT, colFloat FLOAT, colStr VARCHAR(256)," +
                  "colObjId INT, colObj TEXT(1000000) );";

        sInsert = "INSERT INTO sql_test(colInt, colFloat, colStr, colObjId, colObj) VALUES(?, ?, ?, ?, ?)";
    }

    /* PostgreSQL version */
    if (db_type == "POSTGRESQL")
    {
        sCreate = "CREATE TABLE sql_test (" +
                  "colInt INT, colFloat FLOAT, colStr VARCHAR(256)," +
                  "colObjId INT, colObj TEXT );";

        // Even though we're using 0 based parameter numbers, PostgreSQL requires the parameter
        // numbers in the actual SQL string to be 1 based (e.g. $1, $2...  not $0, $1... )
         sInsert = "INSERT INTO sql_test(colInt, colFloat, colStr, colObjId, colObj) VALUES($1, $2, $3, $4, $5)";
    }

    int b = NWNX_SQL_ExecuteQuery(sCreate);
    NWNX_Tests_Report("NWNX_SQL", "Create Table", b);

    object o = CreateObject(OBJECT_TYPE_CREATURE, "nw_chicken", GetStartingLocation());
    if (!GetIsObjectValid(o))
    {
        WriteTimestampedLogEntry("NWNX_SQL test: Failed to create creature");
        cleanup();
        return;
    }

    vector v = Vector(5.0, 5.0, 0.0); // slightly different location.

    b = NWNX_SQL_PrepareQuery(sInsert);
    NWNX_Tests_Report("NWNX_SQL", "Complex PrepareQuery", b);
    NWNX_Tests_Report("NWNX_SQL", "GetPreparedQueryParamCount", NWNX_SQL_GetPreparedQueryParamCount() == 5);

    NWNX_SQL_PreparedInt(0, 42);
    NWNX_SQL_PreparedFloat(1, 0.42);
    NWNX_SQL_PreparedString(2, "FourtyTwooo");
    NWNX_SQL_PreparedObjectId(3, o);
    NWNX_SQL_PreparedObjectFull(4, o);

    b = NWNX_SQL_ExecutePreparedQuery();
    NWNX_Tests_Report("NWNX_SQL", "Complex ExecutePreparedQuery", b);

    b = NWNX_SQL_ExecuteQuery("SELECT * FROM sql_test;");
    NWNX_Tests_Report("NWNX_SQL", "Select ExecuteQuery", b);

    if (b)
    {
        while (NWNX_SQL_ReadyToReadNextRow())
        {
            NWNX_SQL_ReadNextRow();
            int n = StringToInt(NWNX_SQL_ReadDataInActiveRow(0));
            NWNX_Tests_Report("NWNX_SQL", "ReadInt", n == 42);
            float f = StringToFloat(NWNX_SQL_ReadDataInActiveRow(1));
            NWNX_Tests_Report("NWNX_SQL", "ReadFloat", fabs(f - 0.42) < 0.01);
            string s = NWNX_SQL_ReadDataInActiveRow(2);
            NWNX_Tests_Report("NWNX_SQL", "ReadString", s == "FourtyTwooo");

            string sObjId = NWNX_SQL_ReadDataInActiveRow(3); // In base 10
            object o2 = StringToObject(IntToHexString(StringToInt(sObjId)));
            NWNX_Tests_Report("NWNX_SQL", "ReadObjectId", o == o2);

            object o3 = NWNX_SQL_ReadFullObjectInActiveRow(4, GetArea(o), v.x, v.y, v.z);
            NWNX_Tests_Report("NWNX_SQL", "ReadFullObject", GetIsObjectValid(o3));
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

        string test2 = "";
        if (db_type == "MYSQL" || db_type == "SQLITE")
        {
            test2="INSERT INTO sql_test(colInt, colFloat, colStr, colObjId, colObj) VALUES(1337,0.0,'xxx',1337,?)";
        }
        if (db_type == "POSTGRESQL")
        {
            test2="INSERT INTO sql_test(colInt, colFloat, colStr, colObjId, colObj) VALUES(1337,0.0,'xxx',1337,$1)";
        }

        NWNX_SQL_PrepareQuery(test2);

        NWNX_SQL_PreparedObjectFull(0, oItem);
        b = NWNX_SQL_ExecutePreparedQuery();
        NWNX_Tests_Report("NWNX_SQL", "Insert item full", b);

        b = NWNX_SQL_ExecuteQuery("SELECT colObj FROM sql_test WHERE colInt=1337");
        NWNX_Tests_Report("NWNX_SQL", "Select item", b);

        if (NWNX_SQL_ReadyToReadNextRow())
        {
            NWNX_SQL_ReadNextRow();

            object oItem2 = NWNX_SQL_ReadFullObjectInActiveRow(0, oPlc);
            NWNX_Tests_Report("NWNX_SQL", "ReadFullObject Item", GetIsObjectValid(oItem2));
            NWNX_Tests_Report("NWNX_SQL", "Deserialized to placeable's inventory", oItem2 == GetFirstItemInInventory(oPlc));
            NWNX_Tests_Report("NWNX_SQL", "Deserialized to placeable's inventory - possessor", GetItemPossessor(oItem2) == oPlc);

            object oItem3 = NWNX_SQL_ReadFullObjectInActiveRow(0, GetArea(oPlc), v.x, v.y, v.z);
            NWNX_Tests_Report("NWNX_SQL", "Deserialized to area", GetArea(oItem3) == GetArea(oPlc));

            object oItem4 = NWNX_SQL_ReadFullObjectInActiveRow(0, o);
            NWNX_Tests_Report("NWNX_SQL", "Deserialized to creature's inventory - possessor", GetItemPossessor(oItem4) == o);
        }
        else
        {
            WriteTimestampedLogEntry("NWNX_SQL not ready to read item");
        }

    }

    int STRESS_CNT = 10;

    WriteTimestampedLogEntry("NWNX_SQL stress test.");
    NWNX_SQL_ExecuteQuery("create table stress_test ( i_key int, i_int int, s_text varchar(8))");
    int i;
    // Brute force some inserts
    for ( i=1 ; i<=STRESS_CNT ; i++ )  // Generate 1000 rows.
    {
        // Simulates the existing NWNX2 ODBC way of generating SQL.
        NWNX_SQL_ExecuteQuery("insert into stress_test values ( " + IntToString(i) + ", " + IntToString(i*2) + ", '" + IntToString(i*100) + "')");
    }
    NWNX_SQL_ExecuteQuery("delete from stress_test where i_key > 0");
    int res = NWNX_SQL_GetAffectedRows();
    WriteTimestampedLogEntry("Deleted " + IntToString(res) + " rows.");
    NWNX_Tests_Report("NWNX_SQL", "Delete rows", res == STRESS_CNT);

    // now do some elegant inserts
    string test3 = "";
    if (db_type == "MYSQL" || db_type == "SQLITE")
    {
        test3 = "insert into stress_test values ( ?, ?, ? )";
    }
    if (db_type == "POSTGRESQL")
    {
        test3 = "insert into stress_test values ( $1, $2, $3 )";
    }

    NWNX_SQL_PrepareQuery(test3);
    for ( i = 1 ; i <= STRESS_CNT ; i++ )
    {
        NWNX_SQL_PreparedInt(0, i);
        NWNX_SQL_PreparedInt(1, i*2);
        NWNX_SQL_PreparedString(2, IntToString(i*100));
        b = NWNX_SQL_ExecutePreparedQuery();
        NWNX_Tests_Report("NWNX_SQL", "Elegant Looping ExecutePreparedQuery", b);
    }
    NWNX_SQL_ExecuteQuery("delete from stress_test where i_key > 0");
    res = NWNX_SQL_GetAffectedRows();
    WriteTimestampedLogEntry("Deleted " + IntToString(res) + " rows.");
    NWNX_Tests_Report("NWNX_SQL", "Delete rows", res == STRESS_CNT);

    // Test some error output.
    b = NWNX_SQL_ExecuteQuery("create table error_test (col varchar(10))");
    NWNX_Tests_Report("NWNX_SQL", "Test Table Create", b);

    b = NWNX_SQL_ExecuteQuery("insert into error_test values('abcdefghij')");
    NWNX_Tests_Report("NWNX_SQL", "good insert", b);

    if (db_type != "SQLITE")
    {// SQLite doesn't care about size constraints of columns
        b = NWNX_SQL_ExecuteQuery("insert into error_test values('abcde000fghij')");
        NWNX_Tests_Report("NWNX_SQL", "bad insert", !b);
        if (!b) {
        WriteTimestampedLogEntry("There should be an error a couple rows up.");
        }
    }

    string test4 = "";
    if (db_type == "MYSQL" || db_type == "SQLITE")
    {
        test3 = "insert into error_test values ( ? )";
    }
    if (db_type == "POSTGRESQL")
    {
        test3 = "insert into error_test values ( $1 )";
    }
    NWNX_SQL_PrepareQuery(test3);
    NWNX_SQL_PreparedString(100, "lala"); // out of bounds, must not crash.

    NWNX_Tests_Report("NWNX_SQL", "Negative prepare query", NWNX_SQL_PrepareQuery("not a valid query!") == 0);
    NWNX_Tests_Report("NWNX_SQL", "GetLastError", NWNX_SQL_GetLastError() != "");

    // Test with null values
    NWNX_SQL_ExecuteQuery("INSERT INTO sql_test(colInt, colFloat, colStr, colObjId, colObj) VALUES(5121, null, null, null, null)");
    NWNX_Tests_Report("NWNX_SQL", "Select null", NWNX_SQL_ExecuteQuery("SELECT * FROM sql_test WHERE colInt=5121"));
    if (NWNX_SQL_ReadyToReadNextRow())
    {
        NWNX_SQL_ReadNextRow();
        int n = StringToInt(NWNX_SQL_ReadDataInActiveRow(0));
        NWNX_Tests_Report("NWNX_SQL", "ReadInt", n == 5121);
        float f = StringToFloat(NWNX_SQL_ReadDataInActiveRow(1));
        NWNX_Tests_Report("NWNX_SQL", "ReadFloat", f == 0.0);
        string s = NWNX_SQL_ReadDataInActiveRow(2);
        NWNX_Tests_Report("NWNX_SQL", "ReadString", s == "");

        string sObjId = NWNX_SQL_ReadDataInActiveRow(3); // In base 10
        NWNX_Tests_Report("NWNX_SQL", "ReadObjectId", sObjId == "");

        object obj = NWNX_SQL_ReadFullObjectInActiveRow(4);
        NWNX_Tests_Report("NWNX_SQL", "ReadFullObject", obj == OBJECT_INVALID);
    }

    cleanup();
    WriteTimestampedLogEntry("Testing database " + db_type + " complete.");
    WriteTimestampedLogEntry("NWNX_SQL unit tests end.");
}
