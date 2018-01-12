#include "CNWTileSurfaceMesh.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CNWArea.hpp"
#include "CNWTile.hpp"
#include "CNWTileSurfaceMeshAABBNode.hpp"
#include "CNWTileSurfaceMeshHashTableEntry.hpp"
#include "CPathfindInfoIntraTileSuccessors.hpp"
#include "CPathfindInformation.hpp"

namespace NWNXLib {

namespace API {

CNWTileSurfaceMesh::CNWTileSurfaceMesh()
{
    CNWTileSurfaceMesh__CNWTileSurfaceMeshCtor__0(this);
}

CNWTileSurfaceMesh::~CNWTileSurfaceMesh()
{
    CNWTileSurfaceMesh__CNWTileSurfaceMeshDtor__0(this);
}

int32_t CNWTileSurfaceMesh::CheckAABBNode(int32_t a0, CNWTileSurfaceMeshAABBNode* a1, const Vector& a2, Vector& a3)
{
    return CNWTileSurfaceMesh__CheckAABBNode(this, a0, a1, a2, a3);
}

int32_t CNWTileSurfaceMesh::CheckAABBNodeOneWay(int32_t a0, CNWTileSurfaceMeshAABBNode* a1, const Vector& a2, Vector& a3)
{
    return CNWTileSurfaceMesh__CheckAABBNodeOneWay(this, a0, a1, a2, a3);
}

int32_t CNWTileSurfaceMesh::ClearLineOfSight(int32_t a0, Vector a1, Vector a2, Vector* a3)
{
    return CNWTileSurfaceMesh__ClearLineOfSight(this, a0, a1, a2, a3);
}

int32_t CNWTileSurfaceMesh::ClearLineOfSightOneWay(int32_t a0, Vector a1, Vector a2, Vector* a3)
{
    return CNWTileSurfaceMesh__ClearLineOfSightOneWay(this, a0, a1, a2, a3);
}

void CNWTileSurfaceMesh::ClearSubdivision()
{
    return CNWTileSurfaceMesh__ClearSubdivision(this);
}

int32_t CNWTileSurfaceMesh::ClippedLineSegmentWalkable(CNWTile* a0, float a1, float a2, float a3, float a4, float* a5, float* a6, float* a7, float* a8, float* a9, float* a10)
{
    return CNWTileSurfaceMesh__ClippedLineSegmentWalkable(this, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10);
}

int32_t CNWTileSurfaceMesh::ComputeClippedLineSegment(CNWTile* a0, float a1, float a2, float a3, float a4, float* a5, float* a6, float* a7, float* a8)
{
    return CNWTileSurfaceMesh__ComputeClippedLineSegment(this, a0, a1, a2, a3, a4, a5, a6, a7, a8);
}

float CNWTileSurfaceMesh::ComputeHeight(Vector a0)
{
    return CNWTileSurfaceMesh__ComputeHeight(this, a0);
}

void CNWTileSurfaceMesh::ComputePathNodes()
{
    return CNWTileSurfaceMesh__ComputePathNodes(this);
}

void CNWTileSurfaceMesh::ComputeTriangleAdjacency()
{
    return CNWTileSurfaceMesh__ComputeTriangleAdjacency(this);
}

unsigned char CNWTileSurfaceMesh::ConvertToTileOrientation(int32_t a0)
{
    return CNWTileSurfaceMesh__ConvertToTileOrientation(this, a0);
}

float CNWTileSurfaceMesh::EstimateDistanceToTarget(float a0, float a1)
{
    return CNWTileSurfaceMesh__EstimateDistanceToTarget(this, a0, a1);
}

int32_t CNWTileSurfaceMesh::FindClosestRegion(CNWTile* a0, float a1, float a2, unsigned char a3, int32_t a4)
{
    return CNWTileSurfaceMesh__FindClosestRegion(this, a0, a1, a2, a3, a4);
}

int32_t CNWTileSurfaceMesh::FindRegionViaTriangle(int32_t a0, int32_t a1, int32_t* a2, int32_t* a3)
{
    return CNWTileSurfaceMesh__FindRegionViaTriangle(this, a0, a1, a2, a3);
}

int32_t CNWTileSurfaceMesh::FindTriangle(int32_t a0, int32_t a1, float a2, float a3, int32_t a4)
{
    return CNWTileSurfaceMesh__FindTriangle(this, a0, a1, a2, a3, a4);
}

int32_t CNWTileSurfaceMesh::GenerateBestIntraTileExit(CNWTile* a0, CNWArea* a1, CPathfindInformation* a2, float a3, float a4)
{
    return CNWTileSurfaceMesh__GenerateBestIntraTileExit(this, a0, a1, a2, a3, a4);
}

int32_t CNWTileSurfaceMesh::GetExit(int32_t a0, float* a1, float* a2, int32_t* a3)
{
    return CNWTileSurfaceMesh__GetExit(this, a0, a1, a2, a3);
}

int32_t CNWTileSurfaceMesh::GetExitNumber(float a0, float a1)
{
    return CNWTileSurfaceMesh__GetExitNumber(this, a0, a1);
}

int32_t* CNWTileSurfaceMesh::GetLOSMaterials()
{
    return CNWTileSurfaceMesh__GetLOSMaterials();
}

unsigned char CNWTileSurfaceMesh::GetPathNode()
{
    return CNWTileSurfaceMesh__GetPathNode(this);
}

int32_t CNWTileSurfaceMesh::GetPathNodeOrientation()
{
    return CNWTileSurfaceMesh__GetPathNodeOrientation(this);
}

int32_t CNWTileSurfaceMesh::GetRegionCoords(int32_t a0, float* a1, float* a2, unsigned char a3, int32_t a4)
{
    return CNWTileSurfaceMesh__GetRegionCoords(this, a0, a1, a2, a3, a4);
}

int32_t CNWTileSurfaceMesh::GetRegionEntrance(float a0, float a1, unsigned char a2, int32_t a3)
{
    return CNWTileSurfaceMesh__GetRegionEntrance(this, a0, a1, a2, a3);
}

int32_t CNWTileSurfaceMesh::GetSurfaceMaterial(Vector a0)
{
    return CNWTileSurfaceMesh__GetSurfaceMaterial(this, a0);
}

void CNWTileSurfaceMesh::GetTopLevelVertexGeometry(int32_t a0, float* a1, float* a2, float* a3)
{
    return CNWTileSurfaceMesh__GetTopLevelVertexGeometry(this, a0, a1, a2, a3);
}

int32_t CNWTileSurfaceMesh::GetTotalExits()
{
    return CNWTileSurfaceMesh__GetTotalExits(this);
}

void CNWTileSurfaceMesh::GetTriangleAdjacency(int32_t a0, int32_t a1, int32_t* a2, int32_t* a3, int32_t* a4)
{
    return CNWTileSurfaceMesh__GetTriangleAdjacency(this, a0, a1, a2, a3, a4);
}

void CNWTileSurfaceMesh::GetTriangleCentroid(int32_t a0, float* a1, float* a2, float* a3)
{
    return CNWTileSurfaceMesh__GetTriangleCentroid(this, a0, a1, a2, a3);
}

void CNWTileSurfaceMesh::GetTriangleVertices(int32_t a0, int32_t a1, int32_t* a2, int32_t* a3, int32_t* a4)
{
    return CNWTileSurfaceMesh__GetTriangleVertices(this, a0, a1, a2, a3, a4);
}

void CNWTileSurfaceMesh::GetVertexGeometry(int32_t a0, Vector* a1)
{
    return CNWTileSurfaceMesh__GetVertexGeometry__0(this, a0, a1);
}

void CNWTileSurfaceMesh::GetVertexGeometry(int32_t a0, float* a1, float* a2, float* a3)
{
    return CNWTileSurfaceMesh__GetVertexGeometry__1(this, a0, a1, a2, a3);
}

CResRef CNWTileSurfaceMesh::GetWalkMesh()
{
    return CNWTileSurfaceMesh__GetWalkMesh(this);
}

int32_t CNWTileSurfaceMesh::IntersectLineSegments(Vector a0, Vector a1, Vector a2, Vector a3, Vector* a4)
{
    return CNWTileSurfaceMesh__IntersectLineSegments(this, a0, a1, a2, a3, a4);
}

int32_t CNWTileSurfaceMesh::IntraTileDFS(CNWTile* a0, CNWArea* a1, CPathfindInformation* a2, int32_t a3, float a4, int32_t a5, float a6, float a7, float a8, float a9, float a10, int32_t a11)
{
    return CNWTileSurfaceMesh__IntraTileDFS(this, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11);
}

int32_t CNWTileSurfaceMesh::IntraTileDFSGenerateSuccessors(int32_t a0, CNWTile* a1, CNWArea* a2, float a3, float a4, int32_t a5, CPathfindInformation* a6, CPathfindInfoIntraTileSuccessors** a7)
{
    return CNWTileSurfaceMesh__IntraTileDFSGenerateSuccessors(this, a0, a1, a2, a3, a4, a5, a6, a7);
}

void CNWTileSurfaceMesh::LoadDefaultWalkMesh()
{
    return CNWTileSurfaceMesh__LoadDefaultWalkMesh(this);
}

int32_t CNWTileSurfaceMesh::LoadWalkMesh()
{
    return CNWTileSurfaceMesh__LoadWalkMesh(this);
}

int32_t CNWTileSurfaceMesh::LoadWalkMeshString(unsigned char** a0, uint32_t* a1, unsigned char* a2, uint32_t a3)
{
    return CNWTileSurfaceMesh__LoadWalkMeshString(this, a0, a1, a2, a3);
}

int32_t CNWTileSurfaceMesh::NoNonWalkPolysOnTile(float a0, float a1, float a2, float a3, float a4, float a5, float a6, int32_t a7)
{
    return CNWTileSurfaceMesh__NoNonWalkPolysOnTile(this, a0, a1, a2, a3, a4, a5, a6, a7);
}

uint32_t CNWTileSurfaceMesh::PlotIntraTilePath(CNWTile* a0, CNWArea* a1, CPathfindInformation* a2, float a3, float a4, float a5, float a6, uint32_t a7, int32_t a8)
{
    return CNWTileSurfaceMesh__PlotIntraTilePath(this, a0, a1, a2, a3, a4, a5, a6, a7, a8);
}

int32_t CNWTileSurfaceMesh::PolyHit(const Vector* a0, int32_t a1, const Vector& a2, const Vector& a3, const Vector& a4, float a5, Vector* a6)
{
    return CNWTileSurfaceMesh__PolyHit(this, a0, a1, a2, a3, a4, a5, a6);
}

void CNWTileSurfaceMesh::PrintAABBTreeToPrintLog(CNWTileSurfaceMeshAABBNode* a0, int32_t a1)
{
    return CNWTileSurfaceMesh__PrintAABBTreeToPrintLog(this, a0, a1);
}

void CNWTileSurfaceMesh::RunSubdivision(int32_t* a0, int32_t a1, float* a2, int32_t a3, int32_t* a4, int32_t* a5, int32_t a6, float* a7, int32_t a8, int32_t* a9)
{
    return CNWTileSurfaceMesh__RunSubdivision(this, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9);
}

void CNWTileSurfaceMesh::SetPathNode(unsigned char a0)
{
    return CNWTileSurfaceMesh__SetPathNode(this, a0);
}

void CNWTileSurfaceMesh::SetWalkMesh(CResRef a0)
{
    return CNWTileSurfaceMesh__SetWalkMesh(this, a0);
}

void CNWTileSurfaceMesh::Subdivide()
{
    return CNWTileSurfaceMesh__Subdivide(this);
}

int32_t CNWTileSurfaceMesh::TestLineForWalkableOnArea(float a0, float a1, float a2, float a3, float a4, float a5, CPathfindInformation* a6, CNWTile* a7, CNWArea* a8)
{
    return CNWTileSurfaceMesh__TestLineForWalkableOnArea(this, a0, a1, a2, a3, a4, a5, a6, a7, a8);
}

int32_t CNWTileSurfaceMesh::TestLineForWalkableOnTile(float a0, float a1, float a2, float a3, float* a4, float* a5, CPathfindInformation* a6, CNWTile* a7, int32_t a8)
{
    return CNWTileSurfaceMesh__TestLineForWalkableOnTile(this, a0, a1, a2, a3, a4, a5, a6, a7, a8);
}

void CNWTileSurfaceMesh__CNWTileSurfaceMeshCtor__0(CNWTileSurfaceMesh* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWTileSurfaceMesh*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWTileSurfaceMesh__CNWTileSurfaceMeshCtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr);
}

void CNWTileSurfaceMesh__CNWTileSurfaceMeshDtor__0(CNWTileSurfaceMesh* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWTileSurfaceMesh*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWTileSurfaceMesh__CNWTileSurfaceMeshDtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

int32_t CNWTileSurfaceMesh__CheckAABBNode(CNWTileSurfaceMesh* thisPtr, int32_t a0, CNWTileSurfaceMeshAABBNode* a1, const Vector& a2, Vector& a3)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWTileSurfaceMesh*, int32_t, CNWTileSurfaceMeshAABBNode*, const Vector&, Vector&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWTileSurfaceMesh__CheckAABBNode);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

int32_t CNWTileSurfaceMesh__CheckAABBNodeOneWay(CNWTileSurfaceMesh* thisPtr, int32_t a0, CNWTileSurfaceMeshAABBNode* a1, const Vector& a2, Vector& a3)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWTileSurfaceMesh*, int32_t, CNWTileSurfaceMeshAABBNode*, const Vector&, Vector&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWTileSurfaceMesh__CheckAABBNodeOneWay);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

