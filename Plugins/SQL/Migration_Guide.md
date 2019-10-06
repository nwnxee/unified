## NWNX:EE SQL Migration Guide

Included below are some examples and guidance in migrating legacy NWNX ODBC style SQL code to the new NWNX:EE SQL Plugin.

### General Information

The previous plugin only had one execution style:  the SQL_ExecDirect() function that took a SQL string that had been constructed to execute.

The new SQL Plugin has two methods of operation:

1.  The same ExecDirect type functionality via NWNX_SQL_ExecuteQuery()
2.  Prepared Statements similar to that of Java and C# where a SQL string is prepared via NWNX_SQL_PrepareQuery() with placeholders, then script variables are bound to the variables, then executed via NWNX_SQL_ExecutePreparedQuery().

Advantages of using the prepared version are numerous

1.  No need to escape/un-escape values for things that cause string SQL statements problems (like single quotes or SQL injection issues).  Bound data is taken as is and treated as data that won't affect the validity of the SQL statement.
2.  The ability to serialize/un-serialize ObjectIDs and Objects to and from the database.
3.  Probably some others, too!

### Examples

A legacy (albeit contrived) example might look like this:

```cpp
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

The simple, straight forward converted version using existing code as much as possible and with copious comments:

```cpp
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
    
    // ExecuteQuery returns boolean success/failure.  Checking for failure is optional, but 
    // gives you the opportunity to recover from the failrue.
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
    else {
        // report failure?  log message, broadcast to DMs, etc.
    }

    if (i == 0) 
        sFeedback = "No kills.";

    AssignCommand(oBoard, ActionSpeakString(sFeedback));
}
```

A more optimal approach that utilizes the parameterized query to avoid having to escape the input data:

```cpp
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
        // if the prepare fails, continuting on with binding and execution should not cause a server abort
        // but checking return codes gives you the option to recover and/or report the failure.
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
        else {
            // execute failed?  report or handle as necessary.
        }
    }
    else {
        // report/log failure?
    }

    if (i == 0) 
        sFeedback = "No kills.";

    AssignCommand(oBoard, ActionSpeakString(sFeedback));
}

```

### Multi-Platform Support

There is a function to retrieve the specific database type to enable multi-platform support through conditional logic.

```cpp
void main()
{
    WriteTimestampedLogEntry("Multi-Platform example..");

    // GetDatabaseType returns the same name used in the NWNX_SQL_TYPE environment variable.
    // Environment var is not case sensitive, so normalize to upper case.
    string db_type = GetStringUpperCase(NWNX_SQL_GetDatabaseType());

    /* MySQL version */
    if (db_type == "MYSQL")
    {
        // text column definition differs slightly
        sCreate = "CREATE TABLE sql_test (" +
                  "colInt INT, colFloat FLOAT, colStr VARCHAR(256)," +
                  "colObjId INT, colObj TEXT(1000000) );";

        sInsert = "INSERT INTO sql_test(colInt, colFloat, colStr, colObjId, colObj) VALUES(?, ?, ?, ?, ?)";
    }

    /* PostgreSQL version */
    if (db_type == "POSTGRESQL")
    {
        // text column definition differs slightly
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
    
    b = NWNX_SQL_PrepareQuery(sInsert);
    if (!b) {
        WriteTimestampedLogEntry("Object insert failed.");
        // cleanup if necessary.
    }
    
    ...
    // etc., etc.
    

```