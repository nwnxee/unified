#pragma once
#include "nwn_api.hpp"

#include "CResRef.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CNWTileSetManager)
#endif

struct CNWTilePathNode;
struct CNWTileSet;




struct CNWTileSetManager
{
    std::unordered_map<std::string, std::unique_ptr<CNWTileSet>> m_tileSets;
    CNWTilePathNode * m_apTileNodes[50][4];
    BOOL m_bSkipClearTilesets;

    CNWTileSetManager();
    ~CNWTileSetManager();
    CNWTileSet * GetTileSet(const CResRef &resrefTileSet);
    void ClearTileSets(const CResRef &currentTileSet);
    void InitializeTilePathNodes();
    void ClearTilePathNodes();
    CNWTilePathNode * GetTilePathNode(uint8_t nNodeType, uint8_t nRotation);
    void ComputePathNodeInformation(uint8_t nPathNode, int32_t nPathNodeOrientation, int32_t & nRegionNodes, int32_t & nTileExits, float * * pfRegionNodes, float * * pfTileExits, int32_t * * pnTileExitRegion);
    void ComputePathNodeRotation(int32_t nOrientation, float * fX, float * fY);


#ifdef NWN_CLASS_EXTENSION_CNWTileSetManager
    NWN_CLASS_EXTENSION_CNWTileSetManager
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CNWTileSetManager)
#endif

