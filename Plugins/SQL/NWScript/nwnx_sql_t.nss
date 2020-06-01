#include "nwnx_sql"
#include "nwnx_object"
#include "nwnx_test"

void cleanup()
{
    while(TEST("Cleanup"))
    {
        EXPECT(IS_TRUE(NWNX_SQL_ExecuteQuery("DROP TABLE sql_test")), "Cleanup sql_test");
        EXPECT(IS_TRUE(NWNX_SQL_ExecuteQuery("DROP TABLE stress_test")), "Cleanup stress_test");
        EXPECT(IS_TRUE(NWNX_SQL_ExecuteQuery("DROP TABLE error_test")), "Cleanup error_test");
    }
}

void main()
{
    while(TEST("SQL"))
    {
        ASSERT(IS_TRUE(NWNX_Test_PluginExists("NWNX_SQL")));
        ASSERT(IS_TRUE(NWNX_Test_PluginExists("NWNX_Object")));

        string db_type = GetStringUpperCase(NWNX_SQL_GetDatabaseType());
        NWNX_Test_Context("Database Type: " + db_type);

        string sCreate = "";
        string sInsert = "";

        // MySQL and SQLite version
        if (db_type == "MYSQL" || db_type == "SQLITE")
        {
            sCreate = "CREATE TABLE sql_test (" +
                    "colInt INT, colFloat FLOAT, colStr VARCHAR(256)," +
                    "colObjId INT, colObj TEXT(1000000) );";

            sInsert = "INSERT INTO sql_test(colInt, colFloat, colStr, colObjId, colObj) VALUES(?, ?, ?, ?, ?)";
        }

        // PostgreSQL version
        if (db_type == "POSTGRESQL")
        {
            sCreate = "CREATE TABLE sql_test (" +
                    "colInt INT, colFloat FLOAT, colStr VARCHAR(256)," +
                    "colObjId INT, colObj TEXT );";

            // Even though we're using 0 based parameter numbers, PostgreSQL requires the parameter
            // numbers in the actual SQL string to be 1 based (e.g. $1, $2...  not $0, $1... )
            sInsert = "INSERT INTO sql_test(colInt, colFloat, colStr, colObjId, colObj) VALUES($1, $2, $3, $4, $5)";
        }

        object o = CreateObject(OBJECT_TYPE_CREATURE, "nw_chicken", GetStartingLocation());
        ASSERT(IS_VALID(o), "nw_chicken");

        if(!ASSERT(IS_TRUE(NWNX_SQL_ExecuteQuery(sCreate)), "Create Table"))
        {
            NWNX_Test_Context(sCreate);
        }

        vector v = Vector(5.0, 5.0, 0.0); // slightly different location.

        if(!EXPECT(IS_TRUE(NWNX_SQL_PrepareQuery(sInsert)), "Complex PrepareQuery"))
        {
            NWNX_Test_Context(sInsert);
        }
        EXPECT(IS_EQUAL_INT(NWNX_SQL_GetPreparedQueryParamCount(), 5), "GetPreparedQueryParamCount");

        NWNX_SQL_PreparedInt(0, 42);
        NWNX_SQL_PreparedFloat(1, 0.42);
        NWNX_SQL_PreparedString(2, "FourtyTwooo");
        NWNX_SQL_PreparedObjectId(3, o);
        NWNX_SQL_PreparedObjectFull(4, o);

        ASSERT(IS_TRUE(NWNX_SQL_ExecutePreparedQuery()), "Complex ExecutePreparedQuery");

        if (ASSERT(IS_TRUE(NWNX_SQL_ExecuteQuery("SELECT * FROM sql_test;")), "Select ExecuteQuery"))
        {
            while (NWNX_SQL_ReadyToReadNextRow())
            {
                NWNX_SQL_ReadNextRow();
                int n = StringToInt(NWNX_SQL_ReadDataInActiveRow(0));
                EXPECT(IS_EQUAL_INT(n, 42), "ReadInt");
                float f = StringToFloat(NWNX_SQL_ReadDataInActiveRow(1));
                EXPECT(IS_LT_FLOAT(fabs(f - 0.42), 0.01), "ReadFloat");
                string s = NWNX_SQL_ReadDataInActiveRow(2);
                EXPECT(IS_EQUAL_STRING(s, "FourtyTwooo"), "ReadString");

                string sObjId = NWNX_SQL_ReadDataInActiveRow(3); // In base 10
                object o2 = NWNX_Object_StringToObject(IntToHexString(StringToInt(sObjId)));
                EXPECT(IS_EQUAL_OBJECT(o, o2), "ReadObjectId");

                object o3 = NWNX_SQL_ReadFullObjectInActiveRow(4, GetArea(o), v.x, v.y, v.z);
                EXPECT(IS_VALID(o3), "ReadFullObject");
                // Alternatively:
                // object o3 = NWNX_Object_Deserialize(NWNX_SQL_ReadDataInActiveRow(4));
            }
        }

        object oPlc = CreateObject(OBJECT_TYPE_PLACEABLE, "nw_plc_chestburd", GetStartingLocation());
        object oItem = CreateObject(OBJECT_TYPE_ITEM, "x0_it_mring013", GetStartingLocation());
        if (ASSERT(IS_VALID(oPlc)) && ASSERT(IS_VALID(oItem)))
        {
            object oTmp = GetFirstItemInInventory(oPlc);
            while (GetIsObjectValid(oTmp))
            {
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

            EXPECT(IS_TRUE(NWNX_SQL_ExecutePreparedQuery()), "Insert item full");
            EXPECT(IS_TRUE(NWNX_SQL_ExecuteQuery("SELECT colObj FROM sql_test WHERE colInt=1337")), "Select item");

            if (NWNX_SQL_ReadyToReadNextRow())
            {
                NWNX_SQL_ReadNextRow();

                object oItem2 = NWNX_SQL_ReadFullObjectInActiveRow(0, oPlc);
                EXPECT(IS_VALID(oItem2), "ReadFullObject Item");
                EXPECT(IS_EQUAL_OBJECT(oItem2, GetFirstItemInInventory(oPlc)), "Deserialized to placeable's inventory");
                EXPECT(IS_EQUAL_OBJECT(GetItemPossessor(oItem2), oPlc), "Deserialized to placeable's inventory - possessor");

                object oItem3 = NWNX_SQL_ReadFullObjectInActiveRow(0, GetArea(oPlc), v.x, v.y, v.z);
                EXPECT(IS_EQUAL_OBJECT(GetArea(oItem3), GetArea(oPlc)), "Deserialized to area");

                object oItem4 = NWNX_SQL_ReadFullObjectInActiveRow(0, o);
                EXPECT(IS_EQUAL_OBJECT(GetItemPossessor(oItem4), o), "Deserialized to creature's inventory - possessor");
            }
        }

        int STRESS_CNT = 10;
        int i, res;

        ASSERT(IS_TRUE(NWNX_SQL_ExecuteQuery("create table stress_test ( i_key int, i_int int, s_text varchar(8))")));

        while(TEST("Raw Inserts"))
        {
            // Brute force some inserts
            for ( i=1 ; i<=STRESS_CNT ; i++ )  // Generate 1000 rows.
            {
                // Simulates the existing NWNX2 ODBC way of generating SQL.
                NWNX_SQL_ExecuteQuery("insert into stress_test values ( " + IntToString(i) + ", " + IntToString(i*2) + ", '" + IntToString(i*100) + "')");
            }
            NWNX_SQL_ExecuteQuery("delete from stress_test where i_key > 0");
            res = NWNX_SQL_GetAffectedRows();

            EXPECT(IS_EQUAL_INT(res, STRESS_CNT), "Delete rows");
        }

        string test3 = "";
        // now do some elegant inserts
        while(TEST("Prepared Inserts"))
        {
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
                EXPECT(IS_TRUE(NWNX_SQL_ExecutePreparedQuery()), "Elegant Looping ExecutePreparedQuery");
            }
            NWNX_SQL_ExecuteQuery("delete from stress_test where i_key > 0");
            res = NWNX_SQL_GetAffectedRows();
            EXPECT(IS_EQUAL_INT(res, STRESS_CNT), "Delete rows");
        }

        while(TEST("Constraints"))
        {
            // Test some error output.
            EXPECT(IS_TRUE(NWNX_SQL_ExecuteQuery("create table error_test (col varchar(10))")), "Test Table Create");
            EXPECT(IS_TRUE(NWNX_SQL_ExecuteQuery("insert into error_test values('abcdefghij')")), "good insert");

            if (db_type != "SQLITE")
            {// SQLite doesn't care about size constraints of columns
                EXPECT(IS_FALSE(NWNX_SQL_ExecuteQuery("insert into error_test values('abcde000fghij')")), "bad insert");
            }
        }

        while(TEST("Invalid Query"))
        {
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

            EXPECT(IS_FALSE(NWNX_SQL_PrepareQuery("not a valid query!")), "Negative prepare query");
            EXPECT(NOT_EQUAL_STRING(NWNX_SQL_GetLastError(), ""), "GetLastError");
        }

        while(TEST("Null"))
        {
            // Test with null values
            NWNX_SQL_ExecuteQuery("INSERT INTO sql_test(colInt, colFloat, colStr, colObjId, colObj) VALUES(5121, null, null, null, null)");
            EXPECT(IS_TRUE(NWNX_SQL_ExecuteQuery("SELECT * FROM sql_test WHERE colInt=5121")), "Select null");
            if (NWNX_SQL_ReadyToReadNextRow())
            {
                NWNX_SQL_ReadNextRow();
                int n = StringToInt(NWNX_SQL_ReadDataInActiveRow(0));
                EXPECT(IS_EQUAL_INT(n, 5121), "ReadInt");
                float f = StringToFloat(NWNX_SQL_ReadDataInActiveRow(1));
                EXPECT(IS_EQUAL_FLOAT(f, 0.0), "ReadFloat");
                string s = NWNX_SQL_ReadDataInActiveRow(2);
                EXPECT(IS_EQUAL_STRING(s, ""), "ReadString");

                string sObjId = NWNX_SQL_ReadDataInActiveRow(3); // In base 10
                EXPECT(IS_EQUAL_STRING(sObjId, ""), "ReadObjectId");

                object obj = NWNX_SQL_ReadFullObjectInActiveRow(4);
                EXPECT(IS_INVALID(obj), "ReadFullObject");
            }
        }
        cleanup();
    }
}
