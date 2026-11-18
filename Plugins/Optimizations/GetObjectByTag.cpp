#include "nwnx.hpp"
#include "API/CAppManager.hpp"
#include "API/CServerExoApp.hpp"
#include "API/CGameObjectArray.hpp"
#include "API/CNWSModule.hpp"
#include "API/CNWSObject.hpp"
#include "tsl/robin_map.h"
#include <algorithm>

namespace Optimizations
{

using namespace NWNXLib;
using namespace NWNXLib::API;
using namespace NWNXLib::API::Constants;

// Replaces the module's tag lookup table (one sorted array of every tagged object) with a hash map of tag -> bucket.
//
// The results must match the stock table exactly:
// - Tags are compared case-sensitively on their first 64 characters (CNWSTagNode::m_szTag).
// - A new object goes in front of the objects that already have its tag, so GetObjectByTag(sTag, 0) returns the
//   most recently added object, and SetTag() (a remove and an add) moves an object to the front.
// Each bucket is kept oldest first, so adding is a push_back and stock ordinal n is bucket[size - 1 - n].

static constexpr int32_t MAX_TAG_LENGTH = 64;

static tsl::robin_pg_map<CExoString, std::vector<OBJECT_ID>> s_lookupTable;
static Hooks::Hook s_loadModuleStartHook;

static CExoString TableKey(const CExoString& sTag)
{
    return sTag.GetLength() > MAX_TAG_LENGTH ? sTag.Left(MAX_TAG_LENGTH) : sTag;
}

static BOOL AddObjectToLookupTable(CNWSModule*, CExoString sTag, OBJECT_ID oidObject)
{
    s_lookupTable[TableKey(sTag)].push_back(oidObject);
    return true;
}

static BOOL RemoveObjectFromLookupTable(CNWSModule*, CExoString sTag, OBJECT_ID oidObject)
{
    if (auto iter = s_lookupTable.find(TableKey(sTag)); iter != std::end(s_lookupTable))
    {
        std::vector<OBJECT_ID>& bucket = iter.value();
        // Search from the newest end: stock removes the first match in its (newest first) order.
        if (auto found = std::find(bucket.rbegin(), bucket.rend(), oidObject); found != bucket.rend())
        {
            bucket.erase(std::next(found).base());
            if (bucket.empty())
                s_lookupTable.erase(iter);
            return true;
        }
    }

    return false;
}

static OBJECT_ID FindObjectByTagOrdinal(CNWSModule*, const CExoString& sTag, uint32_t nNth)
{
    if (sTag.IsEmpty())
        return OBJECT_INVALID;

    if (auto iter = s_lookupTable.find(TableKey(sTag)); iter != std::end(s_lookupTable))
    {
        const std::vector<OBJECT_ID>& bucket = iter->second;
        return nNth < bucket.size() ? bucket[bucket.size() - 1 - nNth] : OBJECT_INVALID;
    }

    return OBJECT_INVALID;
}

// Used by the game to find waypoint and transition targets. Stock has no empty tag check here, so neither do we.
static OBJECT_ID FindObjectByTagTypeOrdinal(CNWSModule*, const CExoString& sTag, int32_t nObjectType, uint32_t nNth)
{
    if (auto iter = s_lookupTable.find(TableKey(sTag)); iter != std::end(s_lookupTable))
    {
        const std::vector<OBJECT_ID>& bucket = iter->second;
        for (auto it = bucket.rbegin(); it != bucket.rend(); ++it)
        {
            if (CGameObject* obj = Utils::GetGameObject(*it); obj && obj->m_nObjectType == nObjectType)
            {
                if (nNth-- == 0)
                    return *it;
            }
        }
    }

    return OBJECT_INVALID;
}

// A new module starts with an empty table.
static uint32_t LoadModuleStart(CNWSModule* pModule, CExoString sModuleName, BOOL bIsSaveGame, int32_t nSourceType,
                                const NWSync::Advertisement& nwsyncModuleSourceAdvert)
{
    s_lookupTable.clear();
    return s_loadModuleStartHook->CallOriginal<uint32_t>(pModule, sModuleName, bIsSaveGame, nSourceType, nwsyncModuleSourceAdvert);
}

void GetObjectByTag() __attribute__((constructor));
void GetObjectByTag()
{
    if (!Config::Get<bool>("GET_OBJECT_BY_TAG", false))
        return;

    s_loadModuleStartHook = Hooks::HookFunction(&CNWSModule::LoadModuleStart, &LoadModuleStart, Hooks::Order::Earliest);
    static Hooks::Hook s_addHook = Hooks::HookFunction(&CNWSModule::AddObjectToLookupTable, &AddObjectToLookupTable, Hooks::Order::Final);
    static Hooks::Hook s_removeHook = Hooks::HookFunction(&CNWSModule::RemoveObjectFromLookupTable, &RemoveObjectFromLookupTable, Hooks::Order::Final);
    static Hooks::Hook s_findHook = Hooks::HookFunction(&CNWSModule::FindObjectByTagOrdinal, &FindObjectByTagOrdinal, Hooks::Order::Final);
    static Hooks::Hook s_findTypeHook = Hooks::HookFunction(&CNWSModule::FindObjectByTagTypeOrdinal, &FindObjectByTagTypeOrdinal, Hooks::Order::Final);
}

}
