#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct CResGFFFileHeader
{
    uint32_t m_nFileType;
    uint32_t m_nFileVersion;
    uint32_t m_nStructOffset;
    uint32_t m_nStructCount;
    uint32_t m_nFieldOffset;
    uint32_t m_nFieldCount;
    uint32_t m_nLabelOffset;
    uint32_t m_nLabelCount;
    uint32_t m_nDataFieldOffset;
    uint32_t m_nDataFieldCount;
    uint32_t m_nDataLayoutFieldOffset;
    uint32_t m_nDataLayoutFieldCount;
    uint32_t m_nDataLayoutListOffset;
    uint32_t m_nDataLayoutListCount;
};

}

}
