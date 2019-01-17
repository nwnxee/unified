#pragma once

#include <cstdint>

#include "CExoArrayListTemplatedlongunsignedint.hpp"
#include "CNWTile.hpp"
#include "CResRef.hpp"
#include "Vector.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CExoArrayListTemplatedunsignedlong;
struct CNWArea;
struct CNWTileData;
struct CPathfindInformation;

struct CNWSTile
    : CNWTile
{
    CNWTileData* m_pTileData;
    int32_t m_nTriggers;
    int32_t m_nTriggerSize;
    uint32_t* m_poidTriggers;
    CExoArrayListTemplatedlongunsignedint m_aDoors;
    int32_t m_bMainLightColorChange;
    int32_t m_bSourceLightColorChange;
    int32_t m_bFlaggedAsProblem;
    int32_t m_bHasPlaceableWithWalkMesh;

    // The below are auto generated stubs.
    CNWSTile(const CNWSTile&) = default;
    CNWSTile& operator=(const CNWSTile&) = default;

    CNWSTile();
    ~CNWSTile();
    void AddTrigger(uint32_t);
    int32_t ClearLineOfSight(int32_t, Vector, Vector, Vector*);
    int32_t ClippedLineSegmentWalkable(float, float, float, float, float*, float*, float*, float*, float*, float*);
    int32_t ComputeClippedLineSegment(Vector, Vector, Vector*, Vector*);
    float ComputeHeight(Vector);
    int32_t FindClosestRegion(float, float);
    int32_t GetExit(int32_t, float*, float*, int32_t*);
    int32_t GetExitNumber(float, float);
    int32_t GetRegionCoords(int32_t, float*, float*);
    int32_t GetRegionEntrance(float, float);
    int32_t GetSurfaceMaterial(Vector);
    CNWTileData* GetTileData();
    int32_t GetTotalExits();
    CResRef GetWalkMesh();
    int32_t IntersectLineSegments(float, float, float, float, float, float, float, float, float*, float*);
    int32_t InTrigger(Vector, CExoArrayListTemplatedunsignedlong*);
    int32_t LoadWalkMesh();
    int32_t NoNonWalkPolysOnTile(float, float, float, float, float, float, float, int32_t);
    uint32_t PlotIntraTilePath(CNWArea*, CPathfindInformation*, float, float, float, float, uint32_t);
    void SetMainLightColor(unsigned char, unsigned char);
    void SetSourceLightColor(unsigned char, unsigned char);
    void SetTileData(CNWTileData*);
};

void CNWSTile__CNWSTileCtor__0(CNWSTile* thisPtr);
void CNWSTile__CNWSTileDtor__0(CNWSTile* thisPtr);
void CNWSTile__AddTrigger(CNWSTile* thisPtr, uint32_t);
int32_t CNWSTile__ClearLineOfSight(CNWSTile* thisPtr, int32_t, Vector, Vector, Vector*);
int32_t CNWSTile__ClippedLineSegmentWalkable(CNWSTile* thisPtr, float, float, float, float, float*, float*, float*, float*, float*, float*);
int32_t CNWSTile__ComputeClippedLineSegment(CNWSTile* thisPtr, Vector, Vector, Vector*, Vector*);
float CNWSTile__ComputeHeight(CNWSTile* thisPtr, Vector);
int32_t CNWSTile__FindClosestRegion(CNWSTile* thisPtr, float, float);
int32_t CNWSTile__GetExit(CNWSTile* thisPtr, int32_t, float*, float*, int32_t*);
int32_t CNWSTile__GetExitNumber(CNWSTile* thisPtr, float, float);
int32_t CNWSTile__GetRegionCoords(CNWSTile* thisPtr, int32_t, float*, float*);
int32_t CNWSTile__GetRegionEntrance(CNWSTile* thisPtr, float, float);
int32_t CNWSTile__GetSurfaceMaterial(CNWSTile* thisPtr, Vector);
CNWTileData* CNWSTile__GetTileData(CNWSTile* thisPtr);
int32_t CNWSTile__GetTotalExits(CNWSTile* thisPtr);
CResRef CNWSTile__GetWalkMesh(CNWSTile* thisPtr);
int32_t CNWSTile__IntersectLineSegments(CNWSTile* thisPtr, float, float, float, float, float, float, float, float, float*, float*);
int32_t CNWSTile__InTrigger(CNWSTile* thisPtr, Vector, CExoArrayListTemplatedunsignedlong*);
int32_t CNWSTile__LoadWalkMesh(CNWSTile* thisPtr);
int32_t CNWSTile__NoNonWalkPolysOnTile(CNWSTile* thisPtr, float, float, float, float, float, float, float, int32_t);
uint32_t CNWSTile__PlotIntraTilePath(CNWSTile* thisPtr, CNWArea*, CPathfindInformation*, float, float, float, float, uint32_t);
void CNWSTile__SetMainLightColor(CNWSTile* thisPtr, unsigned char, unsigned char);
void CNWSTile__SetSourceLightColor(CNWSTile* thisPtr, unsigned char, unsigned char);
void CNWSTile__SetTileData(CNWSTile* thisPtr, CNWTileData*);

}

}
