#include "nwnx_sql"

#include "nwnx_object"

void report(string func, int bSuccess)
{
    if (bSuccess)
        WriteTimestampedLogEntry("NWNX_SQL: " + func + "() success");
    else
        WriteTimestampedLogEntry("NWNX_SQL: " + func + "() failed");
}
void main()
{
    WriteTimestampedLogEntry("NWNX_SQL unit test begin..");

    string sCreate = "CREATE TABLE sql_test (" +
                        "colInt INT, colFloat FLOAT, colStr VARCHAR(256)," +
                        "colObjId INT, colObj TEXT(1000000) );";


    int b = NWNX_SQL_PrepareQuery(sCreate);
    report("PrepareQuery", b);

    b = NWNX_SQL_ExecuteQuery();
    report("ExecuteQuery", b);

    object o = CreateObject(OBJECT_TYPE_CREATURE, "nw_chicken", GetStartingLocation());
    if (!GetIsObjectValid(o))
    {
        WriteTimestampedLogEntry("NWNX_SQL test: Failed to create creature");
        return;
    }

    b = NWNX_SQL_PrepareQuery("INSERT INTO sql_test(colInt, colFloat, colStr, colObjId, colObj) VALUES(?,?,?,?,?);");
    report("Complex PrepareQuery", b);

    NWNX_SQL_PreparedInt(1, 42);
    NWNX_SQL_PreparedFloat(2, 0.42);
    NWNX_SQL_PreparedString(3, "FourtyTwooo");
    NWNX_SQL_PreparedObjectId(4, o);
    NWNX_SQL_PreparedObjectFull(5, o);


    b = NWNX_SQL_ExecuteQuery();
    report("Complex ExecuteQuery", b);
    
    b = NWNX_SQL_GetAffectedRows();
    report("Affected Rows", b == 1);

    b = NWNX_SQL_PrepareQuery("SELECT * FROM sql_test;");
    report("Select PrepareQuery", b);
    b = NWNX_SQL_ExecuteQuery();
    report("Select ExecuteQuery", b);

    if (b)
    {
        while (NWNX_SQL_ReadyToReadNextRow())
        {
            NWNX_SQL_ReadNextRow();
            int n = StringToInt(NWNX_SQL_ReadDataInActiveRow(0));
            report("ReadInt", n == 42);
            float f = StringToFloat(NWNX_SQL_ReadDataInActiveRow(1));
            report("ReadFloat", fabs(f - 42.0) > 0.01);
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

    NWNX_SQL_PrepareQuery("DROP TABLE sql_test");
    NWNX_SQL_ExecuteQuery();
    WriteTimestampedLogEntry("NWNX_SQL unit test end.");
}
