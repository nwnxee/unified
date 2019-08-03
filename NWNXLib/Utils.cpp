#include "Utils.hpp"
#include "API/Globals.hpp"
#include "API/CAppManager.hpp"
#include "API/CServerExoApp.hpp"
#include "API/CServerExoAppInternal.hpp"
#include "API/CVirtualMachine.hpp"
#include "API/CNWVirtualMachineCommands.hpp"
#include "API/Constants.hpp"
#include "API/CNWSArea.hpp"
#include "API/CNWSAreaOfEffectObject.hpp"
#include "API/CNWSCreature.hpp"
#include "API/CNWSDoor.hpp"
#include "API/CNWSEncounter.hpp"
#include "API/CNWSItem.hpp"
#include "API/CNWSModule.hpp"
#include "API/CNWSObject.hpp"
#include "API/CNWSPlaceable.hpp"
#include "API/CNWSSoundObject.hpp"
#include "API/CNWSStore.hpp"
#include "API/CNWSTrigger.hpp"
#include "API/CNWSWaypoint.hpp"
#include "API/CNWSScriptVarTable.hpp"
#include "API/CNWSScriptVar.hpp"
#include "API/CServerAIMaster.hpp"
#include "API/CScriptEvent.hpp"
#include "API/CScriptLocation.hpp"
#include "API/CExoString.hpp"

#include <sstream>

