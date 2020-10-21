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
#include "API/CExoArrayList.hpp"
#include "../Core/NWNXCore.hpp"

#include <cmath>
#include <sstream>

namespace Core {
    extern NWNXCore* g_core;
}

namespace NWNXLib::Utils {

using namespace API::Constants;

std::string ObjectIDToString(const ObjectID id)
{
    std::stringstream ss;
    ss << std::hex << id;
    return ss.str();
}

std::string GetCurrentScript()
{
    auto *pVM = API::Globals::VirtualMachine();
    if (!pVM || pVM->m_nRecursionLevel < 0)
        return std::string("");

    auto& script = pVM->m_pVirtualMachineScript[pVM->m_nRecursionLevel];
    if (script.m_sScriptName.IsEmpty())
        return std::string("");

    return std::string(script.m_sScriptName.CStr());
}
void ExecuteScript(const std::string& script, ObjectID oidOwner)
{
    CExoString exoStr = script.c_str();
    API::Globals::VirtualMachine()->RunScript(&exoStr, oidOwner, 1);
}


CNWSArea* AsNWSArea(CGameObject* obj)
{
    if (obj && obj->m_nObjectType == ObjectType::Area)
        return static_cast<CNWSArea*>(obj);
    return nullptr;
}
CNWSAreaOfEffectObject* AsNWSAreaOfEffectObject(CGameObject* obj)
{
    if (obj && obj->m_nObjectType == ObjectType::AreaOfEffect)
        return static_cast<CNWSAreaOfEffectObject*>(obj);
    return nullptr;
}
CNWSCreature* AsNWSCreature(CGameObject* obj)
{
    if (obj && obj->m_nObjectType == ObjectType::Creature)
        return static_cast<CNWSCreature*>(obj);
    return nullptr;
}
CNWSDoor* AsNWSDoor(CGameObject* obj)
{
    if (obj && obj->m_nObjectType == ObjectType::Door)
        return static_cast<CNWSDoor*>(obj);
    return nullptr;
}
CNWSEncounter* AsNWSEncounter(CGameObject* obj)
{
    if (obj && obj->m_nObjectType == ObjectType::Encounter)
        return static_cast<CNWSEncounter*>(obj);
    return nullptr;
}
CNWSItem* AsNWSItem(CGameObject* obj)
{
    if (obj && obj->m_nObjectType == ObjectType::Item)
        return static_cast<CNWSItem*>(obj);
    return nullptr;
}
CNWSModule* AsNWSModule(CGameObject* obj)
{
    if (obj && obj->m_nObjectType == ObjectType::Module)
        return static_cast<CNWSModule*>(obj);
    return nullptr;
}
CNWSObject* AsNWSObject(CGameObject* obj)
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
            return static_cast<CNWSObject*>(obj);
    }
    return nullptr;
}
CNWSPlaceable* AsNWSPlaceable(CGameObject* obj)
{
    if (obj && obj->m_nObjectType == ObjectType::Placeable)
        return static_cast<CNWSPlaceable*>(obj);
    return nullptr;
}
CNWSSoundObject* AsNWSSoundObject(CGameObject* obj)
{
    if (obj && obj->m_nObjectType == ObjectType::Sound)
        return static_cast<CNWSSoundObject*>(obj);
    return nullptr;
}
CNWSStore* AsNWSStore(CGameObject* obj)
{
    if (obj && obj->m_nObjectType == ObjectType::Store)
        return static_cast<CNWSStore*>(obj);
    return nullptr;
}
CNWSTrigger* AsNWSTrigger(CGameObject* obj)
{
    if (obj && obj->m_nObjectType == ObjectType::Trigger)
        return static_cast<CNWSTrigger*>(obj);
    return nullptr;
}
CNWSWaypoint* AsNWSWaypoint(CGameObject* obj)
{
    if (obj && obj->m_nObjectType == ObjectType::Waypoint)
        return static_cast<CNWSWaypoint*>(obj);
    return nullptr;
}

CGameObject* GetGameObject(ObjectID objectId)
{
    return API::Globals::AppManager()->m_pServerExoApp->GetGameObject(objectId);
}
CNWSModule* GetModule()
{
    return static_cast<CNWSModule*>(API::Globals::AppManager()->m_pServerExoApp->GetModule());
}

bool AcquireItem(CNWSItem *pItem, CGameObject *pOwner)
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

