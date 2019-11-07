#pragma once
#include "nwn_api.hpp"

#include "Vector.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CPathfindInformation)
#endif

struct CNWTileSurfaceMeshHashTableEntry;
struct CPathfindInfoIntraTileSuccessors;


typedef int BOOL;
typedef uint32_t OBJECT_ID;


struct CPathfindInformation
{
    BOOL m_bClientMoving;
    float m_fPersonalSpace;
    float m_fCreaturePersonalSpace;
    float m_fHeight;
    float m_fHitDistance;
    BOOL m_bUnsmoothedPath;
    BOOL m_bInterTileOnly;
    BOOL m_bGenerateClosestPointPath;
    int32_t m_nClientPathNumber;
    OBJECT_ID m_oidSelf;
    OBJECT_ID m_oidMovingTo;
    int32_t m_nCallsToPlotPath;
    BOOL m_bTempPoints;
    float m_fTempPointEndX;
    float m_fTempPointEndY;
    float m_fTempPointEndZ;
    float m_fTempPointTolerance;
    OBJECT_ID m_oidTempPointEndArea;
    BOOL m_bNewPoints;
    float m_fNewPointEndX;
    float m_fNewPointEndY;
    float m_fNewPointEndZ;
    float m_fPointTolerance;
    int32_t m_nStepTolerance;
    OBJECT_ID m_oidNewPointEndArea;
    float m_fNewPointStartX;
    float m_fNewPointStartY;
    float m_fNewPointStartZ;
    OBJECT_ID m_oidNewPointStartArea;
    BOOL m_bReversePoints;
    BOOL m_bFullComplete;
    int32_t m_nWayPoints;
    float * m_pfWayPoints;
    int32_t m_nUnsmoothedWayPoints;
    float * m_pfUnsmoothedWayPoints;
    int32_t m_nLocationOnList;
    BOOL m_bInterAreaPathResolved;
    BOOL m_bInterAreaPathInProgress;
    int32_t m_nInterAreas;
    OBJECT_ID * m_poidInterAreas;
    OBJECT_ID * m_poidInterAreaExits;
    int32_t m_nInterAreaDeniedTriggers;
    OBJECT_ID * m_poidInterAreaDeniedTriggerIds;
    OBJECT_ID m_oidDeniedDoor;
    int32_t m_nInterTileDeniedExits;
    int32_t * m_pnInterTileDeniedExitTiles;
    int32_t * m_pnInterTileDeniedExitLocations;
    int32_t m_nTilesToBeExplored;
    int32_t * m_pnTilesToBeExplored;
    float * m_pfTileExitsToBeExplored;
    BOOL m_bFirstTileSearching;
    float m_fFirstTileFValue;
    BOOL m_bFirstTileFValueInProgress;
    int32_t m_nFirstTileFValueAlternativeSize;
    int32_t * m_pnFirstTileFValueCurrentAlternatives;
    int32_t * m_pnFirstTileFValueTotalAlternatives;
    CPathfindInfoIntraTileSuccessors * * m_pcFirstTileFValueComputedAlternatives;
    CNWTileSurfaceMeshHashTableEntry * m_pcFirstTileHashTable;
    BOOL m_bWalkedPathCut;
    BOOL m_bWalkedPathCutArea;
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
    int32_t * m_pnGridStepsArray;
    int32_t m_nGridStepsTaken;
    float m_fGridSearchObjectDistance;
    int32_t m_nGridSearchLastDistance;
    void * m_pGridSearchLastTransTable;
    Vector m_vGridSearchLastStartPoint;
    Vector m_vGridSearchLastEndPoint;
    int32_t m_nPathToClosestPointSize;
    int32_t * m_pnPathToClosestPointArray;
    int32_t m_nPathToClosestPointDistance;
    BOOL m_bUsePlotGridPath;
    BOOL m_bWalkStraightLineOnly;
    int32_t m_nPlotPathInAreaResult;
    uint8_t m_nTileSearchedCount;

    CPathfindInformation();
    ~CPathfindInformation();
    void Initialize();
    void Shutdown();
    void ResetAtEndOfPath();
    void ResetInterAreaSearchData();
    void ResetInterAreaPathSearchData();
    void ResetGridSearchData();
    void ResetWayPointData();
    void ResetInterTileSearchData();
    void ResetIntraTileSearchData();
    void FlipStartEndPoints();
    void FlipTempEndPoints();
    void GetFirstTileFValueAlternatives(int32_t level, int32_t * nCurrentAlternative, int32_t * nAlternatives, CPathfindInfoIntraTileSuccessors * * pSuccessors);
    void SetFirstTileFValueAlternatives(int32_t level, int32_t nCurrentAlternative, int32_t nAlternatives, CPathfindInfoIntraTileSuccessors * pSuccessors);
    void CreateFirstTileFValueAlternatives(int32_t nSize);
    void DeleteFirstTileFValueAlternatives();
    void ComputeStepTolerance();


#ifdef NWN_CLASS_EXTENSION_CPathfindInformation
    NWN_CLASS_EXTENSION_CPathfindInformation
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CPathfindInformation)
#endif