int32_t CNWTileSurfaceMesh__ClearLineOfSight(CNWTileSurfaceMesh* thisPtr, int32_t a0, Vector a1, Vector a2, Vector* a3)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWTileSurfaceMesh*, int32_t, Vector, Vector, Vector*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWTileSurfaceMesh__ClearLineOfSight);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

int32_t CNWTileSurfaceMesh__ClearLineOfSightOneWay(CNWTileSurfaceMesh* thisPtr, int32_t a0, Vector a1, Vector a2, Vector* a3)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWTileSurfaceMesh*, int32_t, Vector, Vector, Vector*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWTileSurfaceMesh__ClearLineOfSightOneWay);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

void CNWTileSurfaceMesh__ClearSubdivision(CNWTileSurfaceMesh* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWTileSurfaceMesh*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWTileSurfaceMesh__ClearSubdivision);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CNWTileSurfaceMesh__ClippedLineSegmentWalkable(CNWTileSurfaceMesh* thisPtr, CNWTile* a0, float a1, float a2, float a3, float a4, float* a5, float* a6, float* a7, float* a8, float* a9, float* a10)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWTileSurfaceMesh*, CNWTile*, float, float, float, float, float*, float*, float*, float*, float*, float*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWTileSurfaceMesh__ClippedLineSegmentWalkable);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10);
}

