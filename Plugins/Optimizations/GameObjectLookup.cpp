#include "nwnx.hpp"

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

static constexpr uint32_t ObjectsInNode = 4;
static constexpr uint32_t L0CacheSize = 4;

struct ObjectNode
{
    CGameObject* m_objectPtr[ObjectsInNode];
    uint32_t     m_objectId[ObjectsInNode];
    ObjectNode*  m_nextNode;
    uint32_t     m_count;
    uint8_t      m_padding[4]; // For cache line alignment
};
static_assert(sizeof(ObjectNode) == 64);

// DO NOT REARRANGE - optimal placement across cache lines
static struct alignas(64)
{
    CGameObject*   m_pCacheObjects[L0CacheSize];
    uint32_t       m_nCacheIds[L0CacheSize];
    ObjectNode*    m_pArray;
    uint32_t       m_nArraySize;
    uint32_t       m_nNextObjectArrayID[2];
    uint32_t       m_nNextCharArrayID[2];
} goa;

enum { InternalObject = 0, ExternalObject = 1};
enum { Success = 0, BadId = 1, NullGameObject = 4 };

static void Initialize(uint32_t nLogGameObjectCache);
static void Finalize();
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

    static Hooks::Hook s_gameObjectArrayCtorHook = Hooks::HookFunction(API::Functions::_ZN16CGameObjectArrayC1Ei,
        (void*)+[](CGameObjectArray* pThis) -> void
        {
            s_gameObjectArrayCtorHook->CallOriginal<void>(pThis);

            // Reading the config is currently.. complicated in NWNX, so just
            // let the CGOA constructor read it, and then undo the allocation.
            delete[] pThis->m_pArray;
            pThis->m_pArray = nullptr;
            pThis->m_nArraySize = 0;
            pThis->m_nGameObjectCache = 0;
            Initialize(pThis->m_nLogGameObjectCache);
        }, Hooks::Order::Final);

    static Hooks::Hook s_gameObjectArrayDtorHook = Hooks::HookFunction(API::Functions::_ZN16CGameObjectArrayD1Ev,
        (void*)+[](CGameObjectArray *pThis) -> void
        {
            s_gameObjectArrayDtorHook->CallOriginal<void>(pThis);
            Finalize();
        }, Hooks::Order::Final);

    static auto s_AddObjectAtPos    = Hooks::HookFunction(API::Functions::_ZN16CGameObjectArray14AddObjectAtPosEjP11CGameObject, (void*)&AddObjectAtPos, Hooks::Order::Final);
    static auto s_AddExternalObject = Hooks::HookFunction(API::Functions::_ZN16CGameObjectArray17AddExternalObjectERjP11CGameObjecti, (void*)&AddExternalObject, Hooks::Order::Final);
    static auto s_AddInternalObject = Hooks::HookFunction(API::Functions::_ZN16CGameObjectArray17AddInternalObjectERjP11CGameObjecti, (void*)&AddInternalObject, Hooks::Order::Final);
    static auto s_Delete1           = Hooks::HookFunction(API::Functions::_ZN16CGameObjectArray6DeleteEjPP11CGameObject, (void*)&Delete, Hooks::Order::Final);
    static auto s_Delete2           = Hooks::HookFunction(API::Functions::_ZN16CGameObjectArray6DeleteEj, (void*)+[](void* p, uint32_t id) -> uint8_t { return Delete(p, id, nullptr); }, Hooks::Order::Final);
    static auto s_GetGameObject     = Hooks::HookFunction(API::Functions::_ZN16CGameObjectArray13GetGameObjectEjPP11CGameObject, (void*)&GetGameObject, Hooks::Order::Final);
}


