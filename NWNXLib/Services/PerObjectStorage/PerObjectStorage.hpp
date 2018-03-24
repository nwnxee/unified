#pragma once

#include "API/Types.hpp"
#include "API/CGameObject.hpp"
#include "API/CGameObjectArray.hpp"
#include "Maybe.hpp"
#include "Services/Services.hpp"
#include "Services/Hooks/Hooks.hpp"

#include <cstdint>
#include <memory>
#include <utility>
#include <unordered_map>

namespace NWNXLib {

namespace Services {

class PerObjectStorage : public ServiceBase
{
public:
    using CleanupFunc = void (*)(void*);
    void Set(API::Types::ObjectID object, std::string key, int value);
    void Set(API::Types::ObjectID object, std::string key, float value);
    void Set(API::Types::ObjectID object, std::string key, std::string value);
    void Set(API::Types::ObjectID object, std::string key, void *value, CleanupFunc cleanup = nullptr);

    // Gets the value, but doesn't remove it
    template <typename T> Maybe<T>
    Get(API::Types::ObjectID object, std::string key);

    // Removes without cleanup
    void Remove(API::Types::ObjectID object, std::string key);

    PerObjectStorage();
    ~PerObjectStorage();

    // Should really hook the CGameObject destructor, but that doesn't work currently..
    static void CGameObjectArray__Delete__1_hook(Services::Hooks::CallType type, API::CGameObjectArray* thisPtr, uint32_t, API::CGameObject**);
private:

    class ObjectStorage
    {
        // TODO maybe pack it up into a a single map?
    public:
        using IntMap     = std::unordered_map<std::string, int>;
        using FloatMap   = std::unordered_map<std::string, float>;
        using StringMap  = std::unordered_map<std::string, std::string>;
        using PointerMap = std::unordered_map<std::string, std::pair<void*, CleanupFunc>>;

        IntMap&     GetIntMap();
        FloatMap&   GetFloatMap();
        StringMap&  GetStringMap();
        PointerMap& GetPointerMap();

        ObjectStorage(API::Types::ObjectID owner);
        ~ObjectStorage();

        API::Types::ObjectID        m_oidOwner;
        std::unique_ptr<IntMap>     m_IntMap;
        std::unique_ptr<FloatMap>   m_FloatMap;
        std::unique_ptr<StringMap>  m_StringMap;
        std::unique_ptr<PointerMap> m_PointerMap;
    };

    static ObjectStorage& GetObjectStorage(API::Types::ObjectID object);
    static std::unordered_map<API::Types::ObjectID, std::unique_ptr<ObjectStorage>> g_objectStorage;
};

class PerObjectStorageProxy : public ServiceProxy<PerObjectStorage>
{
public:
    PerObjectStorageProxy(PerObjectStorage& perObjectStorage, std::string pluginName);
    ~PerObjectStorageProxy();

    void Set(API::Types::ObjectID object, std::string key, int value);
    void Set(API::Types::ObjectID object, std::string key, float value);
    void Set(API::Types::ObjectID object, std::string key, std::string value);
    void Set(API::Types::ObjectID object, std::string key, void *value, PerObjectStorage::CleanupFunc cleanup = nullptr);

    // Gets the value, but doesn't remove it
    template <typename T> Maybe<T>
    Get(API::Types::ObjectID object, std::string key)
    {
        return m_proxyBase.Get<T>(object, m_pluginName + "!" + key);
    }

    // Removes without cleanup
    void Remove(API::Types::ObjectID object, std::string key);

    //
    // Interfaces using CGameObject pointer directly:
    //
    void Set(API::CGameObject *pGameObject, std::string key, int value)
    {
        return Set(pGameObject->m_idSelf, key, value);
    }
    void Set(API::CGameObject *pGameObject, std::string key, float value)
    {
        return Set(pGameObject->m_idSelf, key, value);
    }
    void Set(API::CGameObject *pGameObject, std::string key, std::string value)
    {
        return Set(pGameObject->m_idSelf, key, value);
    }
    void Set(API::CGameObject *pGameObject, std::string key, void *value, PerObjectStorage::CleanupFunc cleanup = nullptr)
    {
        return Set(pGameObject->m_idSelf, key, value, cleanup);
    }
    template <typename T> Maybe<T>
    Get(API::CGameObject *pGameObject, std::string key)
    {
        return Get<T>(pGameObject->m_idSelf, key);
    }
    void Remove(API::CGameObject *pGameObject, std::string key)
    {
        return Remove(pGameObject->m_idSelf, key);
    }


private:
    std::string m_pluginName;
};


}

}
