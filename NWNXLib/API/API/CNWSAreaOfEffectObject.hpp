#pragma once
#include "nwn_api.hpp"

#include "CExoString.hpp"
#include "CNWSObject.hpp"
#include "Vector.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CNWSAreaOfEffectObject)
#endif

struct CNWSArea;
struct CResGFF;
struct CResStruct;


typedef int BOOL;
typedef uint32_t OBJECT_ID;


struct CNWSAreaOfEffectObject : CNWSObject
{
    uint16_t m_nObjectArrayIndex;
    int32_t m_nAreaEffectId;
    uint8_t m_nShape;
    uint32_t m_nSpellId;
    float m_fRadius;
    float m_fWidth;
    float m_fLength;
    Vector * m_pVertices;
    OBJECT_ID m_oidCreator;
    OBJECT_ID m_oidLinkedToObj;
    OBJECT_ID m_oidLastEntered;
    OBJECT_ID m_oidLastLeft;
    int32_t m_nSpellSaveDC;
    int32_t m_nSpellCasterLevel;
    CExoString m_sScripts[4];
    uint32_t m_nLastHeartbeatScriptCalendarDay;
    uint32_t m_nLastHeartbeatScriptTimeOfDay;
    uint32_t m_nDuration;
    uint8_t m_nDurationType;

    CNWSAreaOfEffectObject(OBJECT_ID oidId = 0x7f000000);
    ~CNWSAreaOfEffectObject();
    void AIUpdate();
    void EventHandler(uint32_t nEventId, OBJECT_ID nCallerObjectId, void * pScript, uint32_t nCalendarDay, uint32_t nTimeOfDay);
    void AddToArea(CNWSArea * pArea, float fX, float fY, float fZ, BOOL bRunScripts = true);
    void RemoveFromArea();
    BOOL LineSegmentIntersectAreaOfEffect(Vector vStartLine, Vector vEndLine);
    BOOL InAreaOfEffect(Vector vPosition);
    BOOL LoadEffect(CResGFF * pRes, CResStruct * pStruct);
    BOOL SaveEffect(CResGFF * pRes, CResStruct * pStruct);
    void SetTargetObjID(OBJECT_ID oidValue);
    void LoadAreaEffect(int32_t nId);
    void SetDuration(uint8_t nDurationType, float fDuration = 0.0f);
    Vector GetPosition();
    void SetCreator(OBJECT_ID oidObject, int32_t nCasterLevel, int32_t nSpellId, uint8_t nMulticlass = 0, uint8_t nMetaType = 0, int32_t nSaveDC = 14, uint16_t nFeat = 0xFFFF, BOOL bSpontaneous = false);
    virtual uint32_t GetEffectSpellId();
    virtual void SetEffectSpellId(uint32_t nSpellId);
    void JumpToPoint(CNWSArea * pNewArea, const Vector & vNewPos);
    void MoveToPoint(const Vector & vNewPos);
    void SetShape(uint8_t nShape, float f1 = 0.0f, float f2 = 0.0f);
    void UpdateSubAreas(Vector * NewPos = nullptr);
    void RemoveFromSubAreas(BOOL bInstantEvents = false);


#ifdef NWN_CLASS_EXTENSION_CNWSAreaOfEffectObject
    NWN_CLASS_EXTENSION_CNWSAreaOfEffectObject
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CNWSAreaOfEffectObject)
#endif