int32_t CNWTileSurfaceMesh__ComputeClippedLineSegment(CNWTileSurfaceMesh* thisPtr, CNWTile* a0, float a1, float a2, float a3, float a4, float* a5, float* a6, float* a7, float* a8)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWTileSurfaceMesh*, CNWTile*, float, float, float, float, float*, float*, float*, float*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWTileSurfaceMesh__ComputeClippedLineSegment);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4, a5, a6, a7, a8);
}

float CNWTileSurfaceMesh__ComputeHeight(CNWTileSurfaceMesh* thisPtr, Vector a0)
{
    using FuncPtrType = float(__attribute__((cdecl)) *)(CNWTileSurfaceMesh*, Vector);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWTileSurfaceMesh__ComputeHeight);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWTileSurfaceMesh__ComputePathNodes(CNWTileSurfaceMesh* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWTileSurfaceMesh*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWTileSurfaceMesh__ComputePathNodes);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWTileSurfaceMesh__ComputeTriangleAdjacency(CNWTileSurfaceMesh* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWTileSurfaceMesh*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWTileSurfaceMesh__ComputeTriangleAdjacency);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

unsigned char CNWTileSurfaceMesh__ConvertToTileOrientation(CNWTileSurfaceMesh* thisPtr, int32_t a0)
{
    using FuncPtrType = unsigned char(__attribute__((cdecl)) *)(CNWTileSurfaceMesh*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWTileSurfaceMesh__ConvertToTileOrientation);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

float CNWTileSurfaceMesh__EstimateDistanceToTarget(CNWTileSurfaceMesh* thisPtr, float a0, float a1)
{
    using FuncPtrType = float(__attribute__((cdecl)) *)(CNWTileSurfaceMesh*, float, float);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWTileSurfaceMesh__EstimateDistanceToTarget);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWTileSurfaceMesh__FindClosestRegion(CNWTileSurfaceMesh* thisPtr, CNWTile* a0, float a1, float a2, unsigned char a3, int32_t a4)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWTileSurfaceMesh*, CNWTile*, float, float, unsigned char, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWTileSurfaceMesh__FindClosestRegion);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4);
}

