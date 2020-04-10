#pragma once
#include "nwn_api.hpp"

#include "CExoArrayList.hpp"
#include "CExoLinkedList.hpp"
#include "CExoLocString.hpp"
#include "CExoString.hpp"
#include "CGameObject.hpp"
#include "CNWArea.hpp"
#include "CNWSScriptVarTable.hpp"
#include "CNWSUUID.hpp"
#include "CResARE.hpp"
#include "CResHelper.hpp"
#include "CResRef.hpp"
#include "NWAREAEXPANSION.hpp"
#include "Vector.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CNWSArea)
#endif

struct CERFFile;
struct CGameEffect;
struct CGameObject;
struct CNWSAmbientSound;
struct CNWSAreaGridPoint;
struct CNWSAreaGridSuccessors;
struct CNWSAreaGridTransTableEntry;
struct CNWSAreaInterTileSuccessors;
struct CNWSCreature;
struct CNWSPlayer;
struct CNWSTile;
struct CNWTileSet;
struct CPathfindInformation;
struct CResGFF;
struct CResStruct;
struct NWAREAHEADER;


typedef int BOOL;
typedef uint32_t OBJECT_ID;


struct CNWSArea : CNWArea, CResHelper<CResARE, 2012>, CGameObject
{
    int32_t m_nPlayersInArea;
    CExoArrayList<OBJECT_ID> m_pTrapList;
    int32_t m_nObjectByNameIndex;
    uint32_t m_nLastHeartbeatScriptCalendarDay;
    uint32_t m_nLastHeartbeatScriptTimeOfDay;
    CExoLinkedList<NWAREAEXPANSION> m_lstExpansions;
    CExoString m_sComments;
    CExoLocString m_lsName;
    CExoString m_sTag;
    CResRef m_refTileSet;
    CNWTileSet * m_pTileSet;
    CNWSTile * m_pTile;
    NWAREAHEADER * m_pHeader;
    CExoString m_sScripts[4];
    int32_t m_nChanceOfFog;
    int32_t m_nAreaSpotModifier;
    int32_t m_nAreaListenModifier;
    CExoArrayList<OBJECT_ID> m_aGameObjects;
    int32_t m_nPosGameObjects;
    CExoArrayList<OBJECT_ID> m_aSubAreas;
    int32_t * m_pnInterTileTravel;
    float * m_pfInterTileExit;
    int32_t * m_pnInterTileRegionVisited;
    uint8_t * m_pnInterTileRegionDepths;
    int32_t m_nInterTileTravelLength;
    int32_t m_nInterTileGoalX;
    int32_t m_nInterTileGoalY;
    int32_t m_nInterTileGoalRegion;
    float m_fGoalTargetX;
    float m_fGoalTargetY;
    CPathfindInformation * m_pSearchInfo;
    CPathfindInformation * m_pSoundPathInfo;
    CNWSAreaGridTransTableEntry * m_pcGridTransTableEntry;
    int32_t g_nUnsmoothedWPList;
    float * g_pfUnsmoothedWPList;
    int32_t g_nSmoothedWPList;
    float * g_pfSmoothedWPList;
    float g_fPersonalSpace;
    BOOL m_bGridPathfindingTerminated;
    int32_t m_nGridNodesSearched;
    OBJECT_ID m_oidLastEntered;
    OBJECT_ID m_oidLastLeft;
    int32_t m_nCustomScriptEventId;
    CNWSAreaInterTileSuccessors * m_pcInterTileSuccessors;
    int32_t * m_pbInterTileDeniedExitCheck;
    BOOL m_bInterAreaDFSVisited;
    CNWSScriptVarTable m_ScriptVars;
    CNWSAmbientSound * m_pAmbientSound;
    uint8_t m_nWeatherType;
    BOOL m_bWeatherStarted;
    uint32_t m_nWeatherMinDurationTimer;
    uint32_t m_nLastUpdateCalendarDay;
    uint32_t m_nLastUpdateTimeOfDay;
    uint8_t m_nOverrideWeatherType;
    uint8_t m_nCurrentWeatherType;
    uint8_t m_nLightingScheme;
    uint8_t m_nPVPSetting;
    uint8_t m_nMapSize;
    int32_t m_nEnvironmentalAudio;
    uint16_t m_nLoadScreenID;
    CExoString m_sDisplayName;
    CNWSUUID m_pUUID;

