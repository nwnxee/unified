#pragma once

#include "Common.hpp"

#include <unordered_map>
#include <vector>
#include <string>

namespace Optimizations {

class ObjectTagLookup
{
public:
    ObjectTagLookup(NWNXLib::Services::HooksProxy* hooker);

private:

    static std::unordered_map<std::string, std::vector<uint32_t>> m_TagLookupMap;

    static int32_t  AddObjectToLookupTable(void*, CExoString, uint32_t);
    static int32_t  RemoveObjectFromLookupTable(void*, CExoString, uint32_t);
    static uint32_t FindObjectByTagOrdinal(void*, CExoString&, uint32_t);
    static uint32_t FindObjectByTagTypeOrdinal(void*, CExoString&, int32_t, uint32_t);
    static int32_t  FindTagPositionInTable(void*, char *);


};

}
