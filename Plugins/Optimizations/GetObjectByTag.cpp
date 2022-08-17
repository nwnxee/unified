// Add move constructor to CExoString
#define NWN_CLASS_EXTENSION_CExoString                \
    CExoString(CExoString&& rhs)                      \
    {                                                 \
        this->m_sString = rhs.m_sString;              \
        this->m_nBufferLength = rhs.m_nBufferLength;  \
        rhs.m_sString = nullptr;                      \
        rhs.m_nBufferLength = 0;                      \
    }

#include "nwnx.hpp"
#include "API/CAppManager.hpp"
#include "API/CServerExoApp.hpp"
#include "API/CGameObjectArray.hpp"
#include "API/CNWSObject.hpp"
#include "tsl/robin_map.h"
#include <algorithm>

namespace Optimizations
{

using namespace NWNXLib;
using namespace NWNXLib::API;
using namespace NWNXLib::API::Constants;

tsl::robin_pg_map<CExoString, std::vector<OBJECT_ID>> s_lookup_table;

BOOL AddObjectToLookupTable(CNWSModule*, CExoString sTag, OBJECT_ID oidObject)
{
    auto [iter, _] = s_lookup_table.try_emplace(std::move(sTag));
    std::vector<OBJECT_ID>& bucket = iter.value();
    auto insertIter = std::upper_bound(std::begin(bucket), std::end(bucket), oidObject);
    bucket.insert(insertIter, oidObject);
    return true;
}

BOOL RemoveObjectFromLookupTable(CNWSModule*, CExoString sTag, OBJECT_ID oidObject)
{
    if (auto iter = s_lookup_table.find(sTag); iter != std::end(s_lookup_table))
    {
        std::vector<OBJECT_ID>& bucket = iter.value();
        auto eraseIter = std::lower_bound(std::begin(bucket), std::end(bucket), oidObject);
        if (eraseIter != std::end(bucket) && *eraseIter == oidObject)
        {
            bucket.erase(eraseIter);
            return true;
        }
    }

    return false;
}

OBJECT_ID FindObjectByTagOrdinal(CNWSModule*, const CExoString &sTag, uint32_t nNth)
{
    if (sTag.IsEmpty()) return OBJECT_INVALID;

    if (auto iter = s_lookup_table.find(sTag); iter != std::end(s_lookup_table))
    {
        const std::vector<OBJECT_ID>& bucket = iter->second;
        return nNth < bucket.size() ? bucket[nNth] : OBJECT_INVALID;
    }

    return OBJECT_INVALID;
}

// Note: this is not used via scripting, only via base game code to locate waypoint and transition targets. nNth is always zero!
OBJECT_ID FindObjectByTagTypeOrdinal(CNWSModule*, const CExoString &sTag, int32_t nObjectType, uint32_t nNth)
{
    if (sTag.IsEmpty()) return OBJECT_INVALID;

    if (auto iter = s_lookup_table.find(sTag); iter != std::end(s_lookup_table))
    {
        const std::vector<OBJECT_ID>& bucket = iter->second;

        for (OBJECT_ID oid : bucket)
        {
            if (CGameObject* obj = Utils::GetGameObject(oid);
                obj && obj->m_nObjectType == nObjectType)
            {
                if (nNth-- == 0) return oid;
            }
        }
    }

    return OBJECT_INVALID;
}

void GetObjectByTag() __attribute__((constructor));

void GetObjectByTag()
{
    if (Config::Get<bool>("GET_OBJECT_BY_TAG", false))
    {
        static Hooks::Hook _0 = Hooks::HookFunction(API::Functions::_ZN10CNWSModule22AddObjectToLookupTableE10CExoStringj, (void*)&AddObjectToLookupTable, Hooks::Order::Final);
        static Hooks::Hook _1 = Hooks::HookFunction(API::Functions::_ZN10CNWSModule27RemoveObjectFromLookupTableE10CExoStringj, (void*)&RemoveObjectFromLookupTable, Hooks::Order::Final);
        static Hooks::Hook _2 = Hooks::HookFunction(API::Functions::_ZN10CNWSModule22FindObjectByTagOrdinalERK10CExoStringj, (void*)&FindObjectByTagOrdinal, Hooks::Order::Final);
        static Hooks::Hook _3 = Hooks::HookFunction(API::Functions::_ZN10CNWSModule26FindObjectByTagTypeOrdinalERK10CExoStringij, (void*)&FindObjectByTagTypeOrdinal, Hooks::Order::Final);
    }
}

}
