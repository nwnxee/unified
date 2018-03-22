#include "Services/PerObjectStorage/PerObjectStorage.hpp"
#include "API/Constants.hpp"

namespace NWNXLib {

namespace Services {

std::unordered_map<API::Types::ObjectID, std::unique_ptr<PerObjectStorage::ObjectStorage>> PerObjectStorage::g_objectStorage;

PerObjectStorage::ObjectStorage& PerObjectStorage::GetObjectStorage(API::Types::ObjectID object)
{
    auto it = g_objectStorage.find(object);
    if (it != g_objectStorage.end())
        return *it->second;

    return *g_objectStorage.emplace(object, std::make_unique<PerObjectStorage::ObjectStorage>(object)).first->second;
}


void PerObjectStorage::Set(API::Types::ObjectID object, std::string key, int value)
{
    // TODO: check if the object is actually valid
    if (object == API::Constants::OBJECT_INVALID)
        return;

    GetObjectStorage(object).GetIntMap()[key] = value;
}
void PerObjectStorage::Set(API::Types::ObjectID object, std::string key, float value)
{
    // TODO: check if the object is actually valid
    if (object == API::Constants::OBJECT_INVALID)
        return;

    GetObjectStorage(object).GetFloatMap()[key] = value;
}
void PerObjectStorage::Set(API::Types::ObjectID object, std::string key, std::string value)
{
    // TODO: check if the object is actually valid
    if (object == API::Constants::OBJECT_INVALID)
        return;

    GetObjectStorage(object).GetStringMap()[key] = value;
}
void PerObjectStorage::Set(API::Types::ObjectID object, std::string key, void *value, CleanupFunc cleanup)
{
    // TODO: check if the object is actually valid
    if (object == API::Constants::OBJECT_INVALID)
        return;

    GetObjectStorage(object).GetPointerMap()[key] = std::make_pair<>(value, cleanup);
}



void PerObjectStorage::Remove(API::Types::ObjectID object, std::string key)
{
    auto it = g_objectStorage.find(object);
    if (it != g_objectStorage.end())
    {
        // Ugly, but GetXxxMap will create it if missing.
        if (it->second->m_StringMap)
            it->second->m_StringMap->erase(key);
        if (it->second->m_IntMap)
            it->second->m_IntMap->erase(key);
        if (it->second->m_FloatMap)
            it->second->m_FloatMap->erase(key);
        if (it->second->m_PointerMap)
            it->second->m_PointerMap->erase(key);
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

void PerObjectStorageProxy::Set(API::Types::ObjectID object, std::string key, int value)
{
    m_proxyBase.Set(object, m_pluginName + "!" + key, value);
}
void PerObjectStorageProxy::Set(API::Types::ObjectID object, std::string key, float value)
{
    m_proxyBase.Set(object, m_pluginName + "!" + key, value);
}
void PerObjectStorageProxy::Set(API::Types::ObjectID object, std::string key, std::string value)
{
    m_proxyBase.Set(object, m_pluginName + "!" + key, value);
}
void PerObjectStorageProxy::Set(API::Types::ObjectID object, std::string key, void *value, PerObjectStorage::CleanupFunc cleanup)
{
    m_proxyBase.Set(object, m_pluginName + "!" + key, value, cleanup);
}

void PerObjectStorageProxy::Remove(API::Types::ObjectID object, std::string key)
{
    m_proxyBase.Remove(object, m_pluginName + "!" + key);
}


template <> Maybe<int> PerObjectStorage::Get<int>(API::Types::ObjectID object, std::string key)
{
    auto it = g_objectStorage.find(object);
    if (it != g_objectStorage.end())
    {
        auto map = it->second->GetIntMap();
        auto it2 = map.find(key);
        if (it2 != map.end())
            return Maybe<int>(it2->second);
    }
    return Maybe<int>();
}
template <> Maybe<float> PerObjectStorage::Get<float>(API::Types::ObjectID object, std::string key)
{
    auto it = g_objectStorage.find(object);
    if (it != g_objectStorage.end())
    {
        auto map = it->second->GetFloatMap();
        auto it2 = map.find(key);
        if (it2 != map.end())
            return Maybe<float>(it2->second);
    }
    return Maybe<float>();
}
template <> Maybe<std::string> PerObjectStorage::Get<std::string>(API::Types::ObjectID object, std::string key)
{
    auto it = g_objectStorage.find(object);
    if (it != g_objectStorage.end())
    {
        auto map = it->second->GetStringMap();
        auto it2 = map.find(key);
        if (it2 != map.end())
            return Maybe<std::string>(it2->second);
    }
    return Maybe<std::string>();
}

template <> Maybe<void*> PerObjectStorage::Get<void*>(API::Types::ObjectID object, std::string key)
{
    auto it = g_objectStorage.find(object);
    if (it != g_objectStorage.end())
    {
        auto map = it->second->GetPointerMap();
        auto it2 = map.find(key);
        if (it2 != map.end())
            return Maybe<void*>(it2->second.first);
    }
    return Maybe<void*>();
}

void PerObjectStorage::CGameObjectArray__Delete__1_hook(Services::Hooks::CallType type, API::CGameObjectArray* thisPtr, uint32_t id, API::CGameObject **ptr)
{
    // unreferenced variables
    (void)(sizeof(thisPtr) & sizeof(ptr));

    if (type != Services::Hooks::CallType::AFTER_ORIGINAL)
        return;

    id &= 0x7FFFFFFF;
    LOG_DEBUG("Destroying object storage for objectId:0x%08x", id);

    g_objectStorage.erase(id);
}


}
}
