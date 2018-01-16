## NWNX:EE SQL Migration Guide

Included below are some examples and guidance in migrating legacy NWNX ODBC style SQL code to the new NWNX:EE SQL Plugin.

### General Information

The previous plugin only had one execution style:  the SQL_ExecDirect() function that took a SQL string that had been constructed to execute.

The new SQL Plugin has two methods of operation:

1.  The same ExecDirect type functionality (via ``NWNX_SQL_ExecuteQuery("...")``)
1.  Prepared Statements simiar to that of Java and C# where a SQL string is prepared (via ``NWNX_SQL_PrepareQuery(...)``) with place holders, then script variables are bound to the variables, then the executed (via ``NWNX_SQL_ExecutePreparedQuery()``).

Advantages of using the prepared version are numerous

1.  No need to escape/un-escape values for things that cause string SQL statements problems (like single quotes or SQL injection issues).  Bound data is taken as is and treated as data that won't affect the validity of the SQL statement.
1. The ability to serialize/un-serialize ObjectIDs and Objects to and from the database.
1.  Probably some others, too!

### Examples

A legacy (albeit contrived) example might look like this:

```
//This is a silly, non-sensical function.
int SomeUsefulFunction(object oPC, object oBoard)
{
    string sPlayerAccount = SQLEncodeSpecialChars(GetPCPlayerName(oPC));
    string sPCName = SQLEncodeSpecialChars(GetName(oPC));

    string sql = "SELECT kills FROM kill_history WHERE player = '" + sPlayerAccount + 
                 "' AND name='" + sPCName + "'";
    SQLExecDirect(sql);

    string sFeedback = "Kill list\n";
    
    int i = 0;
    
    while(SQLFetch() == SQL_SUCCESS) {
        sFeedback += SQLDecodeSpecialChars(SQLGetData(1)) + " \n";
        i++;
    }
 
    if (i == 0) 
        sFeedback = "No kills.";
     
    AssignCommand(oBoard, ActionSpeakString(sFeedback));
}

```

The simple, straight forward converted version using exising code as much as possible and with copious comments:

```
//This is a silly, non-sensical function.
int SomeUsefulFunction(object oPC, object oBoard)
{
    // still have to encode data if we're building a string for direct execution.
    string sPlayerAccount = SQLEncodeSpecialChars(GetPCPlayerName(oPC));
    string sPCName = SQLEncodeSpecialChars(GetName(oPC));

    // build the SQL string as before.
    string sql = "SELECT kills FROM kill_history WHERE player = '" + sPlayerAccount + 
                 "' AND name='" + sPCName + "'";

    string sFeedback = "Kill list\n";
    int i = 0;
    
    // ExecuteQuery returns boolean success/failure.  On failure, you should not attempt to 
    // do anything further with that query (binding, reading rows, testing for text rows, etc.).
    int ret = NWNX_SQL_ExecuteQuery(sql);
    if (ret) {
        while (NWNX_SQL_ReadyToReadNextRow())
        {
            NWNX_SQL_ReadNextRow();
            // Note NWNX_SQL_ReadDataInActiveRow is zero based..  
            //    0 is the first column, 1 is the second, etc.
            // Also, it returns a string representation by default.  Use StringToInt/Float as necessary.
            sFeedback += NWNX_SQL_ReadDataInActiveRow(0) + " \n";
            i++;
        }
    }

    if (i == 0) 
        sFeedback = "No kills.";

    AssignCommand(oBoard, ActionSpeakString(sFeedback));
}
```

A more optimal approach that utilizies the parameterized query to avoid having to escape the input data:

```
//This is a silly, non-sensical function.
int SomeUsefulFunction(object oPC, object oBoard)
{
    // no need for escaping special caracters.  Binding will take care of that.
    string sPlayerAccount = GetPCPlayerName(oPC);
    string sPCName = GetName(oPC);

    // this is MySQL's binding format.  PostgreSQL uses $1, $2, $3...
    string sql = "SELECT kills FROM kill_history WHERE player=? AND name=?";

    string sFeedback = "Kill list\n";
    int i=0;
    
    // returns boolean success/failure.
    int ret = NWNX_SQL_PrepareQuery(sql);
    if (ret) {
        // if the prepare fails, continuting on with binding and execution can cause bad things to happen.
        NWNX_SQL_PreparedString(0, sPlayerAccount);
        NWNX_SQL_PreparedString(1, sPCName);
        ret = NWNX_SQL_ExecutePreparedQuery();
        if (ret) {
            while (NWNX_SQL_ReadyToReadNextRow())
            {
                NWNX_SQL_ReadNextRow();
                // Note NWNX_SQL_ReadDataInActiveRow is zero based..  
                //    0 is the first column, 1 is the second, etc.
                // Also, it returns a string representation by default.  Use StringToInt/Float as necessary.
                sFeedback += NWNX_SQL_ReadDataInActiveRow(0) + " \n";
                i++;
            }
        }
    }

    if (i == 0) 
        sFeedback = "No kills.";

    AssignCommand(oBoard, ActionSpeakString(sFeedback));
}

```

###Multi-Platform Support

There is a function to retrieve the specfic database type to enable multi-platform support through conditional logic.

```
void main()
{
    WriteTimestampedLogEntry("Multi-Platform example..");

    //GetDatabaseType returns the same name used in the NWNX_SQL_TYPE environment variable.
    string db_type = NWNX_SQL_GetDatabaseType();

    /* MySQL version */
    if (db_type == "MYSQL")
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
    if (!b) {
        WriteTimestampedLogEntry("Create table failed!");
        return;
    }
    
    object o = CreateObject(OBJECT_TYPE_CREATURE, "nw_chicken", GetStartingLocation());
    if (!GetIsObjectValid(o))
    {
        WriteTimestampedLogEntry("No chicken for you");
        NWNX_SQL_ExecuteQuery("drop table sql_test");
        return;
    }

    b = NWNX_SQL_PrepareQuery(sInsert);
    report("Complex PrepareQuery", b);

    ...
    // etc., etc.
    

```