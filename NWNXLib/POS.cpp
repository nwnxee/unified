#include "nwnx.hpp"
#include "API/CGameObject.hpp"
#include "API/CNWSObject.hpp"
#include "API/CGameObjectArray.hpp"
#include "API/CNWSArea.hpp"
#include "API/CNWSPlayer.hpp"
#include "API/CNWSUUID.hpp"
#include "API/CNWSModule.hpp"
#include "API/CNWSPlayerTURD.hpp"

#include <regex>
#include <unordered_map>
#include <sstream>

extern "C" void _ZN10CNWSObjectD1Ev(CNWSObject*);
extern "C" void _ZN8CNWSAreaD1Ev(CNWSArea*);

using namespace NWNXLib;
namespace NWNXLib::POS
{
static char GffFieldName[] = "NWNX_POS";

class ObjectStorage
{
    // TODO maybe pack it up into a a single map?
public:
    using IntMap     = std::unordered_map<std::string, std::pair<int, bool>>;
    using FloatMap   = std::unordered_map<std::string, std::pair<float, bool>>;
    using StringMap  = std::unordered_map<std::string, std::pair<std::string, bool>>;
    using PointerMap = std::unordered_map<std::string, std::pair<void*, CleanupFunc>>;

    IntMap& GetIntMap()
    {
        if (!m_IntMap)
            m_IntMap = std::make_unique<IntMap>();
        return *m_IntMap;
    }
    FloatMap& GetFloatMap()
    {
        if (!m_FloatMap)
            m_FloatMap = std::make_unique<FloatMap>();
        return *m_FloatMap;
    }
    StringMap& GetStringMap()
    {
        if (!m_StringMap)
            m_StringMap = std::make_unique<StringMap>();
        return *m_StringMap;
    }
    PointerMap& GetPointerMap()
    {
        if (!m_PointerMap)
            m_PointerMap = std::make_unique<PointerMap>();
        return *m_PointerMap;
    }

    ObjectStorage(ObjectID owner) : m_oidOwner(owner), m_bCloned(false) {}
    ~ObjectStorage()
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

    void CloneFrom(ObjectStorage *other)
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

    std::string DumpToString()
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

    std::string Serialize(bool persistonly = true)
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
    void Deserialize(const char *serialized, bool persist = true)
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

