#include "nwnx"

// Prepares the provided query for execution. Does not execute it! Clears any previous state.
void NWNX_SQL_PrepareQuery(string query);

// Executes a query which has been prepared.
// Returns the ID of this query if successful, else FALSE.
int NWNX_SQL_ExecuteQuery();

// Returns TRUE if one or more rows are ready, FALSE otherwise.
int NWNX_SQL_ReadyToReadNextRow();

// Reads the next row of returned data.
// Should only be called after a successsful call to NWNX_SQL_ReadyToReadNextRow().
void NWNX_SQL_ReadNextRow();

// Returns data at the nth (0-based) column of the active row.
// NWNX_SQL_ReadNextRow should be called before this.
string NWNX_SQL_ReadDataInActiveRow(int column = 0);

void NWNX_SQL_PrepareQuery(string query)
{
    NWNX_PushArgumentString("NWNX_SQL", "PREPARE_QUERY", query);
    NWNX_CallFunction("NWNX_SQL", "PREPARE_QUERY");
}

int NWNX_SQL_ExecuteQuery()
{
    NWNX_CallFunction("NWNX_SQL", "EXECUTE_QUERY");
    return NWNX_GetReturnValueInt("NWNX_SQL", "EXECUTE_QUERY");
}

int NWNX_SQL_ReadyToReadNextRow()
{
    NWNX_CallFunction("NWNX_SQL", "READY_TO_READ_NEXT_ROW");
    return NWNX_GetReturnValueInt("NWNX_SQL", "READY_TO_READ_NEXT_ROW");
}

void NWNX_SQL_ReadNextRow()
{
    NWNX_CallFunction("NWNX_SQL", "READ_NEXT_ROW");
}

string NWNX_SQL_ReadDataInActiveRow(int column = 0)
{
    NWNX_PushArgumentInt("NWNX_SQL", "READ_DATA_IN_ACTIVE_ROW", column);
    NWNX_CallFunction("NWNX_SQL", "READ_DATA_IN_ACTIVE_ROW");
    return NWNX_GetReturnValueString("NWNX_SQL", "READ_DATA_IN_ACTIVE_ROW");
}
