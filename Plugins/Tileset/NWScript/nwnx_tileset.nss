/// @addtogroup tileset Tileset
/// @brief An advanced plugin that exposes additional tileset and tile properties and allows builders to override the tiles of an area created with CreateArea().
/// @{
/// @file nwnx_tileset.nss

const string NWNX_Tileset = "NWNX_Tileset"; ///< @private

/// @brief A structure containing general tileset data.
struct NWNX_Tileset_TilesetData
{
    int nNumTileData; ///< The number of tiles in the tileset.
    float fHeightTransition; ///< The height difference between tiles on different heights.
    int nNumTerrain; ///< The number of terrains in the tileset.
    int nNumCrossers; ///< The number of crossers in the tileset.
    int nNumGroups; ///< The number of groups in the tileset.
    string sBorderTerrain; ///< The default border terrain of the tileset.
    string sDefaultTerrain; ///< The default terrain of the tileset.
    string sFloorTerrain; ///< The default floor terrain of the tileset.
    int nDisplayNameStrRef; ///< The name of the tileset as strref, -1 if not set.
    string sUnlocalizedName; ///< The unlocalized name of the tileset, "" if not set.
    int bInterior; ///< The type of tileset. TRUE for interior, FALSE for exterior.
    int bHasHeightTransition; ///< TRUE if the tileset supports multiple height levels. FALSE if not.
};

/// @brief A structure containing the group data for a tileset.
struct NWNX_Tileset_TilesetGroupData
{
    string sName; ///< The name of the group.
    int nStrRef; ///< The StrRef of the group.
    int nRows; ///< The number of rows the group has.
    int nColumns; ///< The number of columns the group has.
};

/// @brief A structure containing the edge and corner types of a tile.
struct NWNX_Tileset_TileEdgesAndCorners
{
    string sTopLeft; ///< The top left corner.
    string sTop; ///< The top edge.
    string sTopRight; ///< The top right corner.
    string sRight; ///< The right edge.
    string sBottomRight; ///< The bottom right corner.
    string sBottom; ///< The bottom edge.
    string sBottomLeft; ///< The bottom left corner.
    string sLeft; ///< The left edge.
};

/// @brief A structure containing the door data for a tile.
struct NWNX_Tileset_TileDoorData
{
    int nType; ///< The type of door, returns an index into doortypes.2da.
    float fX; ///< The X position of the door.
    float fY; ///< The Y position of the door.
    float fZ; ///< The Z position of the door.
    float fOrientation; ///< The orientation of the door.
};

/// @brief A structure containing custom tile data,
struct NWNX_Tileset_CustomTileData
{
    int nTileID; ///< The tile ID. See the tileset's .set file.
    int nOrientation; ///< The orientation of the tile. Valid values: 0-3.
    int nHeight; ///< The height of the tile.

    int nMainLightColor1; ///< A `TILE_MAIN_LIGHT_COLOR_*` value.
    int nMainLightColor2; ///< A `TILE_MAIN_LIGHT_COLOR_*` value.
    int nSourceLightColor1; ///< A `TILE_SOURCE_LIGHT_COLOR_*` value.
    int nSourceLightColor2; ///< A `TILE_SOURCE_LIGHT_COLOR_*` value.

    int bAnimLoop1; ///< A bool to enable or disable the tile's first anim loop.
    int bAnimLoop2; ///< A bool to enable or disable the tile's second anim loop.
    int bAnimLoop3; ///< A bool to enable or disable the tile's third anim loop.
};

/// @brief Get general data of sTileset.
/// @param sTileset The tileset.
/// @return A NWNX_Tileset_TilesetData struct.
struct NWNX_Tileset_TilesetData NWNX_Tileset_GetTilesetData(string sTileset);

