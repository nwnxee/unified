#include "Services/PerObjectStorage/PerObjectStorage.hpp"
#include "API/Constants.hpp"

namespace NWNXLib {

namespace Services {


void PerObjectStorage::Set(API::Types::ObjectID object, std::string key, int value)
{
    // TODO: check if the object is actually valid
    if (object == API::Constants::OBJECT_INVALID)
        return;

    m_objectStorage[object]->GetIntMap().emplace(key, value);
}
void PerObjectStorage::Set(API::Types::ObjectID object, std::string key, float value)
{
    // TODO: check if the object is actually valid
    if (object == API::Constants::OBJECT_INVALID)
        return;

    m_objectStorage[object]->GetFloatMap().emplace(key, value);
}
void PerObjectStorage::Set(API::Types::ObjectID object, std::string key, std::string value)
{
    // TODO: check if the object is actually valid
    if (object == API::Constants::OBJECT_INVALID)
        return;

    m_objectStorage[object]->GetStringMap().emplace(key, value);
}
void PerObjectStorage::Set(API::Types::ObjectID object, std::string key, void *value, CleanupFunc cleanup)
{
    // TODO: check if the object is actually valid
    if (object == API::Constants::OBJECT_INVALID)
        return;

    m_objectStorage[object]->GetPointerMap().emplace(key, std::make_pair<>(value, cleanup));
}



void PerObjectStorage::Remove(API::Types::ObjectID object, std::string key)
{
    auto it = m_objectStorage.find(object);
    if (it != m_objectStorage.end())
    {
        it->second->GetStringMap().erase(key);
        it->second->GetIntMap().erase(key);
        it->second->GetFloatMap().erase(key);
        it->second->GetPointerMap().erase(key);
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
    for (auto it: *m_PointerMap)
    {
        auto ptr = it.second.first;
        auto cleanup = it.second.second;
        cleanup(ptr);
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



template <> Maybe<int> PerObjectStorage::Get<int>(API::Types::ObjectID object, std::string key);
template <> Maybe<float> PerObjectStorage::Get<float>(API::Types::ObjectID object, std::string key);
template <> Maybe<std::string> PerObjectStorage::Get<std::string>(API::Types::ObjectID object, std::string key);
template <> Maybe<void*> PerObjectStorage::Get<void*>(API::Types::ObjectID object, std::string key);

template <> Maybe<int> PerObjectStorage::Get<int>(API::Types::ObjectID object, std::string key)
{
    auto it = m_objectStorage.find(object);
    if (it != m_objectStorage.end())
    {
        auto map = it->second->GetIntMap();
        auto it2 = map.find(key);
        if (it2 != map.end())
            return Maybe<int>(std::move(it2->second));
    }
    return Maybe<int>();
}
template <> Maybe<float> PerObjectStorage::Get<float>(API::Types::ObjectID object, std::string key)
{
    auto it = m_objectStorage.find(object);
    if (it != m_objectStorage.end())
    {
        auto map = it->second->GetFloatMap();
        auto it2 = map.find(key);
        if (it2 != map.end())
            return Maybe<float>(std::move(it2->second));
    }
    return Maybe<float>();
}
template <> Maybe<std::string> PerObjectStorage::Get<std::string>(API::Types::ObjectID object, std::string key)
{
    auto it = m_objectStorage.find(object);
    if (it != m_objectStorage.end())
    {
        auto map = it->second->GetStringMap();
        auto it2 = map.find(key);
        if (it2 != map.end())
            return Maybe<std::string>(std::move(it2->second));
    }
    return Maybe<std::string>();
}

template <> Maybe<void*> PerObjectStorage::Get<void*>(API::Types::ObjectID object, std::string key)
{
    auto it = m_objectStorage.find(object);
    if (it != m_objectStorage.end())
    {
        auto map = it->second->GetPointerMap();
        auto it2 = map.find(key);
        if (it2 != map.end())
            return Maybe<void*>(std::move(it2->second.first));
    }
    return Maybe<void*>();
}

void PerObjectStorage::CGameObject_dtor_hook(Services::Hooks::CallType type, API::CGameObject *thisPtr)
{
    if (type != Services::Hooks::CallType::BEFORE_ORIGINAL)
        return;

    m_objectStorage.erase(thisPtr->m_idSelf);
}


}
}
