#pragma once

#include "API/Types.hpp"
#include "Common.hpp"

namespace Optimizations {

class GameObjectLookup
{
public:
    GameObjectLookup(NWNXLib::Services::HooksProxy* hooker);

    static constexpr uint32_t ObjectsInNode = 4;
    static constexpr uint32_t L0CacheSize = 5;
private:

    struct ObjectNode
    {
        CGameObject* m_objectPtr[ObjectsInNode];
        uint32_t     m_objectId[ObjectsInNode];
        ObjectNode*  m_nextNode;
        uint32_t     m_count;
        uint8_t      m_padding[4]; // For cache line alignment
    };

    static CGameObject* m_pCacheObjects[L0CacheSize];
    static uint32_t     m_nCacheIds[L0CacheSize];
    static uint32_t     m_nArraySize;
    static uint32_t     m_nNextObjectArrayID[2];
    static uint32_t     m_nNextCharArrayID[2];
    static ObjectNode*  m_pArray;
    static uint8_t*     m_pArrayUnaligned;

    static void Initialize(uint32_t nLogGameObjectCache);
    static void Finalize();
    static uint32_t GetNextID(void*, BOOL bInternal, BOOL bCharacter);
    static void SetNextObjectArrayID(void*, int32_t nList, uint32_t nVal);
    static void SetNextCharArrayID(void*, int32_t nList, uint32_t nVal);
    static uint8_t AddObjectAtPos(void*, uint32_t id, CGameObject *ptr);
    static uint8_t AddExternalObject(void*, uint32_t &id, CGameObject *ptr);
    static uint8_t AddInternalObject(void*, uint32_t &id, CGameObject *ptr, bool bCharacter);
    static uint8_t Delete(void*, uint32_t id, CGameObject** ptr);
    static uint8_t GetGameObject(void*, uint32_t id, CGameObject** ptr);

    static void SyncWithGameGOA();
};

}
