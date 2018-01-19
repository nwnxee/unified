#pragma once

#include <cstdint>

#include "CNWTileSurfaceMeshLocalInfo.hpp"
#include "CResHelperTemplatedCResWOK2016u.hpp"
#include "CResRef.hpp"
#include "Vector.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CNWArea;
struct CNWTile;
struct CNWTileSurfaceMeshAABBNode;
struct CNWTileSurfaceMeshHashTableEntry;
struct CPathfindInfoIntraTileSuccessors;
struct CPathfindInformation;

struct CNWTileSurfaceMesh
    : CResHelperTemplatedCResWOK2016u
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
    int32_t* m_pnTriangles;
    int32_t* m_pnTrianglesLayer1;
    int32_t* m_pnTrianglesLayer2;
    int32_t* m_pnTrianglesLayer3;
    int32_t* m_pnTriangleMaterial;
    float* m_pfTriangleDistances;
    Vector* m_pvTriangleNormals;
    int32_t* m_pnTAdjacency;
    int32_t* m_pnTAdjacencyLayer1;
    int32_t* m_pnTAdjacencyLayer2;
    int32_t* m_pnTAdjacencyLayer3;
    float* m_pfVertices;
    float* m_pfVerticesLayer1;
    float* m_pfVerticesLayer2;
    float* m_pfVerticesLayer3;
    int32_t m_nDeniedVertices;
    float* m_pfDeniedVertices;
    int32_t m_nDeniedTriangles;
    int32_t* m_pnDeniedTriangles;
    int32_t* m_pnDeniedTriangleMaterial;
    float* m_pfDeniedTriangleDistances;
    Vector* m_pvDeniedTriangleNormals;
    CNWTileSurfaceMeshAABBNode* m_pAABBTree;
    float m_fGoalTargetX;
    float m_fGoalMinX;
    float m_fGoalMaxX;
    float m_fGoalTargetY;
    float m_fGoalMinY;
    float m_fGoalMaxY;
    int32_t m_nGoalTargetTriangle;
    float m_fGoalMaximumDistance;
    int32_t m_nIntraTileWPLength;
    float* m_pfIntraTileWayPoints;
    int32_t m_nIntraTileTriangles;
    int32_t* m_pnIntraTileTriangle;
    int32_t m_nIntraTileUnits;
    int32_t m_nMaxIntraTileUnits;
    float m_fMinEstimateToGoal;
    CNWTileSurfaceMeshHashTableEntry* m_pcIntraTileHashTable;
    CNWTileSurfaceMeshLocalInfo m_pcIntraTileGenSuccessorsLocalInfo;

    // The below are auto generated stubs.
    CNWTileSurfaceMesh(const CNWTileSurfaceMesh&) = default;
    CNWTileSurfaceMesh& operator=(const CNWTileSurfaceMesh&) = default;

    CNWTileSurfaceMesh();
    ~CNWTileSurfaceMesh();
    int32_t CheckAABBNode(int32_t, CNWTileSurfaceMeshAABBNode*, const Vector&, Vector&);
    int32_t CheckAABBNodeOneWay(int32_t, CNWTileSurfaceMeshAABBNode*, const Vector&, Vector&);
    int32_t ClearLineOfSight(int32_t, Vector, Vector, Vector*);
    int32_t ClearLineOfSightOneWay(int32_t, Vector, Vector, Vector*);
    void ClearSubdivision();
    int32_t ClippedLineSegmentWalkable(CNWTile*, float, float, float, float, float*, float*, float*, float*, float*, float*);
    int32_t ComputeClippedLineSegment(CNWTile*, float, float, float, float, float*, float*, float*, float*);
    float ComputeHeight(Vector);
    void ComputePathNodes();
    void ComputeTriangleAdjacency();
    unsigned char ConvertToTileOrientation(int32_t);
    float EstimateDistanceToTarget(float, float);
    int32_t FindClosestRegion(CNWTile*, float, float, unsigned char, int32_t);
    int32_t FindRegionViaTriangle(int32_t, int32_t, int32_t*, int32_t*);
    int32_t FindTriangle(int32_t, int32_t, float, float, int32_t);
    int32_t GenerateBestIntraTileExit(CNWTile*, CNWArea*, CPathfindInformation*, float, float);
    int32_t GetExit(int32_t, float*, float*, int32_t*);
    int32_t GetExitNumber(float, float);
    static int32_t* GetLOSMaterials();
    unsigned char GetPathNode();
    int32_t GetPathNodeOrientation();
    int32_t GetRegionCoords(int32_t, float*, float*, unsigned char, int32_t);
    int32_t GetRegionEntrance(float, float, unsigned char, int32_t);
    int32_t GetSurfaceMaterial(Vector);
    void GetTopLevelVertexGeometry(int32_t, float*, float*, float*);
    int32_t GetTotalExits();
    void GetTriangleAdjacency(int32_t, int32_t, int32_t*, int32_t*, int32_t*);
    void GetTriangleCentroid(int32_t, float*, float*, float*);
    void GetTriangleVertices(int32_t, int32_t, int32_t*, int32_t*, int32_t*);
    void GetVertexGeometry(int32_t, Vector*);
    void GetVertexGeometry(int32_t, float*, float*, float*);
    CResRef GetWalkMesh();
    int32_t IntersectLineSegments(Vector, Vector, Vector, Vector, Vector*);
    int32_t IntraTileDFS(CNWTile*, CNWArea*, CPathfindInformation*, int32_t, float, int32_t, float, float, float, float, float, int32_t);
    int32_t IntraTileDFSGenerateSuccessors(int32_t, CNWTile*, CNWArea*, float, float, int32_t, CPathfindInformation*, CPathfindInfoIntraTileSuccessors**);
    void LoadDefaultWalkMesh();
    int32_t LoadWalkMesh();
    int32_t LoadWalkMeshString(unsigned char**, uint32_t*, unsigned char*, uint32_t);
    int32_t NoNonWalkPolysOnTile(float, float, float, float, float, float, float, int32_t);
    uint32_t PlotIntraTilePath(CNWTile*, CNWArea*, CPathfindInformation*, float, float, float, float, uint32_t, int32_t);
    int32_t PolyHit(const Vector*, int32_t, const Vector&, const Vector&, const Vector&, float, Vector*);
    void PrintAABBTreeToPrintLog(CNWTileSurfaceMeshAABBNode*, int32_t);
    void RunSubdivision(int32_t*, int32_t, float*, int32_t, int32_t*, int32_t*, int32_t, float*, int32_t, int32_t*);
    void SetPathNode(unsigned char);
    void SetWalkMesh(CResRef);
    void Subdivide();
    int32_t TestLineForWalkableOnArea(float, float, float, float, float, float, CPathfindInformation*, CNWTile*, CNWArea*);
    int32_t TestLineForWalkableOnTile(float, float, float, float, float*, float*, CPathfindInformation*, CNWTile*, int32_t);
};

