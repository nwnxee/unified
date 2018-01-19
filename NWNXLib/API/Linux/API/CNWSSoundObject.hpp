#pragma once

#include <cstdint>

#include "CExoArrayListTemplatedCResRef.hpp"
#include "CExoArrayListTemplatedunsignedlong.hpp"
#include "CNWSObject.hpp"
#include "Vector.hpp"
#include "unknown_CNWSSoundObjectTimeOfDay.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CNWSArea;
struct CNWSMessage;
struct CResGFF;
struct CResStruct;

struct CNWSSoundObject
    : CNWSObject
{
    int32_t m_bIsActive;
    int32_t m_bPositional;
    int32_t m_bLooping;
    int32_t m_nVolume;
    int32_t m_nVolumeVariation;
    CNWSSoundObjectTimeOfDay m_Time;
    float m_nPitchVariation;
    uint32_t m_nHours;
    uint8_t m_nPriority;
    int32_t m_bRandomPosition;
    float m_nRandomXRange;
    float m_nRandomYRange;
    CExoArrayListTemplatedCResRef m_SoundList;
    uint32_t m_nInterval;
    uint32_t m_nIntervalVariance;
    float m_nMinDistance;
    float m_nMaxDistance;
    int32_t m_bContinuous;
    int32_t m_bRandom;

    // The below are auto generated stubs.
    CNWSSoundObject() = default;
    CNWSSoundObject(const CNWSSoundObject&) = default;
    CNWSSoundObject& operator=(const CNWSSoundObject&) = default;

    CNWSSoundObject(uint32_t);
    ~CNWSSoundObject();
    void AddToArea(CNWSArea*, int32_t);
    void AIUpdate();
    CNWSSoundObject* AsNWSSoundObject();
    void ChangePosition(Vector);
    void ChangeVolume(int32_t);
    void EventHandler(uint32_t, uint32_t, void*, uint32_t, uint32_t);
    CExoArrayListTemplatedunsignedlong GetPeopleInSoundRange();
    int32_t Load(CResGFF*, CResStruct*);
    void PackIntoMessage(CNWSMessage*);
    void Play();
    void RemoveFromArea();
    void Save(CResGFF*, CResStruct*);
    void Stop();
};

void CNWSSoundObject__CNWSSoundObjectCtor(CNWSSoundObject* thisPtr, uint32_t);
void CNWSSoundObject__CNWSSoundObjectDtor__0(CNWSSoundObject* thisPtr);
void CNWSSoundObject__AddToArea(CNWSSoundObject* thisPtr, CNWSArea*, int32_t);
void CNWSSoundObject__AIUpdate(CNWSSoundObject* thisPtr);
CNWSSoundObject* CNWSSoundObject__AsNWSSoundObject(CNWSSoundObject* thisPtr);
void CNWSSoundObject__ChangePosition(CNWSSoundObject* thisPtr, Vector);
void CNWSSoundObject__ChangeVolume(CNWSSoundObject* thisPtr, int32_t);
void CNWSSoundObject__EventHandler(CNWSSoundObject* thisPtr, uint32_t, uint32_t, void*, uint32_t, uint32_t);
CExoArrayListTemplatedunsignedlong CNWSSoundObject__GetPeopleInSoundRange(CNWSSoundObject* thisPtr);
int32_t CNWSSoundObject__Load(CNWSSoundObject* thisPtr, CResGFF*, CResStruct*);
void CNWSSoundObject__PackIntoMessage(CNWSSoundObject* thisPtr, CNWSMessage*);
void CNWSSoundObject__Play(CNWSSoundObject* thisPtr);
void CNWSSoundObject__RemoveFromArea(CNWSSoundObject* thisPtr);
void CNWSSoundObject__Save(CNWSSoundObject* thisPtr, CResGFF*, CResStruct*);
void CNWSSoundObject__Stop(CNWSSoundObject* thisPtr);

}

}