int32_t CNWTileSurfaceMesh__FindRegionViaTriangle(CNWTileSurfaceMesh* thisPtr, int32_t a0, int32_t a1, int32_t* a2, int32_t* a3)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWTileSurfaceMesh*, int32_t, int32_t, int32_t*, int32_t*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWTileSurfaceMesh__FindRegionViaTriangle);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

int32_t CNWTileSurfaceMesh__FindTriangle(CNWTileSurfaceMesh* thisPtr, int32_t a0, int32_t a1, float a2, float a3, int32_t a4)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWTileSurfaceMesh*, int32_t, int32_t, float, float, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWTileSurfaceMesh__FindTriangle);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4);
}

int32_t CNWTileSurfaceMesh__GenerateBestIntraTileExit(CNWTileSurfaceMesh* thisPtr, CNWTile* a0, CNWArea* a1, CPathfindInformation* a2, float a3, float a4)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWTileSurfaceMesh*, CNWTile*, CNWArea*, CPathfindInformation*, float, float);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWTileSurfaceMesh__GenerateBestIntraTileExit);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4);
}

int32_t CNWTileSurfaceMesh__GetExit(CNWTileSurfaceMesh* thisPtr, int32_t a0, float* a1, float* a2, int32_t* a3)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWTileSurfaceMesh*, int32_t, float*, float*, int32_t*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWTileSurfaceMesh__GetExit);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

