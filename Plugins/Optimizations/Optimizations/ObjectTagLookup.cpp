#include "Optimizations/ObjectTagLookup.hpp"

#include "Services/Hooks/Hooks.hpp"
#include "Services/Tasks/Tasks.hpp"
#include "API/Functions.hpp"
#include "API/Constants.hpp"
#include "API/CGameObject.hpp"
#include "API/CGameObjectArray.hpp"
#include "Utils.hpp"

namespace Optimizations {

using namespace NWNXLib;
using namespace NWNXLib::API;

std::unordered_map<std::string, std::vector<uint32_t>> ObjectTagLookup::m_TagLookupMap;

ObjectTagLookup::ObjectTagLookup(Services::HooksProxy* hooker)
{

    hooker->RequestExclusiveHook<API::Functions::_ZN10CNWSModule22AddObjectToLookupTableE10CExoStringj>
        (ObjectTagLookup::AddObjectToLookupTable);
    hooker->RequestExclusiveHook<API::Functions::_ZN10CNWSModule27RemoveObjectFromLookupTableE10CExoStringj>
        (ObjectTagLookup::RemoveObjectFromLookupTable);
    hooker->RequestExclusiveHook<API::Functions::_ZN10CNWSModule22FindObjectByTagOrdinalERK10CExoStringj>
        (ObjectTagLookup::FindObjectByTagOrdinal);
    hooker->RequestExclusiveHook<API::Functions::_ZN10CNWSModule26FindObjectByTagTypeOrdinalERK10CExoStringij>
        (ObjectTagLookup::FindObjectByTagTypeOrdinal);
    hooker->RequestExclusiveHook<API::Functions::_ZN10CNWSModule22FindTagPositionInTableEPc>
        (ObjectTagLookup::FindTagPositionInTable);
}

int32_t  ObjectTagLookup::AddObjectToLookupTable(void*, CExoString sTag, uint32_t oidObject)
{
    m_TagLookupMap[sTag.Left(64).CStr()].push_back(oidObject);
    return true;
}
int32_t  ObjectTagLookup::RemoveObjectFromLookupTable(void*, CExoString sTag, uint32_t oidObject)
{
    try {
        auto& vec = m_TagLookupMap.at(sTag.Left(64).CStr());
        for (auto it = vec.begin(); it != vec.end(); ++it)
        {
            if (*it == oidObject)
            {
                vec.erase(it);
                return true;
            }
        }
    } catch (const std::out_of_range& oor) {}
    return false;
}

uint32_t ObjectTagLookup::FindObjectByTagOrdinal(void*, CExoString & sTag, uint32_t nNth)
{
    if (sTag.IsEmpty())
        return Constants::OBJECT_INVALID;

    try {
        return m_TagLookupMap.at(sTag.Left(64).CStr()).at(nNth);
    } catch (const std::out_of_range& oor) {}
    return Constants::OBJECT_INVALID;
}

uint32_t ObjectTagLookup::FindObjectByTagTypeOrdinal(void*, CExoString & sTag, int32_t nObjectType, uint32_t nNth)
{
    try {
        auto& vec = m_TagLookupMap.at(sTag.Left(64).CStr());
        for (auto it: vec)
        {
            if (auto* go = Utils::GetGameObject(it))
            {
                if (go->m_nObjectType == nObjectType)
                {
                    if (nNth-- == 0)
                        return it;
                }
            }
        }
    } catch (const std::out_of_range& oor) {}
    return Constants::OBJECT_INVALID;
}

int32_t  ObjectTagLookup::FindTagPositionInTable(void*, char *)
{
    ASSERT_FAIL_MSG("FindTagPositionInTable() called somehow.");
    return 0;
}
}
