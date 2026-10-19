/// @addtogroup watchcat Watchcat
/// @brief Functions to steer Watchcat.
/// @{
/// @file nwnx_watchcat.nss

const string NWNX_Watchcat = "NWNX_Watchcat"; ///< @private

/// @brief Marks the currently-running script as immune to watchcat. While the script runs, Watchcat will ignore any server stalls that occur.
void NWNX_Watchcat_DisableUntilScriptExit();

/// @}

int NWNX_Watchcat_DisableUntilScriptExit()
{
    NWNXCall(NWNX_Watchcat, "DisableUntilScriptExit");
}
