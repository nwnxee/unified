#pragma once

#include <cstdint>

#include "CEncounterListEntry.hpp"
#include "CExoLocString.hpp"
#include "CExoString.hpp"
#include "CNWSObject.hpp"
#include "CResRef.hpp"
#include "Vector.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CEncounterSpawnPoint;
struct CExoArrayListTemplatedfloat;
struct CNWSArea;
struct CResGFF;
struct CResStruct;

struct CNWSEncounter
    : CNWSObject
{
    uint16_t m_nActivateObjectArrayIndex;
    int32_t m_nFactionId;
    CExoLocString m_sLocalizedName;
    int32_t m_bActive;
    int32_t m_bReset;
    int32_t m_nResetTime;
    int32_t m_nSpawnMode;
    int32_t m_nDifficulty;
    int32_t m_nDifficultyIndex;
    int32_t m_nMinNumSpawnedCreatures;
    int32_t m_nMaxSpawnedCreatures;
    int32_t m_nNumSpawnedCreatures;
    uint32_t m_nLastHeartbeatScriptCalendarDay;
    uint32_t m_nLastHeartbeatScriptTimeOfDay;
    uint32_t m_nLastCreatureKilledCalendarDay;
    uint32_t m_nLastCreatureKilledTimeOfDay;
    int32_t m_bEncounterStarted;
    int32_t m_bEncounterExhausted;
    int32_t m_nAreaListArraySize;
    uint32_t* m_pEnemiesInActivateArea;
    int32_t m_nNumEnemiesInActivateArea;
    int32_t m_bNewEntry;
    Vector* m_pvActivateVertices;
    int32_t m_nNumActivateVertices;
    int32_t* m_pnOutlineVertices;
    int32_t m_nNumOutlineVertices;
    float m_fMinActivateX;
    float m_fMaxActivateX;
    float m_fMinActivateY;
    float m_fMaxActivateY;
    CEncounterListEntry* m_pEncounterList;
    int32_t m_nNumEncounterListEntries;
    CEncounterSpawnPoint* m_pSpawnPointList;
    int32_t m_nNumSpawnPoints;
    int32_t m_nEncounterLevel;
    int32_t m_nRespawnsMax;
    int32_t m_nRespawnsCurrent;
    float m_fCreaturePoints;
    float m_fSmallestCreature;
    float m_fEnemyRadiusPoints;
    float m_fSpawnPool;
    float m_fSpawnPoolActive;
    uint32_t m_oidLastEntered;
    uint32_t m_oidLastLeft;
    CExoString m_sScripts[5];
    CExoArrayListTemplatedfloat* m_pFractionalCRThresholds;
    int32_t m_nCustomScriptEventId;
    int32_t m_bPlayerTriggeredOnly;

    // The below are auto generated stubs.
    CNWSEncounter() = default;
    CNWSEncounter(const CNWSEncounter&) = default;
    CNWSEncounter& operator=(const CNWSEncounter&) = default;

    CNWSEncounter(uint32_t);
    ~CNWSEncounter();
    void AddCreaturesToSpawnList(CEncounterListEntry*, int32_t&, int32_t, CEncounterListEntry);
    void AddToActivateAreaList(uint32_t);
    void AddToArea(CNWSArea*, float, float, float, int32_t);
    void AIUpdate();
    CNWSEncounter* AsNWSEncounter();
    float CalculatePointsFromCR(float);
    void CalculateSpawnPool(float);
    void EventHandler(uint32_t, uint32_t, void*, uint32_t, uint32_t);
    CExoLocString& GetFirstName();
    int32_t GetInActivateArea(Vector);
    int32_t GetInActivateAreaList(uint32_t);
    int32_t LineSegmentIntersectActivateArea(Vector, Vector);
    int32_t LoadEncounter(CResGFF*, CResStruct*);
    void LoadFractionalCRData();
    void LoadFromTemplate(CResRef, int32_t, Vector*);
    void MakeSpawnList(CEncounterListEntry*, int32_t&);
    void PadOutCreatureCount(CEncounterListEntry*, int32_t&);
    int32_t ReadEncounterFromGff(CResGFF*, CResStruct*, int32_t, Vector*);
    void ReadEncounterScriptsFromGff(CResGFF*, CResStruct*);
    void RemoveFromActivateAreaList(uint32_t);
    void RemoveFromActiveCreatureCount(float, int32_t);
    void RemoveFromArea();
    int32_t SaveEncounter(CResGFF*, CResStruct*);
    void SetActive(int32_t);
    void SetDifficulty(int32_t);
    void SpawnEncounterCreatures();
    void SpawnIfAppropriate(uint32_t, float);
    void TallyEnemyRadiusPoints();
    void UpdateActivateAreaList(uint32_t);
};