/// @brief Get the name of sTileset's terrain at nIndex.
/// @param sTileset The tileset.
/// @param nIndex The index of the terrain. Range: NWNX_Tileset_TilesetData.nNumTerrain > nIndex >= 0
/// @return The terrain name or "" on error.
string NWNX_Tileset_GetTilesetTerrain(string sTileset, int nIndex);

/// @brief Get the name of sTileset's crosser at nIndex.
/// @param sTileset The tileset.
/// @param nIndex The index of the crosser. Range: NWNX_Tileset_TilesetData.nNumCrossers > nIndex >= 0
/// @return The crosser name or "" on error.
string NWNX_Tileset_GetTilesetCrosser(string sTileset, int nIndex);

/// @brief Get general data of the group at nIndex in sTileset.
/// @param sTileset The tileset.
/// @param nIndex The index of the group. Range: NWNX_Tileset_TilesetData.nNumGroups > nIndex >= 0
/// @return A NWNX_Tileset_TilesetGroupData struct.
struct NWNX_Tileset_TilesetGroupData NWNX_Tileset_GetTilesetGroupData(string sTileset, int nIndex);

/// @brief Get the tile ID at nTileIndex in nGroupIndex of sTileset.
/// @param sTileset The tileset.
/// @param nGroupIndex The index of the group. Range: NWNX_Tileset_TilesetData.nNumGroups > nGroupIndex >= 0
/// @param nTileIndex The index of the tile. Range: (NWNX_Tileset_TilesetGroupData.nRows * NWNX_Tileset_TilesetGroupData.nColumns) > nTileIndex >= 0
/// @return The tile ID or 0 on error.
int NWNX_Tileset_GetTilesetGroupTile(string sTileset, int nGroupIndex, int nTileIndex);

/// @brief Get the model name of a tile in sTileset.
/// @param sTileset The tileset.
/// @param nTileID The tile ID.
/// @return The model name or "" on error.
string NWNX_Tileset_GetTileModel(string sTileset, int nTileID);

/// @brief Get the minimap texture name of a tile in sTileset.
/// @param sTileset The tileset.
/// @param nTileID The tile ID.
/// @return The minimap texture name or "" on error.
string NWNX_Tileset_GetTileMinimapTexture(string sTileset, int nTileID);

/// @brief Get the edges and corners of a tile in sTileset.
/// @param sTileset The tileset.
/// @param nTileID The tile ID.
/// @return A NWNX_Tileset_TileEdgesAndCorners struct.
struct NWNX_Tileset_TileEdgesAndCorners NWNX_Tileset_GetTileEdgesAndCorners(string sTileset, int nTileID);

/// @brief Get the number of doors of a tile in sTileset.
/// @param sTileset The tileset.
/// @param nTileID The tile ID.
/// @return The amount of doors.
int NWNX_Tileset_GetTileNumDoors(string sTileset, int nTileID);

/// @brief Get the door data of a tile in sTileset.
/// @param sTileset The tileset.
/// @param nTileID The tile ID.
/// @param nIndex The index of the door. Range: NWNX_Tileset_GetTileNumDoors() > nIndex >= 0
/// @return A NWNX_Tileset_TileDoorData struct.
struct NWNX_Tileset_TileDoorData NWNX_Tileset_GetTileDoorData(string sTileset, int nTileID, int nIndex = 0);

/// @brief Override the tiles of sAreaResRef with data in sOverrideName.
/// @param sAreaResRef The resref of the area to override.
/// @param sOverrideName The name of the override containing the custom tile data or "" to remove the override.
void NWNX_Tileset_SetAreaTileOverride(string sAreaResRef, string sOverrideName);

/// @brief Create a tile override named sOverrideName.
/// @param sOverrideName The name of the override.
/// @param sTileSet The tileset the override should use.
/// @param nWidth The width of the area. Valid values: 1-32.
/// @param nHeight The height of the area. Valid values: 1-32.
void NWNX_Tileset_CreateTileOverride(string sOverrideName, string sTileSet, int nWidth, int nHeight);

