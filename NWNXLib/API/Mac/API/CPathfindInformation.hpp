#pragma once

#include <cstdint>

#include "Vector.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CPathfindInfoIntraTileSuccessors;

struct CPathfindInformation
{
    int32_t m_bClientMoving;
    float m_fPersonalSpace;
    float m_fCreaturePersonalSpace;
    float m_fHeight;
    float m_fHitDistance;
    int32_t m_bUnsmoothedPath;
    int32_t m_bInterTileOnly;
    int32_t m_bGenerateClosestPointPath;
    int32_t m_nClientPathNumber;
    uint32_t m_oidSelf;
    uint32_t m_oidMovingTo;
    int32_t m_nCallsToPlotPath;
    int32_t m_bTempPoints;
    float m_fTempPointEndX;
    float m_fTempPointEndY;
    float m_fTempPointEndZ;
    float m_fTempPointTolerance;
    uint32_t m_oidTempPointEndArea;
    int32_t m_bNewPoints;
    float m_fNewPointEndX;
    float m_fNewPointEndY;
    float m_fNewPointEndZ;
    float m_fPointTolerance;
    int32_t m_nStepTolerance;
    uint32_t m_oidNewPointEndArea;
    float m_fNewPointStartX;
    float m_fNewPointStartY;
    float m_fNewPointStartZ;
    uint32_t m_oidNewPointStartArea;
    int32_t m_bReversePoints;
    int32_t m_bFullComplete;
    int32_t m_nWayPoints;
    float* m_pfWayPoints;
    int32_t m_nUnsmoothedWayPoints;
    float* m_pfUnsmoothedWayPoints;
    int32_t m_nLocationOnList;
    int32_t m_bInterAreaPathResolved;
    int32_t m_bInterAreaPathInProgress;
    int32_t m_nInterAreas;
    uint32_t* m_poidInterAreas;
    uint32_t* m_poidInterAreaExits;
    int32_t m_nInterAreaDeniedTriggers;
    uint32_t* m_poidInterAreaDeniedTriggerIds;
    uint32_t m_oidDeniedDoor;
    int32_t m_nInterTileDeniedExits;
    int32_t* m_pnInterTileDeniedExitTiles;
    int32_t* m_pnInterTileDeniedExitLocations;
    int32_t m_nTilesToBeExplored;
    int32_t* m_pnTilesToBeExplored;
    float* m_pfTileExitsToBeExplored;
    int32_t m_bFirstTileSearching;
    float m_fFirstTileFValue;
    int32_t m_bFirstTileFValueInProgress;
    int32_t m_nFirstTileFValueAlternativeSize;
    int32_t* m_pnFirstTileFValueCurrentAlternatives;
    int32_t* m_pnFirstTileFValueTotalAlternatives;
    CPathfindInfoIntraTileSuccessors** m_pcFirstTileFValueComputedAlternatives;
    void* m_pcFirstTileHashTable;
    int32_t m_bWalkedPathCut;
    int32_t m_bWalkedPathCutArea;
    uint8_t m_nWalkedPathCutVerify;
    int32_t m_nWalkedPathCutPoints;
    Vector m_vWalkedPathCutNewLastPoint;
    Vector m_vWalkedPathCutNewLastOrientation;
    int32_t m_nGridStartLocationX;
    int32_t m_nGridStartLocationY;
    int32_t m_nGridStartLocationZ;
    Vector m_vGridZeroLocation;
    Vector m_vGridStepX;
    Vector m_vGridStepY;
    Vector m_vGridStepZ;
    int32_t* m_pnGridStepsArray;
    int32_t m_nGridStepsTaken;
    float m_fGridSearchObjectDistance;
    int32_t m_nGridSearchLastDistance;
    void* m_pGridSearchLastTransTable;
    Vector m_vGridSearchLastStartPoint;
    Vector m_vGridSearchLastEndPoint;
    int32_t m_nPathToClosestPointSize;
    int32_t* m_pnPathToClosestPointArray;
    int32_t m_nPathToClosestPointDistance;
    int32_t m_bUsePlotGridPath;
    int32_t m_bWalkStraightLineOnly;
    int32_t m_nPlotPathInAreaResult;
    uint8_t m_nTileSearchedCount;

    // The below are auto generated stubs.
    CPathfindInformation(const CPathfindInformation&) = default;
    CPathfindInformation& operator=(const CPathfindInformation&) = default;

    CPathfindInformation();
    ~CPathfindInformation();
    void ComputeStepTolerance();
    void CreateFirstTileFValueAlternatives(int32_t);
    void DeleteFirstTileFValueAlternatives();
    void FlipStartEndPoints();
    void FlipTempEndPoints();
    void GetFirstTileFValueAlternatives(int32_t, int32_t*, int32_t*, CPathfindInfoIntraTileSuccessors**);
    void Initialize();
    void ResetAtEndOfPath();
    void ResetGridSearchData();
    void ResetInterAreaPathSearchData();
    void ResetInterAreaSearchData();
    void ResetInterTileSearchData();
    void ResetIntraTileSearchData();
    void ResetWayPointData();
    void SetFirstTileFValueAlternatives(int32_t, int32_t, int32_t, CPathfindInfoIntraTileSuccessors*);
    void Shutdown();
};

void CPathfindInformation__CPathfindInformationCtor__0(CPathfindInformation* thisPtr);
void CPathfindInformation__CPathfindInformationDtor__0(CPathfindInformation* thisPtr);
void CPathfindInformation__ComputeStepTolerance(CPathfindInformation* thisPtr);
void CPathfindInformation__CreateFirstTileFValueAlternatives(CPathfindInformation* thisPtr, int32_t);
void CPathfindInformation__DeleteFirstTileFValueAlternatives(CPathfindInformation* thisPtr);
void CPathfindInformation__FlipStartEndPoints(CPathfindInformation* thisPtr);
void CPathfindInformation__FlipTempEndPoints(CPathfindInformation* thisPtr);
void CPathfindInformation__GetFirstTileFValueAlternatives(CPathfindInformation* thisPtr, int32_t, int32_t*, int32_t*, CPathfindInfoIntraTileSuccessors**);
void CPathfindInformation__Initialize(CPathfindInformation* thisPtr);
void CPathfindInformation__ResetAtEndOfPath(CPathfindInformation* thisPtr);
void CPathfindInformation__ResetGridSearchData(CPathfindInformation* thisPtr);
void CPathfindInformation__ResetInterAreaPathSearchData(CPathfindInformation* thisPtr);
void CPathfindInformation__ResetInterAreaSearchData(CPathfindInformation* thisPtr);
void CPathfindInformation__ResetInterTileSearchData(CPathfindInformation* thisPtr);
void CPathfindInformation__ResetIntraTileSearchData(CPathfindInformation* thisPtr);
void CPathfindInformation__ResetWayPointData(CPathfindInformation* thisPtr);
void CPathfindInformation__SetFirstTileFValueAlternatives(CPathfindInformation* thisPtr, int32_t, int32_t, int32_t, CPathfindInfoIntraTileSuccessors*);
void CPathfindInformation__Shutdown(CPathfindInformation* thisPtr);

}

}
