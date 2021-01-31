#include "nwnx.hpp"

#include "API/Functions.hpp"
#include "API/Constants.hpp"
#include "API/CAppManager.hpp"
#include "API/CServerExoApp.hpp"
#include "API/CGameObject.hpp"
#include "API/CGameObjectArray.hpp"


namespace Optimizations {

using namespace NWNXLib;
using namespace NWNXLib::API;

static constexpr uint32_t ObjectsInNode = 4;
static constexpr uint32_t L0CacheSize = 5;

struct ObjectNode
{
    CGameObject* m_objectPtr[ObjectsInNode];
    uint32_t     m_objectId[ObjectsInNode];
    ObjectNode*  m_nextNode;
    uint32_t     m_count;
    uint8_t      m_padding[4]; // For cache line alignment
};

// DO NOT REARRANGE - optimal placement across cache lines
static struct alignas(64)
{
    CGameObject*   m_pCacheObjects[L0CacheSize];
    uint32_t       m_nCacheIds[L0CacheSize];
    uint32_t       m_nArraySize;
    uint32_t       m_nNextObjectArrayID[2];
    uint32_t       m_nNextCharArrayID[2];
    ObjectNode*    m_pArray;
    uint8_t*       m_pArrayUnaligned;
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
static uint8_t GetGameObject(void*, uint32_t id, CGameObject** ptr);

static void SyncWithGameGOA();

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
    goa.m_pArrayUnaligned = new uint8_t[array_size + 0x1000];
    goa.m_pArray = (ObjectNode*)(((uintptr_t)goa.m_pArrayUnaligned + 0xFFF) & ~(0xFFFull));

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
}


static void Finalize()
{
    for (uint32_t index = 0; index < goa.m_nArraySize; index++)
    {
        while (goa.m_pArray[index].m_objectPtr[0])
            delete goa.m_pArray[index].m_objectPtr[0];
    }
    delete[] goa.m_pArrayUnaligned;
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

}
