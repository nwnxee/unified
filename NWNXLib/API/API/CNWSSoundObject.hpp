#pragma once
#include "nwn_api.hpp"

#include "CExoArrayList.hpp"
#include "CNWSObject.hpp"
#include "CResRef.hpp"
#include "Vector.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CNWSSoundObject)
#endif

class CNWSArea;
class CNWSMessage;
class CResGFF;
class CResStruct;


typedef int BOOL;
typedef uint32_t OBJECT_ID;


class CNWSSoundObject : CNWSObject
{
    BOOL m_bIsActive;
    BOOL m_bPositional;
    BOOL m_bLooping;
    int32_t m_nVolume;
    int32_t m_nVolumeVariation;
    int m_Time;
    float m_nPitchVariation;
    uint32_t m_nHours;
    uint8_t m_nPriority;
    BOOL m_bRandomPosition;
    float m_nRandomXRange;
    float m_nRandomYRange;
    CExoArrayList<CResRef> m_SoundList;
    uint32_t m_nInterval;
    uint32_t m_nIntervalVariance;
    float m_nMinDistance;
    float m_nMaxDistance;
    BOOL m_bContinuous;
    BOOL m_bRandom;

    CNWSSoundObject(OBJECT_ID oidId = 0x7f000000);
    ~CNWSSoundObject();
    virtual CNWSSoundObject * AsNWSSoundObject();
    void AIUpdate();
    void EventHandler(uint32_t nEventId, OBJECT_ID nCallerObjectId, void * pScript, uint32_t nCalendarDay, uint32_t nTimeOfDay);
    BOOL Load(CResGFF * pRes, CResStruct * cSoundStruct);
    void Save(CResGFF * pRes, CResStruct * pStruct);
    void AddToArea(CNWSArea * pArea, BOOL bRunScripts = true);
    void RemoveFromArea();
    void PackIntoMessage(CNWSMessage * pMessage);
    void Play();
    void Stop();
    void ChangeVolume(int32_t nVolume);
    void ChangePosition(Vector vPos);
    CExoArrayList<OBJECT_ID> GetPeopleInSoundRange();


#ifdef NWN_CLASS_EXTENSION_CNWSSoundObject
    NWN_CLASS_EXTENSION_CNWSSoundObject
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CNWSSoundObject)
#endif

