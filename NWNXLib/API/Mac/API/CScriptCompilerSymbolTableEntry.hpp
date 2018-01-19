#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct CScriptCompilerSymbolTableEntry
{
    uint32_t m_nSymbolType;
    uint32_t m_nSymbolSubType1;
    uint32_t m_nSymbolSubType2;
    int32_t m_nLocationPointer;
    int32_t m_nNextEntryPointer;
};

}

}
