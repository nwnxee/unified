#pragma once
#include "nwn_api.hpp"

#include "CResRef.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CNWTileSetManager)
#endif

class CNWTilePathNode;
class CNWTileSet;




class CNWTileSetManager
{
public:
    CNWTileSet * m_apTileSets[100];
    int32_t m_anTileSetRegistered[100];
    CNWTilePathNode * m_apTileNodes[50][4];

    CNWTileSetManager();
    ~CNWTileSetManager();
    CNWTileSet * RegisterTileSet(CResRef resrefTileSet);
    void UnregisterTileSet(CNWTileSet * pTileSet);
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

