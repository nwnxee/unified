/// @addtogroup nwsqliteextensions NWSQLiteExtensions
/// @brief Various extensions for the game's built-in sqlite database.
/// @{
/// @file nwnx_nwsqliteext.nss
#include "nwnx"

const string NWNX_NWSQLiteExtensions = "NWNX_NWSQLiteExtensions"; ///< @private

/// @brief Create a virtual table for s2DA in the module sqlite database.
/// @param s2DA The 2DA name, cannot be empty.
/// @param sColumnTypeHints A string containing type hints for the 2DA columns. See this plugin's readme file for more info.
/// @param sTableName The table name, will use the 2da name if empty.
/// @return TRUE if the virtual table was created.
int NWNX_NWSQLiteExtensions_CreateVirtual2DATable(string s2DA, string sColumnTypeHints = "", string sTableName = "");

/// @}

int NWNX_NWSQLiteExtensions_CreateVirtual2DATable(string s2DA, string sColumnTypeHints = "", string sTableName = "")
{
    NWNX_PushArgumentString(sTableName);
    NWNX_PushArgumentString(sColumnTypeHints);
    NWNX_PushArgumentString(s2DA);
    NWNX_CallFunction(NWNX_NWSQLiteExtensions, "CreateVirtual2DATable");
    return NWNX_GetReturnValueInt();
}
