#pragma once

#include "API/Types.hpp"
#include "API/CGameObject.hpp"
#include "API/CNWSScriptVarTable.hpp"
#include "API/Vector.hpp"
#include "API/CGameEffect.hpp"
#include "API/CExoLocString.hpp
#include "API/CNWSMessage.hpp"
#include "Utils/String.hpp"

#include <string>
#include <cstring>


namespace NWNXLib::Utils {

std::string ObjectIDToString(const API::Types::ObjectID id);

std::string GetCurrentScript();
void ExecuteScript(const std::string& script, API::Types::ObjectID oidOwner);

// Since there's no RTTI, and NWN's dynamic casts don't work in NWNX.
// These return nullptr if the object type isn't right.
CNWSArea*               AsNWSArea(CGameObject* obj);
CNWSAreaOfEffectObject* AsNWSAreaOfEffectObject(CGameObject* obj);
CNWSCreature*           AsNWSCreature(CGameObject* obj);
CNWSDoor*               AsNWSDoor(CGameObject* obj);
CNWSEncounter*          AsNWSEncounter(CGameObject* obj);
CNWSItem*               AsNWSItem(CGameObject* obj);
CNWSModule*             AsNWSModule(CGameObject* obj);
CNWSObject*             AsNWSObject(CGameObject* obj);
CNWSPlaceable*          AsNWSPlaceable(CGameObject* obj);
CNWSSoundObject*        AsNWSSoundObject(CGameObject* obj);
CNWSStore*              AsNWSStore(CGameObject* obj);
CNWSTrigger*            AsNWSTrigger(CGameObject* obj);
CNWSWaypoint*           AsNWSWaypoint(CGameObject* obj);

CGameObject* GetGameObject(API::Types::ObjectID objectId);
CNWSModule* GetModule();

// Wrappers around non-virtual methods repeated for all NWS types
bool AcquireItem(CNWSItem *pItem, CGameObject *pOwner);
bool AddToArea(CGameObject *pObject, CNWSArea *pArea, float x, float y, float z);

bool operator==(Vector& v1, Vector& v2);
bool operator!=(Vector& v1, Vector& v2);

// Returns TRUE if the var tables have the same variables with same values
bool CompareVariables(CNWSScriptVarTable *pVars1, CNWSScriptVarTable *pVars2);
CNWSScriptVarTable *GetScriptVarTable(CGameObject *pObject);

void DestroyGameEffect(CGameEffect* pEffect);

std::string ExtractLocString(CExoLocString& locStr, int32_t nID = 0, uint8_t bGender = 0);

template <typename T>
T PeekMessage(CNWSMessage *pMessage, int32_t offset)
{
    static_assert(std::is_pod<T>::value);
    T value;
    uint8_t *ptr = pMessage->m_pnReadBuffer + pMessage->m_nReadBufferPtr + offset;
    std::memcpy(&value, ptr, sizeof(T));
    return value;
}

void AddStealthEvent(int32_t which, API::Types::ObjectID oidSelf, API::Types::ObjectID oidTarget);
void AddObjectEnterAreaEvent(API::Types::ObjectID oid, API::Types::ObjectID oidArea);
void AddObjectExitAreaEvent(API::Types::ObjectID oid, API::Types::ObjectID oidArea);
void AddOnAcquireItemEvent(API::Types::ObjectID oidItem, API::Types::ObjectID oidBy, API::Types::ObjectID oidFrom, int32_t stackSize);
void AddOnLoseItemEvent(API::Types::ObjectID oidItem, API::Types::ObjectID oidBy);
void AddDestroyObjectEvent(API::Types::ObjectID oid);

// Returns the SP
int PushScriptContext(API::Types::ObjectID oid, bool valid = true);
int PopScriptContext();

}
