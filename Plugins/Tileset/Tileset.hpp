#pragma once

#include "Plugin.hpp"
#include "Services/Events/Events.hpp"
#include "Services/Hooks/Hooks.hpp"

#include <unordered_map>

using ArgumentStack = NWNXLib::Services::Events::ArgumentStack;

namespace Tileset
{

class Tileset : public NWNXLib::Plugin
{
public:
    struct TileData
    {
        int32_t id;
        uint8_t orientation;
        int32_t height;

        uint8_t mainLightColor1;
        uint8_t mainLightColor2;
        uint8_t sourceLightColor1;
        uint8_t sourceLightColor2;

        bool animLoop1;
        bool animLoop2;
        bool animLoop3;
    };

    struct TileOverride
    {
        std::string tileset;
        int32_t width;
        int32_t height;

        std::unordered_map<int32_t, TileData> tileData;
    };

public:
    Tileset(NWNXLib::Services::ProxyServiceList* services);
    virtual ~Tileset() {}

private:
    static int32_t LoadTileSetInfoHook(CNWSArea*, CResStruct*);

    ArgumentStack GetTilesetData(ArgumentStack&&);
    ArgumentStack GetTilesetTerrain(ArgumentStack&&);
    ArgumentStack GetTilesetCrosser(ArgumentStack&&);
    ArgumentStack GetTilesetGroupData(ArgumentStack&&);
    ArgumentStack GetTilesetGroupTile(ArgumentStack&&);
    ArgumentStack GetTileModel(ArgumentStack&&);
    ArgumentStack GetTileMinimapTexture(ArgumentStack&&);
    ArgumentStack GetTileEdgesAndCorners(ArgumentStack&&);
    ArgumentStack GetTileNumDoors(ArgumentStack&&);
    ArgumentStack GetTileDoorData(ArgumentStack&&);
    ArgumentStack SetAreaTileOverride(ArgumentStack&&);
    ArgumentStack CreateTileOverride(ArgumentStack&&);
    ArgumentStack DeleteTileOverride(ArgumentStack&&);
    ArgumentStack SetOverrideTileData(ArgumentStack&&);
    ArgumentStack DeleteOverrideTileData(ArgumentStack&&);

    std::vector<int32_t> m_GroupTilesVector;
    std::unordered_map<std::string, std::string> m_AreaTileOverrideMap;
    std::unordered_map<std::string, TileOverride> m_TileOverrideMap;
};

}
