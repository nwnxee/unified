#pragma once
#include "nwn_api.hpp"

#include "CExoString.hpp"
#include "CResHelper.hpp"
#include "CResRef.hpp"
#include "CResSET.hpp"
#include "Vector.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CNWTileSet)
#endif

struct CNWTileData;


typedef int BOOL;


struct CNWTileSet : CResHelper<CResSET, 2013>
{
    CResRef m_resrefName;
    CResRef m_cEnvMap;
    float m_fHeightTransition;
    int32_t m_nProperty;
    int32_t m_nNumTileData;
    int32_t m_nCurrentTileData;
    CNWTileData * m_pTileData;
    BOOL m_bHasGrass;
    float m_fGrassDensity;
    float m_fGrassHeight;
    Vector m_vGrassAmbientColor;
    Vector m_vGrassDiffuseColor;
    CExoString m_sGrassTexture;

    CNWTileSet(CResRef cResRef, BOOL bSetAutoRequest);
    virtual ~CNWTileSet();
    CExoString GetCornerType(int32_t nTile, uint8_t nCorner, uint8_t nOrientation = 0);
    CExoString GetEdgeType(int32_t nTile, uint8_t nEdge, uint8_t nOrientation = 0);
    float GetHeightTransition();
    CResRef GetEnvMapResRef();
    CNWTileData * GetTileData(int32_t nID);
    BOOL LoadTileSet();
    void UnloadTileSet();


#ifdef NWN_CLASS_EXTENSION_CNWTileSet
    NWN_CLASS_EXTENSION_CNWTileSet
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CNWTileSet)
#endif