void CNWTileSurfaceMesh__CNWTileSurfaceMeshCtor__0(CNWTileSurfaceMesh* thisPtr);
void CNWTileSurfaceMesh__CNWTileSurfaceMeshDtor__0(CNWTileSurfaceMesh* thisPtr);
int32_t CNWTileSurfaceMesh__CheckAABBNode(CNWTileSurfaceMesh* thisPtr, int32_t, CNWTileSurfaceMeshAABBNode*, const Vector&, Vector&);
int32_t CNWTileSurfaceMesh__CheckAABBNodeOneWay(CNWTileSurfaceMesh* thisPtr, int32_t, CNWTileSurfaceMeshAABBNode*, const Vector&, Vector&);
int32_t CNWTileSurfaceMesh__ClearLineOfSight(CNWTileSurfaceMesh* thisPtr, int32_t, Vector, Vector, Vector*);
int32_t CNWTileSurfaceMesh__ClearLineOfSightOneWay(CNWTileSurfaceMesh* thisPtr, int32_t, Vector, Vector, Vector*);
void CNWTileSurfaceMesh__ClearSubdivision(CNWTileSurfaceMesh* thisPtr);
int32_t CNWTileSurfaceMesh__ClippedLineSegmentWalkable(CNWTileSurfaceMesh* thisPtr, CNWTile*, float, float, float, float, float*, float*, float*, float*, float*, float*);
int32_t CNWTileSurfaceMesh__ComputeClippedLineSegment(CNWTileSurfaceMesh* thisPtr, CNWTile*, float, float, float, float, float*, float*, float*, float*);
float CNWTileSurfaceMesh__ComputeHeight(CNWTileSurfaceMesh* thisPtr, Vector);
void CNWTileSurfaceMesh__ComputePathNodes(CNWTileSurfaceMesh* thisPtr);
void CNWTileSurfaceMesh__ComputeTriangleAdjacency(CNWTileSurfaceMesh* thisPtr);
unsigned char CNWTileSurfaceMesh__ConvertToTileOrientation(CNWTileSurfaceMesh* thisPtr, int32_t);
float CNWTileSurfaceMesh__EstimateDistanceToTarget(CNWTileSurfaceMesh* thisPtr, float, float);
int32_t CNWTileSurfaceMesh__FindClosestRegion(CNWTileSurfaceMesh* thisPtr, CNWTile*, float, float, unsigned char, int32_t);
int32_t CNWTileSurfaceMesh__FindRegionViaTriangle(CNWTileSurfaceMesh* thisPtr, int32_t, int32_t, int32_t*, int32_t*);
int32_t CNWTileSurfaceMesh__FindTriangle(CNWTileSurfaceMesh* thisPtr, int32_t, int32_t, float, float, int32_t);
int32_t CNWTileSurfaceMesh__GenerateBestIntraTileExit(CNWTileSurfaceMesh* thisPtr, CNWTile*, CNWArea*, CPathfindInformation*, float, float);
int32_t CNWTileSurfaceMesh__GetExit(CNWTileSurfaceMesh* thisPtr, int32_t, float*, float*, int32_t*);
int32_t CNWTileSurfaceMesh__GetExitNumber(CNWTileSurfaceMesh* thisPtr, float, float);
int32_t* CNWTileSurfaceMesh__GetLOSMaterials();
unsigned char CNWTileSurfaceMesh__GetPathNode(CNWTileSurfaceMesh* thisPtr);
int32_t CNWTileSurfaceMesh__GetPathNodeOrientation(CNWTileSurfaceMesh* thisPtr);
int32_t CNWTileSurfaceMesh__GetRegionCoords(CNWTileSurfaceMesh* thisPtr, int32_t, float*, float*, unsigned char, int32_t);
int32_t CNWTileSurfaceMesh__GetRegionEntrance(CNWTileSurfaceMesh* thisPtr, float, float, unsigned char, int32_t);
int32_t CNWTileSurfaceMesh__GetSurfaceMaterial(CNWTileSurfaceMesh* thisPtr, Vector);
void CNWTileSurfaceMesh__GetTopLevelVertexGeometry(CNWTileSurfaceMesh* thisPtr, int32_t, float*, float*, float*);
int32_t CNWTileSurfaceMesh__GetTotalExits(CNWTileSurfaceMesh* thisPtr);
void CNWTileSurfaceMesh__GetTriangleAdjacency(CNWTileSurfaceMesh* thisPtr, int32_t, int32_t, int32_t*, int32_t*, int32_t*);
void CNWTileSurfaceMesh__GetTriangleCentroid(CNWTileSurfaceMesh* thisPtr, int32_t, float*, float*, float*);
void CNWTileSurfaceMesh__GetTriangleVertices(CNWTileSurfaceMesh* thisPtr, int32_t, int32_t, int32_t*, int32_t*, int32_t*);
void CNWTileSurfaceMesh__GetVertexGeometry__0(CNWTileSurfaceMesh* thisPtr, int32_t, Vector*);
void CNWTileSurfaceMesh__GetVertexGeometry__1(CNWTileSurfaceMesh* thisPtr, int32_t, float*, float*, float*);
CResRef CNWTileSurfaceMesh__GetWalkMesh(CNWTileSurfaceMesh* thisPtr);
int32_t CNWTileSurfaceMesh__IntersectLineSegments(CNWTileSurfaceMesh* thisPtr, Vector, Vector, Vector, Vector, Vector*);
int32_t CNWTileSurfaceMesh__IntraTileDFS(CNWTileSurfaceMesh* thisPtr, CNWTile*, CNWArea*, CPathfindInformation*, int32_t, float, int32_t, float, float, float, float, float, int32_t);
int32_t CNWTileSurfaceMesh__IntraTileDFSGenerateSuccessors(CNWTileSurfaceMesh* thisPtr, int32_t, CNWTile*, CNWArea*, float, float, int32_t, CPathfindInformation*, CPathfindInfoIntraTileSuccessors**);
void CNWTileSurfaceMesh__LoadDefaultWalkMesh(CNWTileSurfaceMesh* thisPtr);
int32_t CNWTileSurfaceMesh__LoadWalkMesh(CNWTileSurfaceMesh* thisPtr);
int32_t CNWTileSurfaceMesh__LoadWalkMeshString(CNWTileSurfaceMesh* thisPtr, unsigned char**, uint32_t*, unsigned char*, uint32_t);
int32_t CNWTileSurfaceMesh__NoNonWalkPolysOnTile(CNWTileSurfaceMesh* thisPtr, float, float, float, float, float, float, float, int32_t);
uint32_t CNWTileSurfaceMesh__PlotIntraTilePath(CNWTileSurfaceMesh* thisPtr, CNWTile*, CNWArea*, CPathfindInformation*, float, float, float, float, uint32_t, int32_t);
int32_t CNWTileSurfaceMesh__PolyHit(CNWTileSurfaceMesh* thisPtr, const Vector*, int32_t, const Vector&, const Vector&, const Vector&, float, Vector*);
void CNWTileSurfaceMesh__PrintAABBTreeToPrintLog(CNWTileSurfaceMesh* thisPtr, CNWTileSurfaceMeshAABBNode*, int32_t);
void CNWTileSurfaceMesh__RunSubdivision(CNWTileSurfaceMesh* thisPtr, int32_t*, int32_t, float*, int32_t, int32_t*, int32_t*, int32_t, float*, int32_t, int32_t*);
void CNWTileSurfaceMesh__SetPathNode(CNWTileSurfaceMesh* thisPtr, unsigned char);
void CNWTileSurfaceMesh__SetWalkMesh(CNWTileSurfaceMesh* thisPtr, CResRef);
void CNWTileSurfaceMesh__Subdivide(CNWTileSurfaceMesh* thisPtr);
int32_t CNWTileSurfaceMesh__TestLineForWalkableOnArea(CNWTileSurfaceMesh* thisPtr, float, float, float, float, float, float, CPathfindInformation*, CNWTile*, CNWArea*);
int32_t CNWTileSurfaceMesh__TestLineForWalkableOnTile(CNWTileSurfaceMesh* thisPtr, float, float, float, float, float*, float*, CPathfindInformation*, CNWTile*, int32_t);

}

}
