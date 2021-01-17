#pragma once
#include "nwn_api.hpp"

#include "CNWTileSurfaceMeshLocalInfo.hpp"
#include "CResHelper.hpp"
#include "CResRef.hpp"
#include "CResWOK.hpp"
#include "Vector.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CNWTileSurfaceMesh)
#endif

struct CNWArea;
struct CNWTile;
struct CNWTileSurfaceMeshAABBNode;
struct CNWTileSurfaceMeshHashTableEntry;
struct CPathfindInfoIntraTileSuccessors;
struct CPathfindInformation;


typedef int BOOL;


struct CNWTileSurfaceMesh : CResHelper<CResWOK, 2016>
{
    CResRef m_cWalkMesh;
    uint8_t m_nPathNode;
    int32_t m_nPathNodeOrientation;
    uint8_t m_nVisibilityNode;
    int32_t m_nVisibilityNodeOrientation;
    uint8_t m_nDoorVisNode;
    int32_t m_nDoorVisNodeOrientation;
    int32_t m_nTileConnectivity;
    int32_t m_nVertices;
    int32_t m_nVerticesLayer1;
    int32_t m_nVerticesLayer2;
    int32_t m_nVerticesLayer3;
    int32_t m_nTriangles;
    int32_t m_nTrianglesLayer1;
    int32_t m_nTrianglesLayer2;
    int32_t m_nTrianglesLayer3;
    int32_t * m_pnTriangles;
    int32_t * m_pnTrianglesLayer1;
    int32_t * m_pnTrianglesLayer2;
    int32_t * m_pnTrianglesLayer3;
    int32_t * m_pnTriangleMaterial;
    float * m_pfTriangleDistances;
    Vector * m_pvTriangleNormals;
    int32_t * m_pnTAdjacency;
    int32_t * m_pnTAdjacencyLayer1;
    int32_t * m_pnTAdjacencyLayer2;
    int32_t * m_pnTAdjacencyLayer3;
    float * m_pfVertices;
    float * m_pfVerticesLayer1;
    float * m_pfVerticesLayer2;
    float * m_pfVerticesLayer3;
    int32_t m_nDeniedVertices;
    float * m_pfDeniedVertices;
    int32_t m_nDeniedTriangles;
    int32_t * m_pnDeniedTriangles;
    int32_t * m_pnDeniedTriangleMaterial;
    float * m_pfDeniedTriangleDistances;
    Vector * m_pvDeniedTriangleNormals;
    CNWTileSurfaceMeshAABBNode * m_pAABBTree;
    float m_fGoalTargetX;
    float m_fGoalMinX;
    float m_fGoalMaxX;
    float m_fGoalTargetY;
    float m_fGoalMinY;
    float m_fGoalMaxY;
    int32_t m_nGoalTargetTriangle;
    float m_fGoalMaximumDistance;
    int32_t m_nIntraTileWPLength;
    float * m_pfIntraTileWayPoints;
    int32_t m_nIntraTileTriangles;
    int32_t * m_pnIntraTileTriangle;
    int32_t m_nIntraTileUnits;
    int32_t m_nMaxIntraTileUnits;
    float m_fMinEstimateToGoal;
    CNWTileSurfaceMeshHashTableEntry * m_pcIntraTileHashTable;
    CNWTileSurfaceMeshLocalInfo m_pcIntraTileGenSuccessorsLocalInfo;

