#pragma once
#include "nwn_api.hpp"

#include "CEncounterListEntry.hpp"
#include "CExoArrayList.hpp"
#include "CExoLocString.hpp"
#include "CExoString.hpp"
#include "CNWSObject.hpp"
#include "CResRef.hpp"
#include "Vector.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CNWSEncounter)
#endif

struct CEncounterSpawnPoint;
struct CNWSArea;
struct CResGFF;
struct CResStruct;


typedef int BOOL;
typedef uint32_t OBJECT_ID;


struct CNWSEncounter : CNWSObject
{
    uint16_t m_nActivateObjectArrayIndex;
    int32_t m_nFactionId;
    CExoLocString m_sLocalizedName;
    BOOL m_bActive;
    BOOL m_bReset;
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
    BOOL m_bEncounterStarted;
    BOOL m_bEncounterExhausted;
    int32_t m_nAreaListArraySize;
    OBJECT_ID * m_pEnemiesInActivateArea;
    int32_t m_nNumEnemiesInActivateArea;
    BOOL m_bNewEntry;
    Vector * m_pvActivateVertices;
    int32_t m_nNumActivateVertices;
    float m_fMinActivateX;
    float m_fMaxActivateX;
    float m_fMinActivateY;
    float m_fMaxActivateY;
    CEncounterListEntry * m_pEncounterList;
    int32_t m_nNumEncounterListEntries;
    CEncounterSpawnPoint * m_pSpawnPointList;
    int32_t m_nNumSpawnPoints;
    int32_t m_nEncounterLevel;
    int32_t m_nRespawnsMax;
    int32_t m_nRespawnsCurrent;
    float m_fCreaturePoints;
    float m_fSmallestCreature;
    float m_fEnemyRadiusPoints;
    float m_fSpawnPool;
    float m_fSpawnPoolActive;
    OBJECT_ID m_oidLastEntered;
    OBJECT_ID m_oidLastLeft;
    CExoString m_sScripts[5];
    CExoArrayList<float> * m_pFractionalCRThresholds;
    int32_t m_nCustomScriptEventId;
    BOOL m_bPlayerTriggeredOnly;

    CNWSEncounter(OBJECT_ID oidId = 0x7f000000);
    ~CNWSEncounter();
    void AIUpdate();
    void EventHandler(uint32_t nEventId, OBJECT_ID nCallerObjectId, void * pScript, uint32_t nCalendarDay, uint32_t nTimeOfDay);
    void AddToArea(CNWSArea * pArea, float fX, float fY, float fZ, BOOL bRunScripts = true);
    void RemoveFromArea();
    BOOL GetInActivateArea(Vector vPosition);
    BOOL GetInActivateAreaList(OBJECT_ID oidObject);
    void SetActive(BOOL bActive);
    void SetDifficulty(int nDifficulty);
    void RemoveFromActiveCreatureCount(float fCreatureCRU, int32_t nRemovalReason);
    BOOL LoadEncounter(CResGFF * pRes, CResStruct * cResStruct);
    BOOL ReadEncounterFromGff(CResGFF * pRes, CResStruct * pGffStructWithEncounterData, BOOL bOverrideGeometry = false, Vector * pOverridePosition = nullptr);
    void ReadEncounterScriptsFromGff(CResGFF * pRes, CResStruct * pGffStructWithEncounterData);
    void LoadFromTemplate(CResRef cResRef, BOOL bOverrideGeometry = false, Vector * pOverridePosition = nullptr);
    BOOL SaveEncounter(CResGFF * pRes, CResStruct * pStruct);
    void SpawnIfAppropriate(OBJECT_ID oidEntered = 0x7f000000, float fFakeEnemyRadiusLevels = -1.0f);
    BOOL LineSegmentIntersectActivateArea(Vector vStartLine, Vector vEndLine);
    void AddToActivateAreaList(OBJECT_ID oidObject);
    void RemoveFromActivateAreaList(OBJECT_ID oidObject);
    void UpdateActivateAreaList(OBJECT_ID oidEntered);
    void CalculateSpawnPool(float fFakeEnemyRadiusLevels = -1.0f);
    void SpawnEncounterCreatures();
    void MakeSpawnList(CEncounterListEntry * pSpawnList, int32_t & nNumCreatures);
    void AddCreaturesToSpawnList(CEncounterListEntry * pCreatureList, int32_t & nNumCreatures, int32_t nCRUSplitIndex, CEncounterListEntry cCreature);
    float CalculatePointsFromCR(float fCR);
    void PadOutCreatureCount(CEncounterListEntry * pCreatureList, int32_t & nNumCreatures);
    void TallyEnemyRadiusPoints();
    void LoadFractionalCRData();

    inline CExoLocString &GetFirstName() override { return m_sLocalizedName; }

#ifdef NWN_CLASS_EXTENSION_CNWSEncounter
    NWN_CLASS_EXTENSION_CNWSEncounter
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CNWSEncounter)
#endif

