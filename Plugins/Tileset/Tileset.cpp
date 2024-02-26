#include "nwnx.hpp"

#include "API/CExoResMan.hpp"
#include "API/CResStruct.hpp"
#include "API/CNWSArea.hpp"
#include "API/CNWTileSetManager.hpp"
#include "API/CNWTileSet.hpp"
#include "API/CNWSTile.hpp"
#include "API/CNWTileData.hpp"
#include "API/CNWSVirtualMachineCommands.hpp"
#include "API/CAppManager.hpp"

using namespace NWNXLib;
using namespace NWNXLib::API;

struct CachedTilesetTileDoor
{
    int32_t type;
    Vector position;
    float orientation;
};
struct CachedTilesetTile
{
    std::string tileModel;
    std::string minimapTexture;
    std::string tl, t, tr, r, br, b, bl, l;
    int32_t numDoors;
    std::vector<CachedTilesetTileDoor> doors;
};
struct CachedTilesetGroup
{
    std::string name;
    int32_t strRef;
    int32_t rows;
    int32_t columns;
    std::vector<int32_t> tiles;
};
struct CachedTileset
{
    int32_t numTiles;
    int32_t numTerrains;
    int32_t numCrossers;
    int32_t numGroups;
    int32_t displayNameStrRef;
    int32_t isInterior;
    int32_t hasHeightTransition;
    float heightTransition;
    std::string borderTerrain;
    std::string defaultTerrain;
    std::string floorTerrain;
    std::string unlocalizedName;
    std::vector<std::string> terrains;
    std::vector<std::string> crossers;
    std::vector<CachedTilesetTile> tiles;
    std::vector<CachedTilesetGroup> groups;
};
struct TileOverrideTile
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

    std::unordered_map<int32_t, TileOverrideTile> tileData;
};

static std::unordered_map<std::string, CachedTileset> s_CachedTilesets;
static std::unordered_map<std::string, std::string> s_AreaTileOverrideMap;
static std::unordered_map<std::string, TileOverride> s_TileOverrideMap;
static bool s_CreatingArea = false;
static std::string s_OriginalSourceAreaResRef;

static Hooks::Hook s_ExecuteCommandAreaManagementHook = Hooks::HookFunction(
        &CNWSVirtualMachineCommands::ExecuteCommandAreaManagement,
        +[](CNWSVirtualMachineCommands *pThis, int32_t nCommandId, int32_t nParameters) -> int32_t
        {
            if (nCommandId == Constants::VMCommand::CreateArea)
            {
                s_CreatingArea = true;
                auto retVal = s_ExecuteCommandAreaManagementHook->CallOriginal<int32_t>(pThis, nCommandId, nParameters);
                s_CreatingArea = false;
                return retVal;
            }
            else
                return s_ExecuteCommandAreaManagementHook->CallOriginal<int32_t>(pThis, nCommandId, nParameters);
        }, Hooks::Order::Earliest);

static Hooks::Hook s_ResManGet = Hooks::HookFunction(
        &CExoResMan::Get,
        +[](CExoResMan *pThis, CResRef* cResRef, RESTYPE nType) -> DataBlockRef
        {
            if (s_CreatingArea && nType == Constants::ResRefType::ARE)
                s_OriginalSourceAreaResRef = cResRef->GetResRefStr();
            return s_ResManGet->CallOriginal<DataBlockRef>(pThis, cResRef, nType);
        }, Hooks::Order::Earliest);

