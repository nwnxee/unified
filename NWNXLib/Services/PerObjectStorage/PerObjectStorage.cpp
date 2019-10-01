#include "Services/PerObjectStorage/PerObjectStorage.hpp"
#include "API/CGameObject.hpp"
#include "API/CNWSArea.hpp"
#include "API/CNWSObject.hpp"
#include "API/CNWSPlayer.hpp"
#include "API/CNWSPlayerTURD.hpp"
#include "API/CNWSModule.hpp"
#include "API/CExoLinkedListInternal.hpp"
#include "API/CExoLinkedListNode.hpp"
#include "API/Constants.hpp"

#include <sstream>

namespace NWNXLib {

namespace Services {

PerObjectStorage::ObjectStorage* PerObjectStorage::GetObjectStorage(API::CGameObject *pGameObject)
{
    if (!pGameObject)
        return nullptr;

    if (!pGameObject->m_pNwnxData)
    {
        pGameObject->m_pNwnxData = static_cast<void*>(new ObjectStorage(pGameObject->m_idSelf));
    }
    return static_cast<ObjectStorage*>(pGameObject->m_pNwnxData);
}

PerObjectStorage::ObjectStorage* PerObjectStorage::GetObjectStorage(API::Types::ObjectID object)
{
    return GetObjectStorage(Utils::GetGameObject(object));
}


void PerObjectStorage::Set(API::CGameObject *pGameObject, const std::string& key, int value)
{
    if (auto *pOS = GetObjectStorage(pGameObject))
    {
        pOS->GetIntMap()[key] = value;
    }
}
void PerObjectStorage::Set(API::CGameObject *pGameObject, const std::string& key, float value)
{
    if (auto *pOS = GetObjectStorage(pGameObject))
    {
        pOS->GetFloatMap()[key] = value;
    }
}
void PerObjectStorage::Set(API::CGameObject *pGameObject, const std::string& key, std::string value)
{
    if (auto *pOS = GetObjectStorage(pGameObject))
    {
        pOS->GetStringMap().emplace(key, std::move(value));
    }
}
void PerObjectStorage::Set(API::CGameObject *pGameObject, const std::string& key, void *value, CleanupFunc cleanup)
{
    if (auto *pOS = GetObjectStorage(pGameObject))
    {
        pOS->GetPointerMap()[key] = std::make_pair<>(value, cleanup);
    }
}



void PerObjectStorage::Remove(API::CGameObject *pGameObject, const std::string& key)
{
    if (auto *pOS = GetObjectStorage(pGameObject))
    {
        // Ugly, but GetXxxMap will create it if missing.
        if (pOS->m_StringMap)
            pOS->m_StringMap->erase(key);
        if (pOS->m_IntMap)
            pOS->m_IntMap->erase(key);
        if (pOS->m_FloatMap)
            pOS->m_FloatMap->erase(key);
        if (pOS->m_PointerMap)
            pOS->m_PointerMap->erase(key);
    }
}

PerObjectStorage::PerObjectStorage()
{

}
PerObjectStorage::~PerObjectStorage()
{

}

PerObjectStorage::ObjectStorage::IntMap& PerObjectStorage::ObjectStorage::GetIntMap()
{
    if (!m_IntMap)
        m_IntMap = std::make_unique<IntMap>();
    return *m_IntMap;
}
PerObjectStorage::ObjectStorage::FloatMap& PerObjectStorage::ObjectStorage::GetFloatMap()
{
    if (!m_FloatMap)
        m_FloatMap = std::make_unique<FloatMap>();
    return *m_FloatMap;
}
PerObjectStorage::ObjectStorage::StringMap& PerObjectStorage::ObjectStorage::GetStringMap()
{
    if (!m_StringMap)
        m_StringMap = std::make_unique<StringMap>();
    return *m_StringMap;
}
PerObjectStorage::ObjectStorage::PointerMap& PerObjectStorage::ObjectStorage::GetPointerMap()
{
    if (!m_PointerMap)
        m_PointerMap = std::make_unique<PointerMap>();
    return *m_PointerMap;
}

PerObjectStorage::ObjectStorage::ObjectStorage(API::Types::ObjectID owner)
{
    m_oidOwner = owner;
    m_bCloned = false;
}
PerObjectStorage::ObjectStorage::~ObjectStorage()
{
    if (m_PointerMap && !m_bCloned)
    {
        for (auto it: *m_PointerMap)
        {
            auto ptr = it.second.first;
            if (auto cleanup = it.second.second)
                cleanup(ptr);
        }
    }
}

void PerObjectStorage::ObjectStorage::CloneFrom(PerObjectStorage::ObjectStorage *other)
{
    if (!other)
        return;

    other->m_bCloned = true;

    if (other->m_IntMap)
        m_IntMap = std::make_unique<IntMap>(*other->m_IntMap);
    if (other->m_FloatMap)
        m_FloatMap = std::make_unique<FloatMap>(*other->m_FloatMap);
    if (other->m_StringMap)
        m_StringMap = std::make_unique<StringMap>(*other->m_StringMap);
    if (other->m_PointerMap)
        m_PointerMap = std::make_unique<PointerMap>(*other->m_PointerMap);
}

std::string PerObjectStorage::ObjectStorage::DumpToString()
{
    std::stringstream ss;
    ss << "Object ID: " << std::hex << m_oidOwner << std::endl;
    if (m_IntMap)
    {
        for (auto it: *m_IntMap)
            ss << it.first << " = " << std::dec << it.second << std::endl;
    }
    if (m_FloatMap)
    {
        for (auto it: *m_FloatMap)
            ss << it.first << " = " << it.second << std::endl;
    }
    if (m_StringMap)
    {
        for (auto it: *m_StringMap)
            ss << it.first << " = " << it.second << std::endl;
    }
    if (m_PointerMap)
    {
        for (auto it: *m_PointerMap)
            ss << it.first << " = " << it.second.first << std::endl;
    }
    return ss.str();
}

PerObjectStorageProxy::PerObjectStorageProxy(PerObjectStorage& perObjectStorage, std::string pluginName)
    : ServiceProxy<PerObjectStorage>(perObjectStorage), m_pluginName(std::move(pluginName))
{
}

PerObjectStorageProxy::~PerObjectStorageProxy()
{
    // TODO cleanup all storage from this plugin
}

void PerObjectStorageProxy::Set(API::CGameObject *pGameObject, const std::string& key, int value)
{
    m_proxyBase.Set(pGameObject, m_pluginName + "!" + key, value);
}
void PerObjectStorageProxy::Set(API::CGameObject *pGameObject, const std::string& key, float value)
{
    m_proxyBase.Set(pGameObject, m_pluginName + "!" + key, value);
}
void PerObjectStorageProxy::Set(API::CGameObject *pGameObject, const std::string& key, std::string value)
{
    m_proxyBase.Set(pGameObject, m_pluginName + "!" + key, std::move(value));
}
void PerObjectStorageProxy::Set(API::CGameObject *pGameObject, const std::string& key, void *value, PerObjectStorage::CleanupFunc cleanup)
{
    m_proxyBase.Set(pGameObject, m_pluginName + "!" + key, value, cleanup);
}

void PerObjectStorageProxy::Remove(API::CGameObject *pGameObject, const std::string& key)
{
    m_proxyBase.Remove(pGameObject, m_pluginName + "!" + key);
}


template <> Maybe<int> PerObjectStorage::Get<int>(API::CGameObject *pGameObject, const std::string& key)
{
    if (auto *pOS = GetObjectStorage(pGameObject))
    {
        auto map = pOS->GetIntMap();
        auto it = map.find(key);
        if (it != map.end())
            return Maybe<int>(it->second);
    }
    return Maybe<int>();
}
template <> Maybe<float> PerObjectStorage::Get<float>(API::CGameObject *pGameObject, const std::string& key)
{
    if (auto *pOS = GetObjectStorage(pGameObject))
    {
        auto map = pOS->GetFloatMap();
        auto it = map.find(key);
        if (it != map.end())
            return Maybe<float>(it->second);
    }
    return Maybe<float>();
}
template <> Maybe<std::string> PerObjectStorage::Get<std::string>(API::CGameObject *pGameObject, const std::string& key)
{
    if (auto *pOS = GetObjectStorage(pGameObject))
    {
        auto map = pOS->GetStringMap();
        auto it = map.find(key);
        if (it != map.end())
            return Maybe<std::string>(it->second);
    }
    return Maybe<std::string>();
}

template <> Maybe<void*> PerObjectStorage::Get<void*>(API::CGameObject *pGameObject, const std::string& key)
{
    if (auto *pOS = GetObjectStorage(pGameObject))
    {
        auto map = pOS->GetPointerMap();
        auto it = map.find(key);
        if (it != map.end())
            return Maybe<void*>(it->second.first);
    }
    return Maybe<void*>();
}

void PerObjectStorage::DestroyObjectStorage(API::CGameObject *pGameObject)
{
    if (pGameObject->m_pNwnxData)
    {
        delete static_cast<PerObjectStorage::ObjectStorage*>(pGameObject->m_pNwnxData);
        pGameObject->m_pNwnxData = nullptr;
    }
}

void PerObjectStorage::CNWSObject__CNWSObjectDtor__0_hook(Services::Hooks::CallType type, API::CNWSObject* pThis)
{
    if (type == Services::Hooks::CallType::AFTER_ORIGINAL)
        DestroyObjectStorage(static_cast<API::CGameObject*>(pThis));
}
void PerObjectStorage::CNWSArea__CNWSAreaDtor__0_hook(Services::Hooks::CallType type, API::CNWSArea* pThis)
{
    if (type == Services::Hooks::CallType::AFTER_ORIGINAL)
        DestroyObjectStorage(static_cast<API::CGameObject*>(pThis));
}
void PerObjectStorage::CNWSPlayer__EatTURD_hook(Services::Hooks::CallType type, API::CNWSPlayer* thisPtr, API::CNWSPlayerTURD* pTURD)
{
    if (type == Services::Hooks::CallType::BEFORE_ORIGINAL)
    {
        GetObjectStorage(thisPtr->m_oidNWSObject)->CloneFrom(GetObjectStorage(pTURD));
    }
}
void PerObjectStorage::CNWSPlayer__DropTURD_hook(Services::Hooks::CallType type, API::CNWSPlayer* thisPtr)
{
    if (type == Services::Hooks::CallType::AFTER_ORIGINAL)
    {
        // Be very, very paranoid. Bad things happen when the TURD list doesn't exist
        // This can happen when you BootPC() the very first PC to connect to your sever
        //     https://github.com/nwnxee/unified/issues/319
        if (auto turdlist = Utils::GetModule()->m_lstTURDList.m_pcExoLinkedListInternal)
        {
            if (auto *pHead = turdlist->pHead)
            {
                if (auto *pTURD = static_cast<API::CNWSPlayerTURD*>(pHead->pObject))
                {
                    GetObjectStorage(pTURD)->CloneFrom(GetObjectStorage(thisPtr->m_oidNWSObject));
                }
            }
        }
    }
}

}
}
