@page tileset Readme
@ingroup tileset

This plugin allows the builder to override the tiles of areas created with CreateArea(). It also exposes various properties from tileset .set files.

## Notes

This is a pretty advanced plugin, the builder should be familiar with .set files and the tiles part of the area file format. See: [Bioware_Aurora_AreaFile_Format.pdf](https://nwn.wiki/pages/viewpage.action?pageId=327727) on the [Neverwinter Vault Modding Wiki](https://nwn.wiki/).

## Simple Example

Please create a small area with `myarea` as resref as prerequisite. The tileset and size doesn't matter as we'll be overriding them. You can set any other area settings though.

```c
#include "nwnx_tileset"

// A wrapper around NWNX_Tileset_SetCustomTileData()
void SetTileData(string sOverrideName, int nTileIndex, int nTileID, int nTileOrientation)
{
    struct NWNX_Tileset_CustomTileData ctd;
    ctd.nTileID = nTileID;
    ctd.nOrientation = nTileOrientation;
    ctd.nHeight = 0;
    ctd.nMainLightColor1 = TILE_MAIN_LIGHT_COLOR_BRIGHT_WHITE;
    ctd.nMainLightColor2 = TILE_MAIN_LIGHT_COLOR_BRIGHT_WHITE;
    ctd.nSourceLightColor1 = TILE_SOURCE_LIGHT_COLOR_PALE_YELLOW;
    ctd.nSourceLightColor2 = TILE_SOURCE_LIGHT_COLOR_PALE_YELLOW;
    ctd.bAnimLoop1 = TRUE;
    ctd.bAnimLoop2 = TRUE;
    ctd.bAnimLoop3 = TRUE;

    NWNX_Tileset_SetOverrideTileData(sOverrideName, nTileIndex, ctd);
}

void main()
{
    string sOverrideName = "MyTileOverride";
    string sTileset = TILESET_RESREF_RURAL;
    int nWidth = 3, nHeight = 3;

    // We're creating an override that is a 3x3 area using the rural tileset.
    NWNX_Tileset_CreateTileOverride(sOverrideName, sTileset, nWidth, nHeight);

    // Tiles are stored in an array where 0 is the bottom left tile.
    // A 3x3 area would have the following indexes for the tiles:
    // 6  7  8
    // 3  4  5
    // 0  1  2

    // The orientation of a tile is specified by a 0-3 value.
    // 0 = normal orientation.
    // 1 = 90 degrees counterclockwise.
    // 2 = 180 degrees counterclockwise.
    // 3 = 270 degrees counterclockwise.

    // Here we set the data for the first tile at index 0, the bottom left tile.
    // 35 is the ID of a corner tile with trees.
    // Rotate the tile 180 degrees counterclockwise.
    SetTileData(sOverrideName, 0, 35, 2);

    // Set the data for the tile at index 1.
    // 36 is the ID of a edge tile with trees.
    // Rotate the tile 270 degrees counterclockwise.
    SetTileData(sOverrideName, 1, 36, 3);

    // Set the data for the tile at index 2.
    // 35 again for another corner with trees.
    // Rotate the tile 270 degrees counterclockwise.
    SetTileData(sOverrideName, 2, 35, 3);

    // Set the data for the tile at index 3.
    // 36 again for another edge with trees.
    // Rotate the tile 180 degrees counterclockwise.
    SetTileData(sOverrideName, 3, 36, 2);

    // Set the data for the tile at index 4.
    // 120 is the ID of a tile that's just grass.
    // No need to rotate it
    SetTileData(sOverrideName, 4, 120, 0);

    // Setting the rest of the tiles.
    SetTileData(sOverrideName, 5, 36, 0);
    SetTileData(sOverrideName, 6, 35, 1);
    SetTileData(sOverrideName, 7, 36, 1);
    SetTileData(sOverrideName, 8, 35, 0);

    // Here we override the tiles of the area that has "myarea" as resref with our override.
    NWNX_Tileset_SetAreaTileOverride("myarea", sOverrideName);

    // We can't override or change the tiles of existing areas so we have to
    // create a new one using the resref we've just overridden the tiles of
    CreateArea("myarea", "MY_COOL_AREA", "Optional Cool Name");
}
```

If all went well, when you move to the newly created area, it should look like this:
 
![Area](https://i.imgur.com/WgHIK7N.png)