/// @brief Delete a tile override named sOverrideName.
/// @note This will also delete all custom tile data associated with sOverrideName.
/// @param sOverrideName The name of the override.
void NWNX_Tileset_DeleteTileOverride(string sOverrideName);

/// @brief Set custom tile data for the tile at nIndex in sOverrideName.
/// @note An override must first be created with NWNX_Tileset_CreateTileOverride().
/// @param sOverrideName The name of the override.
/// @param nIndex The index of the tile.
/// @param strCustomTileData A NWNX_Tileset_CustomTileData struct.
void NWNX_Tileset_SetOverrideTileData(string sOverrideName, int nIndex, struct NWNX_Tileset_CustomTileData strCustomTileData);

/// @brief Delete custom tile data of the tile at nIndex in sOverrideName.
/// @param sOverrideName The name of the override.
/// @param nIndex The tile's index or -1 to remove all custom tile data.
void NWNX_Tileset_DeleteOverrideTileData(string sOverrideName, int nIndex);

/// @}

struct NWNX_Tileset_TilesetData NWNX_Tileset_GetTilesetData(string sTileset)
{
    NWNXPushString(sTileset);
    NWNXCall(NWNX_Tileset, "GetTilesetData");
    struct NWNX_Tileset_TilesetData str;
    str.bHasHeightTransition = NWNXPopInt();
    str.bInterior = NWNXPopInt();
    str.sUnlocalizedName = NWNXPopString();
    str.nDisplayNameStrRef = NWNXPopInt();
    str.sFloorTerrain = NWNXPopString();
    str.sDefaultTerrain = NWNXPopString();
    str.sBorderTerrain = NWNXPopString();
    str.nNumGroups = NWNXPopInt();
    str.nNumCrossers = NWNXPopInt();
    str.nNumTerrain = NWNXPopInt();
    str.fHeightTransition = NWNXPopFloat();
    str.nNumTileData = NWNXPopInt();
    return str;
}

string NWNX_Tileset_GetTilesetTerrain(string sTileset, int nIndex)
{
    NWNXPushInt(nIndex);
    NWNXPushString(sTileset);
    NWNXCall(NWNX_Tileset, "GetTilesetTerrain");
    return NWNXPopString();
}

string NWNX_Tileset_GetTilesetCrosser(string sTileset, int nIndex)
{
    NWNXPushInt(nIndex);
    NWNXPushString(sTileset);
    NWNXCall(NWNX_Tileset, "GetTilesetCrosser");
    return NWNXPopString();
}

struct NWNX_Tileset_TilesetGroupData NWNX_Tileset_GetTilesetGroupData(string sTileset, int nIndex)
{
    NWNXPushInt(nIndex);
    NWNXPushString(sTileset);
    NWNXCall(NWNX_Tileset, "GetTilesetGroupData");
    struct NWNX_Tileset_TilesetGroupData str;
    str.nColumns = NWNXPopInt();
    str.nRows = NWNXPopInt();
    str.nStrRef = NWNXPopInt();
    str.sName = NWNXPopString();
    return str;
}

int NWNX_Tileset_GetTilesetGroupTile(string sTileset, int nGroupIndex, int nTileIndex)
{
    NWNXPushInt(nTileIndex);
    NWNXPushInt(nGroupIndex);
    NWNXPushString(sTileset);
    NWNXCall(NWNX_Tileset, "GetTilesetGroupTile");
    return NWNXPopInt();
}

string NWNX_Tileset_GetTileModel(string sTileset, int nTileID)
{
    NWNXPushInt(nTileID);
    NWNXPushString(sTileset);
    NWNXCall(NWNX_Tileset, "GetTileModel");
    return NWNXPopString();
}

string NWNX_Tileset_GetTileMinimapTexture(string sTileset, int nTileID)
{
    NWNXPushInt(nTileID);
    NWNXPushString(sTileset);
    NWNXCall(NWNX_Tileset, "GetTileMinimapTexture");
    return NWNXPopString();
}

