#pragma once
#include "nwn_api.hpp"

#include "CCallbackHandlerBase.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CGameObject)
#endif

struct CNWCDoor;
struct CNWSDoor;
struct CNWSArea;
struct CNWSItem;
struct CNWCTrigger;
struct CNWSEncounter;
struct CNWSStore;
struct CNWCAreaOfEffectObject;
struct CNWCItem;
struct CNWSObject;
struct CNWCSoundObject;
struct CNWCCreature;
struct CNWSModule;
struct CNWCProjectile;
struct CNWSCreature;
struct CNWSPlayerTURD;
struct CNWSAreaOfEffectObject;
struct CNWSWaypoint;
struct CNWSPlaceable;
struct CNWSTrigger;
struct CNWCObject;
struct CNWCStore;
struct CNWCModule;
struct CNWCPlaceable;
struct CNWSSoundObject;
struct CNWCArea;


typedef uint32_t OBJECT_ID;


struct CGameObject : CCallbackHandlerBase
{
    OBJECT_ID m_idSelf;
    uint8_t m_nObjectType;
    void * m_pNwnxData;

    CGameObject(uint8_t nObjectType, OBJECT_ID oidId = 0x7f000000);
    virtual ~CGameObject();
    virtual void SetId(OBJECT_ID oidNew);
    virtual void ResetUpdateTimes(uint32_t nCalendarDay, uint32_t nTimeOfDay);
    virtual CNWCObject * AsNWCObject();
    virtual CNWSObject * AsNWSObject();
    virtual CNWCDoor * AsNWCDoor();
    virtual CNWSDoor * AsNWSDoor();
    virtual CNWCModule * AsNWCModule();
    virtual CNWSModule * AsNWSModule();
    virtual CNWCArea * AsNWCArea();
    virtual CNWSArea * AsNWSArea();
    virtual CNWCCreature * AsNWCCreature();
    virtual CNWSCreature * AsNWSCreature();
    virtual CNWCItem * AsNWCItem();
    virtual CNWSItem * AsNWSItem();
    virtual CNWCTrigger * AsNWCTrigger();
    virtual CNWSTrigger * AsNWSTrigger();
    virtual CNWCProjectile * AsNWCProjectile();
    virtual CNWSPlayerTURD * AsNWSPlayerTURD();
    virtual CNWSPlaceable * AsNWSPlaceable();
    virtual CNWCPlaceable * AsNWCPlaceable();
    virtual CNWSAreaOfEffectObject * AsNWSAreaOfEffectObject();
    virtual CNWCAreaOfEffectObject * AsNWCAreaOfEffectObject();
    virtual CNWSWaypoint * AsNWSWaypoint();
    virtual CNWSEncounter * AsNWSEncounter();
    virtual CNWCStore * AsNWCStore();
    virtual CNWSStore * AsNWSStore();
    virtual CNWSSoundObject * AsNWSSoundObject();
    virtual CNWCSoundObject * AsNWCSoundObject();


#ifdef NWN_CLASS_EXTENSION_CGameObject
    NWN_CLASS_EXTENSION_CGameObject
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CGameObject)
#endif