bool AddToArea(CGameObject *pObject, CNWSArea *pArea, float x, float y, float z)
{
    if (!pObject || !pArea)
        return false;

    switch (pObject->m_nObjectType)
    {
        case ObjectType::Creature:
            AsNWSCreature(pObject)->AddToArea(pArea, x, y, z, true);
            return true;
        case ObjectType::Placeable:
        {
            auto *pPlaceable = AsNWSPlaceable(pObject);
            pPlaceable->AddToArea(pArea, x, y, z, true);

            // If pDoor is trapped it needs to be added to the area's trap list for it to be detectable by players.
            if (pPlaceable->m_bTrapFlag)
            {
                pArea->m_pTrapList.Add(pPlaceable->m_idSelf);
            }
            return true;
        }
        case ObjectType::Waypoint:
            AsNWSWaypoint(pObject)->AddToArea(pArea, x, y, z, true);
            return true;
        case ObjectType::Door:
        {
            auto *pDoor = AsNWSDoor(pObject);
            pDoor->AddToArea(pArea, x, y, z, true);

            // If pDoor is trapped it needs to be added to the area's trap list for it to be detectable by players.
            if (pDoor->m_bTrapped)
            {
                pArea->m_pTrapList.Add(pDoor->m_idSelf);
            }
            return true;
        }
        case ObjectType::Store:
            AsNWSStore(pObject)->AddToArea(pArea, x, y, z, true);
            return true;
        case ObjectType::Trigger:
        {
            auto *pTrigger = AsNWSTrigger(pObject);
            pTrigger->AddToArea(pArea, x, y, z, true);

            // If pTrigger is a trap it needs to be added to the area's trap list for it to be detectable by players.
            if (pTrigger->m_bTrap)
            {
                pArea->m_pTrapList.Add(pTrigger->m_idSelf);
            }
            return true;
        }
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

bool operator==(Vector& v1, Vector& v2)
{
    return v1.x == v2.x && v1.y == v2.y && v1.z == v2.z;
}
bool operator!=(Vector& v1, Vector& v2)
{
    return v1.x != v2.x || v1.y != v2.y || v1.z != v2.z;
}

bool CompareVariables(CNWSScriptVarTable *pVars1, CNWSScriptVarTable *pVars2)
{
    // Fast paths
    if (pVars1->m_vars.size() == 0 && pVars2->m_vars.size() == 0)
        return true;
    if (pVars1->m_vars.size() != pVars2->m_vars.size())
        return false;

    for (auto& it : pVars1->m_vars)
    {
        auto name = it.first;
        if (pVars1->GetInt(name)    != pVars2->GetInt(name)      ||
            pVars1->GetFloat(name)  != pVars2->GetFloat(name)    ||
            pVars1->GetString(name) != pVars2->GetString(name)   ||
            pVars1->GetObject(name) != pVars2->GetObject(name))
           return false;

        auto loc1 = pVars1->GetLocation(name);
        auto loc2 = pVars2->GetLocation(name);
        if (loc1.m_oArea != loc2.m_oArea || loc1.m_vPosition != loc2.m_vPosition || loc1.m_vOrientation != loc2.m_vOrientation)
            return false;
    }
    return true;
}

CNWSScriptVarTable *GetScriptVarTable(CGameObject *pObject)
{
    if (!pObject)
        return nullptr;

    switch (pObject->m_nObjectType)
    {
        case ObjectType::Area:
            return &static_cast<CNWSArea*>(pObject)->m_ScriptVars;
        case ObjectType::Module:
            return &static_cast<CNWSModule*>(pObject)->m_ScriptVars;
        default:
            return &static_cast<CNWSObject*>(pObject)->m_ScriptVars;
    }
}

void DestroyGameEffect(CGameEffect* pEffect)
{
    if (pEffect)
    {
        auto *srv = API::Globals::AppManager()->m_pServerExoApp->m_pcExoAppInternal;
        srv->m_pVirtualMachineCommandImplementer->DestroyGameDefinedStructure(0, pEffect);
    }
}

std::string ExtractLocString(CExoLocString& locStr, int32_t nID, uint8_t bGender)
{
    CExoString str;
    locStr.GetStringLoc(nID, &str, bGender);

    return std::string(str.CStr());
}

void AddStealthEvent(int which, ObjectID oidSelf, ObjectID oidTarget)
{
    auto *pAIMaster = API::Globals::AppManager()->m_pServerExoApp->GetServerAIMaster();

    auto *pScriptEvent = new CScriptEvent();
    pScriptEvent->m_nType = ScriptEvent::OnPerception;
    pScriptEvent->SetInteger(0, which);
    pScriptEvent->SetObjectID(0, oidTarget);
    pAIMaster->AddEventDeltaTime(0, 0, oidTarget, oidSelf, Event::SignalEvent, pScriptEvent);
}

void AddObjectEnterAreaEvent(ObjectID oid, ObjectID oidArea)
{
    auto *pAIMaster = API::Globals::AppManager()->m_pServerExoApp->GetServerAIMaster();

    auto *pScriptEvent = new CScriptEvent;
    pScriptEvent->m_nType = ScriptEvent::OnObjectEnter;
    pAIMaster->AddEventDeltaTime(0, 0, oid, oidArea, Event::SignalEvent, pScriptEvent);
}

void AddObjectExitAreaEvent(ObjectID oid, ObjectID oidArea)
{
    auto *pAIMaster = API::Globals::AppManager()->m_pServerExoApp->GetServerAIMaster();

    auto *pScriptEvent = new CScriptEvent;
    pScriptEvent->m_nType = ScriptEvent::OnObjectExit;
    pAIMaster->AddEventDeltaTime(0, 0, oid, oidArea, Event::SignalEvent, pScriptEvent);
}

void AddOnAcquireItemEvent(
        ObjectID oidItemAcquired,
        ObjectID oidItemAcquiredBy,
        ObjectID oidItemAcquiredFrom,
        int32_t stackSize)
{
    auto *pAIMaster = API::Globals::AppManager()->m_pServerExoApp->GetServerAIMaster();

    auto *pScriptEvent = new CScriptEvent();
    pScriptEvent->m_nType = ScriptEvent::OnAcquireItem;
    pScriptEvent->SetObjectID(0, oidItemAcquired);
    pScriptEvent->SetObjectID(1, oidItemAcquiredBy);
    pScriptEvent->SetObjectID(2, oidItemAcquiredFrom);
    pScriptEvent->SetInteger(0, stackSize);
    pAIMaster->AddEventDeltaTime(0, 0, oidItemAcquired, Utils::GetModule()->m_idSelf, Event::SignalEvent, pScriptEvent);
}

void AddOnLoseItemEvent(
        ObjectID oidItemLost,
        ObjectID oidItemLostBy)
{
    auto *pAIMaster = API::Globals::AppManager()->m_pServerExoApp->GetServerAIMaster();

    auto *pScriptEvent = new CScriptEvent();
    pScriptEvent->m_nType = ScriptEvent::OnLoseItem;
    pScriptEvent->SetObjectID(0, oidItemLost);
    pAIMaster->AddEventDeltaTime(0, 0, oidItemLostBy, Utils::GetModule()->m_idSelf, Event::SignalEvent, pScriptEvent);
}

void AddDestroyObjectEvent(ObjectID oid)
{
    auto *pAIMaster = API::Globals::AppManager()->m_pServerExoApp->GetServerAIMaster();

    pAIMaster->AddEventDeltaTime(0, 0, oid, oid, Utils::Event::DestroyObject, nullptr);
}

int PushScriptContext(ObjectID oid, bool valid)
{
    auto vm = API::Globals::VirtualMachine();
    auto cmd = static_cast<CNWVirtualMachineCommands*>(vm->m_pCmdImplementer);

    if (vm->m_nRecursionLevel++ == -1)
    {
        vm->m_cRunTimeStack.InitializeStack();
        vm->m_cRunTimeStack.m_pVMachine = vm;
        vm->m_nInstructPtrLevel = 0;
        vm->m_nInstructionsExecuted = 0;
    }

    vm->m_oidObjectRunScript[vm->m_nRecursionLevel]    = oid;
    vm->m_bValidObjectRunScript[vm->m_nRecursionLevel] = valid;
    cmd->m_oidObjectRunScript    = vm->m_oidObjectRunScript[vm->m_nRecursionLevel];
    cmd->m_bValidObjectRunScript = vm->m_bValidObjectRunScript[vm->m_nRecursionLevel];

    return vm->m_cRunTimeStack.GetStackPointer();
}
int PopScriptContext()
{
    auto vm = API::Globals::VirtualMachine();
    auto cmd = static_cast<CNWVirtualMachineCommands*>(vm->m_pCmdImplementer);

    if (--vm->m_nRecursionLevel != -1)
    {
        cmd->m_oidObjectRunScript    = vm->m_oidObjectRunScript[vm->m_nRecursionLevel];
        cmd->m_bValidObjectRunScript = vm->m_bValidObjectRunScript[vm->m_nRecursionLevel];
    }

    return vm->m_cRunTimeStack.GetStackPointer();
}

void SetOrientation(CNWSObject *pObject, float facing)
{
    if (!pObject)
        return;

    float radians = facing * (M_PI / 180);
    auto vOrientation = Vector{std::cos(radians), std::sin(radians), 0.0f};

    if (auto *pPlaceable = Utils::AsNWSPlaceable(pObject))
        pPlaceable->SetOrientation(vOrientation);
    else
        pObject->SetOrientation(vOrientation);
}

bool IsValidCustomResourceDirectoryAlias(const std::string& alias)
{
    const auto& crda = Core::g_core->GetCustomResourceDirectoryAliases();
    return std::find(crda.begin(), crda.end(), alias) != crda.end();
}

}