    ObjectID        m_oidOwner;
    bool                        m_bCloned;
    std::unique_ptr<IntMap>     m_IntMap;
    std::unique_ptr<FloatMap>   m_FloatMap;
    std::unique_ptr<StringMap>  m_StringMap;
    std::unique_ptr<PointerMap> m_PointerMap;
};

static ObjectStorage* GetObjectStorage(CGameObject *pGameObject)
{
    if (!pGameObject)
        return nullptr;

    if (!pGameObject->m_pNwnxData)
    {
        pGameObject->m_pNwnxData = static_cast<void*>(new ObjectStorage(pGameObject->m_idSelf));
    }
    return static_cast<ObjectStorage*>(pGameObject->m_pNwnxData);
}
static void DestroyObjectStorage(CGameObject *pGameObject)
{
    if (pGameObject->m_pNwnxData)
    {
        delete static_cast<ObjectStorage*>(pGameObject->m_pNwnxData);
        pGameObject->m_pNwnxData = nullptr;
    }
}

void Set(CGameObject *pGameObject, const std::string& prefix, const std::string& key, int value, bool persist)
{
    auto fullkey = prefix + "!" + key;
    if (auto *pOS = GetObjectStorage(pGameObject))
        pOS->GetIntMap()[fullkey] = std::make_pair<>(value, persist);
}
void Set(CGameObject *pGameObject, const std::string& prefix, const std::string& key, float value, bool persist)
{
    auto fullkey = prefix + "!" + key;
    if (auto *pOS = GetObjectStorage(pGameObject))
        pOS->GetFloatMap()[fullkey] = std::make_pair<>(value, persist);
}
void Set(CGameObject *pGameObject, const std::string& prefix, const std::string& key, std::string value, bool persist)
{
    auto fullkey = prefix + "!" + key;
    if (auto *pOS = GetObjectStorage(pGameObject))
        pOS->GetStringMap()[fullkey] = std::make_pair<>(std::move(value), persist);
}
void Set(CGameObject *pGameObject, const std::string& prefix, const std::string& key, void *value, std::optional<CleanupFunc> cleanup)
{
    auto fullkey = prefix + "!" + key;
    if (auto *pOS = GetObjectStorage(pGameObject))
        pOS->GetPointerMap()[fullkey] = std::make_pair<>(value, cleanup.value_or(nullptr));
}


template <> std::optional<int> Get<int>(CGameObject *pGameObject, const std::string& prefix, const std::string& key)
{
    if (auto *pOS = GetObjectStorage(pGameObject))
    {
        auto fullkey = prefix + "!" + key;
        auto map = pOS->GetIntMap();
        auto it = map.find(fullkey);
        if (it != map.end())
            return std::make_optional<int>(it->second.first);
    }
    return std::optional<int>();
}

template <> std::optional<float> Get<float>(CGameObject *pGameObject, const std::string& prefix, const std::string& key)
{
    if (auto *pOS = GetObjectStorage(pGameObject))
    {
        auto fullkey = prefix + "!" + key;
        auto map = pOS->GetFloatMap();
        auto it = map.find(fullkey);
        if (it != map.end())
            return std::make_optional<float>(it->second.first);
    }
    return std::optional<float>();
}

template <> std::optional<std::string> Get<std::string>(CGameObject *pGameObject,  const std::string& prefix, const std::string& key)
{
    if (auto *pOS = GetObjectStorage(pGameObject))
    {
        auto fullkey = prefix + "!" + key;
        auto map = pOS->GetStringMap();
        auto it = map.find(fullkey);
        if (it != map.end())
            return std::make_optional<std::string>(it->second.first);
    }
    return std::optional<std::string>();
}

template <> std::optional<void*> Get<void*>(CGameObject *pGameObject, const std::string& prefix, const std::string& key)
{
    if (auto *pOS = GetObjectStorage(pGameObject))
    {
        auto fullkey = prefix + "!" + key;
        auto map = pOS->GetPointerMap();
        auto it = map.find(fullkey);
        if (it != map.end())
            return std::make_optional<void*>(it->second.first);
    }
    return std::optional<void*>();
}

void Remove(CGameObject *pGameObject, const std::string& prefix, const std::string& key)
{
    if (auto *pOS = GetObjectStorage(pGameObject))
    {
        auto fullkey = prefix + "!" + key;
        // Ugly, but GetXxxMap will create it if missing.
        if (pOS->m_StringMap)
            pOS->m_StringMap->erase(fullkey);
        if (pOS->m_IntMap)
            pOS->m_IntMap->erase(fullkey);
        if (pOS->m_FloatMap)
            pOS->m_FloatMap->erase(fullkey);
        if (pOS->m_PointerMap)
            pOS->m_PointerMap->erase(fullkey);
    }
}

void RemoveRegex(CGameObject *pGameObject, const std::string& prefix, const std::string& regex)
{
    auto fullregex = "(?:" + prefix + "!)" + regex;
    if (auto *pOS = GetObjectStorage(pGameObject))
    {
        std::regex rgx(fullregex);

        auto Remove = [&](auto &map) -> void
        {
            std::vector<std::string> erase;

            for (const auto& it: *map)
            {
                if (std::regex_match(it.first, rgx))
                    erase.push_back(it.first);
            }

            for (const auto& e: erase)
                map->erase(e);
        };

        if (pOS->m_StringMap)
            Remove(pOS->m_StringMap);
        if (pOS->m_IntMap)
            Remove(pOS->m_IntMap);
        if (pOS->m_FloatMap)
            Remove(pOS->m_FloatMap);
        if (pOS->m_PointerMap)
            Remove(pOS->m_PointerMap);
    }
}

void InitializeHooks()
{
    static Hooks::Hook s_ObjectDtorHook      = Hooks::HookFunction(&_ZN10CNWSObjectD1Ev, 
        +[](CNWSObject* pThis)
        {
            s_ObjectDtorHook->CallOriginal<void>(pThis);
            DestroyObjectStorage(static_cast<CGameObject*>(pThis));
        }, Hooks::Order::VeryEarly);

    static Hooks::Hook s_AreaDtorHook        = Hooks::HookFunction(&_ZN8CNWSAreaD1Ev,
        +[](CNWSArea* pThis)
        {
            s_AreaDtorHook->CallOriginal<void>(pThis);
            DestroyObjectStorage(static_cast<CGameObject*>(pThis));
        }, Hooks::Order::VeryEarly);

    static Hooks::Hook s_EatTURDHook         = Hooks::HookFunction(&CNWSPlayer::EatTURD, 
        +[](CNWSPlayer* pThis, CNWSPlayerTURD* pTURD)
        {
            auto pObjThis = Utils::GetGameObject(pThis->m_oidNWSObject);
            GetObjectStorage(pObjThis)->CloneFrom(GetObjectStorage(pTURD));
            s_EatTURDHook->CallOriginal<void>(pThis, pTURD);
        }, Hooks::Order::VeryEarly);

    static Hooks::Hook s_DropTURDHook        = Hooks::HookFunction(&CNWSPlayer::DropTURD,
        +[](CNWSPlayer* pThis)
        {
            s_DropTURDHook->CallOriginal<void>(pThis);

            // Be very, very paranoid. Bad things happen when the TURD list doesn't exist
            // This can happen when you BootPC() the very first PC to connect to your sever
            //     https://github.com/nwnxee/unified/issues/319
            if (auto turdlist = Utils::GetModule()->m_lstTURDList.m_pcExoLinkedListInternal)
            {
                if (auto *pHead = turdlist->pHead)
                {
                    if (auto *pTURD = static_cast<CNWSPlayerTURD*>(pHead->pObject))
                    {
                        auto pObjThis = Utils::GetGameObject(pThis->m_oidNWSObject);
                        GetObjectStorage(pTURD)->CloneFrom(GetObjectStorage(pObjThis));
                    }
                }
            }
        }, Hooks::Order::VeryEarly);

    static Hooks::Hook s_UUIDSaveToGffHook   = Hooks::HookFunction(&CNWSUUID::SaveToGff,
        +[](CNWSUUID* pThis, CResGFF* pRes, CResStruct* pStruct)
        {
            pRes->WriteFieldCExoString(pStruct, GetObjectStorage(pThis->m_parent)->Serialize(), GffFieldName);
            s_UUIDSaveToGffHook->CallOriginal<void>(pThis, pRes, pStruct);
        }, Hooks::Order::VeryEarly);

    static Hooks::Hook s_UUIDLoadFromGffHook = Hooks::HookFunction(&CNWSUUID::LoadFromGff,
        +[](CNWSUUID* pThis, CResGFF* pRes, CResStruct* pStruct) -> bool
        {
            int32_t success;
            auto str = pRes->ReadFieldCExoString(pStruct, GffFieldName, success);
            if (success)
                GetObjectStorage(pThis->m_parent)->Deserialize(str.CStr());

            return s_UUIDLoadFromGffHook->CallOriginal<bool>(pThis, pRes, pStruct);
        }, Hooks::Order::VeryEarly);
}

}