void CNWSEncounter__CNWSEncounterCtor(CNWSEncounter* thisPtr, uint32_t);
void CNWSEncounter__CNWSEncounterDtor__0(CNWSEncounter* thisPtr);
void CNWSEncounter__AddCreaturesToSpawnList(CNWSEncounter* thisPtr, CEncounterListEntry*, int32_t&, int32_t, CEncounterListEntry);
void CNWSEncounter__AddToActivateAreaList(CNWSEncounter* thisPtr, uint32_t);
void CNWSEncounter__AddToArea(CNWSEncounter* thisPtr, CNWSArea*, float, float, float, int32_t);
void CNWSEncounter__AIUpdate(CNWSEncounter* thisPtr);
CNWSEncounter* CNWSEncounter__AsNWSEncounter(CNWSEncounter* thisPtr);
float CNWSEncounter__CalculatePointsFromCR(CNWSEncounter* thisPtr, float);
void CNWSEncounter__CalculateSpawnPool(CNWSEncounter* thisPtr, float);
void CNWSEncounter__EventHandler(CNWSEncounter* thisPtr, uint32_t, uint32_t, void*, uint32_t, uint32_t);
CExoLocString& CNWSEncounter__GetFirstName(CNWSEncounter* thisPtr);
int32_t CNWSEncounter__GetInActivateArea(CNWSEncounter* thisPtr, Vector);
int32_t CNWSEncounter__GetInActivateAreaList(CNWSEncounter* thisPtr, uint32_t);
int32_t CNWSEncounter__LineSegmentIntersectActivateArea(CNWSEncounter* thisPtr, Vector, Vector);
int32_t CNWSEncounter__LoadEncounter(CNWSEncounter* thisPtr, CResGFF*, CResStruct*);
void CNWSEncounter__LoadFractionalCRData(CNWSEncounter* thisPtr);
void CNWSEncounter__LoadFromTemplate(CNWSEncounter* thisPtr, CResRef, int32_t, Vector*);
void CNWSEncounter__MakeSpawnList(CNWSEncounter* thisPtr, CEncounterListEntry*, int32_t&);
void CNWSEncounter__PadOutCreatureCount(CNWSEncounter* thisPtr, CEncounterListEntry*, int32_t&);
int32_t CNWSEncounter__ReadEncounterFromGff(CNWSEncounter* thisPtr, CResGFF*, CResStruct*, int32_t, Vector*);
void CNWSEncounter__ReadEncounterScriptsFromGff(CNWSEncounter* thisPtr, CResGFF*, CResStruct*);
void CNWSEncounter__RemoveFromActivateAreaList(CNWSEncounter* thisPtr, uint32_t);
void CNWSEncounter__RemoveFromActiveCreatureCount(CNWSEncounter* thisPtr, float, int32_t);
void CNWSEncounter__RemoveFromArea(CNWSEncounter* thisPtr);
int32_t CNWSEncounter__SaveEncounter(CNWSEncounter* thisPtr, CResGFF*, CResStruct*);
void CNWSEncounter__SetActive(CNWSEncounter* thisPtr, int32_t);
void CNWSEncounter__SetDifficulty(CNWSEncounter* thisPtr, int32_t);
void CNWSEncounter__SpawnEncounterCreatures(CNWSEncounter* thisPtr);
void CNWSEncounter__SpawnIfAppropriate(CNWSEncounter* thisPtr, uint32_t, float);
void CNWSEncounter__TallyEnemyRadiusPoints(CNWSEncounter* thisPtr);
void CNWSEncounter__UpdateActivateAreaList(CNWSEncounter* thisPtr, uint32_t);

}

}
