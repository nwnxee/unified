#include "Utils.hpp"
#include "API/Globals.hpp"
#include "API/CAppManager.hpp"
#include "API/CServerExoApp.hpp"
#include "API/CVirtualMachine.hpp"
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
    if (obj && obj->m_nObjectType == OBJECT_TYPE_AREA)
        return static_cast<API::CNWSArea*>(obj);
    return nullptr;
}
API::CNWSAreaOfEffectObject* AsNWSAreaOfEffectObject(API::CGameObject* obj)
{
    if (obj && obj->m_nObjectType == OBJECT_TYPE_AREA_OF_EFFECT)
        return static_cast<API::CNWSAreaOfEffectObject*>(obj);
    return nullptr;
}
API::CNWSCreature* AsNWSCreature(API::CGameObject* obj)
{
    if (obj && obj->m_nObjectType == OBJECT_TYPE_CREATURE)
        return static_cast<API::CNWSCreature*>(obj);
    return nullptr;
}
API::CNWSDoor* AsNWSDoor(API::CGameObject* obj)
{
    if (obj && obj->m_nObjectType == OBJECT_TYPE_DOOR)
        return static_cast<API::CNWSDoor*>(obj);
    return nullptr;
}
API::CNWSEncounter* AsNWSEncounter(API::CGameObject* obj)
{
    if (obj && obj->m_nObjectType == OBJECT_TYPE_ENCOUNTER)
        return static_cast<API::CNWSEncounter*>(obj);
    return nullptr;
}
API::CNWSItem* AsNWSItem(API::CGameObject* obj)
{
    if (obj && obj->m_nObjectType == OBJECT_TYPE_ITEM)
        return static_cast<API::CNWSItem*>(obj);
    return nullptr;
}
API::CNWSModule* AsNWSModule(API::CGameObject* obj)
{
    if (obj && obj->m_nObjectType == OBJECT_TYPE_MODULE)
        return static_cast<API::CNWSModule*>(obj);
    return nullptr;
}
API::CNWSObject* AsNWSObject(API::CGameObject* obj)
{
    if (!obj)
        return nullptr;

    switch (obj->m_nObjectType)
    {
        case OBJECT_TYPE_AREA_OF_EFFECT:
        case OBJECT_TYPE_CREATURE:
        case OBJECT_TYPE_DOOR:
        case OBJECT_TYPE_ENCOUNTER:
        case OBJECT_TYPE_ITEM:
        case OBJECT_TYPE_PLACEABLE:
        case OBJECT_TYPE_SOUND:
        case OBJECT_TYPE_STORE:
        case OBJECT_TYPE_TRIGGER:
        case OBJECT_TYPE_WAYPOINT:
            return static_cast<API::CNWSObject*>(obj);
    }
    return nullptr;
}
API::CNWSPlaceable* AsNWSPlaceable(API::CGameObject* obj)
{
    if (obj && obj->m_nObjectType == OBJECT_TYPE_PLACEABLE)
        return static_cast<API::CNWSPlaceable*>(obj);
    return nullptr;
}
API::CNWSSoundObject* AsNWSSoundObject(API::CGameObject* obj)
{
    if (obj && obj->m_nObjectType == OBJECT_TYPE_SOUND)
        return static_cast<API::CNWSSoundObject*>(obj);
    return nullptr;
}
API::CNWSStore* AsNWSStore(API::CGameObject* obj)
{
    if (obj && obj->m_nObjectType == OBJECT_TYPE_STORE)
        return static_cast<API::CNWSStore*>(obj);
    return nullptr;
}
API::CNWSTrigger* AsNWSTrigger(API::CGameObject* obj)
{
    if (obj && obj->m_nObjectType == OBJECT_TYPE_TRIGGER)
        return static_cast<API::CNWSTrigger*>(obj);
    return nullptr;
}
API::CNWSWaypoint* AsNWSWaypoint(API::CGameObject* obj)
{
    if (obj && obj->m_nObjectType == OBJECT_TYPE_WAYPOINT)
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
        case OBJECT_TYPE_CREATURE:
            return AsNWSCreature(pOwner)->AcquireItem(&pItem, OBJECT_INVALID, OBJECT_INVALID, 0xFF, 0xFF, true, true);
        case OBJECT_TYPE_PLACEABLE:
            return AsNWSPlaceable(pOwner)->AcquireItem(&pItem, OBJECT_INVALID, 0xFF, 0xFF, true);
        case OBJECT_TYPE_STORE:
            return AsNWSStore(pOwner)->AcquireItem(pItem, true, 0xFF, 0xFF);
        case OBJECT_TYPE_ITEM:
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
        case OBJECT_TYPE_CREATURE:
            AsNWSCreature(pObject)->AddToArea(pArea, x, y, z, true);
            return true;
        case OBJECT_TYPE_PLACEABLE:
            AsNWSPlaceable(pObject)->AddToArea(pArea, x, y, z, true);
            return true;
        case OBJECT_TYPE_WAYPOINT:
            AsNWSWaypoint(pObject)->AddToArea(pArea, x, y, z, true);
            return true;
        case OBJECT_TYPE_DOOR:
            AsNWSDoor(pObject)->AddToArea(pArea, x, y, z, true);
            return true;
        case OBJECT_TYPE_STORE:
            AsNWSStore(pObject)->AddToArea(pArea, x, y, z, true);
            return true;
        case OBJECT_TYPE_TRIGGER:
            AsNWSTrigger(pObject)->AddToArea(pArea, x, y, z, true);
            return true;
        case OBJECT_TYPE_ENCOUNTER:
            AsNWSEncounter(pObject)->AddToArea(pArea, x, y, z, true);
            return true;
        case OBJECT_TYPE_ITEM:
            AsNWSItem(pObject)->AddToArea(pArea, x, y, z, true);
            return true;
        case OBJECT_TYPE_AREA_OF_EFFECT:
            AsNWSAreaOfEffectObject(pObject)->AddToArea(pArea, x, y, z, true);
            return true;
        case OBJECT_TYPE_SOUND:
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
                if (pVars2->GetInt(pVar1->m_sName) != reinterpret_cast<int32_t>(pVar1->m_pValue))
                    return false;
                break;
            case 2:
                if (pVars2->GetFloat(pVar1->m_sName) != *reinterpret_cast<float*>(&pVar1->m_pValue))
                    return false;
                break;
            case 3:
                if (pVars2->GetString(pVar1->m_sName) != *static_cast<API::CExoString*>(pVar1->m_pValue))
                    return false;
                break;
            case 4:
                if (pVars2->GetObject(pVar1->m_sName) != reinterpret_cast<uint32_t>(pVar1->m_pValue))
                    return false;
                break;
            case 5:
            {
                API::CScriptLocation loc1 = *reinterpret_cast<API::CScriptLocation*>(pVar1->m_pValue);
                API::CScriptLocation loc2 = pVars2->GetLocation(pVar1->m_sName);
                if (loc1.m_oArea != loc2.m_oArea || loc1.m_vPosition != loc2.m_vPosition || loc1.m_vOrientation != loc2.m_vOrientation)
                    return false;
                break;
            }
        }
    }
    return true;
}

}
}