namespace NWNXLib {
namespace Utils {

using namespace API::Constants;

std::string ObjectIDToString(const API::Types::ObjectID id)
{
    std::stringstream ss;
    ss << std::hex << id;
    return ss.str();
}

std::string GetCurrentScript()
{
    auto *pVM = API::Globals::VirtualMachine();
    if (!pVM || !pVM->m_pVirtualMachineScript || pVM->m_nRecursionLevel < 0)
        return std::string("");

    auto& script = pVM->m_pVirtualMachineScript[pVM->m_nRecursionLevel];
    if (script.m_sScriptName.IsEmpty())
        return std::string("");

    return std::string(script.m_sScriptName.CStr());
}
void ExecuteScript(const std::string& script, API::Types::ObjectID oidOwner)
{
    API::CExoString exoStr = script.c_str();
    API::Globals::VirtualMachine()->RunScript(&exoStr, oidOwner, 1);
}


API::CNWSArea* AsNWSArea(API::CGameObject* obj)
{
    if (obj && obj->m_nObjectType == ObjectType::Area)
        return static_cast<API::CNWSArea*>(obj);
    return nullptr;
}
API::CNWSAreaOfEffectObject* AsNWSAreaOfEffectObject(API::CGameObject* obj)
{
    if (obj && obj->m_nObjectType == ObjectType::AreaOfEffect)
        return static_cast<API::CNWSAreaOfEffectObject*>(obj);
    return nullptr;
}
API::CNWSCreature* AsNWSCreature(API::CGameObject* obj)
{
    if (obj && obj->m_nObjectType == ObjectType::Creature)
        return static_cast<API::CNWSCreature*>(obj);
    return nullptr;
}
API::CNWSDoor* AsNWSDoor(API::CGameObject* obj)
{
    if (obj && obj->m_nObjectType == ObjectType::Door)
        return static_cast<API::CNWSDoor*>(obj);
    return nullptr;
}
API::CNWSEncounter* AsNWSEncounter(API::CGameObject* obj)
{
    if (obj && obj->m_nObjectType == ObjectType::Encounter)
        return static_cast<API::CNWSEncounter*>(obj);
    return nullptr;
}
API::CNWSItem* AsNWSItem(API::CGameObject* obj)
{
    if (obj && obj->m_nObjectType == ObjectType::Item)
        return static_cast<API::CNWSItem*>(obj);
    return nullptr;
}
API::CNWSModule* AsNWSModule(API::CGameObject* obj)
{
    if (obj && obj->m_nObjectType == ObjectType::Module)
        return static_cast<API::CNWSModule*>(obj);
    return nullptr;
}
API::CNWSObject* AsNWSObject(API::CGameObject* obj)
{
    if (!obj)
        return nullptr;

    switch (obj->m_nObjectType)
    {
        case ObjectType::AreaOfEffect:
        case ObjectType::Creature:
        case ObjectType::Door:
        case ObjectType::Encounter:
        case ObjectType::Item:
        case ObjectType::Placeable:
        case ObjectType::Sound:
        case ObjectType::Store:
        case ObjectType::Trigger:
        case ObjectType::Waypoint:
            return static_cast<API::CNWSObject*>(obj);
    }
    return nullptr;
}
API::CNWSPlaceable* AsNWSPlaceable(API::CGameObject* obj)
{
    if (obj && obj->m_nObjectType == ObjectType::Placeable)
        return static_cast<API::CNWSPlaceable*>(obj);
    return nullptr;
}
API::CNWSSoundObject* AsNWSSoundObject(API::CGameObject* obj)
{
    if (obj && obj->m_nObjectType == ObjectType::Sound)
        return static_cast<API::CNWSSoundObject*>(obj);
    return nullptr;
}
API::CNWSStore* AsNWSStore(API::CGameObject* obj)
{
    if (obj && obj->m_nObjectType == ObjectType::Store)
        return static_cast<API::CNWSStore*>(obj);
    return nullptr;
}
API::CNWSTrigger* AsNWSTrigger(API::CGameObject* obj)
{
    if (obj && obj->m_nObjectType == ObjectType::Trigger)
        return static_cast<API::CNWSTrigger*>(obj);
    return nullptr;
}
API::CNWSWaypoint* AsNWSWaypoint(API::CGameObject* obj)
{
    if (obj && obj->m_nObjectType == ObjectType::Waypoint)
        return static_cast<API::CNWSWaypoint*>(obj);
    return nullptr;
}

API::CGameObject* GetGameObject(API::Types::ObjectID objectId)
{
    return API::Globals::AppManager()->m_pServerExoApp->GetGameObject(objectId);
}
API::CNWSModule* GetModule()
{
    return static_cast<API::CNWSModule*>(API::Globals::AppManager()->m_pServerExoApp->GetModule());
}

bool AcquireItem(API::CNWSItem *pItem, API::CGameObject *pOwner)
{
    if (!pOwner || !pItem)
        return false;

    switch (pOwner->m_nObjectType)
    {
        case ObjectType::Creature:
            return AsNWSCreature(pOwner)->AcquireItem(&pItem, OBJECT_INVALID, OBJECT_INVALID, 0xFF, 0xFF, true, true);
        case ObjectType::Placeable:
            return AsNWSPlaceable(pOwner)->AcquireItem(&pItem, OBJECT_INVALID, 0xFF, 0xFF, true);
        case ObjectType::Store:
            return AsNWSStore(pOwner)->AcquireItem(pItem, true, 0xFF, 0xFF);
        case ObjectType::Item:
            return AsNWSItem(pOwner)->AcquireItem(&pItem, OBJECT_INVALID, 0xFF, 0xFF, true);
    }
    return false;
}

bool AddToArea(API::CGameObject *pObject, API::CNWSArea *pArea, float x, float y, float z)
{
    if (!pObject || !pArea)
        return false;

    switch (pObject->m_nObjectType)
    {
        case ObjectType::Creature:
            AsNWSCreature(pObject)->AddToArea(pArea, x, y, z, true);
            return true;
        case ObjectType::Placeable:
            AsNWSPlaceable(pObject)->AddToArea(pArea, x, y, z, true);
            return true;
        case ObjectType::Waypoint:
            AsNWSWaypoint(pObject)->AddToArea(pArea, x, y, z, true);
            return true;
        case ObjectType::Door:
            AsNWSDoor(pObject)->AddToArea(pArea, x, y, z, true);
            return true;
        case ObjectType::Store:
            AsNWSStore(pObject)->AddToArea(pArea, x, y, z, true);
            return true;
        case ObjectType::Trigger:
            AsNWSTrigger(pObject)->AddToArea(pArea, x, y, z, true);
            return true;
        case ObjectType::Encounter:
            AsNWSEncounter(pObject)->AddToArea(pArea, x, y, z, true);
            return true;
        case ObjectType::Item:
            AsNWSItem(pObject)->AddToArea(pArea, x, y, z, true);
            return true;
        case ObjectType::AreaOfEffect:
            AsNWSAreaOfEffectObject(pObject)->AddToArea(pArea, x, y, z, true);
            return true;
        case ObjectType::Sound:
            AsNWSSoundObject(pObject)->AddToArea(pArea, true);
            return true;
        default:
            return false;
    }
}

bool operator==(API::Vector& v1, API::Vector& v2)
{
    return v1.x == v2.x && v1.y == v2.y && v1.z == v2.z;
}
bool operator!=(API::Vector& v1, API::Vector& v2)
{
    return v1.x != v2.x || v1.y != v2.y || v1.z != v2.z;
}

bool CompareVariables(API::CNWSScriptVarTable *pVars1, API::CNWSScriptVarTable *pVars2)
{
    // Fast paths
    if (pVars1->m_lVarList.num == 0 && pVars2->m_lVarList.num == 0)
        return true;
    if (pVars1->m_lVarList.num != pVars2->m_lVarList.num)
        return false;

    // O(n^2) compare
    for (int32_t i = 0; i < pVars1->m_lVarList.num; i++)
    {
        API::CNWSScriptVar *pVar1 = &pVars1->m_lVarList.element[i];
        switch (pVar1->m_nType)
        {
            case 1:
                if (pVars2->GetInt(pVar1->m_sName) != pVar1->m_uValue.m_int)
                    return false;
                break;
            case 2:
                if (pVars2->GetFloat(pVar1->m_sName) != pVar1->m_uValue.m_float)
                    return false;
                break;
            case 3:
                if (pVars2->GetString(pVar1->m_sName) != *pVar1->m_uValue.m_string)
                    return false;
                break;
            case 4:
                if (pVars2->GetObject(pVar1->m_sName) != pVar1->m_uValue.m_objectId)
                    return false;
                break;
            case 5:
            {
                API::CScriptLocation& loc1 = *pVar1->m_uValue.m_location;
                API::CScriptLocation loc2 = pVars2->GetLocation(pVar1->m_sName);
                if (loc1.m_oArea != loc2.m_oArea || loc1.m_vPosition != loc2.m_vPosition || loc1.m_vOrientation != loc2.m_vOrientation)
                    return false;
                break;
            }
        }
    }
    return true;
}

API::CNWSScriptVarTable *GetScriptVarTable(API::CGameObject *pObject)
{
    if (!pObject)
        return nullptr;

    switch (pObject->m_nObjectType)
    {
        case ObjectType::Area:
            return &static_cast<API::CNWSArea*>(pObject)->m_ScriptVars;
        case ObjectType::Module:
            return &static_cast<API::CNWSModule*>(pObject)->m_ScriptVars;
        default:
            return &static_cast<API::CNWSObject*>(pObject)->m_ScriptVars;
    }
}

void DestroyGameEffect(API::CGameEffect* pEffect)
{
    if (pEffect)
    {
        auto *srv = API::Globals::AppManager()->m_pServerExoApp->m_pcExoAppInternal;
        srv->m_pVirtualMachineCommandImplementer->DestroyGameDefinedStructure(0, pEffect);
    }
}

std::string ExtractLocString(API::CExoLocString& locStr, int32_t nID, uint8_t bGender)
{
    API::CExoString str;
    locStr.GetStringLoc(nID, &str, bGender);

    return std::string(str.CStr());
}

void AddStealthEvent(int which, API::Types::ObjectID oidSelf, API::Types::ObjectID oidTarget)
{
    auto *pAIMaster = API::Globals::AppManager()->m_pServerExoApp->GetServerAIMaster();

    auto *pScriptEvent = new API::CScriptEvent();
    pScriptEvent->m_nType = ScriptEvent::OnPerception;
    pScriptEvent->SetInteger(0, which);
    pScriptEvent->SetObjectID(0, oidTarget);
    pAIMaster->AddEventDeltaTime(0, 0, oidTarget, oidSelf, Event::SignalEvent, pScriptEvent);
}

void AddObjectEnterAreaEvent(API::Types::ObjectID oid, API::Types::ObjectID oidArea)
{
    auto *pAIMaster = API::Globals::AppManager()->m_pServerExoApp->GetServerAIMaster();

    auto *pScriptEvent = new API::CScriptEvent;
    pScriptEvent->m_nType = ScriptEvent::OnObjectEnter;
    pAIMaster->AddEventDeltaTime(0, 0, oid, oidArea, Event::SignalEvent, pScriptEvent);
}

void AddObjectExitAreaEvent(API::Types::ObjectID oid, API::Types::ObjectID oidArea)
{
    auto *pAIMaster = API::Globals::AppManager()->m_pServerExoApp->GetServerAIMaster();

    auto *pScriptEvent = new API::CScriptEvent;
    pScriptEvent->m_nType = ScriptEvent::OnObjectExit;
    pAIMaster->AddEventDeltaTime(0, 0, oid, oidArea, Event::SignalEvent, pScriptEvent);
}

void AddOnAcquireItemEvent(
        API::Types::ObjectID oidItemAcquired,
        API::Types::ObjectID oidItemAcquiredBy,
        API::Types::ObjectID oidItemAcquiredFrom,
        int32_t stackSize)
{
    auto *pAIMaster = API::Globals::AppManager()->m_pServerExoApp->GetServerAIMaster();

    auto *pScriptEvent = new API::CScriptEvent();
    pScriptEvent->m_nType = ScriptEvent::OnAcquireItem;
    pScriptEvent->SetObjectID(0, oidItemAcquired);
    pScriptEvent->SetObjectID(1, oidItemAcquiredBy);
    pScriptEvent->SetObjectID(2, oidItemAcquiredFrom);
    pScriptEvent->SetInteger(0, stackSize);
    pAIMaster->AddEventDeltaTime(0, 0, oidItemAcquired, Utils::GetModule()->m_idSelf, Event::SignalEvent, pScriptEvent);
}

void AddOnLoseItemEvent(
        API::Types::ObjectID oidItemLost,
        API::Types::ObjectID oidItemLostBy)
{
    auto *pAIMaster = API::Globals::AppManager()->m_pServerExoApp->GetServerAIMaster();

    auto *pScriptEvent = new API::CScriptEvent();
    pScriptEvent->m_nType = ScriptEvent::OnLoseItem;
    pScriptEvent->SetObjectID(0, oidItemLost);
    pAIMaster->AddEventDeltaTime(0, 0, oidItemLostBy, Utils::GetModule()->m_idSelf, Event::SignalEvent, pScriptEvent);
}

}
}
