#pragma once

#include <cstdint>

#include "CExoArrayListTemplatedlongunsignedint.hpp"
#include "CExoLinkedListTemplatedNWAreaExpansion_st.hpp"
#include "CExoLocString.hpp"
#include "CExoString.hpp"
#include "CGameObject.hpp"
#include "CNWArea.hpp"
#include "CNWSScriptVarTable.hpp"
#include "CResHelperTemplatedCResARE2012u.hpp"
#include "CResRef.hpp"
#include "Vector.hpp"
#include "unknown_CExoArrayListTemplatedunsignedlong.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CERFFile;
struct CExoArrayListTemplatedCGameObjectPtr;
struct CGameEffect;
struct CNWSAmbientSound;
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
struct NWAreaHeader_st;

struct CNWSArea
    : CNWArea, CResHelperTemplatedCResARE2012u, CGameObject
{
    int32_t m_nPlayersInArea;
    CExoArrayListTemplatedlongunsignedint m_pTrapList;
    int32_t m_nObjectByNameIndex;
    uint32_t m_nLastHeartbeatScriptCalendarDay;
    uint32_t m_nLastHeartbeatScriptTimeOfDay;
    CExoLinkedListTemplatedNWAreaExpansion_st m_lstExpansions;
    CExoString m_sComments;
    CExoLocString m_lsName;
    CExoString m_sTag;
    CResRef m_refTileSet;
    CNWTileSet* m_pTileSet;
    CNWSTile* m_pTile;
    NWAreaHeader_st* m_pHeader;
    CExoString m_sScripts[4];
    int32_t m_nChanceOfFog;
    int32_t m_nAreaSpotModifier;
    int32_t m_nAreaListenModifier;
    CExoArrayListTemplatedlongunsignedint m_aGameObjects;
    int32_t m_nPosGameObjects;
    CExoArrayListTemplatedlongunsignedint m_aSubAreas;
    int32_t* m_pnInterTileTravel;
    float* m_pfInterTileExit;
    int32_t* m_pnInterTileRegionVisited;
    uint8_t* m_pnInterTileRegionDepths;
    int32_t m_nInterTileTravelLength;
    int32_t m_nInterTileGoalX;
    int32_t m_nInterTileGoalY;
    int32_t m_nInterTileGoalRegion;
    float m_fGoalTargetX;
    float m_fGoalTargetY;
    CPathfindInformation* m_pSearchInfo;
    CPathfindInformation* m_pSoundPathInfo;
    CNWSAreaGridTransTableEntry* m_pcGridTransTableEntry;
    int32_t g_nUnsmoothedWPList;
    float* g_pfUnsmoothedWPList;
    int32_t g_nSmoothedWPList;
    float* g_pfSmoothedWPList;
    float g_fPersonalSpace;
    int32_t m_bGridPathfindingTerminated;
    int32_t m_nGridNodesSearched;
    uint32_t m_oidLastEntered;
    uint32_t m_oidLastLeft;
    int32_t m_nCustomScriptEventId;
    CNWSAreaInterTileSuccessors* m_pcInterTileSuccessors;
    int32_t* m_pbInterTileDeniedExitCheck;
    int32_t m_bInterAreaDFSVisited;
    CNWSScriptVarTable m_ScriptVars;
    CNWSAmbientSound* m_pAmbientSound;
    uint8_t m_nWeatherType;
    int32_t m_bWeatherStarted;
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

    // The below are auto generated stubs.
    CNWSArea() = default;
    CNWSArea(const CNWSArea&) = default;
    CNWSArea& operator=(const CNWSArea&) = default;

    CNWSArea(CResRef, int32_t, uint32_t);
    ~CNWSArea();
    int32_t AddObjectToArea(uint32_t, int32_t);
    int32_t AIUpdate();
    void ApplyEffect(CGameEffect*, Vector, Vector);
    CNWSArea* AsNWSArea();
    void BudgeCreatures(const Vector&, const Vector&, const Vector&, uint32_t, int32_t);
    int32_t ClearLineOfSight(Vector, Vector, Vector*, uint32_t*, uint32_t, uint32_t, int32_t);
    Vector ComputeAwayVector(Vector, Vector, float, CPathfindInformation*);
    int32_t ComputeBestCorner(float, float, float, float, float, float, float, float, float*, float*, float*, float*);
    float ComputeHeight(Vector);
    int32_t ComputeNonVisibleLocation(Vector, CPathfindInformation*, int32_t, Vector*, float);
    float ComputePathDistance(int32_t, float*);
    int32_t ComputeSafeLocation(Vector, float, CPathfindInformation*, int32_t, Vector*);
    int32_t ComputeSafeLocationInDirection(Vector, Vector, float, CPathfindInformation*, int32_t, Vector*);
    int32_t CountAreaTransitionTriggers(uint32_t*, int32_t, uint32_t*);
    int32_t CountVisibleToPlayers(Vector, int32_t);
    void DecreaseAILevelPriority();
    void DecrementPlayersInArea();
    int32_t EvaluateOverlappingTargets(CPathfindInformation*, Vector, uint32_t, float, float, float, int32_t, int32_t, uint32_t*);
    void EventHandler(uint32_t, uint32_t, void*, uint32_t, uint32_t);
    int32_t ExploreArea(CNWSCreature*, int32_t, int32_t, int32_t);
    int32_t GenerateInterTilePath(int32_t*, int32_t, int32_t, int32_t);
    uint32_t GetDoorCrossed(Vector, Vector);
    int32_t GetFirstObjectInArea(uint32_t&);
    int32_t GetFirstObjectIndiceByX(int32_t*, float);
    int32_t GetIsIDInExcludeList(uint32_t, CExoArrayListTemplatedCGameObjectPtr*);
    int32_t GetNextObjectInArea(uint32_t&);
    unsigned char GetPVPSetting();
    int32_t GetSurfaceMaterial(Vector);
    void GetTile(Vector);
    int32_t GoalMoveDenied(int32_t, int32_t, int32_t);
    int32_t GridDFSearch(int32_t, int32_t, int32_t, int32_t, int32_t, int32_t);
    int32_t GridDFSGenerateSuccessors(int32_t, int32_t, int32_t, int32_t, int32_t, CNWSAreaGridSuccessors**);
    int32_t GridDFSTransTableGet(int32_t, int32_t, int32_t*, int32_t*);
    int32_t GridDFSTransTableHash(int32_t, int32_t);
    void GridDFSTransTableInitialize();
    void GridDFSTransTablePut(int32_t, int32_t, int32_t, int32_t);
    int32_t HandleTransparentDoors(float, float, float, float, float, float, float, uint32_t, uint32_t&, int32_t, CExoArrayListTemplatedCGameObjectPtr*, int32_t);
    void IncreaseAILevelPriority();
    void IncrementPlayersInArea();
    int32_t InSubAreas(Vector, CExoArrayListTemplatedunsignedlong*);
    int32_t IntersectingLineSegment(Vector, Vector, CExoArrayListTemplatedunsignedlong*);
    int32_t InterTileDFS(int32_t, int32_t, int32_t, int32_t, int32_t);
    void InterTileDFSExploreArea(unsigned char*, int32_t, int32_t, int32_t, float, float);
    int32_t InterTileDFSGenerateSuccessors(int32_t, int32_t, int32_t, int32_t);
    int32_t InterTileDFSSoundPath(unsigned char*, int32_t, int32_t, int32_t, int32_t);
    int32_t LoadArea(int32_t, CResGFF*, CResStruct*);
    int32_t LoadAreaEffects(CResGFF*, CResStruct*, int32_t);
    int32_t LoadAreaHeader(CResStruct*);
    int32_t LoadCreatures(CResGFF*, CResStruct*, int32_t);
    int32_t LoadDoors(CResGFF*, CResStruct*, int32_t);
    int32_t LoadEncounters(CResGFF*, CResStruct*, int32_t);
    int32_t LoadGIT(int32_t);
    void LoadGIT(CResGFF*, CResStruct*, int32_t);
    int32_t LoadItems(CResGFF*, CResStruct*, int32_t);
    int32_t LoadPlaceables(CResGFF*, CResStruct*, int32_t);
    int32_t LoadPlayers(CResGFF*, CResStruct*);
    int32_t LoadProperties(CResGFF*, CResStruct*);
    int32_t LoadSounds(CResGFF*, CResStruct*, int32_t);
    int32_t LoadStores(CResGFF*, CResStruct*, int32_t);
    int32_t LoadTileSetInfo(CResStruct*);
    int32_t LoadTriggers(CResGFF*, CResStruct*, int32_t);
    int32_t LoadWaypoints(CResGFF*, CResStruct*, int32_t);
    int32_t NoCreaturesOnLine(float, float, float, float, CPathfindInformation*, int32_t, int32_t, uint32_t*, int32_t);
    int32_t NoNoneWalkPolysInStaticObject(uint32_t, float, float, float, float, float, float, float, uint32_t, int32_t);
    CNWSArea* NWAreaAsNWSArea();
    int32_t PackAreaIntoMessage(int32_t, int32_t, int32_t, CNWSPlayer*);
    void PlayVisualEffect(uint16_t, Vector);
    uint32_t PlotGridPath(CPathfindInformation*, uint64_t);
    uint32_t PlotPath(CPathfindInformation*, uint64_t);
    int32_t PlotSoundPath(CPathfindInformation*);
    int32_t PositionWalkable(Vector);
    int32_t RemoveInterTileExit(int32_t, int32_t, int32_t, int32_t);
    int32_t RemoveObjectFromArea(uint32_t);
    void SaveArea(CERFFile*, CExoString&);
    void SaveAreaEffects(CResGFF*, CResStruct*, CExoArrayListTemplatedunsignedlong&, int32_t);
    void SaveCreatures(CResGFF*, CResStruct*, CExoArrayListTemplatedunsignedlong&, int32_t);
    void SaveDoors(CResGFF*, CResStruct*, CExoArrayListTemplatedunsignedlong&, int32_t);
    void SaveEncounters(CResGFF*, CResStruct*, CExoArrayListTemplatedunsignedlong&, int32_t);
    void SaveGIT(CERFFile*, CExoString&, CExoArrayListTemplatedunsignedlong&);
    void SaveGIT(CResGFF*, CResStruct*, CExoArrayListTemplatedunsignedlong&, int32_t);
    void SaveItems(CResGFF*, CResStruct*, CExoArrayListTemplatedunsignedlong&, int32_t);
    void SavePlaceables(CResGFF*, CResStruct*, CExoArrayListTemplatedunsignedlong&, int32_t);
    void SaveProperties(CResGFF*, CResStruct*);
    void SaveSounds(CResGFF*, CResStruct*, CExoArrayListTemplatedunsignedlong&, int32_t);
    void SaveStores(CResGFF*, CResStruct*, CExoArrayListTemplatedunsignedlong&, int32_t);
    void SaveTriggers(CResGFF*, CResStruct*, CExoArrayListTemplatedunsignedlong&, int32_t);
    void SaveWaypoints(CResGFF*, CResStruct*, CExoArrayListTemplatedunsignedlong&, int32_t);
    void SetCurrentWeather(unsigned char, int32_t);
    void SmoothCornerOptimize(int32_t, float*, int32_t*, float**);
    int32_t SmoothPointsOnPath();
    void SmoothSelection(int32_t, float*, int32_t*, float**);
    void SmoothSelectNodes(int32_t, float*, int32_t*, float**, int32_t, int32_t);
    int32_t TestDirectLine(float, float, float, float, float, float, int32_t);
    int32_t TestLineWalkable(float, float, float, float, float);
    int32_t TestSafeLocationPoint(Vector, CPathfindInformation*);
    void UnloadArea();
    void UpdatePlayerAutomaps();
    int32_t UpdatePositionInObjectsArray(CGameObject*);
};

