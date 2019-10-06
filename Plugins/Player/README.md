# Player Plugin Reference

## Description

Functions exposing additional player properties and commands.

## Function Documentation and Examples

#### SetPersistentLocation()
This function is mainly used so after a server restart the PC doesn't need to load the starting area before being jumped to their persistent location.

Another example usage could be different starting locations for new characters depending on alignment.

Below is an example of setting a player's persistent location for each of their characters in the `NWNX_ON_CLIENT_CONNECT_AFTER` event.
```c
void main()
{
    object oPC = OBJECT_SELF;

    if (GetIsDM(oPC))
        return;

    string sSQL = "SELECT bic_file, current_loc FROM player_tracking WHERE public_cdkey = ? AND persistent_locs_loaded = 0";
    string sCDKey = NWNX_Events_GetEventData("CDKEY");
    NWNX_SQL_PrepareQuery(sSQL);
    NWNX_SQL_PreparedString(0, sCDKey);
    NWNX_SQL_ExecutePreparedQuery();
    int nLoaded = 0;
    while (NWNX_SQL_ReadyToReadNextRow())
    {
        NWNX_SQL_ReadNextRow();
        nLoaded = 1;
        string sResRef = NWNX_SQL_ReadDataInActiveRow(0);
        location lLoc = NWNXStringToLocation(NWNX_SQL_ReadDataInActiveRow(1));
        object oWP = CreateObject(OBJECT_TYPE_WAYPOINT, "nw_waypoint001", lLoc);
        if (GetArea(oWP) != OBJECT_INVALID)
            NWNX_Player_SetPersistentLocation(sCDKey, sResRef, oWP);
    }
    if (nLoaded)
    {
        sSQL = "UPDATE player_tracking SET persistent_locs_loaded = 1 WHERE public_cdkey = ?";
        NWNX_SQL_PrepareQuery(sSQL);
        NWNX_SQL_PreparedString(0, sCDKey);
        NWNX_SQL_ExecutePreparedQuery();
    }
}
```

In this example make you would make sure to reset the `persistent_locs_loaded` back to 0 for all players `OnModuleLoad`.

        string sSQL = "UPDATE player_tracking SET persistent_locs_loaded = 0";
        NWNX_SQL_PrepareQuery(sSQL);
        NWNX_SQL_ExecutePreparedQuery();