int32_t CNWTileSurfaceMesh__GetExitNumber(CNWTileSurfaceMesh* thisPtr, float a0, float a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWTileSurfaceMesh*, float, float);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWTileSurfaceMesh__GetExitNumber);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t* CNWTileSurfaceMesh__GetLOSMaterials()
{
    using FuncPtrType = int32_t*(*)();
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWTileSurfaceMesh__GetLOSMaterials);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func();
}

unsigned char CNWTileSurfaceMesh__GetPathNode(CNWTileSurfaceMesh* thisPtr)
{
    using FuncPtrType = unsigned char(__attribute__((cdecl)) *)(CNWTileSurfaceMesh*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWTileSurfaceMesh__GetPathNode);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CNWTileSurfaceMesh__GetPathNodeOrientation(CNWTileSurfaceMesh* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWTileSurfaceMesh*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWTileSurfaceMesh__GetPathNodeOrientation);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CNWTileSurfaceMesh__GetRegionCoords(CNWTileSurfaceMesh* thisPtr, int32_t a0, float* a1, float* a2, unsigned char a3, int32_t a4)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWTileSurfaceMesh*, int32_t, float*, float*, unsigned char, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWTileSurfaceMesh__GetRegionCoords);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4);
}

int32_t CNWTileSurfaceMesh__GetRegionEntrance(CNWTileSurfaceMesh* thisPtr, float a0, float a1, unsigned char a2, int32_t a3)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWTileSurfaceMesh*, float, float, unsigned char, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWTileSurfaceMesh__GetRegionEntrance);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

int32_t CNWTileSurfaceMesh__GetSurfaceMaterial(CNWTileSurfaceMesh* thisPtr, Vector a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWTileSurfaceMesh*, Vector);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWTileSurfaceMesh__GetSurfaceMaterial);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWTileSurfaceMesh__GetTopLevelVertexGeometry(CNWTileSurfaceMesh* thisPtr, int32_t a0, float* a1, float* a2, float* a3)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWTileSurfaceMesh*, int32_t, float*, float*, float*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWTileSurfaceMesh__GetTopLevelVertexGeometry);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

