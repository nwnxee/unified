#pragma once

#include "API/Types.hpp"
#include "API/CGameObject.hpp"
#include "API/CNWSScriptVarTable.hpp"
#include "API/Vector.hpp"
#include "API/CGameEffect.hpp"
#include "API/CExoLocString.hpp"
#include "API/CNWSMessage.hpp"
#include <string>
#include <cstring>


namespace NWNXLib {
namespace Utils {

std::string ObjectIDToString(const API::Types::ObjectID id);

std::string GetCurrentScript();
void ExecuteScript(const std::string& script, API::Types::ObjectID oidOwner);

// Since there's no RTTI, and NWN's dynamic casts don't work in NWNX.
// These return nullptr if the object type isn't right.
API::CNWSArea*               AsNWSArea(API::CGameObject* obj);
API::CNWSAreaOfEffectObject* AsNWSAreaOfEffectObject(API::CGameObject* obj);
API::CNWSCreature*           AsNWSCreature(API::CGameObject* obj);
API::CNWSDoor*               AsNWSDoor(API::CGameObject* obj);
API::CNWSEncounter*          AsNWSEncounter(API::CGameObject* obj);
API::CNWSItem*               AsNWSItem(API::CGameObject* obj);
API::CNWSModule*             AsNWSModule(API::CGameObject* obj);
API::CNWSObject*             AsNWSObject(API::CGameObject* obj);
API::CNWSPlaceable*          AsNWSPlaceable(API::CGameObject* obj);
API::CNWSSoundObject*        AsNWSSoundObject(API::CGameObject* obj);
API::CNWSStore*              AsNWSStore(API::CGameObject* obj);
API::CNWSTrigger*            AsNWSTrigger(API::CGameObject* obj);
API::CNWSWaypoint*           AsNWSWaypoint(API::CGameObject* obj);

API::CGameObject* GetGameObject(API::Types::ObjectID objectId);
API::CNWSModule* GetModule();

// Wrappers around non-virtual methods repeated for all NWS types
bool AcquireItem(API::CNWSItem *pItem, API::CGameObject *pOwner);
bool AddToArea(API::CGameObject *pObject, API::CNWSArea *pArea, float x, float y, float z);

bool operator==(API::Vector& v1, API::Vector& v2);
bool operator!=(API::Vector& v1, API::Vector& v2);

// Returns TRUE if the var tables have the same variables with same values
bool CompareVariables(API::CNWSScriptVarTable *pVars1, API::CNWSScriptVarTable *pVars2);
API::CNWSScriptVarTable *GetScriptVarTable(API::CGameObject *pObject);

void DestroyGameEffect(API::CGameEffect* pEffect);

std::string ExtractLocString(API::CExoLocString& locStr, int32_t nID = 0, uint8_t bGender = 0);

template <typename T>
T PeekMessage(API::CNWSMessage *pMessage, int32_t offset)
{
    static_assert(std::is_pod<T>::value);
    T value;
    uint8_t *ptr = pMessage->m_pnReadBuffer + pMessage->m_nReadBufferPtr + offset;
    std::memcpy(&value, ptr, sizeof(T));
    return value;
}

}

}
