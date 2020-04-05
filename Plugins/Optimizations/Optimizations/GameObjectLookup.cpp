#include "Optimizations/GameObjectLookup.hpp"

#include "Services/Hooks/Hooks.hpp"
#include "Services/Tasks/Tasks.hpp"
#include "API/Functions.hpp"
#include "API/Constants.hpp"
#include "API/CAppManager.hpp"
#include "API/CServerExoApp.hpp"
#include "API/CGameObject.hpp"
#include "API/CGameObjectArray.hpp"

namespace Optimizations {

using namespace NWNXLib;
using namespace NWNXLib::API;

GameObjectLookup::GameObjectLookup(Services::HooksProxy* hooker)
{
    hooker->RequestSharedHook<API::Functions::_ZN16CGameObjectArrayC1Ei, void>(
    +[](bool before, CGameObjectArray* pThis)
    {
        if (!before)
        {
            // Reading the config is currently.. complicated in NWNX, so just
            // let the CGOA constructor read it, and then undo the allocation.
            delete[] pThis->m_pArray;
            pThis->m_pArray = nullptr;
            pThis->m_nArraySize = 0;
            pThis->m_nGameObjectCache = 0;
            GameObjectLookup::Initialize(pThis->m_nLogGameObjectCache);
        }
    });
    hooker->RequestSharedHook<API::Functions::_ZN16CGameObjectArrayD1Ev, void>(
    +[](bool before, CGameObjectArray*)
    {
        if (!before)
            GameObjectLookup::Finalize();
    });
    hooker->RequestExclusiveHook<API::Functions::_ZN16CGameObjectArray14AddObjectAtPosEjP11CGameObject>
        (GameObjectLookup::AddObjectAtPos);
    hooker->RequestExclusiveHook<API::Functions::_ZN16CGameObjectArray17AddExternalObjectERjP11CGameObjecti>
        (GameObjectLookup::AddExternalObject);
    hooker->RequestExclusiveHook<API::Functions::_ZN16CGameObjectArray17AddInternalObjectERjP11CGameObjecti>
        (GameObjectLookup::AddInternalObject);
    hooker->RequestExclusiveHook<API::Functions::_ZN16CGameObjectArray6DeleteEjPP11CGameObject>
        (GameObjectLookup::Delete);
    hooker->RequestExclusiveHook<API::Functions::_ZN16CGameObjectArray6DeleteEj>
        (+[](void* p, uint32_t id) -> uint8_t { return GameObjectLookup::Delete(p, id, nullptr); });
    hooker->RequestExclusiveHook<API::Functions::_ZN16CGameObjectArray13GetGameObjectEjPP11CGameObject>
        (GameObjectLookup::GetGameObject);
}

// DO NOT REARRANGE
CGameObject*              GameObjectLookup::m_pCacheObjects[L0CacheSize];
uint32_t                  GameObjectLookup::m_nCacheIds[L0CacheSize];
uint32_t                  GameObjectLookup::m_nArraySize;
uint32_t                  GameObjectLookup::m_nNextObjectArrayID[2];
uint32_t                  GameObjectLookup::m_nNextCharArrayID[2];
GameObjectLookup::ObjectNode*  GameObjectLookup::m_pArray;
uint8_t*                  GameObjectLookup::m_pArrayUnaligned;

enum { InternalObject = 0, ExternalObject = 1};
enum { Success = 0, BadId = 1, NullGameObject = 4 };

void GameObjectLookup::Initialize(uint32_t nLogGameObjectCache)
{
    m_nArraySize = (1 << nLogGameObjectCache);

    // Make sure the allocation is properly aligned on a 4k page boundary
    const size_t array_size = m_nArraySize * sizeof(ObjectNode);
    m_pArrayUnaligned = new uint8_t[array_size + 0x1000];
    m_pArray = (ObjectNode*)(((uintptr_t)m_pArrayUnaligned + 0xFFF) & ~(0xFFFull));

    memset(m_pArray, 0, array_size);
    for (uint32_t i = 0; i < m_nArraySize; i++)
    {
        for (uint32_t j = 0; j < ObjectsInNode; j++)
            m_pArray[i].m_objectId[j] = Constants::OBJECT_INVALID;
    }

    for (uint32_t i = 0; i < L0CacheSize; i++)
        m_nCacheIds[i] = Constants::OBJECT_INVALID;

    m_nNextObjectArrayID[InternalObject] = 0x00000000;
    m_nNextCharArrayID[InternalObject]   = 0x7FFFFFFF;
    m_nNextObjectArrayID[ExternalObject] = 0x80000000;
    m_nNextCharArrayID[ExternalObject]   = 0xFFFFFFFF;
}


void GameObjectLookup::Finalize()
{
    for (uint32_t index = 0; index < m_nArraySize; index++)
    {
        while (m_pArray[index].m_objectPtr[0])
            delete m_pArray[index].m_objectPtr[0];
    }
    delete[] m_pArrayUnaligned;
}

uint32_t GameObjectLookup::GetNextID(void*, BOOL bInternal, BOOL bCharacter)
{
    int type = bInternal ? InternalObject : ExternalObject;
    uint32_t ret = bCharacter ? m_nNextCharArrayID[type]-- : m_nNextObjectArrayID[type]++;
    SyncWithGameGOA();
    return ret;
}
void GameObjectLookup::SetNextObjectArrayID(void*, int32_t nList, uint32_t nVal)
{
    if (nList == ExternalObject) nVal |= 0x80000000;
    m_nNextObjectArrayID[nList] = nVal;
    SyncWithGameGOA();
}
void GameObjectLookup::SetNextCharArrayID(void*, int32_t nList, uint32_t nVal)
{
    if (nList == ExternalObject) nVal |= 0x80000000;
    m_nNextCharArrayID[nList] = nVal;
    SyncWithGameGOA();
}

uint8_t GameObjectLookup::AddObjectAtPos(void*, uint32_t id, CGameObject *ptr)
{
    if (!ptr)
        return NullGameObject;

    ObjectNode *node = &m_pArray[id & (m_nArraySize-1)];
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


uint8_t GameObjectLookup::AddExternalObject(void*, uint32_t &id, CGameObject *ptr)
{
    id |= 0x80000000;

    if ((id & 0x7F000000) == 0x7F000000)
    {
        if (id < 0xFF000001)
            return BadId;
        m_nNextCharArrayID[ExternalObject] = std::min(m_nNextCharArrayID[ExternalObject], id-1);
    }
    else
    {
        if (id < 0x80000000 || id > 0xFEFFFFFF)
            return BadId;
        m_nNextObjectArrayID[ExternalObject] = std::max(m_nNextObjectArrayID[ExternalObject], id+1);
    }
    SyncWithGameGOA();
    return AddObjectAtPos(nullptr, id, ptr);
}


uint8_t GameObjectLookup::AddInternalObject(void*, uint32_t &id, CGameObject *ptr, bool bCharacter)
{
    return AddObjectAtPos(nullptr, (id = GetNextID(nullptr, true, bCharacter)), ptr);
}


uint8_t GameObjectLookup::Delete(void*, uint32_t id, CGameObject** ptr)
{
    if (id == Constants::OBJECT_INVALID)
        return BadId;

    // Clear the cache first
    for (uint32_t i = 0; i < L0CacheSize; i++)
    {
        if (m_nCacheIds[i] == id)
            m_nCacheIds[i] = Constants::OBJECT_INVALID;
    }

    ObjectNode *node = &m_pArray[id & (m_nArraySize-1)], *prev = nullptr;
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
uint8_t GameObjectLookup::GetGameObject(void*, uint32_t id, CGameObject** ptr)
{
    // This function needs to be AS FAST AS POSSIBLE, so be very careful what you add to it.
    // The optimization should target the average case where the object does exist.
    if (id != Constants::OBJECT_INVALID)
    {
        // We first check our first level cache for the mappings. However, while
        // we're checking the logic there, we can fetch the required node from
        // the main memory into the CPU L1 cache. If our own cache does not contain
        // the mapping, we won't have to wait on a CPU cache miss later.
        ObjectNode *node = &m_pArray[id & (m_nArraySize-1)];
        PREFETCH(node);

        // Check our first level cache first
        for (uint32_t i = 0; i < L0CacheSize; i++)
        {
            if (m_nCacheIds[i] == id)
            {
                *ptr = m_pCacheObjects[i];
                PREFETCH(*ptr);

                // Shift both arrays to the right to make the 0th entry available
                if (i != 0)
                {
                    memmove(&m_nCacheIds[1],     &m_nCacheIds[0],     i * sizeof(m_nCacheIds[0]));
                    memmove(&m_pCacheObjects[1], &m_pCacheObjects[0], i * sizeof(m_pCacheObjects[0]));
                    m_nCacheIds[0] = id;
                    m_pCacheObjects[0] = *ptr;
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
                    memmove(&m_nCacheIds[1],     &m_nCacheIds[0],     moveelems * sizeof(m_nCacheIds[0]));
                    memmove(&m_pCacheObjects[1], &m_pCacheObjects[0], moveelems * sizeof(m_pCacheObjects[0]));
                    m_nCacheIds[0] = id;
                    m_pCacheObjects[0] = *ptr;
                    return Success;
                }
            }
            node = node->m_nextNode;
        } while (node != nullptr);
    }

    *ptr = NULL;
    return BadId;
}

void GameObjectLookup::SyncWithGameGOA()
{
    if (auto* pGameObjectArray = Globals::AppManager()->m_pServerExoApp->GetObjectArray())
    {
        pGameObjectArray->m_nNextObjectArrayID[0] = m_nNextObjectArrayID[0];
        pGameObjectArray->m_nNextObjectArrayID[1] = m_nNextObjectArrayID[1];
        pGameObjectArray->m_nNextCharArrayID[0] = m_nNextCharArrayID[0];
        pGameObjectArray->m_nNextCharArrayID[1] = m_nNextCharArrayID[1];
    }
}

}