    CNWSArea(CResRef cResRef, BOOL bSetAutoRequest, OBJECT_ID oidId = 0x7f000000);
    ~CNWSArea();
    virtual CNWSArea * AsNWSArea();
    virtual CNWSArea * NWAreaAsNWSArea();
    BOOL AddObjectToArea(OBJECT_ID id, BOOL bRunScripts = true);
    BOOL AIUpdate();
    Vector ComputeAwayVector(Vector vCurrentPosition, Vector vPositionToMoveAwayFrom, float fMoveAwayRange, CPathfindInformation * pPathInfo);
    int32_t ComputeBestCorner(float fX1, float fY1, float fX2, float fY2, float fX3, float fY3, float fPersonalSpace, float fCreatureHeight, float * fNewX1, float * fNewY1, float * fNewX2, float * fNewY2);
    BOOL TestSafeLocationPoint(Vector vTestPosition, CPathfindInformation * pPathfindInfo);
    BOOL ComputeSafeLocation(Vector vPosition, float fSearchRadius, CPathfindInformation * pPathfindInfo, BOOL bWalkStraightLineRequired, Vector * vNewvector);
    BOOL ComputeSafeLocationInDirection(Vector vPosition, Vector vDirection, float fSearchRadius, CPathfindInformation * pPathfindInfo, BOOL bWalkStraightLineRequired, Vector * vNewVector);
    BOOL ComputeNonVisibleLocation(Vector vTargetPosition, CPathfindInformation * pPathfindInfo, BOOL bWalkStraightLineRequired, Vector * vNewPosition, float fTargetRadius);
    int32_t CountVisibleToPlayers(Vector vPosition, int32_t nMaxPlayers);
    float ComputeHeight(Vector vPosition);
    float ComputePathDistance(int32_t nPoints, float * pfPoints);
    void BudgeCreatures(const Vector & vPosition, const Vector & vBBMin, const Vector & vBBMax, OBJECT_ID oidNewObject, BOOL bBumpToActionPoint);
    int32_t CountAreaTransitionTriggers(OBJECT_ID * pTriggers, int32_t nDeniedTriggers, OBJECT_ID * oidDeniedTriggers);
    void EventHandler(uint32_t nEventId, OBJECT_ID nCallerObjectId, void * pScript, uint32_t nCalendarDay, uint32_t nTimeOfDay);
    int32_t GenerateInterTilePath(int32_t * nInterTileStartDepth, int32_t nInterTileStartTileX, int32_t nInterTileStartTileY, int32_t nInterTileStartRegion);
    BOOL GetFirstObjectInArea(OBJECT_ID & id);
    BOOL GetNextObjectInArea(OBJECT_ID & id);
    CNWSTile * GetTile(Vector vPosition);
    int32_t GoalMoveDenied(int32_t level, int32_t x, int32_t y);
    void UpdatePlayerAutomaps();
    int32_t ExploreArea(CNWSCreature * pCreature, int32_t x, int32_t y, int32_t nDepth);
    void InterTileDFSExploreArea(uint8_t * pTransTable, int32_t nDepth, int32_t x, int32_t y, float fEntranceX, float fEntranceY);
    int32_t InterTileDFS(int32_t level, int32_t depth, int32_t x, int32_t y, int32_t region);
    int32_t InterTileDFSGenerateSuccessors(int32_t level, int32_t x, int32_t y, int32_t region);
    int32_t InterTileDFSSoundPath(uint8_t * pTransTable, int32_t nDepth, int32_t x, int32_t y, int32_t nRegion);
    BOOL LoadArea(BOOL bLoadStateInfo = false, CResGFF * cOverrideGitGFF = nullptr, CResStruct * cOverrideGitTopLevelStruct = nullptr);
    virtual BOOL NoCreaturesOnLine(float fSourceX, float fSourceY, float fTargetX, float fTargetY, CPathfindInformation * pPathfindInfo, BOOL bCheckSourceOccluded = true, BOOL bIgnoreAssociates = false, OBJECT_ID * poidBlockingCreature = nullptr, BOOL bEvaluateOverlappingTarget = false);
    BOOL EvaluateOverlappingTargets(CPathfindInformation * pPathfindInfo, Vector vPosition, OBJECT_ID oidAreaCreature, float fSourceX, float fSourceY, float fBothCreaturesPersonalSpace, BOOL bCheckSourceOccluded, BOOL bEvaluateOverlappingTarget, OBJECT_ID * poidBlockingCreature);
    BOOL PackAreaIntoMessage(int32_t nX, int32_t nY, int32_t nZ, CNWSPlayer * pPlayer);
    uint32_t PlotGridPathEnhanced(CPathfindInformation * pcPathfindInformation, uint64_t nTimeSlice, bool bFinalAttempt);
    void GridSearchPath(int32_t nPathID);
    bool GridSearchPathInDirection(int32_t nStepNumber, int32_t nX, int32_t nY, int nDirectionX, int nDirectionY, bool bTestDirectLine, CNWSAreaGridPoint * pcSearch);
    uint32_t PlotGridPath(CPathfindInformation * pcPathfindInformation, uint64_t nTimeSlice);
    BOOL GridDFSearch(int32_t nStepNumber, int32_t nPathLength, int32_t nStepsToExplore, int32_t nX, int32_t nY, int32_t nZ);
    int32_t GridDFSGenerateSuccessors(int32_t nPathLength, int32_t nStepsToExplore, int32_t nX, int32_t nY, int32_t nZ, CNWSAreaGridSuccessors * * pcSuccessors);
    void GridDFSTransTableInitialize();
    int32_t GridDFSTransTableHash(int32_t nX, int32_t nY);
    BOOL GridDFSTransTableGet(int32_t nX, int32_t nY, int32_t * nShortestPath, int32_t * nStepsExplored);
    void GridDFSTransTablePut(int32_t nX, int32_t nY, int32_t nPathLength, int32_t nStepsExplored);
    uint32_t PlotPath(CPathfindInformation * pcPathfindInformation, uint64_t nTimeSlice);
    int32_t RemoveInterTileExit(int32_t nTileX, int32_t nTileY, int32_t nEntrance, int32_t nExit);
    BOOL RemoveObjectFromArea(OBJECT_ID id);
    void SaveArea(CERFFile * cSaveFile, CExoString & sName);
    void SaveGIT(CResGFF * pRes, CResStruct * pStruct, CExoArrayList<OBJECT_ID> & aPlayers, BOOL bSaveOIDs);
    void SaveGIT(CERFFile * cSaveFile, CExoString & sName, CExoArrayList<OBJECT_ID> & aPlayers);
    BOOL LoadGIT(BOOL bLoadStateInfo);
    void LoadGIT(CResGFF * pRes, CResStruct * pStruct, BOOL bLoadStateInfo);
    void SmoothCornerOptimize(int32_t nOldWayPoints, float * pfOldWayPoints, int32_t * nNewWayPoints, float * * pfNewWayPoints);
    int32_t SmoothPointsOnPath();
    void SmoothSelection(int32_t nOldWayPoints, float * pfOldWayPoitns, int32_t * nNewWayPoints, float * * pfNewWayPoints);
    void SmoothSelectNodes(int32_t nOldWayPoints, float * pfOldWayPoints, int32_t * nNewWayPoints, float * * pfNewWayPoints, int32_t bChopIntoMeterSegments, int32_t bSelectBestLines);
    int32_t TestDirectLine(float fStartX, float fStartY, float fEndX, float fEndY, float fPersonalSpace, float fCreatureHeight, BOOL bIgnoreClosedDoors = true);
    int32_t TestLineWalkable(float fStartX, float fStartY, float fEndX, float fEndY, float fPersonalSpace);
    void UnloadArea();
    void PlayVisualEffect(uint16_t nEffectId, Vector vPosition);
    BOOL PlotSoundPath(CPathfindInformation * pcPathfindInformation);
    BOOL GetFirstObjectIndiceByX(int32_t * nIndice, float fMinX);
    BOOL UpdatePositionInObjectsArray(CGameObject * pUpdateObject);
    BOOL InSubAreas(Vector vPosition, CExoArrayList<OBJECT_ID> * aSubAreasWithin);
    BOOL IntersectingLineSegment(Vector vStart, Vector vEnd, CExoArrayList<OBJECT_ID> * aIntersectingSubAreas);
    OBJECT_ID GetDoorCrossed(Vector vStart, Vector vEnd);
    void ApplyEffect(CGameEffect * pEffect, Vector vPosition, Vector vOrientation);
    BOOL ClearLineOfSight(Vector vSource, Vector vTarget, Vector * vImpact, OBJECT_ID * oidImpact, OBJECT_ID oidStart = 0x7f000000, OBJECT_ID oidTarget = 0x7f000000, BOOL bIgnoreTransDoors = false);
    virtual BOOL HandleTransparentDoors(float fSourceX, float fSourceY, float fTargetX, float fTargetY, float fMinZ, float fMaxZ, float fPersonalSpace, OBJECT_ID oidDeniedDoor, OBJECT_ID & oidBlockingDoor, BOOL bWalking, CExoArrayList<CGameObject *> * pExcludeList = nullptr, BOOL bIgnoreTransDoors = false);
    virtual BOOL GetIsIDInExcludeList(OBJECT_ID oidID, CExoArrayList<CGameObject *> * pExcludeList = nullptr);
    BOOL NoNoneWalkPolysInStaticObject(OBJECT_ID oidObject, float fSourceX, float fSourceY, float fTargetX, float fTargetY, float fMinZ, float fMaxZ, float fPersonalSpace, OBJECT_ID oidDeniedDoor, BOOL bWalking = false);
    void IncrementPlayersInArea();
    void DecrementPlayersInArea();
    uint8_t GetPVPSetting();
    int32_t GetSurfaceMaterial(Vector vPosition);
    BOOL PositionWalkable(Vector vPosition);
    void SetCurrentWeather(uint8_t nWeatherType, BOOL bWeatherStarted);
    BOOL LoadAreaHeader(CResStruct * pStruct);
    BOOL LoadTileSetInfo(CResStruct * pStruct);
    BOOL LoadCreatures(CResGFF * pRes, CResStruct * pStruct, BOOL bLoadStateInfo = false);
    BOOL LoadPlayers(CResGFF * pRes, CResStruct * pStruct);
    BOOL LoadItems(CResGFF * pRes, CResStruct * pStruct, BOOL bLoadStateInfo = false);
    BOOL LoadDoors(CResGFF * pRes, CResStruct * pStruct, BOOL bLoadStateInfo = false);
    BOOL LoadTriggers(CResGFF * pRes, CResStruct * pStruct, BOOL bLoadStateInfo = false);
    BOOL LoadEncounters(CResGFF * pRes, CResStruct * pStruct, BOOL bLoadStateInfo = false);
    BOOL LoadWaypoints(CResGFF * pRes, CResStruct * pStruct, BOOL bLoadStateInfo = false);
    BOOL LoadSounds(CResGFF * pRes, CResStruct * pStruct, BOOL bLoadStateInfo = false);
    BOOL LoadPlaceables(CResGFF * pRes, CResStruct * pStruct, BOOL bLoadStateInfo = false);
    BOOL LoadStores(CResGFF * pRes, CResStruct * pStruct, BOOL bLoadStateInfo = false);
    BOOL LoadAreaEffects(CResGFF * pRes, CResStruct * pStruct, BOOL bLoadStateInfo = false);
    BOOL LoadProperties(CResGFF * pRes, CResStruct * pStruct);
    void IncreaseAILevelPriority();
    void DecreaseAILevelPriority();
    void SaveCreatures(CResGFF * pRes, CResStruct * pTopLevelStruct, CExoArrayList<OBJECT_ID> & aCreatures, BOOL bSaveOIDs);
    void SaveItems(CResGFF * pRes, CResStruct * pTopLevelStruct, CExoArrayList<OBJECT_ID> & aItems, BOOL bSaveOIDs);
    void SaveDoors(CResGFF * pRes, CResStruct * pTopLevelStruct, CExoArrayList<OBJECT_ID> & aDoors, BOOL bSaveOIDs);
    void SaveTriggers(CResGFF * pRes, CResStruct * pTopLevelStruct, CExoArrayList<OBJECT_ID> & aTriggers, BOOL bSaveOIDs);
    void SaveEncounters(CResGFF * pRes, CResStruct * pTopLevelStruct, CExoArrayList<OBJECT_ID> & aEncounters, BOOL bSaveOIDs);
    void SaveWaypoints(CResGFF * pRes, CResStruct * pTopLevelStruct, CExoArrayList<OBJECT_ID> & aWaypoints, BOOL bSaveOIDs);
    void SaveSounds(CResGFF * pRes, CResStruct * pTopLevelStruct, CExoArrayList<OBJECT_ID> & aSounds, BOOL bSaveOIDs);
    void SavePlaceables(CResGFF * pRes, CResStruct * pTopLevelStruct, CExoArrayList<OBJECT_ID> & aPlaceables, BOOL bSaveOIDs);
    void SaveStores(CResGFF * pRes, CResStruct * pTopLevelStruct, CExoArrayList<OBJECT_ID> & aStores, BOOL bSaveOIDs);
    void SaveAreaEffects(CResGFF * pRes, CResStruct * pTopLevelStruct, CExoArrayList<OBJECT_ID> & aStores, BOOL bSaveOIDs);
    void SaveProperties(CResGFF * pRes, CResStruct * pTopLevelStruct);


#ifdef NWN_CLASS_EXTENSION_CNWSArea
    NWN_CLASS_EXTENSION_CNWSArea
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CNWSArea)
#endif

