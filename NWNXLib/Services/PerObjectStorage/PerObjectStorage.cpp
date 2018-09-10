#include "Services/PerObjectStorage/PerObjectStorage.hpp"
#include "API/CGameObject.hpp"
#include "API/CNWSArea.hpp"
#include "API/CNWSObject.hpp"
#include "API/Constants.hpp"

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


void PerObjectStorage::Set(API::CGameObject *pGameObject, std::string key, int value)
{
    if (auto *pOS = GetObjectStorage(pGameObject))
    {
        pOS->GetIntMap()[key] = value;
    }
}
void PerObjectStorage::Set(API::CGameObject *pGameObject, std::string key, float value)
{
    if (auto *pOS = GetObjectStorage(pGameObject))
    {
        pOS->GetFloatMap()[key] = value;
    }
}
void PerObjectStorage::Set(API::CGameObject *pGameObject, std::string key, std::string value)
{
    if (auto *pOS = GetObjectStorage(pGameObject))
    {
        pOS->GetStringMap()[key] = value;
    }
}
void PerObjectStorage::Set(API::CGameObject *pGameObject, std::string key, void *value, CleanupFunc cleanup)
{
    if (auto *pOS = GetObjectStorage(pGameObject))
    {
        pOS->GetPointerMap()[key] = std::make_pair<>(value, cleanup);
    }
}



void PerObjectStorage::Remove(API::CGameObject *pGameObject, std::string key)
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
}
PerObjectStorage::ObjectStorage::~ObjectStorage()
{
    if (m_PointerMap)
    {
        for (auto it: *m_PointerMap)
        {
            auto ptr = it.second.first;
            auto cleanup = it.second.second;
            cleanup(ptr);
        }
    }
}



PerObjectStorageProxy::PerObjectStorageProxy(PerObjectStorage& perObjectStorage, std::string pluginName)
    : ServiceProxy<PerObjectStorage>(perObjectStorage)
{
    m_pluginName = pluginName;
}
PerObjectStorageProxy::~PerObjectStorageProxy()
{
    // TODO cleanup all storage from this plugin
}

void PerObjectStorageProxy::Set(API::CGameObject *pGameObject, std::string key, int value)
{
    m_proxyBase.Set(pGameObject, m_pluginName + "!" + key, value);
}
void PerObjectStorageProxy::Set(API::CGameObject *pGameObject, std::string key, float value)
{
    m_proxyBase.Set(pGameObject, m_pluginName + "!" + key, value);
}
void PerObjectStorageProxy::Set(API::CGameObject *pGameObject, std::string key, std::string value)
{
    m_proxyBase.Set(pGameObject, m_pluginName + "!" + key, value);
}
void PerObjectStorageProxy::Set(API::CGameObject *pGameObject, std::string key, void *value, PerObjectStorage::CleanupFunc cleanup)
{
    m_proxyBase.Set(pGameObject, m_pluginName + "!" + key, value, cleanup);
}

void PerObjectStorageProxy::Remove(API::CGameObject *pGameObject, std::string key)
{
    m_proxyBase.Remove(pGameObject, m_pluginName + "!" + key);
}


template <> Maybe<int> PerObjectStorage::Get<int>(API::CGameObject *pGameObject, std::string key)
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
template <> Maybe<float> PerObjectStorage::Get<float>(API::CGameObject *pGameObject, std::string key)
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
template <> Maybe<std::string> PerObjectStorage::Get<std::string>(API::CGameObject *pGameObject, std::string key)
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

template <> Maybe<void*> PerObjectStorage::Get<void*>(API::CGameObject *pGameObject, std::string key)
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
        LOG_DEBUG("Destroying object storage for objectId:0x%08x", pGameObject->m_idSelf);
        delete static_cast<PerObjectStorage::ObjectStorage*>(pGameObject->m_pNwnxData);
        pGameObject->m_pNwnxData = nullptr;
    }
}

void PerObjectStorage::CNWSObject__CNWSObjectDtor__0_hook(Services::Hooks::CallType type, API::CNWSObject* pThis)
{
    if (type == Services::Hooks::CallType::AFTER_ORIGINAL)
        DestroyObjectStorage(dynamic_cast<API::CGameObject*>(pThis));
}
void PerObjectStorage::CNWSArea__CNWSAreaDtor__0_hook(Services::Hooks::CallType type, API::CNWSArea* pThis)
{
    if (type == Services::Hooks::CallType::AFTER_ORIGINAL)
        DestroyObjectStorage(dynamic_cast<API::CGameObject*>(pThis));
}


}
}
