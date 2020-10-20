#pragma once

#include "API/CGameObject.hpp"
#include "API/CNWSScriptVarTable.hpp"
#include "API/Vector.hpp"
#include "API/CGameEffect.hpp"
#include "API/CExoLocString.hpp"
#include "API/CNWSMessage.hpp"
#include "Utils/String.hpp"

#include <string>
#include <cstring>


namespace NWNXLib::Utils {

std::string ObjectIDToString(const ObjectID id);

std::string GetCurrentScript();
void ExecuteScript(const std::string& script, ObjectID oidOwner);

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

CGameObject* GetGameObject(ObjectID objectId);
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
inline T PeekMessage(CNWSMessage *pMessage, int32_t offset)
{
    static_assert(std::is_pod<T>::value);
    T value;
    uint8_t *ptr = pMessage->m_pnReadBuffer + pMessage->m_nReadBufferPtr + offset;
    std::memcpy(&value, ptr, sizeof(T));
    return value;
}

template <>
inline std::string PeekMessage<std::string>(CNWSMessage *pMessage, int32_t offset)
{
    std::string string;
    auto length = PeekMessage<int32_t>(pMessage, offset);

    string.reserve(length + 1);
    string.assign(reinterpret_cast<const char*>(pMessage->m_pnReadBuffer + pMessage->m_nReadBufferPtr + offset + 4), length);
    string[length] = '\0';

    return string;
}

template <>
inline CResRef PeekMessage<CResRef>(CNWSMessage *pMessage, int32_t offset)
{
    std::string string;

    string.reserve(16 + 1);
    string.assign(reinterpret_cast<const char*>(pMessage->m_pnReadBuffer + pMessage->m_nReadBufferPtr + offset), 16);
    string[16] = '\0';

    return CResRef(string);
}

void AddStealthEvent(int32_t which, ObjectID oidSelf, ObjectID oidTarget);
void AddObjectEnterAreaEvent(ObjectID oid, ObjectID oidArea);
void AddObjectExitAreaEvent(ObjectID oid, ObjectID oidArea);
void AddOnAcquireItemEvent(ObjectID oidItem, ObjectID oidBy, ObjectID oidFrom, int32_t stackSize);
void AddOnLoseItemEvent(ObjectID oidItem, ObjectID oidBy);
void AddDestroyObjectEvent(ObjectID oid);

// Returns the SP
int PushScriptContext(ObjectID oid, bool valid = true);
int PopScriptContext();

void SetOrientation(CNWSObject *pObject, float facing);

bool IsValidCustomResourceDirectoryAlias(const std::string& filename);
}
