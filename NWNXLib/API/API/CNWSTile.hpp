#pragma once
#include "nwn_api.hpp"

#include "CExoArrayList.hpp"
#include "CNWTile.hpp"
#include "CResRef.hpp"
#include "Vector.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CNWSTile)
#endif

struct CNWArea;
struct CNWTileData;
struct CPathfindInformation;


typedef int BOOL;
typedef uint32_t OBJECT_ID;


struct CNWSTile : CNWTile
{
    CNWTileData * m_pTileData;
    int32_t m_nTriggers;
    int32_t m_nTriggerSize;
    OBJECT_ID * m_poidTriggers;
    CExoArrayList<OBJECT_ID> m_aDoors;
    BOOL m_bMainLightColorChange;
    BOOL m_bSourceLightColorChange;
    BOOL m_bFlaggedAsProblem;

    CNWSTile();
    ~CNWSTile();
    void AddTrigger(OBJECT_ID oidTrigger);
    BOOL ClearLineOfSight(int32_t nDirectionHeuristic, Vector vSource, Vector vTarget, Vector * vImpact);
    int32_t ClippedLineSegmentWalkable(float fStartX, float fStartY, float fEndX, float fEndY, float * fClipStartX, float * fClipStartY, float * fClipEndX, float * fClipEndY, float * fClipMinZ, float * fClipMaxZ);
    int32_t ComputeClippedLineSegment(Vector vSource, Vector vTarget, Vector * vClipSource, Vector * vClipTarget);
    float ComputeHeight(Vector vPosition);
    int32_t FindClosestRegion(float fX, float fY);
    int32_t GetExit(int32_t nExit, float * fX, float * fY, int32_t * nRegion);
    int32_t GetExitNumber(float fX, float fY);
    int32_t GetRegionCoords(int32_t nRegion, float * fX, float * fY);
    int32_t GetRegionEntrance(float fX, float fY);
    int32_t GetSurfaceMaterial(Vector vPosition);
    CNWTileData * GetTileData();
    int32_t GetTotalExits();
    int32_t IntersectLineSegments(float fX1, float fY1, float fX2, float fY2, float fX3, float fY3, float fX4, float fY4, float * fXIntersect, float * fYIntersect);
    BOOL InTrigger(Vector vPosition, CExoArrayList<OBJECT_ID> * aTriggers);
    CResRef GetWalkMesh();
    BOOL LoadWalkMesh();
    int32_t NoNonWalkPolysOnTile(float fSourceX, float fSourceY, float fTargetX, float fTargetY, float fMinZ, float fMaxZ, float fPersonalSpace, BOOL bTestSinglePoint = false);
    uint32_t PlotIntraTilePath(CNWArea * pWalkGeometry, CPathfindInformation * pPathfindInformation, float fCurrentIntraTileX, float fCurrentIntraTileY, float fInterTileStartX, float fInterTileStartY, uint32_t nMaxTimeAllowed);
    void SetTileData(CNWTileData * pTileData);
    virtual void SetMainLightColor(uint8_t nMainLight1Color, uint8_t nMainLight2Color);
    virtual void SetSourceLightColor(uint8_t nSourceLight1Color, uint8_t nSourceLight2Color);


#ifdef NWN_CLASS_EXTENSION_CNWSTile
    NWN_CLASS_EXTENSION_CNWSTile
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CNWSTile)
#endif