int32_t CNWTileSurfaceMesh__GetTotalExits(CNWTileSurfaceMesh* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWTileSurfaceMesh*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWTileSurfaceMesh__GetTotalExits);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWTileSurfaceMesh__GetTriangleAdjacency(CNWTileSurfaceMesh* thisPtr, int32_t a0, int32_t a1, int32_t* a2, int32_t* a3, int32_t* a4)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWTileSurfaceMesh*, int32_t, int32_t, int32_t*, int32_t*, int32_t*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWTileSurfaceMesh__GetTriangleAdjacency);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4);
}

void CNWTileSurfaceMesh__GetTriangleCentroid(CNWTileSurfaceMesh* thisPtr, int32_t a0, float* a1, float* a2, float* a3)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWTileSurfaceMesh*, int32_t, float*, float*, float*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWTileSurfaceMesh__GetTriangleCentroid);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

void CNWTileSurfaceMesh__GetTriangleVertices(CNWTileSurfaceMesh* thisPtr, int32_t a0, int32_t a1, int32_t* a2, int32_t* a3, int32_t* a4)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWTileSurfaceMesh*, int32_t, int32_t, int32_t*, int32_t*, int32_t*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWTileSurfaceMesh__GetTriangleVertices);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4);
}

void CNWTileSurfaceMesh__GetVertexGeometry__0(CNWTileSurfaceMesh* thisPtr, int32_t a0, Vector* a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWTileSurfaceMesh*, int32_t, Vector*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWTileSurfaceMesh__GetVertexGeometry__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWTileSurfaceMesh__GetVertexGeometry__1(CNWTileSurfaceMesh* thisPtr, int32_t a0, float* a1, float* a2, float* a3)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWTileSurfaceMesh*, int32_t, float*, float*, float*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWTileSurfaceMesh__GetVertexGeometry__1);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

CResRef CNWTileSurfaceMesh__GetWalkMesh(CNWTileSurfaceMesh* thisPtr)
{
    using FuncPtrType = CResRef(__attribute__((cdecl)) *)(CNWTileSurfaceMesh*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWTileSurfaceMesh__GetWalkMesh);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CNWTileSurfaceMesh__IntersectLineSegments(CNWTileSurfaceMesh* thisPtr, Vector a0, Vector a1, Vector a2, Vector a3, Vector* a4)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWTileSurfaceMesh*, Vector, Vector, Vector, Vector, Vector*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWTileSurfaceMesh__IntersectLineSegments);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4);
}

int32_t CNWTileSurfaceMesh__IntraTileDFS(CNWTileSurfaceMesh* thisPtr, CNWTile* a0, CNWArea* a1, CPathfindInformation* a2, int32_t a3, float a4, int32_t a5, float a6, float a7, float a8, float a9, float a10, int32_t a11)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWTileSurfaceMesh*, CNWTile*, CNWArea*, CPathfindInformation*, int32_t, float, int32_t, float, float, float, float, float, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWTileSurfaceMesh__IntraTileDFS);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11);
}

int32_t CNWTileSurfaceMesh__IntraTileDFSGenerateSuccessors(CNWTileSurfaceMesh* thisPtr, int32_t a0, CNWTile* a1, CNWArea* a2, float a3, float a4, int32_t a5, CPathfindInformation* a6, CPathfindInfoIntraTileSuccessors** a7)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWTileSurfaceMesh*, int32_t, CNWTile*, CNWArea*, float, float, int32_t, CPathfindInformation*, CPathfindInfoIntraTileSuccessors**);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWTileSurfaceMesh__IntraTileDFSGenerateSuccessors);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4, a5, a6, a7);
}

void CNWTileSurfaceMesh__LoadDefaultWalkMesh(CNWTileSurfaceMesh* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWTileSurfaceMesh*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWTileSurfaceMesh__LoadDefaultWalkMesh);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CNWTileSurfaceMesh__LoadWalkMesh(CNWTileSurfaceMesh* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWTileSurfaceMesh*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWTileSurfaceMesh__LoadWalkMesh);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CNWTileSurfaceMesh__LoadWalkMeshString(CNWTileSurfaceMesh* thisPtr, unsigned char** a0, uint32_t* a1, unsigned char* a2, uint32_t a3)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWTileSurfaceMesh*, unsigned char**, uint32_t*, unsigned char*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWTileSurfaceMesh__LoadWalkMeshString);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