static Hooks::Hook s_LoadTileSetInfoHook = Hooks::HookFunction(
        &CNWSArea::LoadTileSetInfo,
        +[](CNWSArea *pArea, CResStruct *pStruct) -> int32_t
        {
            if (s_CreatingArea)
            {
                LOG_DEBUG("Original ResRef: %s, New ResRef: %s", s_OriginalSourceAreaResRef, pArea->m_cResRef.GetResRefStr());

                auto areaTileOverride = s_AreaTileOverrideMap.find(s_OriginalSourceAreaResRef);

                if (areaTileOverride != s_AreaTileOverrideMap.end())
                {
                    auto tileOverride = s_TileOverrideMap.find(areaTileOverride->second);

                    if (tileOverride != s_TileOverrideMap.end())
                    {
                        if (!tileOverride->second.height || !tileOverride->second.width || tileOverride->second.tileset.empty())
                        {
                            LOG_WARNING("Invalid Tile Override Data: height or width are 0 or tileset is empty in override '%s'. Loading original tiles for area: '%s' (%s)",
                                        areaTileOverride->second, pArea->m_cResRef.GetResRefStr(), s_OriginalSourceAreaResRef);
                            return s_LoadTileSetInfoHook->CallOriginal<int32_t>(pArea, pStruct);
                        }

                        pArea->m_nHeight = tileOverride->second.height;
                        pArea->m_nWidth = tileOverride->second.width;
                        pArea->m_refTileSet = tileOverride->second.tileset;
                        pArea->m_pTileSet = Globals::AppManager()->m_pNWTileSetManager->GetTileSet(CResRef(tileOverride->second.tileset));

                        if (!pArea->m_pTileSet)
                        {
                            LOG_WARNING("Invalid Tile Override Data: could not load tileset '%s' in override '%s'. Loading original tiles for area: '%s' (%s)",
                                        tileOverride->second.tileset, areaTileOverride->second, pArea->m_cResRef.GetResRefStr(), s_OriginalSourceAreaResRef);
                            return s_LoadTileSetInfoHook->CallOriginal<int32_t>(pArea, pStruct);
                        }

                        int32_t numTiles = pArea->m_nHeight * pArea->m_nWidth;
                        pArea->m_pTile = new CNWSTile[numTiles];

                        for (int i = 0; i < numTiles; i++)
                        {
                            auto *pTile = &pArea->m_pTile[i];
                            auto tileData = tileOverride->second.tileData[i];

                            pTile->m_nID = tileData.id;
                            pTile->m_pTileData = pArea->m_pTileSet->GetTileData(tileData.id);

                            pTile->SetPosition(i % pArea->m_nWidth,
                                               i / pArea->m_nWidth,
                                               tileData.height,
                                               pArea->m_pTileSet->GetHeightTransition());

                            pTile->SetOrientation(tileData.orientation);

                            pTile->SetMainLightColor(tileData.mainLightColor1, tileData.mainLightColor2);
                            pTile->SetSourceLightColor(tileData.sourceLightColor1, tileData.sourceLightColor2);
                            pTile->SetReplaceTexture(0);
                            pTile->SetAnimLoop(tileData.animLoop1, tileData.animLoop2, tileData.animLoop3);

                            pTile->m_bMainLightColorChange = false;
                            pTile->m_bSourceLightColorChange = false;
                        }

                        return true;
                    }
                }
            }

            return s_LoadTileSetInfoHook->CallOriginal<int32_t>(pArea, pStruct);
        }, Hooks::Order::Late);

