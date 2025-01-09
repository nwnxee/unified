/// @addtogroup nwnx NWNX
/// @brief Core NWNX Functions.
/// @{
/// @file nwnx_core.nss

const string NWNX_Core = "NWNX_Core"; ///< @private

/// @brief Determines if the given plugin exists and is enabled.
/// @param sPlugin The name of the plugin to check. This is the case sensitive plugin name as used by NWNXCall
/// @note Example usage: NWNX_PluginExists("NWNX_Creature");
/// @return TRUE if the plugin exists and is enabled, otherwise FALSE.
int NWNX_Core_PluginExists(string sPlugin);

/// @}

int NWNX_Core_PluginExists(string sPlugin)
{
    NWNXPushString(sPlugin);
    NWNXCall(NWNX_Core, "PluginExists");
    return NWNXPopInt();
}
