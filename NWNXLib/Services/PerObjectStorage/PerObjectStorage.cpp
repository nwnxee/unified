#include "Services/PerObjectStorage/PerObjectStorage.hpp"
#include "API/CGameObject.hpp"
#include "API/CNWSArea.hpp"
#include "API/CNWSObject.hpp"
#include "API/CNWSPlayer.hpp"
#include "API/CNWSPlayerTURD.hpp"
#include "API/CNWSModule.hpp"
#include "API/CNWSUUID.hpp"
#include "API/CExoLinkedListInternal.hpp"
#include "API/CExoLinkedListNode.hpp"
#include "API/Constants.hpp"

#include <sstream>
#include <regex>

namespace NWNXLib::Services {

PerObjectStorage::ObjectStorage* PerObjectStorage::GetObjectStorage(CGameObject *pGameObject)
{
    if (!pGameObject)
        return nullptr;

    if (!pGameObject->m_pNwnxData)
    {
        pGameObject->m_pNwnxData = static_cast<void*>(new ObjectStorage(pGameObject->m_idSelf));
    }
    return static_cast<ObjectStorage*>(pGameObject->m_pNwnxData);
}

PerObjectStorage::ObjectStorage* PerObjectStorage::GetObjectStorage(ObjectID object)
{
    return GetObjectStorage(Utils::GetGameObject(object));
}


void PerObjectStorage::Set(CGameObject *pGameObject, const std::string& key, int value, bool persist)
{
    if (auto *pOS = GetObjectStorage(pGameObject))
    {
        pOS->GetIntMap()[key] = std::make_pair<>(value, persist);
    }
}
void PerObjectStorage::Set(CGameObject *pGameObject, const std::string& key, float value, bool persist)
{
    if (auto *pOS = GetObjectStorage(pGameObject))
    {
        pOS->GetFloatMap()[key] = std::make_pair<>(value, persist);
    }
}
void PerObjectStorage::Set(CGameObject *pGameObject, const std::string& key, std::string value, bool persist)
{
    if (auto *pOS = GetObjectStorage(pGameObject))
    {
        pOS->GetStringMap()[key] = std::make_pair<>(std::move(value), persist);
    }
}
void PerObjectStorage::Set(CGameObject *pGameObject, const std::string& key, void *value, CleanupFunc cleanup)
{
    if (auto *pOS = GetObjectStorage(pGameObject))
    {
        pOS->GetPointerMap()[key] = std::make_pair<>(value, cleanup);
    }
}



void PerObjectStorage::Remove(CGameObject *pGameObject, const std::string& key)
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

void PerObjectStorage::RemoveRegex(CGameObject *pGameObject, const std::string& regex)
{
    if (auto *pOS = GetObjectStorage(pGameObject))
    {
        std::regex rgx(regex);

        auto Remove = [&](auto &map) -> void {
            std::vector<std::string> erase;

            for (const auto& it: *map)
            {
                if (std::regex_match(it.first, rgx))
                    erase.push_back(it.first);
            }

            for (const auto& e: erase)
            {
                map->erase(e);
            }
        };

        if (pOS->m_StringMap)
            Remove(pOS->m_StringMap);
        if (pOS->m_IntMap)
            Remove(pOS->m_IntMap);
        if (pOS->m_FloatMap)
            Remove(pOS->m_FloatMap);
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

PerObjectStorage::ObjectStorage::ObjectStorage(ObjectID owner)
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
            ss << it.first << " = " << std::dec << it.second.first << (it.second.second?" (persistant)":"") << std::endl;
    }
    if (m_FloatMap)
    {
        for (auto it: *m_FloatMap)
            ss << it.first << " = " << it.second.first << (it.second.second?" (persistant)":"") << std::endl;
    }
    if (m_StringMap)
    {
        for (auto it: *m_StringMap)
            ss << it.first << " = " << it.second.first << (it.second.second?" (persistant)":"") << std::endl;
    }
    if (m_PointerMap)
    {
        for (auto it: *m_PointerMap)
            ss << it.first << " = " << it.second.first << std::endl;
    }
    return ss.str();
}


std::string PerObjectStorage::ObjectStorage::Serialize(bool persistonly)
{
    std::stringstream ss;
    if (m_IntMap)
    {
        int count = 0;
        for (auto it: *m_IntMap)
            count += (!persistonly || it.second.second) ? 1:0;

        if (count > 0)
        {
            ss << "[INTMAP:" << count << "]";
            for (auto it: *m_IntMap)
                if (!persistonly || it.second.second)
                    ss << "<" << it.first.length() << ">" << it.first << " = " << std::dec << it.second.first << ";";
        }
    }
    if (m_FloatMap)
    {
        int count = 0;
        for (auto it: *m_FloatMap)
            count += (!persistonly || it.second.second) ? 1:0;

        if (count > 0)
        {
            ss << "[FLTMAP:" << count << "]";
            for (auto it: *m_FloatMap)
                if (!persistonly || it.second.second)
                    ss << "<" << it.first.length() << ">" << it.first << " = " << it.second.first << ";";
        }
    }
    if (m_StringMap)
    {
        int count = 0;
        for (auto it: *m_StringMap)
            count += (!persistonly || it.second.second) ? 1:0;

        if (count > 0)
        {
            ss << "[STRMAP:" << count << "]";
            for (auto it: *m_StringMap)
                if (!persistonly || it.second.second)
                    ss << "<" << it.first.length() << ">" << it.first << " = " << "<" << it.second.first.length() << ">" << it.second.first << ";";
        }
    }
    return ss.str();
}
void PerObjectStorage::ObjectStorage::Deserialize(const char *serialized, bool persist)
{
    if (m_IntMap)     m_IntMap->clear();
    if (m_FloatMap)   m_FloatMap->clear();
    if (m_StringMap)  m_IntMap->clear();
    if (m_PointerMap) m_PointerMap->clear();

#define SSCANF_OR_ABORT(s, fmt, val) \
    do { int inc = 0; if (sscanf(s, fmt "%n", val, &inc) != 1)                                                        \
    {                                                                                                                 \
        LOG_ERROR("[%d] Serialized POS corrupted at '%20s', expected to parse '%s'. Aborting.\n", __LINE__, s, fmt);  \
        return;                                                                                                       \
    } s += inc; } while(0)

    const char *s;
    std::string name;
    int count, len;
    if ((s = strstr(serialized, "[INTMAP:")))
    {
        SSCANF_OR_ABORT(s, "[INTMAP:%d]", &count);

        for (int i = 0; i < count; i++)
        {
            SSCANF_OR_ABORT(s, "<%d>", &len);
            name = std::string{s, (size_t)len};
            s += len;

            int value;
            SSCANF_OR_ABORT(s, " = %d;", &value);
            GetIntMap()[name] = std::make_pair<>(value, persist);
        }
    }

    if ((s = strstr(serialized, "[FLTMAP:")))
    {
        SSCANF_OR_ABORT(s, "[FLTMAP:%d]", &count);

        for (int i = 0; i < count; i++)
        {
            SSCANF_OR_ABORT(s, "<%d>", &len);
            name = std::string{s, (size_t)len};
            s += len;

            float value;
            SSCANF_OR_ABORT(s, " = %f;", &value);
            GetFloatMap()[name] = std::make_pair<>(value, persist);
        }
    }

    if ((s = strstr(serialized, "[STRMAP:")))
    {
        SSCANF_OR_ABORT(s, "[STRMAP:%d]", &count);

        for (int i = 0; i < count; i++)
        {
            SSCANF_OR_ABORT(s, "<%d>", &len);
            name = std::string{s, (size_t)len};
            s += len;

            SSCANF_OR_ABORT(s, " = <%d>", &len);
            std::string value = std::string{s, (size_t)len};
            s += len + 1; // ';' at the end.
            GetStringMap().emplace(name, std::make_pair<>(std::move(value), persist));
        }
    }

#undef SSCANF_OR_ABORT
}

PerObjectStorageProxy::PerObjectStorageProxy(PerObjectStorage& perObjectStorage, std::string pluginName)
    : ServiceProxy<PerObjectStorage>(perObjectStorage), m_pluginName(std::move(pluginName))
{
}

PerObjectStorageProxy::~PerObjectStorageProxy()
{
    // TODO cleanup all storage from this plugin
}

void PerObjectStorageProxy::Set(CGameObject *pGameObject, const std::string& key, int value, bool persist)
{
    m_proxyBase.Set(pGameObject, m_pluginName + "!" + key, value, persist);
}
void PerObjectStorageProxy::Set(CGameObject *pGameObject, const std::string& key, float value, bool persist)
{
    m_proxyBase.Set(pGameObject, m_pluginName + "!" + key, value, persist);
}
void PerObjectStorageProxy::Set(CGameObject *pGameObject, const std::string& key, std::string value, bool persist)
{
    m_proxyBase.Set(pGameObject, m_pluginName + "!" + key, std::move(value), persist);
}
void PerObjectStorageProxy::Set(CGameObject *pGameObject, const std::string& key, void *value, PerObjectStorage::CleanupFunc cleanup)
{
    m_proxyBase.Set(pGameObject, m_pluginName + "!" + key, value, cleanup);
}

void PerObjectStorageProxy::Remove(CGameObject *pGameObject, const std::string& key)
{
    m_proxyBase.Remove(pGameObject, m_pluginName + "!" + key);
}
void PerObjectStorageProxy::RemoveRegex(CGameObject *pGameObject, const std::string& regex)
{
    m_proxyBase.RemoveRegex(pGameObject, "(?:" + m_pluginName + "!)" + regex);
}


template <> std::optional<int> PerObjectStorage::Get<int>(CGameObject *pGameObject, const std::string& key)
{
    if (auto *pOS = GetObjectStorage(pGameObject))
    {
        auto map = pOS->GetIntMap();
        auto it = map.find(key);
        if (it != map.end())
            return std::make_optional<int>(it->second.first);
    }
    return std::optional<int>();
}

template <> std::optional<float> PerObjectStorage::Get<float>(CGameObject *pGameObject, const std::string& key)
{
    if (auto *pOS = GetObjectStorage(pGameObject))
    {
        auto map = pOS->GetFloatMap();
        auto it = map.find(key);
        if (it != map.end())
            return std::make_optional<float>(it->second.first);
    }
    return std::optional<float>();
}

template <> std::optional<std::string> PerObjectStorage::Get<std::string>(CGameObject *pGameObject, const std::string& key)
{
    if (auto *pOS = GetObjectStorage(pGameObject))
    {
        auto map = pOS->GetStringMap();
        auto it = map.find(key);
        if (it != map.end())
            return std::make_optional<std::string>(it->second.first);
    }
    return std::optional<std::string>();
}

template <> std::optional<void*> PerObjectStorage::Get<void*>(CGameObject *pGameObject, const std::string& key)
{
    if (auto *pOS = GetObjectStorage(pGameObject))
    {
        auto map = pOS->GetPointerMap();
        auto it = map.find(key);
        if (it != map.end())
            return std::make_optional<void*>(it->second.first);
    }
    return std::optional<void*>();
}

void PerObjectStorage::DestroyObjectStorage(CGameObject *pGameObject)
{
    if (pGameObject->m_pNwnxData)
    {
        delete static_cast<PerObjectStorage::ObjectStorage*>(pGameObject->m_pNwnxData);
        pGameObject->m_pNwnxData = nullptr;
    }
}

void PerObjectStorage::CNWSObject__CNWSObjectDtor__0_hook(bool before, CNWSObject* pThis)
{
    if (!before)
        DestroyObjectStorage(static_cast<CGameObject*>(pThis));
}
void PerObjectStorage::CNWSArea__CNWSAreaDtor__0_hook(bool before, CNWSArea* pThis)
{
    if (!before)
        DestroyObjectStorage(static_cast<CGameObject*>(pThis));
}
void PerObjectStorage::CNWSPlayer__EatTURD_hook(bool before, CNWSPlayer* thisPtr, CNWSPlayerTURD* pTURD)
{
    if (before)
    {
        GetObjectStorage(thisPtr->m_oidNWSObject)->CloneFrom(GetObjectStorage(pTURD));
    }
}
void PerObjectStorage::CNWSPlayer__DropTURD_hook(bool before, CNWSPlayer* thisPtr)
{
    if (!before)
    {
        // Be very, very paranoid. Bad things happen when the TURD list doesn't exist
        // This can happen when you BootPC() the very first PC to connect to your sever
        //     https://github.com/nwnxee/unified/issues/319
        if (auto turdlist = Utils::GetModule()->m_lstTURDList.m_pcExoLinkedListInternal)
        {
            if (auto *pHead = turdlist->pHead)
            {
                if (auto *pTURD = static_cast<CNWSPlayerTURD*>(pHead->pObject))
                {
                    GetObjectStorage(pTURD)->CloneFrom(GetObjectStorage(thisPtr->m_oidNWSObject));
                }
            }
        }
    }
}


void PerObjectStorage::CNWSUUID__SaveToGff_hook(bool before, CNWSUUID* pThis, CResGFF* pRes, CResStruct* pStruct)
{
    if (before)
    {
        pRes->WriteFieldCExoString(pStruct, GetObjectStorage(pThis->m_parent)->Serialize(), GffFieldName);
    }
}
void PerObjectStorage::CNWSUUID__LoadFromGff_hook(bool before, CNWSUUID* pThis, CResGFF* pRes, CResStruct* pStruct)
{
    if (before)
    {
        int32_t success;
        auto str = pRes->ReadFieldCExoString(pStruct, GffFieldName, success);
        if (success)
            GetObjectStorage(pThis->m_parent)->Deserialize(str.CStr());
    }
}

}
