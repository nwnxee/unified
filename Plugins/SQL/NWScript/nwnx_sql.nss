/// @addtogroup sql SQL
/// @brief Functions to interface with a database through SQL
/// @{
/// @file nwnx_sql.nss

const string NWNX_SQL = "NWNX_SQL"; ///< @private

/// @brief Prepares the provided query for execution.
/// @note This does not execute the query. Will also clear any previous state.
/// @param query The query to prepare.
/// @return TRUE if the query was successfully prepared.
int NWNX_SQL_PrepareQuery(string query);

/// @brief Executes a query which has been prepared.
/// @return The ID of this query if successful, else FALSE.
int NWNX_SQL_ExecutePreparedQuery();

/// @brief Directly execute an SQL query.
/// @note Clears previously prepared query states.
/// @return The ID of this query if successful, else FALSE.
int NWNX_SQL_ExecuteQuery(string query);

/// @anchor sql_rtrnr
/// @return TRUE if one or more rows are ready, FALSE otherwise.
int NWNX_SQL_ReadyToReadNextRow();

/// @anchor sql_rnr
/// @brief Reads the next row of returned data.
/// @remark Should only be called after a successful call to @ref sql_rtrnr "NWNX_SQL_ReadyToReadNextRow()".
void NWNX_SQL_ReadNextRow();

/// @param column The column to read in the active row.
/// @return Data at the nth (0-based) column of the active row.
/// @remark Should only be called after a successful call to @ref sql_rnr "NWNX_SQL_ReadNextRow()".
string NWNX_SQL_ReadDataInActiveRow(int column = 0);

/// @brief Set the int value of a prepared statement at given position.
/// @param position The nth ? in a prepared statement.
/// @param value The value to set.
void NWNX_SQL_PreparedInt(int position, int value);

/// @brief Set the string value of a prepared statement at given position.
/// @param position The nth ? in a prepared statement.
/// @param value The value to set.
void NWNX_SQL_PreparedString(int position, string value);

/// @brief Set the float value of a prepared statement at given position.
/// @param position The nth ? in a prepared statement.
/// @param value The value to set.
void NWNX_SQL_PreparedFloat(int position, float value);

/// @brief Set the ObjectId value of a prepared statement at given position.
/// @param position The nth ? in a prepared statement.
/// @param value The value to set.
void NWNX_SQL_PreparedObjectId(int position, object value);

/// @brief Set the full serialized object value of a prepared statement at given position.
/// @param position The nth ? in a prepared statement.
/// @param value The value to set.
/// @param base64 Use base64-encoded string format if TRUE (default), otherwise use binary format.
void NWNX_SQL_PreparedObjectFull(int position, object value, int base64 = TRUE);

/// @brief Set the NULL value of a prepared statement at given position.
/// @param position The nth ? in a prepared statement.
void NWNX_SQL_PreparedNULL(int position);

/// @brief Set the Json value of a prepared statement at given position.
/// Convenience function to match other Prepared(type) functions.
/// @param position The nth ? in a prepared statement.
/// @param value The value to set.
void NWNX_SQL_PreparedJson(int position, json value);

/// @brief Like NWNX_SQL_ReadDataInActiveRow, but for full serialized objects.
///
/// The object will be deserialized and created in the game. New object ID is returned.
///
/// The exact behavior depends on type of deserialized object and owner object:
///   * If object is an item, and owner if placeable, creature or container, the item will be created in its inventory
///   * If owner is an area, the object will be created on the ground at Vector(x,y,z)
///   * Otherwise, the object will be created outside the world and needs to be ported manually.
///
/// @param column The column to read in the active row.
/// @param owner The owner of the object.
/// @param x, y, z The vector for objects to be placed in areas.
/// @param base64 Use base64-encoded string format if TRUE (default), otherwise use binary format.
/// @return The deserialized object.
object NWNX_SQL_ReadFullObjectInActiveRow(int column = 0, object owner = OBJECT_INVALID, float x = 0.0, float y = 0.0, float z = 0.0, int base64 = TRUE);

/// @brief Gets the rows affected by a query.
/// @remark This command is for non-row-based statements like INSERT, UPDATE, DELETE, etc.
/// @return Number of rows affected by SQL statement or -1 if the query was not non-row-based.
int NWNX_SQL_GetAffectedRows();

/// Gets the database type.
/// @return The database type we're interacting with.
/// @remark This is the same value as the value of NWNX_SQL_TYPE environment variable.
string NWNX_SQL_GetDatabaseType();

/// @brief Free any resources attached to an existing prepared query.
/// @remark Resources are automatically freed when a new query is prepared, so calling this isn't necessary.
void NWNX_SQL_DestroyPreparedQuery();

/// @return The last error message generated by the database.
string NWNX_SQL_GetLastError();

