#pragma once

#include "Services/Services.hpp"
#include "Services/Hooks/Hooks.hpp"
#include "Utils.hpp"

#include <cstdint>
#include <memory>
#include <utility>
#include <unordered_map>
#include <optional>

namespace NWNXLib {

namespace Services {

class PerObjectStorage
{
public:
    using CleanupFunc = void (*)(void*);
    void Set(CGameObject *pGameObject, const std::string& key, int value, bool persist = false);
    void Set(CGameObject *pGameObject, const std::string& key, float value, bool persist = false);
    void Set(CGameObject *pGameObject, const std::string& key, std::string value, bool persist = false);
    void Set(CGameObject *pGameObject, const std::string& key, void *value, CleanupFunc cleanup = nullptr);

    // Gets the value, but doesn't remove it
    template <typename T> std::optional<T>
    Get(CGameObject *pGameObject, const std::string& key);

    // Removes without cleanup
    void Remove(CGameObject *pGameObject, const std::string& key);
    void RemoveRegex(CGameObject *pGameObject, const std::string& regex);

    PerObjectStorage();
    ~PerObjectStorage();

    static inline char GffFieldName[] = "NWNX_POS";

    static void CNWSObject__CNWSObjectDtor__0_hook(bool, CNWSObject* thisPtr);
    static void CNWSArea__CNWSAreaDtor__0_hook(bool, CNWSArea* thisPtr);
    static void CNWSPlayer__EatTURD_hook(bool, CNWSPlayer* thisPtr, CNWSPlayerTURD* pTURD);
    static void CNWSPlayer__DropTURD_hook(bool, CNWSPlayer* thisPtr);
    static void CNWSUUID__SaveToGff_hook(bool, CNWSUUID* pThis, CResGFF* pRes, CResStruct* pStruct);
    static void CNWSUUID__LoadFromGff_hook(bool, CNWSUUID* pThis, CResGFF* pRes, CResStruct* pStruct);
private:
    class ObjectStorage
    {
        // TODO maybe pack it up into a a single map?
    public:
        using IntMap     = std::unordered_map<std::string, std::pair<int, bool>>;
        using FloatMap   = std::unordered_map<std::string, std::pair<float, bool>>;
        using StringMap  = std::unordered_map<std::string, std::pair<std::string, bool>>;
        using PointerMap = std::unordered_map<std::string, std::pair<void*, CleanupFunc>>;

        IntMap&     GetIntMap();
        FloatMap&   GetFloatMap();
        StringMap&  GetStringMap();
        PointerMap& GetPointerMap();

        ObjectStorage(ObjectID owner);
        ~ObjectStorage();

        void CloneFrom(ObjectStorage *other);
        std::string DumpToString();
        std::string Serialize(bool persistonly = true);
        void Deserialize(const char *serialized, bool persist = true);

        ObjectID        m_oidOwner;
        bool                        m_bCloned;
        std::unique_ptr<IntMap>     m_IntMap;
        std::unique_ptr<FloatMap>   m_FloatMap;
        std::unique_ptr<StringMap>  m_StringMap;
        std::unique_ptr<PointerMap> m_PointerMap;
    };

    static ObjectStorage* GetObjectStorage(ObjectID object);
    static ObjectStorage* GetObjectStorage(CGameObject *pGameObject);
    static void DestroyObjectStorage(CGameObject *pGameObject);
};

class PerObjectStorageProxy : public ServiceProxy<PerObjectStorage>
{
public:
    PerObjectStorageProxy(PerObjectStorage& perObjectStorage, std::string pluginName);
    ~PerObjectStorageProxy();

    void Set(CGameObject *pGameObject, const std::string& key, int value, bool persist = false);
    void Set(CGameObject *pGameObject, const std::string& key, float value, bool persist = false);
    void Set(CGameObject *pGameObject, const std::string& key, std::string value, bool persist = false);
    void Set(CGameObject *pGameObject, const std::string& key, void *value, PerObjectStorage::CleanupFunc cleanup = nullptr);

    // Gets the value, but doesn't remove it
    template <typename T> std::optional<T>
    Get(CGameObject *pGameObject, const std::string& key)
    {
        return m_proxyBase.Get<T>(pGameObject, m_pluginName + "!" + key);
    }

    // Removes without cleanup
    void Remove(CGameObject *pGameObject, const std::string& key);
    void RemoveRegex(CGameObject *pGameObject, const std::string& regex);

    //
    // Interfaces using objectID instead of CGameObject pointer
    //
    void Set(ObjectID object, const std::string& key, int value, bool persist = false)
    {
        return Set(Utils::GetGameObject(object), key, value, persist);
    }
    void Set(ObjectID object, const std::string& key, float value, bool persist = false)
    {
        return Set(Utils::GetGameObject(object), key, value, persist);
    }
    void Set(ObjectID object, const std::string& key, std::string value, bool persist = false)
    {
        return Set(Utils::GetGameObject(object), key, value, persist);
    }
    void Set(ObjectID object, const std::string& key, void *value, PerObjectStorage::CleanupFunc cleanup = nullptr)
    {
        return Set(Utils::GetGameObject(object), key, value, cleanup);
    }
    template <typename T> std::optional<T>
    Get(ObjectID object, const std::string& key)
    {
        return Get<T>(Utils::GetGameObject(object), key);
    }

    void Remove(ObjectID object, const std::string& key)
    {
        return Remove(Utils::GetGameObject(object), key);
    }

    void RemoveRegex(ObjectID object, const std::string& regex)
    {
        return RemoveRegex(Utils::GetGameObject(object), regex);
    }


private:
    std::string m_pluginName;
};


}

}