    CNWTileSurfaceMesh();
    ~CNWTileSurfaceMesh();
    void ClearSubdivision();
    int32_t CheckAABBNode(int32_t nDirectionHeuristic, CNWTileSurfaceMeshAABBNode * pAABBNode, const Vector & v0, Vector & v1_aor_impact);
    int32_t CheckAABBNodeOneWay(int32_t nDirectionHeuristic, CNWTileSurfaceMeshAABBNode * pAABBNode, const Vector & v0, Vector & v1_aor_impact);
    int32_t ClippedLineSegmentWalkable(CNWTile * pTile, float fStartX, float fStartY, float fEndX, float fEndY, float * fClipStartX, float * fClipStartY, float * fClipEndX, float * fClipEndY, float * fClipMinZ, float * fClipMaxZ);
    int32_t ComputeClippedLineSegment(CNWTile * pTile, float fStartX, float fStartY, float fEndX, float fEndY, float * fClipStartX, float * fClipStartY, float * fClipEndX, float * fClipEndY);
    float ComputeHeight(Vector vPosition);
    void ComputePathNodes();
    void ComputeTriangleAdjacency();
    float EstimateDistanceToTarget(float fX, float fY);
    int32_t FindClosestRegion(CNWTile * pTile, float fX, float fY, uint8_t nPathNode = 0, int32_t nOrientation = 0);
    int32_t FindRegionViaTriangle(int32_t nTriangle, int32_t nRegionNodes, int32_t * pnRegionTriangles, BOOL * pbTriangleChecked);
    int32_t FindTriangle(int32_t nLevel, int32_t nDepth, float fX, float fY, int32_t nTriangle = - 1);
    int32_t GenerateBestIntraTileExit(CNWTile * pTile, CNWArea * pWalkGeometry, CPathfindInformation * pSearchInformation, float fCurrentX, float fCurrentY);
    int32_t GetExit(int32_t nExit, float * fX, float * fY, int32_t * nRegion);
    int32_t GetExitNumber(float fX, float fY);
    uint8_t GetPathNode();
    int32_t GetPathNodeOrientation();
    int32_t GetRegionCoords(int32_t nRegion, float * fX, float * fY, uint8_t nPathNode = 0, int32_t nOrientation = 0);
    int32_t GetRegionEntrance(float fX, float fY, uint8_t nPathNode = 0, int32_t nOrientation = 0);
    int32_t GetSurfaceMaterial(Vector vPosition);
    int32_t GetTotalExits();
    void GetTriangleAdjacency(int32_t nLevel, int32_t nTriangle, int32_t * ta12, int32_t * ta23, int32_t * ta31);
    void GetTriangleCentroid(int32_t nTriangle, float * fX, float * fY, float * fZ);
    void GetTriangleVertices(int32_t nLevel, int32_t nTriangle, int32_t * v1, int32_t * v2, int32_t * v3);
    void GetVertexGeometry(int32_t nVertex, Vector * vVector);
    void GetVertexGeometry(int32_t nVertex, float * vX, float * vY, float * vZ);
    void GetTopLevelVertexGeometry(int32_t nVertex, float * vX, float * vY, float * vZ);
    CResRef GetWalkMesh();
    BOOL ClearLineOfSight(int32_t nDirectionHeuristic, Vector vSource, Vector vTarget, Vector * vImpact);
    BOOL ClearLineOfSightOneWay(int32_t nDirectionHeuristic, Vector vSource, Vector vTarget, Vector * pImpact);
    int32_t IntersectLineSegments(Vector v1, Vector v2, Vector v3, Vector v4, Vector * vIntersect);
    int32_t IntraTileDFS(CNWTile * pTile, CNWArea * pWalkGeometry, CPathfindInformation * pSearchInformation, int32_t level, float fDistanceTravelled, int32_t nCurrentTriangle, float fX, float fY, float fStartX, float fStartY, float fPersonalSpace, BOOL bUseAdjacenciesOnly);
    int32_t IntraTileDFSGenerateSuccessors(BOOL bAdjacenciesOnly, CNWTile * pTile, CNWArea * pWalkGeometry, float fX, float fY, int32_t nCurrentTriangle, CPathfindInformation * pPathfindInfo, CPathfindInfoIntraTileSuccessors * * pSuccessors);
    void PrintAABBTreeToPrintLog(CNWTileSurfaceMeshAABBNode * pNode, int indentation);
    void LoadDefaultWalkMesh();
    BOOL LoadWalkMesh();
    BOOL LoadWalkMeshString(uint8_t * * pInput, uint32_t * nInputSize, uint8_t * pchBuffer, uint32_t nBufferSize);
    int32_t NoNonWalkPolysOnTile(float fSourceX, float fSourceY, float fTargetX, float fTargetY, float fMinZ, float fMaxZ, float fPersonalSpace, BOOL bTestSinglePoint);
    uint32_t PlotIntraTilePath(CNWTile * pTile, CNWArea * pWalkGeometry, CPathfindInformation * pSearchInformation, float fCurrentIntraTileX, float fCurrentIntraTileY, float fInterTileStartX, float fInterTileStartY, uint32_t nMaxTimeAllowed, int32_t bAdjacenciesOnly);
    void RunSubdivision(int32_t * pNewTriangles, int32_t nNewTriangles, float * pNewVertices, int32_t nNewVertices, int32_t * pNewTAdjacency, int32_t * pTriangles, int32_t nTriangles, float * pVertices, int32_t nVertices, int32_t * pTAdjacency);
    void SetPathNode(uint8_t nPathNode);
    void SetWalkMesh(CResRef cWalkMesh);
    void Subdivide();
    BOOL TestLineForWalkableOnArea(float fSourceX, float fSourceY, float fTargetX, float fTargetY, float fClipMinZ, float fClipMaxZ, CPathfindInformation * pPathfindInfo, CNWTile * pTile, CNWArea * pArea);
    BOOL TestLineForWalkableOnTile(float fSourceX, float fSourceY, float fTargetX, float fTargetY, float * fClipMinZ, float * fClipMaxZ, CPathfindInformation * pPathfindInfo, CNWTile * pTile, BOOL bStayOnTile = false);
    int32_t PolyHit(const Vector * vert, const int32_t n, const Vector & v0, const Vector & v1, const Vector & nrml, float dist, Vector * impact);
    uint8_t ConvertToTileOrientation(int32_t nOrientation);


#ifdef NWN_CLASS_EXTENSION_CNWTileSurfaceMesh
    NWN_CLASS_EXTENSION_CNWTileSurfaceMesh
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CNWTileSurfaceMesh)
#endif