int32_t CNWTileSurfaceMesh__NoNonWalkPolysOnTile(CNWTileSurfaceMesh* thisPtr, float a0, float a1, float a2, float a3, float a4, float a5, float a6, int32_t a7)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWTileSurfaceMesh*, float, float, float, float, float, float, float, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWTileSurfaceMesh__NoNonWalkPolysOnTile);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4, a5, a6, a7);
}

uint32_t CNWTileSurfaceMesh__PlotIntraTilePath(CNWTileSurfaceMesh* thisPtr, CNWTile* a0, CNWArea* a1, CPathfindInformation* a2, float a3, float a4, float a5, float a6, uint32_t a7, int32_t a8)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNWTileSurfaceMesh*, CNWTile*, CNWArea*, CPathfindInformation*, float, float, float, float, uint32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWTileSurfaceMesh__PlotIntraTilePath);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4, a5, a6, a7, a8);
}

int32_t CNWTileSurfaceMesh__PolyHit(CNWTileSurfaceMesh* thisPtr, const Vector* a0, int32_t a1, const Vector& a2, const Vector& a3, const Vector& a4, float a5, Vector* a6)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWTileSurfaceMesh*, const Vector*, int32_t, const Vector&, const Vector&, const Vector&, float, Vector*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWTileSurfaceMesh__PolyHit);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4, a5, a6);
}

void CNWTileSurfaceMesh__PrintAABBTreeToPrintLog(CNWTileSurfaceMesh* thisPtr, CNWTileSurfaceMeshAABBNode* a0, int32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWTileSurfaceMesh*, CNWTileSurfaceMeshAABBNode*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWTileSurfaceMesh__PrintAABBTreeToPrintLog);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWTileSurfaceMesh__RunSubdivision(CNWTileSurfaceMesh* thisPtr, int32_t* a0, int32_t a1, float* a2, int32_t a3, int32_t* a4, int32_t* a5, int32_t a6, float* a7, int32_t a8, int32_t* a9)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWTileSurfaceMesh*, int32_t*, int32_t, float*, int32_t, int32_t*, int32_t*, int32_t, float*, int32_t, int32_t*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWTileSurfaceMesh__RunSubdivision);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9);
}

void CNWTileSurfaceMesh__SetPathNode(CNWTileSurfaceMesh* thisPtr, unsigned char a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWTileSurfaceMesh*, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWTileSurfaceMesh__SetPathNode);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWTileSurfaceMesh__SetWalkMesh(CNWTileSurfaceMesh* thisPtr, CResRef a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWTileSurfaceMesh*, CResRef);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWTileSurfaceMesh__SetWalkMesh);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWTileSurfaceMesh__Subdivide(CNWTileSurfaceMesh* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWTileSurfaceMesh*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWTileSurfaceMesh__Subdivide);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CNWTileSurfaceMesh__TestLineForWalkableOnArea(CNWTileSurfaceMesh* thisPtr, float a0, float a1, float a2, float a3, float a4, float a5, CPathfindInformation* a6, CNWTile* a7, CNWArea* a8)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWTileSurfaceMesh*, float, float, float, float, float, float, CPathfindInformation*, CNWTile*, CNWArea*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWTileSurfaceMesh__TestLineForWalkableOnArea);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4, a5, a6, a7, a8);
}

int32_t CNWTileSurfaceMesh__TestLineForWalkableOnTile(CNWTileSurfaceMesh* thisPtr, float a0, float a1, float a2, float a3, float* a4, float* a5, CPathfindInformation* a6, CNWTile* a7, int32_t a8)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWTileSurfaceMesh*, float, float, float, float, float*, float*, CPathfindInformation*, CNWTile*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWTileSurfaceMesh__TestLineForWalkableOnTile);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4, a5, a6, a7, a8);
}

}

}