struct NWNX_Tileset_TileEdgesAndCorners NWNX_Tileset_GetTileEdgesAndCorners(string sTileset, int nTileID)
{
    NWNXPushInt(nTileID);
    NWNXPushString(sTileset);
    NWNXCall(NWNX_Tileset, "GetTileEdgesAndCorners");
    struct NWNX_Tileset_TileEdgesAndCorners str;
    str.sLeft = NWNXPopString();
    str.sBottomLeft = NWNXPopString();
    str.sBottom = NWNXPopString();
    str.sBottomRight = NWNXPopString();
    str.sRight = NWNXPopString();
    str.sTopRight = NWNXPopString();
    str.sTop = NWNXPopString();
    str.sTopLeft = NWNXPopString();
    return str;
}

int NWNX_Tileset_GetTileNumDoors(string sTileset, int nTileID)
{
    NWNXPushInt(nTileID);
    NWNXPushString(sTileset);
    NWNXCall(NWNX_Tileset, "GetTileNumDoors");
    return NWNXPopInt();
}

struct NWNX_Tileset_TileDoorData NWNX_Tileset_GetTileDoorData(string sTileset, int nTileID, int nIndex = 0)
{
    NWNXPushInt(nIndex);
    NWNXPushInt(nTileID);
    NWNXPushString(sTileset);
    NWNXCall(NWNX_Tileset, "GetTileDoorData");
    struct NWNX_Tileset_TileDoorData str;
    str.fOrientation = NWNXPopFloat();
    str.fZ = NWNXPopFloat();
    str.fY = NWNXPopFloat();
    str.fX = NWNXPopFloat();
    str.nType = NWNXPopInt();
    return str;
}

void NWNX_Tileset_SetAreaTileOverride(string sAreaResRef, string sOverrideName)
{
    NWNXPushString(sOverrideName);
    NWNXPushString(sAreaResRef);
    NWNXCall(NWNX_Tileset, "SetAreaTileOverride");
}

void NWNX_Tileset_CreateTileOverride(string sOverrideName, string sTileSet, int nWidth, int nHeight)
{
    NWNXPushInt(nHeight);
    NWNXPushInt(nWidth);
    NWNXPushString(sTileSet);
    NWNXPushString(sOverrideName);
    NWNXCall(NWNX_Tileset, "CreateTileOverride");
}

void NWNX_Tileset_DeleteTileOverride(string sOverrideName)
{
    NWNXPushString(sOverrideName);
    NWNXCall(NWNX_Tileset, "DeleteTileOverride");
}

void NWNX_Tileset_SetOverrideTileData(string sOverrideName, int nIndex, struct NWNX_Tileset_CustomTileData strCustomTileData)
{
    NWNXPushInt(strCustomTileData.bAnimLoop3);
    NWNXPushInt(strCustomTileData.bAnimLoop2);
    NWNXPushInt(strCustomTileData.bAnimLoop1);
    NWNXPushInt(strCustomTileData.nSourceLightColor2);
    NWNXPushInt(strCustomTileData.nSourceLightColor1);
    NWNXPushInt(strCustomTileData.nMainLightColor2);
    NWNXPushInt(strCustomTileData.nMainLightColor1);
    NWNXPushInt(strCustomTileData.nHeight);
    NWNXPushInt(strCustomTileData.nOrientation);
    NWNXPushInt(strCustomTileData.nTileID);
    NWNXPushInt(nIndex);
    NWNXPushString(sOverrideName);
    NWNXCall(NWNX_Tileset, "SetOverrideTileData");
}

void NWNX_Tileset_DeleteOverrideTileData(string sOverrideName, int nIndex)
{
    NWNXPushInt(nIndex);
    NWNXPushString(sOverrideName);
    NWNXCall(NWNX_Tileset, "DeleteOverrideTileData");
}
