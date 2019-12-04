#pragma once
#include "nwn_api.hpp"

#include "CCallbackHandlerBase.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CGameObject)
#endif

struct CNWSEncounter;
struct CNWSStore;
struct CNWSWaypoint;
struct CNWCPlaceable;
struct CNWCAreaOfEffectObject;
struct CNWSSoundObject;
struct CNWCDoor;
struct CNWCItem;
struct CNWCStore;
struct CNWSTrigger;
struct CNWCTrigger;
struct CNWCCreature;
struct CNWSAreaOfEffectObject;
struct CNWCObject;
struct CNWSDoor;
struct CNWSArea;
struct CNWSItem;
struct CNWCSoundObject;
struct CNWSModule;
struct CNWSObject;
struct CNWCArea;
struct CNWSCreature;
struct CNWCModule;
struct CNWSPlayerTURD;
struct CNWCProjectile;
struct CNWSPlaceable;


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

