#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct CScriptCompilerIdentifierHashTableEntry
{
    uint32_t m_nHashValue;
    uint32_t m_nIdentifierType;
    uint32_t m_nIdentifierIndex;
};

}

}