void CGameObject::nwnxSet(const std::string& key, int value, bool persist, const char *pn)
{
    POS::Set(this, pn, key, value, persist);
}
void CGameObject::nwnxSet(const std::string& key, float value, bool persist, const char *pn)
{
    POS::Set(this, pn, key, value, persist);
}
void CGameObject::nwnxSet(const std::string& key, std::string value, bool persist, const char *pn)
{
    POS::Set(this, pn, key, value, persist);
}
void CGameObject::nwnxSet(const std::string& key, void *value, std::optional<CleanupFunc> cleanup, const char *pn)
{
    POS::Set(this, pn, key, value, cleanup);
}
template <> std::optional<int> CGameObject::nwnxGet(const std::string& key, const char *pn)
{
    return POS::Get<int>(this, pn, key);
}
template <> std::optional<float> CGameObject::nwnxGet(const std::string& key, const char *pn)
{
    return POS::Get<float>(this, pn, key);
}
template <> std::optional<std::string> CGameObject::nwnxGet(const std::string& key, const char *pn)
{
    return POS::Get<std::string>(this, pn, key);
}
template <> std::optional<void*> CGameObject::nwnxGet(const std::string& key, const char *pn)
{
    return POS::Get<void*>(this, pn, key);
}
void CGameObject::nwnxRemove(const std::string& key, const char *pn)
{
    POS::Remove(this, pn, key);
}
void CGameObject::nwnxRemoveRegex(const std::string& regex, const char *pn)
{
    POS::RemoveRegex(this, pn, regex);
}