static void Initialize(uint32_t nLogGameObjectCache)
{
    goa.m_nArraySize = (1 << nLogGameObjectCache);

    // Make sure the allocation is properly aligned on a 4k page boundary
    const size_t array_size = goa.m_nArraySize * sizeof(ObjectNode);
    goa.m_pArray = (ObjectNode*)aligned_alloc(0x1000, array_size);
    memset(goa.m_pArray, 0, array_size);

    for (uint32_t i = 0; i < goa.m_nArraySize; i++)
    {
        for (uint32_t j = 0; j < ObjectsInNode; j++)
            goa.m_pArray[i].m_objectId[j] = Constants::OBJECT_INVALID;
    }

    for (uint32_t i = 0; i < L0CacheSize; i++)
        goa.m_nCacheIds[i] = Constants::OBJECT_INVALID;

    goa.m_nNextObjectArrayID[InternalObject] = 0x00000000;
    goa.m_nNextCharArrayID[InternalObject]   = 0x7FFFFFFF;
    goa.m_nNextObjectArrayID[ExternalObject] = 0x80000000;
    goa.m_nNextCharArrayID[ExternalObject]   = 0xFFFFFFFF;

    SetupWrapperHooks();
}


static void Finalize()
{
    for (uint32_t index = 0; index < goa.m_nArraySize; index++)
    {
        while (goa.m_pArray[index].m_objectPtr[0])
            delete goa.m_pArray[index].m_objectPtr[0];
    }
    free(goa.m_pArray);
}

static uint32_t GetNextID(void*, BOOL bInternal, BOOL bCharacter)
{
    int type = bInternal ? InternalObject : ExternalObject;
    uint32_t ret = bCharacter ? goa.m_nNextCharArrayID[type]-- : goa.m_nNextObjectArrayID[type]++;
    SyncWithGameGOA();
    return ret;
}

static uint8_t AddObjectAtPos(void*, uint32_t id, CGameObject *ptr)
{
    if (!ptr)
        return NullGameObject;

    ObjectNode *node = &goa.m_pArray[id & (goa.m_nArraySize-1)];
    while (true)
    {
        for (uint32_t i = 0; i < ObjectsInNode; i++)
        {
            if (node->m_objectId[i] == id)
                return BadId;

            if (node->m_objectPtr[i] == nullptr)
            {
                node->m_objectPtr[i] = ptr;
                node->m_objectId[i] = id;
                node->m_count++;
                return Success;
            }
        }
        if (node->m_nextNode == nullptr)
        {
            node->m_nextNode = new ObjectNode();
            memset(node->m_nextNode, 0, sizeof(*node->m_nextNode));
            for (uint32_t i = 0; i < ObjectsInNode; i++)
                node->m_nextNode->m_objectId[i] = Constants::OBJECT_INVALID;
        }
        node = node->m_nextNode;
    }
}