/// @brief Gets the number of parameters expected by a prepared query.
/// @return Returns the number of parameters expected by the prepared query or -1 if no query is prepared.
int NWNX_SQL_GetPreparedQueryParamCount();

/// @brief Set the next query to return full binary results **ON THE FIRST COLUMN ONLY**.
/// @note This is ONLY needed on PostgreSQL, and ONLY if you want to deserialize raw bytea in NWNX_SQL_ReadFullObjectInActiveRow with base64=FALSE.
void NWNX_SQL_PostgreSQL_SetNextQueryResultsBinaryMode();

/// @}

int NWNX_SQL_PrepareQuery(string query)
{
    NWNXPushString(query);
    NWNXCall(NWNX_SQL, "PrepareQuery");
    return NWNXPopInt();
}

int NWNX_SQL_ExecutePreparedQuery()
{
    NWNXCall(NWNX_SQL, "ExecutePreparedQuery");
    return NWNXPopInt();
}

int NWNX_SQL_ExecuteQuery(string query)
{
    // Note: the implementation might change as support for more SQL targets arrives.
    if (NWNX_SQL_PrepareQuery(query))
    {
        int ret = NWNX_SQL_ExecutePreparedQuery();
        NWNX_SQL_DestroyPreparedQuery();
        return ret;
    }

    return FALSE;
}

int NWNX_SQL_ReadyToReadNextRow()
{
    NWNXCall(NWNX_SQL, "ReadyToReadNextRow");
    return NWNXPopInt();
}

void NWNX_SQL_ReadNextRow()
{
    NWNXCall(NWNX_SQL, "ReadNextRow");
}

string NWNX_SQL_ReadDataInActiveRow(int column = 0)
{
    NWNXPushInt(column);
    NWNXCall(NWNX_SQL, "ReadDataInActiveRow");
    return NWNXPopString();
}


void NWNX_SQL_PreparedInt(int position, int value)
{
    NWNXPushInt(value);
    NWNXPushInt(position);
    NWNXCall(NWNX_SQL, "PreparedInt");
}
void NWNX_SQL_PreparedString(int position, string value)
{
    NWNXPushString(value);
    NWNXPushInt(position);
    NWNXCall(NWNX_SQL, "PreparedString");
}
void NWNX_SQL_PreparedFloat(int position, float value)
{
    NWNXPushFloat(value);
    NWNXPushInt(position);
    NWNXCall(NWNX_SQL, "PreparedFloat");
}
void NWNX_SQL_PreparedObjectId(int position, object value)
{
    NWNXPushObject(value);
    NWNXPushInt(position);
    NWNXCall(NWNX_SQL, "PreparedObjectId");
}
void NWNX_SQL_PreparedObjectFull(int position, object value, int base64 = TRUE)
{
    NWNXPushInt(base64);
    NWNXPushObject(value);
    NWNXPushInt(position);
    NWNXCall(NWNX_SQL, "PreparedObjectFull");
}
void NWNX_SQL_PreparedNULL(int position)
{
    NWNXPushInt(position);
    NWNXCall(NWNX_SQL, "PreparedNULL");
}
void NWNX_SQL_PreparedJson(int position, json value)
{
    // Dump to string and continue as a string from here.
    // Famously assuming we're sent valid Json here.
    NWNX_SQL_PreparedString(position, JsonDump(value));
}


object NWNX_SQL_ReadFullObjectInActiveRow(int column = 0, object owner = OBJECT_INVALID, float x = 0.0, float y = 0.0, float z = 0.0, int base64 = TRUE)
{
    NWNXPushInt(base64);
    NWNXPushFloat(z);
    NWNXPushFloat(y);
    NWNXPushFloat(x);
    NWNXPushObject(owner);
    NWNXPushInt(column);
    NWNXCall(NWNX_SQL, "ReadFullObjectInActiveRow");
    return NWNXPopObject();
}

int NWNX_SQL_GetAffectedRows()
{
    NWNXCall(NWNX_SQL, "GetAffectedRows");
    return NWNXPopInt();
}

string NWNX_SQL_GetDatabaseType()
{
    NWNXCall(NWNX_SQL, "GetDatabaseType");
    return NWNXPopString();
}

void NWNX_SQL_DestroyPreparedQuery()
{
    NWNXCall(NWNX_SQL, "DestroyPreparedQuery");
}

string NWNX_SQL_GetLastError()
{
    NWNXCall(NWNX_SQL, "GetLastError");
    return NWNXPopString();
}

int NWNX_SQL_GetPreparedQueryParamCount()
{
    NWNXCall(NWNX_SQL, "GetPreparedQueryParamCount");
    return NWNXPopInt();
}

void NWNX_SQL_PostgreSQL_SetNextQueryResultsBinaryMode()
{
    NWNXCall(NWNX_SQL, "PostgreSQL_SetNextQueryResultsBinaryMode");
}