static CachedTileset* GetCachedTileset(const std::string& tileset)
{
    auto cachedTilesetIterator = s_CachedTilesets.find(tileset);
    if (cachedTilesetIterator != s_CachedTilesets.end())
    {
        return &cachedTilesetIterator->second;
    }

    auto *pTileset = Globals::AppManager()->m_pNWTileSetManager->GetTileSet(CResRef(tileset));

    if (!pTileset)
        return nullptr;

    if (!pTileset->m_pRes->Demand())
    {
        return nullptr;
    }

    CachedTileset cachedTileset{};
    char section[32];
    char entry[32];
    char value[256];

    cachedTileset.numTiles = pTileset->m_nNumTileData;
    cachedTileset.heightTransition = pTileset->m_fHeightTransition;
    pTileset->m_pRes->GetSectionEntryValue((char*)"TERRAIN TYPES", (char*)"Count", value);
    cachedTileset.numTerrains = atoi(value);
    pTileset->m_pRes->GetSectionEntryValue((char*)"CROSSER TYPES", (char*)"Count", value);
    cachedTileset.numCrossers = atoi(value);
    pTileset->m_pRes->GetSectionEntryValue((char*)"GROUPS", (char*)"Count", value);
    cachedTileset.numGroups = atoi(value);
    pTileset->m_pRes->GetSectionEntryValue((char*)"GENERAL", (char*)"Interior", value);
    cachedTileset.isInterior = atoi(value);
    pTileset->m_pRes->GetSectionEntryValue((char*)"GENERAL", (char*)"DisplayName", value);
    cachedTileset.displayNameStrRef = atoi(value);
    pTileset->m_pRes->GetSectionEntryValue((char*)"GENERAL", (char*)"UnlocalizedName", value);
    cachedTileset.unlocalizedName = value;
    pTileset->m_pRes->GetSectionEntryValue((char*)"GENERAL", (char*)"Border", value);
    cachedTileset.borderTerrain = value;
    pTileset->m_pRes->GetSectionEntryValue((char*)"GENERAL", (char*)"Default", value);
    cachedTileset.defaultTerrain = value;
    pTileset->m_pRes->GetSectionEntryValue((char*)"GENERAL", (char*)"Floor", value);
    cachedTileset.floorTerrain = value;
    pTileset->m_pRes->GetSectionEntryValue((char*)"GENERAL", (char*)"HasHeightTransition", value);
    cachedTileset.hasHeightTransition = atoi(value);

    cachedTileset.terrains.reserve(cachedTileset.numTerrains);
    for (int32_t terrain = 0; terrain < cachedTileset.numTerrains; terrain++)
    {
        std::sprintf(section, "TERRAIN%i", terrain);
        pTileset->m_pRes->GetSectionEntryValue(section, (char*)"Name", value);
        cachedTileset.terrains.emplace_back(value);
    }

    cachedTileset.crossers.reserve(cachedTileset.numCrossers);
    for (int32_t crosser = 0; crosser < cachedTileset.numCrossers; crosser++)
    {
        std::sprintf(section, "CROSSER%i", crosser);
        pTileset->m_pRes->GetSectionEntryValue(section, (char*)"Name", value);
        cachedTileset.crossers.emplace_back(value);
    }

    cachedTileset.groups.reserve(cachedTileset.numGroups);
    for (int32_t group = 0; group < cachedTileset.numGroups; group++)
    {
        std::sprintf(section, "GROUP%i", group);
        CachedTilesetGroup cachedTilesetGroup{};

        pTileset->m_pRes->GetSectionEntryValue(section, (char*)"Name", value);
        cachedTilesetGroup.name = value;
        pTileset->m_pRes->GetSectionEntryValue(section, (char*)"StrRef", value);
        cachedTilesetGroup.strRef = atoi(value);
        pTileset->m_pRes->GetSectionEntryValue(section, (char*)"Rows", value);
        cachedTilesetGroup.rows = atoi(value);
        pTileset->m_pRes->GetSectionEntryValue(section, (char*)"Columns", value);
        cachedTilesetGroup.columns = atoi(value);

        int32_t numTiles = cachedTilesetGroup.rows * cachedTilesetGroup.columns;
        cachedTilesetGroup.tiles.reserve(numTiles);
        for (int groupTile = 0; groupTile < numTiles; groupTile++)
        {
            std::sprintf(entry, "Tile%i", groupTile);
            pTileset->m_pRes->GetSectionEntryValue(section, entry, value);
            cachedTilesetGroup.tiles.emplace_back(atoi(value));
        }

        cachedTileset.groups.emplace_back(cachedTilesetGroup);
    }

    cachedTileset.tiles.reserve(cachedTileset.numTiles);
    for (int32_t tile = 0; tile < cachedTileset.numTiles; tile++)
    {
        CachedTilesetTile cachedTilesetTile{};

        if (auto *pTileData = pTileset->GetTileData(tile))
        {
            cachedTilesetTile.tileModel = pTileData->GetModelResRef().GetResRefStr();
            cachedTilesetTile.minimapTexture = pTileData->GetMapIcon().GetResRefStr();
            cachedTilesetTile.tl = pTileData->m_sCornerTopLeft.CStr();
            cachedTilesetTile.t = pTileData->m_sEdgeTop.CStr();
            cachedTilesetTile.tr = pTileData->m_sCornerTopRight.CStr();
            cachedTilesetTile.r = pTileData->m_sEdgeRight.CStr();
            cachedTilesetTile.br = pTileData->m_sCornerBottomRight.CStr();
            cachedTilesetTile.b = pTileData->m_sEdgeBottom.CStr();
            cachedTilesetTile.bl = pTileData->m_sCornerBottomLeft.CStr();
            cachedTilesetTile.l = pTileData->m_sEdgeLeft.CStr();
            cachedTilesetTile.numDoors = pTileData->m_nNumDoors;

            cachedTilesetTile.doors.reserve(cachedTilesetTile.numDoors);
            for(int32_t door = 0; door < cachedTilesetTile.numDoors; door++)
            {
                CachedTilesetTileDoor cachedTilesetTileDoor{};
                std::sprintf(section, "TILE%iDOOR%i", tile, door);

                pTileset->m_pRes->GetSectionEntryValue(section, (char*)"Type", value);
                cachedTilesetTileDoor.type = atoi(value);
                pTileset->m_pRes->GetSectionEntryValue(section, (char*)"X", value);
                cachedTilesetTileDoor.position.x = atof(value);
                pTileset->m_pRes->GetSectionEntryValue(section, (char*)"Y", value);
                cachedTilesetTileDoor.position.y = atof(value);
                pTileset->m_pRes->GetSectionEntryValue(section, (char*)"Z", value);
                cachedTilesetTileDoor.position.z = atof(value);
                pTileset->m_pRes->GetSectionEntryValue(section, (char*)"Orientation", value);
                cachedTilesetTileDoor.orientation = atof(value);

                cachedTilesetTile.doors.emplace_back(cachedTilesetTileDoor);
            }
        }

        cachedTileset.tiles.emplace_back(cachedTilesetTile);
    }

    pTileset->m_pRes->Release();
    pTileset->m_pRes->Dump();

    auto it = s_CachedTilesets.emplace(tileset, cachedTileset);

    return it.second ? &it.first->second : nullptr;
}

