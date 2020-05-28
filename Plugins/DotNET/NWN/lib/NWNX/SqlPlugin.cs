namespace NWNX
{
    [NWNXPlugin(NWNX_SQL)]
    public class SqlPlugin
    {
        public const string NWNX_SQL = "NWNX_SQL";

        // /< @private
        // / @brief Prepares the provided query for execution.
        // / @note This does not execute the query. Will also clear any previous state.
        // / @param query The query to prepare.
        // / @return TRUE if the query was successfully prepared.
        public static int PrepareQuery(string query)
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_SQL, "PrepareQuery");
            NWN.Internal.NativeFunctions.nwnxPushString(query);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
            return NWN.Internal.NativeFunctions.nwnxPopInt();
        }

        // / @brief Executes a query which has been prepared.
        // / @return The ID of this query if successful, else FALSE.
        public static int ExecutePreparedQuery()
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_SQL, "ExecutePreparedQuery");
            NWN.Internal.NativeFunctions.nwnxCallFunction();
            return NWN.Internal.NativeFunctions.nwnxPopInt();
        }

        // / @brief Directly execute an SQL query.
        // / @note Clears previously prepared query states.
        // / @return The ID of this query if successful, else FALSE.
        public static int ExecuteQuery(string query)
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_SQL, "ExecuteQuery");
            NWN.Internal.NativeFunctions.nwnxPushString(query);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
            return NWN.Internal.NativeFunctions.nwnxPopInt();
        }

        // / @anchor sql_rtrnr
        // / @return TRUE if one or more rows are ready, FALSE otherwise.
        public static int ReadyToReadNextRow()
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_SQL, "ReadyToReadNextRow");
            NWN.Internal.NativeFunctions.nwnxCallFunction();
            return NWN.Internal.NativeFunctions.nwnxPopInt();
        }

        // / @anchor sql_rnr
        // / @brief Reads the next row of returned data.
        // / @remark Should only be called after a successful call to @ref sql_rtrnr "NWNX_SQL_ReadyToReadNextRow()".
        public static void ReadNextRow()
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_SQL, "ReadNextRow");
            NWN.Internal.NativeFunctions.nwnxCallFunction();
        }

        // / @param column The column to read in the active row.
        // / @return Data at the nth (0-based) column of the active row.
        // / @remark Should only be called after a successful call to @ref sql_rnr "NWNX_SQL_ReadNextRow()".
        public static string ReadDataInActiveRow(int column = 0)
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_SQL, "ReadDataInActiveRow");
            NWN.Internal.NativeFunctions.nwnxPushInt(column);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
            return NWN.Internal.NativeFunctions.nwnxPopString();
        }

        // / @brief Set the int value of a prepared statement at given position.
        // / @param position The nth ? in a prepared statement.
        // / @param value The value to set.
        public static void PreparedInt(int position, int value)
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_SQL, "PreparedInt");
            NWN.Internal.NativeFunctions.nwnxPushInt(value);
            NWN.Internal.NativeFunctions.nwnxPushInt(position);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
        }

        // / @brief Set the string value of a prepared statement at given position.
        // / @param position The nth ? in a prepared statement.
        // / @param value The value to set.
        public static void PreparedString(int position, string value)
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_SQL, "PreparedString");
            NWN.Internal.NativeFunctions.nwnxPushString(value);
            NWN.Internal.NativeFunctions.nwnxPushInt(position);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
        }

        // / @brief Set the float value of a prepared statement at given position.
        // / @param position The nth ? in a prepared statement.
        // / @param value The value to set.
        public static void PreparedFloat(int position, float value)
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_SQL, "PreparedFloat");
            NWN.Internal.NativeFunctions.nwnxPushFloat(value);
            NWN.Internal.NativeFunctions.nwnxPushInt(position);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
        }

        // / @brief Set the ObjectId value of a prepared statement at given position.
        // / @param position The nth ? in a prepared statement.
        // / @param value The value to set.
        public static void PreparedObjectId(int position, uint value)
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_SQL, "PreparedObjectId");
            NWN.Internal.NativeFunctions.nwnxPushObject(value);
            NWN.Internal.NativeFunctions.nwnxPushInt(position);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
        }

        // / @brief Set the full serialized object value of a prepared statement at given position.
        // / @param position The nth ? in a prepared statement.
        // / @param value The value to set.
        // / @param base64 Use base64-encoded string format if TRUE (default), otherwise use binary format.
        public static void PreparedObjectFull(int position, uint value, int base64 = NWN.NWScript.TRUE)
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_SQL, "PreparedObjectFull");
            NWN.Internal.NativeFunctions.nwnxPushInt(base64);
            NWN.Internal.NativeFunctions.nwnxPushObject(value);
            NWN.Internal.NativeFunctions.nwnxPushInt(position);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
        }

        // / @brief Like NWNX_SQL_ReadDataInActiveRow, but for full serialized objects.
        // /
        // / The object will be deserialized and created in the game. New object ID is returned.
        // /
        // / The exact behavior depends on type of deserialized object and owner object:
        // /   * If object is an item, and owner if placeable, creature or container, the item will be created in its inventory
        // /   * If owner is an area, the object will be created on the ground at Vector(x,y,z)
        // /   * Otherwise, the object will be created outside the world and needs to be ported manually.
        // /
        // / @param column The column to read in the active row.
        // / @param owner The owner of the object.
        // / @param x, y, z The vector for objects to be placed in areas.
        // / @param base64 Use base64-encoded string format if TRUE (default), otherwise use binary format.
        // / @return The deserialized object.
        public static uint ReadFullObjectInActiveRow(int column = 0, uint owner = NWN.NWScript.OBJECT_INVALID, float x = 0.0f, float y = 0.0f, float z = 0.0f, int base64 = NWN.NWScript.TRUE)
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_SQL, "ReadFullObjectInActiveRow");
            NWN.Internal.NativeFunctions.nwnxPushInt(base64);
            NWN.Internal.NativeFunctions.nwnxPushFloat(z);
            NWN.Internal.NativeFunctions.nwnxPushFloat(y);
            NWN.Internal.NativeFunctions.nwnxPushFloat(x);
            NWN.Internal.NativeFunctions.nwnxPushObject(owner);
            NWN.Internal.NativeFunctions.nwnxPushInt(column);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
            return NWN.Internal.NativeFunctions.nwnxPopObject();
        }

        // / @brief Gets the rows affected by a query.
        // / @remark This command is for non-row-based statements like INSERT, UPDATE, DELETE, etc.
        // / @return Number of rows affected by SQL statement or -1 if the query was not non-row-based.
        public static int GetAffectedRows()
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_SQL, "GetAffectedRows");
            NWN.Internal.NativeFunctions.nwnxCallFunction();
            return NWN.Internal.NativeFunctions.nwnxPopInt();
        }

        // / Gets the database type.
        // / @return The database type we're interacting with.
        // / @remark This is the same value as the value of NWNX_SQL_TYPE environment variable.
        public static string GetDatabaseType()
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_SQL, "GetDatabaseType");
            NWN.Internal.NativeFunctions.nwnxCallFunction();
            return NWN.Internal.NativeFunctions.nwnxPopString();
        }

        // / @brief Free any resources attached to an existing prepared query.
        // / @remark Resources are automatically freed when a new query is prepared, so calling this isn't necessary.
        public static void DestroyPreparedQuery()
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_SQL, "DestroyPreparedQuery");
            NWN.Internal.NativeFunctions.nwnxCallFunction();
        }

        // / @return The last error message generated by the database.
        public static string GetLastError()
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_SQL, "GetLastError");
            NWN.Internal.NativeFunctions.nwnxCallFunction();
            return NWN.Internal.NativeFunctions.nwnxPopString();
        }

        // / @brief Gets the number of parameteres expected by a prepared query.
        // / @return Returns the number of parameters expected by the prepared query or -1 if no query is prepared.
        public static int GetPreparedQueryParamCount()
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_SQL, "GetPreparedQueryParamCount");
            NWN.Internal.NativeFunctions.nwnxCallFunction();
            return NWN.Internal.NativeFunctions.nwnxPopInt();
        }

        // / @}
    }
}
