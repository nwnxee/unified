#include "Tileset.hpp"

#include "API/CResStruct.hpp"
#include "API/CNWSArea.hpp"
#include "API/CNWTileSetManager.hpp"
#include "API/CNWTileSet.hpp"
#include "API/CNWSTile.hpp"
#include "API/CNWTileData.hpp"
#include "API/CAppManager.hpp"

using namespace NWNXLib;
using namespace NWNXLib::API;

static Tileset::Tileset* g_plugin;

NWNX_PLUGIN_ENTRY Plugin* PluginLoad(Services::ProxyServiceList* services)
{
    g_plugin = new Tileset::Tileset(services);
    return g_plugin;
}


namespace Tileset {

static NWNXLib::Hooking::FunctionHook* s_LoadTileSetInfoHook = nullptr;

Tileset::Tileset(Services::ProxyServiceList* services)
    : Plugin(services)
{
#define REGISTER(func)              \
    GetServices()->m_events->RegisterEvent(#func, \
        [this](ArgumentStack&& args){ return func(std::move(args)); })

    REGISTER(GetTilesetData);
    REGISTER(GetTilesetTerrain);
    REGISTER(GetTilesetCrosser);
    REGISTER(GetTilesetGroupData);
    REGISTER(GetTilesetGroupTile);
    REGISTER(GetTileModel);
    REGISTER(GetTileMinimapTexture);
    REGISTER(GetTileEdgesAndCorners);
    REGISTER(GetTileNumDoors);
    REGISTER(GetTileDoorData);
    REGISTER(SetAreaTileOverride);
    REGISTER(CreateTileOverride);
    REGISTER(DeleteTileOverride);
    REGISTER(SetOverrideTileData);
    REGISTER(DeleteOverrideTileData);

#undef REGISTER

    s_LoadTileSetInfoHook = GetServices()->m_hooks->RequestExclusiveHook
            <API::Functions::_ZN8CNWSArea15LoadTileSetInfoEP10CResStruct>(&LoadTileSetInfoHook);
}

int32_t Tileset::LoadTileSetInfoHook(CNWSArea *pArea, CResStruct *pStruct)
{
    auto areaTileOverride = g_plugin->m_AreaTileOverrideMap.find(pArea->m_cResRef.GetResRefStr());

    if (areaTileOverride != g_plugin->m_AreaTileOverrideMap.end())
    {
        auto tileOverride = g_plugin->m_TileOverrideMap.find(areaTileOverride->second);

        if (tileOverride != g_plugin->m_TileOverrideMap.end())
        {
            if (!tileOverride->second.height || !tileOverride->second.width || tileOverride->second.tileset.empty())
            {
                LOG_WARNING("Invalid Tile Override Data: height or width are 0 or tileset is empty in override '%s'. Loading original tiles for area: '%s'",
                            areaTileOverride->second, pArea->m_cResRef.GetResRefStr());
                return s_LoadTileSetInfoHook->CallOriginal<int32_t>(pArea, pStruct);
            }

            pArea->m_nHeight = tileOverride->second.height;
            pArea->m_nWidth = tileOverride->second.width;
            pArea->m_refTileSet = tileOverride->second.tileset;
            pArea->m_pTileSet = Globals::AppManager()->m_pNWTileSetManager->RegisterTileSet(CResRef(tileOverride->second.tileset));

            if (!pArea->m_pTileSet)
            {
                LOG_WARNING("Invalid Tile Override Data: could not load tileset '%s' in override '%s'. Loading original tiles for area: '%s'",
                            tileOverride->second.tileset, areaTileOverride->second, pArea->m_cResRef.GetResRefStr());
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

    return s_LoadTileSetInfoHook->CallOriginal<int32_t>(pArea, pStruct);
}

ArgumentStack Tileset::GetTilesetData(ArgumentStack&& args)
{
    int32_t numTiles = 0, numTerrain = 0, numCrossers = 0, numGroups = 0, displayNameStrRef = -1, isInterior = 0, hasHeightTransition = 0;
    float heightTransition = 0.0f;
    std::string borderTerrain, defaultTerrain, floorTerrain, unlocalizedName;

    const auto tileset = Services::Events::ExtractArgument<std::string>(args);
      ASSERT_OR_THROW(!tileset.empty());

    if (auto *pTileSet = Globals::AppManager()->m_pNWTileSetManager->RegisterTileSet(CResRef(tileset)))
    {
        numTiles = pTileSet->m_nNumTileData;
        heightTransition = pTileSet->GetHeightTransition();

        if (pTileSet->m_pRes->Demand())
        {
            char section[24];
            char entry[24];
            char value[64];

            std::sprintf(section, "TERRAIN TYPES");
            std::sprintf(entry, "Count");
            pTileSet->m_pRes->GetSectionEntryValue(section, entry, value);
            numTerrain = std::strtol(value, nullptr, 0);

            std::sprintf(section, "CROSSER TYPES");
            std::sprintf(entry, "Count");
            pTileSet->m_pRes->GetSectionEntryValue(section, entry, value);
            numCrossers = std::strtol(value, nullptr, 0);

            std::sprintf(section, "GROUPS");
            std::sprintf(entry, "Count");
            pTileSet->m_pRes->GetSectionEntryValue(section, entry, value);
            numGroups = std::strtol(value, nullptr, 0);

            std::sprintf(section, "GENERAL");
            std::sprintf(entry, "Interior");
            pTileSet->m_pRes->GetSectionEntryValue(section, entry, value);
            isInterior = std::strtol(value, nullptr, 0);

            std::sprintf(entry, "DisplayName");
            pTileSet->m_pRes->GetSectionEntryValue(section, entry, value);
            displayNameStrRef = std::strtol(value, nullptr, 0);

            std::sprintf(entry, "UnlocalizedName");
            pTileSet->m_pRes->GetSectionEntryValue(section, entry, value);
            unlocalizedName = value;

            std::sprintf(entry, "Border");
            pTileSet->m_pRes->GetSectionEntryValue(section, entry, value);
            borderTerrain = value;

            std::sprintf(entry, "Default");
            pTileSet->m_pRes->GetSectionEntryValue(section, entry, value);
            defaultTerrain = value;

            std::sprintf(entry, "Floor");
            pTileSet->m_pRes->GetSectionEntryValue(section, entry, value);
            floorTerrain = value;

            std::sprintf(entry, "HasHeightTransition");
            pTileSet->m_pRes->GetSectionEntryValue(section, entry, value);
            hasHeightTransition = std::strtol(value, nullptr, 0);

            pTileSet->m_pRes->Release();
            pTileSet->m_pRes->Dump();
        }
    }
    else
        LOG_WARNING("GetTilesetData: Failed to Register Tileset: %s", tileset);

    return Services::Events::Arguments(numTiles, heightTransition, numTerrain, numCrossers, numGroups, borderTerrain,
                                       defaultTerrain, floorTerrain, displayNameStrRef, unlocalizedName, isInterior,
                                       hasHeightTransition);
}

ArgumentStack Tileset::GetTilesetTerrain(ArgumentStack&& args)
{
    std::string retVal;

    const auto tileset = Services::Events::ExtractArgument<std::string>(args);
      ASSERT_OR_THROW(!tileset.empty());
    const auto terrainIndex = Services::Events::ExtractArgument<int32_t>(args);
      ASSERT_OR_THROW(terrainIndex >= 0);

    if (auto *pTileSet = Globals::AppManager()->m_pNWTileSetManager->RegisterTileSet(CResRef(tileset)))
    {
        if (pTileSet->m_pRes->Demand())
        {
            char section[24];
            char entry[16];
            char value[64];

            std::sprintf(section, "TERRAIN TYPES");
            std::sprintf(entry, "Count");
            pTileSet->m_pRes->GetSectionEntryValue(section, entry, value);
            int32_t numTerrain = std::strtol(value, nullptr, 0);

            if (terrainIndex < numTerrain)
            {
                std::sprintf(section, "TERRAIN%i", terrainIndex);
                std::sprintf(entry, "Name");
                pTileSet->m_pRes->GetSectionEntryValue(section, entry, value);

                retVal = value;
            }

            pTileSet->m_pRes->Release();
            pTileSet->m_pRes->Dump();
        }
    }
    else
        LOG_WARNING("GetTilesetTerrain: Failed to Register Tileset: %s", tileset);

    return Services::Events::Arguments(retVal);
}

ArgumentStack Tileset::GetTilesetCrosser(ArgumentStack&& args)
{
    std::string retVal;

    const auto tileset = Services::Events::ExtractArgument<std::string>(args);
      ASSERT_OR_THROW(!tileset.empty());
    const auto crosserIndex = Services::Events::ExtractArgument<int32_t>(args);
      ASSERT_OR_THROW(crosserIndex >= 0);

    if (auto *pTileSet = Globals::AppManager()->m_pNWTileSetManager->RegisterTileSet(CResRef(tileset)))
    {
        if (pTileSet->m_pRes->Demand())
        {
            char section[24];
            char entry[16];
            char value[64];

            std::sprintf(section, "CROSSER TYPES");
            std::sprintf(entry, "Count");
            pTileSet->m_pRes->GetSectionEntryValue(section, entry, value);
            int32_t numCrossers = std::strtol(value, nullptr, 0);

            if (crosserIndex < numCrossers)
            {
                std::sprintf(section, "CROSSER%i", crosserIndex);
                std::sprintf(entry, "Name");
                pTileSet->m_pRes->GetSectionEntryValue(section, entry, value);

                retVal = value;
            }

            pTileSet->m_pRes->Release();
            pTileSet->m_pRes->Dump();
        }
    }
    else
        LOG_WARNING("GetTilesetCrosser: Failed to Register Tileset: %s", tileset);

    return Services::Events::Arguments(retVal);
}

ArgumentStack Tileset::GetTilesetGroupData(ArgumentStack&& args)
{
    const auto tileset = Services::Events::ExtractArgument<std::string>(args);
      ASSERT_OR_THROW(!tileset.empty());
    const auto groupIndex = Services::Events::ExtractArgument<int32_t>(args);
      ASSERT_OR_THROW(groupIndex >= 0);

    std::string name;
    int32_t strRef = 0, rows = 0, columns = 0;

    if (auto *pTileSet = Globals::AppManager()->m_pNWTileSetManager->RegisterTileSet(CResRef(tileset)))
    {
        if (pTileSet->m_pRes->Demand())
        {
            char section[24];
            char entry[16];
            char value[64];
            std::sprintf(section, "GROUP%i", groupIndex);

            std::sprintf(entry, "Name");
            pTileSet->m_pRes->GetSectionEntryValue(section, entry, value);
            name = value;

            std::sprintf(entry, "StrRef");
            pTileSet->m_pRes->GetSectionEntryValue(section, entry, value);
            strRef = std::strtof(value, nullptr);

            std::sprintf(entry, "Rows");
            pTileSet->m_pRes->GetSectionEntryValue(section, entry, value);
            rows = std::strtof(value, nullptr);

            std::sprintf(entry, "Columns");
            pTileSet->m_pRes->GetSectionEntryValue(section, entry, value);
            columns = std::strtof(value, nullptr);

            int32_t numTiles = rows * columns;
            m_GroupTilesVector.clear();
            m_GroupTilesVector.reserve(numTiles);

            for (int tile = 0; tile < numTiles; tile++)
            {
                std::sprintf(entry, "Tile%i", tile);
                pTileSet->m_pRes->GetSectionEntryValue(section, entry, value);
                int32_t tileId = std::strtof(value, nullptr);

                m_GroupTilesVector.emplace_back(tileId);
            }

            pTileSet->m_pRes->Release();
            pTileSet->m_pRes->Dump();
        }
    }
    else
        LOG_WARNING("GetTilesetGroupData: Failed to Register Tileset: %s", tileset);

    return Services::Events::Arguments(name, strRef, rows, columns);
}

ArgumentStack Tileset::GetTilesetGroupTile(ArgumentStack&& args)
{
    int32_t retVal = 0;
    const auto tileIndex = Services::Events::ExtractArgument<int32_t>(args);
      ASSERT_OR_THROW(tileIndex >= 0);

    if ((size_t)tileIndex < m_GroupTilesVector.size())
    {
        retVal = m_GroupTilesVector[tileIndex];
    }

    return Services::Events::Arguments(retVal);
}

ArgumentStack Tileset::GetTileModel(ArgumentStack&& args)
{
    std::string retVal;
    const auto tileset = Services::Events::ExtractArgument<std::string>(args);
      ASSERT_OR_THROW(!tileset.empty());
    const auto tileId = Services::Events::ExtractArgument<int32_t>(args);
      ASSERT_OR_THROW(tileId >= 0);

    if (auto *pTileSet = Globals::AppManager()->m_pNWTileSetManager->RegisterTileSet(CResRef(tileset)))
    {
        if (auto *pTileData = pTileSet->GetTileData(tileId))
        {
            retVal = pTileData->GetModelResRef().GetResRefStr();
        }
    }
    else
        LOG_WARNING("GetTileModel: Failed to Register Tileset: %s", tileset);

    return Services::Events::Arguments(retVal);
}

ArgumentStack Tileset::GetTileMinimapTexture(ArgumentStack&& args)
{
    std::string retVal;
    const auto tileset = Services::Events::ExtractArgument<std::string>(args);
      ASSERT_OR_THROW(!tileset.empty());
    const auto tileId = Services::Events::ExtractArgument<int32_t>(args);
      ASSERT_OR_THROW(tileId >= 0);

    if (auto *pTileSet = Globals::AppManager()->m_pNWTileSetManager->RegisterTileSet(CResRef(tileset)))
    {
        if (auto *pTileData = pTileSet->GetTileData(tileId))
        {
            retVal = pTileData->GetMapIcon().GetResRefStr();
        }
    }
    else
        LOG_WARNING("GetTileMinimapTexture: Failed to Register Tileset: %s", tileset);

    return Services::Events::Arguments(retVal);
}

ArgumentStack Tileset::GetTileEdgesAndCorners(ArgumentStack&& args)
{
    const auto tileset = Services::Events::ExtractArgument<std::string>(args);
      ASSERT_OR_THROW(!tileset.empty());
    const auto tileId = Services::Events::ExtractArgument<int32_t>(args);
      ASSERT_OR_THROW(tileId >= 0);

    std::string tl, t, tr, r, br, b, bl, l;

    if (auto *pTileSet = Globals::AppManager()->m_pNWTileSetManager->RegisterTileSet(CResRef(tileset)))
    {
        if (auto *pTileData = pTileSet->GetTileData(tileId))
        {
            tl = pTileData->m_sCornerTopLeft.CStr();
            t = pTileData->m_sEdgeTop.CStr();
            tr = pTileData->m_sCornerTopRight.CStr();
            r = pTileData->m_sEdgeRight.CStr();
            br = pTileData->m_sCornerBottomRight.CStr();
            b = pTileData->m_sEdgeBottom.CStr();
            bl = pTileData->m_sCornerBottomLeft.CStr();
            l = pTileData->m_sEdgeLeft.CStr();
        }
    }
    else
        LOG_WARNING("GetTileEdgesAndCorners: Failed to Register Tileset: %s", tileset);

    return Services::Events::Arguments(tl, t, tr, r, br, b, bl, l);
}

ArgumentStack Tileset::GetTileNumDoors(ArgumentStack&& args)
{
    int32_t retVal = 0;
    const auto tileset = Services::Events::ExtractArgument<std::string>(args);
      ASSERT_OR_THROW(!tileset.empty());
    const auto tileId = Services::Events::ExtractArgument<int32_t>(args);
      ASSERT_OR_THROW(tileId >= 0);

    if (auto *pTileSet = Globals::AppManager()->m_pNWTileSetManager->RegisterTileSet(CResRef(tileset)))
    {
        if (auto *pTileData = pTileSet->GetTileData(tileId))
        {
            retVal = pTileData->m_nNumDoors;
        }
    }
    else
        LOG_WARNING("GetTileNumDoors: Failed to Register Tileset: %s", tileset);

    return Services::Events::Arguments(retVal);
}

ArgumentStack Tileset::GetTileDoorData(ArgumentStack&& args)
{
    const auto tileset = Services::Events::ExtractArgument<std::string>(args);
      ASSERT_OR_THROW(!tileset.empty());
    const auto tileId = Services::Events::ExtractArgument<int32_t>(args);
      ASSERT_OR_THROW(tileId >= 0);
    const auto doorIndex = Services::Events::ExtractArgument<int32_t>(args);
      ASSERT_OR_THROW(doorIndex >= 0);

    int32_t type = -1;
    float x = 0.0f, y = 0.0f, z = 0.0f, orientation = 0.0f;

    if (auto *pTileSet = Globals::AppManager()->m_pNWTileSetManager->RegisterTileSet(CResRef(tileset)))
    {
        if (auto *pTileData = pTileSet->GetTileData(tileId))
        {
            if (doorIndex < pTileData->m_nNumDoors)
            {
                if (pTileSet->m_pRes->Demand())
                {
                    char section[24];
                    char entry[16];
                    char value[64];
                    std::sprintf(section, "TILE%iDOOR%i", tileId, doorIndex);

                    std::sprintf(entry, "Type");
                    pTileSet->m_pRes->GetSectionEntryValue(section, entry, value);
                    type = std::strtol(value, nullptr, 0);

                    std::sprintf(entry, "X");
                    pTileSet->m_pRes->GetSectionEntryValue(section, entry, value);
                    x = std::strtof(value, nullptr);

                    std::sprintf(entry, "Y");
                    pTileSet->m_pRes->GetSectionEntryValue(section, entry, value);
                    y = std::strtof(value, nullptr);

                    std::sprintf(entry, "Z");
                    pTileSet->m_pRes->GetSectionEntryValue(section, entry, value);
                    z = std::strtof(value, nullptr);

                    std::sprintf(entry, "Orientation");
                    pTileSet->m_pRes->GetSectionEntryValue(section, entry, value);
                    orientation = std::strtof(value, nullptr);

                    pTileSet->m_pRes->Release();
                    pTileSet->m_pRes->Dump();
                }
            }
        }
    }
    else
        LOG_WARNING("GetTileDoorData: Failed to Register Tileset: %s", tileset);

    return Services::Events::Arguments(type, x, y, z, orientation);
}

ArgumentStack Tileset::SetAreaTileOverride(ArgumentStack&& args)
{
    const auto areaResref = Services::Events::ExtractArgument<std::string>(args);
      ASSERT_OR_THROW(!areaResref.empty());
      ASSERT_OR_THROW(areaResref.size() <= 16);
    const auto overrideName = Services::Events::ExtractArgument<std::string>(args);

    if (overrideName.empty())
        m_AreaTileOverrideMap.erase(areaResref);
    else
        m_AreaTileOverrideMap[areaResref] = overrideName;

    return Services::Events::Arguments();
}

ArgumentStack Tileset::CreateTileOverride(ArgumentStack&& args)
{
    const auto overrideName = Services::Events::ExtractArgument<std::string>(args);
      ASSERT_OR_THROW(!overrideName.empty());
    const auto tileset = Services::Events::ExtractArgument<std::string>(args);
      ASSERT_OR_THROW(!tileset.empty());
    const auto width = Services::Events::ExtractArgument<int32_t>(args);
      ASSERT_OR_THROW(width >= 1);
      ASSERT_OR_THROW(width <= 32);
    const auto height = Services::Events::ExtractArgument<int32_t>(args);
      ASSERT_OR_THROW(height >= 1);
      ASSERT_OR_THROW(height <= 32);

    m_TileOverrideMap[overrideName].tileset = tileset;
    m_TileOverrideMap[overrideName].width = width;
    m_TileOverrideMap[overrideName].height = height;

    return Services::Events::Arguments();
}

ArgumentStack Tileset::DeleteTileOverride(ArgumentStack&& args)
{
    const auto overrideName = Services::Events::ExtractArgument<std::string>(args);
      ASSERT_OR_THROW(!overrideName.empty());

    m_TileOverrideMap.erase(overrideName);

    return Services::Events::Arguments();
}

ArgumentStack Tileset::SetOverrideTileData(ArgumentStack&& args)
{
    const auto overrideName = Services::Events::ExtractArgument<std::string>(args);
      ASSERT_OR_THROW(!overrideName.empty());
    const auto tile = Services::Events::ExtractArgument<int32_t>(args);
      ASSERT_OR_THROW(tile >= 0);
    const auto id = Services::Events::ExtractArgument<int32_t>(args);
      ASSERT_OR_THROW(id >= 0);
    const auto orientation = Services::Events::ExtractArgument<int32_t>(args);
      ASSERT_OR_THROW(orientation >= 0);
      ASSERT_OR_THROW(orientation <= 3);
    const auto height = Services::Events::ExtractArgument<int32_t>(args);
      ASSERT_OR_THROW(height >= 0);
    const auto mainLightColor1 = Services::Events::ExtractArgument<int32_t>(args);
      ASSERT_OR_THROW(mainLightColor1 >= 0);
      ASSERT_OR_THROW(mainLightColor1 < 256);
    const auto mainLightColor2 = Services::Events::ExtractArgument<int32_t>(args);
      ASSERT_OR_THROW(mainLightColor2 >= 0);
      ASSERT_OR_THROW(mainLightColor2 < 256);
    const auto sourceLightColor1 = Services::Events::ExtractArgument<int32_t>(args);
      ASSERT_OR_THROW(sourceLightColor1 >= 0);
      ASSERT_OR_THROW(sourceLightColor1 < 256);
    const auto sourceLightColor2 = Services::Events::ExtractArgument<int32_t>(args);
      ASSERT_OR_THROW(sourceLightColor2 >= 0);
      ASSERT_OR_THROW(sourceLightColor2 < 256);
    const auto animLoop1 = !!Services::Events::ExtractArgument<int32_t>(args);
    const auto animLoop2 = !!Services::Events::ExtractArgument<int32_t>(args);
    const auto animLoop3 = !!Services::Events::ExtractArgument<int32_t>(args);

    auto tileOverride = m_TileOverrideMap.find(overrideName);

    if (tileOverride != m_TileOverrideMap.end())
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

    return Services::Events::Arguments();
}

ArgumentStack Tileset::DeleteOverrideTileData(ArgumentStack&& args)
{
    const auto overrideName = Services::Events::ExtractArgument<std::string>(args);
      ASSERT_OR_THROW(!overrideName.empty());
    const auto tile = Services::Events::ExtractArgument<int32_t>(args);

    auto tileOverride = m_TileOverrideMap.find(overrideName);

    if (tileOverride != m_TileOverrideMap.end())
    {
        if (tile < 0)
            tileOverride->second.tileData.clear();
        else
            tileOverride->second.tileData.erase(tile);
    }

    return Services::Events::Arguments();
}

}