NWNX_EXPORT ArgumentStack GetTilesetData(ArgumentStack&& args)
{
    const auto tileset = args.extract<std::string>();
      ASSERT_OR_THROW(!tileset.empty());

    if (auto *pCachedTileset = GetCachedTileset(tileset))
    {
        return {pCachedTileset->numTiles, pCachedTileset->heightTransition, pCachedTileset->numTerrains, pCachedTileset->numCrossers,
                pCachedTileset->numGroups, pCachedTileset->borderTerrain, pCachedTileset->defaultTerrain, pCachedTileset->floorTerrain,
                pCachedTileset->displayNameStrRef, pCachedTileset->unlocalizedName, pCachedTileset->isInterior, pCachedTileset->hasHeightTransition};
    }

    return {0, 0.0f, 0, 0, 0, "", "", "", 0, "", 0, 0};
}

NWNX_EXPORT ArgumentStack GetTilesetTerrain(ArgumentStack&& args)
{
    const auto tileset = args.extract<std::string>();
      ASSERT_OR_THROW(!tileset.empty());
    const auto terrainIndex = args.extract<int32_t>();
      ASSERT_OR_THROW(terrainIndex >= 0);

    if (auto *pCachedTileset = GetCachedTileset(tileset))
    {
        if (terrainIndex < pCachedTileset->numTerrains)
        {
            return pCachedTileset->terrains[terrainIndex];
        }
    }

    return "";
}

NWNX_EXPORT ArgumentStack GetTilesetCrosser(ArgumentStack&& args)
{
    const auto tileset = args.extract<std::string>();
      ASSERT_OR_THROW(!tileset.empty());
    const auto crosserIndex = args.extract<int32_t>();
      ASSERT_OR_THROW(crosserIndex >= 0);

    if (auto *pCachedTileset = GetCachedTileset(tileset))
    {
        if (crosserIndex < pCachedTileset->numCrossers)
        {
            return pCachedTileset->crossers[crosserIndex];
        }
    }

    return "";
}

NWNX_EXPORT ArgumentStack GetTilesetGroupData(ArgumentStack&& args)
{
    const auto tileset = args.extract<std::string>();
      ASSERT_OR_THROW(!tileset.empty());
    const auto groupIndex = args.extract<int32_t>();
      ASSERT_OR_THROW(groupIndex >= 0);

    if (auto *pCachedTileset = GetCachedTileset(tileset))
    {
        if (groupIndex < pCachedTileset->numGroups)
        {
            return {pCachedTileset->groups[groupIndex].name, pCachedTileset->groups[groupIndex].strRef,
                    pCachedTileset->groups[groupIndex].rows, pCachedTileset->groups[groupIndex].columns};
        }
    }

    return {"", 0, 0, 0};
}

NWNX_EXPORT ArgumentStack GetTilesetGroupTile(ArgumentStack&& args)
{
    const auto tileset = args.extract<std::string>();
      ASSERT_OR_THROW(!tileset.empty());
    const auto groupIndex = args.extract<int32_t>();
      ASSERT_OR_THROW(groupIndex >= 0);
    const auto tileIndex = args.extract<int32_t>();
      ASSERT_OR_THROW(tileIndex >= 0);

    if (auto *pCachedTileset = GetCachedTileset(tileset))
    {
        if (groupIndex < pCachedTileset->numGroups)
        {
            if ((size_t)tileIndex < pCachedTileset->groups[groupIndex].tiles.size())
            {
                return pCachedTileset->groups[groupIndex].tiles[tileIndex];
            }
        }
    }

    return 0;
}

