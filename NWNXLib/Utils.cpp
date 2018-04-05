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

#include <sstream>

namespace NWNXLib {
namespace Utils {


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
    if (obj->m_nObjectType == API::Constants::OBJECT_TYPE_AREA)
        return static_cast<API::CNWSArea*>(obj);
    return nullptr;
}
API::CNWSAreaOfEffectObject* AsNWSAreaOfEffectObject(API::CGameObject* obj)
{
    if (obj->m_nObjectType == API::Constants::OBJECT_TYPE_AREA_OF_EFFECT)
        return static_cast<API::CNWSAreaOfEffectObject*>(obj);
    return nullptr;
}
API::CNWSCreature* AsNWSCreature(API::CGameObject* obj)
{
    if (obj->m_nObjectType == API::Constants::OBJECT_TYPE_CREATURE)
        return static_cast<API::CNWSCreature*>(obj);
    return nullptr;
}
API::CNWSDoor* AsNWSDoor(API::CGameObject* obj)
{
    if (obj->m_nObjectType == API::Constants::OBJECT_TYPE_DOOR)
        return static_cast<API::CNWSDoor*>(obj);
    return nullptr;
}
API::CNWSEncounter* AsNWSEncounter(API::CGameObject* obj)
{
    if (obj->m_nObjectType == API::Constants::OBJECT_TYPE_ENCOUNTER)
        return static_cast<API::CNWSEncounter*>(obj);
    return nullptr;
}
API::CNWSItem* AsNWSItem(API::CGameObject* obj)
{
    if (obj->m_nObjectType == API::Constants::OBJECT_TYPE_ITEM)
        return static_cast<API::CNWSItem*>(obj);
    return nullptr;
}
API::CNWSModule* AsNWSModule(API::CGameObject* obj)
{
    if (obj->m_nObjectType == API::Constants::OBJECT_TYPE_MODULE)
        return static_cast<API::CNWSModule*>(obj);
    return nullptr;
}
API::CNWSObject* AsNWSObject(API::CGameObject* obj)
{
    switch (obj->m_nObjectType)
    {
        case API::Constants::OBJECT_TYPE_AREA_OF_EFFECT:
        case API::Constants::OBJECT_TYPE_CREATURE:
        case API::Constants::OBJECT_TYPE_DOOR:
        case API::Constants::OBJECT_TYPE_ENCOUNTER:
        case API::Constants::OBJECT_TYPE_ITEM:
        case API::Constants::OBJECT_TYPE_PLACEABLE:
        case API::Constants::OBJECT_TYPE_SOUND:
        case API::Constants::OBJECT_TYPE_STORE:
        case API::Constants::OBJECT_TYPE_TRIGGER:
        case API::Constants::OBJECT_TYPE_WAYPOINT:
            return static_cast<API::CNWSObject*>(obj);
    }
    return nullptr;
}
API::CNWSPlaceable* AsNWSPlaceable(API::CGameObject* obj)
{
    if (obj->m_nObjectType == API::Constants::OBJECT_TYPE_PLACEABLE)
        return static_cast<API::CNWSPlaceable*>(obj);
    return nullptr;
}
API::CNWSSoundObject* AsNWSSoundObject(API::CGameObject* obj)
{
    if (obj->m_nObjectType == API::Constants::OBJECT_TYPE_SOUND)
        return static_cast<API::CNWSSoundObject*>(obj);
    return nullptr;
}
API::CNWSStore* AsNWSStore(API::CGameObject* obj)
{
    if (obj->m_nObjectType == API::Constants::OBJECT_TYPE_STORE)
        return static_cast<API::CNWSStore*>(obj);
    return nullptr;
}
API::CNWSTrigger* AsNWSTrigger(API::CGameObject* obj)
{
    if (obj->m_nObjectType == API::Constants::OBJECT_TYPE_TRIGGER)
        return static_cast<API::CNWSTrigger*>(obj);
    return nullptr;
}
API::CNWSWaypoint* AsNWSWaypoint(API::CGameObject* obj)
{
    if (obj->m_nObjectType == API::Constants::OBJECT_TYPE_WAYPOINT)
        return static_cast<API::CNWSWaypoint*>(obj);
    return nullptr;
}


}
}
