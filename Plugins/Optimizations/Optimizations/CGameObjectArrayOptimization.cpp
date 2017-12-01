#include "Optimizations/CGameObjectArrayOptimization.hpp"

#include "API/CAppManager.hpp"
#include "API/CGameObject.hpp"
#include "API/CServerExoApp.hpp"
#include "API/Constants.hpp"
#include "API/Functions.hpp"
#include "API/Globals.hpp"
#include "Services/Hooks/Hooks.hpp"

namespace Optimizations {

using namespace NWNXLib;

static CGameObjectArrayOptimization* g_opt = nullptr;
static Services::HooksProxy* g_hooker = nullptr;

static constexpr uint8_t SUCCESS = 0;
static constexpr uint8_t BAD_ID = 1;

static constexpr API::Types::ObjectID FIRST_OBJ_ID = 0;
static constexpr API::Types::ObjectID LAST_OBJ_ID = API::Constants::OBJECT_INVALID - 1;
static constexpr API::Types::ObjectID EMPTY_KEY = API::Constants::OBJECT_INVALID;
static constexpr API::Types::ObjectID DELETED_KEY = API::Constants::OBJECT_INVALID + 1;
static constexpr API::Types::ObjectID FIRST_CHAR_ID = API::Constants::OBJECT_INVALID + 2;
static constexpr API::Types::ObjectID LAST_CHAR_ID = 0x7FFFFFFF;

CGameObjectArrayOptimization::CGameObjectArrayOptimization(const uint32_t startingSize,
    ViewPtr<Services::HooksProxy> hooker)
    : m_nextObjectId(FIRST_OBJ_ID),
      m_nextCharacterId(LAST_CHAR_ID)
{
    assert(g_opt == nullptr);
    g_opt = this;
    g_hooker = hooker;

    m_hashMap.set_empty_key(EMPTY_KEY);
    m_hashMap.set_deleted_key(DELETED_KEY);
    m_hashMap.resize(startingSize);

    hooker->RequestExclusiveHook<API::Functions::CGameObjectArray__AddObjectAtPos>(&AddObjectAtPos);
    hooker->RequestExclusiveHook<API::Functions::CGameObjectArray__AddCharacterObjectAtPos>(&AddCharacterObjectAtPos);
    hooker->RequestExclusiveHook<API::Functions::CGameObjectArray__AddInternalObject>(&AddInternalObject);
    hooker->RequestExclusiveHook<API::Functions::CGameObjectArray__Delete__0>(&Delete__0);
    hooker->RequestExclusiveHook<API::Functions::CGameObjectArray__Delete__1>(&Delete__1);
    hooker->RequestExclusiveHook<API::Functions::CGameObjectArray__GetGameObject>(&GetGameObject);

    // TODO: Import our state from the existing object array for hotswapping support.
}

CGameObjectArrayOptimization::~CGameObjectArrayOptimization()
{
    // Iterate over our hash map and insert it into the original map.
    // We do this as not to break everything after we've unloaded.
    for (auto& elem : m_hashMap)
    {
        ViewPtr<Hooking::FunctionHook> hook = nullptr;

        if (elem.first <= LAST_OBJ_ID)
        {
            hook = g_hooker->FindHookByAddress(API::Functions::CGameObjectArray__AddObjectAtPos);
        }
        else if (elem.first >= FIRST_CHAR_ID)
        {
            hook = g_hooker->FindHookByAddress(API::Functions::CGameObjectArray__AddCharacterObjectAtPos);
        }

        if (hook)
        {
            API::CGameObjectArray* arr = API::Globals::AppManager()->m_pServerExoApp->GetObjectArray();
            hook->CallOriginal<int8_t>(arr, elem.first, elem.second);
        }
    }
}

CGameObjectReport CGameObjectArrayOptimization::GetObjectReport()
{
    CGameObjectReport report = {};

    for (auto& elem : m_hashMap)
    {
        if (elem.first <= LAST_OBJ_ID)
        {
            ++report.m_objCounts[elem.second->m_nObjectType];
        }
    };

    return report;
}

uint8_t CGameObjectArrayOptimization::AddObjectAtPos(API::CGameObjectArray*, API::Types::ObjectID id, API::CGameObject* ptr)
{
    g_opt->m_hashMap[id] = ptr;
    return SUCCESS;
}

uint8_t CGameObjectArrayOptimization::AddCharacterObjectAtPos(API::CGameObjectArray*, API::Types::ObjectID id, API::CGameObject* ptr)
{
    g_opt->m_hashMap[id] = ptr;
    return SUCCESS;
}

uint8_t CGameObjectArrayOptimization::AddInternalObject(API::CGameObjectArray*, API::Types::ObjectID* id, API::CGameObject* ptr, bool characterObject)
{
    API::Types::ObjectID newId = characterObject ? g_opt->m_nextCharacterId-- : g_opt->m_nextObjectId++;
    g_opt->m_hashMap[newId] = ptr;
    *id = newId;
    return SUCCESS;
}

uint8_t CGameObjectArrayOptimization::Delete__0(API::CGameObjectArray* thisPtr, API::Types::ObjectID id)
{
    API::CGameObject* ptr;
    return Delete__1(thisPtr, id, &ptr);
}

uint8_t CGameObjectArrayOptimization::Delete__1(API::CGameObjectArray*, API::Types::ObjectID id, API::CGameObject** ptr)
{
    auto elem = g_opt->m_hashMap.find(id);

    if (elem == g_opt->m_hashMap.end())
    {
        *ptr = nullptr;
        return BAD_ID;
    }

    *ptr = elem->second;
    g_opt->m_hashMap.erase(elem);
    return SUCCESS;
}

uint8_t CGameObjectArrayOptimization::GetGameObject(API::CGameObjectArray*, API::Types::ObjectID id, API::CGameObject** ptr)
{
    auto elem = g_opt->m_hashMap.find(id);

    if (elem == g_opt->m_hashMap.end())
    {
        *ptr = nullptr;
        return BAD_ID;
    }

    *ptr = elem->second;
    return SUCCESS;
}

}