NWNX_EXPORT ArgumentStack GetTileModel(ArgumentStack&& args)
{
    const auto tileset = args.extract<std::string>();
      ASSERT_OR_THROW(!tileset.empty());
    const auto tileId = args.extract<int32_t>();
      ASSERT_OR_THROW(tileId >= 0);

    if (auto *pCachedTileset = GetCachedTileset(tileset))
    {
        if (tileId < pCachedTileset->numTiles)
        {
            return pCachedTileset->tiles[tileId].tileModel;
        }
    }

    return "";
}

NWNX_EXPORT ArgumentStack GetTileMinimapTexture(ArgumentStack&& args)
{
    const auto tileset = args.extract<std::string>();
      ASSERT_OR_THROW(!tileset.empty());
    const auto tileId = args.extract<int32_t>();
      ASSERT_OR_THROW(tileId >= 0);

    if (auto *pCachedTileset = GetCachedTileset(tileset))
    {
        if (tileId < pCachedTileset->numTiles)
        {
            return pCachedTileset->tiles[tileId].minimapTexture;
        }
    }

    return "";
}

NWNX_EXPORT ArgumentStack GetTileEdgesAndCorners(ArgumentStack&& args)
{
    const auto tileset = args.extract<std::string>();
      ASSERT_OR_THROW(!tileset.empty());
    const auto tileId = args.extract<int32_t>();
      ASSERT_OR_THROW(tileId >= 0);

    if (auto *pCachedTileset = GetCachedTileset(tileset))
    {
        if (tileId < pCachedTileset->numTiles)
        {
            return {pCachedTileset->tiles[tileId].tl, pCachedTileset->tiles[tileId].t, pCachedTileset->tiles[tileId].tr,
                    pCachedTileset->tiles[tileId].r, pCachedTileset->tiles[tileId].br, pCachedTileset->tiles[tileId].b,
                    pCachedTileset->tiles[tileId].bl, pCachedTileset->tiles[tileId].l};
        }
    }

    return {"", "", "", "", "", "", "", ""};
}

NWNX_EXPORT ArgumentStack GetTileNumDoors(ArgumentStack&& args)
{
    const auto tileset = args.extract<std::string>();
      ASSERT_OR_THROW(!tileset.empty());
    const auto tileId = args.extract<int32_t>();
      ASSERT_OR_THROW(tileId >= 0);

    if (auto *pCachedTileset = GetCachedTileset(tileset))
    {
        if (tileId < pCachedTileset->numTiles)
        {
            return pCachedTileset->tiles[tileId].numDoors;
        }
    }

    return 0;
}

NWNX_EXPORT ArgumentStack GetTileDoorData(ArgumentStack&& args)
{
    const auto tileset = args.extract<std::string>();
      ASSERT_OR_THROW(!tileset.empty());
    const auto tileId = args.extract<int32_t>();
      ASSERT_OR_THROW(tileId >= 0);
    const auto doorIndex = args.extract<int32_t>();
      ASSERT_OR_THROW(doorIndex >= 0);

    if (auto *pCachedTileset = GetCachedTileset(tileset))
    {
        if (tileId < pCachedTileset->numTiles)
        {
            if (doorIndex < pCachedTileset->tiles[tileId].numDoors)
            {
                return {pCachedTileset->tiles[tileId].doors[doorIndex].type,
                        pCachedTileset->tiles[tileId].doors[doorIndex].position.x,
                        pCachedTileset->tiles[tileId].doors[doorIndex].position.y,
                        pCachedTileset->tiles[tileId].doors[doorIndex].position.z,
                        pCachedTileset->tiles[tileId].doors[doorIndex].orientation};
            }
        }
    }

    return {-1, 0.0f, 0.0f, 0.0f, 0.0f};
}

NWNX_EXPORT ArgumentStack SetAreaTileOverride(ArgumentStack&& args)
{
    const auto areaResref = args.extract<std::string>();
      ASSERT_OR_THROW(!areaResref.empty());
      ASSERT_OR_THROW(areaResref.size() <= 16);
    const auto overrideName = args.extract<std::string>();

    if (overrideName.empty())
        s_AreaTileOverrideMap.erase(areaResref);
    else
        s_AreaTileOverrideMap[areaResref] = overrideName;

    return {};
}

