#include "nwnx.hpp"

#include "HashTable32.hpp"

#include "API/Functions.hpp"
#include "API/Constants.hpp"
#include "API/CAppManager.hpp"
#include "API/CServerExoApp.hpp"
#include "API/CGameObject.hpp"
#include "API/CGameObjectArray.hpp"

#include "API/CNWSStore.hpp"
#include "API/CNWSItem.hpp"
#include "API/CNWSCreature.hpp"
#include "API/CNWSModule.hpp"
#include "API/CNWSArea.hpp"
#include "API/CNWSTrigger.hpp"
#include "API/CNWSPlaceable.hpp"
#include "API/CNWSDoor.hpp"
#include "API/CNWSAreaOfEffectObject.hpp"
#include "API/CNWSWaypoint.hpp"
#include "API/CNWSEncounter.hpp"
#include "API/CNWSSoundObject.hpp"

namespace Optimizations {

using namespace NWNXLib;
using namespace NWNXLib::API;

static HashTable32<CGameObject, 1024*1024> s_table;
static uint32_t s_nNextObjectArrayID[2];
static uint32_t s_nNextCharArrayID[2];

enum { InternalObject = 0, ExternalObject = 1};
enum { Success = 0, BadId = 1, NullGameObject = 4 };

static uint32_t GetNextID(void*, BOOL bInternal, BOOL bCharacter);
static uint8_t AddObjectAtPos(void*, uint32_t id, CGameObject *ptr);
static uint8_t AddExternalObject(void*, uint32_t &id, CGameObject *ptr);
static uint8_t AddInternalObject(void*, uint32_t &id, CGameObject *ptr, bool bCharacter);
static uint8_t Delete(void*, uint32_t id, CGameObject** ptr);
static uint8_t GetGameObject(void*, uint32_t id, CGameObject** ptr) __attribute__((hot));

static void SyncWithGameGOA();
static void SetupWrapperHooks();

void GameObjectLookup() __attribute__((constructor));
void GameObjectLookup()
{
    if (!Config::Get<bool>("GAME_OBJECT_LOOKUP", false))
        return;

    LOG_INFO("Using optimal CGameObjectArray implementation");

    s_table.Initialize();
    static Hooks::Hook s_gameObjectArrayCtorHook = Hooks::HookFunction(API::Functions::_ZN16CGameObjectArrayC1Ei,
        (void*)+[](CGameObjectArray* pThis) -> void
        {
            pThis->m_pArray                = nullptr;
            pThis->m_nNextObjectArrayID[0] = 0;
            pThis->m_nNextObjectArrayID[1] = 0;
            pThis->m_nNextCharArrayID[0]   = 0;
            pThis->m_nNextCharArrayID[1]   = 0;
            pThis->m_nLogGameObjectCache   = 0;
            pThis->m_nGameObjectCache      = 0;
            pThis->m_bClientMode           = false;
            pThis->m_nArraySize            = 0;
        }, Hooks::Order::Final);

    uint8_t (CGameObjectArray::* delete1Ptr)(OBJECT_ID, CGameObject**) = &CGameObjectArray::Delete;
    uint8_t (CGameObjectArray::* delete2Ptr)(OBJECT_ID) = &CGameObjectArray::Delete;

    static auto s_AddObjectAtPos    = Hooks::HookFunction(&CGameObjectArray::AddObjectAtPos, &AddObjectAtPos, Hooks::Order::Final);
    static auto s_AddExternalObject = Hooks::HookFunction(&CGameObjectArray::AddExternalObject, &AddExternalObject, Hooks::Order::Final);
    static auto s_AddInternalObject = Hooks::HookFunction(&CGameObjectArray::AddInternalObject, &AddInternalObject, Hooks::Order::Final);
    static auto s_Delete1           = Hooks::HookFunction(delete1Ptr, &Delete, Hooks::Order::Final);
    static auto s_Delete2           = Hooks::HookFunction(delete2Ptr, +[](void* p, uint32_t id) -> uint8_t { return Delete(p, id, nullptr); }, Hooks::Order::Final);
    static auto s_GetGameObject     = Hooks::HookFunction(&CGameObjectArray::GetGameObject, &GetGameObject, Hooks::Order::Final);

    s_nNextObjectArrayID[InternalObject] = 0x00000000;
    s_nNextCharArrayID[InternalObject]   = 0x7FFFFFFF;
    s_nNextObjectArrayID[ExternalObject] = 0x80000000;
    s_nNextCharArrayID[ExternalObject]   = 0xFFFFFFFF;

    SetupWrapperHooks();
}

static uint32_t GetNextID(void*, BOOL bInternal, BOOL bCharacter)
{
    int type = bInternal ? InternalObject : ExternalObject;
    uint32_t ret = bCharacter ? s_nNextCharArrayID[type]-- : s_nNextObjectArrayID[type]++;
    SyncWithGameGOA();
    return ret;
}

static uint8_t AddObjectAtPos(void*, uint32_t id, CGameObject *ptr)
{
    if (!ptr)
        return NullGameObject;

    return s_table.Add(id, ptr) ? Success : BadId;
}

static uint8_t AddExternalObject(void*, uint32_t &id, CGameObject *ptr)
{
    id |= 0x80000000;

    if ((id & 0x7F000000) == 0x7F000000)
    {
        if (id < 0xFF000001)
            return BadId;
        s_nNextCharArrayID[ExternalObject] = std::min(s_nNextCharArrayID[ExternalObject], id-1);
    }
    else
    {
        if (id < 0x80000000 || id > 0xFEFFFFFF)
            return BadId;
        s_nNextObjectArrayID[ExternalObject] = std::max(s_nNextObjectArrayID[ExternalObject], id+1);
    }
    SyncWithGameGOA();
    return AddObjectAtPos(nullptr, id, ptr);
}

static uint8_t AddInternalObject(void*, uint32_t &id, CGameObject *ptr, bool bCharacter)
{
    return AddObjectAtPos(nullptr, (id = GetNextID(nullptr, true, bCharacter)), ptr);
}

static uint8_t Delete(void*, uint32_t id, CGameObject** ptr)
{
    return s_table.Delete(id, ptr) ? Success : BadId;
}

static uint8_t GetGameObject(void*, uint32_t id, CGameObject** ptr)
{
    *ptr = s_table.Get(id);
    return *ptr ? Success : BadId;
}

static void SyncWithGameGOA()
{
    if (auto* pGameObjectArray = Globals::AppManager()->m_pServerExoApp->GetObjectArray())
    {
        pGameObjectArray->m_nNextObjectArrayID[0] = s_nNextObjectArrayID[0];
        pGameObjectArray->m_nNextObjectArrayID[1] = s_nNextObjectArrayID[1];
        pGameObjectArray->m_nNextCharArrayID[0]   = s_nNextCharArrayID[0];
        pGameObjectArray->m_nNextCharArrayID[1]   = s_nNextCharArrayID[1];
    }
}

static CGameObject*            GetGameObj      (CServerExoApp*, ObjectID oid) __attribute__((hot));
static CNWSStore*              GetStore        (CServerExoApp*, ObjectID oid) __attribute__((hot));
static CNWSItem*               GetItem         (CServerExoApp*, ObjectID oid) __attribute__((hot));
static CNWSCreature*           GetCreature     (CServerExoApp*, ObjectID oid) __attribute__((hot));
static CNWSModule*             GetModule       (CServerExoApp*, ObjectID oid) __attribute__((hot));
static CNWSArea*               GetArea         (CServerExoApp*, ObjectID oid) __attribute__((hot));
static CNWSTrigger*            GetTrigger      (CServerExoApp*, ObjectID oid) __attribute__((hot));
static CNWSPlaceable*          GetPlaceable    (CServerExoApp*, ObjectID oid) __attribute__((hot));
static CNWSDoor*               GetDoor         (CServerExoApp*, ObjectID oid) __attribute__((hot));
static CNWSAreaOfEffectObject* GetAreaOfEffect (CServerExoApp*, ObjectID oid) __attribute__((hot));
static CNWSWaypoint*           GetWaypoint     (CServerExoApp*, ObjectID oid) __attribute__((hot));
static CNWSEncounter*          GetEncounter    (CServerExoApp*, ObjectID oid) __attribute__((hot));
static CNWSSoundObject*        GetSoundObject  (CServerExoApp*, ObjectID oid) __attribute__((hot));

static void SetupWrapperHooks()
{
    static auto s_GetGameObj      = Hooks::HookFunction(&CServerExoApp::GetGameObject,                 &GetGameObj,      Hooks::Order::Final);
    static auto s_GetStore        = Hooks::HookFunction(&CServerExoApp::GetStoreByGameObjectID,        &GetStore,        Hooks::Order::Final);
    static auto s_GetItem         = Hooks::HookFunction(&CServerExoApp::GetItemByGameObjectID,         &GetItem,         Hooks::Order::Final);
    static auto s_GetCreature     = Hooks::HookFunction(&CServerExoApp::GetCreatureByGameObjectID,     &GetCreature,     Hooks::Order::Final);
    static auto s_GetModule       = Hooks::HookFunction(&CServerExoApp::GetModuleByGameObjectID,       &GetModule,       Hooks::Order::Final);
    static auto s_GetArea         = Hooks::HookFunction(&CServerExoApp::GetAreaByGameObjectID,         &GetArea,         Hooks::Order::Final);
    static auto s_GetTrigger      = Hooks::HookFunction(&CServerExoApp::GetTriggerByGameObjectID,      &GetTrigger,      Hooks::Order::Final);
    static auto s_GetPlaceable    = Hooks::HookFunction(&CServerExoApp::GetPlaceableByGameObjectID,    &GetPlaceable,    Hooks::Order::Final);
    static auto s_GetDoor         = Hooks::HookFunction(&CServerExoApp::GetDoorByGameObjectID,         &GetDoor,         Hooks::Order::Final);
    static auto s_GetAreaOfEffect = Hooks::HookFunction(&CServerExoApp::GetAreaOfEffectByGameObjectID, &GetAreaOfEffect, Hooks::Order::Final);
    static auto s_GetWaypoint     = Hooks::HookFunction(&CServerExoApp::GetWaypointByGameObjectID,     &GetWaypoint,     Hooks::Order::Final);
    static auto s_GetEncounter    = Hooks::HookFunction(&CServerExoApp::GetEncounterByGameObjectID,    &GetEncounter,    Hooks::Order::Final);
    static auto s_GetSoundObject  = Hooks::HookFunction(&CServerExoApp::GetSoundObjectByGameObjectID,  &GetSoundObject,  Hooks::Order::Final);
}

static CGameObject* GetGameObj(CServerExoApp*, ObjectID oid)
{
    return s_table.Get(oid);
}
static CNWSStore* GetStore(CServerExoApp*, ObjectID oid)
{
    auto* obj = s_table.Get(oid);
    if (obj && obj->m_nObjectType == Constants::ObjectType::Store)
        return static_cast<CNWSStore*>(obj);
    return nullptr;
}
static CNWSItem* GetItem(CServerExoApp*, ObjectID oid)
{
    auto* obj = s_table.Get(oid);
    if (obj && obj->m_nObjectType == Constants::ObjectType::Item)
        return static_cast<CNWSItem*>(obj);
    return nullptr;
}
static CNWSCreature* GetCreature(CServerExoApp*, ObjectID oid)
{
    auto* obj = s_table.Get(oid);
    if (obj && obj->m_nObjectType == Constants::ObjectType::Creature)
        return static_cast<CNWSCreature*>(obj);
    return nullptr;
}
static CNWSModule* GetModule(CServerExoApp*, ObjectID oid)
{
    auto* obj = s_table.Get(oid);
    if (obj && obj->m_nObjectType == Constants::ObjectType::Module)
        return static_cast<CNWSModule*>(obj);
    return nullptr;
}
static CNWSArea* GetArea(CServerExoApp*, ObjectID oid)
{
    auto* obj = s_table.Get(oid);
    if (obj && obj->m_nObjectType == Constants::ObjectType::Area)
        return static_cast<CNWSArea*>(obj);
    return nullptr;
}
static CNWSTrigger* GetTrigger(CServerExoApp*, ObjectID oid)
{
    auto* obj = s_table.Get(oid);
    if (obj && obj->m_nObjectType == Constants::ObjectType::Trigger)
        return static_cast<CNWSTrigger*>(obj);
    return nullptr;
}
static CNWSPlaceable* GetPlaceable(CServerExoApp*, ObjectID oid)
{
    auto* obj = s_table.Get(oid);
    if (obj && obj->m_nObjectType == Constants::ObjectType::Placeable)
        return static_cast<CNWSPlaceable*>(obj);
    return nullptr;
}
static CNWSDoor* GetDoor(CServerExoApp*, ObjectID oid)
{
    auto* obj = s_table.Get(oid);
    if (obj && obj->m_nObjectType == Constants::ObjectType::Door)
        return static_cast<CNWSDoor*>(obj);
    return nullptr;
}
static CNWSAreaOfEffectObject* GetAreaOfEffect(CServerExoApp*, ObjectID oid)
{
    auto* obj = s_table.Get(oid);
    if (obj && obj->m_nObjectType == Constants::ObjectType::AreaOfEffect)
        return static_cast<CNWSAreaOfEffectObject*>(obj);
    return nullptr;
}
static CNWSWaypoint* GetWaypoint(CServerExoApp*, ObjectID oid)
{
    auto* obj = s_table.Get(oid);
    if (obj && obj->m_nObjectType == Constants::ObjectType::Waypoint)
        return static_cast<CNWSWaypoint*>(obj);
    return nullptr;
}
static CNWSEncounter* GetEncounter(CServerExoApp*, ObjectID oid)
{
    auto* obj = s_table.Get(oid);
    if (obj && obj->m_nObjectType == Constants::ObjectType::Encounter)
        return static_cast<CNWSEncounter*>(obj);
    return nullptr;
}
static CNWSSoundObject* GetSoundObject(CServerExoApp*, ObjectID oid)
{
    auto* obj = s_table.Get(oid);
    if (obj && obj->m_nObjectType == Constants::ObjectType::Sound)
        return static_cast<CNWSSoundObject*>(obj);
    return nullptr;
}


}
