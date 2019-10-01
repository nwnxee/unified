#pragma once

#include "API/Types.hpp"
#include "Maybe.hpp"
#include "Services/Services.hpp"
#include "Services/Hooks/Hooks.hpp"
#include "Utils.hpp"

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
    void Set(API::CGameObject *pGameObject, const std::string& key, int value);
    void Set(API::CGameObject *pGameObject, const std::string& key, float value);
    void Set(API::CGameObject *pGameObject, const std::string& key, std::string value);
    void Set(API::CGameObject *pGameObject, const std::string& key, void *value, CleanupFunc cleanup = nullptr);

    // Gets the value, but doesn't remove it
    template <typename T> Maybe<T>
    Get(API::CGameObject *pGameObject, const std::string& key);

    // Removes without cleanup
    void Remove(API::CGameObject *pGameObject, const std::string& key);

    PerObjectStorage();
    ~PerObjectStorage();

    static void CNWSObject__CNWSObjectDtor__0_hook(Services::Hooks::CallType type, API::CNWSObject* thisPtr);
    static void CNWSArea__CNWSAreaDtor__0_hook(Services::Hooks::CallType type, API::CNWSArea* thisPtr);
    static void CNWSPlayer__EatTURD_hook(Services::Hooks::CallType type, API::CNWSPlayer* thisPtr, API::CNWSPlayerTURD* pTURD);
    static void CNWSPlayer__DropTURD_hook(Services::Hooks::CallType type, API::CNWSPlayer* thisPtr);
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

        void CloneFrom(ObjectStorage *other);
        std::string DumpToString();

        API::Types::ObjectID        m_oidOwner;
        bool                        m_bCloned;
        std::unique_ptr<IntMap>     m_IntMap;
        std::unique_ptr<FloatMap>   m_FloatMap;
        std::unique_ptr<StringMap>  m_StringMap;
        std::unique_ptr<PointerMap> m_PointerMap;
    };

    static ObjectStorage* GetObjectStorage(API::Types::ObjectID object);
    static ObjectStorage* GetObjectStorage(API::CGameObject *pGameObject);
    static void DestroyObjectStorage(API::CGameObject *pGameObject);
};

class PerObjectStorageProxy : public ServiceProxy<PerObjectStorage>
{
public:
    PerObjectStorageProxy(PerObjectStorage& perObjectStorage, std::string pluginName);
    ~PerObjectStorageProxy();

    void Set(API::CGameObject *pGameObject, const std::string& key, int value);
    void Set(API::CGameObject *pGameObject, const std::string& key, float value);
    void Set(API::CGameObject *pGameObject, const std::string& key, std::string value);
    void Set(API::CGameObject *pGameObject, const std::string& key, void *value, PerObjectStorage::CleanupFunc cleanup = nullptr);

    // Gets the value, but doesn't remove it
    template <typename T> Maybe<T>
    Get(API::CGameObject *pGameObject, const std::string& key)
    {
        return m_proxyBase.Get<T>(pGameObject, m_pluginName + "!" + key);
    }

    // Removes without cleanup
    void Remove(API::CGameObject *pGameObject, const std::string& key);

    //
    // Interfaces using objectID instead of CGameObject pointer
    //
    void Set(API::Types::ObjectID object, const std::string& key, int value)
    {
        return Set(Utils::GetGameObject(object), key, value);
    }
    void Set(API::Types::ObjectID object, const std::string& key, float value)
    {
        return Set(Utils::GetGameObject(object), key, value);
    }
    void Set(API::Types::ObjectID object, const std::string& key, std::string value)
    {
        return Set(Utils::GetGameObject(object), key, value);
    }
    void Set(API::Types::ObjectID object, const std::string& key, void *value, PerObjectStorage::CleanupFunc cleanup = nullptr)
    {
        return Set(Utils::GetGameObject(object), key, value, cleanup);
    }
    template <typename T> Maybe<T>
    Get(API::Types::ObjectID object, const std::string& key)
    {
        return Get<T>(Utils::GetGameObject(object), key);
    }

    void Remove(API::Types::ObjectID object, const std::string& key)
    {
        return Remove(Utils::GetGameObject(object), key);
    }


private:
    std::string m_pluginName;
};


}

}