NWNX_EXPORT ArgumentStack CreateTileOverride(ArgumentStack&& args)
{
    const auto overrideName = args.extract<std::string>();
      ASSERT_OR_THROW(!overrideName.empty());
    const auto tileset = args.extract<std::string>();
      ASSERT_OR_THROW(!tileset.empty());
    const auto width = args.extract<int32_t>();
      ASSERT_OR_THROW(width >= 1);
      ASSERT_OR_THROW(width <= 32);
    const auto height = args.extract<int32_t>();
      ASSERT_OR_THROW(height >= 1);
      ASSERT_OR_THROW(height <= 32);

    s_TileOverrideMap[overrideName].tileset = tileset;
    s_TileOverrideMap[overrideName].width = width;
    s_TileOverrideMap[overrideName].height = height;

    return {};
}

NWNX_EXPORT ArgumentStack DeleteTileOverride(ArgumentStack&& args)
{
    const auto overrideName = args.extract<std::string>();
      ASSERT_OR_THROW(!overrideName.empty());

    s_TileOverrideMap.erase(overrideName);

    return {};
}

NWNX_EXPORT ArgumentStack SetOverrideTileData(ArgumentStack&& args)
{
    const auto overrideName = args.extract<std::string>();
      ASSERT_OR_THROW(!overrideName.empty());
    const auto tile = args.extract<int32_t>();
      ASSERT_OR_THROW(tile >= 0);
    const auto id = args.extract<int32_t>();
      ASSERT_OR_THROW(id >= 0);
    const auto orientation = args.extract<int32_t>();
      ASSERT_OR_THROW(orientation >= 0);
      ASSERT_OR_THROW(orientation <= 3);
    const auto height = args.extract<int32_t>();
      ASSERT_OR_THROW(height >= 0);
    const auto mainLightColor1 = args.extract<int32_t>();
      ASSERT_OR_THROW(mainLightColor1 >= 0);
      ASSERT_OR_THROW(mainLightColor1 < 256);
    const auto mainLightColor2 = args.extract<int32_t>();
      ASSERT_OR_THROW(mainLightColor2 >= 0);
      ASSERT_OR_THROW(mainLightColor2 < 256);
    const auto sourceLightColor1 = args.extract<int32_t>();
      ASSERT_OR_THROW(sourceLightColor1 >= 0);
      ASSERT_OR_THROW(sourceLightColor1 < 256);
    const auto sourceLightColor2 = args.extract<int32_t>();
      ASSERT_OR_THROW(sourceLightColor2 >= 0);
      ASSERT_OR_THROW(sourceLightColor2 < 256);
    const auto animLoop1 = !!args.extract<int32_t>();
    const auto animLoop2 = !!args.extract<int32_t>();
    const auto animLoop3 = !!args.extract<int32_t>();

    auto tileOverride = s_TileOverrideMap.find(overrideName);

    if (tileOverride != s_TileOverrideMap.end())
    {
        tileOverride->second.tileData[tile].id = id;
        tileOverride->second.tileData[tile].orientation = orientation;
        tileOverride->second.tileData[tile].height = height;
        tileOverride->second.tileData[tile].mainLightColor1 = mainLightColor1;
        tileOverride->second.tileData[tile].mainLightColor2 = mainLightColor2;
        tileOverride->second.tileData[tile].sourceLightColor1 = sourceLightColor1;
        tileOverride->second.tileData[tile].sourceLightColor2 = sourceLightColor2;
        tileOverride->second.tileData[tile].animLoop1 = animLoop1;
        tileOverride->second.tileData[tile].animLoop2 = animLoop2;
        tileOverride->second.tileData[tile].animLoop3 = animLoop3;
    }
    else
        LOG_WARNING("SetOverrideTileData: Tile Override with name '%s' does not exist.", overrideName);

    return {};
}

NWNX_EXPORT ArgumentStack DeleteOverrideTileData(ArgumentStack&& args)
{
    const auto overrideName = args.extract<std::string>();
      ASSERT_OR_THROW(!overrideName.empty());
    const auto tile = args.extract<int32_t>();

    auto tileOverride = s_TileOverrideMap.find(overrideName);

    if (tileOverride != s_TileOverrideMap.end())
    {
        if (tile < 0)
            tileOverride->second.tileData.clear();
        else
            tileOverride->second.tileData.erase(tile);
    }

    return {};
}
