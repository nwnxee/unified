#pragma once

#include "API/Types.hpp"
#include "Common.hpp"
#include "Platform/Hooking.hpp"
#include "ViewPtr.hpp"

#include <sparsehash/dense_hash_map>

namespace Optimizations {

struct CGameObjectReport
{
    uint32_t m_objCounts[17];
};

class CGameObjectArrayOptimization
{
public:
    CGameObjectArrayOptimization(const uint32_t startingSize, NWNXLib::ViewPtr<NWNXLib::Services::HooksProxy> hooker);
    ~CGameObjectArrayOptimization();

    CGameObjectReport GetObjectReport();

    static uint8_t AddObjectAtPos(NWNXLib::API::CGameObjectArray* thisPtr, NWNXLib::API::Types::ObjectID id, NWNXLib::API::CGameObject* ptr);
    static uint8_t AddCharacterObjectAtPos(NWNXLib::API::CGameObjectArray* thisPtr, NWNXLib::API::Types::ObjectID id, NWNXLib::API::CGameObject* ptr);
    static uint8_t AddInternalObject(NWNXLib::API::CGameObjectArray* thisPtr, NWNXLib::API::Types::ObjectID* id, NWNXLib::API::CGameObject* ptr, bool characterObject);
    static uint8_t Delete__0(NWNXLib::API::CGameObjectArray* thisPtr, NWNXLib::API::Types::ObjectID id);
    static uint8_t Delete__1(NWNXLib::API::CGameObjectArray* thisPtr, NWNXLib::API::Types::ObjectID id, NWNXLib::API::CGameObject** ptr);
    static uint8_t GetGameObject(NWNXLib::API::CGameObjectArray* thisPtr, NWNXLib::API::Types::ObjectID id, NWNXLib::API::CGameObject** ptr);

private:
    google::dense_hash_map<NWNXLib::API::Types::ObjectID, NWNXLib::API::CGameObject*> m_hashMap;
    NWNXLib::API::Types::ObjectID m_nextObjectId;
    NWNXLib::API::Types::ObjectID m_nextCharacterId;
};

}
