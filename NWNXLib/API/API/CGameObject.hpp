#pragma once
#include "nwn_api.hpp"

// Used by nwnx extensions
#include <optional>
#include <functional>
#include <string>

#include "CCallbackHandlerBase.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CGameObject)
#endif

class CNWCArea;
class CNWCAreaOfEffectObject;
class CNWCCreature;
class CNWCDoor;
class CNWCItem;
class CNWCModule;
class CNWCObject;
class CNWCPlaceable;
class CNWCProjectile;
class CNWCSoundObject;
class CNWCStore;
class CNWCTrigger;
class CNWSArea;
class CNWSAreaOfEffectObject;
class CNWSCreature;
class CNWSDoor;
class CNWSEncounter;
class CNWSItem;
class CNWSModule;
class CNWSObject;
class CNWSPlaceable;
class CNWSPlayerTURD;
class CNWSSoundObject;
class CNWSStore;
class CNWSTrigger;
class CNWSWaypoint;


typedef uint32_t OBJECT_ID;


class CGameObject : CCallbackHandlerBase
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

