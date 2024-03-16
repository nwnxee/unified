#pragma once
#include "nwn_api.hpp"

#include "CExoArrayList.hpp"
#include "CExoLocString.hpp"
#include "CExoString.hpp"
#include "CNWSObject.hpp"
#include "CResRef.hpp"
#include "Vector.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CNWSTrigger)
#endif

struct CNWSArea;
struct CResGFF;
struct CResStruct;
struct CScriptLocation;


typedef int BOOL;
typedef uint32_t OBJECT_ID;


struct CNWSTrigger : CNWSObject
{
    CExoLocString m_sLocalizedName;
    CExoString m_sDescriptionOverride;
    CExoString m_sScripts[7];
    CExoString m_sKey;
    int32_t m_nVertices;
    Vector * m_pvVertices;
    OBJECT_ID m_oidLastEntered;
    OBJECT_ID m_oidLastLeft;
    OBJECT_ID m_oidLastDisarmed;
    CExoArrayList<OBJECT_ID> m_poidCreatures;
    int32_t m_nFactionId;
    BOOL m_bTrap;
    BOOL m_bDetectable;
    BOOL m_bDisarmable;
    BOOL m_bFlagged;
    BOOL m_bAutoRemoveKey;
    BOOL m_bOneShot;
    uint8_t m_nBaseType;
    int32_t m_nDCDetectCheck;
    int32_t m_nDCDisarmCheck;
    BOOL m_bRecoverable;
    BOOL m_bTrapIsActive;
    uint16_t m_nObjectArrayIndex;
    float m_fTriggerHeight;
    OBJECT_ID m_oidCreator;
    float m_fBoundingBoxMinX;
    float m_fBoundingBoxMaxX;
    float m_fBoundingBoxMinY;
    float m_fBoundingBoxMaxY;
    int32_t m_nCustomScriptEventId;
    uint8_t m_nCursor;
    uint32_t m_nLastHeartbeatScriptTimeOfDay;
    uint32_t m_nLastHeartbeatScriptCalendarDay;
    uint16_t m_nLoadScreenID;

    CNWSTrigger(OBJECT_ID oidId = 0x7f000000);
    ~CNWSTrigger();
    void AddToArea(CNWSArea * pArea, float fX, float fY, float fZ, BOOL bRunScripts = true);
    void AIUpdate();
    Vector GetFacingPosition();
    virtual CNWSTrigger * AsNWSTrigger();
    void ComputeBoundingBox(float * fXMin, float * fYMin, float * fXMax, float * fYMax);
    void EventHandler(uint32_t nEventId, OBJECT_ID nCallerObjectId, void * pScript, uint32_t nCalendarDay, uint32_t nTimeOfDay);
    OBJECT_ID GetTargetArea();
    BOOL GetClosestPointWithinTrigger(Vector vCurrentPosition, Vector * vTriggerPoint);
    BOOL CalculateNearestPoint(Vector vPosition, Vector * vIntersectionPoint);
    BOOL InTrigger(Vector vPosition);
    CExoString * GetScriptName(int32_t nScript);
    BOOL LoadFromTemplate(CResRef cResRef);
    BOOL LoadTrigger(CResGFF * pRes, CResStruct * cTriggerStruct);
    BOOL SaveTrigger(CResGFF * pRes, CResStruct * pStruct);
    void RemoveFromArea();
    void CreateNewGeometry(float fGeometrySize, Vector vPosition, CNWSArea * pArea);
    void CreateNewGeometry(float fGeometrySize, CScriptLocation * lTriggerLocation, CNWSArea * pArea);
    BOOL LineSegmentIntersectTrigger(Vector vStartLine, Vector vEndLine);
    BOOL GetCanFireTrapOnObject(OBJECT_ID oidCreatureEntered, BOOL bForceSet);
    void OnEnterTrap(BOOL bForceSet);

    inline CExoLocString &GetFirstName() override { return m_sLocalizedName; }

#ifdef NWN_CLASS_EXTENSION_CNWSTrigger
    NWN_CLASS_EXTENSION_CNWSTrigger
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CNWSTrigger)
#endif