static uint8_t AddExternalObject(void*, uint32_t &id, CGameObject *ptr)
{
    id |= 0x80000000;

    if ((id & 0x7F000000) == 0x7F000000)
    {
        if (id < 0xFF000001)
            return BadId;
        goa.m_nNextCharArrayID[ExternalObject] = std::min(goa.m_nNextCharArrayID[ExternalObject], id-1);
    }
    else
    {
        if (id < 0x80000000 || id > 0xFEFFFFFF)
            return BadId;
        goa.m_nNextObjectArrayID[ExternalObject] = std::max(goa.m_nNextObjectArrayID[ExternalObject], id+1);
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
    if (id == Constants::OBJECT_INVALID)
        return BadId;

    // Clear the cache first
    for (uint32_t i = 0; i < L0CacheSize; i++)
    {
        if (goa.m_nCacheIds[i] == id)
            goa.m_nCacheIds[i] = Constants::OBJECT_INVALID;
    }

    ObjectNode *node = &goa.m_pArray[id & (goa.m_nArraySize-1)], *prev = nullptr;
    while (node != nullptr)
    {
        for (uint32_t i = 0; i < ObjectsInNode; i++)
        {
            if (node->m_objectId[i] == id)
            {
                if (ptr) *ptr = node->m_objectPtr[i];
                //
                // Pack up the index every time we delete a node to keep optimal lookup perf
                //
                // 1. Removed last entry in a node
                if (node->m_count == 1 && prev != nullptr) // never delete root node
                {
                    prev->m_nextNode = node->m_nextNode;
                    delete node;
                }
                // 2. We have another node in the chain. Take the last node's last entry
                else if (node->m_nextNode != nullptr)
                {
                    ObjectNode *last = node->m_nextNode, *secondlast = node;
                    while (last->m_nextNode)
                    {
                        secondlast = last;
                        last = last->m_nextNode;
                    }
                    last->m_count--;
                    node->m_objectPtr[i] = last->m_objectPtr[last->m_count];
                    node->m_objectId[i]  = last->m_objectId[last->m_count];
                    if (last->m_count == 0)
                    {
                        secondlast->m_nextNode = nullptr;
                        delete last;
                    }
                    else
                    {
                        last->m_objectPtr[last->m_count] = nullptr;
                        last->m_objectId[last->m_count]  = Constants::OBJECT_INVALID;
                    }
                }
                // 3. Removed an in the last chain link
                else
                {
                    node->m_count--;
                    node->m_objectPtr[i] = node->m_objectPtr[node->m_count];
                    node->m_objectId[i]  = node->m_objectId[node->m_count];
                    node->m_objectPtr[node->m_count] = nullptr;
                    node->m_objectId[node->m_count] = Constants::OBJECT_INVALID;
                }
                return Success;
            }
        }
        prev = node;
        node = node->m_nextNode;
    }
    return BadId;
}

#pragma GCC optimize ("unroll-loops")
#define PREFETCH(a) __builtin_prefetch(a, 0, 0)
static uint8_t GetGameObject(void*, uint32_t id, CGameObject** ptr)
{
    // This function needs to be AS FAST AS POSSIBLE, so be very careful what you add to it.
    // The optimization should target the average case where the object does exist.
    if (id != Constants::OBJECT_INVALID)
    {
        // We first check our first level cache for the mappings. However, while
        // we're checking the logic there, we can fetch the required node from
        // the main memory into the CPU L1 cache. If our own cache does not contain
        // the mapping, we won't have to wait on a CPU cache miss later.
        ObjectNode *node = &goa.m_pArray[id & (goa.m_nArraySize-1)];
        PREFETCH(node);

        // Check our first level cache first
        for (uint32_t i = 0; i < L0CacheSize; i++)
        {
            if (goa.m_nCacheIds[i] == id)
            {
                *ptr = goa.m_pCacheObjects[i];
                PREFETCH(*ptr);

                // Shift both arrays to the right to make the 0th entry available
                if (i != 0)
                {
                    memmove(&goa.m_nCacheIds[1],     &goa.m_nCacheIds[0],     i * sizeof(goa.m_nCacheIds[0]));
                    memmove(&goa.m_pCacheObjects[1], &goa.m_pCacheObjects[0], i * sizeof(goa.m_pCacheObjects[0]));
                    goa.m_nCacheIds[0] = id;
                    goa.m_pCacheObjects[0] = *ptr;
                }
                return Success;
            }
        }

        do
        {
            // Another PREFETCH(node->m_nextNode) here could help in cases where we're likely to have
            // multiple chained nodes for this index. However, that's an edge case (just increase cache size!)
            // and we're trying to optimize for the average case when the cache size is adequate.
            for (uint32_t i = 0; i < ObjectsInNode; i++)
            {
                if (node->m_objectId[i] == id)
                {
                    *ptr = node->m_objectPtr[i];
                    PREFETCH(*ptr);

                    const uint32_t moveelems = L0CacheSize - 1;
                    memmove(&goa.m_nCacheIds[1],     &goa.m_nCacheIds[0],     moveelems * sizeof(goa.m_nCacheIds[0]));
                    memmove(&goa.m_pCacheObjects[1], &goa.m_pCacheObjects[0], moveelems * sizeof(goa.m_pCacheObjects[0]));
                    goa.m_nCacheIds[0] = id;
                    goa.m_pCacheObjects[0] = *ptr;
                    return Success;
                }
            }
            node = node->m_nextNode;
        } while (node != nullptr);
    }

    *ptr = NULL;
    return BadId;
}

static void SyncWithGameGOA()
{
    if (auto* pGameObjectArray = Globals::AppManager()->m_pServerExoApp->GetObjectArray())
    {
        pGameObjectArray->m_nNextObjectArrayID[0] = goa.m_nNextObjectArrayID[0];
        pGameObjectArray->m_nNextObjectArrayID[1] = goa.m_nNextObjectArrayID[1];
        pGameObjectArray->m_nNextCharArrayID[0] = goa.m_nNextCharArrayID[0];
        pGameObjectArray->m_nNextCharArrayID[1] = goa.m_nNextCharArrayID[1];
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
    static auto s_GetGameObj      = Hooks::HookFunction(Functions::_ZN13CServerExoApp13GetGameObjectEj,                 (void*)&GetGameObj,      Hooks::Order::Final);
    static auto s_GetStore        = Hooks::HookFunction(Functions::_ZN13CServerExoApp22GetStoreByGameObjectIDEj,        (void*)&GetStore,        Hooks::Order::Final);
    static auto s_GetItem         = Hooks::HookFunction(Functions::_ZN13CServerExoApp21GetItemByGameObjectIDEj,         (void*)&GetItem,         Hooks::Order::Final);
    static auto s_GetCreature     = Hooks::HookFunction(Functions::_ZN13CServerExoApp25GetCreatureByGameObjectIDEj,     (void*)&GetCreature,     Hooks::Order::Final);
    static auto s_GetModule       = Hooks::HookFunction(Functions::_ZN13CServerExoApp23GetModuleByGameObjectIDEj,       (void*)&GetModule,       Hooks::Order::Final);
    static auto s_GetArea         = Hooks::HookFunction(Functions::_ZN13CServerExoApp21GetAreaByGameObjectIDEj,         (void*)&GetArea,         Hooks::Order::Final);
    static auto s_GetTrigger      = Hooks::HookFunction(Functions::_ZN13CServerExoApp24GetTriggerByGameObjectIDEj,      (void*)&GetTrigger,      Hooks::Order::Final);
    static auto s_GetPlaceable    = Hooks::HookFunction(Functions::_ZN13CServerExoApp26GetPlaceableByGameObjectIDEj,    (void*)&GetPlaceable,    Hooks::Order::Final);
    static auto s_GetDoor         = Hooks::HookFunction(Functions::_ZN13CServerExoApp21GetDoorByGameObjectIDEj,         (void*)&GetDoor,         Hooks::Order::Final);
    static auto s_GetAreaOfEffect = Hooks::HookFunction(Functions::_ZN13CServerExoApp29GetAreaOfEffectByGameObjectIDEj, (void*)&GetAreaOfEffect, Hooks::Order::Final);
    static auto s_GetWaypoint     = Hooks::HookFunction(Functions::_ZN13CServerExoApp25GetWaypointByGameObjectIDEj,     (void*)&GetWaypoint,     Hooks::Order::Final);
    static auto s_GetEncounter    = Hooks::HookFunction(Functions::_ZN13CServerExoApp26GetEncounterByGameObjectIDEj,    (void*)&GetEncounter,    Hooks::Order::Final);
    static auto s_GetSoundObject  = Hooks::HookFunction(Functions::_ZN13CServerExoApp28GetSoundObjectByGameObjectIDEj,  (void*)&GetSoundObject,  Hooks::Order::Final);
}

static CGameObject* GetGameObj(CServerExoApp*, ObjectID oid)
{
    CGameObject* obj;
    GetGameObject(nullptr, oid, &obj);
    return obj;
}
static CNWSStore* GetStore(CServerExoApp*, ObjectID oid)
{
    CGameObject* obj;
    if (GetGameObject(nullptr, oid, &obj) != Success)
        return nullptr;
    return obj->m_nObjectType == Constants::ObjectType::Store ? static_cast<CNWSStore*>(obj) : nullptr;
}
static CNWSItem* GetItem(CServerExoApp*, ObjectID oid)
{
    CGameObject* obj;
    if (GetGameObject(nullptr, oid, &obj) != Success)
        return nullptr;
    return obj->m_nObjectType == Constants::ObjectType::Item ? static_cast<CNWSItem*>(obj) : nullptr;
}
static CNWSCreature* GetCreature(CServerExoApp*, ObjectID oid)
{
    CGameObject* obj;
    if (GetGameObject(nullptr, oid, &obj) != Success)
        return nullptr;
    return obj->m_nObjectType == Constants::ObjectType::Creature ? static_cast<CNWSCreature*>(obj) : nullptr;
}
static CNWSModule* GetModule(CServerExoApp*, ObjectID oid)
{
    CGameObject* obj;
    if (GetGameObject(nullptr, oid, &obj) != Success)
        return nullptr;
    return obj->m_nObjectType == Constants::ObjectType::Module ? static_cast<CNWSModule*>(obj) : nullptr;
}
static CNWSArea* GetArea(CServerExoApp*, ObjectID oid)
{
    CGameObject* obj;
    if (GetGameObject(nullptr, oid, &obj) != Success)
        return nullptr;
    return obj->m_nObjectType == Constants::ObjectType::Area ? static_cast<CNWSArea*>(obj) : nullptr;
}
static CNWSTrigger* GetTrigger(CServerExoApp*, ObjectID oid)
{
    CGameObject* obj;
    if (GetGameObject(nullptr, oid, &obj) != Success)
        return nullptr;
    return obj->m_nObjectType == Constants::ObjectType::Trigger ? static_cast<CNWSTrigger*>(obj) : nullptr;
}
static CNWSPlaceable* GetPlaceable(CServerExoApp*, ObjectID oid)
{
    CGameObject* obj;
    if (GetGameObject(nullptr, oid, &obj) != Success)
        return nullptr;
    return obj->m_nObjectType == Constants::ObjectType::Placeable ? static_cast<CNWSPlaceable*>(obj) : nullptr;
}
static CNWSDoor* GetDoor(CServerExoApp*, ObjectID oid)
{
    CGameObject* obj;
    if (GetGameObject(nullptr, oid, &obj) != Success)
        return nullptr;
    return obj->m_nObjectType == Constants::ObjectType::Door ? static_cast<CNWSDoor*>(obj) : nullptr;
}
static CNWSAreaOfEffectObject* GetAreaOfEffect(CServerExoApp*, ObjectID oid)
{
    CGameObject* obj;
    if (GetGameObject(nullptr, oid, &obj) != Success)
        return nullptr;
    return obj->m_nObjectType == Constants::ObjectType::AreaOfEffect ? static_cast<CNWSAreaOfEffectObject*>(obj) : nullptr;
}
static CNWSWaypoint* GetWaypoint(CServerExoApp*, ObjectID oid)
{
    CGameObject* obj;
    if (GetGameObject(nullptr, oid, &obj) != Success)
        return nullptr;
    return obj->m_nObjectType == Constants::ObjectType::Waypoint ? static_cast<CNWSWaypoint*>(obj) : nullptr;
}
static CNWSEncounter* GetEncounter(CServerExoApp*, ObjectID oid)
{
    CGameObject* obj;
    if (GetGameObject(nullptr, oid, &obj) != Success)
        return nullptr;
    return obj->m_nObjectType == Constants::ObjectType::Encounter ? static_cast<CNWSEncounter*>(obj) : nullptr;
}
static CNWSSoundObject* GetSoundObject(CServerExoApp*, ObjectID oid)
{
    CGameObject* obj;
    if (GetGameObject(nullptr, oid, &obj) != Success)
        return nullptr;
    return obj->m_nObjectType == Constants::ObjectType::Sound ? static_cast<CNWSSoundObject*>(obj) : nullptr;
}


}