void CNWSArea__CNWSAreaCtor__0(CNWSArea* thisPtr, CResRef, int32_t, uint32_t);
void CNWSArea__CNWSAreaDtor__0(CNWSArea* thisPtr);
int32_t CNWSArea__AddObjectToArea(CNWSArea* thisPtr, uint32_t, int32_t);
int32_t CNWSArea__AIUpdate(CNWSArea* thisPtr);
void CNWSArea__ApplyEffect(CNWSArea* thisPtr, CGameEffect*, Vector, Vector);
CNWSArea* CNWSArea__AsNWSArea(CNWSArea* thisPtr);
void CNWSArea__BudgeCreatures(CNWSArea* thisPtr, const Vector&, const Vector&, const Vector&, uint32_t, int32_t);
int32_t CNWSArea__ClearLineOfSight(CNWSArea* thisPtr, Vector, Vector, Vector*, uint32_t*, uint32_t, uint32_t, int32_t);
Vector CNWSArea__ComputeAwayVector(CNWSArea* thisPtr, Vector, Vector, float, CPathfindInformation*);
int32_t CNWSArea__ComputeBestCorner(CNWSArea* thisPtr, float, float, float, float, float, float, float, float, float*, float*, float*, float*);
float CNWSArea__ComputeHeight(CNWSArea* thisPtr, Vector);
int32_t CNWSArea__ComputeNonVisibleLocation(CNWSArea* thisPtr, Vector, CPathfindInformation*, int32_t, Vector*, float);
float CNWSArea__ComputePathDistance(CNWSArea* thisPtr, int32_t, float*);
int32_t CNWSArea__ComputeSafeLocation(CNWSArea* thisPtr, Vector, float, CPathfindInformation*, int32_t, Vector*);
int32_t CNWSArea__ComputeSafeLocationInDirection(CNWSArea* thisPtr, Vector, Vector, float, CPathfindInformation*, int32_t, Vector*);
int32_t CNWSArea__CountAreaTransitionTriggers(CNWSArea* thisPtr, uint32_t*, int32_t, uint32_t*);
int32_t CNWSArea__CountVisibleToPlayers(CNWSArea* thisPtr, Vector, int32_t);
void CNWSArea__DecreaseAILevelPriority(CNWSArea* thisPtr);
void CNWSArea__DecrementPlayersInArea(CNWSArea* thisPtr);
int32_t CNWSArea__EvaluateOverlappingTargets(CNWSArea* thisPtr, CPathfindInformation*, Vector, uint32_t, float, float, float, int32_t, int32_t, uint32_t*);
void CNWSArea__EventHandler(CNWSArea* thisPtr, uint32_t, uint32_t, void*, uint32_t, uint32_t);
int32_t CNWSArea__ExploreArea(CNWSArea* thisPtr, CNWSCreature*, int32_t, int32_t, int32_t);
int32_t CNWSArea__GenerateInterTilePath(CNWSArea* thisPtr, int32_t*, int32_t, int32_t, int32_t);
uint32_t CNWSArea__GetDoorCrossed(CNWSArea* thisPtr, Vector, Vector);
int32_t CNWSArea__GetFirstObjectInArea(CNWSArea* thisPtr, uint32_t&);
int32_t CNWSArea__GetFirstObjectIndiceByX(CNWSArea* thisPtr, int32_t*, float);
int32_t CNWSArea__GetIsIDInExcludeList(CNWSArea* thisPtr, uint32_t, CExoArrayListTemplatedCGameObjectPtr*);
int32_t CNWSArea__GetNextObjectInArea(CNWSArea* thisPtr, uint32_t&);
unsigned char CNWSArea__GetPVPSetting(CNWSArea* thisPtr);
int32_t CNWSArea__GetSurfaceMaterial(CNWSArea* thisPtr, Vector);
void CNWSArea__GetTile(CNWSArea* thisPtr, Vector);
int32_t CNWSArea__GoalMoveDenied(CNWSArea* thisPtr, int32_t, int32_t, int32_t);
int32_t CNWSArea__GridDFSearch(CNWSArea* thisPtr, int32_t, int32_t, int32_t, int32_t, int32_t, int32_t);
int32_t CNWSArea__GridDFSGenerateSuccessors(CNWSArea* thisPtr, int32_t, int32_t, int32_t, int32_t, int32_t, CNWSAreaGridSuccessors**);
int32_t CNWSArea__GridDFSTransTableGet(CNWSArea* thisPtr, int32_t, int32_t, int32_t*, int32_t*);
int32_t CNWSArea__GridDFSTransTableHash(CNWSArea* thisPtr, int32_t, int32_t);
void CNWSArea__GridDFSTransTableInitialize(CNWSArea* thisPtr);
void CNWSArea__GridDFSTransTablePut(CNWSArea* thisPtr, int32_t, int32_t, int32_t, int32_t);
int32_t CNWSArea__HandleTransparentDoors(CNWSArea* thisPtr, float, float, float, float, float, float, float, uint32_t, uint32_t&, int32_t, CExoArrayListTemplatedCGameObjectPtr*, int32_t);
void CNWSArea__IncreaseAILevelPriority(CNWSArea* thisPtr);
void CNWSArea__IncrementPlayersInArea(CNWSArea* thisPtr);
int32_t CNWSArea__InSubAreas(CNWSArea* thisPtr, Vector, CExoArrayListTemplatedunsignedlong*);
int32_t CNWSArea__IntersectingLineSegment(CNWSArea* thisPtr, Vector, Vector, CExoArrayListTemplatedunsignedlong*);
int32_t CNWSArea__InterTileDFS(CNWSArea* thisPtr, int32_t, int32_t, int32_t, int32_t, int32_t);
void CNWSArea__InterTileDFSExploreArea(CNWSArea* thisPtr, unsigned char*, int32_t, int32_t, int32_t, float, float);
int32_t CNWSArea__InterTileDFSGenerateSuccessors(CNWSArea* thisPtr, int32_t, int32_t, int32_t, int32_t);
int32_t CNWSArea__InterTileDFSSoundPath(CNWSArea* thisPtr, unsigned char*, int32_t, int32_t, int32_t, int32_t);
int32_t CNWSArea__LoadArea(CNWSArea* thisPtr, int32_t, CResGFF*, CResStruct*);
int32_t CNWSArea__LoadAreaEffects(CNWSArea* thisPtr, CResGFF*, CResStruct*, int32_t);
int32_t CNWSArea__LoadAreaHeader(CNWSArea* thisPtr, CResStruct*);
int32_t CNWSArea__LoadCreatures(CNWSArea* thisPtr, CResGFF*, CResStruct*, int32_t);
int32_t CNWSArea__LoadDoors(CNWSArea* thisPtr, CResGFF*, CResStruct*, int32_t);
int32_t CNWSArea__LoadEncounters(CNWSArea* thisPtr, CResGFF*, CResStruct*, int32_t);
int32_t CNWSArea__LoadGIT__0(CNWSArea* thisPtr, int32_t);
void CNWSArea__LoadGIT__1(CNWSArea* thisPtr, CResGFF*, CResStruct*, int32_t);
int32_t CNWSArea__LoadItems(CNWSArea* thisPtr, CResGFF*, CResStruct*, int32_t);
int32_t CNWSArea__LoadPlaceables(CNWSArea* thisPtr, CResGFF*, CResStruct*, int32_t);
int32_t CNWSArea__LoadPlayers(CNWSArea* thisPtr, CResGFF*, CResStruct*);
int32_t CNWSArea__LoadProperties(CNWSArea* thisPtr, CResGFF*, CResStruct*);
int32_t CNWSArea__LoadSounds(CNWSArea* thisPtr, CResGFF*, CResStruct*, int32_t);
int32_t CNWSArea__LoadStores(CNWSArea* thisPtr, CResGFF*, CResStruct*, int32_t);
int32_t CNWSArea__LoadTileSetInfo(CNWSArea* thisPtr, CResStruct*);
int32_t CNWSArea__LoadTriggers(CNWSArea* thisPtr, CResGFF*, CResStruct*, int32_t);
int32_t CNWSArea__LoadWaypoints(CNWSArea* thisPtr, CResGFF*, CResStruct*, int32_t);
int32_t CNWSArea__NoCreaturesOnLine(CNWSArea* thisPtr, float, float, float, float, CPathfindInformation*, int32_t, int32_t, uint32_t*, int32_t);
int32_t CNWSArea__NoNoneWalkPolysInStaticObject(CNWSArea* thisPtr, uint32_t, float, float, float, float, float, float, float, uint32_t, int32_t);
CNWSArea* CNWSArea__NWAreaAsNWSArea(CNWSArea* thisPtr);
int32_t CNWSArea__PackAreaIntoMessage(CNWSArea* thisPtr, int32_t, int32_t, int32_t, CNWSPlayer*);
void CNWSArea__PlayVisualEffect(CNWSArea* thisPtr, uint16_t, Vector);
uint32_t CNWSArea__PlotGridPath(CNWSArea* thisPtr, CPathfindInformation*, uint64_t);
uint32_t CNWSArea__PlotPath(CNWSArea* thisPtr, CPathfindInformation*, uint64_t);
int32_t CNWSArea__PlotSoundPath(CNWSArea* thisPtr, CPathfindInformation*);
int32_t CNWSArea__PositionWalkable(CNWSArea* thisPtr, Vector);
int32_t CNWSArea__RemoveInterTileExit(CNWSArea* thisPtr, int32_t, int32_t, int32_t, int32_t);
int32_t CNWSArea__RemoveObjectFromArea(CNWSArea* thisPtr, uint32_t);
void CNWSArea__SaveArea(CNWSArea* thisPtr, CERFFile*, CExoString&);
void CNWSArea__SaveAreaEffects(CNWSArea* thisPtr, CResGFF*, CResStruct*, CExoArrayListTemplatedunsignedlong&, int32_t);
void CNWSArea__SaveCreatures(CNWSArea* thisPtr, CResGFF*, CResStruct*, CExoArrayListTemplatedunsignedlong&, int32_t);
void CNWSArea__SaveDoors(CNWSArea* thisPtr, CResGFF*, CResStruct*, CExoArrayListTemplatedunsignedlong&, int32_t);
void CNWSArea__SaveEncounters(CNWSArea* thisPtr, CResGFF*, CResStruct*, CExoArrayListTemplatedunsignedlong&, int32_t);
void CNWSArea__SaveGIT__0(CNWSArea* thisPtr, CERFFile*, CExoString&, CExoArrayListTemplatedunsignedlong&);
void CNWSArea__SaveGIT__1(CNWSArea* thisPtr, CResGFF*, CResStruct*, CExoArrayListTemplatedunsignedlong&, int32_t);
void CNWSArea__SaveItems(CNWSArea* thisPtr, CResGFF*, CResStruct*, CExoArrayListTemplatedunsignedlong&, int32_t);
void CNWSArea__SavePlaceables(CNWSArea* thisPtr, CResGFF*, CResStruct*, CExoArrayListTemplatedunsignedlong&, int32_t);
void CNWSArea__SaveProperties(CNWSArea* thisPtr, CResGFF*, CResStruct*);
void CNWSArea__SaveSounds(CNWSArea* thisPtr, CResGFF*, CResStruct*, CExoArrayListTemplatedunsignedlong&, int32_t);
void CNWSArea__SaveStores(CNWSArea* thisPtr, CResGFF*, CResStruct*, CExoArrayListTemplatedunsignedlong&, int32_t);
void CNWSArea__SaveTriggers(CNWSArea* thisPtr, CResGFF*, CResStruct*, CExoArrayListTemplatedunsignedlong&, int32_t);
void CNWSArea__SaveWaypoints(CNWSArea* thisPtr, CResGFF*, CResStruct*, CExoArrayListTemplatedunsignedlong&, int32_t);
void CNWSArea__SetCurrentWeather(CNWSArea* thisPtr, unsigned char, int32_t);
void CNWSArea__SmoothCornerOptimize(CNWSArea* thisPtr, int32_t, float*, int32_t*, float**);
int32_t CNWSArea__SmoothPointsOnPath(CNWSArea* thisPtr);
void CNWSArea__SmoothSelection(CNWSArea* thisPtr, int32_t, float*, int32_t*, float**);
void CNWSArea__SmoothSelectNodes(CNWSArea* thisPtr, int32_t, float*, int32_t*, float**, int32_t, int32_t);
int32_t CNWSArea__TestDirectLine(CNWSArea* thisPtr, float, float, float, float, float, float, int32_t);
int32_t CNWSArea__TestLineWalkable(CNWSArea* thisPtr, float, float, float, float, float);
int32_t CNWSArea__TestSafeLocationPoint(CNWSArea* thisPtr, Vector, CPathfindInformation*);
void CNWSArea__UnloadArea(CNWSArea* thisPtr);
void CNWSArea__UpdatePlayerAutomaps(CNWSArea* thisPtr);
int32_t CNWSArea__UpdatePositionInObjectsArray(CNWSArea* thisPtr, CGameObject*);

}

}
